/**
 * \addtogroup USARTInterface.c
 * @{
 *
 * @file 	USARTInterface.c
 * @author	p344575
 * @brief   USART interface for using TI USART spi driver
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2017-11-14 12:44:56 +0100 (Di, 14 Nov 2017) $
 * $LastChangedBy: ksteingass $
 * $Revision: 16315 $
 * $Id: USARTInterface.c 16315 2017-11-14 11:44:56Z ksteingass $
 *
 */

#include "USARTInterface.h"
#include "hal_uart.h"
#include "npi.h"
#include "bcomdef.h"
#include "OSAL.h"

typedef struct
{
    uint8_t rxBuffer[USART_IFF_MAX_BUFF_LEN];
    uint8_t rxBufferLength;
    uint8_t rxBufferCounter;
    uint8_t isTxComplete;
} USARTInterfaceAttributes_t;

/* private functions */
static void cSerialPacketParser(uint8 port, uint8 event);
static void onTxComplete(void);

/* module attributes */
static USARTInterfaceAttributes_t attr;

/***
 * @brief Module initialization
 */
void USARTInterfaceInit(void)
{
    NPI_InitTransport(&cSerialPacketParser); /* Initializing NPI */
    attr.rxBufferLength = 0;
    attr.rxBufferCounter = 0;
    attr.isTxComplete = 1;
    
    /* Transmission complete callback */
    HalUART_SetTxCompleteCB(&onTxComplete);
}

/**
 * @brief Pushed data to sent over the USARTSPI interface
 * @param data
 * @param dataLength
 * @return  0: pushed correctly
 *          1: could not sent correctly
 *          2: cannot push until previous data has not been sent
 */
uint8_t USARTInterfacePush(uint8_t data[], uint8_t dataLength)
{
    uint8_t ret = SUCCESS;
    uint8_t bytesSent;
    
    if (attr.isTxComplete == 0)
    {
        ret = 2; /* transmission still ongoing, cannot push */
    } 
    else
    {
        attr.isTxComplete = 0;
        bytesSent = HalUARTWrite(NPI_UART_PORT, data, dataLength);
        if (bytesSent != dataLength)
        {
            ret = 1;
        }
    }
    
    return ret;
}

/**
 * @brief private callback called when transmissions are completed
 */
static void onTxComplete(void)
{
    attr.isTxComplete = 1;
}

/**
 * @brief Getter for the transmission complete state
 * @return  TRUE: yes - transmission complete
 *          FALSE: no
 */
uint8_t USARTInterfaceIsTxComplete(void)
{
    return (attr.isTxComplete == 1) ? TRUE : FALSE;
}

/**
 * @brief It retrieves a byte from the RX buffer
 * @param byte: pointer to where value will be stored
 * @return  0: No byte is available for retrieval
 *          SPI_HAS_DATA: a valid byte has been copied to the destination byte
 */
unsigned char USARTInterfaceGetRxByte(unsigned char * byte)
{
    unsigned char cRet = 0;
    
    if (attr.rxBufferCounter < attr.rxBufferLength)
    {
        *byte = attr.rxBuffer[attr.rxBufferCounter++];
        cRet = SPI_HAS_DATA;
        
        if (attr.rxBufferCounter >= attr.rxBufferLength)
        {
            /* all bytes available have been retrieved */
            attr.rxBufferCounter = 0;
            attr.rxBufferLength = 0;
        }
    }
    
    return cRet;
}

/**
 * @brief Called by the NPI interface when new data has been received over the
 * USARTSPI interface
 * @param port
 * @param event
 */
static void cSerialPacketParser(uint8 port, uint8 event)
{
    (void) port; /* not used */
    (void) event; /* not used */
    
    /* only use data read when previous received buffer has been feteched */
    if (attr.rxBufferLength == 0 && attr.rxBufferCounter == 0)
    {
        /* get the number of available bytes to process */
        attr.rxBufferLength = NPI_RxBufLen();
        
        /* loading data from the serial interface */
        if (NPI_ReadTransport(attr.rxBuffer, attr.rxBufferLength) != attr.rxBufferLength)
        {
            /* Failed to retrieve all data available */
            attr.rxBufferLength = 0;
        }
    }
}

/** @}*/
