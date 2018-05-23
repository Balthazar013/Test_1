/**
*   @file CDD_Mcl_Cfg.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Mcl - contains the configuration data of the MCL driver
*   @details Contains the configuration data of the MCL driver
*
*   @addtogroup MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eDMA
*   Dependencies         : none
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
/*==================================================================================================
==================================================================================================*/



#ifndef CDD_MCL_CFG_H
#define CDD_MCL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif 
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*          contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Mcl_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct. 
*          This is used to abstract the export of configuration sets or for a function define.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Mcl_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Mcl_EnvCfg.h"
#include "Mcal.h"

#include "Dem.h"
    
    
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_VENDOR_ID_CFG                       43

#define MCL_AR_RELEASE_MAJOR_VERSION_CFG        4
#define MCL_AR_RELEASE_MINOR_VERSION_CFG        0
#define MCL_AR_RELEASE_REVISION_VERSION_CFG     3

#define MCL_SW_MAJOR_VERSION_CFG                2
#define MCL_SW_MINOR_VERSION_CFG                0
#define MCL_SW_PATCH_VERSION_CFG                0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (MCL_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Check if header file and Dem.h file are of the same Autosar version */
 #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Dem header file are of the same Autosar version */
     #if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
          ( MCL_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Dem.h are different"
     #endif
 #endif

#if (MCL_VENDOR_ID_CFG != MCL_ENVCFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg.h and Mcl_EnvCfg.h have different vendor ids"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same Autosar version */
#if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( MCL_AR_RELEASE_MINOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     ( MCL_AR_RELEASE_REVISION_VERSION_CFG !=  MCL_ENVCFG_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same software version */
#if ((MCL_SW_MAJOR_VERSION_CFG != MCL_ENVCFG_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION_CFG != MCL_ENVCFG_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION_CFG != MCL_ENVCFG_SW_PATCH_VERSION))
     #error "Software Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
    
/* Mcl Pre Compile Switch */
#define MCL_PRECOMPILE_SUPPORT (STD_ON)
/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*   
*/
#define MCL_DEV_ERROR_DETECT                  (STD_ON)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_GetVersionInfo() from the code.
*        STD_ON: Mcl_GetVersionInfo() can be used. STD_OFF: Mcl_GetVersionInfo() can not be used.
*   
*/
#define MCL_GET_VERSION_INFO_API              (STD_ON)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DeInit() from the code.
*        STD_ON: Mcl_DeInit() can be used. STD_OFF: Mcl_DeInit() can not be used.
*   
*/
#define MCL_DEINIT_API                        (STD_OFF)

/**
*   @brief   Switches DMA features initialization on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define MCL_ENABLE_DMA              (STD_ON)



/**
*   @brief   Switches the Crossbar support on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define MCL_CROSSBAR_NUM_INSTANCES        (0x1U)

#define MCL_ENABLE_CROSSBAR              (STD_ON)  

#define MCL_CROSSBAR_PRS_READONLY        (STD_OFF)

#define MCL_CROSSBAR0_PRS_RESET_VALUE_U32     (0x03200010U)   

#define MCL_CROSSBAR0_CRS_RESET_VALUE_U32     (0x00000000U) 



 
/**
* @brief      This define specifies enable or disable initialization of DCHMID register in DMA
*
*/
#define MCL_DMA_ENABLE_INIT_DCHMID (STD_ON) 
/**
* @brief      This define specifies the number of eDma Channels available for one eDma instance
*
*/
#define MCL_DMA_NB_CHANNELS                      (0x20U)
/**
* @brief      This define specifies the number of eDma instances
*
*/
#define MCL_DMA_NB_CONTROLLERS                   (0x1U)
/**
* @brief      This define specifies the number of eDma Mux instances
*
*/
#define MCL_DMAMUX_NB_MODULES                    (0x2U)

/**
* @brief      This define specifies the access to registers of dmamux is Little Endian or not
*
*/
#define MCL_DMAMUX_CHCFG_LITTLE_ENDIAN        (STD_OFF)

/**
* @brief      The defines bellow specify the DMAMUX sources
*
*/
        
/** @brief DMA Channel Sources for DmaMux Instance 0 */
#define MCL_DMA_MUX_0_DSPI2_TX (1U)
#define MCL_DMA_MUX_0_DSPI2_RX (2U)
#define MCL_DMA_MUX_0_DSPI3_TX (3U)
#define MCL_DMA_MUX_0_DSPI3_RX (4U)
#define MCL_DMA_MUX_0_CTU0_CTU (5U)
#define MCL_DMA_MUX_0_CTU0_FIFO1 (6U)
#define MCL_DMA_MUX_0_CTU0_FIFO2 (7U)
#define MCL_DMA_MUX_0_CTU0_FIFO3 (8U)
#define MCL_DMA_MUX_0_CTU0_FIFO4 (9U)
#define MCL_DMA_MUX_0_FlexPWM0_COMP (10U)
#define MCL_DMA_MUX_0_FlexPWM0_CAPT (11U)
#define MCL_DMA_MUX_0_eTimer0_CH0 (12U)
#define MCL_DMA_MUX_0_eTimer0_CH1 (13U)
#define MCL_DMA_MUX_0_eTimer0_CH2 (14U)
#define MCL_DMA_MUX_0_eTimer0_CH3 (15U)
#define MCL_DMA_MUX_0_eTimer2_CH0 (16U)
#define MCL_DMA_MUX_0_eTimer2_CH1 (17U)
#define MCL_DMA_MUX_0_ADC0_DMA (18U)
#define MCL_DMA_MUX_0_ADC2_DMA (19U)
#define MCL_DMA_MUX_0_LINFlex0_TX (20U)
#define MCL_DMA_MUX_0_LINFlex0_RX (21U)
#define MCL_DMA_MUX_0_SENT1_FAST_MSG (22U)
#define MCL_DMA_MUX_0_SENT1_SLOW_MSG (23U)
#define MCL_DMA_MUX_0_ALWAYS_ON_1 (24U)
#define MCL_DMA_MUX_0_ALWAYS_ON_2 (25U)
#define MCL_DMA_MUX_0_ALWAYS_ON_3 (26U)
#define MCL_DMA_MUX_0_ALWAYS_ON_4 (27U)
#define MCL_DMA_MUX_0_ALWAYS_ON_5 (28U)
#define MCL_DMA_MUX_0_ALWAYS_ON_6 (29U)
#define MCL_DMA_MUX_0_NOT_USED (30U)
        
/** @brief DMA Channel Sources for DmaMux Instance 1 */
#define MCL_DMA_MUX_1_DSPI0_TX (1U)
#define MCL_DMA_MUX_1_DSPI0_RX (2U)
#define MCL_DMA_MUX_1_DSPI1_TX (3U)
#define MCL_DMA_MUX_1_DSPI1_RX (4U)
#define MCL_DMA_MUX_1_CTU1_CTU (5U)
#define MCL_DMA_MUX_1_CTU1_FIFO1 (6U)
#define MCL_DMA_MUX_1_CTU1_FIFO2 (7U)
#define MCL_DMA_MUX_1_CTU1_FIFO3 (8U)
#define MCL_DMA_MUX_1_CTU1_FIFO4 (9U)
#define MCL_DMA_MUX_1_eTimer1_CH0 (10U)
#define MCL_DMA_MUX_1_eTimer1_CH1 (11U)
#define MCL_DMA_MUX_1_ADC1_DMA (12U)
#define MCL_DMA_MUX_1_ADC3_DMA (13U)
#define MCL_DMA_MUX_1_LINFlex1_TX (14U)
#define MCL_DMA_MUX_1_LINFlex1_RX (15U)
#define MCL_DMA_MUX_1_FlexPWM1_COMP (16U)
#define MCL_DMA_MUX_1_FlexPWM1_CAPT (17U)
#define MCL_DMA_MUX_1_SIPI_CH0 (18U)
#define MCL_DMA_MUX_1_SIPI_CH1 (19U)
#define MCL_DMA_MUX_1_SIPI_CH2 (20U)
#define MCL_DMA_MUX_1_SIPI_CH3 (21U)
#define MCL_DMA_MUX_1_SENT0_FAST_MSG (22U)
#define MCL_DMA_MUX_1_SENT0_SLOW_MSG (23U)
#define MCL_DMA_MUX_1_SIUL2_REQ0 (24U)
#define MCL_DMA_MUX_1_SIUL2_REQ1 (25U)
#define MCL_DMA_MUX_1_SIUL2_REQ2 (26U)
#define MCL_DMA_MUX_1_SIUL2_REQ3 (27U)
#define MCL_DMA_MUX_1_ALWAYS_ON_1 (28U)
#define MCL_DMA_MUX_1_ALWAYS_ON_2 (29U)
#define MCL_DMA_MUX_1_ALWAYS_ON_3 (30U)
#define MCL_DMA_MUX_1_ALWAYS_ON_4 (31U)
#define MCL_DMA_MUX_1_ALWAYS_ON_5 (32U)
#define MCL_DMA_MUX_1_ALWAYS_ON_6 (33U)
#define MCL_DMA_MUX_1_NOT_USED (34U)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DmaGetChannelErrorStatus() from the code.
*        STD_ON: Mcl_DmaGetChannelErrorStatusApi() can be used. STD_OFF: Mcl_DmaGetChannelErrorStatusApi() can not be used.
*   
*/
#define MCL_DMA_GET_CH_ERR_STATUS_API            (STD_OFF)

/**
*   @brief  Adds or removes the service Mcl_DmaGetGlobalErrorStatusApi() from the code.
*        STD_ON: Mcl_DmaGetGlobalErrorStatusApi() can be used. STD_OFF: Mcl_DmaGetGlobalErrorStatusApi() can not be used.
*   
*/
#define MCL_DMA_GET_GLOBAL_ERR_STATUS_API            (STD_OFF)

/**
* @brief      This define specifies the number of eTimer channels available
*             on the current platform
*
*/
#define MCL_EDMA_CHANNELS_NO            (32U)

/**
* @brief      This define specifies the number of eTimer channels in a group of channels available
*             on the current platform
*
*/
#define MCL_EDMA_CHANNELS_IN_GROUP            (16U)

/**
* @brief      This define specifies the number of eTimer channels in a group of channels available
*             on the current platform
*
*/
#define MCL_DMA_ERROR_INTERRUPTS_USED            (STD_OFF)

/**
* @brief      This define specifies if there is only one transfer completion ISR for all DMA channels within a DMA instance
*             or if there is a transfer completion ISR for each channel
*
*/
#define MCL_DMA_COMBINED_TR_COMPLETION_ISR (STD_OFF)

/**
* @brief      This define specifies if there is only one error ISR for all DMA instances
*             or if there is an error ISR for each DMA instance
*
*/
#define MCL_DMA_COMBINED_ERROR_ISR (STD_OFF)
/**
* @brief      This define specifies if there is Ecc error reporting available          
*
*/
#define MCL_DMA_ECC_REPORTING_ENABLED (STD_ON)

/** 
* @brief  Switch to globaly enable/disable the production error reporting.
*/
#define MCL_DISABLE_DEM_REPORT_ERROR_STATUS  (STD_OFF)


#define MCL_DMA_CH_7_ISR_USED 
#define MCL_DMA_CH_12_ISR_USED 
#define MCL_DMA_CH_13_ISR_USED 
#define MCL_DMA_CH_14_ISR_USED 
#define MCL_DMA_CH_18_ISR_USED 
#define MCL_DMA_CH_23_ISR_USED 
#define MCL_DMA_CH_25_ISR_USED 
#define MCL_DMA_CH_26_ISR_USED 
#define MCL_DMA_CH_27_ISR_USED 

/**
* @brief      This define specifies if there is only one transfer completion ISR for a DMA channel within a DMA instance
*             or if there is a transfer completion ISR for each channel
*
*/
#define MCL_DMA_TR_SEPARATED_ISR (STD_ON)

/**
* @brief      This define specifies if inside a DMA instance some channels have the same transfer completion ISR assigned,
*             and other channels have their own transfer completion ISR.
*
*/
#define MCL_DMA_TR_COMPLETION_MIXED_ISR (STD_OFF)

/** Define to specify if least one transfer completion interrupt and notification is used, 
*      needed for removing at precompile time the code for ISR handling for the transfer 
*      completion notification processing. This define is needed in both combined transfer
*      completion interrupt and single channel mode. */
#define MCL_DMA_NOTIFICATION_SUPPORTED              (STD_ON)

/* Transfer size options available */
#define MCL_TRANSFER_SIZE_1_BYTE 
#define MCL_TRANSFER_SIZE_2_BYTE 
#define MCL_TRANSFER_SIZE_4_BYTE 
#define MCL_TRANSFER_SIZE_8_BYTE 
#define MCL_TRANSFER_SIZE_32_BYTE 







/** @brief Declaration of config set for PC configuration */
#if (MCL_PRECOMPILE_SUPPORT == STD_ON)
 /** @violates @ref Mcl_Cfg_h_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */ 
    #define MCL_INIT_CONFIG_PC_DEFINE extern CONST(Mcl_ConfigType, MCL_CONST) Mcl_InitConfig_PC;
    

#endif /* MCL_PRECOMPILE_SUPPORT */
/*==================================================================================================
                                             ENUMS
==================================================================================================*/
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/
typedef struct
{
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_Dma_E_Bus;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_Dma_E_Descriptor;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_Dma_E_Ecc;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_Dma_E_Priority;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_Dma_E_Unrecognized;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_Dma_E_Inconsistency;
} Mcl_DemConfigType;


#endif


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif    /* CDD_MCL_CFG_H */
/**@}*/


