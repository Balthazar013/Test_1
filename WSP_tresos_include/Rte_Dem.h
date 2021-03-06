#if !defined(RTE_DEM_H)
#define RTE_DEM_H

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
  * This file contains Rte component declarations for component type Dem
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.75
  * on Fri Feb 09 11:09:50 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <TSMem.h>
#include <Rte_Dem_Type.h> /* RTE application types header file */
#include <Rte_Dem_Hook.h> /* RTE application trace hooks header file */

/*==================[macros]=================================================*/

#if (!defined RTE_CORE) /* if included by software component */

#if (!defined RTE_APPLICATION_HEADER_FILE_H) /* prevent double inclusion */
#define RTE_APPLICATION_HEADER_FILE_H
#else
#error Multiple application header files included.
#endif /* if !defined( RTE_APPLICATION_HEADER_FILE_H ) */

#endif

/*------------------[API mapping]--------------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
#if !defined(RTE_RUNNABLEAPI_RE_SetEventStatus) || !defined(RTE_RUNNABLEAPI_RE_ResetEventStatus) || !defined(RTE_RUNNABLEAPI_RE_GetEventStatus) || !defined(RTE_RUNNABLEAPI_RE_GetEventFailed) || !defined(RTE_RUNNABLEAPI_RE_GetEventTested) || !defined(RTE_RUNNABLEAPI_RE_GetDTCOfEvent) || !defined(RTE_RUNNABLEAPI_RE_PrestoreFreezeFrame) || !defined(RTE_RUNNABLEAPI_RE_ClearPrestoredFreezeFrame) || !defined(RTE_RUNNABLEAPI_RE_GetFaultDetectionCounter) || !defined(RTE_RUNNABLEAPI_SetAgingCycleCounterValue)
#define Rte_Call_DidServices_StandardFreezeFrame_ConditionCheckRead Rte_Call_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead

#define Rte_Call_DidServices_StandardFreezeFrame_ReadData Rte_Call_Dem_DidServices_StandardFreezeFrame_ReadData

#define Rte_Call_DidServices_ExtendedFreezeFrame_ConditionCheckRead Rte_Call_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead

#define Rte_Call_DidServices_ExtendedFreezeFrame_ReadData Rte_Call_Dem_DidServices_ExtendedFreezeFrame_ReadData

#endif

#endif

/*------------------[port handle API mapping]--------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*------------------[application errors]-------------------------------------*/

#define RTE_E_DiagnosticMonitor_E_NOT_OK 1U
#define RTE_E_DiagnosticMonitor_E_NO_DTC_AVAILABLE 2U
#define RTE_E_ExternalAgingCycle_E_NOT_OK 1U
#define RTE_E_DidServices_0x0002_E_NOT_OK 1U
#define RTE_E_DidServices_0x0002_E_PENDING 10U
#define RTE_E_DidServices_0x0071_E_NOT_OK 1U
#define RTE_E_DidServices_0x0071_E_PENDING 10U

/*------------------[init values]--------------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*==================[type definitions]=======================================*/

/*------------------[instance handle type]-----------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_Dem, RTE_CONST, RTE_CONST) Rte_Instance;
#endif

/*------------------[port handle types]--------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
#endif

/*------------------[per instance memory types]------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*==================[external function declarations]=========================*/

/*------------------[declaration of runnable entities]-----------------------*/

#define RTE_START_SEC_APPL_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType pdav0, Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_ResetEventStatus(Dem_EventIdType pdav0);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_GetEventStatus(Dem_EventIdType pdav0, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_GetEventFailed(Dem_EventIdType pdav0, P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) EventFailed);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_GetEventTested(Dem_EventIdType pdav0, P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) EventTested);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_GetDTCOfEvent(Dem_EventIdType pdav0, Dem_DTCKindType DTCKind, P2VAR(Dem_DTCType, AUTOMATIC, RTE_APPL_DATA) DTCofEvent);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_PrestoreFreezeFrame(Dem_EventIdType pdav0);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_ClearPrestoredFreezeFrame(Dem_EventIdType pdav0);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType pdav0, P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, RTE_APPL_DATA) EventIdFaultDetectionCounter);

extern FUNC(void, RTE_APPL_CODE) Dem_MainFunction(void);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_SetAgingCycleCounterValue(uint8 CounterValue);

#define RTE_STOP_SEC_APPL_CODE
#include "MemMap.h"

/*--------------[declaration of API functions provided by Rte]--------------*/

#define RTE_START_SEC_CODE
#include "MemMap.h"
#if (!defined(RTE_RUNNABLEAPI_RE_SetEventStatus))  || (!defined(RTE_RUNNABLEAPI_RE_ResetEventStatus)) || (!defined(RTE_RUNNABLEAPI_RE_GetEventStatus)) || (!defined(RTE_RUNNABLEAPI_RE_GetEventFailed)) || (!defined(RTE_RUNNABLEAPI_RE_GetEventTested)) || (!defined(RTE_RUNNABLEAPI_RE_GetDTCOfEvent)) || (!defined(RTE_RUNNABLEAPI_RE_PrestoreFreezeFrame)) || (!defined(RTE_RUNNABLEAPI_RE_ClearPrestoredFreezeFrame)) || (!defined(RTE_RUNNABLEAPI_RE_GetFaultDetectionCounter)) || (!defined(RTE_RUNNABLEAPI_SetAgingCycleCounterValue))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DidServices_StandardFreezeFrame_ConditionCheckRead (P2VAR(NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) Nrc);

#ifdef RTE_PTR2ARRAYTYPE_PASSING
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DidServices_StandardFreezeFrame_ReadData (P2VAR(Dem_Did0x0002_ArrayType, AUTOMATIC, RTE_APPL_DATA) Data);
#else
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DidServices_StandardFreezeFrame_ReadData (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);
#endif

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DidServices_ExtendedFreezeFrame_ConditionCheckRead (P2VAR(NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) Nrc);

#ifdef RTE_PTR2ARRAYTYPE_PASSING
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DidServices_ExtendedFreezeFrame_ReadData (P2VAR(Dem_Did0x0071_ArrayType, AUTOMATIC, RTE_APPL_DATA) Data);
#else
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DidServices_ExtendedFreezeFrame_ReadData (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);
#endif

#endif

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

/*--------------[declaration of API functions provided by other Appl]--------*/

#define RTE_START_SEC_APPL_CODE
#include "MemMap.h"

#if (!defined RTE_CORE) /* if included by software component */

#endif /* (!defined RTE_CORE) */

#define RTE_STOP_SEC_APPL_CODE
#include "MemMap.h"

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*------------------[instance handle declaration]----------------------------*/
#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONSTP2CONST(Rte_CDS_Dem, RTE_CONST, RTE_CONST) Rte_Inst_Dem;

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
/** @} doxygen end group definition */
#endif /* !defined(RTE_DEM_H) */
/*==================[end of file]============================================*/

