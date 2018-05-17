/**
 * \addtogroup BBridgeApp
 * @{
 *
 * @file    BBridgeApp.h
 * @author  p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH

 *
 * @internal
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * $Revision: 18134 $
 * $Id: BBridgeApp.h 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */
#ifndef BBRIDGEAPP_H_
#define BBRIDGEAPP_H_


#include "../src/typedefs.h"
#include "BBridgeDefs.h"
#include "DataHandler.h"


typedef enum{
    BBAPP_IDLE=0,
    BBAPP_SCANNER_MODE,
    BBAPP_CONNECTABLE_MODE,
    BBAPP_IDLE_MODE,
    BBAPP_SND_ACK,
    BBAPP_SND_EVT,
    BBAPP_WAIT_TX_COMPLETE,
    BBAPP_INIT_ERROR
} BBridgeAppState_t;

typedef enum{
    BBIFF_IDLE=0,
    BBIFF_PROCESS_CMD,
    BBIFF_WAIT_RELEASE
} CommandProcessorState_t;

extern uint8_t BBridge_Init(BBridgeHWInterface_t * hwInterface);
extern uint8_t BBridge_ProcessSetCmd(const BBridgeCommand_t * cmd);
extern uint8_t BBridge_ProcessGetCmd(const BBridgeCommand_t * cmd, uint8_t data[], uint8_t * dataLength);
extern BBCMDType_t BBridge_GetCMDType(BBridgeCMDId_t cfgID);
extern uint8_t BBridge_PushACK(BBridgeCMDId_t cmdID, const uint8_t extraData[], uint8_t length);
extern uint8_t BBridge_PushNACK(BBridgeCMDId_t cmdID, BBridgeNACKReason_t reason);
extern uint8_t BBridge_PushEVENT(BBridgeEvents_t event, const uint8_t extraData[], uint8_t length);
extern uint8_t BBridge_StorageRead(uint8_t data[], uint8_t itemID);
extern uint8_t BBridge_StorageWrite(const uint8_t data[], uint8_t itemID);
extern void BBridge_SetWakeUpLine(uint8_t enable);
extern uint8_t BBridge_GetWakeUpLineState(void);
extern uint8_t BBridge_DisconnectDevice(uint8_t deviceIndex);
extern uint8_t BBridge_CanScan(void);
extern uint8_t BBridge_StartBTConnection(const uint8_t devAddr[], uint8_t addrType);

/* tested in the integration tests */
extern void BBridge_Work(void);

/* simple calls (tested within modules) */
extern uint8_t BBridge_IsTxToPantherComplete(void);
extern void BBridge_ReleaseDataHandler(void);
extern void BBridge_OnSPITxComplete(void);
extern uint8_t BBridge_SendBTData(uint8_t devIndex, const uint8_t data[], uint8_t length); /*HT@20171201: to be removed in next release */
extern uint8_t BBridge_SendBTDataCommand(uint8_t devIndex, const uint8_t data[], uint8_t length);
extern uint8_t BBridge_InitDeviceOPMode(BBridgeOpMode_t newMode);
extern uint32_t BBridge_GetSysTime(void);
extern uint32_t BBridge_GetSysTimeDiff(uint32_t value);
extern uint32_t BBridge_GenerateSeed(void);
extern uint32_t BBridge_GetAuthKey(uint32_t seed);
extern uint8_t BBridge_GetConnIndexByHandle(uint16_t connHandle, uint8_t * resultIndex);
extern uint8_t BBridge_IsScanning(void);
extern BBridgeOpMode_t * BBridge_GetOpModePtr(void);
extern uint8_t BBridge_BTDeviceInitialized(void);
extern uint8_t BBridge_IsConnected(void);
extern uint8_t * BBridge_GetFilterMessage(void);

/* ----------------------------------------------------------------------------*/
/* Callbacks from external interfaces*/
/*----------------------------------------------------------------------------*/
extern uint8_t BBridge_OnRssi(uint16_t connHandle, int8_t newRssi);
extern uint8_t BBridge_OnConnectionValidated(uint8_t deviceIndex);
extern uint8_t BBridge_OnBTRxData(BBridgeCommPacket_t *psBrdgComPaket);
extern void BBridge_OnSPIRxComplete(const uint8_t data[], uint8_t length);
extern uint8_t BBridge_OnBTDisconnection(uint8_t status, uint16_t connHandle, uint8_t reason);
extern void BBridge_OnDevInitDone(void);
extern uint8_t BBridge_OnDevDiscovered(int8_t rssi, uint8_t addrType,
                                       const uint8_t addr[], const uint8_t data[], uint8_t dataLength);
extern void BBridge_OnScanStarted(void);
extern void BBridge_OnLinkUpdate(uint16_t connHandle, uint8_t status);
extern uint8_t BBridge_OnBTConnection(uint8_t status, uint16_t connHandle, const uint8_t devAddr[]);
extern void BBridge_OnScanReady(void);
/* ---------------------------------------------------------------------------- */



#ifdef TESTENVIRONMENT
extern void BBridge_Destroy(void);
extern const CommandProcessorState_t * BBridge_GetInterfaceForwarderWork(void);
extern const BBridgeAppState_t * BBridge_GetState(void);
extern void BBridge_SetOpMode(BBridgeOpMode_t newMode);
extern BBridgeAppInterface_t * BBridge_GetModulInterface(void);
#endif

#endif /* BBRIDGEAPP_H_ */
/** @}*/
