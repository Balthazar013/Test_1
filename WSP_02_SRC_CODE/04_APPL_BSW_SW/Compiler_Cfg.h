/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined COMPILER_CFG_H)
#define COMPILER_CFG_H

/*==================[inclusions]=============================================*/

/*------------------[Compiler_Cfg extensions]--------------------------------*/

#if (defined COMPILERCFG_EXTENSION_FILE)
#include <Compiler_CfgExt.h>
#endif

/*==================[macros]=================================================*/

/*------------------[memory and pointer class of a module]-------------------*/

#if (defined ADC_CODE)
#error ADC_CODE already defined
#endif
#define ADC_CODE

#if (defined ADC_CONST)
#error ADC_CONST already defined
#endif
#define ADC_CONST

#if (defined ADC_APPL_DATA)
#error ADC_APPL_DATA already defined
#endif
#define ADC_APPL_DATA

#if (defined ADC_APPL_CONST)
#error ADC_APPL_CONST already defined
#endif
#define ADC_APPL_CONST

#if (defined ADC_APPL_CODE)
#error ADC_APPL_CODE already defined
#endif
#define ADC_APPL_CODE

#if (defined ADC_VAR_NOINIT)
#error ADC_VAR_NOINIT already defined
#endif
#define ADC_VAR_NOINIT

#if (defined ADC_VAR_POWER_ON_INIT)
#error ADC_VAR_POWER_ON_INIT already defined
#endif
#define ADC_VAR_POWER_ON_INIT

#if (defined ADC_VAR_FAST)
#error ADC_VAR_FAST already defined
#endif
#define ADC_VAR_FAST

#if (defined ADC_VAR)
#error ADC_VAR already defined
#endif
#define ADC_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined AUTOSAR_COMSTACKDATA)
#error AUTOSAR_COMSTACKDATA already defined
#endif
#define AUTOSAR_COMSTACKDATA


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined BASE_CODE)
#error BASE_CODE already defined
#endif
#define BASE_CODE

#if (defined BASE_CONST)
#error BASE_CONST already defined
#endif
#define BASE_CONST

#if (defined BASE_APPL_DATA)
#error BASE_APPL_DATA already defined
#endif
#define BASE_APPL_DATA

#if (defined BASE_APPL_CONST)
#error BASE_APPL_CONST already defined
#endif
#define BASE_APPL_CONST

#if (defined BASE_APPL_CODE)
#error BASE_APPL_CODE already defined
#endif
#define BASE_APPL_CODE

#if (defined BASE_VAR_NOINIT)
#error BASE_VAR_NOINIT already defined
#endif
#define BASE_VAR_NOINIT

#if (defined BASE_VAR_POWER_ON_INIT)
#error BASE_VAR_POWER_ON_INIT already defined
#endif
#define BASE_VAR_POWER_ON_INIT

#if (defined BASE_VAR_FAST)
#error BASE_VAR_FAST already defined
#endif
#define BASE_VAR_FAST

#if (defined BASE_VAR)
#error BASE_VAR already defined
#endif
#define BASE_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined BSWM_CODE)
#error BSWM_CODE already defined
#endif
#define BSWM_CODE

#if (defined BSWM_CONST)
#error BSWM_CONST already defined
#endif
#define BSWM_CONST

#if (defined BSWM_APPL_DATA)
#error BSWM_APPL_DATA already defined
#endif
#define BSWM_APPL_DATA

#if (defined BSWM_APPL_CONST)
#error BSWM_APPL_CONST already defined
#endif
#define BSWM_APPL_CONST

#if (defined BSWM_APPL_CODE)
#error BSWM_APPL_CODE already defined
#endif
#define BSWM_APPL_CODE

#if (defined BSWM_VAR_NOINIT)
#error BSWM_VAR_NOINIT already defined
#endif
#define BSWM_VAR_NOINIT

#if (defined BSWM_VAR_POWER_ON_INIT)
#error BSWM_VAR_POWER_ON_INIT already defined
#endif
#define BSWM_VAR_POWER_ON_INIT

#if (defined BSWM_VAR_FAST)
#error BSWM_VAR_FAST already defined
#endif
#define BSWM_VAR_FAST

#if (defined BSWM_VAR)
#error BSWM_VAR already defined
#endif
#define BSWM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CAL_CODE)
#error CAL_CODE already defined
#endif
#define CAL_CODE

#if (defined CAL_CONST)
#error CAL_CONST already defined
#endif
#define CAL_CONST

#if (defined CAL_APPL_DATA)
#error CAL_APPL_DATA already defined
#endif
#define CAL_APPL_DATA

#if (defined CAL_APPL_CONST)
#error CAL_APPL_CONST already defined
#endif
#define CAL_APPL_CONST

#if (defined CAL_APPL_CODE)
#error CAL_APPL_CODE already defined
#endif
#define CAL_APPL_CODE

#if (defined CAL_VAR_NOINIT)
#error CAL_VAR_NOINIT already defined
#endif
#define CAL_VAR_NOINIT

#if (defined CAL_VAR_POWER_ON_INIT)
#error CAL_VAR_POWER_ON_INIT already defined
#endif
#define CAL_VAR_POWER_ON_INIT

#if (defined CAL_VAR_FAST)
#error CAL_VAR_FAST already defined
#endif
#define CAL_VAR_FAST

#if (defined CAL_VAR)
#error CAL_VAR already defined
#endif
#define CAL_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CAN_CODE)
#error CAN_CODE already defined
#endif
#define CAN_CODE

#if (defined CAN_CONST)
#error CAN_CONST already defined
#endif
#define CAN_CONST

#if (defined CAN_APPL_DATA)
#error CAN_APPL_DATA already defined
#endif
#define CAN_APPL_DATA

#if (defined CAN_APPL_CONST)
#error CAN_APPL_CONST already defined
#endif
#define CAN_APPL_CONST

#if (defined CAN_APPL_CODE)
#error CAN_APPL_CODE already defined
#endif
#define CAN_APPL_CODE

#if (defined CAN_VAR_NOINIT)
#error CAN_VAR_NOINIT already defined
#endif
#define CAN_VAR_NOINIT

#if (defined CAN_VAR_POWER_ON_INIT)
#error CAN_VAR_POWER_ON_INIT already defined
#endif
#define CAN_VAR_POWER_ON_INIT

#if (defined CAN_VAR_FAST)
#error CAN_VAR_FAST already defined
#endif
#define CAN_VAR_FAST

#if (defined CAN_VAR)
#error CAN_VAR already defined
#endif
#define CAN_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CANIF_CODE)
#error CANIF_CODE already defined
#endif
#define CANIF_CODE

#if (defined CANIF_CONST)
#error CANIF_CONST already defined
#endif
#define CANIF_CONST

#if (defined CANIF_APPL_DATA)
#error CANIF_APPL_DATA already defined
#endif
#define CANIF_APPL_DATA

#if (defined CANIF_APPL_CONST)
#error CANIF_APPL_CONST already defined
#endif
#define CANIF_APPL_CONST

#if (defined CANIF_APPL_CODE)
#error CANIF_APPL_CODE already defined
#endif
#define CANIF_APPL_CODE

#if (defined CANIF_VAR_NOINIT)
#error CANIF_VAR_NOINIT already defined
#endif
#define CANIF_VAR_NOINIT

#if (defined CANIF_VAR_POWER_ON_INIT)
#error CANIF_VAR_POWER_ON_INIT already defined
#endif
#define CANIF_VAR_POWER_ON_INIT

#if (defined CANIF_VAR_FAST)
#error CANIF_VAR_FAST already defined
#endif
#define CANIF_VAR_FAST

#if (defined CANIF_VAR)
#error CANIF_VAR already defined
#endif
#define CANIF_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CANNM_CODE)
#error CANNM_CODE already defined
#endif
#define CANNM_CODE

#if (defined CANNM_CONST)
#error CANNM_CONST already defined
#endif
#define CANNM_CONST

#if (defined CANNM_APPL_DATA)
#error CANNM_APPL_DATA already defined
#endif
#define CANNM_APPL_DATA

#if (defined CANNM_APPL_CONST)
#error CANNM_APPL_CONST already defined
#endif
#define CANNM_APPL_CONST

#if (defined CANNM_APPL_CODE)
#error CANNM_APPL_CODE already defined
#endif
#define CANNM_APPL_CODE

#if (defined CANNM_VAR_NOINIT)
#error CANNM_VAR_NOINIT already defined
#endif
#define CANNM_VAR_NOINIT

#if (defined CANNM_VAR_POWER_ON_INIT)
#error CANNM_VAR_POWER_ON_INIT already defined
#endif
#define CANNM_VAR_POWER_ON_INIT

#if (defined CANNM_VAR_FAST)
#error CANNM_VAR_FAST already defined
#endif
#define CANNM_VAR_FAST

#if (defined CANNM_VAR)
#error CANNM_VAR already defined
#endif
#define CANNM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CANSM_CODE)
#error CANSM_CODE already defined
#endif
#define CANSM_CODE

#if (defined CANSM_CONST)
#error CANSM_CONST already defined
#endif
#define CANSM_CONST

#if (defined CANSM_APPL_DATA)
#error CANSM_APPL_DATA already defined
#endif
#define CANSM_APPL_DATA

#if (defined CANSM_APPL_CONST)
#error CANSM_APPL_CONST already defined
#endif
#define CANSM_APPL_CONST

#if (defined CANSM_APPL_CODE)
#error CANSM_APPL_CODE already defined
#endif
#define CANSM_APPL_CODE

#if (defined CANSM_VAR_NOINIT)
#error CANSM_VAR_NOINIT already defined
#endif
#define CANSM_VAR_NOINIT

#if (defined CANSM_VAR_POWER_ON_INIT)
#error CANSM_VAR_POWER_ON_INIT already defined
#endif
#define CANSM_VAR_POWER_ON_INIT

#if (defined CANSM_VAR_FAST)
#error CANSM_VAR_FAST already defined
#endif
#define CANSM_VAR_FAST

#if (defined CANSM_VAR)
#error CANSM_VAR already defined
#endif
#define CANSM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CANTP_CODE)
#error CANTP_CODE already defined
#endif
#define CANTP_CODE

#if (defined CANTP_CONST)
#error CANTP_CONST already defined
#endif
#define CANTP_CONST

#if (defined CANTP_APPL_DATA)
#error CANTP_APPL_DATA already defined
#endif
#define CANTP_APPL_DATA

#if (defined CANTP_APPL_CONST)
#error CANTP_APPL_CONST already defined
#endif
#define CANTP_APPL_CONST

#if (defined CANTP_APPL_CODE)
#error CANTP_APPL_CODE already defined
#endif
#define CANTP_APPL_CODE

#if (defined CANTP_VAR_NOINIT)
#error CANTP_VAR_NOINIT already defined
#endif
#define CANTP_VAR_NOINIT

#if (defined CANTP_VAR_POWER_ON_INIT)
#error CANTP_VAR_POWER_ON_INIT already defined
#endif
#define CANTP_VAR_POWER_ON_INIT

#if (defined CANTP_VAR_FAST)
#error CANTP_VAR_FAST already defined
#endif
#define CANTP_VAR_FAST

#if (defined CANTP_VAR)
#error CANTP_VAR already defined
#endif
#define CANTP_VAR

#if (defined CANTP_ENTRY_JUMP_TABLE)
#error CANTP_ENTRY_JUMP_TABLE already defined
#endif
#define CANTP_ENTRY_JUMP_TABLE

#if (defined CANTP_EXIT_JUMP_TABLE)
#error CANTP_EXIT_JUMP_TABLE already defined
#endif
#define CANTP_EXIT_JUMP_TABLE


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CANTRCV_CODE)
#error CANTRCV_CODE already defined
#endif
#define CANTRCV_CODE

#if (defined CANTRCV_CONST)
#error CANTRCV_CONST already defined
#endif
#define CANTRCV_CONST

#if (defined CANTRCV_APPL_DATA)
#error CANTRCV_APPL_DATA already defined
#endif
#define CANTRCV_APPL_DATA

#if (defined CANTRCV_APPL_CONST)
#error CANTRCV_APPL_CONST already defined
#endif
#define CANTRCV_APPL_CONST

#if (defined CANTRCV_APPL_CODE)
#error CANTRCV_APPL_CODE already defined
#endif
#define CANTRCV_APPL_CODE

#if (defined CANTRCV_VAR_NOINIT)
#error CANTRCV_VAR_NOINIT already defined
#endif
#define CANTRCV_VAR_NOINIT

#if (defined CANTRCV_VAR_POWER_ON_INIT)
#error CANTRCV_VAR_POWER_ON_INIT already defined
#endif
#define CANTRCV_VAR_POWER_ON_INIT

#if (defined CANTRCV_VAR_FAST)
#error CANTRCV_VAR_FAST already defined
#endif
#define CANTRCV_VAR_FAST

#if (defined CANTRCV_VAR)
#error CANTRCV_VAR already defined
#endif
#define CANTRCV_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CANTRCV_1_T01_CODE)
#error CANTRCV_1_T01_CODE already defined
#endif
#define CANTRCV_1_T01_CODE

#if (defined CANTRCV_1_T01_CONST)
#error CANTRCV_1_T01_CONST already defined
#endif
#define CANTRCV_1_T01_CONST

#if (defined CANTRCV_1_T01_APPL_DATA)
#error CANTRCV_1_T01_APPL_DATA already defined
#endif
#define CANTRCV_1_T01_APPL_DATA

#if (defined CANTRCV_1_T01_APPL_CONST)
#error CANTRCV_1_T01_APPL_CONST already defined
#endif
#define CANTRCV_1_T01_APPL_CONST

#if (defined CANTRCV_1_T01_APPL_CODE)
#error CANTRCV_1_T01_APPL_CODE already defined
#endif
#define CANTRCV_1_T01_APPL_CODE

#if (defined CANTRCV_1_T01_VAR_NOINIT)
#error CANTRCV_1_T01_VAR_NOINIT already defined
#endif
#define CANTRCV_1_T01_VAR_NOINIT

#if (defined CANTRCV_1_T01_VAR_POWER_ON_INIT)
#error CANTRCV_1_T01_VAR_POWER_ON_INIT already defined
#endif
#define CANTRCV_1_T01_VAR_POWER_ON_INIT

#if (defined CANTRCV_1_T01_VAR_FAST)
#error CANTRCV_1_T01_VAR_FAST already defined
#endif
#define CANTRCV_1_T01_VAR_FAST

#if (defined CANTRCV_1_T01_VAR)
#error CANTRCV_1_T01_VAR already defined
#endif
#define CANTRCV_1_T01_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CANTRCV_1_T02_CODE)
#error CANTRCV_1_T02_CODE already defined
#endif
#define CANTRCV_1_T02_CODE

#if (defined CANTRCV_1_T02_CONST)
#error CANTRCV_1_T02_CONST already defined
#endif
#define CANTRCV_1_T02_CONST

#if (defined CANTRCV_1_T02_APPL_DATA)
#error CANTRCV_1_T02_APPL_DATA already defined
#endif
#define CANTRCV_1_T02_APPL_DATA

#if (defined CANTRCV_1_T02_APPL_CONST)
#error CANTRCV_1_T02_APPL_CONST already defined
#endif
#define CANTRCV_1_T02_APPL_CONST

#if (defined CANTRCV_1_T02_APPL_CODE)
#error CANTRCV_1_T02_APPL_CODE already defined
#endif
#define CANTRCV_1_T02_APPL_CODE

#if (defined CANTRCV_1_T02_VAR_NOINIT)
#error CANTRCV_1_T02_VAR_NOINIT already defined
#endif
#define CANTRCV_1_T02_VAR_NOINIT

#if (defined CANTRCV_1_T02_VAR_POWER_ON_INIT)
#error CANTRCV_1_T02_VAR_POWER_ON_INIT already defined
#endif
#define CANTRCV_1_T02_VAR_POWER_ON_INIT

#if (defined CANTRCV_1_T02_VAR_FAST)
#error CANTRCV_1_T02_VAR_FAST already defined
#endif
#define CANTRCV_1_T02_VAR_FAST

#if (defined CANTRCV_1_T02_VAR)
#error CANTRCV_1_T02_VAR already defined
#endif
#define CANTRCV_1_T02_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CANTRCV_1_T03_CODE)
#error CANTRCV_1_T03_CODE already defined
#endif
#define CANTRCV_1_T03_CODE

#if (defined CANTRCV_1_T03_CONST)
#error CANTRCV_1_T03_CONST already defined
#endif
#define CANTRCV_1_T03_CONST

#if (defined CANTRCV_1_T03_APPL_DATA)
#error CANTRCV_1_T03_APPL_DATA already defined
#endif
#define CANTRCV_1_T03_APPL_DATA

#if (defined CANTRCV_1_T03_APPL_CONST)
#error CANTRCV_1_T03_APPL_CONST already defined
#endif
#define CANTRCV_1_T03_APPL_CONST

#if (defined CANTRCV_1_T03_APPL_CODE)
#error CANTRCV_1_T03_APPL_CODE already defined
#endif
#define CANTRCV_1_T03_APPL_CODE

#if (defined CANTRCV_1_T03_VAR_NOINIT)
#error CANTRCV_1_T03_VAR_NOINIT already defined
#endif
#define CANTRCV_1_T03_VAR_NOINIT

#if (defined CANTRCV_1_T03_VAR_POWER_ON_INIT)
#error CANTRCV_1_T03_VAR_POWER_ON_INIT already defined
#endif
#define CANTRCV_1_T03_VAR_POWER_ON_INIT

#if (defined CANTRCV_1_T03_VAR_FAST)
#error CANTRCV_1_T03_VAR_FAST already defined
#endif
#define CANTRCV_1_T03_VAR_FAST

#if (defined CANTRCV_1_T03_VAR)
#error CANTRCV_1_T03_VAR already defined
#endif
#define CANTRCV_1_T03_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CNM_CODE)
#error CNM_CODE already defined
#endif
#define CNM_CODE

#if (defined CNM_CONST)
#error CNM_CONST already defined
#endif
#define CNM_CONST

#if (defined CNM_APPL_DATA)
#error CNM_APPL_DATA already defined
#endif
#define CNM_APPL_DATA

#if (defined CNM_APPL_CONST)
#error CNM_APPL_CONST already defined
#endif
#define CNM_APPL_CONST

#if (defined CNM_APPL_CODE)
#error CNM_APPL_CODE already defined
#endif
#define CNM_APPL_CODE

#if (defined CNM_VAR_NOINIT)
#error CNM_VAR_NOINIT already defined
#endif
#define CNM_VAR_NOINIT

#if (defined CNM_VAR_POWER_ON_INIT)
#error CNM_VAR_POWER_ON_INIT already defined
#endif
#define CNM_VAR_POWER_ON_INIT

#if (defined CNM_VAR_FAST)
#error CNM_VAR_FAST already defined
#endif
#define CNM_VAR_FAST

#if (defined CNM_VAR)
#error CNM_VAR already defined
#endif
#define CNM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined COM_CODE)
#error COM_CODE already defined
#endif
#define COM_CODE

#if (defined COM_CONST)
#error COM_CONST already defined
#endif
#define COM_CONST

#if (defined COM_APPL_DATA)
#error COM_APPL_DATA already defined
#endif
#define COM_APPL_DATA

#if (defined COM_APPL_CONST)
#error COM_APPL_CONST already defined
#endif
#define COM_APPL_CONST

#if (defined COM_APPL_CODE)
#error COM_APPL_CODE already defined
#endif
#define COM_APPL_CODE

#if (defined COM_VAR_NOINIT)
#error COM_VAR_NOINIT already defined
#endif
#define COM_VAR_NOINIT

#if (defined COM_VAR_POWER_ON_INIT)
#error COM_VAR_POWER_ON_INIT already defined
#endif
#define COM_VAR_POWER_ON_INIT

#if (defined COM_VAR_FAST)
#error COM_VAR_FAST already defined
#endif
#define COM_VAR_FAST

#if (defined COM_VAR)
#error COM_VAR already defined
#endif
#define COM_VAR

#if (defined COM_RTE_CODE)
#error COM_RTE_CODE already defined
#endif
#define COM_RTE_CODE


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined COMM_CODE)
#error COMM_CODE already defined
#endif
#define COMM_CODE

#if (defined COMM_CONST)
#error COMM_CONST already defined
#endif
#define COMM_CONST

#if (defined COMM_APPL_DATA)
#error COMM_APPL_DATA already defined
#endif
#define COMM_APPL_DATA

#if (defined COMM_APPL_CONST)
#error COMM_APPL_CONST already defined
#endif
#define COMM_APPL_CONST

#if (defined COMM_APPL_CODE)
#error COMM_APPL_CODE already defined
#endif
#define COMM_APPL_CODE

#if (defined COMM_VAR_NOINIT)
#error COMM_VAR_NOINIT already defined
#endif
#define COMM_VAR_NOINIT

#if (defined COMM_VAR_POWER_ON_INIT)
#error COMM_VAR_POWER_ON_INIT already defined
#endif
#define COMM_VAR_POWER_ON_INIT

#if (defined COMM_VAR_FAST)
#error COMM_VAR_FAST already defined
#endif
#define COMM_VAR_FAST

#if (defined COMM_VAR)
#error COMM_VAR already defined
#endif
#define COMM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CPL_CODE)
#error CPL_CODE already defined
#endif
#define CPL_CODE

#if (defined CPL_CONST)
#error CPL_CONST already defined
#endif
#define CPL_CONST

#if (defined CPL_APPL_DATA)
#error CPL_APPL_DATA already defined
#endif
#define CPL_APPL_DATA

#if (defined CPL_APPL_CONST)
#error CPL_APPL_CONST already defined
#endif
#define CPL_APPL_CONST

#if (defined CPL_APPL_CODE)
#error CPL_APPL_CODE already defined
#endif
#define CPL_APPL_CODE

#if (defined CPL_VAR_NOINIT)
#error CPL_VAR_NOINIT already defined
#endif
#define CPL_VAR_NOINIT

#if (defined CPL_VAR_POWER_ON_INIT)
#error CPL_VAR_POWER_ON_INIT already defined
#endif
#define CPL_VAR_POWER_ON_INIT

#if (defined CPL_VAR_FAST)
#error CPL_VAR_FAST already defined
#endif
#define CPL_VAR_FAST

#if (defined CPL_VAR)
#error CPL_VAR already defined
#endif
#define CPL_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CRC_CODE)
#error CRC_CODE already defined
#endif
#define CRC_CODE

#if (defined CRC_CONST)
#error CRC_CONST already defined
#endif
#define CRC_CONST

#if (defined CRC_APPL_DATA)
#error CRC_APPL_DATA already defined
#endif
#define CRC_APPL_DATA

#if (defined CRC_APPL_CONST)
#error CRC_APPL_CONST already defined
#endif
#define CRC_APPL_CONST

#if (defined CRC_APPL_CODE)
#error CRC_APPL_CODE already defined
#endif
#define CRC_APPL_CODE

#if (defined CRC_VAR_NOINIT)
#error CRC_VAR_NOINIT already defined
#endif
#define CRC_VAR_NOINIT

#if (defined CRC_VAR_POWER_ON_INIT)
#error CRC_VAR_POWER_ON_INIT already defined
#endif
#define CRC_VAR_POWER_ON_INIT

#if (defined CRC_VAR_FAST)
#error CRC_VAR_FAST already defined
#endif
#define CRC_VAR_FAST

#if (defined CRC_VAR)
#error CRC_VAR already defined
#endif
#define CRC_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CRY_CODE)
#error CRY_CODE already defined
#endif
#define CRY_CODE

#if (defined CRY_CONST)
#error CRY_CONST already defined
#endif
#define CRY_CONST

#if (defined CRY_APPL_DATA)
#error CRY_APPL_DATA already defined
#endif
#define CRY_APPL_DATA

#if (defined CRY_APPL_CONST)
#error CRY_APPL_CONST already defined
#endif
#define CRY_APPL_CONST

#if (defined CRY_APPL_CODE)
#error CRY_APPL_CODE already defined
#endif
#define CRY_APPL_CODE

#if (defined CRY_VAR_NOINIT)
#error CRY_VAR_NOINIT already defined
#endif
#define CRY_VAR_NOINIT

#if (defined CRY_VAR_POWER_ON_INIT)
#error CRY_VAR_POWER_ON_INIT already defined
#endif
#define CRY_VAR_POWER_ON_INIT

#if (defined CRY_VAR_FAST)
#error CRY_VAR_FAST already defined
#endif
#define CRY_VAR_FAST

#if (defined CRY_VAR)
#error CRY_VAR already defined
#endif
#define CRY_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined CSM_CODE)
#error CSM_CODE already defined
#endif
#define CSM_CODE

#if (defined CSM_CONST)
#error CSM_CONST already defined
#endif
#define CSM_CONST

#if (defined CSM_APPL_DATA)
#error CSM_APPL_DATA already defined
#endif
#define CSM_APPL_DATA

#if (defined CSM_APPL_CONST)
#error CSM_APPL_CONST already defined
#endif
#define CSM_APPL_CONST

#if (defined CSM_APPL_CODE)
#error CSM_APPL_CODE already defined
#endif
#define CSM_APPL_CODE

#if (defined CSM_VAR_NOINIT)
#error CSM_VAR_NOINIT already defined
#endif
#define CSM_VAR_NOINIT

#if (defined CSM_VAR_POWER_ON_INIT)
#error CSM_VAR_POWER_ON_INIT already defined
#endif
#define CSM_VAR_POWER_ON_INIT

#if (defined CSM_VAR_FAST)
#error CSM_VAR_FAST already defined
#endif
#define CSM_VAR_FAST

#if (defined CSM_VAR)
#error CSM_VAR already defined
#endif
#define CSM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined DBG_CODE)
#error DBG_CODE already defined
#endif
#define DBG_CODE

#if (defined DBG_CONST)
#error DBG_CONST already defined
#endif
#define DBG_CONST

#if (defined DBG_APPL_DATA)
#error DBG_APPL_DATA already defined
#endif
#define DBG_APPL_DATA

#if (defined DBG_APPL_CONST)
#error DBG_APPL_CONST already defined
#endif
#define DBG_APPL_CONST

#if (defined DBG_APPL_CODE)
#error DBG_APPL_CODE already defined
#endif
#define DBG_APPL_CODE

#if (defined DBG_VAR_NOINIT)
#error DBG_VAR_NOINIT already defined
#endif
#define DBG_VAR_NOINIT

#if (defined DBG_VAR_POWER_ON_INIT)
#error DBG_VAR_POWER_ON_INIT already defined
#endif
#define DBG_VAR_POWER_ON_INIT

#if (defined DBG_VAR_FAST)
#error DBG_VAR_FAST already defined
#endif
#define DBG_VAR_FAST

#if (defined DBG_VAR)
#error DBG_VAR already defined
#endif
#define DBG_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined DCM_CODE)
#error DCM_CODE already defined
#endif
#define DCM_CODE

#if (defined DCM_CONST)
#error DCM_CONST already defined
#endif
#define DCM_CONST

#if (defined DCM_APPL_DATA)
#error DCM_APPL_DATA already defined
#endif
#define DCM_APPL_DATA

#if (defined DCM_APPL_CONST)
#error DCM_APPL_CONST already defined
#endif
#define DCM_APPL_CONST

#if (defined DCM_APPL_CODE)
#error DCM_APPL_CODE already defined
#endif
#define DCM_APPL_CODE

#if (defined DCM_VAR_NOINIT)
#error DCM_VAR_NOINIT already defined
#endif
#define DCM_VAR_NOINIT

#if (defined DCM_VAR_POWER_ON_INIT)
#error DCM_VAR_POWER_ON_INIT already defined
#endif
#define DCM_VAR_POWER_ON_INIT

#if (defined DCM_VAR_FAST)
#error DCM_VAR_FAST already defined
#endif
#define DCM_VAR_FAST

#if (defined DCM_VAR)
#error DCM_VAR already defined
#endif
#define DCM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined DEM_CODE)
#error DEM_CODE already defined
#endif
#define DEM_CODE

#if (defined DEM_CONST)
#error DEM_CONST already defined
#endif
#define DEM_CONST

#if (defined DEM_APPL_DATA)
#error DEM_APPL_DATA already defined
#endif
#define DEM_APPL_DATA

#if (defined DEM_APPL_CONST)
#error DEM_APPL_CONST already defined
#endif
#define DEM_APPL_CONST

#if (defined DEM_APPL_CODE)
#error DEM_APPL_CODE already defined
#endif
#define DEM_APPL_CODE

#if (defined DEM_VAR_NOINIT)
#error DEM_VAR_NOINIT already defined
#endif
#define DEM_VAR_NOINIT

#if (defined DEM_VAR_POWER_ON_INIT)
#error DEM_VAR_POWER_ON_INIT already defined
#endif
#define DEM_VAR_POWER_ON_INIT

#if (defined DEM_VAR_FAST)
#error DEM_VAR_FAST already defined
#endif
#define DEM_VAR_FAST

#if (defined DEM_VAR)
#error DEM_VAR already defined
#endif
#define DEM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined DET_CODE)
#error DET_CODE already defined
#endif
#define DET_CODE

#if (defined DET_CONST)
#error DET_CONST already defined
#endif
#define DET_CONST

#if (defined DET_APPL_DATA)
#error DET_APPL_DATA already defined
#endif
#define DET_APPL_DATA

#if (defined DET_APPL_CONST)
#error DET_APPL_CONST already defined
#endif
#define DET_APPL_CONST

#if (defined DET_APPL_CODE)
#error DET_APPL_CODE already defined
#endif
#define DET_APPL_CODE

#if (defined DET_VAR_NOINIT)
#error DET_VAR_NOINIT already defined
#endif
#define DET_VAR_NOINIT

#if (defined DET_VAR_POWER_ON_INIT)
#error DET_VAR_POWER_ON_INIT already defined
#endif
#define DET_VAR_POWER_ON_INIT

#if (defined DET_VAR_FAST)
#error DET_VAR_FAST already defined
#endif
#define DET_VAR_FAST

#if (defined DET_VAR)
#error DET_VAR already defined
#endif
#define DET_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined DIO_CODE)
#error DIO_CODE already defined
#endif
#define DIO_CODE

#if (defined DIO_CONST)
#error DIO_CONST already defined
#endif
#define DIO_CONST

#if (defined DIO_APPL_DATA)
#error DIO_APPL_DATA already defined
#endif
#define DIO_APPL_DATA

#if (defined DIO_APPL_CONST)
#error DIO_APPL_CONST already defined
#endif
#define DIO_APPL_CONST

#if (defined DIO_APPL_CODE)
#error DIO_APPL_CODE already defined
#endif
#define DIO_APPL_CODE

#if (defined DIO_VAR_NOINIT)
#error DIO_VAR_NOINIT already defined
#endif
#define DIO_VAR_NOINIT

#if (defined DIO_VAR_POWER_ON_INIT)
#error DIO_VAR_POWER_ON_INIT already defined
#endif
#define DIO_VAR_POWER_ON_INIT

#if (defined DIO_VAR_FAST)
#error DIO_VAR_FAST already defined
#endif
#define DIO_VAR_FAST

#if (defined DIO_VAR)
#error DIO_VAR already defined
#endif
#define DIO_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined E2E_CODE)
#error E2E_CODE already defined
#endif
#define E2E_CODE

#if (defined E2E_CONST)
#error E2E_CONST already defined
#endif
#define E2E_CONST

#if (defined E2E_APPL_DATA)
#error E2E_APPL_DATA already defined
#endif
#define E2E_APPL_DATA

#if (defined E2E_APPL_CONST)
#error E2E_APPL_CONST already defined
#endif
#define E2E_APPL_CONST

#if (defined E2E_APPL_CODE)
#error E2E_APPL_CODE already defined
#endif
#define E2E_APPL_CODE

#if (defined E2E_VAR_NOINIT)
#error E2E_VAR_NOINIT already defined
#endif
#define E2E_VAR_NOINIT

#if (defined E2E_VAR_POWER_ON_INIT)
#error E2E_VAR_POWER_ON_INIT already defined
#endif
#define E2E_VAR_POWER_ON_INIT

#if (defined E2E_VAR_FAST)
#error E2E_VAR_FAST already defined
#endif
#define E2E_VAR_FAST

#if (defined E2E_VAR)
#error E2E_VAR already defined
#endif
#define E2E_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined E2EPW_CODE)
#error E2EPW_CODE already defined
#endif
#define E2EPW_CODE

#if (defined E2EPW_CONST)
#error E2EPW_CONST already defined
#endif
#define E2EPW_CONST

#if (defined E2EPW_APPL_DATA)
#error E2EPW_APPL_DATA already defined
#endif
#define E2EPW_APPL_DATA

#if (defined E2EPW_APPL_CONST)
#error E2EPW_APPL_CONST already defined
#endif
#define E2EPW_APPL_CONST

#if (defined E2EPW_APPL_CODE)
#error E2EPW_APPL_CODE already defined
#endif
#define E2EPW_APPL_CODE

#if (defined E2EPW_VAR_NOINIT)
#error E2EPW_VAR_NOINIT already defined
#endif
#define E2EPW_VAR_NOINIT

#if (defined E2EPW_VAR_POWER_ON_INIT)
#error E2EPW_VAR_POWER_ON_INIT already defined
#endif
#define E2EPW_VAR_POWER_ON_INIT

#if (defined E2EPW_VAR_FAST)
#error E2EPW_VAR_FAST already defined
#endif
#define E2EPW_VAR_FAST

#if (defined E2EPW_VAR)
#error E2EPW_VAR already defined
#endif
#define E2EPW_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined EA_CODE)
#error EA_CODE already defined
#endif
#define EA_CODE

#if (defined EA_CONST)
#error EA_CONST already defined
#endif
#define EA_CONST

#if (defined EA_APPL_DATA)
#error EA_APPL_DATA already defined
#endif
#define EA_APPL_DATA

#if (defined EA_APPL_CONST)
#error EA_APPL_CONST already defined
#endif
#define EA_APPL_CONST

#if (defined EA_APPL_CODE)
#error EA_APPL_CODE already defined
#endif
#define EA_APPL_CODE

#if (defined EA_VAR_NOINIT)
#error EA_VAR_NOINIT already defined
#endif
#define EA_VAR_NOINIT

#if (defined EA_VAR_POWER_ON_INIT)
#error EA_VAR_POWER_ON_INIT already defined
#endif
#define EA_VAR_POWER_ON_INIT

#if (defined EA_VAR_FAST)
#error EA_VAR_FAST already defined
#endif
#define EA_VAR_FAST

#if (defined EA_VAR)
#error EA_VAR already defined
#endif
#define EA_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined EBSTUBS_CODE)
#error EBSTUBS_CODE already defined
#endif
#define EBSTUBS_CODE

#if (defined EBSTUBS_CONST)
#error EBSTUBS_CONST already defined
#endif
#define EBSTUBS_CONST

#if (defined EBSTUBS_APPL_DATA)
#error EBSTUBS_APPL_DATA already defined
#endif
#define EBSTUBS_APPL_DATA

#if (defined EBSTUBS_APPL_CONST)
#error EBSTUBS_APPL_CONST already defined
#endif
#define EBSTUBS_APPL_CONST

#if (defined EBSTUBS_APPL_CODE)
#error EBSTUBS_APPL_CODE already defined
#endif
#define EBSTUBS_APPL_CODE

#if (defined EBSTUBS_VAR_NOINIT)
#error EBSTUBS_VAR_NOINIT already defined
#endif
#define EBSTUBS_VAR_NOINIT

#if (defined EBSTUBS_VAR_POWER_ON_INIT)
#error EBSTUBS_VAR_POWER_ON_INIT already defined
#endif
#define EBSTUBS_VAR_POWER_ON_INIT

#if (defined EBSTUBS_VAR_FAST)
#error EBSTUBS_VAR_FAST already defined
#endif
#define EBSTUBS_VAR_FAST

#if (defined EBSTUBS_VAR)
#error EBSTUBS_VAR already defined
#endif
#define EBSTUBS_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined EBTEST_CODE)
#error EBTEST_CODE already defined
#endif
#define EBTEST_CODE

#if (defined EBTEST_CONST)
#error EBTEST_CONST already defined
#endif
#define EBTEST_CONST

#if (defined EBTEST_APPL_DATA)
#error EBTEST_APPL_DATA already defined
#endif
#define EBTEST_APPL_DATA

#if (defined EBTEST_APPL_CONST)
#error EBTEST_APPL_CONST already defined
#endif
#define EBTEST_APPL_CONST

#if (defined EBTEST_APPL_CODE)
#error EBTEST_APPL_CODE already defined
#endif
#define EBTEST_APPL_CODE

#if (defined EBTEST_VAR_NOINIT)
#error EBTEST_VAR_NOINIT already defined
#endif
#define EBTEST_VAR_NOINIT

#if (defined EBTEST_VAR_POWER_ON_INIT)
#error EBTEST_VAR_POWER_ON_INIT already defined
#endif
#define EBTEST_VAR_POWER_ON_INIT

#if (defined EBTEST_VAR_FAST)
#error EBTEST_VAR_FAST already defined
#endif
#define EBTEST_VAR_FAST

#if (defined EBTEST_VAR)
#error EBTEST_VAR already defined
#endif
#define EBTEST_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined ECUM_CODE)
#error ECUM_CODE already defined
#endif
#define ECUM_CODE

#if (defined ECUM_CONST)
#error ECUM_CONST already defined
#endif
#define ECUM_CONST

#if (defined ECUM_APPL_DATA)
#error ECUM_APPL_DATA already defined
#endif
#define ECUM_APPL_DATA

#if (defined ECUM_APPL_CONST)
#error ECUM_APPL_CONST already defined
#endif
#define ECUM_APPL_CONST

#if (defined ECUM_APPL_CODE)
#error ECUM_APPL_CODE already defined
#endif
#define ECUM_APPL_CODE

#if (defined ECUM_VAR_NOINIT)
#error ECUM_VAR_NOINIT already defined
#endif
#define ECUM_VAR_NOINIT

#if (defined ECUM_VAR_POWER_ON_INIT)
#error ECUM_VAR_POWER_ON_INIT already defined
#endif
#define ECUM_VAR_POWER_ON_INIT

#if (defined ECUM_VAR_FAST)
#error ECUM_VAR_FAST already defined
#endif
#define ECUM_VAR_FAST

#if (defined ECUM_VAR)
#error ECUM_VAR already defined
#endif
#define ECUM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined EEP_CODE)
#error EEP_CODE already defined
#endif
#define EEP_CODE

#if (defined EEP_CONST)
#error EEP_CONST already defined
#endif
#define EEP_CONST

#if (defined EEP_APPL_DATA)
#error EEP_APPL_DATA already defined
#endif
#define EEP_APPL_DATA

#if (defined EEP_APPL_CONST)
#error EEP_APPL_CONST already defined
#endif
#define EEP_APPL_CONST

#if (defined EEP_APPL_CODE)
#error EEP_APPL_CODE already defined
#endif
#define EEP_APPL_CODE

#if (defined EEP_VAR_NOINIT)
#error EEP_VAR_NOINIT already defined
#endif
#define EEP_VAR_NOINIT

#if (defined EEP_VAR_POWER_ON_INIT)
#error EEP_VAR_POWER_ON_INIT already defined
#endif
#define EEP_VAR_POWER_ON_INIT

#if (defined EEP_VAR_FAST)
#error EEP_VAR_FAST already defined
#endif
#define EEP_VAR_FAST

#if (defined EEP_VAR)
#error EEP_VAR already defined
#endif
#define EEP_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined EEPIF_CODE)
#error EEPIF_CODE already defined
#endif
#define EEPIF_CODE

#if (defined EEPIF_CONST)
#error EEPIF_CONST already defined
#endif
#define EEPIF_CONST

#if (defined EEPIF_APPL_DATA)
#error EEPIF_APPL_DATA already defined
#endif
#define EEPIF_APPL_DATA

#if (defined EEPIF_APPL_CONST)
#error EEPIF_APPL_CONST already defined
#endif
#define EEPIF_APPL_CONST

#if (defined EEPIF_APPL_CODE)
#error EEPIF_APPL_CODE already defined
#endif
#define EEPIF_APPL_CODE

#if (defined EEPIF_VAR_NOINIT)
#error EEPIF_VAR_NOINIT already defined
#endif
#define EEPIF_VAR_NOINIT

#if (defined EEPIF_VAR_POWER_ON_INIT)
#error EEPIF_VAR_POWER_ON_INIT already defined
#endif
#define EEPIF_VAR_POWER_ON_INIT

#if (defined EEPIF_VAR_FAST)
#error EEPIF_VAR_FAST already defined
#endif
#define EEPIF_VAR_FAST

#if (defined EEPIF_VAR)
#error EEPIF_VAR already defined
#endif
#define EEPIF_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined ETH_CODE)
#error ETH_CODE already defined
#endif
#define ETH_CODE

#if (defined ETH_CONST)
#error ETH_CONST already defined
#endif
#define ETH_CONST

#if (defined ETH_APPL_DATA)
#error ETH_APPL_DATA already defined
#endif
#define ETH_APPL_DATA

#if (defined ETH_APPL_CONST)
#error ETH_APPL_CONST already defined
#endif
#define ETH_APPL_CONST

#if (defined ETH_APPL_CODE)
#error ETH_APPL_CODE already defined
#endif
#define ETH_APPL_CODE

#if (defined ETH_VAR_NOINIT)
#error ETH_VAR_NOINIT already defined
#endif
#define ETH_VAR_NOINIT

#if (defined ETH_VAR_POWER_ON_INIT)
#error ETH_VAR_POWER_ON_INIT already defined
#endif
#define ETH_VAR_POWER_ON_INIT

#if (defined ETH_VAR_FAST)
#error ETH_VAR_FAST already defined
#endif
#define ETH_VAR_FAST

#if (defined ETH_VAR)
#error ETH_VAR already defined
#endif
#define ETH_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined ETHIF_CODE)
#error ETHIF_CODE already defined
#endif
#define ETHIF_CODE

#if (defined ETHIF_CONST)
#error ETHIF_CONST already defined
#endif
#define ETHIF_CONST

#if (defined ETHIF_APPL_DATA)
#error ETHIF_APPL_DATA already defined
#endif
#define ETHIF_APPL_DATA

#if (defined ETHIF_APPL_CONST)
#error ETHIF_APPL_CONST already defined
#endif
#define ETHIF_APPL_CONST

#if (defined ETHIF_APPL_CODE)
#error ETHIF_APPL_CODE already defined
#endif
#define ETHIF_APPL_CODE

#if (defined ETHIF_VAR_NOINIT)
#error ETHIF_VAR_NOINIT already defined
#endif
#define ETHIF_VAR_NOINIT

#if (defined ETHIF_VAR_POWER_ON_INIT)
#error ETHIF_VAR_POWER_ON_INIT already defined
#endif
#define ETHIF_VAR_POWER_ON_INIT

#if (defined ETHIF_VAR_FAST)
#error ETHIF_VAR_FAST already defined
#endif
#define ETHIF_VAR_FAST

#if (defined ETHIF_VAR)
#error ETHIF_VAR already defined
#endif
#define ETHIF_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined ETHSM_CODE)
#error ETHSM_CODE already defined
#endif
#define ETHSM_CODE

#if (defined ETHSM_CONST)
#error ETHSM_CONST already defined
#endif
#define ETHSM_CONST

#if (defined ETHSM_APPL_DATA)
#error ETHSM_APPL_DATA already defined
#endif
#define ETHSM_APPL_DATA

#if (defined ETHSM_APPL_CONST)
#error ETHSM_APPL_CONST already defined
#endif
#define ETHSM_APPL_CONST

#if (defined ETHSM_APPL_CODE)
#error ETHSM_APPL_CODE already defined
#endif
#define ETHSM_APPL_CODE

#if (defined ETHSM_VAR_NOINIT)
#error ETHSM_VAR_NOINIT already defined
#endif
#define ETHSM_VAR_NOINIT

#if (defined ETHSM_VAR_POWER_ON_INIT)
#error ETHSM_VAR_POWER_ON_INIT already defined
#endif
#define ETHSM_VAR_POWER_ON_INIT

#if (defined ETHSM_VAR_FAST)
#error ETHSM_VAR_FAST already defined
#endif
#define ETHSM_VAR_FAST

#if (defined ETHSM_VAR)
#error ETHSM_VAR already defined
#endif
#define ETHSM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined ETHTRCV_CODE)
#error ETHTRCV_CODE already defined
#endif
#define ETHTRCV_CODE

#if (defined ETHTRCV_CONST)
#error ETHTRCV_CONST already defined
#endif
#define ETHTRCV_CONST

#if (defined ETHTRCV_APPL_DATA)
#error ETHTRCV_APPL_DATA already defined
#endif
#define ETHTRCV_APPL_DATA

#if (defined ETHTRCV_APPL_CONST)
#error ETHTRCV_APPL_CONST already defined
#endif
#define ETHTRCV_APPL_CONST

#if (defined ETHTRCV_APPL_CODE)
#error ETHTRCV_APPL_CODE already defined
#endif
#define ETHTRCV_APPL_CODE

#if (defined ETHTRCV_VAR_NOINIT)
#error ETHTRCV_VAR_NOINIT already defined
#endif
#define ETHTRCV_VAR_NOINIT

#if (defined ETHTRCV_VAR_POWER_ON_INIT)
#error ETHTRCV_VAR_POWER_ON_INIT already defined
#endif
#define ETHTRCV_VAR_POWER_ON_INIT

#if (defined ETHTRCV_VAR_FAST)
#error ETHTRCV_VAR_FAST already defined
#endif
#define ETHTRCV_VAR_FAST

#if (defined ETHTRCV_VAR)
#error ETHTRCV_VAR already defined
#endif
#define ETHTRCV_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FEE_CODE)
#error FEE_CODE already defined
#endif
#define FEE_CODE

#if (defined FEE_CONST)
#error FEE_CONST already defined
#endif
#define FEE_CONST

#if (defined FEE_APPL_DATA)
#error FEE_APPL_DATA already defined
#endif
#define FEE_APPL_DATA

#if (defined FEE_APPL_CONST)
#error FEE_APPL_CONST already defined
#endif
#define FEE_APPL_CONST

#if (defined FEE_APPL_CODE)
#error FEE_APPL_CODE already defined
#endif
#define FEE_APPL_CODE

#if (defined FEE_VAR_NOINIT)
#error FEE_VAR_NOINIT already defined
#endif
#define FEE_VAR_NOINIT

#if (defined FEE_VAR_POWER_ON_INIT)
#error FEE_VAR_POWER_ON_INIT already defined
#endif
#define FEE_VAR_POWER_ON_INIT

#if (defined FEE_VAR_FAST)
#error FEE_VAR_FAST already defined
#endif
#define FEE_VAR_FAST

#if (defined FEE_VAR)
#error FEE_VAR already defined
#endif
#define FEE_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FIM_CODE)
#error FIM_CODE already defined
#endif
#define FIM_CODE

#if (defined FIM_CONST)
#error FIM_CONST already defined
#endif
#define FIM_CONST

#if (defined FIM_APPL_DATA)
#error FIM_APPL_DATA already defined
#endif
#define FIM_APPL_DATA

#if (defined FIM_APPL_CONST)
#error FIM_APPL_CONST already defined
#endif
#define FIM_APPL_CONST

#if (defined FIM_APPL_CODE)
#error FIM_APPL_CODE already defined
#endif
#define FIM_APPL_CODE

#if (defined FIM_VAR_NOINIT)
#error FIM_VAR_NOINIT already defined
#endif
#define FIM_VAR_NOINIT

#if (defined FIM_VAR_POWER_ON_INIT)
#error FIM_VAR_POWER_ON_INIT already defined
#endif
#define FIM_VAR_POWER_ON_INIT

#if (defined FIM_VAR_FAST)
#error FIM_VAR_FAST already defined
#endif
#define FIM_VAR_FAST

#if (defined FIM_VAR)
#error FIM_VAR already defined
#endif
#define FIM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FLS_CODE)
#error FLS_CODE already defined
#endif
#define FLS_CODE

#if (defined FLS_CONST)
#error FLS_CONST already defined
#endif
#define FLS_CONST

#if (defined FLS_APPL_DATA)
#error FLS_APPL_DATA already defined
#endif
#define FLS_APPL_DATA

#if (defined FLS_APPL_CONST)
#error FLS_APPL_CONST already defined
#endif
#define FLS_APPL_CONST

#if (defined FLS_APPL_CODE)
#error FLS_APPL_CODE already defined
#endif
#define FLS_APPL_CODE

#if (defined FLS_VAR_NOINIT)
#error FLS_VAR_NOINIT already defined
#endif
#define FLS_VAR_NOINIT

#if (defined FLS_VAR_POWER_ON_INIT)
#error FLS_VAR_POWER_ON_INIT already defined
#endif
#define FLS_VAR_POWER_ON_INIT

#if (defined FLS_VAR_FAST)
#error FLS_VAR_FAST already defined
#endif
#define FLS_VAR_FAST

#if (defined FLS_VAR)
#error FLS_VAR already defined
#endif
#define FLS_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FLSIF_CODE)
#error FLSIF_CODE already defined
#endif
#define FLSIF_CODE

#if (defined FLSIF_CONST)
#error FLSIF_CONST already defined
#endif
#define FLSIF_CONST

#if (defined FLSIF_APPL_DATA)
#error FLSIF_APPL_DATA already defined
#endif
#define FLSIF_APPL_DATA

#if (defined FLSIF_APPL_CONST)
#error FLSIF_APPL_CONST already defined
#endif
#define FLSIF_APPL_CONST

#if (defined FLSIF_APPL_CODE)
#error FLSIF_APPL_CODE already defined
#endif
#define FLSIF_APPL_CODE

#if (defined FLSIF_VAR_NOINIT)
#error FLSIF_VAR_NOINIT already defined
#endif
#define FLSIF_VAR_NOINIT

#if (defined FLSIF_VAR_POWER_ON_INIT)
#error FLSIF_VAR_POWER_ON_INIT already defined
#endif
#define FLSIF_VAR_POWER_ON_INIT

#if (defined FLSIF_VAR_FAST)
#error FLSIF_VAR_FAST already defined
#endif
#define FLSIF_VAR_FAST

#if (defined FLSIF_VAR)
#error FLSIF_VAR already defined
#endif
#define FLSIF_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FR_CODE)
#error FR_CODE already defined
#endif
#define FR_CODE

#if (defined FR_CONST)
#error FR_CONST already defined
#endif
#define FR_CONST

#if (defined FR_APPL_DATA)
#error FR_APPL_DATA already defined
#endif
#define FR_APPL_DATA

#if (defined FR_APPL_CONST)
#error FR_APPL_CONST already defined
#endif
#define FR_APPL_CONST

#if (defined FR_APPL_CODE)
#error FR_APPL_CODE already defined
#endif
#define FR_APPL_CODE

#if (defined FR_VAR_NOINIT)
#error FR_VAR_NOINIT already defined
#endif
#define FR_VAR_NOINIT

#if (defined FR_VAR_POWER_ON_INIT)
#error FR_VAR_POWER_ON_INIT already defined
#endif
#define FR_VAR_POWER_ON_INIT

#if (defined FR_VAR_FAST)
#error FR_VAR_FAST already defined
#endif
#define FR_VAR_FAST

#if (defined FR_VAR)
#error FR_VAR already defined
#endif
#define FR_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FRIF_CODE)
#error FRIF_CODE already defined
#endif
#define FRIF_CODE

#if (defined FRIF_CONST)
#error FRIF_CONST already defined
#endif
#define FRIF_CONST

#if (defined FRIF_APPL_DATA)
#error FRIF_APPL_DATA already defined
#endif
#define FRIF_APPL_DATA

#if (defined FRIF_APPL_CONST)
#error FRIF_APPL_CONST already defined
#endif
#define FRIF_APPL_CONST

#if (defined FRIF_APPL_CODE)
#error FRIF_APPL_CODE already defined
#endif
#define FRIF_APPL_CODE

#if (defined FRIF_VAR_NOINIT)
#error FRIF_VAR_NOINIT already defined
#endif
#define FRIF_VAR_NOINIT

#if (defined FRIF_VAR_POWER_ON_INIT)
#error FRIF_VAR_POWER_ON_INIT already defined
#endif
#define FRIF_VAR_POWER_ON_INIT

#if (defined FRIF_VAR_FAST)
#error FRIF_VAR_FAST already defined
#endif
#define FRIF_VAR_FAST

#if (defined FRIF_VAR)
#error FRIF_VAR already defined
#endif
#define FRIF_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FRNM_CODE)
#error FRNM_CODE already defined
#endif
#define FRNM_CODE

#if (defined FRNM_CONST)
#error FRNM_CONST already defined
#endif
#define FRNM_CONST

#if (defined FRNM_APPL_DATA)
#error FRNM_APPL_DATA already defined
#endif
#define FRNM_APPL_DATA

#if (defined FRNM_APPL_CONST)
#error FRNM_APPL_CONST already defined
#endif
#define FRNM_APPL_CONST

#if (defined FRNM_APPL_CODE)
#error FRNM_APPL_CODE already defined
#endif
#define FRNM_APPL_CODE

#if (defined FRNM_VAR_NOINIT)
#error FRNM_VAR_NOINIT already defined
#endif
#define FRNM_VAR_NOINIT

#if (defined FRNM_VAR_POWER_ON_INIT)
#error FRNM_VAR_POWER_ON_INIT already defined
#endif
#define FRNM_VAR_POWER_ON_INIT

#if (defined FRNM_VAR_FAST)
#error FRNM_VAR_FAST already defined
#endif
#define FRNM_VAR_FAST

#if (defined FRNM_VAR)
#error FRNM_VAR already defined
#endif
#define FRNM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FRSM_CODE)
#error FRSM_CODE already defined
#endif
#define FRSM_CODE

#if (defined FRSM_CONST)
#error FRSM_CONST already defined
#endif
#define FRSM_CONST

#if (defined FRSM_APPL_DATA)
#error FRSM_APPL_DATA already defined
#endif
#define FRSM_APPL_DATA

#if (defined FRSM_APPL_CONST)
#error FRSM_APPL_CONST already defined
#endif
#define FRSM_APPL_CONST

#if (defined FRSM_APPL_CODE)
#error FRSM_APPL_CODE already defined
#endif
#define FRSM_APPL_CODE

#if (defined FRSM_VAR_NOINIT)
#error FRSM_VAR_NOINIT already defined
#endif
#define FRSM_VAR_NOINIT

#if (defined FRSM_VAR_POWER_ON_INIT)
#error FRSM_VAR_POWER_ON_INIT already defined
#endif
#define FRSM_VAR_POWER_ON_INIT

#if (defined FRSM_VAR_FAST)
#error FRSM_VAR_FAST already defined
#endif
#define FRSM_VAR_FAST

#if (defined FRSM_VAR)
#error FRSM_VAR already defined
#endif
#define FRSM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FRTP_CODE)
#error FRTP_CODE already defined
#endif
#define FRTP_CODE

#if (defined FRTP_CONST)
#error FRTP_CONST already defined
#endif
#define FRTP_CONST

#if (defined FRTP_APPL_DATA)
#error FRTP_APPL_DATA already defined
#endif
#define FRTP_APPL_DATA

#if (defined FRTP_APPL_CONST)
#error FRTP_APPL_CONST already defined
#endif
#define FRTP_APPL_CONST

#if (defined FRTP_APPL_CODE)
#error FRTP_APPL_CODE already defined
#endif
#define FRTP_APPL_CODE

#if (defined FRTP_VAR_NOINIT)
#error FRTP_VAR_NOINIT already defined
#endif
#define FRTP_VAR_NOINIT

#if (defined FRTP_VAR_POWER_ON_INIT)
#error FRTP_VAR_POWER_ON_INIT already defined
#endif
#define FRTP_VAR_POWER_ON_INIT

#if (defined FRTP_VAR_FAST)
#error FRTP_VAR_FAST already defined
#endif
#define FRTP_VAR_FAST

#if (defined FRTP_VAR)
#error FRTP_VAR already defined
#endif
#define FRTP_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FRTRCV_CODE)
#error FRTRCV_CODE already defined
#endif
#define FRTRCV_CODE

#if (defined FRTRCV_CONST)
#error FRTRCV_CONST already defined
#endif
#define FRTRCV_CONST

#if (defined FRTRCV_APPL_DATA)
#error FRTRCV_APPL_DATA already defined
#endif
#define FRTRCV_APPL_DATA

#if (defined FRTRCV_APPL_CONST)
#error FRTRCV_APPL_CONST already defined
#endif
#define FRTRCV_APPL_CONST

#if (defined FRTRCV_APPL_CODE)
#error FRTRCV_APPL_CODE already defined
#endif
#define FRTRCV_APPL_CODE

#if (defined FRTRCV_VAR_NOINIT)
#error FRTRCV_VAR_NOINIT already defined
#endif
#define FRTRCV_VAR_NOINIT

#if (defined FRTRCV_VAR_POWER_ON_INIT)
#error FRTRCV_VAR_POWER_ON_INIT already defined
#endif
#define FRTRCV_VAR_POWER_ON_INIT

#if (defined FRTRCV_VAR_FAST)
#error FRTRCV_VAR_FAST already defined
#endif
#define FRTRCV_VAR_FAST

#if (defined FRTRCV_VAR)
#error FRTRCV_VAR already defined
#endif
#define FRTRCV_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FRTRCV_1_T01_CODE)
#error FRTRCV_1_T01_CODE already defined
#endif
#define FRTRCV_1_T01_CODE

#if (defined FRTRCV_1_T01_CONST)
#error FRTRCV_1_T01_CONST already defined
#endif
#define FRTRCV_1_T01_CONST

#if (defined FRTRCV_1_T01_APPL_DATA)
#error FRTRCV_1_T01_APPL_DATA already defined
#endif
#define FRTRCV_1_T01_APPL_DATA

#if (defined FRTRCV_1_T01_APPL_CONST)
#error FRTRCV_1_T01_APPL_CONST already defined
#endif
#define FRTRCV_1_T01_APPL_CONST

#if (defined FRTRCV_1_T01_APPL_CODE)
#error FRTRCV_1_T01_APPL_CODE already defined
#endif
#define FRTRCV_1_T01_APPL_CODE

#if (defined FRTRCV_1_T01_VAR_NOINIT)
#error FRTRCV_1_T01_VAR_NOINIT already defined
#endif
#define FRTRCV_1_T01_VAR_NOINIT

#if (defined FRTRCV_1_T01_VAR_POWER_ON_INIT)
#error FRTRCV_1_T01_VAR_POWER_ON_INIT already defined
#endif
#define FRTRCV_1_T01_VAR_POWER_ON_INIT

#if (defined FRTRCV_1_T01_VAR_FAST)
#error FRTRCV_1_T01_VAR_FAST already defined
#endif
#define FRTRCV_1_T01_VAR_FAST

#if (defined FRTRCV_1_T01_VAR)
#error FRTRCV_1_T01_VAR already defined
#endif
#define FRTRCV_1_T01_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FRTRCV_1_TJA1080_CODE)
#error FRTRCV_1_TJA1080_CODE already defined
#endif
#define FRTRCV_1_TJA1080_CODE

#if (defined FRTRCV_1_TJA1080_CONST)
#error FRTRCV_1_TJA1080_CONST already defined
#endif
#define FRTRCV_1_TJA1080_CONST

#if (defined FRTRCV_1_TJA1080_APPL_DATA)
#error FRTRCV_1_TJA1080_APPL_DATA already defined
#endif
#define FRTRCV_1_TJA1080_APPL_DATA

#if (defined FRTRCV_1_TJA1080_APPL_CONST)
#error FRTRCV_1_TJA1080_APPL_CONST already defined
#endif
#define FRTRCV_1_TJA1080_APPL_CONST

#if (defined FRTRCV_1_TJA1080_APPL_CODE)
#error FRTRCV_1_TJA1080_APPL_CODE already defined
#endif
#define FRTRCV_1_TJA1080_APPL_CODE

#if (defined FRTRCV_1_TJA1080_VAR_NOINIT)
#error FRTRCV_1_TJA1080_VAR_NOINIT already defined
#endif
#define FRTRCV_1_TJA1080_VAR_NOINIT

#if (defined FRTRCV_1_TJA1080_VAR_POWER_ON_INIT)
#error FRTRCV_1_TJA1080_VAR_POWER_ON_INIT already defined
#endif
#define FRTRCV_1_TJA1080_VAR_POWER_ON_INIT

#if (defined FRTRCV_1_TJA1080_VAR_FAST)
#error FRTRCV_1_TJA1080_VAR_FAST already defined
#endif
#define FRTRCV_1_TJA1080_VAR_FAST

#if (defined FRTRCV_1_TJA1080_VAR)
#error FRTRCV_1_TJA1080_VAR already defined
#endif
#define FRTRCV_1_TJA1080_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined FR_1_MFR4300_CODE)
#error FR_1_MFR4300_CODE already defined
#endif
#define FR_1_MFR4300_CODE

#if (defined FR_1_MFR4300_CONST)
#error FR_1_MFR4300_CONST already defined
#endif
#define FR_1_MFR4300_CONST

#if (defined FR_1_MFR4300_APPL_DATA)
#error FR_1_MFR4300_APPL_DATA already defined
#endif
#define FR_1_MFR4300_APPL_DATA

#if (defined FR_1_MFR4300_APPL_CONST)
#error FR_1_MFR4300_APPL_CONST already defined
#endif
#define FR_1_MFR4300_APPL_CONST

#if (defined FR_1_MFR4300_APPL_CODE)
#error FR_1_MFR4300_APPL_CODE already defined
#endif
#define FR_1_MFR4300_APPL_CODE

#if (defined FR_1_MFR4300_VAR_NOINIT)
#error FR_1_MFR4300_VAR_NOINIT already defined
#endif
#define FR_1_MFR4300_VAR_NOINIT

#if (defined FR_1_MFR4300_VAR_POWER_ON_INIT)
#error FR_1_MFR4300_VAR_POWER_ON_INIT already defined
#endif
#define FR_1_MFR4300_VAR_POWER_ON_INIT

#if (defined FR_1_MFR4300_VAR_FAST)
#error FR_1_MFR4300_VAR_FAST already defined
#endif
#define FR_1_MFR4300_VAR_FAST

#if (defined FR_1_MFR4300_VAR)
#error FR_1_MFR4300_VAR already defined
#endif
#define FR_1_MFR4300_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined GPT_CODE)
#error GPT_CODE already defined
#endif
#define GPT_CODE

#if (defined GPT_CONST)
#error GPT_CONST already defined
#endif
#define GPT_CONST

#if (defined GPT_APPL_DATA)
#error GPT_APPL_DATA already defined
#endif
#define GPT_APPL_DATA

#if (defined GPT_APPL_CONST)
#error GPT_APPL_CONST already defined
#endif
#define GPT_APPL_CONST

#if (defined GPT_APPL_CODE)
#error GPT_APPL_CODE already defined
#endif
#define GPT_APPL_CODE

#if (defined GPT_VAR_NOINIT)
#error GPT_VAR_NOINIT already defined
#endif
#define GPT_VAR_NOINIT

#if (defined GPT_VAR_POWER_ON_INIT)
#error GPT_VAR_POWER_ON_INIT already defined
#endif
#define GPT_VAR_POWER_ON_INIT

#if (defined GPT_VAR_FAST)
#error GPT_VAR_FAST already defined
#endif
#define GPT_VAR_FAST

#if (defined GPT_VAR)
#error GPT_VAR already defined
#endif
#define GPT_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined GW_CODE)
#error GW_CODE already defined
#endif
#define GW_CODE

#if (defined GW_CONST)
#error GW_CONST already defined
#endif
#define GW_CONST

#if (defined GW_APPL_DATA)
#error GW_APPL_DATA already defined
#endif
#define GW_APPL_DATA

#if (defined GW_APPL_CONST)
#error GW_APPL_CONST already defined
#endif
#define GW_APPL_CONST

#if (defined GW_APPL_CODE)
#error GW_APPL_CODE already defined
#endif
#define GW_APPL_CODE

#if (defined GW_VAR_NOINIT)
#error GW_VAR_NOINIT already defined
#endif
#define GW_VAR_NOINIT

#if (defined GW_VAR_POWER_ON_INIT)
#error GW_VAR_POWER_ON_INIT already defined
#endif
#define GW_VAR_POWER_ON_INIT

#if (defined GW_VAR_FAST)
#error GW_VAR_FAST already defined
#endif
#define GW_VAR_FAST

#if (defined GW_VAR)
#error GW_VAR already defined
#endif
#define GW_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined ICU_CODE)
#error ICU_CODE already defined
#endif
#define ICU_CODE

#if (defined ICU_CONST)
#error ICU_CONST already defined
#endif
#define ICU_CONST

#if (defined ICU_APPL_DATA)
#error ICU_APPL_DATA already defined
#endif
#define ICU_APPL_DATA

#if (defined ICU_APPL_CONST)
#error ICU_APPL_CONST already defined
#endif
#define ICU_APPL_CONST

#if (defined ICU_APPL_CODE)
#error ICU_APPL_CODE already defined
#endif
#define ICU_APPL_CODE

#if (defined ICU_VAR_NOINIT)
#error ICU_VAR_NOINIT already defined
#endif
#define ICU_VAR_NOINIT

#if (defined ICU_VAR_POWER_ON_INIT)
#error ICU_VAR_POWER_ON_INIT already defined
#endif
#define ICU_VAR_POWER_ON_INIT

#if (defined ICU_VAR_FAST)
#error ICU_VAR_FAST already defined
#endif
#define ICU_VAR_FAST

#if (defined ICU_VAR)
#error ICU_VAR already defined
#endif
#define ICU_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined IOHWAB_CODE)
#error IOHWAB_CODE already defined
#endif
#define IOHWAB_CODE

#if (defined IOHWAB_CONST)
#error IOHWAB_CONST already defined
#endif
#define IOHWAB_CONST

#if (defined IOHWAB_APPL_DATA)
#error IOHWAB_APPL_DATA already defined
#endif
#define IOHWAB_APPL_DATA

#if (defined IOHWAB_APPL_CONST)
#error IOHWAB_APPL_CONST already defined
#endif
#define IOHWAB_APPL_CONST

#if (defined IOHWAB_APPL_CODE)
#error IOHWAB_APPL_CODE already defined
#endif
#define IOHWAB_APPL_CODE

#if (defined IOHWAB_VAR_NOINIT)
#error IOHWAB_VAR_NOINIT already defined
#endif
#define IOHWAB_VAR_NOINIT

#if (defined IOHWAB_VAR_POWER_ON_INIT)
#error IOHWAB_VAR_POWER_ON_INIT already defined
#endif
#define IOHWAB_VAR_POWER_ON_INIT

#if (defined IOHWAB_VAR_FAST)
#error IOHWAB_VAR_FAST already defined
#endif
#define IOHWAB_VAR_FAST

#if (defined IOHWAB_VAR)
#error IOHWAB_VAR already defined
#endif
#define IOHWAB_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined IPDUM_CODE)
#error IPDUM_CODE already defined
#endif
#define IPDUM_CODE

#if (defined IPDUM_CONST)
#error IPDUM_CONST already defined
#endif
#define IPDUM_CONST

#if (defined IPDUM_APPL_DATA)
#error IPDUM_APPL_DATA already defined
#endif
#define IPDUM_APPL_DATA

#if (defined IPDUM_APPL_CONST)
#error IPDUM_APPL_CONST already defined
#endif
#define IPDUM_APPL_CONST

#if (defined IPDUM_APPL_CODE)
#error IPDUM_APPL_CODE already defined
#endif
#define IPDUM_APPL_CODE

#if (defined IPDUM_VAR_NOINIT)
#error IPDUM_VAR_NOINIT already defined
#endif
#define IPDUM_VAR_NOINIT

#if (defined IPDUM_VAR_POWER_ON_INIT)
#error IPDUM_VAR_POWER_ON_INIT already defined
#endif
#define IPDUM_VAR_POWER_ON_INIT

#if (defined IPDUM_VAR_FAST)
#error IPDUM_VAR_FAST already defined
#endif
#define IPDUM_VAR_FAST

#if (defined IPDUM_VAR)
#error IPDUM_VAR already defined
#endif
#define IPDUM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined J1939DM_CODE)
#error J1939DM_CODE already defined
#endif
#define J1939DM_CODE

#if (defined J1939DM_CONST)
#error J1939DM_CONST already defined
#endif
#define J1939DM_CONST

#if (defined J1939DM_APPL_DATA)
#error J1939DM_APPL_DATA already defined
#endif
#define J1939DM_APPL_DATA

#if (defined J1939DM_APPL_CONST)
#error J1939DM_APPL_CONST already defined
#endif
#define J1939DM_APPL_CONST

#if (defined J1939DM_APPL_CODE)
#error J1939DM_APPL_CODE already defined
#endif
#define J1939DM_APPL_CODE

#if (defined J1939DM_VAR_NOINIT)
#error J1939DM_VAR_NOINIT already defined
#endif
#define J1939DM_VAR_NOINIT

#if (defined J1939DM_VAR_POWER_ON_INIT)
#error J1939DM_VAR_POWER_ON_INIT already defined
#endif
#define J1939DM_VAR_POWER_ON_INIT

#if (defined J1939DM_VAR_FAST)
#error J1939DM_VAR_FAST already defined
#endif
#define J1939DM_VAR_FAST

#if (defined J1939DM_VAR)
#error J1939DM_VAR already defined
#endif
#define J1939DM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined J1939RSM_CODE)
#error J1939RSM_CODE already defined
#endif
#define J1939RSM_CODE

#if (defined J1939RSM_CONST)
#error J1939RSM_CONST already defined
#endif
#define J1939RSM_CONST

#if (defined J1939RSM_APPL_DATA)
#error J1939RSM_APPL_DATA already defined
#endif
#define J1939RSM_APPL_DATA

#if (defined J1939RSM_APPL_CONST)
#error J1939RSM_APPL_CONST already defined
#endif
#define J1939RSM_APPL_CONST

#if (defined J1939RSM_APPL_CODE)
#error J1939RSM_APPL_CODE already defined
#endif
#define J1939RSM_APPL_CODE

#if (defined J1939RSM_VAR_NOINIT)
#error J1939RSM_VAR_NOINIT already defined
#endif
#define J1939RSM_VAR_NOINIT

#if (defined J1939RSM_VAR_POWER_ON_INIT)
#error J1939RSM_VAR_POWER_ON_INIT already defined
#endif
#define J1939RSM_VAR_POWER_ON_INIT

#if (defined J1939RSM_VAR_FAST)
#error J1939RSM_VAR_FAST already defined
#endif
#define J1939RSM_VAR_FAST

#if (defined J1939RSM_VAR)
#error J1939RSM_VAR already defined
#endif
#define J1939RSM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined J1939TP_CODE)
#error J1939TP_CODE already defined
#endif
#define J1939TP_CODE

#if (defined J1939TP_CONST)
#error J1939TP_CONST already defined
#endif
#define J1939TP_CONST

#if (defined J1939TP_APPL_DATA)
#error J1939TP_APPL_DATA already defined
#endif
#define J1939TP_APPL_DATA

#if (defined J1939TP_APPL_CONST)
#error J1939TP_APPL_CONST already defined
#endif
#define J1939TP_APPL_CONST

#if (defined J1939TP_APPL_CODE)
#error J1939TP_APPL_CODE already defined
#endif
#define J1939TP_APPL_CODE

#if (defined J1939TP_VAR_NOINIT)
#error J1939TP_VAR_NOINIT already defined
#endif
#define J1939TP_VAR_NOINIT

#if (defined J1939TP_VAR_POWER_ON_INIT)
#error J1939TP_VAR_POWER_ON_INIT already defined
#endif
#define J1939TP_VAR_POWER_ON_INIT

#if (defined J1939TP_VAR_FAST)
#error J1939TP_VAR_FAST already defined
#endif
#define J1939TP_VAR_FAST

#if (defined J1939TP_VAR)
#error J1939TP_VAR already defined
#endif
#define J1939TP_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined LIN_CODE)
#error LIN_CODE already defined
#endif
#define LIN_CODE

#if (defined LIN_CONST)
#error LIN_CONST already defined
#endif
#define LIN_CONST

#if (defined LIN_APPL_DATA)
#error LIN_APPL_DATA already defined
#endif
#define LIN_APPL_DATA

#if (defined LIN_APPL_CONST)
#error LIN_APPL_CONST already defined
#endif
#define LIN_APPL_CONST

#if (defined LIN_APPL_CODE)
#error LIN_APPL_CODE already defined
#endif
#define LIN_APPL_CODE

#if (defined LIN_VAR_NOINIT)
#error LIN_VAR_NOINIT already defined
#endif
#define LIN_VAR_NOINIT

#if (defined LIN_VAR_POWER_ON_INIT)
#error LIN_VAR_POWER_ON_INIT already defined
#endif
#define LIN_VAR_POWER_ON_INIT

#if (defined LIN_VAR_FAST)
#error LIN_VAR_FAST already defined
#endif
#define LIN_VAR_FAST

#if (defined LIN_VAR)
#error LIN_VAR already defined
#endif
#define LIN_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined LINIF_CODE)
#error LINIF_CODE already defined
#endif
#define LINIF_CODE

#if (defined LINIF_CONST)
#error LINIF_CONST already defined
#endif
#define LINIF_CONST

#if (defined LINIF_APPL_DATA)
#error LINIF_APPL_DATA already defined
#endif
#define LINIF_APPL_DATA

#if (defined LINIF_APPL_CONST)
#error LINIF_APPL_CONST already defined
#endif
#define LINIF_APPL_CONST

#if (defined LINIF_APPL_CODE)
#error LINIF_APPL_CODE already defined
#endif
#define LINIF_APPL_CODE

#if (defined LINIF_VAR_NOINIT)
#error LINIF_VAR_NOINIT already defined
#endif
#define LINIF_VAR_NOINIT

#if (defined LINIF_VAR_POWER_ON_INIT)
#error LINIF_VAR_POWER_ON_INIT already defined
#endif
#define LINIF_VAR_POWER_ON_INIT

#if (defined LINIF_VAR_FAST)
#error LINIF_VAR_FAST already defined
#endif
#define LINIF_VAR_FAST

#if (defined LINIF_VAR)
#error LINIF_VAR already defined
#endif
#define LINIF_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined LINSM_CODE)
#error LINSM_CODE already defined
#endif
#define LINSM_CODE

#if (defined LINSM_CONST)
#error LINSM_CONST already defined
#endif
#define LINSM_CONST

#if (defined LINSM_APPL_DATA)
#error LINSM_APPL_DATA already defined
#endif
#define LINSM_APPL_DATA

#if (defined LINSM_APPL_CONST)
#error LINSM_APPL_CONST already defined
#endif
#define LINSM_APPL_CONST

#if (defined LINSM_APPL_CODE)
#error LINSM_APPL_CODE already defined
#endif
#define LINSM_APPL_CODE

#if (defined LINSM_VAR_NOINIT)
#error LINSM_VAR_NOINIT already defined
#endif
#define LINSM_VAR_NOINIT

#if (defined LINSM_VAR_POWER_ON_INIT)
#error LINSM_VAR_POWER_ON_INIT already defined
#endif
#define LINSM_VAR_POWER_ON_INIT

#if (defined LINSM_VAR_FAST)
#error LINSM_VAR_FAST already defined
#endif
#define LINSM_VAR_FAST

#if (defined LINSM_VAR)
#error LINSM_VAR already defined
#endif
#define LINSM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined MCU_CODE)
#error MCU_CODE already defined
#endif
#define MCU_CODE

#if (defined MCU_CONST)
#error MCU_CONST already defined
#endif
#define MCU_CONST

#if (defined MCU_APPL_DATA)
#error MCU_APPL_DATA already defined
#endif
#define MCU_APPL_DATA

#if (defined MCU_APPL_CONST)
#error MCU_APPL_CONST already defined
#endif
#define MCU_APPL_CONST

#if (defined MCU_APPL_CODE)
#error MCU_APPL_CODE already defined
#endif
#define MCU_APPL_CODE

#if (defined MCU_VAR_NOINIT)
#error MCU_VAR_NOINIT already defined
#endif
#define MCU_VAR_NOINIT

#if (defined MCU_VAR_POWER_ON_INIT)
#error MCU_VAR_POWER_ON_INIT already defined
#endif
#define MCU_VAR_POWER_ON_INIT

#if (defined MCU_VAR_FAST)
#error MCU_VAR_FAST already defined
#endif
#define MCU_VAR_FAST

#if (defined MCU_VAR)
#error MCU_VAR already defined
#endif
#define MCU_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined MEMIF_CODE)
#error MEMIF_CODE already defined
#endif
#define MEMIF_CODE

#if (defined MEMIF_CONST)
#error MEMIF_CONST already defined
#endif
#define MEMIF_CONST

#if (defined MEMIF_APPL_DATA)
#error MEMIF_APPL_DATA already defined
#endif
#define MEMIF_APPL_DATA

#if (defined MEMIF_APPL_CONST)
#error MEMIF_APPL_CONST already defined
#endif
#define MEMIF_APPL_CONST

#if (defined MEMIF_APPL_CODE)
#error MEMIF_APPL_CODE already defined
#endif
#define MEMIF_APPL_CODE

#if (defined MEMIF_VAR_NOINIT)
#error MEMIF_VAR_NOINIT already defined
#endif
#define MEMIF_VAR_NOINIT

#if (defined MEMIF_VAR_POWER_ON_INIT)
#error MEMIF_VAR_POWER_ON_INIT already defined
#endif
#define MEMIF_VAR_POWER_ON_INIT

#if (defined MEMIF_VAR_FAST)
#error MEMIF_VAR_FAST already defined
#endif
#define MEMIF_VAR_FAST

#if (defined MEMIF_VAR)
#error MEMIF_VAR already defined
#endif
#define MEMIF_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined NM_CODE)
#error NM_CODE already defined
#endif
#define NM_CODE

#if (defined NM_CONST)
#error NM_CONST already defined
#endif
#define NM_CONST

#if (defined NM_APPL_DATA)
#error NM_APPL_DATA already defined
#endif
#define NM_APPL_DATA

#if (defined NM_APPL_CONST)
#error NM_APPL_CONST already defined
#endif
#define NM_APPL_CONST

#if (defined NM_APPL_CODE)
#error NM_APPL_CODE already defined
#endif
#define NM_APPL_CODE

#if (defined NM_VAR_NOINIT)
#error NM_VAR_NOINIT already defined
#endif
#define NM_VAR_NOINIT

#if (defined NM_VAR_POWER_ON_INIT)
#error NM_VAR_POWER_ON_INIT already defined
#endif
#define NM_VAR_POWER_ON_INIT

#if (defined NM_VAR_FAST)
#error NM_VAR_FAST already defined
#endif
#define NM_VAR_FAST

#if (defined NM_VAR)
#error NM_VAR already defined
#endif
#define NM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined NVM_CODE)
#error NVM_CODE already defined
#endif
#define NVM_CODE

#if (defined NVM_CONST)
#error NVM_CONST already defined
#endif
#define NVM_CONST

#if (defined NVM_APPL_DATA)
#error NVM_APPL_DATA already defined
#endif
#define NVM_APPL_DATA

#if (defined NVM_APPL_CONST)
#error NVM_APPL_CONST already defined
#endif
#define NVM_APPL_CONST

#if (defined NVM_APPL_CODE)
#error NVM_APPL_CODE already defined
#endif
#define NVM_APPL_CODE

#if (defined NVM_VAR_NOINIT)
#error NVM_VAR_NOINIT already defined
#endif
#define NVM_VAR_NOINIT

#if (defined NVM_VAR_POWER_ON_INIT)
#error NVM_VAR_POWER_ON_INIT already defined
#endif
#define NVM_VAR_POWER_ON_INIT

#if (defined NVM_VAR_FAST)
#error NVM_VAR_FAST already defined
#endif
#define NVM_VAR_FAST

#if (defined NVM_VAR)
#error NVM_VAR already defined
#endif
#define NVM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined OS_CODE)
#error OS_CODE already defined
#endif
#define OS_CODE

#if (defined OS_CONST)
#error OS_CONST already defined
#endif
#define OS_CONST

#if (defined OS_APPL_DATA)
#error OS_APPL_DATA already defined
#endif
#define OS_APPL_DATA

#if (defined OS_APPL_CONST)
#error OS_APPL_CONST already defined
#endif
#define OS_APPL_CONST

#if (defined OS_APPL_CODE)
#error OS_APPL_CODE already defined
#endif
#define OS_APPL_CODE

#if (defined OS_VAR_NOINIT)
#error OS_VAR_NOINIT already defined
#endif
#define OS_VAR_NOINIT

#if (defined OS_VAR_POWER_ON_INIT)
#error OS_VAR_POWER_ON_INIT already defined
#endif
#define OS_VAR_POWER_ON_INIT

#if (defined OS_VAR_FAST)
#error OS_VAR_FAST already defined
#endif
#define OS_VAR_FAST

#if (defined OS_VAR)
#error OS_VAR already defined
#endif
#define OS_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined PBCFGM_CODE)
#error PBCFGM_CODE already defined
#endif
#define PBCFGM_CODE

#if (defined PBCFGM_CONST)
#error PBCFGM_CONST already defined
#endif
#define PBCFGM_CONST

#if (defined PBCFGM_APPL_DATA)
#error PBCFGM_APPL_DATA already defined
#endif
#define PBCFGM_APPL_DATA

#if (defined PBCFGM_APPL_CONST)
#error PBCFGM_APPL_CONST already defined
#endif
#define PBCFGM_APPL_CONST

#if (defined PBCFGM_APPL_CODE)
#error PBCFGM_APPL_CODE already defined
#endif
#define PBCFGM_APPL_CODE

#if (defined PBCFGM_VAR_NOINIT)
#error PBCFGM_VAR_NOINIT already defined
#endif
#define PBCFGM_VAR_NOINIT

#if (defined PBCFGM_VAR_POWER_ON_INIT)
#error PBCFGM_VAR_POWER_ON_INIT already defined
#endif
#define PBCFGM_VAR_POWER_ON_INIT

#if (defined PBCFGM_VAR_FAST)
#error PBCFGM_VAR_FAST already defined
#endif
#define PBCFGM_VAR_FAST

#if (defined PBCFGM_VAR)
#error PBCFGM_VAR already defined
#endif
#define PBCFGM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined PDUR_CODE)
#error PDUR_CODE already defined
#endif
#define PDUR_CODE

#if (defined PDUR_CONST)
#error PDUR_CONST already defined
#endif
#define PDUR_CONST

#if (defined PDUR_APPL_DATA)
#error PDUR_APPL_DATA already defined
#endif
#define PDUR_APPL_DATA

#if (defined PDUR_APPL_CONST)
#error PDUR_APPL_CONST already defined
#endif
#define PDUR_APPL_CONST

#if (defined PDUR_APPL_CODE)
#error PDUR_APPL_CODE already defined
#endif
#define PDUR_APPL_CODE

#if (defined PDUR_VAR_NOINIT)
#error PDUR_VAR_NOINIT already defined
#endif
#define PDUR_VAR_NOINIT

#if (defined PDUR_VAR_POWER_ON_INIT)
#error PDUR_VAR_POWER_ON_INIT already defined
#endif
#define PDUR_VAR_POWER_ON_INIT

#if (defined PDUR_VAR_FAST)
#error PDUR_VAR_FAST already defined
#endif
#define PDUR_VAR_FAST

#if (defined PDUR_VAR)
#error PDUR_VAR already defined
#endif
#define PDUR_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined PORT_CODE)
#error PORT_CODE already defined
#endif
#define PORT_CODE

#if (defined PORT_CONST)
#error PORT_CONST already defined
#endif
#define PORT_CONST

#if (defined PORT_APPL_DATA)
#error PORT_APPL_DATA already defined
#endif
#define PORT_APPL_DATA

#if (defined PORT_APPL_CONST)
#error PORT_APPL_CONST already defined
#endif
#define PORT_APPL_CONST

#if (defined PORT_APPL_CODE)
#error PORT_APPL_CODE already defined
#endif
#define PORT_APPL_CODE

#if (defined PORT_VAR_NOINIT)
#error PORT_VAR_NOINIT already defined
#endif
#define PORT_VAR_NOINIT

#if (defined PORT_VAR_POWER_ON_INIT)
#error PORT_VAR_POWER_ON_INIT already defined
#endif
#define PORT_VAR_POWER_ON_INIT

#if (defined PORT_VAR_FAST)
#error PORT_VAR_FAST already defined
#endif
#define PORT_VAR_FAST

#if (defined PORT_VAR)
#error PORT_VAR already defined
#endif
#define PORT_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined PWM_CODE)
#error PWM_CODE already defined
#endif
#define PWM_CODE

#if (defined PWM_CONST)
#error PWM_CONST already defined
#endif
#define PWM_CONST

#if (defined PWM_APPL_DATA)
#error PWM_APPL_DATA already defined
#endif
#define PWM_APPL_DATA

#if (defined PWM_APPL_CONST)
#error PWM_APPL_CONST already defined
#endif
#define PWM_APPL_CONST

#if (defined PWM_APPL_CODE)
#error PWM_APPL_CODE already defined
#endif
#define PWM_APPL_CODE

#if (defined PWM_VAR_NOINIT)
#error PWM_VAR_NOINIT already defined
#endif
#define PWM_VAR_NOINIT

#if (defined PWM_VAR_POWER_ON_INIT)
#error PWM_VAR_POWER_ON_INIT already defined
#endif
#define PWM_VAR_POWER_ON_INIT

#if (defined PWM_VAR_FAST)
#error PWM_VAR_FAST already defined
#endif
#define PWM_VAR_FAST

#if (defined PWM_VAR)
#error PWM_VAR already defined
#endif
#define PWM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined RAMTST_CODE)
#error RAMTST_CODE already defined
#endif
#define RAMTST_CODE

#if (defined RAMTST_CONST)
#error RAMTST_CONST already defined
#endif
#define RAMTST_CONST

#if (defined RAMTST_APPL_DATA)
#error RAMTST_APPL_DATA already defined
#endif
#define RAMTST_APPL_DATA

#if (defined RAMTST_APPL_CONST)
#error RAMTST_APPL_CONST already defined
#endif
#define RAMTST_APPL_CONST

#if (defined RAMTST_APPL_CODE)
#error RAMTST_APPL_CODE already defined
#endif
#define RAMTST_APPL_CODE

#if (defined RAMTST_VAR_NOINIT)
#error RAMTST_VAR_NOINIT already defined
#endif
#define RAMTST_VAR_NOINIT

#if (defined RAMTST_VAR_POWER_ON_INIT)
#error RAMTST_VAR_POWER_ON_INIT already defined
#endif
#define RAMTST_VAR_POWER_ON_INIT

#if (defined RAMTST_VAR_FAST)
#error RAMTST_VAR_FAST already defined
#endif
#define RAMTST_VAR_FAST

#if (defined RAMTST_VAR)
#error RAMTST_VAR already defined
#endif
#define RAMTST_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined RTE_CODE)
#error RTE_CODE already defined
#endif
#define RTE_CODE

#if (defined RTE_CONST)
#error RTE_CONST already defined
#endif
#define RTE_CONST

#if (defined RTE_APPL_DATA)
#error RTE_APPL_DATA already defined
#endif
#define RTE_APPL_DATA

#if (defined RTE_APPL_CONST)
#error RTE_APPL_CONST already defined
#endif
#define RTE_APPL_CONST

#if (defined RTE_APPL_CODE)
#error RTE_APPL_CODE already defined
#endif
#define RTE_APPL_CODE

#if (defined RTE_VAR_NOINIT)
#error RTE_VAR_NOINIT already defined
#endif
#define RTE_VAR_NOINIT

#if (defined RTE_VAR_POWER_ON_INIT)
#error RTE_VAR_POWER_ON_INIT already defined
#endif
#define RTE_VAR_POWER_ON_INIT

#if (defined RTE_VAR_FAST)
#error RTE_VAR_FAST already defined
#endif
#define RTE_VAR_FAST

#if (defined RTE_VAR)
#error RTE_VAR already defined
#endif
#define RTE_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined SCHM_CODE)
#error SCHM_CODE already defined
#endif
#define SCHM_CODE

#if (defined SCHM_CONST)
#error SCHM_CONST already defined
#endif
#define SCHM_CONST

#if (defined SCHM_APPL_DATA)
#error SCHM_APPL_DATA already defined
#endif
#define SCHM_APPL_DATA

#if (defined SCHM_APPL_CONST)
#error SCHM_APPL_CONST already defined
#endif
#define SCHM_APPL_CONST

#if (defined SCHM_APPL_CODE)
#error SCHM_APPL_CODE already defined
#endif
#define SCHM_APPL_CODE

#if (defined SCHM_VAR_NOINIT)
#error SCHM_VAR_NOINIT already defined
#endif
#define SCHM_VAR_NOINIT

#if (defined SCHM_VAR_POWER_ON_INIT)
#error SCHM_VAR_POWER_ON_INIT already defined
#endif
#define SCHM_VAR_POWER_ON_INIT

#if (defined SCHM_VAR_FAST)
#error SCHM_VAR_FAST already defined
#endif
#define SCHM_VAR_FAST

#if (defined SCHM_VAR)
#error SCHM_VAR already defined
#endif
#define SCHM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined SCRC_CODE)
#error SCRC_CODE already defined
#endif
#define SCRC_CODE

#if (defined SCRC_CONST)
#error SCRC_CONST already defined
#endif
#define SCRC_CONST

#if (defined SCRC_APPL_DATA)
#error SCRC_APPL_DATA already defined
#endif
#define SCRC_APPL_DATA

#if (defined SCRC_APPL_CONST)
#error SCRC_APPL_CONST already defined
#endif
#define SCRC_APPL_CONST

#if (defined SCRC_APPL_CODE)
#error SCRC_APPL_CODE already defined
#endif
#define SCRC_APPL_CODE

#if (defined SCRC_VAR_NOINIT)
#error SCRC_VAR_NOINIT already defined
#endif
#define SCRC_VAR_NOINIT

#if (defined SCRC_VAR_POWER_ON_INIT)
#error SCRC_VAR_POWER_ON_INIT already defined
#endif
#define SCRC_VAR_POWER_ON_INIT

#if (defined SCRC_VAR_FAST)
#error SCRC_VAR_FAST already defined
#endif
#define SCRC_VAR_FAST

#if (defined SCRC_VAR)
#error SCRC_VAR already defined
#endif
#define SCRC_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined SD_CODE)
#error SD_CODE already defined
#endif
#define SD_CODE

#if (defined SD_CONST)
#error SD_CONST already defined
#endif
#define SD_CONST

#if (defined SD_APPL_DATA)
#error SD_APPL_DATA already defined
#endif
#define SD_APPL_DATA

#if (defined SD_APPL_CONST)
#error SD_APPL_CONST already defined
#endif
#define SD_APPL_CONST

#if (defined SD_APPL_CODE)
#error SD_APPL_CODE already defined
#endif
#define SD_APPL_CODE

#if (defined SD_VAR_NOINIT)
#error SD_VAR_NOINIT already defined
#endif
#define SD_VAR_NOINIT

#if (defined SD_VAR_POWER_ON_INIT)
#error SD_VAR_POWER_ON_INIT already defined
#endif
#define SD_VAR_POWER_ON_INIT

#if (defined SD_VAR_FAST)
#error SD_VAR_FAST already defined
#endif
#define SD_VAR_FAST

#if (defined SD_VAR)
#error SD_VAR already defined
#endif
#define SD_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined SOAD_CODE)
#error SOAD_CODE already defined
#endif
#define SOAD_CODE

#if (defined SOAD_CONST)
#error SOAD_CONST already defined
#endif
#define SOAD_CONST

#if (defined SOAD_APPL_DATA)
#error SOAD_APPL_DATA already defined
#endif
#define SOAD_APPL_DATA

#if (defined SOAD_APPL_CONST)
#error SOAD_APPL_CONST already defined
#endif
#define SOAD_APPL_CONST

#if (defined SOAD_APPL_CODE)
#error SOAD_APPL_CODE already defined
#endif
#define SOAD_APPL_CODE

#if (defined SOAD_VAR_NOINIT)
#error SOAD_VAR_NOINIT already defined
#endif
#define SOAD_VAR_NOINIT

#if (defined SOAD_VAR_POWER_ON_INIT)
#error SOAD_VAR_POWER_ON_INIT already defined
#endif
#define SOAD_VAR_POWER_ON_INIT

#if (defined SOAD_VAR_FAST)
#error SOAD_VAR_FAST already defined
#endif
#define SOAD_VAR_FAST

#if (defined SOAD_VAR)
#error SOAD_VAR already defined
#endif
#define SOAD_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined SPI_CODE)
#error SPI_CODE already defined
#endif
#define SPI_CODE

#if (defined SPI_CONST)
#error SPI_CONST already defined
#endif
#define SPI_CONST

#if (defined SPI_APPL_DATA)
#error SPI_APPL_DATA already defined
#endif
#define SPI_APPL_DATA

#if (defined SPI_APPL_CONST)
#error SPI_APPL_CONST already defined
#endif
#define SPI_APPL_CONST

#if (defined SPI_APPL_CODE)
#error SPI_APPL_CODE already defined
#endif
#define SPI_APPL_CODE

#if (defined SPI_VAR_NOINIT)
#error SPI_VAR_NOINIT already defined
#endif
#define SPI_VAR_NOINIT

#if (defined SPI_VAR_POWER_ON_INIT)
#error SPI_VAR_POWER_ON_INIT already defined
#endif
#define SPI_VAR_POWER_ON_INIT

#if (defined SPI_VAR_FAST)
#error SPI_VAR_FAST already defined
#endif
#define SPI_VAR_FAST

#if (defined SPI_VAR)
#error SPI_VAR already defined
#endif
#define SPI_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined STBM_CODE)
#error STBM_CODE already defined
#endif
#define STBM_CODE

#if (defined STBM_CONST)
#error STBM_CONST already defined
#endif
#define STBM_CONST

#if (defined STBM_APPL_DATA)
#error STBM_APPL_DATA already defined
#endif
#define STBM_APPL_DATA

#if (defined STBM_APPL_CONST)
#error STBM_APPL_CONST already defined
#endif
#define STBM_APPL_CONST

#if (defined STBM_APPL_CODE)
#error STBM_APPL_CODE already defined
#endif
#define STBM_APPL_CODE

#if (defined STBM_VAR_NOINIT)
#error STBM_VAR_NOINIT already defined
#endif
#define STBM_VAR_NOINIT

#if (defined STBM_VAR_POWER_ON_INIT)
#error STBM_VAR_POWER_ON_INIT already defined
#endif
#define STBM_VAR_POWER_ON_INIT

#if (defined STBM_VAR_FAST)
#error STBM_VAR_FAST already defined
#endif
#define STBM_VAR_FAST

#if (defined STBM_VAR)
#error STBM_VAR already defined
#endif
#define STBM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined TCPIP_CODE)
#error TCPIP_CODE already defined
#endif
#define TCPIP_CODE

#if (defined TCPIP_CONST)
#error TCPIP_CONST already defined
#endif
#define TCPIP_CONST

#if (defined TCPIP_APPL_DATA)
#error TCPIP_APPL_DATA already defined
#endif
#define TCPIP_APPL_DATA

#if (defined TCPIP_APPL_CONST)
#error TCPIP_APPL_CONST already defined
#endif
#define TCPIP_APPL_CONST

#if (defined TCPIP_APPL_CODE)
#error TCPIP_APPL_CODE already defined
#endif
#define TCPIP_APPL_CODE

#if (defined TCPIP_VAR_NOINIT)
#error TCPIP_VAR_NOINIT already defined
#endif
#define TCPIP_VAR_NOINIT

#if (defined TCPIP_VAR_POWER_ON_INIT)
#error TCPIP_VAR_POWER_ON_INIT already defined
#endif
#define TCPIP_VAR_POWER_ON_INIT

#if (defined TCPIP_VAR_FAST)
#error TCPIP_VAR_FAST already defined
#endif
#define TCPIP_VAR_FAST

#if (defined TCPIP_VAR)
#error TCPIP_VAR already defined
#endif
#define TCPIP_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined TS5ATL_CODE)
#error TS5ATL_CODE already defined
#endif
#define TS5ATL_CODE

#if (defined TS5ATL_CONST)
#error TS5ATL_CONST already defined
#endif
#define TS5ATL_CONST

#if (defined TS5ATL_APPL_DATA)
#error TS5ATL_APPL_DATA already defined
#endif
#define TS5ATL_APPL_DATA

#if (defined TS5ATL_APPL_CONST)
#error TS5ATL_APPL_CONST already defined
#endif
#define TS5ATL_APPL_CONST

#if (defined TS5ATL_APPL_CODE)
#error TS5ATL_APPL_CODE already defined
#endif
#define TS5ATL_APPL_CODE

#if (defined TS5ATL_VAR_NOINIT)
#error TS5ATL_VAR_NOINIT already defined
#endif
#define TS5ATL_VAR_NOINIT

#if (defined TS5ATL_VAR_POWER_ON_INIT)
#error TS5ATL_VAR_POWER_ON_INIT already defined
#endif
#define TS5ATL_VAR_POWER_ON_INIT

#if (defined TS5ATL_VAR_FAST)
#error TS5ATL_VAR_FAST already defined
#endif
#define TS5ATL_VAR_FAST

#if (defined TS5ATL_VAR)
#error TS5ATL_VAR already defined
#endif
#define TS5ATL_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined UDPNM_CODE)
#error UDPNM_CODE already defined
#endif
#define UDPNM_CODE

#if (defined UDPNM_CONST)
#error UDPNM_CONST already defined
#endif
#define UDPNM_CONST

#if (defined UDPNM_APPL_DATA)
#error UDPNM_APPL_DATA already defined
#endif
#define UDPNM_APPL_DATA

#if (defined UDPNM_APPL_CONST)
#error UDPNM_APPL_CONST already defined
#endif
#define UDPNM_APPL_CONST

#if (defined UDPNM_APPL_CODE)
#error UDPNM_APPL_CODE already defined
#endif
#define UDPNM_APPL_CODE

#if (defined UDPNM_VAR_NOINIT)
#error UDPNM_VAR_NOINIT already defined
#endif
#define UDPNM_VAR_NOINIT

#if (defined UDPNM_VAR_POWER_ON_INIT)
#error UDPNM_VAR_POWER_ON_INIT already defined
#endif
#define UDPNM_VAR_POWER_ON_INIT

#if (defined UDPNM_VAR_FAST)
#error UDPNM_VAR_FAST already defined
#endif
#define UDPNM_VAR_FAST

#if (defined UDPNM_VAR)
#error UDPNM_VAR already defined
#endif
#define UDPNM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined WDG_CODE)
#error WDG_CODE already defined
#endif
#define WDG_CODE

#if (defined WDG_CONST)
#error WDG_CONST already defined
#endif
#define WDG_CONST

#if (defined WDG_APPL_DATA)
#error WDG_APPL_DATA already defined
#endif
#define WDG_APPL_DATA

#if (defined WDG_APPL_CONST)
#error WDG_APPL_CONST already defined
#endif
#define WDG_APPL_CONST

#if (defined WDG_APPL_CODE)
#error WDG_APPL_CODE already defined
#endif
#define WDG_APPL_CODE

#if (defined WDG_VAR_NOINIT)
#error WDG_VAR_NOINIT already defined
#endif
#define WDG_VAR_NOINIT

#if (defined WDG_VAR_POWER_ON_INIT)
#error WDG_VAR_POWER_ON_INIT already defined
#endif
#define WDG_VAR_POWER_ON_INIT

#if (defined WDG_VAR_FAST)
#error WDG_VAR_FAST already defined
#endif
#define WDG_VAR_FAST

#if (defined WDG_VAR)
#error WDG_VAR already defined
#endif
#define WDG_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined WDGIF_CODE)
#error WDGIF_CODE already defined
#endif
#define WDGIF_CODE

#if (defined WDGIF_CONST)
#error WDGIF_CONST already defined
#endif
#define WDGIF_CONST

#if (defined WDGIF_APPL_DATA)
#error WDGIF_APPL_DATA already defined
#endif
#define WDGIF_APPL_DATA

#if (defined WDGIF_APPL_CONST)
#error WDGIF_APPL_CONST already defined
#endif
#define WDGIF_APPL_CONST

#if (defined WDGIF_APPL_CODE)
#error WDGIF_APPL_CODE already defined
#endif
#define WDGIF_APPL_CODE

#if (defined WDGIF_VAR_NOINIT)
#error WDGIF_VAR_NOINIT already defined
#endif
#define WDGIF_VAR_NOINIT

#if (defined WDGIF_VAR_POWER_ON_INIT)
#error WDGIF_VAR_POWER_ON_INIT already defined
#endif
#define WDGIF_VAR_POWER_ON_INIT

#if (defined WDGIF_VAR_FAST)
#error WDGIF_VAR_FAST already defined
#endif
#define WDGIF_VAR_FAST

#if (defined WDGIF_VAR)
#error WDGIF_VAR already defined
#endif
#define WDGIF_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined WDGM_CODE)
#error WDGM_CODE already defined
#endif
#define WDGM_CODE

#if (defined WDGM_CONST)
#error WDGM_CONST already defined
#endif
#define WDGM_CONST

#if (defined WDGM_APPL_DATA)
#error WDGM_APPL_DATA already defined
#endif
#define WDGM_APPL_DATA

#if (defined WDGM_APPL_CONST)
#error WDGM_APPL_CONST already defined
#endif
#define WDGM_APPL_CONST

#if (defined WDGM_APPL_CODE)
#error WDGM_APPL_CODE already defined
#endif
#define WDGM_APPL_CODE

#if (defined WDGM_VAR_NOINIT)
#error WDGM_VAR_NOINIT already defined
#endif
#define WDGM_VAR_NOINIT

#if (defined WDGM_VAR_POWER_ON_INIT)
#error WDGM_VAR_POWER_ON_INIT already defined
#endif
#define WDGM_VAR_POWER_ON_INIT

#if (defined WDGM_VAR_FAST)
#error WDGM_VAR_FAST already defined
#endif
#define WDGM_VAR_FAST

#if (defined WDGM_VAR)
#error WDGM_VAR already defined
#endif
#define WDGM_VAR


/*------------------[memory and pointer class of a module]-------------------*/

#if (defined XCP_CODE)
#error XCP_CODE already defined
#endif
#define XCP_CODE

#if (defined XCP_CONST)
#error XCP_CONST already defined
#endif
#define XCP_CONST

#if (defined XCP_APPL_DATA)
#error XCP_APPL_DATA already defined
#endif
#define XCP_APPL_DATA

#if (defined XCP_APPL_CONST)
#error XCP_APPL_CONST already defined
#endif
#define XCP_APPL_CONST

#if (defined XCP_APPL_CODE)
#error XCP_APPL_CODE already defined
#endif
#define XCP_APPL_CODE

#if (defined XCP_VAR_NOINIT)
#error XCP_VAR_NOINIT already defined
#endif
#define XCP_VAR_NOINIT

#if (defined XCP_VAR_POWER_ON_INIT)
#error XCP_VAR_POWER_ON_INIT already defined
#endif
#define XCP_VAR_POWER_ON_INIT

#if (defined XCP_VAR_FAST)
#error XCP_VAR_FAST already defined
#endif
#define XCP_VAR_FAST

#if (defined XCP_VAR)
#error XCP_VAR already defined
#endif
#define XCP_VAR



#endif /* if !defined( COMPILER_CFG_H ) */
/*==================[end of file]============================================*/
