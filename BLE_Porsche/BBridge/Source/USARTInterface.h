/**
 * \addtogroup USARTInterface
 * @{
 *
 * @file 	USARTInterface.h
 * @author	p344575
 * @brief       USART interface for using TI USART spi driver
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * \addtogroup USARTInterface
 *
 * @internal
 * $LastChangedDate: 2018-01-23 13:31:37 +0100 (Di, 23 Jan 2018) $
 * $LastChangedBy: svn_integrationbot $
 * $Revision: 17379 $
 * $Id: USARTInterface.h 17379 2018-01-23 12:31:37Z svn_integrationbot $
 *
 */
#ifndef USARTINTERFACE_H_
#define USARTINTERFACE_H_

#include "typedefs.h"
#define USART_IFF_MAX_BUFF_LEN 76 /* 3xBytes_HDR + 18Bytes*4xPackets_DATA + 1xByte FrameControl*/

extern void USARTInterfaceInit(void);
extern uint8_t USARTInterfacePush(uint8_t data[], uint8_t dataLength );
extern uint8_t USARTInterfaceIsTxComplete(void);
unsigned char USARTInterfaceGetRxByte(unsigned char * byte);


#endif /* USARTINTERFACE_H_ */

/** @}*/
