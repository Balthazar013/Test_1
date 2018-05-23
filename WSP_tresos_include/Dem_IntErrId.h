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
#if (!defined DEM_INT_ERR_ID_H)
#define DEM_INT_ERR_ID_H

/* This file contains the configuration declarations of the
 * BSW Event ID symbols for AUTOSAR module Dem. */

/*==================[inclusions]============================================*/

/** \brief Id for invalid events  */
#define DEM_INVALID_EVENT_ID_BSW 255U
/*==================[macros]================================================*/

/*------------------[Events configuration]----------------------------------*/

/* Symbolic names of configured BSW event IDs */

#if (defined MCU_E_TIMEOUT_FAILURE)
#error MCU_E_TIMEOUT_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_TIMEOUT_FAILURE  */
#define MCU_E_TIMEOUT_FAILURE \
0U

#if (defined MCU_E_DEFAULTCASE_FAILURE)
#error MCU_E_DEFAULTCASE_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_DEFAULTCASE_FAILURE  */
#define MCU_E_DEFAULTCASE_FAILURE \
1U

#if (defined MCU_E_FORBIDDEN_INVOCATION)
#error MCU_E_FORBIDDEN_INVOCATION already defined
#endif
/** \brief Symbolic name of event MCU_E_FORBIDDEN_INVOCATION  */
#define MCU_E_FORBIDDEN_INVOCATION \
2U

#if (defined MCU_E_INVALID_PARAMETER)
#error MCU_E_INVALID_PARAMETER already defined
#endif
/** \brief Symbolic name of event MCU_E_INVALID_PARAMETER  */
#define MCU_E_INVALID_PARAMETER \
3U

#if (defined MCU_E_CLOCK_FAILURE)
#error MCU_E_CLOCK_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_CLOCK_FAILURE  */
#define MCU_E_CLOCK_FAILURE \
4U

#if (defined MCU_E_QUARTZ_FAILURE)
#error MCU_E_QUARTZ_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_QUARTZ_FAILURE  */
#define MCU_E_QUARTZ_FAILURE \
5U

#if (defined MCU_E_PLLLOCK_FAILURE)
#error MCU_E_PLLLOCK_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_PLLLOCK_FAILURE  */
#define MCU_E_PLLLOCK_FAILURE \
6U

#if (defined MCU_E_FUNCRESET_FAILURE)
#error MCU_E_FUNCRESET_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_FUNCRESET_FAILURE  */
#define MCU_E_FUNCRESET_FAILURE \
7U

#if (defined MCU_E_DESTRESET_FAILURE)
#error MCU_E_DESTRESET_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_DESTRESET_FAILURE  */
#define MCU_E_DESTRESET_FAILURE \
8U

#if (defined MCU_E_SAFEMODE_FAILURE)
#error MCU_E_SAFEMODE_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_SAFEMODE_FAILURE  */
#define MCU_E_SAFEMODE_FAILURE \
9U

#if (defined MCU_E_INVALIDMODE)
#error MCU_E_INVALIDMODE already defined
#endif
/** \brief Symbolic name of event MCU_E_INVALIDMODE  */
#define MCU_E_INVALIDMODE \
10U

#if (defined MCU_E_INVALIDMODE_CONFIG)
#error MCU_E_INVALIDMODE_CONFIG already defined
#endif
/** \brief Symbolic name of event MCU_E_INVALIDMODE_CONFIG  */
#define MCU_E_INVALIDMODE_CONFIG \
11U

#if (defined MCU_E_VOLTAGE_ERROR)
#error MCU_E_VOLTAGE_ERROR already defined
#endif
/** \brief Symbolic name of event MCU_E_VOLTAGE_ERROR  */
#define MCU_E_VOLTAGE_ERROR \
12U

#if (defined MCU_E_TEMPERATURE_ERROR)
#error MCU_E_TEMPERATURE_ERROR already defined
#endif
/** \brief Symbolic name of event MCU_E_TEMPERATURE_ERROR  */
#define MCU_E_TEMPERATURE_ERROR \
13U

#if (defined MCU_E_SSCM_CER_FAILURE)
#error MCU_E_SSCM_CER_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_SSCM_CER_FAILURE  */
#define MCU_E_SSCM_CER_FAILURE \
14U

#if (defined MCU_E_CER_FAILURE)
#error MCU_E_CER_FAILURE already defined
#endif
/** \brief Symbolic name of event MCU_E_CER_FAILURE  */
#define MCU_E_CER_FAILURE \
15U

#if (defined GPT_E_FORBIDDEN_INVOCATION)
#error GPT_E_FORBIDDEN_INVOCATION already defined
#endif
/** \brief Symbolic name of event GPT_E_FORBIDDEN_INVOCATION  */
#define GPT_E_FORBIDDEN_INVOCATION \
21U

#if (defined MCL_DMA_E_DESCRIPTOR)
#error MCL_DMA_E_DESCRIPTOR already defined
#endif
/** \brief Symbolic name of event MCL_DMA_E_DESCRIPTOR  */
#define MCL_DMA_E_DESCRIPTOR \
22U

#if (defined MCL_DMA_E_ECC)
#error MCL_DMA_E_ECC already defined
#endif
/** \brief Symbolic name of event MCL_DMA_E_ECC  */
#define MCL_DMA_E_ECC \
23U

#if (defined MCL_DMA_E_BUS)
#error MCL_DMA_E_BUS already defined
#endif
/** \brief Symbolic name of event MCL_DMA_E_BUS  */
#define MCL_DMA_E_BUS \
24U

#if (defined MCL_DMA_E_PRIORITY)
#error MCL_DMA_E_PRIORITY already defined
#endif
/** \brief Symbolic name of event MCL_DMA_E_PRIORITY  */
#define MCL_DMA_E_PRIORITY \
25U

#if (defined FLS_E_ERASE_FAILED)
#error FLS_E_ERASE_FAILED already defined
#endif
/** \brief Symbolic name of event FLS_E_ERASE_FAILED  */
#define FLS_E_ERASE_FAILED \
26U

#if (defined FLS_E_READ_FAILED)
#error FLS_E_READ_FAILED already defined
#endif
/** \brief Symbolic name of event FLS_E_READ_FAILED  */
#define FLS_E_READ_FAILED \
27U

#if (defined FLS_E_UNEXPECTED_FLASH_ID)
#error FLS_E_UNEXPECTED_FLASH_ID already defined
#endif
/** \brief Symbolic name of event FLS_E_UNEXPECTED_FLASH_ID  */
#define FLS_E_UNEXPECTED_FLASH_ID \
28U

#if (defined FLS_E_WRITE_FAILED)
#error FLS_E_WRITE_FAILED already defined
#endif
/** \brief Symbolic name of event FLS_E_WRITE_FAILED  */
#define FLS_E_WRITE_FAILED \
29U

#if (defined FLS_E_COMPARE_FAILED)
#error FLS_E_COMPARE_FAILED already defined
#endif
/** \brief Symbolic name of event FLS_E_COMPARE_FAILED  */
#define FLS_E_COMPARE_FAILED \
30U

#if (defined ECUM_E_RAM_CHECK_FAILED)
#error ECUM_E_RAM_CHECK_FAILED already defined
#endif
/** \brief Symbolic name of event ECUM_E_RAM_CHECK_FAILED  */
#define ECUM_E_RAM_CHECK_FAILED \
31U

#if (defined ECUM_E_ALL_RUN_REQUESTS_KILLED)
#error ECUM_E_ALL_RUN_REQUESTS_KILLED already defined
#endif
/** \brief Symbolic name of event ECUM_E_ALL_RUN_REQUESTS_KILLED  */
#define ECUM_E_ALL_RUN_REQUESTS_KILLED \
32U

#if (defined ADC_E_TIMEOUT)
#error ADC_E_TIMEOUT already defined
#endif
/** \brief Symbolic name of event ADC_E_TIMEOUT  */
#define ADC_E_TIMEOUT \
33U

#if (defined SPI_E_HARDWARE_ERROR)
#error SPI_E_HARDWARE_ERROR already defined
#endif
/** \brief Symbolic name of event SPI_E_HARDWARE_ERROR  */
#define SPI_E_HARDWARE_ERROR \
34U

#if (defined MCL_DMA_E_INCONSISTENCY)
#error MCL_DMA_E_INCONSISTENCY already defined
#endif
/** \brief Symbolic name of event MCL_DMA_E_INCONSISTENCY  */
#define MCL_DMA_E_INCONSISTENCY \
35U

#if (defined MCL_DMA_E_UNRECOGNIZED)
#error MCL_DMA_E_UNRECOGNIZED already defined
#endif
/** \brief Symbolic name of event MCL_DMA_E_UNRECOGNIZED  */
#define MCL_DMA_E_UNRECOGNIZED \
36U

#if (defined WPC_TEMPERATURE_HIGH)
#error WPC_TEMPERATURE_HIGH already defined
#endif
/** \brief Symbolic name of event WPC_TEMPERATURE_HIGH  */
#define WPC_TEMPERATURE_HIGH \
97U

#if (defined SWITCH_CURR_2_TOO_HIGH)
#error SWITCH_CURR_2_TOO_HIGH already defined
#endif
/** \brief Symbolic name of event SWITCH_CURR_2_TOO_HIGH  */
#define SWITCH_CURR_2_TOO_HIGH \
128U

#if (defined WPC_PH1_CURR_EXCEEDED)
#error WPC_PH1_CURR_EXCEEDED already defined
#endif
/** \brief Symbolic name of event WPC_PH1_CURR_EXCEEDED  */
#define WPC_PH1_CURR_EXCEEDED \
131U

#if (defined SEC_KEYUPDATE_FAILURE_PAD)
#error SEC_KEYUPDATE_FAILURE_PAD already defined
#endif
/** \brief Symbolic name of event SEC_KEYUPDATE_FAILURE_PAD  */
#define SEC_KEYUPDATE_FAILURE_PAD \
163U

#if (defined SEC_MSG_ENCYPTION_FAILURE_PAD)
#error SEC_MSG_ENCYPTION_FAILURE_PAD already defined
#endif
/** \brief Symbolic name of event SEC_MSG_ENCYPTION_FAILURE_PAD  */
#define SEC_MSG_ENCYPTION_FAILURE_PAD \
164U

#if (defined SEC_PIN_CHANGING_STATUS_PAD)
#error SEC_PIN_CHANGING_STATUS_PAD already defined
#endif
/** \brief Symbolic name of event SEC_PIN_CHANGING_STATUS_PAD  */
#define SEC_PIN_CHANGING_STATUS_PAD \
165U

#if (defined SEC_USER_AUTHENTICATION_STATUS_PAD)
#error SEC_USER_AUTHENTICATION_STATUS_PAD already defined
#endif
/** \brief Symbolic name of event SEC_USER_AUTHENTICATION_STATUS_PAD  */
#define SEC_USER_AUTHENTICATION_STATUS_PAD \
166U

#if (defined SEC_ADMIN_AUTHENTICATION_STATUS_PAD)
#error SEC_ADMIN_AUTHENTICATION_STATUS_PAD already defined
#endif
/** \brief Symbolic name of event SEC_ADMIN_AUTHENTICATION_STATUS_PAD  */
#define SEC_ADMIN_AUTHENTICATION_STATUS_PAD \
167U

#if (defined SEC_SECURECONNECTION_STATUS_PAD)
#error SEC_SECURECONNECTION_STATUS_PAD already defined
#endif
/** \brief Symbolic name of event SEC_SECURECONNECTION_STATUS_PAD  */
#define SEC_SECURECONNECTION_STATUS_PAD \
168U

#if (defined SEC_INTERNAL_MALFUNCTION_PAD)
#error SEC_INTERNAL_MALFUNCTION_PAD already defined
#endif
/** \brief Symbolic name of event SEC_INTERNAL_MALFUNCTION_PAD  */
#define SEC_INTERNAL_MALFUNCTION_PAD \
169U

#if (defined SEC_AUTHENTICATION_MSG_FAILED_PAD)
#error SEC_AUTHENTICATION_MSG_FAILED_PAD already defined
#endif
/** \brief Symbolic name of event SEC_AUTHENTICATION_MSG_FAILED_PAD  */
#define SEC_AUTHENTICATION_MSG_FAILED_PAD \
170U

#if (defined SEC_UNKNOWN_MSG_RECEIVED_PAD)
#error SEC_UNKNOWN_MSG_RECEIVED_PAD already defined
#endif
/** \brief Symbolic name of event SEC_UNKNOWN_MSG_RECEIVED_PAD  */
#define SEC_UNKNOWN_MSG_RECEIVED_PAD \
171U

#if (defined SEC_MSG_DECRYPTION_FAILURE_PAD)
#error SEC_MSG_DECRYPTION_FAILURE_PAD already defined
#endif
/** \brief Symbolic name of event SEC_MSG_DECRYPTION_FAILURE_PAD  */
#define SEC_MSG_DECRYPTION_FAILURE_PAD \
172U

#if (defined WDGM_E_MONITORING)
#error WDGM_E_MONITORING already defined
#endif
/** \brief Symbolic name of event WDGM_E_MONITORING  */
#define WDGM_E_MONITORING \
173U

#if (defined WDGM_E_SET_MODE)
#error WDGM_E_SET_MODE already defined
#endif
/** \brief Symbolic name of event WDGM_E_SET_MODE  */
#define WDGM_E_SET_MODE \
174U

#if (defined WDGM_E_DATA_CORRUPTION)
#error WDGM_E_DATA_CORRUPTION already defined
#endif
/** \brief Symbolic name of event WDGM_E_DATA_CORRUPTION  */
#define WDGM_E_DATA_CORRUPTION \
175U

/* Additional symbolic names of configured BSW event IDs */

#if (defined DemConf_DemEventParameter_MCU_E_TIMEOUT_FAILURE)
#error DemConf_DemEventParameter_MCU_E_TIMEOUT_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_TIMEOUT_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_TIMEOUT_FAILURE \
0U

#if (defined DemConf_DemEventParameter_MCU_E_DEFAULTCASE_FAILURE)
#error DemConf_DemEventParameter_MCU_E_DEFAULTCASE_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_DEFAULTCASE_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_DEFAULTCASE_FAILURE \
1U

#if (defined DemConf_DemEventParameter_MCU_E_FORBIDDEN_INVOCATION)
#error DemConf_DemEventParameter_MCU_E_FORBIDDEN_INVOCATION already defined
#endif
/** \brief Additional symbolic name of event MCU_E_FORBIDDEN_INVOCATION  */
#define DemConf_DemEventParameter_MCU_E_FORBIDDEN_INVOCATION \
2U

#if (defined DemConf_DemEventParameter_MCU_E_INVALID_PARAMETER)
#error DemConf_DemEventParameter_MCU_E_INVALID_PARAMETER already defined
#endif
/** \brief Additional symbolic name of event MCU_E_INVALID_PARAMETER  */
#define DemConf_DemEventParameter_MCU_E_INVALID_PARAMETER \
3U

#if (defined DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE)
#error DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_CLOCK_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE \
4U

#if (defined DemConf_DemEventParameter_MCU_E_QUARTZ_FAILURE)
#error DemConf_DemEventParameter_MCU_E_QUARTZ_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_QUARTZ_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_QUARTZ_FAILURE \
5U

#if (defined DemConf_DemEventParameter_MCU_E_PLLLOCK_FAILURE)
#error DemConf_DemEventParameter_MCU_E_PLLLOCK_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_PLLLOCK_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_PLLLOCK_FAILURE \
6U

#if (defined DemConf_DemEventParameter_MCU_E_FUNCRESET_FAILURE)
#error DemConf_DemEventParameter_MCU_E_FUNCRESET_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_FUNCRESET_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_FUNCRESET_FAILURE \
7U

#if (defined DemConf_DemEventParameter_MCU_E_DESTRESET_FAILURE)
#error DemConf_DemEventParameter_MCU_E_DESTRESET_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_DESTRESET_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_DESTRESET_FAILURE \
8U

#if (defined DemConf_DemEventParameter_MCU_E_SAFEMODE_FAILURE)
#error DemConf_DemEventParameter_MCU_E_SAFEMODE_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_SAFEMODE_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_SAFEMODE_FAILURE \
9U

#if (defined DemConf_DemEventParameter_MCU_E_INVALIDMODE)
#error DemConf_DemEventParameter_MCU_E_INVALIDMODE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_INVALIDMODE  */
#define DemConf_DemEventParameter_MCU_E_INVALIDMODE \
10U

#if (defined DemConf_DemEventParameter_MCU_E_INVALIDMODE_CONFIG)
#error DemConf_DemEventParameter_MCU_E_INVALIDMODE_CONFIG already defined
#endif
/** \brief Additional symbolic name of event MCU_E_INVALIDMODE_CONFIG  */
#define DemConf_DemEventParameter_MCU_E_INVALIDMODE_CONFIG \
11U

#if (defined DemConf_DemEventParameter_MCU_E_VOLTAGE_ERROR)
#error DemConf_DemEventParameter_MCU_E_VOLTAGE_ERROR already defined
#endif
/** \brief Additional symbolic name of event MCU_E_VOLTAGE_ERROR  */
#define DemConf_DemEventParameter_MCU_E_VOLTAGE_ERROR \
12U

#if (defined DemConf_DemEventParameter_MCU_E_TEMPERATURE_ERROR)
#error DemConf_DemEventParameter_MCU_E_TEMPERATURE_ERROR already defined
#endif
/** \brief Additional symbolic name of event MCU_E_TEMPERATURE_ERROR  */
#define DemConf_DemEventParameter_MCU_E_TEMPERATURE_ERROR \
13U

#if (defined DemConf_DemEventParameter_MCU_E_SSCM_CER_FAILURE)
#error DemConf_DemEventParameter_MCU_E_SSCM_CER_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_SSCM_CER_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_SSCM_CER_FAILURE \
14U

#if (defined DemConf_DemEventParameter_MCU_E_CER_FAILURE)
#error DemConf_DemEventParameter_MCU_E_CER_FAILURE already defined
#endif
/** \brief Additional symbolic name of event MCU_E_CER_FAILURE  */
#define DemConf_DemEventParameter_MCU_E_CER_FAILURE \
15U

#if (defined DemConf_DemEventParameter_GPT_E_FORBIDDEN_INVOCATION)
#error DemConf_DemEventParameter_GPT_E_FORBIDDEN_INVOCATION already defined
#endif
/** \brief Additional symbolic name of event GPT_E_FORBIDDEN_INVOCATION  */
#define DemConf_DemEventParameter_GPT_E_FORBIDDEN_INVOCATION \
21U

#if (defined DemConf_DemEventParameter_MCL_DMA_E_DESCRIPTOR)
#error DemConf_DemEventParameter_MCL_DMA_E_DESCRIPTOR already defined
#endif
/** \brief Additional symbolic name of event MCL_DMA_E_DESCRIPTOR  */
#define DemConf_DemEventParameter_MCL_DMA_E_DESCRIPTOR \
22U

#if (defined DemConf_DemEventParameter_MCL_DMA_E_ECC)
#error DemConf_DemEventParameter_MCL_DMA_E_ECC already defined
#endif
/** \brief Additional symbolic name of event MCL_DMA_E_ECC  */
#define DemConf_DemEventParameter_MCL_DMA_E_ECC \
23U

#if (defined DemConf_DemEventParameter_MCL_DMA_E_BUS)
#error DemConf_DemEventParameter_MCL_DMA_E_BUS already defined
#endif
/** \brief Additional symbolic name of event MCL_DMA_E_BUS  */
#define DemConf_DemEventParameter_MCL_DMA_E_BUS \
24U

#if (defined DemConf_DemEventParameter_MCL_DMA_E_PRIORITY)
#error DemConf_DemEventParameter_MCL_DMA_E_PRIORITY already defined
#endif
/** \brief Additional symbolic name of event MCL_DMA_E_PRIORITY  */
#define DemConf_DemEventParameter_MCL_DMA_E_PRIORITY \
25U

#if (defined Dem_ECUM_E_RAM_CHECK_FAILED)
#error Dem_ECUM_E_RAM_CHECK_FAILED already defined
#endif
/** \brief Additional symbolic name of event ECUM_E_RAM_CHECK_FAILED  */
#define Dem_ECUM_E_RAM_CHECK_FAILED \
31U

#if (defined Dem_ECUM_E_ALL_RUN_REQUESTS_KILLED)
#error Dem_ECUM_E_ALL_RUN_REQUESTS_KILLED already defined
#endif
/** \brief Additional symbolic name of event ECUM_E_ALL_RUN_REQUESTS_KILLED  */
#define Dem_ECUM_E_ALL_RUN_REQUESTS_KILLED \
32U

#if (defined DemConf_DemEventParameter_ADC_E_TIMEOUT)
#error DemConf_DemEventParameter_ADC_E_TIMEOUT already defined
#endif
/** \brief Additional symbolic name of event ADC_E_TIMEOUT  */
#define DemConf_DemEventParameter_ADC_E_TIMEOUT \
33U

#if (defined DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR)
#error DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR already defined
#endif
/** \brief Additional symbolic name of event SPI_E_HARDWARE_ERROR  */
#define DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR \
34U

#if (defined DemConf_DemEventParameter_MCL_DMA_E_INCONSISTENCY)
#error DemConf_DemEventParameter_MCL_DMA_E_INCONSISTENCY already defined
#endif
/** \brief Additional symbolic name of event MCL_DMA_E_INCONSISTENCY  */
#define DemConf_DemEventParameter_MCL_DMA_E_INCONSISTENCY \
35U

#if (defined DemConf_DemEventParameter_MCL_DMA_E_UNRECOGNIZED)
#error DemConf_DemEventParameter_MCL_DMA_E_UNRECOGNIZED already defined
#endif
/** \brief Additional symbolic name of event MCL_DMA_E_UNRECOGNIZED  */
#define DemConf_DemEventParameter_MCL_DMA_E_UNRECOGNIZED \
36U

/* Symbolic names of configured BSW invalid event IDs */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_INT_ERR_ID_H ) */
/*==================[end of file]===========================================*/
