/**************************************************************************************
 * @file    bridge.c
 * @brief : BBridge example implementation.
 *     For this example two BBridges are to be used. One configured in "Connecteable" and the
 *     other in "Scanner" modes. The connectable device waits for a connection from the scanner 
 *     device. When a bluetooth connection is estabilished, they start exchanging data 
 *    (set by the Panther over SPI).
 * @note:The Panther application keeps trying to send and retrieve data over SPI without success
 *    until a bluetooth connection is estabilished. Once a BT connection is ready, the
 *    BBridges will start receiving data from the Panther and forwarding to the bluetooth
 *    channel.
 * $Id: bbridge.c 18134 2018-03-07 13:04:02Z cfarcas $
 * @author : A. Perico
 ***************************************************************************************
 * @copyright
 *
 * <h2><center>&copy; COPYRIGHT 2016 Porsche Engineering Services GmbH</center></h2>
 ***************************************************************************************/

//#include <limits.h>
#include "bcomdef.h"
#include "OSAL.h"
#include "OSAL_PwrMgr.h"
#include "OnBoard.h"
#include "gatt.h"
#include "ll.h"
#include "gatt.h"
#include "gapgattserver.h"
#include "gattservapp.h"
#include "osal_snv.h"
#include "hci.h"
#include "bbridge.h"
#include "hal_board_cfg.h"
#include "SPITransportLayer.h"
#include "BBridgeApp.h"
#include "BBridgeDefs.h"
#include "Scanner.h"
#include "Connectable.h"
#include "USARTInterface.h"




// Customer NV Items - Range 0x80 - 0x8F
#define BLE_NVID_CUST_START         0x80 //!< Start of the Customer's NV IDs
#define BLE_NVID_CUST_END           0x8F //!< End of the Customer's NV IDs
#define STORAGE_TOTAL_ITEMS         8

#define GPIO_STS_LOW                0x00
#define GPIO_STS_HIGH               0x01
#define BOOT_MODE_FLAG              0xC0CABABE

#define RX_DATA_FRAME_SIZE          (uint8)(18)
#define RX_DATA_BUFF_SIZE           (uint8)(RX_DATA_FRAME_SIZE*4)
#define DATA_FRAME_CONN_SEQ_MASK    0xC0
#define DATA_FRAME_FRM_NR_MASK      0x38
#define DATA_FRAME_FRM_IDX_MASK     0x07

typedef struct {
    BBridgeHWInterface_t hwInterface;
    uint8 wupState; //<!-- wakeup line state
    uint16 connHandle;
    BBridgeOpMode_t * operatingModePtr;
    SPITransportLayerHWInterface_t spiHdlrHWInterface;
    uint32_t lastScan;
    uint8_t bbridgeConnected;
} BBridgeControls_t;

typedef enum{
    SELFTST_INIT = 0,
    SELFTEST_OK,
    SELFTST_ERR_RELAY_DEFECT,
    SELFTST_ERR_RELAY_RCD_FAULT,
    SELFTST_ERR_RELAY_LATCH_OFF,
    SELFTST_ERR_RELAY_LATCH_ON,
    SELFTST_ERR_RCD_DEFECT,
    SELFTST_ERR_RCD_IDIFF_6mA,
    SELFTST_ERR_RCD_IDIFF_30mA,
    SELFTST_ERR_RCD_SYS_FAULT
} SelftestResult_t;

static BBridgeInterface_t bbinterface;

static uint8 STORAGE_IDS[] = 
{
    BLE_NVID_CUST_START,
    BLE_NVID_CUST_START + 1,
    BLE_NVID_CUST_START + 2,
    BLE_NVID_CUST_START + 3,
    BLE_NVID_CUST_START + 4,
    BLE_NVID_CUST_START + 5,
    BLE_NVID_CUST_START + 6,
    BLE_NVID_CUST_START + 7, 
};

// hardware interface
static void setWakeupLine(uint8 enable);
static uint8 getWakeupLine(void);

// generic bluetooth functions
static void bbridgeProcessOSALMsg(osal_event_hdr_t *pMsg);
static uint8 transmitTxBuffer(uint16_t connHandle, const uint8 * data,
                                uint8 dataLength);
static uint8 transmitTxBufferCommand(uint16_t connHandle, const uint8 * data,
    uint8 dataLength);
static uint8 storageWrite(const uint8 * data, uint8 id);
static uint8 storageRead(uint8 * data, uint8 id);
static uint8 bbridge_InitDeviceOPMode(BBridgeOpMode_t operatingMode);
static void HandleReceivedFrame(uint16 connHandle, uint8 * pFrameData, uint8 uFrameLen);

#ifdef PAD_B3 
/* Selftest related functions */
static SelftestResult_t Relay_Selftest(void);
static SelftestResult_t RCD_Selftest(void);
static void SelftestErrHdl(SelftestResult_t eSelftestResult);
static uint8 PAD_STATUS;
static uint8 PAD_PowerON_Status;
#endif


/**
 * @brief callback from the scanner when the module has been initialized
 */
static void onBTDeviceInit(void);

#ifdef TARGET_ORU
static uint8 scannerOnDevDiscovered(int8_t rssi, uint8_t addrType,
                                    const uint8_t * addr,
                                    const uint8_t * data, uint8_t dataLength);

static void scannerOnDiscoveryReady(void);
#endif

static uint8 onBTConnection(uint8_t status, uint16_t devhandle,
                            const uint8_t * devAddr);

static uint8 onBTDisconnection(uint8_t status, uint16_t connHandle,
                                uint8_t reason);
static void onRSSIReceived(uint16_t connHandle, int8 rssi);
static void bbridgeTerminateConnection(uint16 connHandle);
static uint8 updateConnectionParams(uint16 connHandle, uint16 connMin, 
                                    uint16 connMax, uint16_t slaveLatency, 
                                    uint16_t connTimeout);
static void onLinkUpdate(uint16 connHandle, uint8_t status);
static void gotosleep();

/*
 * Time delay function
 */
static void BLE_DELAY_MS(uint32 msec);

// BBridge attributes
static BBridgeControls_t controls;

#ifdef PAD_B3 
//Main relay & RCD selftest result
static SelftestResult_t eSelftestResult;
uint8 RelayTesterror;
static uint32 bootmodeflag;
static uint8 uaFlag[4];
#endif

#ifdef ORU_B1
static uint32 u32GoToSleepReq = 0;
#endif


//--------------------------------
// PUBLIC
//--------------------------------
void BBridgeBT_Init(uint8 task_id)
{
    uint8 ret;

#ifdef ORU_B1
    WUP_PORT = 0; // Configure Port 0 as GPIO
    WUP_DDR = 0x09;
#endif
    
#ifdef PAD_B3
    /*check if flag in NVM is set to bootmode */
    if(osal_snv_read(NVM_BLOCK_ID_BOOTMODE, NVM_BLOCK_LEN_BOOTMODE, &uaFlag[0]) != BB_SUCCESS)
    {
        //error condition
        bootmodeflag = 0;
    }
    else
    {
        bootmodeflag = (((uint32)uaFlag[0]<<24)|((uint32)uaFlag[1]<<16)|((uint32)uaFlag[2]<<8)|(uint32)uaFlag[3]);
    }
    
    /*Port 0*/
    P0SEL = 0x00;
    if(bootmodeflag == BOOT_MODE_FLAG)
    {
      P0_0 = 0;
    }
    P0DIR = 0x83;
    
    /* Port 2 */
    P2SEL = 0x00; //Set all to GPIO
    P2DIR = 0x01; // Inout and output
    P2INP = 0x00; //Select Pull-Up for all Input Pins
    D_STATUS_LED_LPCPU_LED = 0;
    
    /*** STARTUP PROCEDURE ***/
    
    //init vars
    PAD_PowerON_Status = 0;
    RelayTesterror = FALSE;
    
    //Enable 5V
    HAL_5V_ON();
    BLE_DELAY_MS(200u);
    
    if(bootmodeflag != BOOT_MODE_FLAG)
    {
        // Perform main relay selftest
        eSelftestResult = SELFTST_INIT;
        eSelftestResult = Relay_Selftest();
        
        if(SELFTEST_OK == eSelftestResult)
        {
            //Perform RCD selftest
            eSelftestResult = SELFTST_INIT;
            eSelftestResult = RCD_Selftest();
        }
        
        if (SELFTEST_OK == eSelftestResult)
        {
            //Switch-ON main relay
            HAL_WUP_LINE_ON();
            BLE_DELAY_MS(20);
            HAL_WUP_LINE_OFF();
        }
    }
    else
    {
        if(D_WAKEUPREL_ACTIVE != GPIO_STS_HIGH)
        {
            //Switch-ON main relay
            HAL_WUP_LINE_ON();
            BLE_DELAY_MS(20);
            HAL_WUP_LINE_OFF();
        }
    }
    
#endif
    
    //Range Extender Settings
    
#if defined(ORU_B1) || defined(PAD_B3) 
    /*
    - SPI 0
    - Enable LNA, PA and HGM for Rev B.1 PCB 
    */
    RFC_OBS_CTRL0 = 0x6A; /* Select LNA */
    TXPOWER = 0xF1;
    OBSSEL0 = 0xFB;
    P1DIR  |= 0x82;
    P1     |= 0x82;
#endif
    
#ifdef PAD_B0
    /* SPI 1  */
    HCI_EXT_ExtendRfRangeCmd();
#endif
    
    // struct shared between Scanner.c and Connectable.c modules
    bbinterface.taskID = task_id;
    bbinterface.onBTDeviceInit = &onBTDeviceInit;
    bbinterface.onBTConnection = &onBTConnection;
#ifdef TARGET_ORU
    bbinterface.scannerOnDeviceDiscovered = &scannerOnDevDiscovered;
    bbinterface.onDiscoveryReady = &scannerOnDiscoveryReady;
#endif
    bbinterface.onBTDisconnection = &onBTDisconnection;
    bbinterface.onBLERSSI = &onRSSIReceived;
    bbinterface.terminateConnection = &bbridgeTerminateConnection;
    bbinterface.activeTime = DEFAULT_ADVERTISING_INTERVAL;
    bbinterface.advertisingEnabled = 0;
    bbinterface.onLinkUpdate = &onLinkUpdate;
    bbinterface.HandleReceivedFrame= &HandleReceivedFrame;
    
    // defining HW interface (needed within BBridgeModules)
    controls.hwInterface.wupSetter = &setWakeupLine;
    controls.hwInterface.wupGetter = &getWakeupLine;
#ifdef TARGET_PAD
    controls.hwInterface.broadcastMsgSetter = &ConnectableSetScanResp;
    controls.hwInterface.setActiveTime = &ConnectableSetAdvertiseInterval;
    controls.hwInterface.getActiveTime = &ConnectableGetAdvertiseInterval;
#endif
    controls.hwInterface.terminateConnection = &bbridgeTerminateConnection;
    controls.hwInterface.transmitBTData = &transmitTxBuffer; /*HT@20171201: to be removed in next release */
    controls.hwInterface.transmitBTDataCommand = &transmitTxBufferCommand;
#ifdef TARGET_ORU
    controls.hwInterface.connect = &ScannerConnect;
#endif
    controls.hwInterface.storageRead = &storageRead;
    controls.hwInterface.storageWrite = &storageWrite;
    controls.hwInterface.initDeviceOPMode = &bbridge_InitDeviceOPMode;
    controls.hwInterface.pushTXData = &SPITransportLayerPushTXData;
    controls.hwInterface.getSystime = &osal_GetSystemClock;
    controls.hwInterface.updateConnectionParams = &updateConnectionParams;
    controls.hwInterface.gotosleep = &gotosleep;
    controls.hwInterface.BLE_Delay = &BLE_DELAY_MS;
    
    USARTInterfaceInit();
    
    ret = BBridge_Init(&controls.hwInterface);
    if (ret != 0)
    {
        // memory issues ?!
        while (1)
        {
            //Add NOP
        }
    }
    
    controls.operatingModePtr = BBridge_GetOpModePtr();
    
    // initializing SPITransportLayer (to manage unreliable SPI communications)
    controls.spiHdlrHWInterface.getSysTime = &osal_GetSystemClock;
    controls.spiHdlrHWInterface.onTxComplete = &BBridge_OnSPITxComplete;
    controls.spiHdlrHWInterface.onRxComplete = &BBridge_OnSPIRxComplete;
    controls.spiHdlrHWInterface.spiPush = &USARTInterfacePush;
    controls.spiHdlrHWInterface.spiTxComplete = &USARTInterfaceIsTxComplete;
    controls.spiHdlrHWInterface.spiGetRxByte = &USARTInterfaceGetRxByte;
    
    SPITransportLayerInit(&controls.spiHdlrHWInterface);
    // end initializing internal communication interface

#ifdef TARGET_ORU
        ScannerInit(&bbinterface);
#else
        ConnectableInit(&bbinterface);
        SelftestErrHdl(eSelftestResult);
#endif
    
    osal_set_event(bbinterface.taskID, BBRIDGE_START_DEVICE_EVT);
    
}

/**
 * Called by the OSAL when events for the BBridgeBT module is available
 * @param task_id
 * @param events
 * @return remaining events
 */
uint16 BBridgeBT_ProcessEvent(uint8 task_id, uint16 events)
{
    uint8 * pMsg;
    
#ifdef ORU_B1
    if(u32GoToSleepReq == 0xAFFEC0CA)
    {
        return 0;
    }
#endif
    
    if (events & SYS_EVENT_MSG)
    {
        if ((pMsg = osal_msg_receive(task_id)) != NULL)
        {
            bbridgeProcessOSALMsg((osal_event_hdr_t *) pMsg);
            // Release the OSAL message
            VOID osal_msg_deallocate( pMsg);
        }
        // return unprocessed events
        return (events ^ SYS_EVENT_MSG);
    }
    
    if ( events & BBRIDGE_START_DEVICE_EVT )
    {
#ifdef TARGET_ORU
        ScannerStartDevice();
#else
        ConnectableStartDevice();
#endif
        osal_start_timerEx(bbinterface.taskID, BBRIDGE_PERIODIC_EVT, BBRIDGE_EVT_PERIOD);
        return ( events ^ BBRIDGE_START_DEVICE_EVT );
    }
    
#ifdef TARGET_PAD
    if ( events & BBRIDGE_CONN_PARAM_UPDATE_EVT )
    {

        GAPRole_SendUpdateParam( DEFAULT_DESIRED_MIN_CONN_INTERVAL, DEFAULT_DESIRED_MAX_CONN_INTERVAL,
                             DEFAULT_DESIRED_SLAVE_LATENCY, DEFAULT_DESIRED_CONN_TIMEOUT,
                             GAPROLE_RESEND_PARAM_UPDATE );

        return (events ^ BBRIDGE_CONN_PARAM_UPDATE_EVT);
    }
#endif
    
#ifdef TARGET_ORU
    if ( events & BBRIDGE_START_DISCOVERY_EVT )
    {
        ScannerStartServiceDiscovery();
        return ( events ^ BBRIDGE_START_DISCOVERY_EVT );
    }
#endif

    if (events & BBRIDGE_PERIODIC_EVT)
    {
#ifdef PAD_B3
        if(RelayTesterror == FALSE)
        {
            uint32 uTimestamp = BBridge_GetSysTime();
            
            if( (PAD_PowerON_Status == 0 ) && ( uTimestamp < 100000u) )
            {
                PAD_STATUS = PAD_STATUS_Power_ON;
            }
            else
            {
                PAD_STATUS = PAD_STATUS_Normal_Operation;
                PAD_PowerON_Status = 1;
            }
            
            ConnectableSetDeviceStatus(PAD_STATUS);
        }
#endif

#ifdef TARGET_ORU
        /*Only perform scan if in Scanner_Mode and there is no connection active. Else do not perform scan.*/
        if ((*controls.operatingModePtr == BB_SCANNER_MODE) && (BBridge_IsConnected() == FALSE))
        {
            if (BBridge_CanScan() == TRUE)
            {
                /* only enters this state when previous scan has finished */
                if(BBridge_GetSysTimeDiff(controls.lastScan) >= DEFAULT_SCAN_OFFTIME)
                {
                    if (ScannerStartDiscovery() == BB_SUCCESS)
                    {
                        controls.lastScan = BBridge_GetSysTime();
                        BBridge_OnScanStarted();
                    }
                }
            }
        }
#endif
        BBridge_Work();
        
        osal_start_timerEx(bbinterface.taskID, BBRIDGE_PERIODIC_EVT, BBRIDGE_EVT_PERIOD);
        
        return (events ^ BBRIDGE_PERIODIC_EVT);
    }
    
    return 0; // Discard unknown events
}

//--------------------------------
// end public
//--------------------------------

/***
 * @brief   Process an incoming task message.
 * @param   pMsg - message to process
 */
static void bbridgeProcessOSALMsg(osal_event_hdr_t *pMsg)
{
    gattMsgEvent_t * gatMsg;
    
    switch (pMsg->event) 
    {
        case GATT_MSG_EVENT:
        {
            gatMsg = (gattMsgEvent_t *) pMsg;

#ifdef TARGET_ORU
            ScannerProcessGATTMsg(gatMsg);
#else
            ConnectableProcessGATTMsg(gatMsg);
#endif
            GATT_bm_free(&gatMsg->msg, gatMsg->method);
            break;
        }
        
        default:
            break;
    }
}

#ifdef PAD_B3

static SelftestResult_t Relay_Selftest(void)
{
    /* Check main relay feedback signal - It shall be OFF at startup of BLE */
    if((D_WAKEUPREL_ACTIVE == GPIO_STS_HIGH) && (WUP_SBIT == GPIO_STS_HIGH))
    {
        return SELFTST_ERR_RELAY_DEFECT;
    }
    
    /* Check if RCD device detects any error which prevents switching-on the main relay */
    if( (D_CTRL_IDIFF_6mA == GPIO_STS_HIGH) 
         || 
        (D_CTRL_IDIFF_30mA == GPIO_STS_HIGH) 
         || 
        (D_CTRL_IDIFF_ERROR_10 == GPIO_STS_HIGH))
    {
        return SELFTST_ERR_RELAY_RCD_FAULT;
    }
    
    /* switch-on main relay - it operates on failing edge of the wakeup line signal */
    //HAL_WUP_LINE_ON();
    //BLE_DELAY_MS(20u);
    //HAL_WUP_LINE_OFF();
    //BLE_DELAY_MS(20u);
    //
    /* Check main relay feedback signal - it shall be ON*/
    //if (D_WAKEUPREL_ACTIVE == GPIO_STS_LOW)
    //{
    //    return SELFTST_ERR_RELAY_LATCH_OFF;
    //}
    //
    /* switch-off main relay */
    //HAL_WUP_LINE_ON();
    //BLE_DELAY_MS(20u);
    //
    /* Check main relay feedback signal - it shall be OFF*/
    //if (D_WAKEUPREL_ACTIVE == GPIO_STS_HIGH)
    //{
    //    return SELFTST_ERR_RELAY_LATCH_ON;
    //}
    
    return SELFTEST_OK;
}

static SelftestResult_t RCD_Selftest(void) 
{
    /* Ensure that wakeup line is ON */
    HAL_WUP_LINE_ON();
    
    /* trigger RCD selftest while setting the PIN TEST_RCMB low for a short time */
    HAL_TEST_RCMB_OFF();
    BLE_DELAY_MS (50u);
    HAL_TEST_RCMB_ON();
    
    /* wait for 500ms before checking the 6mA residual current failure */
    BLE_DELAY_MS (500u);
    
    /* check if the expected error has occurred */
    if( (D_CTRL_IDIFF_6mA == GPIO_STS_HIGH)
         && 
        (D_CTRL_IDIFF_30mA == GPIO_STS_LOW)
         && 
        (D_CTRL_IDIFF_ERROR_10 == GPIO_STS_LOW))
    {
        /* Try to switch-on the main relay */
        HAL_WUP_LINE_OFF();
        BLE_DELAY_MS(20u);
        /* Check main relay feedback signal - It shall be OFF when 6mA residual current failure is present */
        if (D_WAKEUPREL_ACTIVE == GPIO_STS_HIGH)
        {
            return SELFTST_ERR_RCD_IDIFF_6mA;
        }
    }
    else
    {
        return SELFTST_ERR_RCD_DEFECT;
    }
    
    /* set wakeup line to ON */
    HAL_WUP_LINE_ON();
    
    /* wait for 800ms before checking the 30mA residual current failure */
    BLE_DELAY_MS (800u);
    
    /* check if the expected error has occurred */
    if( (D_CTRL_IDIFF_6mA == GPIO_STS_LOW)
         && 
        (D_CTRL_IDIFF_30mA == GPIO_STS_HIGH)
         && 
        (D_CTRL_IDIFF_ERROR_10 == GPIO_STS_LOW))
    {
        /* Try to switch-on the main relay */
        HAL_WUP_LINE_OFF();
        BLE_DELAY_MS(20u);
        
        /* Check main relay feedback signal - It shall be OFF when 30mA residual current failure is present */
        if (D_WAKEUPREL_ACTIVE == GPIO_STS_HIGH)
        {
            return SELFTST_ERR_RCD_IDIFF_30mA;
        }
    }
    else
    {
        return SELFTST_ERR_RCD_DEFECT;
    }
    
    /* set wakeup line to ON */
    HAL_WUP_LINE_ON();
    
    /* wait for 500ms before checking the RCD internal system fault */
    BLE_DELAY_MS (500u);
    
    /* check if the expected error has occurred */
    if( (D_CTRL_IDIFF_6mA == GPIO_STS_LOW)
         && 
        (D_CTRL_IDIFF_30mA == GPIO_STS_LOW)
         && 
        (D_CTRL_IDIFF_ERROR_10 == GPIO_STS_HIGH))
    {
         /* Try to switch-on the main relay */
        HAL_WUP_LINE_OFF();
        BLE_DELAY_MS(20u);
        
        /* Check main relay feedback signal - It shall be OFF when RCD internal system fault is present */
        if (D_WAKEUPREL_ACTIVE == GPIO_STS_HIGH)
        {
            return SELFTST_ERR_RCD_SYS_FAULT;
        }
    }
    else
    {
        return SELFTST_ERR_RCD_DEFECT;
    }
    
    /* set wakeup line to ON */
    HAL_WUP_LINE_ON();
    
    /*wait for 400ms until the test is done and no simulated failures are present */
    BLE_DELAY_MS(400u);
    
    return SELFTEST_OK;
}

static void SelftestErrHdl(SelftestResult_t eSelftestResult)
{
    switch(eSelftestResult)
    {
        case SELFTST_ERR_RELAY_DEFECT:
        case SELFTST_ERR_RELAY_LATCH_ON:
        case SELFTST_ERR_RELAY_RCD_FAULT:
        case SELFTST_ERR_RELAY_LATCH_OFF:
        case SELFTST_ERR_RCD_DEFECT:
        case SELFTST_ERR_RCD_IDIFF_6mA:
        case SELFTST_ERR_RCD_IDIFF_30mA:
        case SELFTST_ERR_RCD_SYS_FAULT:
            RelayTesterror = TRUE;
            D_STATUS_LED_LPCPU_LED = 1;
            HAL_WUP_LINE_ON();
            break;
        
        default:
            break;
        
    }
    
    if(TRUE == RelayTesterror )
    {
        extern uint8 connectableAdvertData[25];
        uint8 AdvEnabled;
        uint8 Buf[31];
        
        connectableAdvertData[9] = PAD_STATUS_RCMB_TEST_ERROR;
        AdvEnabled = FALSE;
        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8), &AdvEnabled);
        AdvEnabled = TRUE;
        GAPRole_SetParameter(GAPROLE_ADV_NONCONN_ENABLED, sizeof(uint8),& AdvEnabled);
        
        if (osal_snv_read(NVM_BLOCK_ID_SCAN_RESP, NVM_BLOCK_LEN_SCAN_RESP, &Buf[0])  == SUCCESS)
        {
          for(int i =0; i<sizeof(Buf);i++)
          {
            if(Buf[i] == GAP_ADTYPE_LOCAL_NAME_COMPLETE)
            {
              osal_memcpy(&connectableAdvertData[12], &Buf[i++], 13);
            }
          }
        }
        
        GAPRole_SetParameter(GAPROLE_ADVERT_DATA, sizeof(connectableAdvertData), connectableAdvertData);
    }
}

#endif

/* Define Delay Function */
void BLE_DELAY_MS (uint32 msec)
{
    uint32 u32StartTime;
    uint32 u32Delay;
    uint32 u32Time;
    
    // Note: Read of ST0 latches ST1 and ST2.
    ((uint8 *)&u32StartTime)[0] = ST0;
    ((uint8 *)&u32StartTime)[1] = ST1;
    ((uint8 *)&u32StartTime)[2] = ST2;
    ((uint8 *)&u32StartTime)[3] = 0;
    
    u32Time = 0;
    u32Delay = ((msec * 4096) / 125u);
    
    do
    {
        // Note: Read of ST0 latches ST1 and ST2.
        ((uint8 *)&u32Time)[0] = ST0;
        ((uint8 *)&u32Time)[1] = ST1;
        ((uint8 *)&u32Time)[2] = ST2;
        ((uint8 *)&u32Time)[3] = 0;
    }
    while (u32Time < (u32StartTime + u32Delay));
    
    return;
}

/**
 * @brief It sets the wakeup line to HIGH or LOW
 * @param enable (1: HIGH, 0: LOW)
 */
static void setWakeupLine(uint8 enable) {
    if (enable) 
    {
        HAL_WUP_LINE_ON();
    } 
    else
    {
        HAL_WUP_LINE_OFF();
        #ifdef PAD_B3 
        /*Re-initialise RXFC TXFC values to sync after a wakeup of the PAD*/
        RxfcTxfcReset();
        #endif
    }
    controls.wupState = enable;
}

/**
 * @brief it returns the current state of the Wakeup line
 * @return  0: low\n
 *          1: high
 */
static uint8 getWakeupLine(void)
{
    return controls.wupState;
}

static uint8 transmitTxBuffer(uint16_t connHandle, const uint8 * data, uint8 dataLength)
{
#ifdef TARGET_PAD
    return ConnectableTxData(connHandle, data, dataLength);
#else
    return ScannerTxData(connHandle, data, dataLength);
#endif

}

static uint8 transmitTxBufferCommand(uint16_t connHandle, const uint8 * data, uint8 dataLength)
{
#ifdef TARGET_PAD
    return ConnectableTxData(connHandle, data, dataLength);
#else
    return ScannerTxData(connHandle, data, dataLength);
#endif
}


static void bbridgeTerminateConnection(uint16_t connHandle)
{
#ifdef TARGET_PAD
    ConnectableTerminateConnection(connHandle);
#else
    ScannerTerminateConnection(connHandle);
#endif
}

static void gotosleep()
{
    bbridge_InitDeviceOPMode(BB_IDLE_MODE); 
    
    #ifdef ORU_B1
    u32GoToSleepReq = 0xAFFEC0CA;
    P1_6 = 1; //set SPI ready port to 1.
    osal_clear_event(bbinterface.taskID, BBRIDGE_PERIODIC_EVT );
    osal_stop_timerEx(bbinterface.taskID, BBRIDGE_PERIODIC_EVT);
    #endif
}

/**
 * @return   0: ok\n
 *           1: invalid mode\n
 *           2: could not set role  (BB_SCANNER_MODE)\n
 *           3: could not set role  (BB_CONNECTABLE_MODE)\n
 *           4: could not set role  (BB_IDLE_MODE)\n
 */
static uint8 bbridge_InitDeviceOPMode(BBridgeOpMode_t newMode)
{
#ifdef TARGET_ORU
    if (newMode == BB_SCANNER_MODE)
    {
      ScannerInit(&bbinterface);
    }
#else
    if (newMode == BB_CONNECTABLE_MODE) 
    {
      ConnectableInit(&bbinterface);

    }
#endif
    else if (newMode == BB_IDLE_MODE)
    {
#ifdef TARGET_PAD
        ConnectableEnableAdv(0);
#endif
    }
    else
    {
        // role unknown
        return 1;
    }
    
    return 0; // OK, executed correctly
}

static uint8 storageWrite(const uint8 * data, uint8 id)
{
    uint8 ret;
    if (id < STORAGE_TOTAL_ITEMS)
    {
        ret = osal_snv_write(STORAGE_IDS[id], 1, (void *)data);
        if (ret == SUCCESS)
        {
            return 0;
        }
        
        return ret;
    }
    else
    {
        return 1; // index out of range
    }
}

static uint8 storageRead(uint8 * data, uint8 id)
{
    uint8 ret;
    if (id < STORAGE_TOTAL_ITEMS)
    {
        ret = osal_snv_read(STORAGE_IDS[id], 1, data);
        if (ret == SUCCESS)
        {
            return 0;
        }
        
        return ret;
    } 
    else
    {
        return 1; // index out of range
    }
}

static uint8 onBTDisconnection(uint8_t status, uint16_t connHandle,
                               uint8_t reason)
{
    BBridge_OnBTDisconnection(status, connHandle, reason);
    return 0;
}

static uint8 onBTConnection(uint8_t status, uint16_t devhandle,
                            const uint8_t * devAddr) 
{
    return BBridge_OnBTConnection(status, devhandle, devAddr);
}

static void onBTDeviceInit(void)
{
    BBridge_OnDevInitDone();
}

#ifdef TARGET_ORU
static uint8_t scannerOnDevDiscovered(int8_t rssi, uint8_t addrType,
                                      const uint8_t * addr, const uint8_t * data,
                                      uint8_t dataLength)
{
    return BBridge_OnDevDiscovered(rssi, addrType, addr, data, dataLength);
}

static void scannerOnDiscoveryReady(void)
{
    controls.lastScan = BBridge_GetSysTime();
    BBridge_OnScanReady();
}
#endif

static void onRSSIReceived(uint16_t connHandle, int8 rssi)
{
    BBridge_OnRssi(connHandle, rssi);
}

static uint8 updateConnectionParams(uint16 connHandle, uint16 connMin,
                                    uint16 connMax, uint16 slaveLatency,
                                    uint16_t connTimeout)
{
#ifdef TARGET_ORU
    if (*controls.operatingModePtr == BB_SCANNER_MODE)
    {
        return ScannerUpdateLink(connHandle, connMin, connMax , slaveLatency, connTimeout);
    }
#else
    if(*controls.operatingModePtr == BB_CONNECTABLE_MODE)
    {
        return ConnectableUpdateConnectionparams(connMin, connMax, slaveLatency, connTimeout);
    }
#endif
    else
    {
        return 0;
    }
}

static void onLinkUpdate(uint16 connHandle, uint8_t status)
{
    BBridge_OnLinkUpdate(connHandle, status);
}

static void HandleReceivedFrame(uint16 connHandle, uint8 * pFrameData, uint8 uFrameLen)
{
    static BBridgeCommPacket_t sBrdgComPack;
    static uint8 uRxSeqIdx = 0;
    static uint8 uTotalRxFrameCnt = 0;
    static uint8 uTotalRxFrameSize = 0;
    static uint8 uRxFramesCnt = 0;
    static uint8 uRxFramesFlag = 0;
    
    uint8 uCurrFrameIdx;
    uint8 uCurrTotalFrameCnt;
    uint8 uCurrRxSeqIdx;
    uint8 uCurrFrameFlag;
    
    /* index of actual transmission sequence */
    uCurrRxSeqIdx = ((pFrameData[0]&DATA_FRAME_CONN_SEQ_MASK)>>6u);
    
    /* number of frames within the actual transmission sequence */
    uCurrTotalFrameCnt = ((pFrameData[0]&DATA_FRAME_FRM_NR_MASK)>>3u);
    
    /* actual frame index */
    uCurrFrameIdx = (pFrameData[0]&DATA_FRAME_FRM_IDX_MASK);
    
    /* actual frame flag/mask */
    uCurrFrameFlag = (uint8)(1<<(uCurrFrameIdx-1));
    
    /*Check if a new transmission sequence has been started */
    if((uRxSeqIdx != uCurrRxSeqIdx) 
        ||
       ((uRxSeqIdx == uCurrRxSeqIdx) && (uRxFramesCnt == 0))
      )
    {
        /* Preparation for new transmission sequence */
        uRxSeqIdx = uCurrRxSeqIdx;
        uTotalRxFrameCnt = uCurrTotalFrameCnt;
        uTotalRxFrameSize = 0;
        uRxFramesCnt = 0;
        uRxFramesFlag = 0;
    }
    
    /* check if the actual frame has been already handled - case of frame re-transmission */
    if(!(uRxFramesFlag&uCurrFrameFlag))
    {
        /* buffer the received data frame */
        osal_memcpy(&(sBrdgComPack.unPacketData.st.data[RX_DATA_FRAME_SIZE*(uCurrFrameIdx-1)]), &pFrameData[1], (uFrameLen-1));
        uTotalRxFrameSize += (uFrameLen-1);
        uRxFramesFlag |= uCurrFrameFlag;
        uRxFramesCnt++;
    }
    
    if(uRxFramesCnt == uTotalRxFrameCnt)
    {
        if (BBridge_GetConnIndexByHandle(connHandle, &(sBrdgComPack.unPacketInfo.st.ConnIndex)) == BB_SUCCESS)
        {
            sBrdgComPack.unPacketInfo.st.HeaderLength = 0;
            sBrdgComPack.unPacketInfo.st.HeaderOffset = 0;
            sBrdgComPack.unPacketInfo.st.DataLength = uTotalRxFrameSize;
            
            /*all frames within the actual transmission sequence have been received and packed successfully */
            VOID BBridge_OnBTRxData(&sBrdgComPack);
        }
        
        uRxFramesCnt = 0;
    }
}

