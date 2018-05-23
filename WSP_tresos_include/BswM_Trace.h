
#if !defined(BSWM_TRACE_H)
#define BSWM_TRACE_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/*==================[inclusions]============================================*/

/*==================[macros]================================================*/
#ifndef DBG_BSWM_INIT_ENTRY
/** \brief Entry point of function BswM_Init */
#define DBG_BSWM_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_INIT_EXIT
/** \brief Exit point of function BswM_Init */
#define DBG_BSWM_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_ENTRY
/** \brief Entry point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_EXIT
/** \brief Exit point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_EXIT(a)
#endif

#ifndef DBG_BSWM_DEINIT_ENTRY
/** \brief Entry point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_ENTRY()
#endif

#ifndef DBG_BSWM_DEINIT_EXIT
/** \brief Exit point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_EXIT()
#endif

#ifndef DBG_BSWM_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_ENTRY(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_EXIT(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY
/** \brief Entry point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY(a)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT
/** \brief Exit point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY
/** \brief Entry point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT
/** \brief Exit point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT(a,b)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY
/** \brief Entry point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT
/** \brief Exit point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_MAINFUNCTION_ENTRY
/** \brief Entry point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_ENTRY()
#endif

#ifndef DBG_BSWM_MAINFUNCTION_EXIT
/** \brief Exit point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_EXIT()
#endif

/* Dynamically generated macros */
#ifndef DBG_BSWM_ACTION_BSWM_ACT_RUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RUNTWO_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_RUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_REQUESTRUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RequestRunTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_REQUESTRUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_REQUESTRUNTWO_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RequestRunTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_REQUESTRUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_GOOFFONEA_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_GoOffOneA */
#define DBG_BSWM_ACTION_BSWM_ACT_GOOFFONEA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_GOOFFONEA_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_GoOffOneA */
#define DBG_BSWM_ACTION_BSWM_ACT_GOOFFONEA_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_GOOFFONEB_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_GoOffOneB */
#define DBG_BSWM_ACTION_BSWM_ACT_GOOFFONEB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_GOOFFONEB_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_GoOffOneB */
#define DBG_BSWM_ACTION_BSWM_ACT_GOOFFONEB_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_WAKEUPTWO_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_WakeupTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_WAKEUPTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_WAKEUPTWO_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_WakeupTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_WAKEUPTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_REQUESTWAKEUPTWO_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RequestWakeupTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_REQUESTWAKEUPTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_REQUESTWAKEUPTWO_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RequestWakeupTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_REQUESTWAKEUPTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_GOOFFONEA_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RteSwitch_GoOffOneA */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_GOOFFONEA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_GOOFFONEA_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RteSwitch_GoOffOneA */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_GOOFFONEA_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_GOOFFONEB_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RteSwitch_GoOffOneB */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_GOOFFONEB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_GOOFFONEB_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RteSwitch_GoOffOneB */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_GOOFFONEB_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_RUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RteSwitch_RunTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_RUNTWO_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RteSwitch_RunTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_RUNTWO_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_STARTUPTWOA_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RteSwitch_StartupTwoA */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_STARTUPTWOA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_STARTUPTWOA_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RteSwitch_StartupTwoA */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_STARTUPTWOA_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_STARTUPTWOB_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RteSwitch_StartupTwoB */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_STARTUPTWOB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_STARTUPTWOB_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RteSwitch_StartupTwoB */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_STARTUPTWOB_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_WAKEUPTWO_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RteSwitch_WakeupTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_WAKEUPTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_WAKEUPTWO_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RteSwitch_WakeupTwo */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_WAKEUPTWO_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_CANNOCOM_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_CanNoCom */
#define DBG_BSWM_ACTION_BSWM_ACT_CANNOCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_CANNOCOM_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_CanNoCom */
#define DBG_BSWM_ACTION_BSWM_ACT_CANNOCOM_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_CANSILENTCOM_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_CanSilentCom */
#define DBG_BSWM_ACTION_BSWM_ACT_CANSILENTCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_CANSILENTCOM_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_CanSilentCom */
#define DBG_BSWM_ACTION_BSWM_ACT_CANSILENTCOM_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_CANFULLCOM_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_CanFullCom */
#define DBG_BSWM_ACTION_BSWM_ACT_CANFULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_CANFULLCOM_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_CanFullCom */
#define DBG_BSWM_ACTION_BSWM_ACT_CANFULLCOM_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_PRPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_PrpShutdown */
#define DBG_BSWM_ACTION_BSWM_ACT_PRPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_PRPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_PrpShutdown */
#define DBG_BSWM_ACTION_BSWM_ACT_PRPSHUTDOWN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RESTARTCOMMFULLCOM_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RestartComMFullCom */
#define DBG_BSWM_ACTION_BSWM_ACT_RESTARTCOMMFULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RESTARTCOMMFULLCOM_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RestartComMFullCom */
#define DBG_BSWM_ACTION_BSWM_ACT_RESTARTCOMMFULLCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_BswM_Act_RteSwitch_PrpShutdown */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_BswM_Act_RteSwitch_PrpShutdown */
#define DBG_BSWM_ACTION_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_GOOFFONEA_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_GoOffOneA */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_GOOFFONEA_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_GOOFFONEA_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_GoOffOneA */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_GOOFFONEA_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_GOOFFONEB_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_GoOffOneB */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_GOOFFONEB_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_GOOFFONEB_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_GoOffOneB */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_GOOFFONEB_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_RUNTWO_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_RunTwo */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_RUNTWO_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_RUNTWO_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_RunTwo */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_RUNTWO_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_STARTUPTWOA_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_StartupTwoA */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_STARTUPTWOA_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_STARTUPTWOA_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_StartupTwoA */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_STARTUPTWOA_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_STARTUPTWOB_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_StartupTwoB */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_STARTUPTWOB_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_STARTUPTWOB_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_StartupTwoB */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_STARTUPTWOB_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_WAKEUPTWO_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_WakeupTwo */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_WAKEUPTWO_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_WAKEUPTWO_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_WakeupTwo */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_WAKEUPTWO_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANNOCOM_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_CanNoCom */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANNOCOM_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANNOCOM_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_CanNoCom */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANNOCOM_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANSILENTCOM_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_CanSilentCom */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANSILENTCOM_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANSILENTCOM_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_CanSilentCom */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANSILENTCOM_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANFULLCOM_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_CanFullCom */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANFULLCOM_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANFULLCOM_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_CanFullCom */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_CANFULLCOM_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_PRPSHUTDOWN_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_PrpShutdown */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_PRPSHUTDOWN_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_PRPSHUTDOWN_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_PrpShutdown */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_PRPSHUTDOWN_EXIT(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_RESTARTCOMMFULLCOM_ENTRY
/** \brief Entry point of function Bswm_Actionlist_BswM_ActLst_RestartComMFullCom */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_RESTARTCOMMFULLCOM_ENTRY(a, b)
#endif

#ifndef DBG_BSWM_ACTIONLIST_BSWM_ACTLST_RESTARTCOMMFULLCOM_EXIT
/** \brief Exit point of function Bswm_Actionlist_BswM_ActLst_RestartComMFullCom */
#define DBG_BSWM_ACTIONLIST_BSWM_ACTLST_RESTARTCOMMFULLCOM_EXIT(a, b)
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_STARTUPTWOA_EXEC_REQRTESWITCH_STARTUPTWOA_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_StartupTwoA_Exec_ReqRteSwitch_StartupTwoA */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_STARTUPTWOA_EXEC_REQRTESWITCH_STARTUPTWOA_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_STARTUPTWOA_EXEC_REQRTESWITCH_STARTUPTWOA_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_StartupTwoA_Exec_ReqRteSwitch_StartupTwoA */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_STARTUPTWOA_EXEC_REQRTESWITCH_STARTUPTWOA_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_STARTUPTWOB_EXEC_REQRTESWITCH_STARTUPTWOB_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_StartupTwoB_Exec_ReqRteSwitch_StartupTwoB */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_STARTUPTWOB_EXEC_REQRTESWITCH_STARTUPTWOB_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_STARTUPTWOB_EXEC_REQRTESWITCH_STARTUPTWOB_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_StartupTwoB_Exec_ReqRteSwitch_StartupTwoB */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_STARTUPTWOB_EXEC_REQRTESWITCH_STARTUPTWOB_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_GOOFFONEA_EXEC_CALLOUT_REQRTESWITCH_GOOFFONEA_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_GoOffOneA_Exec_Callout_ReqRteSwitch_GoOffOneA */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_GOOFFONEA_EXEC_CALLOUT_REQRTESWITCH_GOOFFONEA_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_GOOFFONEA_EXEC_CALLOUT_REQRTESWITCH_GOOFFONEA_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_GoOffOneA_Exec_Callout_ReqRteSwitch_GoOffOneA */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_GOOFFONEA_EXEC_CALLOUT_REQRTESWITCH_GOOFFONEA_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_GOOFFONEB_EXEC_CALLOUT_REQRTESWITCH_GOOFFONEB_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_GoOffOneB_Exec_Callout_ReqRteSwitch_GoOffOneB */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_GOOFFONEB_EXEC_CALLOUT_REQRTESWITCH_GOOFFONEB_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_GOOFFONEB_EXEC_CALLOUT_REQRTESWITCH_GOOFFONEB_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_GoOffOneB_Exec_Callout_ReqRteSwitch_GoOffOneB */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_GOOFFONEB_EXEC_CALLOUT_REQRTESWITCH_GOOFFONEB_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_WAKEUPTWO_EXEC_CALLOUT_REQRTESWITCH_WAKEUPTWO_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_WakeUpTwo_Exec_Callout_ReqRteSwitch_WakeUpTwo */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_WAKEUPTWO_EXEC_CALLOUT_REQRTESWITCH_WAKEUPTWO_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_WAKEUPTWO_EXEC_CALLOUT_REQRTESWITCH_WAKEUPTWO_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_WakeUpTwo_Exec_Callout_ReqRteSwitch_WakeUpTwo */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_WAKEUPTWO_EXEC_CALLOUT_REQRTESWITCH_WAKEUPTWO_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_RUNTWO_EXEC_CALLOUT_REQRTESWITCH_RUNTWO_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_RunTwo_Exec_Callout_ReqRteSwitch_RunTwo */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_RUNTWO_EXEC_CALLOUT_REQRTESWITCH_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_RUNTWO_EXEC_CALLOUT_REQRTESWITCH_RUNTWO_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_RunTwo_Exec_Callout_ReqRteSwitch_RunTwo */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_RUNTWO_EXEC_CALLOUT_REQRTESWITCH_RUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_PRPSHUTDOWN_EXEC_CALLOUT_REQRTESWITCH_PRPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_PrpShutdown_Exec_Callout_ReqRteSwitch_PrpShutdown */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_PRPSHUTDOWN_EXEC_CALLOUT_REQRTESWITCH_PRPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_PRPSHUTDOWN_EXEC_CALLOUT_REQRTESWITCH_PRPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_PrpShutdown_Exec_Callout_ReqRteSwitch_PrpShutdown */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_PRPSHUTDOWN_EXEC_CALLOUT_REQRTESWITCH_PRPSHUTDOWN_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_MODERUNNOCOM_EXEC_COMM_FULL_COM_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_ModeRunNoCom_Exec_ComM_FULL_COM */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_MODERUNNOCOM_EXEC_COMM_FULL_COM_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_MODERUNNOCOM_EXEC_COMM_FULL_COM_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_ModeRunNoCom_Exec_ComM_FULL_COM */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_MODERUNNOCOM_EXEC_COMM_FULL_COM_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_MODENOCOM_EXEC_CALLOUT_NOCOM_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_ModeNoCom_Exec_Callout_NoCom */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_MODENOCOM_EXEC_CALLOUT_NOCOM_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_MODENOCOM_EXEC_CALLOUT_NOCOM_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_ModeNoCom_Exec_Callout_NoCom */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_MODENOCOM_EXEC_CALLOUT_NOCOM_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_MODESILENTCOM_EXEC_CALLOUT_SILENTCOM_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_ModeSilentCom_Exec_Callout_SilentCom */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_MODESILENTCOM_EXEC_CALLOUT_SILENTCOM_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_MODESILENTCOM_EXEC_CALLOUT_SILENTCOM_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_ModeSilentCom_Exec_Callout_SilentCom */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_MODESILENTCOM_EXEC_CALLOUT_SILENTCOM_EXIT()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_MODEFULLCOM_EXEC_CALLOUT_FULLCOM_ENTRY
/** \brief Entry point of function BswM_EB_Rule_BswMRule_If_ModeFullCom_Exec_Callout_FullCom */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_MODEFULLCOM_EXEC_CALLOUT_FULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_EB_RULE_BSWMRULE_IF_MODEFULLCOM_EXEC_CALLOUT_FULLCOM_EXIT
/** \brief Exit point of function BswM_EB_Rule_BswMRule_If_ModeFullCom_Exec_Callout_FullCom */
#define DBG_BSWM_EB_RULE_BSWMRULE_IF_MODEFULLCOM_EXEC_CALLOUT_FULLCOM_EXIT()
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[end of file]===========================================*/
/** @} doxygen end group definition */
#endif /* !defined(BSWM_TRACE_H) */
/*==================[end of file]============================================*/

