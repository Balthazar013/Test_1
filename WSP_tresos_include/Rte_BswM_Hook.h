#if !defined(RTE_BSWM_HOOK_H)
#define RTE_BSWM_HOOK_H

/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /*
  * This file contains Rte hook declarations for the software component type BswM
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.75
  * on Fri Feb 09 11:09:50 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

#include <Rte_Cfg.h>         /* RTE VFB configuration header file */
#include <Rte_Type.h>     /* Rte type definitions header file */

/*==================[macros]=================================================*/

#if (!defined RTE_CORE) /* if included by software component */
#ifndef RTE_VFB_TRACE
#define RTE_VFB_TRACE (0)
#endif /* RTE_VFB_TRACE */
#endif
#if defined(Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Start
#endif
#if defined(Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Start)
#undef Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Start(uint8 mode);
#else
#define Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Start(mode) ((void)0)
#endif /* Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Start */
#if defined(Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Return
#endif
#if defined(Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Return)
#undef Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Return(uint8 mode);
#else
#define Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Return(mode) ((void)0)
#endif /* Rte_SwitchHook_BswM_BswM_ModeSwitchPort_BswMSwitchPort_Rte_CurrentMode_Return */
#if defined(Rte_Runnable_BswM_RES_MainFunction_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_BswM_RES_MainFunction_Start
#endif
#if defined(Rte_Runnable_BswM_RES_MainFunction_Start)
#undef Rte_Runnable_BswM_RES_MainFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_BswM_RES_MainFunction_Start(void);
#else
#define Rte_Runnable_BswM_RES_MainFunction_Start() ((void)0)
#endif /* Rte_Runnable_BswM_RES_MainFunction_Start */
#if defined(Rte_Runnable_BswM_RES_MainFunction_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_BswM_RES_MainFunction_Return
#endif
#if defined(Rte_Runnable_BswM_RES_MainFunction_Return)
#undef Rte_Runnable_BswM_RES_MainFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_BswM_RES_MainFunction_Return(void);
#else
#define Rte_Runnable_BswM_RES_MainFunction_Return() ((void)0)
#endif /* Rte_Runnable_BswM_RES_MainFunction_Return */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/
/** @} doxygen end group definition */
#endif /* !defined(RTE_BSWM_HOOK_H) */
/*==================[end of file]============================================*/

