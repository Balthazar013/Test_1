/*! \addtogroup FifoBuffer
 *  @{
 */

/*!
 * @file 		FifoBuffer.h
 * @brief       This is a universal FIFO-Buffer implementation for embedded systems
 *
 * @author      Daniel Simon
 * @author      Harald Schöffler
 * @copyright 	&copy; 2015 by Porsche Engineering Services GmbH
 *
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * @version        		1.0
 * $Revision: 18134 $
 *
 * @attention      (Important information and major changes should be documented here.
 *                 A changelog of this file is provided whithin the subversion history)
 *
 ***************************************************************************************
 */

#ifndef FIFO_BUFFER_H
#define FIFO_BUFFER_H

/* Provide C++ compatibility*/
#ifdef __cplusplus
extern "C" {
#endif
#include "typedefs.h"
#include "BBridgeDefs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*! \brief Version of the FIFO-Buffer Implementation
 *  \details High Byte of uint16_t is the major\n
 *           Low Byte of uint16_t is the minor
 */
#define FIFO_BUFFER_VERSION     0x10


/*! \brief Select one mode to specify the FIFO-Buffer behavior
 */
typedef enum
{
    FIFO_MODE_LOST_ELEMENT_IF_FULL=0U,         /*!< FIFO-Buffer behavior, discard new element if the buffer is full*/
    FIFO_MODE_OVERWRITE_OLDEST_ELEMENT      /*!< FIFO-Buffer behavior, overwrite the oldest value if the buffer is full*/
} FifoBufferMode_t;


/*! \brief Hold the context of a FIFO-Buffer instance
 */
typedef struct
{
    uint8_t* buffer;                        /*!< Hold the start address to the allocated memory*/
    uint16_t head;                          /*!< Index to next push operation*/
    uint16_t tail;                          /*!< Index to next pop operation*/
    FifoBufferMode_t fifoBufferMode;        /*!< Select the FIFO-Buffer behavior if the buffer is full*/
    uint16_t fifoBufferSize;                /*!< FIFO-Buffer depth*/
    size_t sizeOfOneElement;                /*!< Size of one element*/
    uint8_t popOperationActive;             /*!< help variable for a interrupt safe overwrite mode*/
} FifoBufferInstance_t;


int8_t FifoBufferInit(FifoBufferInstance_t* const buf, const FifoBufferMode_t mode, const uint16_t size, const size_t sizeOfOneElement);
int8_t FifoBufferPush(FifoBufferInstance_t* const buf, BBridgeCommPacket_t * psBrdgComExtPaket);
int8_t FifoBufferPop(FifoBufferInstance_t* const buf, BBridgeCommIntData_t * psBrdgComIntData);

int8_t FifoBufferIsFull(FifoBufferInstance_t* const buf);
int8_t FifoBufferIsEmpty(FifoBufferInstance_t* const buf);
int8_t FifoBufferClear(FifoBufferInstance_t* const buf);
uint16_t FifoBufferGetNumberOfEntries(FifoBufferInstance_t* const buf);

/* Provide C++ compatibility*/
#ifdef __cplusplus
}
#endif

#endif

/*! @} */
