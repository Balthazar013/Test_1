/**
 * \addtogroup BBridgeApp
 * @{
 *
 * @file  BBridgeApp
 * @author  p344575
 * @brief   Business logins implementation for the BBridge application. It
 * contains shared functions and definitions to be used across the BBridge
 * application.
 *
 * @copyright &copy; 2016 Porsche Engineering Services GmbH and Bombardier Primove GmbH
 *
 * @internal
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: Reiner Bogenfürst
 * $Revision: 18134 $
 * $Id: BBridgeApp.c 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */
#include "BBridgeApp.h"
#include "DataHandler.h"
#include <stdlib.h>
#include <string.h>
#include "IdleMode.h"
#include "ConnectableMode.h"
#include "central.h"
#include "ScannerMode.h"
#include <stdlib.h>
#include "SPITransportLayer.h"
#include "osal_snv.h"
#include "hal_mcu.h"



typedef struct
{
    /**
    * @brief Stores the length of each configuration for the BBridge application
    */
    uint8_t configLengths[BB_MAX_CONFIGS];
    
    /**
    * @brief It stores a pointer to the each configuration value available
    */
    uint8_t configValues[BB_MAX_CONFIGS][BB_MAX_CONFIG_LENGTH];
    
    /*uint8_t sharedBroadOrFilterMsg[BB_MAX_EXT_DATA];*/
    
    /**
    * @brief used to check whether the initConfiguration function has been
    * called already or not (mainly needed for testing purposes)
    */
    uint8_t isModuleInitialized;
    
    /**
    * @brief Set when a message to Panther has been transmitted
    */
    uint8_t isDataHandlerDeliveryComplete;
    
    /**
    * @brief BBridge application state
    */
    BBridgeAppState_t state;
    
    /**
    * @brief Currently selected operating mode
    */
    BBridgeOpMode_t selectedOpMode;
    
    /**
    * @brief Previous selected operating mode
    */
    BBridgeOpMode_t prevOpMode;
    
    /**
    * @brief Used in different areas to transfer array of data between
    * different module
    */
    uint8_t sharedMemValueBuffer[BB_MAX_BROADCAST_MSG];
    
    /**
    * @brief Stores the current broadcast message value
    * @note Another copy of this value is also available within the BLE stack
    */
    uint8_t broadcastMsg[BB_MAX_BROADCAST_MSG];
    
    /**
    * @brief Stores the current filter message value
    */
    uint8_t filterMsg[BB_MAX_BROADCAST_MSG];
    
    /**
    * @brief Structure pointer that contains hardware-dependent functions
    */
    BBridgeHWInterface_t * hwInterface;
    
    /**
    * @brief Pointers to functions and values from this module to be used by
    * external modules.
    */
    BBridgeAppInterface_t bbridgeAppInterface;
    
    /**
    * @brief State for the "Command Processor" state machine
    */
    CommandProcessorState_t commandProcessorState;
    
    /**
    * @brief Used by the "Command interface" to transform SPI data in actual
    * BBridge commands
    */
    BBridgeCommIntData_t iffTMPData;
    
    /**
    * @brief Command that can given to the operating modes
    */
    BBridgeCommand_t pantherCMD;
    
    /**
    * @brief Flag to check whether the last command received from the Panther
    * has been processed or not
    */
    uint8_t isCMDProcessed;
    
    /**
    * @brief Internal shared memory to handle data for ACK, NACK and EVENTS
    */
    BBridgeCommIntData_t intData;
    
} BBridgeControls_t;

/* private functions*/
static uint8_t initConfigurations(void);
static uint8_t setInitialConfigValues(void);
static void onDataHandlerDeliveryComplete(void);
static void commandProcessorWork(void);
static uint8_t findBTIndex(uint16_t connHandle);
#if 0
static void resetScannerModeState(void);
static void resetConnectableModeState(void);
static void resetIdleModeState(void);
static void resetAllConnections(void);
#endif
static uint8_t setConfigurationValue(const BBridgeCFGId_t cfgID,
                                     const uint8_t configValue[], uint8_t length);
static uint8_t getConfigurationValue(BBridgeCFGId_t cfgID, uint8_t resultData[],
                                     uint8_t * resultDataLength);
static BBridgeCFGId_t getCMDConfigID(BBridgeCMDId_t cmdID);
static uint8_t getCFGDataLength(BBridgeCFGId_t cfgID);

/* private variables*/
static BBridgeControls_t controls;

/**
* @brief Stores mapping commands to their "Command types"
*/
static const BBCMDType_t cmdTypes[BB_MAX_COMMANDS]=
{
    CMDTYPE_SET, /*BBCMD_SET_BROADCAST_MSG      */
    CMDTYPE_GET, /*BBCMD_GET_BROADCAST_MSG      */
    CMDTYPE_SET, /*BBCMD_SET_FILTER_MSG         */
    CMDTYPE_GET, /*BBCMD_GET_FILTER_MSG         */
    CMDTYPE_SET, /*BBCMD_SET_OP_MODE            */
    CMDTYPE_GET, /*BBCMD_GET_OP_MODE            */
    CMDTYPE_SET, /*BBCMD_DISCONNECT             */
    CMDTYPE_SET, /*BBCMD_SET_NVM_BYTE           */
    CMDTYPE_GET, /*BBCMD_GET_NVM_BYTE           */
    CMDTYPE_SET, /*BBCMD_SEND_DATA              */
    CMDTYPE_SET, /*BBCMD_SET_ADV_INTERVAL       */
    CMDTYPE_GET, /*BBCMD_GET_ADV_INTERVAL       */
    CMDTYPE_GET, /*BBCMD_GET_CONN_STATES        */
    CMDTYPE_GET, /*BBCMD_GET_CONN_RSSI          */
    CMDTYPE_GET, /*BBCMD_GET_CONN_ADDR          */
    CMDTYPE_GET, /*BBCMD_GET_CONN_BRM           */
    CMDTYPE_SET, /*BBCMD_SET_SLEEP_MODE         */
    CMDTYPE_SET, /*BBCMD_SET_SCAN_MODE          */
    CMDTYPE_SET, /*BBCMD_INITIATE_CONNECTION    */
    CMDTYPE_GET, /*BBCMD_GET_CONN_NAMES         */
    CMDTYPE_SET, /*BBCMD_REQ_SLEEP              */
    CMDTYPE_SET, /*BBCMD_SET_BOOT_MODE          */
    CMDTYPE_GET, /*BBCMD_GET_BOOT_MODE          */
    CMDTYPE_GET, /*BBCMD_GET_RESET_REASON       */
    CMDTYPE_GET, /*BBCMD_GET_OWN_ADDR           */
};

/**
* @brief Stores mapping from commands to their configuration keys
*/
static const BBridgeCFGId_t cmdConfigMap[BB_MAX_COMMANDS] = 
{
    BBCFG_BROADCAST_MSG, /*BBCMD_SET_BROADCAST_MSG      */
    BBCFG_BROADCAST_MSG, /*BBCMD_GET_BROADCAST_MSG      */
    BBCFG_FILTER_MSG,    /*BBCMD_SET_FILTER_MSG         */
    BBCFG_FILTER_MSG,    /*BBCMD_GET_FILTER_MSG         */
    BBCFG_OP_MODE,       /*BBCMD_SET_OP_MODE            */
    BBCFG_OP_MODE,       /*BBCMD_GET_OP_MODE            */
    BBCFG_NONE,          /*BBCMD_DISCONNECT             */
    BBCFG_NVM_BYTE,      /*BBCMD_SET_NVM_BYTE           */
    BBCFG_NVM_BYTE,      /*BBCMD_GET_NVM_BYTE           */
    BBCFG_NONE,          /*BBCMD_SEND_DATA              */
    BBCFG_ADV_INTERVAL,  /*BBCMD_SET_ADV_INTERVAL       */
    BBCFG_ADV_INTERVAL,  /*BBCMD_GET_ADV_INTERVAL       */
    BBCFG_NONE,          /*BBCMD_GET_CONN_STATES        */
    BBCFG_NONE,          /*BBCMD_GET_CONN_RSSI          */
    BBCFG_NONE,          /*BBCMD_GET_CONN_ADDR          */
    BBCFG_NONE,          /*BBCMD_GET_CONN_BRM           */
    BBCFG_NONE,          /*BBCMD_SET_SLEEP_MODE         */
    BBCFG_NONE,          /*BBCMD_SET_SCAN_MODE          */
    BBCFG_NONE,          /*BBCMD_INITIATE_CONNECTION    */
    BBCFG_NONE,          /*BBCMD_GET_CONN_NAMES         */
    BBCFG_NONE,          /*BBCMD_REQ_SLEEP              */
    BBCFG_BOOT_MODE,     /*BBCMD_SET_BOOT_MODE          */
    BBCFG_BOOT_MODE,     /*BBCMD_GET_BOOT_MODE          */
    BBCFG_NONE,          /*BBCMD_GET_RESET_REASON       */
    BBCFG_NONE,          /*BBCMD_GET_OWN_ADDR           */
};

/**
 * @brief It initializes the BBridge module.
 * @param hwInterface - interface with HW-Dependent calls
 * @return  BB_SUCCESS: ok\n
 *          1 - 15: Hardware interface not correctly allocated
 *          x+30: Error initializing DataHandler Module\n
 *          x+100: Error initializing configurations
 */
uint8_t BBridge_Init(BBridgeHWInterface_t * hwInterface)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    /* checking whether all hw interface calls were set correctly*/
    if (hwInterface == NULL)
    {
        funcRet = 1u;
    } 
    else if (hwInterface->pushTXData == NULL)
    {
        /* spi not allocated correctly*/
        funcRet = 2u;
    } 
    else if (hwInterface->wupSetter == NULL)
    {
        /* not allocated*/
        funcRet = 3u;
    } 
    else if (hwInterface->wupGetter == NULL)
    {
        /* not allocated*/
        funcRet = 4u;
    } 
    else if (hwInterface->transmitBTData == NULL)
    {
        /* not allocated*/
        funcRet = 6u;
    } 
    else if (hwInterface->terminateConnection == NULL)
    {
        /* not allocated*/
        funcRet = 7u;
    } 
#ifdef TARGET_ORU
    else if (hwInterface->connect == NULL)
    {
        /* not allocated*/
        funcRet = 8u;
    }
#endif
    else if (hwInterface->storageRead == NULL)
    {
        /* not allocated*/
        funcRet = 9u;
    } 
    else if (hwInterface->storageWrite == NULL)
    {
        /* not allocated*/
        funcRet = 10u;
    } 
    else if (hwInterface->initDeviceOPMode == NULL)
    {
        /* not allocated*/
        funcRet = 11u;
    }
#ifdef TARGET_PAD
    else if (hwInterface->broadcastMsgSetter == NULL)
    {
        /* not allocated*/
        funcRet = 5u;
    } 
    else if (hwInterface->getActiveTime == NULL)
    {
        /* not allocated*/
        funcRet = 12u;
    } 
    else if (hwInterface->setActiveTime == NULL)
    {
        /* not allocated*/
        funcRet = 13u;
    } 
#endif
    else if (hwInterface->getSystime == NULL)
    {
        /* not allocated*/
        funcRet = 14u;
    }
    else if (hwInterface->updateConnectionParams == NULL)
    {
        funcRet = 15u;
    }
    else
    {
        controls.hwInterface = hwInterface;
        controls.bbridgeAppInterface.setBroadcastMsg = controls.hwInterface->broadcastMsgSetter;
        
        /*
        * CONNECTING MODULES AND CALLBACKS
        * Initializing DataHandler module. It needs the "access" to a module that
        * can send and receive data to/from the Panther device over SPI
        */
         /*<!  Called when data has been delivered to Panther*/
        ret = DataHandler_Init(&onDataHandlerDeliveryComplete, hwInterface->pushTXData);
        if (ret != BB_SUCCESS)
        {
            funcRet = (ret + 30u);
        }
        else
        {
            /* init configurations*/
            ret = initConfigurations();
            if (ret != BB_SUCCESS)
            {
                funcRet = (100u + ret);
            }
            else
            {
                /* initializing module interface*/
                controls.bbridgeAppInterface.pushACK = &BBridge_PushACK;
                controls.bbridgeAppInterface.pushNACK = &BBridge_PushNACK;
                controls.bbridgeAppInterface.pushEVENT = &BBridge_PushEVENT;
                controls.bbridgeAppInterface.isTxToPantherComplete =
                        &BBridge_IsTxToPantherComplete;
                controls.bbridgeAppInterface.proccessGetCmd =
                        &BBridge_ProcessGetCmd;
                controls.bbridgeAppInterface.proccessSetCmd =
                        &BBridge_ProcessSetCmd;
                controls.bbridgeAppInterface.releaseDataHandler =
                        &BBridge_ReleaseDataHandler;
                controls.bbridgeAppInterface.getCMDType = &BBridge_GetCMDType;
                controls.bbridgeAppInterface.setWakeUPLine =
                        &BBridge_SetWakeUpLine;
                controls.bbridgeAppInterface.generateSeed =
                        &BBridge_GenerateSeed;
                controls.bbridgeAppInterface.calculateAuthKey =
                        &BBridge_GetAuthKey;
                controls.bbridgeAppInterface.onConnectionValidated =
                        &BBridge_OnConnectionValidated;
                controls.bbridgeAppInterface.connect =
                        &BBridge_StartBTConnection;
                controls.bbridgeAppInterface.onBTConnection =
                        &BBridge_OnBTConnection;
                controls.bbridgeAppInterface.storageRead = &BBridge_StorageRead;
                controls.bbridgeAppInterface.storageWrite =
                        &BBridge_StorageWrite;
                controls.bbridgeAppInterface.sendBTData = &BBridge_SendBTData; /*HT@20171201: to be removed in next release */
                controls.bbridgeAppInterface.sendBTDataCommand =&BBridge_SendBTDataCommand;
                controls.bbridgeAppInterface.disconnectBTDevice =
                        &BBridge_DisconnectDevice;
                controls.bbridgeAppInterface.onBTDisconnection =
                        &BBridge_OnBTDisconnection;
                controls.bbridgeAppInterface.initDeviceOPMode =
                        &BBridge_InitDeviceOPMode;
                controls.bbridgeAppInterface.getSystime = &BBridge_GetSysTime;
                controls.bbridgeAppInterface.getSystimeDiff =
                        &BBridge_GetSysTimeDiff;
                controls.bbridgeAppInterface.btDeviceInitialized =
                        &BBridge_BTDeviceInitialized;
                controls.bbridgeAppInterface.updateConnectionParams =
                        hwInterface->updateConnectionParams;
                controls.bbridgeAppInterface.gotosleep =
                        hwInterface->gotosleep;
                controls.bbridgeAppInterface.BLE_Delay =
                        hwInterface->BLE_Delay;
                
                /* initializing internal working variables*/
                controls.isDataHandlerDeliveryComplete = TRUE;
                controls.isModuleInitialized = FALSE;
#ifdef TARGET_ORU
                controls.selectedOpMode = BB_SCANNER_MODE;
#else
                controls.selectedOpMode = BB_CONNECTABLE_MODE;
#endif
                controls.prevOpMode = BB_NO_MODE;
                controls.state = BBAPP_IDLE;
                controls.isCMDProcessed = TRUE;
                controls.bbridgeAppInterface.isConnecting = FALSE;
            }
        }
    }
    
    return funcRet;
}

/**
 * @brief This callback is called automatically the DataHandler module to state
 * that the last transfer to the Panther device has been completed.
 * @attention not to be mixed with "BBridge_OnTxToPantherComplete" which is
 * actually callback from the TI BLE system to the BBridgeCommons interface.
 */
static void onDataHandlerDeliveryComplete(void)
{
    controls.isDataHandlerDeliveryComplete = TRUE;
}

/**
 * @brief Called by the OSAL hardware when SPI data has been received from the
 * SPI channel.
 * @param data
 * @param length
 * @note Data received in this call is directly forwarded to the DataHandler
 * module. In case the module is not able to receive data, SPI messages will
 * be dropped. Make sure to send SPI commands only when the previous command
 * has been properly completed.
 * @see DataHandler_OnRxDataFromPanther
 */
void BBridge_OnSPIRxComplete(const uint8_t data[], uint8_t length)
{
    /* not handling return values here*/
    (void) DataHandler_OnRxDataFromPanther(data, length);
}

/**
 * @brief Callback from the HW when the SPI transmission is done.
 * @attention Not to be confused with "onTxToPantherComplete" which is actually
 * a callback from the DataHandler module.
 * @see DataHandler_OnTxDataToPantherComplete
 */
void BBridge_OnSPITxComplete(void)
{
    /* notifying the DataHandler that the last SPI message has been transmitted*/
    DataHandler_OnTxDataToPantherComplete();
}

/**
 * @brief It initializes the system configurations structure
 * @note Here the maximum length for every configuration is set and the needed
 * memory for every value is allocated
 * @return  BB_SUCCESS: when ok\n
 *          1: in case of invalid configurations
 */
static uint8_t initConfigurations(void)
{
    /* initializing config arrays*/
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (controls.isModuleInitialized == FALSE)
    {
        memset(controls.configLengths, 0, BB_MAX_COMMANDS); /* setting all to 0*/
        memset(controls.configValues, 0, BB_MAX_COMMANDS); /* setting all to "NULL"*/
    }
    
    /* ----------------------------*/
    /* setting the configuration length for every configuration available*/
    /* @attention DO NOT USE MORE THAN "BB_MAX_CONFIG_LENGTH"*/
    controls.configLengths[BBCFG_FILTER_MSG] = BB_MAX_BROADCAST_MSG;
    controls.configLengths[BBCFG_BROADCAST_MSG] = BB_MAX_BROADCAST_MSG;
    controls.configLengths[BBCFG_OP_MODE] = 1u;
    controls.configLengths[BBCFG_ADV_INTERVAL] = 2u;
    controls.configLengths[BBCFG_NVM_BYTE] = 1u;
    controls.configLengths[BBCFG_BOOT_MODE] = 4u;
    
    /* only call setInitialConfigValues after allocating*/
    ret = setInitialConfigValues();
    if (ret != BB_SUCCESS)
    {
        funcRet = ret;
    }
    else
    {
        controls.isModuleInitialized = TRUE;
    }
    
    return funcRet;
}

/**
 * @brief It returns the configuration length for a given configuration
 * @note If length is 0, the configuration has not been initialized -> non
 * existent
 * @param cfgID
 * @return configuration length
 */
static uint8_t getCFGDataLength(BBridgeCFGId_t cfgID)
{
    return controls.configLengths[cfgID];
}

/**
 * @brief It return a copy of the configuration value and its length
 *
 * @param cfgID - existing and valid ID
 * @param result - pointer to a BBridgeConfigValue_t variable
 * @return  0(BB_SUCCESS) - configuration value was loaded correctly\n
 *          1 - invalid configuration ID\n
 *          2 - destination pointer (result) is not properly allocated\n
 *          3 - value destination pointer not correctly allocated
 */
static uint8_t getConfigurationValue(BBridgeCFGId_t cfgID, uint8_t resultData[], uint8_t * resultDataLength)
{
    uint8_t cfgLength;
    uint8_t ret = BB_SUCCESS;
    
    /* checking if the destination pointer is not NULL*/
    if (resultData == NULL)
    {
        ret = 2u;
    }
    else if (cfgID == BBCFG_BROADCAST_MSG)
    {
    
        cfgLength = getCFGDataLength(cfgID);
        *resultDataLength = cfgLength;
        /* special configuration with 31 bytes*/
        memset(resultData, 0, BB_MAX_BROADCAST_MSG);
        if (cfgLength > 0u)
        {
            memcpy(resultData, controls.broadcastMsg, (uint16_t) cfgLength);
        }
    }
    else if (cfgID == BBCFG_FILTER_MSG)
    {
        cfgLength = getCFGDataLength(cfgID);
        *resultDataLength = cfgLength;
        /* special configuration with 31 bytes*/
        memset(resultData, 0, BB_MAX_BROADCAST_MSG);
        if (cfgLength > 0u) 
        {
            memcpy(resultData, controls.filterMsg, (uint16_t) cfgLength);
        }
    }
    else
    {
        if (cfgID >= BB_MAX_CONFIGS)
        {
            ret = 1u;
        }
        else
        {
            /* checking if the configuration ID is valid*/
            cfgLength = getCFGDataLength(cfgID);
            if (cfgLength == 0u)
            {
                ret = 1u; /* configuration not existent*/
            }
            else
            {
                *resultDataLength = cfgLength;
                /* normal configuration with max 4 size*/
                memcpy(resultData, controls.configValues[cfgID], (uint16_t) cfgLength);
            }
        }
    }
    
    return ret;
}

/**
 * @brief It sets a configuration value
 * @param cfgID
 * @param configValue
 * @attention the memory length given shall match the same value from the
 * memory allocated, not the actual data length being set.
 * @return  BB_SUCCESS: value set correctly\n
 *          1: configuration value ID not valid or not allocated\n
 *          2: allocated length and given length does not match\n
 *          3: invalid configuration value (not allocated)\n
 *          4: configuration input not valid\n
 *          5: could not set value
 *
 */
static uint8_t setConfigurationValue(const BBridgeCFGId_t cfgID, const uint8_t configValue[], uint8_t length)
{
    uint16_t tmp;
    uint8_t ret = BB_SUCCESS;
    uint8_t cfgLength = getCFGDataLength(cfgID);
    static uint8 NVM_broadcast_mess[31];
    
    if (cfgLength == 0u)
    {
        ret = 1u; /* configuration not valid*/
    }
    else if (configValue == NULL)
    {
        /* checking if the configuration input is valid*/
        ret = 4u; /* invalid configuration value*/
    }
    else if (cfgID == BBCFG_BROADCAST_MSG)
    {
        if (length > BB_MAX_BROADCAST_MSG)
        {
            ret = 2u;
        }
        else
        {
            /* storing value in the BBridgeApp interface*/
            /* special configuration with 31 bytes*/
            memset(&controls.broadcastMsg[0], 0, BB_MAX_BROADCAST_MSG);
            memcpy(&controls.broadcastMsg[0], configValue, (uint16_t) length);
            controls.configLengths[cfgID] = length;
            
            if(osal_snv_read(NVM_BLOCK_ID_SCAN_RESP, NVM_BLOCK_LEN_SCAN_RESP, &NVM_broadcast_mess[0]) == SUCCESS)
            {
                if(memcmp(&NVM_broadcast_mess[0],&controls.broadcastMsg[0],NVM_BLOCK_LEN_SCAN_RESP)!= 0)
                {
                    osal_snv_write(NVM_BLOCK_ID_SCAN_RESP, NVM_BLOCK_LEN_SCAN_RESP, &controls.broadcastMsg[0]);
                }
            }
            else
            {
                osal_snv_write(NVM_BLOCK_ID_SCAN_RESP, NVM_BLOCK_LEN_SCAN_RESP, &controls.broadcastMsg[0]);
            }
            
            /* setting value in the HW interface*/
            if ((controls.hwInterface != NULL) && (controls.hwInterface->broadcastMsgSetter != 0))
            {
                if (controls.hwInterface->broadcastMsgSetter(controls.broadcastMsg, length) != BB_SUCCESS)
                {
                    /* could not set value in the HW interface*/
                    ret = 5u;
                }
            }
        }
    }
    else if (cfgID == BBCFG_FILTER_MSG)
    {
        if (length > BB_MAX_BROADCAST_MSG)
        {
            ret = 2u;
        } else {
            memset(&controls.filterMsg[0], 0, BB_MAX_BROADCAST_MSG);
            if (length == 1u) {
                /* SPECIAL CASE to set no filter value*/
                controls.configLengths[cfgID] = 0u;
            } else {
                memcpy(controls.filterMsg, configValue, (uint16_t) length);
                controls.configLengths[cfgID] = length;
            }
        }
    }
    else
    {
        if (length > cfgLength)
        {
            ret = 2u; /* configuration value is out of range*/
        }
        else
        {
            /* normal configuration with max 2 size*/
            /* coping configuration value*/
            memcpy(&controls.configValues[cfgID], configValue, (uint16_t) controls.configLengths[cfgID]);
            if (cfgID == BBCFG_ADV_INTERVAL)
            {
                tmp = (uint16_t) (controls.configValues[BBCFG_ADV_INTERVAL][0]);
                tmp |= (uint16_t) ((uint16_t) controls.configValues[BBCFG_ADV_INTERVAL][1] << 8);
                if (controls.hwInterface->setActiveTime(tmp) != BB_SUCCESS)
                {
                    /* could not set value in the HW interface*/
                    ret = 5u;
                }
            }
        }
    }
    
    return ret;
}

/**
 * @brief Setting the initial "factory" values for every configuration
 * @param tmp: shared memory needed to operate
 */
static uint8_t setInitialConfigValues(void)
{
    uint16_t tmp;
    memset(controls.broadcastMsg, 0, BB_MAX_BROADCAST_MSG);
    /*memcpy(controls.broadcastMsg, "#BBridge Connectable#", 21);*/
    
    memset(controls.filterMsg, 0, BB_MAX_BROADCAST_MSG);
    /*memcpy(controls.filterMsg, "#BBridge Connectable#", 21);*/
    
    /* default advertising interval*/
    tmp = DEFAULT_ADVERTISING_INTERVAL;
    controls.configValues[BBCFG_ADV_INTERVAL][0] = ((uint8_t) tmp & 0xFFU);
    controls.configValues[BBCFG_ADV_INTERVAL][1] |= ((uint8_t) (tmp >> 8U) & 0xFFU);
    
    return BB_SUCCESS;
}

/**
 * @brief It returns the type of a command
 * @param cfgID
 * @see BBridgeCMDId_t
 * @see BBCMDType_t
 * @return BBCMDType_t
 */
BBCMDType_t BBridge_GetCMDType(BBridgeCMDId_t cfgID)
{
    return cmdTypes[cfgID];
}

/**
 * @brief It sets a configuration value in the module's configuration table.
 * If necessary it calls hardware-dependent functions to set and store the given
 * value
 * @param BBridgeCommand_t
 * @return  BB_SUCCESS: processed correctly\n
 *          1: not a valid SET command\n
 *          5: invalid command length\n
 *          6: could not write in the NVM\n
 *          10+x: see returns from setConfigurationValue
 */
uint8_t BBridge_ProcessSetCmd(const BBridgeCommand_t * cmd)
{
    BBridgeCFGId_t cfgId;
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    /* Checking whether the command is of type SET */
    if (BBridge_GetCMDType(cmd->id) != CMDTYPE_SET)
    {
        funcRet = 1u; /* not a valid SET command*/
    }
    else if (cmd->id == BBCMD_SET_NVM_BYTE)
    {
        /* checking whether this command requires Non-volatile memory access*/
        
        /* this command requires two parameters (index and value to be set)*/
        if (cmd->cmd.length != 2u)
        {
            funcRet = 5u;
        }
        else
        {
            /* Calling hw-dependend function to store a value in the NVM*/
            if (BBridge_StorageWrite((&cmd->cmd.data[1]), cmd->cmd.data[0]) != BB_SUCCESS)
            {
                funcRet = 6u; /* could not write value from storage*/
            }
        }
    }
    else if (cmd->id == BBCMD_SET_BOOT_MODE)
    {
        if (cmd->cmd.length != 4u)
        {
            funcRet = 7u;
        }
        else
        {
            if (osal_snv_write(NVM_BLOCK_ID_BOOTMODE, NVM_BLOCK_LEN_BOOTMODE, (uint8 *)cmd->cmd.data) != BB_SUCCESS)
            {
                funcRet = 8u;
            }
        }
    }
    else
    {
        cfgId = getCMDConfigID(cmd->id);
        ret = setConfigurationValue(cfgId, cmd->cmd.data, cmd->cmd.length);
        
        if (ret != BB_SUCCESS)
        {
            funcRet = (ret + 10u);
        }
    }
    
    return funcRet;
}

/**
 * @brief It gives the configuration ID in which the command shall act upon
 * @param cmdID
 * @return BBridgeCFGId_t configurationID
 */
static BBridgeCFGId_t getCMDConfigID(BBridgeCMDId_t cmdID)
{
    return cmdConfigMap[cmdID];
}

/**
 * @brief It loads a BBridge configuration value
 * @param cnfId
 * @param cnfigVals
 * @param configLength
 * @return  BB_SUCCESS: configuration loaded correctly\n
 *          1: invalid configuration ID\n
 *          2: invalid data destination pointer\n
 *          3: invalid length destination pointer\n
 *          4: the command is not from a valid GET type\n
 *          5: invalid command input or parameters\n
 *          6: internal error
 *
 */
uint8_t BBridge_ProcessGetCmd(const BBridgeCommand_t * cmd, uint8_t data[], uint8_t * dataLength)
{
    BBridgeCFGId_t cfgId;
    uint8_t ret = BB_SUCCESS;
    
    if (BBridge_GetCMDType(cmd->id) != CMDTYPE_GET)
    {
        ret = 4u;
    }
    else if (cmd->id == BBCMD_GET_OP_MODE)
    {
        data[0] = (uint8_t) controls.selectedOpMode;
        *dataLength = 1u;
    }
    else if (cmd->id == BBCMD_GET_NVM_BYTE)
    {
    
        /* this command requires one parameter for the byte index*/
        if (cmd->cmd.length != 1u)
        {
            ret = 5u;
        }
        else
        {
            if (BBridge_StorageRead(data, cmd->cmd.data[0]) == BB_SUCCESS)
            {
                *dataLength = 1u;
            }
            else
            {
                ret = 6u; /* could not read value from storage*/
            }
        }
    }
    else if(cmd->id == BBCMD_GET_BOOT_MODE)
    {
        /* this command requires no parameters */
        if (cmd->cmd.length != 0)
        {
            ret = 7u;
        }
        else
        {
            if (osal_snv_read(NVM_BLOCK_ID_BOOTMODE, NVM_BLOCK_LEN_BOOTMODE, data) == BB_SUCCESS)
            {
                *dataLength = 4u;
            }
            else
            {
                ret = 8u;
            }
        }
    }
    else if(cmd->id == BBCMD_GET_RESET_REASON)
    {
        /* this command requires no parameters */
        if (cmd->cmd.length != 0)
        {
            ret = 9u;
        }
        else
        {
            data[0] = ((uint8)(SLEEPSTA>>3)&0x3); /*get only the reset reason 2bits*/
            *dataLength = 1u;
        }
    }
    else
    {
        cfgId = getCMDConfigID(cmd->id);
        ret = getConfigurationValue(cfgId, data, dataLength);
    }
    
    return ret;
}

/**
 * @brief It releases the DataHandler module from a "locked" state
 */
void BBridge_ReleaseDataHandler(void)
{
    DataHandler_RxDataFromPantherProcessed();
}

/**
 * @brief It reads the actual state of the WAKEUP line PIN
 * @return  BB_SUCCESS: LOW\n
 *          1: HIGH
 */
uint8_t BBridge_GetWakeUpLineState(void)
{
    //return (controls.hwInterface->wupGetter() == TRUE) ? 1u : 0u;
    return 0;
}

/**
 * @brief It sets the WAKEUP line PIN
 * @param   1: HIGH\n
 *          0: LOW
 */
void BBridge_SetWakeUpLine(uint8_t enable)
{
    controls.hwInterface->wupSetter(enable);
}

/**
 * @brief it sets data to transferred over the Blueooth interface
 * @param devIndex
 * @param data
 * @param length
 * @param authRequired
 * @return  BB_SUCCESS: ok\n
 *          1: device index out of range\n
 *          2: device is not connected\n
 *          3: cannot send data in idle mode\n
 *          x+100: transmission error from HW interface
 */
uint8_t BBridge_SendBTData(uint8_t devIndex, const uint8_t data[], uint8_t length)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (controls.selectedOpMode == BB_IDLE_MODE)
    {
        funcRet = 100u; /* cannot send msgs in IDLE mode*/
    }
    else if (devIndex >= BB_MAX_SCANNER_BT_CONNS)
    {
        funcRet = 101u; /* devIndex out of range*/
    }
    else if (controls.bbridgeAppInterface.btConnections[devIndex].isConnected == FALSE)
    {
        funcRet = 102u;
    }
    else
    {
        ret = controls.hwInterface->transmitBTData(
                controls.bbridgeAppInterface.btConnections[devIndex].cnnhandle,
                data,
                length);
                
        if (ret != BB_SUCCESS)
        {
            funcRet = ret;
        }
    }
    
    return funcRet;
}

/**
 * @brief it sets data to transferred over the Blueooth interface
 * @param devIndex
 * @param data
 * @param length
 * @param authRequired
 * @return  BB_SUCCESS: ok\n
 *      1: device index out of range\n
 *      2: device is not connected\n
 *      3: cannot send data in idle mode\n
 *      x+100: transmission error from HW interface
 */
uint8_t BBridge_SendBTDataCommand(uint8_t devIndex, const uint8_t data[], uint8_t length)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (controls.selectedOpMode == BB_IDLE_MODE)
    {
        funcRet = 100u; /* cannot send msgs in IDLE mode*/
    }
    else if (devIndex >= BB_MAX_SCANNER_BT_CONNS)
    {
        funcRet = 101u; /* devIndex out of range*/
    }
    else if (controls.bbridgeAppInterface.btConnections[devIndex].isConnected == FALSE) 
    {
        funcRet = 102u;
    }
    else
    {
        ret = controls.hwInterface->transmitBTDataCommand(
                                            controls.bbridgeAppInterface.btConnections[devIndex].cnnhandle,
                                            data, 
                                            length);
        if (ret != BB_SUCCESS)
        {
            funcRet = ret;
        }
    }
    
    return funcRet;
}

/**
 * @brief Called by the BBridge interface when a connection handle is disconnected
 * @param connHandle
 * @return  100x: forwarded to connectable mode (100 = accepted)\n
 *          200x: forwarded to scanner mode (200 = accepted)\n
 *          BB_SUCCESS: ok: but not forwarded to any operating mode\n
 *          1: connection not available in the BBridge interface\n
 *          2: could not forward to any mode
 *
 */
uint8_t BBridge_OnBTDisconnection(uint8_t status, uint16_t connHandle, uint8_t reason)
{
    uint8_t i;
    uint8_t funcRet = BB_SUCCESS;
    
    /* searching for handle*/
    for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; i++) 
    {
        if (controls.bbridgeAppInterface.btConnections[i].cnnhandle == connHandle)
        {
            /* controls.bbridgeAppInterface.btConnections[i].isValidated = 0;  attention: do not set the isValidated here*/
            
            /* forwarding event*/
            if (controls.bbridgeAppInterface.btConnections[i].isConnected == TRUE)
            {
                controls.bbridgeAppInterface.btConnections[i].isConnected = FALSE;
#ifdef TARGET_PAD
                if (controls.selectedOpMode == BB_CONNECTABLE_MODE)
                {
                    funcRet = (ConnectableMode_OnDisconnection(i, status, reason) + 100u);
                }
#else
                if (controls.selectedOpMode == BB_SCANNER_MODE)
                {
                    funcRet = (ScannerMode_OnDisconnection(i, status, reason) + 200u);
                }
#endif
                else
                {
                    /* There is no operating mode available*/
                }
            }
            else
            {
                funcRet = 1u;
            }
            
            break;
        }
    }
    
    if (i >= BB_MAX_SCANNER_BT_CONNS)
    {
        funcRet = 1u; /* connection not found */
    }
    
    return funcRet; /* connection handle not available in the interface*/
}

void BBridge_OnLinkUpdate(uint16_t connHandle, uint8_t status)
{
#ifdef TARGET_ORU
    if (controls.selectedOpMode == BB_SCANNER_MODE)
    {
        ScannerMode_OnLinkUpdate(connHandle, status);
    } 
#else
    if (controls.selectedOpMode == BB_CONNECTABLE_MODE)
    {
        /* no need to forward to connectable*/
        ConnectableMode_OnLinkUpdate(connHandle, status);
    }
#endif
}

/**
 * @brief Callback called when a new Bluetooth connection is established.
 * It processes the callback event and data given and forward the new connection
 * to the correct operating mode callbacks.
 * @param status 0, non-zero: failure
 * @param connHandle
 * @param devAddr
 * @return  BB_SUCCESS: ok\n
 *          1: cannot handle more connections\n
 *          2: cannot accept connections in the current operating mode\n
 *          3: connection failed\n
 *          4: CONNECTABLE: there is already a connection (only 1 can be handled)
 */
uint8_t BBridge_OnBTConnection(uint8_t status, uint16_t connHandle, const uint8_t devAddr[])
{
    uint8_t i;
    
#ifdef TARGET_ORU
    uint8_t j, ret;
#endif

    uint8_t funcRet = BB_SUCCESS;
    
    /* checking feedback given for the connection status*/
    if (status != BB_SUCCESS)
    {
        /* connection failed*/
        controls.bbridgeAppInterface.isConnecting = FALSE;
#ifdef TARGET_PAD
        if (controls.selectedOpMode == BB_CONNECTABLE_MODE)
        {
            /* in connectable mode there no reason to notify when a connection arrives with error*/
            /* error happened during connection establishment*/
        }
#else
        if (controls.selectedOpMode == BB_SCANNER_MODE)
        {
            /* since scanner initiates connections, it shall be notified when*/
            /* connection errors occur.*/
            ScannerMode_OnConnection(status, BB_INVALID_DEV_INDEX);
        }
#endif
        else
        {
            //TODO:
        }
        
        funcRet = 3u;
    } 
    else 
    {
        /* ------------------------*/
        /* checking business logics conditions for the active operating mode*/
        /* ------------------------*/
#ifdef TARGET_PAD
        if (controls.selectedOpMode == BB_CONNECTABLE_MODE)
        {
            /* checking whether there is a connection already available. In case any*/
            /* the new connection shall be ignored*/
            for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; i++)
            {
                if (controls.bbridgeAppInterface.btConnections[i].isConnected == TRUE)
                {
                    controls.hwInterface->terminateConnection(connHandle);
                    funcRet = 4u; /* there is already a connection*/
                    break;
                }
            }
            /* there is no connection yet (ok to proceed)*/
        }
#else
        if (controls.selectedOpMode == BB_SCANNER_MODE)
        {
            /* checking if there is a connection with the same device address*/
            for (j = 0u; j < BB_MAX_SCANNER_BT_CONNS; j++) 
            {
                if (controls.bbridgeAppInterface.btConnections[j].isConnected == TRUE)
                {
                    if (memcmp(controls.bbridgeAppInterface.btConnections[j].btDevice.addr, devAddr, 6u) == 0)
                    {
                        /* there is a device with the same address already connected*/
                        controls.hwInterface->terminateConnection(connHandle);
                        controls.bbridgeAppInterface.isConnecting = FALSE;
                        funcRet = 5u;
                        break;
                    }
                }
            }
        }
#endif
        else
        {
            controls.bbridgeAppInterface.isConnecting = FALSE;
            funcRet = 2u; /* cannot accept connections in this operating mode*/
        }
        
        if (funcRet == BB_SUCCESS) 
        {
            /* Handling new "accepted" connection*/
            /* new connection established, find an empty spot to store connection info*/
            for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; i++)
            {
                if (controls.bbridgeAppInterface.btConnections[i].isConnected == FALSE)
                {
                    /* this spot is free to be used -> taking it*/
                    controls.bbridgeAppInterface.btConnections[i].isConnected = TRUE;
                    controls.bbridgeAppInterface.btConnections[i].isValidated = FALSE;
                    controls.bbridgeAppInterface.btConnections[i].cnnhandle = connHandle;
                    
                    /* notifying operating mode callbacks*/
#ifdef TARGET_PAD
                    if (controls.selectedOpMode == BB_CONNECTABLE_MODE)
                    {
                        controls.bbridgeAppInterface.btConnections[i].btDevice.rssi = 0;
                        
                        memset(controls.bbridgeAppInterface.btConnections[i].btDevice.broadcastMsg,
                                0, BB_MAX_BROADCAST_MSG); /* no value loaded/ available at this point */
                        
                        memcpy(controls.bbridgeAppInterface.btConnections[i].btDevice.addr, devAddr, 6u);
                        
                        ConnectableMode_OnConnection(i);
                    
                    }
#else
                    if (controls.selectedOpMode == BB_SCANNER_MODE)
                    {
                    
                        /* ------------------------------------*/
                        /* Copy device data from the SCAN list to the "connection" list*/
                        /* ------------------------------------*/
                        for (j = 0u; j < BB_MAX_SCAN_RES; j++) /* matching by device address */
                        {
                            if (memcmp(controls.bbridgeAppInterface.btScanResult[j].addr, devAddr, 6u) == 0)
                            {
                                /* copy device from scan results */
                                controls.bbridgeAppInterface.btConnections[i].btDevice.addrType =
                                        controls.bbridgeAppInterface.btScanResult[j].addrType;
                                
                                controls.bbridgeAppInterface.btConnections[i].btDevice.rssi =
                                        controls.bbridgeAppInterface.btScanResult[j].rssi;
                                
                                memcpy( controls.bbridgeAppInterface.btConnections[i].btDevice.addr,
                                        devAddr,
                                        6u);
                                        
                                controls.bbridgeAppInterface.btConnections[i].btDevice.broadcastMsgLength =
                                        controls.bbridgeAppInterface.btScanResult[j].broadcastMsgLength;
                                        
                                memcpy( controls.bbridgeAppInterface.btConnections[i].btDevice.broadcastMsg,
                                        controls.bbridgeAppInterface.btScanResult[j].broadcastMsg,
                                        (uint16_t) controls.bbridgeAppInterface.btScanResult[j].broadcastMsgLength);
                                break;
                            }
                        }
                        
                        controls.bbridgeAppInterface.isConnecting = FALSE;
                        ret = ScannerMode_OnConnection(0u, i);
                        if (ret == 2u)
                        {
                            /* operating mode cannot accept this connection -> disconnect*/
                            BBridge_DisconnectDevice(i);
                        }
                        else
                        {
                        
                        }
                    }
#endif
                    else
                    {
                        /* shall never get to this point (operating mode not handled)*/
                    }
                    
                    break;/* connection received correctly */
                }
            } /* end for  */
            
            if (i >= BB_MAX_SCANNER_BT_CONNS)
            {
                controls.bbridgeAppInterface.isConnecting = FALSE;
                funcRet = 1u; /* all possible connections are busy */
            }
        }
    }
    
    return funcRet;
}

/**
 * @brief it finds the index of a connected device by its CONN handler
 * @param connHandle
 * @return  BB_INVALID_DEV_INDEX: could not find
 *          index(i): device index in the btConnections list
 */
static uint8_t findBTIndex(uint16_t connHandle)
{
    uint8_t i;
    uint8_t ret = BB_INVALID_DEV_INDEX;
    for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; i++)
    {
        if (controls.bbridgeAppInterface.btConnections[i].isConnected == TRUE)
        {
            if (controls.bbridgeAppInterface.btConnections[i].cnnhandle == connHandle)
            {
                ret = i;
                break;
            }
        }
    }
    
    return ret;
}

/**
 * @brief Called by Bluetooth Stack when a new RSSI value is available for a
 * valid connection
 * @param connHandle
 * @param newRssi
 * @return  BB_SUCCESS: RSSI received and updated correctly
 *          1: could not find a connected device with the handle given
 *          2: cannot receive RSSI in idle mode
 */
uint8_t BBridge_OnRssi(uint16_t connHandle, int8_t newRssi) 
{
    uint8_t devIndex;
    uint8_t ret = BB_SUCCESS;
    
    if (controls.selectedOpMode == BB_IDLE_MODE)
    {
        ret = 2u; /* cannot receive RSSI in idle mode*/
    
    }
    else
    {
        devIndex = findBTIndex(connHandle);
        if (devIndex != BB_INVALID_DEV_INDEX)
        {
            controls.bbridgeAppInterface.btConnections[devIndex].btDevice.rssi = newRssi;
            ret = BB_SUCCESS;
        } 
        else
        {
            ret = 1u; /* could not find connected device*/
        }
    }
    
    return ret;
}

/**
 * @brief called by Bluetooth stack when device has been initialized
 */
void BBridge_OnDevInitDone(void)
{
    controls.bbridgeAppInterface.isDevInitialized = TRUE;
}

/**
 * @brief Callback from the Bluetooth hardware triggered when a new device has
 * been discovered.
 * @note It checks for duplicated advertisements.
 * @param rssi
 * @param addrType
 * @param addr
 * @param data
 * @param dataLength
 * @return  BB_SUCCESS: ok\n
 *          1: cannot receive new device when a scan event has not been initiated\n
 *          2: too many devices discovered already (dropping information)\n
 */
uint8_t BBridge_OnDevDiscovered(int8_t rssi, uint8_t addrType, const uint8_t addr[],
                                const uint8_t data[], uint8_t dataLength)
{
    uint8_t index, i, isDuplicated;
    uint8_t ret = BB_SUCCESS;
    
    /*As soon as scanning has been initiated, controls.bbridgeAppInterface.btScanBusy is set to TRUE.
    It is set to FALSE when the Device Discovery Process completes */
    if(controls.bbridgeAppInterface.btScanBusy != TRUE)
    {
        /* shall only operate when "btScanBusy"*/
        ret = 1u;
    }
    else
    {
        index = controls.bbridgeAppInterface.btScanResultTotal;
        if (index >= BB_MAX_SCAN_RES)
        {
            /* ignoring discovered device*/
            GAPCentralRole_CancelDiscovery();
            ret = 2u;
        }
        else
        {
            /* checking for duplicated devices*/
            isDuplicated = FALSE;
            for (i = 0u; i < index; i++)
            {
                if (memcmp(controls.bbridgeAppInterface.btScanResult[i].addr, addr, 6u) == 0)
                {
                    /* device has already been discovered*/
                    index = i;
                    isDuplicated = 1u;
                    break;
                }
            }
            
            controls.bbridgeAppInterface.btScanResult[index].addrType = addrType;
            controls.bbridgeAppInterface.btScanResult[index].rssi = rssi;
            memcpy(controls.bbridgeAppInterface.btScanResult[index].addr, addr, 6u);
            
            if(dataLength > BB_MAX_BROADCAST_MSG)
            {
                /* advertised data is too long*/
                dataLength = BB_MAX_BROADCAST_MSG;
            }
            
            if(dataLength > 0u)
            {
                memcpy( controls.bbridgeAppInterface.btScanResult[index].broadcastMsg, data, (uint16_t) dataLength);
            }
            
            controls.bbridgeAppInterface.btScanResult[index].broadcastMsgLength = dataLength;
            
            if(isDuplicated == FALSE)
            {
                controls.bbridgeAppInterface.btScanResultTotal++;
            }
        }
    }
    
    return ret;
}

/**
 * @brief It receives data coming from the BLE stack and processes it internally
 * in the BBridge application module
 * @param connHandle
 * @param data
 * @param length
 * @return  1: cannot receive data in IDLE mode\n
 *          2: cannot receive more than BB_MAX_EXT_DATA bytes\n
 *          3: invalid data pointer\n
 *          4: could not find connection handle\n
 *          5: mode not handled\n
 *          received OK: forwarding to operating mode\n
 *          x+100: return from CONNECTABLE mode\n
 *          x+200: return from SCANNER mode\n
 *          x+50: return from DATAHandler\n
 */
uint8_t BBridge_OnBTRxData(BBridgeCommPacket_t *psBrdgComPaket)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (psBrdgComPaket == NULL)
    {
        funcRet = 2u; /* invalid data pointer*/
    }
    else if ((psBrdgComPaket->unPacketInfo.st.DataLength == 0u) || (psBrdgComPaket->unPacketInfo.st.DataLength > BB_MAX_EXT_DATA_SPI) )
    {
        funcRet = 3u; /* cannot receive more than BB_MAX_EXT_DATA bytes*/
    }
    else
    {
        if (controls.bbridgeAppInterface.btConnections[psBrdgComPaket->unPacketInfo.st.ConnIndex].isValidated == TRUE)
        {
            ret = DataHandler_PushExtDataToPanther(psBrdgComPaket);
            funcRet = (ret + 50u);
        }
        else
        {
            /* forwarding to operating mode*/
#ifdef TARGET_PAD
            if (controls.selectedOpMode == BB_CONNECTABLE_MODE)
            {
                ret = ConnectableMode_OnRxExtData(psBrdgComPaket);
                funcRet = (ret + 100u);
            }
#else
            if (controls.selectedOpMode == BB_SCANNER_MODE)
            {
                ret = ScannerMode_OnRxExtData(psBrdgComPaket);
                funcRet = (ret + 200u);
            }
#endif
            else
            {
                funcRet = 5u; /* mode not handled*/
            }
        }
    }
    
    return funcRet;
}

/**
 * @brief Called by the operating modes (scanner or connectable) when a given connection
 * has been validated
 * @note: when in Connectable mode, the advertisement shall stop
 * @param deviceIndex
 * @return  BB_SUCCESS: ok\n
 *          1: index out of range\n
 *          2: device not connected\n
 */
uint8_t BBridge_OnConnectionValidated(uint8_t deviceIndex) 
{
    uint8_t ret = BB_SUCCESS;
    
    /* check index range*/
    if (deviceIndex >= BB_MAX_SCANNER_BT_CONNS)
    {
        ret = 1u; /* out of range*/
    } 
    else if (controls.bbridgeAppInterface.btConnections[deviceIndex].isConnected == FALSE)
    {
        controls.bbridgeAppInterface.btConnections[deviceIndex].isValidated = FALSE; /* making sure value is correct*/
        ret = 2u; /* device is not properly connected*/
    }
    else
    {
        /* Storing "authenticated" state in the module interface.*/
        /* This is important so the BBridge interface can decide where to*/
        /* forward the incoming external messages -> datahandler or module*/
        /* auth process*/
        if (controls.selectedOpMode == BB_CONNECTABLE_MODE)
        {
            /* make sure there is no more advertisements*/
            /*connectableEnableAdv(FALSE);*/
        }
    
        controls.bbridgeAppInterface.btConnections[deviceIndex].isValidated =
        TRUE;
    }
    
    return ret;
}

/**
 * @brief It calls the terminate connection function in the HW module
 * @param deviceIndex
 * @return  BB_SUCCESS: ok, termination started\n
 *          1: deviceIndex out of range\n
 *          2: device is not connected
 */
uint8_t BBridge_DisconnectDevice(uint8_t deviceIndex)
{
    uint8_t ret = BB_SUCCESS;
    
    if (deviceIndex >= BB_MAX_SCANNER_BT_CONNS)
    {
        ret = 1u; /*index out of range*/
    }
    else if (controls.bbridgeAppInterface.btConnections[deviceIndex].isConnected == TRUE)
    {
        controls.hwInterface->terminateConnection(
                controls.bbridgeAppInterface.btConnections[deviceIndex].cnnhandle);
    
        /*    controls.bbridgeAppInterface.btConnections[deviceIndex].isConnected = 0;*/
        /*    controls.bbridgeAppInterface.btConnections[deviceIndex].isValidated = 0;*/
    
        /* Note that the device is not really disconnected at this points. We*/
        /* need to check if the disconnection callbacks from the HW works in all*/
        /* the possible cases*/
    
        /* TODO: check if the "disconnection" events comes correctly from the HW callback*/
        /* and mode the isConnected=0 there.*/
    
    }
    else
    {
        ret = 2u; /* not connected*/
    }
    
    return ret;
}

/**
 * @brief It generates a seed to be used when calculating the key
 * @attention: not yet implemented, waiting algorithm from Bombardier
 */
uint32_t BBridge_GenerateSeed(void)
{
    return (uint32_t) 0x55443322ul;
}

/**
 * @brief it calculates a key based on the seed given
 * @param seed
 * @return calculated KEY
 * @attention Not yet implemented (waiting Algorithm from bombardier)
 */
uint32_t BBridge_GetAuthKey(uint32_t seed)
{
    /* TODO use algorithm given by Bombardier*/
    return seed; /* Y(X(seed))*/
}

/**
 * @brief It returns the state of the TXComplete value (TX to Panther)
 * @return  0: not complete
 *          1: tx complete (waiting for more inputs)
 */
uint8_t BBridge_IsTxToPantherComplete(void)
{
    return (controls.isDataHandlerDeliveryComplete == 0u) ? FALSE : TRUE;
}

/**
 * It returns the state of the scanner operation
 * @return  0: not scanning\n
 *          1: scanning going on\n
 */
uint8_t BBridge_IsScanning(void)
{
    return (controls.bbridgeAppInterface.btScanBusy == 1u) ? TRUE : FALSE;
}

/**
 * @brief Check if the BBridge can start a discovery process
 * @return  0: no\n
 *          1: yes
 */
uint8_t BBridge_CanScan(void) 
{
    return ((BBridge_BTDeviceInitialized())
            /*&& (controls.bbridgeAppInterface.totalConnected == 0)*/
            && (controls.selectedOpMode == BB_SCANNER_MODE)
            && (controls.bbridgeAppInterface.isConnecting == FALSE)
            && (controls.bbridgeAppInterface.scanAllowed == TRUE)
            && (controls.bbridgeAppInterface.btScanBusy == FALSE)) ? TRUE : FALSE;
}

uint8_t BBridge_BTDeviceInitialized(void)
{
    return (controls.bbridgeAppInterface.isDevInitialized == TRUE) ? TRUE : FALSE;
}

/**
 * @brief It pushes an ACK packet to be transferred to the Panther device.
 * @param cmdID being acknowledged
 * @param extraData data to be sent together with the ACK packet
 * @param length of the extra data
 * @return  BB_SUCCESS: ok \n
 *          1: bbridge busy \n
 *          x+10: problem push data, see returns from \n
 *          DataHandler_PushDataToPanther(...)
 */
uint8_t BBridge_PushACK(BBridgeCMDId_t cmdID, const uint8_t extraData[], uint8_t length)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (controls.isDataHandlerDeliveryComplete == FALSE)
    {
        funcRet = 1u;
    } 
    else
    {
        controls.intData.data[0] = BB_MSGTYPE_ACK;
        controls.intData.data[1] = cmdID;
        
        if (length > 0u) 
        {
            memcpy(&controls.intData.data[2], extraData, (uint16_t) length);
        }
        
        controls.intData.length = (length + 2u);
        ret = DataHandler_PushIntDataToPanther(&controls.intData.data[0], controls.intData.length);
        
        if (ret == BB_SUCCESS) 
        {
            controls.isDataHandlerDeliveryComplete = FALSE;
        } 
        else
        {
            /* could not push data*/
            funcRet = (ret + 10u);
        }
    }
    
    return funcRet;
}

/**
 * @brief It pushes a Negative ACK to be send to the Panther
 * @param cmdID
 * @param reason NACK reason
 * @return  BB_SUCCESS: ok\n
 *          1: bbridge busy\n
 *          x+10: problem push data, see returns from\n
 *          DataHandler_PushDataToPanther(...)
 */
uint8_t BBridge_PushNACK(BBridgeCMDId_t cmdID, BBridgeNACKReason_t reason)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (controls.isDataHandlerDeliveryComplete == FALSE)
    {
        funcRet = 1u;
    } 
    else 
    {
    
        controls.intData.data[0] = BB_MSGTYPE_NACK;
        controls.intData.data[1] = cmdID;
        controls.intData.data[2] = reason;
        controls.intData.length = 3u;
        
        ret = DataHandler_PushIntDataToPanther(&controls.intData.data[0],
                controls.intData.length);
        
        if (ret == BB_SUCCESS)
        {
            controls.isDataHandlerDeliveryComplete = FALSE;
        } 
        else
        {
            /* could not push data*/
            funcRet = (ret + 10u);
        }
    }
    return funcRet;
}

/**
 * @brief It pushed a new event to the Panther device;
 * @param cmdID
 * @param extraData
 * @param length
 * @return  BB_SUCCESS: ok\n
 *          1: bbridge busy\n
 *          x+10: problem push data, see returns from\n
 *          DataHandler_PushDataToPanther(...)
 */
uint8_t BBridge_PushEVENT(BBridgeEvents_t event, const uint8_t extraData[], uint8_t length)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (controls.isDataHandlerDeliveryComplete == FALSE)
    {
        funcRet = 1u;
    }
    else
    {
        controls.intData.data[0] = BB_MSGTYPE_EVENT;
        controls.intData.data[1] = event;
        memcpy(&controls.intData.data[2], extraData, (uint16_t) length);
        controls.intData.length = (length + 2u);
        ret = DataHandler_PushIntDataToPanther(&controls.intData.data[0],
                controls.intData.length);
        
        if (ret == BB_SUCCESS)
        {
            controls.isDataHandlerDeliveryComplete = FALSE;
        } 
        else
        {
            /* could not push data*/
            funcRet = (ret + 10u);
        }
    }
    
    return funcRet;
}

/**
 * @brief It finds a connection index in the connections list by a connection
 * handler
 * @param connHandler
 * @param resultPtr (index in the btConnections list)
 * @return  BB_SUCCESS: ok\n
 *          1: could not find connection handle
 */
uint8_t BBridge_GetConnIndexByHandle(uint16_t connHandle, uint8_t * resultIndex)
{
    uint8_t i;
    uint8_t ret = BB_SUCCESS;
    
    for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; ++i)
    {
        if (controls.bbridgeAppInterface.btConnections[i].isConnected == TRUE)
        {
            if (controls.bbridgeAppInterface.btConnections[i].cnnhandle == connHandle)
            {
                *resultIndex = i;
                break;
            }
        }
    }
    
    if (i >= BB_MAX_SCANNER_BT_CONNS)
    {
        ret = 1u;
    }
    
    return ret;
}

/**
 * @brief It reads 1 byte from the storage interface (NVM)
 * @param data - 1 byte
 * @param itemID -> 0-7
 * @return  BB_SUCCESS: ok\n
 *          1: itemID out of range\n
 *          2: storage error
 */
uint8_t BBridge_StorageRead(uint8_t data[], uint8_t itemID)
{
    uint8_t ret = BB_SUCCESS;
    
    if (itemID >= BB_MAX_STORAGE_ITEMS)
    {
        ret = 1u;
    }
    else
    {
        ret = controls.hwInterface->storageRead(data, itemID);
    }
    
    return ret;
}

/**
 * @brief It stores a byte into the storage interface (NVM)
 * @param data 1 byte
 * @param itemID
 * @return  BB_SUCCESS: ok\n
 *          1: itemID out of range\n
 *          2: storage error
 */
uint8_t BBridge_StorageWrite(const uint8_t data[], uint8_t itemID)
{
    uint8_t ret = BB_SUCCESS;
    
    if (itemID >= BB_MAX_STORAGE_ITEMS)
    {
        ret = 1u;
    }
    else
    {
        ret = controls.hwInterface->storageWrite(data, itemID);
    }
    
    return ret;
}

/**
 * @brief It begins a connection process with the given bluetooth device addrr
 * @param devAddr
 * @param addrType
 * @return  BB_SUCCESS: ok, process started\n
 *          1: error: connection process already in progress\n
 *          2: cannot initiate connection in the operating mode given\n
 *          x+10: error at HW level -> could not start process
 *
 */
uint8_t BBridge_StartBTConnection(const uint8_t devAddr[], uint8_t addrType)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (controls.selectedOpMode != BB_SCANNER_MODE)
    {
        funcRet = 2u; /* cannot initiate connection in the operating mode given*/
    }
    else if (controls.bbridgeAppInterface.isConnecting == TRUE)
    {
        funcRet = 1u; /* cannot start a connection yet (connection process already in progress)*/
    } 
    else
    {
        ret = controls.hwInterface->connect(devAddr, addrType);
        if (ret == BB_SUCCESS) 
        {
            controls.bbridgeAppInterface.isConnecting = TRUE;
        } 
        else
        {
            funcRet = (ret + 10u);
        }
    }
    
    return funcRet;
}

/**
 * @brief Callback called by the Bluetooth module when a discovery event is
 * ready
 */
void BBridge_OnScanReady(void)
{
    controls.bbridgeAppInterface.btScanBusy = FALSE;
}

/**
 * @brief Callback called when a bluetooth Scan operation is started
 */
void BBridge_OnScanStarted(void)
{
    controls.bbridgeAppInterface.btScanResultTotal = 0u;
    controls.bbridgeAppInterface.btScanBusy = TRUE;
}

/**
 * @brief It handles the overall business logics for the BBridge application.
 * On the first time, after initialization is completed, an event "init ok"
 * is sent to the Panther.
 * @enddot
 */
void BBridge_Work(void)
{
    uint8_t ret;
    
    SPITransportLayerWork();
    DataHandler_Work();         /* DataHandler state machine*/
    commandProcessorWork();     /* command processor state machine*/
    
    switch (controls.state)
    {
         /* Idle state */
        case (BBAPP_IDLE):
        {
            /* Deciding which operating mode module to initialize*/
            switch (controls.selectedOpMode) 
            {
#ifdef TARGET_PAD
                case (BB_CONNECTABLE_MODE):
                {
                    /* initializing CONNECTABLE operating mode module */
                    ret = ConnectableMode_Init(&controls.bbridgeAppInterface);
                    if (ret == BB_SUCCESS) 
                    {
                        if (controls.prevOpMode == BB_NO_MODE)
                        {
                            /* first time the BBridge is initialized, it notifies the*/
                            /* Panther with the EVENT_INIT_OK message*/
                            controls.bbridgeAppInterface.sharedMemValue[0] = BB_EVT_INIT_OK;
                            controls.bbridgeAppInterface.sharedMemValue[1] = BB_IDLE_MODE;
                            controls.bbridgeAppInterface.sharedMemValueLength = 2u;
                            controls.prevOpMode = BB_CONNECTABLE_MODE;
                            controls.state = BBAPP_SND_EVT;
                        }
                        else
                        {
                            controls.state = BBAPP_CONNECTABLE_MODE;
                        }
                    } 
                    else 
                    {
                        controls.state = BBAPP_INIT_ERROR;
                    }
                    break;
                }
#else
                case (BB_SCANNER_MODE):
                {
                    /* initializing SCANNER operating mode module */
                    ret = ScannerMode_Init(&controls.bbridgeAppInterface);
                    if (ret == BB_SUCCESS)
                    {
                        if (controls.prevOpMode == BB_NO_MODE)
                        {
                            /* first time the BBridge is initialized, it notifies the*/
                            /* Panther with the EVENT_INIT_OK message*/
                            controls.bbridgeAppInterface.sharedMemValue[0] = BB_EVT_INIT_OK;
                            controls.bbridgeAppInterface.sharedMemValue[1] = BB_IDLE_MODE;
                            controls.bbridgeAppInterface.sharedMemValueLength = 2u;
                            controls.prevOpMode = BB_SCANNER_MODE;
                            controls.state = BBAPP_SND_EVT;
                        }
                        else
                        {
                            controls.state = BBAPP_SCANNER_MODE;
                        }
                    }
                    else
                    {
                        controls.state = BBAPP_INIT_ERROR;
                    }
                    break;
                }
#endif

#if 0
                case (BB_IDLE_MODE):
                {
                    /* initializing IDLE operating mode module */
                    ret = IdleMode_Init(&controls.bbridgeAppInterface);
                    if (ret != BB_SUCCESS)
                    {
                        controls.state = BBAPP_INIT_ERROR;
                    }
                    else
                    {
                        controls.selectedOpMode = BB_IDLE_MODE;
                        controls.hwInterface->initDeviceOPMode(controls.selectedOpMode); /* needed to clean hw states*/
                        resetIdleModeState();
                        if (controls.prevOpMode == BB_NO_MODE)
                        {
                            /* first time the BBridge is initialized, it notifies the*/
                            /* Panther with the EVENT_INIT_OK message*/
                            controls.bbridgeAppInterface.sharedMemValue[0] = BB_EVT_INIT_OK;
                            controls.bbridgeAppInterface.sharedMemValue[1] = controls.selectedOpMode;
                            controls.bbridgeAppInterface.sharedMemValueLength = 2u;
                            controls.prevOpMode = BB_IDLE_MODE;
                            controls.state = BBAPP_SND_EVT;
                        }
                        else
                        {
                            controls.state = BBAPP_IDLE_MODE;
                        }
                    }
                    break;
                }
#endif

                default:
                {
                    /* going to IDLE mode in case no mode is active */
                    controls.prevOpMode = BB_NO_MODE;
                    controls.selectedOpMode = BB_IDLE_MODE;
                    break;
                }
            }
            
            break;
        } /* end Idle state */
#ifdef TARGET_PAD
        case (BBAPP_CONNECTABLE_MODE):
        {
            ConnectableMode_Work();
            /* checking for "exit" procedure*/
            if (ConnectableMode_ReadyToExit() == TRUE)
            {
                if (ConnectableMode_ExitMode() == BB_SUCCESS)
                {
                    ConnectableMode_Work();
                    if (controls.hwInterface->initDeviceOPMode(controls.selectedOpMode) == BB_SUCCESS)
                    {
                        controls.selectedOpMode = BB_IDLE_MODE;
                        /* SEND CMD ACK!*/
                        controls.bbridgeAppInterface.sharedMemValue[0] = BBCMD_SET_OP_MODE;
                        controls.bbridgeAppInterface.sharedMemValue[1] = BB_IDLE_MODE;
                        controls.bbridgeAppInterface.sharedMemValueLength = 2u;
                        controls.state = BBAPP_SND_ACK;
                        controls.prevOpMode = BB_CONNECTABLE_MODE;
                    }
                }
            }
            
            break;
        }
#else
        case (BBAPP_SCANNER_MODE):
        {
            ScannerMode_Work();
            /* checking for "exit" procedure*/
            if (ScannerMode_ReadyToExit() == TRUE) 
            {
                if (ScannerMode_ExitMode() == BB_SUCCESS) 
                {
                    ScannerMode_Work();
                    if (controls.hwInterface->initDeviceOPMode(controls.selectedOpMode) == BB_SUCCESS) 
                    {
                        controls.bbridgeAppInterface.sharedMemValue[0] = BBCMD_SET_OP_MODE;
                        controls.bbridgeAppInterface.sharedMemValue[1] = BB_IDLE_MODE;
                        controls.bbridgeAppInterface.sharedMemValueLength = 2u;
                        controls.selectedOpMode = BB_IDLE_MODE;
                        controls.state = BBAPP_SND_ACK;
                        controls.prevOpMode = BB_SCANNER_MODE;
                    }
                }
            }
            
            break;
        }
#endif
#if 0
        case (BBAPP_IDLE_MODE):
        {
            IdleMode_Work();
            /* checking for "exit" procedure*/
            if (IdleMode_ReadyToExit() == TRUE)
            {
                IdleMode_GetNewOperatingMode(&controls.selectedOpMode);
                if (IdleMode_ExitMode() == BB_SUCCESS)
                {
                    IdleMode_Work();
                    resetConnectableModeState();
                    resetScannerModeState();
                    
                    // initializing hardware for the new operating mode
                    if (controls.hwInterface->initDeviceOPMode(controls.selectedOpMode) == BB_SUCCESS)
                    {
                        controls.bbridgeAppInterface.sharedMemValue[0] = BBCMD_SET_OP_MODE;
                        controls.bbridgeAppInterface.sharedMemValue[1] = controls.selectedOpMode;
                        controls.bbridgeAppInterface.sharedMemValueLength = 2u;
                        controls.state = BBAPP_SND_ACK;
                        controls.prevOpMode = BB_IDLE_MODE;
                    }
                }
            }
            
            break;
        }
#endif
        case (BBAPP_SND_EVT):
        {
            ret = controls.bbridgeAppInterface.pushEVENT(
                                    (BBridgeEvents_t) controls.bbridgeAppInterface.sharedMemValue[0],
                                    &controls.bbridgeAppInterface.sharedMemValue[1],
                                    1u);
            
            if (ret == BB_SUCCESS) 
            {
                controls.state = BBAPP_WAIT_TX_COMPLETE;
            } 
            else 
            {
                /* could not push ACK... try again*/
            }
            
            break;
        }
        
        case (BBAPP_SND_ACK):
        {
            ret = BBridge_PushACK(
                                (BBridgeCMDId_t) controls.bbridgeAppInterface.sharedMemValue[0],
                                &controls.bbridgeAppInterface.sharedMemValue[1],
                                1u);
            
            if (ret == BB_SUCCESS)
            {
                controls.state = BBAPP_WAIT_TX_COMPLETE;
            }
            else
            {
                /* could not push ACK... try again*/
            }
            
            break;
        }
        
        case (BBAPP_WAIT_TX_COMPLETE):
        {
            if (controls.bbridgeAppInterface.isTxToPantherComplete() == TRUE) 
            {
                controls.state = BBAPP_IDLE;
                BBridge_ReleaseDataHandler();
            }
            
            break;
        }
        
        case (BBAPP_INIT_ERROR):
        {
            /* dead-end*/
            break;
        }
        
        default:
        {
            controls.state = BBAPP_IDLE;
            break;
        }
    }
}

/**
 * @brief It checks for received commands from Panther and forwards them to the
 * to the current active operating mode
 */
static void commandProcessorWork(void)
{
    switch (controls.commandProcessorState)
    {
        case (BBIFF_IDLE):
        {
            if (controls.isCMDProcessed == TRUE)
            {
                /* last command has been processed (free to receive more)*/
                if (DataHandler_HasDataFromPanther() == TRUE)
                {
                    /* there is new data from Panther*/
                    if (DataHandler_GetRxDataFromPanther(controls.iffTMPData.data, &controls.iffTMPData.length) == BB_SUCCESS)
                    {
                        controls.pantherCMD.id = (BBridgeCMDId_t) controls.iffTMPData.data[0];
                        controls.pantherCMD.cmd.length = (controls.iffTMPData.length - 1u);
                        if ((controls.iffTMPData.length - 1u) > 0u) 
                        {
                            memcpy(controls.pantherCMD.cmd.data, &controls.iffTMPData.data[1], (controls.iffTMPData.length - 1u));
                        }
                        
                        controls.commandProcessorState = BBIFF_PROCESS_CMD;
                        controls.isCMDProcessed = FALSE;
                    }
                }
            }
            
            break;
        }
        
        case (BBIFF_PROCESS_CMD):
        {
#if 0
            /* deciding where to forward the command*/
            if (controls.selectedOpMode == BB_IDLE_MODE) 
            {
                if (IdleMode_IsBusy() == FALSE)
                {
                    if (IdleMode_OnRxCommand(&controls.pantherCMD) == BB_SUCCESS)
                    {
                        controls.commandProcessorState = BBIFF_WAIT_RELEASE;
                    }
                }
            }
#endif

#ifdef TARGET_PAD
            if (controls.selectedOpMode == BB_CONNECTABLE_MODE) 
            {
                if (ConnectableMode_IsBusy() == FALSE)
                {
                    if (ConnectableMode_OnRxCommand(&controls.pantherCMD) == BB_SUCCESS)
                    {
                        controls.commandProcessorState = BBIFF_WAIT_RELEASE;
                    }
                }
            }
#else
            if (controls.selectedOpMode == BB_SCANNER_MODE)
            {
                if (ScannerMode_IsBusy() == FALSE)
                {
                    if (ScannerMode_OnRxCommand(&controls.pantherCMD) == BB_SUCCESS)
                    {
                        controls.commandProcessorState = BBIFF_WAIT_RELEASE;
                    }
                }
            }
#endif
            else
            {
                /* shall never happen (ignoring command)*/
                controls.isCMDProcessed = TRUE;
                controls.commandProcessorState = BBIFF_IDLE;
            }
            
            break;
        }
        
        case (BBIFF_WAIT_RELEASE):
        {
            if (DataHandler_IsDataFromPantherProcessed() == TRUE)
            {
                controls.isCMDProcessed = TRUE;
                controls.commandProcessorState = BBIFF_IDLE;
            }
            
            break;
        }
        
        default:
        {
            controls.commandProcessorState = BBIFF_IDLE;
            controls.isCMDProcessed = TRUE;
            break;
        }
    }
}

#if 0
static void resetScannerModeState(void)
{
    controls.bbridgeAppInterface.btScanBusy = FALSE;
    controls.bbridgeAppInterface.isConnecting = FALSE;
    controls.bbridgeAppInterface.isDevInitialized = FALSE;
    controls.bbridgeAppInterface.scanAllowed = FALSE;
    controls.bbridgeAppInterface.btScanResultTotal = FALSE;
    resetAllConnections();
}

static void resetConnectableModeState(void)
{
    /* TODO: add reset variables needed for the connectable mode*/
    /* TODO: to be called when entering the selected mode*/
    controls.bbridgeAppInterface.isConnecting = FALSE;
    controls.bbridgeAppInterface.isDevInitialized = FALSE;
    resetAllConnections();
}

static void resetIdleModeState(void)
{
    /* TODO: add reset variables needed for the idle mode*/
    /* TODO: to be called when entering the selected mode*/
    controls.bbridgeAppInterface.isConnecting = FALSE;
    controls.bbridgeAppInterface.isDevInitialized = FALSE;
    resetAllConnections();
    BBridge_ReleaseDataHandler();
}

static void resetAllConnections(void)
{
    uint8_t i;
    
    for (i = 0u; i < BB_MAX_SCANNER_BT_CONNS; ++i)
    {
        controls.bbridgeAppInterface.btConnections[i].isConnected = FALSE;
        controls.bbridgeAppInterface.btConnections[i].isValidated = FALSE;
    }
    
    controls.bbridgeAppInterface.totalConnected = 0u;
}

#endif

/**
 * @brief It calls the hw function to initialize the bluetooth device
 * with the specific given operating mode
 * @param newMode BBridgeOpMode_t
 */
uint8_t BBridge_InitDeviceOPMode(BBridgeOpMode_t newMode)
{
    return controls.hwInterface->initDeviceOPMode(newMode);
}

/**
 *
 * @return system time in milliseconds
 */
uint32_t BBridge_GetSysTime(void)
{
    return controls.hwInterface->getSystime();
}

uint32_t BBridge_GetSysTimeDiff(uint32_t value)
{
    uint32_t tmp;
    
    tmp = controls.hwInterface->getSystime();
    
    if (tmp >= value)
    {
        tmp = tmp - value;
    }
    else
    {
        tmp = BB_UINT32_MAX - value + tmp + 1u;
    }
    
    return tmp;
}

BBridgeOpMode_t * BBridge_GetOpModePtr(void)
{
    return &controls.selectedOpMode;
}

uint8_t BBridge_IsConnected(void)
{
    if(controls.bbridgeAppInterface.btConnections[0].isConnected == TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

uint8_t * BBridge_GetFilterMessage(void)
{
    return (uint8_t *)&(controls.filterMsg[0]);
}

#ifdef TESTENVIRONMENT
/* only for testing*/

const BBridgeAppState_t * BBridge_GetState(void)
{
    return &controls.state;
}

void BBridge_SetOpMode(BBridgeOpMode_t newMode)
{
    controls.selectedOpMode = newMode;
    
    if (newMode == BB_IDLE_MODE)
    {
        IdleMode_Init(&controls.bbridgeAppInterface);
    }
#ifdef TARGET_PAD
    else if (newMode == BB_CONNECTABLE_MODE)
    {
        ConnectableMode_Init(&controls.bbridgeAppInterface);
    }
#else
    else if (newMode == BB_SCANNER_MODE)
    {
        ScannerMode_Init(&controls.bbridgeAppInterface);
    }
#endif
}

const CommandProcessorState_t * BBridge_GetInterfaceForwarderWork(void)
{
    return &controls.commandProcessorState;
}

BBridgeAppInterface_t * BBridge_GetModulInterface(void)
{
    return &controls.bbridgeAppInterface;
}

void BBridge_Destroy(void)
{
    controls.isDataHandlerDeliveryComplete = TRUE;
    DataHandler_Destroy();
    /* reseting connections*/
    resetAllConnections();
}

#endif

/**
 * @}
 */
