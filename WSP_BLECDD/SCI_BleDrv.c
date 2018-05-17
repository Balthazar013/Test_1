/*----------------------------------------------------------------------------
** Project Name:CAR_36_PAD
** #Archive: 22_BLECDD/SCI_BleDrv #
** #Author: Reiner Bogenfuerst#
** #Date: 2016-06-28#
** (c) Copyright 2015, Bombardier Primove GmbH
**----------------------------------------------------------------------------
** #Revision: #
**----------------------------------------------------------------------------
** Target system: Freescale MPC5744P
** Compiler:GHS
** Description: Bluetooth Low Energy Complex Device Driver
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    -------------------------------------
** RBOGENFU   Reiner Bogenfuerst    Bombardier Primove GmbH
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log: #
**--------------------------------------------------------------------------*/

#include "Rte_SCI_BleDrv.h"
#include "Com.h"
#include "Com_Cfg.h"
#include "NvmData.h"
#include "Ti2540cdd.h"
#include "SpiCtrl.h"
#include <Port.h>
#include <TSMem.h> 

typedef struct
{
    uint16  I_DC_REQ;
    uint16  U_DC_ACT;
    uint16  U_AC_ACT;
    uint16  I_DC_ACT;
    uint16  U_DC_MAX;
    uint8   CmdWsStateMachine;
    uint8   OruSftyState;
    float   PosTrjE;
    float   PosTrjStrAng;
    uint16  PosTrjOfflPosX;
    uint16  PosTrjOfflPosY;
    uint8   PosTrjOfflPosT;
}BLE_ORU_ITF;

typedef union 
{
    uint8 ar[25];
    BLE_ORU_ITF st;
} uBLE_ORU_ITF;

typedef struct
{
    uint8       WsState             : 8;
    uint8       WsSftyState         : 8;
    uint16      PosX                :16;
    uint16      PosY                :16;
    uint16      PosT                :16;
    boolean     PosRssiStatus       : 1;
    boolean     PosInitStatus       : 1;
    uint16      ChrgMaxPower        :16;
    boolean     ChrgInhibited       : 1;
    boolean     TempDly             : 1;
    boolean     zMoverIsUp          : 1;
    boolean     zMoverIsDown        : 1;
    boolean     zMoverIsActive      : 1;
    boolean     zMoverInChrgPos     : 1;
    boolean     zMoverLocked        : 1;
    boolean     zMoverError         : 1;
    boolean     FodDly              : 1;
    boolean     FodError            : 1;
}BLE_WS_ITF;

typedef union
{
    uint8 ar[25];
    BLE_WS_ITF st;
} uBLE_WS_ITF;


static uint8 NvmExtRead_Status = E_NOT_OK;
static uint8 NvmExtRead_Request = 0;
BleName  BleNamePar;

static uBLE_ORU_ITF  uBleOruItf;
static uBLE_WS_ITF   uBleWsItf;

/*------------------------[runnable entity skeletons]------------------------*/

void BleCom_MainFunction (void)
{
    Dem_FaultDetectionCounterType EventIdFaultDetectionCounter_3;
    Dem_DTCType DTCofEvent_3;
    Dem_DTCKindType DTCKind_3;
    boolean EventTested_3;
    boolean EventFailed_3;
    boolean isChrgInhibited;
    boolean stTempDly;
    Dem_EventStatusExtendedType EventStatusExtended_3;
    Dem_EventStatusType EventStatus_3;
    Dem_FaultDetectionCounterType EventIdFaultDetectionCounter_2;
    Dem_DTCType DTCofEvent_2;
    Dem_DTCKindType DTCKind_2;
    boolean EventTested_2;
    boolean EventFailed_2;
    Dem_EventStatusExtendedType EventStatusExtended_2;
    Dem_EventStatusType EventStatus_2;
    Dem_FaultDetectionCounterType EventIdFaultDetectionCounter_1;
    Dem_DTCType DTCofEvent_1;
    Dem_DTCKindType DTCKind_1;
    boolean EventTested_1;
    boolean EventFailed_1;
    Dem_EventStatusExtendedType EventStatusExtended_1;
    Dem_EventStatusType EventStatus_1;
    Dem_FaultDetectionCounterType EventIdFaultDetectionCounter_0;
    Dem_DTCType DTCofEvent_0;
    Dem_DTCKindType DTCKind_0;
    boolean EventTested_0;
    boolean EventFailed_0;
    Dem_EventStatusExtendedType EventStatusExtended_0;
    Dem_EventStatusType EventStatus_0;
    Dem_FaultDetectionCounterType EventIdFaultDetectionCounter;
    Dem_DTCType DTCofEvent;
    Dem_DTCKindType DTCKind;
    boolean EventTested;
    boolean EventFailed;
    Dem_EventStatusExtendedType EventStatusExtended;
    Dem_EventStatusType EventStatus;
    TrueFalse SCI_BleDrv_Z_MoverUpValue;
    TrueFalse SCI_BleDrv_Z_MoverDownValue;
    GenericByte SCI_BleDrv_GenericByteValue_3;
    GenericByte SCI_BleDrv_ActStateWsValue;
    Distance_s16 PositionYValue_PAD;
    Distance_s16 PositionXValue_PAD;
    Power_u16 PowerValue;
    P2CONST(SftyBoolOO, AUTOMATIC, AUTOMATIC) SCI_BleDrv_SftyBoolValue;
    
    AngleDegree_s16 AngleValue_PAD;
    Distance_s16 PositionYValue_ORU;
    Distance_s16 PositionXValue_ORU;
    AngleDegree_s16 AngleValue_ORU;
    
    P2VAR(GenericByte, AUTOMATIC, AUTOMATIC) SCI_BleDrv_GenericByteValue_2;
    GenericByte SCI_BleDrv_GenericByteValue_1;
    P2VAR(Voltage_s32, AUTOMATIC, AUTOMATIC) SCI_BleDrv_Maximum_battery_voltage_s32_TValue_0;
    Voltage_s32 SCI_BleDrv_Maximum_battery_voltage_s32_TValue;
    P2VAR(Voltage_s32, AUTOMATIC, AUTOMATIC) SCI_BleDrv_Measured_oru_hv_dc_out_s32_TValue_0;
    Voltage_s32 SCI_BleDrv_Measured_oru_hv_dc_out_s32_TValue;
    P2VAR(Voltage_s32, AUTOMATIC, AUTOMATIC) SCI_BleDrv_Measured_oru_hv_ac_in_s32_TValue_0;
    Voltage_s32 SCI_BleDrv_Measured_oru_hv_ac_in_s32_TValue;
    P2VAR(GenericByte, AUTOMATIC, AUTOMATIC) SCI_BleDrv_GenericByteValue_0;
    GenericByte SCI_BleDrv_GenericByteValue;
    P2VAR(Current_s32, AUTOMATIC, AUTOMATIC) SCI_BleDrv_Requested_charging_current_s32_TValue_0;
    Current_s32 SCI_BleDrv_Requested_charging_current_s32_TValue;
    P2VAR(Current_s32, AUTOMATIC, AUTOMATIC) SCI_BleDrv_Measured_charging_current_s32_TValue_0;
    Current_s32 SCI_BleDrv_Measured_charging_current_s32_TValue;
    // P2VAR(BapLEDreq, AUTOMATIC, AUTOMATIC) SCI_BleDrv_BapLEDreqValue_0;
    // BapLEDreq SCI_BleDrv_BapLEDreqValue;
    P2VAR(BapLedCtrl, AUTOMATIC, AUTOMATIC) LedCtrlValue_0;
    BapLedCtrl LedCtrlValue;
    P2VAR(ErrorCode_u32, AUTOMATIC, AUTOMATIC) SCI_BleDrv_ErrorCodeValue_0;
    ErrorCode_u32 SCI_BleDrv_ErrorCodeValue;
    P2VAR(BleStatus, AUTOMATIC, AUTOMATIC) Value_0;
    BleStatus Value;
    Std_ReturnType status;
    boolean PosRSSIStatusVal;
    boolean PosInitStatusVal;
    FehlerZMover stFehlerZMover;
    zMoverLocked stZMoverLocked;
    zMoverIsInChrPosition stzMoverIsInChrPosition;
    zMoverIsActive stzMoverIsActive;
    Fehler_FOD stFodError;
    PP_Verz_FOD stFodDly;
    
    LedCtrlValue.Color  = 0;
    LedCtrlValue.Operation = 0;
  
    if(FLAG == 0xAB)
    {
        spiHdlrHWInterface.getSysTime = &getSysTime;
        spiHdlrHWInterface.onTxComplete = &onSPITxComplete;
        spiHdlrHWInterface.onRxComplete = &onSPIRxNewData;
        spiHdlrHWInterface.setSPIData = &setSPIData;
        spiHdlrHWInterface.getSPIData = &getSPIData;
        SPITransportLayerInit(HDLR_MASTER, &spiHdlrHWInterface);
        
        BLE.state = WAIT_BLE_INIT;
        BLE.LifeSignStat = INIT;
        hasNewRxBuffer = 0;
        BLE.Disconnect = 0;
        memset(BLE.ConnectionStates, 0,3);
        memset(&DatafromRTE[0], 0, 25);
        BLE.SPIsendBusyCounter = 0;
        BLE.SPIreceiveBusyCounter = 0;
        BLE.Request_Sleep = 0;
        BLE.Inhibit_Sleep = 1;
        
        if(bFirstStart == FALSE)
        {
            timer1ms = 0;
            FLAG = 0xAC;
            bFirstStart = TRUE;
        }
        else
        {
            Port_SetPinDirection(PortConfigSet_0_PortContainer_0_PortPin_J3_D_DBG_RESET_CU_LPCPU, PORT_PIN_OUT);
    FLAG = 0xD5;
        }
    }
    
    else if(FLAG == 0xD1)
    {
        Dio_WriteChannel(DioConf_DioChannel_J3_D_DBG_RESET_CU_LPCPU, 0);
        timer1ms = 0;
        FLAG = 0xD2;
    }
    
    else if(FLAG == 0xD2)
    {   
        timer1ms++;
        if(timer1ms > 5)
        {
            FLAG = 0xD3;
        }
    }
    
    else if(FLAG == 0xD3)
    {
        Dio_WriteChannel(DioConf_DioChannel_J3_D_DBG_RESET_CU_LPCPU, 1);
        timer1ms = 0;
        FLAG = 0xD4;
    }
    
    else if(FLAG == 0xD4)
    {   
        timer1ms++;
        if(timer1ms > 10)
        {
            Dio_WriteChannel(DioConf_DioChannel_J3_D_DBG_RESET_CU_LPCPU, 0);
            FLAG = 0xD5;
        }
    }
    
    else if(FLAG == 0xD5)
    {
        Port_SetPinDirection(PortConfigSet_0_PortContainer_0_PortPin_J3_D_DBG_RESET_CU_LPCPU, PORT_PIN_IN);
        timer1ms = 0;
        FLAG = 0xAC;
    }
    
    else if (FLAG == 0xAC)
    {
        timer1ms++;
        SPITransportLayerWork();
        
        /*Read from RTE if ManualControl is not active, else read from XCP*/
        if(ManualControl==1)
        {
            SCI_BleDrv_ActStateWsValue = ManualWsdState;
            SCI_BleDrv_GenericByteValue_3 = ManualSafetyState;
            SCI_BleDrv_SftyBoolValue = ManualErrorFod;
            
            AngleValue_PAD = ManualAngle;
            PositionXValue_PAD = ManualPosX;
            PositionYValue_PAD = ManualPosY;
            PosRSSIStatusVal = ManualPosRSSIStatusVal;
            PosInitStatusVal = ManualPosInitStatusVal;
            
            PowerValue          = ManualMaxPower;
            isChrgInhibited     = ManualInhibitCharging;
            stTempDly           = ManualTempDly;
            
            SCI_BleDrv_Z_MoverDownValue = ManualZmoverDown;
            SCI_BleDrv_Z_MoverUpValue = ManualZmoverUp;
            stzMoverIsActive = ManualstzMoverIsActive;
            stZMoverLocked = ManualstZMoverLocked;
            stFehlerZMover = ManualstFehlerZMover;
            stzMoverIsInChrPosition = ManualstzMoverIsInChrPosition;
            
            stFodDly   = ManualstFodDly;
            stFodError = ManualstFodError;
        }
        else
        {
            SCI_BleDrv_ActStateWsValue = Rte_IRead_BleCom_MainFunction_RP_WSState_SCI_BleDrv_ActStateWsValue();
            SCI_BleDrv_GenericByteValue_3 = Rte_IRead_BleCom_MainFunction_RP_WsSftyMgrState_SCI_BleDrv_GenericByteValue();
            
            SCI_BleDrv_SftyBoolValue = Rte_IRead_BleCom_MainFunction_RP_ForeignObjectDetected_SCI_BleDrv_SftyBoolValue();
            
            AngleValue_PAD = Rte_IRead_BleCom_MainFunction_RP_Angle_AngleValue();
            AngleValue_PAD += 180;
            PositionXValue_PAD = Rte_IRead_BleCom_MainFunction_RP_PositionX_PositionXValue();
            if(PositionXValue_PAD != 1023) PositionXValue_PAD += 1000; /*offset defined in DBC file */
            PositionYValue_PAD = Rte_IRead_BleCom_MainFunction_RP_PositionY_PositionYValue();
            if(PositionYValue_PAD != 1023) PositionYValue_PAD += 1000; /*offset defined in DBC file */
            PosRSSIStatusVal = Rte_IRead_BleCom_MainFunction_RP_PosRSSIStatus_PosRSSIStatusVal();
            PosInitStatusVal = Rte_IRead_BleCom_MainFunction_PosInitStatus_PosInitStatus();
            
            PowerValue = Rte_IRead_BleCom_MainFunction_RP_MaxPossiblePower_PowerValue();
            Rte_Call_ChrgInhibit_InhibitCharging(&isChrgInhibited);
            
            SCI_BleDrv_Z_MoverDownValue = Rte_IRead_BleCom_MainFunction_RP_ZMoverIsDown_SCI_BleDrv_Z_MoverDownValue();
            SCI_BleDrv_Z_MoverUpValue = Rte_IRead_BleCom_MainFunction_RP_ZMoverIsUp_SCI_BleDrv_Z_MoverUpValue();
            stzMoverIsActive = Rte_IRead_BleCom_MainFunction_RP_ZMoverActive_Value();
            stZMoverLocked = Rte_IRead_BleCom_MainFunction_WspStMgr_stZMoverLocked_stZMoverLocked();
            stFehlerZMover = Rte_IRead_BleCom_MainFunction_WspStMgr_stFehlerZMover_stFehlerZMover();
            stzMoverIsInChrPosition = Rte_IRead_BleCom_MainFunction_PP_ZMovrIsChargPos_Value();
            
            stFodDly = Rte_IRead_BleCom_MainFunction_RP_Verz_FOD_Value();
            stFodError = Rte_IRead_BleCom_MainFunction_RP_Fehler_FOD_Value();
            
            Rte_Call_WspErrHndl_stWsTempDly_TempDly(&stTempDly);
        }
        
        /*Write RTE variables to CAN*/
        Com_SendSignal(Com_Com_COM_WSD_State__DEV_AWC_Resp_58__MLBevo_HCAN,&SCI_BleDrv_ActStateWsValue);
        Com_SendSignal(Com_Com_COM_AWC_X_Coordinate__DEV_AWC_Resp_56__MLBevo_HCAN,&PositionXValue_PAD);
        Com_SendSignal(Com_Com_COM_AWC_Y_Coordinate__DEV_AWC_Resp_56__MLBevo_HCAN,&PositionYValue_PAD);
        Com_SendSignal(Com_Com_COM_BAP_AWC_Winkel__DEV_AWC_Resp_56__MLBevo_HCAN,&AngleValue_PAD);
        Com_SendSignal(Com_Com_COM_AWC_MaxLadLeistung__DEV_AWC_Resp_57__MLBevo_HCAN,&PowerValue);
        Com_SendSignal(Com_Com_COM_AWC_zMoverIsUp__DEV_AWC_Resp_59__MLBevo_HCAN,&SCI_BleDrv_Z_MoverUpValue);
        Com_SendSignal(Com_Com_COM_AWC_zMoverIsDown__DEV_AWC_Resp_59__MLBevo_HCAN,&SCI_BleDrv_Z_MoverDownValue);
        
        /************************* START: Pack BLE data ***********************************/
        TS_MemSet(uBleWsItf.ar, 0, 25);
        
        uBleWsItf.st.WsState            = SCI_BleDrv_ActStateWsValue;
        uBleWsItf.st.WsSftyState        = SCI_BleDrv_GenericByteValue_3;
        uBleWsItf.st.PosX               = PositionXValue_PAD;
        uBleWsItf.st.PosY               = PositionYValue_PAD;
        uBleWsItf.st.PosT               = AngleValue_PAD;
        uBleWsItf.st.PosRssiStatus      = PosRSSIStatusVal;
        uBleWsItf.st.PosInitStatus      = PosInitStatusVal;
        uBleWsItf.st.ChrgMaxPower       = (uint16)(PowerValue / 15);
        uBleWsItf.st.ChrgInhibited      = isChrgInhibited;
        uBleWsItf.st.TempDly            = stTempDly;
        uBleWsItf.st.zMoverIsUp         = SCI_BleDrv_Z_MoverUpValue;
        uBleWsItf.st.zMoverIsDown       = SCI_BleDrv_Z_MoverDownValue;
        uBleWsItf.st.zMoverIsActive     = stzMoverIsActive;
        uBleWsItf.st.zMoverInChrgPos    = stzMoverIsInChrPosition;
        uBleWsItf.st.zMoverLocked       = stZMoverLocked;
        uBleWsItf.st.zMoverError        = stFehlerZMover;
        uBleWsItf.st.FodDly             = stFodDly;
        uBleWsItf.st.FodError           = stFodError;
        
        TS_MemCpy(DatafromRTE, uBleWsItf.ar, 25);
        /************************* END: Pack BLE data ***************************************/
        
        blemain();
        
        /************************* START: Unpack BLE data ***********************************/
        TS_MemCpy(uBleOruItf.ar, &DatatoRTE[0], 25);
        
        /*Write received BLE signals to RTE*/
        Rte_IWrite_BleCom_MainFunction_PP_IDcReqOru_SCI_BleDrv_Requested_charging_current_s32_TValue(uBleOruItf.st.I_DC_REQ);
        Rte_IWrite_BleCom_MainFunction_PP_UDcActOru_SCI_BleDrv_Measured_oru_hv_dc_out_s32_TValue((uBleOruItf.st.U_DC_ACT*10));  /* Hundreds to milliVolt conversion */
        Rte_IWrite_BleCom_MainFunction_PP_UAcActOru_SCI_BleDrv_Measured_oru_hv_ac_in_s32_TValue((uBleOruItf.st.U_AC_ACT*10));   /* Hundreds to milliVolt conversion */
        Rte_IWrite_BleCom_MainFunction_PP_IDcActOru_SCI_BleDrv_Measured_charging_current_s32_TValue(uBleOruItf.st.I_DC_ACT);
        Rte_IWrite_BleCom_MainFunction_PP_UDcMaxOru_SCI_BleDrv_Maximum_battery_voltage_s32_TValue((uBleOruItf.st.U_DC_MAX*10)); /* Hundreds to milliVolt conversion */
        Rte_IWrite_BleCom_MainFunction_PP_WsCmdStateMachine_SCI_BleDrv_GenericByteValue(uBleOruItf.st.CmdWsStateMachine);
        Rte_IWrite_BleCom_MainFunction_PP_OruSftyMgrState_SCI_BleDrv_GenericByteValue(uBleOruItf.st.OruSftyState);
        Rte_IWrite_BleCom_MainFunction_PP_TrjE_Val(uBleOruItf.st.PosTrjE);
        Rte_IWrite_BleCom_MainFunction_PP_StrAngl_Val(uBleOruItf.st.PosTrjStrAng);
        Rte_IWrite_BleCom_MainFunction_PosTrjOfflPosT_AngleValue(uBleOruItf.st.PosTrjStrAng);
        Rte_IWrite_BleCom_MainFunction_PosTrjOfflPosX_PositionXValue(uBleOruItf.st.PosTrjOfflPosX);
        Rte_IWrite_BleCom_MainFunction_PosTrjOfflPosY_PositionYValue(uBleOruItf.st.PosTrjOfflPosY);
        
        /************************* START: Unpack BLE data ***********************************/
         
        Rte_IWrite_BleCom_MainFunction_PP_BapLedReq_LedCtrlValue(&LedCtrlValue);
        Rte_IWrite_BleCom_MainFunction_PP_BleState_Value(BLE.LifeSignStat);
        Rte_IWrite_BleCom_MainFunction_PP_ErrorCode_SCI_BleDrv_ErrorCodeValue(SCI_BleDrv_ErrorCodeValue);
        
        /*Diagnostics*/
        if(BLE.LifeSignStat == ERROR)
        {
            EventStatus_1 = DEM_EVENT_STATUS_PREFAILED;
        }
        else
        {
            EventStatus_1 = DEM_EVENT_STATUS_PREPASSED;
        }
        
        (void)Rte_Call_Event_BT_SPI_COMMUNICATION_TIMEOUT_SetEventStatus(EventStatus_1);
        //(void)Rte_Call_Event_BLE_STATUS_SIGNAL_NOTRECEIVED_SetEventStatus(EventStatus);
        //(void)Rte_Call_Event_BLE_COMM_TIMEOUT_SetEventStatus(EventStatus_0);
        //(void)Rte_Call_Event_RCDA_LEAKAGECURRDETECTED_SetEventStatus(EventStatus_2);
        //(void)Rte_Call_Event_RCDA_TEST_FAILED_SetEventStatus(EventStatus_3);
    }
    
}

void BtSrv_StartScan (void)
{
  Std_ReturnType status;

}

void BtSrv_StopScan (void)
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void BtSrv_ConnectTo (P2CONST(DeviceName, AUTOMATIC, RTE_APPL_CONST) DeviceName)
#else
void BtSrv_ConnectTo (P2CONST(GenericChar, AUTOMATIC, RTE_APPL_CONST) DeviceName)
#endif
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void BtSrv_DisconnectFrom (P2CONST(DeviceName, AUTOMATIC, RTE_APPL_CONST) DeviceName)
#else
void BtSrv_DisconnectFrom (P2CONST(GenericChar, AUTOMATIC, RTE_APPL_CONST) DeviceName)
#endif
{
  Std_ReturnType status;

}

void BtSrv_TransferFile (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) aByte, GenericQuad Size)
{
  Std_ReturnType status;

}

void BtSrv_DeactivateBleChip (void)
{
  Std_ReturnType status;

}

void BtSrv_WakeUpBleChip (void)
{
  Std_ReturnType status;

}

void BtSrv_SendPinToWayside (P2VAR(GenericChar, AUTOMATIC, RTE_APPL_DATA) aByte, GenericByte Size)
{
  Std_ReturnType status;

}

void BtSrv_SendPukToWayside (P2VAR(GenericChar, AUTOMATIC, RTE_APPL_DATA) aByte, GenericByte Size)
{
  Std_ReturnType status;

}

void BtSrv_ReceiveFileData (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) aByte, P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) Size)
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void BtSrv_GetStation (P2VAR(DeviceName, AUTOMATIC, RTE_APPL_DATA) DeviceName)
#else
void BtSrv_GetStation (P2VAR(GenericChar, AUTOMATIC, RTE_APPL_DATA) DeviceName)
#endif
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void BtSrv_GetStationList (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) NumOfElement, P2VAR(DeviceList, AUTOMATIC, RTE_APPL_DATA) ElementArray)
#else
void BtSrv_GetStationList (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) NumOfElement, P2VAR(StationElement, AUTOMATIC, RTE_APPL_DATA) ElementArray)
#endif
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void BtSrv_GetTrustedDeviceList (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) NumOfElement, P2VAR(TrustedDeviceList, AUTOMATIC, RTE_APPL_DATA) ElementArray)
#else
void BtSrv_GetTrustedDeviceList (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) NumOfElement, P2VAR(DeviceName, AUTOMATIC, RTE_APPL_DATA) ElementArray)
#endif
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void BtSrv_SaveDevice (P2CONST(DeviceName, AUTOMATIC, RTE_APPL_CONST) DeviceName)
#else
void BtSrv_SaveDevice (P2CONST(GenericChar, AUTOMATIC, RTE_APPL_CONST) DeviceName)
#endif
{
  Std_ReturnType status;

}

#ifdef RTE_PTR2ARRAYTYPE_PASSING
void BtSrv_DeleteDevice (P2VAR(DeviceName, AUTOMATIC, RTE_APPL_DATA) DeviceName)
#else
void BtSrv_DeleteDevice (P2VAR(GenericChar, AUTOMATIC, RTE_APPL_DATA) DeviceName)
#endif
{
  Std_ReturnType status;

}

void BtSrv_TransferDiag (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) aByte, GenericQuad Size)
{
  Std_ReturnType status;

}

void BtSrv_ReceiveDiag (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) aByte, P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) Size)
{
  Std_ReturnType status;

}

// main loop
void blemain()
{
	/*If BLE.Disconnect  is set, immediately disconnect*/
	if((BLE.Disconnect == 1) && (BLE.state != WAIT_TO_RECONNECT) && (BLE.state != GO_TO_IDLE_MODE))
	{
		BLE.state = DISCONNECT_FROM_DEVICE;
	}
	/*Send command go to request sleep on XCP */
	if(BLE.Request_Sleep == 1)
	{
		BLE.state = REQUEST_SLEEP;
		BLE.Request_Sleep = 0;
	}
    
	switch(BLE.state)
	{
	/*************************************************************State REQUEST_SLEEP**********************************************************************/
	case(REQUEST_SLEEP):
    {
			/*
			Clear the buffer to send data packet.
			*/
			memset(sharedMemValue, 0, 22);
			/*
			Fill the data packet buffer.
			*/
			sharedMemValue[0] 	= 0x14; /* Command request sleep */
			sharedMemValueLength = 1;
			/*Calling function SPITransportLayerPushTXData will push data to the SPI processor. After data has been transmitted successfuly, hasTxComplete will be set. 
			Before calling this function, hasTxComplete shall be set to zero.*/
			hasTxComplete = 0;
			/*The SPI data processor will also notify the client once it gets a respond to the command. So reset hasNewRxBuffer before calling the SPI data processor.*/
			hasNewRxBuffer = 0;
			/*
			Wait for the SPI data processor to accept data to be processed
			@return	0: ok
			1: previous buffer not yet processed
			2: invalid data length
			3: invalid buffer pointer
			4: Cannot push yet
			*/
			ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength,PKT_T_CTRL);
			if (ppret == 0) 
			{
				timer = getSysTime();
				/*
				Go to state WAIT_GET_RSSI to wait for an acknowledge from the BLE chip that it has received and processed the command
				*/
				BLE.state = WAIT_BLE_INIT; //GO_TO_INIT
			}

	break;
    }
	/*************************************************************State WAIT_BLE_INIT**********************************************************************/
	/*
	Wait for the BLE Chip to send it's initialise data
	*/
	case(WAIT_BLE_INIT):
    {
			if( hasNewRxBuffer == 1)
			{
				hasNewRxBuffer = 0;  
            
				/*Wait here until the BLE chip sends an event that initialisation is complete
				*/
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x03/*INIT OK*/) && (rxBuffer[2] == 0x01/*WAIT_BLE_INIT OP MODE*/))
				{
					/*Go to BLE.state SET_FILTER_MSG once initialise data is received*/
                timer = getSysTime();
					BLE.state = WAIT_GET_NVM_DATA;
				}
            
				/*Wait here until the BLE chip sends an event that connection is established
				*/
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x00/*EVT_CONN_ESTABLISHED*/))
				{
					/*
					The connection channel (0, 1 or 2) shall be updated to be used later for data transfer.	
					*/
					updateConnections(&rxBuffer[2]);
					BLE.state = GET_CONN_ADDRESS;
					timer = getSysTime();
				}
        }

        break;
			}
    /*************************************************************State WAIT_GET_NVM_DATA******************************************************************/
    /*
    Wait for the NVM Data to be copied into the RAM. The 0,5s was set by trial and error. PS* should use an event tag here instead
    */
	case(WAIT_GET_NVM_DATA):
			{
        if(NvmExtRead_Request == 0)
        {
            Rte_Call_BleNvData_GetBleName( &BleNamePar );
            if( BleNamePar.Valid > 0 )
            {
                NvmExtRead_Request = 1;
                sharedMemValueLength = 17;
                memcpy(&(BLE.DeviceName[0]), &(BleNamePar.Data[0]), sharedMemValueLength);
                NvmExtRead_Status = E_OK;
            }
        }
        
        if( (E_OK == NvmExtRead_Status) ||(getSystimeDiff(timer) >= 1500))
        {
				BLE.state = SET_FILTER_MSG;
			}
        
	break;
    }
	/*************************************************************State SET_FILTER_MSG**********************************************************************/	
	/*
	Set the filter message here after the BLE chip has initialised. The filter message is the name of the device.
	*/
	case (SET_FILTER_MSG):
    {
			if(hasNewRxBuffer == 1)
			{
				/*New data arrived although not expected. Ignore it and reset hasNewRxBuffer to allow new notification */
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
				*/
				hasNewRxBuffer = 0;
				break;
			}
        sharedMemValueLength = 13; /* reduced from 17 to 13 characters */
        memcpy(&(sharedMemValue[0]), &(BLE.DeviceName[0]), sharedMemValueLength);
            
			/* 
			Construct scanResponse buffer in "scanResponse" and "scanResponseLength". the function setScanResponse handles setting the device name according
			to the BLE stack sepecification.
			*/
			setScanResponse(0x01, 80 /* 80*1.25 */,  800 /* 800*1.25 */, 0, sharedMemValue, sharedMemValueLength);
			/*
			If the device is a connectable, the command Set Broadcast Message is sent. See BBridge_Architecture_Interfaces_Protocol.pdf page 15 for more details.
			*/
			if (OPERATING_MODE == CONNECTABLE) 
			{
				sharedMemValue[0] = 0x00; // BBCMD_SET_BROADCAST_MSG
			}
			/*
			If the device is a scanner, the command Set Filter Message is sent. See BBridge_Architecture_Interfaces_Protocol.pdf page 15 for more details.
			*/
			if (OPERATING_MODE == SCANNER) 
			{
				sharedMemValue[0] = 0x02; // BBCMD_SET_FILTER_MSG
			}
			/*
			Copy data package from scan response into sharedMemValue starting from byte 1. Byte 0 is used for command.
			*/
			memcpy(&sharedMemValue[1], scanResponse, scanResponseLength);
			sharedMemValueLength = scanResponseLength+1; //Add one for the command
			/*Calling function SPITransportLayerPushTXData will push data to the SPI processor. After data has been transmitted successfuly, hasTxComplete will be set. 
			Before calling this function, hasTxComplete shall be set to zero.*/
			hasTxComplete = 0;
			/*The SPI data processor will also notify the client once it gets a respond to the command. So reset hasNewRxBuffer before calling the SPI data processor.*/
			hasNewRxBuffer = 0;
			/*
			Wait for the SPI data processor to accept data to be processed
			@return	0: ok
			1: previous buffer not yet processed
			2: invalid data length
			3: invalid buffer pointer
			4: Cannot push yet
			*/
			ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength,PKT_T_CTRL);
			if(ppret == 0)
			{
			  /*
			  Go to BLE.state WAIT_SET_FILTER_MSG and wait for transmitt to complete and also for command acknowledge from BLE chip
			  */
			  BLE.state = WAIT_SET_FILTER_MSG;
			}
        
	break;
    }
	/*************************************************************State WAIT_SET_FILTER_MSG****************************************************************************/
	case (WAIT_SET_FILTER_MSG):
    {
			if(hasNewRxBuffer ==1)
			{
				/*Reset hasNewRxBuffer in case none of the if cases are fulfilled*/
				hasNewRxBuffer = 0;
				/*
				If the BLE chip reinitialises during when in this BLE.state, return to BLE.state SET_FILTER_MSG
				*/
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x03/*INIT OK*/) && (rxBuffer[2] == 0x01/*WAIT_BLE_INIT OP MODE*/))
				{
					testCounterBLEChipReinitWAIT_SET++;
					/*
					hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
					*/
					hasNewRxBuffer = 0; 
					/*
					hasTxComplete is set to zero. This flag will be set by the SPI data processor once it has received an acknowledge of the data sent from 
					the BLE chip.
					*/
					hasTxComplete = 0;
					BLE.state = SET_FILTER_MSG;
					break;
				}
            
            if (OPERATING_MODE == CONNECTABLE) 
            {
                /*
                If the device is connectable, wait for Reply_BBCMD_SET_BROADCAST_MSG and then set the operating mode to Scanner BB_OP_CONNECTABLE (see below)
                */
                if((hasTxComplete ==1) && (rxBuffer[0] == 0x00/*ACK*/) && (rxBuffer[1] == 0x00/*Reply_BBCMD_SET_BROADCAST_MSG*/))
                {
                    BLE.state = WAIT_CONNECTION;
                }
            }
        }
        
        break;
    }
	/*************************************************************State WAIT_SET_MODE****************************************************************************/
	case (WAIT_SET_MODE):
    {
			/*There is a notification from the SPI server*/
			if(hasNewRxBuffer ==1)
			{
				/*
				If the BLE chip reinitialises during when in this BLE.state, return to BLE.state SET_FILTER_MSG
				*/
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x03/*INIT OK*/) && (rxBuffer[2] == 0x01/*WAIT_BLE_INIT OP MODE*/))
				{
					testCounterBLEChipReinitWAIT_SET_MODE++;
					BLE.state = SET_FILTER_MSG;
					/*
					hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data from the BLE chip.
					*/
					hasNewRxBuffer = 0;
					/*
					  hasTxComplete is set to zero. This flag will be set by the SPI data processor once it has received an acknowledge of the data sent from 
					  the BLE chip.
					  */
					hasTxComplete = 0;
					break;
				}
				
				/*
				Wait for the Reply_BBCMD_SET_OP_MODE which is the acknowledge from the BLE chip that it has set the operating mode as requested
				*/
				if((hasTxComplete ==1) && (rxBuffer[0] == 0x00/*ACK*/) && (rxBuffer[1] == 0x04/*Reply_BBCMD_SET_OP_MODE*/)) 
				{
					  /*
					  hasTxComplete is set to zero. This flag will be set by the SPI data processor once it has received an acknowledge of the data sent from 
					  the BLE chip.
					  */
						hasTxComplete = 0;
					/*
					  Go to BLE.state WAIT_CONNECTION and wait for a connection notification from the BLE chip
					  */
					BLE.state = WAIT_CONNECTION;
					timer = getSysTime();
				}
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data from the BLE chip.
				*/
				hasNewRxBuffer = 0;
				
				if((hasTxComplete ==1) && (rxBuffer[0] == 0x01/*NACK*/) && (rxBuffer[1] == 0x04/*Reply_BBCMD_SET_OP_MODE*/)) 
				{
					  /*
					  hasTxComplete is set to zero. This flag will be set by the SPI data processor once it has received an acknowledge of the data sent from 
					  the BLE chip.
					  */
						hasTxComplete = 0;
					/*
					  Go to BLE.state WAIT_CONNECTION and wait for a connection notification from the BLE chip
					  */
					BLE.state = SET_FILTER_MSG;
					timer = getSysTime();
				}
			}
	break;
    }
	/*************************************************************State WAIT_CONNECTION****************************************************************************/
	case (WAIT_CONNECTION):
    {
			/*There is a notification from the SPI server*/
			if(hasNewRxBuffer == 1)
			{
				/*
				If the BLE chip reinitialises during when in this BLE.state, return to BLE.state SET_FILTER_MSG
				*/
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x03/*INIT OK*/) && (rxBuffer[2] == 0x01/*WAIT_BLE_INIT OP MODE*/))
				{
					testCounterBLEChipReinitWAIT_SET_MODE++;
					hasNewRxBuffer = 0;
					BLE.state = SET_FILTER_MSG;
				}
				/*
				Wait here until the BLE chip sends an event that connection is established
				*/
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x00/*EVT_CONN_ESTABLISHED*/))
				{
					/*
					The connection channel (0, 1 or 2) shall be updated to be used later for data transfer.	
					*/
					updateConnections(&rxBuffer[2]);
					BLE.state = GET_CONN_ADDRESS;
					timer = getSysTime();
				}
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
				*/
				hasNewRxBuffer = 0;
			}
            /*In case it takes too long to receive the RSSI value, continue to next state*/
			if((getSystimeDiff(timer) >= 10000) && (BLE.Inhibit_Sleep == 0))
			{
				BLE.state = REQUEST_SLEEP;
			}

	break;
    }
	/*************************************************************State GET_CONN_ADDRESS****************************************************************************/
	case (GET_CONN_ADDRESS):
    {
			/*
			The function updateConnections was used in state WAIT_CONNECTION to notify which BLE channel is used for the communication. Only the first active channel
			is used.
			*/
			for (i = 0; i < MAX_CONNECTIONS; i++) 
			{
				if (connections[i] == 1) 
				{
					/*
					send data to connection channel i.
					Clear the buffer to send data packet.
					*/
					memset(sharedMemValue, 0, 22);
					/*
					Fill the data packet buffer.
					*/
					sharedMemValue[0] 	= 0x0E; /* Command Get Connection Address */
					sharedMemValue[1] 	= i; /*Connection index*/
					sharedMemValueLength = 2;
					/*Calling function SPITransportLayerPushTXData will push data to the SPI processor. After data has been transmitted successfuly, hasTxComplete will be set. 
					Before calling this function, hasTxComplete shall be set to zero.*/
					hasTxComplete = 0;
					/*The SPI data processor will also notify the client once it gets a respond to the command. So reset hasNewRxBuffer before calling the SPI data processor.*/
					hasNewRxBuffer = 0;
					/*
					Wait for the SPI data processor to accept data to be processed
					@return	0: ok
					1: previous buffer not yet processed
					2: invalid data length
					3: invalid buffer pointer
					4: Cannot push yet
					*/
					ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength,PKT_T_CTRL);
					if (ppret == 0) 
					{
						timer = getSysTime();
						/*
						Go to state WAIT_RX_SEND_ACK to wait for an acknowledge from the BLE chip that it has received and processed the transmitt command
						*/
						BLE.state = WAIT_GET_CONN_ADDRESS;
					}
					break;
				}
			}
        
	break;
    }
	/*************************************************************State WAIT_GET_CONN_ADDRESS****************************************************************************/
	case (WAIT_GET_CONN_ADDRESS):
    {
			/*
			Wait for an ackowledge that the command to get the the connection address was received by the BLE chip successfuly. If data is recedived but it is not the 
			acknowledge, wait here.
			*/
			if(hasNewRxBuffer == 1)
			{
				if((rxBuffer[0] == 0x00) && (rxBuffer[1] == 0x0E))
				{
					/*
					Once the command has been acknowledged successfuly, copy the address value and continue.
					*/
					memcpy(&BLE.DeviceAddress[0], &rxBuffer[2], 6);
					
					/*
					If the mode is connectable, fo to state WAIT_BEFORE_FIRST_TX to wait before transmitting the first data packet. This is to allow the 
					scanner to get ready.
					*/
					if (OPERATING_MODE == CONNECTABLE) 
					{
						BLE.state = WAIT_BEFORE_FIRST_TX;
						timer = getSysTime();
					}
					/*
					If the mode is scanner, go to state WAIT_RX_DATA to wait for the first data packet from the connectable
					*/
                else if (OPERATING_MODE == SCANNER) 
					{
						BLE.state = WAIT_RX_DATA;
						timer = getSysTime();
					}
				}
                else if((rxBuffer[0] == 0x02) && (rxBuffer[1] == 0x01)) /*connection lost*/
                {
                    if (OPERATING_MODE == CONNECTABLE) 
                    {
                        BLE.state = WAIT_CONNECTION;
                        timer = getSysTime();
                    }
                }
            
				/*
				  hasTxComplete is set to zero. This flag will be set by the SPI data processor once it has received an acknowledge of the data sent from 
				  the BLE chip.
				*/
					hasTxComplete = 0;
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
				*/
					hasNewRxBuffer = 0;	
			}
        
	break;
    }
	/*************************************************************State WAIT_BEFORE_FIRST_TX************************************************************************/
	case(WAIT_BEFORE_FIRST_TX):
    {
			if(getSystimeDiff(timer) >= 500)
			{	/*
				Scanner should be ready now. Go to BLE.state TX_DATA to transmitt the first data packet.
				*/
				timer = getSysTime();
				BLE.state = TX_DATA;
			}
        
	break;
    }
		/*************************************************************State TX_DATA************************************************************************************/
		case (TX_DATA):
    {
				/*
				The function updateConnections was used in BLE.state WAIT_CONNECTION to notify which BLE channel is used for the communication. Only the first active channel
				is used.
				*/
				for (i = 0; i < MAX_CONNECTIONS; i++) 
				{
					if (connections[i] == 1) 
					{
						/*
						send data to connection channel i.
						Clear the buffer to send data packet.
						*/
						memset(sharedMemValue, 0, 56);
						/*
						Fill the data packet buffer.
						*/
						sharedMemValue[0] 	= 0x09; /* Command BBCMD_SEND_DATA */
						sharedMemValue[1] 	= i; /*Communication channel to send data on*/
						sharedMemValue[2]	= datacounter++; /*Counter*/
						memcpy(&sharedMemValue[3], &DatafromRTE[0], 25); /*Payload Data starts here*/
						sharedMemValueLength = 56;
						/*Calling function SPITransportLayerPushTXData will push data to the SPI processor. After data has been transmitted successfuly, hasTxComplete will be set. 
						Before calling this function, hasTxComplete shall be set to zero.*/
						hasTxComplete = 0;
						/*The SPI data processor will also notify the client once it gets a respond to the command. So reset hasNewRxBuffer before calling the SPI data processor.*/
						hasNewRxBuffer = 0;
						/*
						/*
						Wait for the SPI data processor to accept data to be processed
						@return	0: ok
						1: previous buffer not yet processed
						2: invalid data length
						3: invalid buffer pointer
						4: Cannot push yet
						*/
						ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength,PKT_T_DATA);
						if (ppret == 0)
						{
							timer = getSysTime();
							/*
							Go to BLE.state WAIT_RX_SEND_ACK to wait for an acknowledge from the BLE chip that it has received and processed the transmitt command
							*/
							BLE.state = WAIT_RX_DATA;
						}
                
						break;
					}
				}
        
		break;
    }
		/******************************************************State WAIT_RX_SEND_ACK************************************************************************************/
		case (WAIT_RX_SEND_ACK):
    {
				/*
				Wait for an ackowledge that the command to transmit data packet was received by the BLE chip successfuly. If data is recedived but it is not the 
				acknowledge, wait here.
				*/
				if(hasNewRxBuffer == 1)
				{
					if((rxBuffer[0] == 0x00) && (rxBuffer[1] == 0x09))
					{
						/*
						Once data has been transmitted successfuly, go to BLE.state WAIT_RX_DATA and wait for data packet to arrive from the other side. If this step
						is reached but the data is not a proper acknowldge,stay here and wait for the acknowledge.
						*/
						BLE.state = WAIT_RX_DATA;
						timer = getSysTime();
					}
					/*In case data received while trying to send*/
					if((rxBuffer[0] == 0x02/*BB_MSGTYPE_EVENT*/) && (rxBuffer[1] == 0x02/*BB_EVT_RX_MSG*/))
					{
						/*
						New data packet received
						*/
						BLE.ConnectionIndex 	= rxBuffer[2]; /*Connection Index*/
						BLE.DataRoundTripCounter	= rxBuffer[3]; /*Counter*/
						memcpy(&DatatoRTE[0], &rxBuffer[4], 25); /*Payload Data starts here*/
						BLE.state = TX_DATA;
						//BLE.nextstate = TX_DATA;
						timer = getSysTime();
					}
					/*
					  hasTxComplete is set to zero. This flag will be set by the SPI data processor once it has received an acknowledge of the data sent from 
					  the BLE chip.
					*/
						hasTxComplete = 0;
					/*
					hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
					*/
						hasNewRxBuffer = 0;	
				}
				else if(BLE.LifeSignStat == ERROR)
				{
					if(getSystimeDiff(timer) >= 1000)
					{
					FLAG = 0xAB;
					}
					// BLE.state = WAIT_GET_NVM_DATA;
					// BLE.nextstate = WAIT_RX_DATA; //come back here
				}
				/*In case there were too much data to be read, it could be that transmitt was not successful. So, return to TX_Data after timeout*/
				else if(getSystimeDiff(timer) >= 300)
				{
					timer = getSysTime();
					//BLE.state = TX_DATA;
					BLE.TXackTimeoutCounter++;
				}
        
		break;
    }
    /******************************************************State WAIT_RX_DATA*****************************************************************************************/
    case (WAIT_RX_DATA):
    {
				if (hasNewRxBuffer == 1)
				{
					if((rxBuffer[0] == 0x02/*BB_MSGTYPE_EVENT*/) && (rxBuffer[1] == 0x02/*BB_EVT_RX_MSG*/))
					{
						/*
						New data packet received
						*/
						BLE.ConnectionIndex 	= rxBuffer[2]; /*Connection Index*/
						BLE.DataRoundTripCounter	= rxBuffer[3]; /*Counter*/
						memcpy(&DatatoRTE[0], &rxBuffer[4], 25); /*Payload Data starts here*/
						BLE.state = TX_DATA;
						//BLE.nextstate = TX_DATA;
						timer = getSysTime();
					}
                    else if((rxBuffer[0] == 0x02) && (rxBuffer[1] == 0x01)) /*connection lost*/
                    {
                        BLE.state = WAIT_CONNECTION;
                        timer = getSysTime();
                    }
                    if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x00/*EVT_CONN_ESTABLISHED*/))
                    {
                        /*
                        The connection channel (0, 1 or 2) shall be updated to be used later for data transfer.	
                        */
                        updateConnections(&rxBuffer[2]);
                        BLE.state = GET_CONN_ADDRESS;
                        timer = getSysTime();
                    }
					/*
					  hasTxComplete is set to zero. This flag will be set by the SPI data processor once it has received an acknowledge of the data sent from 
					  the BLE chip.
					*/
						hasTxComplete = 0;
					/*
					hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
					*/
						hasNewRxBuffer = 0;	
				}
				else if(BLE.LifeSignStat == ERROR)
				{
					if(getSystimeDiff(timer) >= 2000)
					{
					FLAG = 0xAB;
					}
					
					// BLE.state = WAIT_GET_NVM_DATA;
					// BLE.nextstate = WAIT_RX_DATA; //come back here
				}
				/*Connectable waits for 2 seconds in case it gets stuck*/
				else if((getSystimeDiff(timer) >= 300) && (OPERATING_MODE == CONNECTABLE))
				{
					timer = getSysTime();
					BLE.state = TX_DATA;
					BLE.RXConnectableTimeoutCounter++;
				}

		break;
    }
	/*************************************************************State DISCONNECT_FROM_DEVICE**********************************************************************/
	/*
	Disconnect existing connection
	*/
	case(DISCONNECT_FROM_DEVICE):
    {
				/*
			The function updateConnections was used in state WAIT_CONNECTION to notify which BLE channel is used for the communication. Only the first active channel
			is used.
			*/
			for (i = 0; i < MAX_CONNECTIONS; i++) 
			{
				if (connections[i] == 1) 
				{
					/*
					send data to connection channel i.
					Clear the buffer to send data packet.
					*/
					memset(sharedMemValue, 0, 22);
					/*
					Fill the data packet buffer.
					*/
					sharedMemValue[0] 	= 0x06; /* Command Disconnect From Device */
					sharedMemValue[1] 	= i; /*Communication channel to disconnect*/
					sharedMemValueLength = 2;
					/*Calling function SPITransportLayerPushTXData will push data to the SPI processor. After data has been transmitted successfuly, hasTxComplete will be set. 
					Before calling this function, hasTxComplete shall be set to zero.*/
					hasTxComplete = 0;
					/*The SPI data processor will also notify the client once it gets a respond to the command. So reset hasNewRxBuffer before calling the SPI data processor.*/
					hasNewRxBuffer = 0;
					/*
					Wait for the SPI data processor to accept data to be processed
					@return	0: ok
					1: previous buffer not yet processed
					2: invalid data length
					3: invalid buffer pointer
					4: Cannot push yet
					*/
					ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength,PKT_T_CTRL);
					if (ppret == 0) 
					{
						timer = getSysTime();
						/*
						Go to state WAIT_GET_RSSI to wait for an acknowledge from the BLE chip that it has received and processed the command
						*/
						BLE.state = WAIT_TO_RECONNECT; //GO_TO_IDLE_MODE
					}
					break;
				}
			}

	break;
    }
	/*************************************************************State GO_TO_IDLE_MODE**********************************************************************/
	/*
	Wait here until BLE.Disconnect is reset
	*/
	case(GO_TO_IDLE_MODE):
    {
				  /*
				  Send the command BBCMD_SET_OP_MODE to set the operating mode of the BLE chip to IDLE
				  */
					sharedMemValue[0] = 0x04; // BBCMD_SET_OP_MODE

					sharedMemValue[1] = 0x01; // BB_OP_IDLE
					BLE.OperatingMode = sharedMemValue[1];

				sharedMemValueLength = 2;
				/*Calling function SPITransportLayerPushTXData will push data to the SPI processor. After data has been transmitted successfuly, hasTxComplete will be set. 
				Before calling this function, hasTxComplete shall be set to zero.*/
				hasTxComplete = 0;
				/*The SPI data processor will also notify the client once it gets a respond to the command. So reset hasNewRxBuffer before calling the SPI data processor.*/
				hasNewRxBuffer = 0;
				/*
				Wait for the SPI data processor to accept data to be processed
				@return	0: ok
				1: previous buffer not yet processed
				2: invalid data length
				3: invalid buffer pointer
				4: Cannot push yet
				*/
				ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength,PKT_T_CTRL);
				if (ppret == 0) 
				{										
					  /*
					  Go to state WAIT_SET_MODE and wait for transmitt to complete and also for command acknowledge from BLE chip
					  */
						BLE.state = WAIT_TO_RECONNECT;
				}

	break;	
    }
	/*************************************************************State WAIT_TO_RECONNECT**********************************************************************/
	/*
	Wait here until BLE.Disconnect is reset
	*/
	case(WAIT_TO_RECONNECT):
    {
		if(BLE.Disconnect == 0)
		{
			BLE.state = WAIT_CONNECTION;
		}
	break;	
    }
	/******************************************************State default*****************************************************************************************/			
		default:
    {
				BLE.state = WAIT_BLE_INIT;
				timer = getSysTime();
		break;
    }
		
	}
	
    // TODO: take NVM parameters
    // Rte_Call_BleNvData_GetBleCommTO( &BleCommTO );
    // Rte_Call_BleNvData_GetBleDeviceSleepTO( &BleDeviceSleepTO );
    // Rte_Call_BleNvData_GetBleScanTO( &BleScanTO );
    
	/*Onlyincrement LifesignMissingCounter if there is a BLE connection available */
	if( (BLE.ConnectionStates[0] == 1) || (BLE.ConnectionStates[1] == 1) || (BLE.ConnectionStates[2] == 1))
	{
		if(BLE.DataRoundTripCounter == OldDataRoundTripCounter)
		{
			LifesignMissingCounter++;
		}
		else
		{
			BLE.LifeSignStat = BLE_OK;
			LifesignMissingCounter = 0;
		}
		if(LifesignMissingCounter > 2000)
		{
			BLE.LifeSignStat = ERROR;
		}
		OldDataRoundTripCounter = BLE.DataRoundTripCounter;
	}
    
	if( (BLE.ConnectionStates[0] == 0) && (BLE.ConnectionStates[1] == 0) && (BLE.ConnectionStates[2] == 0))
	{
		//BLE Connection lost
		BLE.LifeSignStat = LOSTBLE;
	}
}	


/* 
SCAN_RESPONSE = 
[
    [safety-agains-cellphone-names (3 bytes)],
    [slave conn intervals(4+1 Bytes):
        slave conn (min)internal (2),
        slave conn (max)internal(2) ],
    [tx power level (3 bytes)],
    [device local name (rest)],
    

]
*/
static uint8_t setScanResponse(uint8_t safetyByte, uint16_t minConnInterval,  uint16_t maxConnInterval, uint8_t txPower, uint8_t * devName, uint8_t devNameLength)
{
    scanResponse[0] = 0x06;
    scanResponse[1] = GAP_ADTYPE_MANUFACTURER_SPECIFIC; // custom manufacturer data
    scanResponse[2] = 0x0E; /* Manufacture ID   */
    scanResponse[3] = 0x01; /* Manufacture ID   */
    scanResponse[4] = 0xFF; /* Service ID       */
    scanResponse[5] = 0xFF; /* Service ID       */
    scanResponse[6] = 0x00; /* Device Status    */
    
    // configuring slave interval
    scanResponse[7] = 0x05;
    scanResponse[8] = GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE;
    // minConnInterval * 1.25ms range(0x0006 - 0x0C80)
    scanResponse[9] = LO_UINT16(minConnInterval);
    scanResponse[10] = HI_UINT16(minConnInterval);
    // maxConnInterval * 1.25ms range(0x0006 - 0x0C80)
    scanResponse[11] = LO_UINT16(maxConnInterval);
    scanResponse[12] = HI_UINT16(maxConnInterval);
    
    // tx power (not clear yet how this works)
    scanResponse[13] = 0x02;
    scanResponse[14] = GAP_ADTYPE_POWER_LEVEL;
    scanResponse[15] = 0;
    
    // device name
    scanResponse[16] = devNameLength+1;
    scanResponse[17] = GAP_ADTYPE_LOCAL_NAME_COMPLETE;
    
    if(devNameLength < (MAX_SPI_TX_LENGTH-18))
    { // 13 characters for device name
        memcpy(&scanResponse[18], devName, devNameLength);
        scanResponseLength = 18+devNameLength;
        return 0;
    }
    else
    {
        return 1; // invalid device name
    }
}

/*This function is called after connection has been established to update which of the three channels is active*/
void updateConnections(uint8_t * rnewConnections){
    connections[0] = rnewConnections[0];
    connections[1] = rnewConnections[1];
    connections[2] = rnewConnections[2];
	
	BLE.ConnectionStates[0] = rnewConnections[0];
	BLE.ConnectionStates[1] = rnewConnections[1];
	BLE.ConnectionStates[2] = rnewConnections[2];
}

/*Called to get the time diff since the last BLE.state change for exampleto calculate timeout*/
uint32_t getSystimeDiff(uint32_t value){
	return timer1ms - value;
}
/*Called to get the latest ticks of te 1ms timer*/
uint32_t getSysTime(void){
    return timer1ms;
}

/*Called from SPI data processor once transmission is completed successfuly (received and processed acknowledge from BLE chip) after 
handshake to inform client that send was successful*/
void onSPITxComplete(void){
    hasTxComplete = 1;
}
/*Called from SPI data processor to inform client that new incoming data has been processed succesfuly and copied to the client buffer*/
uint8_t onSPIRxNewData(const uint8_t * data, uint8_t length){
    if(hasNewRxBuffer == 0)
	{
		memset(rxBuffer, 0, sizeof(rxBuffer));
		memcpy(rxBuffer, data, length);
		rxBufferLength = length;
		hasNewRxBuffer = 1;
		return 0;
	}
	else
	{
		return 1; /*Client is busy. Cannot notify.*/
	}
}
/*Called from the SPI data processor to send SPI data via MCAL*/
uint8_t setSPIData(uint8_t * data, uint8_t length){
	Std_ReturnType eStdReturn;
	a = Dio_ReadChannel(DioConf_DioChannel_B6_SPI_SRDY_CU_LPCPU);
	if(a == 1)
	{
		/*Use memcpy in case data is overwritten by SPI_Transmit_Byte*/
		eStdReturn = SPI_Transmit_Byte(&data[0], &temp[0], length);
		if(eStdReturn != E_OK)
		{
			BLE.SPIsendBusyCounter++;
			return 1; /* cannot push - slave sending or busy */ 
		}
		SPITransportLayerOnMasterTXComplete();
		testTimercustomSPIWork++;
		return 0;
	}
	else
	{
		return 1; /* cannot push - slave sending or busy */ 
	}

}
/*Called from the SPI data handler to receive SPI data from the MCAL*/
uint8_t getSPIData(uint8_t * lastCharPtr, uint8_t length)
{   
   Std_ReturnType eStdReturn;
   uint8_t hasData = 0;    
    if(length > MAX_SPI_TX_LENGTH)
	{
		return 0xFF;
	}
	a = Dio_ReadChannel(DioConf_DioChannel_B6_SPI_SRDY_CU_LPCPU);
    if(a==0)
	{        
		memset(temp, 0, sizeof(temp));
		eStdReturn = SPI_Transmit_Byte(&temp[0],&internalRxBuffer[0],length);
		if(eStdReturn != E_OK)
		{
			*lastCharPtr = 0;
			hasData = 0;
			BLE.SPIreceiveBusyCounter++;
			return hasData; /* cannot pull - slave busy */ 
		}
		memcpy(lastCharPtr, internalRxBuffer, length);
		hasData = SPI_HAS_DATA;
    }
	else
	{     
		*lastCharPtr = 0;
		hasData = 0;
    }
	return hasData;  
}
/*Internal function to transmit and receive SPI data via MCAL*/
Std_ReturnType SPI_Transmit_Byte(uint8_t * src, uint8_t * dest, uint8_t byteCnt)
{
	Std_ReturnType eStdReturn;
    Spi_SeqResultType eSpiSeqResult;
	uint8_t status;
	byteCntSPI_Transmit_Byte = byteCnt;
	//memcpy(&dest[0], &src[0], byteCnt);
 
	/*This function setup an external buffer to be used by a specific channel*/
	/*
    E_OK      Setup command has been accepted
    E_NOT_OK  Setup command has not been accepted
    */
	eStdReturn = Spi_SetupEB(SpiConf_SpiChannel_Spi_TICC2540_Command_8, src, dest, byteCnt);
	if(eStdReturn != E_OK)
	{
		return E_NOT_OK;
	}		
	/* Comment: Check that the Upit sequence is ready */
	eSpiSeqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_Spi_Seq_WCom);
	if(eSpiSeqResult != SPI_SEQ_OK)
    {
        return E_NOT_OK;
    }
	/* Comment: Call the Spi Synchronous transmit API */
	eStdReturn = Spi_SyncTransmit(SpiConf_SpiSequence_Spi_Seq_WCom);
	if(eStdReturn != E_OK)
    {
        return E_NOT_OK;
    }
		
		/*This function must be called back after transmitt SPI is completed*/
		//SPIHandlerWorkOnSPIMasterTX();
	memcpy(&arrReceive[0], &dest[0], byteCnt);

	return E_OK;
}

void BleCom_SpiRxPending_ISR()
{
}

void BleCom_SpiExchangeDone_Cbk()
{
}

/* callbacks */
uint8 awc_send_via_ble(const uint8 *uid, const uint8 *msg, const uint32 msg_len){return 0;}
void awc_on_open_secure_connection_completed_test(const uint8 *uid, sint16 status){}
void awc_on_open_secure_connection_completed(const uint8 *uid, const uint8 status){}
void awc_on_secure_pairing_completed(const uint8 *uid, const uint8 status){}
void awc_on_enter_admin_mode_completed(const uint8 *uid, const uint8 status){}
void awc_on_decrypted_data_available(const uint8 *uid, const uint8 *msg, const uint32 msg_len){}

/* Unique Identifier */
uint8 awc_get_uid(uint8 *uid){return 0;}

/* car- or wayside */
uint8 awc_get_side(void){return 0xFF;}

/* AUTH keypair */
uint8 awc_get_private_key(uint8 *key, const uint16 key_len){return 0;}
uint8 awc_set_private_key (const uint8 *key, const uint16 key_len){return 0;}
uint8 awc_get_public_key (uint8 *key, const uint16 key_len){return 0;}
uint8 awc_set_public_key (const uint8 *key, const uint16 key_len){return 0;}

/* Public key and nonces*/
uint8 awc_get_public_key_by_id (const uint8 *uid, uint8 *key, const uint16 key_len){return 0;}
uint8 awc_set_public_key_by_id (const uint8 *uid, const uint8 *key, const uint16 key_len){return 0;}

/* Session key and nonces */
uint8 awc_get_session_key_by_id (const uint8 *uid, uint8 *key, const uint16 key_len){return 0;}
uint8 awc_set_session_key_by_id (const uint8 *uid, const uint8 *key, const uint16 key_len){return 0;}
uint8 awc_get_nonces_by_id (const uint8 *uid, uint8 *nonce_car, const uint16 nc_len, uint8 *nonce_way, const uint16 nw_len){return 0;}
uint8 awc_set_nonces_by_id (const uint8 *uid, const uint8 *nonce_car, const uint16 nc_len, const uint8 *nonce_way, const uint16 nw_len){return 0;}

/* PIN/PUK verifier */
uint8 awc_get_verifier_by_user (const uint8 *user, const uint16 user_len, uint8 *verifier, const uint16 ver_len){return 0;}
uint8 awc_set_verifier_by_user (const uint8 *user, const uint16 user_len, const uint8 *verifier, const uint16 ver_len){return 0;}

/* Used for SRP-6a */
uint8 awc_srp_get_prime (uint8 *prime, const uint16 prime_len){return 0;}
uint8 awc_srp_get_generator(void){return 0;}
uint8 awc_srp_get_salt (uint8 *salt, const uint16 salt_len){return 0;}

/* Trusted device */
uint8 awc_is_trusted_device(const uint8 *uid){return 0;}
uint8 awc_set_trusted_device (const uint8 *uid){return 0;}
uint8 awc_remove_trusted_device (const uint8 *uid){return 0;}

/* random number generator */
uint8 awc_get_sensor1(uint8* value, const uint16 value_len){return 0;}
uint8 awc_get_sensor2(uint8* value, const uint16 value_len){return 0;}
uint8 awc_get_sensor3(uint8* value, const uint16 value_len){return 0;}
uint8 awc_get_sensor4(uint8* value, const uint16 value_len){return 0;}
uint8 awc_get_sensor5(uint8* value, const uint16 value_len){return 0;}
/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------

  ------------------------[per instance memory API]--------------------------

*/
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

