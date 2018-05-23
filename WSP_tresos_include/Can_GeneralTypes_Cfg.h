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

#if (!defined CAN_GENERALTYPES_CFG_H)
#define CAN_GENERALTYPES_CFG_H

/*==================[inclusions]=============================================*/

#include <Std_Types.h>          /* AUTOSAR standard type definitions */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/** \brief Represents the hardware object handles of a CAN hardware unit. For
 **        CAN hardware units with more than 255 HW objects use extended range.
 */
typedef uint8 Can_HwHandleType;


/** \brief Represents the Identifier of an L-PDU. For extended IDs the most
 **        significant bit is set.
 */
typedef uint32 Can_IdType;

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
#endif /* if !defined( CAN_GENERALTYPES_CFG_H ) */
