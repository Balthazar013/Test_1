/**
 * \addtogroup ScannerMode
 * @{
 *
 * @file 	ScannerMode.c
 * @author	p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 *
 * @internal
 * $LastChangedDate: 2018-05-14 14:43:58 +0200 (Mo, 14 Mai 2018) $
 * $LastChangedBy: fkofler $
 * $Revision: 19523 $
 * $Id: ScannerMode.c 19523 2018-05-14 12:43:58Z fkofler $
 *
 */

#ifdef TARGET_ORU

#include "ScannerMode.h"
#include "BBridgeCommons.h"
#include <string.h>
#include <stdlib.h>
#include "BBridgeDefs.h"
#include "central.h"
#include "BBridgeApp.h"

#define TOTAL_ACCEPTABLE_COMMANDS  18u
#define BLE_NAME_LENGTH (13u)

/*@ATTENTION: this list must be sorted in ASC order*/
static BBridgeCMDId_t ACCEPTABLE_COMMANDS[TOTAL_ACCEPTABLE_COMMANDS] =
{
    BBCMD_SET_FILTER_MSG,
    BBCMD_GET_FILTER_MSG,
    BBCMD_SET_OP_MODE,
    BBCMD_GET_OP_MODE,
    BBCMD_DISCONNECT,
    BBCMD_SEND_DATA,
    BBCMD_GET_CONN_STATES,
    BBCMD_GET_CONN_RSSI,
    BBCMD_GET_CONN_ADDR,
    BBCMD_GET_CONN_BRM,
    BBCMD_SET_SLEEP_MODE,
    BBCMD_SET_SCAN_MODE,
    BBCMD_INITIATE_CONNECTION,
    BBCMD_GET_CONN_NAMES,
    BBCMD_SET_BOOT_MODE,
    BBCMD_GET_BOOT_MODE,
    BBCMD_GET_RESET_REASON,
    BBCMD_GET_OWN_ADDR,
};

typedef struct
{
    BBridgeAppInterface_t * bbAPPInterface;
    uint8_t lastCommandProcessed;
    uint8_t commandPosition; /*!< for internal purposes only*/
    BBridgeCommand_t lastCommand;
    BB_ScannerMD_State_t state;
    uint8_t eventSource; /*<! used to distinguish from where an event came from (internal usage only)*/
    BBridgeNACKReason_t nackReason;
    uint8_t exitRequested;
    BBridgeCommPacket_t externalData;
    uint8_t isExternalDataProcessed;
    uint8_t hasDisconnection;
    uint8_t hasConnLost;
    uint8_t disconnectRequestForIndex;
    uint8_t disconnectFailureReason;
    uint8_t isConnecting;
    uint8_t currentDevIndex;
    uint32_t timer;
    uint32_t opDependentTimer;
    uint8_t  bSeedReqRetry;
    uint8_t currentFilterValue[BB_MAX_BROADCAST_MSG];
    uint8_t currentFilterValueLength;
    uint8_t lastDevProcessed;
    BBSCNERValidConnState_t valConnState;
    uint32_t lastCMDTime;
    uint8_t connLinkUpdating;
    uint16_t connLinkUpdatingHandle;
} BBSCNR_Controls_t;

static void setCMDAsProcessed(void);
static uint8_t loadCurrentFilterMessage(void);
static void resetOperatingVariables(void);
static BBValidResult_t validateConnection(const uint8_t data[], uint8_t length, uint8_t devIndex);
static void validateConnectionReset(void);
static uint8_t hasActiveConnections(void);
static void OnTxToPantherComplete(void);
/* private variables*/
static BBSCNR_Controls_t controls;

/**
 * @brief It initializes the Scanner mode module
 * @param bbridgeInterface
 * @return  0: BB_SUCCESS
 *          1: acceptable commands list is not in ascending order
 *          2: bad allocation for bbridge interface pointer
 */
uint8_t ScannerMode_Init(BBridgeAppInterface_t * bbridgeInterface)
{
    uint8_t i;
    uint8_t ret = BB_SUCCESS;
    
    /* checking acceptable commands list (it must be sorted) */
    for (i = 0u; i < TOTAL_ACCEPTABLE_COMMANDS - 1u; i++)
    {
        if (ACCEPTABLE_COMMANDS[i] > ACCEPTABLE_COMMANDS[i + 1u])
        {
            ret = 1u;
            break;
        }
    }
    
    if (ret == BB_SUCCESS)
    {
        if (bbridgeInterface == NULL)
        {
            ret = 2u;
        }
        else
        {
            controls.bbAPPInterface = bbridgeInterface;
            resetOperatingVariables();
        }
    }
    
    return ret;
}

void ScannerMode_OnLinkUpdate(uint16_t connHandle, uint8_t status)
{
    controls.connLinkUpdating = FALSE;
    controls.connLinkUpdatingHandle = connHandle;
}

/**
 * @brief Business logics implementation of the Scanner mode. (main state
 * machine)
 */
void ScannerMode_Work(void)
{
    BBCMDType_t cmdType;
    uint8_t tmpData[5];
    //int8_t cmpRet;
    uint8_t ret, i, tmpVal;
    static uint8_t connWithIndex;
    static uint8_t connWithAddr[6];
    uint16_t cnnMin, cnnMax;
    uint16_t tmp;
    uint16_t shiftby8 = 8u;
    uint32_t timePassed;
    
    switch (controls.state)
    {
        case (BBSCNRMD_INIT):
        {
            if (controls.bbAPPInterface->btDeviceInitialized() == FALSE)
            {
                /* stay until device is initialized. This value is set by the BBrige
                * application interface when the BLE hardware has been properly
                * initialized.
                */
            } 
            else
            {
                controls.lastCMDTime = controls.bbAPPInterface->getSystime();
                resetOperatingVariables();
                controls.state = BBSCNRMD_IDLE; /* important to be called here */
            }
            
            break;
        }
        /* begin IDLE state */
        case (BBSCNRMD_IDLE):
        {
            /*If there is an unprocessed command, start processing it*/
            if (controls.lastCommandProcessed == FALSE) 
            {
                controls.eventSource = 0u; /* for internal usage only */
                /* there is a new command available, checking type */
                cmdType = controls.bbAPPInterface->getCMDType(
                        controls.lastCommand.id);
                switch (cmdType)
                {
                    case (CMDTYPE_SET):
                        controls.state = BBSCNRMD_PROCESS_SETCMD;
                        break;
                    case (CMDTYPE_GET):
                        controls.state = BBSCNRMD_PROCESS_GETCMD;
                        break;
                    default:
                        /* Invalid command -> send NACK */
                        controls.nackReason = BB_NACK_CMD_UNKNOWN;
                        controls.state = BBSCNRMD_SND_NACK;
                        break;
                }
            }
            /*If there is no commands to be processed, check if a connection has been lost*/
            else if (controls.hasConnLost == TRUE)
            {
                controls.hasConnLost = FALSE;
                controls.state = BBSCNRMD_PROCESS_CONN_LOST;
            }
            
            break;
        }   /* end IDLE state */
        /* Begin scan state */
        case (BBSCNRMD_PROCESS_SCAN):
        {
            /* scan operation has finished */
            if (controls.bbAPPInterface->btScanResultTotal > 0u)
            {
                int a = 2;
                for(i = 0; i < controls.bbAPPInterface->btScanResultTotal; ++i)
                {
                    memcpy(&controls.bbAPPInterface->sharedMemValue[a], &controls.bbAPPInterface->btScanResult[i].addr[0], 6);
                    a = a + 6;
                }
                
                controls.bbAPPInterface->sharedMemValue[0] = BB_EVT_DETECTED_CONNECTABLE;
                controls.bbAPPInterface->sharedMemValue[1] = (a-2) / 6 ;
                controls.bbAPPInterface->sharedMemValueLength = a;
                controls.state = BBSCNRMD_SND_EVENT;
            }
            else
            {
                controls.state = BBSCNRMD_IDLE;
                controls.bbAPPInterface->scanAllowed = TRUE;
                controls.lastDevProcessed = FALSE;
                controls.bbAPPInterface->btScanResultTotal = 0u;
            }
            
            break;
        }/* end SCAN state */
        
        case (BBSCNRMD_INITIATE_CONNECTION):
        {
            connWithIndex = BB_INVALID_DEV_INDEX;
            
            for(i = 0; i < controls.bbAPPInterface->btScanResultTotal; i++)
            {
                if ( memcmp(&(controls.bbAPPInterface->btScanResult[i].addr[0]), &connWithAddr[0], 6U) == 0)
                {
                    connWithIndex = i;
                }
            }
            
            if (connWithIndex != BB_INVALID_DEV_INDEX)
            {
                /* initiate connection */
                controls.lastDevProcessed = connWithIndex;
                
                if (controls.bbAPPInterface->connect(
                    controls.bbAPPInterface->btScanResult[connWithIndex].addr,
                    controls.bbAPPInterface->btScanResult[connWithIndex].addrType) == BB_SUCCESS)
                {
                    /* connection initiated*/
                    controls.isConnecting = TRUE;
                    controls.state = BBSCNRMD_WAIT_CONN_STATE;
                    controls.timer = controls.bbAPPInterface->getSystime();
                    controls.currentDevIndex = controls.lastDevProcessed;
                    controls.lastDevProcessed++;
                }
                else
                {
                    /* could not initiate connection */
                    controls.state = BBSCNRMD_PROCESS_SCAN;
                    controls.lastDevProcessed++;
                }
            }
            else
            {
                /* device is not a match */
                controls.state = BBSCNRMD_PROCESS_SCAN;
                controls.lastDevProcessed++;
            }
            
            break;
        }
        
        case (BBSCNRMD_WAIT_CONN_STATE):
        {
            if (controls.isConnecting == FALSE)
            {
                /* not connecting anymore (received a connection feedback) */
                if (controls.currentDevIndex == BB_INVALID_DEV_INDEX)
                {
                    /* failed to connect, back to process the scan list*/
                    controls.state = BBSCNRMD_PROCESS_SCAN;
                }
                else
                {
                    /* loading new connection parameters*/
                    if (DEFAULT_ENABLE_UPDATE_REQUEST == TRUE)
                    {
                        controls.connLinkUpdating = TRUE;
                        /*controls.state = BBSCNRMD_WAIT_CONN_PARAMS;*/
                        tmp = (uint16_t) controls.bbAPPInterface->btConnections[controls.currentDevIndex].btDevice.broadcastMsg[9];
                        tmp |= (uint16_t) ((uint16_t) controls.bbAPPInterface->btConnections[controls.currentDevIndex].btDevice.broadcastMsg[10] << shiftby8);
                        cnnMin = tmp;
                        
                        tmp = (uint16_t) controls.bbAPPInterface->btConnections[controls.currentDevIndex].btDevice.broadcastMsg[11];
                        tmp |= (uint16_t) ((uint16_t) controls.bbAPPInterface->btConnections[controls.currentDevIndex].btDevice.broadcastMsg[12] << shiftby8);
                        cnnMax = tmp;
                        
                        ret = controls.bbAPPInterface->updateConnectionParams(
                                        controls.bbAPPInterface->btConnections[controls.currentDevIndex].cnnhandle,
                                        cnnMin, cnnMax,
                                        DEFAULT_DESIRED_SLAVE_LATENCY,
                                        DEFAULT_DESIRED_CONN_TIMEOUT);
                        
                        if (ret == BB_SUCCESS)
                        {
                            controls.state = BBSCNRMD_WAIT_CONN_PARAMS;
                            controls.connLinkUpdating = TRUE;
                            controls.timer = controls.bbAPPInterface->getSystime();
                        }
                        else
                        {
                            /* failed to request parameters, disconnecting from device*/
                            controls.hasDisconnection = FALSE;
                            controls.state = BBSCNRMD_WAIT_DISCONNECTION;
                            controls.eventSource = 2u; /* used in the wait state to check previous state machine state*/
                            controls.disconnectRequestForIndex = controls.currentDevIndex;
                            controls.timer = controls.bbAPPInterface->getSystime();
                            controls.isConnecting = FALSE;
                        }
                    }
                    else
                    {
                        if (BB_VALIDATION_ENABLED == TRUE)
                        {
                            controls.bSeedReqRetry = FALSE;
                            controls.state = BBSCNRMD_REQ_SEED;
                        }
                        else
                        {
                            controls.state = BBSCNRMD_BB_AUTH_OK;
                        }
                    }
                }
            }
            else
            {
                /* handling timeout */
                if (controls.bbAPPInterface->getSystimeDiff(controls.timer) >= BBCONN_TIMEOUT)
                {
                    controls.hasDisconnection = FALSE;
                    controls.state = BBSCNRMD_WAIT_DISCONNECTION;
                    controls.disconnectRequestForIndex = controls.currentDevIndex;
                    controls.timer = controls.bbAPPInterface->getSystime();
                    controls.isConnecting = FALSE;
                    controls.eventSource = 2u;
                }
            }
            
            break;
        }
        
        case (BBSCNRMD_WAIT_CONN_PARAMS):
        {
            if ((controls.connLinkUpdating == FALSE)
                    && (controls.connLinkUpdatingHandle
                            == controls.bbAPPInterface->btConnections[controls.currentDevIndex].cnnhandle))
            {
                if (BB_VALIDATION_ENABLED == TRUE)
                {
                    controls.bSeedReqRetry = FALSE;
                    controls.state = BBSCNRMD_REQ_SEED;
                }
                else
                {
                    controls.state = BBSCNRMD_BB_AUTH_OK;
                }
            }
            else
            {
                if (controls.bbAPPInterface->getSystimeDiff(controls.timer) >= BBCONN_TIMEOUT)
                {
                    controls.bbAPPInterface->disconnectBTDevice(controls.currentDevIndex);
                    controls.hasDisconnection = FALSE;
                    controls.state = BBSCNRMD_WAIT_DISCONNECTION;
                    controls.disconnectRequestForIndex = controls.currentDevIndex;
                    controls.timer = controls.bbAPPInterface->getSystime();
                    controls.isConnecting = FALSE;
                    controls.eventSource = 2u;
                }
            }
            
            break;
        }
        
        case (BBSCNRMD_PROCESS_GETCMD):
        {
            if ((controls.lastCommand.id == BBCMD_GET_CONN_RSSI)
                ||
                (controls.lastCommand.id == BBCMD_GET_CONN_ADDR)
                ||
                (controls.lastCommand.id == BBCMD_GET_CONN_BRM))
            {
                if (controls.lastCommand.cmd.length != 1u)
                {
                    controls.nackReason = BB_NACK_INVALID_REQ;
                    controls.state = BBSCNRMD_SND_NACK;
                    controls.eventSource = 2u; /* to not enter in scanning state*/
                } 
                else
                {
                    tmpVal = controls.lastCommand.cmd.data[0]; /* dev index*/
                    /* check index*/
                    if (tmpVal >= BB_MAX_SCANNER_BT_CONNS)
                    {
                        controls.nackReason = BB_NACK_INVALID_REQ;
                        controls.state = BBSCNRMD_SND_NACK;
                    }
                    else
                    {
                        /* check connection*/
                        if ((controls.bbAPPInterface->btConnections[tmpVal].isConnected == FALSE)
                            ||
                            (controls.bbAPPInterface->btConnections[tmpVal].isValidated == FALSE))
                        {
                            controls.nackReason = BB_NACK_NOT_CONNECTED;
                            controls.state = BBSCNRMD_SND_NACK;
                        }
                        else
                        {
                            /* device requested is valid */
                            switch (controls.lastCommand.id) {
                            case (BBCMD_GET_CONN_RSSI):
                                /* attention this value should be converted to int8_t*/
                                controls.bbAPPInterface->sharedMemValue[0] =
                                        (uint8_t) controls.bbAPPInterface->btConnections[tmpVal].btDevice.rssi;
                                controls.bbAPPInterface->sharedMemValueLength = 1u;
                                break;
                            case (BBCMD_GET_CONN_ADDR):
                                memcpy(controls.bbAPPInterface->sharedMemValue,
                                        controls.bbAPPInterface->btConnections[tmpVal].btDevice.addr,
                                        6u);
                                controls.bbAPPInterface->sharedMemValueLength = 6u;
                                break;
                            case (BBCMD_GET_CONN_BRM):
                                memcpy(controls.bbAPPInterface->sharedMemValue,
                                        controls.bbAPPInterface->btConnections[tmpVal].btDevice.broadcastMsg,
                                        (uint16_t) controls.bbAPPInterface->btConnections[tmpVal].btDevice.broadcastMsgLength);
                                controls.bbAPPInterface->sharedMemValueLength =
                                        controls.bbAPPInterface->btConnections[tmpVal].btDevice.broadcastMsgLength;
                                break;
                            default:
                                break;
                            }
                            controls.state = BBSCNRMD_SND_ACK;
                            controls.eventSource = 2u; /* to not enter in scanning state*/
                        }
                    }
                }
            }
            else if (controls.lastCommand.id == BBCMD_GET_CONN_STATES)
            {
                controls.bbAPPInterface->sharedMemValue[0] = \
                    (controls.bbAPPInterface->btConnections[0].isValidated == TRUE) ? TRUE : FALSE;
                    
                controls.bbAPPInterface->sharedMemValue[1] = \
                    (controls.bbAPPInterface->btConnections[1].isValidated == TRUE) ? TRUE : FALSE;
                    
                controls.bbAPPInterface->sharedMemValue[2] =
                    (controls.bbAPPInterface->btConnections[2].isValidated == TRUE) ? TRUE : FALSE;
                    
                controls.bbAPPInterface->sharedMemValueLength = 3u;
                controls.eventSource = 2u; /* to not enter in scanning state*/
                controls.state = BBSCNRMD_SND_ACK;
            }
            else if(controls.lastCommand.id == BBCMD_GET_CONN_NAMES)
            {
                int a = 0;
                for(i = 0; i < controls.bbAPPInterface->btScanResultTotal; ++i)
                {
                    /* found a device to try a connection */
                    memcpy(&controls.bbAPPInterface->sharedMemValue[a], &controls.bbAPPInterface->btScanResult[i].broadcastMsg[18], BLE_NAME_LENGTH);
                    a = a + BLE_NAME_LENGTH;
                }
                
                controls.bbAPPInterface->sharedMemValueLength = a;
                controls.eventSource = 2u; /* to not enter in scanning state*/
                controls.state = BBSCNRMD_SND_ACK;
            }
            else if(controls.lastCommand.id  == BBCMD_GET_OWN_ADDR)
            {
                GAPCentralRole_GetParameter(GAPCENTRALROLE_BD_ADDR, controls.bbAPPInterface->sharedMemValue);
                controls.bbAPPInterface->sharedMemValueLength = 6u;
                controls.eventSource = 2u;
                controls.state = BBSCNRMD_SND_ACK;
            }
            else
            {
                /* Loading other generic values from the BBridge APP interface */
                ret = controls.bbAPPInterface->proccessGetCmd(&controls.lastCommand,
                        controls.bbAPPInterface->sharedMemValue,
                        &controls.bbAPPInterface->sharedMemValueLength);
                if (ret == BB_SUCCESS)
                {
                    controls.state = BBSCNRMD_SND_ACK;
                    controls.eventSource = 2u; /* to not enter in scanning state after ack sent*/
                }
                else
                {
                    /* error processing -> send NACK*/
                    controls.nackReason = BB_NACK_CMD_UNKNOWN;
                    controls.state = BBSCNRMD_SND_NACK;
                    controls.eventSource = 2u; /* to not enter in scanning state after Nack sent*/
                }
            }
            
            break;
        }
        /* begin switch set command */
        case (BBSCNRMD_PROCESS_SETCMD):
        {
            switch (controls.lastCommand.id)
            {
                case (BBCMD_SET_OP_MODE):
                {
                    if (controls.lastCommand.cmd.data[0] == BB_IDLE_MODE)
                    {
                        /* exiting mode */
                        controls.exitRequested = FALSE;
                        controls.state = BBSCNRMD_WAIT_EXIT_CALL;
                    }
                    else
                    {
                        /* can only go from Scanner to IDLE */
                        //controls.nackReason = BB_NACK_INVALID_REQ;
                        controls.state = BBSCNRMD_SND_ACK;
                    }
                    
                    controls.eventSource = 2u; /* to not enter in scanning state after NACK send*/
                break;
                }
                
                /* begin send data */
                case (BBCMD_SEND_DATA):
                {
                    /* check if command data is correct*/
                    if (controls.lastCommand.cmd.length < 2u)
                    {
                        /* there is no valid data to be transfered*/
                        controls.nackReason = BB_NACK_INVALID_REQ;
                        controls.state = BBSCNRMD_SND_NACK;
                    }
                    else
                    {
                        /* check if destination index is correct*/
                        if (controls.lastCommand.cmd.data[0] < BB_MAX_SCANNER_BT_CONNS)
                        {
                            /* index within range (ok)*/
                            /* checking if device is connected*/
                            if ((controls.bbAPPInterface->btConnections[controls.lastCommand.cmd.data[0]].isConnected == TRUE)
                                &&
                                (controls.bbAPPInterface->btConnections[controls.lastCommand.cmd.data[0]].isValidated == TRUE))
                            {
                                ret = controls.bbAPPInterface->sendBTDataCommand(
                                                controls.lastCommand.cmd.data[0],
                                                &controls.lastCommand.cmd.data[1],
                                                (controls.lastCommand.cmd.length - 1u));
                                if (ret == 0u)
                                {
                                    /* bluetooth transmission ok*/
                                    controls.bbAPPInterface->sharedMemValue[0] = controls.lastCommand.cmd.data[0]; /* device index*/
                                    controls.bbAPPInterface->sharedMemValueLength = 1u;
                                    OnTxToPantherComplete();
                                    //controls.state = BBSCNRMD_SND_ACK; 
                                }
                                else
                                {
                                controls.nackReason = BB_NACK_SEND_ERROR;
                                controls.state = BBSCNRMD_SND_NACK;
                                }
                            }
                            else
                            {
                                controls.nackReason = BB_NACK_NOT_CONNECTED;
                                controls.state = BBSCNRMD_SND_NACK;
                                controls.bbAPPInterface->sharedMemValueLength = 0u;
                            }
                        }
                        else
                        {
                            controls.nackReason = BB_NACK_INDEX_OUTORANGE;
                            controls.state = BBSCNRMD_SND_NACK;
                            controls.bbAPPInterface->sharedMemValueLength = 0u;
                        }
                    }
                    
                    break;
                } /* end send data */
                
                case (BBCMD_DISCONNECT):
                {
                    controls.state = BBSCNRMD_PROCESS_CMDDISCONNECT;
                    break;
                }
                
                case (BBCMD_SET_SLEEP_MODE):
                {
                    controls.state = BBSCNRMD_PROCESS_CMDSET_SLEEP_MODE; 
                    controls.timer = controls.bbAPPInterface->getSystime();
                    break;
                }
                
                case (BBCMD_SET_SCAN_MODE):
                {
                    if (controls.bbAPPInterface->btScanBusy == FALSE)
                    {
                        /* Scan operation is not operating, checking for scan results */
                        if (controls.bbAPPInterface->btScanResultTotal > 0u)
                        {
                            /* found potential devices to be connected */
                            /*  blocking further scanning operations */
                            controls.bbAPPInterface->scanAllowed = FALSE;
                            
                            /* loading current filter message in case it has changed
                            since last run */
                            ret = loadCurrentFilterMessage();
                            if (ret == BB_SUCCESS)
                            {
                                controls.state = BBSCNRMD_PROCESS_SCAN;
                            }
                            else
                            {
                                /* could not load filter (not processing) */
                                controls.bbAPPInterface->scanAllowed = TRUE;
                            }
                        }
                        else
                        {
                            controls.lastDevProcessed = 0u;
                            controls.bbAPPInterface->scanAllowed = TRUE; 
                        }
                    }
                    
                    break;
                }
                
                case (BBCMD_INITIATE_CONNECTION):
                {
                    memcpy(&connWithAddr[0], &controls.lastCommand.cmd.data[0], 6);
                    controls.state = BBSCNRMD_INITIATE_CONNECTION;
                    controls.timer = controls.bbAPPInterface->getSystime();
                    break;
                }
                
                default:
                {
                    ret = controls.bbAPPInterface->proccessSetCmd(&controls.lastCommand);
                    if (ret == BB_SUCCESS)
                    {
                        controls.state = BBSCNRMD_SND_ACK;
                        controls.bbAPPInterface->sharedMemValueLength = 0u;
                    }
                    else
                    {
                        /* error processing -> send NACK*/
                        controls.nackReason = BB_NACK_CMD_UNKNOWN; /* TODO check correct NACK reason*/
                        controls.state = BBSCNRMD_SND_NACK;
                    }
                    
                    break;
                }
            }
            
            break;
        } /* end switch set command */
        
        case (BBSCNRMD_WAIT_EXIT_CALL):
        {
            if (controls.exitRequested == TRUE)
            {
                controls.exitRequested = FALSE;
                resetOperatingVariables();
            }
            
            break;
        }
        
        case (BBSCNRMD_SND_NACK):
        {
            ret = controls.bbAPPInterface->pushNACK(controls.lastCommand.id, controls.nackReason);
            if (ret == BB_SUCCESS)
            {
                /* data was pushed to be transmitted correctly*/
                controls.state = BBSCNRMD_WAIT_TX2PANTHER;
            }
            else
            {
                /* could not push NACK... try again*/
            }
            
            break;
        }
        
        case (BBSCNRMD_SND_ACK):
        {
            ret = controls.bbAPPInterface->pushACK(controls.lastCommand.id,
                    controls.bbAPPInterface->sharedMemValue,
                    controls.bbAPPInterface->sharedMemValueLength);
            if (ret == BB_SUCCESS)
            {
                /* data was pushed to be transmitted correctly*/
                controls.state = BBSCNRMD_WAIT_TX2PANTHER;
            }
            else
            {
                /* could not push ACK... try again*/
            }
            
            break;
        }
        
        case (BBSCNRMD_SND_EVENT):
        {
            ret = controls.bbAPPInterface->pushEVENT(
                                    (BBridgeEvents_t) controls.bbAPPInterface->sharedMemValue[0],
                                    &controls.bbAPPInterface->sharedMemValue[1],
                                    (uint8_t) (controls.bbAPPInterface->sharedMemValueLength - 1u));
                    
            if (ret == BB_SUCCESS)
            {
                /* data was pushed to be transmitted correctly*/
                controls.state = BBSCNRMD_WAIT_TX2PANTHER;
            }
            else
            {
                /* could not push EVENT... try again*/
            }
            
            break;
        }
        
        case (BBSCNRMD_WAIT_TX2PANTHER):
        {
            if (controls.bbAPPInterface->isTxToPantherComplete() == TRUE)
            {
                  OnTxToPantherComplete();
            }
            
            break;
        }
        
        case (BBSCNRMD_REQ_SEED):
        {
            /* only for debugging*/
            tmpData[0] = BB_SEED_REQ; /* seed request tx*/
            
            ret = controls.bbAPPInterface->sendBTData(controls.currentDevIndex, tmpData, 1u);
            if (ret == BB_SUCCESS) 
            {
                controls.isExternalDataProcessed = TRUE; /* clearing RX to not processed*/
                controls.state = BBSCNRMD_VALIDATE_CONN;
                 /* update the timestamp in the first transition */
                if(controls.bSeedReqRetry == FALSE)
                {
                    controls.timer = controls.bbAPPInterface->getSystime();
                    controls.opDependentTimer = controls.bbAPPInterface->getSystime();
                }
                else
                {
                    controls.bSeedReqRetry = FALSE;
                }
            }
            else
            {
                controls.bbAPPInterface->disconnectBTDevice(controls.currentDevIndex);
                controls.hasDisconnection = FALSE;
                controls.state = BBSCNRMD_WAIT_DISCONNECTION;
                controls.disconnectRequestForIndex = controls.currentDevIndex;
                controls.timer = controls.bbAPPInterface->getSystime();
                controls.isConnecting = FALSE;
                controls.eventSource = 2u;
            }
            
            break;
        }
        
        case (BBSCNRMD_VALIDATE_CONN):
        {
            if (controls.isExternalDataProcessed == FALSE)
            {
                controls.isExternalDataProcessed = TRUE;
                /* received new data*/
            
                /* -> check if it comes from the expected source*/
                if (controls.currentDevIndex != controls.externalData.unPacketInfo.st.ConnIndex) {
                    /* data came from an unexpected device*/
                    /* ignore data and wait for more packets*/
                }
                else 
                {
                    /* data comes from the expected source*/
                    switch (validateConnection(controls.externalData.unPacketData.st.data,
                            controls.externalData.unPacketInfo.st.DataLength, controls.currentDevIndex))
                    {
                        case (BBVAL_BUSY):
                            /* do nothing*/
                            break;
                        case (BBVAL_PASS):
                            validateConnectionReset();
                
                            controls.state = BBSCNRMD_BB_AUTH_OK;
                            controls.bbAPPInterface->onConnectionValidated(
                                    controls.currentDevIndex);
                
                            break;
                        default:
                            validateConnectionReset();
                            controls.state = BBSCNRMD_BB_AUTH_FAIL;
                            break;
                    }
                }
            }
            else
            {
                if (controls.bbAPPInterface->getSystimeDiff(controls.opDependentTimer) >= 2000u)
                {
                    /* Seed request retransmission (in case the it got lost) */
                    controls.opDependentTimer = controls.bbAPPInterface->getSystime();
                    controls.bSeedReqRetry = TRUE;
                    controls.state = BBSCNRMD_REQ_SEED;
                }
                
                if (controls.bbAPPInterface->getSystimeDiff(controls.timer) >= BB_VALIDATION_TIMEOUT)
                {
                    controls.timer = controls.bbAPPInterface->getSystime();
                    controls.state = BBSCNRMD_BB_AUTH_FAIL;
                }
            }
            
            break;
        }
        
        case (BBSCNRMD_BB_AUTH_FAIL):
        {
            controls.bbAPPInterface->disconnectBTDevice(controls.currentDevIndex);
            controls.state = BBSCNRMD_PROCESS_SCAN;
            break;
        }
        
        case (BBSCNRMD_BB_AUTH_OK):
        {
            if (controls.bbAPPInterface->btConnections[controls.currentDevIndex].isValidated != TRUE)
            {
                controls.bbAPPInterface->onConnectionValidated(controls.currentDevIndex);
                controls.bbAPPInterface->btConnections[controls.currentDevIndex].isValidated = TRUE;
            }
            
            /* copying device data*/
            controls.bbAPPInterface->setWakeUPLine(1u);
            
            controls.bbAPPInterface->sharedMemValue[0] = BB_EVT_CONN_ESTABLISHED;
            
            controls.bbAPPInterface->sharedMemValue[1] = \
                (controls.bbAPPInterface->btConnections[0].isValidated == TRUE) ? TRUE : FALSE;
            
            controls.bbAPPInterface->sharedMemValue[2] = \
                (controls.bbAPPInterface->btConnections[1].isValidated == TRUE) ? TRUE : FALSE;
            
            controls.bbAPPInterface->sharedMemValue[3] = \
                (controls.bbAPPInterface->btConnections[2].isValidated == TRUE) ? TRUE : FALSE;
            
            controls.bbAPPInterface->sharedMemValueLength = 4u;
            controls.eventSource = 1u; /* not to SCAN after sending event*/
            controls.state = BBSCNRMD_SND_EVENT;
            
            break;
        }
        
        case (BBSCNRMD_PROCESS_CMDDISCONNECT):
        {
            /* process disconnection*/
            /* check if device index given is valid and device is connected/validated*/
            if (controls.lastCommand.cmd.data[0] < BB_MAX_SCANNER_BT_CONNS)
            {
                /* index given within range*/
                ret = controls.bbAPPInterface->disconnectBTDevice(controls.lastCommand.cmd.data[0]);
                if (ret != BB_SUCCESS)
                {
                    if (ret == 2u)
                    {
                        controls.nackReason = BB_NACK_NOT_CONNECTED;
                        controls.state = BBSCNRMD_SND_NACK;
                    }
                    else
                    {
                        controls.nackReason = BB_NACK_INDEX_OUTORANGE;
                        controls.state = BBSCNRMD_SND_NACK;
                    }
                }
                else
                {
                    controls.hasDisconnection = FALSE;
                    controls.state = BBSCNRMD_WAIT_DISCONNECTION;
                    controls.disconnectRequestForIndex = controls.lastCommand.cmd.data[0];
                    controls.timer = controls.bbAPPInterface->getSystime();
                    controls.eventSource = 1u;
                }
            }
            else
            {
                /* device out of range (SEND NACK)*/
                controls.nackReason = BB_NACK_INDEX_OUTORANGE;
                controls.state = BBSCNRMD_SND_NACK;
            }
            
            break;
        }
        
        case (BBSCNRMD_PROCESS_CMDSET_SLEEP_MODE):
        {
            if (controls.bbAPPInterface->getSystimeDiff(controls.timer) >= 1u)
            {
                controls.bbAPPInterface->gotosleep();
            }
            
            break;
        }
        
        case (BBSCNRMD_WAIT_DISCONNECTION):
        {
            if (controls.hasDisconnection == TRUE)
            {
                controls.hasDisconnection = FALSE;
                
                if (controls.eventSource == 1u)
                {
                    /* disconnection request came from PANTHER COMMAND*/
                    if (controls.bbAPPInterface->btConnections[controls.disconnectRequestForIndex].isConnected == FALSE)
                    {
                        /* got a disconnection from the correct device*/
                        controls.bbAPPInterface->sharedMemValue[0] = \
                            (controls.bbAPPInterface->btConnections[0].isValidated == TRUE) ? 1u : 0u;
                        
                        controls.bbAPPInterface->sharedMemValue[1] = \
                            (controls.bbAPPInterface->btConnections[1].isValidated == TRUE) ? 1u : 0u;
                        
                        controls.bbAPPInterface->sharedMemValue[2] = \
                            (controls.bbAPPInterface->btConnections[2].isValidated == TRUE) ? 1u : 0u;
                        
                        if (hasActiveConnections() == FALSE)
                        {
                            //controls.bbAPPInterface->setWakeUPLine(0u);
                        }
                        
                        controls.bbAPPInterface->sharedMemValueLength = 3u;
                        controls.state = BBSCNRMD_SND_ACK;
                        controls.eventSource = 2u; /* to skip scan after ACK transmission*/
                        controls.disconnectRequestForIndex = BB_INVALID_DEV_INDEX;
                    }
                }
                else
                {
                    /* disconnection request came from invalid/not correct connected device*/
                    controls.state = BBSCNRMD_PROCESS_SCAN;
                }
            }
            
            timePassed = controls.bbAPPInterface->getSystimeDiff(controls.timer);
            if ((controls.state == BBSCNRMD_WAIT_DISCONNECTION)
                &&
               (timePassed >= BBDISCONN_TIMEOUT))
            {
                if (controls.eventSource == 1u)
                {
                    /* disconnection request came from PANTHER COMMAND*/
                    /* disconnection timeout*/
                    controls.disconnectRequestForIndex = BB_INVALID_DEV_INDEX;
                    controls.state = BBSCNRMD_SND_NACK;
                    controls.timer = controls.bbAPPInterface->getSystime();
                    
                    /* This set is important to check when the disconnection event
                    * arrives after the timeout. In this case it is interpreted as a
                    * connection lost event
                    */
                }
                else
                {
                    /* disconnection request came from invalid/not correct connected device*/
                    controls.state = BBSCNRMD_PROCESS_SCAN;
                    controls.disconnectRequestForIndex = BB_INVALID_DEV_INDEX;
                }
            }
            else
            {
                /* not needed */
            }
            break;
        }
        
        case (BBSCNRMD_PROCESS_CONN_LOST):
        {
            controls.bbAPPInterface->sharedMemValue[0] = BB_EVT_CONN_LOST;
            
            controls.bbAPPInterface->sharedMemValue[1] = \
                (controls.bbAPPInterface->btConnections[0].isValidated == TRUE) ? 1u : 0u;
            
            controls.bbAPPInterface->sharedMemValue[2] =
                (controls.bbAPPInterface->btConnections[1].isValidated == TRUE) ? 1u : 0u;
            
            controls.bbAPPInterface->sharedMemValue[3] =
                (controls.bbAPPInterface->btConnections[2].isValidated == TRUE) ? 1u : 0u;
            
            controls.bbAPPInterface->sharedMemValueLength = 4u;
            controls.state = BBSCNRMD_SND_EVENT;
            
            /* setting WAKEUP line to LOW in case of no more connections active*/
            if (hasActiveConnections() == FALSE)
            {
                //controls.bbAPPInterface->setWakeUPLine(0u);
            }
            
            /* update list and send conn lost event*/
            break;
        }
        
        default:
        {
            controls.state = BBSCNRMD_INIT;
            break;
        }
    }
}

/**
 * @brief It loads the current filter message value in the currentFilterValue
 * variable
 * @return  BB_SUCCESS: ok\n
 *          non-zero: error (see return values bbAPPInterface->proccessGetCmd)
 */
static uint8_t loadCurrentFilterMessage(void)
{
    /* found devices not yet processed, checking filter */
    /* loading filter command*/
    uint8 * ptr =  BBridge_GetFilterMessage();
    controls.currentFilterValueLength = BB_MAX_BROADCAST_MSG;
    memcpy(controls.currentFilterValue, ptr, BB_MAX_BROADCAST_MSG);
    return 0;
}

/**
 * @brief It checks whether there are validated connections in the btConnections
 * list
 * @return  TRUE: yes\n
 *          FALSE: no
 */
static uint8_t hasActiveConnections(void)
{
    uint8_t i;
    uint8_t ret = FALSE;
    
    for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; ++i)
    {
        if (controls.bbAPPInterface->btConnections[i].isValidated == TRUE)
        {
            ret = TRUE;
            break;
        }
    }
    
    return ret;
}

/**
 * @brief It resets the validate connection state machine to is initial state
 */
static void validateConnectionReset(void)
{
    controls.valConnState = BBSCNER_VAL_IDLE;
}

/**
 * @brief State machine to validate a connection using SEED/KEY approach
 * @return BBVALResult_t
 */
static BBValidResult_t validateConnection(const uint8_t data[], uint8_t length, uint8_t devIndex)
{
    uint8_t tmpData[5];
    uint8_t ret;
    uint32_t tmp;
    BBValidResult_t funcRet = BBVAL_BUSY;
    
    switch (controls.valConnState)
    {
        case (BBSCNER_VAL_IDLE):
        {
            if ((data[0] == BB_SEED_RESP) && (length == 5u))
            {
                /*receiving SEED*/
                tmp = 0u;
                tmp |= (uint32_t) controls.externalData.unPacketData.st.data[1];
                tmp |= ((uint32_t) controls.externalData.unPacketData.st.data[2]) << 8u;
                tmp |= ((uint32_t) controls.externalData.unPacketData.st.data[3]) << 16u;
                tmp |= ((uint32_t) controls.externalData.unPacketData.st.data[4]) << 24u;
        
                /* calculating KEY*/
                tmp = controls.bbAPPInterface->calculateAuthKey(tmp);
        
                /* adding key in a response array*/
                tmpData[0] = (uint8_t) BB_KEY_RESP; /* key tx*/
                tmpData[1] = (uint8_t) (tmp & 0xFFu);
                tmpData[2] = (uint8_t) ((tmp >> 8u) & 0xFFu);
                tmpData[3] = (uint8_t) ((tmp >> 16u) & 0xFFu);
                tmpData[4] = (uint8_t) ((tmp >> 24u) & 0xFFu);
        
                ret = controls.bbAPPInterface->sendBTData(devIndex, tmpData, 5u);
                if (ret == 0u)
                {
                    funcRet = BBVAL_PASS;
                }
                else
                {
                    funcRet = BBVAL_ERROR;
                }
            }
            
            break;
        }
        
        case (BBSCNER_VAL_CHECK_KEY_OK):
        {
            if ((data[0] == BB_KEY_PASS) && (length == 1u))
            {
                /* validation succeeded!*/
                controls.valConnState = BBSCNER_VAL_AUTH_PASS;
            }
            else
            {
                controls.valConnState = BBSCNER_VAL_AUTH_FAILED;
            }
            
            break;
        }
        
        case (BBSCNER_VAL_AUTH_PASS):
        {
            funcRet = BBVAL_PASS;
            break;
        }
        
        case (BBSCNER_VAL_AUTH_FAILED):
        {
            funcRet = BBVAL_FAILED;
            break;
        }
        
        case (BBSCNER_VAL_AUTH_ERROR):
        {
            funcRet = BBVAL_ERROR;
            break;
        }
        
        default:
        {
            controls.valConnState = BBSCNER_VAL_IDLE;
            break;
        }
    }
    
    return funcRet;
}

/**
 * @brief It sets the current command as processed. Thus freeing the module to
 * receive more commands
 */
static void setCMDAsProcessed(void)
{
    controls.lastCommandProcessed = TRUE;
}

/**
 * @brief called by the Bluetooth interface when data is received from a non-
 * validated connection
 * @param devIndex
 * @param data
 * @param dataLength
 * @return  0(BB_SUCCESS): data received\n
 *          1: cannot receive data (busy processing previous)\n
 *          2: invalid data pointer\n
 *          3: invalid data length\n
 *          4: invalid device index
 *
 */
uint8_t ScannerMode_OnRxExtData(BBridgeCommPacket_t *psBrdgComPaket)
{
    uint8_t ret = BB_SUCCESS;
    
    controls.lastCMDTime = controls.bbAPPInterface->getSystime();
    
    if (controls.isExternalDataProcessed == FALSE)
    {
        ret = 1u; /* previous data not yet processed (dropping*/
    }
    else if (psBrdgComPaket->unPacketInfo.st.ConnIndex >= BB_MAX_SCANNER_BT_CONNS)
    {
        ret = 4u;
    }
    else
    {
        controls.externalData.unPacketInfo.st.ConnIndex = psBrdgComPaket->unPacketInfo.st.ConnIndex;
        controls.externalData.unPacketInfo.st.HeaderLength = 0;
        controls.externalData.unPacketInfo.st.HeaderOffset = 0;
        controls.externalData.unPacketInfo.st.DataLength = psBrdgComPaket->unPacketInfo.st.DataLength;
        
        memcpy(controls.externalData.unPacketData.st.data,\
               psBrdgComPaket->unPacketData.st.data, \
               psBrdgComPaket->unPacketInfo.st.DataLength);
        
        controls.isExternalDataProcessed = FALSE;
    }
    
    return ret;
}

/**
 * @brief Called when there is a new connection event from the Bluetooth stack
 * @param status
 * @param deviceIndex
 * @return  BB_SUCCESS: ok, event received correctly\n
 *          1: ok, event received correctly\n
 *          2: fail: unexpected connection (caller should terate this connection)
 */
uint8_t ScannerMode_OnConnection(uint8_t status, uint8_t deviceIndex)
{
    uint8_t ret = BB_SUCCESS;
    
    if (controls.isConnecting == FALSE)
    {
        /* unexpected connection*/
        ret = 2u;
    }
    else if (status != 0u)
    {
        /* connection failed*/
        controls.isConnecting = FALSE;
        controls.currentDevIndex = BB_INVALID_DEV_INDEX;
        ret = 1u;
    }
    else
    {
        controls.bbAPPInterface->btConnections[deviceIndex].isConnected = TRUE;
        controls.bbAPPInterface->btConnections[deviceIndex].isValidated = FALSE;
        controls.bbAPPInterface->totalConnected++;
        controls.isConnecting = FALSE;
        controls.currentDevIndex = deviceIndex;
    }
    
    return ret;
}

/**
 * @brief Called when there is a disconnection event (connection lost included)
 * @return  0(BB_SUCCESS): ok, device disconnected correctly\n
 *          1: error, could not disconnect from device\n
 *          2: error, device index out of range\n
 */
uint8_t ScannerMode_OnDisconnection(uint8_t deviceIndex, uint8_t status, uint8_t reason)
{
    uint8_t ret = BB_SUCCESS;
    
    if (deviceIndex >= BB_MAX_SCANNER_BT_CONNS)
    {
        ret = 2u; /* index out of range*/
    }
    else if (status == 0u)
    {
        /* checking if the given device was disconnected connected by the called of this*/
        /* function*/
        if (controls.bbAPPInterface->btConnections[deviceIndex].isConnected == TRUE)
        {
            controls.bbAPPInterface->btConnections[deviceIndex].isConnected = FALSE;
        }
        
        if (controls.bbAPPInterface->btConnections[deviceIndex].isValidated == TRUE)
        {
            /* deciding if disconnection or connection lost*/
            if (controls.disconnectRequestForIndex == deviceIndex)
            {
                controls.hasDisconnection = TRUE;
            }
            else
            {
                controls.hasConnLost = TRUE;
            }
        }
        
        controls.bbAPPInterface->btConnections[deviceIndex].isValidated = FALSE;
        controls.bbAPPInterface->btConnections[deviceIndex].isConnected = FALSE;
        controls.bbAPPInterface->totalConnected--;
    }
    else
    {
        controls.disconnectFailureReason = reason;
        ret = 1u; /* could not disconnect device*/
    }
    
    return ret;
}

/**
 * @brief It checks whether there are commands pending to be processed or not
 * @return  TRUE: is not busy (no more pending commands)
 *          FALSE: not busy
 */
uint8_t ScannerMode_IsBusy(void)
{
    return (controls.lastCommandProcessed == TRUE) ? FALSE : TRUE;
}

/**
 * @brief To be used when checking whether the module is ready to exit its
 * operating state
 * @return  TRUE: yes (ready to exit)
 *          FALSE: no
 */
uint8_t ScannerMode_ReadyToExit(void)
{
    return (controls.state == BBSCNRMD_WAIT_EXIT_CALL) ? TRUE : FALSE;
}

/**
 * @brief Called when the mode shall finally finish its operating state
 * @return BB_SUCCESS
 */
uint8_t ScannerMode_ExitMode(void)
{
    controls.exitRequested = TRUE;
    return BB_SUCCESS;
}

/**
 * @brief Called when a new command has been received for the Scanner mode
 * @param data
 * @param length
 * @return  0(BB_SUCCESS): command received\n
 *          1: BUSY\n
 *          2: invalid command pointer\n
 *          3: command is not acceptable by the SCANNER MODE
 */
uint8_t ScannerMode_OnRxCommand(BBridgeCommand_t * command)
{
    uint8_t ret = BB_SUCCESS;
    int cmdPosition, searchRet;
    
    controls.lastCMDTime = controls.bbAPPInterface->getSystime();
    
    if (controls.lastCommandProcessed == FALSE)
    {
        ret = 1u; /* BUSY*/
    }
    else if (command == NULL)
    {
        ret = 2u; /* invalid command pointer*/
    }
    else
    {
    
        /* check is this mode can accept the command*/
    
        searchRet = BBridgeCommons_FindCMDInList(command->id,
                ACCEPTABLE_COMMANDS,
                TOTAL_ACCEPTABLE_COMMANDS, &cmdPosition);
        if (searchRet < 0)
        {
            /* command not found in the list*/
            ret = 3u;
        }
        else
        {
            /* ok to accept command*/
            controls.commandPosition = (uint8_t) cmdPosition;
            controls.lastCommand.id = command->id;
            controls.lastCommand.cmd.length = command->cmd.length;
            
            if (command->cmd.length > 0u) 
            {
                memcpy(controls.lastCommand.cmd.data, command->cmd.data, (uint16_t) command->cmd.length);
            }
            
            controls.lastCommandProcessed = FALSE; /* setting it to not processed*/
        }
    }
    
    return ret;
}

static void resetOperatingVariables(void)
{
    uint8_t i;
    
    controls.lastCommandProcessed = TRUE;
    controls.isExternalDataProcessed = TRUE;
    controls.hasDisconnection = FALSE;
    controls.hasConnLost = FALSE;
    controls.disconnectRequestForIndex = BB_INVALID_DEV_INDEX;
    controls.state = BBSCNRMD_INIT;
    controls.bbAPPInterface->isConnecting = FALSE;
    controls.bbAPPInterface->btScanBusy = FALSE;
    controls.bbAPPInterface->btScanResultTotal = 0u;
    controls.eventSource = 0u; /* for internal usage only*/
    controls.currentDevIndex = 0u;
    controls.lastDevProcessed = FALSE;
    
    controls.bbAPPInterface->totalConnected = 0u;
    
    for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; ++i)
    {
        controls.bbAPPInterface->btConnections[i].isConnected = FALSE;
        controls.bbAPPInterface->btConnections[i].isValidated = FALSE;
    }
}

static void OnTxToPantherComplete()
{
    if (controls.eventSource == 1u) 
    {
        controls.state = BBSCNRMD_PROCESS_SCAN;
    }
    else
    {
        setCMDAsProcessed();
        controls.state = BBSCNRMD_IDLE;
    }
    
    controls.eventSource = 0u;
    controls.bbAPPInterface->releaseDataHandler(); /* freeing data handler*/
}

#ifdef TESTENVIRONMENT

BB_ScannerMD_State_t * ScannerMode_GetState(void)
{
    return &controls.state;
}

void ScannerMode_SetIsConnecting(uint8_t isConnecting)
{
    controls.isConnecting = isConnecting;
}

#endif


#endif

/** @}*/

