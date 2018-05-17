/**
 * \addtogroup DataHandler
 * @{
 *
 * @file 	DataHandler.h
 * @author	p344575
 * @brief 	It handles the business logics for the commands, events and responses
 * between the BBridge and the Panther applications. It ensures that the Panther
 * and the BBridge communicates uses the protocol "command->ack", thus, the
 * Panther cannot send the next command until the previous has not yet been
 * acknowledged.
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * $Revision: 18134 $
 * $Id: DataHandler.h 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */

#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

#include "typedefs.h"

/**
 * @brief Maximum messages received from bluetooth that can be buffered
 */
#define DHDLR_RX_EXT_BUFFER_SIZE 2u

/**
 * @brief DataHandler states
 * @note this struct has been made public so it can be used during testing
 */
typedef enum {
	DH_IDLE = 0,
	DH_PROCESS_DATA2PANTHER,
	DH_DATAFROMPANTHER_WAIT_RELEASE,
	DH_PROCESS_EXTERNAL,
	DH_WAIT_TX_COMPLETE
} DataHandler_State_t;

extern uint8_t DataHandler_Init(BBGenericCB_t onBBridgeToPantherTx,
		DataExchangeFnc dataToPantherSender);

extern uint8_t DataHandler_PushIntDataToPanther(const uint8_t * data, uint8_t length);
extern uint8_t DataHandler_PushExtDataToPanther(BBridgeCommPacket_t *psBrdgComPaket);
extern uint8_t DataHandler_OnRxDataFromPanther(const uint8_t * data, uint8_t length);
extern void DataHandler_OnTxDataToPantherComplete(void);
extern uint8_t DataHandler_HasDataFromPanther(void);
extern uint8_t DataHandler_IsDataFromPantherProcessed(void);
extern uint8_t DataHandler_GetRxDataFromPanther(uint8_t * data, uint8_t * length);
extern void DataHandler_RxDataFromPantherProcessed(void);
extern void DataHandler_Work(void);

#ifdef TESTENVIRONMENT
extern void DataHandler_Destroy(void);
extern const DataHandler_State_t * DataHandler_GetState(void);
#endif

#endif /* DATAHANDLER_H_ */

/** @}*/
