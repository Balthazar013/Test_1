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
#if (!defined NVM_TRACE_H)
#define NVM_TRACE_H
/*==================[inclusions]============================================*/



/*==================[macros]================================================*/

#ifndef DBG_NVM_JOBERRORNOTIFICATION_ENTRY
/** \brief Entry point of function NvM_JobErrorNotification() */
#define DBG_NVM_JOBERRORNOTIFICATION_ENTRY()
#endif

#ifndef DBG_NVM_INIT_ENTRY
/** \brief Entry point of function NvM_Init() */
#define DBG_NVM_INIT_ENTRY()
#endif

#ifndef DBG_NVM_GLOBALWORKINGSTATUS
/** \brief Change of NvM_GlobalWorkingStatus */
#define DBG_NVM_GLOBALWORKINGSTATUS(a,b)
#endif

#ifndef DBG_NVM_INIT_EXIT
/** \brief Exit point of function NvM_Init() */
#define DBG_NVM_INIT_EXIT()
#endif

#ifndef DBG_NVM_MAINFUNCTION_ENTRY
/** \brief Entry point of function NvM_MainFunction() */
#define DBG_NVM_MAINFUNCTION_ENTRY()
#endif

#ifndef DBG_NVM_GLOBALERRORSTATUS
/** \brief Change of NvM_GlobalErrorStatus */
#define DBG_NVM_GLOBALERRORSTATUS(a,b)
#endif

#ifndef DBG_NVM_GLOBALGENERICSTATUS
/** \brief Change of NvM_GlobalErrorStatus */
#define DBG_NVM_GLOBALGENERICSTATUS(a,b)
#endif

#ifndef DBG_NVM_MAINFUNCTION_EXIT
/** \brief Exit point of function NvM_MainFunction() */
#define DBG_NVM_MAINFUNCTION_EXIT()
#endif

#ifndef DBG_NVM_PROCESSCANCELEDJOB_ENTRY
/** \brief Entry point of function NvM_ProcessCanceledJob() */
#define DBG_NVM_PROCESSCANCELEDJOB_ENTRY()
#endif

#ifndef DBG_NVM_PROCESSCANCELEDJOB_EXIT
/** \brief Exit point of function NvM_ProcessCanceledJob() */
#define DBG_NVM_PROCESSCANCELEDJOB_EXIT()
#endif

#ifndef DBG_NVM_PROCESSBLOCKCALLBACK_ENTRY
/** \brief Entry point of function NvM_ProcessBlockCallback() */
#define DBG_NVM_PROCESSBLOCKCALLBACK_ENTRY()
#endif

#ifndef DBG_NVM_PROCESSBLOCKCALLBACK_EXIT
/** \brief Exit point of function NvM_ProcessBlockCallback() */
#define DBG_NVM_PROCESSBLOCKCALLBACK_EXIT()
#endif

#ifndef DBG_NVM_REPORTSTATUSTOBSWM_ENTRY
/** \brief Entry point of function NvM_ReportStatusToBswM() */
#define DBG_NVM_REPORTSTATUSTOBSWM_ENTRY()
#endif

#ifndef DBG_NVM_REPORTSTATUSTOBSWM_EXIT
/** \brief Exit point of function NvM_ReportStatusToBswM() */
#define DBG_NVM_REPORTSTATUSTOBSWM_EXIT()
#endif

#ifndef DBG_NVM_ASR40_RESTOREBLOCKDEFAULTS_ENTRY
/** \brief Entry point of function NvM_ASR40_RestoreBlockDefaults() */
#define DBG_NVM_ASR40_RESTOREBLOCKDEFAULTS_ENTRY(a,b)
#endif

#ifndef DBG_NVM_ASR40_RESTOREBLOCKDEFAULTS_EXIT
/** \brief Exit point of function NvM_ASR40_RestoreBlockDefaults() */
#define DBG_NVM_ASR40_RESTOREBLOCKDEFAULTS_EXIT(a,b,c)
#endif

#ifndef DBG_NVM_ASR40_GETERRORSTATUS_ENTRY
/** \brief Entry point of function NvM_ASR40_GetErrorStatus() */
#define DBG_NVM_ASR40_GETERRORSTATUS_ENTRY(a,b)
#endif

#ifndef DBG_NVM_ASR40_GETERRORSTATUS_EXIT
/** \brief Exit point of function NvM_ASR40_GetErrorStatus() */
#define DBG_NVM_ASR40_GETERRORSTATUS_EXIT(a,b,c)
#endif

#ifndef DBG_NVM_ASR40_ERASENVBLOCK_ENTRY
/** \brief Entry point of function NvM_ASR40_EraseNvBlock() */
#define DBG_NVM_ASR40_ERASENVBLOCK_ENTRY(a)
#endif

#ifndef DBG_NVM_ASR40_ERASENVBLOCK_EXIT
/** \brief Exit point of function NvM_ASR40_EraseNvBlock() */
#define DBG_NVM_ASR40_ERASENVBLOCK_EXIT(a,b)
#endif

#ifndef DBG_NVM_ASR40_INVALIDATENVBLOCK_ENTRY
/** \brief Entry point of function NvM_ASR40_InvalidateNvBlock() */
#define DBG_NVM_ASR40_INVALIDATENVBLOCK_ENTRY(a)
#endif

#ifndef DBG_NVM_ASR40_INVALIDATENVBLOCK_EXIT
/** \brief Exit point of function NvM_ASR40_InvalidateNvBlock() */
#define DBG_NVM_ASR40_INVALIDATENVBLOCK_EXIT(a,b)
#endif

#ifndef DBG_NVM_ASR40_SETBLOCKPROTECTION_ENTRY
/** \brief Entry point of function NvM_ASR40_SetBlockProtection() */
#define DBG_NVM_ASR40_SETBLOCKPROTECTION_ENTRY(a,b)
#endif

#ifndef DBG_NVM_ASR40_SETBLOCKPROTECTION_EXIT
/** \brief Exit point of function NvM_ASR40_SetBlockProtection() */
#define DBG_NVM_ASR40_SETBLOCKPROTECTION_EXIT(a,b,c)
#endif

#ifndef DBG_NVM_ASR40_SETRAMBLOCKSTATUS_ENTRY
/** \brief Entry point of function NvM_ASR40_SetRamBlockStatus() */
#define DBG_NVM_ASR40_SETRAMBLOCKSTATUS_ENTRY(a,b)
#endif

#ifndef DBG_NVM_ASR40_SETRAMBLOCKSTATUS_EXIT
/** \brief Exit point of function NvM_ASR40_SetRamBlockStatus() */
#define DBG_NVM_ASR40_SETRAMBLOCKSTATUS_EXIT(a,b,c)
#endif

#ifndef DBG_NVM_SETBLOCKLOCKSTATUS_ENTRY
/** \brief Entry point of function NvM_SetBlockLockStatus() */
#define DBG_NVM_SETBLOCKLOCKSTATUS_ENTRY(a,b)
#endif

#ifndef DBG_NVM_SETBLOCKLOCKSTATUS_EXIT
/** \brief Exit point of function NvM_SetBlockLockStatus() */
#define DBG_NVM_SETBLOCKLOCKSTATUS_EXIT(a,b)
#endif

#ifndef DBG_NVM_GETVERSIONINFO_ENTRY
/** \brief Entry point of function NvM_GetVersionInfo() */
#define DBG_NVM_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_NVM_GETVERSIONINFO_EXIT
/** \brief Exit point of function NvM_GetVersionInfo() */
#define DBG_NVM_GETVERSIONINFO_EXIT(a)
#endif

#ifndef DBG_NVM_JOBENDNOTIFICATION_ENTRY
/** \brief Entry point of function NvM_JobEndNotification() */
#define DBG_NVM_JOBENDNOTIFICATION_ENTRY()
#endif

#ifndef DBG_NVM_JOBENDNOTIFICATION_EXIT
/** \brief Exit point of function NvM_JobEndNotification() */
#define DBG_NVM_JOBENDNOTIFICATION_EXIT()
#endif

#ifndef DBG_NVM_JOBERRORNOTIFICATION_EXIT
/** \brief Exit point of function NvM_JobErrorNotification() */
#define DBG_NVM_JOBERRORNOTIFICATION_EXIT()
#endif

#ifndef DBG_NVM_ASR40TOASR32_STATUSTYPE_ENTRY
/** \brief Entry point of function NvM_ASR40toASR32_StatusType() */
#define DBG_NVM_ASR40TOASR32_STATUSTYPE_ENTRY(a)
#endif

#ifndef DBG_NVM_ASR40TOASR32_STATUSTYPE_EXIT
/** \brief Exit point of function NvM_ASR40toASR32_StatusType() */
#define DBG_NVM_ASR40TOASR32_STATUSTYPE_EXIT(a,b)
#endif

#ifndef DBG_NVM_INVALIDATENVBLOCK_ASYNC_ENTRY
/** \brief Entry point of function NvM_InvalidateNvBlock_Async() */
#define DBG_NVM_INVALIDATENVBLOCK_ASYNC_ENTRY()
#endif

#ifndef DBG_NVM_INVALIDATENVBLOCK_ASYNC_EXIT
/** \brief Exit point of function NvM_InvalidateNvBlock_Async() */
#define DBG_NVM_INVALIDATENVBLOCK_ASYNC_EXIT()
#endif

#ifndef DBG_NVM_INVALIDATENVBLOCK_ASYNC_STATE1_ENTRY
/** \brief Entry point of function NvM_InvalidateNvBlock_Async_State1() */
#define DBG_NVM_INVALIDATENVBLOCK_ASYNC_STATE1_ENTRY()
#endif

#ifndef DBG_NVM_INVALIDATENVBLOCK_ASYNC_STATE1_EXIT
/** \brief Exit point of function NvM_InvalidateNvBlock_Async_State1() */
#define DBG_NVM_INVALIDATENVBLOCK_ASYNC_STATE1_EXIT()
#endif

#ifndef DBG_NVM_ERASENVBLOCK_ASYNC_ENTRY
/** \brief Entry point of function NvM_EraseNvBlock_Async() */
#define DBG_NVM_ERASENVBLOCK_ASYNC_ENTRY()
#endif

#ifndef DBG_NVM_ERASENVBLOCK_ASYNC_EXIT
/** \brief Exit point of function NvM_EraseNvBlock_Async() */
#define DBG_NVM_ERASENVBLOCK_ASYNC_EXIT()
#endif

#ifndef DBG_NVM_ERASENVBLOCK_ASYNC_STATE1_ENTRY
/** \brief Entry point of function NvM_EraseNvBlock_Async_State1() */
#define DBG_NVM_ERASENVBLOCK_ASYNC_STATE1_ENTRY()
#endif

#ifndef DBG_NVM_ERASENVBLOCK_ASYNC_STATE1_EXIT
/** \brief Exit point of function NvM_EraseNvBlock_Async_State1() */
#define DBG_NVM_ERASENVBLOCK_ASYNC_STATE1_EXIT()
#endif

#ifndef DBG_NVM_CALCCRC_UPDATELENGTH_ENTRY
/** \brief Entry point of function NvM_CalcCrc_UpdateLength() */
#define DBG_NVM_CALCCRC_UPDATELENGTH_ENTRY()
#endif

#ifndef DBG_NVM_CALCCRC_UPDATELENGTH_EXIT
/** \brief Exit point of function NvM_CalcCrc_UpdateLength() */
#define DBG_NVM_CALCCRC_UPDATELENGTH_EXIT(a)
#endif

#ifndef DBG_NVM_CALCCRC_GETBLOCKCRCADDRESS_ENTRY
/** \brief Entry point of function NvM_CalcCrc_GetBlockCrcAddress() */
#define DBG_NVM_CALCCRC_GETBLOCKCRCADDRESS_ENTRY()
#endif

#ifndef DBG_NVM_CALCCRC_GETBLOCKCRCADDRESS_EXIT
/** \brief Exit point of function NvM_CalcCrc_GetBlockCrcAddress() */
#define DBG_NVM_CALCCRC_GETBLOCKCRCADDRESS_EXIT(a)
#endif

#ifndef DBG_NVM_GETSTOREDRAMCRCADDRESS_ENTRY
/** \brief Entry point of function NvM_GetStoredRamCRCAddress() */
#define DBG_NVM_GETSTOREDRAMCRCADDRESS_ENTRY()
#endif

#ifndef DBG_NVM_GETSTOREDRAMCRCADDRESS_EXIT
/** \brief Exit point of function NvM_GetStoredRamCRCAddress() */
#define DBG_NVM_GETSTOREDRAMCRCADDRESS_EXIT(a)
#endif

#ifndef DBG_NVM_CALCULATECRC_ENTRY
/** \brief Entry point of function NvM_CalculateCrc() */
#define DBG_NVM_CALCULATECRC_ENTRY(a)
#endif

#ifndef DBG_NVM_GLOBALCALLLEVEL
/** \brief Change of NvM_GlobalCallLevel */
#define DBG_NVM_GLOBALCALLLEVEL(a,b)
#endif

#ifndef DBG_NVM_CALCULATECRC_EXIT
/** \brief Exit point of function NvM_CalculateCrc() */
#define DBG_NVM_CALCULATECRC_EXIT(a)
#endif

#ifndef DBG_NVM_COPYCRC_ENTRY
/** \brief Entry point of function NvM_CopyCrc() */
#define DBG_NVM_COPYCRC_ENTRY(a)
#endif

#ifndef DBG_NVM_COPYCRC_EXIT
/** \brief Exit point of function NvM_CopyCrc() */
#define DBG_NVM_COPYCRC_EXIT(a)
#endif

#ifndef DBG_NVM_CHECKCRC_ENTRY
/** \brief Entry point of function NvM_CheckCrc() */
#define DBG_NVM_CHECKCRC_ENTRY(a)
#endif

#ifndef DBG_NVM_CHECKCRC_EXIT
/** \brief Exit point of function NvM_CheckCrc() */
#define DBG_NVM_CHECKCRC_EXIT(a,b)
#endif

#ifndef DBG_NVM_CALCCRC_ASYNCSTATE_ENTRY
/** \brief Entry point of function NvM_CalcCrc_AsyncState() */
#define DBG_NVM_CALCCRC_ASYNCSTATE_ENTRY()
#endif

#ifndef DBG_NVM_CALCCRC_ASYNCSTATE_EXIT
/** \brief Exit point of function NvM_CalcCrc_AsyncState() */
#define DBG_NVM_CALCCRC_ASYNCSTATE_EXIT()
#endif

#ifndef DBG_NVM_SETPERMANENTRAMBLOCKINVALID_ENTRY
/** \brief Entry point of function NvM_SetPermanentRamBlockInvalid() */
#define DBG_NVM_SETPERMANENTRAMBLOCKINVALID_ENTRY()
#endif

#ifndef DBG_NVM_SETPERMANENTRAMBLOCKINVALID_EXIT
/** \brief Exit point of function NvM_SetPermanentRamBlockInvalid() */
#define DBG_NVM_SETPERMANENTRAMBLOCKINVALID_EXIT()
#endif

#ifndef DBG_NVM_SETPERMANENTRAMBLOCKVALID_ENTRY
/** \brief Entry point of function NvM_SetPermanentRamBlockValid() */
#define DBG_NVM_SETPERMANENTRAMBLOCKVALID_ENTRY()
#endif

#ifndef DBG_NVM_SETPERMANENTRAMBLOCKVALID_EXIT
/** \brief Exit point of function NvM_SetPermanentRamBlockValid() */
#define DBG_NVM_SETPERMANENTRAMBLOCKVALID_EXIT()
#endif

#ifndef DBG_NVM_SETPERMANENTRAMBLOCKUNCHANGED_ENTRY
/** \brief Entry point of function NvM_SetPermanentRamBlockUnchanged() */
#define DBG_NVM_SETPERMANENTRAMBLOCKUNCHANGED_ENTRY()
#endif

#ifndef DBG_NVM_SETPERMANENTRAMBLOCKUNCHANGED_EXIT
/** \brief Exit point of function NvM_SetPermanentRamBlockUnchanged() */
#define DBG_NVM_SETPERMANENTRAMBLOCKUNCHANGED_EXIT()
#endif

#ifndef DBG_NVM_SETPERMANENTRAMBLOCKCHANGED_ENTRY
/** \brief Entry point of function NvM_SetPermanentRamBlockChanged() */
#define DBG_NVM_SETPERMANENTRAMBLOCKCHANGED_ENTRY()
#endif

#ifndef DBG_NVM_SETPERMANENTRAMBLOCKCHANGED_EXIT
/** \brief Exit point of function NvM_SetPermanentRamBlockChanged() */
#define DBG_NVM_SETPERMANENTRAMBLOCKCHANGED_EXIT()
#endif

#ifndef DBG_NVM_GETUSERRAMBLOCKADDRESS_ENTRY
/** \brief Entry point of function NvM_GetUserRamBlockAddress() */
#define DBG_NVM_GETUSERRAMBLOCKADDRESS_ENTRY()
#endif

#ifndef DBG_NVM_GETUSERRAMBLOCKADDRESS_EXIT
/** \brief Exit point of function NvM_GetUserRamBlockAddress() */
#define DBG_NVM_GETUSERRAMBLOCKADDRESS_EXIT(a)
#endif

#ifndef DBG_NVM_GETMERGEDBLOCKNUMBER_ENTRY
/** \brief Entry point of function NvM_GetMergedBlockNumber() */
#define DBG_NVM_GETMERGEDBLOCKNUMBER_ENTRY()
#endif

#ifndef DBG_NVM_GETMERGEDBLOCKNUMBER_EXIT
/** \brief Exit point of function NvM_GetMergedBlockNumber() */
#define DBG_NVM_GETMERGEDBLOCKNUMBER_EXIT(a)
#endif

#ifndef DBG_NVM_RESETREDUNDANTBLOCKDATAINDEX_ENTRY
/** \brief Entry point of function NvM_ResetRedundantBlockDataIndex() */
#define DBG_NVM_RESETREDUNDANTBLOCKDATAINDEX_ENTRY()
#endif

#ifndef DBG_NVM_RESETREDUNDANTBLOCKDATAINDEX_EXIT
/** \brief Exit point of function NvM_ResetRedundantBlockDataIndex() */
#define DBG_NVM_RESETREDUNDANTBLOCKDATAINDEX_EXIT()
#endif

#ifndef DBG_NVM_MULTIREQUESTFINISHEDSINGLEBLOCK_ENTRY
/** \brief Entry point of function NvM_MultiRequestFinishedSingleBlock() */
#define DBG_NVM_MULTIREQUESTFINISHEDSINGLEBLOCK_ENTRY(a)
#endif

#ifndef DBG_NVM_MULTIREQUESTFINISHEDSINGLEBLOCK_EXIT
/** \brief Exit point of function NvM_MultiRequestFinishedSingleBlock() */
#define DBG_NVM_MULTIREQUESTFINISHEDSINGLEBLOCK_EXIT(a)
#endif

#ifndef DBG_NVM_PRESERVICE_FUNCTION_ENTRY
/** \brief Entry point of function NvM_PreService_Function() */
#define DBG_NVM_PRESERVICE_FUNCTION_ENTRY()
#endif

#ifndef DBG_NVM_PRESERVICE_FUNCTION_EXIT
/** \brief Exit point of function NvM_PreService_Function() */
#define DBG_NVM_PRESERVICE_FUNCTION_EXIT()
#endif

#ifndef DBG_NVM_POSTSERVICE_FUNCTION_ENTRY
/** \brief Entry point of function NvM_PostService_Function() */
#define DBG_NVM_POSTSERVICE_FUNCTION_ENTRY()
#endif

#ifndef DBG_NVM_POSTSERVICE_FUNCTION_EXIT
/** \brief Exit point of function NvM_PostService_Function() */
#define DBG_NVM_POSTSERVICE_FUNCTION_EXIT()
#endif

#ifndef DBG_NVM_MULTIPOSTSERVICE_FUNCTION_ENTRY
/** \brief Entry point of function NvM_MultiPostService_Function() */
#define DBG_NVM_MULTIPOSTSERVICE_FUNCTION_ENTRY()
#endif

#ifndef DBG_NVM_MULTIPOSTSERVICE_FUNCTION_EXIT
/** \brief Exit point of function NvM_MultiPostService_Function() */
#define DBG_NVM_MULTIPOSTSERVICE_FUNCTION_EXIT()
#endif

#ifndef DBG_NVM_CHECKWRITEPROTECTION_ENTRY
/** \brief Entry point of function NvM_CheckWriteProtection() */
#define DBG_NVM_CHECKWRITEPROTECTION_ENTRY(a)
#endif

#ifndef DBG_NVM_CHECKWRITEPROTECTION_EXIT
/** \brief Exit point of function NvM_CheckWriteProtection() */
#define DBG_NVM_CHECKWRITEPROTECTION_EXIT(a,b)
#endif

#ifndef DBG_NVM_CHECKDATASETROMBLOCK_ENTRY
/** \brief Entry point of function NvM_CheckDataSetRomBlock() */
#define DBG_NVM_CHECKDATASETROMBLOCK_ENTRY(a)
#endif

#ifndef DBG_NVM_CHECKDATASETROMBLOCK_EXIT
/** \brief Exit point of function NvM_CheckDataSetRomBlock() */
#define DBG_NVM_CHECKDATASETROMBLOCK_EXIT(a,b)
#endif

#ifndef DBG_NVM_GETBLOCKCRCLENGTH_ENTRY
/** \brief Entry point of function NvM_GetBlockCRCLength() */
#define DBG_NVM_GETBLOCKCRCLENGTH_ENTRY()
#endif

#ifndef DBG_NVM_GETBLOCKCRCLENGTH_EXIT
/** \brief Exit point of function NvM_GetBlockCRCLength() */
#define DBG_NVM_GETBLOCKCRCLENGTH_EXIT(a)
#endif

#ifndef DBG_NVM_GETBLOCKLENGTH_ENTRY
/** \brief Entry point of function NvM_GetBlockLength() */
#define DBG_NVM_GETBLOCKLENGTH_ENTRY()
#endif

#ifndef DBG_NVM_GETBLOCKLENGTH_EXIT
/** \brief Exit point of function NvM_GetBlockLength() */
#define DBG_NVM_GETBLOCKLENGTH_EXIT(a)
#endif

#ifndef DBG_NVM_GETBUFFERADDRESS_ENTRY
/** \brief Entry point of function NvM_GetBufferAddress() */
#define DBG_NVM_GETBUFFERADDRESS_ENTRY()
#endif

#ifndef DBG_NVM_GETBUFFERADDRESS_EXIT
/** \brief Exit point of function NvM_GetBufferAddress() */
#define DBG_NVM_GETBUFFERADDRESS_EXIT(a)
#endif

#ifndef DBG_NVM_GETDATAADDRESS_ENTRY
/** \brief Entry point of function NvM_GetDataAddress() */
#define DBG_NVM_GETDATAADDRESS_ENTRY()
#endif

#ifndef DBG_NVM_GETDATAADDRESS_EXIT
/** \brief Exit point of function NvM_GetDataAddress() */
#define DBG_NVM_GETDATAADDRESS_EXIT(a)
#endif

#ifndef DBG_NVM_MIRRORCOPY_ENTRY
/** \brief Entry point of function NvM_MirrorCopy() */
#define DBG_NVM_MIRRORCOPY_ENTRY(a,b,c)
#endif

#ifndef DBG_NVM_MIRRORCOPY_EXIT
/** \brief Exit point of function NvM_MirrorCopy() */
#define DBG_NVM_MIRRORCOPY_EXIT(a,b,c,d)
#endif

#ifndef DBG_NVM_CHECKBLOCKSTATUS_ENTRY
/** \brief Entry point of function NvM_CheckBlockStatus() */
#define DBG_NVM_CHECKBLOCKSTATUS_ENTRY()
#endif

#ifndef DBG_NVM_CHECKBLOCKSTATUS_EXIT
/** \brief Exit point of function NvM_CheckBlockStatus() */
#define DBG_NVM_CHECKBLOCKSTATUS_EXIT()
#endif

#ifndef DBG_NVM_FATALERROR_ENTRY
/** \brief Entry point of function NvM_FatalError() */
#define DBG_NVM_FATALERROR_ENTRY()
#endif

#ifndef DBG_NVM_FATALERROR_EXIT
/** \brief Exit point of function NvM_FatalError() */
#define DBG_NVM_FATALERROR_EXIT()
#endif

#ifndef DBG_NVM_QUEUE_CHECKEMPTY_ENTRY
/** \brief Entry point of function Nvm_Queue_CheckEmpty() */
#define DBG_NVM_QUEUE_CHECKEMPTY_ENTRY()
#endif

#ifndef DBG_NVM_QUEUE_CHECKEMPTY_EXIT
/** \brief Exit point of function Nvm_Queue_CheckEmpty() */
#define DBG_NVM_QUEUE_CHECKEMPTY_EXIT(a)
#endif

#ifndef DBG_NVM_QUEUE_CHECKFULLSTANDARD_ENTRY
/** \brief Entry point of function NvM_Queue_CheckFullStandard() */
#define DBG_NVM_QUEUE_CHECKFULLSTANDARD_ENTRY(a)
#endif

#ifndef DBG_NVM_QUEUE_CHECKFULLSTANDARD_EXIT
/** \brief Exit point of function NvM_Queue_CheckFullStandard() */
#define DBG_NVM_QUEUE_CHECKFULLSTANDARD_EXIT(a,b)
#endif

#ifndef DBG_NVM_QUEUE_INSERTSTANDARD_ENTRY
/** \brief Entry point of function NvM_Queue_InsertStandard() */
#define DBG_NVM_QUEUE_INSERTSTANDARD_ENTRY(a,b,c)
#endif

#ifndef DBG_NVM_QUEUE_INSERTSTANDARD_EXIT
/** \brief Exit point of function NvM_Queue_InsertStandard() */
#define DBG_NVM_QUEUE_INSERTSTANDARD_EXIT(a,b,c,d)
#endif

#ifndef DBG_NVM_QUEUE_REMOVEFIRSTITEM_ENTRY
/** \brief Entry point of function NvM_Queue_RemoveFirstItem() */
#define DBG_NVM_QUEUE_REMOVEFIRSTITEM_ENTRY()
#endif

#ifndef DBG_NVM_QUEUE_REMOVEFIRSTITEM_EXIT
/** \brief Exit point of function NvM_Queue_RemoveFirstItem() */
#define DBG_NVM_QUEUE_REMOVEFIRSTITEM_EXIT()
#endif

#ifndef DBG_NVM_QUEUE_PULLDOWNFIRSTITEM_ENTRY
/** \brief Entry point of function NvM_Queue_PullDownFirstItem() */
#define DBG_NVM_QUEUE_PULLDOWNFIRSTITEM_ENTRY()
#endif

#ifndef DBG_NVM_QUEUE_PULLDOWNFIRSTITEM_EXIT
/** \brief Exit point of function NvM_Queue_PullDownFirstItem() */
#define DBG_NVM_QUEUE_PULLDOWNFIRSTITEM_EXIT(a)
#endif

#ifndef DBG_NVM_READALL_ENTRY
/** \brief Entry point of function NvM_ReadAll() */
#define DBG_NVM_READALL_ENTRY()
#endif

#ifndef DBG_NVM_READALL_EXIT
/** \brief Exit point of function NvM_ReadAll() */
#define DBG_NVM_READALL_EXIT()
#endif

#ifndef DBG_NVM_FORCEFORWRITEALL_ENTRY
/** \brief Entry point of function NvM_ForceForWriteAll() */
#define DBG_NVM_FORCEFORWRITEALL_ENTRY()
#endif

#ifndef DBG_NVM_FORCEFORWRITEALL_EXIT
/** \brief Exit point of function NvM_ForceForWriteAll() */
#define DBG_NVM_FORCEFORWRITEALL_EXIT()
#endif

#ifndef DBG_NVM_READALL_ASYNC_ENTRY
/** \brief Entry point of function NvM_ReadAll_Async() */
#define DBG_NVM_READALL_ASYNC_ENTRY()
#endif

#ifndef DBG_NVM_READALL_ASYNC_EXIT
/** \brief Exit point of function NvM_ReadAll_Async() */
#define DBG_NVM_READALL_ASYNC_EXIT()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE0_ENTRY
/** \brief Entry point of function NvM_ReadAll_Async_State0() */
#define DBG_NVM_READALL_ASYNC_STATE0_ENTRY()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE0_EXIT
/** \brief Exit point of function NvM_ReadAll_Async_State0() */
#define DBG_NVM_READALL_ASYNC_STATE0_EXIT()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE1_ENTRY
/** \brief Entry point of function NvM_ReadAll_Async_State1() */
#define DBG_NVM_READALL_ASYNC_STATE1_ENTRY()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE1_EXIT
/** \brief Exit point of function NvM_ReadAll_Async_State1() */
#define DBG_NVM_READALL_ASYNC_STATE1_EXIT()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE5_ENTRY
/** \brief Entry point of function NvM_ReadAll_Async_State5() */
#define DBG_NVM_READALL_ASYNC_STATE5_ENTRY()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE5_EXIT
/** \brief Exit point of function NvM_ReadAll_Async_State5() */
#define DBG_NVM_READALL_ASYNC_STATE5_EXIT()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE6_ENTRY
/** \brief Entry point of function NvM_ReadAll_Async_State6() */
#define DBG_NVM_READALL_ASYNC_STATE6_ENTRY()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE6_EXIT
/** \brief Exit point of function NvM_ReadAll_Async_State6() */
#define DBG_NVM_READALL_ASYNC_STATE6_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE0_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_State0() */
#define DBG_NVM_READBLOCK_ASYNC_STATE0_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE0_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_State0() */
#define DBG_NVM_READBLOCK_ASYNC_STATE0_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE2_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_State2() */
#define DBG_NVM_READBLOCK_ASYNC_STATE2_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE2_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_State2() */
#define DBG_NVM_READBLOCK_ASYNC_STATE2_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE4_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_State4() */
#define DBG_NVM_READBLOCK_ASYNC_STATE4_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE4_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_State4() */
#define DBG_NVM_READBLOCK_ASYNC_STATE4_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE5_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_State5() */
#define DBG_NVM_READBLOCK_ASYNC_STATE5_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE5_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_State5() */
#define DBG_NVM_READBLOCK_ASYNC_STATE5_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE6_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_State6() */
#define DBG_NVM_READBLOCK_ASYNC_STATE6_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE6_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_State6() */
#define DBG_NVM_READBLOCK_ASYNC_STATE6_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE10_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_State10() */
#define DBG_NVM_READBLOCK_ASYNC_STATE10_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE10_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_State10() */
#define DBG_NVM_READBLOCK_ASYNC_STATE10_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE12_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_State12() */
#define DBG_NVM_READBLOCK_ASYNC_STATE12_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATE12_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_State12() */
#define DBG_NVM_READBLOCK_ASYNC_STATE12_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_RETRY_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_Retry() */
#define DBG_NVM_READBLOCK_ASYNC_RETRY_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_RETRY_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_Retry() */
#define DBG_NVM_READBLOCK_ASYNC_RETRY_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATEERROR1_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_StateError1() */
#define DBG_NVM_READBLOCK_ASYNC_STATEERROR1_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATEERROR1_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_StateError1() */
#define DBG_NVM_READBLOCK_ASYNC_STATEERROR1_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATEERROR2_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_StateError2() */
#define DBG_NVM_READBLOCK_ASYNC_STATEERROR2_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATEERROR2_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_StateError2() */
#define DBG_NVM_READBLOCK_ASYNC_STATEERROR2_EXIT()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATEERROR3_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async_StateError3() */
#define DBG_NVM_READBLOCK_ASYNC_STATEERROR3_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_STATEERROR3_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async_StateError3() */
#define DBG_NVM_READBLOCK_ASYNC_STATEERROR3_EXIT()
#endif

#ifndef DBG_NVM_MEMIFREAD_ENTRY
/** \brief Entry point of function NvM_MemIfRead() */
#define DBG_NVM_MEMIFREAD_ENTRY(a,b)
#endif

#ifndef DBG_NVM_MEMIFREAD_EXIT
/** \brief Exit point of function NvM_MemIfRead() */
#define DBG_NVM_MEMIFREAD_EXIT(a,b)
#endif

#ifndef DBG_NVM_REPORTLOSSOFREDUNDANCY_ENTRY
/** \brief Entry point of function NvM_ReportLossOfRedundancy() */
#define DBG_NVM_REPORTLOSSOFREDUNDANCY_ENTRY()
#endif

#ifndef DBG_NVM_REPORTLOSSOFREDUNDANCY_EXIT
/** \brief Exit point of function NvM_ReportLossOfRedundancy() */
#define DBG_NVM_REPORTLOSSOFREDUNDANCY_EXIT()
#endif

#ifndef DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE0_ENTRY
/** \brief Entry point of function NvM_RestoreBlockDefaults_Async_State0() */
#define DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE0_ENTRY()
#endif

#ifndef DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE0_EXIT
/** \brief Exit point of function NvM_RestoreBlockDefaults_Async_State0() */
#define DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE0_EXIT()
#endif

#ifndef DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE1_ENTRY
/** \brief Entry point of function NvM_RestoreBlockDefaults_Async_State1() */
#define DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE1_ENTRY()
#endif

#ifndef DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE1_EXIT
/** \brief Exit point of function NvM_RestoreBlockDefaults_Async_State1() */
#define DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE1_EXIT()
#endif

#ifndef DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE2_ENTRY
/** \brief Entry point of function NvM_RestoreBlockDefaults_Async_State2() */
#define DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE2_ENTRY()
#endif

#ifndef DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE2_EXIT
/** \brief Exit point of function NvM_RestoreBlockDefaults_Async_State2() */
#define DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE2_EXIT()
#endif

#ifndef DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE3_ENTRY
/** \brief Entry point of function NvM_RestoreBlockDefaults_Async_State3() */
#define DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE3_ENTRY()
#endif

#ifndef DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE3_EXIT
/** \brief Exit point of function NvM_RestoreBlockDefaults_Async_State3() */
#define DBG_NVM_RESTOREBLOCKDEFAULTS_ASYNC_STATE3_EXIT()
#endif

#ifndef DBG_NVM_COPYBLOCKROM2RAM_ENTRY
/** \brief Entry point of function NvM_CopyBlockRom2Ram() */
#define DBG_NVM_COPYBLOCKROM2RAM_ENTRY()
#endif

#ifndef DBG_NVM_COPYBLOCKROM2RAM_EXIT
/** \brief Exit point of function NvM_CopyBlockRom2Ram() */
#define DBG_NVM_COPYBLOCKROM2RAM_EXIT()
#endif

#ifndef DBG_NVM_STATEMACHINE_PROCESSREDUNDANTBLOCK_ENTRY
/** \brief Entry point of function NvM_StateMachine_ProcessRedundantBlock() */
#define DBG_NVM_STATEMACHINE_PROCESSREDUNDANTBLOCK_ENTRY(a)
#endif

#ifndef DBG_NVM_STATEMACHINE_PROCESSREDUNDANTBLOCK_EXIT
/** \brief Exit point of function NvM_StateMachine_ProcessRedundantBlock() */
#define DBG_NVM_STATEMACHINE_PROCESSREDUNDANTBLOCK_EXIT(a)
#endif

#ifndef DBG_NVM_STATEMACHINE_REDUNDANTBLOCKERROR_ENTRY
/** \brief Entry point of function NvM_StateMachine_RedundantBlockError() */
#define DBG_NVM_STATEMACHINE_REDUNDANTBLOCKERROR_ENTRY()
#endif

#ifndef DBG_NVM_STATEMACHINE_REDUNDANTBLOCKERROR_EXIT
/** \brief Exit point of function NvM_StateMachine_RedundantBlockError() */
#define DBG_NVM_STATEMACHINE_REDUNDANTBLOCKERROR_EXIT()
#endif

#ifndef DBG_NVM_STATEMACHINE_TERMINATECURRENTLEVEL_ENTRY
/** \brief Entry point of function NvM_StateMachine_TerminateCurrentLevel() */
#define DBG_NVM_STATEMACHINE_TERMINATECURRENTLEVEL_ENTRY()
#endif

#ifndef DBG_NVM_STATEMACHINE_TERMINATECURRENTLEVEL_EXIT
/** \brief Exit point of function NvM_StateMachine_TerminateCurrentLevel() */
#define DBG_NVM_STATEMACHINE_TERMINATECURRENTLEVEL_EXIT()
#endif

#ifndef DBG_NVM_STATEMACHINE_TERMINATESUBLEVEL_ENTRY
/** \brief Entry point of function NvM_StateMachine_TerminateSubLevel() */
#define DBG_NVM_STATEMACHINE_TERMINATESUBLEVEL_ENTRY()
#endif

#ifndef DBG_NVM_STATEMACHINE_TERMINATESUBLEVEL_EXIT
/** \brief Exit point of function NvM_StateMachine_TerminateSubLevel() */
#define DBG_NVM_STATEMACHINE_TERMINATESUBLEVEL_EXIT()
#endif

#ifndef DBG_NVM_STATEMACHINE_PROCESSJOBRESULT_ENTRY
/** \brief Entry point of function NvM_StateMachine_ProcessJobResult() */
#define DBG_NVM_STATEMACHINE_PROCESSJOBRESULT_ENTRY()
#endif

#ifndef DBG_NVM_STATEMACHINE_PROCESSJOBRESULT_EXIT
/** \brief Exit point of function NvM_StateMachine_ProcessJobResult() */
#define DBG_NVM_STATEMACHINE_PROCESSJOBRESULT_EXIT()
#endif

#ifndef DBG_NVM_STATEMACHINE_SETNEXTREQUEST_ENTRY
/** \brief Entry point of function NvM_StateMachine_SetNextRequest() */
#define DBG_NVM_STATEMACHINE_SETNEXTREQUEST_ENTRY()
#endif

#ifndef DBG_NVM_STATEMACHINE_SETNEXTREQUEST_EXIT
/** \brief Exit point of function NvM_StateMachine_SetNextRequest() */
#define DBG_NVM_STATEMACHINE_SETNEXTREQUEST_EXIT()
#endif

#ifndef DBG_NVM_WRITEALL_ENTRY
/** \brief Entry point of function NvM_WriteAll() */
#define DBG_NVM_WRITEALL_ENTRY()
#endif

#ifndef DBG_NVM_WRITEALL_EXIT
/** \brief Exit point of function NvM_WriteAll() */
#define DBG_NVM_WRITEALL_EXIT()
#endif

#ifndef DBG_NVM_CANCELWRITEALL_ENTRY
/** \brief Entry point of function NvM_CancelWriteAll() */
#define DBG_NVM_CANCELWRITEALL_ENTRY()
#endif

#ifndef DBG_NVM_CANCELWRITEALL_EXIT
/** \brief Exit point of function NvM_CancelWriteAll() */
#define DBG_NVM_CANCELWRITEALL_EXIT()
#endif

#ifndef DBG_NVM_WRITEALL_ASYNC_ENTRY
/** \brief Entry point of function NvM_WriteAll_Async() */
#define DBG_NVM_WRITEALL_ASYNC_ENTRY()
#endif

#ifndef DBG_NVM_WRITEALL_ASYNC_EXIT
/** \brief Exit point of function NvM_WriteAll_Async() */
#define DBG_NVM_WRITEALL_ASYNC_EXIT()
#endif

#ifndef DBG_NVM_WRITEALL_ASYNC_STATE1_ENTRY
/** \brief Entry point of function NvM_WriteAll_Async_State1() */
#define DBG_NVM_WRITEALL_ASYNC_STATE1_ENTRY()
#endif

#ifndef DBG_NVM_WRITEALL_ASYNC_STATE1_EXIT
/** \brief Exit point of function NvM_WriteAll_Async_State1() */
#define DBG_NVM_WRITEALL_ASYNC_STATE1_EXIT()
#endif

#ifndef DBG_NVM_WRITEALL_ASYNC_STATE2_ENTRY
/** \brief Entry point of function NvM_WriteAll_Async_State2() */
#define DBG_NVM_WRITEALL_ASYNC_STATE2_ENTRY()
#endif

#ifndef DBG_NVM_WRITEALL_ASYNC_STATE2_EXIT
/** \brief Exit point of function NvM_WriteAll_Async_State2() */
#define DBG_NVM_WRITEALL_ASYNC_STATE2_EXIT()
#endif

#ifndef DBG_NVM_WRITEALL_ASYNC_STATE3_ENTRY
/** \brief Entry point of function NvM_WriteAll_Async_State3() */
#define DBG_NVM_WRITEALL_ASYNC_STATE3_ENTRY()
#endif

#ifndef DBG_NVM_WRITEALL_ASYNC_STATE3_EXIT
/** \brief Exit point of function NvM_WriteAll_Async_State3() */
#define DBG_NVM_WRITEALL_ASYNC_STATE3_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_COPYCRC_ENTRY
/** \brief Entry point of function NvM_WriteBlock_Async_CopyCrc() */
#define DBG_NVM_WRITEBLOCK_ASYNC_COPYCRC_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_COPYCRC_EXIT
/** \brief Exit point of function NvM_WriteBlock_Async_CopyCrc() */
#define DBG_NVM_WRITEBLOCK_ASYNC_COPYCRC_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_ERROR_ENTRY
/** \brief Entry point of function NvM_WriteBlock_Async_Error() */
#define DBG_NVM_WRITEBLOCK_ASYNC_ERROR_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_ERROR_EXIT
/** \brief Exit point of function NvM_WriteBlock_Async_Error() */
#define DBG_NVM_WRITEBLOCK_ASYNC_ERROR_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_STATE1_ENTRY
/** \brief Entry point of function NvM_WriteBlock_Async_State1() */
#define DBG_NVM_WRITEBLOCK_ASYNC_STATE1_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_STATE1_EXIT
/** \brief Exit point of function NvM_WriteBlock_Async_State1() */
#define DBG_NVM_WRITEBLOCK_ASYNC_STATE1_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_STATE2_ENTRY
/** \brief Entry point of function NvM_WriteBlock_Async_State2() */
#define DBG_NVM_WRITEBLOCK_ASYNC_STATE2_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_STATE2_EXIT
/** \brief Exit point of function NvM_WriteBlock_Async_State2() */
#define DBG_NVM_WRITEBLOCK_ASYNC_STATE2_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_STATE3_ENTRY
/** \brief Entry point of function NvM_WriteBlock_Async_State3() */
#define DBG_NVM_WRITEBLOCK_ASYNC_STATE3_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_STATE3_EXIT
/** \brief Exit point of function NvM_WriteBlock_Async_State3() */
#define DBG_NVM_WRITEBLOCK_ASYNC_STATE3_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_PROCESSJOBRESULT_ASYNC_STATE_ENTRY
/** \brief Entry point of function NvM_WriteBlock_ProcessJobResult_Async_State() */
#define DBG_NVM_WRITEBLOCK_PROCESSJOBRESULT_ASYNC_STATE_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_PROCESSJOBRESULT_ASYNC_STATE_EXIT
/** \brief Exit point of function NvM_WriteBlock_ProcessJobResult_Async_State() */
#define DBG_NVM_WRITEBLOCK_PROCESSJOBRESULT_ASYNC_STATE_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_PROCESSJOBRESULT_ENTRY
/** \brief Entry point of function NvM_WriteBlock_ProcessJobResult() */
#define DBG_NVM_WRITEBLOCK_PROCESSJOBRESULT_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_PROCESSJOBRESULT_EXIT
/** \brief Exit point of function NvM_WriteBlock_ProcessJobResult() */
#define DBG_NVM_WRITEBLOCK_PROCESSJOBRESULT_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_PROCESSREDUNDANTBLOCK_ENTRY
/** \brief Entry point of function NvM_WriteBlock_ProcessRedundantBlock() */
#define DBG_NVM_WRITEBLOCK_PROCESSREDUNDANTBLOCK_ENTRY(a)
#endif

#ifndef DBG_NVM_WRITEBLOCK_PROCESSREDUNDANTBLOCK_EXIT
/** \brief Exit point of function NvM_WriteBlock_ProcessRedundantBlock() */
#define DBG_NVM_WRITEBLOCK_PROCESSREDUNDANTBLOCK_EXIT(a)
#endif

#ifndef DBG_NVM_WRITEBLOCK_REDUNDANTBLOCKERROR_ENTRY
/** \brief Entry point of function NvM_WriteBlock_RedundantBlockError() */
#define DBG_NVM_WRITEBLOCK_REDUNDANTBLOCKERROR_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_REDUNDANTBLOCKERROR_EXIT
/** \brief Exit point of function NvM_WriteBlock_RedundantBlockError() */
#define DBG_NVM_WRITEBLOCK_REDUNDANTBLOCKERROR_EXIT()
#endif

#ifndef DBG_NVM_WRITEBLOCK_VERIFY_ASYNC_STATE_ENTRY
/** \brief Entry point of function NvM_WriteBlock_Verify_Async_State() */
#define DBG_NVM_WRITEBLOCK_VERIFY_ASYNC_STATE_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_VERIFY_ASYNC_STATE_EXIT
/** \brief Exit point of function NvM_WriteBlock_Verify_Async_State() */
#define DBG_NVM_WRITEBLOCK_VERIFY_ASYNC_STATE_EXIT()
#endif

#ifndef DBG_NVM_MEMIFREADTOVERIFY_ENTRY
/** \brief Entry point of function NvM_MemIfReadToVerify() */
#define DBG_NVM_MEMIFREADTOVERIFY_ENTRY()
#endif

#ifndef DBG_NVM_MEMIFREADTOVERIFY_EXIT
/** \brief Exit point of function NvM_MemIfReadToVerify() */
#define DBG_NVM_MEMIFREADTOVERIFY_EXIT()
#endif

#ifndef DBG_NVM_GETVERIFYDATASIZE_ENTRY
/** \brief Entry point of function NvM_GetVerifyDataSize() */
#define DBG_NVM_GETVERIFYDATASIZE_ENTRY()
#endif

#ifndef DBG_NVM_GETVERIFYDATASIZE_EXIT
/** \brief Exit point of function NvM_GetVerifyDataSize() */
#define DBG_NVM_GETVERIFYDATASIZE_EXIT(a)
#endif

#ifndef DBG_NVM_FILLINTERNALBUFFER_ENTRY
/** \brief Entry point of function NvM_FillInternalBuffer() */
#define DBG_NVM_FILLINTERNALBUFFER_ENTRY()
#endif

#ifndef DBG_NVM_FILLINTERNALBUFFER_EXIT
/** \brief Exit point of function NvM_FillInternalBuffer() */
#define DBG_NVM_FILLINTERNALBUFFER_EXIT()
#endif

#ifndef DBG_NVM_PROCESSIMMEDIATEBLOCK_ENTRY
/** \brief Entry point of function NvM_ProcessImmediateBlock */
#define DBG_NVM_PROCESSIMMEDIATEBLOCK_ENTRY()
#endif

#ifndef DBG_NVM_PROCESSIMMEDIATEBLOCK_EXIT
/** \brief Exit point of function NvM_ProcessImmediateBlock */
#define DBG_NVM_PROCESSIMMEDIATEBLOCK_EXIT()
#endif

#ifndef DBG_NVM_ASR40_SETDATAINDEX_ENTRY
/** \brief Entry point of function NvM_ASR40_SetDataIndex */
#define DBG_NVM_ASR40_SETDATAINDEX_ENTRY(a,b)
#endif

#ifndef DBG_NVM_ASR40_SETDATAINDEX_EXIT
/** \brief Exit point of function NvM_ASR40_SetDataIndex */
#define DBG_NVM_ASR40_SETDATAINDEX_EXIT(a,b,c)
#endif

#ifndef DBG_NVM_ASR40_GETDATAINDEX_ENTRY
/** \brief Entry point of function NvM_ASR40_GetDataIndex */
#define DBG_NVM_ASR40_GETDATAINDEX_ENTRY(a,b)
#endif

#ifndef DBG_NVM_ASR40_GETDATAINDEX_EXIT
/** \brief Exit point of function NvM_ASR40_GetDataIndex */
#define DBG_NVM_ASR40_GETDATAINDEX_EXIT(a,b,c)
#endif

#ifndef DBG_NVM_CANCELJOBS_ENTRY
/** \brief Entry point of function NvM_CancelJobs */
#define DBG_NVM_CANCELJOBS_ENTRY(a)
#endif

#ifndef DBG_NVM_CANCELJOBS_EXIT
/** \brief Exit point of function NvM_CancelJobs */
#define DBG_NVM_CANCELJOBS_EXIT(a,b)
#endif

#ifndef DBG_NVM_SETRAMBLOCKSTATUS_ASYNC_CALCCRC_START_ENTRY
/** \brief Entry point of function NvM_SetRamBlockStatus_Async_CalcCrc_Start */
#define DBG_NVM_SETRAMBLOCKSTATUS_ASYNC_CALCCRC_START_ENTRY()
#endif

#ifndef DBG_NVM_SETRAMBLOCKSTATUS_ASYNC_CALCCRC_START_EXIT
/** \brief Exit point of function NvM_SetRamBlockStatus_Async_CalcCrc_Start */
#define DBG_NVM_SETRAMBLOCKSTATUS_ASYNC_CALCCRC_START_EXIT()
#endif

#ifndef DBG_NVM_SETRAMBLOCKSTATUS_ASYNC_CALCCRC_END_ENTRY
/** \brief Entry point of function NvM_SetRamBlockStatus_Async_CalcCrc_End */
#define DBG_NVM_SETRAMBLOCKSTATUS_ASYNC_CALCCRC_END_ENTRY()
#endif

#ifndef DBG_NVM_SETRAMBLOCKSTATUS_ASYNC_CALCCRC_END_EXIT
/** \brief Exit point of function NvM_SetRamBlockStatus_Async_CalcCrc_End */
#define DBG_NVM_SETRAMBLOCKSTATUS_ASYNC_CALCCRC_END_EXIT()
#endif

#ifndef DBG_NVM_INVOKESINGLEBLOCKCALLBACK_ENTRY
/** \brief Entry point of function NvM_InvokeSingleBlockCallback */
#define DBG_NVM_INVOKESINGLEBLOCKCALLBACK_ENTRY()
#endif

#ifndef DBG_NVM_INVOKESINGLEBLOCKCALLBACK_EXIT
/** \brief Exit point of function NvM_InvokeSingleBlockCallback */
#define DBG_NVM_INVOKESINGLEBLOCKCALLBACK_EXIT()
#endif

#ifndef DBG_NVM_QUEUE_INSERTIMMEDIATE_ENTRY
/** \brief Entry point of function NvM_Queue_InsertImmediate */
#define DBG_NVM_QUEUE_INSERTIMMEDIATE_ENTRY(a,b,c)
#endif

#ifndef DBG_NVM_QUEUE_INSERTIMMEDIATE_EXIT
/** \brief Exit point of function NvM_Queue_InsertImmediate */
#define DBG_NVM_QUEUE_INSERTIMMEDIATE_EXIT(a,b,c,d)
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE7_ENTRY
/** \brief Entry point of function NvM_ReadAll_Async_State7 */
#define DBG_NVM_READALL_ASYNC_STATE7_ENTRY()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE7_EXIT
/** \brief Exit point of function NvM_ReadAll_Async_State7 */
#define DBG_NVM_READALL_ASYNC_STATE7_EXIT()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE8_ENTRY
/** \brief Entry point of function NvM_ReadAll_Async_State8 */
#define DBG_NVM_READALL_ASYNC_STATE8_ENTRY()
#endif

#ifndef DBG_NVM_READALL_ASYNC_STATE8_EXIT
/** \brief Exit point of function NvM_ReadAll_Async_State8 */
#define DBG_NVM_READALL_ASYNC_STATE8_EXIT()
#endif

#ifndef DBG_NVM_ASR40_READBLOCK_ENTRY
/** \brief Entry point of function NvM_ASR40_ReadBlock */
#define DBG_NVM_ASR40_READBLOCK_ENTRY(a,b)
#endif

#ifndef DBG_NVM_ASR40_READBLOCK_EXIT
/** \brief Exit point of function NvM_ASR40_ReadBlock */
#define DBG_NVM_ASR40_READBLOCK_EXIT(a,b,c)
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_ENTRY
/** \brief Entry point of function NvM_ReadBlock_Async */
#define DBG_NVM_READBLOCK_ASYNC_ENTRY()
#endif

#ifndef DBG_NVM_READBLOCK_ASYNC_EXIT
/** \brief Exit point of function NvM_ReadBlock_Async */
#define DBG_NVM_READBLOCK_ASYNC_EXIT()
#endif

#ifndef DBG_NVM_STATEMACHINE_WRITEIMMEDIATEBLOCK_ENTRY
/** \brief Entry point of function NvM_StateMachine_WriteImmediateBlock */
#define DBG_NVM_STATEMACHINE_WRITEIMMEDIATEBLOCK_ENTRY()
#endif

#ifndef DBG_NVM_STATEMACHINE_WRITEIMMEDIATEBLOCK_EXIT
/** \brief Exit point of function NvM_StateMachine_WriteImmediateBlock */
#define DBG_NVM_STATEMACHINE_WRITEIMMEDIATEBLOCK_EXIT()
#endif

#ifndef DBG_NVM_PROCESSSTANDARDPRIORITYJOB_ENTRY
/** \brief Entry point of function NvM_ProcessStandardPriorityJob */
#define DBG_NVM_PROCESSSTANDARDPRIORITYJOB_ENTRY()
#endif

#ifndef DBG_NVM_PROCESSSTANDARDPRIORITYJOB_EXIT
/** \brief Exit point of function NvM_ProcessStandardPriorityJob */
#define DBG_NVM_PROCESSSTANDARDPRIORITYJOB_EXIT()
#endif

#ifndef DBG_NVM_ASR40_WRITEBLOCK_ENTRY
/** \brief Entry point of function NvM_ASR40_WriteBlock */
#define DBG_NVM_ASR40_WRITEBLOCK_ENTRY(a,b)
#endif

#ifndef DBG_NVM_ASR40_WRITEBLOCK_EXIT
/** \brief Exit point of function NvM_ASR40_WriteBlock */
#define DBG_NVM_ASR40_WRITEBLOCK_EXIT(a,b,c)
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_ENTRY
/** \brief Entry point of function NvM_WriteBlock_Async */
#define DBG_NVM_WRITEBLOCK_ASYNC_ENTRY()
#endif

#ifndef DBG_NVM_WRITEBLOCK_ASYNC_EXIT
/** \brief Exit point of function NvM_WriteBlock_Async */
#define DBG_NVM_WRITEBLOCK_ASYNC_EXIT()
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

#endif /* (!defined NVM_TRACE_H) */
/*==================[end of file]===========================================*/
