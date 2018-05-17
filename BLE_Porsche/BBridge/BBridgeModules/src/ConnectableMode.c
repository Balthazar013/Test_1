/**
 * \addtogroup ConnectableMode
 * @{
 *
 * @file        ConnectableMode.c
 * @author      p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 *
 * @internal
 * $LastChangedDate: 2018-04-20 09:48:38 +0200 (Fr, 20 Apr 2018) $
 * $LastChangedBy: ksteingass $
 * $Revision: 18932 $
 * $Id: ConnectableMode.c 18932 2018-04-20 07:48:38Z ksteingass $
 *
 */
#ifdef TARGET_PAD

#include "ConnectableMode.h"
#include "BBridgeDefs.h"
#include "BBridgeCommons.h"
#include <stdlib.h>
#include <string.h>
#include "gatt.h"
#include "peripheral.h"

/* number of commands accepted by this operating mode*/
#define TOTAL_ACCEPTABLE_COMMANDS  14u


/*@ATTENTION: this list must be sorted in ascending order*/
static BBridgeCMDId_t ACCEPTABLE_COMMANDS[TOTAL_ACCEPTABLE_COMMANDS] =
{
    BBCMD_SET_BROADCAST_MSG,
    BBCMD_GET_BROADCAST_MSG,
    BBCMD_SET_OP_MODE,
    BBCMD_GET_OP_MODE,
    BBCMD_DISCONNECT,
    BBCMD_SEND_DATA,
    BBCMD_GET_CONN_STATES,
    BBCMD_GET_CONN_RSSI,
    BBCMD_GET_CONN_ADDR,
    BBCMD_REQ_SLEEP,
    BBCMD_SET_BOOT_MODE,
    BBCMD_GET_BOOT_MODE,
    BBCMD_GET_RESET_REASON,
    BBCMD_GET_OWN_ADDR,
};

/**
 * @brief Holds the local attributes for this module
 */
typedef struct
{
    BBConnectableMDState_t state;
    uint8_t eventSource;
    BBridgeCommand_t lastCMD;
    uint8_t isLastCMDProcessed;
    BBridgeAppInterface_t * bbAPPInterface;
    BBridgeNACKReason_t nackReason;
    uint8_t cmdIndex; /*!< for internal purposes only*/
    
    uint8_t hasNewConnection;
    uint8_t hasAuthenticatedConnection;
    
    BBCONNValidConnState_t valConnState;
    uint32_t valConnSeedGenerated;
    uint32_t valConnKeyReceived;
    
    BBridgeCommPacket_t externalData;
    uint8_t isExternalDataProcessed;
    uint8_t currentDevIndex;
    
    uint8_t hasDisconnection;
    uint8_t hasConnectionLost;
    uint8_t hasRequestedDisconnection;
    uint8_t discFailureReason;
    uint8_t waitReason;
    uint8_t exitRequested;
    uint32_t timer;
    uint8_t connLinkUpdating;
    uint16_t connLinkUpdatingHandle;
} BBConnectableMD_Controls_t;



/* private functions*/
static void resetWorkingVariables(void);
static void setCMDAsProcessed(void);
static BBValidResult_t validateConnection(const uint8_t data[], uint8_t length);
static void validateConnectionReset(void);
static void OnTxToPantherComplete(void);
/* private variables*/
static BBConnectableMD_Controls_t controls;


/**
 * @brief It initializes the Connectable mode module
 * @param sharedMemValue
 * @param bbridgeInterface
 * @return  0: BB_SUCCESS\n
 *          1: bad bbridge interface allocation
 *          2: acceptable command list invalid -> must be in ascending order
 *          non-zero: in case of errors
 */
uint8_t ConnectableMode_Init(BBridgeAppInterface_t * bbridgeInterface)
{
    uint8_t i;
    uint8_t ret = BB_SUCCESS;
    
    if (bbridgeInterface == NULL)
    {
        ret = 1u; /* invalid bbridge interface ptr*/
    }
    else
    {
        /* checking acceptable commands list (it must be sorted)*/
        for (i = 0u; i < TOTAL_ACCEPTABLE_COMMANDS - 1u; i++)
        {
            if (ACCEPTABLE_COMMANDS[i] > ACCEPTABLE_COMMANDS[i + 1u])
            {
                ret = 2u;
                break;
            }
        }
        
        if(ret == BB_SUCCESS)
        {
            controls.bbAPPInterface = bbridgeInterface;
            resetWorkingVariables();
        }
    }
    
    return ret;
}

/**
 * @brief Callback called when a new Bluetooth connection (not yet validated)
 * has been established
 * @note: Caller of this function must set the btConnection[devIndex].isConnected=TRUE
 * @return  0(BB_SUCCESS):ok
 *          1: caller of this callback must set "isConnected" value\n
 *          2: cannot accept more than one connection\n
 *          3: index out of range\n
 */
uint8_t ConnectableMode_OnConnection(uint8_t deviceIndex)
{
    uint8_t i;
    uint8_t ret = BB_SUCCESS;
    
    if (deviceIndex >= BB_MAX_SCANNER_BT_CONNS)
    {
        /* note that the BB_MAX_SCANNER_BT_CONNS was used intentionally once*/
        /* the btConnections variables is of that size*/
        ret = 3u; /* index out of range*/
    }
    else
    {
        /* check for previous connected active*/
        for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; ++i)
        {
            if (i != deviceIndex)
            {
                if (controls.bbAPPInterface->btConnections[i].isConnected == TRUE)
                {
                    /* cannot accept more than 1 connection, checking if connection exists.*/
                    ret = 2u;
                    break;
                }
            }
        }
        
        if(ret == BB_SUCCESS)
        {
            /* checking if the index is already connected*/
            if (controls.bbAPPInterface->btConnections[deviceIndex].isConnected == FALSE)
            {
                ret = 1u;
            }
            else
            {
                /* accepting connection*/
                controls.hasNewConnection = TRUE;
                controls.currentDevIndex = deviceIndex;
                controls.bbAPPInterface->btConnections[deviceIndex].isValidated = FALSE;
            }
        }
    }
    
    return ret;
}

/**
 * @brief Called when there is a disconnection event from the bluetooth HW.
 * (connection lost included)
 * @return  0(BB_SUCCESS): processed ok\n
 *          1: device index currently not handled by the op mode\n
 *          2: disconnection failed\n
 */
uint8_t ConnectableMode_OnDisconnection(uint8_t deviceIndex, uint8_t status, uint8_t reason)
{
    uint8_t ret = BB_SUCCESS;
    
    if (status != 0u) 
    {
        /*  could not disconnect */
        controls.discFailureReason = reason;
        ret = 2u;
    }
    else
    {
        if (controls.currentDevIndex == deviceIndex) 
        {
            /* no need to check if it was connected or not. */
            controls.hasNewConnection = FALSE;
            controls.hasAuthenticatedConnection = FALSE;
            
            /* do not reset the device id (currentDevIndex) here*/
            controls.bbAPPInterface->btConnections[deviceIndex].isValidated = FALSE;
            controls.bbAPPInterface->btConnections[deviceIndex].isConnected = FALSE;
            
            if(controls.hasRequestedDisconnection == FALSE)
            {
                    controls.hasConnectionLost = TRUE;
            }
            else
            {
                    controls.hasDisconnection = TRUE;
                    controls.hasRequestedDisconnection = FALSE;
            }
        }
        else
        {
            ret = 1u; /* device index is not currently handled by the op mode */
        }
    }
    
    return ret;
}

void ConnectableMode_OnLinkUpdate(uint16_t connHandle, uint8_t status)
{
    /*(void)status;*/
    controls.connLinkUpdating = FALSE;
    controls.connLinkUpdatingHandle = connHandle;
}

/**
 * @brief Called when a new command has been received from the Panther to the
 * the Connectable mode
 * @param data
 * @param length
 * @return  0(BB_SUCCESS): command received\n
 *          1: BUSY\n
 *          2: invalid command pointer\n
 *          3: command is not acceptable by the CONNECTABLE MODE\n
 */
uint8_t ConnectableMode_OnRxCommand(const BBridgeCommand_t * command)
{
    uint8_t ret = BB_SUCCESS;
    
    if (controls.isLastCMDProcessed == FALSE)
    {
        ret = 1u; /* BUSY*/
    }
    else if (command == NULL)
    {
        ret = 2u; /* invalid command pointer*/
    }
    else
    {
        /* ok to accept command*/
        controls.lastCMD.id = command->id;
        controls.lastCMD.cmd.length = command->cmd.length;
        if(command->cmd.length > 0u)
        {
            memcpy(controls.lastCMD.cmd.data, command->cmd.data, (uint16_t)command->cmd.length);
        }
        controls.isLastCMDProcessed = FALSE; /* setting it to not processed*/
    }
    
    return ret;
}

/**
 * @brief Called when messages from a non-validated connection is received
 * @param devIndex
 * @param data
 * @param dataLength
 * @return  BB_SUCCESS: ok\n
 *          1: busy processing previous external message (dropping new)\n
 *          2: invalid data pointer\n
 *          3: invalid data length (must > 0 and < BB_MAX_EXT_DATA)\n
 *          4: invalid device index\n
 *          5: data from unhandled connection\n
 *          6: cannot receive data from unconnected device\n
 *          7: rejecting data from authenticated connections\n
 *          8: not connected\n
 *          9: data from unexpected connections
 */
uint8_t ConnectableMode_OnRxExtData(BBridgeCommPacket_t *psBrdgComPaket)
{
    uint8_t ret = BB_SUCCESS;
    if (controls.isExternalDataProcessed == FALSE)
    {
        ret = 1u; /* previous data not yet processed (dropping*/
    }
    else if (controls.hasNewConnection == TRUE)
    {
        ret = 5u;
    }
    else if (psBrdgComPaket->unPacketInfo.st.ConnIndex >= BB_MAX_SCANNER_BT_CONNS)
    {
        ret = 4u;
    }
    else if (controls.bbAPPInterface->btConnections[psBrdgComPaket->unPacketInfo.st.ConnIndex].isConnected != TRUE)
    {
        ret = 8u; /* not connected*/
    }
    else if (controls.currentDevIndex != psBrdgComPaket->unPacketInfo.st.ConnIndex)
    {
        ret = 9u;
    }
    else if (controls.bbAPPInterface->btConnections[psBrdgComPaket->unPacketInfo.st.ConnIndex].isValidated == TRUE)
    {
        ret = 7u; /* should not receive data from validated connections*/
        /* authenticated data should go directly to the PANTHER*/
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
 * @brief Check whether the the operating mode can receive more commands or not
 * @return  TRUE: yes: is busy, cannot receive commands\n
 *          FALSE: no: is not busy, ok to receive command\n
 */
uint8_t ConnectableMode_IsBusy(void)
{
    return (controls.isLastCMDProcessed == TRUE) ? FALSE : TRUE;
}

/**
 * @brief Check if the mode is ready to exit or not
 * @return  FALSE: not ready to exit
 *          TRUE: ok to exit
 */
uint8_t ConnectableMode_ReadyToExit(void)
{
    return (controls.state == BBCONNMD_WAIT_EXIT_CALL) ? TRUE : FALSE;
}

/**
 * @brief To be called by the caller module when the Connectable state machine
 * will not be executed anymore. It ensures that the Connectable mode goes back
 * to initial running state;
 * @return  0(BB_SUCCESS): exit ok\n
 *          1: not ready to exit
 */
uint8_t ConnectableMode_ExitMode(void)
{
    uint8_t ret = BB_SUCCESS;
    
    if (ConnectableMode_ReadyToExit() == TRUE)
    {
        controls.exitRequested = TRUE;
    }
    else
    {
        ret = 1u;
    }
    
    return ret;
}

/**
 * @brief State machine for the Connectable operating mode
 * - Wait initialization\n
 * - Load configurations and set them in the bluetooth HW\n
 * - Allows bluetooth stack to start broadcasting\n
 * - Wait for connections\n
 * - Validate peer upon connection\n
 * - "Bridge" incomining bluetooth messages to the Panther\n
 * - Sends received messages from the Panther to the validated connection\n
 */
void ConnectableMode_Work(void)
{
    BBCMDType_t cmdType;
    uint8_t ret, tmp, i;
    /*uint16_t tmpVal, cnnMin, cnnMax;*/
    int index;
    int searchRet;
        
    switch (controls.state)
    {
        case (BBCONNMD_IDLE):
        {
            /* cannot proceed while the bluetooth device mode has not yet been initialized */
            if (controls.bbAPPInterface->isDevInitialized == FALSE)
            {
                controls.state = BBCONNMD_WAIT_DEV_INIT;
            }
            else
            {
                if (controls.isLastCMDProcessed == FALSE)
                {
                    /* check is this mode can accept the command*/
                    searchRet = BBridgeCommons_FindCMDInList(controls.lastCMD.id, ACCEPTABLE_COMMANDS,
                    TOTAL_ACCEPTABLE_COMMANDS, &index);
                    if (searchRet < 0) 
                    {
                            /* command not found in the list*/
                            controls.nackReason = BB_NACK_CMD_UNKNOWN;
                            controls.state = BBCONNMD_SND_NACK;
                    }
                    else
                    {
                        /* there is a new command from Panther available */
                        /* deciding how to process command based on the command type */
                        cmdType = controls.bbAPPInterface->getCMDType(
                                        controls.lastCMD.id);
                        switch(cmdType){
                        case(CMDTYPE_SET):
                                controls.state = BBCONNMD_PROCESS_SETCMD;
                                break;
                        case(CMDTYPE_GET):
                                controls.state = BBCONNMD_PROCESS_GETCMD;
                                break;
                        default:
                                /* Invalid command -> send NACK */
                                controls.nackReason = BB_NACK_CMD_UNKNOWN;
                                controls.state = BBCONNMD_SND_NACK;
                                break;
                        }
                    }
                }
                else if (controls.hasConnectionLost == TRUE)
                {
                    controls.hasConnectionLost = FALSE;
                    /* setting wakeup line to low*/
                    //controls.bbAPPInterface->setWakeUPLine(0u);
                    
                    /* reseting device id */
                    controls.currentDevIndex = BB_INVALID_DEV_INDEX;
                    
                    /* filling up event feedback buffer */
                    controls.bbAPPInterface->sharedMemValue[0] = BB_EVT_CONN_LOST;
                    controls.bbAPPInterface->sharedMemValueLength = BB_MAX_SCANNER_BT_CONNS+1u;
                    for(i=0u; i < BB_MAX_SCANNER_BT_CONNS; ++i)
                    {
                        controls.bbAPPInterface->sharedMemValue[i+1u] = (controls.currentDevIndex==i)?TRUE:FALSE;
                    }
                    
                    controls.state = BBCONNMD_SND_EVT;
                }
                else if (controls.hasAuthenticatedConnection == FALSE)
                {
                    /* there isn't a validated connection active*/
                    /* checking if there is a normal Bluetooth connection available*/
                    if (controls.hasNewConnection == TRUE) 
                    {
                        controls.hasNewConnection = FALSE;
                        controls.state = BBCONNMD_WAITING_VALIDATION;
                        /*if(DEFAULT_ENABLE_UPDATE_REQUEST == TRUE){
                                controls.state = BBCONNMD_WAITING_VALIDATION;
                        }else{
                                controls.state = BBCONNMD_WAITING_VALIDATION;
                        }*/
                        controls.timer = controls.bbAPPInterface->getSystime();
                    }
                }
                else
                {
                    /* not handled */
                }
            }
            
            break;
        }
        
        case(BBCONNMD_WAIT_CONN_PARAMS):
        {
            if(controls.connLinkUpdating == FALSE)
            {
                /* got update*/
                controls.state = BBCONNMD_WAITING_VALIDATION;
            }
            else
            {
                if (controls.bbAPPInterface->getSystimeDiff(controls.timer) >= BBCONN_TIMEOUT)
                {
                    /* disconnection timed out */
                    controls.hasRequestedDisconnection = TRUE;
                    controls.bbAPPInterface->disconnectBTDevice( controls.currentDevIndex);
                    controls.state = BBCONNMD_WAIT_DISCONNECTION;
                    controls.eventSource = 1U; /* to control where to go after disconnection event */
                    controls.timer = controls.bbAPPInterface->getSystime();
                }
            }
            
            break;
        }
        
        case (BBCONNMD_INIT):
        {
            
            controls.state = BBCONNMD_IDLE;
            break;
        }
        
        case (BBCONNMD_WAIT_DEV_INIT):
        {
            /* waiting BT device initialization */
            if (controls.bbAPPInterface->isDevInitialized == TRUE)
            {
                //controls.bbAPPInterface->setWakeUPLine(0u); /* making sure wakeup line is low */
                controls.state = BBCONNMD_IDLE;
            }
            break;
        }
        
        case (BBCONNMD_WAIT_EXIT_CALL):
        {
            if (controls.exitRequested == TRUE) {
                controls.exitRequested = FALSE;
                resetWorkingVariables();
                controls.state = BBCONNMD_IDLE;
            }
            
            break;
        }
        
        case (BBCONNMD_WAIT_DISCONNECTION):
        {
            if (controls.hasDisconnection == TRUE)
            {
                controls.hasDisconnection = FALSE;
                //controls.bbAPPInterface->setWakeUPLine(0u);
                controls.hasAuthenticatedConnection = FALSE;
                controls.bbAPPInterface->btConnections[controls.currentDevIndex].isValidated = FALSE;
                controls.bbAPPInterface->btConnections[controls.currentDevIndex].isConnected = FALSE;
                controls.bbAPPInterface->sharedMemValueLength = 1u;
                controls.bbAPPInterface->sharedMemValue[0] = controls.currentDevIndex;
                controls.currentDevIndex = BB_INVALID_DEV_INDEX;
                if(controls.eventSource == 1u)
                {
                    controls.state = BBCONNMD_IDLE;
                    controls.eventSource = 0u;
                }
                else
                {
                    setCMDAsProcessed();
                    controls.state = BBCONNMD_SND_ACK;
                }
            }
            else
            {
                /* handling timeout */
                if (controls.bbAPPInterface->getSystimeDiff(controls.timer) >= BB_DISCONNECTION_TIMEOUT)
                {
                    controls.timer = controls.bbAPPInterface->getSystime();
                    if(controls.eventSource == 1u)
                    {
                        /* disconnection timed out, go to IDLE */
                        controls.state = BBCONNMD_IDLE;
                        controls.eventSource = 0u;
                    }
                    else
                    {
                        /* failed to disconnect */
                        controls.state = BBCONNMD_SND_NACK;
                        controls.nackReason = BB_NACK_TIMEOUT;
                    }
                }
            }
            
            break;
        }
        
        case (BBCONNMD_PROCESS_GETCMD):
        {
            if( (controls.lastCMD.id == BBCMD_GET_CONN_RSSI)
                ||
                (controls.lastCMD.id == BBCMD_GET_CONN_ADDR))
            {
                if (controls.lastCMD.cmd.length != 1u) 
                {
                    controls.nackReason = BB_NACK_INVALID_REQ;
                    controls.state = BBCONNMD_SND_NACK;
                }
                else
                {
                    tmp = controls.lastCMD.cmd.data[0]; /* dev index*/
                    /* check index*/
                    if (tmp >= BB_MAX_SCANNER_BT_CONNS)
                    {
                        controls.nackReason = BB_NACK_INVALID_REQ;
                        controls.state = BBCONNMD_SND_NACK;
                    }
                    else
                    {
                        /* check connection*/
                        if ( (controls.bbAPPInterface->btConnections[tmp].isConnected == FALSE)
                                ||
                            (controls.bbAPPInterface->btConnections[tmp].isValidated == FALSE))
                        {
                                controls.nackReason = BB_NACK_NOT_CONNECTED;
                                controls.state = BBCONNMD_SND_NACK;
                        }
                        else
                        {
                            /* device requested is valid*/
                            if (controls.lastCMD.id == BBCMD_GET_CONN_RSSI)
                            {
                                /* attention this value should be converted to int8_t*/
                                controls.bbAPPInterface->sharedMemValue[0] = \
                                (uint8_t) controls.bbAPPInterface->btConnections[tmp].btDevice.rssi;
                                
                                controls.bbAPPInterface->sharedMemValueLength = 1U;
                            }
                            else if (controls.lastCMD.id == BBCMD_GET_CONN_ADDR)
                            {
                                memcpy(controls.bbAPPInterface->sharedMemValue,
                                       controls.bbAPPInterface->btConnections[tmp].btDevice.addr,
                                       6u);
                                controls.bbAPPInterface->sharedMemValueLength = 6u;
                            }
                            else
                            {
                                /* not handled */
                            }
                            
                            controls.state = BBCONNMD_SND_ACK;
                        }
                    }
                }
            }
            else if(controls.lastCMD.id == BBCMD_GET_CONN_STATES)
            {
                controls.bbAPPInterface->sharedMemValueLength = BB_MAX_SCANNER_BT_CONNS;
                for(i=0u; i < BB_MAX_SCANNER_BT_CONNS; ++i)
                {
                    controls.bbAPPInterface->sharedMemValue[i] = (controls.currentDevIndex==i)?TRUE:FALSE;
                }
                controls.state = BBCONNMD_SND_ACK;
            }
            else if(controls.lastCMD.id  == BBCMD_GET_OWN_ADDR)
            {
                GAPRole_GetParameter(GAPROLE_BD_ADDR, controls.bbAPPInterface->sharedMemValue);
                controls.bbAPPInterface->sharedMemValueLength = 6u;
                controls.state = BBCONNMD_SND_ACK;
            }
            else
            {
                /* normal configurations*/
                ret = controls.bbAPPInterface->proccessGetCmd( &controls.lastCMD,
                                                    controls.bbAPPInterface->sharedMemValue,
                                                    &controls.bbAPPInterface->sharedMemValueLength);
                if (ret == BB_SUCCESS)
                {
                    controls.state = BBCONNMD_SND_ACK;
                } 
                else 
                {
                    controls.nackReason = BB_NACK_CMD_UNKNOWN;
                    controls.state = BBCONNMD_SND_NACK;
                }
            }
            
            break;
        }
        
        case (BBCONNMD_PROCESS_SETCMD):
        {
            switch(controls.lastCMD.id) 
            { /* begin set command switch */
                case(BBCMD_REQ_SLEEP):
                {
                    controls.state = BBCONNMD_SND_ACK;
                    break;
                }
                
                case(BBCMD_DISCONNECT):
                {
                    /* controls.lastCommand.cmd.data[0] the device ID to be disconnected
                    in the case of connectable, this value does not matter since
                    connectable shall only hold 1 connection */
                    if (controls.lastCMD.cmd.length == 0u)
                    {
                        controls.nackReason = BB_NACK_INVALID_REQ;
                        controls.state = BBCONNMD_SND_NACK;
                    }
                    else
                    {
                        if (controls.lastCMD.cmd.data[0] == controls.currentDevIndex)
                        {
                            controls.hasRequestedDisconnection = TRUE;
                            if (controls.bbAPPInterface->disconnectBTDevice(controls.currentDevIndex) == BB_SUCCESS)
                            {
                                controls.state = BBCONNMD_WAIT_DISCONNECTION;
                                controls.eventSource = 0u; /* to control where to go after disconnection event */
                                controls.timer = controls.bbAPPInterface->getSystime();
                            }
                            else
                            {
                                controls.nackReason = BB_NACK_INTERNAL_ERROR;
                                controls.state = BBCONNMD_SND_NACK;
                            }
                        }
                        else
                        {
                            controls.nackReason = BB_NACK_NOT_CONNECTED;
                            controls.state = BBCONNMD_SND_NACK;
                        }
                    }
                    break;
                }
                
                case(BBCMD_SEND_DATA):
                {
                    /* the first byte must be the device index*/
                    /* second byte must be the first valid data byte*/
                    if (controls.lastCMD.cmd.length < 2u)
                    {
                        /* there is no valid data to be transfered*/
                        controls.nackReason = BB_NACK_INVALID_REQ;
                        controls.state = BBCONNMD_SND_NACK;
                    }
                    else
                    {
                        /* check if can send*/
                        if (controls.lastCMD.cmd.data[0] == controls.currentDevIndex)
                        {
                            if ((controls.bbAPPInterface->btConnections[controls.currentDevIndex].isConnected == TRUE)
                                && 
                                (controls.bbAPPInterface->btConnections[controls.currentDevIndex].isValidated == TRUE)) 
                            {
                                /* ok to send*/
                                ret = controls.bbAPPInterface->sendBTDataCommand(
                                                controls.currentDevIndex,
                                                &controls.lastCMD.cmd.data[1], /* [0] is device ID*/
                                                (uint8_t) (controls.lastCMD.cmd.length - 1u));
                                if (ret == BB_SUCCESS) 
                                {
                                    controls.bbAPPInterface->sharedMemValueLength = 0u;
                                    controls.waitReason = 1u; 
                                    OnTxToPantherComplete();
                                } 
                                else 
                                {
                                    /* could not send*/
                                    controls.nackReason = BB_NACK_SEND_ERROR;
                                    controls.state = BBCONNMD_SND_NACK;
                                }
                            }
                            else
                            {
                                controls.nackReason = BB_NACK_NOT_CONNECTED;
                                controls.state = BBCONNMD_SND_NACK;
                            }
                        }
                        else 
                        {
                                controls.nackReason = BB_NACK_INVALID_REQ;
                                controls.state = BBCONNMD_SND_NACK;
                        }
                    }
                    
                    break;
                }
                
                case(BBCMD_SET_OP_MODE):
                {
                    if (controls.lastCMD.cmd.data[0] == BB_IDLE_MODE)
                    {
                        /* exiting connectable mode*/
                        if (controls.bbAPPInterface->btConnections[controls.currentDevIndex].isConnected == TRUE)
                        {
                            controls.bbAPPInterface->disconnectBTDevice(controls.currentDevIndex);
                        }
                        controls.exitRequested = FALSE;
                        controls.state = BBCONNMD_WAIT_EXIT_CALL;
                    } 
                    else 
                    {
                        //controls.nackReason = BB_NACK_CMD_UNKNOWN;
                        controls.state = BBCONNMD_SND_ACK;
                    }
                    
                    break;
                }
                
                default:
                {
                    ret = controls.bbAPPInterface->proccessSetCmd(&controls.lastCMD);
                    if (ret == BB_SUCCESS)
                    {
                        controls.state = BBCONNMD_SND_ACK;
                        controls.bbAPPInterface->sharedMemValueLength = 0u;
                    }
                    else
                    {
                        /* error processing -> send NACK*/
                        controls.nackReason = BB_NACK_CMD_UNKNOWN; /* TODO check correct NACK reason*/
                        controls.state = BBCONNMD_SND_NACK;
                    }
                    
                    break;
                }
            /* end set command switch */
            }
            
            break;
        }
        
        case (BBCONNMD_SND_NACK):
        {
            ret = controls.bbAPPInterface->pushNACK(controls.lastCMD.id,
                                                    controls.nackReason);
            if (ret == BB_SUCCESS) 
            {
                /* data was pushed to be transmitted correctly*/
                controls.waitReason = 1u; /* normal*/
                controls.state = BBCONNMD_WAIT_TX2PANTHER;
            } 
            else 
            {
                /* could not push NACK... try again*/
            }
            
            break;
        }
        
        case (BBCONNMD_SND_EVT):
        {
            /* processed correctly -> send ACK*/
            ret = controls.bbAPPInterface->pushEVENT(
                                        (BBridgeEvents_t) controls.bbAPPInterface->sharedMemValue[0],
                                        &controls.bbAPPInterface->sharedMemValue[1],
                                        (uint8_t)(controls.bbAPPInterface->sharedMemValueLength - 1u));
            if (ret == BB_SUCCESS) 
            {
                /* data was pushed to be transmitted correctly*/
                controls.waitReason = 3U; /* normal*/
                controls.state = BBCONNMD_WAIT_TX2PANTHER;
            } 
            else 
            {
                /* could not push EVT... try again*/
            }
            
            break;
        }
        
        case (BBCONNMD_SND_ACK):
        {
            /* processed correctly -> send ACK*/
            ret = controls.bbAPPInterface->pushACK(controls.lastCMD.id,
                                                    controls.bbAPPInterface->sharedMemValue,
                                                    controls.bbAPPInterface->sharedMemValueLength);
            if (ret == BB_SUCCESS)
            {
                /* data was pushed to be transmitted correctly*/
                controls.waitReason = 1u; /* normal*/
                controls.state = BBCONNMD_WAIT_TX2PANTHER;
            }
            else 
            {
                /* could not push ACK... try again*/
            }
            
            break;
        }
        
        case (BBCONNMD_WAIT_TX2PANTHER):
        {
            if (controls.bbAPPInterface->isTxToPantherComplete() == TRUE)
            {
                OnTxToPantherComplete();
            }
            
            break;
        }
        
        case (BBCONNMD_WAITING_VALIDATION):
        {
            if(BB_VALIDATION_ENABLED == TRUE)
            {
                /* Waiting to receive data from the bluetooth channel */
                if(controls.isExternalDataProcessed == FALSE)
                {
                    /* received new data */
                    /* check if it comes from the expected source */
                    if (controls.currentDevIndex != controls.externalData.unPacketInfo.st.ConnIndex)
                    {
                        /* data came from an unexpected connection handler, ignore data */
                        controls.isExternalDataProcessed = TRUE;
                        
                        /* disconnecting from other device */
                        (void) controls.bbAPPInterface->disconnectBTDevice(controls.externalData.unPacketInfo.st.ConnIndex);
                        /* do nothing, let it timeout */
                    }
                    else
                    {
                        /* data comes from the expected source */
                        switch(validateConnection(controls.externalData.unPacketData.st.data, controls.externalData.unPacketInfo.st.DataLength))
                        {
                            case(BBVAL_BUSY):
                                break;
                            case(BBVAL_PASS):
                                //controls.bbAPPInterface->setWakeUPLine(1u);
                                validateConnectionReset();
                                controls.state = BBCONNMD_WAIT_FOR_PANTHER;
                                controls.timer = controls.bbAPPInterface->getSystime();
                                break;
                            default:
                                validateConnectionReset();
                                controls.state = BBCONNMD_AUTH_FAIL;
                                break;
                        }
                        
                        controls.isExternalDataProcessed = TRUE;
                    }
                }
                else if (controls.bbAPPInterface->getSystimeDiff(controls.timer) >= BB_VALIDATION_TIMEOUT)
                {
                    /* validation timed out */
                    controls.timer = controls.bbAPPInterface->getSystime();
                    controls.state = BBCONNMD_AUTH_FAIL;
                    validateConnectionReset();
                }
                else
                {
                    /* just wait */
                }
            }
            else
            {
                //controls.bbAPPInterface->setWakeUPLine(1u);
                controls.state = BBCONNMD_WAIT_FOR_PANTHER;
                controls.timer = controls.bbAPPInterface->getSystime();
            }
            
            break;
        }
        
        case(BBCONNMD_WAIT_FOR_PANTHER):
        {
            if(controls.bbAPPInterface->getSystimeDiff(controls.timer) > 1)
            {
                controls.timer = controls.bbAPPInterface->getSystime();
                controls.state = BBCONNMD_AUTH_PASS;
            }
            
            break;
        }
        
        case (BBCONNMD_AUTH_PASS):
        {
            /* notifying upper layers that this connection has been validated */
            controls.bbAPPInterface->onConnectionValidated(controls.currentDevIndex);
            
            /* waking up panther */
            controls.hasAuthenticatedConnection = TRUE;
            controls.bbAPPInterface->sharedMemValue[0] = BB_EVT_CONN_ESTABLISHED;
            controls.bbAPPInterface->sharedMemValueLength = 4u;
            
            for(i=0u; i < BB_MAX_SCANNER_BT_CONNS; ++i)
            {
                controls.bbAPPInterface->sharedMemValue[1u+i] = (controls.currentDevIndex==i)?TRUE:FALSE;
            }
            
            controls.state = BBCONNMD_SND_EVT;
            
            break;
        }
        
        case (BBCONNMD_AUTH_FAIL):
        {
            controls.hasAuthenticatedConnection = FALSE;
            controls.bbAPPInterface->btConnections[controls.currentDevIndex].isValidated = FALSE;
            /*controls.currentDevIndex = BB_INVALID_DEV_INDEX;*/
            //controls.bbAPPInterface->setWakeUPLine(0u);
            controls.eventSource = 1u; /* to control where to go after disconnection event */
            controls.state = BBCONNMD_WAIT_DISCONNECTION;
            controls.hasRequestedDisconnection = TRUE;
            controls.bbAPPInterface->disconnectBTDevice(controls.currentDevIndex);
            
            break;
        }
        
        default:
        {
            controls.state = BBCONNMD_WAIT_DEV_INIT;
            break;
        }
    }
}


/*
-----------------------------------------------------------------------------
Private functions
-----------------------------------------------------------------------------
*/

/**
 * @brief It sets the current command as processed. Thus freeing the module to
 * receive more commands
 */
static void setCMDAsProcessed(void)
{
    controls.isLastCMDProcessed = TRUE;
}

/**
 * It validated the connection
 * @return BBVALResult_t
 */
static BBValidResult_t validateConnection(const uint8_t data[], uint8_t length)
{
    uint8_t tmpData[5];
    BBValidResult_t ret=BBVAL_BUSY;
    
    switch (controls.valConnState)
    {
        case (BBVLDCONN_IDLE):
        {
            /* checking if data received from the bluetooth is a SEED request*/
            if ( (data[0] == BB_SEED_REQ) && (length == 1U) )
            {
                /* sending seed response*/
                controls.valConnSeedGenerated = controls.bbAPPInterface->generateSeed();
                tmpData[0] = (uint8_t) BB_SEED_RESP; /* seed tx*/
                tmpData[1] = (uint8_t) (controls.valConnSeedGenerated & 0xFFu);
                tmpData[2] = (uint8_t) ((controls.valConnSeedGenerated >> 8u) & 0xFFu);
                tmpData[3] = (uint8_t) ((controls.valConnSeedGenerated >> 16u) & 0xFFu);
                tmpData[4] = (uint8_t) ((controls.valConnSeedGenerated >> 24u) & 0xFFu);
                
                if (controls.bbAPPInterface->sendBTData(controls.currentDevIndex, tmpData, 5u) 
                     == BB_SUCCESS) 
                {
                    controls.valConnState = BBVLDCONN_CHECK_KEY;
                }
                else
                {
                    ret = BBVAL_ERROR;
                }
            }
            else
            {
                controls.valConnState = BBVLDCONN_AUTH_FAILED;
            }
            
            break;
        }
        case (BBVLDCONN_CHECK_KEY):
        {
            if ((data[0] == BB_KEY_RESP) && (length == 5u))
            {
                /* received a key response*/
                controls.valConnKeyReceived = (uint32_t)data[1];
                controls.valConnKeyReceived |= ((uint32_t)data[2] << 8u);
                controls.valConnKeyReceived |= ((uint32_t) data[3] << 16u);
                controls.valConnKeyReceived |= ((uint32_t) data[4] << 24u);
                
                /* checking KEY*/
                if (controls.valConnKeyReceived == 
                    controls.bbAPPInterface->calculateAuthKey(controls.valConnSeedGenerated))
                {
                    controls.bbAPPInterface->sharedMemValue[0] = BB_KEY_PASS;
                    
                    if(controls.bbAPPInterface->sendBTData(controls.currentDevIndex,
                            controls.bbAPPInterface->sharedMemValue, 1u) == BB_SUCCESS)
                    {
                        controls.valConnState = BBVLDCONN_AUTH_PASS;
                        ret = BBVAL_PASS;
                    }
                    else
                    {
                        controls.valConnState = BBVLDCONN_AUTH_ERROR;
                        ret = BBVAL_ERROR;
                    }
                }
                else
                {
                    controls.valConnState = BBVLDCONN_AUTH_FAILED;
                    ret = BBVAL_FAILED;
                }
            } 
            else 
            {
                controls.valConnState = BBVLDCONN_AUTH_FAILED;
                ret = BBVAL_FAILED;
            }
            
            break;
        }
        
        case (BBVLDCONN_AUTH_PASS):
        {
            ret = BBVAL_PASS;
            break;
        }
        
        case (BBVLDCONN_AUTH_FAILED):
        {
            ret = BBVAL_FAILED;
            break;
        }
        
        case(BBVLDCONN_AUTH_ERROR):
        {
            ret = BBVAL_ERROR;
            break;
        }
        
        default:
        {
            controls.valConnState = BBVLDCONN_IDLE;
            break;
        }
    }
    
    return ret;
}

static void validateConnectionReset(void)
{
    controls.valConnState = BBVLDCONN_IDLE;
}



/**
 * @brief it resets working variables for this module
 */
static void resetWorkingVariables(void)
{
    controls.hasNewConnection = FALSE;
    controls.hasConnectionLost = FALSE;
    controls.hasRequestedDisconnection = FALSE;
    controls.hasAuthenticatedConnection = FALSE;
    controls.isLastCMDProcessed = TRUE;
    controls.isExternalDataProcessed = TRUE;
    controls.hasDisconnection = FALSE;
    controls.state = BBCONNMD_WAIT_DEV_INIT;
}

static void OnTxToPantherComplete()
{
    if (controls.waitReason == 1u)
    {
        setCMDAsProcessed();
    }
    else if (controls.waitReason == 2u)
    {
        /* waiting disconnection evt TX*/
    }
    else 
    {
        /* waiting data evt (from BB->PANTHER) TX complete*/
    }
    
    if(controls.lastCMD.id == BBCMD_REQ_SLEEP)
    {
        /* a rising edge on the wakeup line is required to switch-off the main relay - PAC C0 sample*/
        controls.bbAPPInterface->setWakeUPLine(1u);
    }
    
    controls.state = BBCONNMD_IDLE;
    controls.waitReason = 0u; /* resetting*/
    controls.bbAPPInterface->releaseDataHandler(); /* freeing data handler*/
}

#ifdef TESTENVIRONMENT
BBConnectableMDState_t * ConnectableMode_GetState(void)
{
    return &controls.state;
}

const BBCONNValidConnState_t * ConnectableMode_GetValConnState(void)
{
    return &controls.valConnState;
}
#endif


#endif

/** @}*/
