/**
 * \file
 *
 * \brief AUTOSAR MemIf
 *
 * This file contains the implementation of the AUTOSAR
 * module MemIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H

/*==================[includes]==============================================*/

/* !LINKSTO MemIf037,1 */
#include <Std_Types.h>                            /* AUTOSAR standard types     */
#include <TSAutosar.h>                            /* EB specific standard types */

/* include lower layer headers */
#include <Fee.h>

/*==================[macros]================================================*/

/** \brief En-/disable development error tracer checks */
#define MEMIF_DEV_ERROR_DETECT   STD_ON

/** \brief Number of the underlying memory abstraction modules
 **
 ** 0 Ea and 1 Fee */
#define MEMIF_NUMBER_OF_DEVICES  1U

/** \brief En-/disable API version information */
#define MEMIF_VERSION_INFO_API   STD_ON

/* !LINKSTO MemIf019,1 */
/* Macro mappings of driver API calls */

#define MemIf_Read(DeviceIndex, BlockNumber, BlockOffset, DataBufferPtr, Length) \
  (TS_PARAM_UNUSED(DeviceIndex),Fee_Read(BlockNumber, BlockOffset, DataBufferPtr, Length))

#define MemIf_Write(DeviceIndex, BlockNumber, DataBufferPtr) \
  (TS_PARAM_UNUSED(DeviceIndex),Fee_Write(BlockNumber, DataBufferPtr))

#define MemIf_Cancel(DeviceIndex) \
  (TS_PARAM_UNUSED(DeviceIndex),Fee_Cancel())

#define MemIf_GetStatus(DeviceIndex) \
  (TS_PARAM_UNUSED(DeviceIndex),Fee_GetStatus())

#define MemIf_GetJobResult(DeviceIndex) \
  (TS_PARAM_UNUSED(DeviceIndex),Fee_GetJobResult())

#define MemIf_InvalidateBlock(DeviceIndex, BlockNumber) \
  (TS_PARAM_UNUSED(DeviceIndex),Fee_InvalidateBlock(BlockNumber))

#define MemIf_EraseImmediateBlock(DeviceIndex, BlockNumber) \
  (TS_PARAM_UNUSED(DeviceIndex),Fee_EraseImmediateBlock(BlockNumber))

#define MemIf_SetMode(Mode) \
  Fee_SetMode(Mode)

/* !LINKSTO MemIf020,1 */

/*==================[type definitions]======================================*/

/*==================[external data]=========================================*/

#endif /* ifndef MEMIF_CFG_H */
/*==================[end of file]===========================================*/
