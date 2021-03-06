
/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /*
  * This file contains an Rte component template / example code
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.75
  * on Fri Feb 09 11:09:51 CET 2018. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

#include "Rte_WsConf.h"

/*------------------------[runnable entity skeletons]------------------------*/

void ConfSwc_Conf_10ms (void)
{
  Dem_EventStatusType EventStatus;
  uint8 Status_0;
  unsigned char Data_0[128];
  uint16 Index_0;
  uint8 Status;
  uint8 Data;
  uint16 Index;
  P2VAR(NvmZMPos, AUTOMATIC, AUTOMATIC) ZMPos_0;
  NvmZMPos ZMPos;
  Std_ReturnType status;

  Rte_IWrite_Conf_10ms_ConfZMPos_ZMPos(&ZMPos);

  ZMPos_0 = Rte_IWriteRef_Conf_10ms_ConfZMPos_ZMPos();

  status = Rte_Call_NvmExtServ_NvmExt_Read(Index, &Data, &Status);

  status = Rte_Call_NvmExtServ_NvmExt_Write(Index_0, Data_0, &Status_0);

  status = Rte_Call_Event_FOD_NULL_VECTOR_INVALID_SetEventStatus(EventStatus);

}

Std_ReturnType WsConf_PNJobFinished_NvBlockNeeds (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvM_BLE_Name (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvM_BleCommTimeout (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvM_BleScanTimeout (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvM_DeviceSleepTimeout (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvM_ResetsNumber (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvmBlock_Zmover_Pos (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvmBlock_NullVectorValid (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvM_BleDevFilterName (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvM_BleDefaultRole (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType WsConf_PNJobFinished_NvM_BleDriverLoc (uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType status;

  return status;
}

void WsConf_GetBleDefaultRole (P2VAR(BleDefaultRole, AUTOMATIC, RTE_APPL_DATA) BleDefaultRole)
{
  Std_ReturnType status;

}

void WsConf_GetBleDriverLoc (P2VAR(BleDriverLoc, AUTOMATIC, RTE_APPL_DATA) BleDriverLoc)
{
  Std_ReturnType status;

}

void WsConf_GetBleName (P2VAR(BleName, AUTOMATIC, RTE_APPL_DATA) BleName)
{
  Std_ReturnType status;

}

void WsConf_GetBleCommTO (P2VAR(NvmBleTO, AUTOMATIC, RTE_APPL_DATA) BleCommTO)
{
  Std_ReturnType status;

}

void WsConf_GetBleDeviceSleepTO (P2VAR(NvmBleTO, AUTOMATIC, RTE_APPL_DATA) BleDeviceSleepTO)
{
  Std_ReturnType status;

}

void WsConf_GetBleScanTO (P2VAR(NvmBleTO, AUTOMATIC, RTE_APPL_DATA) BleScanTO)
{
  Std_ReturnType status;

}

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------

  ------------------------[per instance memory API]--------------------------

*/
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

