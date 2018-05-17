/**
* @brief 
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
#include "ICOM.h"

//---------------------------------------------------------------------------------------------------------------------
// MAKRO DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

#define MAX_PAYLOAD_LENGTH        80
#define ICOM_INST_MAX             1

//---------------------------------------------------------------------------------------------------------------------
// TYPE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

typedef struct 
{
  ICOM_INST   ICOM_Instance_List[ICOM_INST_MAX];
  ICOM_INST   *first_free;
  boolean     bIComSrvInitDone;
} ICOM_SRV;

//---------------------------------------------------------------------------------------------------------------------
// VARIABLE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------
static ICOM_SRV sICOMSrvData;


//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType ICOM_GetChannelIndex(ICOM_INST* ICOMSrv_Instance, uint8 FrameType, uint8* puChIdx);

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DEFINITIONS
//---------------------------------------------------------------------------------------------------------------------

void ICOM_SRV_Init (void)
{
  sICOMSrvData.first_free   =&sICOMSrvData.ICOM_Instance_List[0];
  sICOMSrvData.bIComSrvInitDone = TRUE;
}

ICOM_INST* ICOM_Create(void)
{
  ptrdiff_t index;
  ICOM_INST * pICOMInstance;
  
  if(FALSE == sICOMSrvData.bIComSrvInitDone)
  {
    ICOM_SRV_Init();
  }
  
  index = sICOMSrvData.first_free - sICOMSrvData.ICOM_Instance_List;
  pICOMInstance = NULL_PTR;
  if(index < ICOM_INST_MAX)
  {
    pICOMInstance = sICOMSrvData.first_free;
    pICOMInstance->first_free_idx = 0;
    pICOMInstance->first_free_CollBuff_idx = 0;
    ++sICOMSrvData.first_free;
  }
  return pICOMInstance;
}

Std_ReturnType ICOM_onCollectFrame(ICOM_INST *ICOMSrv_Instance, const uint8 *databeginpointer, const uint8 Length, uint8* WrittenLength)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 loop;
  uint8 *startofframeptr = NULL_PTR;
  uint8 *dataendptr = NULL_PTR;
  uint8 *DataCollect = NULL_PTR;

  startofframeptr = (uint8 *)databeginpointer;
  dataendptr = (uint8 *)startofframeptr + Length;

  for(loop=0; loop < ICOMSrv_Instance->first_free_idx; loop++)
  {
    switch(ICOMSrv_Instance->ICOM_CH_INFO_list[loop].pICOM_CH->uFrameType)
    {
      case FRAME_TYPE_STATUS:
      {
        if (E_OK == ICOMSrv_Instance->ICOM_CH_INFO_list[loop].pICOM_CH->fpCollect(startofframeptr, dataendptr, &DataCollect))
        {
          *WrittenLength = (uint8 *)(DataCollect) - (uint8 *)startofframeptr;
          startofframeptr = (uint8 *)(DataCollect);
          retVal = E_OK;
          break;
        }
        
      }
      case FRAME_TYPE_DIAG:
      {
        
        if (E_OK == ICOMSrv_Instance->ICOM_CH_INFO_list[loop].pICOM_CH->fpCollect(startofframeptr, dataendptr, &DataCollect))
        {
          *WrittenLength += (uint8 *)(DataCollect) - (uint8 *)startofframeptr;
          startofframeptr = (uint8 *)(DataCollect);
          retVal = E_OK;
          break;
        }
        
      }
      case FRAME_TYPE_FLS:
      {
        
      }
      case FRAME_TYPE_REMOTE_ACCESS:
      {
        
      }
      default:
    }
  }
    return retVal;
}

Std_ReturnType ICOM_onReceivedFrame(ICOM_INST *ICOMSrv_Instance, const uint8 *databeginpointer, const uint8 *dataendpointer)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 *startofframeptr = NULL_PTR;
  uint8 *endofframeptr   = NULL_PTR;
  uint8 uChIdx = 0;
  uint8 *pDataUpdate = NULL_PTR;
  ICOM_uDummyFrameHeader  *pICOM_uDummyFrameHeader;
  ICOM_uStsFrameHeader    *pICOM_uStsFrameHeader;
  ICOM_uDiagFrameHeader   *pICOM_uDiagFrameHeader;
  
  //assign to the internal pointer
  startofframeptr = (uint8 *)databeginpointer;
  
  //SE
  while (startofframeptr<dataendpointer)
  {
    //masking the received databeginpointer(startofframeptr) to the pointer to the frameheader to extract/access the frameheader
    pICOM_uDummyFrameHeader = (ICOM_uDummyFrameHeader*)startofframeptr;
    pICOM_uStsFrameHeader   = (ICOM_uStsFrameHeader*)startofframeptr;
    pICOM_uDiagFrameHeader  = (ICOM_uDiagFrameHeader*)startofframeptr;
    
    switch(pICOM_uDummyFrameHeader->st.FRAME_TYPE)
    {
      case FRAME_TYPE_STATUS:
      {
        
        endofframeptr= startofframeptr + pICOM_uStsFrameHeader->stStsFrmHdr.FRAME_LENGTH;
        //Get the channel index from the channel list
        if(ICOM_GetChannelIndex(ICOMSrv_Instance, FRAME_TYPE_STATUS, &uChIdx) == E_NOT_OK)
        {
          startofframeptr = endofframeptr;
          retVal = E_NOT_OK;
          break;
        }
        //calling the updatedata fn from the ICOM_Channel through a fn pointer & passing the frame without the header
        ICOMSrv_Instance->ICOM_CH_INFO_list[uChIdx].pICOM_CH->fpUpdate(startofframeptr, endofframeptr, &pDataUpdate);
        //updating the start pointer to point to the next frame type in the channel list 
        if ((pDataUpdate != NULL_PTR) && (pDataUpdate != startofframeptr))
        {
          startofframeptr = pDataUpdate;
        }
        else
        {
          startofframeptr = endofframeptr;
        }
        retVal = E_OK;
        break;
      }
      
      case FRAME_TYPE_DIAG:
      {
        endofframeptr= startofframeptr + pICOM_uDiagFrameHeader->stDiagFrmHdr.FRAME_LENGTH;
        //Get the channel index from the channel list
        if(ICOM_GetChannelIndex(ICOMSrv_Instance, FRAME_TYPE_DIAG, &uChIdx) == E_NOT_OK)
        {
          startofframeptr = endofframeptr;
          retVal = E_NOT_OK;
          break;
        }
        
        ICOMSrv_Instance->ICOM_CH_INFO_list[uChIdx].pICOM_CH->fpUpdate(startofframeptr, endofframeptr, &pDataUpdate);
        if ((pDataUpdate != NULL_PTR) && (pDataUpdate != startofframeptr))
        {
          startofframeptr = pDataUpdate;
        }
        else
        {
          startofframeptr = endofframeptr;
        }
        
        retVal = E_OK;
        break;
      }
    
      case FRAME_TYPE_FLS:
      {
            break;
      }
    
      case FRAME_TYPE_REMOTE_ACCESS:
      {
            break;
      }
      
      default:
      {
        retVal = E_NOT_OK; 
        return retVal; // TODO(TT):
      }
    }
  }
    return retVal;
}

Std_ReturnType ICOM_openChannel(ICOM_INST *ICOMSrv_Instance, ICOM_CH *ICOM_Channel)
{
  Std_ReturnType retVal = E_NOT_OK;
  //Bound Check
  if (ICOMSrv_Instance->first_free_idx < ICOM_CH_MAX)
  {
    uint8 i,key=0;
    sint8 j;
    
    //Check if any channel with same priority is already registered
    for (i=0; i < ICOMSrv_Instance->first_free_idx; i++)
    {
      if(ICOMSrv_Instance->ICOM_CH_INFO_list[i].pICOM_CH->uPriority == ICOM_Channel->uPriority)
      {
        retVal = E_NOT_OK;
      }
    }
    //Assign the channel pointer to the ICOM Channel pointer list and the internal collect-buffer pointer
    ICOMSrv_Instance->ICOM_CH_INFO_list[ICOMSrv_Instance->first_free_idx].pICOM_CH        = ICOM_Channel;
    ICOMSrv_Instance->ICOM_CH_INFO_list[ICOMSrv_Instance->first_free_idx].pCollectBuffer  = &(ICOMSrv_Instance->CollectBuffer[ICOMSrv_Instance->first_free_CollBuff_idx]);
      
    //update the first free pointers
    ++ICOMSrv_Instance->first_free_idx;
    ICOMSrv_Instance->first_free_CollBuff_idx += CHANNEL_BUFFER_LENGTH;
    
    //Insertion Sorting (from the highest to the lowest priority of the channel list)
      //The pointer to the pCollectBuffer need not to be moved as the buffer is associated with the channel itself
    for (i=0 ; i< ICOMSrv_Instance->first_free_idx ; i++)
    {
      key = ICOMSrv_Instance->ICOM_CH_INFO_list[i].pICOM_CH->uPriority;
      j=i-1;
      
      while (j>=0 && (ICOMSrv_Instance->ICOM_CH_INFO_list[j].pICOM_CH->uPriority) > key)
      {
        ICOMSrv_Instance->ICOM_CH_INFO_list[j+1].pICOM_CH = ICOMSrv_Instance->ICOM_CH_INFO_list[j].pICOM_CH;
        j = -1;
      }
      ICOMSrv_Instance->ICOM_CH_INFO_list[j+1].pICOM_CH = ICOMSrv_Instance->ICOM_CH_INFO_list[i].pICOM_CH;
    }
    retVal = E_OK;
  }
  return retVal;
}

Std_ReturnType ICOM_closeChannel(ICOM_INST *ICOMSrv_Instance, ICOM_CH *ICOM_Channel)
{
  uint8 i,j;
  Std_ReturnType retVal = E_NOT_OK;
  //Loop through the registered channel list to find if the given channel 
  for (i=0; i < ICOMSrv_Instance->first_free_idx; i++)
  {
    if(ICOMSrv_Instance->ICOM_CH_INFO_list[i].pICOM_CH == ICOM_Channel)
    {
      //if found, restructure the list (from the highest to the lowest priority)
      for(j=i; j< ICOMSrv_Instance->first_free_idx; j++)
      {
        ICOMSrv_Instance->ICOM_CH_INFO_list[j].pICOM_CH = ICOMSrv_Instance->ICOM_CH_INFO_list[j+1].pICOM_CH;
      }
      --ICOMSrv_Instance->first_free_idx;
      retVal= E_OK;
    }
  }
  return retVal;
}

//Function to get the index of the channel i.e. where the channel is located in the channel list
Std_ReturnType ICOM_GetChannelIndex(ICOM_INST *ICOMSrv_Instance, uint8 FrameType, uint8* puChIdx)
{
  Std_ReturnType status;
  uint8 loop;
  status = E_NOT_OK;
  
  //Loop through the channel list to find the given channel based on the frame type
  for(loop=0; loop < ICOMSrv_Instance->first_free_idx; loop++)
  {
    if (ICOMSrv_Instance->ICOM_CH_INFO_list[loop].pICOM_CH->uFrameType == FrameType)
    {
      *puChIdx= loop;
      status = E_OK;
      break;
    }
  }
  return status;
}

