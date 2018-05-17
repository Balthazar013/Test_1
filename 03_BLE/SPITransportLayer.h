/*----------------------------------------------------------------------------
** Project Name:CAR_36_ORU
** #Archive: 20_CDD/BLE/SPITransportLayer #
** #Author: Reiner Bogenfuerst#
** #Date: 2016-06-28#
** (c) Copyright 2015, Bombardier Primove GmbH
**----------------------------------------------------------------------------
** #Revision: #
**----------------------------------------------------------------------------
** Target system: Freescale MPC5744P
** Compiler:GHS
** Description: Bluetooth Low Energy Complex Device Driver
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    -------------------------------------
** RBOGENFU   Reiner Bogenfuerst    Bombardier Primove GmbH
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log: #
**--------------------------------------------------------------------------*/


#ifndef SPITRANSPORTLAYER_H_
#define SPITRANSPORTLAYER_H_

#include "typedefs.h"

#ifndef SPI_HAS_DATA
#define SPI_HAS_DATA 0xFAu
#endif

#ifndef SPI_SENT_DATA
#define SPI_SENT_DATA 0xACu
#endif

#ifndef PKT_SLAVE_READ
#define PKT_SLAVE_READ 0xABu
#endif


#define PKT_REJECT 			0x55u
#define PKT_SOF 			0xFEu
#define PKT_T_ACK 			1u
#define PKT_T_NACK 			2u
#define PKT_T_DATA 			3u
#define PKT_COUNTER_MASK 	0xF0u
#define PKT_TYPE_MASK 		0x0Fu
#define PROTOCOL_TIMEOUT 	300 // milliseconds
#define SPITransportLayer_BUFFER_SIZE  200

/*Static variables for XCP debugging*/

typedef struct 
{
	uint32_t timerStateMachine;
	uint32_t timerState_Push_RX_ACK;
	uint8_t ret_pushResponse;
	uint32_t timerState_WAIT_ACK;
	uint32_t timerState_WAIT_TX;
	uint32_t timerState_WAIT_TO_RTX;
	uint32_t timerState_RetransmittData;
}
t_XCP_SPI_Transport_Layer;

/***********************************/




/**********New vars for code modification************/
static uint8_t SPIChar[100]; //41 is for MAX_SPI_TX_LENGTH
static uint8_t TransportLayer_p = 0;
static uint8_t TransportLayer_temp = 0;
static uint8_t TransportLayer_q = 0;
/************************/

typedef enum {
	HDLR_SLAVE, HDLR_MASTER
} HandlingMode_t;


typedef struct{
	DataExchangeFncGet32 getSysTime;
	BBGenericCB_t onTxComplete;
	DataExchangeFnc2 onRxComplete;
	DataExchangeFnc setSPIData;
	BBUCharUCharPtr_t getSPIData;
} SPITransportLayerHWInterface_t;


typedef enum {
	SPIHDLR_TXRX=0,
	SPIHDLR_PUSH_RX_ACK=1,
	SPIHDLR_WAIT_ACK=2,
	SPIHDLR_PUSH_NACK=3,
	SPIHDLR_PUSH_RX_NACK=4,
	SPIHDLR_RETX_ACK=5,
	SPIHDLR_NOTIFY_CLIENT=6,
} SPITransportLayerState_t;


extern void SPITransportLayerWork(void);
extern void SPITransportLayerInit(HandlingMode_t mode, SPITransportLayerHWInterface_t * hwInterface);
extern void SPITransportLayerOnMasterTXComplete(void);
extern uint8_t SPITransportLayerPushTXData(const uint8_t * data, uint8_t length);
extern uint8_t SPITransportLayerCalcFCS(const uint8_t * payload, uint8_t payloadLength);


#endif /* SPITRANSPORTLAYER_H_ */

/** @}*/

