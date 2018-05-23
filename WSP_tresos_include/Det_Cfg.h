#ifndef DET_CFG_H
#define DET_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR Det
 *
 * This file contains the implementation of the AUTOSAR
 * module Det.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */






/*==================[includes]==============================================*/

/*==================[macros]================================================*/

#define DET_SERVICE_API_NONE   0
#define DET_SERVICE_API_ASR32 32
#define DET_SERVICE_API_ASR40 40

#if (defined DET_ENABLE_ASR32_SERVICE_API) /* To prevent double declaration */
#error DET_ENABLE_ASR32_SERVICE_API already defined
#endif /* if (defined DET_ENABLE_ASR32_SERVICE_API) */

/** \brief Definition whether AUTOSAR 3.2 service API is enabled **/
#define DET_ENABLE_ASR32_SERVICE_API                   STD_OFF


#if (defined DET_ENABLE_ASR40_SERVICE_API) /* To prevent double declaration */
#error DET_ENABLE_ASR40_SERVICE_API already defined
#endif /* if (defined DET_ENABLE_ASR40_SERVICE_API) */

/** \brief Definition whether AUTOSAR 4.0 service API is enabled **/
#define DET_ENABLE_ASR40_SERVICE_API                   STD_OFF


#if (defined DET_DEFAULT_ASR_SERVICE_API) /* To prevent double declaration */
#error DET_DEFAULT_ASR_SERVICE_API already defined
#endif /* if (defined DET_DEFAULT_ASR_SERVICE_API) */

/** \brief Definition of default service API **/
#define DET_DEFAULT_ASR_SERVICE_API                    DET_SERVICE_API_ASR40



/** \brief Version info API availabiliity
 **
 ** En- or diasable the availability of Det_GetVersionInfo() */
#define DET_VERSION_INFO_API                STD_ON

/** \brief Rte usage
 **
 ** En- or disables the usage of the Rte for the Det */
#define DET_RTE_USAGE                       STD_ON

/** \brief Internal logging mode
 **
 ** Errors are logged in an internal circular buffer. */
#define DET_LOGMODE_INTERNAL                1U
/** \brief Breakpoint mode
 **
 ** If an error is reported the system hals at a break point and the user can
 ** analyse the situation in a debugger/emulator. */
#define DET_LOGMODE_BREAKPOINT              2U

/** \brief Error logging mode
 **
 ** Defines the mode how errors are logged. Only one of the following modes
 ** can be active. Possible modes: ::DET_LOGMODE_INTERNAL,
 ** ::DET_LOGMODE_BREAKPOINT */
#define DET_LOGMODE                         DET_LOGMODE_BREAKPOINT



/*------------------[defensive programming]---------------------------------*/

#if (defined DET_DEFENSIVE_PROGRAMMING_ENABLED)
#error DET_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif

/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming handling by the
 ** Det */
#define DET_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined DET_PRECONDITION_ASSERT_ENABLED)
#error DET_PRECONDITION_ASSERT_ENABLED is already defined
#endif

/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion check handling by the
 ** Det */
#define DET_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined DET_POSTCONDITION_ASSERT_ENABLED)
#error DET_POSTCONDITION_ASSERT_ENABLED is already defined
#endif

/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion check handling by the
 ** Det */
#define DET_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined DET_STATIC_ASSERT_ENABLED)
#error DET_STATIC_ASSERT_ENABLED is already defined
#endif

/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion check handling by the Det */
#define DET_STATIC_ASSERT_ENABLED           STD_OFF

#if (defined DET_UNREACHABLE_CODE_ASSERT_ENABLED)
#error DET_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif

/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion check handling by
 ** the Det */
#define DET_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined DET_INVARIANT_ASSERT_ENABLED)
#error DET_INVARIANT_ASSERT_ENABLED is already defined
#endif

/** \brief Invariant code assertion usage
 **
 ** En- or disables the usage of invariant assertion check handling */
#define DET_INVARIANT_ASSERT_ENABLED        STD_OFF

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
#endif /* if !defined( DET_CFG_H ) */
