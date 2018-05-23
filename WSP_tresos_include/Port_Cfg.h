/**
* @file    Port_Cfg.h
* @implements Port_Cfg.h_Artifact
*
* @version 2.0.0
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup Port
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : SIUL2
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/


#ifndef PORT_CFG_H
#define PORT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linkershall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers. 
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_CFG_H_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section PORT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function.
* These objects are used in various parts of the code.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port_EnvCfg.h"
#include "Port_Siul2_Types.h"




/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_VENDOR_ID_CFG_H                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_H        0
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_H     3
#define PORT_SW_MAJOR_VERSION_CFG_H                2
#define PORT_SW_MINOR_VERSION_CFG_H                0
#define PORT_SW_PATCH_VERSION_CFG_H                0

/*=================================================================================================
*                               FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_Cfg.h and Port_SIUL_Types.h file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_SIUL2_VENDOR_ID_TYPES_H)
    #error "Port_Cfg.h and Port_Siul2_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Port_Siul2_Types.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_TYPES_H)   ||  \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_SIUL2_AR_RELEASE_MINOR_VERSION_TYPES_H)   ||  \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_SIUL2_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_Siul2_Types.h are different"
#endif
/* Check if Port_Cfg.h and Port_Siul2_Types.h file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_SIUL2_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_SIUL2_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_SIUL2_SW_PATCH_VERSION_TYPES_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_Siul2_Types.h are different"
#endif

/* Check if Port_Cfg.h file and Port_EnvCfg header file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_ENVCFG_VENDOR_ID)
    #error "Port_Cfg.h and Port_EnvCfg.h have different vendor IDs"
#endif

#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_MAJOR_VERSION)      || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_MINOR_VERSION)      || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_EnvCfg.h are different"
#endif
/* Check if Port_Cfg.h and PORT header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_ENVCFG_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_ENVCFG_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_ENVCFG_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Port_Cfg.h and Port_EnvCfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief       Ensure better readability of the configuration
* @note 
*
* @violates @ref PORT_CFG_H_REF_3 Function-like macro defined.
*/
#define SHL_PAD_U16(x)                      ((uint16)(((uint16)1) << (x)))

/**
* @brief PSMI setting not available
* @note The current platform does not implement pad selection for multiplexed input for current pin.
*       Used for better readability of PSMI settings.
*
*/
#define NO_INPUTMUX_U16                     ((uint16)0xFFFFU)

/**
* @brief Show the Platform used.
* @note This define can be used by test phase.  
*
*/
#define PLATFORM_PANTHER
/**
* @brief Show the IPV used.
* @note This define can be used by test phase.
*
*/
#define IPV_SIUL2_USED


/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                  ((Port_PinModeType)0)
/** @brief Port Alternate 1 Mode */
#define PORT_ALT1_FUNC_MODE             ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/** @brief Port Analog input Mode */
#define PORT_ANALOG_INPUT_MODE          ((Port_PinModeType)5)
/** @brief Port Input 1 Mode */
#define PORT_INPUT1_MODE                ((Port_PinModeType)6)
/** @brief Port Input 2 Mode */
#define PORT_INPUT2_MODE                ((Port_PinModeType)7)
/** @brief Port Input 3 Mode */
#define PORT_INPUT3_MODE                ((Port_PinModeType)8)
/** @brief Port Input 4 Mode */
#define PORT_INPUT4_MODE                ((Port_PinModeType)9)
/** @brief Port Input 5 Mode */
#define PORT_INPUT5_MODE                ((Port_PinModeType)10)
/** @brief Port Input/Output 1 Mode */
#define PORT_INOUT1_MODE                ((Port_PinModeType)11)
/** @brief Port Input/Output 2 Mode */
#define PORT_INOUT2_MODE                ((Port_PinModeType)12)
/** @brief Port Input/Output 3 Mode */
#define PORT_INOUT3_MODE                ((Port_PinModeType)13)
/** @brief Port Input/Output 4 Mode */
#define PORT_INOUT4_MODE                ((Port_PinModeType)14)
/** @brief Port Input Mode */
#define PORT_ONLY_INPUT_MODE            ((Port_PinModeType)15)

/** @brief Port Abstraction Modes */



#define    PORT0_GPIO        (PORT_GPIO_MODE)
#define    PORT0_eTimer0_ETC0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT0_DSPI2_SCK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT0_eTimer0_ETC0_IN        (PORT_INPUT1_MODE)
#define    PORT0_DSPI2_SCK_IN        (PORT_INPUT2_MODE)
#define    PORT0_SIUL2_IRQ0        (PORT_INPUT3_MODE)
#define    PORT0_eTimer0_ETC0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT0_DSPI2_SCK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT1_GPIO        (PORT_GPIO_MODE)
#define    PORT1_eTimer0_ETC1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT1_DSPI2_SOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT1_eTimer0_ETC1_IN        (PORT_INPUT1_MODE)
#define    PORT1_SIUL2_IRQ1        (PORT_INPUT2_MODE)
#define    PORT1_eTimer0_ETC1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT2_GPIO        (PORT_GPIO_MODE)
#define    PORT2_eTimer0_ETC2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT2_FlexPWM0_A3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT2_MC_RGM_ABS0        (PORT_INPUT1_MODE)
#define    PORT2_DSPI2_SIN        (PORT_INPUT2_MODE)
#define    PORT2_eTimer0_ETC2_IN        (PORT_INPUT3_MODE)
#define    PORT2_SIUL2_IRQ2        (PORT_INPUT4_MODE)
#define    PORT2_FlexPWM0_A3_IN        (PORT_INPUT5_MODE)
#define    PORT2_eTimer0_ETC2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT2_FlexPWM0_A3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT3_GPIO        (PORT_GPIO_MODE)
#define    PORT3_eTimer0_ETC3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT3_DSPI2_CS0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT3_FlexPWM0_B3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT3_MC_RGM_ABS2        (PORT_INPUT1_MODE)
#define    PORT3_eTimer0_ETC3_IN        (PORT_INPUT2_MODE)
#define    PORT3_DSPI2_CS0_IN        (PORT_INPUT3_MODE)
#define    PORT3_SIUL2_IRQ3        (PORT_INPUT4_MODE)
#define    PORT3_FlexPWM0_B3_IN        (PORT_INPUT5_MODE)
#define    PORT3_eTimer0_ETC3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT3_DSPI2_CS0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT3_FlexPWM0_B3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT4_GPIO        (PORT_GPIO_MODE)
#define    PORT4_eTimer1_ETC0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT4_DSPI2_CS1        (PORT_ALT2_FUNC_MODE)
#define    PORT4_eTimer0_ETC4_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT4_FlexPWM1_A2_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT4_FlexPWM1_A2_IN        (PORT_INPUT1_MODE)
#define    PORT4_SIUL2_IRQ4        (PORT_INPUT2_MODE)
#define    PORT4_MC_RGM_FAB        (PORT_INPUT3_MODE)
#define    PORT4_eTimer0_ETC4_IN        (PORT_INPUT4_MODE)
#define    PORT4_eTimer1_ETC0_IN        (PORT_INPUT5_MODE)
#define    PORT4_eTimer1_ETC0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT4_eTimer0_ETC4_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT4_FlexPWM1_A2_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT5_GPIO        (PORT_GPIO_MODE)
#define    PORT5_DSPI1_CS0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT5_eTimer1_ETC5_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT5_DSPI0_CS7        (PORT_ALT3_FUNC_MODE)
#define    PORT5_SIUL2_IRQ5        (PORT_INPUT1_MODE)
#define    PORT5_eTimer1_ETC5_IN        (PORT_INPUT2_MODE)
#define    PORT5_DSPI1_CS0_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT5_DSPI1_CS0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT5_eTimer1_ETC5_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT6_GPIO        (PORT_GPIO_MODE)
#define    PORT6_DSPI1_SCK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT6_eTimer2_ETC2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT6_SIUL2_IRQ6        (PORT_INPUT1_MODE)
#define    PORT6_eTimer2_ETC2_IN        (PORT_INPUT2_MODE)
#define    PORT6_DSPI1_SCK_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT6_DSPI1_SCK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT6_eTimer2_ETC2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT7_GPIO        (PORT_GPIO_MODE)
#define    PORT7_DSPI1_SOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT7_eTimer2_ETC3_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT7_SIUL2_IRQ7        (PORT_INPUT1_MODE)
#define    PORT7_eTimer2_ETC3_IN        (PORT_INPUT2_MODE)
#define    PORT7_eTimer2_ETC3_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT8_GPIO        (PORT_GPIO_MODE)
#define    PORT8_eTimer2_ETC4_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT8_DSPI1_SIN        (PORT_INPUT1_MODE)
#define    PORT8_SIUL2_IRQ8        (PORT_INPUT2_MODE)
#define    PORT8_eTimer2_ETC4_IN        (PORT_INPUT3_MODE)
#define    PORT8_eTimer2_ETC4_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT9_GPIO        (PORT_GPIO_MODE)
#define    PORT9_DSPI2_CS1        (PORT_ALT1_FUNC_MODE)
#define    PORT9_eTimer2_ETC5_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT9_FlexPWM0_B3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT9_FlexPWM0_FAULT0        (PORT_INPUT1_MODE)
#define    PORT9_eTimer2_ETC5_IN        (PORT_INPUT2_MODE)
#define    PORT9_FlexPWM0_B3_IN        (PORT_INPUT3_MODE)
#define    PORT9_SENT0_RX1        (PORT_INPUT4_MODE)
#define    PORT9_eTimer2_ETC5_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT9_FlexPWM0_B3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT10_GPIO        (PORT_GPIO_MODE)
#define    PORT10_DSPI2_CS0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT10_FlexPWM0_B0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT10_FlexPWM0_X2_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT10_DSPI2_CS0_IN        (PORT_INPUT1_MODE)
#define    PORT10_SIUL2_IRQ9        (PORT_INPUT2_MODE)
#define    PORT10_FlexPWM0_B0_IN        (PORT_INPUT3_MODE)
#define    PORT10_FlexPWM0_X2_IN        (PORT_INPUT4_MODE)
#define    PORT10_SENT1_RX1        (PORT_INPUT5_MODE)
#define    PORT10_DSPI2_CS0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT10_FlexPWM0_B0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT10_FlexPWM0_X2_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT11_GPIO        (PORT_GPIO_MODE)
#define    PORT11_DSPI2_SCK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT11_FlexPWM0_A0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT11_FlexPWM0_A2_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT11_DSPI2_SCK_IN        (PORT_INPUT1_MODE)
#define    PORT11_SIUL2_IRQ10        (PORT_INPUT2_MODE)
#define    PORT11_FlexPWM0_A0_IN        (PORT_INPUT3_MODE)
#define    PORT11_FlexPWM0_A2_IN        (PORT_INPUT4_MODE)
#define    PORT11_DSPI2_SCK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT11_FlexPWM0_A0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT11_FlexPWM0_A2_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT12_GPIO        (PORT_GPIO_MODE)
#define    PORT12_DSPI2_SOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT12_FlexPWM0_A2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT12_FlexPWM0_B2_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT12_SIUL2_IRQ11        (PORT_INPUT1_MODE)
#define    PORT12_FlexPWM0_A2_IN        (PORT_INPUT2_MODE)
#define    PORT12_FlexPWM0_B2_IN        (PORT_INPUT3_MODE)
#define    PORT12_FlexPWM0_A2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT12_FlexPWM0_B2_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT13_GPIO        (PORT_GPIO_MODE)
#define    PORT13_FlexPWM0_B2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT13_FlexPWM0_FAULT0        (PORT_INPUT1_MODE)
#define    PORT13_DSPI2_SIN        (PORT_INPUT2_MODE)
#define    PORT13_SIUL2_IRQ12        (PORT_INPUT3_MODE)
#define    PORT13_FlexPWM0_B2_IN        (PORT_INPUT4_MODE)
#define    PORT13_FlexPWM0_B2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT14_GPIO        (PORT_GPIO_MODE)
#define    PORT14_CAN1_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT14_eTimer1_ETC4_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT14_SIUL2_IRQ13        (PORT_INPUT1_MODE)
#define    PORT14_eTimer1_ETC4_IN        (PORT_INPUT2_MODE)
#define    PORT14_eTimer1_ETC4_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT15_GPIO        (PORT_GPIO_MODE)
#define    PORT15_eTimer1_ETC5_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT15_CAN0_RX        (PORT_INPUT1_MODE)
#define    PORT15_CAN1_RX        (PORT_INPUT2_MODE)
#define    PORT15_SIUL2_IRQ14        (PORT_INPUT3_MODE)
#define    PORT15_eTimer1_ETC5_IN        (PORT_INPUT4_MODE)
#define    PORT15_eTimer1_ETC5_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT16_GPIO        (PORT_GPIO_MODE)
#define    PORT16_CAN0_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT16_eTimer1_ETC2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT16_SSCM_DEBUG0        (PORT_ALT3_FUNC_MODE)
#define    PORT16_SIUL2_IRQ15        (PORT_INPUT1_MODE)
#define    PORT16_eTimer1_ETC2_IN        (PORT_INPUT2_MODE)
#define    PORT16_eTimer1_ETC2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT17_GPIO        (PORT_GPIO_MODE)
#define    PORT17_eTimer1_ETC3_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT17_SSCM_DEBUG1        (PORT_ALT3_FUNC_MODE)
#define    PORT17_CAN0_RX        (PORT_INPUT1_MODE)
#define    PORT17_CAN1_RX        (PORT_INPUT2_MODE)
#define    PORT17_SIUL2_IRQ16        (PORT_INPUT3_MODE)
#define    PORT17_eTimer1_ETC3_IN        (PORT_INPUT4_MODE)
#define    PORT17_eTimer1_ETC3_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT18_GPIO        (PORT_GPIO_MODE)
#define    PORT18_LIN0_TXD        (PORT_ALT1_FUNC_MODE)
#define    PORT18_DSPI0_CS4        (PORT_ALT2_FUNC_MODE)
#define    PORT18_SSCM_DEBUG2        (PORT_ALT3_FUNC_MODE)
#define    PORT18_SIUL2_IRQ17        (PORT_INPUT1_MODE)
#define    PORT19_GPIO        (PORT_GPIO_MODE)
#define    PORT19_DSPI0_CS5        (PORT_ALT2_FUNC_MODE)
#define    PORT19_SSCM_DEBUG3        (PORT_ALT3_FUNC_MODE)
#define    PORT19_LIN0_RXD        (PORT_INPUT1_MODE)
#define    PORT20_GPIO        (PORT_GPIO_MODE)
#define    PORT20_TDO_MUX_TDO        (PORT_ALT1_FUNC_MODE)
#define    PORT21_GPIO        (PORT_GPIO_MODE)
#define    PORT21_DSPI0_CS7        (PORT_ALT1_FUNC_MODE)
#define    PORT22_GPIO        (PORT_GPIO_MODE)
#define    PORT22_MC_CGM_CLKOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT22_DSPI2_CS2        (PORT_ALT2_FUNC_MODE)
#define    PORT22_SIUL2_IRQ18        (PORT_INPUT1_MODE)
#define    PORT23_GPI        (PORT_GPIO_MODE)
#define    PORT23_ADC0_AN0        (PORT_ANALOG_INPUT_MODE)
#define    PORT23_LIN0_RXD        (PORT_INPUT1_MODE)
#define    PORT24_GPI        (PORT_GPIO_MODE)
#define    PORT24_ADC0_AN1        (PORT_ANALOG_INPUT_MODE)
#define    PORT24_eTimer0_ETC5_IN        (PORT_INPUT1_MODE)
#define    PORT25_GPI        (PORT_GPIO_MODE)
#define    PORT25_ADC0_ADC1_AN11        (PORT_ANALOG_INPUT_MODE)
#define    PORT26_GPI        (PORT_GPIO_MODE)
#define    PORT26_ADC0_ADC1_AN12        (PORT_ANALOG_INPUT_MODE)
#define    PORT27_GPI        (PORT_GPIO_MODE)
#define    PORT27_ADC0_ADC1_AN13        (PORT_ANALOG_INPUT_MODE)
#define    PORT28_GPI        (PORT_GPIO_MODE)
#define    PORT28_ADC0_ADC1_AN14        (PORT_ANALOG_INPUT_MODE)
#define    PORT29_GPI        (PORT_GPIO_MODE)
#define    PORT29_ADC1_AN0        (PORT_ANALOG_INPUT_MODE)
#define    PORT29_LIN1_RXD        (PORT_INPUT1_MODE)
#define    PORT30_GPI        (PORT_GPIO_MODE)
#define    PORT30_ADC1_AN1        (PORT_ANALOG_INPUT_MODE)
#define    PORT30_eTimer0_ETC4_IN        (PORT_INPUT1_MODE)
#define    PORT30_SIUL2_IRQ19        (PORT_INPUT2_MODE)
#define    PORT31_GPI        (PORT_GPIO_MODE)
#define    PORT31_ADC1_AN2        (PORT_ANALOG_INPUT_MODE)
#define    PORT31_SIUL2_IRQ20        (PORT_INPUT1_MODE)
#define    PORT32_GPI        (PORT_GPIO_MODE)
#define    PORT32_ADC1_AN3        (PORT_ANALOG_INPUT_MODE)
#define    PORT33_GPI        (PORT_GPIO_MODE)
#define    PORT33_ADC0_AN2        (PORT_ANALOG_INPUT_MODE)
#define    PORT34_GPI        (PORT_GPIO_MODE)
#define    PORT34_ADC0_AN3        (PORT_ANALOG_INPUT_MODE)
#define    PORT36_GPIO        (PORT_GPIO_MODE)
#define    PORT36_DSPI0_CS0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT36_FlexPWM0_X1_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT36_SSCM_DEBUG4        (PORT_ALT3_FUNC_MODE)
#define    PORT36_SIUL2_IRQ22        (PORT_INPUT1_MODE)
#define    PORT36_FlexPWM0_X1_IN        (PORT_INPUT2_MODE)
#define    PORT36_DSPI0_CS0_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT36_DSPI0_CS0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT36_FlexPWM0_X1_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT37_GPIO        (PORT_GPIO_MODE)
#define    PORT37_DSPI0_SCK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT37_SSCM_DEBUG5        (PORT_ALT3_FUNC_MODE)
#define    PORT37_FlexPWM0_FAULT3        (PORT_INPUT1_MODE)
#define    PORT37_SIUL2_IRQ23        (PORT_INPUT2_MODE)
#define    PORT37_DSPI0_SCK_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT37_DSPI0_SCK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT38_GPIO        (PORT_GPIO_MODE)
#define    PORT38_DSPI0_SOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT38_FlexPWM0_B1_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT38_SSCM_DEBUG6        (PORT_ALT3_FUNC_MODE)
#define    PORT38_SIUL2_IRQ24        (PORT_INPUT1_MODE)
#define    PORT38_FlexPWM0_B1_IN        (PORT_INPUT2_MODE)
#define    PORT38_FlexPWM0_B1_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT39_GPIO        (PORT_GPIO_MODE)
#define    PORT39_FlexPWM0_A1_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT39_SSCM_DEBUG7        (PORT_ALT3_FUNC_MODE)
#define    PORT39_DSPI0_SIN        (PORT_INPUT1_MODE)
#define    PORT39_FlexPWM0_A1_IN        (PORT_INPUT2_MODE)
#define    PORT39_FlexPWM0_A1_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT42_GPIO        (PORT_GPIO_MODE)
#define    PORT42_DSPI2_CS2        (PORT_ALT1_FUNC_MODE)
#define    PORT42_FlexPWM0_A3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT42_FlexPWM0_FAULT1        (PORT_INPUT1_MODE)
#define    PORT42_FlexPWM0_A3_IN        (PORT_INPUT2_MODE)
#define    PORT42_FlexPWM0_A3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT43_GPIO        (PORT_GPIO_MODE)
#define    PORT43_eTimer0_ETC4_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT43_DSPI2_CS2        (PORT_ALT2_FUNC_MODE)
#define    PORT43_ENET0_TX_ER        (PORT_ALT3_FUNC_MODE)
#define    PORT43_eTimer0_ETC4_IN        (PORT_INPUT1_MODE)
#define    PORT43_DSPI3_CS0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT43_DSPI3_CS0_IN        (PORT_INPUT2_MODE)
#define    PORT43_eTimer0_ETC4_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT43_DSPI3_CS0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT44_GPIO        (PORT_GPIO_MODE)
#define    PORT44_eTimer0_ETC5_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT44_DSPI2_CS3        (PORT_ALT2_FUNC_MODE)
#define    PORT44_LFAST_PH0_POS        (PORT_ALT3_FUNC_MODE)
#define    PORT44_DSPI3_CS1        (PORT_ALT4_FUNC_MODE)
#define    PORT44_eTimer0_ETC5_IN        (PORT_INPUT1_MODE)
#define    PORT44_SENT1_RX0        (PORT_INPUT2_MODE)
#define    PORT44_eTimer0_ETC5_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT45_GPIO        (PORT_GPIO_MODE)
#define    PORT45_eTimer1_ETC1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT45_FlexPWM1_A0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT45_CTU0_EXT_IN        (PORT_INPUT1_MODE)
#define    PORT45_FlexPWM0_SYNC        (PORT_INPUT2_MODE)
#define    PORT45_FlexPWM1_A0_IN        (PORT_INPUT3_MODE)
#define    PORT45_eTimer1_ETC1_IN        (PORT_INPUT4_MODE)
#define    PORT45_eTimer1_ETC1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT45_FlexPWM1_A0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT46_GPIO        (PORT_GPIO_MODE)
#define    PORT46_eTimer1_ETC2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT46_CTU0_EXT_TRIG        (PORT_ALT2_FUNC_MODE)
#define    PORT46_DSPI1_CS7        (PORT_ALT3_FUNC_MODE)
#define    PORT46_FlexPWM1_B0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT46_FlexPWM1_B0_IN        (PORT_INPUT1_MODE)
#define    PORT46_eTimer1_ETC2_IN        (PORT_INPUT2_MODE)
#define    PORT46_eTimer1_ETC2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT46_FlexPWM1_B0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT47_GPIO        (PORT_GPIO_MODE)
#define    PORT47_FlexRay_FR_A_TXEN        (PORT_ALT1_FUNC_MODE)
#define    PORT47_eTimer1_ETC0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT47_FlexPWM0_A1_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT47_CTU0_EXT_IN        (PORT_INPUT1_MODE)
#define    PORT47_FlexPWM0_SYNC        (PORT_INPUT2_MODE)
#define    PORT47_eTimer1_ETC0_IN        (PORT_INPUT3_MODE)
#define    PORT47_FlexPWM0_A1_IN        (PORT_INPUT4_MODE)
#define    PORT47_eTimer1_ETC0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT47_FlexPWM0_A1_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT48_GPIO        (PORT_GPIO_MODE)
#define    PORT48_FlexRay_FR_A_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT48_eTimer1_ETC1_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT48_FlexPWM0_B1_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT48_eTimer1_ETC1_IN        (PORT_INPUT1_MODE)
#define    PORT48_FlexPWM0_B1_IN        (PORT_INPUT2_MODE)
#define    PORT48_eTimer1_ETC1_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT48_FlexPWM0_B1_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT49_GPIO        (PORT_GPIO_MODE)
#define    PORT49_eTimer1_ETC2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT49_CTU0_EXT_TRIG        (PORT_ALT3_FUNC_MODE)
#define    PORT49_FlexRay_FR_A_RX        (PORT_INPUT1_MODE)
#define    PORT49_eTimer1_ETC2_IN        (PORT_INPUT2_MODE)
#define    PORT49_eTimer1_ETC2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT50_GPIO        (PORT_GPIO_MODE)
#define    PORT50_eTimer1_ETC3_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT50_FlexPWM0_X3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT50_FlexRay_FR_B_RX        (PORT_INPUT1_MODE)
#define    PORT50_eTimer1_ETC3_IN        (PORT_INPUT2_MODE)
#define    PORT50_FlexPWM0_X3_IN        (PORT_INPUT3_MODE)
#define    PORT50_eTimer1_ETC3_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT50_FlexPWM0_X3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT51_GPIO        (PORT_GPIO_MODE)
#define    PORT51_FlexRay_FR_B_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT51_eTimer1_ETC4_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT51_FlexPWM0_A3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT51_eTimer1_ETC4_IN        (PORT_INPUT1_MODE)
#define    PORT51_FlexPWM0_A3_IN        (PORT_INPUT2_MODE)
#define    PORT51_eTimer1_ETC4_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT51_FlexPWM0_A3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT52_GPIO        (PORT_GPIO_MODE)
#define    PORT52_FlexRay_FR_B_TXEN        (PORT_ALT1_FUNC_MODE)
#define    PORT52_eTimer1_ETC5_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT52_FlexPWM0_B3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT52_eTimer1_ETC5_IN        (PORT_INPUT1_MODE)
#define    PORT52_FlexPWM0_B3_IN        (PORT_INPUT2_MODE)
#define    PORT52_eTimer1_ETC5_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT52_FlexPWM0_B3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT53_GPIO        (PORT_GPIO_MODE)
#define    PORT53_DSPI0_CS3        (PORT_ALT1_FUNC_MODE)
#define    PORT53_DSPI3_SOUT        (PORT_ALT4_FUNC_MODE)
#define    PORT53_FlexPWM0_FAULT2        (PORT_INPUT1_MODE)
#define    PORT53_SENT0_RX0        (PORT_INPUT2_MODE)
#define    PORT53_ENET0_RX_D1        (PORT_INPUT3_MODE)
#define    PORT54_GPIO        (PORT_GPIO_MODE)
#define    PORT54_DSPI0_CS2        (PORT_ALT1_FUNC_MODE)
#define    PORT54_FlexPWM0_X3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT54_DSPI3_SCK_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT54_FlexPWM0_FAULT1        (PORT_INPUT1_MODE)
#define    PORT54_FlexPWM0_X3_IN        (PORT_INPUT2_MODE)
#define    PORT54_DSPI3_SCK_IN        (PORT_INPUT3_MODE)
#define    PORT54_ENET0_RX_D0        (PORT_INPUT4_MODE)
#define    PORT54_FlexPWM0_X3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT54_DSPI3_SCK_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT55_GPIO        (PORT_GPIO_MODE)
#define    PORT55_DSPI1_CS3        (PORT_ALT1_FUNC_MODE)
#define    PORT55_DSPI0_CS4        (PORT_ALT3_FUNC_MODE)
#define    PORT55_SENT1_RX0        (PORT_INPUT1_MODE)
#define    PORT55_DSPI3_SIN        (PORT_INPUT2_MODE)
#define    PORT55_ENET0_RX_DV        (PORT_INPUT3_MODE)
#define    PORT56_GPIO        (PORT_GPIO_MODE)
#define    PORT56_DSPI1_CS2        (PORT_ALT1_FUNC_MODE)
#define    PORT56_eTimer1_ETC4_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT56_DSPI0_CS5        (PORT_ALT3_FUNC_MODE)
#define    PORT56_FlexPWM0_FAULT3        (PORT_INPUT1_MODE)
#define    PORT56_eTimer1_ETC4_IN        (PORT_INPUT2_MODE)
#define    PORT56_ENET0_RX_CLK        (PORT_INPUT3_MODE)
#define    PORT56_eTimer1_ETC4_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT57_GPIO        (PORT_GPIO_MODE)
#define    PORT57_FlexPWM0_X0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT57_LIN1_TXD        (PORT_ALT2_FUNC_MODE)
#define    PORT57_FlexPWM0_X0_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT57_FlexPWM0_X0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT58_GPIO        (PORT_GPIO_MODE)
#define    PORT58_FlexPWM0_A0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT58_ENET0_TX_D2        (PORT_ALT3_FUNC_MODE)
#define    PORT58_DSPI3_CS0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT58_eTimer0_ETC0_IN        (PORT_INPUT1_MODE)
#define    PORT58_FlexPWM0_A0_IN        (PORT_INPUT2_MODE)
#define    PORT58_DSPI3_CS0_IN        (PORT_INPUT3_MODE)
#define    PORT58_FlexPWM0_A0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT58_DSPI3_CS0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT59_GPIO        (PORT_GPIO_MODE)
#define    PORT59_FlexPWM0_B0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT59_DSPI3_CS1        (PORT_ALT3_FUNC_MODE)
#define    PORT59_DSPI3_SCK_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT59_eTimer0_ETC1_IN        (PORT_INPUT1_MODE)
#define    PORT59_FlexPWM0_B0_IN        (PORT_INPUT2_MODE)
#define    PORT59_DSPI3_SCK_IN        (PORT_INPUT3_MODE)
#define    PORT59_FlexPWM0_B0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT59_DSPI3_SCK_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT60_GPIO        (PORT_GPIO_MODE)
#define    PORT60_FlexPWM0_X1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT60_DSPI1_CS6        (PORT_ALT2_FUNC_MODE)
#define    PORT60_DSPI3_CS2        (PORT_ALT3_FUNC_MODE)
#define    PORT60_DSPI3_SOUT        (PORT_ALT4_FUNC_MODE)
#define    PORT60_LIN1_RXD        (PORT_INPUT1_MODE)
#define    PORT60_FlexPWM0_X1_IN        (PORT_INPUT2_MODE)
#define    PORT60_FlexPWM0_X1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT62_GPIO        (PORT_GPIO_MODE)
#define    PORT62_FlexPWM0_B1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT62_DSPI3_CS3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT62_eTimer0_ETC3_IN        (PORT_INPUT1_MODE)
#define    PORT62_FlexPWM0_B1_IN        (PORT_INPUT2_MODE)
#define    PORT62_DSPI3_SIN        (PORT_INPUT3_MODE)
#define    PORT62_FlexPWM0_B1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT62_DSPI3_CS3_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT62_DSPI3_CS3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT64_GPI        (PORT_GPIO_MODE)
#define    PORT64_ADC1_AN5_ADC3_AN4        (PORT_ANALOG_INPUT_MODE)
#define    PORT66_GPI        (PORT_GPIO_MODE)
#define    PORT66_ADC0_AN5        (PORT_ANALOG_INPUT_MODE)
#define    PORT68_GPI        (PORT_GPIO_MODE)
#define    PORT68_ADC0_AN7        (PORT_ANALOG_INPUT_MODE)
#define    PORT69_GPI        (PORT_GPIO_MODE)
#define    PORT69_ADC0_AN8        (PORT_ANALOG_INPUT_MODE)
#define    PORT70_GPI        (PORT_GPIO_MODE)
#define    PORT70_ADC0_ADC2_AN4        (PORT_ANALOG_INPUT_MODE)
#define    PORT71_GPI        (PORT_GPIO_MODE)
#define    PORT71_ADC0_AN6        (PORT_ANALOG_INPUT_MODE)
#define    PORT73_GPI        (PORT_GPIO_MODE)
#define    PORT73_ADC1_AN7_ADC3_AN6        (PORT_ANALOG_INPUT_MODE)
#define    PORT74_GPI        (PORT_GPIO_MODE)
#define    PORT74_ADC1_AN8_ADC3_AN7        (PORT_ANALOG_INPUT_MODE)
#define    PORT75_GPI        (PORT_GPIO_MODE)
#define    PORT75_ADC1_AN4_ADC3_AN3        (PORT_ANALOG_INPUT_MODE)
#define    PORT76_GPI        (PORT_GPIO_MODE)
#define    PORT76_ADC1_AN6_ADC3_AN5        (PORT_ANALOG_INPUT_MODE)
#define    PORT77_GPIO        (PORT_GPIO_MODE)
#define    PORT77_eTimer0_ETC5_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT77_DSPI2_CS3        (PORT_ALT2_FUNC_MODE)
#define    PORT77_DSPI1_CS4        (PORT_ALT3_FUNC_MODE)
#define    PORT77_DSPI3_SCK_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT77_SIUL2_IRQ25        (PORT_INPUT1_MODE)
#define    PORT77_eTimer0_ETC5_IN        (PORT_INPUT2_MODE)
#define    PORT77_DSPI3_SCK_IN        (PORT_INPUT3_MODE)
#define    PORT77_eTimer0_ETC5_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT77_DSPI3_SCK_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT78_GPIO        (PORT_GPIO_MODE)
#define    PORT78_eTimer1_ETC5_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT78_DSPI3_SOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT78_DSPI1_CS5        (PORT_ALT3_FUNC_MODE)
#define    PORT78_FlexPWM1_B2_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT78_FlexPWM1_B2_IN        (PORT_INPUT1_MODE)
#define    PORT78_SIUL2_IRQ26        (PORT_INPUT2_MODE)
#define    PORT78_eTimer1_ETC5_IN        (PORT_INPUT3_MODE)
#define    PORT78_eTimer1_ETC5_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT78_FlexPWM1_B2_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT79_GPIO        (PORT_GPIO_MODE)
#define    PORT79_DSPI0_CS1        (PORT_ALT1_FUNC_MODE)
#define    PORT79_ENET0_TIMER1        (PORT_ALT3_FUNC_MODE)
#define    PORT79_SIUL2_IRQ27        (PORT_INPUT1_MODE)
#define    PORT79_DSPI3_SIN        (PORT_INPUT2_MODE)
#define    PORT80_GPIO        (PORT_GPIO_MODE)
#define    PORT80_FlexPWM0_A1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT80_DSPI3_CS3_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT80_ENET0_MDC        (PORT_ALT3_FUNC_MODE)
#define    PORT80_eTimer0_ETC2_IN        (PORT_INPUT1_MODE)
#define    PORT80_SIUL2_IRQ28        (PORT_INPUT2_MODE)
#define    PORT80_FlexPWM0_A1_IN        (PORT_INPUT3_MODE)
#define    PORT80_FlexPWM0_A1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT80_DSPI3_CS3_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT80_DSPI3_CS3_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT83_GPIO        (PORT_GPIO_MODE)
#define    PORT83_DSPI0_CS6        (PORT_ALT1_FUNC_MODE)
#define    PORT83_DSPI3_CS2        (PORT_ALT3_FUNC_MODE)
#define    PORT83_ENET0_TIMER2_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT83_ENET0_TIMER2_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT83_ENET0_TIMER2_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT84_GPIO        (PORT_GPIO_MODE)
#define    PORT84_Nexus0_MDO3        (PORT_ALT2_FUNC_MODE)
#define    PORT84_DSPI3_CS1        (PORT_ALT3_FUNC_MODE)
#define    PORT85_GPIO        (PORT_GPIO_MODE)
#define    PORT85_Nexus0_MDO2        (PORT_ALT2_FUNC_MODE)
#define    PORT85_DSPI3_CS0_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT85_DSPI3_CS0_IN        (PORT_INPUT1_MODE)
#define    PORT85_DSPI3_CS0_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT86_GPIO        (PORT_GPIO_MODE)
#define    PORT86_Nexus0_MDO1        (PORT_ALT2_FUNC_MODE)
#define    PORT87_GPIO        (PORT_GPIO_MODE)
#define    PORT87_Nexus0_MCKO        (PORT_ALT2_FUNC_MODE)
#define    PORT88_GPIO        (PORT_GPIO_MODE)
#define    PORT88_Nexus0_MSEO_B1        (PORT_ALT2_FUNC_MODE)
#define    PORT89_GPIO        (PORT_GPIO_MODE)
#define    PORT89_Nexus0_MSEO_B0        (PORT_ALT2_FUNC_MODE)
#define    PORT90_GPIO        (PORT_GPIO_MODE)
#define    PORT90_Nexus0_EVTO_B        (PORT_ALT2_FUNC_MODE)
#define    PORT91_GPIO        (PORT_GPIO_MODE)
#define    PORT91_Nexus0_EVTI_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT92_GPIO        (PORT_GPIO_MODE)
#define    PORT92_eTimer1_ETC3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT92_FlexPWM1_A1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT92_FlexPWM1_A1_IN        (PORT_INPUT1_MODE)
#define    PORT92_SIUL2_IRQ30        (PORT_INPUT2_MODE)
#define    PORT92_eTimer1_ETC3_IN        (PORT_INPUT3_MODE)
#define    PORT92_eTimer1_ETC3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT92_FlexPWM1_A1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT93_GPIO        (PORT_GPIO_MODE)
#define    PORT93_eTimer1_ETC4_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT93_FlexPWM1_B1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT93_FlexPWM1_B1_IN        (PORT_INPUT1_MODE)
#define    PORT93_SIUL2_IRQ31        (PORT_INPUT2_MODE)
#define    PORT93_eTimer1_ETC4_IN        (PORT_INPUT3_MODE)
#define    PORT93_eTimer1_ETC4_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT93_FlexPWM1_B1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT94_GPIO        (PORT_GPIO_MODE)
#define    PORT94_LIN1_TXD        (PORT_ALT1_FUNC_MODE)
#define    PORT94_CAN2_TXD        (PORT_ALT2_FUNC_MODE)
#define    PORT95_GPIO        (PORT_GPIO_MODE)
#define    PORT95_LIN1_RXD        (PORT_INPUT1_MODE)
#define    PORT95_CAN2_RXD        (PORT_INPUT2_MODE)
#define    PORT98_GPIO        (PORT_GPIO_MODE)
#define    PORT98_FlexPWM0_X2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT98_DSPI1_CS1        (PORT_ALT2_FUNC_MODE)
#define    PORT98_FlexPWM0_X2_IN        (PORT_INPUT1_MODE)
#define    PORT98_FlexPWM0_X2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT99_GPIO        (PORT_GPIO_MODE)
#define    PORT99_FlexPWM0_A2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT99_eTimer0_ETC4_IN        (PORT_INPUT1_MODE)
#define    PORT99_FlexPWM0_A2_IN        (PORT_INPUT2_MODE)
#define    PORT99_FlexPWM0_A2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT100_GPIO        (PORT_GPIO_MODE)
#define    PORT100_FlexPWM0_B2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT100_eTimer0_ETC5_IN        (PORT_INPUT1_MODE)
#define    PORT100_FlexPWM0_B2_IN        (PORT_INPUT2_MODE)
#define    PORT100_FlexPWM0_B2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT101_GPIO        (PORT_GPIO_MODE)
#define    PORT101_FlexPWM0_X3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT101_DSPI2_CS3        (PORT_ALT2_FUNC_MODE)
#define    PORT101_ENET0_TX_EN        (PORT_ALT3_FUNC_MODE)
#define    PORT101_FlexPWM0_X3_IN        (PORT_INPUT1_MODE)
#define    PORT101_FlexPWM0_X3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT102_GPIO        (PORT_GPIO_MODE)
#define    PORT102_FlexPWM0_A3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT102_FlexPWM0_A3_IN        (PORT_INPUT1_MODE)
#define    PORT102_FlexPWM0_A3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT103_GPIO        (PORT_GPIO_MODE)
#define    PORT103_FlexPWM0_B3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT103_LFAST_RX_POS        (PORT_ONLY_INPUT_MODE)
#define    PORT103_FlexPWM0_B3_IN        (PORT_INPUT1_MODE)
#define    PORT103_FlexPWM0_B3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT104_GPIO        (PORT_GPIO_MODE)
#define    PORT104_FlexRay_DBG0        (PORT_ALT1_FUNC_MODE)
#define    PORT104_DSPI0_CS1        (PORT_ALT2_FUNC_MODE)
#define    PORT104_ENET0_RMII_CLK        (PORT_ALT3_FUNC_MODE)
#define    PORT104_FlexPWM0_FAULT0        (PORT_INPUT1_MODE)
#define    PORT104_SIUL2_IRQ21        (PORT_INPUT2_MODE)
#define    PORT104_SENT0_RX0        (PORT_INPUT3_MODE)
#define    PORT104_ENET0_TX_CLK        (PORT_INPUT4_MODE)
#define    PORT105_GPIO        (PORT_GPIO_MODE)
#define    PORT105_FlexRay_DBG1        (PORT_ALT1_FUNC_MODE)
#define    PORT105_DSPI1_CS1        (PORT_ALT2_FUNC_MODE)
#define    PORT105_ENET0_TX_D0        (PORT_ALT3_FUNC_MODE)
#define    PORT105_FlexPWM0_FAULT1        (PORT_INPUT1_MODE)
#define    PORT105_SIUL2_IRQ29        (PORT_INPUT2_MODE)
#define    PORT105_SENT1_RX0        (PORT_INPUT3_MODE)
#define    PORT106_GPIO        (PORT_GPIO_MODE)
#define    PORT106_FlexRay_DBG2        (PORT_ALT1_FUNC_MODE)
#define    PORT106_DSPI2_CS3        (PORT_ALT2_FUNC_MODE)
#define    PORT106_ENET0_TX_D1        (PORT_ALT3_FUNC_MODE)
#define    PORT106_FlexPWM0_FAULT2        (PORT_INPUT1_MODE)
#define    PORT106_SENT0_RX1        (PORT_INPUT2_MODE)
#define    PORT107_GPIO        (PORT_GPIO_MODE)
#define    PORT107_FlexRay_DBG3        (PORT_ALT1_FUNC_MODE)
#define    PORT107_ENET0_TX_D3        (PORT_ALT3_FUNC_MODE)
#define    PORT107_FlexPWM0_FAULT3        (PORT_INPUT1_MODE)
#define    PORT107_SENT1_RX1        (PORT_INPUT2_MODE)
#define    PORT116_GPIO        (PORT_GPIO_MODE)
#define    PORT116_FlexPWM1_X0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT116_eTimer2_ETC0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT116_eTimer2_ETC0_IN        (PORT_INPUT1_MODE)
#define    PORT116_ENET0_CRS        (PORT_INPUT2_MODE)
#define    PORT116_FlexPWM1_X0_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT116_FlexPWM1_X0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT116_eTimer2_ETC0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT117_GPIO        (PORT_GPIO_MODE)
#define    PORT117_FlexPWM1_A0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT117_DSPI0_CS4        (PORT_ALT3_FUNC_MODE)
#define    PORT117_FlexPWM1_A0_IN        (PORT_INPUT1_MODE)
#define    PORT117_ENET0_COL        (PORT_INPUT2_MODE)
#define    PORT117_FlexPWM1_A0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT118_GPIO        (PORT_GPIO_MODE)
#define    PORT118_FlexPWM1_B0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT118_DSPI0_CS5        (PORT_ALT3_FUNC_MODE)
#define    PORT118_FlexPWM1_B0_IN        (PORT_INPUT1_MODE)
#define    PORT118_FlexPWM1_B0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT119_GPIO        (PORT_GPIO_MODE)
#define    PORT119_FlexPWM1_X1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT119_eTimer2_ETC1_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT119_ENET0_MDIO_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT119_eTimer2_ETC1_IN        (PORT_INPUT2_MODE)
#define    PORT119_FlexPWM1_X1_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT119_FlexPWM1_X1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT119_eTimer2_ETC1_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT119_ENET0_MDIO_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT119_ENET0_MDIO_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT120_GPIO        (PORT_GPIO_MODE)
#define    PORT120_FlexPWM1_A1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT120_DSPI0_CS6        (PORT_ALT3_FUNC_MODE)
#define    PORT120_FlexPWM1_A1_IN        (PORT_INPUT1_MODE)
#define    PORT120_ENET0_RX_D2        (PORT_INPUT2_MODE)
#define    PORT120_FlexPWM1_A1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT121_GPIO        (PORT_GPIO_MODE)
#define    PORT121_FlexPWM1_B1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT121_DSPI0_CS7        (PORT_ALT3_FUNC_MODE)
#define    PORT121_FlexPWM1_B1_IN        (PORT_INPUT1_MODE)
#define    PORT121_FlexPWM1_B1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT122_GPIO        (PORT_GPIO_MODE)
#define    PORT122_FlexPWM1_X2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT122_eTimer2_ETC2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT122_eTimer2_ETC2_IN        (PORT_INPUT1_MODE)
#define    PORT122_FlexPWM1_X2_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT122_FlexPWM1_X2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT122_eTimer2_ETC2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT123_GPIO        (PORT_GPIO_MODE)
#define    PORT123_FlexPWM1_A2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT123_FlexPWM1_A2_IN        (PORT_INPUT1_MODE)
#define    PORT123_FlexPWM1_A2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT124_GPIO        (PORT_GPIO_MODE)
#define    PORT124_FlexPWM1_B2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT124_FlexPWM1_B2_IN        (PORT_INPUT1_MODE)
#define    PORT124_FlexPWM1_B2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT125_GPIO        (PORT_GPIO_MODE)
#define    PORT125_FlexPWM1_X3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT125_eTimer2_ETC3_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT125_eTimer2_ETC3_IN        (PORT_INPUT1_MODE)
#define    PORT125_FlexPWM1_X3_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT125_FlexPWM1_X3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT125_eTimer2_ETC3_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT126_GPIO        (PORT_GPIO_MODE)
#define    PORT126_FlexPWM1_A3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT126_eTimer2_ETC4_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT126_eTimer2_ETC4_IN        (PORT_INPUT1_MODE)
#define    PORT126_FlexPWM1_A3_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT126_FlexPWM1_A3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT126_eTimer2_ETC4_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT127_GPIO        (PORT_GPIO_MODE)
#define    PORT127_FlexPWM1_B3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT127_eTimer2_ETC5_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT127_eTimer2_ETC5_IN        (PORT_INPUT1_MODE)
#define    PORT127_FlexPWM1_B3_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT127_FlexPWM1_B3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT127_eTimer2_ETC5_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT128_GPIO        (PORT_GPIO_MODE)
#define    PORT128_eTimer2_ETC0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT128_DSPI0_CS4        (PORT_ALT2_FUNC_MODE)
#define    PORT128_FlexPWM1_FAULT0        (PORT_INPUT1_MODE)
#define    PORT128_eTimer2_ETC0_IN        (PORT_INPUT2_MODE)
#define    PORT128_eTimer2_ETC0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT129_GPIO        (PORT_GPIO_MODE)
#define    PORT129_eTimer2_ETC1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT129_DSPI0_CS5        (PORT_ALT2_FUNC_MODE)
#define    PORT129_FlexPWM1_FAULT1        (PORT_INPUT1_MODE)
#define    PORT129_eTimer2_ETC1_IN        (PORT_INPUT2_MODE)
#define    PORT129_ENET0_RX_ER        (PORT_INPUT3_MODE)
#define    PORT129_eTimer2_ETC1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT130_GPIO        (PORT_GPIO_MODE)
#define    PORT130_eTimer2_ETC2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT130_DSPI0_CS6        (PORT_ALT2_FUNC_MODE)
#define    PORT130_FlexPWM1_FAULT2        (PORT_INPUT1_MODE)
#define    PORT130_eTimer2_ETC2_IN        (PORT_INPUT2_MODE)
#define    PORT130_eTimer2_ETC2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT131_GPIO        (PORT_GPIO_MODE)
#define    PORT131_eTimer2_ETC3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT131_DSPI0_CS7        (PORT_ALT2_FUNC_MODE)
#define    PORT131_CTU0_EXT_TRIG        (PORT_ALT3_FUNC_MODE)
#define    PORT131_ENET0_TIMER0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT131_FlexPWM1_FAULT3        (PORT_INPUT1_MODE)
#define    PORT131_eTimer2_ETC3_IN        (PORT_INPUT2_MODE)
#define    PORT131_eTimer2_ETC3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT131_ENET0_TIMER0_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT131_ENET0_TIMER0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT132_GPIO        (PORT_GPIO_MODE)
#define    PORT132_Nexus0_NEX_RDY_B        (PORT_ALT2_FUNC_MODE)
#define    PORT133_GPIO        (PORT_GPIO_MODE)
#define    PORT133_CAN2_TXD        (PORT_ALT1_FUNC_MODE)
#define    PORT133_LFAST_PH0_NEG        (PORT_ALT3_FUNC_MODE)
#define    PORT134_GPIO        (PORT_GPIO_MODE)
#define    PORT134_LFAST_RX_NEG        (PORT_ALT3_FUNC_MODE)
#define    PORT134_CAN2_RXD        (PORT_INPUT1_MODE)
#define    PORT135_GPIO        (PORT_GPIO_MODE)
#define    PORT135_LFAST_REF_CLK        (PORT_ALT1_FUNC_MODE)
#define    PORT135_SENT0_RX0        (PORT_INPUT1_MODE)
#define    PORT136_GPIO        (PORT_GPIO_MODE)
#define    PORT136_SENT1_RX0        (PORT_INPUT1_MODE)
#define    PORT137_GPIO        (PORT_GPIO_MODE)
#define    PORT137_eTimer2_ETC4_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT137_eTimer2_ETC4_IN        (PORT_INPUT1_MODE)
#define    PORT137_eTimer2_ETC4_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT138_GPIO        (PORT_GPIO_MODE)
#define    PORT138_eTimer2_ETC5_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT138_eTimer2_ETC5_IN        (PORT_INPUT1_MODE)
#define    PORT138_eTimer2_ETC5_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT139_GPIO        (PORT_GPIO_MODE)
#define    PORT139_SENT0_RX1        (PORT_INPUT1_MODE)
#define    PORT140_GPIO        (PORT_GPIO_MODE)
#define    PORT140_SENT1_RX1        (PORT_INPUT1_MODE)
#define    PORT141_GPIO        (PORT_GPIO_MODE)
#define    PORT141_CTU1_EXT_TRIG_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT141_CTU1_EXT_TRIG_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT141_CTU1_EXT_TRIG_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT142_GPIO        (PORT_GPIO_MODE)
#define    PORT142_DSPI3_CS0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT142_DSPI3_CS0_IN        (PORT_INPUT1_MODE)
#define    PORT142_DSPI3_CS0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT143_GPIO        (PORT_GPIO_MODE)
#define    PORT143_DSPI3_SCK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT143_DSPI3_SCK_IN        (PORT_INPUT1_MODE)
#define    PORT143_DSPI3_SCK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT144_GPIO        (PORT_GPIO_MODE)
#define    PORT144_DSPI3_SOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT145_GPIO        (PORT_GPIO_MODE)
#define    PORT145_DSPI3_SIN        (PORT_INPUT1_MODE)
#define    PORT146_GPIO        (PORT_GPIO_MODE)
#define    PORT146_DSPI3_CS1        (PORT_ALT1_FUNC_MODE)
#define    PORT147_GPIO        (PORT_GPIO_MODE)
#define    PORT147_DSPI3_CS2        (PORT_ALT1_FUNC_MODE)
#define    PORT148_GPIO        (PORT_GPIO_MODE)
#define    PORT148_DSPI3_CS3        (PORT_ALT1_FUNC_MODE)
#define    PORT148_CTU1_EXT_IN        (PORT_INPUT1_MODE)
#define    PORT149_GPI        (PORT_GPIO_MODE)
#define    PORT149_ADC2_ADC3_AN0        (PORT_ANALOG_INPUT_MODE)
#define    PORT149_SENT0_RX1        (PORT_INPUT1_MODE)
#define    PORT150_GPI        (PORT_GPIO_MODE)
#define    PORT150_ADC2_ADC3_AN1        (PORT_ANALOG_INPUT_MODE)
#define    PORT150_SENT1_RX1        (PORT_INPUT1_MODE)
#define    PORT151_GPI        (PORT_GPIO_MODE)
#define    PORT151_ADC2_ADC3_AN2        (PORT_ANALOG_INPUT_MODE)
#define    PORT152_GPIO        (PORT_GPIO_MODE)
#define    PORT152_eTimer2_ETC4_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT152_eTimer2_ETC2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT152_CAN2_RXD        (PORT_INPUT1_MODE)
#define    PORT152_eTimer2_ETC2_IN        (PORT_INPUT2_MODE)
#define    PORT152_eTimer2_ETC4_IN        (PORT_INPUT3_MODE)
#define    PORT152_eTimer2_ETC4_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT152_eTimer2_ETC2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT153_GPIO        (PORT_GPIO_MODE)
#define    PORT153_eTimer2_ETC5_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT153_Nexus0_NEX_RDY_B        (PORT_ALT2_FUNC_MODE)
#define    PORT153_CTU1_EXT_IN        (PORT_INPUT1_MODE)
#define    PORT153_eTimer2_ETC5_IN        (PORT_INPUT2_MODE)
#define    PORT153_ENET0_RX_D3        (PORT_INPUT3_MODE)
#define    PORT153_eTimer2_ETC5_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT154_NMI_B        (PORT_ONLY_INPUT_MODE)


/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           (STD_ON)

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/

#define PORT_SET_PIN_DIRECTION_API      (STD_ON)


/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/

#define PORT_SET_PIN_MODE_API           (STD_OFF)


/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           (STD_OFF)

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API           (STD_ON)

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*
*/
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A0_SPI_SCLK_NVM_CU  0
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A1_SPI_MOSI_CU_NVM  1
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A2_SPI_MISO_NVM_CU  2
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A3_SPI_CS_CU_NVM  3
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A4_PWM_THRESH_CU_ASC  4
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A5_D_EN_AFE_CM_PPM_00  5
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A6_TP1036  6
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A7_TP1035  7
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A8_TP1034  8
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A9_PWM_STATUS_LED_GREEN_CU_LED  9
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A10_PWM_CTRL_AUDI_LED_01  10
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A14_CAN_DBG_TX_CM_WPM_01  11
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_A15_CAN_FOD_RX_WPM_CM_05  12
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B0_CAN_FOD_TX_CM_WPM_05  13
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B1_CAN_DBG_RX_WPM_CM_05  14
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B4_JTAG_TDO  15
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B5_JTAG_TDI  16
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B6_SPI_SRDY_CU_LPCPU  17
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B7_I_MEAS_BUCK_P1_BUCK_CM_05  18
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B8_I_MEAS_BUCK_P2_BUCK_CM_05  19
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B9_T_MEAS_PFC_POS_PPM_CM_01  20
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B10_T_MEAS_RECT_POS_PPM_CM_01  21
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B11_T_MEAS_WPC_POS_WPM_CM_01  22
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B12_T_MEAS_AMB_POS_WPM_CM_01  23
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B13_I_MEAS_ZM_WPM_CM_05  24
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_B15_U_MEAS_MUX_SBC_CU_01  25
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C0_U_MEAS_P3V3_S_CU  26
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C1_T_MEAS_WPM2_POS_WPM_CM_01  27
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C2_I_MEAS_WPC_REF_CM_01  28
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C4_SPI_CS_CU_SBC_01  29
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C5_SPI_SCLK_CU_SBC_01  30
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C6_SPI_MOSI_CU_SBC_01  31
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C7_SPI_MISO_SBC_CU_01  32
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C10_PWM_STATUS_LED_BLUE_CU_LED  33
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C12_D_ACOK_PFC_PPM_CM_05  34
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C13_D_ZM_HALL2_WPM_CM_10  35
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C14_D_ZM_HALL_WPM_CM_10  36
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_C15_PWM_ZM_SPEED_CM_WPM_01  37
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D0_D_INRUSHREL_ACTIVE_PPM_CM_10  38
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D2_PWM_FAN_CTRL_CM_WPM_01  39
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D5_SPI_MOSI_CU_LPCPU  40
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D6_SPI_SCLK_CU_LPCPU  41
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D7_SPI_MISO_LPCPU_CU  42
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D9_UART_TX_ADP_CM_01  43
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D10_SPI_CS_CU_LPCPU  44
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D11_PWM_FAN_TACH_PPM_CM_05  45
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D12_UART_RX_ADP_CM_01  46
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_D14_D_PGOOD_PFC_PPM_CM_05  47
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E0_U_MEAS_WPC_V_WPM_CM_01  48
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E2_U_MEAS_R_NETWORK_EXTERNAL_POS_05  49
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E4_U_MEAS_P12V0_CU  50
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E5_I_ASC_THRESHOLD_POSITIVE  51
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E6_I_MEAS_WPC_INPUT_WPM_CM_05  52
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E7_I_ASC_THRESHOLD_NEGATIVE  53
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E9_U_MEAS_AFE_WPM_CM_01  54
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E10_U_MEAS_P5V0_CU  55
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E11_I_MEAS_WPC_U_WPM_CM_05  56
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E12_U_MEAS_WPC_W_WPM_CM_01  57
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E13_D_OCURR_RESET_CM_BUCK_01  58
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E14_D_INT_SBC_CU_01  59
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_E15_D_RESET_RS485_CM_PPM_01  60
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_F0_D_ZC_WPC_U_01  61
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_F3_D_RESETASC_CU_ASC_01  62
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_F12_D_DBG_CLK_CU_LPCPU  63
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_G3_D_ZM_FAULT_B_WPM_CM_05  64
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_G5_PWM_STATUS_LED_RED_CU_LED  65
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_G9_D_OCURR_P1_BUCK_CM_05  66
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_G10_D_OCURR_P2_BUCK_CM_05  67
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_G11_D_STATUS_BUCK_CM_05  68
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H5_PWM_SYNC_PFC_CM_PPM_05  69
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H7_D_CTRL_CU_P25V0_CM_WPM_01  70
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H8_PWM_LS_U_CM_WPM_01  71
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H9_PWM_HS_U_CM_WPM_01  72
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H10_D_EN_CU_WPC_01  73
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H11_PWM_LS_V_CM_WPM_01  74
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H12_PWM_HS_V_CM_WPM_01  75
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H14_PWM_LS_W_CM_WPM_01  76
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_H15_PWM_HS_W_CM_WPM_01  77
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_I0_PWM_FAN_TACH_WPM_CM_05  78
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_I2_D_ZM_CCW_CM_WPM_01  79
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_I3_D_ZM_CW_CM_WPM_01  80
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_I5_D_STATUS_WPC_WPM_CM_01  81
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_I6_D_ASCDET_ASC_05  82
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_I9_D_ZC_WPC_V_01  83
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_I10_ET2C5_TP585  84
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_I14_D_ZM_EN_SAFETY_01  85
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_J3_D_DBG_RESET_CU_LPCPU  86
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_J4_D_EN_PSU_CM_WPM_01  87
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_J5_U_MEAS_WPC_U_WPM_CM_01  88
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_J6_I_MEAS_WPC_V_WPM_CM_05  89
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_J7_I_MEAS_WPC_W_WPM_CM_05  90
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_J8_D_ZC_WPC_W_01  91
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_0_PortContainer_0_PortPin_J9_D_DBG_DATA_CU_LPCPU  92


/**
* @brief Number of INMUX registers
* @details Platform constant
*/
#define PORT_NMBR_INMUX_REGS_U16    ((uint16)234)
/**
* @brief Number of available pad modes options
* @details Platform constant
*/
#define PAD_MODE_OPTIONS_U8         ((uint8)16)
/**
* @brief Number of pad 16 blocks
* @details Platform constant
*/
#define PAD_16BLOCK_NO_U8           ((uint8)10)
/**
 * @brief The last supported pin number
 */
#define PORT_MAX_PIN_PACKAGE_U16    ((uint16)154)



/**
* @brief Port driver Pre-Compile configuration switch
*/
#define PORT_PRECOMPILE_SUPPORT  (STD_ON)

/**
* @brief Declaration of configuration settings for PC configuration
*/
#define PORT_CONFIG_PC
/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16   ((uint16)93)
/**
* @brief The number of configured pins
*/

/**
 * @brief Number of UnUsed pin array
*/
#define PORT_MAX_UNUSED_PADS_U16   (41U)



#if (STD_ON == PORT_SET_PIN_MODE_API)
#define  PORT_INOUT_TABLE_NUM_ENTRIES_U16       ((uint16)117)
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */
/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*
* @api
*/
typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumPins;                                                     /**< @brief Number of used pads (to be configured) */
    VAR(uint16, AUTOMATIC) u16NumUnusedPins;                                               /**< @brief Number of unused pads */
    P2CONST(uint16, AUTOMATIC, PORT_APPL_CONST) au16UnusedPads;                            /**< @brief Unused pad id's array */
    P2CONST(Port_Siul2_UnUsedPinConfigType, AUTOMATIC, PORT_APPL_CONST) pUnusedPadConfig;  /**< @brief Unused pad configuration */
    P2CONST(Port_Siul2_PinConfigType, AUTOMATIC, PORT_APPL_CONST) pUsedPadConfig;          /**< @brief Used pads data configuration */
    P2CONST(Port_Siul2_PadSelConfigType, AUTOMATIC, PORT_APPL_CONST) pPadSelConfig;        /**< @brief Used pads INMUX configuration */
} Port_ConfigType;

/**
* @brief Settings for a INMUX register
* @details The structure @p Port_InMuxSettingType manages ExtraFunctions PinMode.
* 
*
* @api
*/
typedef struct
{
    VAR(uint16,AUTOMATIC) u16InMuxId;   /**< @brief The id of the INMUX register to be configured */
    VAR(uint8, AUTOMATIC) u8InMuxCode;  /**< @brief The value of the INMUX reg for signal allocation */
} Port_InMuxSettingType;

/**
* @brief Settings for a INOUT functionality
* @details The structure @p Port_InoutSettingType manages Inout PinModes.
* 
* @api
*/
typedef struct
{
    VAR(uint16,AUTOMATIC) u16MSCR;      /**< @brief The id of the MSCR register to be configured */
    VAR(uint8,AUTOMATIC)  u8Mode;       /**< @brief The mode to be configured */
    VAR(uint16,AUTOMATIC) u16InMuxId;   /**< @brief The id of the INMUX register to be configured */
    VAR(uint8, AUTOMATIC) u8InMuxCode;  /**< @brief The value of the INMUX reg for signal allocation */
} Port_InoutSettingType;
/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"



/**
* @brief External declaration of the Port configuration structure for pre-compiled mode
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(Port_ConfigType, PORT_CONST) Port_ConfigPC;


#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief External declaration of the Port pin description array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(uint16, PORT_CONST) Port_au16PinDescription[16][10];

/**
* @brief External declaration of the Port pad functionality inout settings table
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(Port_InoutSettingType,PORT_CONST) Port_aPadFunctInoutMuxSettings[PORT_INOUT_TABLE_NUM_ENTRIES_U16];

/**
* @brief External declaration of the Port pad inmux functionality settings array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(Port_InMuxSettingType,PORT_CONST) Port_aPadFunctInMuxSettings[212];

/**
* @brief External declaration of the Port pad inmux functionality settings index array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(uint16,PORT_CONST) Port_au16PadFunctInMuxIndex[155];
#endif

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#define PORT_START_SEC_CODE
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#define PORT_STOP_SEC_CODE
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

/* End of File */

