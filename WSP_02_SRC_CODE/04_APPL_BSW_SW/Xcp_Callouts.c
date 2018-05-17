/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#include <Xcp_Trace.h>
#include <Xcp_Cbk.h>           /* callbacks and callouts of Xcp */
#include <TSAutosar.h>         /* EB specific standard types, TS_PARAM_UNUSED*/
#include <Xcp_UserCallouts.h>  /* Xcp callouts */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/
extern void Appl_SetCalPage(uint8 calpage);
extern uint32 Appl_GetCalPageAddress(uint8 calpage);

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/
extern uint8 WspProtec_10ms_PageSwtVar;
/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

#define XCP_START_SEC_APPL_CODE
#include <MemMap.h>

/*------------------[Callouts to compare key]--------------------------------*/

FUNC(Std_ReturnType, XCP_APPL_CODE) Xcp_ApplCompareKey
(
  uint8 ResourceIdentifier,
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) KeyBufferPtr,
  uint8 KeyLength
)
{
  DBG_XCP_APPLCOMPAREKEY_ENTRY(ResourceIdentifier,KeyBufferPtr,KeyLength);
  TS_PARAM_UNUSED(ResourceIdentifier); /* Remove if parameter is used */
  TS_PARAM_UNUSED(KeyBufferPtr); /* Remove if parameter is used */
  TS_PARAM_UNUSED(KeyLength); /* Remove if parameter is used */

  /* insert your code here */
  DBG_XCP_APPLCOMPAREKEY_EXIT(E_OK,ResourceIdentifier,KeyBufferPtr,KeyLength);

  return E_OK;
}

/*------------------[Callouts to generate seed]------------------------------*/

FUNC(Std_ReturnType, XCP_APPL_CODE) Xcp_ApplGetSeed
(
  uint8 ResourceIdentifier,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) SeedBufferPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) SeedBufferLengthPtr
)
{
  DBG_XCP_APPLGETSEED_ENTRY(ResourceIdentifier,SeedBufferPtr,SeedBufferLengthPtr);
  TS_PARAM_UNUSED(ResourceIdentifier);  /* Remove if parameter is used */
  TS_PARAM_UNUSED(SeedBufferPtr);       /* Remove if parameter is used */
  TS_PARAM_UNUSED(SeedBufferLengthPtr); /* Remove if parameter is used */

  /* insert your code here */


  DBG_XCP_APPLGETSEED_EXIT(E_OK,ResourceIdentifier,SeedBufferPtr,SeedBufferLengthPtr);
  return E_OK;
}
/*------------------[Callout for PROGRAM_START]------------------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplProgramStart
(
  P2VAR(uint16, AUTOMATIC, XCP_APPL_DATA) ErrorCodePtr
)
{
  *ErrorCodePtr = 0U; /* Remove if function is used */

  /* insert your code here */

  return XCP_APPL_OK;
}

/*------------------[Callout for PROGRAM_CLEAR]------------------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplProgramClear
(
  P2VAR(void, AUTOMATIC, XCP_APPL_DATA) AddressPtr,
  uint32 ClearRange
)
{
  TS_PARAM_UNUSED(AddressPtr); /* Remove if parameter is used */
  TS_PARAM_UNUSED(ClearRange); /* Remove if parameter is used */

  /* insert your code here */

  return XCP_APPL_OK;
}

/*------------------[Callout for PROGRAM/PROGRAM_NEXT/PROGRAM_MAX]----------------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplProgram
(
  P2VAR(void, AUTOMATIC, XCP_APPL_DATA) AddressPtr,
  P2CONST( uint8, AUTOMATIC, XCP_APPL_DATA ) DataPtr,
  uint16 DataLength
)
{
  TS_PARAM_UNUSED(AddressPtr); /* Remove if parameter is used */
  TS_PARAM_UNUSED(DataPtr); /* Remove if parameter is used */
  TS_PARAM_UNUSED(DataLength); /* Remove if parameter is used */

  /* insert your code here */

  return XCP_APPL_OK;
}

/*------------------[Callout for PROGRAM_RESET]------------------------------*/

FUNC(void, XCP_APPL_CODE) Xcp_ApplProgramReset(void)
{

  /* insert your code here */

}

/*------------------[Callout for GET_PGM_PROCESSOR_INFO]------------------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetPgmProcessorInfo
(
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) MaxSectorPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) PgmPropertiesPtr
)
{
  Xcp_ApplReturnType RetValue = XCP_APPL_OK;

  TS_PARAM_UNUSED(MaxSectorPtr);     /* Remove if parameter is used */
  TS_PARAM_UNUSED(PgmPropertiesPtr); /* Remove if parameter is used */

  DBG_XCP_APPLGETPGMPROCESSORINFO_ENTRY(MaxSectorPtr, PgmPropertiesPtr);

  /* insert your code here */

  DBG_XCP_APPLGETPGMPROCESSORINFO_EXIT(MaxSectorPtr, PgmPropertiesPtr, RetValue);

  return RetValue;
}

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetSectorInfo
(
  uint8 Mode,
  uint8 Sector,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) MtaPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) CommandResponsePtr
)
{
  Xcp_ApplReturnType RetValue = XCP_APPL_OK;

  TS_PARAM_UNUSED(Mode);               /* Remove if parameter is used */
  TS_PARAM_UNUSED(Sector);             /* Remove if parameter is used */
  TS_PARAM_UNUSED(MtaPtr);             /* Remove if parameter is used */
  TS_PARAM_UNUSED(CommandResponsePtr); /* Remove if parameter is used */

  DBG_XCP_APPLGETSECTORINFO_ENTRY(Mode, Sector, MtaPtr, CommandResponsePtr);

  /* insert your code here */

  DBG_XCP_APPLGETSECTORINFO_EXIT(Mode, Sector, MtaPtr, CommandResponsePtr, RetValue);

  return RetValue;
}

/*------------------[Callout for command Calibration Page Initialization]----*/

FUNC(void, XCP_APPL_CODE) Xcp_ApplCalPagInit
(
  void
)
{
  DBG_XCP_APPLCALPAGINIT_ENTRY();

  /* insert your code here */

  DBG_XCP_APPLCALPAGINIT_EXIT();
}

/*------------------[Callout for command COPY_CAL_PAGE]----------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplCopyCalPage
(
  uint8 SrcSegment,
  uint8 SrcPage,
  uint8 DestSegment,
  uint8 DestPage
)
{

  DBG_XCP_APPLCOPYCALPAGE_ENTRY(SrcSegment,SrcPage,DestSegment,DestPage);
  TS_PARAM_UNUSED( SrcSegment );  /* Remove if parameter is used */
  TS_PARAM_UNUSED( SrcPage );     /* Remove if parameter is used */
  TS_PARAM_UNUSED( DestSegment ); /* Remove if parameter is used */
  TS_PARAM_UNUSED( DestPage );    /* Remove if parameter is used */

  /* insert your code here */


  DBG_XCP_APPLCOPYCALPAGE_EXIT(XCP_APPL_OK,SrcSegment,SrcPage,DestSegment,DestPage);
  return XCP_APPL_OK;
}

/*------------------[Callout for command GET_PAG_PROCESSOR_INFO]-------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetPagProcessorInfo
(
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) MaxSegmentPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) PagPropertiesPtr
)
{

  DBG_XCP_APPLGETPAGPROCESSORINFO_ENTRY(MaxSegmentPtr,PagPropertiesPtr);
  *MaxSegmentPtr    = 0U; /* Remove if function is used */
  *PagPropertiesPtr = 0U; /* Remove if function is used */

  /* insert your code here */


  DBG_XCP_APPLGETPAGPROCESSORINFO_EXIT(XCP_APPL_OK,MaxSegmentPtr,PagPropertiesPtr);
  return XCP_APPL_OK;
}

/*------------------[Callout for command GET_CAL_PAGE]-----------------------*/


FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetCalPage
(
  uint8 Segment,
  uint8 Mode,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) PagePtr
)
{

  DBG_XCP_APPLGETCALPAGE_ENTRY(Segment,Mode,PagePtr);
  TS_PARAM_UNUSED( Segment ); /* Remove if parameter is used */
  TS_PARAM_UNUSED( Mode );    /* Remove if parameter is used */
  
  *PagePtr = WspProtec_10ms_PageSwtVar;
  
  DBG_XCP_APPLGETCALPAGE_EXIT(XCP_APPL_OK,Segment,Mode,PagePtr);
  return XCP_APPL_OK;
}

/*------------------[Callout for command SET_CAL_PAGE]-----------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplSetCalPage
(
  uint8 Segment,
  uint8 Page,
  uint8 Mode
)
{

  DBG_XCP_APPLSETCALPAGE_ENTRY(Segment,Page,Mode);
  TS_PARAM_UNUSED( Segment ); /* Remove if parameter is used */
  TS_PARAM_UNUSED( Mode );    /* Remove if parameter is used */

  /* insert your code here */
  Appl_SetCalPage(Page);

  DBG_XCP_APPLSETCALPAGE_EXIT(XCP_APPL_OK,Segment,Page,Mode);
  return XCP_APPL_OK;
}

/*------------------[Callout for command GET_SEGMENT_MODE]-------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetSegmentMode
(
  uint8 Segment,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) ModePtr
)
{

  DBG_XCP_APPLGETSEGMENTMODE_ENTRY(Segment,ModePtr);
  TS_PARAM_UNUSED( Segment ); /* Remove if parameter is used */

  /* insert your code here */
  *ModePtr = 0U;                 /* Remove if function is used */


  DBG_XCP_APPLGETSEGMENTMODE_EXIT(XCP_APPL_OK,Segment,ModePtr);
  return XCP_APPL_OK;
}

/*------------------[Callout for command SET_SEGMENT_MODE]-------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplSetSegmentMode
(
  uint8 Segment,
  uint8 Mode
)
{

  DBG_XCP_APPLSETSEGMENTMODE_ENTRY(Segment,Mode);
  TS_PARAM_UNUSED( Segment ); /* Remove if parameter is used */
  TS_PARAM_UNUSED( Mode );    /* Remove if parameter is used */

  /* insert your code here */


  DBG_XCP_APPLSETSEGMENTMODE_EXIT(XCP_APPL_OK,Segment,Mode);
  return XCP_APPL_OK;
}

/*------------------[Callout for command GET_SEGMENT_INFO]-------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetSegmentInfo
(
  uint8 Mode,
  uint8 Segment,
  uint8 SegmentInfo,
  uint8 MappingIndex,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) CommandResponsePtr
)
{

  DBG_XCP_APPLGETSEGMENTINFO_ENTRY(Mode,Segment,SegmentInfo,MappingIndex,CommandResponsePtr);
  TS_PARAM_UNUSED( Mode );         /* Remove if parameter is used */
  TS_PARAM_UNUSED( Segment );      /* Remove if parameter is used */
  TS_PARAM_UNUSED( SegmentInfo );  /* Remove if parameter is used */
  TS_PARAM_UNUSED( MappingIndex ); /* Remove if parameter is used */

  /* insert your code here */
  *CommandResponsePtr = 0U;        /* Remove if function is used */


  DBG_XCP_APPLGETSEGMENTINFO_EXIT(XCP_APPL_OK,Mode,Segment,SegmentInfo,MappingIndex,CommandResponsePtr);
  return XCP_APPL_OK;
}

/*------------------[Callout for command GET_PAGE_INFO]----------------------*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetPageInfo
(
  uint8 Segment,
  uint8 Page,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) PagePropertiesPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) InitSegmentPtr
)
{

  DBG_XCP_APPLGETPAGEINFO_ENTRY(Segment,Page,PagePropertiesPtr,InitSegmentPtr);
  TS_PARAM_UNUSED( Segment );      /* Remove if parameter is used */
  TS_PARAM_UNUSED( Page );         /* Remove if parameter is used */

  *PagePropertiesPtr = 0U;         /* Remove if function is used */
  *InitSegmentPtr = 0U;            /* Remove if function is used */

  /* insert your code here */


  DBG_XCP_APPLGETPAGEINFO_EXIT(XCP_APPL_OK,Segment,Page,PagePropertiesPtr,InitSegmentPtr);
  return XCP_APPL_OK;
}

/*------------------[Callout for command SET_REQUEST - STORE_CAL_REQ Mode]---*/

FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplSetReqStoreCalReq
(
  void
)
{
  DBG_XCP_APPLSETREQSTORECALREQ_ENTRY();

  /* insert your code here */


  DBG_XCP_APPLSETREQSTORECALREQ_EXIT(XCP_APPL_OK);
  return XCP_APPL_OK;
}


#define XCP_STOP_SEC_APPL_CODE
#include <MemMap.h>

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
