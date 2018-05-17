/**
 * \addtogroup Scanner
 * @{
 *
 * @file 	Scanner.c
 * @author	p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * \addtogroup Scanner
 * @{
 * detailed description here
 * @}
 *
 * @internal
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * $Revision: 18134 $
 * $Id: Scanner.c 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */

#ifdef TARGET_ORU

// code here
#include "Scanner.h"
#include "gapgattserver.h"
#include "gapbondmgr.h"
#include "central.h"
#include "BBridgeDefs.h"
#include "gattservapp.h"
#include "gatt.h"
#include <string.h>
#include "BBridgeApp.h"
#include "hci.h"
#include "BBridgeGATTprofile.h"

#define WR_REQ_NO_RSP_DATA_SIZE     (uint8)(18)
#define WR_REQ_NO_RSP_HDR_SIZE      (uint8)(1)

// Application states
enum
{
  BLE_STATE_IDLE,
  BLE_STATE_CONNECTING,
  BLE_STATE_CONNECTED,
  BLE_STATE_DISCONNECTING
};

// Discovery states
enum
{
  BLE_DISC_STATE_IDLE,                // Idle
  BLE_DISC_STATE_SVC,                 // Service discovery
  BLE_DISC_STATE_CHAR                 // Characteristic discovery
};

static uint8 scannerBLEEventCB(gapCentralRoleEvent_t *pEvent);
static void onRSSICB(uint16_t connHandle, int8 rssi);

static BBridgeInterface_t * interface;

static uint8_t* puCurrFltMsg;

static const gapCentralRoleCB_t scannerBLECBs =
{
    onRSSICB, // RSSI callback
    scannerBLEEventCB  // Event callback
};

// Bond Manager Callbacks
static const gapBondCBs_t scannerBondCBs = { NULL, NULL };

// GAP GATT Attributes
static const uint8 attDeviceName[] = "AWC Onboard Unit";

// Discovered service start and end handle
static uint16 BBridgeBleSvcStartHdl = 0;
static uint16 BBridgeBleSvcEndHdl = 0;

// Discovered characteristic handle
static uint16 BBridgeBleCharHdl = 0;

// Connection handle of current connection 
static uint16 BBridgeBleConnHandle = GAP_CONNHANDLE_INIT;

// Discovery state
static uint8 BBridgeBleDiscState = BLE_DISC_STATE_IDLE;

// Application state
static uint8 BBridgeBleState = BLE_STATE_IDLE;

// GATT read/write procedure state
static bool BBridgeBleProcedureInProgress = FALSE;

/**
 * @brief   RSSI callback.
 * @param   rssi - RSSI
 */
static void onRSSICB(uint16_t connHandle, int8 rssi)
{
    interface->onBLERSSI(connHandle, rssi);
}

/**
 * @brief   Central (scanner) event callback function.
 * @param   pEvent - pointer to event structure
 * @return  TRUE if safe to deallocate event message, FALSE otherwise.
 */
static uint8 scannerBLEEventCB(gapCentralRoleEvent_t *pEvent)
{
    uint8 ret;
    
    switch (pEvent->gap.opcode)
    {
        case (GAP_DEVICE_INIT_DONE_EVENT):
        {
            interface->onBTDeviceInit();
            break;
        }
        
        case (GAP_DEVICE_INFO_EVENT):
        {
            if (
                ((pEvent->deviceInfo.eventType == GAP_ADRPT_SCAN_RSP) && 
                 (memcmp(pEvent->deviceInfo.pEvtData, puCurrFltMsg, 6U) == 0))
                  ||
                ((pEvent->deviceInfo.eventType == GAP_ADRPT_ADV_NONCONN_IND) && 
                 (memcmp((uint8 *)(pEvent->deviceInfo.pEvtData + 3), puCurrFltMsg, 6U) == 0))
               )
            {
                interface->scannerOnDeviceDiscovered(pEvent->deviceInfo.rssi,
                                                     pEvent->deviceInfo.addrType,
                                                     pEvent->deviceInfo.addr,
                                                     pEvent->deviceInfo.pEvtData,
                                                     pEvent->deviceInfo.dataLen);
            }
            break;
        }
        
        case (GAP_DEVICE_DISCOVERY_EVENT):
        {
            interface->onDiscoveryReady();
            break;
        }
        
        case (GAP_LINK_ESTABLISHED_EVENT):
        {
            ret = interface->onBTConnection(pEvent->gap.hdr.status,
                                            pEvent->linkCmpl.connectionHandle, 
                                            pEvent->linkCmpl.devAddr);
            if (ret != 0)
            {
                BBridgeBleState = BLE_STATE_IDLE;
                BBridgeBleConnHandle = GAP_CONNHANDLE_INIT;
                BBridgeBleDiscState = BLE_DISC_STATE_IDLE;
                
                interface->terminateConnection(pEvent->linkCmpl.connectionHandle);
            }
            else
            {
                BBridgeBleState = BLE_STATE_CONNECTED;
                BBridgeBleConnHandle = pEvent->linkCmpl.connectionHandle;
                BBridgeBleProcedureInProgress = TRUE;
                
                GAPCentralRole_UpdateLink( BBridgeBleConnHandle,
                                            DEFAULT_DESIRED_MIN_CONN_INTERVAL,
                                            DEFAULT_DESIRED_MAX_CONN_INTERVAL,
                                            DEFAULT_DESIRED_SLAVE_LATENCY,
                                            DEFAULT_DESIRED_CONN_TIMEOUT);
                
                // If service discovery not performed initiate service discovery
                if ( BBridgeBleCharHdl == 0 )
                {
                    osal_start_timerEx( interface->taskID , BBRIDGE_START_DISCOVERY_EVT, BBRIDGE_SVC_DISCOVERY_DELAY );
                }
            }
            
            break;
        }
        
        case (GAP_LINK_TERMINATED_EVENT):
        {
            BBridgeBleState = BLE_STATE_IDLE;
            BBridgeBleConnHandle = GAP_CONNHANDLE_INIT;
            BBridgeBleDiscState = BLE_DISC_STATE_IDLE;
            BBridgeBleProcedureInProgress = FALSE;
            
            interface->onBTDisconnection(pEvent->linkTerminate.hdr.status,
                                         pEvent->linkTerminate.connectionHandle,
                                         pEvent->linkTerminate.reason);
            break;
        }
        
        case (GAP_LINK_PARAM_UPDATE_EVENT):
        {
            interface->onLinkUpdate(pEvent->linkUpdate.connectionHandle, pEvent->linkUpdate.status);
            break;
        }
        
        default:
            break;
    }
    
    return (TRUE);
}

void ScannerInit(BBridgeInterface_t * anInterface)
{
    interface = anInterface;
    
    puCurrFltMsg = BBridge_GetFilterMessage(); //TODO: shall be shifted BBridge interface
    
    // Setup Central Profile
    {
        uint8 scanRes = BB_MAX_SCAN_RES;
        GAPCentralRole_SetParameter ( GAPCENTRALROLE_MAX_SCAN_RES, sizeof( uint8 ), &scanRes );
    }
    
    // Setup GAP
    GAP_SetParamValue(TGAP_GEN_DISC_SCAN, DEFAULT_SCAN_DURATION);
    GAP_SetParamValue(TGAP_LIM_DISC_SCAN, DEFAULT_SCAN_DURATION);
    GGS_SetParameter( GGS_DEVICE_NAME_ATT, sizeof(attDeviceName), (uint8 *)attDeviceName );
    
    // Setup the GAP Bond Manager
    {
        uint8 pairMode = DEFAULT_PAIRING_MODE;
        uint8 mitm = DEFAULT_MITM_MODE;
        uint8 ioCap = DEFAULT_IO_CAPABILITIES;
        uint8 bonding = DEFAULT_BONDING_MODE;
        
        GAPBondMgr_SetParameter(GAPBOND_PAIRING_MODE, sizeof(uint8), &pairMode);
        GAPBondMgr_SetParameter(GAPBOND_MITM_PROTECTION, sizeof(uint8), &mitm);
        GAPBondMgr_SetParameter(GAPBOND_IO_CAPABILITIES, sizeof(uint8), &ioCap);
        GAPBondMgr_SetParameter(GAPBOND_BONDING_ENABLED, sizeof(uint8), &bonding);
    }
    
    // Initialize GATT Client
    VOID GATT_InitClient();
    
    // Register to receive incoming ATT Indications/Notifications
    GATT_RegisterForInd(interface->taskID);
    
    // Initialize GATT attributes
    GGS_AddService( GATT_ALL_SERVICES );         // GAP
    GATTServApp_AddService( GATT_ALL_SERVICES ); // GATT attributes
    
    // Turn on overlapped processing
    HCI_EXT_HaltDuringRfCmd(HCI_EXT_HALT_DURING_RF_DISABLE);
    HCI_EXT_OverlappedProcessingCmd(HCI_EXT_ENABLE_OVERLAPPED_PROCESSING);
    
}

void ScannerStartDevice(void)
{
    // Start the Device
    VOID GAPCentralRole_StartDevice((gapCentralRoleCB_t *) &scannerBLECBs);
    
    // Register with bond manager after starting device
    GAPBondMgr_Register((gapBondCBs_t *) &scannerBondCBs);
    
}

uint8 ScannerStartDiscovery(void)
{
    uint8 ret = GAPCentralRole_StartDiscovery(DEFAULT_DISCOVERY_MODE,
                                              DEFAULT_DISCOVERY_ACTIVE_SCAN, 
                                              DEFAULT_DISCOVERY_WHITE_LIST);
    if (ret != SUCCESS) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

uint8 ScannerConnect(const uint8 * peerAddr, uint8 addrType)
{
    uint8_t tmp[6];
    osal_memcpy(tmp, peerAddr, 6);
    
    BBridgeBleState = BLE_STATE_CONNECTING;
    
    return GAPCentralRole_EstablishLink(DEFAULT_LINK_HIGH_DUTY_CYCLE,
                                        DEFAULT_LINK_WHITE_LIST, addrType, tmp);
}

uint8 ScannerUpdateLink(uint16 connHandle, uint16 connIntervalMin, 
                        uint16 connIntervalMax, uint16 connLatency, uint16 connTimeout)
{
    return GAPCentralRole_UpdateLink( connHandle, connIntervalMin, 
                                      connIntervalMax, connLatency, connTimeout);
}

uint8 ScannerPeriodicChecks(void)
{
    //GAPCentralRole_StartRssi( simpleBLEConnHandle, DEFAULT_RSSI_PERIOD );
    return 0;
}

void ScannerStartServiceDiscovery( void )
{
  uint8 uuid[ATT_BT_UUID_SIZE] = { LO_UINT16(SIMPLEPROFILE_SERV_UUID),
                                   HI_UINT16(SIMPLEPROFILE_SERV_UUID) };
  
  // Initialize cached handles
  BBridgeBleSvcStartHdl = BBridgeBleSvcEndHdl = BBridgeBleCharHdl = 0;

  BBridgeBleDiscState = BLE_DISC_STATE_SVC;
  
  // Discovery simple BLE service
  GATT_DiscPrimaryServiceByUUID( BBridgeBleConnHandle,
                                 uuid,
                                 ATT_BT_UUID_SIZE,
                                 interface->taskID);
}

void ScannerProcessGATTMsg( gattMsgEvent_t *pMsg )
{
    if ( BBridgeBleState != BLE_STATE_CONNECTED )
    {
        return;
    }
    
    if (pMsg->method == ATT_HANDLE_VALUE_NOTI)
    {
        /* || (gatMsg->method == ATT_HANDLE_VALUE_IND */
        if((pMsg->msg.handleValueNoti.len > 0)
            &&
        (pMsg->msg.handleValueNoti.len <= BB_MAX_EXT_DATA))
        {
            interface->HandleReceivedFrame(pMsg->connHandle, pMsg->msg.handleValueNoti.pValue, pMsg->msg.handleValueNoti.len);
        }
    }
    else if ( ( pMsg->method == ATT_READ_RSP ) ||
            ( ( pMsg->method == ATT_ERROR_RSP ) && ( pMsg->msg.errorRsp.reqOpcode == ATT_READ_REQ ) ) )
    {
        BBridgeBleProcedureInProgress = FALSE;
    }
    else if ( ( pMsg->method == ATT_WRITE_RSP ) ||
            ( ( pMsg->method == ATT_ERROR_RSP ) && ( pMsg->msg.errorRsp.reqOpcode == ATT_WRITE_REQ ) ) )
    {
        BBridgeBleProcedureInProgress = FALSE;
    }
    else if ( BBridgeBleDiscState != BLE_DISC_STATE_IDLE )
    {
        if ( BBridgeBleDiscState == BLE_DISC_STATE_SVC )
        {
            // Service found, store handles
            if ( pMsg->method == ATT_FIND_BY_TYPE_VALUE_RSP &&
                 pMsg->msg.findByTypeValueRsp.numInfo > 0 )
            {
                BBridgeBleSvcStartHdl = ATT_ATTR_HANDLE(pMsg->msg.findByTypeValueRsp.pHandlesInfo, 0);
                BBridgeBleSvcEndHdl = ATT_GRP_END_HANDLE(pMsg->msg.findByTypeValueRsp.pHandlesInfo, 0);
            }
            
            // If procedure complete
            if ( ( pMsg->method == ATT_FIND_BY_TYPE_VALUE_RSP && pMsg->hdr.status == bleProcedureComplete )
                  ||
                ( pMsg->method == ATT_ERROR_RSP ) 
               )
            {
                if ( BBridgeBleSvcStartHdl != 0 )
                {
                    attReadByTypeReq_t req;
                    
                    // Discover characteristic
                    BBridgeBleDiscState = BLE_DISC_STATE_CHAR;
                    
                    req.startHandle = BBridgeBleSvcStartHdl;
                    req.endHandle   = BBridgeBleSvcEndHdl;
                    req.type.len = ATT_BT_UUID_SIZE;
                    req.type.uuid[0] = LO_UINT16(SIMPLEPROFILE_CHAR1_UUID);
                    req.type.uuid[1] = HI_UINT16(SIMPLEPROFILE_CHAR1_UUID);
            
                    GATT_ReadUsingCharUUID(BBridgeBleConnHandle, &req, interface->taskID);
                }
            }
        }
        else if ( BBridgeBleDiscState == BLE_DISC_STATE_CHAR )
        {
            // Characteristic found, store handle
            if ( pMsg->method == ATT_READ_BY_TYPE_RSP && pMsg->msg.readByTypeRsp.numPairs > 0 )
            {
                BBridgeBleCharHdl = BUILD_UINT16(pMsg->msg.readByTypeRsp.pDataList[0],
                                                pMsg->msg.readByTypeRsp.pDataList[1]);
                                                
                BBridgeBleProcedureInProgress = FALSE;
            }
            
            BBridgeBleDiscState = BLE_DISC_STATE_IDLE;
        }
    }
}

uint8 ScannerTxData(uint16_t connHandle, const uint8 * data, uint8 dataLength)
{
    static uint8 uTxSeqIdx = 1;
    attWriteReq_t wrReq;
    uint8 uTotalFrameCnt;
    uint8 currDataLength;
    uint8 currFrameLength;
    uint8 i;
    uint8 ret = BB_SUCCESS;
    
    if ( (BBridgeBleState != BLE_STATE_CONNECTED)||
         (BBridgeBleCharHdl == 0) ||
         (BBridgeBleProcedureInProgress == TRUE))
    {
        return 3;
    }
    
     uTotalFrameCnt = dataLength/WR_REQ_NO_RSP_DATA_SIZE;
    if((dataLength % WR_REQ_NO_RSP_DATA_SIZE) != 0)
    {
        uTotalFrameCnt++;
    }
    
    if(uTxSeqIdx >= 4)
    {
        uTxSeqIdx = 1;
    }
    
    currDataLength = dataLength;
    
    for (i = 0; i < uTotalFrameCnt; i++)
    {
        
        if(currDataLength >= WR_REQ_NO_RSP_DATA_SIZE)
        {
            currFrameLength = WR_REQ_NO_RSP_DATA_SIZE + WR_REQ_NO_RSP_HDR_SIZE;
            currDataLength -= WR_REQ_NO_RSP_DATA_SIZE;
        }
        else
        {
            currFrameLength = currDataLength + WR_REQ_NO_RSP_HDR_SIZE;
            currDataLength = 0;
        }
        
        wrReq.pValue = GATT_bm_alloc(BBridgeBleConnHandle, ATT_WRITE_REQ, currFrameLength, NULL);
        if (wrReq.pValue != NULL)
        {
            wrReq.pValue[0]  = ((uTxSeqIdx &0x03)<<6);
            wrReq.pValue[0] |= ((uTotalFrameCnt &0x07)<<3);
            wrReq.pValue[0] |= ((i+1) &0x07);
            osal_memcpy(&wrReq.pValue[1], &data[i*WR_REQ_NO_RSP_DATA_SIZE],\
                        (currFrameLength - WR_REQ_NO_RSP_HDR_SIZE));
            wrReq.len = currFrameLength;
            wrReq.sig = FALSE;
            wrReq.cmd = TRUE;
            wrReq.handle = BBridgeBleCharHdl;
            
            if(GATT_WriteNoRsp(BBridgeBleConnHandle, &wrReq) != SUCCESS)
            {
                GATT_bm_free((gattMsg_t *) &wrReq, ATT_WRITE_REQ);
                ret = 1;
                break;
            }
        }
        else
        {
            ret = 2;
            break;
        }
    }
    
    uTxSeqIdx++;
    
    return ret;
}

void ScannerTerminateConnection(uint16_t connHandle)
{
    BBridgeBleState = BLE_STATE_DISCONNECTING;

    //VOID GAPCentralRole_TerminateLink( connHandle );
    HCI_EXT_DisconnectImmedCmd(connHandle);
}


#endif

/** @}*/
