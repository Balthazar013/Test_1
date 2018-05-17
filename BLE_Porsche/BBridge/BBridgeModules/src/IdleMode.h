/**
 * \addtogroup IdleMode
 * @{
 *
 * @file 	IdleMode.h
 * @author	p344575
 * @brief 	It implements the business logics for the IDLE mode of the BBridge
 * application
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 *
 * @internal
 * $LastChangedDate: 2017-11-14 12:44:56 +0100 (Di, 14 Nov 2017) $
 * $LastChangedBy: ksteingass $
 * $Revision: 16315 $
 * $Id: IdleMode.h 16315 2017-11-14 11:44:56Z ksteingass $
 *
 */


#ifndef IDLEMODE_H_
#define IDLEMODE_H_

#include "BBridgeDefs.h"


/**
 * @brief States of the IDLE mode for the BBridge application
 */
typedef enum{
	BBIDLEMD_IDLE= 0, /*!< ...*/
	BBIDLEMD_PROCESS_SETCMD, /*!< ...*/
	BBIDLEMD_PROCESS_GETCMD, /*!< ...*/
	BBIDLEMD_WAIT_EXIT_CALL, /*!< ...*/
	BBIDLEMD_SND_ACK, /*!< ...*/
	BBIDLEMD_SND_NACK, /*!< ...*/
	BBIDLEMD_WAIT_TX2PANTHER /*!< ... (internal state)*/
} BBIDleMDState_t;



extern void IdleMode_Work(void);
extern uint8_t IdleMode_Init(BBridgeAppInterface_t * bbridgeInterface);
extern uint8_t IdleMode_OnRxCommand(const BBridgeCommand_t * command);

extern uint8_t IdleMode_GetNewOperatingMode(BBridgeOpMode_t * newMode);
extern uint8_t IdleMode_ReadyToExit(void);
extern uint8_t IdleMode_ExitMode(void);
extern uint8_t IdleMode_IsBusy(void);

#ifdef TESTENVIRONMENT
/*void IdleMode_Destroy(void);*/
extern BBIDleMDState_t * IdleMode_GetState(void);
#endif

#endif /* IDLEMODE_H_ */

/** @}*/
