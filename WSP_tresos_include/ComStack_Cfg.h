/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined COMSTACK_CFG_H)
#define COMSTACK_CFG_H






/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[Size of Autosar Comstack Types]-------------------------*/

#if (defined TS_SIZE_PduIdType)
#error TS_SIZE_PduIdType already defined
#endif
/** \brief Size of AUTOSAR standard type PduIdType */
#define TS_SIZE_PduIdType 2U

#if (defined TS_SIZE_PduLengthType)
#error TS_SIZE_PduLengthType already defined
#endif
/** \brief Size of AUTOSAR standard type PduLengthType */
#define TS_SIZE_PduLengthType 2U

/*==================[type definitions]======================================*/

/* this type can be configured:
 * - uint8 or uint16
 * - range: 0 .. PduIdmax
 */
/** \brief Type for a unique identifier for a PDU */
typedef uint16 PduIdType;

/* this type can be configured:
 * - uint8/uint16/uint32
 * - range: 0 .. PduLengthmax
 */
/** \brief Type for lengths information of a PDU */
typedef uint16 PduLengthType;

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( COMSTACK_CFG_H ) */
/*==================[end of file]============================================*/
