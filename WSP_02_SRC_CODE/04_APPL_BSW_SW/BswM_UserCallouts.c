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

/*==================[inclusions]============================================*/

#include <Std_Types.h>                  /* AUTOSAR standard types        */
#include <TSAutosar.h>                  /* EB specific standard types    */
#include <BswM_UserCallouts.h>          /* Callout function declarations */
#include <Base_Modules.h>               /* Module enable defines and
                                           standard config pointer names */
#include <BswM_Modules.h>               /* Init function call defines    */

#ifdef BASE_PBCFGM_ENABLED
#ifndef PBCFGM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define PBCFGM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <PbcfgM.h>
#endif

#ifdef BASE_NVM_ENABLED
#ifndef NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <NvM_DataIntern.h>             /* contains defines for service ids */
#include <NvM_Include.h>                /* prototype for callback */
#endif

#ifdef BASE_BSWM_ENABLED
#ifndef BSWM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define BSWM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <BswM.h>
#endif

#ifdef BASE_CAN_ENABLED
#ifndef CAN_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define CAN_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Can.h>
#endif

#ifdef BASE_CANIF_ENABLED
#ifndef CANIF_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define CANIF_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <CanIf.h>
#endif

#ifdef BASE_CANNM_ENABLED
#ifndef CANNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define CANNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <CanNm.h>
#endif

#ifdef BASE_CANSM_ENABLED
#ifndef CANSM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define CANSM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <CanSM.h>
#endif

#ifdef BASE_CANTP_ENABLED
#ifndef CANTP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define CANTP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <CanTp.h>
#endif

#ifdef BASE_CANTRCV_ENABLED
#ifndef CANTRCV_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define CANTRCV_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <CanTrcv.h>
#endif

#ifdef BASE_COM_ENABLED
#ifndef COM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define COM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Com.h>
#endif

#ifdef BASE_COMM_ENABLED
#ifndef COMM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define COMM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <ComM.h>
#include <ComM_EcuMBswM.h>
#endif

#ifdef BASE_DCM_ENABLED
#ifndef DCM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define DCM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Dcm.h>
#endif

#ifdef BASE_DEM_ENABLED
#ifndef DEM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define DEM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Dem.h>
#endif

#ifdef BASE_EA_ENABLED
#ifndef EA_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define EA_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Ea.h>
#endif

#ifdef BASE_ECUM_ENABLED
#ifndef ECUM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define ECUM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <EcuM.h>
#endif

#ifdef BASE_EEP_ENABLED
#ifndef EEP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define EEP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Eep.h>
#endif

#ifdef BASE_ETH_ENABLED
#ifndef ETH_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define ETH_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Eth.h>
#endif

#ifdef BASE_ETHIF_ENABLED
#ifndef ETHIF_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define ETHIF_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <EthIf.h>
#endif

#ifdef BASE_ETHSM_ENABLED
#ifndef ETHSM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define ETHSM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <EthSM.h>
#endif

#ifdef BASE_ETHTRCV_ENABLED
#ifndef ETHTRCV_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define ETHTRCV_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <EthTrcv.h>
#endif

#ifdef BASE_FEE_ENABLED
#ifndef FEE_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FEE_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Fee.h>
#endif

#ifdef BASE_FIM_ENABLED
#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <FiM.h>
#endif

#ifdef BASE_FLS_ENABLED
#ifndef FLS_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FLS_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Fls.h>
#endif

#ifdef BASE_FR_ENABLED
#ifndef FR_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FR_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Fr.h>
#endif

#ifdef BASE_FRIF_ENABLED
#ifndef FRIF_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FRIF_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <FrIf.h>
#endif

#ifdef BASE_FRNM_ENABLED
#ifndef FRNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FRNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <FrNm.h>
#endif

#ifdef BASE_FRSM_ENABLED
#ifndef FRSM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FRSM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <FrSM.h>
#endif

#ifdef BASE_FRTP_ENABLED
#ifndef FRTP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FRTP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <FrTp.h>
#endif

#ifdef BASE_FRTRCV_ENABLED
#ifndef FRTRCV_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define FRTRCV_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <FrTrcv.h>
#endif

#ifdef BASE_IPDUM_ENABLED
#ifndef IPDUM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define IPDUM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <IpduM.h>
#endif

#ifdef BASE_LIN_ENABLED
#ifndef LIN_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define LIN_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Lin.h>
#endif

#ifdef BASE_LINIF_ENABLED
#ifndef LINIF_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define LINIF_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <LinIf.h>
#endif

#ifdef BASE_LINSM_ENABLED
#ifndef LINSM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define LINSM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <LinSM.h>
#endif

#ifdef BASE_LINTRCV_ENABLED
#ifndef LINTRCV_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define LINTRCV_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <LinTrcv.h>
#endif

#ifdef BASE_NM_ENABLED
#ifndef NM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define NM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Nm.h>
#endif

#ifdef BASE_NVM_ENABLED
#ifndef NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define NVM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <NvM.h>
#endif

#ifdef BASE_PDUR_ENABLED
#ifndef PDUR_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define PDUR_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <PduR.h>
#endif

#ifdef BASE_RAMTST_ENABLED
#ifndef RAMTST_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define RAMTST_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <RamTst.h>
#endif

#ifdef BASE_RTE_ENABLED
#ifndef RTE_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define RTE_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Rte_Main.h>
#endif

#ifdef BASE_SOAD_ENABLED
#ifndef SOAD_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define SOAD_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <SoAd.h>
#endif

#ifdef BASE_SD_ENABLED
#ifndef SD_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define SD_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Sd.h>
#endif

#ifdef BASE_SPI_ENABLED
#ifndef SPI_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define SPI_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Spi.h>
#endif

#ifdef BASE_TCPIP_ENABLED
#ifndef TCPIP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define TCPIP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <TcpIp.h>
#endif

#ifdef BASE_UDPNM_ENABLED
#ifndef UDPNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define UDPNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <UdpNm.h>
#endif

#ifdef BASE_XCP_ENABLED
#ifndef XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#define XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#endif
#include <Xcp.h>
#endif

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define BSWM_START_SEC_CODE
#include <MemMap.h>
/* #include "SbcMC33xxCdd.h" */

/*------------------[User callouts]------------------------------------------*/


FUNC(void, BSWM_APPL_CODE) BswM_OnPrpShutdown(void)
{
  /* Do all activities here which shall be done right before the shutdown */

  EcuM_StateType shutdownTarget;
  uint8 sleepMode;

#ifdef BASE_DEM_ENABLED
  /* end the Dem operation cycle and shutdown the Dem */
  //(void) Dem_SetOperationCycleState(DEM_OPCYC_POWER, DEM_CYCLE_STATE_END);
  Dem_Shutdown();
#endif

  EcuM_GetShutdownTarget(&shutdownTarget, &sleepMode);

  if (ECUM_STATE_OFF == shutdownTarget)
  {
    BswM_RequestMode(BSWM_BSWM_SM, BSWM_GO_OFF_ONE_A);
  }
  else if (ECUM_STATE_SLEEP == shutdownTarget)
  {
/*    EcuM_GoPoll(); */ /* Missing in Vector EcuM */
  }
  else if (ECUM_STATE_RESET == shutdownTarget)
  {
    /* Insert your code here. */
  }
  else
  {
    /* Insert your code here. */
  }
}

FUNC(void, BSWM_APPL_CODE) BswM_OnGoOffOneA(void)
{
/*#if 0 */
/* When compile the final demo application, remove enclosing "#if 0", "#endif"
 * preprocessor statements.
 *
 * Reason:
 * Within the basicTemplate itself the RteGeneratorOutput is set to BSW_SCHEDULER_ONLY
 * and hence no Rte_Start(), Rte_Stop() are generated/provided.
 *
 * But during demo application configuration the RteGeneratorOutput is set to FULL mode
 * and Rte_Start(), Rte_Stop() are generated/provided and have to be called by the application.
*/
#ifdef BASE_RTE_ENABLED
  if ( Rte_Stop() != E_OK )
  {
    /* failed to stop the Rte */
  }
/*#endif *//* 0 */
#endif

#ifdef BASE_COMM_ENABLED
  ComM_DeInit();
#endif
  
#ifdef BASE_NVM_ENABLED
  /* when the NvM is used, call NvM_WriteAll() here. The job finished
   * callback EcuM_CB_NfyNvMJobEnd will then request BSWM_GO_OFF_ONE_B. */
  NvM_WriteAll();
#else
  /* directly request BSWM_GO_OFF_ONE_B */
  BswM_RequestMode(BSWM_BSWM_SM, BSWM_GO_OFF_ONE_B);
#endif
}


FUNC(void, BSWM_APPL_CODE) BswM_OnGoOffOneB(void)
{
/*  (void) EcuM_GoDown(BSWM_MODULE_ID);  */ /* Missing in Vector EcuM */
}


FUNC(void, BSWM_APPL_CODE) BswM_OnGoOffTwo(void)
{
}

FUNC(void, BSWM_APPL_CODE) BswM_OnWakeupTwo(void)
{
  EcuM_CheckWakeup(EcuM_MLBevo_HCAN);
}

FUNC(void, BSWM_APPL_CODE) BswM_OnRunTwo(void)
{
	ComM_RequestComMode(0U, COMM_FULL_COMMUNICATION );
}

#ifdef BASE_NVM_ENABLED
/* define NvM job finished callback only if NvM is part of the project */

FUNC(void, ECUM_APPL_CODE) EcuM_CB_NfyNvMJobEnd
(
    uint8                 ServiceId,
    NvM_RequestResultType JobResult
)
{
  /* to prevent immediate shutdown, when NvM_WriteAll() was called for 
     the very first initialization of DFlash */
  static boolean NvW_isWrittenFirstTime = FALSE;
  /* read the status for each single block */
  NvM_RequestResultType NvmBlockStatus;
  if (ServiceId == NVM_READ_ALL_API_ID)
  {
    if ( JobResult != NVM_REQ_OK )
    {
      NvW_isWrittenFirstTime = TRUE;
    }

    BswM_RequestMode(BSWM_BSWM_SM, BSWM_STARTUP_TWO_B);
  }
  else if (ServiceId == NVM_WRITE_ALL_API_ID)
  {
      if (NvW_isWrittenFirstTime == FALSE)
      {
         BswM_RequestMode(BSWM_BSWM_SM, BSWM_GO_OFF_ONE_B);
      }
      else
      {
         NvW_isWrittenFirstTime = FALSE;
      }
  }
  else
  {
    /* should not occur */
  }
}
#endif

FUNC(void, BSWM_APPL_CODE) ApplCan_FullCom(void)
{
  Com_IpduGroupStart(Com_PduGrp_AWC_Wayside__MLBevo_HCAN_Tx, 1);
  Com_IpduGroupStart(Com_PduGrp_AWC_Wayside__MLBevo_HCAN_Rx, 1);
  Com_IpduGroupStart(Com_PduGrp_AWC_Wayside__BT_CAN_MOD_V40_Rx, 1);
  Com_IpduGroupStart(Com_PduGrp_AWC_Wayside__BT_CAN_MOD_V40_Tx, 1);
}

FUNC(void, BSWM_APPL_CODE) ApplCan_NoCom(void)
{
  (void) ComM_RequestComMode(ComM_ComMUser_MLBevo_HCAN, COMM_NO_COMMUNICATION);
  Com_IpduGroupStop(Com_PduGrp_AWC_Wayside__MLBevo_HCAN_Rx);
  Com_IpduGroupStop(Com_PduGrp_AWC_Wayside__MLBevo_HCAN_Tx);
  Com_IpduGroupStop(Com_PduGrp_AWC_Wayside__BT_CAN_MOD_V40_Rx);
  Com_IpduGroupStop(Com_PduGrp_AWC_Wayside__BT_CAN_MOD_V40_Tx);
}

FUNC(void, BSWM_APPL_CODE) ApplCan_SilentCom(void)
{
  (void) ComM_RequestComMode(ComM_ComMUser_MLBevo_HCAN, COMM_SILENT_COMMUNICATION);
  Com_IpduGroupStop(Com_PduGrp_AWC_Wayside__MLBevo_HCAN_Tx);
  Com_IpduGroupStop(Com_PduGrp_AWC_Wayside__BT_CAN_MOD_V40_Tx);
}

FUNC(void, BSWM_APPL_CODE) ApplCan_BusOffEvent(void)
{
  //Dem_ReportErrorStatus( Dem_CANSM_E_BUSOFF_NETWORK_0, DEM_EVENT_STATUS_PREFAILED );
  //Com_IpduGroupStop(Com_PduGrp_AWC__MLBevo_HCAN_Tx);
}

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>


/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
