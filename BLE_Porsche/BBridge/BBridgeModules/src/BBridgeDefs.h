/**
 * \addtogroup BBridgeDefs
 * @{
 *
 * @file    BBridgeDefs.h
 * @author  p344575
 * @brief   Definitions and parameters to be used across the BBridge application
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2017-01-24 09:52:00 
 * $LastChangedBy: Reiner Bogenfürst
 * $Revision: 18134 $
 * $Id: BBridgeDefs.h 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */
#ifndef BBRIDGEDEFS_H_
#define BBRIDGEDEFS_H_
#include "typedefs.h"

/**
 * @brief Maximum amount of BBridge commands, GET_X + SET_Y + DO_Z = 0xFF
 */
#define BB_MAX_COMMANDS 25u
#define BB_MAX_CONFIGS 7u

/**
 * @brief Maximum data length that can be exchanged over the external interface
 * (bluetooth)
 */
#define BB_MAX_EXT_DATA 20u
#define BB_MAX_EXT_DATA_SPI 80u  /*indicates the max size of data to be sent to the Panther*/
#define BB_MAX_BROADCAST_MSG 31u
#define BB_BROADCAST_MSG_HDR_LEN 6u
#define BB_MAX_SCANNER_BT_CONNS 1u
#define BB_MAX_CONNECTABLE_BT_CONNS 1u //Should be deleted
#define BB_MAX_SCAN_RES 8u
#define BB_MAX_STORAGE_ITEMS 8u

/**
 * @brief It defines the maximum length in bytes that a configuration can have.
 * This value is used for boundary checks only
 */
#define BB_MAX_CONFIG_LENGTH 4u

/**
 * @brief  Maximum data length data can be exchanged over the internal interface
 * (SPI)
 */
#define BB_MAX_INT_DATA (BB_MAX_BROADCAST_MSG+BB_BROADCAST_MSG_HDR_LEN+24u)
#define BB_SEED_REQ 0x55u
#define BB_SEED_RESP 0x56u
#define BB_KEY_RESP 0x57u
#define BB_KEY_PASS 0x58u
#define BB_INVALID_DEV_INDEX 0xFFu
#define MAX_BT_MTU 31u
/*#define DEFAULT_RSSI_PERIOD                   1000u*/
/*#define SBP_CON_EVT                           0x0008u*/

/* SCANNER-RELATED ------------------------------------------------------------------------------------*/
/* Scan duration in ms*/
#define DEFAULT_SCAN_DURATION                 2000u
#define DEFAULT_SCAN_OFFTIME                  DEFAULT_SCAN_DURATION
/* Discovey mode (limited, general, all)*/
#define DEFAULT_DISCOVERY_MODE                DEVDISC_MODE_ALL
#define DEFAULT_DISCOVERY_ACTIVE_SCAN         TRUE
/* TRUE to use white list during discovery*/
#define DEFAULT_DISCOVERY_WHITE_LIST          FALSE
/* TRUE to use high scan duty cycle when creating link*/
#define DEFAULT_LINK_HIGH_DUTY_CYCLE          FALSE
#define DEFAULT_LINK_WHITE_LIST               FALSE
/*END-SCANNER_RELATED---------------------------------------------------*/

/* CONNECTABLE-RELATED ------------------------------------------------------------------------------------*/
/* General discoverable mode advertises indefinitely*/
#define DEFAULT_DISCOVERABLE_MODE             GAP_ADTYPE_FLAGS_GENERAL /*GAP_ADTYPE_FLAGS_GENERAL*/

/* Minimum connection interval (units of 1.25ms, 80=100ms) if automatic parameter update request is enabled*/
#define DEFAULT_DESIRED_MIN_CONN_INTERVAL     8u

/* Maximum connection interval (units of 1.25ms, 800=1000ms) if automatic parameter update request is enabled*/
#define DEFAULT_DESIRED_MAX_CONN_INTERVAL     8u

/* Fast advertising interval in 625us units*/
#define defaultFastAdvInternval             32u
/* Duration of fast advertising duration in ms*/
#define defaultFastAdvDuration              100u

/* Slow advertising interval in 625us units*/
#define  defaultSlowAdvInterval             1600u
#define defaultSlowAdvDuration              0u
/* Connection Pause Peripheral time value (in seconds)*/
#define DEFAULT_CONN_PAUSE_PERIPHERAL         6u
#define DEFAULT_ENABLE_UPDATE_REQUEST         FALSE

/* Slave latency to use if automatic parameter update request is enabled*/
#define DEFAULT_DESIRED_SLAVE_LATENCY         0u
/* Supervision timeout value (units of 10ms, 1000=10s) if automatic parameter update request is enabled*/
#define DEFAULT_DESIRED_CONN_TIMEOUT          10u
/* What is the advertising interval when device is discoverable (units of 625us, 160=100ms)*/
#define DEFAULT_ADVERTISING_INTERVAL          800u

/* By setting this to zero, the device will go into the waiting state after*/
/* being discoverable for 30.72 second, and will not being advertising again*/
/* until the enabler is set back to TRUE*/
#define DEFAULT_ADV_TIME_OFF 0

/* Default passcode*/
/*#define DEFAULT_PASSCODE                      00000*/
/* Default GAP pairing mode*/
#define DEFAULT_PAIRING_MODE                  GAPBOND_PAIRING_MODE_NO_PAIRING /*GAPBOND_PAIRING_MODE_WAIT_FOR_REQ*/
/* Default MITM mode (TRUE to require passcode or OOB when pairing)*/
#define DEFAULT_MITM_MODE                     FALSE
/* Default bonding mode, TRUE to bond*/
#define DEFAULT_BONDING_MODE                  FALSE
/* Default GAP bonding I/O capabilities*/
#define DEFAULT_IO_CAPABILITIES               GAPBOND_IO_CAP_NO_INPUT_NO_OUTPUT /* GAPBOND_IO_CAP_KEYBOARD_ONLY*/

#define BB_VALIDATION_TIMEOUT 10000u /*ms*/
#define BBCONN_TIMEOUT 10000u
#define BBDISCONN_TIMEOUT 5000u
#define BB_VALIDATION_ENABLED FALSE
#define BB_DISCONNECTION_TIMEOUT 7000u /* time to wait for a disconnection to work*/

/* Definitions for BLE status within the scan response */
#define PAD_STATUS_Power_ON 1u;
#define PAD_STATUS_Normal_Operation 2u;
#define PAD_STATUS_RCMB_TEST_ERROR 4u;
#define PAD_STATUS_Flashing_On_Going 8u;

#define NVM_BLOCK_ID_BOOTMODE                       0x88
#define NVM_BLOCK_LEN_BOOTMODE                      0x04
#define NVM_BLOCK_ID_SCAN_RESP                      0x89
#define NVM_BLOCK_LEN_SCAN_RESP                     0x1F

#define BBRIDGE_START_DEVICE_EVT            0x0001
#define BBRIDGE_PERIODIC_EVT                0x0002
#define BBRIDGE_CONN_PARAM_UPDATE_EVT       0x0004
#define BBRIDGE_START_DISCOVERY_EVT         0x0008

#define BBRIDGE_CONN_PARAM_UPDATE_DELAY     1000
#define BBRIDGE_SVC_DISCOVERY_DELAY         10
#define BBRIDGE_EVT_PERIOD                  1


/* Internal communication packet definitions */
#define BBRIDGE_COM_PCK_INFO_SIZE       4
#define BBRIDGE_COM_PCK_HDR_SIZE        3
#define BBRIDGE_COM_PCK_FRMS_SIZE       72
#define BBRIDGE_COM_PCK_DATA_SIZE       (BBRIDGE_COM_PCK_HDR_SIZE+BBRIDGE_COM_PCK_FRMS_SIZE)

#define BBRDIGE_CMD_MAX_DATA_LEN        72

/**
 * @brief Validation return values
 */
typedef enum
{
    BBVAL_BUSY = 0, BBVAL_FAILED, BBVAL_PASS, BBVAL_ERROR
} BBValidResult_t;

typedef enum
{
    BB_MSGTYPE_ACK = 0, /*!< 0- Success*/
    BB_MSGTYPE_NACK, /*!< 1- Failure*/
    BB_MSGTYPE_EVENT /*!< 2- Event from BBridge*/
} BBridge2PantherMsgType_t;

/**
 * @brief BBridge Command types
 */
typedef enum
{
    CMDTYPE_GET, /*!< Command to get values from the BBridge application*/
    CMDTYPE_SET /*!< Command to get a value in the BBridge application*/
} BBCMDType_t;

typedef enum
{
    BB_NACK_CMD_UNKNOWN = 0,
    BB_NACK_BUSY,
    BB_NACK_NOT_CONNECTED,
    BB_NACK_INVALID_REQ,
    BB_NACK_INDEX_OUTORANGE,
    BB_NACK_SEND_ERROR,
    BB_NACK_INTERNAL_ERROR,
    BB_NACK_TIMEOUT,
    BB_NACK_ERROR
} BBridgeNACKReason_t;

typedef enum
{
    BB_EVT_CONN_ESTABLISHED = 0, /*!< connection established*/
    BB_EVT_CONN_LOST,/*!< connection lost*/
    BB_EVT_RX_MSG, /*!< rx msg from bluetooth interface*/
    BB_EVT_INIT_OK, /*!< When the BBridge is ready to react to Panther commands*/
    BB_EVT_INTERNAL_ERROR, /*!< Internal BBridge error*/
    BB_EVT_DETECTED_CONNECTABLE /*!< When the Scanner has detected a connectable*/
} BBridgeEvents_t;

typedef enum
{
    BB_ERR_INITILIZATION = 0 /*!< Initialization error*/
} BBridgeErrors_t;

/**
 * @brief BBridge Command IDs
 */
typedef enum
{
    BBCMD_SET_BROADCAST_MSG = 0x00, /*!< sets the broadcast message on the connectable device*/
    BBCMD_GET_BROADCAST_MSG = 0x01, /*!< returns the broadcast message on the connectable*/
    BBCMD_SET_FILTER_MSG = 0x02, /*!< to set the filter messages used on the scanner */
    BBCMD_GET_FILTER_MSG = 0x03, /*!< to get the filter message used on the scanner */
    BBCMD_SET_OP_MODE = 0x04, /*!< to set the operating mode */
    BBCMD_GET_OP_MODE = 0x05, /*!< to load the current operating mode*/
    BBCMD_DISCONNECT = 0x06, /*!< disconnects from a Bluetooth device*/
    BBCMD_SET_NVM_BYTE = 0x07, /*!< to store data from the NVM */
    BBCMD_GET_NVM_BYTE = 0x08, /*!< to load stored data from the NVM */
    BBCMD_SEND_DATA = 0x09, /*!< to send data over Bluetooth*/
    BBCMD_SET_ADV_INTERVAL = 0x0A, /*!< Sets the advertisement internal values */
    BBCMD_GET_ADV_INTERVAL = 0x0B, /*!< Returns the advertisement internal values */
    BBCMD_GET_CONN_STATES = 0x0C, /*!< returns the state of each possible connection*/
    BBCMD_GET_CONN_RSSI = 0x0D, /*!< returns signal strength of a connected device*/
    BBCMD_GET_CONN_ADDR = 0x0E, /*!< returns Bluetooth address of a connected device*/
    BBCMD_GET_CONN_BRM = 0x0F, /*!< returns broadcasted message of a connected device*/
    BBCMD_SET_SLEEP_MODE = 0x10, /*!< Sets the BLE chip and range extender in sleep mode */
    BBCMD_SET_SCAN_MODE = 0x11, /*!< Commands the BLE chip to process the scan results */
    BBCMD_INITIATE_CONNECTION = 0x12, /*!< Commands the BLE chip to initiate connection to selected pad */
    BBCMD_GET_CONN_NAMES = 0x13, /*!< Commands the BLE chip to transfer the PAD names to the panther */
    BBCMD_REQ_SLEEP = 0x14, /*!< Processes a request sleep from the panther by switching off the mains relais*/
    BBCMD_SET_BOOT_MODE = 0x15, /*!<  Set Bootloader mode flag */
    BBCMD_GET_BOOT_MODE = 0x16, /*!<  Get Bootloader mode flag */
    BBCMD_GET_RESET_REASON = 0x17, /*!<  Get Reset Reason of BLE chip */
    BBCMD_GET_OWN_ADDR = 0x18, /*!<  Get own address of BLE chip*/
    
} BBridgeCMDId_t;

/**
 * @brief BBridge Configurations 
 */
typedef enum 
{
    BBCFG_NONE              = 0x00,/*!< [01] Used as placeholder for ACTION commands*/
    BBCFG_BROADCAST_MSG     = 0x01,/*!< [21] Broadcast message in Connectable mode*/
    BBCFG_FILTER_MSG        = 0x02,/*!< [21] Filter message in Scanner mode*/
    BBCFG_OP_MODE           = 0x03,/*!< [01] Current operating mode*/
    BBCFG_ADV_INTERVAL      = 0x04,
    BBCFG_NVM_BYTE          = 0x05,
    BBCFG_BOOT_MODE         = 0x06,
} BBridgeCFGId_t;

/**
 * @brief BBridge operating modes
 */
typedef enum
{
    BB_NO_MODE = 0, BB_IDLE_MODE = 1, /*!< BBrige with bluetooth functions not enabled - used for configuring the system*/
    BB_SCANNER_MODE = 2, /*!< BBridge in Scanner mode - Scans and try to connect to other BBridges*/
    BB_CONNECTABLE_MODE = 3 /*!< BBridge in Connectable mode - Broadcasts its position and waits for connections*/
} BBridgeOpMode_t;

/**
 * @brief Internal data packet
 */
typedef struct
{
    uint8_t length;
    uint8_t data[BBRIDGE_COM_PCK_DATA_SIZE];
} BBridgeCommIntData_t;

/**
 * @brief Internal communication packet
 */
 
typedef union
{
    uint8_t ar[BBRIDGE_COM_PCK_INFO_SIZE];
    struct
    {
        uint8_t     ConnIndex;
        uint8_t     HeaderLength;
        uint8_t     HeaderOffset;
        uint8_t     DataLength;
    } st;
} PaketInfo_t;

typedef union
{
    uint8_t ar[BBRIDGE_COM_PCK_DATA_SIZE];
    struct
    {
        uint8_t header[BBRIDGE_COM_PCK_HDR_SIZE];
        uint8_t data[BBRIDGE_COM_PCK_FRMS_SIZE];
    }st;
} PaketData_t;

typedef struct
{
    PaketInfo_t     unPacketInfo;
    PaketData_t     unPacketData;
} BBridgeCommPacket_t;


/**
 * @brief BBridge Command
 */
 typedef struct
{
    uint8_t length;
    uint8_t data[BBRDIGE_CMD_MAX_DATA_LEN];
} BBridgeCommandData_t;

typedef struct
{
    BBridgeCMDId_t id;
    BBridgeCommandData_t cmd;
} BBridgeCommand_t;

typedef struct
{
    uint8_t addrType; /*!< Address Type: @ref GAP_ADDR_TYPE_DEFINES*/
    uint8_t addr[6]; /*!< Device's Address*/
    uint8_t broadcastMsg[BB_MAX_BROADCAST_MSG];
    uint8_t broadcastMsgLength;
    int8_t rssi;
} BBridgeBTDevice_t;

typedef struct
{
    uint16_t cnnhandle;
    uint8_t isValidated;
    uint8_t isConnected;
    BBridgeBTDevice_t btDevice;
} BBridgeConnection_t;

typedef BBCMDType_t (*GetCMDType_t)(BBridgeCMDId_t cfgID);
typedef uint8_t (*ProcessSetCMD_t)(const BBridgeCommand_t * cmd);
typedef uint8_t (*ProcessGetCMD_t)(const BBridgeCommand_t * cmd, uint8_t * data,
        uint8_t * dataLength);
typedef uint8_t (*SendPantherNACK_t)(BBridgeCMDId_t cmdID,
        BBridgeNACKReason_t reason);
typedef uint8_t (*SendPantherACK_t)(BBridgeCMDId_t cmdID,
        const uint8_t * extraData, uint8_t length);
typedef uint8_t (*SendPantherEVT_t)(BBridgeEvents_t cmdID,
        const uint8_t * extraData, uint8_t length);
typedef uint8_t (*onBtConnection)(uint8_t status, uint16_t devhandle,
        const uint8_t * devAddr);
typedef uint8_t (*onDevDiscovered)(int8_t rssi, uint8_t addrType,
        const uint8_t * addr, const uint8_t * data, uint8_t dataLength);
typedef void (*onRSSI)(uint16_t connHandle, int8_t rssi);
typedef uint8_t (*BTDataExchangeFnc)(uint16_t x, const uint8_t * data,
        uint8_t length);
typedef uint8_t (*BTDataIndexExchangeFnc)(uint8_t x, const uint8_t * data,
        uint8_t length);
typedef uint8_t (*BBGeneric3Uint_t)(uint8_t x, uint16_t y, uint8_t z);
typedef uint8_t (*BBSetMode)(BBridgeOpMode_t mode);
typedef uint8_t (*BBUpdateParams)(uint16_t connHandle, uint16_t connMin,
        uint16_t connMax, uint16_t slaveLatency, uint16_t connTimeout);

/**
 * @brief callbacks and functions to interface with the BBridge module
 */
typedef struct
{
    ProcessSetCMD_t proccessSetCmd;
    ProcessGetCMD_t proccessGetCmd;
    BBCharCB_t isTxToPantherComplete;
    BBGenericVoidVoidCB_t releaseDataHandler;
    SendPantherNACK_t pushNACK;
    SendPantherACK_t pushACK;
    SendPantherEVT_t pushEVENT;
    GetCMDType_t getCMDType;
    BBGenericVoiduint8_tCB_t setWakeUPLine;
    BTDataIndexExchangeFnc sendBTData;/*HT@20171201: to be removed in next release */
    BTDataIndexExchangeFnc sendBTDataCommand;
    BBCharCB_t hasBTData;
    DataExchangeFnc setBroadcastMsg;
    BBGenericu8_u8_tCB_t onConnectionValidated;
    BBGenericu8_u8_tCB_t disconnectBTDevice;
    DataExchangeFncGet32 generateSeed;
    DataExchangeFnc3232 calculateAuthKey;
    DataExchangeFnc connect;
    uint8_t scanAllowed;
    DataExchangeNConstFnc storageRead;
    DataExchangeFnc storageWrite;
    BBGeneric3Uint_t onBTDisconnection; /*<! callback from HW when a disconnection occurs*/
    BBGenericVoiduint8_tuint16_tCB_t onBTConnection;/*<! callback from HW when a connection occurs*/
    uint8_t sharedMemValue[BB_MAX_BROADCAST_MSG];
    uint8_t sharedMemValueLength;
    BBridgeConnection_t btConnections[BB_MAX_SCANNER_BT_CONNS];
    uint8_t totalConnected;
    BBridgeBTDevice_t btScanResult[BB_MAX_SCAN_RES];
    BBCharCB_t btDeviceInitialized;
    uint8_t isDevInitialized;
    uint8_t btScanResultTotal;
    uint8_t btScanBusy;
    uint8_t isConnecting;
    BBSetMode initDeviceOPMode;
    DataExchangeFncGet32 getSystime;
    DataExchangeFnc3232 getSystimeDiff;
    BBUpdateParams updateConnectionParams;
    BBGenericVoidVoidCB_t gotosleep;
    BBGenericVoiduint32_tCB_t BLE_Delay;
} BBridgeAppInterface_t;

/**
 * @brief Functions to interface with the Hardware
 * (TI OSAL and HAl for this project)
 */
typedef struct
{
    BBGenericVoiduint8_tCB_t wupSetter;
    BBCharCB_t wupGetter;
    DataExchangeFnc broadcastMsgSetter;
    BTDataExchangeFnc transmitBTData;/*HT@20171201: to be removed in next release */
    BTDataExchangeFnc  transmitBTDataCommand;
    BBGenericVoiduint16_tCB_t terminateConnection;
    DataExchangeFnc connect;
    DataExchangeNConstFnc storageRead;
    DataExchangeFnc storageWrite;
    BBSetMode initDeviceOPMode;
    DataExchangeFnc pushTXData;
    BBGenericVoid_u16_tCB_t getActiveTime;
    BBGenericu8_u16_tCB_t setActiveTime;
    DataExchangeFncGet32 getSystime;
    BBUpdateParams updateConnectionParams;
    BBGenericVoidVoidCB_t gotosleep;
    BBGenericVoiduint32_tCB_t BLE_Delay;
} BBridgeHWInterface_t;

typedef struct
{
    uint8_t taskID;
    BBGenericVoidVoidCB_t onBTDeviceInit;
    BBGenericVoidVoidCB_t onDiscoveryReady;
    onBtConnection onBTConnection;
    BBGeneric3Uint_t onBTDisconnection;
    onDevDiscovered scannerOnDeviceDiscovered;
    onRSSI onBLERSSI;
    uint8_t advertisingEnabled;
    uint16_t activeTime;
    BBGenericVoiduint16_tCB_t terminateConnection;
    uint16_t connHandle; /* only for the connectable mode */
    BBGenericVoiduint16uin8_tCB_t onLinkUpdate;
    fpHandleReceivedFrame_t HandleReceivedFrame;
} BBridgeInterface_t;

#endif /* BBRIDGEDEFS_H_ */

/** @}*/
