/**
* @brief ICOM Diagnostic Channel to provide/collect the Diagnostic data from RTE to/from ICOM Service
*
* @copyright Copyright (c) 2015-2017 Bombardier Transportation. All rights reserved.
*
* @file $RCSfile$
* @author $Author$
* @date $Date$
* @version $Revision$
*/

#include <Std_Types.h>
#include <stddef.h>
#include <TSMem.h>
#include "ICOM.h"
#include "ICOMChannel_Diag.h"

//---------------------------------------------------------------------------------------------------------------------
// MAKRO DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

#define DIAG_MIN_FRAME_SIZE     (uint32)1
#define DIAG_MAX_FRAME_SIZE     (uint32)15
#define DIAG_CHANNEL_PRIORITY   2
#define DIAG_TX_BUFFER          1024
#define DIAG_RX_BUFFER          1024


#define ICOM_CH_DIAG_DATA_FRM   0u
#define ICOM_CH_DIAG_CTRL_FRM   1u

// #define DEBUG_ICOM_CH_DIAG

#define SOF     0x8u
#define EOF     0x1u


//---------------------------------------------------------------------------------------------------------------------
// TYPE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

typedef enum
{
  CANCEL = 0,
} DiagCmd_t;

#pragma pack(1)
typedef struct
{
  uint8   type  : 4;
  uint8   FrameDescription : 4;
} S_ICOM_CH_DIAG_FRAME;
#pragma pack()

#define DIAG_HDR_FRAME_SIZE     sizeof(S_ICOM_CH_DIAG_FRAME)

typedef union
{
  uint8                     array[1];
  S_ICOM_CH_DIAG_FRAME      st;
} ICOM_CH_DIAG_FRAME;

typedef struct
{
  uint8               TxBuff[DIAG_TX_BUFFER];
  uint16              TxIndex;
  uint16              TxLength;
  ICOM_CH_DIAG_FRAME  TxFrameHdr;
} ICOM_ChDiagOut;

typedef struct
{
  uint8   RxBuff[DIAG_RX_BUFFER];
  uint16  RxIndex;
  uint16              RxLength;
  ICOM_CH_DIAG_FRAME RxFrameHdr;
} ICOM_ChDiagIn;

typedef struct
{
  ICOM_ChDiagIn           ChDiagIn;
  ICOM_ChDiagOut          ChDiagOut;
  ICOM_uDiagFrameHeader   ChDiagInHdr;
  ICOM_uDiagFrameHeader   ChDiagOutHdr;
  uint8                   DiagChBusyFlag;
}ICOM_ChDiag;

//----------------------------------------------------------------------------
// VARIABLE DECLARATIONS
//----------------------------------------------------------------------------

static ICOM_ChDiag  ICOMSrvDiag_instance;
static ICOM_CH      ICOM_Channel_instance;
static DiagCmd_t    DiagCmd;

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType ICOM_updateData (const uint8 *databeginptr, const uint8 *dataendptr, uint8 **pDataUpdate);
static Std_ReturnType ICOM_collectData(const uint8 *databeginptr, const uint8 *dataendptr, uint8 **pDataCollect);
Std_ReturnType ICOMChannelDiag_Init(ICOM_INST *pICOM_Instance);

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DEFINITIONS
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType ICOMChannelDiag_Init(ICOM_INST *pICOM_Instance)
{
  uint16 loop;
  Std_ReturnType retVal = E_NOT_OK;

  ICOMSrvDiag_instance.ChDiagOut.TxIndex            = 0;
  ICOMSrvDiag_instance.ChDiagOut.TxLength           = 0;
  ICOMSrvDiag_instance.ChDiagIn.RxIndex             = 0;
  ICOMSrvDiag_instance.DiagChBusyFlag               = FALSE;

  ICOM_Channel_instance.uPriority     = DIAG_CHANNEL_PRIORITY;
  ICOM_Channel_instance.uFrameType    = FRAME_TYPE_DIAG;
  ICOM_Channel_instance.fpUpdate      = &ICOM_updateData;
  ICOM_Channel_instance.fpCollect     = &ICOM_collectData;

  if (ICOM_openChannel (pICOM_Instance, &ICOM_Channel_instance) == E_OK)
  {
    retVal = E_OK;
  }
  ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.st.type = ICOM_CH_DIAG_DATA_FRM;
  ICOMSrvDiag_instance.ChDiagOutHdr.stDiagFrmHdr.FRAME_TYPE = FRAME_TYPE_DIAG;

  #ifdef DEBUG_ICOM_CH_DIAG
  ICOMSrvDiag_instance.ChDiagOut.TxLength = 1000;
  for(loop = 0; loop < ICOMSrvDiag_instance.ChDiagOut.TxLength; loop++)
  {
    ICOMSrvDiag_instance.ChDiagOut.TxBuff[loop]=loop;
  }
  #endif

  return retVal;
}

static Std_ReturnType ICOM_updateData (const uint8 *databeginptr, const uint8 *dataendptr, uint8 **pDataUpdate)
{
  ICOM_uDiagFrameHeader   * pICOM_uDiagFrameHeader;
  ICOM_CH_DIAG_FRAME  * pRxFrameHdr;
  Std_ReturnType retVal   = E_NOT_OK;
  uint8 *pSOF             = NULL_PTR;
  ptrdiff_t allowedlength = dataendptr - databeginptr;

    if(allowedlength > 0)
    {
      if (DIAG_RX_BUFFER >= (ICOMSrvDiag_instance.ChDiagIn.RxIndex + ICOM_FRAME_HDR_SIZE + DIAG_HDR_FRAME_SIZE + DIAG_MIN_FRAME_SIZE))
      {
        pSOF = (uint8*)databeginptr;
        pICOM_uDiagFrameHeader = (ICOM_uDiagFrameHeader*)pSOF;

        ICOMSrvDiag_instance.ChDiagInHdr.stDiagFrmHdr.FRAME_TYPE    = pICOM_uDiagFrameHeader->stDiagFrmHdr.FRAME_TYPE;
        ICOMSrvDiag_instance.ChDiagInHdr.stDiagFrmHdr.FRAME_SEQ     = pICOM_uDiagFrameHeader->stDiagFrmHdr.FRAME_SEQ;
        ICOMSrvDiag_instance.ChDiagInHdr.stDiagFrmHdr.FRAME_LENGTH  = pICOM_uDiagFrameHeader->stDiagFrmHdr.FRAME_LENGTH;

        pSOF += ICOM_FRAME_HDR_SIZE;

        pRxFrameHdr = (ICOM_CH_DIAG_FRAME*)pSOF;
        TS_MemCpy(&ICOMSrvDiag_instance.ChDiagIn.RxFrameHdr.array, pRxFrameHdr, DIAG_HDR_FRAME_SIZE);
        pSOF += DIAG_HDR_FRAME_SIZE;
        ICOMSrvDiag_instance.ChDiagIn.RxLength = ICOMSrvDiag_instance.ChDiagInHdr.stDiagFrmHdr.FRAME_LENGTH - ICOM_FRAME_HDR_SIZE - DIAG_HDR_FRAME_SIZE;

        if( (ICOM_CH_DIAG_DATA_FRM == ICOMSrvDiag_instance.ChDiagIn.RxFrameHdr.st.type
                      &&
          (ICOMSrvDiag_instance.ChDiagIn.RxLength > 0)  ) )
        {

          TS_MemCpy (&ICOMSrvDiag_instance.ChDiagIn.RxBuff[ICOMSrvDiag_instance.ChDiagIn.RxIndex], pSOF, ICOMSrvDiag_instance.ChDiagIn.RxLength);
          ICOMSrvDiag_instance.ChDiagIn.RxIndex += ICOMSrvDiag_instance.ChDiagIn.RxLength;

          *pDataUpdate = (uint8 *)(pSOF + ICOMSrvDiag_instance.ChDiagIn.RxLength);

          if (ICOMSrvDiag_instance.ChDiagIn.RxFrameHdr.st.FrameDescription == SOF)
          {
            ICOMSrvDiag_instance.DiagChBusyFlag = TRUE;
          }

          if (ICOMSrvDiag_instance.ChDiagIn.RxFrameHdr.st.FrameDescription == EOF)
          {
            ICOMSrvDiag_instance.DiagChBusyFlag = FALSE;
          }
          retVal = E_OK;
        }
        else if(ICOM_CH_DIAG_CTRL_FRM == ICOMSrvDiag_instance.ChDiagIn.RxFrameHdr.st.type)
        {

          TS_MemCpy (&ICOMSrvDiag_instance.ChDiagIn.RxBuff[ICOMSrvDiag_instance.ChDiagIn.RxIndex], pSOF, ICOMSrvDiag_instance.ChDiagIn.RxLength);
          if (ICOMSrvDiag_instance.ChDiagIn.RxBuff[ICOMSrvDiag_instance.ChDiagIn.RxIndex] == CANCEL)
          {
            ICOMSrvDiag_instance.ChDiagIn.RxIndex = 0;
            TS_MemSet(&ICOMSrvDiag_instance.ChDiagIn.RxBuff[0], 0x00u, DIAG_RX_BUFFER);
            ICOMSrvDiag_instance.DiagChBusyFlag = FALSE;
          }
          else
          {
            ICOMSrvDiag_instance.ChDiagIn.RxIndex += ICOMSrvDiag_instance.ChDiagIn.RxLength;
          }
          *pDataUpdate = (uint8 *)(pSOF + ICOMSrvDiag_instance.ChDiagIn.RxLength);

          retVal = E_OK;
        }
      }
      else
      {
        //set the flag so that the diagnostic can collect the data from the DIAG_RX_BUFFER and then reset the DIAG_RX_BUFFER
        *pDataUpdate = (uint8 *)databeginptr;
        retVal = E_OK;
      }
    }
    else
      {
        *pDataUpdate = NULL_PTR;
        retVal = E_NOT_OK;
      }
  return retVal;
}

static Std_ReturnType ICOM_collectData(const uint8 *databeginptr, const uint8 *dataendptr, uint8 **pDataCollect)
{
  Std_ReturnType retVal = E_NOT_OK;
  ptrdiff_t allowedlength;
  uint16 uDataChunkLen;
  ICOM_uDiagFrameHeader * pICOM_uDiagFrameHeader;
  uint8 *pCurrentData   = NULL_PTR;

  allowedlength = dataendptr - databeginptr;

  if(allowedlength >= ICOM_FRAME_HDR_SIZE + DIAG_HDR_FRAME_SIZE + DIAG_MIN_FRAME_SIZE)
  {
    if (ICOMSrvDiag_instance.ChDiagOut.TxLength >= DIAG_MIN_FRAME_SIZE)
    {
      pCurrentData = (uint8*)databeginptr;
      pICOM_uDiagFrameHeader = (ICOM_uDiagFrameHeader*)pCurrentData;

      ICOMSrvDiag_instance.ChDiagOutHdr.stDiagFrmHdr.FRAME_SEQ++;
      pICOM_uDiagFrameHeader->stDiagFrmHdr.FRAME_TYPE   = ICOMSrvDiag_instance.ChDiagOutHdr.stDiagFrmHdr.FRAME_TYPE;
      pICOM_uDiagFrameHeader->stDiagFrmHdr.FRAME_SEQ    = ICOMSrvDiag_instance.ChDiagOutHdr.stDiagFrmHdr.FRAME_SEQ;
      ICOMSrvDiag_instance.ChDiagOutHdr.stDiagFrmHdr.FRAME_LENGTH = ICOM_FRAME_HDR_SIZE + DIAG_HDR_FRAME_SIZE;

      if(ICOM_CH_DIAG_DATA_FRM == ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.st.type)

      {
        uDataChunkLen = (uint16)(allowedlength - ICOM_FRAME_HDR_SIZE - DIAG_HDR_FRAME_SIZE);
        if (uDataChunkLen > DIAG_MAX_FRAME_SIZE)
        {
          uDataChunkLen = DIAG_MAX_FRAME_SIZE;
        }
        if(ICOMSrvDiag_instance.ChDiagOut.TxLength < uDataChunkLen)
        {
          uDataChunkLen = ICOMSrvDiag_instance.ChDiagOut.TxLength;
          ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.st.FrameDescription = EOF;

        }
        ICOMSrvDiag_instance.ChDiagOutHdr.stDiagFrmHdr.FRAME_LENGTH += uDataChunkLen;
        pICOM_uDiagFrameHeader->stDiagFrmHdr.FRAME_LENGTH = ICOMSrvDiag_instance.ChDiagOutHdr.stDiagFrmHdr.FRAME_LENGTH;

        pCurrentData += ICOM_FRAME_HDR_SIZE;
        if (ICOMSrvDiag_instance.DiagChBusyFlag == FALSE)
        {
          ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.st.FrameDescription = SOF;
          if (uDataChunkLen < DIAG_MAX_FRAME_SIZE)
          {
            ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.st.FrameDescription = EOF;
          }
        }
        ICOMSrvDiag_instance.DiagChBusyFlag = TRUE;

        TS_MemCpy(pCurrentData, ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.array, DIAG_HDR_FRAME_SIZE);
        pCurrentData += DIAG_HDR_FRAME_SIZE;

        TS_MemCpy(pCurrentData,\
                  (uint8 *)&(ICOMSrvDiag_instance.ChDiagOut.TxBuff[ICOMSrvDiag_instance.ChDiagOut.TxIndex]),\
                  uDataChunkLen);
        ICOMSrvDiag_instance.ChDiagOut.TxLength -= uDataChunkLen;
        ICOMSrvDiag_instance.ChDiagOut.TxIndex  += uDataChunkLen;
        *pDataCollect = (uint8 *)(pCurrentData + uDataChunkLen);

        retVal = E_OK;
      }
      else if(ICOM_CH_DIAG_CTRL_FRM == ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.st.type)
      {
        ICOMSrvDiag_instance.DiagChBusyFlag = TRUE;
        ICOMSrvDiag_instance.ChDiagOutHdr.stDiagFrmHdr.FRAME_LENGTH += DIAG_MIN_FRAME_SIZE;

        pCurrentData += ICOM_FRAME_HDR_SIZE;

        TS_MemCpy(pCurrentData, ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.array, DIAG_HDR_FRAME_SIZE);
        pCurrentData += DIAG_HDR_FRAME_SIZE;

        ICOMSrvDiag_instance.ChDiagOut.TxBuff[0]=DiagCmd;
        TS_MemCpy(pCurrentData,\
                  (uint8 *)&(ICOMSrvDiag_instance.ChDiagOut.TxBuff[ICOMSrvDiag_instance.ChDiagOut.TxIndex]),\
                  DIAG_MIN_FRAME_SIZE);
        ICOMSrvDiag_instance.ChDiagOut.TxLength -= DIAG_MIN_FRAME_SIZE;
        ICOMSrvDiag_instance.ChDiagOut.TxIndex  += DIAG_MIN_FRAME_SIZE;
        *pDataCollect = (uint8 *)(pCurrentData + DIAG_MIN_FRAME_SIZE);
        ICOMSrvDiag_instance.DiagChBusyFlag = FALSE;
        retVal = E_OK;
      }
    }
    else
    {
      *pDataCollect = (uint8 *)databeginptr;
      retVal = E_OK;
    }
  }
  else
  {
    *pDataCollect = (uint8 *)databeginptr;
    retVal = E_NOT_OK;
  }
  return retVal;
}

DiagChRsp_t ICOMDiagCh_SendCmd( uint8 *pData, uint16 Length )
{
  static DiagChRsp_t DiagChResponse;

  if ((Length < DIAG_TX_BUFFER) && (Length > 0))
  {
    if( ICOMSrvDiag_instance.DiagChBusyFlag == FALSE)
    {
      TS_MemCpy(&ICOMSrvDiag_instance.ChDiagOut.TxBuff[0], pData, Length);
      ICOMSrvDiag_instance.ChDiagOut.TxIndex            = 0;
      ICOMSrvDiag_instance.ChDiagOut.TxLength           = Length;
      ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.st.type = ICOM_CH_DIAG_DATA_FRM;
      DiagChResponse = WRITE_SUCCESS;
    }
    else
    {
      DiagChResponse = CHANNEL_BUSY;
    }
  }
  else
  {
    DiagChResponse = INCORRECT_LENGTH;
  }
  return DiagChResponse;
}

DiagChRsp_t ICOMDiagCh_GetRsp( uint8 *pData, uint16* pLength )
{
  static DiagChRsp_t DiagChResponse;
  if(*pLength >= ICOMSrvDiag_instance.ChDiagIn.RxLength)
  {
    if(ICOMSrvDiag_instance.DiagChBusyFlag == FALSE)
    {
      if (ICOMSrvDiag_instance.ChDiagIn.RxIndex > 0)
      {
      	TS_MemCpy(pData, &ICOMSrvDiag_instance.ChDiagIn.RxBuff[0], ICOMSrvDiag_instance.ChDiagIn.RxIndex);
      	*pLength = ICOMSrvDiag_instance.ChDiagIn.RxIndex;
        ICOMSrvDiag_instance.ChDiagIn.RxIndex = 0;
        ICOMSrvDiag_instance.ChDiagIn.RxLength = 0;
        DiagChResponse = READ_SUCCESS;
      }
      else
      {
        DiagChResponse = CHANNEL_IDLE;
      }
    }
    else
    {
      DiagChResponse = CHANNEL_BUSY;
    }
  }
  else
  {
    DiagChResponse = INCORRECT_LENGTH;
  }
  return DiagChResponse;
}

/* CANCEL DIAG COMMAND FUNCTION */
Std_ReturnType ICOMDiagCh_CancelCmd(void)
{
  /*discard buffer & Send cancel command to the other side - Control frame instead of data frame*/
  Std_ReturnType retVal = E_NOT_OK;

  TS_MemSet(&ICOMSrvDiag_instance.ChDiagOut.TxBuff[0], 0x00u, DIAG_TX_BUFFER);
  ICOMSrvDiag_instance.ChDiagOut.TxIndex            = 0;
  ICOMSrvDiag_instance.ChDiagOut.TxLength           = DIAG_MIN_FRAME_SIZE;
  ICOMSrvDiag_instance.ChDiagOut.TxFrameHdr.st.type = ICOM_CH_DIAG_CTRL_FRM;
  DiagCmd = CANCEL;

  retVal = E_OK;

  return retVal;

}

boolean ICOMDiagCh_CheckBusyFlag(void)
{
  return ICOMSrvDiag_instance.DiagChBusyFlag;
}