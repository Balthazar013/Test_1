
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
  * on Fri Feb 09 11:09:50 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

#include "Rte_SwCVoltageMonitor.h"

/*------------------------[runnable entity skeletons]------------------------*/

void VM_Main (void)
{
  uint8 VMModFAULT_BATTERY_VOLTAGE_UPPER_0;
  uint8 VMModFAULT_BATTERY_VOLTAGE_LOWER_0;
  uint8 VMModFAULT_BATTERY_VOLTAGE_UPPER;
  uint8 VMModFAULT_BATTERY_VOLTAGE_LOWER;
  uint16 value;
  Dem_EventStatusType EventStatus_0;
  Dem_EventStatusType EventStatus;
  Std_ReturnType status;

  status = Rte_Call_Event_FAULT_BATTERY_VOLTAGE_LOWER_SetEventStatus(EventStatus);

  status = Rte_Call_Event_FAULT_BATTERY_VOLTAGE_UPPER_SetEventStatus(EventStatus_0);

  status = Rte_Call_VMKl30Sense_Get(&value);

  status = Rte_Switch_VMModFAULT_BATTERY_VOLTAGE_LOWER_VoltageMonitorMode(VMModFAULT_BATTERY_VOLTAGE_LOWER);

  status = Rte_Switch_VMModFAULT_BATTERY_VOLTAGE_UPPER_VoltageMonitorMode(VMModFAULT_BATTERY_VOLTAGE_UPPER);

  VMModFAULT_BATTERY_VOLTAGE_LOWER_0 = Rte_Mode_VMModFAULT_BATTERY_VOLTAGE_LOWER_VoltageMonitorMode();

  VMModFAULT_BATTERY_VOLTAGE_UPPER_0 = Rte_Mode_VMModFAULT_BATTERY_VOLTAGE_UPPER_VoltageMonitorMode();

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
