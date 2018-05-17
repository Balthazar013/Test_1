/**
* @brief General Purpose Timer, to be used by other components for the timeout calculations
*
* @copyright Copyright (c) 2015-2017 Bombardier Transportation. All rights reserved.
*
* @file $RCSfile$
* @author $Author: Muhammad$
* @date $Date: 21.02.2018$
* @version $Revision: 1.2$
*/

#include <Gpt.h>
#include <stddef.h>
#include "SwGPT.h"
//---------------------------------------------------------------------------------------------------------------------
// MAKRO DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------
#define PBRIDGE_FREQUENCY_HZ          (uint32)45000000
#define RESOLUTION_GPT_MS             (uint32)10
#define RESOLUTION_GPT_PBRIDGE_TICKS  (uint32)(PBRIDGE_FREQUENCY_HZ * RESOLUTION_GPT_MS / 1000)

//---------------------------------------------------------------------------------------------------------------------
// TYPE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

typedef struct
{
 uint32         ulTimeoutInGPTCyC;
 SwGPTFnPtr     pfCbkTimeout;
 uint32         ulCountStamp;
 boolean        bActivateSupervision;
} SwGPTEntry;                                   //Structure to maintain entries for each software GPT

typedef struct
{
  uint32        SwGPTCnt;
  SwGPTEntry    SwGPTEntryList[MAX_CHANNEL_ID];
  SwGPTEntry *  first_free;
  boolean       bSwGPTInitdone;
} SwGPT_Instance;

//---------------------------------------------------------------------------------------------------------------------
// VARIABLE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

SwGPT_Instance sSwGPTInst;

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType SwGPT_Register (SwGPTFnPtr pfCbkTimeout,uint32 ulTimeout, SwGPT_ChannelID* ptrSwGPTCh)
{ 
  Std_ReturnType retVal = E_NOT_OK;
  ptrdiff_t idx;
  
  if(sSwGPTInst.bSwGPTInitdone == FALSE)
  {
    SwGpt_Init();
  }
  else
  {
    
  }
  
  if((ulTimeout != 0) && (ulTimeout >= RESOLUTION_GPT_MS) && ((ulTimeout % RESOLUTION_GPT_MS) == 0) && (pfCbkTimeout != NULL_PTR))
  {
    idx = sSwGPTInst.first_free - sSwGPTInst.SwGPTEntryList;
    if(idx <= MAX_CHANNEL_ID)
    {
      sSwGPTInst.SwGPTEntryList[idx].pfCbkTimeout = pfCbkTimeout;
      sSwGPTInst.SwGPTEntryList[idx].ulTimeoutInGPTCyC = (ulTimeout/RESOLUTION_GPT_MS);
      *ptrSwGPTCh = (uint32)idx;
      ++sSwGPTInst.first_free;
      retVal= E_OK;
    }
    else
    {
      
    }
  }
  else
  {
    
  }
  
  return retVal;
}

Std_ReturnType SwGPT_Deregister (SwGPT_ChannelID eSwGPTCh)
{
  uint8 loop;
  Std_ReturnType retVal = E_NOT_OK;
  if(eSwGPTCh <= MAX_CHANNEL_ID)
  {
    sSwGPTInst.SwGPTEntryList[eSwGPTCh].pfCbkTimeout = NULL_PTR;
    sSwGPTInst.SwGPTEntryList[eSwGPTCh].ulTimeoutInGPTCyC = 0;
    sSwGPTInst.SwGPTEntryList[eSwGPTCh].ulCountStamp = 0;
    sSwGPTInst.SwGPTEntryList[eSwGPTCh].bActivateSupervision = FALSE;
    
    for (loop=eSwGPTCh; loop < MAX_CHANNEL_ID; loop++)
    {
      sSwGPTInst.SwGPTEntryList[eSwGPTCh]=sSwGPTInst.SwGPTEntryList[eSwGPTCh+1];
    }
    --sSwGPTInst.first_free;
    retVal= E_OK;
  }
  else
  {
    
  }
  return retVal;
}

Std_ReturnType SwGPT_Start (SwGPT_ChannelID eSwGPTCh)
{
  Std_ReturnType retVal = E_NOT_OK;
  if(eSwGPTCh < MAX_CHANNEL_ID)
  {
    sSwGPTInst.SwGPTEntryList[eSwGPTCh].ulCountStamp = sSwGPTInst.SwGPTCnt;
    sSwGPTInst.SwGPTEntryList[eSwGPTCh].bActivateSupervision= TRUE;
    retVal= E_OK;
  }
  else
  {
    
  }
  return retVal;
}

Std_ReturnType SwGPT_Stop (SwGPT_ChannelID eSwGPTCh)
{
  Std_ReturnType retVal = E_NOT_OK;
  if(eSwGPTCh < MAX_CHANNEL_ID)
  {
    sSwGPTInst.SwGPTEntryList[eSwGPTCh].bActivateSupervision = FALSE;
    retVal= E_OK;
  }
  else
  {
    
  }
    return retVal;
}

Std_ReturnType SwGPT_SetTimeout(SwGPT_ChannelID eSwGPTCh, uint32 ulTimeout)
{
    if(eSwGPTCh < MAX_CHANNEL_ID)
    {
        if((ulTimeout!=0) &&((ulTimeout % RESOLUTION_GPT_MS) == 0))
        {
            sSwGPTInst.SwGPTEntryList[eSwGPTCh].bActivateSupervision = FALSE;
            sSwGPTInst.SwGPTEntryList[eSwGPTCh].ulTimeoutInGPTCyC = (ulTimeout/RESOLUTION_GPT_MS);
            return E_OK;
        }
    }
    return E_NOT_OK;
}

//----------------------------------------------------------------------------
// FUNCTION DEFINITIONS
//----------------------------------------------------------------------------

void SwGpt_GptNotification(void)
{
  SwGPTEntry* start = &sSwGPTInst.SwGPTEntryList[0];
  ++sSwGPTInst.SwGPTCnt;
  while(start < sSwGPTInst.first_free)
  {
    if(TRUE == start->bActivateSupervision)
    {
      if ((uint32)((sint32)sSwGPTInst.SwGPTCnt - (sint32)(start->ulCountStamp)) > start->ulTimeoutInGPTCyC) //typecasting to preventing overflow
      {
        start->pfCbkTimeout();
        start->ulCountStamp = sSwGPTInst.SwGPTCnt;
      }
      else
      {
        
      }
    }
    else
    {
      
    }
    ++start;
  }
}


void SwGpt_Init(void)
{
  uint8 entry;
  
  // APIs for the GPT which are needed in addition to the Tresos Configuration
  Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChCfg_SwGpt);
  Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChCfg_SwGpt, RESOLUTION_GPT_PBRIDGE_TICKS);
  
  // Initialization of the instance
  sSwGPTInst.first_free=&sSwGPTInst.SwGPTEntryList[0];
  for (entry=0; entry < (MAX_CHANNEL_ID); entry++)
  {
    sSwGPTInst.SwGPTEntryList[entry].pfCbkTimeout = NULL_PTR;
    sSwGPTInst.SwGPTEntryList[entry].ulTimeoutInGPTCyC = 0;
    sSwGPTInst.SwGPTEntryList[entry].ulCountStamp = 0;
    sSwGPTInst.SwGPTEntryList[entry].bActivateSupervision = FALSE;
  }
  sSwGPTInst.bSwGPTInitdone = TRUE;
}