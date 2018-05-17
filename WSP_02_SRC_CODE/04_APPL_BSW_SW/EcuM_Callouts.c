/**
 * \file
 *
 * \brief AUTOSAR EcuM_Callouts
 *
 * This file contains the implementation of the callouts for the AUTOSAR
 * EcuM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <TSAutosar.h>     /* EB specific standard types */
#include <Base_Modules.h>               /* Module enable defines and
                                           standard config pointer names */
#include <BswM_Modules.h>               /* Init function call defines    */

#ifdef BASE_CANTP_ENABLED
#include <CanTp.h>
#endif
#ifdef BASE_DCM_ENABLED
#include <Dcm.h>
#endif
#ifdef BASE_FEE_ENABLED
#include <Fee.h>
#endif
#ifdef BASE_FLS_ENABLED
#include <Fls.h>
#endif
#ifdef BASE_NVM_ENABLED
#include <NvM.h>
#include <NvM_DataIntern.h>             /* contains defines for service ids */
#include <NvM_Include.h>                /* prototype for callback */
#endif

#include "Det.h"
#include "Dem.h"
#include "Fim.h"
#include "Dio.h"
#include "Adc.h"
#include "GPT.h"
#include "Pwm.h"
#include "Port.h"
#include "Mcu.h"
#include "Mcl.h"
#include "Mcu_User.h"

#include "BswM.h"
#include "BswM_UserCallouts.h"
#include "Can.h"
#include "CanIf.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"
#include "Spi.h"
#include "SpiCtrl.h"
#include "Icu.h"
#include "CanSM_EcuM.h"

/** @todo move this include file in the approriate init list!!! */
#include "SbcMC33xxCdd.h"
#include "CC254xCDD.h"
#include "ICOM.h"
#include "ICOMChannel_Status.h"
#include "EcuM_Callouts.h"
#include "Xcp.h"
//#include "Nm.h"
//#include "CanNm.h"
#include "ExtFlashSpiCtrl.h"

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/
extern void DiagMeas_Init(void);
extern void DiagCtrl_Init(void);
extern void SCI_B6Bridge_Init(void);
extern void SpiCtrl_Init(void);
extern void LinEmuUart_Init(void);
extern void SCI_Pfc_Init(void);
extern void SCI_IOHW_Init(void);

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

ICOM_INST * pIcomInstBle;
/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*------------------[User callouts]------------------------------------------*/

void EcuM_Callout_DriverInitListOne(void)
{
  Det_Init();
  Dem_PreInit();
  Mcu_Init(&McuModuleConfiguration_0);
  Mcu_AdditionalInit();
  Mcl_Init(NULL_PTR);
  Port_Init(NULL_PTR);
  Adc_Init(NULL_PTR);
  Dio_Init(NULL_PTR);
  Gpt_Init(NULL_PTR);
  Pwm_Init(NULL_PTR);
  Icu_Init(NULL_PTR);
  Spi_Init(NULL_PTR);
  SpiCtrl_Init();
  SwGpt_Init();
  pIcomInstBle = ICOM_Create();
  ICOMChannelStatus_Init(pIcomInstBle);
  ICOMChannelDiag_Init(pIcomInstBle);
  ExtFlashSpiCtrlInit(SpiConf_SpiChannel_Spi_NVM_Command,\
                      SpiConf_SpiSequence_Spi_Seq_NVM,\
                      SpiConf_SpiJob_Spi_Job_NVM);
  CC254xCDD_Init(pIcomInstBle, 
                 DioConf_DioChannel_B6_SPI_SRDY_CU_LPCPU,\
                 SpiConf_SpiChannel_Spi_TICC2540_Command_8,\
                 SpiConf_SpiSequence_Spi_Seq_Ble_Exchange);
                 
  /* *******************************************************************
   * Wdg must be the latest in the initialization sequence
   * otherwise the function call Spi_SetAsyncMode(SPI_INTERRUPT_MODE)
   * returns a negative response when initializing the CC254xCDD_Init
   *********************************************************************/
  Wdg_Init(NULL_PTR);
  WdgM_Init(NULL_PTR);
  WdgM_SetMode(1U,0U);
  
}

void EcuM_Callout_DriverInitListTwo(void)
{
  /* status of NvM initialization */
  NvM_RequestResultType Result;
  BswM_Init(BswM_ConfigPtr);
  
  
  Fls_Init(NULL_PTR);
#ifdef BASE_EA_ENABLED
  EA_INIT_FUNC();
#endif
#ifdef BASE_FEE_ENABLED
  FEE_INIT_FUNC();
  
  /* wait for FEE to complete the init sequence */
  do
  {
    Fee_MainFunction();
    Fls_MainFunction();
  }
  while (MEMIF_IDLE != Fee_GetStatus());

#endif
#ifdef BASE_NVM_ENABLED
  NVM_INIT_FUNC();
  NvM_ReadAll();
  
  /* wait for the NvM_ReadAll() to complete - some of the remaining
     modules need valid NvRam data...       */
  do
  {
    NvM_MainFunction();
    Fee_MainFunction();
    Fls_MainFunction();

    (void)NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlock_ConfigID, &Result);
  }
  while (Result == NVM_REQ_PENDING);

#endif
  LinEmuUart_Init();
  
  Can_InitMemory();
  Can_Init(&CanConfigSet);

  CanIf_InitMemory();
  CanIf_Init(&CanIf_Config);
  //CanNm_Init(&CanNmGlobalConfig);
  //Nm_Init(&Nm_Configuration0);
  PduR_InitMemory();
  PduR_Init(&PduRGlobalConfig);
  Com_InitMemory();
  Com_Init(&ComConfig);
  CanSM_InitMemory();
  CanSM_Init();
  CanTp_InitMemory();
  CanTp_Init();  
  ComM_InitMemory();
  ComM_Init(&ComMConfig);
  Xcp_Init(NULL);
  FiM_Init(&FiM_Config_0);
  DiagMeas_Init();
  DiagCtrl_Init();
  SCI_B6Bridge_Init();
    SCI_Pfc_Init();
  SCI_IOHW_Init();
  
#ifdef BASE_DEM_ENABLED
  DEM_INIT_FUNC();
  /* start the standard operation cycle */
  /* (void) Dem_SetOperationCycleState(DEM_OPCYC_POWER, DEM_CYCLE_STATE_START); */
#endif  
  Dcm_Init();
}

void EcuM_Callout_BswM_RequestSTARTUP_TWO_AaB(void)
{
  /* Normally we should request this mode in InitListTwo. But we must
     call it here, as the Rte wasn't started earlier and the RteSwitchMode
     will get refused. */
  BswM_RequestMode(BSWM_BSWM_SM, BSWM_STARTUP_TWO_A);
  BswM_MainFunction();
  /* Normally we should request this mode in InitListTwo. But we must
     call it here, as the Rte wasn't started earlier and the RteSwitchMode
     will get refused. */
  BswM_RequestMode(BSWM_BSWM_SM, BSWM_STARTUP_TWO_B);
  BswM_MainFunction();
  
  /*
   * Init Function of the SecurityAccess.
   * This function should be called from the EcuM in
   * init level 3 (after NvM is available).
   */
  Dcm_SecurityAccess_Init();
}

void Appl_EcuM_currentMode_currentMode(EcuM_ModeType modeEvent_u8)
{
}
/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

