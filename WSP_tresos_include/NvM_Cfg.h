/**
 * \file
 *
 * \brief AUTOSAR NvM
 *
 * This file contains the implementation of the AUTOSAR
 * module NvM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO NVM030,1 */

#if (!defined NVM_CFG_H)
#define NVM_CFG_H
/* !LINKSTO NVM028,1 */
/*==================[inclusions]============================================*/

/* !LINKSTO NVM689,1 */
#include <NvM_Types.h>        /* contains NvM specific types. NVM689 */
#include <Std_Types.h>





/*==================[macros]================================================*/

/** \brief Macro switch for DET usage */
#define NVM_DEV_ERROR_DETECT             STD_ON

/** \brief Defines whether a Rte module configuration is available.
 **        If it is available then it is automatically used by the NVRAM Manager.
 **        STD_ON:  Rte configuration is available.
 **        STD_OFF: Rte configuration is not available.
 **/
#define NVM_INCLUDE_RTE                  STD_ON

/** \brief Disables or enables the API NvM_SetRamBlockStatus()
 **/
#define NVM_SET_RAM_BLOCK_STATUS_API     STD_ON

/** \brief Disables or enables the API NvM_VersionInfoApi()
 **/
#define NVM_VERSION_INFO_API             STD_ON

/** \brief Dis- or enable the recovery of blocks()
 **/
#define NVM_ADVANCED_RECOVERY            STD_OFF

#if (defined NVM_PROD_ERR_HANDLING_INTEGRITY_FAILED)
#error NVM_PROD_ERR_HANDLING_INTEGRITY_FAILED already defined
#endif
/** \brief Switch for DEM to DET reporting Integrity Failure
 **/
#define NVM_PROD_ERR_HANDLING_INTEGRITY_FAILED     TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_REQ_FAILED)
#error NVM_PROD_ERR_HANDLING_REQ_FAILED already defined
#endif
/** \brief Switch for DEM to DET reporting Request Failure
 **/
#define NVM_PROD_ERR_HANDLING_REQ_FAILED           TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_LOSS_OF_REDUNDANCY)
#error NVM_PROD_ERR_HANDLING_LOSS_OF_REDUNDANCY already defined
#endif
/** \brief Switch for DEM to DET reporting Loss of Redundancy
 **/
#define NVM_PROD_ERR_HANDLING_LOSS_OF_REDUNDANCY   TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_QUEUE_OVERFLOW)
#error NVM_PROD_ERR_HANDLING_QUEUE_OVERFLOW already defined
#endif
/** \brief Switch for DEM to DET reporting Queue Overflow
 **/
#define NVM_PROD_ERR_HANDLING_QUEUE_OVERFLOW       TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_VERIFY_FAILED)
#error NVM_PROD_ERR_HANDLING_VERIFY_FAILED already defined
#endif
/** \brief Switch for DEM to DET reporting Verify Failure
 **/
#define NVM_PROD_ERR_HANDLING_VERIFY_FAILED        TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_WRITE_PROTECTED)
#error NVM_PROD_ERR_HANDLING_WRITE_PROTECTED already defined
#endif
/** \brief Switch for DEM to DET reporting Write Protection
 **/
#define NVM_PROD_ERR_HANDLING_WRITE_PROTECTED      TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_WRONG_BLOCK_ID)
#error NVM_PROD_ERR_HANDLING_WRONG_BLOCK_ID already defined
#endif
/** \brief Switch for DEM to DET reporting Wrong Block ID
 **/
#define NVM_PROD_ERR_HANDLING_WRONG_BLOCK_ID       TS_PROD_ERR_DISABLE


/** \brief special value: no Dem event id configured
 **        (0 is not a valid value for Dem_EventIdType)
 **/
#define NVM_INVALID_DEM_EVENTID        0U

/** \brief Switch for integrity failure Dem event Id
 **/
#define NVM_INTEGRITY_FAILED_DEM_EVENT_ID NVM_INVALID_DEM_EVENTID

/** \brief Switch for request failure Dem event Id
 **/
#define NVM_REQ_FAILED_DEM_EVENT_ID    NVM_INVALID_DEM_EVENTID

/** \brief Switch for redundancy loss Dem event Id
 **/
#define NVM_REDUNDANCY_LOSS_DEM_EVENT_ID NVM_INVALID_DEM_EVENTID

/** \brief Switch for queue overflow Dem event Id
 **/
#define NVM_QUEUE_OVERFLOW_DEM_EVENT_ID NVM_INVALID_DEM_EVENTID

/** \brief Switch for verify failed Dem event Id
 **/
#define NVM_VERIFY_FAILED_DEM_EVENT_ID NVM_INVALID_DEM_EVENTID

/** \brief Switch for write protection failure Dem event Id
 **/
#define NVM_WRITE_PROT_DEM_EVENT_ID    NVM_INVALID_DEM_EVENTID

/** \brief Switch for wrong block Id Dem event Id
 **/
#define NVM_WRONG_BLOCK_DEM_EVENT_ID   NVM_INVALID_DEM_EVENTID

/** \brief Symbolic name for Block 0.
 **/
#define NVM_BLOCK_MULTI                0U

#if (defined NvMConf_NvMBlockDescriptor_NvMBlock_ConfigID)
#error NvMConf_NvMBlockDescriptor_NvMBlock_ConfigID already defined
#endif
/** \brief  Symbolic name for Block 1 */
#define NvMConf_NvMBlockDescriptor_NvMBlock_ConfigID   1U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvMBlock_ConfigID)
#error NvMBlock_ConfigID already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvMBlock_ConfigID   1U

#if (defined NvM_NvMBlock_ConfigID)
#error NvM_NvMBlock_ConfigID already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvMBlock_ConfigID   1U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvMBlock_DEM_Status)
#error NvMConf_NvMBlockDescriptor_NvMBlock_DEM_Status already defined
#endif
/** \brief  Symbolic name for Block 2 */
#define NvMConf_NvMBlockDescriptor_NvMBlock_DEM_Status   2U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvMBlock_DEM_Status)
#error NvMBlock_DEM_Status already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvMBlock_DEM_Status   2U

#if (defined NvM_NvMBlock_DEM_Status)
#error NvM_NvMBlock_DEM_Status already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvMBlock_DEM_Status   2U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvMBlock_DEM_PRIMARY)
#error NvMConf_NvMBlockDescriptor_NvMBlock_DEM_PRIMARY already defined
#endif
/** \brief  Symbolic name for Block 3 */
#define NvMConf_NvMBlockDescriptor_NvMBlock_DEM_PRIMARY   3U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvMBlock_DEM_PRIMARY)
#error NvMBlock_DEM_PRIMARY already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvMBlock_DEM_PRIMARY   3U

#if (defined NvM_NvMBlock_DEM_PRIMARY)
#error NvM_NvMBlock_DEM_PRIMARY already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvMBlock_DEM_PRIMARY   3U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_PersistentCounterValue)
#error NvMConf_NvMBlockDescriptor_PersistentCounterValue already defined
#endif
/** \brief  Symbolic name for Block 4 */
#define NvMConf_NvMBlockDescriptor_PersistentCounterValue   4U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PersistentCounterValue)
#error PersistentCounterValue already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define PersistentCounterValue   4U

#if (defined NvM_PersistentCounterValue)
#error NvM_PersistentCounterValue already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_PersistentCounterValue   4U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f197)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f197 already defined
#endif
/** \brief  Symbolic name for Block 5 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f197   5U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f197)
#error NvM_DID_f197 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f197   5U

#if (defined NvM_NvM_DID_f197)
#error NvM_NvM_DID_f197 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f197   5U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f17b)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f17b already defined
#endif
/** \brief  Symbolic name for Block 6 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f17b   6U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f17b)
#error NvM_DID_f17b already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f17b   6U

#if (defined NvM_NvM_DID_f17b)
#error NvM_NvM_DID_f17b already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f17b   6U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f19a)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f19a already defined
#endif
/** \brief  Symbolic name for Block 7 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f19a   7U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f19a)
#error NvM_DID_f19a already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f19a   7U

#if (defined NvM_NvM_DID_f19a)
#error NvM_NvM_DID_f19a already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f19a   7U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f19b)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f19b already defined
#endif
/** \brief  Symbolic name for Block 8 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f19b   8U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f19b)
#error NvM_DID_f19b already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f19b   8U

#if (defined NvM_NvM_DID_f19b)
#error NvM_NvM_DID_f19b already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f19b   8U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f1a5)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f1a5 already defined
#endif
/** \brief  Symbolic name for Block 9 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f1a5   9U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f1a5)
#error NvM_DID_f1a5 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f1a5   9U

#if (defined NvM_NvM_DID_f1a5)
#error NvM_NvM_DID_f1a5 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f1a5   9U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f1a9)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f1a9 already defined
#endif
/** \brief  Symbolic name for Block 10 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f1a9   10U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f1a9)
#error NvM_DID_f1a9 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f1a9   10U

#if (defined NvM_NvM_DID_f1a9)
#error NvM_NvM_DID_f1a9 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f1a9   10U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f1aa)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f1aa already defined
#endif
/** \brief  Symbolic name for Block 11 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f1aa   11U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f1aa)
#error NvM_DID_f1aa already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f1aa   11U

#if (defined NvM_NvM_DID_f1aa)
#error NvM_NvM_DID_f1aa already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f1aa   11U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f1a0)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f1a0 already defined
#endif
/** \brief  Symbolic name for Block 12 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f1a0   12U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f1a0)
#error NvM_DID_f1a0 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f1a0   12U

#if (defined NvM_NvM_DID_f1a0)
#error NvM_NvM_DID_f1a0 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f1a0   12U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_DID_f1a4)
#error NvMConf_NvMBlockDescriptor_NvM_DID_f1a4 already defined
#endif
/** \brief  Symbolic name for Block 13 */
#define NvMConf_NvMBlockDescriptor_NvM_DID_f1a4   13U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_DID_f1a4)
#error NvM_DID_f1a4 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_DID_f1a4   13U

#if (defined NvM_NvM_DID_f1a4)
#error NvM_NvM_DID_f1a4 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_DID_f1a4   13U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Name)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Name already defined
#endif
/** \brief  Symbolic name for Block 14 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Name   14U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Name)
#error NvM_BLE_Name already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Name   14U

#if (defined NvM_NvM_BLE_Name)
#error NvM_NvM_BLE_Name already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Name   14U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_ResetsNumber)
#error NvMConf_NvMBlockDescriptor_NvM_ResetsNumber already defined
#endif
/** \brief  Symbolic name for Block 15 */
#define NvMConf_NvMBlockDescriptor_NvM_ResetsNumber   15U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ResetsNumber)
#error NvM_ResetsNumber already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_ResetsNumber   15U

#if (defined NvM_NvM_ResetsNumber)
#error NvM_NvM_ResetsNumber already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_ResetsNumber   15U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvmBlock_NullVectorValid)
#error NvMConf_NvMBlockDescriptor_NvmBlock_NullVectorValid already defined
#endif
/** \brief  Symbolic name for Block 16 */
#define NvMConf_NvMBlockDescriptor_NvmBlock_NullVectorValid   16U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvmBlock_NullVectorValid)
#error NvmBlock_NullVectorValid already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvmBlock_NullVectorValid   16U

#if (defined NvM_NvmBlock_NullVectorValid)
#error NvM_NvmBlock_NullVectorValid already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvmBlock_NullVectorValid   16U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvBlockNeeds)
#error NvMConf_NvMBlockDescriptor_NvBlockNeeds already defined
#endif
/** \brief  Symbolic name for Block 17 */
#define NvMConf_NvMBlockDescriptor_NvBlockNeeds   17U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvBlockNeeds)
#error NvBlockNeeds already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvBlockNeeds   17U

#if (defined NvM_NvBlockNeeds)
#error NvM_NvBlockNeeds already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvBlockNeeds   17U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Data_1)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Data_1 already defined
#endif
/** \brief  Symbolic name for Block 18 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Data_1   18U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Data_1)
#error NvM_BLE_Data_1 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Data_1   18U

#if (defined NvM_NvM_BLE_Data_1)
#error NvM_NvM_BLE_Data_1 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Data_1   18U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Data_2)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Data_2 already defined
#endif
/** \brief  Symbolic name for Block 19 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Data_2   19U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Data_2)
#error NvM_BLE_Data_2 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Data_2   19U

#if (defined NvM_NvM_BLE_Data_2)
#error NvM_NvM_BLE_Data_2 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Data_2   19U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Data_3)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Data_3 already defined
#endif
/** \brief  Symbolic name for Block 20 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Data_3   20U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Data_3)
#error NvM_BLE_Data_3 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Data_3   20U

#if (defined NvM_NvM_BLE_Data_3)
#error NvM_NvM_BLE_Data_3 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Data_3   20U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Data_4)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Data_4 already defined
#endif
/** \brief  Symbolic name for Block 21 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Data_4   21U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Data_4)
#error NvM_BLE_Data_4 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Data_4   21U

#if (defined NvM_NvM_BLE_Data_4)
#error NvM_NvM_BLE_Data_4 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Data_4   21U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Data_5)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Data_5 already defined
#endif
/** \brief  Symbolic name for Block 22 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Data_5   22U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Data_5)
#error NvM_BLE_Data_5 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Data_5   22U

#if (defined NvM_NvM_BLE_Data_5)
#error NvM_NvM_BLE_Data_5 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Data_5   22U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Data_6)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Data_6 already defined
#endif
/** \brief  Symbolic name for Block 23 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Data_6   23U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Data_6)
#error NvM_BLE_Data_6 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Data_6   23U

#if (defined NvM_NvM_BLE_Data_6)
#error NvM_NvM_BLE_Data_6 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Data_6   23U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Data_7)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Data_7 already defined
#endif
/** \brief  Symbolic name for Block 24 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Data_7   24U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Data_7)
#error NvM_BLE_Data_7 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Data_7   24U

#if (defined NvM_NvM_BLE_Data_7)
#error NvM_NvM_BLE_Data_7 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Data_7   24U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NvM_BLE_Data_8)
#error NvMConf_NvMBlockDescriptor_NvM_BLE_Data_8 already defined
#endif
/** \brief  Symbolic name for Block 25 */
#define NvMConf_NvMBlockDescriptor_NvM_BLE_Data_8   25U

#if (!defined NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_BLE_Data_8)
#error NvM_BLE_Data_8 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvM_BLE_Data_8   25U

#if (defined NvM_NvM_BLE_Data_8)
#error NvM_NvM_BLE_Data_8 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvM_BLE_Data_8   25U
#endif /* NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/** \brief Defines the number of all configured blocks including the reserved Block 0.
 **/
#define NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS 26U

/** \brief Defines whether the immediate priority queue is used.
 **
 **        Range:
 **        STD_ON  : Immediate priority queue is used.
 **        STD_OFF : Immediate priority queue is not usesd.
 **/
#define NVM_JOB_PRIORITIZATION           STD_OFF

/** \brief Defines the size of the internal data buffer
 **/
#define NVM_INTERNAL_BUFFER_SIZE         1178U

/** \brief Defines the size of the NvM internal mirror for explicit synchronization
 **/
#define NVM_MIRROR_SIZE                  0U
/** \brief Defines the size of the buffer for storing RAM block CRC values.
 **/
#define NVM_RAMBLOCK_CRC_BUFFER_SIZE     2U

/** \brief Defines the size of the buffer for storing CRC values for redundant block.
 **/
#define NVM_STORED_CRC_SIZE              2U

/** \brief The size of the standard job queue.
 **        One entry is reserved for WriteAll or ReadAll requests,
 **        so the configured value is incremented by one.
 **/
#define NVM_SIZE_STANDARD_JOB_QUEUE      201U

/** \brief The size of the immediate job queue.
 **/
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE     0U

/** \brief The RAM data buffer for the configuration Id shall be defined
 **        according the following rules:
 **
 **        if (for block 1:    NvMBlockUseCrc     == TRUE
 **                   && NvMCalcRamBlockCrc == TRUE
 **                   && NvMBlockCrcType    == NVM_CRC_TYPE_8
 **           )
 **        then   'VAR(uint16,NVM_VAR)        NvM_ConfigurationId[2];'
 **        else
 **        if (for block 1:    NvMBlockUseCrc     == TRUE
 **                   && NvMCalcRamBlockCrc == TRUE
 **                   && NvMBlockCrcType    == NVM_CRC_TYPE_16
 **           )
 **        then   'VAR(uint16,NVM_VAR)        NvM_ConfigurationId[2];'
 **        else
 **        if (for block 1:    NvMBlockUseCrc     == TRUE
 **                          && NvMCalcRamBlockCrc == TRUE
 **                          && NvMBlockCrcType    == NVM_CRC_TYPE_32
 **           )
 **        then  'VAR(uint16,NVM_VAR)  NvM_ConfigurationId[3];'
 **        else  'VAR(uint16,NVM_VAR) NvM_ConfigurationId[1];'
 **/
#define NVM_CONFIGURATIONID_SIZE  2U


/** \brief Defines the maximum number of user data bytes for which the CRC
 **        calculation is not interrupted.
 **/
#define NVM_CRC_NUM_OF_BYTES             65535U

/** \brief Defines the number of bits set aside for data set selection
 **/
#define NVM_DATASET_SELECTION_BITS       1U

/** \brief Defines the number of retries to let the application copy data to or from
 **        the NvM module's mirror before postponing the current job.
 **/
#define NVM_REPEAT_MIRROR_OPERATIONS     0U

/** \brief determines if NvM_WriteAll() and NvM_ReadAll() must switch to fast mode.
 **/
#define NVM_DRV_MODE_SWITCH              STD_ON

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMResistantToChangedSw set to false.
 **/
#define NVM_NUMBER_OF_RESISTANT_TO_CHANGED_SW_BLOCKS    24U

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMSelectBlockForReadAll set to true.
 **        Block 0 is reserved and independent of this parameter Block 1 is read as part of the NvM_ReadAll.
 **/
#define NVM_NUMBER_OF_SELECT_BLOCK_FOR_READALL_BLOCKS   13U

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMSelectBlockForWriteAll set to true.
  **/
#define NVM_NUMBER_OF_SELECT_BLOCK_FOR_WRITEALL   13U

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockManagementType
 **        set to NVM_BLOCK_DATASET.
 **/
#define NVM_NUMBER_OF_DATASET_BLOCKS                    0U

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMInitBlockCallback set to not null
 **        NvMProvideRteInitBlockPort is set to true.
 **/
#define NVM_NUMBER_OF_INIT_BLOCK_CALLBACK               0U

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMSingleBlockCallback set to not null.
 **/
#define NVM_NUMBER_OF_SINGLE_BLOCK_CALLBACK             4U

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockUseCrc set to true and
 **        NvMBlockCrcType set to NVM_CRC8.
 **/
#define NVM_NUMBER_OF_CALC_CRC8_BLOCKS                 0

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockUseCrc set to true and
 **        NvMBlockCrcType set to NVM_CRC16.
 **/
#define NVM_NUMBER_OF_CALC_CRC16_BLOCKS                 25

/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockUseCrc set to true and
 **        NvMBlockCrcType set to NVM_CRC32.
 **/
#define NVM_NUMBER_OF_CALC_CRC32_BLOCKS                 0

/** \brief Defines whether BswM job status info is enabled/disabled
 **        by checking NvMBswMMultiBlockJobStatusInformation set to true.
 **/
#define NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFO            STD_OFF

/** \brief Defines whether BswM block status info is enabled/disabled
 **        by checking the number of NVRAM blocks having
 **        NvMBswMBlockStatusInformation set to true.
 **/
#define NVM_BSWM_BLOCK_STATUS_INFO                      STD_OFF

/** \brief Defines whether Write verification is turned on or not
 **        by checking the number of NVRAM Blocks having NvMWriteVerification set to true.
 **/
#define NVM_WRITE_VERIFICATION                          STD_ON

/** \brief Defines the size of the Write verification buffer.
 **/
#define NVM_WRITE_VERIFICATION_BUFFER_SIZE              1


/** \brief Defines whether Static Block Id check is turned on or not
 **        by checking the number of NVRAM Blocks having NvMStaticBlockIDCheck set to true.
 **/
#define NVM_STATIC_BLOCKID_CHECK                        STD_ON

/** \brief Defines whether Explicit Synchronization is turned on or not
 **        by checking the number of NVRAM Blocks having NvMBlockUseSyncMechanism set to true.
 **/
#define NVM_SYNC_MECHANISM                              STD_OFF

/** \brief Defines whether any block is configured with immediate priority
 **        by checking the number of NVRAM Blocks having NvMBlockJobPriority set to zero.
 **/
#define NVM_NUMBER_OF_IMMEDIATE_PRIORITY_BLOCKS         0U

/** \brief Defines whether any block is configured with write block once
 **        by checking the number of NVRAM Blocks having NvMWriteBlockOnce set to zero.
 **/
#define NVM_WRITE_BLOCK_ONCE                            STD_OFF

/** \brief Defines whether any block is configured with write retry
 **        by checking the number of NVRAM Blocks having NvMMaxNumOfWriteRetries set to non-zero.
 **/
#define NVM_NUMBER_OF_WRITE_RETRY_BLOCKS                25U

/** \brief Defines whether any block is configured with read retry
 **        by checking the number of NVRAM Blocks having NvMMaxNumOfReadRetries set to non-zero.
 **/
#define NVM_NUMBER_OF_READ_RETRY_BLOCKS                 0U

/** \brief Defines the NvM Api config class 1.
 **/
#define NVM_API_CONFIG_CLASS_1                          0U

/** \brief Defines the NvM Api config class 2.
 **/
#define NVM_API_CONFIG_CLASS_2                          1U

/** \brief Defines the NvM Api config class 3.
 **/
#define NVM_API_CONFIG_CLASS_3                          2U

/** \brief Defines API config class
 **        NVM_API_CONFIG_CLASS_3 - all API functions are available
 **        NVM_API_CONFIG_CLASS_2 - an intermediate set API functions is available
 **        NVM_API_CONFIG_CLASS_1 - a minimum set of API functions is available
 **/
#define NVM_API_CONFIG_CLASS                            NVM_API_CONFIG_CLASS_3

/** \brief Preprocessor switch to enable/disable the polling mode in the NVRAM Manager
 **        and at the same time disable/enable the callback functions useable by lower layers.
 **
 **        STD_ON:  Polling mode enabled/callbacks disabled
 **        STD_OFF: Polling mode disabled/callbacks enabled
 **/
#define NVM_POLLING_MODE                 STD_ON

/** \brief Preprocessor switch to enable the dynamic configuration management handling
 **        by the NvM_ReadAll request.
 **        STD_ON: Dynamic configuration management handling enabled.
 **        STD_OFF: Dynamic configuration management handling disabled.
 **/
#define NVM_DYNAMIC_CONFIGURATION                 STD_ON

/** \brief Hook functions macros for ReadBlock and WriteBlock. They are called after
 **        the NvM calls the MemIf_Read and before it calls the NvM MemIf_Write
 **        function respectively.
 **/
#define NVM_READ_BLOCK_HOOK(BlockNum, RamBlockDataAddress, BlockLength) \
  do {} while (0)

#define NVM_WRITE_BLOCK_HOOK(BlockNum, RamBlockDataAddress, BlockLength) \
  do {} while (0)

/** \brief Multi block callback function macro. It is called
 **        if the NvM multi request NvM_WriteAll() or NvM_ReadAll() is
 **        finished.
 **/
#define NVM_MULTI_BLOCK_CALLBACK(sid,errorStatus) \
  EcuM_CB_NfyNvMJobEnd((sid),(errorStatus))

/** \brief Rte admin port macro used for declaring NvM_SetBlockProtection()
 **        when Rte usage is enabled but Rte admin port is disabled for all
 **        configured blocks.
 **/
#define NVM_ADMIN_PORT_USED                       STD_OFF

/** \brief Rte service port macro used for declaring NvM_GetErrorStatus()
 **        when Rte usage is enabled but Rte service port is disabled for all
 **        configured blocks.
 **/
#define NVM_SERVICE_PORT_USED                       STD_ON

#if (defined NVM_SERVICE_API_NONE)
#error NVM_SERVICE_API_NONE already defined
#endif
/** \brief Definition that no default service API is set **/
#define NVM_SERVICE_API_NONE   0U

#if (defined NVM_SERVICE_API_ASR32)
#error NVM_SERVICE_API_ASR32 already defined
#endif
/** \brief Definition that AUTOSAR 3.2 service API is set as default **/
#define NVM_SERVICE_API_ASR32   32U

#if (defined NVM_SERVICE_API_ASR40)
#error NVM_SERVICE_API_ASR40 already defined
#endif
/** \brief Definition that AUTOSAR 4.0 service API is set as default **/
#define NVM_SERVICE_API_ASR40   40U

  #if (defined NVM_ENABLE_ASR32_SERVICE_API) /* To prevent double declaration */
#error NVM_ENABLE_ASR32_SERVICE_API already defined
#endif /* if (defined NVM_ENABLE_ASR32_SERVICE_API) */

/** \brief Definition whether AUTOSAR 3.2 service API is enabled **/
#define NVM_ENABLE_ASR32_SERVICE_API                   STD_OFF

#if (defined NVM_ENABLE_ASR40_SERVICE_API) /* To prevent double declaration */
#error NVM_ENABLE_ASR40_SERVICE_API already defined
#endif /* if (defined NVM_ENABLE_ASR40_SERVICE_API) */

/** \brief Definition whether AUTOSAR 4.0 service API is enabled **/
#define NVM_ENABLE_ASR40_SERVICE_API                   STD_ON

#if (defined NVM_DEFAULT_ASR_SERVICE_API) /* To prevent double declaration */
#error NVM_DEFAULT_ASR_SERVICE_API already defined
#endif /* if (defined NVM_DEFAULT_ASR_SERVICE_API) */

/** \brief Definition of default service API **/
#define NVM_DEFAULT_ASR_SERVICE_API                    NVM_SERVICE_API_ASR40

/*================[variables user application data section]================*/
#define NVM_START_CONFIG_DATA_APPL_DATA
#include <MemMap.h>

/** \brief Stores the calculated CRC values in RAM
 **/

extern VAR(uint16,NVM_APPL_DATA) NvM_CalcCrc_CalcBuffer;


#define NVM_STOP_CONFIG_DATA_APPL_DATA
#include <MemMap.h>
/*===============[end of variables user application data section]==========*/

/*==================[external function declarations]========================*/

#define NVM_START_SEC_CODE
#include <MemMap.h>


#define NVM_STOP_SEC_CODE
#include <MemMap.h>

/*------------------[Defensive programming]---------------------------------*/

#if (defined NVM_DEFENSIVE_PROGRAMMING_ENABLED)
#error NVM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define NVM_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined NVM_PRECONDITION_ASSERT_ENABLED)
#error NVM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define NVM_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined NVM_POSTCONDITION_ASSERT_ENABLED)
#error NVM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define NVM_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined NVM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error NVM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define NVM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined NVM_INVARIANT_ASSERT_ENABLED)
#error NVM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define NVM_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined NVM_STATIC_ASSERT_ENABLED)
#error NVM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define NVM_STATIC_ASSERT_ENABLED           STD_OFF


/*==================[ end of external function declarations]================*/
#endif /* if !defined( NVM_CFG_H ) */
/*==================[end of file NvM_Cfg.h]==================================*/
