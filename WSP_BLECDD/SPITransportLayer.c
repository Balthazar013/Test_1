/*----------------------------------------------------------------------------
** Project Name:CAR_36_PAD
** #Archive: 22_BLECDD/SPITransportLayer #
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

#include "SPITransportLayer.h"
//#include "Rte_SCI_BleDrv_Type.h"
#include "string.h"
#include "typedefs.h"

//#define BLE_DEM_EVENT_ID                    85u // TODO: go to Florian Kofler and get a number!

typedef struct 
{
	SPITransportLayerState_t state;
	SPITransportLayerHWInterface_t * hwInterface;
	uint32_t timer;
	uint8_t lastTXFC;
	uint8_t lastRXFC;
	uint8_t txRespBuffer[4];
	uint8_t txRespBufferLength;
	uint8_t txBuffer[SPITransportLayer_BUFFER_SIZE + 4];
	uint8_t txBufferLength;
	uint8_t txBufferProcessed;
	uint8_t rxBuffer[SPITransportLayer_BUFFER_SIZE + 4];
	uint8_t rxBufferLength;
	uint8_t rxBufferFCS;
	uint8_t masterTxComplete;
	uint8_t mode;
} SPITransportLayerAttr_t;

// private functions
static uint8_t pushResponse(const uint8_t * data, uint8_t length);
static uint32_t getSystimeDiff(uint32_t time);

// private variables
static SPITransportLayerAttr_t attr;
t_XCP_SPI_Transport_Layer XCP_SPI_Transport_Layer;


/*This function initializes the SPITransportLayer module*/
void SPITransportLayerInit(HandlingMode_t mode, SPITransportLayerHWInterface_t * hwInterface) 
{
	attr.mode = mode;
	attr.txBufferProcessed = TRUE;
	attr.txBufferLength = 0;
	attr.rxBufferLength = 0;
	attr.lastTXFC = 0xF;
	attr.lastRXFC = 0xF;
	attr.state = SPIHDLR_TXRX;
	attr.hwInterface = hwInterface;
	attr.masterTxComplete = TRUE;
}
/*This function is called from the client once SPI data has been transmitted successfuly*/
void SPITransportLayerOnMasterTXComplete(void) 
{
	attr.masterTxComplete = TRUE;
}

/*This task is called every 1ms from the scheduler. It is a server to the client and performs the following services:
1. Pack and unpack payload data from the client in the proper SPI protocol as specified in BBridge_Transport_Layer_Protocol.pdf
2. Perform hand shakes with the BLE Chip as specified in BBridge_Transport_Layer_Protocol.pdf.  
This server neither accesses the hardware(MCAL) nor the RTE. It only communicates to the client, which is the BLE Chip controller.
*/
void SPITransportLayerWork(void) 
{
	uint8_t tmp, ret, hasNewByte;

XCP_SPI_Transport_Layer.timerStateMachine++;
	switch (attr.state) 
	{		
/****************************************STATE SPIHDLR_TXRX********************************************************/	
	case (SPIHDLR_TXRX):
		/*Check first if there is data from BLE chip to be processed*/
		hasNewByte = (attr.hwInterface->getSPIData(&SPIChar[0],1) == SPI_HAS_DATA);
		if(hasNewByte == TRUE)
		{    attr.rxBufferLength = 0u;

		if(SPIChar[0] == PKT_SOF)
		{
			/*Founf SOF, get the length*/
			attr.hwInterface->getSPIData(&SPIChar[1],1);
			/*Use the length info to get the rest of the info.*/
			attr.hwInterface->getSPIData(&SPIChar[2],(SPIChar[1] + 1));
			/*increment array until SOF is found*/
			for (TransportLayer_p = 0; TransportLayer_p < 79; TransportLayer_p++) // TODO: why this loop this and the following if are the same code as the enclosing if which also checks fro SOF
			{
				if(SPIChar[TransportLayer_p] == PKT_SOF)
				{
					TransportLayer_p++;
					TransportLayer_q = 0;

					attr.rxBufferFCS = 0;
					attr.rxBufferFCS ^= SPIChar[TransportLayer_p];
					attr.rxBufferLength = (uint8_t) (SPIChar[TransportLayer_p++]); //inclrement TransportLayer_p to go to data

					/*Found length, start data copy*/
					for(TransportLayer_q = 0; TransportLayer_q < attr.rxBufferLength; TransportLayer_q++)
					{
						attr.rxBufferFCS ^= SPIChar[TransportLayer_p];
						attr.rxBuffer[TransportLayer_q] = SPIChar[TransportLayer_p++];
					}

					if(SPIChar[TransportLayer_p] == attr.rxBufferFCS)
					{
						/*Reset TransportLayer_p*/
						TransportLayer_p = 0;
						/*Data was received correctly*/

						// checking data type (first payload byte)
						tmp = attr.rxBuffer[0] & PKT_TYPE_MASK;
						if (tmp == PKT_T_DATA)
						{ // received data
							//checking frame counter
							tmp = (attr.rxBuffer[0] & PKT_COUNTER_MASK) >> 4;
							if (((attr.lastRXFC + 1) & 0xF) == tmp) // it a new packet
							{
								// received correct frame counter

								// checking data length received
								if (attr.rxBufferLength > 1) { // the first payload byte is the frame control for retransmission

									// delivering data to upper layer (without FRAME CONTROL byte)
									attr.lastRXFC = tmp; // storing last control received


									attr.state = SPIHDLR_NOTIFY_CLIENT;
									hasNewByte = FALSE;
									attr.timer = attr.hwInterface->getSysTime();
								}

							}
							else
							{
								/*Wrong counter, ignore and return to SPIHDLR_TXRX*/

								hasNewByte = FALSE;
								attr.state = SPIHDLR_NOTIFY_CLIENT;
								attr.timer = attr.hwInterface->getSysTime();
							}

						}
						/*Did not receive data. Either corrupted message or acknowledge which is coming in too late. Ignore and
							return to SPIHDLR_TXRX 
						 */
						else
						{  //Dem_SetEventStatus(BLE_DEM_EVENT_ID, DEM_EVENT_STATUS_FAILED); // TODO: BLE Error code!!! will be activated once we got an event for handling error from the architect
							
							attr.state = SPIHDLR_TXRX;
							hasNewByte = FALSE;
							attr.timer = attr.hwInterface->getSysTime();
						}
					}
					break;
				}
			}
		}
		}
		else
		{
			// Wait for new data to transmit
			/*attr.txBufferProcessed is set to FALSE after SPITransportLayerPushTXData is executed successfuly.
				SPITransportLayerPushTXData is called from the client to push new data
				to the SPI transport layer. SPITransportLayerPushTXData receives payload data and creates and
				SPI package to be transmitted via raw SPI. This data is stored in attr.txBuffer.
				attr.txBufferProcessed is set to TRUE after acknowldge is received from the BLE chip in state 
				SPIHDLR_WAIT_ACK*/
			if (attr.txBufferProcessed == FALSE) // there is data to be transmitted over SPI
			{
				attr.masterTxComplete = FALSE;
				/*Push data to SPI TX buffer*/
				if (attr.hwInterface->setSPIData(&attr.txBuffer[0], attr.txBufferLength) == BB_SUCCESS) 
				{			
					if (attr.masterTxComplete == TRUE) 
					{  tmp = attr.txBuffer[2] & PKT_TYPE_MASK;
					if (tmp == PKT_T_CTRL)
					{
						attr.state = SPIHDLR_WAIT_ACK; 
					}

					else if (tmp == PKT_T_DATA)
					{

						/*attr.txBufferProcessed is set to TRUE to allow new data to be pushed*/
						attr.txBufferProcessed = TRUE;
						/* notify listener that the packet has been transfered*/
						attr.hwInterface->onTxComplete();

						attr.state = SPIHDLR_TXRX;//SPIHDLR_TXRX;





					}
					}

					attr.timer = attr.hwInterface->getSysTime();

				}
			}
		}
		
		
	

	break;
/****************************************STATE SPIHDLR_WAIT_ACK********************************************************/		
	case (SPIHDLR_WAIT_ACK):

		hasNewByte = (attr.hwInterface->getSPIData(&SPIChar[0],1) == SPI_HAS_DATA); // new byte available 
		if(hasNewByte == TRUE)
		{  attr.rxBufferLength =  0;
			if(SPIChar[0] == PKT_SOF)
			{
				/*Founf SOF, get the length*/
				attr.hwInterface->getSPIData(&SPIChar[1],1);
				/*Use the length info to get the rest of the info.*/
				attr.hwInterface->getSPIData(&SPIChar[2],(SPIChar[1] + 1));
				
				XCP_SPI_Transport_Layer.timerState_WAIT_ACK++;
				/*increment array until SOF is found*/
				for (TransportLayer_p = 0; TransportLayer_p < 79; TransportLayer_p++) 
				{				
					if(SPIChar[TransportLayer_p] == PKT_SOF)
					{
						TransportLayer_p++;
						break;
					}
				}
				
				TransportLayer_q = 0;
				attr.rxBufferFCS = 0;
				attr.rxBufferFCS ^= SPIChar[TransportLayer_p];
				attr.rxBufferLength = (uint8_t) (SPIChar[TransportLayer_p++]); //inclrement TransportLayer_p to go to data
				
				/*Found length, start data copy*/
				for(TransportLayer_q = 0; TransportLayer_q < attr.rxBufferLength; TransportLayer_q++)
				{
					attr.rxBufferFCS ^= SPIChar[TransportLayer_p];
					attr.rxBuffer[TransportLayer_q] = SPIChar[TransportLayer_p++];
				}
				
				if(SPIChar[TransportLayer_p] == attr.rxBufferFCS)
				{
					// checking data type (first payload byte)
					tmp = attr.rxBuffer[0] & PKT_TYPE_MASK;
					if(tmp == PKT_T_ACK)
					{
						if( ((attr.rxBuffer[0] >> 4) & 0xF) == ((attr.lastTXFC+1)&0xF))
						{
							attr.lastTXFC =	((attr.lastTXFC+1)&0xF);
							/*attr.txBufferProcessed is set to TRUE to allow new data to be pushed*/
							attr.txBufferProcessed = TRUE; 
							hasNewByte = FALSE;
							/* notify listener that the packet has been transfered*/
							attr.hwInterface->onTxComplete();
							attr.state = SPIHDLR_TXRX;
							attr.timer = attr.hwInterface->getSysTime();
						}
					}
						else if (tmp == PKT_T_DATA) 
					{ // received data
						//checking frame counter
						tmp = (attr.rxBuffer[0] & PKT_COUNTER_MASK) >> 4;
						if ((attr.lastRXFC & 0xF) <= tmp) // TODO: Data does not have to match our counter + 1, just has to be newer than last one
						{
							// received correct frame counter
							// checking data length received
							if (attr.rxBufferLength > 1) 
							{ // the first payload byte is the frame control for retransmission

								// delivering data to upper layer (without FRAME CONTROL byte)
								attr.lastRXFC = tmp; // storing last control received
								attr.state = SPIHDLR_NOTIFY_CLIENT;
								attr.timer = attr.hwInterface->getSysTime();
							} 

						} 
						else
						{
							/*Wrong counter, ignore and return to SPIHDLR_TXRX*/
							//Dem_SetEventStatus(BLE_DEM_EVENT_ID, DEM_EVENT_STATUS_FAILED); // TODO: BLE Error code!!!
							attr.state = SPIHDLR_TXRX;//SPIHDLR_NOTIFY_CLIENT;
							attr.timer = attr.hwInterface->getSysTime();
						}

					} 			
					else if (tmp == PKT_T_CTRL) 
					{ // received data
						//checking frame counter
						tmp = (attr.rxBuffer[0] & PKT_COUNTER_MASK) >> 4;
						if (((attr.lastRXFC + 1) & 0xF) == tmp) 
						{
							// received correct frame counter
							// checking data length received
							if (attr.rxBufferLength > 1) 
							{ // the first payload byte is the frame control for retransmission

								// delivering data to upper layer (without FRAME CONTROL byte)
								attr.lastRXFC = tmp; // storing last control received
								attr.state = SPIHDLR_PUSH_RX_ACK;
								attr.timer = attr.hwInterface->getSysTime();
							} 
							else 
							{
								/*Wrong counter, ignore and return to SPIHDLR_TXRX*/
								attr.state = SPIHDLR_TXRX;
								attr.timer = attr.hwInterface->getSysTime();
							}
						} 
						else // TODO this is bad we have to retransmit our CTRL-Message, because client didn't get it or didn't reply properly
						{
							// checking if this is last (already received)
							if ((attr.lastRXFC & 0xF) == tmp) 
							{
								// retransmit ACK
								attr.state = SPIHDLR_PUSH_RX_ACK; // TODO: Never ok in state SPIHDLR_WAIT_ACK to go to SPIHDLR_PUSH_RX_ACK in case of errors we retransmit message we wait for the ack
								attr.timer = attr.hwInterface->getSysTime();
							}
						}
					}
				}
			}
		}
		else 
		{
			/* ACK timeout */
			if (getSystimeDiff(attr.timer) >= PROTOCOL_TIMEOUT) 
			{
				attr.state = SPIHDLR_TXRX;
				attr.timer = attr.hwInterface->getSysTime();
			}
		}	
		break;


/****************************************STATE SPIHDLR_PUSH_RX_ACK********************************************************/	
	case (SPIHDLR_PUSH_RX_ACK):

		/*Wait 10ms before sending receive ack*/
		//if (getSystimeDiff(attr.timer) <= 10) break;
		tmp = PKT_T_ACK;
		tmp |= (uint8_t) (attr.lastRXFC << 4);
		ret = pushResponse(&tmp, 1);
		XCP_SPI_Transport_Layer.ret_pushResponse = ret;
		if (ret == BB_SUCCESS) 
		{
			attr.masterTxComplete = FALSE;
			// pushing to SPI TX buffer
			XCP_SPI_Transport_Layer.timerState_Push_RX_ACK++;
			if (attr.hwInterface->setSPIData(attr.txRespBuffer, attr.txRespBufferLength) == BB_SUCCESS) 
			{
				if (attr.masterTxComplete == TRUE) 
				{
					attr.state = SPIHDLR_NOTIFY_CLIENT; 
					attr.timer = attr.hwInterface->getSysTime();
				}
			}
			/* ACK timeout */
			if (getSystimeDiff(attr.timer) >= PROTOCOL_TIMEOUT) 
			{
				attr.state = SPIHDLR_TXRX;
				attr.timer = attr.hwInterface->getSysTime();
			}
		}
	break;
/****************************************STATE SPIHDLR_NOTIFY_CLIENT********************************************************/
	case (SPIHDLR_NOTIFY_CLIENT):
			//if (getSystimeDiff(attr.timer) <= 10) break;
			/*Stay here until client is notified*/
			if( (attr.hwInterface->onRxComplete(&attr.rxBuffer[1], (uint8_t) (attr.rxBufferLength - 1)) ) == BB_SUCCESS)
			{
				attr.state = SPIHDLR_TXRX; 
				attr.timer = attr.hwInterface->getSysTime();
			}
	break;
/****************************************STATE default********************************************************/

	default:
		attr.state = SPIHDLR_TXRX;
		break;
	}

}

/**
 * @brief It pushes DATA to be transmitted over SPI
 * @param data
 * @param length
 * @return	0: ok\n
 * 			1: previous buffer not yet processed\n
 * 			2: invalid data length\n
 * 			3: invalid buffer pointer\n
 * 			4: Cannot push yet\n
 */
uint8_t SPITransportLayerPushTXData(const uint8_t * data, uint8_t length,unsigned int  FrameType) 
{
	/*If the existing transmission buffer is not processed yet, no new data shall be accepted*/
	if (attr.txBufferProcessed == FALSE) {
		return 1;
	}
	/*Catch NULL pointer*/
	if (data == NULL) {
		return 3; // invalid data pointer
	}
	/*Check if length is zero or if length is larger than reserved buffer size*/
	if ((length == 0) || (length > (SPITransportLayer_BUFFER_SIZE-4))) {
		return 2;  // wrong data length
	}
	/*Do not accept new data if the SPI Handler is not in state TXRX*/
	if (attr.state != SPIHDLR_TXRX) {
		return 4;
	}
	/*SPI protocol frame is built here as described in BBridge_Transport_Layer_Protocol.pdf page 5
	--------------------------------------------------
	SOF		|	LENGTH	|	CONTROL	|	PAYLOAD			|	Frame Check Sum (FCS)	|
	1 Byte	|	1 Byte	|	1 Byte	| Application Data	|		1 Byte				|
	*/
	attr.txBuffer[0] = PKT_SOF;
	/*LENGTH is added by 2 to include CONTROL byte and FCS byte. The input parameter lenth only includes
	payload length.*/
	attr.txBuffer[1] = (uint8_t) (length + 1);   /*(uint8_t) (length + 2);*/ /*Removed FCS from length*/
	/*The CONTROL byte consists of the follwoing information:
	first 4 bits for the frame counter and last 4 bits for the frame type. In this step, the frame counter 
	is incremented by one*/
	attr.txBuffer[2] = (uint8_t) (((attr.lastTXFC + 1) & 0xF) << 4);
	/*In this step, the frame type is set to packet data*/
	attr.txBuffer[2] |= FrameType;
	/*Data payload is copied to the PAYLOAD section of attr.txBuffer.*/
	memcpy(&attr.txBuffer[3], data, length);
	/*The function SPITransportLayerCalcFCS is called to calculate the checksum including length byte*/
	attr.txBuffer[length + 3] = SPITransportLayerCalcFCS(&attr.txBuffer[1], (uint8_t) (length + 2));
	/*Input parameter length is added by 4 to include SOF, LENGTH, CONTROL and FCS*/
	attr.txBufferLength = (uint8_t) (length + 4); 
	/* Telling the state machine that there is a new TX buffer to be sent*/
	attr.txBufferProcessed = FALSE;
	/*Return BB_SUCCESS to notify that data package has been prepared for raw SPI transfer*/
	return BB_SUCCESS;

}

/**
 * @brief It shall be used to push ACK and NACK to be transmitted
 * @param data
 * @param length
 * @return	0: pushed ok\n
 * 			1: invalid data pointer\n
 * 			2: wrong fata length\n
 */
/*Acknowledge frame is built here as described in BBridge_Transport_Layer_Protocol.pdf page 5&6
--------------------------------------------------
SOF		|	LENGTH	|	CONTROL	|	Frame Check Sum (FCS)	|
1 Byte	|	1 Byte	|	1 Byte	| 	1 Byte					|
*/
 static uint8_t pushResponse(const uint8_t * data, uint8_t length) 
 {
	if (data == 0) 
	{
		return 1; // invalid data pointer
	}
	if ((length == 0) || (length > (SPITransportLayer_BUFFER_SIZE))) 
	{
		return 2;  // wrong data length
	}
	attr.txRespBuffer[0] = PKT_SOF;
	attr.txRespBuffer[1] = 1; //Removed FCS from length
	attr.txRespBuffer[2] = data[0];
	// calculating checksum  LENGTH byte and CONTROL byte
	attr.txRespBuffer[3] = SPITransportLayerCalcFCS(&attr.txRespBuffer[1], 2);
	attr.txRespBufferLength = 4; 
	return 0;
}

/**
 * @brief Calculating Frame Check Sum for the SPI transmission
 * @param payload array
 * @param payloadLength
 * @return XORed bytes
 */
uint8_t SPITransportLayerCalcFCS(const uint8_t * payload, uint8_t payloadLength) 
{
	uint8_t i = 0;
	uint8_t fcs = 0;
	while (i < payloadLength) 
	{
		fcs ^= payload[i++];
	}
	return fcs;
}

static uint32_t getSystimeDiff(uint32_t time) 
{
	return attr.hwInterface->getSysTime() - time;
}

/** @}*/

