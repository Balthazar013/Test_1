
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
  * on Fri Feb 09 11:09:49 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

#include "Rte_SwCCanMonitor.h"

/*------------------------[runnable entity skeletons]------------------------*/

void CanMonitor_SelfDiagInit (void)
{
  Std_ReturnType status;

}

void CanMonitor_SelfDiagMonitor (void)
{
  boolean EventFailed_5;
  boolean ConditionFulfilled_5;
  boolean EventFailed_4;
  boolean ConditionFulfilled_4;
  boolean EventFailed_3;
  boolean ConditionFulfilled_3;
  boolean EventFailed_2;
  boolean ConditionFulfilled_2;
  boolean EventFailed_1;
  boolean ConditionFulfilled_1;
  boolean EventFailed_0;
  boolean ConditionFulfilled_0;
  boolean EventFailed;
  boolean ConditionFulfilled;
  uint16 mV_Value;
  boolean kl15_status;
  uint8 Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN;
  uint8 Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN;
  uint16 Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN;
  uint8 Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN;
  uint8 Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN;
  uint8 Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN;
  Std_ReturnType status;

  Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN = Rte_IRead_SelfDiagMonitor_Pdu_DEV_AWC_Resp_50_MLBevo_HCAN_Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN();

  status = Rte_IStatus_SelfDiagMonitor_Pdu_DEV_AWC_Resp_50_MLBevo_HCAN_Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN();

  Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN = Rte_IRead_SelfDiagMonitor_Pdu_DEV_AWC_Resp_51_MLBevo_HCAN_Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN();

  status = Rte_IStatus_SelfDiagMonitor_Pdu_DEV_AWC_Resp_51_MLBevo_HCAN_Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN();

  Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN = Rte_IRead_SelfDiagMonitor_Pdu_DEV_AWC_Resp_52_MLBevo_HCAN_Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN();

  status = Rte_IStatus_SelfDiagMonitor_Pdu_DEV_AWC_Resp_52_MLBevo_HCAN_Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN();

  Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN = Rte_IRead_SelfDiagMonitor_Pdu_DEV_AWC_Resp_53_MLBevo_HCAN_Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN();

  status = Rte_IStatus_SelfDiagMonitor_Pdu_DEV_AWC_Resp_53_MLBevo_HCAN_Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN();

  Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN = Rte_IRead_SelfDiagMonitor_Pdu_DEV_AWC_Resp_54_MLBevo_HCAN_Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN();

  status = Rte_IStatus_SelfDiagMonitor_Pdu_DEV_AWC_Resp_54_MLBevo_HCAN_Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN();

  Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN = Rte_IRead_SelfDiagMonitor_Pdu_DEV_AWC_Resp_55_MLBevo_HCAN_Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN();

  status = Rte_IStatus_SelfDiagMonitor_Pdu_DEV_AWC_Resp_55_MLBevo_HCAN_Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN();

  kl15_status = Rte_IRead_SelfDiagMonitor_Kl15_Status_kl15_status();

  mV_Value = Rte_IRead_SelfDiagMonitor_KL30_mV_Value();

  status = Rte_Call_EnableCond_CAN_TO_Pdu_DEV_AWC_Resp_50_MLB_SetEnableCondition(ConditionFulfilled);

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_50_MLBevo_HCAN_GetEventFailed(&EventFailed);

  status = Rte_Call_EnableCond_CAN_TO_Pdu_DEV_AWC_Resp_51_MLB_SetEnableCondition(ConditionFulfilled_0);

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_51_MLBevo_HCAN_GetEventFailed(&EventFailed_0);

  status = Rte_Call_EnableCond_CAN_TO_Pdu_DEV_AWC_Resp_52_MLB_SetEnableCondition(ConditionFulfilled_1);

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_52_MLBevo_HCAN_GetEventFailed(&EventFailed_1);

  status = Rte_Call_EnableCond_CAN_TO_Pdu_DEV_AWC_Resp_53_MLB_SetEnableCondition(ConditionFulfilled_2);

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_53_MLBevo_HCAN_GetEventFailed(&EventFailed_2);

  status = Rte_Call_EnableCond_CAN_TO_Pdu_DEV_AWC_Resp_54_MLB_SetEnableCondition(ConditionFulfilled_3);

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_54_MLBevo_HCAN_GetEventFailed(&EventFailed_3);

  status = Rte_Call_EnableCond_CAN_TO_Pdu_DEV_AWC_Resp_55_MLB_SetEnableCondition(ConditionFulfilled_4);

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_55_MLBevo_HCAN_GetEventFailed(&EventFailed_4);

  status = Rte_Call_EnableCond_BusOff_MLBevo_HCAN_SetEnableCondition(ConditionFulfilled_5);

  status = Rte_Call_Event_CANTO_BusOff_MLBevo_HCAN_GetEventFailed(&EventFailed_5);

}

void CanMonitor_RxTO_Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN (void)
{
  Dem_EventStatusType EventStatus;
  uint8 Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN;
  Std_ReturnType status;

  Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN = Rte_IRead_RxTO_Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN_Pdu_DEV_AWC_Resp_50_MLBevo_HCAN_Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN();

  status = Rte_IStatus_RxTO_Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN_Pdu_DEV_AWC_Resp_50_MLBevo_HCAN_Com_COM_AB_Deaktivierung_HV_DEV_AWC_Resp_50_MLBevo_HCAN();

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_50_MLBevo_HCAN_SetEventStatus(EventStatus);

}

void CanMonitor_RxTO_Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN (void)
{
  Dem_EventStatusType EventStatus;
  uint8 Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN;
  Std_ReturnType status;

  Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN = Rte_IRead_RxTO_Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN_Pdu_DEV_AWC_Resp_51_MLBevo_HCAN_Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN();

  status = Rte_IStatus_RxTO_Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN_Pdu_DEV_AWC_Resp_51_MLBevo_HCAN_Com_COM_AWC_Poshilfe_DEV_AWC_Resp_51_MLBevo_HCAN();

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_51_MLBevo_HCAN_SetEventStatus(EventStatus);

}

void CanMonitor_RxTO_Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN (void)
{
  Dem_EventStatusType EventStatus;
  uint8 Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN;
  Std_ReturnType status;

  Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN = Rte_IRead_RxTO_Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN_Pdu_DEV_AWC_Resp_52_MLBevo_HCAN_Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN();

  status = Rte_IStatus_RxTO_Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN_Pdu_DEV_AWC_Resp_52_MLBevo_HCAN_Com_COM_AWC_Fehlerstatus_DEV_AWC_Resp_52_MLBevo_HCAN();

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_52_MLBevo_HCAN_SetEventStatus(EventStatus);

}

void CanMonitor_RxTO_Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN (void)
{
  Dem_EventStatusType EventStatus;
  uint16 Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN;
  Std_ReturnType status;

  Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN = Rte_IRead_RxTO_Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN_Pdu_DEV_AWC_Resp_53_MLBevo_HCAN_Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN();

  status = Rte_IStatus_RxTO_Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN_Pdu_DEV_AWC_Resp_53_MLBevo_HCAN_Com_COM_AWC_IstSpannung_DEV_AWC_Resp_53_MLBevo_HCAN();

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_53_MLBevo_HCAN_SetEventStatus(EventStatus);

}

void CanMonitor_RxTO_Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN (void)
{
  Dem_EventStatusType EventStatus;
  uint8 Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN;
  Std_ReturnType status;

  Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN = Rte_IRead_RxTO_Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN_Pdu_DEV_AWC_Resp_54_MLBevo_HCAN_Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN();

  status = Rte_IStatus_RxTO_Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN_Pdu_DEV_AWC_Resp_54_MLBevo_HCAN_Com_COM_DGN_Verlernzaehler_DEV_AWC_Resp_54_MLBevo_HCAN();

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_54_MLBevo_HCAN_SetEventStatus(EventStatus);

}

void CanMonitor_RxTO_Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN (void)
{
  Dem_EventStatusType EventStatus;
  uint8 Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN;
  Std_ReturnType status;

  Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN = Rte_IRead_RxTO_Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN_Pdu_DEV_AWC_Resp_55_MLBevo_HCAN_Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN();

  status = Rte_IStatus_RxTO_Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN_Pdu_DEV_AWC_Resp_55_MLBevo_HCAN_Com_COM_AWC_EVCCID_DEV_AWC_Resp_55_MLBevo_HCAN();

  status = Rte_Call_Event_CANTO_Pdu_DEV_AWC_Resp_55_MLBevo_HCAN_SetEventStatus(EventStatus);

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

