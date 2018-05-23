/**
 * \file
 *
 * \brief AUTOSAR NvM
 *
 * This file contains the implementation of the AUTOSAR
 * module NvM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if ( !defined NVM_TYPES_H )
#define NVM_TYPES_H

/*==================[inclusions]============================================*/

#include <TSAutosar.h>            /* EB specific standard types      */
/* !LINKSTO NVM690,1 */
#include <Std_Types.h>            /* AUTOSAR standard types. NVM550 */
#include <NvM_BSW_Types.h>

/* !LINKSTO NVM755,1 */
#include <Rte_NvM_Type.h>    /* Rte type definitions. */

/*==================[type definitions]======================================*/


/**  \brief Defines the NVRAM block initialization call back function.
 **         It is called if data from NVRAM is not readable.
 **/
typedef P2FUNC( Std_ReturnType,NVM_CODE,NvM_InitBlockCallbackType )( void );

/**  \brief Defines the NVRAM block error status callback function.
 **         It is called if a asynchronous NvM API request has finished.
 **/
typedef P2FUNC( Std_ReturnType,NVM_CODE,NvM_SingleBlockCallbackType )
              ( uint8 ServiceId, NvM_RequestResultType JobResult );

/**  \brief Defines the NVRAM multi request callback function.
 **         It is called if the NvM multiblock requests
 **         NvM_WriteAll() or NvM_ReadAll() is finished.
 **/
typedef P2FUNC( void,NVM_CODE,NvM_MultiBlockCallbackType )
              ( uint8 ServiceId, NvM_RequestResultType JobResult );



/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* NVM_TYPES_H */

/*=========================[end of file NvM_Types.h]========================*/
