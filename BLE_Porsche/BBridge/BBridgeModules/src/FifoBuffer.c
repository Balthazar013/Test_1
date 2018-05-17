/*! \addtogroup FifoBuffer
 *  The goal of this FIFO-Buffer implementation was:\n
 *  1. one implementation to store items of any user defined type definition
 *  2. small footprint
 *  3. optimized for speed
 *  4. interrupt safe
 *  5. Select FIFO-Buffer behavior: Keep oldest or delete oldest
 *  6. simple to use
 *  @{
 */

/*!
 * @file 		FifoBuffer.c
 * @brief       This is a universal FIFO-Buffer implementation for embedded systems
 *
 * @author      Daniel Simon
 * @author      Harald Schöffler
 * @copyright 	&copy; 2015 by Porsche Engineering Services GmbH
 *
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * @version        		1.1
 * $Revision: 18134 $
 *
 * @attention      (Important information and major changes should be documented here.
 *                 A changelog of this file is provided whithin the subversion history)
 *              - fixed most of the non MISRA C 2004 compatible code
 *
 ***************************************************************************************
 */

#include "FifoBuffer.h"
#include "typedefs.h"

/*! \brief Initialisation of the FIFO-Buffer instance
 *  \details If a error occured during the initialisation, the function return the reason.\n
 *           This circular buffer implementation allocate one element more than specified because:\n
 *           1. increase robustness and speed with the modulo operator --> zero check of divisor isn´t necessary\n
 *           2. interrupt safe while fully separation of the tail and head index.
 *  \param buf                  Constant pointer of the FIFO-Buffer instance
 *  \param mode                 Configure the behavior of the FIFO-Buffer if the Buffer is full
 *  \param size                 FIFO-Buffer depth
 *  \param sizeOfOneElement     Size in byte of one element --> use the sizeof-Operator
 *  \return -3      The FIFO-Buffer is already instantiated\n
 *          -2      The FIFO-Buffer behavior mode don´t exist\n
 *          -1      The FIFO-Buffer can´t allocate the required memory, fix this error, because you´ll get a memory leak\n
 *           1      The FIFO-Buffer is sucessfully allocated and ready to use
 */
int8_t FifoBufferInit(FifoBufferInstance_t* const buf, const FifoBufferMode_t mode, const uint16_t size, const size_t sizeOfOneElement)
{
    uint8_t * buffer;
    int8_t ret=1;

    if (buf->buffer == NULL)
    {
        /* The FIFO-Buffer don´t allocate memory for this instance*/
        buf->head = 0u;
        buf->tail = 0u;
        buf->popOperationActive = 0u;
        buf->sizeOfOneElement = sizeOfOneElement;
        buf->fifoBufferSize = (uint16_t)(size + 1u);     /* +1 --> Interrupt safe (entire separation of tail and head index)*/
                                            /* +1 --> increase robustness, prevent division by zero with the modulo operator*/

        if ((mode == FIFO_MODE_LOST_ELEMENT_IF_FULL) ||
            (mode == FIFO_MODE_OVERWRITE_OLDEST_ELEMENT))
        {
            buf->fifoBufferMode = mode;
        }
        else
        {
            /* The FIFO-Buffer behavior mode don´t exist*/
            buf->buffer = NULL;
            buf->fifoBufferMode = FIFO_MODE_LOST_ELEMENT_IF_FULL;
            ret = -2;
        }

        if(ret == 1)
        {
          buffer = malloc((size + 1u) * sizeOfOneElement);
          if (buffer != NULL)
          {
              buf->buffer = buffer;
          }
          else
          {
              /* The FIFO-Buffer can´t allocate the required memory, fix this error, because you´ll get a memory leak*/
              buf->buffer = NULL;
              ret = -1;
          }
        }
    }
    else
    {
        /* The FIFO-Buffer is already instantiated*/
        ret = -3;
    }
    return ret; /*return 1;*/
}


/*! \brief Push a new element into the FIFO-Buffer in dependency of the initialized behavior mode
 *  \details Simplest way to push elements of type uint16_t into the FIFO-Buffer:\n\n
 *           FifoBufferInstance_t myBuffer;\n
 *           uint16_t pushElement;\n
 *           FifoBufferInit(&myBuffer, FIFO_MODE_LOST_ELEMENT_IF_FULL, 3, sizeof(uint16_t));\n
 *           FifoBufferPush(&myBuffer, &pushElement);
 *  \param buf      Constant pointer of the FIFO-Buffer instance
 *  \param value    Generic pointer to incomplete type --> universal buffer implementation
 *  \return  0      If the behavior mode is configured to FIFO_MODE_LOST_ELEMENT_IF_FULL, then the buffer is full and the push operation failed\n
 *           1      The push operation sucessfully performed. If the behavior mode is configured to FIFO_MODE_OVERWRITE_OLDEST_ELEMENT, then the oldest value in the buffer will be overwrite
 */
int8_t FifoBufferPush(FifoBufferInstance_t* const buf, BBridgeCommPacket_t * psBrdgComPaket)
{
    int8_t ret=1;
    
    if (((buf->head + 1u) % buf->fifoBufferSize) == buf->tail)
    {
        if (buf->fifoBufferMode == FIFO_MODE_LOST_ELEMENT_IF_FULL)
        {
            ret = 0;
        }
        else
        {
            /* Buffer is full and in overwrite mode*/
            if (!buf->popOperationActive)
            {
                if (++buf->tail == buf->fifoBufferSize)
                {
                    buf->tail = 0u;
                }
            }
            /* else { popOperation is interrupted, so the tail will be increment in the FifoBufferPop function }*/
        }
    }
    
    if(ret == 1)
    {
        memcpy(&buf->buffer[(buf->head * buf->sizeOfOneElement)],\
               psBrdgComPaket->unPacketInfo.ar,\
               sizeof(PaketInfo_t));
        
        if(psBrdgComPaket->unPacketInfo.st.HeaderLength != 0)
        {
            memcpy((&buf->buffer[(buf->head * buf->sizeOfOneElement)] + sizeof(PaketInfo_t)),\
                    &(psBrdgComPaket->unPacketData.ar[psBrdgComPaket->unPacketInfo.st.HeaderOffset]),\
                    psBrdgComPaket->unPacketInfo.st.HeaderLength +psBrdgComPaket->unPacketInfo.st.DataLength);
        }
        else
        {
            memcpy((&buf->buffer[(buf->head * buf->sizeOfOneElement)]  + sizeof(PaketInfo_t)),\
               psBrdgComPaket->unPacketData.st.data,\
               psBrdgComPaket->unPacketInfo.st.DataLength);
        }
        
        if (++buf->head == buf->fifoBufferSize)
        {
            buf->head = 0u;
        }
    }
    
    return ret;
}


/*! \brief Pop the oldest element from FIFO-Buffer
 *  \details Simplest way to pop elements of type uint16_t from the FIFO-Buffer:\n\n
 *           FifoBufferInstance_t myBuffer;\n
 *           uint16_t popElement;\n
 *           FifoBufferInit(&myBuffer, FIFO_MODE_LOST_ELEMENT_IF_FULL, 3, sizeof(uint16_t));\n
 *           FifoBufferPop(&myBuffer, &popElement);
 *  \param buf      Constant pointer of the FIFO-Buffer instance
 *  \param value    Generic pointer to incomplete type --> universal buffer implementation
 *  \return  0      The FIFO-Buffer is empty\n
 *           1      The pop operation sucessfully performed. The caller has exclusive access to the popped value!
 */
int8_t FifoBufferPop(FifoBufferInstance_t* const buf, BBridgeCommIntData_t * psBrdgComIntData)
{
    int8_t ret=0;
    PaketInfo_t unPacketInfo;
    
    if (buf->tail != buf->head)
    {
        buf->popOperationActive = 1u;
        
        memcpy(unPacketInfo.ar, &buf->buffer[buf->tail * buf->sizeOfOneElement], sizeof(PaketInfo_t));
        
        psBrdgComIntData->length = unPacketInfo.st.HeaderLength + unPacketInfo.st.DataLength;
        
        memcpy( psBrdgComIntData->data,\
                (&buf->buffer[(buf->tail * buf->sizeOfOneElement)] + sizeof(PaketInfo_t)),\
                psBrdgComIntData->length);
        
        if (++buf->tail == buf->fifoBufferSize)
        {
            buf->tail = 0u;
        }
        
        buf->popOperationActive = 0u;
        
        ret = 1;
    }
    
    return ret;
}


/*! \brief FIFO-Buffer help function to check if the FIFO-Buffer is full
 *  \details The FIFO-Buffer is full if,\n
 *           1. the tail pointed to one element behind the head
 *           2. the head pointed to the last element and the tail to the first element in the linear allocated memory
 *  \param buf      Constant pointer of the FIFO-Buffer instance
 *  \return  0      You can push new elements into the FIFO-Buffer\n
 *           1      The FIFO-Buffer is full
 */
int8_t FifoBufferIsFull(FifoBufferInstance_t* const buf)
{
  return (((buf->head + 1u) % buf->fifoBufferSize) == buf->tail)?1:0;
}


/*! \brief FIFO-Buffer help function to check if the FIFO-Buffer is empty
 *  \details The FIFO-Buffer is empty if, the tail point to the same location as the head.\n
 *           While we allocate one element more than specified during initialisation, this simple check is well defined.
 *  \param buf      Constant pointer of the FIFO-Buffer instance
 *  \return  0      You can pop elements from the FIFO-Buffer\n
 *           1      The FIFO-Buffer is empty
 */
int8_t FifoBufferIsEmpty(FifoBufferInstance_t* const buf)
{
  return (buf->head == buf->tail)?1:0;
}


/*! \brief FIFO-Buffer help function to clear the FIFO-Buffer
 *  \details While the FIFO-Buffer initialisation initialize the buffer only at the first time, you need a function to clear the buffer.
 *  \param buf      Constant pointer of the FIFO-Buffer instance
 *  \return  1      The clear operation sucessfully performed. The FIFO-Buffer is now empty.
 */
int8_t FifoBufferClear(FifoBufferInstance_t* const buf)
{
    buf->head = buf->tail;
    return 1;
}


/*! \brief FIFO-Buffer help function to get the number of entries in the FIFO-Buffer
 *  \details Get the number of entries in the FIFO-Buffer.
 *  \param buf      Constant pointer of the FIFO-Buffer instance
 *  \return  1      The clear operation sucessfully performed. The FIFO-Buffer is now empty.
 */
uint16_t FifoBufferGetNumberOfEntries(FifoBufferInstance_t* const buf)
{
    uint16_t num = 0u;
    if(buf->head > buf->tail)
    {
      num = (uint16_t)(buf->head - buf->tail);
    }
    else
    {
      num =  (uint16_t)(num + buf->fifoBufferSize);
      /*num = (buf->tail-buf->head);*/
    }
    
    /*if (num < 0)
    {
        num = (int16_t)(num + buf->fifoBufferSize);
    }*/
    return num;
}

/*! @} */
