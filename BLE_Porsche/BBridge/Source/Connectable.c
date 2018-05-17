/**
 * \addtogroup Connectable
 * @{
 *
 * @file 	Connectable.c
 * @author	p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * \addtogroup Connectable
 * @{
 * detailed description here
 * @}
 *
 * @internal
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * $Revision: 18134 $
 * $Id: Connectable.c 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */

#ifdef TARGET_PAD

#include "Connectable.h"
#include "gatt.h"
#include "gap.h"
#include "gapbondmgr.h"
#include "gapgattserver.h"
#include "gattservapp.h"
#include "osal_snv.h"
#include "hci.h"
#include "devinfoservice.h"
#include "BBridgeDefs.h"
#include "BBridgeGATTprofile.h"
#include "BBridgeApp.h"

#define NOTIFICATION_DATA_SIZE     (uint8)(18)
#define NOTIFICATION_HDR_SIZE      (uint8)(1)

static uint8 updateGAPRoleParameters(void);
static void bleRssiCB(int8 rssi);
static void bleEventCB(gaprole_States_t newState);
static void simpleProfileChangeCB( uint16 connHandle, uint8 paramID, uint8 *pValue, uint8 len);


// GAP GATT Attributes
static const uint8 attDeviceName[] = "AWC Wayside Unit";
static uint8_t prevAdvertEnabled = TRUE;

/**
 * @brief Scanner response data (GAP - SCAN RSP data (max size = 31 bytes))
 */
static uint8 connectableScanRspDataLength = MAX_BT_MTU;
static uint8 connectableScanRspData[MAX_BT_MTU]=
{
    0x06,
    GAP_ADTYPE_MANUFACTURER_SPECIFIC,
    0x0E, /* Manufacture ID     */
    0x01, /* Manufacture ID     */
    0xFF, /* AWC Service ID     */
    0xFF, /* AWC Service ID     */
    0x00, /* AWC Device Status  */
    0x05,
    GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE,
    LO_UINT16(DEFAULT_DESIRED_MIN_CONN_INTERVAL),
    HI_UINT16(DEFAULT_DESIRED_MIN_CONN_INTERVAL),
    LO_UINT16(DEFAULT_DESIRED_MAX_CONN_INTERVAL),
    HI_UINT16(DEFAULT_DESIRED_MAX_CONN_INTERVAL),
    0x02,
    GAP_ADTYPE_POWER_LEVEL,
    0,
    0x0E,
    GAP_ADTYPE_LOCAL_NAME_COMPLETE,
    0x50, 0x52, 0x49, 0x4d, 0x4f, 0x56, 0x45, 0x5f, 0x44, 0x55, 0x4d, 0x4d, 0x59,
};

/**
 * @brief GAP - Advertisement data (max size = 31 bytes, though this is
 * best kept short to conserve power while advertising)
 */
uint8 connectableAdvertData[25] = 
{
    0x02,
    GAP_ADTYPE_FLAGS,
    DEFAULT_DISCOVERABLE_MODE | GAP_ADTYPE_FLAGS_BREDR_NOT_SUPPORTED,
    0x06,
    GAP_ADTYPE_MANUFACTURER_SPECIFIC,
    0x0E, /* Manufacture ID     */
    0x01, /* Manufacture ID     */
    0xFF, /* AWC Service ID     */
    0xFF, /* AWC Service ID     */
    0x00, /* AWC Device Status  */
    0x0E,
    GAP_ADTYPE_LOCAL_NAME_COMPLETE,
    0x50, 0x52, 0x49, 0x4d, 0x4f, 0x56, 0x45, 0x5f, 0x44, 0x55, 0x4d, 0x4d, 0x59,
};

static BBridgeInterface_t * interface;

/*********************************************************************
 * PROFILE CALLBACKS
 */
 
static gapRolesCBs_t connectableBLECBs =
{
    bleEventCB, // Profile State Change Callbacks
    bleRssiCB,  // When a valid RSSI is read from controller
};

// Callback when the connection parameteres are updated.
static gapRolesParamUpdateCB_t updateCb = 
{
    ConnectableOnConnParametersUpdate
};

// Simple GATT Profile Callbacks
static simpleProfileCBs_t simpleBLEPeripheral_SimpleProfileCBs =
{
  simpleProfileChangeCB    // Characteristic value change callback
};

// GAP Bond Manager Callbacks
static gapBondCBs_t Connectable_BondMgrCBs =
{
  NULL,                     // Passcode callback (not used by application)
  NULL                      // Pairing / Bonding state Callback (not used by application)
};

/*********************************************************************
 * PUBLIC FUNCTIONS
 */
 
void ConnectableInit(BBridgeInterface_t * anInterface)
{
    interface = anInterface;
    
    // Setup the GAP
    VOID GAP_SetParamValue( TGAP_CONN_PAUSE_PERIPHERAL, DEFAULT_CONN_PAUSE_PERIPHERAL);
    
    {
        uint8 initial_advertising_enable = TRUE;
        interface->advertisingEnabled = initial_advertising_enable;
        uint16 gapRole_AdvertOffTime = DEFAULT_ADV_TIME_OFF;
        
        uint8  enable_update_request = DEFAULT_ENABLE_UPDATE_REQUEST;
        uint16 desired_min_interval  = DEFAULT_DESIRED_MIN_CONN_INTERVAL;
        uint16 desired_max_interval  = DEFAULT_DESIRED_MAX_CONN_INTERVAL;
        uint16 desired_slave_latency = DEFAULT_DESIRED_SLAVE_LATENCY;
        uint16 desired_conn_timeout  = DEFAULT_DESIRED_CONN_TIMEOUT;
        
        
        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof( uint8 ), &initial_advertising_enable);
        GAPRole_SetParameter(GAPROLE_ADVERT_OFF_TIME, sizeof(uint16), &gapRole_AdvertOffTime);
        
        VOID osal_snv_read(NVM_BLOCK_ID_SCAN_RESP, NVM_BLOCK_LEN_SCAN_RESP, &connectableScanRspData[0]);
        GAPRole_SetParameter(GAPROLE_SCAN_RSP_DATA, sizeof (connectableScanRspData), connectableScanRspData);
        GAPRole_SetParameter(GAPROLE_ADVERT_DATA, 3, connectableAdvertData);
        
        GAPRole_SetParameter(GAPROLE_PARAM_UPDATE_ENABLE, sizeof(uint8), &enable_update_request);
        GAPRole_SetParameter(GAPROLE_MIN_CONN_INTERVAL, sizeof(uint16), &desired_min_interval);
        GAPRole_SetParameter(GAPROLE_MAX_CONN_INTERVAL, sizeof(uint16), &desired_max_interval);
        GAPRole_SetParameter(GAPROLE_SLAVE_LATENCY, sizeof(uint16), &desired_slave_latency);
        GAPRole_SetParameter(GAPROLE_TIMEOUT_MULTIPLIER, sizeof(uint16), &desired_conn_timeout);
    }
    
    GGS_SetParameter(GGS_DEVICE_NAME_ATT, sizeof(attDeviceName), (uint8 *)attDeviceName);
    
    // Set advertising interval
    {
        uint16 advInt = DEFAULT_ADVERTISING_INTERVAL;
        
        GAP_SetParamValue( TGAP_LIM_DISC_ADV_INT_MIN, advInt );
        GAP_SetParamValue( TGAP_LIM_DISC_ADV_INT_MAX, advInt );
        GAP_SetParamValue( TGAP_GEN_DISC_ADV_INT_MIN, advInt );
        GAP_SetParamValue( TGAP_GEN_DISC_ADV_INT_MAX, advInt );
    }
    
    // Setup the GAP Bond Manager
    {
        uint8 pairMode = DEFAULT_PAIRING_MODE;
        uint8 mitm = DEFAULT_MITM_MODE;
        uint8 ioCap = DEFAULT_IO_CAPABILITIES;
        uint8 bonding = DEFAULT_BONDING_MODE;
        
        GAPBondMgr_SetParameter( GAPBOND_PAIRING_MODE, sizeof ( uint8 ), &pairMode );
        GAPBondMgr_SetParameter( GAPBOND_MITM_PROTECTION, sizeof ( uint8 ), &mitm );
        GAPBondMgr_SetParameter( GAPBOND_IO_CAPABILITIES, sizeof ( uint8 ), &ioCap );
        GAPBondMgr_SetParameter( GAPBOND_BONDING_ENABLED, sizeof ( uint8 ), &bonding );
    }
    
    // Initialize GATT attributes
    GGS_AddService( GATT_ALL_SERVICES );            // GAP
    GATTServApp_AddService( GATT_ALL_SERVICES );    // GATT attributes
    
    // Device Information Service
    DevInfo_AddService();
    
    // Simple GATT Profile
    SimpleProfile_AddService( GATT_ALL_SERVICES );
    VOID SimpleProfile_RegisterAppCBs( &simpleBLEPeripheral_SimpleProfileCBs );
    
    // Register connection parameter update callbacks
    GAPRole_RegisterAppCBs( &updateCb );
    
    //turn on overlapped processing
    HCI_EXT_HaltDuringRfCmd(HCI_EXT_HALT_DURING_RF_DISABLE);
    HCI_EXT_OverlappedProcessingCmd(HCI_EXT_ENABLE_OVERLAPPED_PROCESSING);
}


void ConnectableStartDevice(void)
{
    // Start the device
    GAPRole_StartDevice(&connectableBLECBs);
    
    // Start Bond Manager
    VOID GAPBondMgr_Register( &Connectable_BondMgrCBs );
}


static uint8 updateGAPRoleParameters(void)
{
    if(BBridge_IsConnected() == TRUE)
    {
        return 0;
    }
    
    if(connectableScanRspDataLength > 0)
    {
        GAPRole_SetParameter(GAPROLE_SCAN_RSP_DATA, connectableScanRspDataLength, connectableScanRspData);
    }
    
    if (prevAdvertEnabled != interface->advertisingEnabled) 
    {
        // Set advertising interval
        if (interface->advertisingEnabled == TRUE)
        {
            GAP_SetParamValue(TGAP_LIM_DISC_ADV_INT_MIN, interface->activeTime);
            GAP_SetParamValue(TGAP_LIM_DISC_ADV_INT_MAX, interface->activeTime);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MIN, interface->activeTime);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MAX, interface->activeTime);
        } 
        else
        {
            GAP_SetParamValue(TGAP_LIM_DISC_ADV_INT_MIN, 0);
            GAP_SetParamValue(TGAP_LIM_DISC_ADV_INT_MAX, 0);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MIN, 0);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MAX, 0);
        }
        
        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8),
                             &interface->advertisingEnabled);
                             
        prevAdvertEnabled = interface->advertisingEnabled;
    }
    
    return 0;
}

/**
 *@brief It sets the device name in the broadcast message
 *@return       0: ok
 *              1: invalid length (attention: 1 byte is needed to store the name length)
 */
uint8 ConnectableSetScanResp(const uint8 * scanResp, uint8 length)
{
    if ((length == 0) || (length > MAX_BT_MTU))
    {
        return 1;
    }
    
    osal_memset(connectableScanRspData, 0, MAX_BT_MTU);
    osal_memcpy(connectableScanRspData, scanResp, length);
    connectableScanRspDataLength = length;
    
    // updating parameters on the bluetooth stack
    updateGAPRoleParameters();
    return BB_SUCCESS;
}

void ConnectableSetDeviceStatus(uint8_t status)
{
    if((BBridge_IsConnected() == FALSE) && (connectableScanRspData[6] != status))
    {
        connectableScanRspData[6] = status;
        GAPRole_SetParameter(GAPROLE_SCAN_RSP_DATA, sizeof (connectableScanRspData), connectableScanRspData);
    }
}

/**
 * @brief Enable or disable the advertisement
 * @param enable
 */
void ConnectableEnableAdv(uint8 enable)
{
    interface->advertisingEnabled = (enable == 1) ? 1 : 0;
    
    if (prevAdvertEnabled != interface->advertisingEnabled) 
    {
        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8), &interface->advertisingEnabled);
                             
        prevAdvertEnabled = interface->advertisingEnabled;
    }
}

uint8 ConnectableSetAdvertiseInterval(uint16 offTime)
{
    interface->activeTime = offTime;
    updateGAPRoleParameters();
    return 0;
}

uint16 ConnectableGetAdvertiseInterval(void)
{
    return interface->activeTime;
}

/***
 * @brief   Notification from the profile of a state change.
 * @param   newState - new state
 */
static void bleEventCB(gaprole_States_t newState)
{
    uint8 btAddr[6];
    uint8 ret;
    
    if ((newState == GAPROLE_STARTED) || (newState == GAPROLE_WAITING)
        || (newState == GAPROLE_WAITING_AFTER_TIMEOUT)
        || (newState == GAPROLE_ERROR))
    {
          //ConnectableEnableAdv(1);
    }
    
    if (newState == GAPROLE_STARTED)
    {
        uint8 ownAddress[B_ADDR_LEN];
        uint8 systemId[DEVINFO_SYSTEM_ID_LEN];
        
        GAPRole_GetParameter(GAPROLE_BD_ADDR, ownAddress);
        
        // use 6 bytes of device address for 8 bytes of system ID value
        systemId[0] = ownAddress[0];
        systemId[1] = ownAddress[1];
        systemId[2] = ownAddress[2];
        
        // set middle bytes to zero
        systemId[4] = 0x00;
        systemId[3] = 0x00;
        
        // shift three bytes up
        systemId[7] = ownAddress[5];
        systemId[6] = ownAddress[4];
        systemId[5] = ownAddress[3];
        
        DevInfo_SetParameter(DEVINFO_SYSTEM_ID, DEVINFO_SYSTEM_ID_LEN, systemId);
        
        // callback for the BBridge module
        interface->onBTDeviceInit();
    }
    else if (newState == GAPROLE_CONNECTED)
    {
        
        // get connection handle
        GAPRole_GetParameter(GAPROLE_CONNHANDLE, &interface->connHandle);
        GAPRole_GetParameter(GAPROLE_CONN_BD_ADDR, btAddr);
        
        uint16 rssi_read_rate = 1000;
        GAPRole_SetParameter(GAPROLE_RSSI_READ_RATE, sizeof(uint16), &rssi_read_rate);
        
        ret = interface->onBTConnection(0, interface->connHandle, btAddr);
        if (ret != 0) 
        {
            // bbridge could not accept connection -> terminate it!
            interface->terminateConnection(interface->connHandle);
        }
        else
        {
            //osal_start_timerEx( interface->taskID , BBRIDGE_CONN_PARAM_UPDATE_EVT, BBRIDGE_CONN_PARAM_UPDATE_DELAY);
        }
    }
    else if (newState == GAPROLE_WAITING) 
    {
        // Advertising has stopped
        // if fast advertising switch to slow
        if (GAP_GetParamValue(TGAP_GEN_DISC_ADV_INT_MIN)
                == defaultFastAdvInternval) 
        {
            //uint8 advState = TRUE;
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MIN, defaultSlowAdvInterval);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MAX, defaultSlowAdvInterval);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_MIN, defaultSlowAdvDuration);
        }
        
        interface->onBTDisconnection(0, interface->connHandle, 1);
        prevAdvertEnabled = 0;
        ConnectableEnableAdv(1);
    }
    else if (newState == GAPROLE_ERROR) 
    {
        // callback to the module
        interface->onBTDisconnection(0, interface->connHandle, 1);
    }
    else
    {
        // lost connection ?
        if (newState == GAPROLE_WAITING_AFTER_TIMEOUT)
        {
            // link loss timeout-- use fast advertising
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MIN, defaultFastAdvInternval);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MAX, defaultFastAdvInternval);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_MIN, defaultFastAdvDuration);
        }
        else
        {
            // Else use slow advertising
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MIN, defaultSlowAdvInterval);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MAX, defaultSlowAdvInterval);
            GAP_SetParamValue(TGAP_GEN_DISC_ADV_MIN, defaultSlowAdvDuration);
        }
    }
}

/**
 * @brief   RSSI callback.
 * @param   rssi - RSSI
 */
static void bleRssiCB(int8 rssi)
{
    //LCD_WRITE_STRING_VALUE( "RSSI -dB:", (uint8) (-rssi), 10, HAL_LCD_LINE_1 );
    interface->onBLERSSI(interface->connHandle, rssi);
}

void ConnectableOnConnParametersUpdate(uint16 connInterval, uint16 connSlaveLatency,
                                       uint16 connTimeout)
{
  
    GAPRole_SetParameter(GAPROLE_MIN_CONN_INTERVAL, sizeof(uint16), &connInterval);
    GAPRole_SetParameter(GAPROLE_MAX_CONN_INTERVAL, sizeof(uint16), &connInterval);
    GAPRole_SetParameter(GAPROLE_SLAVE_LATENCY, sizeof(uint16), &connSlaveLatency);
    GAPRole_SetParameter(GAPROLE_TIMEOUT_MULTIPLIER, sizeof(uint16), &connTimeout);

    interface->onLinkUpdate(interface->connHandle, 0);
}

uint8_t ConnectableUpdateConnectionparams(uint16 connMin, uint16 connMax, 
                                          uint16 connSlaveLatency, uint16 connTimeout)
{
    return GAPRole_SendUpdateParam( connMin, connMax , connSlaveLatency, 
                                    connTimeout, GAPROLE_RESEND_PARAM_UPDATE );
}

static void simpleProfileChangeCB(uint16 connHandle, uint8 paramID, uint8 *pValue, uint8 len)
{
  switch( paramID )
  {
    case SIMPLEPROFILE_CHAR1:
      interface->HandleReceivedFrame(connHandle, pValue, len);
      break;

    default:
      // should not reach here!
      break;
  }
}

void ConnectableProcessGATTMsg(gattMsgEvent_t *pMsg )
{
    
}

uint8 ConnectableTxData(uint16_t connHandle, const uint8 * data, uint8 dataLength)
{
    static uint8 uTxSeqIdx = 1;
    attHandleValueNoti_t notification;
    uint8 uTotalFrameCnt;
    uint8 currDataLength;
    uint8 currFrameLength;
    uint8 i;
    uint8 ret = BB_SUCCESS;
    
    uTotalFrameCnt = dataLength/NOTIFICATION_DATA_SIZE;
    if((dataLength % NOTIFICATION_DATA_SIZE) != 0)
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
        if(currDataLength >= NOTIFICATION_DATA_SIZE)
        {
            currFrameLength = NOTIFICATION_DATA_SIZE + NOTIFICATION_HDR_SIZE;
            currDataLength -= NOTIFICATION_DATA_SIZE;
        }
        else
        {
            currFrameLength = currDataLength + NOTIFICATION_HDR_SIZE;
            currDataLength = 0;
        }
        
        notification.pValue = GATT_bm_alloc(connHandle, ATT_HANDLE_VALUE_NOTI, currFrameLength, NULL);
        if (notification.pValue != NULL)
        {
           
            notification.pValue[0]  = ((uTxSeqIdx&0x03)<<6);
            notification.pValue[0] |= ((uTotalFrameCnt&0x07)<<3);
            notification.pValue[0] |= ((i+1)&0x07);
            osal_memcpy(&notification.pValue[1], &data[i*NOTIFICATION_DATA_SIZE],\
                        (currFrameLength - NOTIFICATION_HDR_SIZE));
            notification.len = currFrameLength;
            
            if(GATT_Notification(connHandle, &notification, FALSE) != SUCCESS)
            {
                GATT_bm_free((gattMsg_t *) &notification, ATT_HANDLE_VALUE_NOTI);
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

void ConnectableTerminateConnection(uint16_t connHandle)
{
    //GAPRole_TerminateConnection();
    HCI_EXT_DisconnectImmedCmd(connHandle);
}


#endif

// ----------------------------------------------
// END CONNECTABLE
// ----------------------------------------------

/** @}*/
