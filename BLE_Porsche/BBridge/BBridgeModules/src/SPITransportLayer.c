/**
 * \addtogroup SPITransportLayer
 * @{
 *
 * @file 	SPITransportLayer.c
 * @author	p344575
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2018-01-23 13:31:37 +0100 (Di, 23 Jan 2018) $
 * $LastChangedBy: svn_integrationbot $
 * $Revision: 17379 $
 * $Id: SPITransportLayer.c 17379 2018-01-23 12:31:37Z svn_integrationbot $
 *
 */

#include "SPITransportLayer.h"
#include "string.h"
#include "typedefs.h"

typedef struct
{
    SPITransportLayerState_t state;
    SPITransportLayerState_t prevState;
    SPITransportLayerState_t nextState;
    uint32_t timer;
    uint8_t lastTXFC;
    uint8_t lastRXFC;
    uint8_t txRespBuffer[4];
    uint8_t txRespBufferLength;
    uint8_t txRespBufferProcessed;
    uint8_t txBuffer[PROTOCOL_MAX_LEN];
    uint8_t txBufferLength;
    uint8_t txBufferProcessed;
    uint8_t rxBuffer[PROTOCOL_MAX_LEN];
    uint8_t rxBufferLength;
    uint8_t rxBufferCounter;
    SPITransportLayerHWInterface_t * hwInterface;
} SPITransportLayerAttr_t;

/* private functions*/
static uint32_t getSystimeDiff(uint32_t time);

/* private variables*/
static SPITransportLayerAttr_t attr;

/**
 * @brief It initializes the SPITransportLayer module
 * @param mode
 */
void SPITransportLayerInit(SPITransportLayerHWInterface_t * hwInterface)
{
    attr.txBufferProcessed = TRUE;
    attr.txBufferLength = 0u;
    attr.rxBufferLength = 0u;
    attr.lastTXFC = 0xFu;
    attr.lastRXFC = 0xFu;
    attr.state = SPIHDLR_IDLE;
    attr.prevState = SPIHDLR_IDLE;
    attr.hwInterface = hwInterface;
}

void RxfcTxfcReset()
{
    attr.lastTXFC = 0xFu;
    attr.lastRXFC = 0xFu;
}

/**
 * @brief It processes SPI receive and SPI transmit as a serial interface.
 * This implementation does not allow for "duplex" communication.
 */
void SPITransportLayerWork(void) 
{
    uint8_t tmp, lastSPIChar, hasNewData;
    
    switch (attr.state) 
    {
        case (SPIHDLR_IDLE):
        {
            if (attr.txBufferProcessed == FALSE)
            {
                /*There is new data to be sent over SPI (buffer not yet processed)*/
                /* Pushing data to SPI TX buffer*/
                if (attr.hwInterface->spiPush(&attr.txBuffer[0], attr.txBufferLength) == BB_SUCCESS)
                {
                    /* allowing new data to be pushed*/
                    attr.txBufferProcessed = TRUE; 
                    
                    /* notify listener that the packet has been transfered*/
                    attr.hwInterface->onTxComplete();
                    attr.state = SPIHDLR_WAIT_TX;
                    attr.nextState = SPIHDLR_IDLE;
                    attr.timer = attr.hwInterface->getSysTime();
                    attr.rxBufferLength = 0u;
                    attr.rxBufferCounter = 0u;
                }
            }
            else
            {
                /* checking whether SPI got new data to be processed*/
                attr.rxBufferLength = 0u;
                attr.rxBufferCounter = 0u;
                hasNewData = FALSE;
                while ((attr.hwInterface->spiGetRxByte(&lastSPIChar) == SPI_HAS_DATA)?TRUE:FALSE)
                {
                    attr.rxBuffer[attr.rxBufferLength++] = lastSPIChar;
                    hasNewData = TRUE;
                }
                
                if (hasNewData == TRUE)
                {
                    attr.timer = attr.hwInterface->getSysTime();
                    tmp = attr.rxBuffer[0] & PKT_TYPE_MASK;
                    
                    if (tmp == PKT_T_CTRL)  /* received CTRL*/
                    {
                        /*checking frame counter*/
                        tmp = (attr.rxBuffer[0] & PKT_COUNTER_MASK) >> 4;
                        if (((attr.lastRXFC + 1u) & 0xFu) == tmp)
                        {
                            /* received correct frame counter*/
                            /* checking data length received*/
                            if (attr.rxBufferLength > 1u) /* the first payload byte is the frame control for retransmission*/
                            {
                                /* delivering data to upper layer (without FRAME CONTROL byte)*/
                                attr.lastRXFC = tmp; /* storing last control received*/
                                /* making sure the frame parser is reset*/
                                attr.state = SPIHDLR_PUSH_RX_ACK;
                                hasNewData = FALSE; /* breaking out while in case there is still more data to be processed */
                            }
                            else
                            {
                                /* invalid data received (wrong counter)*/
                            }
                        }
                        else
                        {
                            /* checking if this is last (already received)*/
                            if ((attr.lastRXFC & 0xFu) == tmp) 
                            {
                                /* retransmit ACK*/
                                attr.state = SPIHDLR_PUSH_RX_ACK;
                                hasNewData = FALSE; /* breaking out while in case there is still more data to be processed */
                            }
                            else
                            {
                                /* Release an error and synchronize again */
                                attr.lastRXFC = tmp;
                            }
                        }
                    }
                    else  if (tmp == PKT_T_DATA) /* received data*/
                    {
                        /*checking frame counter*/
                        tmp = (attr.rxBuffer[0] & PKT_COUNTER_MASK) >> 4;
                        if (((attr.lastRXFC + 1u) & 0xFu) <= tmp)  // TODO (attr.lastRXFC + 1u) & 0xFu) < tmp)
                        {
                            /* received correct frame counter*/
                            /* checking data length received*/
                            if (attr.rxBufferLength > 1u) /* the first payload byte is the frame control for retransmission*/
                            {
                                //notifying upper layer
                                /* delivering data to upper layer (without FRAME CONTROL byte)*/
                                attr.lastRXFC = tmp; /* storing last control received*/
                                /* making sure the frame parser is reset*/
                                /* notifying transport layers's listener that new valid data has been received */
                                hasNewData = FALSE; /* breaking out while in case there is still more data to be processed */
                                attr.state = SPIHDLR_IDLE ;
                                attr.hwInterface->onTxComplete();
                                attr.hwInterface->onRxComplete(&attr.rxBuffer[1], (attr.rxBufferLength - 1u)); /* 2=1_FRAME control + 1_FCS*/
                                attr.timer = attr.hwInterface->getSysTime();
                            }
                        }
                        else 
                        {
                            if ((attr.lastRXFC & 0xFu) == tmp)
                            {
                                /* retransmit ACK*/
                                attr.state = SPIHDLR_IDLE ;
                                attr.hwInterface->onTxComplete();
                                attr.hwInterface->onRxComplete(&attr.rxBuffer[1], (attr.rxBufferLength - 1u)); /* 2=1_FRAME control + 1_FCS*/
                                hasNewData = FALSE; /* breaking out while in case there is still more data to be processed */
                                attr.timer = attr.hwInterface->getSysTime();
                            }
                            /* invalid data received (wrong counter)*/
                            else
                            {
                                /* Release an error and synchronize again */
                                attr.lastRXFC = tmp;
                            }
                        }
                    }
                    else
                    {
                        /* received something else than data and CTRL*/
                    }
                }
            }
            break;
        }
        
        case (SPIHDLR_PUSH_RX_ACK):
        {
            /* setting buffers to processed*/
            attr.txBufferProcessed = TRUE;
            attr.txRespBufferProcessed = TRUE;
            
            tmp = PKT_T_ACK;
            tmp |= (uint8_t) (attr.lastRXFC << 4u);
            
            attr.txRespBuffer[0] = tmp;
            attr.txRespBufferLength = 1u;
            
            /* pushing to SPI TX buffer*/
            if (attr.hwInterface->spiPush(attr.txRespBuffer, attr.txRespBufferLength) == BB_SUCCESS)
            {
                attr.state = SPIHDLR_WAIT_TX;
                attr.nextState = SPIHDLR_IDLE;
                
                /* notifying transport layers's listener that new valid data has been received */
                // TODO: Remove we don't have this case anymore... no CTRL via BLE
                if (((attr.rxBuffer[0] & PKT_COUNTER_MASK) >> 4) == attr.lastRXFC)
                {
                    attr.hwInterface->onRxComplete(&attr.rxBuffer[1], (attr.rxBufferLength - 1u)); /* 2=1_FRAME control + 1_FCS*/
                }
            }
            
            break;
        }
        
        case (SPIHDLR_WAIT_ACK): // TODO: Clarify IF there is any case at all where the BLE-Chip sends a CTRL message to the Panther
        {
            hasNewData = FALSE;
            while ((attr.hwInterface->spiGetRxByte(&lastSPIChar) == SPI_HAS_DATA)?TRUE:FALSE)
            {
                attr.rxBuffer[attr.rxBufferLength++] = lastSPIChar;
                hasNewData = TRUE;
            }
            
            if (hasNewData == TRUE) 
            {
                attr.timer = attr.hwInterface->getSysTime();
                
                switch ((attr.rxBuffer[0] & 0x0Fu)) /* checking frame control */
                {
                    case (PKT_T_ACK):
                    {
                        if (((attr.rxBuffer[0] >> 4u) & 0xFu) == ((attr.lastTXFC + 1u) & 0xFu))
                        {
                            attr.lastTXFC = ((attr.lastTXFC + 1u) & 0xFu);
                            attr.state = SPIHDLR_IDLE;
                            attr.txBufferProcessed = TRUE; /* allowing new data to be pushed*/
                            /* notify listener that the packet has been transfered*/
                            attr.hwInterface->onTxComplete();
                        } 
                        else
                        {
                            /* received wrong ACK */
                            /* retransmitting previous TX buffer*/
                            attr.state = SPIHDLR_WAIT_TO_RTX;
                            attr.timer = attr.hwInterface->getSysTime();
                        }
                        break;
                    }
                    default:
                    {
                        // TODO: DATA needs to be forwarded
                        /* received data instead of ACK (happens when other side*/
                        /* does not get the ACk packet correctly*/
                        if (((attr.rxBuffer[0] >> 4u) & 0x0Fu) == attr.lastRXFC)
                        {
                            /* data already received previously -> (ack again)*/
                            attr.state = SPIHDLR_RETX_ACK;
                        }
                        else
                        {
                            /* received a data packet with unexpected Frame Counter.
                            * Do nothing to wait timeout
                            */
                        }
                        break;
                    }
                }
                
                break;
            }
            
            /* ACK timeout */
            if (getSystimeDiff(attr.timer) >= PROTOCOL_TIMEOUT)
            {
                attr.state = SPIHDLR_RETRANSMIT_DATA;
            }
            
            break;
        }
        
        case (SPIHDLR_WAIT_TO_RTX):
        {
            if (getSystimeDiff(attr.timer) >= PROTOCOL_TIMEOUT)
            {
                attr.state = SPIHDLR_RETRANSMIT_DATA;
            }
            
            break;
        }
        
        case (SPIHDLR_RETRANSMIT_DATA): // TODO: common problem if we receive DATA or anything else in this and some other cases its lost... but shouldn't be!!!
        {
            /* pushing to TX buffer*/
            if (attr.hwInterface->spiPush(attr.txBuffer, attr.txBufferLength) == BB_SUCCESS)
            {
                /* retransmitting current TX buffer*/
                attr.txBufferProcessed = FALSE;
                attr.timer = attr.hwInterface->getSysTime();
                /* transition to wait for TX complete*/
                attr.state = SPIHDLR_WAIT_TX;
                attr.nextState = SPIHDLR_WAIT_ACK;
                attr.rxBufferLength = 0u;
                attr.rxBufferCounter = 0u;
            }
            
            break;
        }
        
        case (SPIHDLR_RETX_ACK): // TODO: Throw this out or have an own Type Request_Ack ==>This should not be throw out it is called once and we are sure that the data  recievd but the ACK not yet recieved.
        {
            attr.txRespBuffer[0] = PKT_T_ACK;
            attr.txRespBuffer[0] |= (uint8_t) (attr.lastRXFC << 4);
            attr.txRespBufferLength = 1u;
            
            /* pushing to TX buffer*/
            if (attr.hwInterface->spiPush(attr.txRespBuffer, attr.txRespBufferLength) == BB_SUCCESS)
            {
                attr.state = SPIHDLR_WAIT_TX;
                attr.nextState = SPIHDLR_WAIT_ACK;
                attr.rxBufferLength = 0u;
                attr.rxBufferCounter = 0u;
            }
            
            break;
        }
        
        case (SPIHDLR_WAIT_TX):
        {
            if (attr.hwInterface->spiTxComplete() == TRUE)
            {
                attr.state = attr.nextState;
                attr.timer = attr.hwInterface->getSysTime();
            }
            
            break;
        }
        
        default:
        {
            attr.state = SPIHDLR_IDLE;
            break;
        }
    }
}

/**
 * @brief It pushes DATA to be transmitted over SPI
 * @param data
 * @param length
 * @return  0: ok\n
 *          1: previous buffer not yet processed\n
 *          2: invalid data length\n
 *          3: invalid buffer pointer\n
 *          4: Cannot push yet\n
 */
uint8_t SPITransportLayerPushTXData(const uint8_t data[], uint8_t length)
{
    uint8_t ret = BB_SUCCESS;
    
    if (attr.txBufferProcessed == FALSE)
    {
        ret = 1u;
    } 
    else if (data == NULL)
    {
        ret = 3u; /* invalid data pointer */
    } 
    else if ((length == 0u) || (length > PROTOCOL_MAX_PAYLOAD_LEN))
    {
        ret = 2u; /* wrong data length */
    } 
    else if (attr.state != SPIHDLR_IDLE)
    {
        /* only allowed to push data when state machine is in IDLE */
        ret = 4u;
    } 
    else
    {
        attr.txBufferLength = length + 1u;
        attr.txBuffer[0] = (uint8_t) (((attr.lastTXFC + 1u) & 0xFu) << 4u);
        attr.txBuffer[0] |= PKT_T_DATA;
        memcpy(&attr.txBuffer[1], &data[0], (uint16_t) length);
        attr.txBufferProcessed = FALSE;
    }
    
    return ret;
}

static uint32_t getSystimeDiff(uint32_t time)
{
    return attr.hwInterface->getSysTime() - time;
}

#ifdef TESTENVIRONMENT

SPITransportLayerState_t * SPITransportLayer_GetState(void)
{
    return &attr.state;
}
uint8_t SPITransportLayerGetTXData(uint8_t * data, uint8_t * length)
{
    memcpy(data, attr.txBuffer, attr.txBufferLength);
    *length = attr.txBufferLength;
    return 0;
}

#endif


/** @}*/
