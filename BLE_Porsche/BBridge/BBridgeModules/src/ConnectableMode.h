/**
 * \addtogroup ConnectableMode
 * @{
 *
 * @file 	ConnectableMode.h
 * @author	p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * $Revision: 18134 $
 * $Id: ConnectableMode.h 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */

#ifndef CONNECTABLEMODE_H_
#define CONNECTABLEMODE_H_

#include "BBridgeDefs.h"

/**
 * @brief States of the CONNECTABLE mode for the BBridge application
 */
typedef enum {
	BBCONNMD_WAIT_DEV_INIT = 0,
	BBCONNMD_INIT,
	BBCONNMD_IDLE, /*!< ...*/
	BBCONNMD_PROCESS_SETCMD,
	BBCONNMD_PROCESS_GETCMD,
	BBCONNMD_SND_ACK,
	BBCONNMD_SND_NACK,
	BBCONNMD_SND_EVT,
	BBCONNMD_WAITING_VALIDATION,
	BBCONNMD_WAIT_CONN_PARAMS,
	BBCONNMD_WAIT_TX2PANTHER,
	BBCONNMD_WAIT_DISCONNECTION,
	BBCONNMD_AUTH_PASS,
	BBCONNMD_AUTH_FAIL,
	BBCONNMD_WAIT_EXIT_CALL,
	BBCONNMD_WAIT_FOR_PANTHER

} BBConnectableMDState_t;

typedef enum {
	BBVLDCONN_IDLE = 0,
	BBVLDCONN_CHECK_KEY,
	BBVLDCONN_AUTH_PASS,
	BBVLDCONN_AUTH_FAILED,
	BBVLDCONN_AUTH_ERROR
} BBCONNValidConnState_t;

/* --------------------*/
/* Public functions for this module*/
/* --------------------*/

extern uint8_t ConnectableMode_OnConnection(uint8_t deviceIndex);
extern uint8_t ConnectableMode_Init(BBridgeAppInterface_t * bbridgeInterface);
extern uint8_t ConnectableMode_OnDisconnection(uint8_t deviceIndex, uint8_t status,
		uint8_t reason);
extern uint8_t ConnectableMode_OnRxCommand(const BBridgeCommand_t * command);
extern uint8_t ConnectableMode_OnRxExtData(BBridgeCommPacket_t *psBrdgComPaket);
extern uint8_t ConnectableMode_IsBusy(void);
extern uint8_t ConnectableMode_ReadyToExit(void);
extern uint8_t ConnectableMode_ExitMode(void);
extern void ConnectableMode_Work(void);
extern void ConnectableMode_OnLinkUpdate(uint16_t connHandle, uint8_t status);


#ifdef TESTENVIRONMENT
extern BBConnectableMDState_t * ConnectableMode_GetState(void);
extern const BBCONNValidConnState_t * ConnectableMode_GetValConnState(void);
#endif

#endif /* CONNECTABLEMODE_H_ */
/** @}*/
