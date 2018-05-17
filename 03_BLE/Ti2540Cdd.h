/*----------------------------------------------------------------------------
** Project Name:CAR_36_ORU
** #Archive: 20_CDD/BLE/Ti2540Cdd #
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


#include "Spi.h"
#include "Dio.h"
#include "Os.h"
#include <stdint.h>
#include <string.h> // memcpy

#include "SPITransportLayer.h" 
#include "typedefs.h"

#include "Rte_OruBleCdd.h"

#ifndef GOT_RTE_DATA
#define GOT_RTE_DATA 0xAAu
#endif

#ifndef BUSY
#define BUSY 0xFEu
#endif

#ifndef SENT_RTE_DATA
#define SENT_RTE_DATA 0xEFu
#endif

#define COM_AWC_Status_ServiceState 0x08
#define COM_AWC_Status_StandbyState 0x00
#define COM_AWC_Status_SearchingState 0x01
#define COM_AWC_Status_FoundState 0x02
#define COM_AWC_Status_EnablingState 0x03
#define COM_AWC_Status_zMoverState 0x04
#define COM_AWC_Status_NormalOperatingState 0x05
#define COM_AWC_Status_ProductionState 0x06
#define COM_AWC_Status_DisabledState 0x07
#define COM_AWC_Status_Init 0x0E
#define COM_AWC_Status_Fehler 0x0F

#define Maximum_Vehicle_Speed 65532

typedef enum {
	/*00*/WAIT_BLE_INIT=0x00,
	/*01*/READ_OP_MODE=0x01,
	/*02*/WAIT_OP_MODE=0x02,
	/*03*/SET_OP_MODE=0x03,
	/*04*/WAIT_SET_MODE=0x04,
	/*05*/WAIT_BRDCM=0x05,
	/*06*/GET_BRDCM=0x06,
	/*07*/SET_FILTER_MSG=0x07,
	/*08*/WAIT_SET_FILTER_MSG=0x08,
	/*09*/WAIT_CHECK_BRDCM=0x09,
	/*10*/CHECK_MSG_SET=0x0A,
	/*11*/TX_DATA=0x0B,
	/*12*/WAIT_TX_OK=0x0C,
	/*13*/RX_DATA=0x0D,
	/*14*/WAIT_CONNECTION=0x0E,
    /*15*/WAIT_BEFORE_FIRST_TX=0x0F,
	/*16*/WAIT_TO_TX=0x10,
	/*17*/WAIT_TX_ACK=0x11,
	/*18*/WAIT_RX_SEND_ACK=0x12,
	/*19*/WAIT_RX_DATA=0x13,
	/*20*/GET_RSSI=0x14,
	/*21*/WAIT_GET_RSSI=0x15,
	/*22*/GET_CONN_ADDRESS=0x16,
	/*23*/WAIT_GET_CONN_ADDRESS=0x17,
	/*24*/GET_CONN_STATES=0x18,
	/*25*/WAIT_GET_CONN_STATES=0x19,
	/*26*/DISCONNECT_FROM_DEVICE=0x20,
	/*27*/WAIT_TO_RECONNECT=0x21,
	/*28*/GO_TO_IDLE_MODE=0x22,
	/*29*/WAIT_GET_NVM_DATA=0x23,
	/*30*/GO_TO_SLEEP=0x24,
	/*31*/WAIT_GO_TO_SLEEP=0x25,
	/*32*/GET_DET_CONNECTABLES=0x26,
	/*33*/WAIT_GET_DET_CONNECTABLES=0x27,
	/*34*/INITIATE_CONNECTION = 0x28,
	/*35*/WAIT_SCAN_CMD = 0x29,
	/*36*/GET_CONN_NAMES = 0x30,
	/*37*/WAIT_GET_CONN_NAMES = 0x31,
	/*38*/WAIT_FOR_PAD = 0x32,
	/*39*/WAIT_FIRST_RX_DATA = 0x33,
	/*40*/CHECK_IF_KNOWN_PAD = 0x34,
	/*50*/VEHICLE_SPEED_INIT_VALUE = 0x35,
} APPState_t;

typedef enum {
	INIT=0,
	OK=1,
	ERROR=2,
	LOSTBLE=3,
} LifeSignStat_t;

/* typedef enum {
	BLE_SLEEP = 0,
	PAIRED = 1,
	SEARCHING = 2,
	SCAN_TIMEOUT = 3,
	NO_STATIONS_FOUND = 4,
	STATION_FOUND = 5,
	PAIRING_FAILED = 6,
	BLE_READY = 7,
	WRONG_PIN = 8,
	WRONG_PUK = 9,
	ADMIN_MODE = 10,
	ADMIN_MODE_NOT_POSSIBLE = 11,
	SCAN_COMPLETE = 12,
} BLE_Status_t; */

typedef struct 
{
	int 			RSSI;
	APPState_t 		state; 
	APPState_t 		nextstate;
	uint8_t 		DeviceAddress[6];
	uint8_t 		DataRoundTripCounter;
	uint8_t 		ConnectionIndex;
	uint8_t 		OperatingMode;
	uint8_t 		ConnectionStates[3];
	LifeSignStat_t 	LifeSignStat;
	BleStatus 		Status;
	uint8_t 		Disconnect;
	uint8_t 		DeviceName[17];
	uint8_t 		GoToSleep;
	uint8_t 		GoToSleepNM;
	uint8_t 		NumberOfDetectedChargingStations;
	uint8_t 		DetectedChargingStation_1_UUID[6];
	uint8_t 		DetectedChargingStation_1_Name[12];
	uint8_t 		DetectedChargingStation_2_UUID[6];
	uint8_t 		DetectedChargingStation_2_Name[12];
	uint8_t 		DetectedChargingStation_3_UUID[6];
	uint8_t 		DetectedChargingStation_3_Name[12];
	uint8_t 		DetectedChargingStation_4_UUID[6];
	uint8_t 		DetectedChargingStation_4_Name[12];
	uint8_t 		DetectedChargingStation_5_UUID[6];
	uint8_t 		DetectedChargingStation_5_Name[12];
	uint8_t 		DetectedChargingStation_6_UUID[6];
	uint8_t 		DetectedChargingStation_6_Name[12];
	uint8_t 		DetectedChargingStation_7_UUID[6];
	uint8_t 		DetectedChargingStation_7_Name[12];
	uint8_t 		DetectedChargingStation_8_UUID[6];
	uint8_t 		DetectedChargingStation_8_Name[12];
	uint8_t 		InitiateConnection;
	uint8_t 		AutoConnectionMode;
	uint8_t 		ScanComplete;
	uint8_t 		ConnectToChargingStation;
	uint8_t 		Scan;
	uint8_t 		InternalScanCMD;
	uint32_t 		TXackTimeoutCounter;
	uint32_t 		SPIreceiveBusyCounter;
	uint32_t 		SPIsendBusyCounter;
}	
t_BLE;
static t_BLE BLE;

static uint8_t OldDataRoundTripCounter;
static uint32_t CounterWaitToSleep;
uint8_t cmpRet;

SPITransportLayerHWInterface_t spiHdlrHWInterface;

    uint32_t timer;

static uint8_t AWC_Status;    

/* ------------------------------------------
 * defined from gap.h
 *------------------------------------------*/
#define GAP_ADTYPE_LOCAL_NAME_COMPLETE          0x09 //!< Complete local name
#define GAP_ADTYPE_POWER_LEVEL                  0x0A //!< TX Power Level: 0xXX: -127 to +127 dBm
#define GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE    0x12 //!< Min and Max values of the connection interval (2 octets Min, 2 octets Max) (0xFFFF indicates no conn interval min or max)
#define GAP_ADTYPE_ADV_INTERVAL                 0x1A //!< Advertising Interval
#define GAP_ADTYPE_MANUFACTURER_SPECIFIC        0xFF //!< Manufacturer Specific Data: first 2 octets contain the Company Identifier Code followed by the additional manufacturer specific data
#define HI_UINT16(a) (((a) >> 8) & 0xFF)
#define LO_UINT16(a) ((a) & 0xFF)



#define CONNECTABLE 3
#define SCANNER 2

// SET THE OPERATING MODE HERE
#define OPERATING_MODE SCANNER
//#define OPERATING_MODE CONNECTABLE

#define MAX_CONNECTIONS 3
static uint8_t connections[MAX_CONNECTIONS];

#define MAX_SPI_TX_LENGTH 31+10

#define BLE_RESET_ATTEMPTS 2


// -------------------
// External Functions
// -------------------
extern uint32_t getSysTime(void);
extern uint32_t getSystimeDiff(uint32_t time);
extern void onSPITxComplete(void);
extern uint8_t onSPIRxNewData(const uint8_t * data, uint8_t length);
extern uint8_t setSPIData(uint8_t * data, uint8_t length);
static uint8_t getSPIData(uint8_t * charPtr, uint8_t length);
uint8_t setDatatoRTE(uint8_t * DatatoRTE, uint8_t length);
uint8_t getDatafromRTE(uint8_t * DatafromRTE, uint8_t length);
// -----------------
// External vars
// -----------------
static uint8_t DatafromRTE[20];
static uint8_t DatatoRTE[20];
static uint16_t Buffer_16_DatafromRTE[10];
static uint16_t Buffer_16_DataToRTE[10];

typedef struct{
	uint16_t COM_I_DC_REQ_ORU;
	uint16_t COM_U_DC_ACT_ORU;
	uint16_t COM_U_AC_ACT_ORU;
	uint16_t COM_I_DC_ACT_ORU;
	uint16_t COM_U_DC_MAX_ORU;
	uint16_t CmdWSDStateMachine;
	uint16_t ModeValue;
	uint16_t CmdWSDStateMachine_ModeValue;
	uint16_t Data_AWC_Panel_PositionX;
	uint16_t Data_AWC_Panel_PositionY;
	uint16_t VehicleSpeed;
}InternalFromRte_t;
static InternalFromRte_t InternalFromRte;

typedef struct{
	uint8_t  COM_WSD_State;
	uint16_t COM_AWC_X_Coordinate;
	uint16_t COM_AWC_Y_Coordinate;
	uint32_t Data_AWC_Panel_Verdrehwinkel;
	uint16_t COM_AWC_MaxLadLeistung;
	uint8_t  COM_AWC_zMoverIsUp;
	uint8_t  COM_AWC_zMoverIsDown;
	uint8_t  COM_AWC_zMoverActive;
	uint8_t  COM_AWC_zMovrIsChargPos;
	uint8_t  COM_AWC_zMoverLocked;
	uint8_t  COM_AWC_Fehler_FOD;
	uint8_t  COM_AWC_Verz_FOD;
	uint16_t PadSftyStateMgr;
	uint8_t  ChrgInhibitVal;
}InternalToRte_t;
static InternalToRte_t InternalToRte = 
{
	0,   //COM_WSD_State
	0,   //COM_AWC_X_Coordinate
	0,   //COM_AWC_Y_Coordinate
	0,   //Data_AWC_Panel_Verdrehwinkel
	0,   //COM_AWC_MaxLadLeistung
	0,   //COM_AWC_zMoverIsUp
	0,   //COM_AWC_zMoverIsDown
	0,   //COM_AWC_zMoverActive
	0,   //COM_AWC_zMovrIsChargPos
	0,   //COM_AWC_zMoverLocked
	0,   //COM_AWC_Fehler_FOD
	0,   //COM_AWC_Verz_FOD
	0,   //PadSftyStateMgr
	0	 //ChrgInhibitVal
};

// -------------------
// Local functions
// -------------------
static uint8_t setScanResponse(uint8_t safetyByte, uint16_t minConnInterval,  uint16_t maxConnInterval, uint8_t txPower, uint8_t * devName, uint8_t devNameLength);
void updateConnections(uint8_t * rnewConnections);
void blemain(void);
void PackDataForBLETransfer(void);
void UnpackDataFromBLETransfer(void);
// -----------------
// Private vars
// -----------------

// internal SPITransportLayer usage
//static uint8_t internalRxBuffer[MAX_SPI_TX_LENGTH];
static uint8_t internalRxBuffer[200];
static uint8_t internalRxBufferLength = 0;
static uint8_t internalHasNewRxBuffer = 0;
static uint8_t internalReadCounter = 0;


static uint8_t rxBuffer[200];
static uint8_t rxBufferLength = 0;
static uint8_t hasNewRxBuffer = 0;
static uint8_t connections[MAX_CONNECTIONS];
static uint8_t hasTxComplete = 1;


static uint8_t scanResponse[200];
static uint8_t scanResponseLength=0;

static uint8_t src[200];
static uint8_t dest[200];
static uint8_t a;
static uint32_t timer1ms = 0;

// -------------------
// Local functions
// -------------------
Std_ReturnType SPI_Transmit_Byte(uint8_t * src, uint8_t * dest, uint8_t byteCnt);
// -----------------

static uint8_t ppret;
static uint8_t sharedMemValue[200];
static uint8_t sharedMemValueLength;

/*For XCP*/
static uint8_t temp[200];
static uint8_t arrReceive[200];
static uint8_t arrReceiveSendText[200];
static uint8_t byteCntSPI_Transmit_Byte;


static uint16_t OldVehSpeed;

uint16_t LifesignMissingCounter;
uint8_t j;
static uint8_t ResetCounterAtWAIT_TX_ACK = 0;
static uint8_t ResetCounterAtWAIT_RX_SEND_ACK = 0;

static uint8_t FLAG = 0xAB;
static uint8_t BLEResetCount = 0;
static uint8_t InitBLE = 0;
static uint8_t Read_In_WaitOpMode = 0;
static uint8_t Write_Out_ReadOpMode = 0;
static uint8_t testCounterBLEChipReinitWAIT_CONNECTION = 0;
static uint8_t testCounterBLEChipReinitWAIT_SET_MODE = 0;
static uint8_t testCounterBLEChipReinitWAIT_SET = 0;
static uint8_t testtimerWAIT_BUFFER_READ;
static uint8_t datacounter;

static uint8_t CMD_GO_TO_SLEEP;
uint8_t WAIT_Before_Shutdown;




