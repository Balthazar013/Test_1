#if !defined(RTE_CBK_H)
#define RTE_CBK_H

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
  * This file contains Rte callback declarations
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.75
  * on Fri Feb 09 11:09:49 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define RTE_START_SEC_CODE
#include "MemMap.h"

/*------------------[COM callbacks]------------------------------------------*/
FUNC(void, RTE_CODE) Rte_COMCbk_Com_COM_AB_Deaktivierung_HV__DEV_AWC_Resp_50__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_COM_AB_Deaktivierung_HV__DEV_AWC_Resp_50__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_COM_AWC_Poshilfe__DEV_AWC_Resp_51__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_COM_AWC_Poshilfe__DEV_AWC_Resp_51__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_COM_AWC_Fehlerstatus__DEV_AWC_Resp_52__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_COM_AWC_Fehlerstatus__DEV_AWC_Resp_52__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_COM_AWC_IstSpannung__DEV_AWC_Resp_53__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_COM_AWC_IstSpannung__DEV_AWC_Resp_53__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_COM_DGN_Verlernzaehler__DEV_AWC_Resp_54__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_COM_DGN_Verlernzaehler__DEV_AWC_Resp_54__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_COM_AWC_EVCCID__DEV_AWC_Resp_55__MLBevo_HCAN(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_COM_AWC_EVCCID__DEV_AWC_Resp_55__MLBevo_HCAN(void);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/
/** @} doxygen end group definition */
#endif /* !defined(RTE_CBK_H) */
/*==================[end of file]============================================*/

