/**************************************************************************************
* @file    OSAL_BBridge.c
* @brief : Task definition and initialization (complaining with TI OSAL) system
* $Id: OSAL_BBridge.c 17313 2018-01-19 15:57:14Z ewaboh $
* @author : A. Perico
 ***************************************************************************************
 * @copyright
 *
 * <h2><center>&copy; COPYRIGHT 2016 Porsche Engineering Services GmbH</center></h2>
 ***************************************************************************************/

#include "hal_types.h"
#include "OSAL.h"
#include "OSAL_Tasks.h"

/* HAL */
#include "hal_drivers.h"

/* LL */
#include "ll.h"

/* HCI */
#include "hci_tl.h"

#if defined ( OSAL_CBTIMER_NUM_TASKS )
  #include "osal_cbtimer.h"
#endif

/* L2CAP */
#include "l2cap.h"

/* gap */
#include "gap.h"
#include "gapgattserver.h"
#include "gapbondmgr.h"

/* GATT */
#include "gatt.h"

#include "gattservapp.h"

/* Profiles */
#include "peripheral.h"
#include "central.h"
#include "bbridge.h"


// The order in this table must be identical to the task initialization calls below in osalInitTask.
const pTaskEventHandlerFn tasksArr[] =
{
  LL_ProcessEvent,                                                  // task 0
  Hal_ProcessEvent,                                                 // task 1
  HCI_ProcessEvent,                                                 // task 2
#if defined ( OSAL_CBTIMER_NUM_TASKS )
  OSAL_CBTIMER_PROCESS_EVENT( osal_CbTimerProcessEvent ),           // task 3
#endif
  L2CAP_ProcessEvent,                                               // task 4
  GAP_ProcessEvent,                                                 // task 5
  SM_ProcessEvent,                                                  // task 6
  GATT_ProcessEvent,                                                // task 7
#ifdef TARGET_ORU
  GAPCentralRole_ProcessEvent,                                      // task 8 (ORU)
#else
  GAPRole_ProcessEvent,                                             // task 8 (PAD)
#endif
  GAPBondMgr_ProcessEvent,                                          // task 9
  GATTServApp_ProcessEvent,                                         // task 10
  
  BBridgeBT_ProcessEvent                                            // task 11
};

const uint8 tasksCnt = sizeof( tasksArr ) / sizeof( tasksArr[0] );
uint16 *tasksEvents;

/*********************************************************************
 * FUNCTIONS
 *********************************************************************/

/*********************************************************************
 * @fn      osalInitTasks
 *
 * @brief   This function invokes the initialization function for each task.
 *
 * @param   void
 *
 * @return  none
 */
void osalInitTasks( void )
{
  uint8 taskID = 0;

  tasksEvents = (uint16 *)osal_mem_alloc( sizeof( uint16 ) * tasksCnt);
  osal_memset( tasksEvents, 0, (sizeof( uint16 ) * tasksCnt));

  /* LL Task */
  LL_Init( taskID++ );

  /* Hal Task */
  Hal_Init( taskID++ );

  /* HCI Task */
  HCI_Init( taskID++ );

#if defined ( OSAL_CBTIMER_NUM_TASKS )
  /* Callback Timer Tasks */
  osal_CbTimerInit( taskID );
  taskID += OSAL_CBTIMER_NUM_TASKS;
#endif

  /* L2CAP Task */
  L2CAP_Init( taskID++ );

  /* GAP Task */
  GAP_Init( taskID++ );

  /* SM Task */
  SM_Init( taskID++ );
  
  /* GATT Task */
  GATT_Init( taskID++ );

  /* Profiles */
#ifdef TARGET_ORU
  GAPCentralRole_Init( taskID++ );
#else
  GAPRole_Init( taskID++ );
#endif

  GAPBondMgr_Init( taskID++ );

  GATTServApp_Init( taskID++ );

  /* Application */
  BBridgeBT_Init( taskID );
}

/*********************************************************************
*********************************************************************/
