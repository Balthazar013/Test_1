/**
 * \file
 *
 * \brief AUTOSAR EcuM_Callouts
 *
 * This file contains the implementation of the callouts for the AUTOSAR
 * EcuM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef ECUM_CALLOUTS_H
#define ECUM_CALLOUTS_H

/*==================[includes]==============================================*/
#include <TSAutosar.h>     /* EB specific standard types */

/*==================[external function definitions]=========================*/

void EcuM_Callout_DriverInitListOne(void);
void EcuM_Callout_DriverInitListTwo(void);
void EcuM_Callout_BswM_RequestSTARTUP_TWO_AaB(void);
void Appl_EcuM_currentMode_currentMode(EcuM_ModeType modeEvent_u8);

/*==================[internal function definitions]=========================*/

#endif /* ifndef BSWM_USERCALLOUTS_H */

/*==================[end of file]===========================================*/

