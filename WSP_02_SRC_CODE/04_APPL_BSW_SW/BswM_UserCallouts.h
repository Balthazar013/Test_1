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

#ifndef BSWM_USERCALLOUTS_H
#define BSWM_USERCALLOUTS_H


/*==================[includes]==============================================*/

#include <TSAutosar.h>     /* EB specific standard types */


/*==================[macros]================================================*/

/* BswM states:
 * The values assigned to the macros must be less than or equal to the value
 * you have configured in parameter "BswMRequestedModeMax" of the corresponding
 * BswM mode request port (the value of parameter "BswMModeRequestSource" of
 * this mode request port has to be "BswMGenericRequest"). */
#define BSWM_BSWM_SM        0u  /* the BswMModeRequesterId of the BswM state
                                 * machine. */

#define BSWM_STARTUP_TWO_A  0u  /*!< ECU state handled by BswM module. */
#define BSWM_STARTUP_TWO_B  1u  /*!< ECU state handled by BswM module. */
#define BSWM_RUN_TWO        2u  /*!< ECU state handled by BswM module. */
#define BSWM_GO_OFF_ONE_A   3u  /*!< ECU state handled by BswM module. */
#define BSWM_GO_OFF_ONE_B   4u  /*!< ECU state handled by BswM module. */
#define BSWM_WAKEUP_TWO     5u  /*!< ECU state handled by BswM module. */

/* SWC_CyclicCounter states:
 * The values assigned to the macros must be less than or equal to the value
 * you have configured in parameter "BswMRequestedModeMax" of the corresponding
 * BswM mode request port (the value of parameter "BswMModeRequestSource" of
 * this mode request port has to be "BswMGenericRequest"). */
#define BSWM_SWC_CYCLIC             1u  /* the BswMModeRequesterId of the 
                                         * SWC_CyclicCounter. */

#define BSWM_SWC_CYCLIC_UNINIT      0u  /* SWC_CyclicCounter state */
#define BSWM_SWC_CYCLIC_RUN         1u  /* SWC_CyclicCounter state */
#define BSWM_SWC_CYCLIC_SHUTDOWN    2u  /* SWC_CyclicCounter state */


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/* AUTOSAR Memory Mapping - start section for code */
#define BSWM_START_SEC_CODE
#include <MemMap.h>


extern FUNC(void, BSWM_APPL_CODE) BswM_OnRunTwo(void);
extern FUNC(void, BSWM_APPL_CODE) BswM_OnPrpShutdown(void);
extern FUNC(void, BSWM_APPL_CODE) BswM_OnGoOffOneA(void);
extern FUNC(void, BSWM_APPL_CODE) BswM_OnGoOffOneB(void);
extern FUNC(void, BSWM_APPL_CODE) BswM_OnGoOffTwo(void);
extern FUNC(void, BSWM_APPL_CODE) BswM_OnWakeupTwo(void);
extern FUNC(void, BSWM_APPL_CODE) ApplCan_FullCom(void);
extern FUNC(void, BSWM_APPL_CODE) ApplCan_NoCom(void);
extern FUNC(void, BSWM_APPL_CODE) ApplCan_SilentCom(void);
extern FUNC(void, BSWM_APPL_CODE) ApplCan_BusOffEvent(void);

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>


/*==================[internal function definitions]=========================*/


#endif /* ifndef BSWM_USERCALLOUTS_H */

/*==================[end of file]===========================================*/
