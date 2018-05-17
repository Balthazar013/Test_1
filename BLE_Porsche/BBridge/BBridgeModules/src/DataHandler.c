/**
 * \addtogroup DataHandler
 * @{
 *
 * @file 	DataHandler.c
 * @author	p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2018-03-07 14:04:02 +0100 (Mi, 07 Mrz 2018) $
 * $LastChangedBy: cfarcas $
 * $Revision: 18134 $
 * $Id: DataHandler.c 18134 2018-03-07 13:04:02Z cfarcas $
 *
 */

#include <stdio.h>
#include "BBridgeCommons.h"
#include "DataHandler.h"
#include "FifoBuffer.h"

/**
 * @brief Holds the attribute variables for the DataHandler module
 */
typedef struct {

    /*! ...*/
    BBGenericCB_t onDataToPantherTX;
    
    /*! ...*/
    DataExchangeFnc dataToPantherSender;
    BBCharCB_t canTX;
    
    /*! ...*/
    uint8_t isLocked;
    
    /*! ...*/
    BBridgeCommIntData_t toPantherBuffer;
    
    /*! ...*/
    uint8_t isToPantherBufferProccessed;
    
    /*! ...*/
    BBridgeCommIntData_t fromPantherBuffer;
    
    /*! ...*/
    uint8_t isFromPantherBufferProccessed;
    
    /*! ...*/
    FifoBufferInstance_t rxExternalBuffer;
    
    /*! Module execution states*/
    DataHandler_State_t state;
    uint8_t isDataToPantherTX;
    uint8_t isFeedback;
} DataHandlerControls_t;

/* Private functions*/
static uint8_t hasDataFromExternal(void);
static uint8_t getDataFromExternal(BBridgeCommIntData_t * psBrdgComIntData);
static uint8_t setTxDataToPanther(const uint8_t * data, uint8_t length);
static uint8_t setRxDataFromPanther(const uint8_t * data, uint8_t length);
static void setTxDataToPantherProcessed(void);
static uint8_t hasDataToPanther(void);
static uint8_t lock(void);
static uint8_t isLocked(void);
static uint8_t release(void);


/* private variables*/
static DataHandlerControls_t controls;

/**
 * @brief It initializes the DataHandler module
 * @param onBBridgeToPantherTx - called by this module when data has been
 *  delivered to Panther
 * @param dataToPantherSender - function that sets message to be sent over SPI
 * @return  BB_SUCCESS: ok\n
 *          1: invalid callback for BBridge to Panther\n
 *          2: could not initialize buffer\n
 *          3: invalid data to Panther sender \n
 *          4: invalid "dataToPantherSender" cb \n
 */
uint8_t DataHandler_Init(BBGenericCB_t onBBridgeToPantherTx, DataExchangeFnc dataToPantherSender)
{
    int8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (onBBridgeToPantherTx == NULL)
    {
        funcRet = 1u;
    }
    else if (dataToPantherSender == NULL)
    {
        funcRet = 3u;
    }
    else
    {
        ret = FifoBufferInit(&controls.rxExternalBuffer,
                                FIFO_MODE_OVERWRITE_OLDEST_ELEMENT,
                                DHDLR_RX_EXT_BUFFER_SIZE,
                                sizeof(BBridgeCommPacket_t));
        if (ret != 1)
        {
                funcRet = 2u;
        }
        else
        {
            controls.onDataToPantherTX = onBBridgeToPantherTx;
            controls.dataToPantherSender = dataToPantherSender;
            setTxDataToPantherProcessed(); /* setting it to processed (free to use)*/
            controls.isFromPantherBufferProccessed = TRUE; /* setting it to processed (free to use)*/
            controls.isLocked = FALSE;
            controls.state = DH_IDLE;
        }
    }
    
    return funcRet;
}


/**
 * @brief It pushes "internal" data to be sent to the Panther device
 * @param data
 * @param length
 * @note This call does not actually send the data directly, the DataHandler
 * and the underlying modules flushes the data when possible.
 * @return      BB_SUCCESS: data is set to be transmitted\n
 *              1: could not receive internal data -> busy\n
 *              2: invalid internal data source length\n
 *              3: invalid internal data source pointer\n
 *              4: not handled error
 */
uint8_t DataHandler_PushIntDataToPanther(const uint8_t * data, uint8_t length)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (hasDataToPanther() == TRUE)
    {
        /* there is data yet to be transfered*/
        funcRet = 1u;
    }
    else
    {
        /* Data handler is free to send data to the Internal COMM interface*/
        ret = setTxDataToPanther(data, length);
        
        if (ret == BB_SUCCESS)
        {
            funcRet = 0u; /* ok*/
        } 
        else if (ret == 1u)
        {
            funcRet = 2u; /* invalid data source length*/
        }
        else if (ret == 2u)
        {
            funcRet = 3u; /* data source pointer invalid*/
        }
        else
        {
            funcRet = 4u; /* unknown (not likely to happen)*/
        }
    }
    
    return funcRet;
}

/**
 * @brief It pushes external data to be sent to the Panther device
 * @param data
 * @param length
 * @note This call does not actually send the data directly, the DataHandler
 * and the underlying modules flushes the data when possible.
 * @return      BB_SUCCESS: data is set to be transmitted\n
 *              1: External data length invalid\n
 *              2: External data pointer invalid\n
 *              3: could not push data to tx buffer\n
 */
uint8_t DataHandler_PushExtDataToPanther(BBridgeCommPacket_t *psBrdgComPaket)
{
    uint8_t ret = BB_SUCCESS;
    
    psBrdgComPaket->unPacketInfo.st.HeaderLength = 3;
    psBrdgComPaket->unPacketInfo.st.HeaderOffset = BBRIDGE_COM_PCK_HDR_SIZE - psBrdgComPaket->unPacketInfo.st.HeaderLength;
    
    psBrdgComPaket->unPacketData.st.header[0+psBrdgComPaket->unPacketInfo.st.HeaderOffset] = BB_MSGTYPE_EVENT;
    psBrdgComPaket->unPacketData.st.header[1+psBrdgComPaket->unPacketInfo.st.HeaderOffset] = BB_EVT_RX_MSG;
    psBrdgComPaket->unPacketData.st.header[2+psBrdgComPaket->unPacketInfo.st.HeaderOffset] = psBrdgComPaket->unPacketInfo.st.ConnIndex;

    
    /* pushing external data to buffer*/
    if(FifoBufferPush(&controls.rxExternalBuffer, psBrdgComPaket) != 1)
    {
        /* failed to add to buffer (buffer full most likely)*/
        ret = 3u;
    }
    
    return ret; 
}

/**
 * @brief It receives data from the Panther. It shall be called when there is
 * data from the SPI to the BBridge
 * @param data
 * @param length
 * @return  BB_SUCCESS: ok\n
 *          1: Can not receive data from Panther\n
 *          2: Previous data to Panther has not yet been processed\n
 *          3: Invalid data source length\n
 *          4: Invalid data source pointer\n
 *          5: Could not receive data -> unhandled
 */
uint8_t DataHandler_OnRxDataFromPanther(const uint8_t * data, uint8_t length)
{
    uint8_t ret;
    uint8_t funcRet = BB_SUCCESS;
    
    if (isLocked() == TRUE)
    {
        funcRet = 1u; /* cannot receive*/
    }
    else
    {
        /* not locked, ok to continue*/
        if (controls.isFromPantherBufferProccessed == FALSE)
        {
            /* previous data from Panther not yet processed*/
            funcRet = 2U; /* cannot receive*/
        }
        else
        {
            ret = setRxDataFromPanther(data, length);
            if (ret == BB_SUCCESS)
            {
                /* BB_SUCCESS;  received OK*/
            }
            else if (ret == 1u)
            {
                funcRet = 3u; /* invalid data length*/
            }
            else if (ret == 2u)
            {
                funcRet = 4u; /* invalid data source pointer*/
            }
            else
            {
                /* should never happen*/
                funcRet = 5u;
            }
        }
    }
    
    return funcRet;
}

/**
 * @brief notification from outside to state that the SPI data has been
 * transmitted.
 */
void DataHandler_OnTxDataToPantherComplete(void)
{
    controls.isDataToPantherTX = TRUE;
}

/**
 * @brief If there is data from Panther to be processed
 * @note data is available for retrieval only in specific states of the inner
 * worker state machine
 * @return  BB_SUCCESS: no\n
 *          1: yes
 */
uint8_t DataHandler_HasDataFromPanther(void)
{
    return ((controls.isFromPantherBufferProccessed == FALSE)
            && (controls.state == DH_DATAFROMPANTHER_WAIT_RELEASE)) ? TRUE : FALSE;
}

/**
 * @brief Checks whether there data from Panther is available or not
 * @return  BB_SUCCESS: no data from Panther available\n
 *  1: there is data from panther to be processed
 */
uint8_t DataHandler_IsDataFromPantherProcessed(void)
{
    return (controls.isFromPantherBufferProccessed == TRUE) ? TRUE : FALSE;
}

/**
 * @brief It loads the data received from the Panther device
 * @param data destination
 * @param length of the data copied
 * @return  BB_SUCCESS: ok\n
 *          1: There is no data to be fetched\n
 *          2: data destination pointer not valid\n
 *          3: length destination pointer not valid
 */
uint8_t DataHandler_GetRxDataFromPanther(uint8_t * data, uint8_t * length)
{
    uint8_t ret = BB_SUCCESS;
    
    if (controls.isFromPantherBufferProccessed == TRUE)
    {
        ret = 1u;
    }
    else if (data == NULL)
    {
        /* data destination not valid*/
        ret = 2u;
    }
    else if (length == NULL)
    {
        /* length destination not valid*/
        ret = 3u;
    }
    else
    {
        memcpy(data, controls.fromPantherBuffer.data, (uint16_t)controls.fromPantherBuffer.length);
        *length = controls.fromPantherBuffer.length;
    }
    
    return ret;
}

/**
 * @brief It sets the RX buffer from Panther to "free"
 */
void DataHandler_RxDataFromPantherProcessed(void)
{
    controls.isFromPantherBufferProccessed = TRUE;
}

/**
 * @brief It processes the Business logics for the Data handler
 */
void DataHandler_Work(void)
{
    switch (controls.state)
    {
        case (DH_IDLE):
        {
            /* not locked*/
            /* has data To Panther ?*/
            if (hasDataToPanther() == TRUE)
            {
                /* process internal TX*/
                if (lock() == BB_SUCCESS)
                {
                    controls.state = DH_PROCESS_DATA2PANTHER;
                }
            }
            else
            {
                /* has data from Panther ?*/
                if (controls.isFromPantherBufferProccessed == FALSE)
                {
                    if (lock() == BB_SUCCESS)
                    {
                        controls.state = DH_DATAFROMPANTHER_WAIT_RELEASE;
                    }
                } 
                else
                {
                    /* external (validated) data to Panther ?*/
                    if (hasDataFromExternal() == TRUE)
                    {
                        if (lock() == BB_SUCCESS) 
                        {
                            controls.state = DH_PROCESS_EXTERNAL;
                        }
                    }
                }
            }
            break;
        }
        case (DH_PROCESS_DATA2PANTHER):
        {
            /* can transmit ?*/
            controls.isDataToPantherTX = FALSE;
            if(controls.dataToPantherSender(controls.toPantherBuffer.data, controls.toPantherBuffer.length) == BB_SUCCESS)
            {
                controls.state = DH_WAIT_TX_COMPLETE;
            }
            break;
        }
        case (DH_WAIT_TX_COMPLETE):
        {
            /* sent ok*/
            if (controls.isDataToPantherTX == TRUE)
            {
                /*controls.isDataToPantherTX = 0;*/
                setTxDataToPantherProcessed();
                if (controls.isFeedback == FALSE) {
                    release();
                    controls.onDataToPantherTX(); /* notifying listeners*/
                    controls.state = DH_IDLE;
                }
                else
                {
                    controls.onDataToPantherTX(); /* notifying listeners*/
                    controls.state = DH_DATAFROMPANTHER_WAIT_RELEASE;
                }
            }
            break;
        }
        case (DH_DATAFROMPANTHER_WAIT_RELEASE):
        {
            /* In this state the data handler waits that the a listening controller*/
            /* retrieves the data and releases it for further operation*/
            
            if (hasDataToPanther() == TRUE)
            {
                /* Listener wants to send FEEDBACK*/
                controls.state = DH_PROCESS_DATA2PANTHER;
                controls.isFeedback = TRUE;
            } 
            else
            {
                if (controls.isFromPantherBufferProccessed == TRUE)
                {
                    /* there isn't  data from Panther available anymore*/
                    controls.state = DH_IDLE;
                    release();
                } 
                else 
                {
                    /* waiting for processing*/
                    /* DataHandler_GetRxDataFromPanther(...) and*/
                    /* DataHandler_RxDataFromPantherProcessed()*/
                }
            }
            break;
        }
        case (DH_PROCESS_EXTERNAL):
        {
            /*copy one external message to TX buffer -> Panther*/
            if (getDataFromExternal(&controls.toPantherBuffer) == BB_SUCCESS)
            {
                controls.isToPantherBufferProccessed = FALSE; /* setting it to not processed*/
                
                /* The idle state shall process this message now*/
                controls.state = DH_IDLE;
                release();
            }
            else
            {
                /* could not get data. It shall never happen as the preconditions*/
                /* for this call where met before this state was called.*/
                controls.state = DH_IDLE;
                release();
            }
            break;
        }
        default:
        {
            release();
            controls.state = DH_IDLE;
            break;
        }
    }
}

/* ----------------------------------------------------------------------------*/
/* Private functions*/
/* ----------------------------------------------------------------------------*/

/**
 * @brief It locks the module for further operations. When locked it is not
 * possible to receive or transfer new data.
 * @return  BB_SUCCESS: locked correctly\n
 *          1: could not lock -> Already locked\n
 */
static uint8_t lock(void)
{
    uint8_t ret = BB_SUCCESS;
    if (isLocked() == TRUE)
    {
        ret = 1u;
    }
    else
    {
        controls.isLocked = TRUE;
    }
    
    return ret;
}

/**
 * @brief It checks whether the module is locked or not for further operations
 * @return	BB_SUCCESS: not locked\n
 * 			1: locked
 */
static uint8_t isLocked(void)
{
    return (controls.isLocked == TRUE) ? TRUE : FALSE;
}

/**
 * @brief It releases the module from a locked state
 * @return  BB_SUCCESS: released correctly\n
 *          1: not locked\n
 *          2: could not release
 */
static uint8_t release(void)
{
    uint8_t ret = BB_SUCCESS;
    if (isLocked() == TRUE) 
    {
        controls.isLocked = FALSE;
        ret = FALSE;
    }
    else 
    {
        ret = TRUE;
    }
    
    return ret;
}

/**
 * @brief If there is data to be transfered to the Panther device
 * @note Data to be transferred to the Panther device is only set by the worker
 * on appropriate times
 * @return  BB_SUCCESS: no\n
 *          1: yes
 */
static uint8_t hasDataToPanther(void)
{
    return (controls.isToPantherBufferProccessed == FALSE) ? TRUE : FALSE;
}

/**
 * @brief If there is data buffered from the external interface not yet processed
 * @return  BB_SUCCESS: no\n
 *          1: yes
 */
static uint8_t hasDataFromExternal(void)
{
    return (FifoBufferIsEmpty(&controls.rxExternalBuffer) == 0) ? TRUE : FALSE;
}

/**
 * @brief It retrieves  an external message from the buffer
 * @param externalData - points to the extract destination
 * @note make sure to properly allocate the externalData parameter
 * @return  BB_SUCCESS: data retrieved correctly\n
 *          1: there is no data to be retrieved\n
 *          2: invalid parameter pointer (not allocated)\n
 *          3: could not retrieve data
 */
static uint8_t getDataFromExternal(BBridgeCommIntData_t * psBrdgComIntData)
{
    uint8_t ret = BB_SUCCESS;
    
    if (hasDataFromExternal() == TRUE)
    {
        if (FifoBufferPop(&controls.rxExternalBuffer, psBrdgComIntData) == 1)
        {
            ret = BB_SUCCESS; /* retrieved correctly*/
        } 
        else 
        {
            ret = 3u; /* error getting data (e.g. externalData is invalid)*/
        }
    } 
    else 
    {
        ret = 1u; /* no msg available*/
    }
    
        return ret;
}

/**
 * @brief It sets the "output" data to be transferred to the Panther device
 * @param data
 * @param length
 * @return  BB_SUCCESS: set ok\n
 *          1: data source length is invalid\n
 *          2: data source pointer is invalid\n
 */
static uint8_t setTxDataToPanther(const uint8_t * data, uint8_t length)
{
    uint8_t ret = BB_SUCCESS;
    if (data == NULL)
    {
        ret = 2u;
    }
    else if ((length == 0u) || (length > BB_MAX_EXT_DATA_SPI))
    {
        ret = 1u;
    }
    else
    {
        controls.toPantherBuffer.length = length;
        memcpy(controls.toPantherBuffer.data, data, (uint16_t)length);
        controls.isToPantherBufferProccessed = FALSE; /* setting it to not processed*/
    }
    
    return ret;
}

/**
 * @brief It sets the variable that frees the TX buffer to Panther
 * @return none
 */
static void setTxDataToPantherProcessed(void)
{
    controls.isToPantherBufferProccessed = TRUE;
}

/**
 * @brief It sets a buffer with received data from the Panther
 * @param data
 * @param length
 * @return  BB_SUCCESS: ok\n
 *          1: invalid data source length\n
 *          2: invalid data source pointer
 */
static uint8_t setRxDataFromPanther(const uint8_t * data, uint8_t length)
{
    uint8_t ret = BB_SUCCESS;
    if (data == NULL) 
    {
            ret = 2u;
    }
    else if ((length == 0u) || (length > BB_MAX_EXT_DATA_SPI))
    {
        ret =1u;
    }
    else
    {
          controls.fromPantherBuffer.length = length;
          memcpy(controls.fromPantherBuffer.data, data, (uint16_t)length);
          controls.isFromPantherBufferProccessed = FALSE; /* setting it to not processed*/
    }
    
    return ret;
}

#ifdef TESTENVIRONMENT
/**
 * @brief For testing purposes only
 */
void DataHandler_Destroy(void) 
{
    free(controls.rxExternalBuffer.buffer);
    controls.rxExternalBuffer.buffer = 0u;
    setTxDataToPantherProcessed();
}

const DataHandler_State_t * DataHandler_GetState(void)
{
    return &controls.state;
}

#endif

/** @}*/
