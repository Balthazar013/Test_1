#if !defined(RTE_DEM_TYPE_H)
#define RTE_DEM_TYPE_H

/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /*
  * This file contains the application-specific types for component type Dem
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.75
  * on Fri Feb 09 11:09:50 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <Rte_Type.h>         /* RTE types header file */

/*==================[macros]=================================================*/

/*------------------[enumeration constants]----------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#ifndef DEM_EVENT_STATUS_PASSED
#define DEM_EVENT_STATUS_PASSED 0U
#endif /* DEM_EVENT_STATUS_PASSED */

#ifndef DEM_EVENT_STATUS_FAILED
#define DEM_EVENT_STATUS_FAILED 1U
#endif /* DEM_EVENT_STATUS_FAILED */

#ifndef DEM_EVENT_STATUS_PREPASSED
#define DEM_EVENT_STATUS_PREPASSED 2U
#endif /* DEM_EVENT_STATUS_PREPASSED */

#ifndef DEM_EVENT_STATUS_PREFAILED
#define DEM_EVENT_STATUS_PREFAILED 3U
#endif /* DEM_EVENT_STATUS_PREFAILED */

#ifndef DEM_UDS_STATUS_TF
#define DEM_UDS_STATUS_TF 1U
#endif /* DEM_UDS_STATUS_TF */

#ifndef DEM_UDS_STATUS_TFTOC
#define DEM_UDS_STATUS_TFTOC 2U
#endif /* DEM_UDS_STATUS_TFTOC */

#ifndef DEM_UDS_STATUS_PDTC
#define DEM_UDS_STATUS_PDTC 4U
#endif /* DEM_UDS_STATUS_PDTC */

#ifndef DEM_UDS_STATUS_CDTC
#define DEM_UDS_STATUS_CDTC 8U
#endif /* DEM_UDS_STATUS_CDTC */

#ifndef DEM_UDS_STATUS_TNCSLC
#define DEM_UDS_STATUS_TNCSLC 16U
#endif /* DEM_UDS_STATUS_TNCSLC */

#ifndef DEM_UDS_STATUS_TFSLC
#define DEM_UDS_STATUS_TFSLC 32U
#endif /* DEM_UDS_STATUS_TFSLC */

#ifndef DEM_UDS_STATUS_TNCTOC
#define DEM_UDS_STATUS_TNCTOC 64U
#endif /* DEM_UDS_STATUS_TNCTOC */

#ifndef DEM_UDS_STATUS_WIR
#define DEM_UDS_STATUS_WIR 128U
#endif /* DEM_UDS_STATUS_WIR */

#ifndef DEM_DTC_KIND_ALL_DTCS
#define DEM_DTC_KIND_ALL_DTCS 1U
#endif /* DEM_DTC_KIND_ALL_DTCS */

#ifndef DEM_DTC_KIND_EMISSION_REL_DTCS
#define DEM_DTC_KIND_EMISSION_REL_DTCS 2U
#endif /* DEM_DTC_KIND_EMISSION_REL_DTCS */

#ifndef DEM_INIT_MONITOR_CLEAR
#define DEM_INIT_MONITOR_CLEAR 1U
#endif /* DEM_INIT_MONITOR_CLEAR */

#ifndef DEM_INIT_MONITOR_RESTART
#define DEM_INIT_MONITOR_RESTART 2U
#endif /* DEM_INIT_MONITOR_RESTART */

#ifndef DEM_CYCLE_STATE_START
#define DEM_CYCLE_STATE_START 1U
#endif /* DEM_CYCLE_STATE_START */

#ifndef DEM_CYCLE_STATE_END
#define DEM_CYCLE_STATE_END 2U
#endif /* DEM_CYCLE_STATE_END */

#ifndef DEM_INDICATOR_OFF
#define DEM_INDICATOR_OFF 0U
#endif /* DEM_INDICATOR_OFF */

#ifndef DEM_INDICATOR_CONTINUOUS
#define DEM_INDICATOR_CONTINUOUS 1U
#endif /* DEM_INDICATOR_CONTINUOUS */

#ifndef DEM_INDICATOR_BLINKING
#define DEM_INDICATOR_BLINKING 2U
#endif /* DEM_INDICATOR_BLINKING */

#ifndef DEM_INDICATOR_BLINK_CONT
#define DEM_INDICATOR_BLINK_CONT 3U
#endif /* DEM_INDICATOR_BLINK_CONT */

#ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED 145U
#endif /* DCM_E_TORQUECONVERTERCLUTCHLOCKED */

#ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#define DCM_E_THROTTLE_PEDALTOOHIGH 138U
#endif /* DCM_E_THROTTLE_PEDALTOOHIGH */

#ifndef DCM_E_ENGINEISRUNNING
#define DCM_E_ENGINEISRUNNING 131U
#endif /* DCM_E_ENGINEISRUNNING */

#ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#define DCM_E_GENERALPROGRAMMINGFAILURE 114U
#endif /* DCM_E_GENERALPROGRAMMINGFAILURE */

#ifndef DCM_E_VOLTAGETOOHIGH
#define DCM_E_VOLTAGETOOHIGH 146U
#endif /* DCM_E_VOLTAGETOOHIGH */

#ifndef DCM_E_SECURITYACCESSDENIED
#define DCM_E_SECURITYACCESSDENIED 51U
#endif /* DCM_E_SECURITYACCESSDENIED */

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION 126U
#endif /* DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION */

#ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION 127U
#endif /* DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION */

#ifndef DCM_E_REQUESTOUTOFRANGE
#define DCM_E_REQUESTOUTOFRANGE 49U
#endif /* DCM_E_REQUESTOUTOFRANGE */

#ifndef DCM_E_ENGINERUNTIMETOOLOW
#define DCM_E_ENGINERUNTIMETOOLOW 133U
#endif /* DCM_E_ENGINERUNTIMETOOLOW */

#ifndef DCM_E_RPMTOOLOW
#define DCM_E_RPMTOOLOW 130U
#endif /* DCM_E_RPMTOOLOW */

#ifndef DCM_E_RPMTOOHIGH
#define DCM_E_RPMTOOHIGH 129U
#endif /* DCM_E_RPMTOOHIGH */

#ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#define DCM_E_TRANSMISSIONRANGENOTINGEAR 141U
#endif /* DCM_E_TRANSMISSIONRANGENOTINGEAR */

#ifndef DCM_E_SHIFTERLEVERNOTINPARK
#define DCM_E_SHIFTERLEVERNOTINPARK 144U
#endif /* DCM_E_SHIFTERLEVERNOTINPARK */

#ifndef DCM_E_CONDITIONSNOTCORRECT
#define DCM_E_CONDITIONSNOTCORRECT 34U
#endif /* DCM_E_CONDITIONSNOTCORRECT */

#ifndef DCM_E_VEHICLESPEEDTOOHIGH
#define DCM_E_VEHICLESPEEDTOOHIGH 136U
#endif /* DCM_E_VEHICLESPEEDTOOHIGH */

#ifndef DCM_E_VOLTAGETOOLOW
#define DCM_E_VOLTAGETOOLOW 147U
#endif /* DCM_E_VOLTAGETOOLOW */

#ifndef DCM_E_BUSYREPEATREQUEST
#define DCM_E_BUSYREPEATREQUEST 33U
#endif /* DCM_E_BUSYREPEATREQUEST */

#ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL 140U
#endif /* DCM_E_TRANSMISSIONRANGENOTINNEUTRAL */

#ifndef DCM_E_THROTTLE_PEDALTOOLOW
#define DCM_E_THROTTLE_PEDALTOOLOW 139U
#endif /* DCM_E_THROTTLE_PEDALTOOLOW */

#ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#define DCM_E_BRAKESWITCH_NOTCLOSED 143U
#endif /* DCM_E_BRAKESWITCH_NOTCLOSED */

#ifndef DCM_E_ENGINEISNOTRUNNING
#define DCM_E_ENGINEISNOTRUNNING 132U
#endif /* DCM_E_ENGINEISNOTRUNNING */

#ifndef DCM_E_GENERALREJECT
#define DCM_E_GENERALREJECT 16U
#endif /* DCM_E_GENERALREJECT */

#ifndef DCM_E_VEHICLESPEEDTOOLOW
#define DCM_E_VEHICLESPEEDTOOLOW 137U
#endif /* DCM_E_VEHICLESPEEDTOOLOW */

#ifndef DCM_E_TEMPERATURETOOHIGH
#define DCM_E_TEMPERATURETOOHIGH 134U
#endif /* DCM_E_TEMPERATURETOOHIGH */

#ifndef DCM_E_TEMPERATURETOOLOW
#define DCM_E_TEMPERATURETOOLOW 135U
#endif /* DCM_E_TEMPERATURETOOLOW */

#ifndef DCM_E_REQUESTSEQUENCEERROR
#define DCM_E_REQUESTSEQUENCEERROR 36U
#endif /* DCM_E_REQUESTSEQUENCEERROR */

#ifndef DCM_E_SERVICENOTSUPPORTED
#define DCM_E_SERVICENOTSUPPORTED 17U
#endif /* DCM_E_SERVICENOTSUPPORTED */

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#define DCM_E_SUBFUNCTIONNOTSUPPORTED 18U
#endif /* DCM_E_SUBFUNCTIONNOTSUPPORTED */

#ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT 19U
#endif /* DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT */

#ifndef DCM_E_INVALIDKEY
#define DCM_E_INVALIDKEY 53U
#endif /* DCM_E_INVALIDKEY */

#ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#define DCM_E_EXCEEDNUMBEROFATTEMPTS 54U
#endif /* DCM_E_EXCEEDNUMBEROFATTEMPTS */

#ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED 55U
#endif /* DCM_E_REQUIREDTIMEDELAYNOTEXPIRED */

#endif /* (!defined RTE_CORE) */

/*------------------[range definitions]--------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif /* (!defined RTE_CORE) */

/*------------------[invalid values]-----------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif /* (!defined RTE_CORE) */

/*------------------[mode declarations]--------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif /* (!defined RTE_CORE) */

/*==================[type definitions]=======================================*/

/*------------------[mode declaration group types]---------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif /* (!defined RTE_CORE) */

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
/** @} doxygen end group definition */
#endif /* !defined(RTE_DEM_TYPE_H) */
/*==================[end of file]============================================*/
