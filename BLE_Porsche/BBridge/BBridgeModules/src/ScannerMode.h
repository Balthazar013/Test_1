/**
 * \addtogroup ScannerMode
 * @{
 *
 * @file 	ScannerMode.h
 * @author	p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 *
 * @internal
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * $Revision: 18134 $
 * $Id: ScannerMode.h 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */

#ifndef SCANNERMODE_H_
#define SCANNERMODE_H_

#include "BBridgeDefs.h"

/**
 * @brief States of the CONNECTABLE mode for the BBridge application
 */
typedef enum
{
    BBSCNRMD_INIT = 0,
    BBSCNRMD_IDLE,
    BBSCNRMD_PROCESS_SETCMD,
    BBSCNRMD_PROCESS_GETCMD,
    BBSCNRMD_SND_ACK,
    BBSCNRMD_SND_NACK,
    BBSCNRMD_SND_EVENT,
    BBSCNRMD_WAIT_TX2PANTHER,
    BBSCNRMD_WAIT_DISCONNECTION,
    BBSCNRMD_WAIT_EXIT_CALL,
    BBSCNRMD_PROCESS_CONN_LOST,
    BBSCNRMD_PROCESS_DISCONNECTION,
    BBSCNRMD_PROCESS_SCAN,
    BBSCNRMD_WAIT_CONN_STATE,
    BBSCNRMD_PROCESS_CMDDISCONNECT,
    BBSCNRMD_VALIDATE_CONN,
    BBSCNRMD_REQ_SEED,
    BBSCNRMD_BB_AUTH_OK,
    BBSCNRMD_BB_AUTH_FAIL,
    BBSCNRMD_WAIT_CONN_PARAMS,
    BBSCNRMD_PROCESS_CMDSET_SLEEP_MODE,
    BBSCNRMD_INITIATE_CONNECTION
} BB_ScannerMD_State_t;

typedef enum
{
    BBSCNER_VAL_IDLE = 0,
    BBSCNER_VAL_BUSY,
    BBSCNER_VAL_CHECK_KEY_OK,
    BBSCNER_VAL_AUTH_PASS,
    BBSCNER_VAL_AUTH_FAILED,
    BBSCNER_VAL_AUTH_ERROR
} BBSCNERValidConnState_t;

extern uint8_t ScannerMode_Init(BBridgeAppInterface_t * bbridgeInterface);

extern uint8_t ScannerMode_OnRxExtData(BBridgeCommPacket_t *psBrdgComPaket);
extern uint8_t ScannerMode_OnConnection(uint8_t status, uint8_t deviceIndex);
extern uint8_t ScannerMode_OnDisconnection(uint8_t deviceIndex, uint8_t status, uint8_t reason);
extern uint8_t ScannerMode_OnRxCommand(BBridgeCommand_t * command);
extern uint8_t ScannerMode_IsBusy(void);
extern uint8_t ScannerMode_ReadyToExit(void);
extern uint8_t ScannerMode_ExitMode(void);
extern void ScannerMode_Work(void);
extern void ScannerMode_OnLinkUpdate(uint16_t connHandle, uint8_t status);

#ifdef TESTENVIRONMENT

BB_ScannerMD_State_t * ScannerMode_GetState(void);
void ScannerMode_SetIsConnecting(uint8_t isConnecting);
#endif

#endif /* SCANNERMODE_H_ */

/** @}*/
