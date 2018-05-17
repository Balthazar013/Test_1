/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef NVM_INCLUDE_H
#define NVM_INCLUDE_H


/*==================[includes]==============================================*/

#include <Base_Modules.h>               /* Module enable defines */

#ifdef BASE_DEM_ENABLED
#include <Dem.h>                        /* Dem has an RAM block */
#endif

#ifdef BASE_COMM_ENABLED
#include <ComM.h>                       /* ComM has an RAM block */
#endif

#include "NvmData.h"

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/* multi block request callback called by the NvM when NvM_ReadAll() or
   NvM_WriteAll() is finished */
extern FUNC(void, ECUM_APPL_CODE) EcuM_CB_NfyNvMJobEnd
(
    uint8                 ServiceId,
    NvM_RequestResultType JobResult
);

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef NVM_INCLUDE_H */

/*==================[end of file]===========================================*/
