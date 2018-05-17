/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/
#include <Os.h>
#include <BswM.h>
#include <BswM_UserCallouts.h>
#include <EcuM.h>

extern void InitWorkPage(void);
extern void Appl_SetCalPage(uint8 calpage);
extern void RESTART_SCI_IOHW_WsIoHwAb_Calc10ms(void);

/*==================[OS resource declarations]===============================*/
DeclareTask(Init_Task);
DeclareTask(IdleTask);


/*==================[OS resource definitions]================================*/
TASK(Init_Task)
{
  EcuM_StartupTwo();  /* Task "Init_Task" has to invoke function "EcuM_StartupTwo". */
  InitWorkPage();
  Appl_SetCalPage(0);
  RESTART_SCI_IOHW_WsIoHwAb_Calc10ms();

#if 0
  BswM_RequestMode(BSWM_BSWM_SM, BSWM_STARTUP_TWO_A);  /* Parameter 1 refers to BswM parameter
                                             * "BswMModeRequesterId",
                                             * which belongs to mode request port "EcuM_AL_ReqPort". */
                                            /* TBD: This invocation needs to be done due
                                             * to current BswM implementation - at the moment
                                             * rules will just be evaluated within the main function
                                             * if a mode request has been initiated before.
                                             * This does not comply to the AUTOSAR specification.
                                             * Therefore an EB specific parameter will probably be
                                             * introduced that controls this behaviour.
                                             * Remove this code line and the accompayning header file
                                             * inclusion when the EB specific parameter has been
                                             * implemented. */
#endif
	//ActivateTask(IdleTask);
  (void) TerminateTask();
}

// TASK(IdleTask)
// {
	// while (1)
	// {
		// /* place here your tooling code... */
		// /* keep in mind you have a memory stack of 100 bytes!!! */
		
	// }
  // (void) TerminateTask();
// }


/*==================[end of file]============================================*/
