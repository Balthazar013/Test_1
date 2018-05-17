/*----------------------------------------------------------------------------
** Project Name:CAR_36_PAD
** #Archive: 22_BLECDD/Ti2540Cdd #
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

#ifndef GOT_RTE_DATA
#define GOT_RTE_DATA 0xAAu
#endif

#ifndef BUSY
#define BUSY 0xFEu
#endif

#ifndef SENT_RTE_DATA
#define SENT_RTE_DATA 0xEFu
#endif

typedef enum {
	/*00*/WAIT_BLE_INIT=0x00,/*Wait for the BLE Chip to send it's initialise data*/
	/*01*/READ_OP_MODE=0x01, /*Reading operation mode from BLE Chip*/
	/*02*/WAIT_OP_MODE=0x02, /*Waiting to get operational mode from BLE chip*/
	/*03*/SET_OP_MODE=0x03, /*Setting operational mode of BLE chip*/
	/*04*/WAIT_SET_MODE=0x04, /*Waiting for operational mode of BLE to be set*/
	/*05*/WAIT_BRDCM=0x05, /*Waiting for broadcast message*/
	/*06*/GET_BRDCM=0x06, /*Retrieving broadcast message*/
	/*07*/SET_FILTER_MSG=0x07, /*Setting filter message of BLE Chip*/
	/*08*/WAIT_SET_FILTER_MSG=0x08, /*Waiting for filter message to be set on BLE chip*/
	/*09*/WAIT_CHECK_BRDCM=0x09, /*Checking the broadcast message of the BLE chip*/
	/*10*/CHECK_MSG_SET=0x0A, /*Checking if set message was successful*/
	/*11*/TX_DATA=0x0B, /*Transmitting data*/
	/*12*/WAIT_TX_OK=0x0C, /*Waiting for acknowldge of data transmission*/
	/*13*/RX_DATA=0x0D, /*Receiving data*/
	/*14*/WAIT_CONNECTION=0x0E, /*Waiting for connection to get established*/
    /*15*/WAIT_BEFORE_FIRST_TX=0x0F, /*Waiting before first transmitt after fresh connection*/
	/*16*/WAIT_TO_TX=0x10, /*Waiting to transmitt in case of overload*/
	/*17*/WAIT_TX_ACK=0x11, /*Waiting for transmitt acknowledge*/
	/*18*/WAIT_RX_SEND_ACK=0x12, /*Waiting to send acknowldge from received BLE data*/
	/*19*/WAIT_RX_DATA=0x13, /*Waiting for new incoming BLE data*/
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
		/*30*/REQUEST_SLEEP = 0x24,
} APPState_t;

typedef enum {
	INIT=0,
	BLE_OK=1,
	ERROR=2,
	LOSTBLE=3,
} LifeSignStat_t;

typedef struct 
{
	int RSSI;
  // @@ ELEMENT = state
  // @@ STRUCTURE = t_BLE
  // @@ A2L_TYPE = PARAMETER
  // @@ DATA_TYPE = UBYTE
  // @@ END
	APPState_t state; 
	APPState_t nextstate;
	uint8_t DeviceAddress[6];
  // @@ ELEMENT = DataRoundTripCounter
  // @@ STRUCTURE = t_BLE
  // @@ A2L_TYPE = PARAMETER
  // @@ DATA_TYPE = UBYTE
  // @@ END
	uint8_t DataRoundTripCounter;
	uint8_t ConnectionIndex;
  // @@ ELEMENT = OperatingMode
  // @@ STRUCTURE = t_BLE
  // @@ A2L_TYPE = PARAMETER
  // @@ DATA_TYPE = UBYTE
  // @@ END
	uint8_t OperatingMode;
	uint8_t ConnectionStates[3];
  // @@ ELEMENT = LifeSignStat
  // @@ STRUCTURE = t_BLE
  // @@ A2L_TYPE = PARAMETER
  // @@ DATA_TYPE = UBYTE
  // @@ END
	LifeSignStat_t LifeSignStat;
	uint8_t Disconnect;
  // @@ ELEMENT = DeviceName
  // @@ STRUCTURE = t_BLE
  // @@ A2L_TYPE = STRING 17
  // @@ END
	uint8_t DeviceName[17];
	uint32_t TXackTimeoutCounter;
	uint32_t RXConnectableTimeoutCounter;
	uint32_t SPIreceiveBusyCounter;
	uint32_t SPIsendBusyCounter;
  // @@ ELEMENT = Request_Sleep
  // @@ STRUCTURE = t_BLE
  // @@ A2L_TYPE = PARAMETER
  // @@ DATA_TYPE = UBYTE
  // @@ END
	uint8_t Request_Sleep;
  // @@ ELEMENT = Inhibit_Sleep
  // @@ STRUCTURE = t_BLE
  // @@ A2L_TYPE = PARAMETER
  // @@ DATA_TYPE = UBYTE
  // @@ END
	uint8_t Inhibit_Sleep;
}
t_BLE;

// @@ INSTANCE = BLE
// @@ STRUCTURE = t_BLE
// @@ GROUP = BLE
// @@ END
static t_BLE BLE;

static uint8_t OldDataRoundTripCounter;

SPITransportLayerHWInterface_t spiHdlrHWInterface;

uint32_t timer;
uint8_t i;

static uint8 ManualControl=0;
static uint8 ManualWsdState=0;
static uint16 ManualMaxPower=0;
static uint8 ManualSafetyState=0;
static sint16 ManualPosX=0;
static sint16 ManualPosY=0;
static sint16 ManualAngle=0;
static boolean ManualErrorFod;
static boolean ManualZmoverUp;
static boolean ManualZmoverDown;
static boolean ManualInhibitCharging = 0;
static boolean ManualPosRSSIStatusVal = 0;
static boolean ManualPosInitStatusVal = 0;
static boolean ManualTempDly = 0;

static PP_Verz_FOD ManualstFodDly;
static Fehler_FOD ManualstFodError;
static FehlerZMover ManualstFehlerZMover;
static zMoverLocked ManualstZMoverLocked;
static zMoverIsInChrPosition ManualstzMoverIsInChrPosition;
static zMoverIsActive ManualstzMoverIsActive;

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
//#define OPERATING_MODE SCANNER
#define OPERATING_MODE CONNECTABLE

#define MAX_CONNECTIONS 3
static uint8_t connections[MAX_CONNECTIONS];

#define MAX_SPI_TX_LENGTH 80


void BleCdd_BLESendData(uint8 *Data);

// -------------------
// External Functions
// -------------------
extern uint32_t getSysTime(void);
extern uint32_t getSystimeDiff(uint32_t time);
extern void onSPITxComplete(void);
extern uint8_t onSPIRxNewData(const uint8_t * data, uint8_t length);
extern uint8_t setSPIData(uint8_t * data, uint8_t length);

static uint8_t getSPIData(uint8_t * charPtr, uint8_t length);
uint8_t getDatafromRTE(uint8_t * DatafromRTE, uint8_t length);

// -------------------
// Local functions
// -------------------
static uint8_t setScanResponse(uint8_t safetyByte, uint16_t minConnInterval,  uint16_t maxConnInterval, uint8_t txPower, uint8_t * devName, uint8_t devNameLength);
void updateConnections(uint8_t * rnewConnections);
void blemain();
// -----------------
// External vars
// -----------------
static uint8_t DatafromRTE[25];
static uint8_t DatatoRTE[25];
// -----------------
// Private vars
// -----------------

// internal SPITransportLayer usage
//static uint8_t internalRxBuffer[MAX_SPI_TX_LENGTH];
static uint8_t internalRxBuffer[100];
static uint8_t internalRxBufferLength = 0;
static uint8_t internalHasNewRxBuffer = 0;
static uint8_t internalReadCounter = 0;


static uint8_t rxBuffer[100];
static uint8_t rxBufferLength = 0;
static uint8_t hasNewRxBuffer = 0;
static uint8_t connections[MAX_CONNECTIONS];
static uint8_t hasTxComplete = 1;


static uint8_t scanResponse[100];
static uint8_t scanResponseLength=0;

static uint8_t src[100];
static uint8_t dest[100];
static uint8_t a;
static uint32_t timer1ms = 0;

// -------------------
// Local functions
// -------------------
Std_ReturnType SPI_Transmit_Byte(uint8_t * src, uint8_t * dest, uint8_t byteCnt);
// -----------------

static uint8_t ppret;
static uint8_t sharedMemValue[100];
static uint8_t sharedMemValueLength;

/*For XCP*/
static uint8_t temp[100];
static uint8_t arrReceive[100];
static uint8_t arrReceiveSendText[100];
static uint8_t byteCntSPI_Transmit_Byte;

uint16_t LifesignMissingCounter = 0;
	uint8_t i;
	
static uint8_t ReceivedDataOnPAD[22];
static uint8_t ResetCounterAtWAIT_TX_ACK = 0;
static uint8_t ResetCounterAtWAIT_RX_SEND_ACK = 0;

static uint8_t FLAG = 0xAB;
static uint8_t bFirstStart = FALSE;
static uint8_t InitBLE = 0;
static uint8_t Read_In_WaitOpMode = 0;
static uint8_t Write_Out_ReadOpMode = 0;
static uint8_t testTimercustomSPIWork = 0;
static uint8_t testCounterBLEChipReinitWAIT_CONNECTION = 0;
static uint8_t testCounterBLEChipReinitWAIT_SET_MODE = 0;
static uint8_t testCounterBLEChipReinitWAIT_SET = 0;
static uint8_t testtimerWAIT_BUFFER_READ;
static uint8_t datacounter;
