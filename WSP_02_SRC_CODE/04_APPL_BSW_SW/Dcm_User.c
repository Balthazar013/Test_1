/**
 * \file
 *
 * \brief Autosar Dcm
 *
 * This file contains the implementation of the Autosar
 * module Dcm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define SDS_START_SEC_CODE
#include <i2s_MemMap.h>

#include <Dcm.h>
#include <EcuM.h>
#include <BswM_UserCallouts.h>
#include <BswM.h>
#include <Mcu.h>
#include <RamSharedData.h>
#include <NvM_DataIntern.h>
#include <Nvm.h>
#include <NVMS.h>
#include "SwCVoltageMonitor_Cfg.h"

#include <FLSMGR.h>

#include "NvmExt_Cfg.h"
#include "Dcm_User.h"

/**********************************************************************************************************************
 * Defines
**********************************************************************************************************************/


/**********************************************************************************************************************
 * Static functions
**********************************************************************************************************************/

/*
 * local void CheckSecurityAccessAndVoltage( uint8* pu8SaAttempts, uint16* pu16Voltage_mV )
 *
 * function for
 *
 * parameter
 * */
static void CheckSecurityAccessAndVoltage( uint8* pu8SaAttempts, uint16* pu16Voltage_mV )
{
    uint32 u32Val;

    // SA
    Std_ReturnType Ret = NVMS_ReadBlockSync( NVMS_BLOCK_SAK_BreakInTries, (uint8*)&u32Val );
    if( Ret != E_OK )
    {
        u32Val = 0u;
    }
    // SCO 157446: Do not check SA2 because of NVMS writing problem -- temporary solution
    // *pu8SaAttempts = (uint8)u32Val; // SCO: commented
    *pu8SaAttempts = 0u; // SCO: remove this when problem is fixed
    // Voltage
    *pu16Voltage_mV = Rte_IRead_DiagMeas_MainFunction_WspIoHwAbs_uP3V3_Voltage() * 10u; // 0.01 to 0.001 V
}

/*
 * local Std_ReturnType CheckSecurityAccessAndVoltage2( void )
 *
 * function for
 *
 * parameter
 * */
static Std_ReturnType CheckSecurityAccessAndVoltage2( void )
{
    byte Res = DCM_RES_POS_OK;
    uint8 u8SaAttempts = 0;
    uint16 u16VoltageMin_mV = 3000u;
    uint16 u16VoltageMax_mV = 3800u;
    uint16 u16Voltage_mV = 3300u;

    CheckSecurityAccessAndVoltage( &u8SaAttempts, &u16Voltage_mV );
    if( u8SaAttempts >= DCM_SECURITY_ATTEMPTS_UNTIL_DELAY )
    {
        Res = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
    }
/* TODO:
#if (VM_SETMAX > 1)
    // in case we have defined low and high voltage boundaries
    if( VM_SetContextPara[0].enType == VM_SETTYPE_UV )
    {
        u16VoltageMin_mV = VM_SetContextPara[0].uiThreshold;
    }
    if( VM_SetContextPara[0].enType == VM_SETTYPE_OV )
    {
        u16VoltageMax_mV = VM_SetContextPara[0].uiThreshold;
    }
    if( VM_SetContextPara[1].enType == VM_SETTYPE_UV )
    {
        u16VoltageMin_mV = VM_SetContextPara[1].uiThreshold;
    }
    if( VM_SetContextPara[1].enType == VM_SETTYPE_OV )
    {
        u16VoltageMax_mV = VM_SetContextPara[1].uiThreshold;
    }
#endif
*/
    if( u16Voltage_mV < u16VoltageMin_mV )
    {
        Res = DCM_E_VOLTAGETOOLOW;
    }
    if( u16Voltage_mV > u16VoltageMax_mV )
    {
        Res = DCM_E_VOLTAGETOOHIGH;
    }
    return Res;
}

/*==================[internal function definitions]==========================*/



/** \brief Activates/Deactivates Tx/Rx messages.
 **
 ** Description: Activates/Deactivates Tx/Rx messages.
 ** Instructions: Application must provide this function as callback.
 ** Configuration: SDS_A_START_DIAGNOSTIC_SESSION == SDS_ENABLED oder
 **                SDS_A_COMMUNICATION_CONTROL == SDS_ENABLED
 ** \param[in] ControlType     Rx/Tx Control (see [VW80124])
 ** \param[in] CommNetworkType Communication/Network control (see [VW80124])
 ** \param[in] Sid             Service Id
 ** \retval UDScub_IN_PROCESS Transmit data not received yet.
 ** \retval UDScub_FINISHED   Transmit data received, no string data.
 ** \retval UDScub_CANCELED   Request not accepted. No response will be sent.
 ** \retval NRC               Request not accepted. A negative response with the
 **                           error code will be sent.
 */
FUNC(byte,SDS_APPL_CODE) SDSext_ubComCtrl
(
  VAR(byte,AUTOMATIC) ControlType,
  VAR(byte,AUTOMATIC) CommNetworkType,
  VAR(byte,AUTOMATIC) Sid
)
{
  DCM_PARAM_UNUSED(ControlType);
  DCM_PARAM_UNUSED(CommNetworkType);
  DCM_PARAM_UNUSED(Sid);

  return UDScub_CANCELED;
}


#if (APPL_STOP_PROTOCOL == STD_ON)
/** \brief Callout function, to ask the user if a protocol shall be stoped
 **
 ** VAG UDS Dispatcher.pdf:
 ** This callback is used to stop current service request within the application if a
 ** new request with higher priority is received. It is called by the UDS layer, if a
 ** running request process was interrupted by receipt of a request of higher
 ** priority. In such a case, the application decides whether the new request will
  ** be accepted or not.
 */
FUNC(uint8,UDS_APPL_CODE) Appl_StopProtocol( void )
{
  return E_OK; /* Application has completed the running process. */
}
#endif

#if (DCM_TIMEOUT_CALLBACK == STD_ON )
/** \brief Callout function, which informs the application about a S3 timeout
 **
 ** The Dcm-Wrapper provides this function because the UDS S3 timeout callout
 ** function (UDS_vDiagTimeout) is implemented in the Dcm-Wrapper.
 ** The UDS_vDiagTimeout of the Dcm-Wrapper informs the Dem-Wrapper about
 ** the S3 timout to reset the internel session value of the DEH. In addition
 ** the Theft Protection is reinitialized in UDS_vDiagTimeout. If the internal
 ** implementation of the service CommunicationControl is used, the function SDSext_ubComCtrl
 ** will be called in UDS_vDiagTimeout.
 */
FUNC(void, DCM_APPL_CODE) Appl_DiagTimeout(void)
{
}
#endif


#if( ((SDS_A_START_DIAGNOSTIC_SESSION == SDS_ENABLED)  &&  \
      (SDS_10_PreConditionCheck == SDS_ENABLED) && \
      (SDS_10_ProgrammingSession == SDS_ENABLED))           || \
     ((SDS_A_COMMUNICATION_CONTROL == SDS_ENABLED)     && \
      (SDS_28_PreConditionCheck == SDS_ENABLED))     || \
     ((SDS_A_CTRL_DTC_SETTINGS == SDS_ENABLED)     && \
      (SDS_85_PreConditionCheck == SDS_ENABLED))     || \
     ((SDS_A_RESPONSE_ON_EVENT == SDS_ENABLED)         && \
      (SDS_86_PreConditionCheck == SDS_ENABLED)) \
    )
/** \brief Callout function, which checks if the conditions for the execution of the
 **        services 0x10, 0x28 (only for DcmAPIVersion=DCM_API_3_1), 0x85 or 0x86 are fulfilled.
 */
FUNC( byte, SDS_APPL_CODE ) SDSext_ubPreConditionCheck( byte ServiceID )
{
    byte Res = DCM_RES_POS_OK;
    boolean PrecondOk;

    switch( ServiceID ) 
    {
        case 0x10:
        {
            // ORU states
            FLSMGR_GetPrecondState( &PrecondOk );
            if( PrecondOk == 0 )
            {
                // TODO: do we need specific NRC?
                Res = DCM_E_CONDITIONSNOTCORRECT;
            }
            if( Res == DCM_RES_POS_OK )
            {
                // SA and Voltage
                Res = CheckSecurityAccessAndVoltage2();
            }
        }
        break;

        case 0x28:
            // NO BREAK here!!!
        case 0x85:
        {
            // SA and Voltage
            Res = CheckSecurityAccessAndVoltage2();
        }
        break;
    }
    return Res;
}
#endif


#if( SDS_A_RESET_OR_DISCONNECT == SDS_ENABLED )
#if( DCM_INT_PROVIDE_DORESET_CALLOUT == STD_OFF )
/** \brief Performs a reset
 **
 ** Configuration: SDS_A_RESET_OR_DISCONNECT == SDS_ENABLED
 **                DCM_INT_PROVIDE_DORESET_CALLOUT == STD_OFF
 **
 ** \param[in] ubResetControl Reset type (e. g. hard reset)
 */
FUNC(void,SDS_APPL_CODE) SDSext_vDoReset
(
  byte ubResetControl
)
{
  if(ubResetControl == SDS_11_KeyOffOnReset)
  {
    /* ... */
  }
}
#endif /* #if( DCM_INT_PROVIDE_DORESET_CALLOUT == STD_ON ) */
#endif /* #if( SDS_A_RESET_OR_DISCONNECT == SDS_ENABLED ) */


#if( SDS_A_RESPONSE_ON_EVENT == SDS_ENABLED )
#if( DCM_ROE_STATUS_OVER_RTE == STD_OFF )
/** \brief Writing function of RoE status data into non volotile memory
 **
 ** Description: This function writes the ROE status into the non volotile memory.
 **
 ** Configuration: SDS_A_RESPONSE_ON_EVENT == SDS_ENABLED
 **                DCM_ROE_STATUS_OVER_RTE == STD_OFF
 **
 ** \param[in] RoeData   Data to be written
 ** \retval SDS_OK       Data accepted for writing
 ** \retval SDS_BUSY     Writing not possible at the moment - try again
 ** \retval SDS_FAILED   Data cannot be written permanently
 **
 */
FUNC(tSDS_RoeData_Return, SDS_APPL_CODE) SDSext_WriteRoeData
(
  P2VAR(tSDS_ROE_ConfigType,AUTOMATIC,SDS_APPL_DATA) RoeData
)
{
  tSDS_RoeData_Return ret = SDS_OK;
  DCM_PARAM_UNUSED(RoeData);
  return ret;
}


/** \brief Reading function of RoE status data from non volotile memory
 **
 ** Description: This function read the ROE status from the non volotile memory.
 **
 ** Configuration: SDS_A_RESPONSE_ON_EVENT == SDS_ENABLED
 **                DCM_ROE_STATUS_OVER_RTE == STD_OFF
 **
 ** \param[out] RoeData  Readed data
 ** \retval SDS_OK       Data accepted for writing
 ** \retval SDS_BUSY     Writing not possible at the moment - try again
 ** \retval SDS_FAILED   Data cannot be written permanently
 **
 */
FUNC(tSDS_RoeData_Return, SDS_APPL_CODE) SDSext_ReadRoeData
(
  P2VAR(tSDS_ROE_ConfigType,AUTOMATIC,SDS_APPL_DATA) RoeData
)
{
  tSDS_RoeData_Return ret = SDS_OK;
  DCM_PARAM_UNUSED(RoeData);
  return ret;
}
#endif
#endif


/* prototypes for user defined service callback functions */

/* User callback function for service 0x34 */
FUNC(byte,SDS_APPL_CODE) UDS_DiagService_0x34
(
  P2VAR(byte, AUTOMATIC, SDS_APPL_DATA) RxTxBuf,
  P2VAR(word, AUTOMATIC, SDS_APPL_DATA) LenOfMsg,
  VAR(byte, AUTOMATIC) Mode
)
{
  DCM_PARAM_UNUSED(RxTxBuf);
  DCM_PARAM_UNUSED(LenOfMsg);
  DCM_PARAM_UNUSED(Mode);
  return E_NOT_OK;
}


/* User callback function for service 0x36 */
FUNC(byte,SDS_APPL_CODE) UDS_DiagService_0x36
(
  P2VAR(byte, AUTOMATIC, SDS_APPL_DATA) RxTxBuf,
  P2VAR(word, AUTOMATIC, SDS_APPL_DATA) LenOfMsg,
  VAR(byte, AUTOMATIC) Mode
)
{
  DCM_PARAM_UNUSED(RxTxBuf);
  DCM_PARAM_UNUSED(LenOfMsg);
  DCM_PARAM_UNUSED(Mode);
  return E_NOT_OK;
}


/* User callback function for service 0x37 */
FUNC(byte,SDS_APPL_CODE) UDS_DiagService_0x37
(
  P2VAR(byte, AUTOMATIC, SDS_APPL_DATA) RxTxBuf,
  P2VAR(word, AUTOMATIC, SDS_APPL_DATA) LenOfMsg,
  VAR(byte, AUTOMATIC) Mode
)
{
  DCM_PARAM_UNUSED(RxTxBuf);
  DCM_PARAM_UNUSED(LenOfMsg);
  DCM_PARAM_UNUSED(Mode);
  return E_NOT_OK;
}




#define SDS_STOP_SEC_CODE
#include <i2s_MemMap.h>

#define DCM_START_SEC_CODE
#include <MemMap.h>

#if ( DCM_RTE_TABLE_SESSION_CONTROL_SIZE == 0U )
/** \brief Indication sent to Central Diagnostic SwC when a session is changed
 **
 ** \param SesCtrlTypeOld Type of old session
 ** (::DCM_EXTENDED_DIAG_SESSION, ::DCM_PROGRAMMING_SESSION,
 ** ::DCM_DEFAULT_SESSION, ::DCM_ALL_SESSION_LEVEL, ::DCM_SAFETY_SYSTEM_DIAG_SESSION, ...)
 ** \param SesCtrlTypeNew Type of new session
 ** (::DCM_EXTENDED_DIAG_SESSION, ::DCM_PROGRAMMING_SESSION,
 ** ::DCM_DEFAULT_SESSION, ::DCM_ALL_SESSION_LEVEL, ::DCM_SAFETY_SYSTEM_DIAG_SESSION, ...)
 **
 ** \return Change Indication Status
 **         - ::E_OK: Change Indication Success
 **         - ::E_NOT_OK: Change Indication Failed
 */
FUNC(Std_ReturnType, DCM_APPL_CODE) Rte_DcmSesCtrlChangeIndication
(
  Dcm_SesCtrlType SesCtrlTypeOld,
  Dcm_SesCtrlType SesCtrlTypeNew
 )
{
  DCM_PARAM_UNUSED(SesCtrlTypeOld);
  DCM_PARAM_UNUSED(SesCtrlTypeNew);
  return E_OK;
}
#endif

#if ( (DCM_REQUEST_INDICATION_ENABLED        == STD_ON) && \
      (DCM_RTE_TABLE_REQUEST_INDICATION_SIZE == 0U    )    \
    )
/** \brief Indication sent to Central Diagnostic SwC when a service request is indicated
 **
 ** \param[in]  SID          Service ID
 ** \param[in]  RequestData  Service Request
 ** \param[in]  DataSize     Size of the buffer
 **
 ** \return  ServiceRequestIndication Status
 ** \retval  E_OK                    Change Indication Success
 ** \retval  E_REQUEST_NOT_ACCEPTED  Request is not accepted
 ** \retval  DCM_E_REQUEST_ENV_NOK   Eviromental condtions are not correct
 ** \retval  DCM_E_PENDING           Request is pending
 **/
FUNC(Std_ReturnType, DCM_CODE) Rte_DcmSrvRqstIndication
(
  uint8                            SID,
  P2CONST(uint8, AUTOMATIC, DCM_VAR) RequestData,
  uint16                           DataSize
)
{
  DCM_PARAM_UNUSED(SID);
  DCM_PARAM_UNUSED(RequestData);
  DCM_PARAM_UNUSED(DataSize);
  return E_OK;
}
#endif /* #if ( (DCM_REQUEST_INDICATION_ENABLED        == STD_ON) && \
                (DCM_RTE_TABLE_REQUEST_INDICATION_SIZE == 0U    )    \
              ) */





/* ======= User Callout Functions for ProgConditions ======= */

#if ( ( (SDS_A_START_DIAGNOSTIC_SESSION == SDS_ENABLED) &&      \
        (SDS_10_ProgrammingSession == SDS_ENABLED)         ) || \
        (DCM_A_START_DIAGNOSTIC_SESSION == SDS_ENABLED)           )
/** \brief Notification of request by tester to return to bootloader
 **
 ** Notification function to inform the application that the tester
 ** has been requested to return to the bootloader.
 ** Instructions:
 ** Application must provide this function as callback.
 ** The negative response-code $78 is generated by the SDS.
 ** The reset and trasmission of the positive response $50,02
 ** has to be performed by the bootloader.
 */
FUNC(Std_ReturnType,SDS_APPL_CODE) Dcm_SetProgConditions
(
  Dcm_ProgConditionsType ProgConditions
)
{
  /* To be filled by application developer */

  if(ProgConditions.ReprogrammingRequest == TRUE)
  {
    /* bootloader integration -- non-Autosar */
    RSD_RamSharedData.bootword = RSD_START_BOOTLOADER;
    RSD_RamSharedData.statusword = (ProgConditions.ResponseRequired == TRUE)
        ? RSD_RESPONSE_REQUISITION : RSD_NO_RESPONSE_REQUISITION;
    RSD_RamSharedData.reqBuffer[0] = 0x02;
    RSD_RamSharedData.reqBuffer[1] = ProgConditions.Sid;
    RSD_RamSharedData.reqBuffer[2] = ProgConditions.SubFncId;

    /* restart ECU */
    EcuM_KillAllRUNRequests();
    Mcu_PerformReset();
  }

  return E_OK;
}
#endif /*  #if ( ( (SDS_A_START_DIAGNOSTIC_SESSION == SDS_ENABLED) &&      \
                   (SDS_10_ProgrammingSession == SDS_ENABLED)         ) || \
                   (DCM_A_START_DIAGNOSTIC_SESSION == SDS_ENABLED)           )
*/

#if (DCM_A_START_DIAGNOSTIC_SESSION == SDS_ENABLED)
/** \brief Get programming conditions after initialization
 **
 ** The Dcm_GetProgConditions callout is called upon DCM initialization and
 ** allows to determine if a response ($50 or $51) has to be sent depending on
 ** request within the bootloader. The context parameter are defined in
 ** Dcm_ProgConditionsType.
 **
 ** \param[out] ProgConditions Conditions on which the jump from the bootloader has been requested
 **
 */
FUNC(void, DCM_CODE) Dcm_GetProgConditions
(
  P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions
)
{
  ProgConditions->ProtocolId = 0x01;

  ProgConditions->ResponseRequired =
      (RSD_RamSharedData.statusword == RSD_RESPONSE_REQUISITION) ? TRUE : FALSE;
  ProgConditions->Sid = RSD_RamSharedData.reqBuffer[1];
  ProgConditions->SubFncId = RSD_RamSharedData.reqBuffer[2];
}
#endif




/* ======= User Callout Functions for SecurityAccess ======= */

/** \brief Get number of failed attempts of a certain security level
 **
 ** The function Rte_DcmSetNumAtt() shall set the number of failed attempts for security access.The
 ** central diagnostic SwC has to store the number of failed attempts value into some kind of
 ** non-volatile memory.
 **
 **
 ** \return number of failed attempts
 **/
FUNC(uint8, DCM_APPL_CODE) Rte_DcmSecGetNumAtt
(
)
{
	Std_ReturnType ret;
	uint32 u32Val;
	ret = NVMS_ReadBlockSync( NVMS_BLOCK_SAK_BreakInTries, (uint8*)&u32Val );
	if( ret != E_OK )
	{
		return 0x00u;
	}
    return (uint8)u32Val;
}

/** \brief Set number of failed attempts of a certain security level
 **
 ** The function Rte_DcmSetNumAtt() shall set the number of failed attempts for security access.The
 ** central diagnostic SwC has to store the number of failed attempts value into some kind of
 ** non-volatile memory.
 **
 ** \param NumAtt Number of failed attempts
 **/
FUNC(void, DCM_APPL_CODE) Rte_DcmSecSetNumAtt
(
    uint8 NumAtt
)
{
    uint32 u32Val = NumAtt;
    NVMS_WriteBlockSync( NVMS_BLOCK_SAK_BreakInTries, (uint8*)&u32Val );
}



/* ======= User Callout Functions for SecurityAccess ======= */



/* ======= User Callout Functions for CommunicationControl ======= */

/* User defined CommunicationControl callback functions */
FUNC(Std_ReturnType, DCM_APPL_CODE) DcmVAGDspComControlPermissionCallout
(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
  /* consider CommControl to be always acceptable. */
  return E_OK;
}

/* ======= User Callout Functions for RoutineControl ======= */
/** \brief User callout functions for DcmDspRoutine_203 */
FUNC(Std_ReturnType,DCM_APPL_CODE) DcmRoutineStart_0203
(
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) InBuffer,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) OutBuffer,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
)
{
    // Check the preconditions in the following order
    // 0x01 - The Engine speed must be zero (Drehzahl = 0).
    // 0x05 - The Vehicle speed must be zero (Geschwindigkeit = 0).
    // 0x0A - The voltage must be in normal range.
    // 0x81 - Security Lock Timer must not be active
    // 0xA2 - Car shall not be parked over infrastructure part

    uint8 u8Counter = 0u;
    uint8 u8SaAttempts = 0u;
    uint16 u16VoltageMin_mV = 3000u;
    uint16 u16VoltageMax_mV = 3800u;
    uint16 u16Voltage_mV = 3300u;
    boolean PrecondOk;

    DCM_PARAM_UNUSED(InBuffer);

    CheckSecurityAccessAndVoltage( &u8SaAttempts, &u16Voltage_mV );
    if( u8SaAttempts >= DCM_SECURITY_ATTEMPTS_UNTIL_DELAY )
    {
        OutBuffer[u8Counter+2] = 0x81u;
        u8Counter++;
    }
/* TODO:
#if (VM_SETMAX > 1)
    // in case we have defined low and high voltage boundaries
    if( VM_SetContextPara[0].enType == VM_SETTYPE_UV )
    {
        u16VoltageMin_mV = VM_SetContextPara[0].uiThreshold;
    }
    if( VM_SetContextPara[0].enType == VM_SETTYPE_OV )
    {
        u16VoltageMax_mV = VM_SetContextPara[0].uiThreshold;
    }
    if( VM_SetContextPara[1].enType == VM_SETTYPE_UV )
    {
        u16VoltageMin_mV = VM_SetContextPara[1].uiThreshold;
    }
    if( VM_SetContextPara[1].enType == VM_SETTYPE_OV )
    {
        u16VoltageMax_mV = VM_SetContextPara[1].uiThreshold;
    }
#endif
*/
    if(( u16Voltage_mV < u16VoltageMin_mV ) || ( u16Voltage_mV > u16VoltageMax_mV ))
    {
        OutBuffer[u8Counter+2] = 0x0Au;
        u8Counter++;
    }

    FLSMGR_GetPrecondState( &PrecondOk );
    if( PrecondOk == 0 )
    {
        OutBuffer[u8Counter+2] = 0xA2u;
        u8Counter++;
    }

    // dinamic responce size is uint16 MSB
    OutBuffer[0] = 0;
    OutBuffer[1] = u8Counter;

    // this routine allways return positive response
    ErrorCode[0] = E_OK;
    return E_OK;
}


/* ======= User Callout Functions for Dcm_TxConfirmation ======= */



/* ======= User Callout Functions for service EcuReset (0x11) ======= */

/** \brief User callout function for DcmDspEcuReset
 **
 ** This function is called by the Dcm-Wrapper to check the preconditions before execution
 ** of an EcuReset service.
 **
 ** \param[in]   resetType     Reset type
 ** \param[out]  NRC           NRC which is returned to the tester
 ** \retval      E_OK          Request positiv response
 ** \retval      E_NOT_OK      Trigger negative response with the NRC value returned in ErrorCode
 ** \retval      DCM_E_PENDING Invoke this function again in next cycle
 */
extern FUNC(Std_ReturnType,DCM_APPL_CODE) DcmExt_CheckEcuResetPrecondition
(
  uint8 resetType,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
)
{
  DCM_PARAM_UNUSED(ErrorCode);
  DCM_PARAM_UNUSED(resetType);
  return E_OK;
}


/* ======= User Callout Functions for service InputOutputControlByIdentifier (0x2F) ======= */




/* ======= User Callout Functions for service ReadDataByIdentifier (0x22) ======= */

/* User callout functions for DcmDspDid_ff3f */
extern VAR(FOD_NullVector, RTE_VAR) Pim_NullVector_pim;

FUNC(Std_ReturnType,DCM_APPL_CODE) DidCondCheckRead_ff3f
(
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) nrc
)
{
    Std_ReturnType status = RTE_E_OK;
    nrc[0] = RTE_E_OK;

    return status;
}

FUNC(Std_ReturnType,DCM_APPL_CODE) DidReadData_ff3f
(
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) data
)
{
    return NvmExt_DiagRead( NvmExt_NvBlockNeeds, data );
}


/* ======= User Callout Functions for service InputOutputControlByIdentifier (0x2F) ======= */




/* ======= User Callout Functions for service ReadDataByIdentifier (0x22) ======= */



#define DCM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/** @} doxygen end group definition */
/*==================[end of file]============================================*/
