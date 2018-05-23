/**
*   @file    Dio_Cfg.h
*   @implements Dio_Cfg.h_Artifact
*   @version 2.0.0
*
*   @brief   AUTOSAR Dio configuration header.
*   @details This file is the Autosar DIO driver configuration header. This
*            file is automatically generated, do not modify manually.
*
*   @addtogroup DIO_CFG
*   @{
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

#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_Cfg_H_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external
*          identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
* 
* @section Dio_Cfg_H_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, 
*          Precautions shall be taken in order to prevent the contents of a header file 
*          being included twice. This violation is not fixed since the inclusion of MemMap.h is as per 
*          Autosar requirement MEMMAP003.
*
* @section Dio_Cfg_H_REF_3
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope 
*          if they are only accessed from within a single function. 
*          These objects are used in various parts of the code.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
*          rely on the significance of more than 31 characters. The used compilers use more than
*          31 chars for identifiers.
**/


/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Dio_EnvCfg.h"


/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_VENDOR_ID_CFG                   43
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG    4
#define DIO_AR_RELEASE_MINOR_VERSION_CFG    0
/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define DIO_AR_RELEASE_REVISION_VERSION_CFG 3
#define DIO_SW_MAJOR_VERSION_CFG            2
#define DIO_SW_MINOR_VERSION_CFG            0
#define DIO_SW_PATCH_VERSION_CFG            0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Dio_EnvCfg.h version check start */
#if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG != DIO_ENVCFG_AR_RELEASE_MAJOR_VERSION) ||   \
     (DIO_AR_RELEASE_MINOR_VERSION_CFG != DIO_ENVCFG_AR_RELEASE_MINOR_VERSION) ||   \
     (DIO_AR_RELEASE_REVISION_VERSION_CFG != DIO_ENVCFG_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AUTOSAR Version Numbers of Dio_Cfg.h and Dio_EnvCfg.h are different"
#endif

#if ((DIO_SW_MAJOR_VERSION_CFG != DIO_ENVCFG_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_CFG != DIO_ENVCFG_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_CFG != DIO_ENVCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Dio_Cfg.h and Dio_EnvCfg.h are different"
#endif

#if ((DIO_VENDOR_ID_CFG != DIO_ENVCFG_VENDOR_ID))
    #error "VENDOR ID for Dio_Cfg.h and Dio_EnvCfg.h is different"
#endif
/* Dio_EnvCfg.h version check end */
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/**
* @brief          Enable or Disable Development Error Detection.
*
* @implements     DIO_DEV_ERROR_DETECT_define
* @api
*/
#define DIO_DEV_ERROR_DETECT    (STD_OFF)

/**
* @brief          Function @p Dio_GetVersionInfo() enable switch.
*
* @implements DIO_VERSION_INFO_API_define
* @api
*/
#define DIO_VERSION_INFO_API    (STD_ON)

/**
* @brief          Function @p Dio_FlipChannel() enable switch.
*
* @api
*/
#define DIO_FLIP_CHANNEL_API    (STD_OFF)

/**
* @brief          Function @p Dio_MaskedWritePort() enable switch.
*
* @api
*/
#define DIO_MASKEDWRITEPORT_API (STD_OFF)

/**
* @brief          Reversed port functionality enable switch.
*
* @implements DIO_REVERSEPORTBITS_define
* @api
*/
#define DIO_REVERSEPORTBITS     (STD_OFF)

/**
* @brief          Undefined pins masking enable switch.
*
* @api
*/
#define DIO_READZERO_UNDEFINEDPORTS (STD_ON)


/**
* @brief          Number of implemented ports.
*
* @note           Used for channel, port and channel group validation.
*
* @api
*/
#define DIO_NUM_PORTS_U16   ((uint16)0xa)

/**
* @brief          Number channel in a port.
*
* @note           Used for channel, port and channel group validation.
*
* @api
*/
#define DIO_NUM_CHANNELS_PER_PORT_U16   ((uint16)(sizeof(Dio_PortLevelType) * 0x8U))

/**
* @brief          Number of channels available on the implemented ports.
*
* @note           Used for channel validation.
*
* @api
*/
#define DIO_NUM_CHANNELS_U16    ((uint16)(DIO_NUM_PORTS_U16 * DIO_NUM_CHANNELS_PER_PORT_U16))

/**
* @brief          Mask representing no available channels on a port.
*
* @note           Used for channel validation.
*
* @api
*/
#define DIO_NO_AVAILABLE_CHANNELS_U16   ((Dio_PortLevelType)0x0U)

/**
* @brief          Mask representing the maximum valid offset for a channel group.
*
* @note           Used for channel group validation.
*
* @api
*/
#define DIO_MAX_VALID_OFFSET_U8 ((uint8)0xFU)

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*   @note    Currently, no register protection mechanism is used for Dio driver.
*/
#define DIO_USER_MODE_SOFT_LOCKING  (STD_OFF)

/**
* @brief          Dio driver Pre-Compile configuration switch.
*
* @api
*/
#define DIO_PRECOMPILE_SUPPORT


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief          Symbolic name for the configuration Dio_ConfigPC.
*
*/
#define Dio_ConfigPC    (DioConfig_0)  

/* ========== DioConfig_0 ========== */

/* ---------- DIO_PORT_A ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_A.
*
*/
#define DioConf_DioPort_DIO_PORT_A  ((uint8)0x00U)

/**
* @brief          Symbolic name for the channel A5_D_EN_AFE_CM_PPM_00.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_A5_D_EN_AFE_CM_PPM_00 ((uint8)0x05U)

/* ---------- DIO_PORT_B ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_B.
*
*/
#define DioConf_DioPort_DIO_PORT_B  ((uint8)0x01U)

/**
* @brief          Symbolic name for the channel B6_SPI_SRDY_CU_LPCPU.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_B6_SPI_SRDY_CU_LPCPU ((uint8)0x16U)

/* ---------- DIO_PORT_C ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_C.
*
*/
#define DioConf_DioPort_DIO_PORT_C  ((uint8)0x02U)

/**
* @brief          Symbolic name for the channel C12_D_ACOK_PFC_PPM_CM_05.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_C12_D_ACOK_PFC_PPM_CM_05 ((uint8)0x2cU)

/* ---------- DIO_PORT_D ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_D.
*
*/
#define DioConf_DioPort_DIO_PORT_D  ((uint8)0x03U)

/**
* @brief          Symbolic name for the channel D0_D_INRUSHREL_ACTIVE_PPM_CM_10.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_D0_D_INRUSHREL_ACTIVE_PPM_CM_10 ((uint8)0x30U)

/**
* @brief          Symbolic name for the channel D14_D_PGOOD_PFC_PPM_CM_05.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_D14_D_PGOOD_PFC_PPM_CM_05 ((uint8)0x3eU)

/* ---------- DIO_PORT_E ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_E.
*
*/
#define DioConf_DioPort_DIO_PORT_E  ((uint8)0x04U)

/**
* @brief          Symbolic name for the channel E13_D_OCURR_RESET_CM_BUCK_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_E13_D_OCURR_RESET_CM_BUCK_01 ((uint8)0x4dU)

/**
* @brief          Symbolic name for the channel E15_D_RESET_RS485_CM_PPM_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_E15_D_RESET_RS485_CM_PPM_01 ((uint8)0x4fU)

/* ---------- DIO_PORT_F ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_F.
*
*/
#define DioConf_DioPort_DIO_PORT_F  ((uint8)0x05U)

/**
* @brief          Symbolic name for the channel F0_D_ZC_WPC_U_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_F0_D_ZC_WPC_U_01 ((uint8)0x50U)

/**
* @brief          Symbolic name for the channel F3_D_RESETASC_CU_ASC_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_F3_D_RESETASC_CU_ASC_01 ((uint8)0x53U)

/**
* @brief          Symbolic name for the channel F12_D_DBG_CLK_CU_LPCPU.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_F12_D_DBG_CLK_CU_LPCPU ((uint8)0x5cU)

/* ---------- DIO_PORT_G ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_G.
*
*/
#define DioConf_DioPort_DIO_PORT_G  ((uint8)0x06U)

/**
* @brief          Symbolic name for the channel G3_D_ZM_FAULT_B_WPM_CM_05.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_G3_D_ZM_FAULT_B_WPM_CM_05 ((uint8)0x63U)

/**
* @brief          Symbolic name for the channel G9_D_OCURR_P1_BUCK_CM_05.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_G9_D_OCURR_P1_BUCK_CM_05 ((uint8)0x69U)

/**
* @brief          Symbolic name for the channel G10_D_OCURR_P2_BUCK_CM_05.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_G10_D_OCURR_P2_BUCK_CM_05 ((uint8)0x6aU)

/**
* @brief          Symbolic name for the channel G11_D_STATUS_BUCK_CM_05.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_G11_D_STATUS_BUCK_CM_05 ((uint8)0x6bU)

/* ---------- DIO_PORT_H ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_H.
*
*/
#define DioConf_DioPort_DIO_PORT_H  ((uint8)0x07U)

/**
* @brief          Symbolic name for the channel H7_D_CTRL_CU_P25V0_CM_WPM_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_H7_D_CTRL_CU_P25V0_CM_WPM_01 ((uint8)0x77U)

/**
* @brief          Symbolic name for the channel H10_D_EN_CU_WPC_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_H10_D_EN_CU_WPC_01 ((uint8)0x7aU)

/* ---------- DIO_PORT_I ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_I.
*
*/
#define DioConf_DioPort_DIO_PORT_I  ((uint8)0x08U)

/**
* @brief          Symbolic name for the channel I2_D_ZM_CCW_CM_WPM_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_I2_D_ZM_CCW_CM_WPM_01 ((uint8)0x82U)

/**
* @brief          Symbolic name for the channel I3_D_ZM_CW_CM_WPM_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_I3_D_ZM_CW_CM_WPM_01 ((uint8)0x83U)

/**
* @brief          Symbolic name for the channel I5_D_STATUS_WPC_WPM_CM_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_I5_D_STATUS_WPC_WPM_CM_01 ((uint8)0x85U)

/**
* @brief          Symbolic name for the channel I6_D_ASCDET_ASC_05.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_I6_D_ASCDET_ASC_05 ((uint8)0x86U)

/**
* @brief          Symbolic name for the channel I9_D_ZC_WPC_V_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_I9_D_ZC_WPC_V_01 ((uint8)0x89U)

/**
* @brief          Symbolic name for the channel I14_D_ZM_EN_SAFETY_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_I14_D_ZM_EN_SAFETY_01 ((uint8)0x8eU)

/* ---------- DIO_PORT_J ---------- */

/**
* @brief          Symbolic name for the port DIO_PORT_J.
*
*/
#define DioConf_DioPort_DIO_PORT_J  ((uint8)0x09U)

/**
* @brief          Symbolic name for the channel J3_D_DBG_RESET_CU_LPCPU.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_J3_D_DBG_RESET_CU_LPCPU ((uint8)0x93U)

/**
* @brief          Symbolic name for the channel J4_D_EN_PSU_CM_WPM_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_J4_D_EN_PSU_CM_WPM_01 ((uint8)0x94U)

/**
* @brief          Symbolic name for the channel J8_D_ZC_WPC_W_01.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_J8_D_ZC_WPC_W_01 ((uint8)0x98U)

/**
* @brief          Symbolic name for the channel J9_D_DBG_DATA_CU_LPCPU.
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_J9_D_DBG_DATA_CU_LPCPU ((uint8)0x99U)


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief          Type of a DIO port representation.
*
* @implements     Dio_PortType_typedef
*
* @api
*/
typedef uint8 Dio_PortType;

/**
* @brief          Type of a DIO channel representation.
*
* @implements     Dio_ChannelType_typedef
*
* @api
*/
typedef uint8 Dio_ChannelType;

/**
* @brief          Type of a DIO port levels representation.
*
* @implements     Dio_PortLevelType_typedef
*
* @api
*/
typedef uint16 Dio_PortLevelType;

/**
* @brief          Type of a DIO channel levels representation.
*
* @implements     Dio_LevelType_typedef
*
* @api
*/
typedef uint8 Dio_LevelType;

/**
* @brief          Type of a DIO channel group representation.
*
* @implements     Dio_ChannelGroupType_struct
*
* @api
*/
typedef struct
{
    VAR(Dio_PortType, AUTOMATIC)      port;      /**< @brief Port identifier.  */
    VAR(uint8, AUTOMATIC)             offset;    /**< @brief Bit offset within the port. */
    VAR(Dio_PortLevelType, AUTOMATIC) mask;      /**< @brief Group mask. */
} Dio_ChannelGroupType;

/**
* @brief          Type of a DIO configuration structure.
*
* @note           In this implementation there is no need for a configuration
*                 structure there is only a dummy field, it is recommended
*                 to initialize this field to zero.
*
* @implements     Dio_ConfigType_struct
*
* @api
*/
typedef struct
{                                                                       
    VAR(uint8, AUTOMATIC) u8NumChannelGroups; /**< @brief Number of channel groups in configuration */
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupList;  /**< @brief 
                                               Pointer to list of channel groups in configuration */
} Dio_ConfigType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Dio_Cfg_H_REF_2 Precautions to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"
/**
* @brief Array of bitmaps of output pins available per port
*/
/** @violates @ref Dio_Cfg_H_REF_3 Objects shall be defined at block scope if they are only accessed from within a single function. */

extern CONST(Dio_PortLevelType, DIO_CONST) Dio_aAvailablePinsForWrite[DIO_NUM_PORTS_U16];

/**
* @brief Array of bitmaps of input pins available per port
*/
/** @violates @ref Dio_Cfg_H_REF_3 Objects shall be defined at block scope if they are only accessed from within a single function. */

extern CONST(Dio_PortLevelType, DIO_CONST) Dio_aAvailablePinsForRead[DIO_NUM_PORTS_U16];


/**
* @brief          List of channel groups in configuration DioConfig_0.
*/



#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Dio_Cfg_H_REF_2 Precautions to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"
/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} */
