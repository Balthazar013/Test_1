/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/
#include <Dem.h>

/*==================[macros]=================================================*/

/** \brief This macro can be used to avoid compiler warnings */
#define DEM_TEMP_PARAM_UNUSED(x) ((void) (x))

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define DEM_START_SEC_CODE
#include <MemMap.h>


/*============================================================================
function name    :  APL_DEH_ReadAddFF()
input parameter  :   RecordNumber_uT: RecordNumber
                     BuffSize_u8     : size of destination buffer for snapshot records
                     EventNumber_u16 : Event Number
                     pNumOfBytes_u8 : pointer to a value for a number of copied bytes
                     pDestBuffer_u8 : pointer to destination buffer
output parameter :  -
globals          :  -
return value     :  tDEH_Return
description      :  read addional freeze frames from system.
                    This function is implemented in Dem_Int.c if
                    DemDidInterfaceType is set to DEM_DEH_FUNCTION.
============================================================================*/
tDEH_Return APL_DEH_ReadAddFF
(
  tDEH_RecordNumber        RecordNumber_uT,
  uint8_t                  BuffSize_u8,
  uint16_t                 EventNumber_u16,
  uint8_t                 *pNumOfBytes_u8,
  uint8_t                 *pAddFFrame_u8
)
{
  DEM_TEMP_PARAM_UNUSED(RecordNumber_uT);
  DEM_TEMP_PARAM_UNUSED(BuffSize_u8);
  DEM_TEMP_PARAM_UNUSED(EventNumber_u16);
  DEM_TEMP_PARAM_UNUSED(pNumOfBytes_u8);
  DEM_TEMP_PARAM_UNUSED(pAddFFrame_u8);

  /* implement your code here
  */

  return DEH_OK;
}


/*============================================================================
function name    :  APL_DEH_ReadUnlearnCounter()
input parameter  : -
output parameter :  -
globals          :  -
return value     :  tDEH_Return
description      :  read addional freeze frames from system.
                    This function is implemented in Dem_Int.c if
                    DemAgingCycleCounterProcessing is set to DEM_PROCESS_AGINGCTR_EXTERN.
============================================================================*/
#if (DEM_USE_SET_AGING_COUNTER_API != STD_ON)
uint8_t APL_DEH_ReadUnlearnCounter
(
  void
)
{
  return 0xFFU;
}
#endif /* DEM_USE_SET_AGING_COUNTER_API != STD_ON */

#ifdef DEH_SUP_SNAP_SHOT_DATA
/* ============================================================================
function name    :   APL_DEH_SnapShotDatenInit()
input parameter  :   mode_u8  : current special mode of DEH
output parameter :
globals          :
return value     :   no
description      :   Function to inform the application about special DEH states
============================================================================ */
void APL_DEH_SnapShotDatenInit
(
  uint8_t mode_u8
)
{
  DEM_TEMP_PARAM_UNUSED( mode_u8 );

  return;
}


/*============================================================================
function name    :   APL_DEH_ReadDTCSnapshotRecord()
input parameter  :   DTC_uT          : DTC to read the snapshot records
                     BuffSize_u16    : size of destination buffer for snapshot records
                     pNumOfBytes_u16 : pointer to a value for a number of copied bytes
                     pDestBuffer_u8  : pointer to destination buffer
output parameter :
globals          :
return value     :   tDEH_Return
description      :   Function to read stored snapshot records for a DTC.
============================================================================*/
tDEH_Return APL_DEH_ReadDTCSnapshotRecord
(
  tDEH_DTC DTC_uT,
  uint16_t BuffSize_u16,
  uint16_t *pNumOfBytes_u16,
  uint8_t *pDestBuffer_u8
)
{
  tDEH_Return retVal = DEH_OK;

  DEM_TEMP_PARAM_UNUSED( DTC_uT );
  DEM_TEMP_PARAM_UNUSED( BuffSize_u16 );
  DEM_TEMP_PARAM_UNUSED( pNumOfBytes_u16 );
  DEM_TEMP_PARAM_UNUSED( pDestBuffer_u8 );

  return (retVal);
}
#endif


/*============================================================================
function name    :   APL_DEH_RequestReportEvent()
input parameter  :   Report_Event_Parameter : parameter of event to report
output parameter :
globals          :
return value     :
description      :   Function to report different events
                     (I):   event momory cleared
                     (II):  event memory activated by DEH_ControlDTCSetting
============================================================================*/
#ifdef DEH_SUP_REQUEST_REPORT_EV
void APL_DEH_RequestReportEvent
(
  uint8_t Report_Event_Parameter
)
{
  DEM_TEMP_PARAM_UNUSED( Report_Event_Parameter );

  return;
}
#endif









#define DEM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/** @} doxygen end group definition  */
/*==================[end of file]============================================*/

