#if (!defined PLATFORM_TYPES_H)
#define PLATFORM_TYPES_H


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

/*
 * MISRA-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 5.1 (required)
 *   Identifiers (internal and external) shall not rely on the significance of
 *   more then 31 characters.
 *
 *   Reason:
 *   The AUTOSAR specification requires the definition of the macros
 *   with overlong names.
 *
 * MISRA-2) Deviated Rule: 1.4 (required)
 *   The compiler/linker shall be checked to ensure that 31 character
 *   significance and case sensitivity are supported for external identifiers.
 *
 *   Reason:
 *   The AUTOSAR specification requires the definition of the macros
 *   with overlong names.
 *
 * MISRA-3) Deviated Rule: 6.3 (required)
 *   Typedefs that indicate size and signedness should be used in place
 *   of the basic types.
 *
 *   Reason:
 *   Such types need to be defined somewhere and this file provides the
 *   AUTOSAR type definitions with fixed size and signedness.
 */


 /* !LINKSTO PLATFORM001,1,
    !        PLATFORM003,1
    !description Header file Platform_Types.h containing platform types
  */

/*==================[inclusions]=============================================*/



/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined PLATFORM_VENDOR_ID)
#error PLATFORM_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: Elektrobit Automotive GmbH */
#define PLATFORM_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined PLATFORM_MODULE_ID)
#error PLATFORM_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define PLATFORM_MODULE_ID     199U
/*------------------[AUTOSAR release version identification]----------------*/

/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#if (defined PLATFORM_AR_RELEASE_MAJOR_VERSION)
#error PLATFORM_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION     4U

/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#if (defined PLATFORM_AR_RELEASE_MINOR_VERSION)
#error PLATFORM_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define PLATFORM_AR_RELEASE_MINOR_VERSION     0U

/* Deviation MISRA-1 */
/* Deviation MISRA-2 */
#if (defined PLATFORM_AR_RELEASE_REVISION_VERSION)
#error PLATFORM_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define PLATFORM_AR_RELEASE_REVISION_VERSION  3U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined PLATFORM_SW_MAJOR_VERSION)
#error PLATFORM_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define PLATFORM_SW_MAJOR_VERSION  2U

#if (defined PLATFORM_SW_MINOR_VERSION)
#error PLATFORM_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define PLATFORM_SW_MINOR_VERSION  5U

#if (defined PLATFORM_SW_PATCH_VERSION)
#error PLATFORM_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define PLATFORM_SW_PATCH_VERSION  0U

/*------------------[AUTOSAR module vendor API infix]------------------------*/

#if (defined PLATFORM_VENDOR_API_INFIX)
#error PLATFORM_VENDOR_API_INFIX already defined
#endif
/** \brief Vendor API infix
 *
 * Left empty as this header does not belong to any module */
#define PLATFORM_VENDOR_API_INFIX

/*------------------[global identifiers]-------------------------------------*/

/* !LINKSTO PLATFORM054,1 */
#if (!defined TRUE)
/* PLATFORM056 */
/** \brief true value for boolean type */
#define TRUE 1U
#endif

/* !LINKSTO PLATFORM054,1 */
#if (!defined FALSE)
/* PLATFORM056 */
/** \brief false value for boolean type */
#define FALSE 0U
#endif

/* !LINKSTO PLATFORM054,1 */
/* redefinition check may lead to an incorrect condition that
 * TRUE and FALSE are equal */
#if (TRUE == FALSE)
#error TRUE == FALSE is incorrect
#endif




/*------------------[CPU properties]-----------------------------------------*/

#if (defined CPU_TYPE_8)
#error CPU_TYPE_8 already defined
#endif
/* !LINKSTO PLATFORM057,1 */
/** \brief cpu identifier for  8-bit CPUs */
#define CPU_TYPE_8 8U

#if (defined CPU_TYPE_16)
#error CPU_TYPE_16 already defined
#endif /* if (defined CPU_TYPE_16) */
/* !LINKSTO PLATFORM057,1 */
/** \brief cpu identifier for  8-bit CPUs */
#define CPU_TYPE_16 16U

#if (defined CPU_TYPE_32)
#error CPU_TYPE_32 already defined
#endif
/* !LINKSTO PLATFORM057,1 */
/** \brief cpu identifier for 32-bit CPUs */
#define CPU_TYPE_32 32U

#if (defined MSB_FIRST)
#error MSB_FIRST already defined
#endif
/** \brief identifier for 'high byte first' */
#define MSB_FIRST 0U

#if (defined LSB_FIRST)
#error LSB_FIRST already defined
#endif /* if (defined LSB_FIRST) */
/** \brief identifier for 'little endian' */
#define LSB_FIRST 1U

#if (defined HIGH_BYTE_FIRST)
#error HIGH_BYTE_FIRST already defined
#endif
/** \brief identifier for 'high byte first' */
#define HIGH_BYTE_FIRST 0U

#if (defined LOW_BYTE_FIRST)
#error LOW_BYTE_FIRST already defined
#endif
/** \brief cpu identifier for  8-bit CPUs */
#define LOW_BYTE_FIRST 1U


#if (defined CPU_TYPE)
#error CPU_TYPE already defined
#endif

/* !LINKSTO PLATFORM044,1,
   !        PLATFORM045,1
*/
/** \brief Word size of this CPU
 **
 ** The word size specifies the natural data unit size of a CPU
 **
 ** Possible values:
 **  - CPU_TYPE_32
 **  - CPU_TYPE_16
 **  - CPU_TYPE_8
 */
#define CPU_TYPE CPU_TYPE_32


/* !LINKSTO PLATFORM043,1,
   !        PLATFORM048,1,
   !        PLATFORM049,1,
   !        PLATFORM038,1
*/
#if (defined CPU_BIT_ORDER)
#error CPU_BIT_ORDER already defined
#endif

/** \brief Bit order of this CPU
 **
 ** Range:
 **  - LSB_FIRST
 **  - MSB_FIRST
 */
#define CPU_BIT_ORDER MSB_FIRST

/* PLATFORM039 */
/* PLATFORM046 */
/* PLATFORM050 */
/* PLATFORM051 */
#if (defined CPU_BYTE_ORDER)
#error CPU_BYTE_ORDER already defined
#endif


/** \brief Byte order of this CPU
 **
 ** Range:
 **  - HIGH_BYTE_FIRST
 **  - LOW_BYTE_FIRST
 */
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST



/*==================[type definitions]======================================*/

/* PLATFORM005,PLATFORM013,PLATFORM014,PLATFORM015,PLATFORM016,PLATFORM017,
 * PLATFORM018,PLATFORM020,PLATFORM021,PLATFORM022,PLATFORM023,PLATFORM024,
 * PLATFORM025,PLATFORM027,PLATFORM041,PLATFORM042,PLATFORM060 */
/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type boolean */
typedef unsigned char boolean;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type sint8 */
typedef signed char sint8;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type sint16 */
typedef signed short sint16;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type sint32 */
typedef signed long sint32;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type uint8 */
typedef unsigned char uint8;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type uint16 */
typedef unsigned short uint16;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type uint32 */
typedef unsigned long uint32;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type sint8_least */
typedef signed long sint8_least;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type sint16_least */
typedef signed long sint16_least;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type sint32_least */
typedef signed long sint32_least;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type uint8_least */
typedef unsigned long uint8_least;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type uint16_least */
typedef unsigned long uint16_least;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type uint32_least */
typedef unsigned long uint32_least;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type float32 */
typedef float float32;

/* Deviation MISRA-3 <+2> */
/** \brief Type definition of AUTOSAR standard type float64 */
typedef double float64;


/*==================[inclusions]=============================================*/

/* !LINKSTO Base.ConfigScheme.PlatformTypesGeneration,1 */

#endif /* if (!defined PLATFORM_TYPES_H) */
