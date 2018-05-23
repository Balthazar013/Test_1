#if !defined(RTE_FOD_H)
#define RTE_FOD_H

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
  * This file contains Rte component declarations for component type FOD
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.75
  * on Fri Feb 09 14:59:49 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <TSMem.h>
#include <Rte_FOD_Type.h> /* RTE application types header file */
#include <Rte_FOD_Hook.h> /* RTE application trace hooks header file */

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
#define Rte_Pim_NullVector_pim() (*Rte_Inst_FOD->Pim_NullVector_pim)

#if !defined(RTE_RUNNABLEAPI_WsFodMgr_NullVector_Start)
#define Rte_IrvRead_WsFodMgr_MainFunction_NvFlag() Rte_IrvRead_FOD_WsFodMgr_MainFunction_NvFlag()

#define Rte_IrvWrite_WsFodMgr_MainFunction_NvFlag(data) Rte_IrvWrite_FOD_WsFodMgr_MainFunction_NvFlag(data)

#define Rte_IWrite_WsFodMgr_MainFunction_PP_ForeignObjectDetected_SCI_FODMGR_SftyOnOffValue(data) (Rte_IWriteHook_FOD_PP_ForeignObjectDetected_SCI_FODMGR_SftyOnOffValue_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_ForeignObjectDetected_SCI_FODMGR_SftyOnOffValue->value = *(data), Rte_IWriteHook_FOD_PP_ForeignObjectDetected_SCI_FODMGR_SftyOnOffValue_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_ForeignObjectDetected_SCI_FODMGR_SftyOnOffValue() (P2VAR(SftyBoolOO, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_ForeignObjectDetected_SCI_FODMGR_SftyOnOffValue->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckDuringChrg_SftyBoolValue(data) (Rte_IWriteHook_FOD_PP_FodCheckDuringChrg_SftyBoolValue_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckDuringChrg_SftyBoolValue->value = *(data), Rte_IWriteHook_FOD_PP_FodCheckDuringChrg_SftyBoolValue_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckDuringChrg_SftyBoolValue() (P2VAR(SftyBoolTF, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckDuringChrg_SftyBoolValue->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckStartUpChrg_SftyBoolValue(data) (Rte_IWriteHook_FOD_PP_FodCheckStartUpChrg_SftyBoolValue_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckStartUpChrg_SftyBoolValue->value = *(data), Rte_IWriteHook_FOD_PP_FodCheckStartUpChrg_SftyBoolValue_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckStartUpChrg_SftyBoolValue() (P2VAR(SftyBoolTF, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckStartUpChrg_SftyBoolValue->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckZMDown_SftyBoolValue(data) (Rte_IWriteHook_FOD_PP_FodCheckZMDown_SftyBoolValue_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckZMDown_SftyBoolValue->value = *(data), Rte_IWriteHook_FOD_PP_FodCheckZMDown_SftyBoolValue_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckZMDown_SftyBoolValue() (P2VAR(SftyBoolTF, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckZMDown_SftyBoolValue->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckZMUp_SftyBoolValue(data) (Rte_IWriteHook_FOD_PP_FodCheckZMUp_SftyBoolValue_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckZMUp_SftyBoolValue->value = *(data), Rte_IWriteHook_FOD_PP_FodCheckZMUp_SftyBoolValue_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckZMUp_SftyBoolValue() (P2VAR(SftyBoolTF, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckZMUp_SftyBoolValue->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodPreCheck_SftyBoolValue(data) (Rte_IWriteHook_FOD_PP_FodPreCheck_SftyBoolValue_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodPreCheck_SftyBoolValue->value = *(data), Rte_IWriteHook_FOD_PP_FodPreCheck_SftyBoolValue_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodPreCheck_SftyBoolValue() (P2VAR(SftyBoolTF, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodPreCheck_SftyBoolValue->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckDuringChrgTh_Value(data) (Rte_IWriteHook_FOD_PP_FodCheckDuringChrgTh_Value_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckDuringChrgTh_Value->value = (data), Rte_IWriteHook_FOD_PP_FodCheckDuringChrgTh_Value_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckDuringChrgTh_Value() (P2VAR(FodDetectTh, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckDuringChrgTh_Value->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckZMDownTh_Value(data) (Rte_IWriteHook_FOD_PP_FodCheckZMDownTh_Value_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckZMDownTh_Value->value = (data), Rte_IWriteHook_FOD_PP_FodCheckZMDownTh_Value_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckZMDownTh_Value() (P2VAR(FodDetectTh, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckZMDownTh_Value->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckZMUpTh_Value(data) (Rte_IWriteHook_FOD_PP_FodCheckZMUpTh_Value_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckZMUpTh_Value->value = (data), Rte_IWriteHook_FOD_PP_FodCheckZMUpTh_Value_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckZMUpTh_Value() (P2VAR(FodDetectTh, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodCheckZMUpTh_Value->value))

#define Rte_IWrite_WsFodMgr_MainFunction_PP_FodPreCheckTh_Value(data) (Rte_IWriteHook_FOD_PP_FodPreCheckTh_Value_Start((data)), Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodPreCheckTh_Value->value = (data), Rte_IWriteHook_FOD_PP_FodPreCheckTh_Value_Return((data)))

#define Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodPreCheckTh_Value() (P2VAR(FodDetectTh, AUTOMATIC, RTE_APPL_DATA))(&(Rte_Inst_FOD->WsFodMgr_MainFunction_PP_FodPreCheckTh_Value->value))

#define Rte_IRead_WsFodMgr_MainFunction_RP_FodData_SCI_FODMGR_FodDataValue() (Rte_IReadHook_FOD_RP_FodData_SCI_FODMGR_FodDataValue_Start((P2CONST(FodDataV40, AUTOMATIC, RTE_APPL_CONST))&(Rte_Inst_FOD->WsFodMgr_MainFunction_RP_FodData_SCI_FODMGR_FodDataValue->value)), Rte_IReadHook_FOD_RP_FodData_SCI_FODMGR_FodDataValue_Return((P2CONST(FodDataV40, AUTOMATIC, RTE_APPL_CONST))&(Rte_Inst_FOD->WsFodMgr_MainFunction_RP_FodData_SCI_FODMGR_FodDataValue->value)), (P2CONST(FodDataV40, AUTOMATIC, RTE_APPL_CONST))&(Rte_Inst_FOD->WsFodMgr_MainFunction_RP_FodData_SCI_FODMGR_FodDataValue->value))

#define Rte_IRead_WsFodMgr_MainFunction_RP_ResData_ResDataVal() (Rte_IReadHook_FOD_RP_ResData_ResDataVal_Start((P2CONST(ResData, AUTOMATIC, RTE_APPL_CONST))&(Rte_Inst_FOD->WsFodMgr_MainFunction_RP_ResData_ResDataVal->value)), Rte_IReadHook_FOD_RP_ResData_ResDataVal_Return((P2CONST(ResData, AUTOMATIC, RTE_APPL_CONST))&(Rte_Inst_FOD->WsFodMgr_MainFunction_RP_ResData_ResDataVal->value)), (P2CONST(ResData, AUTOMATIC, RTE_APPL_CONST))&(Rte_Inst_FOD->WsFodMgr_MainFunction_RP_ResData_ResDataVal->value))

#define Rte_IRead_WsFodMgr_MainFunction_WspDiagCtrl_cmdFodActivate_DiagCtrlFod() (Rte_IReadHook_FOD_WspDiagCtrl_cmdFodActivate_DiagCtrlFod_Start(Rte_Inst_FOD->WsFodMgr_MainFunction_WspDiagCtrl_cmdFodActivate_DiagCtrlFod->value), Rte_IReadHook_FOD_WspDiagCtrl_cmdFodActivate_DiagCtrlFod_Return(Rte_Inst_FOD->WsFodMgr_MainFunction_WspDiagCtrl_cmdFodActivate_DiagCtrlFod->value), Rte_Inst_FOD->WsFodMgr_MainFunction_WspDiagCtrl_cmdFodActivate_DiagCtrlFod->value)

#define Rte_IRead_WsFodMgr_MainFunction_WspDiagCtrl_cmdFodFreeze_DiagCtrlFreeze() (Rte_IReadHook_FOD_WspDiagCtrl_cmdFodFreeze_DiagCtrlFreeze_Start(Rte_Inst_FOD->WsFodMgr_MainFunction_WspDiagCtrl_cmdFodFreeze_DiagCtrlFreeze->value), Rte_IReadHook_FOD_WspDiagCtrl_cmdFodFreeze_DiagCtrlFreeze_Return(Rte_Inst_FOD->WsFodMgr_MainFunction_WspDiagCtrl_cmdFodFreeze_DiagCtrlFreeze->value), Rte_Inst_FOD->WsFodMgr_MainFunction_WspDiagCtrl_cmdFodFreeze_DiagCtrlFreeze->value)

#define Rte_Call_RP_NvMService_GetErrorStatus Rte_Call_FOD_RP_NvMService_GetErrorStatus

#define Rte_Call_RP_NvMService_SetDataIndex Rte_Call_FOD_RP_NvMService_SetDataIndex

#define Rte_Call_RP_NvMService_GetDataIndex Rte_Call_FOD_RP_NvMService_GetDataIndex

#define Rte_Call_RP_NvMService_SetRamBlockStatus Rte_Call_FOD_RP_NvMService_SetRamBlockStatus

#define Rte_Call_RP_NvMService_ReadBlock Rte_Call_FOD_RP_NvMService_ReadBlock

#define Rte_Call_RP_NvMService_WriteBlock Rte_Call_FOD_RP_NvMService_WriteBlock

#define Rte_Call_RP_NvMService_RestoreBlockDefaults Rte_Call_FOD_RP_NvMService_RestoreBlockDefaults

#define Rte_Call_RP_NvMService_InvalidateNvBlock Rte_Call_FOD_RP_NvMService_InvalidateNvBlock

#define Rte_Call_Event_METAL_ON_PAD_SetEventStatus Rte_Call_FOD_Event_METAL_ON_PAD_SetEventStatus

#define Rte_Call_Event_METAL_ON_PAD_ResetEventStatus Rte_Call_FOD_Event_METAL_ON_PAD_ResetEventStatus

#define Rte_Call_Event_METAL_ON_PAD_GetEventStatus Rte_Call_FOD_Event_METAL_ON_PAD_GetEventStatus

#define Rte_Call_Event_METAL_ON_PAD_GetEventFailed Rte_Call_FOD_Event_METAL_ON_PAD_GetEventFailed

#define Rte_Call_Event_METAL_ON_PAD_GetEventTested Rte_Call_FOD_Event_METAL_ON_PAD_GetEventTested

#define Rte_Call_Event_METAL_ON_PAD_GetDTCOfEvent Rte_Call_FOD_Event_METAL_ON_PAD_GetDTCOfEvent

#define Rte_Call_Event_METAL_ON_PAD_PrestoreFreezeFrame Rte_Call_FOD_Event_METAL_ON_PAD_PrestoreFreezeFrame

#define Rte_Call_Event_METAL_ON_PAD_ClearPrestoredFreezeFrame Rte_Call_FOD_Event_METAL_ON_PAD_ClearPrestoredFreezeFrame

#define Rte_Call_Event_METAL_ON_PAD_GetFaultDetectionCounter Rte_Call_FOD_Event_METAL_ON_PAD_GetFaultDetectionCounter

#define Rte_Call_alive_WdgMSvEnt_FodMgr_CheckpointReached Rte_Call_FOD_alive_WdgMSvEnt_FodMgr_CheckpointReached

#define Rte_Call_alive_WdgMSvEnt_FodMgr_UpdateAliveCounter Rte_Call_FOD_alive_WdgMSvEnt_FodMgr_UpdateAliveCounter

#endif
#if !defined(RTE_RUNNABLEAPI_WsFodMgr_MainFunction)
#define Rte_IrvRead_WsFodMgr_NullVector_Start_NvFlag() Rte_IrvRead_FOD_WsFodMgr_NullVector_Start_NvFlag()

#define Rte_IrvWrite_WsFodMgr_NullVector_Start_NvFlag(data) Rte_IrvWrite_FOD_WsFodMgr_NullVector_Start_NvFlag(data)

#endif

#endif

/*------------------[port handle API mapping]--------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*------------------[application errors]-------------------------------------*/

#define RTE_E_NvMService_E_NOT_OK 1U
#define RTE_E_DiagnosticMonitor_E_NOT_OK 1U
#define RTE_E_DiagnosticMonitor_E_NO_DTC_AVAILABLE 2U
#define RTE_E_WdgM_AliveSupervision_E_NOT_OK 1U

/*------------------[init values]--------------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#define Rte_InitValue_PP_FodPreCheckTh_Value 0
#define Rte_InitValue_PP_FodCheckZMDownTh_Value 0
#define Rte_InitValue_PP_FodCheckZMUpTh_Value 0
#define Rte_InitValue_PP_FodCheckDuringChrgTh_Value 0
#define Rte_InitValue_WspDiagCtrl_cmdFodFreeze_DiagCtrlFreeze 0U
#define Rte_InitValue_WspDiagCtrl_cmdFodActivate_DiagCtrlFod 0U

#endif

/*==================[type definitions]=======================================*/

/*------------------[instance handle type]-----------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_FOD, RTE_CONST, RTE_CONST) Rte_Instance;
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

extern FUNC(void, RTE_APPL_CODE) WsFodMgr_MainFunction(void);

extern FUNC(void, RTE_APPL_CODE) WsFodMgr_NullVector_Start(GenericByte trigger, P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) result);

#define RTE_STOP_SEC_APPL_CODE
#include "MemMap.h"

/*--------------[declaration of API functions provided by Rte]--------------*/

#define RTE_START_SEC_CODE
#include "MemMap.h"
#if (!defined(RTE_RUNNABLEAPI_WsFodMgr_NullVector_Start))
extern FUNC(GenericByte, RTE_CODE) Rte_IrvRead_FOD_WsFodMgr_MainFunction_NvFlag (void);

extern FUNC(void, RTE_CODE) Rte_IrvWrite_FOD_WsFodMgr_MainFunction_NvFlag (GenericByte data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_RP_NvMService_GetErrorStatus (P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_APPL_DATA) RequestResultPtr);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_RP_NvMService_SetDataIndex (uint8 DataIndex);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_RP_NvMService_GetDataIndex (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) DataIndexPtr);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_RP_NvMService_SetRamBlockStatus (boolean BlockChanged);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_RP_NvMService_ReadBlock (NvM_DstPtrType DstPtr);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_RP_NvMService_WriteBlock (NvM_SrcPtrType SrcPtr);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_RP_NvMService_RestoreBlockDefaults (NvM_DstPtrType DstPtr);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_RP_NvMService_InvalidateNvBlock (void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_SetEventStatus (Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_ResetEventStatus (void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_GetEventStatus (P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_GetEventFailed (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) EventFailed);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_GetEventTested (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) EventTested);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_GetDTCOfEvent (Dem_DTCKindType DTCKind, P2VAR(Dem_DTCType, AUTOMATIC, RTE_APPL_DATA) DTCofEvent);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_PrestoreFreezeFrame (void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_ClearPrestoredFreezeFrame (void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_Event_METAL_ON_PAD_GetFaultDetectionCounter (P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, RTE_APPL_DATA) EventIdFaultDetectionCounter);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_alive_WdgMSvEnt_FodMgr_CheckpointReached (WdgM_CheckpointIdType CheckpointId);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FOD_alive_WdgMSvEnt_FodMgr_UpdateAliveCounter (void);

#endif
#if (!defined(RTE_RUNNABLEAPI_WsFodMgr_MainFunction))
extern FUNC(GenericByte, RTE_CODE) Rte_IrvRead_FOD_WsFodMgr_NullVector_Start_NvFlag (void);

extern FUNC(void, RTE_CODE) Rte_IrvWrite_FOD_WsFodMgr_NullVector_Start_NvFlag (GenericByte data);

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

extern CONSTP2CONST(Rte_CDS_FOD, RTE_CONST, RTE_CONST) Rte_Inst_FOD;

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
#endif /* !defined(RTE_FOD_H) */
/*==================[end of file]============================================*/
