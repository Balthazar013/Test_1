/**
*   @file       Pwm_Cfg.h
*   @implements Pwm_Cfg.h_Artifact
*   @version    2.0.0
*
*   @brief      AUTOSAR Pwm - Pwm configuration file.
*   @details    Precompile parameters and extern configuration.
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : FlexPWM eTimer
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


#ifndef PWM_CFG_H
#define PWM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Cfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Pwm_Cfg_H_REF_2
* Violates MISRA 2004 Required Rule 19.4, C macros should only extend to braced initializer,
* a constant, a paranthesised expression, a type qualifier, a storage class specifier or 
* a  do-while-zero construct. 
* Macro used to define external constant in order to reduce code complexity.*
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref Pwm_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Pwm_EnvCfg.h"
#include "Pwm_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm_Cfg.h
*/
#define PWM_CFG_VENDOR_ID                         43
#define PWM_CFG_MODULE_ID                         121
#define PWM_CFG_AR_RELEASE_MAJOR_VERSION          4
#define PWM_CFG_AR_RELEASE_MINOR_VERSION          0
#define PWM_CFG_AR_RELEASE_REVISION_VERSION       3
#define PWM_CFG_SW_MAJOR_VERSION                  2
#define PWM_CFG_SW_MINOR_VERSION                  0
#define PWM_CFG_SW_PATCH_VERSION                  0
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (PWM_CFG_VENDOR_ID != PWM_CFG_ENV_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_EnvCfg.h have different vendor ids"
#endif
/* Check if current file and Pwm_EnvCfg header file are of the same Autosar version */
#if (( PWM_CFG_AR_RELEASE_MAJOR_VERSION != PWM_CFG_ENV_AR_RELEASE_MAJOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_MINOR_VERSION != PWM_CFG_ENV_AR_RELEASE_MINOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_REVISION_VERSION !=  PWM_CFG_ENV_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_EnvCfg.h are different"
#endif
/* Check if current file and Pwm_EnvCfg header file are of the same software version */
#if ((PWM_CFG_SW_MAJOR_VERSION != PWM_CFG_ENV_SW_MAJOR_VERSION) || \
     (PWM_CFG_SW_MINOR_VERSION != PWM_CFG_ENV_SW_MINOR_VERSION) || \
     (PWM_CFG_SW_PATCH_VERSION != PWM_CFG_ENV_SW_PATCH_VERSION))
     #error "Software Version Numbers of Pwm_Cfg.h and Pwm_EnvCfg.h are different"
#endif

#if (PWM_CFG_VENDOR_ID != PWM_TYPES_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_Types.h have different vendor ids"
#endif
/* Check if current file and Pwm_Types header file are of the same Autosar version */
#if (( PWM_CFG_AR_RELEASE_MAJOR_VERSION != PWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_MINOR_VERSION != PWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_REVISION_VERSION !=  PWM_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_Types.h are different"
#endif
/* Check if current file and Pwm_Types header file are of the same software version */
#if ((PWM_CFG_SW_MAJOR_VERSION != PWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_CFG_SW_MINOR_VERSION != PWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_CFG_SW_PATCH_VERSION != PWM_TYPES_SW_PATCH_VERSION))
     #error "Software Version Numbers of Pwm_Cfg.h and Pwm_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          API service ID
*/
#define PWM_PROCESSNOTIFICATION_ID        (0x0AU)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief      Pwm Pre Compile Switch
*/
#define PWM_PRECOMPILE_SUPPORT            (STD_ON)

/**
* @brief      Switch to indicate that Pwm_DeInit API is supported
*
*/
#define PWM_DE_INIT_API                   (STD_ON)

/**
* @brief      Switch to indicate that Pwm_GetOutputState API is supported
*
*/
#define PWM_GET_OUTPUT_STATE_API          (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetDutyCycle API is supported
*
*/
#define PWM_SET_DUTY_CYCLE_API            (STD_ON)

/**
* @brief      Switch to indicate that Pwm_SetOutputToIdle API is supported
*
*/
#define PWM_SET_OUTPUT_TO_IDLE_API        (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetPeriodAndDuty API is supported
*
*/
#define PWM_SET_PERIOD_AND_DUTY_API       (STD_ON)

/**
* @brief      Switch to indicate that Pwm_GetVersionInfo API is supported
*
*/
#define PWM_VERSION_INFO_API              (STD_ON)

/**
* @brief      Switch to indicate that Pwm_GetChannelState API is supported
*
*/
#define PWM_GET_CHANNEL_STATE_API         (STD_ON)

/**
* @brief      Switch to indicate that Pwm_ForceOutputToZero API is supported
*
*/
#define PWM_FORCE_OUTPUT_TO_ZERO_API       (STD_OFF)

/**
* @brief      Switch for enabling the development error detection.
*
*/
#define PWM_DEV_ERROR_DETECT              (STD_ON)

/**
* @brief      Switch for enabling the update of the duty cycle parameter at the end of 
*             the current period
*
*/
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD       (STD_ON)

/**
* @brief      Switch for enabling the update of the period parameter at the end of the current period
*
*/
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD     (STD_ON)


/**
* @brief      Switch to indicate that Pwm_SetChannelOutput API is supported
*
*/
#define PWM_SET_CHANNEL_OUTPUT_API         (STD_ON)

/**
* @brief      Switch to indicate that Pwm_SetTriggerDelay API is supported
*
*/
#define PWM_SET_TRIGGER_DELAY_API          (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_BufferTransferEnableDisable API is supported
*
*/
#define PWM_BUFFER_TRANSFER_EN_DIS_API     (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetCounterBus API is supported
*
*/
#define PWM_SET_COUNTER_BUS_API            (STD_OFF)

/**
* @brief      Switch to indicate that the Pwm_SelectCommonTimebase API is supported
*
*/
#define  PWM_SELECT_COMMON_TIMEBASE_API        (STD_OFF)

/**
* @brief      Switch to indicate that PwmSetDutyCycle_NoUpdate API is supported
*
*/

#define PWM_SET_DUTY_CYCLE_NO_UPDATE_API       (STD_OFF)


/**
* @brief      Switch to indicate that PwmSetPeriodAndDuty_NoUpdate API is supported
*
*/

#define PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API          (STD_OFF)



/**
* @brief      Switch to indicate that Pwm_SyncUpdate API is supported
*
*/
#define PWM_SYNC_UPDATE_API                    (STD_OFF)


/**
* @brief      Switch for enabling the dual clock functionality (Pwm_SetClockMode API)
*
*/
#define PWM_SET_CLOCK_MODE_API            (STD_OFF)


/**
* @brief      Switch to indicate that the notifications are supported
*
*/
#define PWM_NOTIFICATION_SUPPORTED        (STD_OFF)



/**
* @brief      Switch to indicate that the notifications are supported
*
*/
#define PWM_UPDATE_DUTY_SYNCHRONOUS       (STD_OFF)




/**
* @brief      Switch for enabling the fault functionality
*
*/
#define PWM_FAULT_SUPPORTED               (STD_OFF)


/**
* @brief      Specifies the InstanceId of this module instance.
* @details    Specifies the InstanceId of this module instance.
*             If only one instance is present it shall have the Id 0.
*             Not used in the current implementation
*
*/
#define PWM_INDEX                         (0U)

/**
* @brief      Switch to indicate that platform-specific validations of the notification function are supported
*
*/
#define PWM_NOTIFICATON_PLAUSABILITY          (STD_OFF)

/**
* @brief      Switch to indicate that platform-specific validation of the offset (phase shift) of duty-cycle is supported
*
*/
#define PWM_OFFSET_PLAUSABILITY               (STD_OFF)

/**
* @brief      Switch to indicate that platform-specific validation of the period is supported
*
*/
#define PWM_MAX_PERIOD_PLAUSABILITY           (STD_ON)

/**
* @brief      Switch to indicate that platform-specific validation of the output state parameter is supported
*
*/
#define PWM_OUTPUT_STATE_PLAUSABILITY           (STD_ON)


/* Configure specific features for FlexPwm-eTimer platforms */
#define PWM_ALLOW_SUBMODULE_SYNC                (STD_ON)
#define PWM_SET_PHASE_SHIFT_API                    (STD_OFF)
#define PWM_SET_PHASE_SHIFT_NO_UPDATE_API        (STD_OFF)
#define PWM_ENABLE_TRIGEER_API                    (STD_OFF)
#define PWM_DIABLE_TRIGEER_API                    (STD_OFF)
#define PWM_RESET_COUNTER_API                    (STD_OFF)
#define PWM_ENABLE_MASKING_OPERATIONS            (STD_OFF)

/**
* @brief      This define specifies the number of FlexPwm Modules available
*             on the current platform
*
*/
#define PWM_FLEXPWM_NO                    (2U)

/**
* @brief      This define specifies maximum number of Pwm Modules available
*             on the current platform*
*/
#define  PWM_HW_MODULES_CFG_U8              (PWM_FLEXPWM_NO)


/**
* @brief      This define specifies the number of FlexPwm SubModules available
*             on the current platform
*
*/
#define PWM_SUBMODULE_NO                  (8U)

/**
* @brief      This define specifies the number of FlexPwm channels available
*             on the current platform
*
*/
#define PWM_FLEXPWM_CHANNELS_NO           (24U)

/**
* @brief      This define specifies the number of FlexPwm Fault channels available
*             on the current platform
*
*/
#define PWM_FLEXPWM_FAULT_NO              (8U)

/**
* @brief      This define specifies the number of eTimer Modules available
*             on the current platform
*
*/
#define PWM_ETIMER_NO                     (3U)

/**
* @brief      This define specifies the number of eTimer channels available
*             on the current platform
*
*/
#define PWM_ETIMER_CHANNELS_NO            (24U)

/**
* @brief      Defines that specifies the submodule type used in Pwm_FlexPwm_SubModuleType type
*/
#define PWM_SUBMOD_0        ((Pwm_FlexPwm_SubModuleType)0U)
#define PWM_SUBMOD_1        ((Pwm_FlexPwm_SubModuleType)1U)
#define PWM_SUBMOD_2        ((Pwm_FlexPwm_SubModuleType)2U)
#define PWM_SUBMOD_3        ((Pwm_FlexPwm_SubModuleType)3U)
#define PWM_SUBMOD_4        ((Pwm_FlexPwm_SubModuleType)4U)
#define PWM_SUBMOD_5        ((Pwm_FlexPwm_SubModuleType)5U)
#define PWM_SUBMOD_6        ((Pwm_FlexPwm_SubModuleType)6U)
#define PWM_SUBMOD_7        ((Pwm_FlexPwm_SubModuleType)7U)

/**
* @brief      Defines that specifies the Module types used in Pwm_FlexPwm_ModuleType type
*/
#define PWM_FLEXPWM_0      ((Pwm_FlexPwm_ModuleType)0U)
#define PWM_FLEXPWM_1      ((Pwm_FlexPwm_ModuleType)1U)


/**
* @brief      Type definition of the PWM module based on the supported hw module 
*/
typedef uint8  Pwm_ModuleType; 


/**
* @brief      Defines that specifies the Module types used in Pwm_ModuleType type
*/
#define PWM_MODULE_0      ((Pwm_ModuleType) 0U)
#define PWM_MODULE_1      ((Pwm_ModuleType) 1U)


/**
* @brief Symbolic Names for configured channels
*/
#define PwmChannel_PWM_CTRL_AUDI_LED_01       ((Pwm_ChannelType)0U)
#define PwmChannel_PWM_ZM_SPEED_CM_WPM_01       ((Pwm_ChannelType)1U)
#define PwmChannel_PWM_STATUS_LED_BLUE_CU_LED       ((Pwm_ChannelType)2U)
#define PwmChannel_PWM_STATUS_LED_GREEN_CU_LED       ((Pwm_ChannelType)3U)
#define PwmChannel_PWM_STATUS_LED_RED_CU_LED       ((Pwm_ChannelType)4U)
#define PwmChannel_PWM_SYNC_PFC_CM_PPM       ((Pwm_ChannelType)5U)
#define PwmChannel_PWM_LS_U_CM_WPM_01       ((Pwm_ChannelType)6U)
#define PwmChannel_PWM_HS_U_CM_WPM_01       ((Pwm_ChannelType)7U)
#define PwmChannel_PWM_LS_V_CM_WPM_01       ((Pwm_ChannelType)8U)
#define PwmChannel_PWM_HS_V_CM_WPM_01       ((Pwm_ChannelType)9U)
#define PwmChannel_PWM_LS_W_CM_WPM_01       ((Pwm_ChannelType)10U)
#define PwmChannel_PWM_HS_W_CM_WPM_01       ((Pwm_ChannelType)11U)
#define PwmChannel_PWM_FAN_TACH_PPM_CM_05       ((Pwm_ChannelType)12U)
#define PwmChannel_PWM_THRESH_CU_ASC       ((Pwm_ChannelType)13U)
#define PwmChannel_D_ZM_HALL2_WPM_CM_10       ((Pwm_ChannelType)14U)
#define PwmChannel_D_ZM_HALL_WPM_CM_10       ((Pwm_ChannelType)15U)
#define PwmChannel_PWM_FAN_CTRL_CM_WPM_01       ((Pwm_ChannelType)16U)
#define PwmChannel_PWM_FAN_TACH_WPM_CM_05       ((Pwm_ChannelType)17U)
#define PwmChannel_ET2C5_TP585       ((Pwm_ChannelType)18U)


/**
* @brief Symbolic Names for configured channels - ecuc 2108 compliant.
*/
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_CTRL_AUDI_LED_01       ((Pwm_ChannelType)0U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_ZM_SPEED_CM_WPM_01       ((Pwm_ChannelType)1U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_STATUS_LED_BLUE_CU_LED       ((Pwm_ChannelType)2U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_STATUS_LED_GREEN_CU_LED       ((Pwm_ChannelType)3U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_STATUS_LED_RED_CU_LED       ((Pwm_ChannelType)4U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_SYNC_PFC_CM_PPM       ((Pwm_ChannelType)5U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_LS_U_CM_WPM_01       ((Pwm_ChannelType)6U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_HS_U_CM_WPM_01       ((Pwm_ChannelType)7U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_LS_V_CM_WPM_01       ((Pwm_ChannelType)8U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_HS_V_CM_WPM_01       ((Pwm_ChannelType)9U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_LS_W_CM_WPM_01       ((Pwm_ChannelType)10U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_HS_W_CM_WPM_01       ((Pwm_ChannelType)11U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_FAN_TACH_PPM_CM_05       ((Pwm_ChannelType)12U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_THRESH_CU_ASC       ((Pwm_ChannelType)13U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_D_ZM_HALL2_WPM_CM_10       ((Pwm_ChannelType)14U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_D_ZM_HALL_WPM_CM_10       ((Pwm_ChannelType)15U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_FAN_CTRL_CM_WPM_01       ((Pwm_ChannelType)16U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_PWM_FAN_TACH_WPM_CM_05       ((Pwm_ChannelType)17U)
#define PwmConf_PwmChannelConfigSet_PwmChannel_ET2C5_TP585       ((Pwm_ChannelType)18U)


/* ISR enable macros not generated because PwmNotificationSupported was not checked - notifications 
not supported in this configuration */


/* Array of boolean flags stating that a FlexPwm Module has already been processed */
  
/* Make sure faults are disabled for all unused FlexPwm modules */
#define PWM_FLEXPWM_0_FAULT_ISR_USED  (STD_OFF)
#define PWM_FLEXPWM_1_FAULT_ISR_USED  (STD_OFF)

/* On Panther platform FlexPwm Module 2 is not existent */
#define PWM_FLEXPWM_2_FAULT_ISR_USED  (STD_OFF)



/** @brief FlexPwm support for Phase Shifted channels */
#define PWM_FLEXPWM_PHASE_SHIFTED   (STD_OFF)

/** @brief Symbolic Name for period det error */
#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    #define PWM_E_PERIODVALUE       (0x1AU)
#endif

/** @brief Defines the maximum number of hw channels in the current configuration */
#define  PWM_HW_CHANNELS_NO_U8 (PWM_FLEXPWM_CHANNELS_NO + PWM_ETIMER_CHANNELS_NO)

/** @brief Defines the maximum value of the period - this value is hardware/platform dependent */
#define PWM_MAX_PERIOD   (0xFFFFU)
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief      Pwm period type (the value of the period is platform dependent and thus configurable)
* @implements Pwm_PeriodType_typedef
*/
typedef uint16 Pwm_PeriodType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_Cfg_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_Cfg_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_Cfg_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


  
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_Cfg_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

#endif    /*PWM_CFG_H*/

/** @} */

