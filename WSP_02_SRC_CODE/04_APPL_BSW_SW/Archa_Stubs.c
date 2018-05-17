
#include <RTE_SCI_DiagRtn_Type.h>

void BswSCI_B6Bridge_BswMainFunction (void)
{}

void BswSCI_ZMover_BswMainFunction  (void)
{}


uint16 Rte_IRead_DiagMeas_MainFunction_WspPosMgr_posActual_X(void) 
{}

uint16 Rte_IRead_DiagMeas_MainFunction_WspPosMgr_posActual_Y(void) 
{}

uint16 Rte_IRead_DiagMeas_MainFunction_WspPosMgr_posActual_Theta(void) 
{}

void SCI_DiagCtrl_Result()
{}

void SystemTracing_SystemTracing_10ms(){}
void SystemTracing_Background(){}
void T1_RxIndication(){}

#ifndef T1_ENABLED
void TraceInit( void ){}
void TraceStateChangeTask( os_taskid_t StateId, os_taskid_t oldValue, os_taskid_t newValue ){}
void TraceStateChangeIsr( os_uchar_t IsrId, os_uchar_t newValue ){}
#endif