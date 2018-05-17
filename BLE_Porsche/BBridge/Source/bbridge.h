/**************************************************************************************
* @file    bridge.h
* @brief : BBridge interface to integrate with the OSAL from TI
* $Id: bbridge.h 17313 2018-01-19 15:57:14Z ewaboh $
* @author : A. Perico
 ***************************************************************************************
 * @copyright
 *
 * <h2><center>&copy; COPYRIGHT 2016 Porsche Engineering Services GmbH</center></h2>
 ***************************************************************************************/
#ifndef BBRIDGE_H
#define BBRIDGE_H

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * Task Initialization for the BLE Application
 */
extern void BBridgeBT_Init( uint8 task_id );

/*
 * Task Event Processor for the BLE Application
 */
extern uint16 BBridgeBT_ProcessEvent( uint8 task_id, uint16 events );


#ifdef __cplusplus
}
#endif

#endif /* BBRIDGE_H */
