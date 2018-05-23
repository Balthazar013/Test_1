/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DEM_CFG_H)
#define DEM_CFG_H

/* This file contains all target independent public configuration declarations
 * for the AUTOSAR module Dem. */


/*------------------[Events configuration]----------------------------------*/
















/*==================[includes]==============================================*/

#include <Dem_Types.h>
#include <Dem_IntErrId.h>                           /* BSW Event ID symbols */
#include <Dem_IntEvtId.h>                          /* SW-C Event ID symbols */
#include <Dcm.h>     /* has to be included for Dcm_NegativeResponseCodeType */


/* !LINKSTO vsc_Dem_445_MQB_MLB, 1 */
#include <Rte_Dem_Type.h> 

/*==================[macros]================================================*/

#if (defined DEM_IN_POINTER)
#error DEM_IN_POINTER already defined
#endif

/**brief type of a IN argument of a C/S interface */
#define DEM_IN_POINTER P2CONST


/*------------------[Wrapper Macros]----------------------------------------*/

#if (defined DEM_DEH_NUM_OF_DID)
#error DEM_DEH_NUM_OF_DID already defined
#endif
#if (defined DEM_DEH_STD_FF_POSITION)
#error DEM_DEH_STD_FF_POSITION already defined
#endif
#if (defined DEM_DEH_NUM_OF_ADD_FF)
#error DEM_DEH_NUM_OF_ADD_FF already defined
#endif
#if (defined DEM_DEH_STD_FF_POSITION_NOT_DEFINED)
#error DEM_DEH_STD_FF_POSITION_NOT_DEFINED already defined
#endif


/** \brief Number of configured DIDs */
#define DEM_DEH_NUM_OF_DID    (2u)

/** \brief Posistion of Standard Freeze Frame in Dem_DEH_DidArray */
#define DEM_DEH_STD_FF_POSITION  (DEM_DEH_NUM_OF_DID -1)

/** \brief Number configured Freeze Frames */
#define DEM_DEH_NUM_OF_ADD_FF  (DEM_DEH_NUM_OF_DID -1)
/*------------------[NVRAM]------------------------------------------------------*/
/* data declaration for RAM Area for Error Memory and Status Of DTC data         */

#if (defined DEM_EVENT_MEMORY_RAM_SIZE)
#error DEM_EVENT_MEMORY_RAM_SIZE already defined
#endif
/** \brief Size of the global RAM array for the event memory data (freeze frames, OCC ...).
           This array must be configured in the NVM.
           The size depends on the NVRAM block definition. */
#define DEM_EVENT_MEMORY_RAM_SIZE 1176U

#if (defined DEM_ST_OF_DTC_MEMORY_RAM_SIZE)
#error DEM_ST_OF_DTC_MEMORY_RAM_SIZE already defined
#endif
/** \brief Size of the global RAM array for the status bytes of the events.
           This array must be configured in the NVM.
           The size depends on the NVRAM block definition. */
#define DEM_ST_OF_DTC_MEMORY_RAM_SIZE 60U

#if (defined DEM_NVRAM_STATUS_OF_DTC_BLOCK_ID)
#error DEM_NVRAM_STATUS_OF_DTC_BLOCK_ID already defined
#endif
/** \brief ID of the NvM block which contains the status bytes for the events */
#define DEM_NVRAM_STATUS_OF_DTC_BLOCK_ID 2U

#if (defined DEM_NVRAM_EVENT_MEMORY_BLOCK_ID)
#error DEM_NVRAM_EVENT_MEMORY_BLOCK_ID already defined
#endif
/** \brief ID of the NvM block which contains the event memory data
 */
#define DEM_NVRAM_EVENT_MEMORY_BLOCK_ID 3U

#if (defined DEM_NVRAM_SUPERVISION_CYCLE_BLOCK_ID)
#error DEM_NVRAM_SUPERVISION_CYCLE_BLOCK_ID already defined
#endif
/** \brief ID of the NvM block which contains the event memory data
 */
#define DEM_NVRAM_SUPERVISION_CYCLE_BLOCK_ID U

#if (defined DEM_IMMEDIATE_NV_STORAGE)
#error DEM_IMMEDIATE_NV_STORAGE already defined
#endif
/** \brief Switch to activate immediate NvM block storage mechanism
 */
#define DEM_IMMEDIATE_NV_STORAGE         STD_ON

#if (defined DEM_STORE_EVENT_MEMORY_ON_SHUTDOWN)
#error DEM_STORE_EVENT_MEMORY_ON_SHUTDOWN already defined
#endif
/** \brief Switch to activate the persistent storage of the NvM blocks
           EVENT_MEMORY, STATUS_OF_DTC_MEMORY and SUPERVISION_CYCLE_MEMORY 
           during shutdown
 */
#define DEM_STORE_EVENT_MEMORY_ON_SHUTDOWN         STD_ON

#if (defined DEM_NVM_REQUEST_RESULT_TYPE)
#error DEM_NVM_REQUEST_RESULT_TYPE already defined
#endif /* #if (defined DEM_NVM_REQUEST_RESULT_TYPE) */

/** \brief Configured type of pointer where the request result of 
           NvM_GetErrorStatus function is stored. */
/* !LINKSTO vsc_Dem_453_MQB_MLB, 1 */
#define DEM_NVM_REQUEST_RESULT_TYPE NvM_RequestResultType

#if (defined DEM_PROVIDE_DUMMY_ASR4_VERSION_INFO)
#error DEM_PROVIDE_DUMMY_ASR4_VERSION_INFO already defined
#endif /* #if (defined DEM_PROVIDE_DUMMY_ASR4_VERSION_INFO) */

/** \brief Switch to include dummy AUTOSAR 4.0.3 version information */
#define DEM_PROVIDE_DUMMY_ASR4_VERSION_INFO STD_ON

/*------------------[General]-----------------------------------------------*/

#if (defined DEM_DEV_ERROR_DETECT)
#error DEM_DEV_ERROR_DETECT already defined
#endif
/** \brief Switch, indicating if development error detection is activated for
 ** DEM
 */
#define DEM_DEV_ERROR_DETECT         STD_ON

#if (defined DEM_USE_SET_AGING_COUNTER_API)
#error DEM_USE_SET_AGING_COUNTER_API already defined
#endif
/** \brief Switch to activate Dem_SetAgingCycleCounterValue
 */
#define DEM_USE_SET_AGING_COUNTER_API         STD_ON

/*------------------[Add Freeze frame configuration]------------------------*/
#if (defined DEM_DEH_APL_READADDFF_OF_WRAPPER)
#error DEM_DEH_APL_READADDFF_OF_WRAPPER already defined
#endif
/** \brief Switch to activate DEM_DEH_APL_READADDFF_OF_WRAPPER
 ** If DEM_DEH_APL_READADDFF_OF_WRAPPER is STD_ON, the implemented function APL_DEH_ReadAddFF
 ** will be used. If the DEM_DEH_APL_READADDFF_OF_WRAPPER is STD_OFF, the integrator has to implement
 ** the function APL_DEH_ReadAddFF.
 */

#define DEM_DEH_APL_READADDFF_OF_WRAPPER         STD_OFF

/*------------------[Freeze frame configuration]----------------------------*/

#if (defined DEM_MAX_NUMBER_PRESTORED_FF)
#error DEM_MAX_NUMBER_PRESTORED_FF already defined
#endif
/** \brief Maximum number of available prestored freeze frames
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 */
#define DEM_MAX_NUMBER_PRESTORED_FF 0U

/*------------------[FiM activation for DEM - configuration]----------------------------*/
#if (defined DEM_TRIGGER_FIM_REPORTS)
#error DEM_TRIGGER_FIM_REPORTS already defined
#endif
/** \brief Switch, indicating if notification to FiM is activated for Dem */
#define DEM_TRIGGER_FIM_REPORTS      STD_ON

/*------------------[Memory size configuration]-----------------------------*/

#if (defined DEM_BSW_ERROR_BUFFER_SIZE)
#error DEM_BSW_ERROR_BUFFER_SIZE already defined
#endif
/** \brief Maximal number of error-queue entries
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 */
#define DEM_BSW_ERROR_BUFFER_SIZE 5U


#if (defined DEM_SUPERVISION_BLOCK_SIZE)
#error DEM_SUPERVISION_BLOCK_SIZE already defined
#endif
/** \brief Supervision Cycle RAM block size
 **
 ** \note Includes storage space for CRC depending on NvM configuration.
 */

/*------------------[Events configuration]----------------------------------*/


#if (defined DEM_NUMBER_OF_EVENTS)
#error DEM_NUMBER_OF_EVENTS already defined
#endif
/** \brief Number of events which are present in the system
 **
 ** Number of events as given in the configuration
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
          First event ID is 0 because the first event ID of the DEH is 0 too.
 */
#define DEM_NUMBER_OF_EVENTS 176U


#if (defined DEM_NUMBER_OF_INVALID_EVENTS)
#error DEM_NUMBER_OF_INVALID_EVENTS already defined
#endif
/** \brief Number of invalid events which are present in the BSW
 **
 ** Number of invalid events as given in the configuration
 */
#define DEM_NUMBER_OF_INVALID_EVENTS 0U

/*------------------[DemCallbackEventStatusChanged]---------------------------*/
#if (defined DEM_NUM_EV_STATUSCHANGECALLOUT)
#error DEM_NUM_EV_STATUSCHANGECALLOUT already defined
#endif
/** \brief Number of Events with at least one DemCallbackEvenStatusChangedFnc */
#define DEM_NUM_EV_STATUSCHANGECALLOUT 0U

/*------------------[DemECNoIgnore]---------------------------*/
#if (defined DEM_NUM_EV_ECNOIGNORE)
#error DEM_NUM_EV_ECNOIGNORE already defined
#endif
/** \brief Number of Events with ECNoIgnore configure to true */
#define DEM_NUM_EV_ECNOIGNORE 0U

/*------------------[AUTOSAR event ID declaration]--------------------------*/

#if (defined DEM_EVENT_ID_INVALID) /* to prevent double declaration */
#error DEM_EVENT_ID_INVALID already defined
#endif /* if (defined DEM_EVENT_ID_INVALID) */

#define DEM_EVENT_ID_INVALID DEM_INVALID_EVENT_ID_BSW

/*------------------[Pending Bit support configuration]----------------------*/

#define DEM_DEH_USE_STATUSOFDTC_PENDING_BIT STD_OFF

/*------------[Extended Freeze Frames application support configuration]-----*/
/** \brief Enable wrapper support for Extended FreezeFrames
 **
 ** If enabled the wrapper functions are used to map the SWC port interface
 ** to the DEH callbacks. If the port interface is disabled no wrapper functions
 ** are used, the user has to provide the standard DEH callback functions
 ** in integration code.
 **/

#define DEM_RTE_DEH_EXT_FF_APL_SUP STD_OFF

/*------------------[Warning indicators configuration]----------------------*/

/* Symbolic names of configured warning indicator IDs */


#if (defined DEM_NUMBER_OF_INDICATORS)
#error DEM_NUMBER_OF_INDICATORS already defined
#endif
/** \brief Number of warning indicators which are present in the system
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS. */
#define DEM_NUMBER_OF_INDICATORS 0U

/** \brief Flag to enable / disable warning indicator wrapper functions.
 */

#define DEM_DEH_SET_WARNING_INDICATOR_REQ STD_OFF

/*------------------[Enable conditions configuration]-----------------------*/

/* Symbolic names of configured enable conditions */

#if (defined DEM_NUM_ENABLECONDITIONS)
#error DEM_NUM_ENABLECONDITIONS already defined
#endif
/** \brief Number of enable conditions */
#define DEM_NUM_ENABLECONDITIONS 0U

#if (defined DEM_NUM_ENCOND_LINKS)
#error DEM_NUM_ENCOND_LINKS already defined
#endif
/** \brief Number of enable condition links
 */
#define DEM_NUM_ENCOND_LINKS   0U

#if (defined DEM_ENCONDIDX_WIDTH)
#error DEM_ENCONDIDX_WIDTH already defined
#endif
/** \brief number of bits which are necessary to save the max enable condition index
 ** in the generated configuration.
 */
#define DEM_ENCONDIDX_WIDTH            1U

#if (defined DEM_NUMENCOND_WIDTH)
#error DEM_NUMENCOND_WIDTH already defined
#endif
/** \brief number of bits which are necessary to save the max enable condition number of an event */
#define DEM_NUMENCOND_WIDTH            1U


/*------------------[Operation cycles configuration]------------------------*/

#if (defined DEM_NUM_OPCYCLES)
#error DEM_NUM_OPCYCLES already defined
#endif
/** \brief Number of operation cycles */
#define DEM_NUM_OPCYCLES 0U

/*------------------[Rte configuration]-------------------------------------*/

#if (defined DEM_INCLUDE_RTE)
#error DEM_INCLUDE_RTE already defined
#endif
/** \brief Switch, indicating if RTE is available and can be used from Dem */
#define DEM_INCLUDE_RTE STD_ON

/** \brief symbolic names for Operation Cycles */

/*------------------[Version Info API ]-------------------------------------*/

#if (defined DEM_VERSION_INFO_API)
#error DEM_VERSION_INFO_API already defined
#endif
/** \brief Enables / disables version API support. */
#define DEM_VERSION_INFO_API  STD_ON
/*==================[type definitions]======================================*/

/** \brief This type is used as index type for the enable conditions
 **
 ** Its size depends on the configuration.
 **
 ** Word of the event description bit-package:
 **
 ** - cccc: EnCondIdx     (var size)
 ** - ee:   NumEnCond     (var size - max. 8 bit according to configuration)
 **
 ** - xxxx xxxx  xxxx xxxx  xxxx xxxx  xxxx xxxx
 ** - ____ ____  ____ ____  ____ ____  __ee cccc
 */
#if ( ( DEM_ENCONDIDX_WIDTH + DEM_NUMENCOND_WIDTH ) <= 8U  )
typedef uint8 Dem_EnableConditionIdType;
#elif ( ( DEM_ENCONDIDX_WIDTH + DEM_NUMENCOND_WIDTH ) <= 16U )
typedef uint16 Dem_EnableConditionIdType;
#elif ( ( DEM_ENCONDIDX_WIDTH + DEM_NUMENCOND_WIDTH ) <= 32U )
typedef uint32 Dem_EnableConditionIdType;
#else
#error The are no many enable condition links configured. Invalid configuration.
#endif

/*------------------[Dem_EventStatusExtendedType]---------------------------*/

/** \brief See API Dem_GetEventStatus()
 **
 ** Used in Dem_GetEventStatus() and Xxx_TriggerOnEventStatus() .
 ** - Bit0: testFailed (= 1; Passed = 0)
 ** - Bit1: (not supported) testFailedThisOperationCycle (= 1; not yet failed this cycle = 0)
 ** - Bit2: pendingDTC (= 1; Not Pending DTC status = 0)
 **         supported if DemUseStatusOfDtcPendingBit set to 'true'
 ** - Bit3: confirmedDTC (= 1; Not Confirmed DTC status = 0)
 ** - Bit4: testNotCompletedSinceLastClear (= 1; Test Completed Since Last
 **         Clear = 0)
 ** - Bit5: (not supported) testFailedSinceLastClear (= 1; test not Failed Since Last Clear
 **         = 0)
 ** - Bit6: (not supported) testNotCompletedThisOperationCycle (= 1; Completed this cycle = 0)
 ** - Bit7: warningIndicatorRequested (= 1) */
/** \brief Switch, indicating if RTE is available and can be used from Dem */
/* Dem_EventStatusExtendedType is included with Rte_Types.h */
/* typedef uint8 Dem_EventStatusExtendedType; */

/*==================[external function declarations]========================*/
#define DEM_START_SEC_CODE
#include <MemMap.h>

/*------------------[DemPidOrDidCallback]---------------------------*/

/*------------------[DemCallbackEventStatusChanged]---------------------------*/

#define DEM_STOP_SEC_CODE
#include <MemMap.h>
/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_CFG_H ) */
/*==================[end of file]===========================================*/
