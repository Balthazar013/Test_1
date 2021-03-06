
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
  * on Thu May 03 17:50:49 CEST 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

#include "Rte_Chronos.h"

/*------------------------[runnable entity skeletons]------------------------*/

void Chronos_now (P2VAR(Timestamp, AUTOMATIC, RTE_APPL_DATA) timestamp)
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void Chronos_pack (P2CONST(Timestamp, AUTOMATIC, RTE_APPL_CONST) timestamp, P2VAR(TimestampBuffer, AUTOMATIC, RTE_APPL_DATA) buffer)
#else
void Chronos_pack (P2CONST(Timestamp, AUTOMATIC, RTE_APPL_CONST) timestamp, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) buffer)
#endif
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void Chronos_unpack (P2VAR(Timestamp, AUTOMATIC, RTE_APPL_DATA) timestamp, P2CONST(TimestampBuffer, AUTOMATIC, RTE_APPL_CONST) buffer)
#else
void Chronos_unpack (P2VAR(Timestamp, AUTOMATIC, RTE_APPL_DATA) timestamp, P2CONST(uint8, AUTOMATIC, RTE_APPL_CONST) buffer)
#endif
{
  Std_ReturnType status;

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

