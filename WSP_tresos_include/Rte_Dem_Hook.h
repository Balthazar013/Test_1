#if !defined(RTE_DEM_HOOK_H)
#define RTE_DEM_HOOK_H

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
  * This file contains Rte hook declarations for the software component type Dem
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
#if defined(Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Start
#endif
#if defined(Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Start)
#undef Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Start(P2VAR(NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) Nrc);
#else
#define Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Start(Nrc) ((void)0)
#endif /* Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Start */
#if defined(Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Return
#endif
#if defined(Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Return)
#undef Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Return(P2VAR(NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) Nrc);
#else
#define Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Return(Nrc) ((void)0)
#endif /* Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead_Return */
#if defined(Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Start
#endif
#if defined(Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Start)
#undef Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Start(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);
#else
#define Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Start(Data) ((void)0)
#endif /* Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Start */
#if defined(Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Return
#endif
#if defined(Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Return)
#undef Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Return(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);
#else
#define Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Return(Data) ((void)0)
#endif /* Rte_CallHook_Dem_DidServices_StandardFreezeFrame_ReadData_Return */
#if defined(Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Start
#endif
#if defined(Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Start)
#undef Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Start(P2VAR(NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) Nrc);
#else
#define Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Start(Nrc) ((void)0)
#endif /* Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Start */
#if defined(Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Return
#endif
#if defined(Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Return)
#undef Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Return(P2VAR(NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) Nrc);
#else
#define Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Return(Nrc) ((void)0)
#endif /* Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead_Return */
#if defined(Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Start
#endif
#if defined(Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Start)
#undef Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Start(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);
#else
#define Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Start(Data) ((void)0)
#endif /* Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Start */
#if defined(Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Return
#endif
#if defined(Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Return)
#undef Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Return(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);
#else
#define Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Return(Data) ((void)0)
#endif /* Rte_CallHook_Dem_DidServices_ExtendedFreezeFrame_ReadData_Return */
#if defined(Rte_Runnable_Dem_RE_SetEventStatus_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_SetEventStatus_Start
#endif
#if defined(Rte_Runnable_Dem_RE_SetEventStatus_Start)
#undef Rte_Runnable_Dem_RE_SetEventStatus_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_SetEventStatus_Start(void);
#else
#define Rte_Runnable_Dem_RE_SetEventStatus_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_SetEventStatus_Start */
#if defined(Rte_Runnable_Dem_RE_SetEventStatus_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_SetEventStatus_Return
#endif
#if defined(Rte_Runnable_Dem_RE_SetEventStatus_Return)
#undef Rte_Runnable_Dem_RE_SetEventStatus_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_SetEventStatus_Return(void);
#else
#define Rte_Runnable_Dem_RE_SetEventStatus_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_SetEventStatus_Return */
#if defined(Rte_Runnable_Dem_RE_ResetEventStatus_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_ResetEventStatus_Start
#endif
#if defined(Rte_Runnable_Dem_RE_ResetEventStatus_Start)
#undef Rte_Runnable_Dem_RE_ResetEventStatus_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_ResetEventStatus_Start(void);
#else
#define Rte_Runnable_Dem_RE_ResetEventStatus_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_ResetEventStatus_Start */
#if defined(Rte_Runnable_Dem_RE_ResetEventStatus_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_ResetEventStatus_Return
#endif
#if defined(Rte_Runnable_Dem_RE_ResetEventStatus_Return)
#undef Rte_Runnable_Dem_RE_ResetEventStatus_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_ResetEventStatus_Return(void);
#else
#define Rte_Runnable_Dem_RE_ResetEventStatus_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_ResetEventStatus_Return */
#if defined(Rte_Runnable_Dem_RE_GetEventStatus_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetEventStatus_Start
#endif
#if defined(Rte_Runnable_Dem_RE_GetEventStatus_Start)
#undef Rte_Runnable_Dem_RE_GetEventStatus_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetEventStatus_Start(void);
#else
#define Rte_Runnable_Dem_RE_GetEventStatus_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetEventStatus_Start */
#if defined(Rte_Runnable_Dem_RE_GetEventStatus_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetEventStatus_Return
#endif
#if defined(Rte_Runnable_Dem_RE_GetEventStatus_Return)
#undef Rte_Runnable_Dem_RE_GetEventStatus_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetEventStatus_Return(void);
#else
#define Rte_Runnable_Dem_RE_GetEventStatus_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetEventStatus_Return */
#if defined(Rte_Runnable_Dem_RE_GetEventFailed_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetEventFailed_Start
#endif
#if defined(Rte_Runnable_Dem_RE_GetEventFailed_Start)
#undef Rte_Runnable_Dem_RE_GetEventFailed_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetEventFailed_Start(void);
#else
#define Rte_Runnable_Dem_RE_GetEventFailed_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetEventFailed_Start */
#if defined(Rte_Runnable_Dem_RE_GetEventFailed_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetEventFailed_Return
#endif
#if defined(Rte_Runnable_Dem_RE_GetEventFailed_Return)
#undef Rte_Runnable_Dem_RE_GetEventFailed_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetEventFailed_Return(void);
#else
#define Rte_Runnable_Dem_RE_GetEventFailed_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetEventFailed_Return */
#if defined(Rte_Runnable_Dem_RE_GetEventTested_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetEventTested_Start
#endif
#if defined(Rte_Runnable_Dem_RE_GetEventTested_Start)
#undef Rte_Runnable_Dem_RE_GetEventTested_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetEventTested_Start(void);
#else
#define Rte_Runnable_Dem_RE_GetEventTested_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetEventTested_Start */
#if defined(Rte_Runnable_Dem_RE_GetEventTested_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetEventTested_Return
#endif
#if defined(Rte_Runnable_Dem_RE_GetEventTested_Return)
#undef Rte_Runnable_Dem_RE_GetEventTested_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetEventTested_Return(void);
#else
#define Rte_Runnable_Dem_RE_GetEventTested_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetEventTested_Return */
#if defined(Rte_Runnable_Dem_RE_GetDTCOfEvent_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetDTCOfEvent_Start
#endif
#if defined(Rte_Runnable_Dem_RE_GetDTCOfEvent_Start)
#undef Rte_Runnable_Dem_RE_GetDTCOfEvent_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetDTCOfEvent_Start(void);
#else
#define Rte_Runnable_Dem_RE_GetDTCOfEvent_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetDTCOfEvent_Start */
#if defined(Rte_Runnable_Dem_RE_GetDTCOfEvent_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetDTCOfEvent_Return
#endif
#if defined(Rte_Runnable_Dem_RE_GetDTCOfEvent_Return)
#undef Rte_Runnable_Dem_RE_GetDTCOfEvent_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetDTCOfEvent_Return(void);
#else
#define Rte_Runnable_Dem_RE_GetDTCOfEvent_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetDTCOfEvent_Return */
#if defined(Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Start
#endif
#if defined(Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Start)
#undef Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Start(void);
#else
#define Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Start */
#if defined(Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Return
#endif
#if defined(Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Return)
#undef Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Return(void);
#else
#define Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_PrestoreFreezeFrame_Return */
#if defined(Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Start
#endif
#if defined(Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Start)
#undef Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Start(void);
#else
#define Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Start */
#if defined(Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Return
#endif
#if defined(Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Return)
#undef Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Return(void);
#else
#define Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_ClearPrestoredFreezeFrame_Return */
#if defined(Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Start
#endif
#if defined(Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Start)
#undef Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Start(void);
#else
#define Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Start */
#if defined(Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Return
#endif
#if defined(Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Return)
#undef Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Return(void);
#else
#define Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_GetFaultDetectionCounter_Return */
#if defined(Rte_Runnable_Dem_RE_MainFunction_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_MainFunction_Start
#endif
#if defined(Rte_Runnable_Dem_RE_MainFunction_Start)
#undef Rte_Runnable_Dem_RE_MainFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_MainFunction_Start(void);
#else
#define Rte_Runnable_Dem_RE_MainFunction_Start() ((void)0)
#endif /* Rte_Runnable_Dem_RE_MainFunction_Start */
#if defined(Rte_Runnable_Dem_RE_MainFunction_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_RE_MainFunction_Return
#endif
#if defined(Rte_Runnable_Dem_RE_MainFunction_Return)
#undef Rte_Runnable_Dem_RE_MainFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_RE_MainFunction_Return(void);
#else
#define Rte_Runnable_Dem_RE_MainFunction_Return() ((void)0)
#endif /* Rte_Runnable_Dem_RE_MainFunction_Return */
#if defined(Rte_Runnable_Dem_SetAgingCycleCounterValue_Start) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_SetAgingCycleCounterValue_Start
#endif
#if defined(Rte_Runnable_Dem_SetAgingCycleCounterValue_Start)
#undef Rte_Runnable_Dem_SetAgingCycleCounterValue_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetAgingCycleCounterValue_Start(void);
#else
#define Rte_Runnable_Dem_SetAgingCycleCounterValue_Start() ((void)0)
#endif /* Rte_Runnable_Dem_SetAgingCycleCounterValue_Start */
#if defined(Rte_Runnable_Dem_SetAgingCycleCounterValue_Return) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Dem_SetAgingCycleCounterValue_Return
#endif
#if defined(Rte_Runnable_Dem_SetAgingCycleCounterValue_Return)
#undef Rte_Runnable_Dem_SetAgingCycleCounterValue_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetAgingCycleCounterValue_Return(void);
#else
#define Rte_Runnable_Dem_SetAgingCycleCounterValue_Return() ((void)0)
#endif /* Rte_Runnable_Dem_SetAgingCycleCounterValue_Return */

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
#endif /* !defined(RTE_DEM_HOOK_H) */
/*==================[end of file]============================================*/
