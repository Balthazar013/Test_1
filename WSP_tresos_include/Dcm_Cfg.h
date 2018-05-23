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
#ifndef DCM_CFG_H
#define DCM_CFG_H

/*==================[includes]===============================================*/
#include <Dcm_Types.h>

/*==================[macros]=================================================*/

/** \brief Defines if the Rte is used or not */

#define DCM_INCLUDE_RTE STD_ON


#if (defined DCM_NUMBER_OF_RX_PDU_IDS)
#error DCM_NUMBER_OF_RX_PDU_IDS already defined
#endif /* if (defined DCM_NUMBER_OF_RX_PDU_IDS) */

/** \brief Defines the number of RxPduIds the Dcm-Wrapper can receive
 **
 ** This preprocessor macro defines for how many different RxPduIds the Dcm-
 ** Wrapper can look up and map the corresponding TxPduId.
 */
#define DCM_NUMBER_OF_RX_PDU_IDS 2U

#if (defined DCM_NUMBER_OF_SID)
#error DCM_NUMBER_OF_SID already defined
#endif /* if (defined DCM_NUMBER_OF_SID) */

/** \brief Defines the number of services. */
#define DCM_NUMBER_OF_SID 15U

#if (defined DCM_NUMBER_OF_DID_READ_CALLOUT_FUNCTIONS_ITEMS)
#error DCM_NUMBER_OF_DID_READ_CALLOUT_FUNCTIONS_ITEMS already defined
#endif /* if (defined DCM_NUMBER_OF_DID_READ_CALLOUT_FUNCTIONS_ITEMS) */

/** \brief Defines the number of read callout functions for DIDs available. */
#define DCM_NUMBER_OF_DID_READ_CALLOUT_FUNCTIONS_ITEMS 135U

#if (defined DCM_NUMBER_OF_DID_WRITE_CALLOUT_FUNCTIONS_ITEMS)
#error DCM_NUMBER_OF_DID_WRITE_CALLOUT_FUNCTIONS_ITEMS already defined
#endif /* if (defined DCM_NUMBER_OF_DID_WRITE_CALLOUT_FUNCTIONS_ITEMS) */

/** \brief Defines the number of write callout functions for DIDs available. */
#define DCM_NUMBER_OF_DID_WRITE_CALLOUT_FUNCTIONS_ITEMS 14U

#if (defined DCM_NUMBER_OF_DID_READ_DATA_LENGTH_CALLOUT_FUNCTIONS_ITEMS)
#error DCM_NUMBER_OF_DID_READ_DATA_LENGTH_CALLOUT_FUNCTIONS_ITEMS already defined
#endif /* if (defined DCM_NUMBER_OF_DID_READ_DATA_LENGTH_CALLOUT_FUNCTIONS_ITEMS) */

/** \brief Defines the number of read data length callout functions for DIDs available. */
#define DCM_NUMBER_OF_DID_READ_DATA_LENGTH_CALLOUT_FUNCTIONS_ITEMS 17U

#if (defined DCM_NUMBER_OF_RESET_SERVICE_ELEMENTS)
#error DCM_NUMBER_OF_RESET_SERVICE_ELEMENTS already defined
#endif /* if (defined DCM_NUMBER_OF_RESET_SERVICE_ELEMENTS) */

/** \brief Defines the number of configured ResetServices. */
#define DCM_NUMBER_OF_RESET_SERVICE_ELEMENTS 2U

#if (defined DCM_RTE_TABLE_SESSION_CONTROL_SIZE)
#error DCM_RTE_TABLE_SESSION_CONTROL_SIZE already defined
#endif
/** \brief Session control count */
#define DCM_RTE_TABLE_SESSION_CONTROL_SIZE   1U

#if (defined DCM_NUMBER_OF_ROUTINES)
#error DCM_NUMBER_OF_ROUTINES already defined
#endif /* if (defined DCM_NUMBER_OF_ROUTINES) */

/** \brief Defines the number of supported Routine functions. */
#define DCM_NUMBER_OF_ROUTINES 3U

#if (defined DCM_NUMBER_OF_ROUTINEINFO_ELEMENTS)
#error DCM_NUMBER_OF_ROUTINEINFO_ELEMENTS already defined
#endif /* if (defined DCM_NUMBER_OF_ROUTINEINFO_ELEMENTS) */

/** \brief Defines the number of RoutineInfo elements. */
#define DCM_NUMBER_OF_ROUTINEINFO_ELEMENTS 3U

#if (defined DCM_MAX_ROUTINESTSOPTRECSIZE)
#error DCM_MAX_ROUTINESTSOPTRECSIZE already defined
#endif /* if (defined DCM_MAX_ROUTINESTSOPTRECSIZE) */

/** \brief the maximum number of bytes configured for a RoutineStsOptRecSize */
#define DCM_MAX_ROUTINESTSOPTRECSIZE 257U

#if (defined DCM_REQUEST_INDICATION_ENABLED)
#error DCM_REQUEST_INDICATION_ENABLED already defined
#endif
/** \brief Switch, indicating if Service request indication is available */
#define DCM_REQUEST_INDICATION_ENABLED       STD_ON

#if (defined DCM_RTE_TABLE_REQUEST_INDICATION_SIZE)
#error DCM_RTE_TABLE_REQUEST_INDICATION_SIZE already defined
#endif
/** \brief Service request indication count */
#define DCM_RTE_TABLE_REQUEST_INDICATION_SIZE   1U

#if (defined DCM_DEV_ERROR_DETECT)
#error DCM_DEV_ERROR_DETECT already defined
#endif /* if (defined DCM_DEV_ERROR_DETECT) */

/** \brief Enables / Disables Det support. */
#define DCM_DEV_ERROR_DETECT STD_ON

#if (defined DCM_VERSION_INFO_API)
#error DCM_VERSION_INFO_API already defined
#endif /* if (defined DCM_VERSION_INFO_API) */

/** \brief Enables / disables version API support. */
#define DCM_VERSION_INFO_API STD_ON


#if (defined DCM_BSWM_API_VERSION)
#error DCM_BSWM_API_VERSION already defined
#endif /* #if (defined DCM_BSWM_API_VERSION) */

/* !LINKSTO vsc_Dcm-650_MQB_MLB, 1 */
/** \brief Configured BswM API variant. */
#define DCM_BSWM_API_VERSION DCM_BSWM_API_4_0_3


#if (defined DCM_BSWM_USER)
#error DCM_BSWM_USER already defined
#endif /* #if (defined DCM_BSWM_USER) */

/* !LINKSTO vsc_Dcm-651_MQB_MLB, 1 */
/** \brief  The user that requests the mode. */
#define DCM_BSWM_USER 0U



#if (defined DCM_COMM_API_VERSION)
#error DCM_COMM_API_VERSION already defined
#endif /* #if (defined DCM_COMM_API_VERSION) */

/* !LINKSTO vsc_Dcm-652_MQB_MLB, 1 */
/** \brief Configured ComM API variant. */
#define DCM_COMM_API_VERSION DCM_COMM_API_3_2

#if (defined DCM_PDUINFOPTR_TYPE)
#error DCM_PDUINFOPTR_TYPE already defined
#endif /* #if (defined DCM_PDUINFOPTR_TYPE) */

/* !LINKSTO vsc_Dcm-649_MQB_MLB, 1 */
/** \brief  Type of input pointer parameter of PduRTp_Transmit function */
#define DCM_PDUINFOPTR_TYPE P2CONST

#if (defined DCM_TIMEOUT_CALLBACK)
#error DCM_TIMEOUT_CALLBACK already defined
#endif /* if (defined DCM_TIMEOUT_CALLBACK) */

/** \brief Enables / disables the Appl_DiagTimeout function
 **        which is called at S3 timeout.
 */
#define DCM_TIMEOUT_CALLBACK                         STD_ON

#if (defined DCM_DEM_ENABLE_STATUS)
#error DCM_DEM_ENABLE_STATUS already defined
#endif /* if (defined DCM_DEM_ENABLE_STATUS) */

/** \brief Macro which defines if the Dem-Wrapper for DEH is enabled or disabled */
#define DCM_DEM_ENABLE_STATUS                       STD_ON

#if (defined DCM_KS_ENABLE_STATUS)
#error DCM_KS_ENABLE_STATUS already defined
#endif /* if (defined DCM_KS_ENABLE_STATUS) */

/** \brief Macro which defines if the KS is enabled or disabled */
#define DCM_KS_ENABLE_STATUS                       STD_OFF

/* The following block generates macros for the possible TX PduIDs of Dcm_SendMessage. */
#if (!defined DCM_TX_PduRRoutingPath_Channel_0_TxNSdu)
  #define DCM_TX_PduRRoutingPath_Channel_0_TxNSdu 0
#endif
#if (!defined DCM_TX_PduRRoutingPath_Channel_0_TxNSdu)
  #define DCM_TX_PduRRoutingPath_Channel_0_TxNSdu 0
#endif


#if (defined DCM_SESSIONS_WITHOUT_S3SERVER)
#error DCM_SESSIONS_WITHOUT_S3SERVER already defined
#endif /* if (defined DCM_SESSIONS_WITHOUT_S3SERVER) */

/** \brief Macro which defines if the S3Server timeout is disabled for at least on session */
#define DCM_SESSIONS_WITHOUT_S3SERVER                       STD_OFF

#if (defined DCM_SESSIONS_WITHOUT_RES_PEND)
#error DCM_SESSIONS_WITHOUT_RES_PEND already defined
#endif /* if (defined DCM_SESSIONS_WITHOUT_RES_PEND) */

/** \brief Macro which defines if the Request Response Pending mechanism is disabled for at least on session */
#define DCM_SESSIONS_WITHOUT_RES_PEND                       STD_OFF

#if (defined DCM_INT_PROVIDE_DORESET_CALLOUT)
#error DCM_INT_PROVIDE_DORESET_CALLOUT already defined
#endif /* if (defined DCM_INT_PROVIDE_DORESET_CALLOUT) */

/** Configuration option which defines if the SDSext_vDoReset shall be implemented in the Dcm-Wrapper */
#define DCM_INT_PROVIDE_DORESET_CALLOUT     STD_OFF

#if (defined DCM_NUMBER_OF_ROE_WAKEUP_ITEMS)
#error DCM_NUMBER_OF_ROE_WAKEUP_ITEMS already defined
#endif /* if (defined DCM_NUMBER_OF_ROE_WAKEUP_ITEMS) */

/** brief Number of configured wakeup items for roe*/
#define DCM_NUMBER_OF_ROE_WAKEUP_ITEMS         0U

#if (defined DCM_ROE_STATUS_OVER_RTE)
#error DCM_ROE_STATUS_OVER_RTE already defined
#endif /* if (defined DCM_ROE_STATUS_OVER_RTE) */

/** brief read Roe status over a Rte interface */
#define DCM_ROE_STATUS_OVER_RTE         STD_OFF

#if (defined DCM_ROE_INIT_ECUM_WAKEUP_SOURCES)
#error DCM_ROE_INIT_ECUM_WAKEUP_SOURCES already defined
#endif /* if (defined DCM_ROE_INIT_ECUM_WAKEUP_SOURCES) */

/** brief Init Roe dependend on the EcuM wakeup sources*/
#define DCM_ROE_INIT_ECUM_WAKEUP_SOURCES         STD_OFF

#if (defined DCM_NUMBER_OF_DIDINFO_ELEMENTS)
#error DCM_NUMBER_OF_DIDINFO_ELEMENTS already defined
#endif /* if (defined DCM_NUMBER_OF_DIDINFO_ELEMENTS) */

/** \brief Defines the number of RoutineInfo elements. */
#define DCM_NUMBER_OF_DIDINFO_ELEMENTS 8U

#if (defined DCM_NO_DID_CALLOUT_FUNCTION)
#error DCM_NO_DID_CALLOUT_FUNCTION already defined
#endif

/**brief Define is set in DidAccessIndex of Dcm_DataIdItem if no Dcm_DidAccess element is set */
#define DCM_NO_DID_CALLOUT_FUNCTION 65535U

#if (defined DCM_A_SECURITY_ACCESS)
#error DCM_A_SECURITY_ACCESS already defined
#endif /* if (defined DCM_A_SECURITY_ACCESS) */

/** brief Global configuration swich Service 0x27 */
#define DCM_A_SECURITY_ACCESS        STD_ON

#if (defined DCM_NUMBER_OF_SECURITY_LEVELS)
#error DCM_NUMBER_OF_SECURITY_LEVELS already defined
#endif /* if (defined DCM_NUMBER_OF_SECURITY_LEVELS) */

/** brief Number of configured Security Levels */
#define DCM_NUMBER_OF_SECURITY_LEVELS    2U

#if (defined DCM_PDURTRACE_ENABLED)
#error DCM_PDURTRACE_ENABLED already defined
#endif /* if (defined DCM_PDURTRACE_ENABLED) */

/** \brief Enables / Disables PduR interface function call tracing mechanism. */
#define DCM_PDURTRACE_ENABLED  STD_OFF

#if (defined DCM_PDURTRACE_BUFLEN)
#error DCM_PDURTRACE_BUFLEN already defined
#endif /* if (defined DCM_PDURTRACE_BUFLEN) */

/** \brief  The number of elements of the PduR interface function call trace buffer. */
#define DCM_PDURTRACE_BUFLEN  0x00U



#if (defined DCM_INVALIDPDUIDCALLOUT_ENABLED)
#error DCM_INVALIDPDUIDCALLOUT_ENABLED already defined
#endif /* if (defined DCM_INVALIDPDUIDCALLOUT_ENABLED) */

/** \brief  Enables / disables invalid Rx PduID user callout functions. */
#define DCM_INVALIDPDUIDCALLOUT_ENABLED STD_OFF


#if (defined DCM_USERTXCONFIRMATION_ENABLED)
#error DCM_USERTXCONFIRMATION_ENABLED already defined
#endif /* if (defined DCM_USERTXCONFIRMATION_SWITCH) */

/** \brief  Enables / disables user Tx confirmation function. */
#define DCM_USERTXCONFIRMATION_ENABLED STD_OFF





#if defined(DCM_NUMBER_OF_DIDIOCTRL_CALLOUT_FUNCTIONS_ITEMS)
#error DCM_NUMBER_OF_DIDIOCTRL_CALLOUT_FUNCTIONS_ITEMS already defined
#endif /* if (defined DCM_NUMBER_OF_DIDIOCTRL_CALLOUT_FUNCTIONS_ITEMS) */

/** brief  Number of callout functions for DIDs available related to service
 **        InputOutputControlByIdentifier (0x2F).
 **/
#define DCM_NUMBER_OF_DIDIOCTRL_CALLOUT_FUNCTIONS_ITEMS  5U

#if defined(DCM_SIZE_OF_DIDIOCTRL_CONTROLSTATUSRECORD)
#error DCM_SIZE_OF_DIDIOCTRL_CONTROLSTATUSRECORD already defined
#endif /* if (defined DCM_SIZE_OF_DIDIOCTRL_CONTROLSTATUSRECORD) */

/** brief  maximum of all configured DcmVAGDspDidIOCtrlControlStatusRecordSizes */
#define DCM_SIZE_OF_DIDIOCTRL_CONTROLSTATUSRECORD        4U


#if (defined DCM_A_START_DIAGNOSTIC_SESSION)
#error DCM_A_START_DIAGNOSTIC_SESSION already defined
#endif /* if (defined DCM_A_START_DIAGNOSTIC_SESSION) */

/** brief Service 0x10 Dcm-Wrapper*/
#define DCM_A_START_DIAGNOSTIC_SESSION     SDS_ENABLED

#if (defined DCM_A_RESET_OR_DISCONNECT)
#error DCM_A_RESET_OR_DISCONNECT already defined
#endif /* if (defined DCM_A_RESET_OR_DISCONNECT) */

/** brief Service 0x11 Dcm-Wrapper functionality*/
#define DCM_A_RESET_OR_DISCONNECT          SDS_ENABLED

#if (defined DCM_A_COMMUNICATION_CONTROL)
#error DCM_A_COMMUNICATION_CONTROL already defined
#endif /* if (defined DCM_A_COMMUNICATION_CONTROL) */

/** brief Service 0x28 Dcm-Wrapper functionality */
#define DCM_A_COMMUNICATION_CONTROL        SDS_ENABLED

#if (defined DCM_A_WRITE_DATA_BY_IDENTIFIER)
#error DCM_A_WRITE_DATA_BY_IDENTIFIER already defined
#endif /* if (defined DCM_A_WRITE_DATA_BY_IDENTIFIER) */

/** brief Service 0x2e Dcm-Wrapper functionality */
#define DCM_A_WRITE_DATA_BY_IDENTIFIER     SDS_ENABLED

#if (defined DCM_A_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER)
#error DCM_A_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER already defined
#endif /* if (defined DCM_A_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER) */

/** brief Service 0x2f Dcm-Wrapper functionality */
#define DCM_A_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER  SDS_ENABLED

#if (defined DCM_A_ROUTINE_CONTROL)
#error DCM_A_ROUTINE_CONTROL already defined
#endif /* if (defined DCM_A_ROUTINE_CONTROL) */

/** brief Service 0x31 - Dcm-Wrapper functionality */
#define DCM_A_ROUTINE_CONTROL              SDS_ENABLED

/*------------------[supported sub-function of CommunicationControl]----------]*/

#if (defined DCM_COMCTRL_EN_RX_AND_TX_ENABLED)
#error DCM_COMCTRL_EN_RX_AND_TX_ENABLED already defined
#endif

/** \brief Enable the ComControl subfunction "EnableRxAndTx" */
#define DCM_COMCTRL_EN_RX_AND_TX_ENABLED       SDS_ENABLED


#if (defined DCM_COMCTRL_EN_RX_DIS_TX_ENABLED)
#error DCM_COMCTRL_EN_RX_DIS_TX_ENABLED already defined
#endif

/** \brief Enable the ComControl subfunction "EnableRxAndDisableTx" */
#define DCM_COMCTRL_EN_RX_DIS_TX_ENABLED       SDS_ENABLED

#if (defined DCM_COMCTRL_DIS_RX_EN_TX_ENABLED)
#error DCM_COMCTRL_DIS_RX_EN_TX_ENABLED already defined
#endif

/** \brief Enable the ComControl subfunction "DisableRxAndEnableTx" */
#define DCM_COMCTRL_DIS_RX_EN_TX_ENABLED      SDS_DISABLED

#if (defined DCM_COMCTRL_DIS_RX_AND_TX_ENABLED)
#error DCM_COMCTRL_DIS_RX_AND_TX_ENABLED already defined
#endif

/** \brief Enable the ComControl subfunction "DisableRxAndTx" */
#define DCM_COMCTRL_DIS_RX_AND_TX_ENABLED     SDS_DISABLED

#if (defined DCM_COMCTRL_EN_ENHANCED_ADDR_ENABLED)
#error DCM_COMCTRL_EN_ENHANCED_ADDR_ENABLED already defined
#endif

/** \brief Enable the ComControl subfunction "enableRxAndDisableTxWithEnhancedAddressInformation" */
#define DCM_COMCTRL_EN_ENHANCED_ADDR_ENABLED  SDS_DISABLED

#if (defined DCM_COMCTRL_DIS_ENHANCED_ADDR_ENABLED)
#error DCM_COMCTRL_DIS_ENHANCED_ADDR_ENABLED already defined
#endif

/** \brief Enable the ComControl subfunction "enableRxAndTxWithEnhancedAddressInformation" */
#define DCM_COMCTRL_DIS_ENHANCED_ADDR_ENABLED SDS_DISABLED

#if (defined DCM_COMCTRL_GW_VEHICLE_WAKEUP_ENABLED)
#error DCM_COMCTRL_GW_VEHICLE_WAKEUP_ENABLED already defined
#endif

/** \brief Enable the ComControl subfunction "GatewayVehicleWakeUp" */
#define DCM_COMCTRL_GW_VEHICLE_WAKEUP_ENABLED SDS_DISABLED


#if (defined DCM_NUMBER_OF_DID_ITEMS)
#error DCM_NUMBER_OF_DID_ITEMS already defined
#endif /* if (defined DCM_NUMBER_OF_DID_ITEMS) */


/** brief Defines the number of DIDs supported. */
#define DCM_NUMBER_OF_DID_ITEMS            135U


#if (defined I2S_USE_AUTOSAR_CANCEL_RECEIVE)
#error I2S_USE_AUTOSAR_CANCEL_RECEIVE already defined
#endif /* if (defined I2S_USE_AUTOSAR_CANCEL_RECEIVE) */

/**brife activation of Receive Cancilation of an PDU */
#define I2S_USE_AUTOSAR_CANCEL_RECEIVE     1   /* 1=cancel receive func supported, 0=none */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/
#define SDS_START_SEC_CODE
#include <i2s_MemMap.h>

/* prototypes for user defined service callback functions */

/** brief User callback function for service 0x34 */
extern FUNC(byte,SDS_APPL_CODE) UDS_DiagService_0x34
(
  P2VAR(byte, AUTOMATIC, SDS_APPL_DATA) RxTxBuf,
  P2VAR(word, AUTOMATIC, SDS_APPL_DATA) LenOfMsg,
  VAR(byte,AUTOMATIC) Mode
);

/** brief User callback function for service 0x36 */
extern FUNC(byte,SDS_APPL_CODE) UDS_DiagService_0x36
(
  P2VAR(byte, AUTOMATIC, SDS_APPL_DATA) RxTxBuf,
  P2VAR(word, AUTOMATIC, SDS_APPL_DATA) LenOfMsg,
  VAR(byte,AUTOMATIC) Mode
);

/** brief User callback function for service 0x37 */
extern FUNC(byte,SDS_APPL_CODE) UDS_DiagService_0x37
(
  P2VAR(byte, AUTOMATIC, SDS_APPL_DATA) RxTxBuf,
  P2VAR(word, AUTOMATIC, SDS_APPL_DATA) LenOfMsg,
  VAR(byte,AUTOMATIC) Mode
);

#define SDS_STOP_SEC_CODE
#include <i2s_MemMap.h>

#define DCM_START_SEC_CODE
#include <MemMap.h>

/** brief User callout functions for DcmDspDid_ff3f */
extern FUNC(Std_ReturnType,DCM_APPL_CODE) DidCondCheckRead_ff3f
(
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) nrc
);

extern FUNC(Std_ReturnType,DCM_APPL_CODE) DidReadData_ff3f
(
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) data
);


/* prototypes for user defines RoutineControl callback functions */
  
/** \brief User callout functions for DcmDspRoutine_203 */
extern FUNC(Std_ReturnType,DCM_APPL_CODE) DcmRoutineStart_0203
(
  DCM_IN_POINTER(uint8,AUTOMATIC,DCM_APPL_DATA) InBuffer,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) OutBuffer,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);




/* prototype for user defined CommunicationControl callback functions */
extern FUNC(Std_ReturnType, DCM_APPL_CODE) DcmVAGDspComControlPermissionCallout
(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

/* prototypes for user defined EcuReset callback functions */
/** \brief User callout functions for DcmDspEcuReset */
extern FUNC(Std_ReturnType,DCM_APPL_CODE) DcmExt_CheckEcuResetPrecondition
(
  uint8 resetType, P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);



#define DCM_STOP_SEC_CODE
#include <MemMap.h>
/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief Array with config. info for service 0x31 */
extern CONST(Dcm_RoutineInfoType,DCM_CONST)
  Dcm_DspRoutineInfo[DCM_NUMBER_OF_ROUTINEINFO_ELEMENTS];

/** \brief Array with callout functions for service 0x31 */
extern CONST(Dcm_RoutineType,DCM_CONST)
  Dcm_DspRoutine[DCM_NUMBER_OF_ROUTINES];

/** \brief Array with callout functions for service 0x11 */
extern CONST(Dcm_EcuResetType,DCM_CONST)
  Dcm_ResetService[DCM_NUMBER_OF_RESET_SERVICE_ELEMENTS];

/** brief Security Level Access for EcuReset (service 0x11). */
extern CONST(Dcm_SecurityMaskType,DCM_CONST)
         Dcm_ResetServiceSecurityAccess[DCM_NUMBER_OF_RESET_SERVICE_ELEMENTS];
/** brief Security Level Access for service execution. */
extern CONST(Dcm_SecurityMaskType,DCM_CONST)
         Dcm_SIDServiceSecurityAccess[DCM_NUMBER_OF_SID];


/** \brief RTE-Callback function pointer table for ServiceRequestIndication */
extern CONST (Dcm_RteIndicationType, DCM_CONST)
  Dcm_RteRequestIndicationTable[DCM_RTE_TABLE_REQUEST_INDICATION_SIZE];

/** \brief RTE-Callback function pointer table for SessionControl */
extern CONST(Dcm_RteSessionControlType, DCM_CONST)
  Dcm_RteSessionControlTable[DCM_RTE_TABLE_SESSION_CONTROL_SIZE];

/** \brief Array with read callout functions for service 0x22 */
extern CONST(Dcm_DidReadCalloutFunctionType,DCM_CONST)
         Dcm_DidReadCalloutFunctions[DCM_NUMBER_OF_DID_READ_CALLOUT_FUNCTIONS_ITEMS];

/** \brief Array with write callout functions for service 0x2e */
extern CONST(Dcm_DidWriteCalloutFunctionType,DCM_CONST)
         Dcm_DidWriteCalloutFunctions[DCM_NUMBER_OF_DID_WRITE_CALLOUT_FUNCTIONS_ITEMS];



/** \brief Array with write callout functions for service 0x22/0x2e */
extern CONST(Dcm_DidReadDataLengthCalloutFunctionType,DCM_CONST)
         Dcm_DidReadDataLengthCalloutFunctions[DCM_NUMBER_OF_DID_READ_DATA_LENGTH_CALLOUT_FUNCTIONS_ITEMS];

/** \brief Configured session options */
extern CONST(Dcm_SessionStatusType,DCM_CONST) Dcm_SessionStatus[UDS_MAX_NO_OF_SESSIONS];


/** \brief  Array with function pointers of callback function of service
 **         InputOutputControlByIdentifier (0x2F)
 **/
extern CONST(Dcm_DidIOCtrlCalloutFunctionType, DCM_CONST) Dcm_DidIOCtrlCalloutFunctions[DCM_NUMBER_OF_DIDIOCTRL_CALLOUT_FUNCTIONS_ITEMS];

/** \brief  Array of configuation parameter sets of service InputOutputControlByIdentifier (0x2F) */
extern CONST(Dcm_DidIOCtrlConfigType,          DCM_CONST) Dcm_DidIOCtrlConfigs         [DCM_NUMBER_OF_DIDIOCTRL_CALLOUT_FUNCTIONS_ITEMS];

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[external data]=========================================*/

#define DCM_START_SEC_VAR_POWER_ON_INIT_8BIT
#include <MemMap.h>

#if ( DCM_A_SECURITY_ACCESS == STD_ON )
/* Active security level index */
extern VAR(uint8, DCM_VAR)  Dcm_SecTabIdx;
#endif /* DCM_A_SECURITY_ACCESS == STD_ON */

#define DCM_STOP_SEC_VAR_POWER_ON_INIT_8BIT
#include <MemMap.h>

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/** @} doxygen end group definition */
#endif /* #ifndef DCM_CFG_H */
/*==================[end of file]============================================*/
