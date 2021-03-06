
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

#include "Rte_SbcMC33xxCdd.h"

/*------------------------[runnable entity skeletons]------------------------*/

void SbcMC33xxCdd_10ms (void)
{
  Dem_EventStatusType EventStatus;
  Dem_FaultDetectionCounterType EventIdFaultDetectionCounter;
  boolean EventTested;
  Dem_EventStatusExtendedType EventStatusExtended;
  boolean EventFailed;
  Dem_DTCType DTCofEvent;
  Dem_DTCKindType DTCKind;
  Std_ReturnType status;

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_ClearPrestoredFreezeFrame();

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_GetDTCOfEvent(DTCKind, &DTCofEvent);

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_GetEventFailed(&EventFailed);

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_GetEventStatus(&EventStatusExtended);

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_GetEventTested(&EventTested);

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_GetFaultDetectionCounter(&EventIdFaultDetectionCounter);

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_PrestoreFreezeFrame();

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_ResetEventStatus();

  status = Rte_Call_Event_SBC_SPI_COMMUNICATION_TIMEOUT_SetEventStatus(EventStatus);

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

