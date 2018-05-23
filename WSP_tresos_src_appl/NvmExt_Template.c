
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
  * on Fri Feb 09 11:09:51 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

#include "Rte_NvmExt.h"

/*------------------------[runnable entity skeletons]------------------------*/

void NvmExt_NvmExtMain (void)
{
  Std_ReturnType status;

}

Std_ReturnType NvmExt_Read (uint16 Index, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Status)
{
  Std_ReturnType status;

  Rte_Enter_NvMExtJobHandling();

  Rte_Exit_NvMExtJobHandling();

  return status;
}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
Std_ReturnType NvmExt_Write (uint16 Index, P2CONST(GenericArray, AUTOMATIC, RTE_APPL_CONST) Data, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Status)
#else
Std_ReturnType NvmExt_Write (uint16 Index, P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) Data, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Status)
#endif
{
  Std_ReturnType status;

  Rte_Enter_NvMExtJobHandling();

  Rte_Exit_NvMExtJobHandling();

  return status;
}

Std_ReturnType NvmExt_DiagRead (uint16 Index, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  Std_ReturnType status;

  Rte_Enter_NvMExtJobHandling();

  Rte_Exit_NvMExtJobHandling();

  return status;
}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
Std_ReturnType NvmExt_DiagWrite (uint16 Index, P2CONST(GenericArray, AUTOMATIC, RTE_APPL_CONST) Data, uint16 DataLength, P2VAR(NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
#else
Std_ReturnType NvmExt_DiagWrite (uint16 Index, P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) Data, uint16 DataLength, P2VAR(NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
#endif
{
  Std_ReturnType status;

  Rte_Enter_NvMExtJobHandling();

  Rte_Exit_NvMExtJobHandling();

  return status;
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
