#include "Com_Callouts.h"

#define _USE_CAN_TIMEOUT_ 0

#if _USE_CAN_TIMEOUT_
uint32 canTimeout = 0;
#endif

void Appl_COMCbkTOut_Com_COM_I_DC_ACT_ORU__DEV_AWC_Resp_62__MLBevo_HCAN(void)
{
#if _USE_CAN_TIMEOUT_
	timeout |= 0x00000001;
#endif
}
	

void Appl_COMCbkTOut_Com_COM_I_DC_REQ_ORU__DEV_AWC_Resp_62__MLBevo_HCAN(void)
{
#if _USE_CAN_TIMEOUT_
	timeout |= 0x00000001;
#endif
}

void Appl_COMCbkTOut_Com_COM_U_AC_ACT_ORU__DEV_AWC_Resp_62__MLBevo_HCAN(void)
{
#if _USE_CAN_TIMEOUT_
	timeout |= 0x00000001;
#endif
}

void Appl_COMCbkTOut_Com_COM_U_DC_ACT_ORU__DEV_AWC_Resp_62__MLBevo_HCAN(void)
{
#if _USE_CAN_TIMEOUT_
	timeout |= 0x00000001;
#endif
}

void Appl_COMCbkTOut_Com_COM_U_DC_MAX_ORU__DEV_AWC_Resp_62__MLBevo_HCAN(void)
{
#if _USE_CAN_TIMEOUT_
	timeout |= 0x00000001;
#endif
}

void Appl_COMCbkTOut_Com_CmdWSDStateMachine__DEV_AWC_Resp_50__MLBevo_HCAN(void)
{
#if _USE_CAN_TIMEOUT_
	timeout |= 0x00000001;
#endif
}

void Appl_COMCbkTOut_Com_Inverto_Test_RX0__Inverto_Test_Receive__MLBevo_HCAN(void)
{
}

void Appl_COMCbkTOut_Com_Inverto_Test_RX1__Inverto_Test_Receive__MLBevo_HCAN(void)
{
}

void Appl_COMCbkTOut_Com_Inverto_Test_RX2__Inverto_Test_Receive__MLBevo_HCAN(void)
{
}

void Appl_COMCbkTOut_Com_Inverto_Test_RX3__Inverto_Test_Receive__MLBevo_HCAN(void)
{
}

void Appl_COMCbkTOut_Com_Inverto_Test_RX4__Inverto_Test_Receive__MLBevo_HCAN(void)
{
}

void Appl_COMCbkTOut_Com_Inverto_Test_RX5__Inverto_Test_Receive__MLBevo_HCAN(void)
{
}

void Appl_COMCbkTOut_Com_Inverto_Test_RX6__Inverto_Test_Receive__MLBevo_HCAN(void)
{
}

void Appl_COMCbkTOut_Com_Inverto_Test_RX7__Inverto_Test_Receive__MLBevo_HCAN(void)
{
}
