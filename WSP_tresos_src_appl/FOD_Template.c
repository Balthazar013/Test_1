
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
  * This file contains an Rte component template / example code
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.75
  * on Fri Feb 09 14:59:50 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

#include "Rte_FOD.h"

/*------------------------[runnable entity skeletons]------------------------*/

void WsFodMgr_MainFunction (void)
{
  WdgM_CheckpointIdType CheckpointId;
  Dem_FaultDetectionCounterType EventIdFaultDetectionCounter;
  Dem_DTCType DTCofEvent;
  Dem_DTCKindType DTCKind;
  boolean EventTested;
  boolean EventFailed;
  Dem_EventStatusExtendedType EventStatusExtended;
  Dem_EventStatusType EventStatus;
  NvM_DstPtrType DstPtr_0;
  NvM_SrcPtrType SrcPtr;
  NvM_DstPtrType DstPtr;
  boolean BlockChanged;
  uint8 DataIndexPtr;
  uint8 DataIndex;
  NvM_RequestResultType RequestResultPtr;
  GenericByte DiagCtrlFreeze;
  uint8 DiagCtrlFod;
  P2CONST(ResData, AUTOMATIC, AUTOMATIC) ResDataVal;
  P2CONST(FodDataV40, AUTOMATIC, AUTOMATIC) SCI_FODMGR_FodDataValue;
  P2VAR(FodDetectTh, AUTOMATIC, AUTOMATIC) Value_6;
  FodDetectTh Value_5;
  P2VAR(FodDetectTh, AUTOMATIC, AUTOMATIC) Value_4;
  FodDetectTh Value_3;
  P2VAR(FodDetectTh, AUTOMATIC, AUTOMATIC) Value_2;
  FodDetectTh Value_1;
  P2VAR(FodDetectTh, AUTOMATIC, AUTOMATIC) Value_0;
  FodDetectTh Value;
  P2VAR(SftyBoolTF, AUTOMATIC, AUTOMATIC) SftyBoolValue_8;
  SftyBoolTF SftyBoolValue_7;
  P2VAR(SftyBoolTF, AUTOMATIC, AUTOMATIC) SftyBoolValue_6;
  SftyBoolTF SftyBoolValue_5;
  P2VAR(SftyBoolTF, AUTOMATIC, AUTOMATIC) SftyBoolValue_4;
  SftyBoolTF SftyBoolValue_3;
  P2VAR(SftyBoolTF, AUTOMATIC, AUTOMATIC) SftyBoolValue_2;
  SftyBoolTF SftyBoolValue_1;
  P2VAR(SftyBoolTF, AUTOMATIC, AUTOMATIC) SftyBoolValue_0;
  SftyBoolTF SftyBoolValue;
  P2VAR(SftyBoolOO, AUTOMATIC, AUTOMATIC) SCI_FODMGR_SftyOnOffValue_0;
  SftyBoolOO SCI_FODMGR_SftyOnOffValue;
  GenericByte NvFlag_0;
  GenericByte NvFlag;
  Std_ReturnType status;

  NvFlag = Rte_IrvRead_WsFodMgr_MainFunction_NvFlag();

  Rte_IrvWrite_WsFodMgr_MainFunction_NvFlag(NvFlag_0);

  Rte_IWrite_WsFodMgr_MainFunction_PP_ForeignObjectDetected_SCI_FODMGR_SftyOnOffValue(&SCI_FODMGR_SftyOnOffValue);

  SCI_FODMGR_SftyOnOffValue_0 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_ForeignObjectDetected_SCI_FODMGR_SftyOnOffValue();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckDuringChrg_SftyBoolValue(&SftyBoolValue);

  SftyBoolValue_0 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckDuringChrg_SftyBoolValue();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckStartUpChrg_SftyBoolValue(&SftyBoolValue_1);

  SftyBoolValue_2 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckStartUpChrg_SftyBoolValue();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckZMDown_SftyBoolValue(&SftyBoolValue_3);

  SftyBoolValue_4 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckZMDown_SftyBoolValue();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckZMUp_SftyBoolValue(&SftyBoolValue_5);

  SftyBoolValue_6 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckZMUp_SftyBoolValue();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodPreCheck_SftyBoolValue(&SftyBoolValue_7);

  SftyBoolValue_8 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodPreCheck_SftyBoolValue();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckDuringChrgTh_Value(Value);

  Value_0 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckDuringChrgTh_Value();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckZMDownTh_Value(Value_1);

  Value_2 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckZMDownTh_Value();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodCheckZMUpTh_Value(Value_3);

  Value_4 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodCheckZMUpTh_Value();

  Rte_IWrite_WsFodMgr_MainFunction_PP_FodPreCheckTh_Value(Value_5);

  Value_6 = Rte_IWriteRef_WsFodMgr_MainFunction_PP_FodPreCheckTh_Value();

  SCI_FODMGR_FodDataValue = Rte_IRead_WsFodMgr_MainFunction_RP_FodData_SCI_FODMGR_FodDataValue();

  ResDataVal = Rte_IRead_WsFodMgr_MainFunction_RP_ResData_ResDataVal();

  DiagCtrlFod = Rte_IRead_WsFodMgr_MainFunction_WspDiagCtrl_cmdFodActivate_DiagCtrlFod();

  DiagCtrlFreeze = Rte_IRead_WsFodMgr_MainFunction_WspDiagCtrl_cmdFodFreeze_DiagCtrlFreeze();

  status = Rte_Call_RP_NvMService_GetErrorStatus(&RequestResultPtr);

  status = Rte_Call_RP_NvMService_SetDataIndex(DataIndex);

  status = Rte_Call_RP_NvMService_GetDataIndex(&DataIndexPtr);

  status = Rte_Call_RP_NvMService_SetRamBlockStatus(BlockChanged);

  status = Rte_Call_RP_NvMService_ReadBlock(DstPtr);

  status = Rte_Call_RP_NvMService_WriteBlock(SrcPtr);

  status = Rte_Call_RP_NvMService_RestoreBlockDefaults(DstPtr_0);

  status = Rte_Call_RP_NvMService_InvalidateNvBlock();

  status = Rte_Call_Event_METAL_ON_PAD_SetEventStatus(EventStatus);

  status = Rte_Call_Event_METAL_ON_PAD_ResetEventStatus();

  status = Rte_Call_Event_METAL_ON_PAD_GetEventStatus(&EventStatusExtended);

  status = Rte_Call_Event_METAL_ON_PAD_GetEventFailed(&EventFailed);

  status = Rte_Call_Event_METAL_ON_PAD_GetEventTested(&EventTested);

  status = Rte_Call_Event_METAL_ON_PAD_GetDTCOfEvent(DTCKind, &DTCofEvent);

  status = Rte_Call_Event_METAL_ON_PAD_PrestoreFreezeFrame();

  status = Rte_Call_Event_METAL_ON_PAD_ClearPrestoredFreezeFrame();

  status = Rte_Call_Event_METAL_ON_PAD_GetFaultDetectionCounter(&EventIdFaultDetectionCounter);

  status = Rte_Call_alive_WdgMSvEnt_FodMgr_CheckpointReached(CheckpointId);

  status = Rte_Call_alive_WdgMSvEnt_FodMgr_UpdateAliveCounter();

}

void WsFodMgr_NullVector_Start (GenericByte trigger, P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) result)
{
  GenericByte NvFlag_0;
  GenericByte NvFlag;
  Std_ReturnType status;

  NvFlag = Rte_IrvRead_WsFodMgr_NullVector_Start_NvFlag();

  Rte_IrvWrite_WsFodMgr_NullVector_Start_NvFlag(NvFlag_0);

}

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------

  ------------------------[per instance memory API]--------------------------

*/
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

