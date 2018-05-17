/** \brief Shared RAM data between bootloader and application
 **
 ** \project vsc_bootloader
 ** \file
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** \controller independent
 ** \compiler independent
 ** \hardware independent
 **
 ** Copyright 2011 by EB - Elektrobit Automotive GmbH
 ** All rights exclusively reserved for EB - Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise
 **/

/*==================[inclusions]=============================================*/

#include <RamSharedData.h>

/*==================[macros]=================================================*/
/*==================[type definitions]=======================================*/
/*==================[internal function declarations]=========================*/
/*==================[internal constants]=====================================*/
/*==================[internal data]==========================================*/
/*==================[external constants]=====================================*/
/*==================[external data]==========================================*/

#define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#pragma ghs section bss=".NOINIT_RAM"
VAR(Ram_SharedDataType, BL_VAR) RSD_RamSharedData;
#pragma ghs section bss=default

#define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[external function definitions]==========================*/
/*==================[internal function definitions]==========================*/
/*==================[end of file]============================================*/
