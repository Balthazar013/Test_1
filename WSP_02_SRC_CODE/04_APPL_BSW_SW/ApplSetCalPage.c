#include <Std_Types.h> 

extern uint8 WspProtec_10ms_PageSwtVar;
extern uint8 WspProtec_100ms_PageSwtVar;
extern uint8 WspSfty_State_PageSwtVar;
extern uint8 WspSfty_Calc_PageSwtVar;
extern uint8 WspSfty_Pinch_PageSwtVar;
extern uint8 WspSfty_Calc_PageSwtVar;

extern uint8 WspFlsMgr_PageSwtVar;

extern uint8 PwrTrf_PageSwtVar;
extern uint8 SCIF_WSP_POSMGR_PageSwtVar;
extern uint8 WspVehDet_PageSwtVar;
extern uint8 WspIoHwAb_Calc_PageSwtVar;
extern uint8 WspStMgr_PageSwtVar;
extern uint8 WspFOD_PageSwtVar;
extern uint8 WspB6cdd_PageSwtVar;
extern uint8 LedSwc_PageSwtVar;
extern uint8 PFC_PageSwtVar;
extern uint8 ZMControl_PageSwtVar; 

extern void WspFOD_PageSwtFunc(void);
extern void WspProtec_10ms_PageSwtFunc(void);
extern void WspProtec_100ms_PageSwtFunc(void);
extern void WspSfty_Calc_PageSwtFunc(void);
extern void WspSfty_Pinch_PageSwtFunc(void);
extern void WspSfty_State_PageSwtFunc(void);
extern void WspFlsMgr_PageSwtFunc(void);
extern void PwrTrf_PageSwtFunc(void);
extern void SCIF_WSP_POSMGR_PageSwtFunc(void);
extern void WspVehDet_PageSwtFunc(void);
extern void WspIoHwAb_Calc_PageSwtFunc(void);
extern void WspStMgr_PageSwtFunc(void);
extern void WspB6cdd_PageSwtFunc(void);
extern void LedSwc_PageSwtFunc(void);
extern void PFC_PageSwtFunc(void);
extern void ZMControl_PageSwtFunc(void);

extern uint32 __REF_PAGE_START;         /* defined in the linker file */
extern uint32 __WORK_PAGE_START;        /* defined in the linker file */
extern uint32 __REF_PAGE_TOTAL_SIZE;    /* defined in the linker file */

uint32 Appl_GetCalPageAddress(uint8 calpage)
{
    if(calpage==0)          /* FLASH    */
    {
        return (uint32)&__REF_PAGE_START;
    }
    else                    /* RAM      */
    {
        return (uint32)&__WORK_PAGE_START;
    }
}


void InitWorkPage(void)
{
 uint32* wp = (uint32 *)&__WORK_PAGE_START; /* Startadresse XCP Work Page */
 uint32* rp = (uint32 *)&__REF_PAGE_START; /* Startadresse XCP Reference  Page */
 uint16 i;
 static uint16 szCnt = 0x4000;
 
 for(i=0; i < szCnt; ++i) /* Copy XCP Reference Page to Work Page */
 {
  wp[i] = rp[i];
 }
}

void Appl_SetCalPage(uint8 calpage)
{
 
  WspStMgr_PageSwtVar = calpage;
  WspStMgr_PageSwtFunc();
 
  WspProtec_10ms_PageSwtVar = calpage;
  WspProtec_10ms_PageSwtFunc();
  
  WspProtec_100ms_PageSwtVar = calpage;
  WspProtec_100ms_PageSwtFunc();
  
  WspSfty_Calc_PageSwtVar = calpage;
  WspSfty_Calc_PageSwtFunc();
  
  WspSfty_Pinch_PageSwtVar  = calpage;
  WspSfty_Pinch_PageSwtFunc();
  
  WspSfty_State_PageSwtVar  = calpage;
  WspSfty_State_PageSwtFunc();
  
  WspFlsMgr_PageSwtVar  = calpage;
  WspFlsMgr_PageSwtFunc();
    
  SCIF_WSP_POSMGR_PageSwtVar = calpage;
  SCIF_WSP_POSMGR_PageSwtFunc();
    
  WspVehDet_PageSwtVar = calpage;
  WspVehDet_PageSwtFunc();
  
  WspIoHwAb_Calc_PageSwtVar = calpage;
  WspIoHwAb_Calc_PageSwtFunc();
  
  WspB6cdd_PageSwtVar = calpage;
  WspB6cdd_PageSwtFunc();  
#if 0
  WspFOD_PageSwtVar = calpage;
  WspFOD_PageSwtFunc();
#endif
  PwrTrf_PageSwtVar = calpage;
  PwrTrf_PageSwtFunc();
  
  LedSwc_PageSwtVar = calpage;
  LedSwc_PageSwtFunc();
  
  PFC_PageSwtVar = calpage;
  PFC_PageSwtFunc();
  
  ZMControl_PageSwtVar = calpage;
  ZMControl_PageSwtFunc();
}
