
/*----------------------------------------------------------------------------
** Project Name:CAR_36_ORU
** #Archive: 20_CDD/BLE/OruBleCdd #
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




#include "Rte_OruBleCdd.h"
#include "Ti2540cdd.h"
#include "NvmData.h"
#include "global_def.h"
#include "OruBleCdd.h"
#include <Dio.h>
#include <Port.h>


/*------------------------[runnable entity skeletons]------------------------*/
void OruBleCdd_Init(void)
{
	BLE.AutoConnectionMode = 1;
}

void OruBleCdd_OruBleCdd1ms (void)
{
  /*Declarations from SysDesk Tresos*/
  Dem_EventStatusType EventStatus_0;
  Dem_FaultDetectionCounterType EventIdFaultDetectionCounter_0;
  boolean EventTested_0;
  Dem_EventStatusExtendedType EventStatusExtended_0;
  boolean EventFailed_0;
  Dem_DTCType DTCofEvent_0;
  Dem_DTCKindType DTCKind_0;
  Dem_EventStatusType EventStatus;
  Dem_FaultDetectionCounterType EventIdFaultDetectionCounter;
  boolean EventTested;
  Dem_EventStatusExtendedType EventStatusExtended;
  boolean EventFailed;
  Dem_DTCType DTCofEvent;
  Dem_DTCKindType DTCKind;
  DTCan_COM_U_DC_MAX_ORU COM_U_DC_MAX_ORU;
  DTCan_COM_U_DC_ACT_ORU COM_U_DC_ACT_ORU;
  DTCan_COM_U_AC_ACT_ORU COM_U_AC_ACT_ORU;
  DTCan_COM_I_DC_REQ_ORU COM_I_DC_REQ_ORU;
  DTCan_COM_I_DC_ACT_ORU COM_I_DC_ACT_ORU;
  uint8 CmdWSDStateMachine;
  P2CONST(DTCan_SG_ESP_21, AUTOMATIC, AUTOMATIC) DataElementESP;
  P2VAR(DTCan_PadSftyStateMgr, AUTOMATIC, AUTOMATIC) DataElement_0;
  DTCan_PadSftyStateMgr DataElement;
  P2VAR(DTCan_COM_AWC_zMovrIsChargPos, AUTOMATIC, AUTOMATIC) COM_AWC_zMovrIsChargPos_0;
  DTCan_COM_AWC_zMovrIsChargPos COM_AWC_zMovrIsChargPos;
  P2VAR(DTCan_COM_AWC_zMoverLocked, AUTOMATIC, AUTOMATIC) COM_AWC_zMoverLocked_0;
  DTCan_COM_AWC_zMoverLocked COM_AWC_zMoverLocked;
  P2VAR(DTCan_COM_AWC_zMoverIsUp, AUTOMATIC, AUTOMATIC) COM_AWC_zMoverIsUp_0;
  DTCan_COM_AWC_zMoverIsUp COM_AWC_zMoverIsUp;
  P2VAR(DTCan_COM_AWC_zMoverIsDown, AUTOMATIC, AUTOMATIC) COM_AWC_zMoverIsDown_0;
  DTCan_COM_AWC_zMoverIsDown COM_AWC_zMoverIsDown;
  P2VAR(DTCan_COM_AWC_zMoverActive, AUTOMATIC, AUTOMATIC) COM_AWC_zMoverActive_0;
  DTCan_COM_AWC_zMoverActive COM_AWC_zMoverActive;
  P2VAR(DTCan_COM_AWC_Y_Coordinate, AUTOMATIC, AUTOMATIC) COM_AWC_Y_Coordinate_0;
  DTCan_COM_AWC_Y_Coordinate COM_AWC_Y_Coordinate;
  P2VAR(DTCan_COM_AWC_X_Coordinate, AUTOMATIC, AUTOMATIC) COM_AWC_X_Coordinate_0;
  DTCan_COM_AWC_X_Coordinate COM_AWC_X_Coordinate;
  P2VAR(DTCan_COM_AWC_Verz_FOD, AUTOMATIC, AUTOMATIC) COM_AWC_Verz_FOD_0;
  DTCan_COM_AWC_Verz_FOD COM_AWC_Verz_FOD;
  P2VAR(DTCan_AWC_Panel_Verdrehwinkel, AUTOMATIC, AUTOMATIC) Data_AWC_Panel_Verdrehwinkel_0;
  DTCan_AWC_Panel_Verdrehwinkel Data_AWC_Panel_Verdrehwinkel;
  P2VAR(DTCan_AWC_Panel_PositionY, AUTOMATIC, AUTOMATIC) Data_AWC_Panel_PositionY_0;
  DTCan_AWC_Panel_PositionY Data_AWC_Panel_PositionY;
  P2VAR(DTCan_AWC_Panel_PositionX, AUTOMATIC, AUTOMATIC) Data_AWC_Panel_PositionX_0;
  DTCan_AWC_Panel_PositionX Data_AWC_Panel_PositionX;
  P2VAR(DTCan_COM_AWC_Fehler_FOD, AUTOMATIC, AUTOMATIC) COM_AWC_Fehler_FOD_0;
  DTCan_COM_AWC_Fehler_FOD COM_AWC_Fehler_FOD;
  P2VAR(DTCan_COM_WSD_State, AUTOMATIC, AUTOMATIC) COM_WSD_State_0;
  DTCan_COM_WSD_State COM_WSD_State;
  P2VAR(DTCan_COM_AWC_MaxLadLeistung, AUTOMATIC, AUTOMATIC) COM_AWC_MaxLadLeistung_0;
  DTCan_COM_AWC_MaxLadLeistung COM_AWC_MaxLadLeistung;
  P2VAR(BleStatus, AUTOMATIC, AUTOMATIC) BLEStat_0;
  P2VAR(WsChrgInhibition, AUTOMATIC, AUTOMATIC) ChrgInhibitVal_0;
  WsChrgInhibition ChrgInhibitVal;
  BleStatus BLEStat;
  uint8 ModeValue;
  Std_ReturnType status;

  /*Read from RTE*/
  AWC_Status = Rte_IRead_OruBleCdd1ms_rpAWCStatus_AWC_Status();
  DataElementESP = Rte_IRead_OruBleCdd1ms_rpSG_ESP_21_DataElementESP();
  CmdWSDStateMachine = Rte_IRead_OruBleCdd1ms_rpCOM_CmdWSDStateMachine_CmdWSDStateMachine();
  COM_I_DC_ACT_ORU = Rte_IRead_OruBleCdd1ms_rpCOM_I_DC_ACT_ORU_COM_I_DC_ACT_ORU();
  COM_I_DC_REQ_ORU = Rte_IRead_OruBleCdd1ms_rpCOM_I_DC_REQ_ORU_COM_I_DC_REQ_ORU();
  COM_U_AC_ACT_ORU = Rte_IRead_OruBleCdd1ms_rpCOM_U_AC_ACT_ORU_COM_U_AC_ACT_ORU();
  COM_U_DC_ACT_ORU = Rte_IRead_OruBleCdd1ms_rpCOM_U_DC_ACT_ORU_COM_U_DC_ACT_ORU();
  COM_U_DC_MAX_ORU = Rte_IRead_OruBleCdd1ms_rpCOM_U_DC_MAX_ORU_COM_U_DC_MAX_ORU();
  ModeValue = Rte_IRead_OruBleCdd1ms_rpCOM_OruSftyStateMode_ModeValue();
  
  /****************************Perform internal tasks********************************************************/
  
  	 if(FLAG == 0xAB)
	 {
		// initializing SPITransportLayer (to manage unreliable SPI communications)
		spiHdlrHWInterface.getSysTime = &getSysTime;
		spiHdlrHWInterface.onTxComplete = &onSPITxComplete;
		spiHdlrHWInterface.onRxComplete = &onSPIRxNewData;
		spiHdlrHWInterface.setSPIData = &setSPIData;
		spiHdlrHWInterface.getSPIData = &getSPIData;
		SPITransportLayerInit(HDLR_MASTER, &spiHdlrHWInterface);

        FLAG = 0xD0;
	 }
    else if(FLAG == 0xD0)
    {
		BLE.state = WAIT_BLE_INIT;
		if(BLE.InternalScanCMD != 1)
		{
			BLE.Status = BLE_SLEEP;
		}
        
		hasNewRxBuffer = 0;
		BLE.LifeSignStat = INIT;
		LifesignMissingCounter = 0;
		BLE.Disconnect = 0;
		// BLE.AutoConnectionMode = 1;
		BLE.GoToSleep = 0;
		CMD_GO_TO_SLEEP = 0;
		WAIT_Before_Shutdown = 1;
		Rte_IWrite_OruBleCdd10ms_ppBLEStatus_BLEStat(2);
		memset(BLE.ConnectionStates, 0,3);
		BLE.InitiateConnection = 0;
		BLE.NumberOfDetectedChargingStations = 0;
		memset(BLE.DetectedChargingStation_1_UUID,0,6);
		memset(BLE.DetectedChargingStation_1_Name,0,12); 
		memset(BLE.DetectedChargingStation_2_UUID,0,6);
		memset(BLE.DetectedChargingStation_2_Name,0,12); 
		memset(BLE.DetectedChargingStation_3_UUID,0,6);
		memset(BLE.DetectedChargingStation_3_Name,0,12); 
		memset(BLE.DetectedChargingStation_4_UUID,0,6);
		memset(BLE.DetectedChargingStation_4_Name,0,12); 
		memset(BLE.DetectedChargingStation_5_UUID,0,6);
		memset(BLE.DetectedChargingStation_5_Name,0,12); 
		memset(BLE.DetectedChargingStation_6_UUID,0,6);
		memset(BLE.DetectedChargingStation_6_Name,0,12); 
		memset(BLE.DetectedChargingStation_7_UUID,0,6);
		memset(BLE.DetectedChargingStation_7_Name,0,12); 
		memset(BLE.DetectedChargingStation_8_UUID,0,6);
		memset(BLE.DetectedChargingStation_8_Name,0,12); 
		Port_SetPinDirection(PortConfigSet_0_PortContainer_0_PortPin_F14_D_GATE_DEBUG_RESET_CU_BT, PORT_PIN_OUT);
        BLEResetCount = 0;
        FLAG = 0xD1;
    }
    else if(FLAG == 0xD1)
    {
        Dio_WriteChannel(DioConf_DioChannel_DioChannel_D_GATE_DEBUG_RESET_CU_BT, 0);
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
        Dio_WriteChannel(DioConf_DioChannel_DioChannel_D_GATE_DEBUG_RESET_CU_BT, 1);
        timer1ms = 0;
        FLAG = 0xD4;
    }
    else if(FLAG == 0xD4)
    {   
        timer1ms++;
        if(timer1ms > 10)
        {
            BLEResetCount++;
            //if(BLEResetCount >= BLE_RESET_ATTEMPTS)
            //{
                Dio_WriteChannel(DioConf_DioChannel_DioChannel_D_GATE_DEBUG_RESET_CU_BT, 0);
                FLAG = 0xD5;
            //}
            //else
            //{
              //  FLAG = 0xD1;
            //}
        }
    }
    else if(FLAG == 0xD5)
    {
        Port_SetPinDirection(PortConfigSet_0_PortContainer_0_PortPin_F14_D_GATE_DEBUG_RESET_CU_BT, PORT_PIN_IN);
        timer1ms = 0;
        FLAG = 0xDC;
    }
	else if(FLAG == 0xDC)
	{
		timer1ms++;	
		SPITransportLayerWork();
		
		/*Read BLE signals to transfer from Rte*/
		InternalFromRte.COM_I_DC_REQ_ORU = COM_I_DC_REQ_ORU;
		InternalFromRte.COM_U_DC_ACT_ORU = COM_U_DC_ACT_ORU;
		InternalFromRte.COM_U_AC_ACT_ORU = COM_U_AC_ACT_ORU;
		InternalFromRte.COM_I_DC_ACT_ORU = COM_I_DC_ACT_ORU;
		InternalFromRte.COM_U_DC_MAX_ORU = COM_I_DC_ACT_ORU;
		InternalFromRte.CmdWSDStateMachine = CmdWSDStateMachine;
		InternalFromRte.ModeValue = ModeValue;
		InternalFromRte.VehicleSpeed = DataElementESP->ESP_v_Signal;
		
		
		if(InternalFromRte.VehicleSpeed > Maximum_Vehicle_Speed)
		{
			if (BLE.state == WAIT_BLE_INIT)
			{
				BLE.state = VEHICLE_SPEED_INIT_VALUE;
			}
		}
		
		if((InternalFromRte.VehicleSpeed > 2000) && (InternalFromRte.VehicleSpeed < Maximum_Vehicle_Speed) && (OldVehSpeed < 2000)) 
		{
			BLE.GoToSleep = 1;
			OldVehSpeed = InternalFromRte.VehicleSpeed;
		}
		else if((InternalFromRte.VehicleSpeed < 2000) && (OldVehSpeed > 2000))
		{
			BLE.GoToSleep = 0;
			OruBleCdd_BtSrv_StartScan();
			OldVehSpeed = InternalFromRte.VehicleSpeed;
		}
		
		PackDataForBLETransfer();
        
		blemain();
        
		UnpackDataFromBLETransfer();
        
		/*Write received BLE signals to RTE*/
		COM_WSD_State = InternalToRte.COM_WSD_State;
		COM_AWC_X_Coordinate = InternalToRte.COM_AWC_X_Coordinate;
		COM_AWC_Y_Coordinate = InternalToRte.COM_AWC_Y_Coordinate;
		Data_AWC_Panel_Verdrehwinkel = (uint16) InternalToRte.Data_AWC_Panel_Verdrehwinkel;
		COM_AWC_MaxLadLeistung = InternalToRte.COM_AWC_MaxLadLeistung;
		COM_AWC_zMoverIsUp = InternalToRte.COM_AWC_zMoverIsUp;
		COM_AWC_zMoverIsDown = InternalToRte.COM_AWC_zMoverIsDown;
		COM_AWC_zMoverActive = InternalToRte.COM_AWC_zMoverActive;
		COM_AWC_zMovrIsChargPos = InternalToRte.COM_AWC_zMovrIsChargPos;
		COM_AWC_zMoverLocked = InternalToRte.COM_AWC_zMoverLocked;
		COM_AWC_Fehler_FOD = InternalToRte.COM_AWC_Fehler_FOD;
		COM_AWC_Verz_FOD = InternalToRte.COM_AWC_Verz_FOD;
		DataElement = InternalToRte.PadSftyStateMgr;
		ChrgInhibitVal = InternalToRte.ChrgInhibitVal;
		
		/**************************Map internal variables to RTE signals*******************************************************/	
		BLEStat = BLE.Status;
		/**************************************************************************************************************************/
	}
  
  /*Write to RTE*/	
  Rte_IWrite_OruBleCdd1ms_ppBLEStatus_BLEStat(BLEStat); //Done

  BLEStat_0 = Rte_IWriteRef_OruBleCdd1ms_ppBLEStatus_BLEStat(); //Done

  Rte_IWrite_OruBleCdd1ms_PpCOM_AWC_MaxLadLeistung_COM_AWC_MaxLadLeistung(COM_AWC_MaxLadLeistung); //Done

  COM_AWC_MaxLadLeistung_0 = Rte_IWriteRef_OruBleCdd1ms_PpCOM_AWC_MaxLadLeistung_COM_AWC_MaxLadLeistung(); //Done

  Rte_IWrite_OruBleCdd1ms_PpCOM_WSD_State_COM_WSD_State(COM_WSD_State); //Done

  COM_WSD_State_0 = Rte_IWriteRef_OruBleCdd1ms_PpCOM_WSD_State_COM_WSD_State(); //Done

  Rte_IWrite_OruBleCdd1ms_ppAWC_Fehler_FOD_COM_AWC_Fehler_FOD(COM_AWC_Fehler_FOD); //Done

  COM_AWC_Fehler_FOD_0 = Rte_IWriteRef_OruBleCdd1ms_ppAWC_Fehler_FOD_COM_AWC_Fehler_FOD(); //Done

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_Verz_FOD_COM_AWC_Verz_FOD(COM_AWC_Verz_FOD); //Done

  COM_AWC_Verz_FOD_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_Verz_FOD_COM_AWC_Verz_FOD(); //Done

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_X_Coordinate_COM_AWC_X_Coordinate(COM_AWC_X_Coordinate); //Done

  COM_AWC_X_Coordinate_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_X_Coordinate_COM_AWC_X_Coordinate(); //Done

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_Y_Coordinate_COM_AWC_Y_Coordinate(COM_AWC_Y_Coordinate); //Done

  COM_AWC_Y_Coordinate_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_Y_Coordinate_COM_AWC_Y_Coordinate(); //Done

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_zMoverActive_COM_AWC_zMoverActive(COM_AWC_zMoverActive); //Done

  COM_AWC_zMoverActive_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_zMoverActive_COM_AWC_zMoverActive(); //Done

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_zMoverIsDown_COM_AWC_zMoverIsDown(COM_AWC_zMoverIsDown); //Done

  COM_AWC_zMoverIsDown_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_zMoverIsDown_COM_AWC_zMoverIsDown(); //Done

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_zMoverIsUp_COM_AWC_zMoverIsUp(COM_AWC_zMoverIsUp); //Done

  COM_AWC_zMoverIsUp_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_zMoverIsUp_COM_AWC_zMoverIsUp(); //Done

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_zMoverLocked_COM_AWC_zMoverLocked(COM_AWC_zMoverLocked); //Done

  COM_AWC_zMoverLocked_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_zMoverLocked_COM_AWC_zMoverLocked(); //Done

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_zMovrIsChargPos_COM_AWC_zMovrIsChargPos(COM_AWC_zMovrIsChargPos); //Done

  COM_AWC_zMovrIsChargPos_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_zMovrIsChargPos_COM_AWC_zMovrIsChargPos(); //Done

  Rte_IWrite_OruBleCdd1ms_ppPadSftyMgrState_DataElement(DataElement); //Done

  DataElement_0 = Rte_IWriteRef_OruBleCdd1ms_ppPadSftyMgrState_DataElement(); //Done
  
  Rte_IWrite_OruBleCdd1ms_ppWsInhibitCharging_ChrgInhibitVal(ChrgInhibitVal);
  
  // ChrgInhibitVal_0 = Rte_IWriteRef_OruBleCdd1ms_ppWsInhibitCharging_ChrgInhibitVal();

  Rte_IWrite_OruBleCdd1ms_ppCOM_AWC_Verdrehwinkel_Data_COM_AWC_Panel_Verdrehwinkel(Data_AWC_Panel_Verdrehwinkel);

  // Data_COM_AWC_Panel_Verdrehwinkel_0 = Rte_IWriteRef_OruBleCdd1ms_ppCOM_AWC_Verdrehwinkel_Data_COM_AWC_Panel_Verdrehwinkel();

/*Diagnostics*/ 
 status = Rte_Call_Event_BLE_COMM_TIMEOUT_ClearPrestoredFreezeFrame();

  status = Rte_Call_Event_BLE_COMM_TIMEOUT_GetDTCOfEvent(DTCKind, &DTCofEvent);

  status = Rte_Call_Event_BLE_COMM_TIMEOUT_GetEventFailed(&EventFailed);

  status = Rte_Call_Event_BLE_COMM_TIMEOUT_GetEventStatus(&EventStatusExtended);

  status = Rte_Call_Event_BLE_COMM_TIMEOUT_GetEventTested(&EventTested);

  status = Rte_Call_Event_BLE_COMM_TIMEOUT_GetFaultDetectionCounter(&EventIdFaultDetectionCounter);

  status = Rte_Call_Event_BLE_COMM_TIMEOUT_PrestoreFreezeFrame();

  status = Rte_Call_Event_BLE_COMM_TIMEOUT_ResetEventStatus();

  if(BLE.LifeSignStat == ERROR)
  {
	EventStatus = DEM_EVENT_STATUS_PREFAILED;   
  }
  else
  {
	  EventStatus = DEM_EVENT_STATUS_PREPASSED;
  }
  
  status = Rte_Call_Event_BLE_COMM_TIMEOUT_SetEventStatus(EventStatus);

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_ClearPrestoredFreezeFrame();

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_GetDTCOfEvent(DTCKind_0, &DTCofEvent_0);

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_GetEventFailed(&EventFailed_0);

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_GetEventStatus(&EventStatusExtended_0);

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_GetEventTested(&EventTested_0);

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_GetFaultDetectionCounter(&EventIdFaultDetectionCounter_0);

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_PrestoreFreezeFrame();

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_ResetEventStatus();

  status = Rte_Call_Event_BLE_STATUS_SIGNAL_SetEventStatus(EventStatus_0);

}

void OruBleCdd_BtSrv_WakeUpBleChip (void)
{
  Std_ReturnType status;
  BLE.GoToSleep = 0;

}

void OruBleCdd_BtSrv_StartScan (void) //Ad return type : Std_ReturnType : OK | NOK
{
  // Return OK wenn Scan Befehl angenommen werden kann. Return NOK wenn Scan Befehl nicht angenommen werden konnte
  Std_ReturnType status;
  
  BLE.Scan = 1;
  BLE.Status = BLE_SEARCHING;

}

void OruBleCdd_BtSrv_GetStationList (P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station0, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station1, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station2, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station3, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station4, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station5, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station6, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station7)
{
  Std_ReturnType status;
  memcpy(&Station0[0],&BLE.DetectedChargingStation_1_Name[0], 9);
  memcpy(&Station1[0],&BLE.DetectedChargingStation_2_Name[0], 9);
  memcpy(&Station2[0],&BLE.DetectedChargingStation_3_Name[0], 9);
  memcpy(&Station3[0],&BLE.DetectedChargingStation_4_Name[0], 9);
  memcpy(&Station4[0],&BLE.DetectedChargingStation_5_Name[0], 9);
  memcpy(&Station5[0],&BLE.DetectedChargingStation_6_Name[0], 9);
  memcpy(&Station6[0],&BLE.DetectedChargingStation_7_Name[0], 9);
  memcpy(&Station7[0],&BLE.DetectedChargingStation_8_Name[0], 9);

}

void OruBleCdd_BtSrv_ConnectTo (P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) StationName)
{
  Std_ReturnType status;
  //return Std_ReturnType OK | NOK
  
  cmpRet = memcmp(&StationName[0],&BLE.DetectedChargingStation_1_Name[0], 9);
  if(cmpRet == 0)
  {
	  BLE.ConnectToChargingStation = 1;
	  BLE.InitiateConnection = 1;
	  return;
  }
  cmpRet = memcmp(&StationName[0],&BLE.DetectedChargingStation_2_Name[0], 9);
  if(cmpRet == 0)
  {
	  BLE.ConnectToChargingStation = 2;
	  BLE.InitiateConnection = 1;
	  return;
  }
  cmpRet = memcmp(&StationName[0],&BLE.DetectedChargingStation_3_Name[0], 9);
  if(cmpRet == 0)
  {
	  BLE.ConnectToChargingStation = 3;
	  BLE.InitiateConnection = 1;
	  return;
  }
  cmpRet = memcmp(&StationName[0],&BLE.DetectedChargingStation_4_Name[0], 9);
  if(cmpRet == 0)
  {
	  BLE.ConnectToChargingStation = 4;
	  BLE.InitiateConnection = 1;
	  return;
  }
  cmpRet = memcmp(&StationName[0],&BLE.DetectedChargingStation_5_Name[0], 9);
  if(cmpRet == 0)
  {
	  BLE.ConnectToChargingStation = 5;
	  BLE.InitiateConnection = 1;
	  return;
  }
}

// void OruBleCdd_BtSrv_DeactivateBleChip (void)
// {
  // Std_ReturnType status;
  // BLE.GoToSleep = 1;

// }

// void OruBleCdd_BtSrv_TransferFile (GenericQuad Size, P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) Data)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_BtSrv_TransferDiag (uint32 Size, P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) Data)
// {
  // Std_ReturnType status;

// }


// void OruBleCdd_BtSrv_SendPinToWayside (GenericByte Size, P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) PinCodeArray)
// {
  // Ignore PIN until security is implemented
  // Std_ReturnType status;
  // return OK, NOK, WRONG_PIN

// }

// void OruBleCdd_BtSrv_GetStation (P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) DeviceName)
// {
  // Std_ReturnType status;

// }


// void OruBleCdd_BtSrv_DisconnectFrom (P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) StationName)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_BtSrv_DeleteDevice (P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) StationName)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_BtSrv_GetTrustedDeviceList (P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station0, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station1, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station2, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station3, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station4, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station5, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station6, P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) Station7)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_BtSrv_ReceiveDiag (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) aByte, P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) Size)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_BtSrv_ReceiveFileData (P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) aByte, P2VAR(GenericByte, AUTOMATIC, RTE_APPL_DATA) Size)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_BtSrv_SaveDevice (P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) StationName)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_BtSrv_SendPukToWayside (GenericByte Size, P2CONST(unsigned char, AUTOMATIC, RTE_APPL_CONST) PukCode)
// {
  // Std_ReturnType status;

// }



// void OruBleCdd_BtSrv_StopScan (void)
// {
  // Std_ReturnType status;

// }



// void OruBleCdd_BtSrv_GetDevice (P2VAR(unsigned char, AUTOMATIC, RTE_APPL_DATA) StationName)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_OruBleCdd10ms (void)
// {
// }

// void OruBleCdd_BtSrv_ChangePinTo (P2VAR(GenericChar, AUTOMATIC, RTE_APPL_DATA) aByte, GenericByte Size)
// {
  // Std_ReturnType status;

// }

// void OruBleCdd_BtSrv_ChangePanelNameTo (P2VAR(GenericChar, AUTOMATIC, RTE_APPL_DATA) aByte, GenericByte Size)
// {
  // Std_ReturnType status;

// }

	/************************************************************* MAIN LOOP **********************************************************************/
void blemain(void)
{
	//Dio_WriteChannel(DioConf_DioChannel_DioChannel_D_WUP_CU_BT, CMD_GO_TO_SLEEP);
	/*If BLE.Disconnect  is set, immediately disconnect*/
	if((BLE.Disconnect == 1) && (BLE.state != WAIT_TO_RECONNECT) && (BLE.state != GO_TO_IDLE_MODE) && (BLE.state != GO_TO_SLEEP) && (BLE.state != WAIT_GO_TO_SLEEP))
	{
		BLE.state = DISCONNECT_FROM_DEVICE;
	}
	/*Send command go to sllep on XCP Command go to sleep*/
	if((BLE.GoToSleep == 1) || (AWC_Status == COM_AWC_Status_DisabledState))
	{
		BLE.GoToSleep = 1;
		BLE.state = GO_TO_SLEEP;
		//BLE.state = WAIT_GO_TO_SLEEP;
	}
	if((BLE.Scan == 1) && (BLE.GoToSleep != 1))
	{
		BLE.ScanComplete = 0;
		FLAG = 0xAB;
		BLE.Scan = 0;
		BLE.InternalScanCMD = 1;
	}
	switch(BLE.state)
	{
	
	/*************************************************************State VEHICLE_SPEED_INIT_VALUE**********************************************************************/
	/*
	If the value of the ESP_v_Signal is greater than the limit (init value)
	*/
	case(VEHICLE_SPEED_INIT_VALUE):

		if (InternalFromRte.VehicleSpeed < Maximum_Vehicle_Speed)
		{
			BLE.state = WAIT_GET_NVM_DATA;
		}
	
	break;
	/*************************************************************State WAIT_BLE_INIT**********************************************************************/
	/*
	Wait for the BLE Chip to send it's initialise data
	*/
	case(WAIT_BLE_INIT):
			if( hasNewRxBuffer == 1)
			{
				hasNewRxBuffer = 0;  
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x03/*INIT OK*/) && (rxBuffer[2] == 0x01/*WAIT_BLE_INIT OP MODE*/))                              					
				/*Go to BLE.state SET_FILTER_MSG once initialise data is received & if the vehicle speed is within range, else go to VEHICLE_SPEED_INIT_VALUE and wait there*/
				
				if (InternalFromRte.VehicleSpeed < Maximum_Vehicle_Speed)
				{	
					BLE.state = WAIT_GET_NVM_DATA;
				}
				else 
				{
					BLE.state = VEHICLE_SPEED_INIT_VALUE;
				}
				timer = getSysTime();
			}
	break;
	/*************************************************************State WAIT_GET_NVM_DATA**********************************************************************/
	/*Wait for the NVM Data to be copied into the RAM. The 1,5s was set by trial and error...0,5s did not work and 1s was on the limit. 
	However, for wayside 0,5s seems to be enough and works stabil. PS* should use an event tag here instead*/
	case(WAIT_GET_NVM_DATA):
			if(getSystimeDiff(timer) >= 1500 || (BLE.GoToSleepNM == 0xAF))
			{
				BLE.state = SET_FILTER_MSG;
			}
	break;
	/*************************************************************State SET_FILTER_MSG**********************************************************************/
	/*
	Set the filter message here after the BLE chip has initialised. The filter message is the name of the device.
	*/
	case (SET_FILTER_MSG):
			if(hasNewRxBuffer == 1)
			{
				/*New data arrived although not expected. Ignore it and reset hasNewRxBuffer to allow new notification */
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
				*/
				hasNewRxBuffer = 0;
				break;
			}
			sharedMemValueLength = 17;
			memcpy(&sharedMemValue[0], &NvM_RamBlock_BLE_Name[0], sharedMemValueLength);
			memcpy(&BLE.DeviceName[0], &sharedMemValue[0], sharedMemValueLength);			
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
			ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength);
			if(ppret == 0)
			{
			  /*
			  Go to state WAIT_SET_FILTER_MSG and wait for transmitt to complete and also for command acknowledge from BLE chip
			  */
			  BLE.state = WAIT_SET_FILTER_MSG;
			}
	break;
	/*************************************************************State WAIT_SET_FILTER_MSG****************************************************************************/
	case (WAIT_SET_FILTER_MSG):
			if(hasNewRxBuffer ==1)
			{
				/*Reset hasNewRxBuffer in case none of the if cases are fulfilled*/
				hasNewRxBuffer = 0;
				/*
				If the BLE chip reinitialises during when in this state, return to state SET_FILTER_MSG
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
					  /*
					  Send the command BBCMD_SET_OP_MODE to set the operating mode of the BLE chip
					  */
						sharedMemValue[0] = 0x04; // BBCMD_SET_OP_MODE

						sharedMemValue[1] = 0x03; // BB_OP_CONNECTABLE
						BLE.OperatingMode = sharedMemValue[1];
					}
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
					ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
					if (ppret == 0) 
					{										
						  /*
						  Go to state WAIT_SET_MODE and wait for transmitt to complete and also for command acknowledge from BLE chip
						  */
							BLE.state = WAIT_SET_MODE;
					}
				}
				if (OPERATING_MODE == SCANNER) 
				{
					/*
					If the device is scanner, wait for Reply_BBCMD_SET_FILTER_MSG and then set the operating mode to Scanner BB_OP_SCANNER (see below)
					*/
					if((hasTxComplete ==1) && (rxBuffer[0] == 0x00/*ACK*/) && (rxBuffer[1] == 0x02/*Reply_BBCMD_SET_FILTER_MSG*/)) 
					{
					  /*
					  Send the command BBCMD_SET_OP_MODE to set the operating mode of the BLE chip
					  */
						sharedMemValue[0] = 0x04; // BBCMD_SET_OP_MODE

						sharedMemValue[1] = 0x02; // BB_OP_SCANNER
						BLE.OperatingMode = sharedMemValue[1];
					}
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
					ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
					if (ppret == 0) 
					{										
						  /*
						  Go to state WAIT_SET_MODE and wait for transmitt to complete and also for command acknowledge from BLE chip
						  */
							BLE.state = WAIT_SET_MODE;
					}
				}	
			}

	break;
	/*************************************************************State WAIT_SET_MODE****************************************************************************/
	case (WAIT_SET_MODE):
			/*There is a notification from the SPI server*/
			if(hasNewRxBuffer ==1)
			{
				/*
				If the BLE chip reinitialises during when in this state, return to state SET_FILTER_MSG
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
					if(BLE.GoToSleepNM == 0xAF)
					{
						BLE.state = GO_TO_SLEEP;
					}
					else
					{
											/*
						  Go to state WAIT_CONNECTION and wait for a connection notification from the BLE chip
						  */
						BLE.state = WAIT_SCAN_CMD;
						if(BLE.InternalScanCMD == 1)
						{
							BLE.Status = BLE_SEARCHING;
						}
						else{
							BLE.Status = BLE_READY;
						}
					}

					
				}
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data from the BLE chip.
				*/
				hasNewRxBuffer = 0;
			}
	break;
	/*************************************************************State GET_DET_CONNECTABLES**********************************************************************/
	case(WAIT_SCAN_CMD):
	if(BLE.InternalScanCMD == 1)
	{		
		BLE.state = GET_DET_CONNECTABLES;
	}
	break;
	/*************************************************************State GET_DET_CONNECTABLES**********************************************************************/
	/*
	Set the filter message here after the BLE chip has initialised. The filter message is the name of the device.
	*/
	case (GET_DET_CONNECTABLES):
			BLE.InternalScanCMD = 0;
			if(hasNewRxBuffer == 1)
			{
				/*New data arrived although not expected. Ignore it and reset hasNewRxBuffer to allow new notification */
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
				*/
				hasNewRxBuffer = 0;
				break;
			}
			/*
			Clear the buffer to send data packet.
			*/
			memset(sharedMemValue, 0, 22);
			/*
			Fill the data packet buffer.
			*/
			sharedMemValue[0] 	= 0x11; /* Command GET_DET_CONNECTABLES */
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
			ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength);
			if(ppret == 0)
			{
			  /*
			  Go to state WAIT_GET_DET_CONNECTABLES and wait for detected connectables
			  */
			  BLE.state = WAIT_GET_DET_CONNECTABLES;
			  timer = getSysTime();
			}
	break;
	/*************************************************************State WAIT_GET_DET_CONNECTABLES****************************************************************************/
	case (WAIT_GET_DET_CONNECTABLES):
			/*There is a notification from the SPI server*/
			if(hasNewRxBuffer == 1)
			{
				/*
				If the BLE chip reinitialises during when in this state, return to state SET_FILTER_MSG
				*/
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x03/*INIT OK*/) && (rxBuffer[2] == 0x01/*WAIT_BLE_INIT OP MODE*/))
				{
					testCounterBLEChipReinitWAIT_SET_MODE++;
					hasNewRxBuffer = 0;                                  					
					BLE.state = SET_FILTER_MSG;
				}
				/*
				Wait here until the BLE chip sends an event that connectables were detected
				*/
				if((rxBuffer[0] == 0x02/*EVT*/) && (rxBuffer[1] == 0x05/*EVT_DETECTED_CONNECTABLE*/))
				{
					/*Copy detected connectables here*/
					BLE.ScanComplete = 1;
					BLE.NumberOfDetectedChargingStations = rxBuffer[2];
					//memcpy(&BLE.DetectedConnectable1[0], &rxBuffer[3], (6*BLE.NumberOfDetectedConnectables));
					if(BLE.NumberOfDetectedChargingStations > 0) 
					{
						memcpy(&BLE.DetectedChargingStation_1_UUID[0], &rxBuffer[3], 6);
					}
					if(BLE.NumberOfDetectedChargingStations > 1) 
					{
						memcpy(&BLE.DetectedChargingStation_2_UUID[0], &rxBuffer[9], 6);
						
						
					}
					if(BLE.NumberOfDetectedChargingStations > 2)
					{
						memcpy(&BLE.DetectedChargingStation_3_UUID[0], &rxBuffer[15], 6);
						
					}						
						
					if(BLE.NumberOfDetectedChargingStations > 3) 
					{
						memcpy(&BLE.DetectedChargingStation_4_UUID[0], &rxBuffer[21], 6);
						
					}
						
					if(BLE.NumberOfDetectedChargingStations > 4) 
					{
						memcpy(&BLE.DetectedChargingStation_5_UUID[0], &rxBuffer[27], 6);
						
					}
						
					if(BLE.NumberOfDetectedChargingStations > 5) 
					{
/* 						memcpy(&BLE.DetectedChargingStation_6_UUID[0], &rxBuffer[93], 6);
						memcpy(&BLE.DetectedChargingStation_6_Name[0], &rxBuffer[99], 12); */
					}
						
					if(BLE.NumberOfDetectedChargingStations > 6)
					{
/* 						memcpy(&BLE.DetectedChargingStation_7_UUID[0], &rxBuffer[111], 6);
						memcpy(&BLE.DetectedChargingStation_7_Name[0], &rxBuffer[117], 12); */
					}
						
					if(BLE.NumberOfDetectedChargingStations > 7)
					{
/* 						memcpy(&BLE.DetectedChargingStation_8_UUID[0], &rxBuffer[129], 6);
						memcpy(&BLE.DetectedChargingStation_8_Name[0], &rxBuffer[135], 12); */
					}							
					BLE.state = GET_CONN_NAMES;
					timer = getSysTime();
				}
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
				*/
				hasNewRxBuffer = 0;
			}
			if(getSystimeDiff(timer) >= 3000)
			{
				timer = getSysTime();
				BLE.state = GET_DET_CONNECTABLES;
			}

	break;
	/*************************************************************State GET_CONN_NAMES****************************************************************************/
	case (GET_CONN_NAMES):
			if(hasNewRxBuffer == 1)
			{
				/*New data arrived although not expected. Ignore it and reset hasNewRxBuffer to allow new notification */
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
				*/
				hasNewRxBuffer = 0;
				break;
			}
			/*
			Clear the buffer to send data packet.
			*/
			memset(sharedMemValue, 0, 22);
			/*
			Fill the data packet buffer.
			*/
			sharedMemValue[0] 	= 0x13; /* Command GET_CONN_NAMES */
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
			ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength);
			if(ppret == 0)
			{
			  /*
			  Go to state WAIT_GET_DET_CONNECTABLES and wait for detected connectables
			  */
			  BLE.state = WAIT_GET_CONN_NAMES;
			  timer = getSysTime();
			}
	break;
	/*************************************************************State WAIT_GET_CONN_NAMES****************************************************************************/
	case(WAIT_GET_CONN_NAMES):
	/*
	Wait for an ackowledge that the command to get the the connection address was received by the BLE chip successfuly. If data is recedived but it is not the 
	acknowledge, wait here.
	*/
			if(hasNewRxBuffer == 1)
			{						
				if((rxBuffer[0] == 0x00) && (rxBuffer[1] == 0x13))
				{
					/*
					Once the command has been acknowledged successfuly, copy the value and continue.
					*/
					if(BLE.NumberOfDetectedChargingStations > 0) memcpy(&BLE.DetectedChargingStation_1_Name[0], &rxBuffer[2], 9);
					if(BLE.NumberOfDetectedChargingStations > 1) memcpy(&BLE.DetectedChargingStation_2_Name[0], &rxBuffer[11], 9);
					if(BLE.NumberOfDetectedChargingStations > 2) memcpy(&BLE.DetectedChargingStation_3_Name[0], &rxBuffer[20], 9);
					if(BLE.NumberOfDetectedChargingStations > 3) memcpy(&BLE.DetectedChargingStation_4_Name[0], &rxBuffer[29], 9);
					 BLE.state = CHECK_IF_KNOWN_PAD;
					 BLE.Status = BLE_STATION_FOUND;
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
	break;
	/*************************************************************State CHECK_IF_KNOWN_PAD****************************************************************************/
	case(CHECK_IF_KNOWN_PAD):
						
			cmpRet = memcmp(&BLE.DeviceName[0],&BLE.DetectedChargingStation_1_Name[0], 9);
			if(cmpRet == 0)
			{
				BLE.ConnectToChargingStation = 1;
				BLE.InitiateConnection = 1;
				BLE.state = INITIATE_CONNECTION;
				BLE.Status = BLE_STATION_FOUND;
				timer = getSysTime();
				break;
			}
			cmpRet = memcmp(&BLE.DeviceName[0],&BLE.DetectedChargingStation_2_Name[0], 9);
			if(cmpRet == 0)
			{
				BLE.ConnectToChargingStation = 2;
				BLE.InitiateConnection = 1;
				BLE.state = INITIATE_CONNECTION;
				BLE.Status = BLE_STATION_FOUND;
				timer = getSysTime();
				break;
			}
			cmpRet = memcmp(&BLE.DeviceName[0],&BLE.DetectedChargingStation_3_Name[0], 9);
			if(cmpRet == 0)
			{
				BLE.ConnectToChargingStation = 3;
				BLE.InitiateConnection = 1;
				BLE.state = INITIATE_CONNECTION;
				BLE.Status = BLE_STATION_FOUND;
				timer = getSysTime();
				break;
			}
			cmpRet = memcmp(&BLE.DeviceName[0],&BLE.DetectedChargingStation_4_Name[0], 9);
			if(cmpRet == 0)
			{
				BLE.ConnectToChargingStation = 4;
				BLE.InitiateConnection = 1;
				BLE.state = INITIATE_CONNECTION;
				BLE.Status = BLE_STATION_FOUND;
				timer = getSysTime();
				break;
			}
			cmpRet = memcmp(&BLE.DeviceName[0],&BLE.DetectedChargingStation_5_Name[0], 9);
			if(cmpRet == 0)
			{
				BLE.ConnectToChargingStation = 5;
				BLE.InitiateConnection = 1;
				BLE.state = INITIATE_CONNECTION;
				BLE.Status = BLE_STATION_FOUND;
				timer = getSysTime();
				break;
			}
			
			 BLE.state = INITIATE_CONNECTION;
			 BLE.Status = BLE_SCAN_COMPLETE;
			 timer = getSysTime();


	break;
	
	/*************************************************************State INITIATE_CONNECTION****************************************************************************/
	case (INITIATE_CONNECTION):
	if(BLE.InitiateConnection == 1)
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
			/*
			Clear the buffer to send data packet.
			*/
			memset(sharedMemValue, 0, 22);
			/*
			Fill the data packet buffer.
			*/
			sharedMemValue[0] 	= 0x12; /* Command Initiate connection */
			sharedMemValue[1] = (BLE.ConnectToChargingStation - 1);
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
			ppret = SPITransportLayerPushTXData(sharedMemValue,sharedMemValueLength);
			if(ppret == 0)
			{
			  /*
			  Go to state WAIT_GET_DET_CONNECTABLES and wait for detected connectables
			  */
			  BLE.state = WAIT_CONNECTION;
			  timer = getSysTime();
			  BLE.InitiateConnection = 0;
			}
			
			
			
	}
	if(BLE.InitiateConnection == 0 && BLE.AutoConnectionMode == 1)	
	{	
		if(getSystimeDiff(timer) >= 5000)
		{
			BLE.ScanComplete = 0;
			FLAG = 0xAB;
			BLE.Scan = 0;
			BLE.InternalScanCMD = 1;
		}
	}
	break;
	/*************************************************************State WAIT_CONNECTION****************************************************************************/
	case (WAIT_CONNECTION):
			/*There is a notification from the SPI server*/
			if(hasNewRxBuffer == 1)
			{
				/*
				If the BLE chip reinitialises during when in this state, return to state SET_FILTER_MSG
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
					BLE.state = WAIT_FOR_PAD; //TODO: Scanner should send first data because PAD sending first data causes the scanner to get stuck at get connection address//GET_CONN_ADDRESS;
					timer = getSysTime();
				}
				/*
				hasNewRxBuffer is set to zero. This flag will be set by the SPI data processor once it has processed new data  from the BLE chip.
				*/
				hasNewRxBuffer = 0;
			}
			
			if(getSystimeDiff(timer) >= 5000)
				{
					BLE.ScanComplete = 0;
					FLAG = 0xAB;
					BLE.Scan = 0;
					BLE.InternalScanCMD = 1;
				}

	break;
	/*************************************************************State WAIT_FOR_PAD****************************************************************************/
	case(WAIT_FOR_PAD):
	if(getSystimeDiff(timer) >= 1)
	{
		/*
		The connection channel (0, 1 or 2) shall be updated to be used later for data transfer.	
		*/
		updateConnections(&rxBuffer[2]);
		BLE.state = WAIT_FIRST_RX_DATA; //TODO: Scanner should send first data because PAD sending first data causes the scanner to get stuck at get connection address//GET_CONN_ADDRESS;
		timer = getSysTime();
	}
	break;
	/*************************************************************State GET_CONN_ADDRESS****************************************************************************/
	case (GET_CONN_ADDRESS):
			/*
			The function updateConnections was used in state WAIT_CONNECTION to notify which BLE channel is used for the communication. Only the first active channel
			is used.
			*/
			for (j = 0; j < MAX_CONNECTIONS; j++) 
			{
				if (connections[j] == 1) 
				{
					/*
					send data to connection channel j.
					Clear the buffer to send data packet.
					*/
					memset(sharedMemValue, 0, 22);
					/*
					Fill the data packet buffer.
					*/
					sharedMemValue[0] 	= 0x0E; /* Command Get Connection Address */
					sharedMemValue[1] 	= j; /*Connection index*/
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
					ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
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
	/*************************************************************State WAIT_GET_CONN_ADDRESS****************************************************************************/
	case (WAIT_GET_CONN_ADDRESS):
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
					if (OPERATING_MODE == SCANNER) 
					{
						BLE.state = WAIT_FIRST_RX_DATA;
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
	/*************************************************************State WAIT_BEFORE_FIRST_TX************************************************************************/
	case(WAIT_BEFORE_FIRST_TX):
			if(getSystimeDiff(timer) >= 500)
			{	/*
				Scanner should be ready now. Go to state TX_DATA to transmitt the first data packet.
				*/
				timer = getSysTime();
				BLE.state = TX_DATA;
			}
	break;
	/*************************************************************State TX_DATA************************************************************************************/
	case (TX_DATA):
			/*
			The function updateConnections was used in state WAIT_CONNECTION to notify which BLE channel is used for the communication. Only the first active channel
			is used.
			*/
			for (j = 0; j < MAX_CONNECTIONS; j++) 
			{
				if (connections[j] == 1) 
				{
					/*
					send data to connection channel j.
					Clear the buffer to send data packet.
					*/
					memset(sharedMemValue, 0, 22);
					/*
					Fill the data packet buffer.
					*/
					sharedMemValue[0] 	= 0x09; /* Command BBCMD_SEND_DATA */
					sharedMemValue[1] 	= j; /*Communication channel to send data on*/
					sharedMemValue[2]	= datacounter++; /*Counter*/
					memcpy(&sharedMemValue[3], &DatafromRTE[0], 19); /*Payload Data starts here*/		
					sharedMemValueLength = 22;
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
					ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
					if (ppret == 0) 
					{
						timer = getSysTime();
						/*
						Go to state WAIT_RX_SEND_ACK to wait for an acknowledge from the BLE chip that it has received and processed the transmitt command
						*/
						BLE.state = WAIT_RX_SEND_ACK;
					}
					break;
				}
			}
	break;
	/******************************************************State WAIT_RX_SEND_ACK************************************************************************************/
	case (WAIT_RX_SEND_ACK):
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
					memcpy(&DatatoRTE[0], &rxBuffer[4], 19); /*Payload Data starts here*/
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
						BLE.ScanComplete = 0;
						FLAG = 0xAB;
						BLE.Scan = 0;
						BLE.InternalScanCMD = 1;
					}
				// BLE.state = GET_CONN_STATES;
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
	/******************************************************State WAIT_FIRST_RX_DATA*****************************************************************************************/
	case (WAIT_FIRST_RX_DATA):
			if (hasNewRxBuffer == 1) 
			{
				if((rxBuffer[0] == 0x02/*BB_MSGTYPE_EVENT*/) && (rxBuffer[1] == 0x02/*BB_EVT_RX_MSG*/))
				{
					/*
					New data packet received
					*/
					BLE.ConnectionIndex 	= rxBuffer[2]; /*Connection Index*/
					BLE.DataRoundTripCounter	= rxBuffer[3]; /*Counter*/
					memcpy(&DatatoRTE[0], &rxBuffer[4], 19); /*Payload Data starts here*/
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
	break;
	/******************************************************State WAIT_RX_DATA*****************************************************************************************/
	case (WAIT_RX_DATA):
			if (hasNewRxBuffer == 1) 
			{
				if((rxBuffer[0] == 0x02/*BB_MSGTYPE_EVENT*/) && (rxBuffer[1] == 0x02/*BB_EVT_RX_MSG*/))
				{
					/*
					New data packet received
					*/
					BLE.ConnectionIndex 	= rxBuffer[2]; /*Connection Index*/
					BLE.DataRoundTripCounter	= rxBuffer[3]; /*Counter*/
					memcpy(&DatatoRTE[0], &rxBuffer[4], 19); /*Payload Data starts here*/
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
					BLE.ScanComplete = 0;
					FLAG = 0xAB;
					BLE.Scan = 0;
					BLE.InternalScanCMD = 1;
					}
				// BLE.state = GET_CONN_STATES;
				// BLE.nextstate = WAIT_RX_DATA; //come back here
			}

	break;
	/******************************************************State GET_RSSI*****************************************************************************************/
	case (GET_RSSI):
			/*
			The function updateConnections was used in state WAIT_CONNECTION to notify which BLE channel is used for the communication. Only the first active channel
			is used.
			*/
			for (j = 0; j < MAX_CONNECTIONS; j++) 
			{
				if (connections[j] == 1) 
				{
					/*
					send data to connection channel j.
					Clear the buffer to send data packet.
					*/
					memset(sharedMemValue, 0, 22);
					/*
					Fill the data packet buffer.
					*/
					sharedMemValue[0] 	= 0x0D; /* Command Get Connection RSSI */
					sharedMemValue[1] 	= j; /*Communication channel to send data on*/
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
					ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
					if (ppret == 0) 
					{						
						timer = getSysTime();
						/*
						Go to state WAIT_GET_RSSI to wait for an acknowledge from the BLE chip that it has received and processed the command
						*/
						BLE.state = WAIT_GET_RSSI;
					}
					break;
				}
			}
	break;
	/******************************************************State WAIT_GET_RSSI*****************************************************************************************/
	case (WAIT_GET_RSSI):
			/*
			Wait for an ackowledge that the command to get the RSSI value was received by the BLE chip successfuly. If data is recedived but it is not the 
			acknowledge, wait here.
			*/
			if(hasNewRxBuffer == 1)
			{						
				if((rxBuffer[0] == 0x00) && (rxBuffer[1] == 0x0D))
				{
					/*
					Once the command has been acknowledged successfuly, copy the RSSI value and continue.
					*/
					BLE.RSSI = 0; /*clean the int*/
					BLE.RSSI = rxBuffer[2];
					BLE.state = GET_CONN_STATES;
					timer = getSysTime();
				}
				/*Check if received BLE data while waiting for RSSI value*/
				if((rxBuffer[0] == 0x02/*BB_MSGTYPE_EVENT*/) && (rxBuffer[1] == 0x02/*BB_EVT_RX_MSG*/))
				{
					/*
					New data packet received
					*/
					BLE.ConnectionIndex 	= rxBuffer[2]; /*Connection Index*/
					BLE.DataRoundTripCounter	= rxBuffer[3]; /*Counter*/
					memcpy(&DatatoRTE[0], &rxBuffer[4], 19); /*Payload Data starts here*/
					BLE.state = GET_RSSI;
					BLE.nextstate = TX_DATA;
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
			/*In case it takes too long to receive the RSSI value, continue to next state*/
			if(getSystimeDiff(timer) >= 300)
			{
				timer = getSysTime();
				BLE.state = GET_CONN_STATES;
			}
	break;	
	/******************************************************State GET_CONN_STATES*****************************************************************************************/
	case (GET_CONN_STATES):
			/*
			send data to connection channel j.
			Clear the buffer to send data packet.
			*/
			memset(sharedMemValue, 0, 22);
			/*
			Fill the data packet buffer.
			*/
			sharedMemValue[0] 	= 0x0C; /* Command Get Connection States */
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
			ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
			if (ppret == 0) 
			{						
				timer = getSysTime();
				/*
				Go to state WAIT_GET_RSSI to wait for an acknowledge from the BLE chip that it has received and processed the command
				*/
				BLE.state = WAIT_GET_CONN_STATES;
			}
	break;
	/******************************************************State WAIT_GET_CONN_STATES*****************************************************************************************/
	case (WAIT_GET_CONN_STATES):
			/*
			Wait for an ackowledge that the command to get the RSSI value was received by the BLE chip successfuly. If data is recedived but it is not the 
			acknowledge, wait here.
			*/
			if(hasNewRxBuffer == 1)
			{						
				if((rxBuffer[0] == 0x00) && (rxBuffer[1] == 0x0C))
				{
					/*
					Once the command has been acknowledged successfuly, copy the conn states values and continue.
					*/
					memcpy(&BLE.ConnectionStates[0], &rxBuffer[2],3);
					/*If BLE Connection is lost, go to state wait connection*/
					if((BLE.ConnectionStates[0] == 0) && (BLE.ConnectionStates[1] == 0) && (BLE.ConnectionStates[2] == 0))
					{
						BLE.state = WAIT_CONNECTION;
						timer = getSysTime();
					}
					else{
						BLE.state = BLE.nextstate;
						timer = getSysTime();
					}
				}
				/*Check if received BLE data while waiting for Connection States value*/
				if((rxBuffer[0] == 0x02/*BB_MSGTYPE_EVENT*/) && (rxBuffer[1] == 0x02/*BB_EVT_RX_MSG*/))
				{
					/*
					New data packet received
					*/
					BLE.ConnectionIndex 	= rxBuffer[2]; /*Connection Index*/
					BLE.DataRoundTripCounter	= rxBuffer[3]; /*Counter*/
					memcpy(&DatatoRTE[0], &rxBuffer[4], 19); /*Payload Data starts here*/
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
			/*In case it takes too long to receive the connection states, */
			if(getSystimeDiff(timer) >= 300)
			{
				timer = getSysTime();
				//for now, stay here
			}
	break;
	/*************************************************************State DISCONNECT_FROM_DEVICE**********************************************************************/
	/*
	Disconnect existing connection
	*/
	case(DISCONNECT_FROM_DEVICE):
				/*
			The function updateConnections was used in state WAIT_CONNECTION to notify which BLE channel is used for the communication. Only the first active channel
			is used.
			*/
			for (j = 0; j < MAX_CONNECTIONS; j++) 
			{
				if (connections[j] == 1) 
				{
					/*
					send data to connection channel j.
					Clear the buffer to send data packet.
					*/
					memset(sharedMemValue, 0, 22);
					/*
					Fill the data packet buffer.
					*/
					sharedMemValue[0] 	= 0x06; /* Command Disconnect From Device */
					sharedMemValue[1] 	= j; /*Communication channel to disconnect*/
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
					ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
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
	/*************************************************************State GO_TO_SLEEP****************************************************************************/
	case (GO_TO_SLEEP):

				//BLE_SetSleepMode();
				//BLE.state = WAIT_GO_TO_SLEEP;
					/*
					Clear the buffer to send data packet.
					*/
					memset(sharedMemValue, 0, 22);
					/*
					Fill the data packet buffer.
					*/
					sharedMemValue[0] 	= 0x10; /* Command Go to sleep */
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
					ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
					if (ppret == 0) 
					{						
						timer = getSysTime();
						BLE.GoToSleep = 0;
						BLE.GoToSleepNM = 0;
						CounterWaitToSleep = 0;
						BLE.state = WAIT_BLE_INIT;
					}
	break;
	/*************************************************************State WAIT_GO_TO_SLEEP****************************************************************************/
	case (WAIT_GO_TO_SLEEP):
		
					
					CounterWaitToSleep++;
					if(getSystimeDiff(timer) >= 500)
					{
						//SbcMC33xxCdd_SetLowPowerOff();
					}

	break;
	/*************************************************************State GO_TO_IDLE_MODE**********************************************************************/
	/*
	Wait here until BLE.Disconnect is reset
	*/
	case(GO_TO_IDLE_MODE):

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
				ppret = SPITransportLayerPushTXData(sharedMemValue, sharedMemValueLength);
				if (ppret == 0) 
				{										
					  /*
					  Go to state WAIT_SET_MODE and wait for transmitt to complete and also for command acknowledge from BLE chip
					  */
						BLE.state = WAIT_TO_RECONNECT;
				}

	break;	
	/*************************************************************State WAIT_TO_RECONNECT**********************************************************************/
	/*
	Wait here until BLE.Disconnect is reset
	*/
	case(WAIT_TO_RECONNECT):
		if(BLE.Disconnect == 0)
		{
			BLE.state = WAIT_CONNECTION;
		}
	break;	
	/******************************************************State default*****************************************************************************************/			
	default:
			BLE.state = WAIT_BLE_INIT;
	break;			
	}
	
	/*Onlyincrement LifesignMissingCounter if there is a BLE connection available */
	if( (BLE.ConnectionStates[0] == 1) || (BLE.ConnectionStates[1] == 1) || (BLE.ConnectionStates[2] == 1))
	{
		if(BLE.DataRoundTripCounter == OldDataRoundTripCounter)
		{
			LifesignMissingCounter++;
		}
		else
		{
			BLE.LifeSignStat = OK;
			BLE.Status = BLE_PAIRED;
			LifesignMissingCounter = 0;
		}
		if(LifesignMissingCounter > 2000) //This value should be accessible via CIF
		{
			BLE.LifeSignStat = ERROR;
			if(BLE.Status == BLE_PAIRED)
			{
				BLE.Status = BLE_READY;
			}
			Rte_Call_Event_BLE_COMM_TIMEOUT_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);	
			Rte_Call_Event_BLE_STATUS_SIGNAL_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
		}
		else
		{
			Rte_Call_Event_BLE_COMM_TIMEOUT_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
			Rte_Call_Event_BLE_STATUS_SIGNAL_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
		}
		
		OldDataRoundTripCounter = BLE.DataRoundTripCounter;
	}
	if( (BLE.ConnectionStates[0] == 0) && (BLE.ConnectionStates[1] == 0) && (BLE.ConnectionStates[2] == 0))
	{
		//BLE Connection lost
		BLE.LifeSignStat = LOSTBLE;
		if(BLE.Status == BLE_PAIRED)
		{
			BLE.Status = BLE_READY;
		}
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
    // first 3 bytes are to introduce characters that are not possible to be input by users with a cell-phone
    scanResponse[0] = 0x02;
    scanResponse[1] = GAP_ADTYPE_MANUFACTURER_SPECIFIC; // custom manufacturer data
    scanResponse[2] = 0x01; // SOH (start of heading - from ASCII table) (use here any value that a user cannot enter from a cell-phone)
    
    // configuring slave interval
    scanResponse[3] = 0x05;
    scanResponse[4] = GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE;
    // minConnInterval * 1.25ms range(0x0006 - 0x0C80)       //This is fixed in BLE chip so can be removed from here
    scanResponse[5] = LO_UINT16(minConnInterval);            //This is fixed in BLE chip so can be removed from here
    scanResponse[6] = HI_UINT16(minConnInterval);            //This is fixed in BLE chip so can be removed from here
    // maxConnInterval * 1.25ms range(0x0006 - 0x0C80)       //This is fixed in BLE chip so can be removed from here
    scanResponse[7] = LO_UINT16(maxConnInterval);            //This is fixed in BLE chip so can be removed from here
    scanResponse[8] = HI_UINT16(maxConnInterval);            //This is fixed in BLE chip so can be removed from here
    
    // tx power (not clear yet how this works)
    scanResponse[9] = 0x02;
    scanResponse[10] = GAP_ADTYPE_POWER_LEVEL;
    scanResponse[11] = 0;
    
    // device name
    scanResponse[12] = devNameLength+1;
    scanResponse[13] = GAP_ADTYPE_LOCAL_NAME_COMPLETE;
    
    if(devNameLength < (MAX_SPI_TX_LENGTH-14))
	{ // 17 characters for device name
        memcpy(&scanResponse[14], devName, devNameLength);
        scanResponseLength = 14+devNameLength;
        return 0;                                      //Not checked atm
    }else{                                             //Not checked atm
        return 1; // invalid device name               //Not checked atm
    }   
}
/*This function is called after connection has been established to update which of the three channels is active*/
void updateConnections(uint8_t * rnewConnections){
    connections[0] = rnewConnections[0];      //check if it is used anywhere
    connections[1] = rnewConnections[1];      //check if it is used anywhere
    connections[2] = rnewConnections[2];      //check if it is used anywhere
	
	BLE.ConnectionStates[0] = rnewConnections[0];
	BLE.ConnectionStates[1] = rnewConnections[1];
	BLE.ConnectionStates[2] = rnewConnections[2];
}

/*Called to get the time diff since the last state change for exampleto calculate timeout*/
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
uint8_t setSPIData(uint8_t * data, uint8_t length)
{
	Std_ReturnType eStdReturn;
	a = Dio_ReadChannel(DioConf_DioChannel_DioChannel_D_SPIRDY_BT_CU);
	if(a == 1)
	{
		/*Use memcpy in case data is overwritten by SPI_Transmit_Byte*/
		eStdReturn = SPI_Transmit_Byte(&data[0], &temp[0], length);
		if(eStdReturn != E_OK)
		{
			BLE.SPIsendBusyCounter++; //Check for optimization
			return 1; /* cannot push - slave sending or busy */ 
		}
		SPITransportLayerOnMasterTXComplete(); //only executed if the SPI transmission is successful
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
	a = Dio_ReadChannel(DioConf_DioChannel_DioChannel_D_SPIRDY_BT_CU);
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

void PackDataForBLETransfer(void)
{				
		InternalFromRte.CmdWSDStateMachine_ModeValue = (uint16) (((uint16) (((uint16) InternalFromRte.ModeValue) << 8)) | InternalFromRte.CmdWSDStateMachine);
		memset(Buffer_16_DatafromRTE,0,20);
		Buffer_16_DatafromRTE[0] = InternalFromRte.COM_I_DC_REQ_ORU * 100;
		Buffer_16_DatafromRTE[1] = InternalFromRte.COM_U_DC_ACT_ORU;
		Buffer_16_DatafromRTE[2] = InternalFromRte.COM_U_AC_ACT_ORU; //not used
		Buffer_16_DatafromRTE[3] = InternalFromRte.COM_I_DC_ACT_ORU;
		Buffer_16_DatafromRTE[4] = InternalFromRte.COM_U_DC_MAX_ORU;
		Buffer_16_DatafromRTE[5] = InternalFromRte.CmdWSDStateMachine_ModeValue;
		Buffer_16_DatafromRTE[6] = 0;
		Buffer_16_DatafromRTE[7] = 0;
		Buffer_16_DatafromRTE[8] = 0;
		Buffer_16_DatafromRTE[9] = 0;
		memcpy(DatafromRTE, Buffer_16_DatafromRTE, 19);
}

void UnpackDataFromBLETransfer(void)
{
		memset(Buffer_16_DataToRTE, 0, 20);
		memcpy(Buffer_16_DataToRTE,&DatatoRTE[0], 19);
    
    InternalToRte.COM_WSD_State = (uint8) Buffer_16_DataToRTE[0];
    
    InternalToRte.COM_AWC_X_Coordinate = (uint16) Buffer_16_DataToRTE[1];
    if (InternalToRte.COM_AWC_X_Coordinate == 1023) 
		{
			InternalToRte.COM_AWC_X_Coordinate = 2046;
		}
    
    InternalToRte.COM_AWC_Y_Coordinate = (uint16) Buffer_16_DataToRTE[2];
    if (InternalToRte.COM_AWC_Y_Coordinate == 1023) 
		{
			InternalToRte.COM_AWC_Y_Coordinate = 2046;
		}
    
    InternalToRte.Data_AWC_Panel_Verdrehwinkel  = (uint16) (Buffer_16_DataToRTE[3] % 512);
		InternalToRte.Data_AWC_Panel_Verdrehwinkel	= (uint8) ((((uint32) InternalToRte.Data_AWC_Panel_Verdrehwinkel) * 43691) >> 16);
		InternalToRte.Data_AWC_Panel_Verdrehwinkel 	= (((uint16) (((uint16)InternalToRte.Data_AWC_Panel_Verdrehwinkel) << 1)) / 3);
		
    InternalToRte.COM_AWC_MaxLadLeistung        = (Buffer_16_DataToRTE[4] >> 7) * 25;
    InternalToRte.COM_AWC_zMoverIsUp            = ((Buffer_16_DataToRTE[4] >> 6) % 2) != 0;  
    InternalToRte.COM_AWC_zMoverIsDown          = ((Buffer_16_DataToRTE[4] >> 5) % 2) != 0;
    InternalToRte.COM_AWC_zMoverActive          = ((Buffer_16_DataToRTE[4] >> 4) % 2) != 0;
    InternalToRte.COM_AWC_zMovrIsChargPos       = ((Buffer_16_DataToRTE[4] >> 3) % 2) != 0;
    InternalToRte.COM_AWC_zMoverLocked          = ((Buffer_16_DataToRTE[4] >> 2) % 2) != 0;
    InternalToRte.COM_AWC_Fehler_FOD            = ((Buffer_16_DataToRTE[4] >> 1) % 2) != 0;
    InternalToRte.COM_AWC_Verz_FOD              = (Buffer_16_DataToRTE[4] % 2) != 0;
    InternalToRte.PadSftyStateMgr               = Buffer_16_DataToRTE[5] >> 8;
    InternalToRte.ChrgInhibitVal                = ((Buffer_16_DataToRTE[5] >> 7) % 2) != 0;

}

/*Internal function to transmit and receive SPI data via MCAL*/
Std_ReturnType SPI_Transmit_Byte(uint8_t * src, uint8_t * dest, uint8_t byteCnt)
{
    Std_ReturnType eStdReturn;
    Spi_SeqResultType eSpiSeqResult;
    
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
    /*
    SPI_SEQ_OK          The last transmission of the Sequence has been finished successfully.
    SPI_SEQ_PENDING     The SPI handler/Driver is performing a SPI Sequence.
    SPI_SEQ_FAILED      The last transmission of the Sequence has failed.
    SPI_SEQ_CANCELLED   The last transmission of the Sequence has been cancelled by the user.
    */
    eSpiSeqResult = (uint8_t)Spi_GetSequenceResult(SpiConf_SpiSequence_Spi_Seq_OCom);
    if(eSpiSeqResult != SPI_SEQ_OK)
    {
        return E_NOT_OK;
    }
    
    /* Comment: Call the Spi Synchronous transmit API */
    eStdReturn = Spi_SyncTransmit(SpiConf_SpiSequence_Spi_Seq_OCom);
    if(eStdReturn != E_OK)
    {
        return E_NOT_OK;
    }
    
	memcpy(&arrReceive[0], &dest[0], byteCnt);	
	return E_OK;
}

BLE_Sleep_Status_E BLE_SetSleepMode (void)
{
	//BLE.GoToSleep = 1;
	BLE.GoToSleepNM = 0xAF;
	SPITransportLayerInit(HDLR_MASTER, &spiHdlrHWInterface);
	FLAG = 0xD0;
	return BLE_SLEEP_OK;
}

BLE_Wake_Status_E BLE_SetWakeUp(void)
{
	BLE.state = WAIT_BLE_INIT;
	BLE.Scan = 1;
	return BLE_WAKE_OK;
}

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------

  ------------------------[per instance memory API]--------------------------

*/
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
























/*------------------------[runnable entity skeletons]------------------------*/


			


/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------

  ------------------------[per instance memory API]--------------------------

*/
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

