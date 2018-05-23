/**
*   @file    Fee_Cfg.h
*   @implements Fee_Cfg.h_Artifact
*   @version 2.0.0
*
*   @brief   AUTOSAR Fee - AUTOSAR Module Flash EEPROM Emulation Driver.
*   @details Definitions of all pre-compile configuration parameters..
*
*   @addtogroup FEE
*   @{

*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : none
*   Dependencies         : Fls
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : MPC57xxP_MCAL_2_0_0_RTM_ASR_REL_4_0_REV_0003_20141024
*
*   (c) Copyright 2006-2014 Freescale Inc
*   All Rights Reserved.
==================================================================================================*/

#ifndef FEE_CFG_H
#define FEE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_cfg_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR
* requirement MEMMAP003.
*
* @section Fee_cfg_h_REF_2
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for a macro.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external
* identifiers.
* Block name symbol defines are too long, handled by preprocessor.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters due to
* AUTOSAR compatibility.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/** @implements   VendorId_Object */
#define FEE_VENDOR_ID_CFG                    43
/** @implements   ModuleId_Object */
#define FEE_MODULE_ID_CFG                    21
/** @implements   ArReleaseMajorVersion_Object */
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG     4
/** @implements   ArReleaseMinorVersion_Object */
#define FEE_AR_RELEASE_MINOR_VERSION_CFG     0
/** @implements   ArReleaseRevisionVersion_Object */
#define FEE_AR_RELEASE_REVISION_VERSION_CFG  3
/** @implements   SwMajorVersion_Object */
#define FEE_SW_MAJOR_VERSION_CFG             2
/** @implements   SwMinorVersion_Object */
#define FEE_SW_MINOR_VERSION_CFG             0
/** @implements   SwPatchVersion_Object */
#define FEE_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MODULENAME configuration header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG != FEE_TYPES_VENDOR_ID)
    #error "Fee_Types.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same Autosar version
*/
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG != FEE_TYPES_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same software version
*/
#if ((FEE_SW_MAJOR_VERSION_CFG != FEE_TYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG != FEE_TYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG != FEE_TYPES_SW_PATCH_VERSION)\
    )
    #error "Software Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Pre-processor switch to enable and disable development error detection */
/** @implements   FeeDevErrorDetect_Object */
#define FEE_DEV_ERROR_DETECT                (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules
    version information */
/** @implements   FeeVersionInfoApi_Object */
#define FEE_VERSION_INFO_API                (STD_ON)

/* Compiler switch to enable/disable the SetMode functionality of the module */
/** @implements   FeeSetModeSupported_Object */
#define FEE_SETMODE_API_SUPPORTED           (STD_ON)

/* Pre-processor switch to enable /disable the Fls_Cancel function of the module */
#define FEE_CANCEL_API                     (STD_OFF)

/* The size in bytes to which logical blocks shall be aligned */
/** @implements   FeeVirtualPageSize_Object */
#define FEE_VIRTUAL_PAGE_SIZE               32U

/* Job end notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobEndNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_END_NOTIFICATION_DECL   extern void NvM_JobEndNotification(void);

/* Job end notification routine provided by the upper layer module */
/** @implements   FeeNvmJobEndNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_END_NOTIFICATION        NvM_JobEndNotification();

/* Job error notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobErrorNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL  extern void NvM_JobErrorNotification(void);

/* Job error notification routine provided by the upper layer module */
/** @implements   FeeNvmJobErrorNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_ERROR_NOTIFICATION       NvM_JobErrorNotification();

/* Job cluster format notification routine provided by the upper layer module (declaration) */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL  

/* Job cluster format notification routine provided by the upper layer module */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION       

/* Number of configured Fee cluster groups */
#define FEE_NUMBER_OF_CLUSTER_GROUPS        1U

/* Number of configured Fee blocks */
#define FEE_CRT_CFG_NR_OF_BLOCKS                40U

/* Maximum number of Fee blocks in all project versions and configurations */
#define FEE_MAX_NR_OF_BLOCKS        (FEE_CRT_CFG_NR_OF_BLOCKS)
/* Management overhead per logical block in bytes */
/** @implements   FeeBlockOverhead_Object */
#define FEE_BLOCK_OVERHEAD                  96U

/* Management overhead per logical cluster in bytes */
#define FEE_CLUSTER_OVERHEAD                96U

/* Size of the data buffer in bytes */
#define FEE_DATA_BUFFER_SIZE                96U

/* The contents of an erased flash memory cell */
#define FEE_ERASED_VALUE                    0xffU

/* Value of the block and cluster validation flag */
#define FEE_VALIDATED_VALUE                0x81U

/* Value of the block and cluster invalidation flag */
#define FEE_INVALIDATED_VALUE              0x18U

/* If reset, power loss etc. occurs here, neither newly nor previously written data is available */
#define FEE_BLOCK_ALWAYS_AVAILABLE          (STD_ON)

/* Compile switch to enable Legacy mode (original FEE immediate data handling) */
#define FEE_LEGACY_MODE                     (STD_ON)

/* Behavior of Fee_ImmediateBlockErase */
#define FEE_LEGACY_IMM_ERASE_MODE           (STD_OFF)

/* This configuration defines wheather Fee should swap foreign blocks found in flash at swap or not */
#define FEE_SWAP_FOREIGN_BLOCKS_ENABLED          (STD_OFF)

/* This configuration defines for which project the Fee configuration is used  */
#define FEE_BOOTLOADER_CONFIG           (STD_OFF)

/* Symbolic names of configured Fee blocks */
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID     2U
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_1     3U
#define FeeConf_FeeBlockConfiguration_Fee_PersistentCounterValue_0     4U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f197_0     6U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f197_1     7U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f17b_0     8U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f17b_1     9U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f19a_0     10U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f19a_1     11U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f19b_0     12U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f19b_1     13U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1a5_0     14U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1a5_1     15U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1a9_0     16U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1a9_1     17U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1aa_0     18U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1aa_1     19U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1a0_0     20U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1a0_1     21U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1a4_0     22U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_DID_f1a4_1     23U
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_NullVectorValid_0     24U
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_NullVectorValid_1     25U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Name_0     26U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_ResetsNumber_0     28U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_ResetsNumber_1     29U
#define FeeConf_FeeBlockConfiguration_Fee_NvBlockNeeds_0     30U
#define FeeConf_FeeBlockConfiguration_Fee_NvBlockNeeds_1     31U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Data_1     32U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Data_3     34U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Data_5     36U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Data_7     38U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Data_2     42U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Data_4     44U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Data_6     46U
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLE_Data_8     48U
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_DEM_DEFAULT_0     256U
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_DEM_DEFAULT_1     257U
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_DEM_PRIMARY_0     258U
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_DEM_PRIMARY_1     259U


#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "MemMap.h"

/* Configuration of cluster group set */
extern CONST(Fee_ClusterGroupType, FEE_CONST) Fee_ClrGrps[ FEE_NUMBER_OF_CLUSTER_GROUPS ];

/* Configuration of Fee blocks */
extern CONST(Fee_BlockConfigType, FEE_CONST) Fee_BlockConfig[ FEE_CRT_CFG_NR_OF_BLOCKS ];

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FEE_CFG_H */
/** @} */
