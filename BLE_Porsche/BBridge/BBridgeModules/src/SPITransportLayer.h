/**
 * \addtogroup SPITransportLayer
 * @{
 *
 * @file 	SPITransportLayer.h
 * @author	p344575
 * @brief	Upper layer implementation of the SPI communication. It
 * ensures that the communication over SPI is reliable by checking the
 * data received and acknowledging it to the sender.
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2018-01-23 13:31:37 +0100 (Di, 23 Jan 2018) $
 * $LastChangedBy: svn_integrationbot $
 * $Revision: 17379 $
 * $Id: SPITransportLayer.h 17379 2018-01-23 12:31:37Z svn_integrationbot $
 *
 */

#ifndef SPITRANSPORTLAYER_H_
#define SPITRANSPORTLAYER_H_

#include "typedefs.h"

#ifndef SPI_HAS_DATA
#define SPI_HAS_DATA 0xFAu
#endif

#ifndef PKT_SLAVE_READ
#define PKT_SLAVE_READ 0xABu
#endif


#define PKT_T_ACK           1u
#define PKT_T_DATA          3u
#define PKT_T_CTRL          5u
#define PKT_COUNTER_MASK    0xF0u
#define PKT_TYPE_MASK       0x0Fu
#define PROTOCOL_TIMEOUT    30u /* milliseconds*/

#ifndef PROTOCOL_MAX_LEN
#define PROTOCOL_MAX_LEN    76 /* 3xBytes_HDR + 18Bytes*4xPackets_DATA + 1xByte FrameControl*/
#endif

#define PROTOCOL_MAX_PAYLOAD_LEN PROTOCOL_MAX_LEN-1u /* extra control byte */

typedef enum
{
    SPITRNSP_SOF = 0,
    SPITRNSP_FCTL,
    SPITRNSP_LEN,
    SPITRNSP_DATA,
    SPITRNSP_FCS,
    SPITRNSP_DATA_OK,
    SPITRNSP_INVALID
} FrameParserState_t;

typedef struct
{
    DataExchangeFncGet32 getSysTime;
    BBGenericCB_t onTxComplete;
    DataExchangeFncVoid onRxComplete;
    DataExchangeNConstFnc spiPush;
    BBCharCB_t spiTxComplete;
    BBUCharUCharPtr_t spiGetRxByte;
} SPITransportLayerHWInterface_t;

typedef enum
{
    SPIHDLR_IDLE=0,
    SPIHDLR_WAIT_TX,
    SPIHDLR_WAIT_TO_RTX,
    SPIHDLR_RETRANSMIT_DATA,
    SPIHDLR_PUSH_RX_ACK,
    SPIHDLR_WAIT_ACK,
    SPIHDLR_RETX_ACK
} SPITransportLayerState_t;

extern void SPITransportLayerWork(void);
extern void SPITransportLayerInit(SPITransportLayerHWInterface_t * hwInterface);
extern uint8_t SPITransportLayerPushTXData(const uint8_t data[], uint8_t length);
extern void RxfcTxfcReset();

#ifdef TESTENVIRONMENT
extern SPITransportLayerState_t * SPITransportLayer_GetState(void);
extern FrameParserState_t * SPITransportLayer_GetReadState(void);
extern uint8_t SPITransportLayerGetTXData(uint8_t data[], uint8_t * length);
#endif

#endif /* SPITRANSPORTLAYER_H_ */

/** @}*/
