/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef DCM_INT_CFG_H
#define DCM_INT_CFG_H

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 20.1 (required)
 *     The macro `memcpy' shall not be redefined
 *
 *     Reason:
 *     The function memcpy is used in supplied source file uds.c. Since modifying
 *     this supplied file is not allowed, it is required to map memcpy to TS_MemCpy.
*/

/*==================[includes]===============================================*/
#include <Std_Types.h>

#include <uds.h>

#include <TSMem.h>           /* Elektrobit Automotive TS_MemCpy/TS_MemSet*/

/*==================[macros]=================================================*/

#if (defined DCM_IN_POINTER)
#error DCM_IN_POINTER already defined
#endif

/**brief type of a IN argument of a C/S interface */
#define DCM_IN_POINTER P2CONST

/** \brief Dcm API Version for AUTOSAR Release 3.1 */
#define DCM_API_3_1     31U
/** \brief Dcm API Version for AUTOSAR Release 3.2 */
#define DCM_API_3_2     32U
/** \brief Dcm API Version for AUTOSAR Release 4.0.3 */
#define DCM_API_4_0_3   40U

/** \brief Dcm BswM API Version for AUTOSAR Release 3.2 */
#define DCM_BSWM_API_3_2     41U
/** \brief Dcm BswM API Version for AUTOSAR Release 4.0.3 */
#define DCM_BSWM_API_4_0_3   42U

/** \brief Dcm ComM API Version for AUTOSAR Release 3.2 */
#define DCM_COMM_API_3_2     43U
/** \brief Dcm ComM API Version for AUTOSAR Release 4.0.3 */
#define DCM_COMM_API_4_0_3   44U

#if (defined DCM_API_VERSION)
#error DCM_API_VERSION already defined
#endif

/**brief configure DCM API Variant */
#define DCM_API_VERSION DCM_API_4_0_3

/** \brief ComM API interface activated */
#define COMM_API_ACTIVATED    0U
/** \brief ComM API interface deactivated */
#define COMM_API_DEACTIVATED  1U
/** \brief User defined ComM API interface activated */
#define USER_CALLOUT          2U

/*------------------[ComM API interface macros]------------------------------------*/

#if (defined DCM_SESSION_CHANGE_COMM_API)
#error DCM_SESSION_CHANGE_COMM_API already defined
#endif /* if (defined DCM_SESSION_CHANGE_COMM_API) */

/** \brief Select the ComM Interface API concerning the Session Change. */
#define DCM_SESSION_CHANGE_COMM_API COMM_API_ACTIVATED

#if (defined DCM_VEHICLE_WAKEUP_COMM_API)
#error DCM_VEHICLE_WAKEUP_COMM_API already defined
#endif /* if (defined DCM_VEHICLE_WAKEUP_COMM_API) */

/** \brief Select the ComM Interface API concerning the Vehicle Wakeup. */

/* set to default value */
#define DCM_VEHICLE_WAKEUP_COMM_API COMM_API_ACTIVATED


#if (defined DCM_STARTUP_AFTER_FLASHING_COMM_API)
#error DCM_STARTUP_AFTER_FLASHING_COMM_API already defined
#endif /* if (defined DCM_STARTUP_AFTER_FLASHING_COMM_API) */

/** \brief Select the ComM Interface API concerning the After Flashing. */

#define DCM_STARTUP_AFTER_FLASHING_COMM_API COMM_API_ACTIVATED


/*------------------[Mem copy/set macros]------------------------------------*/

#if (defined DCM_MemCpy)
#error DCM_MemCpy already defined
#endif

#if (defined UDS_MemCpy)
#error UDS_MemCpy already defined
#endif

#if (defined DCM_MemSet)
#error DCM_MemSet already defined
#endif
/** \brief This Dcm-Wrapper macro maps to TS_MemCpy() */
#define DCM_MemCpy(d,s,n) TS_MemCpy((d),(s),(n))
/** \brief UDS_MemCpy is used in uds.c Map this macro to TS_MemCpy() */
/* Deviation MISRA-1 */
#define UDS_MemCpy(d,s,n) TS_MemCpy((d),(s),(n))
/** \brief This Dcm-Wrapper macro maps to TS_MemSet() */
#define DCM_MemSet(d,s,n) TS_MemSet((d),(s),(n))


/*------------------[UDS macros]---------------------------------------------*/

/*------------------[Dcm_DynLengthConfigType macros]---------------------------*/

#if (defined DCM_DSPDYNSTARTROUTINECTRL_BIT_MASK )
#error DCM_DSPDYNSTARTROUTINECTRL_BIT_MASK already defined
#endif /* if (defined DCM_DSPDYNSTARTROUTINECTRL_BIT_MASK) */

/** Bit position of DcmDspDynStartRoutineCtrlOptRS in Dcm_DynLengthConfigType.
 */
#define DCM_DSPDYNSTARTROUTINECTRL_BIT_MASK  1u

#if (defined DCM_DSPDYNSTARTROUTINESTS_BIT_MASK )
#error DCM_DSPDYNSTARTROUTINESTS_BIT_MASK already defined
#endif /* if (defined DCM_DSPDYNSTARTROUTINESTS_BIT_MASK) */

/** Bit position of DcmDspDynStartRoutineStsOptRS in Dcm_DynLengthConfigType.
 */
#define DCM_DSPDYNSTARTROUTINESTS_BIT_MASK  2u

#if (defined DCM_DSPDYNREQUESTRESSTS_BIT_MASK )
#error DCM_DSPDYNREQUESTRESSTS_BIT_MASK already defined
#endif /* if (defined DCM_DSPDYNREQUESTRESSTS_BIT_MASK) */

/** Bit position of DcmDspDynRequestResStsOptRS in Dcm_DynLengthConfigType.
 */
#define DCM_DSPDYNREQUESTRESSTS_BIT_MASK  4u

/*------------------[DcmDspDidAccess macros]---------------------------------*/

#if (defined DCM_DSP_DID_READ_ENANBLED )
#error DCM_DSP_DID_READ_ENANBLED already defined
#endif /* if (defined DCM_DSP_DID_READ_ENANBLED) */
/** Did Read conditions
 *  STD_ON  -> activated
 *  STD_OFF -> deactivated
 */
#define DCM_DSP_DID_READ_ENABLED STD_OFF


#if (defined DCM_DSP_DID_WRITE_ENANBLED )
#error DCM_DSP_DID_WRITE_ENANBLED already defined
#endif /* if (defined DCM_DSP_DID_WRITE_ENANBLED) */
/** Did Read conditions
 *  STD_ON  -> activated
 *  STD_OFF -> deactivated
 */
#define DCM_DSP_DID_WRITE_ENABLED STD_OFF


#if (defined DCM_USE_PRECONDITION_CHECK_WRITE )
#error DCM_USE_PRECONDITION_CHECK_WRITE already defined
#endif /* if (defined DCM_USE_PRECONDITION_CHECK_WRITE) */
/** Did Write precondition check
 *  STD_ON  -> activated
 *  STD_OFF -> deactivated
 */
#define DCM_USE_PRECONDITION_CHECK_WRITE STD_OFF



/*------------------[Security Access macros]---------------------------------*/

#if (defined DCM_RTE_TABLE_SECURITY_ACCESS_SIZE )
#error DCM_RTE_TABLE_SECURITY_ACCESS_SIZE already defined
#endif /* if (defined DCM_RTE_TABLE_SECURITY_ACCESS_SIZE) */
/** Number of configured security levels
 */
#define DCM_RTE_TABLE_SECURITY_ACCESS_SIZE  2U

#if (defined DCM_SECURITY_ATTEMPTS_UNTIL_DELAY )
#error DCM_SECURITY_ATTEMPTS_UNTIL_DELAY already defined
#endif /* if (defined DCM_RTE_TABLE_SECURITY_ACCESS_SIZE) */
/** Number of failed security accesses after which the delay time is activated.
 */
#define DCM_SECURITY_ATTEMPTS_UNTIL_DELAY   3U

#if (defined DCM_SECURITY_DELAY_TIME )
#error DCM_SECURITY_DELAY_TIME already defined
#endif /* if (defined DCM_SECURITY_DELAY_TIME) */
/**
 *  Delay time after failed security access.
 *  This is started after DcmDspSecurityNumAttDelay number of failed security accesses.
 *
 *  DcmDspSecurityDelayTime (in sec) * 1000 / MainFunctionPeriod
 */
#define DCM_SECURITY_DELAY_TIME       ( (600U * 1000U) / cuw_UDS_TASK_CYCLE )

#if (defined DCM_SECURITY_DELAY_TIME_ON_BOOT )
#error DCM_SECURITY_DELAY_TIME_ON_BOOT already defined
#endif /* if (defined DCM_SECURITY_DELAY_TIME_ON_BOOT) */
/**
 *  Start delay timer on power on (in ms)
 */
#define DCM_SECURITY_DELAY_TIME_ON_BOOT     1000U



/*------------------[Com Ctrl macros]---------------------------------*/



#if (defined DCM_COM_CTRL_NR_OF_SUB_SYSTEMS )
#error DCM_COM_CTRL_NR_OF_SUB_SYSTEMS already defined
#endif /* if (defined DCM_COM_CTRL_NR_OF_SUB_SYSTEMS) */


/** Number of subsystems which are connected to one of the LIN networks*/
#define DCM_COM_CTRL_NR_OF_SUB_SYSTEMS  0U

#if (defined DCM_COM_CTRL_NR_OF_ALL_CHANNELS )
#error DCM_COM_CTRL_NR_OF_ALL_CHANNELS already defined
#endif /* if (defined DCM_COM_CTRL_NR_OF_ALL_CHANNELS) */
/** Number of networks which can be accessed by a CommunicationControl message for "all" networks */
#define DCM_COM_CTRL_NR_OF_ALL_CHANNELS  0U

#if (defined DCM_COM_CTRL_NR_OF_SPC_CHANNELS )
#error DCM_COM_CTRL_NR_OF_SPC_CHANNELS already defined
#endif /* if (defined DCM_COM_CTRL_NR_OF_SPC_CHANNELS) */
/** Number of networks which can be directly accessed by a CommunicationControl message */
#define DCM_COM_CTRL_NR_OF_SPC_CHANNELS  0U

#if (defined DCM_COM_CTRL_FULL_COM_TIMEOUT )
#error DCM_COM_CTRL_FULL_COM_TIMEOUT already defined
#endif /* if (defined DCM_COM_CTRL_FULL_COM_TIMEOUT) */
/** Time to wait after requesting full communication for the acknowledgment; measured in Dcm main function calls */
/* #define DCM_COM_CTRL_FULL_COM_TIMEOUT */ /* DCM_COMCTRL_GW_VEHICLE_WAKEUP_ENABLED == SDS_DISABLED */

#if (defined DCM_COM_CTRL_NR_OF_RX_PDUS )
#error DCM_COM_CTRL_NR_OF_RX_PDUS already defined
#endif /* if (defined DCM_COM_CTRL_NR_OF_RX_PDUS) */
/** Number of Rx PDUs on which diagnostic messages can be received*/
#define DCM_COM_CTRL_NR_OF_RX_PDUS  2U

#if (defined DCM_COM_CTRL_FCN_GETPERMISSION)
#error DCM_COM_CTRL_FCN_GETPERMISSION already defined
#endif /* if (defined DCM_COM_CTRL_FCN_GETPERMISSION) */
/** Name of ComControlPermission function */
#define DCM_COM_CTRL_FCN_PERMISSION  DcmVAGDspComControlPermissionCallout



/*==================[type definitions]=======================================*/


/**brief This type is used to define a bitarray with the supported security levels.
 */
typedef uint8 Dcm_SecurityMaskType;

/**brief This type is used to define a bitarry with the supported sessions.
 ** The size of this type depends on the number of configured sessions.
 */
#if ( UDS_MAX_NO_OF_SESSIONS <= 8 )
typedef uint8 Dcm_SessionMaskType;
#elif ( UDS_MAX_NO_OF_SESSIONS <= 16 )
typedef uint16 Dcm_SessionMaskType;
#endif

/** no doxygen (only for internal usage)
 ** structure to hold the configuration of the three dyn length
 ** configuration option.
 ** Bit 0: DcmDspDynStartRoutineCtrlOptRS (DCM_DSPDYNSTARTROUTINECTRL_BIT_MASK)
 ** Bit 1: DcmDspDynStartRoutineStsOptRS  (DCM_DSPDYNSTARTROUTINESTS_BIT_MASK)
 ** Bit 2: DcmDspDynRequestResStsOptRS    (DCM_DSPDYNREQUESTRESSTS_BIT_MASK)
 */
typedef uint8 Dcm_DynLengthConfigType;

/** no doxygen (only for internal usage)
 ** structure to hold the configuration of an entry in DcmDspRoutineInfo.
 ** The size of this type depends on the number of configured sessions.
 */
typedef struct {
  uint8 StartRoutineCtrlOptRecSize;
  uint8 StopRoutineCtrlOptRecSize;
  uint16 StartRoutineStsOptRecSize;
  uint8 StopRoutineStsOptRecSize;
  /* uint8 ReqResRtnCtrlOptRecSize; not used */
  uint16 ReqResRtnStsOptRecSize;
  Dcm_SessionMaskType RoutineSession;
  Dcm_SecurityMaskType RoutineSecurityLevel;
  Dcm_DynLengthConfigType RoutineDynLengthConfig;
} Dcm_RoutineInfoType;

/*==================[external function declarations]=========================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/** @} doxygen end group definition */
#endif /* #ifndef DCM_INT_CFG_H */
/*==================[end of file]============================================*/
