/*----------------------------------------------------------------------------
** Project Name:CAR_36_Wayside
** #Archive: WsSbcCddSwc.h #
** #Author: Reiner Bogenfuerst#
** #Date: 2015-02-24#
** (c) Copyright 2015, Bombardier Transportation
**----------------------------------------------------------------------------
** #Revision: #
**----------------------------------------------------------------------------
** Target system: Freescale MPC5744P
** Compiler:GHS
** Description: SBC Handler System Basis Chip_MC33907_8
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    -------------------------------------
** RBOGENFU		Reiner Bogenfuerst 		Bombardier Transportation
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log: #
**--------------------------------------------------------------------------*/
#ifndef WSSBCCDDSWC_H
#define WSSBCCDDSWC_H

/* Protection again #define uint8_t uint8 */
#ifndef uint8_t
typedef uint8   uint8_t;
#endif

/* Protection again #define uint16_t uint16 */
#ifndef uint16_t
typedef uint16  uint16_t;
#endif

/* Protection again #define uint32_t uint32 */
#ifndef uint32_t
typedef uint32  uint32_t;
#endif

/*Typedefs*/

/*---------------------------Function call parameters-----------------------*/
/*Enums*/
	enum SbcChannelId
	{
			SbcDigitalChannel_0 = 0,
	/*1*/	SbcDigitalChannel_1,
	/*2*/	SbcDigitalChannel_2,
	/*3*/	SbcDigitalChannel_3,
	/*4*/	SbcDigitalChannel_4,
	/*5*/	SbcDigitalChannel_5
	};
	enum Level
	{
			LOW = 0,
	/*1*/	HIGH
	};
	enum CanMode
	{
			SleepNoWakeUp = 0,
	/*1*/	ListenOnly,
	/*2*/	SleepWakeUp,
	/*3*/	NormalModeNoAutoDis,
	/*4*/	NormalModeAutoDis,
	/*5*/	NormalModeAutoDisVcanOVSup
	};
	enum WatcdogMode
	{
			WDGIF_OFF_MODE = 0,
	/*1*/	WDGIF_SLOW_MODE,
	/*2*/	WDGIF_FAST_MODE,
	/*3*/	WDGIF_UNDEFINED_MODE
	};
/*
-----------------------------------
Description |	Select AMUX output
-----------------------------------
	000		|	Vref
	001		|	Vsns wide range
	010		|	IO_0 wide range
	011		|	IO_1 wide range
	100		|	Vsns tight range
	101		|	IO_0 tight range
	110		|	IO_1 tight range
	111		|	Die temp. Sense
-----------------------------------	
*/
#define Vref								0x00
#define VsnsWideRange						0x01				
#define IO_0WideRange						0x02				
#define IO_1WideRange						0x03					
#define VsnsTightRange						0x04				
#define IO_0TightRange						0x05					
#define IO_1TightRange						0x06
#define DieTempSens							0x07
/*------------------------------------END-----------------------------------*/
/**
* @brief Voltage regulators and power supply
*/
#define READ_INIT_VREG1 					0x02
#define READ_STATUS_VREG1 					0x18
#define READ_DIAG_VREG1 					0x1C
#define READ_INIT_VREG2 					0x04
#define READ_STATUS_VREG2 					0x1A
#define READ_DIAG_VREG2 					0x1E
#define READ_DIAG_VREG3						0x20
#define READ_VREG_MODE						0x2C
/**				
* @brief CAN				
*/				
#define READ_INIT_CAN						0x06
#define READ_CAN_MODE						0x30
#define READ_CAN_MODE2						0x32
#define READ_DIAG_CAN1						0x22
#define READ_DIAG_CAN2						0x24
/**
* @brief Watchdog
*/
#define READ_WU_SOURCE						0x12
#define READ_WD_WINDOW 						0x4C
#define READ_WD_LFSR						0x4E
#define READ_WD_ANSWER						0x50
#define READ_WD_COUNTER						0x5A
#define READ_WD_INIT						0x58
#define WRITE_WD_WINDOW 					0xCC
#define WRITE_WD_ANSWER						0xD0
/**
* @brief Fail safe state machine
*/
#define READ_INIT_FSSM1						0x48
#define READ_INIT_FSSM2						0x4A
#define READ_INIT_SUP1						0x42
#define READ_INIT_SUP2						0x44
#define READ_INIT_SUP3						0x46
#define READ_DIAG_FS1						0x58
#define READ_DIAG_FS2						0x5C
/**
* @brief Hardware inputs and outputs
*/
#define READ_INIT_IO_WU1					0x08
#define READ_INIT_IO_WU2					0x0A
#define READ_IO_OUT_AMUX					0x2E
#define READ_IO 							0x16
#define WRITE_IO							0xAE
/**
* @brief Others SBC registers
*/
#define READ_MODE 							0x2A
#define READ_SPI_DIAG 						0x26
#define READ_HW_CONF 						0x10
#define READ_INIT_INT						0x0C
#define READ_COMMAND						0x00
#define WRITE_RSTb_request					0xD4
#define WRITE_MODE							0xAA
#define WRITE_CAN_MODE						0xB0
#define WRITE_CAN_MODE2						0xB2
#define WRITE_FS_OUT						0xD2
				
/**				
* @brief Others				
*/				
#define FltBit7								0x80
#define FltBit6								0x40
#define FltBit5								0x20
#define FltBit4								0x10
#define FltBit3								0x08
#define FltBit2								0x04
#define FltBit1								0x02
#define FltBit0								0x01
#define Set_RSTb_request					0x24
#define Set_LPOFF							0x24
#define Set_RequestINT_Pulse				0x18
/*Refer to datasheet page 75. Delete the bits to write AMUX*/
#define Delete_AMUX							0xF8
/*Refer to datasheet page 75. Delete the bits to write channel 4*/
#define DigitalOut4							0x3F
/*Refer to datasheet page 75. Delete the bits to write channel 5*/
#define DigitalOut5							0xCF
/*Refer to datasheet page 76&77 Can Mode.*/
#define Set_CanMode_SleepNoWakeup			0x00
#define Set_CanMode_ListenOnly				0x40
#define Set_CanMode_SleepWakeUp				0x80
#define Set_CanMode_NormalOpNoAutoDis		0xC0
#define Set_CanMode_NormalOpAutoDis			0xE0
#define Set_VcanOV_Mon						0x18

/**
* @brief Define  configuration registers of main logic. Datasheet page 53.
*/
#define WRITE_INIT_VREG1					0x82
#define WRITE_INIT_VREG2					0x84
#define WRITE_INIT_CAN						0x86
#define WRITE_INIT_IO_WU1					0x88
#define WRITE_INIT_IO_WU2					0x8A
#define WRITE_INIT_INT						0x8C

/**
* @brief Define  configuration registers of fail safe logic. Datasheet page 54.
*/
#define WRITE_INIT_SUPERVISOR1				0xC2
#define WRITE_INIT_SUPERVISOR2				0xC4
#define WRITE_INIT_SUPERVISOR3				0xC6
#define WRITE_INIT_FSM1						0xC8
#define WRITE_INIT_FSM2						0xCA
#define WRITE_INIT_WD						0xD6

/**
* @brief Define  configuration bits
*/
#define INSERT_PARITY_BIT					0x01
#define Set_Vcore_DIS_Bit					0x00
#define Set_IPFF_DIS_Bit					0x20
#define Set_Vpre_DIS_Bit					0x10
#define Set_Tcca_lim_off_50ms				0x40
#define Set_Icca_lim_out					0x20
/*Datasheet page 60*/
#define Set_INT_duration_25					0x80
#define Set_INT_inh_all						0x20
#define Set_INT_inh_Vsns					0x10
#define Set_INT_inh_Vpre					0x08
#define Set_INT_inh_Vcore					0x04
#define Set_INT_inh_Vothers					0x02 
/*Datasheet page 57*/	 
#define Set_CAN_WU_Single_Dominant_Pulse	0x40 
#define Set_CAN_TOY							0x10
#define Set_CAN_WU_360						0x08
/*Datasheet page 58*/
#define Set_IO_0_No_WU						0x00
#define Set_IO_0_Rising_WU					0x40
#define Set_IO_0_Falling_WU					0x80
#define Set_IO_0_Any_WU						0xC0
#define Set_IO_1_No_WU						0x00
#define Set_IO_1_Rising_WU					0x10
#define Set_IO_1_Falling_WU					0x20
#define Set_IO_1_Any_WU						0x30
#define Set_IO_2_No_WU						0x00
#define Set_IO_2_Rising_WU					0x04
#define Set_IO_2_Falling_WU					0x08
#define Set_IO_2_Any_WU						0x0C
#define Set_INT_inh_IO_1_masked				0x02
#define Set_INT_inh_IO_0_masked				0x01
/*Datasheet page 59*/
#define Set_IO_3_No_WU						0x00
#define Set_IO_3_Rising_WU					0x40
#define Set_IO_3_Falling_WU					0x80
#define Set_IO_3_Any_WU						0xC0
#define Set_IO_4_No_WU						0x00
#define Set_IO_4_Rising_WU					0x10
#define Set_IO_4_Falling_WU					0x20
#define Set_IO_4_Any_WU						0x30
#define Set_IO_5_No_WU						0x00
#define Set_IO_5_Rising_WU					0x04
#define Set_IO_5_Falling_WU					0x08
#define Set_IO_5_Any_WU						0x0C
#define Set_INT_inh_IO_23_masked			0x02
#define Set_INT_inh_IO_45_masked			0x01
/*Datasheet page 78*/
#define Set_FSSM_Vcore_OV					0x82
#define Set_FSSM_Vcore_UV_RSTb				0x41
#define Set_FSSM_Vcore_UV_RSTb_FSxx			0xC3
#define Set_FSSM_Vcca_OV					0x24
#define Set_FSSM_Vcca_UV_RSTb				0x18
#define Set_FSSM_Vcca_UV_RSTb_FSxx			0x30
#define Set_FSSM_Vcca_No_Effect				0x0C
/*Datasheet page 80*/
#define Set_FSSM_Vaux_OV					0x8A
#define Set_FSSM_Vaux_UV_RSTb				0x49
#define Set_FSSM_Vaux_UV_RSTb_FSxx			0xCB
#define Set_DIS_8s							0x18
#define Set_En_8s							0x0C
/*Datasheet page 82*/
#define Set_Vcore_uv_D						0x86
#define Set_Vcca_uv_D						0x45
#define Set_Vaux_uv_D						0x24
#define Set_Vaux_uv_5V						0x0D
/*Datasheet page 84*/
#define Set_IO_01_FS						0x81
#define Set_IO_45_FS						0x21
#define Set_IO_45_NOT_FS					0x09
#define Set_Rstb_low_1ms					0x11
#define Set_Rstb_low_10ms					0x05
/*Datasheet page 86*/
#define Set_IO_23_FS						0x41
#define Set_RSTb_err_FS_1					0x82
#define Set_Fccu_eaout_active_LOW			0x20
#define Set_Fccu_eaout_active_HIGH			0x08
#define Set_F_FS1							0x10
#define Not_F_FS1							0x04
/*Datasheet page 88*/
#define Set_WDGIF_OFF_MODE					0x0C /*WD Disabled*/
#define Set_WDGIF_SLOW_MODE					0xF3 /*1024ms*/ /*256ms   0xDB*/
#define Set_WDGIF_FAST_MODE					0x18 /*1ms*/


/* SBC global error definitions */
#define SBC_ERR_OK							0
#define SBC_SPI_COM_ERR						0x00000001

#define Hardware_Timer_0					0

#define SBCH_INVALID_MODE					0
#define SBCH_NORMAL_MODE					1
#define SBCH_INIT_MODE						2

#define	SBC_COM_TIMEOUT_US					(uint32)100000

/**
* @brief The INTb output pin generates a low pulse when an Interrupt condition occurs. The INTb behavior as well as the pulse duration
are set through SPI during INIT phase. It is possible to mask some Interruption source (see register mapping). Source:SBC_MC33907_8
Datasheet page 98.
*/
typedef struct
{
    struct
    {
		/*Byte 0*/
		uint8_t	VSNS_UV				:  1;  /* [7] Detection of Vbattery below 8.5V */
		uint8_t	VSUP_UV_7			:  1;  /* [6] Detection of VSUP below 7V (after reverse current protection diode)*/
		uint8_t	IPFF				:  1;  /* [5] Input power feed forward. Based on VSUP and IPRE_PEAK */
		uint8_t	ILIM_PRE			:  1;  /* [4] Pre-Regulator Current Limitation */
		uint8_t TWARN_PRE			:  1;  /* [3] Temperature warning on the pass transistor */
		uint8_t	BoB					:  1;  /* [2] Return the running state of VPRE converter (Buck or Boost mode) */
		uint8_t	VPRE_STATE			:  1;  /* [1] Return the activation state of VPRE DC/DC converter */
		uint8_t	VPRE_OV				:  1;  /* [0] Report a VPRE overvoltage detection */
		/*Byte 1*/
		uint8_t	VPRE_UV				:  1;  /* [7] Report a VPRE under voltage detection */
		uint8_t	ILIM_CORE			:  1;  /* [6] VCORE Current limitation */
		uint8_t	TWARN_CORE			:  1;  /* [5] Temperature warning on the pass transistor */
		uint8_t	VCORE_STATE			:  1;  /* [4] Return the activation state of VCORE DC/DC converter */
		uint8_t	VCORE_OV			:  1;  /* [3] Report a VCORE overvoltage detection */
		uint8_t	VCORE_UV			:  1;  /* [2] Report a VCORE under voltage detection */
		uint8_t	ILIM_CCA			:  1;  /* [1] VCCA Current limitation */
		uint8_t	TWARN_CCA			:  1;  /* [0] Temperature warning on the pass transistor (Internal Pass transistor only) */
		/*Byte 2*/
		uint8_t	TSDVCCA				:  1;  /* [7] Temperature shutdown of the VCCA */
		uint8_t	ILIM_CCA_OFF		:  1;  /* [6] Current limitation maximum duration expiration. */
		uint8_t	VCCA_OV				:  1;  /* [5] Report a VCCA overvoltage detection */
		uint8_t	VCCA_UV				:  1;  /* [4] Report a VCCA under voltage detection */
		uint8_t	ILIM_AUX			:  1;  /* [3] VAUX Current limitation */
		uint8_t	ILIM_AUX_OFF		:  1;  /* [2] Current limitation maximum duration expiration. */
		uint8_t	VAUX_OV				:  1;  /* [1] Report a VAUX overvoltage detection */
		uint8_t	VAUX_UV				:  1;  /* [0] Report a VAUX under voltage detection */
		/*Byte 3*/
		uint8_t	TSDVAUX				:  1;  /* [7] Temperature shutdown of the VAUX */
		uint8_t	ILIM_CAN			:  1;  /* [6] VCAN Current limitation */
		uint8_t	VCAN_OV				:  1;  /* [5] Report a VCAN overvoltage detection */
		uint8_t	VCAN_UV				:  1;  /* [4] Report a VCAN under voltage detection */
		uint8_t	TSDCAN				:  1;  /* [3] Temperature shutdown on the pass transistor. Auto restart when TJ < (TSDCAN -TSDCAN_HYST). */
		uint8_t	IO_0				:  1;  /* [2] Report IO_0 digital state change */
		uint8_t	IO_1				:  1;  /* [1] Report IO_1 digital state change */
		uint8_t	IO_2				:  1;  /* [0] Report IO_2 digital state change */
		/*Byte 4*/
		uint8_t	IO_3				:  1;  /* [7] Report IO_3 digital state change */											
		uint8_t	IO_4				:  1;  /* [6] Report IO_4 digital state change */
		uint8_t	IO_5				:  1;  /* [5] Report IO_5 digital state change */
		uint8_t	IO_0_WU				:  1;  /* [4] Report IO_0 WU event */
		uint8_t	IO_1_WU				:  1;  /* [3] Report IO_1 WU event */
		uint8_t	IO_2_WU				:  1;  /* [2] Report IO_2 WU event */
		uint8_t	IO_3_WU				:  1;  /* [1] Report IO_3 WU event */
		uint8_t	IO_4_WU				:  1;  /* [0] Report IO_4 WU event */
		/*Byte 5*/
		uint8_t	IO_5_WU				:  1;  /* [7] Report IO_5 WU event */
		uint8_t	CANLBATT			:  1;  /* [6] CANL short-circuit to battery det*/
		uint8_t	CANLGND				:  1;  /* [5] CANL short-circuit to GND detection */
		uint8_t	CANHBATT			:  1;  /* [4] CANH short-circuit to battery detection	*/
		uint8_t	CANHGND				:  1;  /* [3] CANH short-circuit to GND detection	*/
		uint8_t	CAN_WU				:  1;  /* [2] Report a CAN wake-up event */
		uint8_t	CAN_OT				:  1;  /* [1] CAN overtemperature detection */
		uint8_t	RXD_recessive		:  1;  /* [0] CAN RXD recessive clamping detection (short circuit to 5 V) */
		/*Byte 6*/
		uint8_t	TXD_dominant		:  1;  /* [7] CAN TXD dominant clamping detection (short circuit to GND) */
		uint8_t	CAN_dominant		:  1;  /* [6] CAN bus dominant clamping detection */
		uint8_t	CAN_OC				:  1;  /* [5] CAN overcurrent detection */
		uint8_t	INT_Request			:  1;  /* [4] MCU request for an Interrupt pulse */
		uint8_t	SPI_err				:  1;  /* [3] Secured SPI communication check */
		uint8_t	SPI_CLK				:  1;  /* [2] Report a wrong number of CLK pulse different than 16 during the NCS low pulse in Main state machine */
		uint8_t	SPI_Req				:  1;  /* [1] Invalid SPI access (Wrong write or read, write to INIT registers in normal mode, wrong address) */
		uint8_t	SPI_Parity			:  1;  /* [0] Report a Parity error in Main state machine */
	};
} __attribute__((packed))
t_bits;

static os_tick_t ostickCurrent	=0;
static os_tick_t ostickBegin	=0;
static uint32 u32TimeDiffInUs	=0;
static uint8 u8TimeOutDetected	=0;
static uint8 XCP_WDRESET		=0;
static uint32 u32SBCError		=SBC_ERR_OK;



typedef union
{
	uint8_t Data[sizeof (t_bits) / sizeof (uint8_t)]; 
	t_bits bits;
} t_SBC_MC33907_Interrupt; 

#ifdef _SBCMC33XXCDD_C_
	#define SBCMC33XXCDD_EXT
#else
	#define SBCMC33XXCDD_EXT extern
#endif
/*SBCMC33XXCDD_EXT Std_ReturnType SbcMC33xxCdd_Init (void);*/
SBCMC33XXCDD_EXT Std_ReturnType SbcMC33xxCdd_WdgSetMode (uint8 mode);
SBCMC33XXCDD_EXT Std_ReturnType SbcMC33xxCdd_SetCanMode (uint8 canMode);
SBCMC33XXCDD_EXT Std_ReturnType SbcMC33xxCdd_GetWdgLfsr (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) WdgLfsrValue);
SBCMC33XXCDD_EXT Std_ReturnType SbcMC33xxCdd_WdgSetTriggerCondition (uint8 lfsrByte, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) triggerConditionOutput);
SBCMC33XXCDD_EXT Std_ReturnType SbcMC33xxCdd_GetInterruptCode (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) interruptDataPtr);
SBCMC33XXCDD_EXT Std_ReturnType SbcMC33xxCdd_SetMuxChannel (uint8 MuxChanId);
SBCMC33XXCDD_EXT Std_ReturnType SbcMC33xxCdd_ClearFsOutput (uint8 lfsrByte);
SBCMC33XXCDD_EXT Std_ReturnType write_sbc( uint8_t RegisterAddress, uint8_t Data);
SBCMC33XXCDD_EXT Std_ReturnType read_sbc(uint8_t RegisterAddress, uint8_t * Data);
SBCMC33XXCDD_EXT uint8_t SbcH_ReadDigitalPin(uint8_t SbcChannelId);
SBCMC33XXCDD_EXT uint8_t ByteSwap(uint8_t byte_1);
SBCMC33XXCDD_EXT uint8_t flag;
#endif
