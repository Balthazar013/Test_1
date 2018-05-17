/*-----------------------------------------------------------------------------
** Project Name:
** #Archive: LINFlexUARTMode.c #
** #Author: Muneer Ramadan #
** #Date: 2016-08-10#
** (c) Copyright 2016, Bombardier Primove GmbH
**-----------------------------------------------------------------------------
** #Revision: #
**-----------------------------------------------------------------------------
** Target system: Freescale MPC5744P
** Compiler:GHS
** Description:
**
**-----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**-----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    --------------------------------------
** MuRa         Muneer Ramadan           
**-----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**-----------------------------------------------------------------------------
** #Log: #      See the history log file located in the main folder of 
**              the PFC component.
**-----------------------------------------------------------------------------*/

/*******************************************************************************
*                                   INCLUDES                                   *
********************************************************************************/
/* AUTOSAR header files*/
#include "Std_Types.h"
#include "TSMem.h"
#include "Dio.h"
#include "Mcl.h"
#include <Os.h>
#include <os_api.h>

/* PFC related header files */
#include "LINFlexUARTMode.h"
#include "LINFlexD_CFG.h"
#include "SC18IM700.h"
#include "ADP1048W.h"

/*******************************************************************************
*                                   DEFINES                                    *
********************************************************************************/
/* LINFlexD controller index used for UART communication with PFC */
#define LINFLEXD_HW_CTRL_0                          0x00     /*SA CPE B3 sample*/
#define LINFLEXD_HW_CTRL_1                          0x01     /*SA CPE B4 sample*/
#define LINFLEXD_HW_CTRL_IDX                        LINFLEXD_HW_CTRL_1

#if defined(LINFLEXD_HW_CTRL_0) && (LINFLEXD_HW_CTRL_0 == LINFLEXD_HW_CTRL_IDX)
    #define LINFlexD                            LINFlexD_0
    
    /* DMA channel index defined in tresos Mcl configurtion                    */
    /* It was expected to be defined automatically in CDD_Mcl_Cfg.h!           */
    #define DMA_CH_CFG_IDX_LINFlexD_TX          0             /* DMA channel 5 */
    #define DMA_CH_CFG_IDX_LINFlexD_RX          1             /* DMA channel 6 */
    
    #define DMA_CH_ID_LINFlexD_TX               5             /* DMA channel 5 */
    #define DMA_CH_ID_LINFlexD_RX               6             /* DMA channel 6 */
    
#else
    #define LINFlexD                            LINFlexD_1

    /* DMA channel index defined in tresos Mcl configurtion                    */
    /* It was expected to be defined automatically in CDD_Mcl_Cfg.h!           */
    #define DMA_CH_CFG_IDX_LINFlexD_TX          0            /* DMA channel 21 */
    #define DMA_CH_CFG_IDX_LINFlexD_RX          1            /* DMA channel 22 */
    
    #define DMA_CH_ID_LINFlexD_TX               21           /* DMA channel 21 */
    #define DMA_CH_ID_LINFlexD_RX               22           /* DMA channel 22 */
#endif

/* Timeout to enter the LINFlexD initialization mode at startup                */
#define UART_ENTER_INIT_MODE_TIMEOUT_US         1000        /* Timeout in us   */

/* Reset pulse width in ms */
#define SC18IM700_RESET_PULSE_WIDTH_MS          5           /* Time in ms      */

/*Cycle time for PFC main function in ms, it shall match the runnable time */
#define PFC_MAIN_FUNC_CYCLE_TIME_MS             2

/* 10 ms */
#define PFC_SYNC_VIN_UPD                        (uint32)(10/PFC_MAIN_FUNC_CYCLE_TIME_MS)

/* 50 ms - Time to wait for checking the VOUT after requesting it */
#define PFC_SYNC_VOUT_CHK_AFTER_REQ             (uint32)(50/PFC_MAIN_FUNC_CYCLE_TIME_MS)

/* 5V deviation is allowed in comparison to the requested VOUT voltage */
#define PFC_VOUT_VALUE_TOLERANCE                5.0f 

/* required time until SC18IM700 changes the baud rate after receiving the command via uart*/
/* 1 second */
#define SC18IM700_DELAY_UNTIL_BAUDRATE_CHANGED   (uint32)(1000/PFC_MAIN_FUNC_CYCLE_TIME_MS)

/* max time to receive a responce from the bridge after initiating a HW reset*/
/*100 ms*/
#define SC18IM700_HW_RESET_RESPONSE_TIMEOUT     (uint32)(100/PFC_MAIN_FUNC_CYCLE_TIME_MS)

/* Timeout before releasing the communication drop error with SC18IM7800       */
/* 5 seconds */
#define SC18IM700_RECONNECTION_TIMEOUT          (uint32)(5000/PFC_MAIN_FUNC_CYCLE_TIME_MS)

/* Timeout definitions for cyclic communication with SC18IM700/ADP1048W        */
/* TODO: It shall be dependent on the expected length of the UART TX/RX data   */
/* 100 ms  */
#define UART_CYC_TX_TIMEOUT                     (uint32)(100/PFC_MAIN_FUNC_CYCLE_TIME_MS)
/* 200 ms  */
#define UART_CYC_TXRX_TIMEOUT                   (uint32)(200/PFC_MAIN_FUNC_CYCLE_TIME_MS)
/* 1 second  */
#define UART_CYC_CLEAN_RX_BUFF_TIME             (uint32)(1000/PFC_MAIN_FUNC_CYCLE_TIME_MS)

/* PFC error suppresion time due to RCMB test triggerd by BLE                  */
/* 10 seconds */
#define PFC_ERROR_SUPPRESS_TIME                 (uint32)(10000/PFC_MAIN_FUNC_CYCLE_TIME_MS)
#define PFC_ERROR_SUPPRESS                      (uint8)0xA5
#define PFC_ERROR_ACTIVATE                      (uint8)0x5A
#define PFC_ERROR_RESET_DELAY                   (uint32)(50/PFC_MAIN_FUNC_CYCLE_TIME_MS)

/*Number of allowed attemps to retry sending a command                         */
#define UART_CMD_RETRY_ATTEMPTS                 1

/* PFC command Header start index and Header length                            */
#define UART_PFC_CMD_START_INDEX                3
#define UART_PFC_CMD_TX_HDR_SIZE                4
#define UART_PFC_CMD_TXRX_HDR_SIZE              7

/* PFC communication performance measurement - Health factors                  */
#define PFC_COM_PERF_MAX_COUNT                  100.0f
#define PFC_COM_PERF_COUNT_DOWN                 0.100f
#define PFC_COM_PERF_COUNT_UP                   0.001f

/* eDMA TX/RX buffer located in SRAM section .dma                              */
/* The RAM section .dma is defined in the linker configuration file            */
#pragma ghs section bss=".dma"
uint8 UART_DMA_TX_BUF[LINFLEXD_DMA_TX_BUF_SIZE];
uint8 UART_DMA_RX_BUF[LINFLEXD_DMA_RX_BUF_SIZE];
#pragma ghs section bss=default

/******************************************************************************
*                   XCP Working Page (FLASH/RAM)                              *
******************************************************************************/
#pragma ghs section bss =".workpage"
volatile PFC_Page_tp PFC_Page_1;
#pragma ghs section bss=default

#pragma ghs section rodata=".refpage"
const PFC_Page_tp PFC_Page_0 =
{
    /* Timeout for re-establishing a connection with the UART/I2C bridge [ms]   */
    5000,
    /* Timeout for transmitting data via UART using DMA channels [ms]           */
    100,
    /* Timeout for transmitting/Receiving data via UART using DMA channels [ms] */
    200,
    /* Time window for cleaning the UART RX buffer after reseting the bridge [ms] */
    1000,
    /* Time window for supprressing PFC errors which occur at startup [ms]      */
    10000,
    /* Timeout for receiving a response from the UART/I2C bridge after initiating a HW reset [ms] */
    100,
    /*  Time window required for changing the baud rate on the UART/I2C bridge [ms] */
    1000,
    /* Flag to activate the PWM frequency synchronisation with the external SYNC clock */
    1,
    /* Frequency division between the switching frequency and the external SYNC clock (valid values are 0,1,2 and 3)*/
    1,
    /* PFC HW Configuration Version used for SW compatibility check             */
    0x00010700,
    /* Input voltage scaling factor used for converting a RAW value received from PFC to a physical value */
    4.0f,
    /* Input current caling factor used for converting a RAW value received from PFC to a physical value */
    32.0f,
    /* Input power scaling factor used for converting a RAW value received from PFC to a physical value */
    2.0f,
    /* Line frequency scaling factor used  for converting a RAW value received from PFC to a physical value */
    163.84f,
    /* Output voltage Scaling factor used for converting a RAW value received from PFC to a physical value */
    4.0f,
    /* Output voltage scaling factor used for converting a physical value to a RAW value before sending it PFC */
    4.0f
};
#pragma ghs section rodata=default

uint8 PFC_PageSwtVar = 0;
static PFC_Page_tp *psPFC_ActivePagePointer = (PFC_Page_tp *)&PFC_Page_0;

/*******************************************************************************
*                    INTERNAL FUNCTION DESCLARATIONS                           *
********************************************************************************/
static void PFC_SYNC_FSM(void);

static uint8 UART_SetBaudRate(uint32_t uiLINIBRR, uint32_t uiLINFBRR, 
                              const uint32 u32Timeout);
static uint8 UART_TxData(uint8 u8TxNrBytes, uint8 *pu8TxData, const uint32 u32Timeout);
static uint8 UART_RxData(uint8 u8RxNrBytes, uint8 *pu8RxData, const uint32 u32Timeout);
static uint8 UART_TxRxData(uint8 u8TxNrBytes, uint8 *pu8TxData, 
                           uint8 u8RxNrBytes, uint8 *pu8RxData, const uint32 u32Timeout);
static uint8 UART_SC18IM700_ResetAndCheckResponse(const uint32 u32Timeout);

static uint8 PFC_CMD_ADD_TXRX_HEADER(uint8 u8TxLength, uint8 u8RxLength);
static uint8 PFC_CMD_ADD_TX_HEADER(uint8 u8TxLength);
static float PFC_RAW2PHYS(uint8 u8RawType, uint32 u32RawValue);
static uint16 PFC_PHYS2RAW(uint8 u8PhysType, float f32PhysValue);

static void PFC_SET_ERROR(uint32 u32ErrCode, boolean  bMergeErrCode);
static void PFC_SET_INTERNAL_ERROR(uint32 u32ErrCode);
static void PFC_CLEAR_ERRORS(void);

static void PFC_INC_PERF_COUNT(void);
static void PFC_DEC_PERF_COUNT(void);
static void PFC_INIT_VAR(void);

/******************************************************************************
*                           EXTERNAL CONSTANTS                                *
*******************************************************************************/

/******************************************************************************
*                           INTERNAL CONSTANTS                                *
*******************************************************************************/

/******************************************************************************
*                               EXTERNAL DATA                                 *
*******************************************************************************/

/******************************************************************************
*                               INTERNAL DATA                                 *
*******************************************************************************/
/* Temporary variables */
static uint8  u8Tmp;
static uint16 u16Tmp;
static uint32 u32Tmp;
static uint8  u8TmpArray[16];
static os_tick_t osTickBegin = 0;
static os_tick_t osTickNow   = 0;
    
/* UART state machine */

// @@ SYMBOL = u8UARTState
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint8 u8UARTState;
static uint8 u8TxDataUART[16];
static uint8 u8RxDataUART[16];
static uint8 u8ReturnUART;
static uint8 u8RetryCmdUART;

/* PFC state machine */

// @@ SYMBOL = ePFCState
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_STATE           ePFCState;

static uint32              u32PFCSyncCount;

// @@ SYMBOL = ePFCInitSubState
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_INIT_SUBSTATE   ePFCInitSubState;
static PFC_INIT_SUBSTATE   ePFCInitAfterWrState;

// @@ SYMBOL = ePFCSyncSubState
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_SYNC_SUBSTATE   ePFCSyncSubState;
static PFC_SYNC_SUBSTATE   ePFCSyncAfterWrState;

// @@ SYMBOL = ePFCNoComSubState
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_NO_COM_SUBSTATE ePFCNoComSubState;

// @@ SYMBOL = u32PFCError
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = ULONG
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint32              u32PFCError;

// @@ SYMBOL = u32PFCInternalError
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = ULONG
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint32              u32PFCInternalError;
static uint8               u8PFCSetErrorFlag;           /*Flag to activate setting the PFC error */
static uint32              u32PFCReqClrErrTimeStamp;

#ifdef EN_PFC_RECONNECT
// @@ SYMBOL = ePFCReconnectStep
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_RECONNECT_STEP  ePFCReconnectStep;
static uint32              PFC_RECONN_TIMEOUT_COUNT;  /* Reconnection attempts timeout counter */
static uint32              PFC_RECONN_TIMEOUT;        /* Reconnection timeout                  */
#endif

// @@ SYMBOL = PFC_COM_PERF_COUNT
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = FLOAT
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static float   PFC_COM_PERF_COUNT;              /* Comunication Performance Counter      */

// @@ SYMBOL = PFC_VIN
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = FLOAT
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static float    PFC_VIN;                        /* Input Voltage  [V]                    */

// @@ SYMBOL = PFC_IIN
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = FLOAT
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static float    PFC_IIN;                        /* Input Current  [A]                    */

// @@ SYMBOL = PFC_VOUT
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = FLOAT
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static float    PFC_VOUT;                       /* Output Voltage [V]                    */
static float    PFC_EXP_VOUT_MIN;               /* Min expected Output Voltage [V]       */
static float    PFC_EXP_VOUT_MAX;               /* Max expected Output Voltage [V]       */

// @@ SYMBOL = PFC_PIN
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = FLOAT
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static float    PFC_PIN;                        /* Input Power    [W]                    */
// @@ SYMBOL = PFC_VAC_LN_PRD
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = FLOAT
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static float    PFC_VAC_LN_PRD;                 /* VAC pin signal period [us]            */

// @@ SYMBOL = PFC_PGOOD
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE 0x01
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint8    PFC_PGOOD;                      /* Status PGOOD - GPIO                   */

// @@ SYMBOL = PFC_ACOK
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE 0x01
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint8    PFC_ACOK;                       /* Status AC_OK - GPIO                   */

// @@ SYMBOL = PFC_PSON
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE 0x01
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint8    PFC_PSON;                       /* Status PSON - GPIO                    */

// @@ SYMBOL = PFC_VOUT_REQ
// @@ A2L_TYPE = PARAMETER
// @@ DATA_TYPE = FLOAT
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static float    PFC_VOUT_REQ;                   /* Requested Output Voltage [V]          */

/* SCO 143149 */
//static uint8    PFC_POWER_ON_REQ;             /* Enable PFC Power request              */
static float    Pre_PFC_VOUT_REQ;               /* Previous Request                      */
static uint8    PFC_URGENT_CMD_REQ;             /* Urgent Command is requested           */

/* SCO 143149 */
//static uint8    Pre_PFC_POWER_ON_REQ;         /* Previous Request                      */

// @@ SYMBOL = PFC_STANDALONE
// @@ A2L_TYPE = PARAMETER
// @@ DATA_TYPE = UBYTE 0x01
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint8    PFC_STANDALONE;                 /* STANDALONE Request via XCP            */

static uint32   PFC_TIMEOUT_COUNT;              /* Response timeout counter              */

// @@ SYMBOL = PFC_NO_COM_ERR_COUNT
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = ULONG
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint32   PFC_NO_COM_ERR_COUNT;           /* Communication error occurence counter */

// @@ SYMBOL = PFC_CLEAR_FAULTS_REQ
// @@ A2L_TYPE = PARAMETER
// @@ DATA_TYPE = UBYTE 0x01
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static uint8    PFC_CLEAR_FAULTS_REQ;           /* Clear PFC faults request              */

static uint8    PFC_CLEAR_FAULTS_EXE;           /* Clear PFC faults is ongoing           */
static uint8    Pre_PFC_CLEAR_FAULTS_VALUE;     /* Previous PFC clear faults value       */
static uint32   PFC_SYNC_COUNT;                 /* Sync state counter                    */
static uint32   PFC_SYNC_VIN_UPD_COUNTSTAMP;    /* Sync state VIN update counter stamp   */
static uint32   PFC_SYNC_VOUT_REQ_COUNTSTAMP;   /* Sync state VOUT request counter stamp */

// @@ SYMBOL = PFC_STS_WORD.R
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UWORD
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_STS_WORD_REG  PFC_STS_WORD;           /* Status WORD         -  PMBus         */

// @@ SYMBOL = PFC_STS_VOUT.R
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_STS_VOUT_REG  PFC_STS_VOUT;           /* Status VOUT         -  PMBus         */

// @@ SYMBOL = PFC_STS_IN.R
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_STS_INPUT_REG PFC_STS_IN;             /* Status INPUT        -  PMBus         */

// @@ SYMBOL = PFC_STS_TEMP.R
// @@ A2L_TYPE = MEASURE
// @@ DATA_TYPE = UBYTE
// @@ BYTE_ORDER = MOTOROLA
// @@ GROUP = PFC
// @@ END
static PFC_STS_TEMP_REG  PFC_STS_TEMP;           /* Status TEMPERATURE  -  PMBus         */


/* eDMA Configuration */
static Mcl_DmaTcdType *TcdAddressTx;
static Mcl_DmaTcdAttributesType DmaTcdConfigTx;
static Mcl_DmaTcdType *TcdAddressRx;
static Mcl_DmaTcdAttributesType DmaTcdConfigRx;


/******************************************************************************
*                       PUBLIC FUNCTION DEFINITIONS                           *
******************************************************************************/
void LinEmuUart_Init(void)
{
    /* Precondition: The eDMA initialization has to be performed before invoking this function    */ 

    /* initialize UART state */
    u8UARTState = UART_STATE_IDLE;
    
    /* clear DMA TX/RX buffer */
    TS_MemSet((uint8 *)&UART_DMA_TX_BUF[0], 0, LINFLEXD_DMA_TX_BUF_SIZE);
    TS_MemSet((uint8 *)&UART_DMA_RX_BUF[0], 0, LINFLEXD_DMA_RX_BUF_SIZE);
    
    /* configure DMA TCD for TX/RX channels */
    TcdAddressTx = (Mcl_DmaTcdType *)Mcl_DmaGetChannelTcdAddress((Mcl_ChannelType)DMA_CH_CFG_IDX_LINFlexD_TX);
    TcdAddressRx = (Mcl_DmaTcdType *)Mcl_DmaGetChannelTcdAddress((Mcl_ChannelType)DMA_CH_CFG_IDX_LINFlexD_RX);
    
    /* make sure that PSON of ADP1048W is not enabled - GPIO PIN A[5] */
    /* SCO 143149 */
    //Dio_WriteChannel(DioConf_DioChannel_A5_D_EN_AFE_CM_PPM_00, ADP1048W_DIO_SWITCH_OFF);
    
    /* set UART baud rate to 9600[bit/s] */
    if(UART_SetBaudRate(LINFLEXD_LINIBRR_9600, 
                        LINFLEXD_LINFBRR_9600, 
                        UART_ENTER_INIT_MODE_TIMEOUT_US) != UART_RET_OK)
    {
        u8UARTState = UART_STATE_LIN_ERR;
        return;
    }
    
    /* read the SC18IM700 response received on UART DMA RX channel */
    if(UART_SC18IM700_ResetAndCheckResponse(SC18IM700_HW_RESET_RESPONSE_TIMEOUT) != UART_RET_RESPONSE_OK)
    {
        u8UARTState = UART_STATE_COM_ERR;
    }
}

/******************************************************************************
*                      P F C   I N I T   F U N C T I O N                      *
******************************************************************************/
void SCI_Pfc_Init(void)
{
    u32PFCError = PFC_ERR_OK;
    u32PFCSyncCount = 0;
    u8PFCSetErrorFlag = PFC_ERROR_SUPPRESS;
    u32PFCReqClrErrTimeStamp = 0;
    
    if(u8UARTState != UART_STATE_IDLE)
    {
        ePFCState = PFC_STATE_SC18_NOT_DETECTED;
        if(u8UARTState == UART_STATE_LIN_ERR)
        {
            PFC_SET_ERROR((uint32)(PFC_ERR_IN_UART_INIT|UART_INIT_LIN_CTRL_ERR), FALSE);
        }
        else if(u8UARTState == UART_STATE_COM_ERR)
        {
            PFC_SET_ERROR((uint32)(PFC_ERR_IN_UART_INIT|UART_INIT_SC18_COM_ERR), FALSE);
        }
    }
    else
    {
        ePFCState = PFC_STATE_INIT;
    }
    
    PFC_INIT_VAR();
}

/******************************************************************************
*                      P F C   M A I N   F U N C T I O N                      *
******************************************************************************/
void PFC_SYNC(void)
{
    
    /**************************************************************************
    *                 CONTROL PFC Error Handling                              *
    **************************************************************************/
    u32PFCSyncCount++;
    
    if((u8PFCSetErrorFlag != PFC_ERROR_ACTIVATE) && (u32PFCSyncCount > PFC_ERROR_SUPPRESS_TIME))
    {
        u8PFCSetErrorFlag = PFC_ERROR_ACTIVATE;
    }
    
    /* Automatic PFC Error Reset */
    if(u32PFCError == PFC_ERR_OK)
    {
        u32PFCReqClrErrTimeStamp = u32PFCSyncCount;
    }
    else
    {
        /*wait for 50ms before requesting a reset/clear of PFC errors*/
        if(((uint32)((sint32)u32PFCSyncCount - (sint32)u32PFCReqClrErrTimeStamp)) > PFC_ERROR_RESET_DELAY)
        {
            PFC_CLEAR_FAULTS_REQ = 1;
            u32PFCReqClrErrTimeStamp = u32PFCSyncCount;
        }
    }
    
    /**************************************************************************
    *                 CONTROL PFC OUTPUT POWER VIA PSON PORT                  *
    **************************************************************************/
    /* SCO 143149 */
    //if(Pre_PFC_POWER_ON_REQ != PFC_POWER_ON_REQ)
    //{
    //    if(u8PFCSetErrorFlag != PFC_ERROR_SUPPRESS)
    //    {
    //        Pre_PFC_POWER_ON_REQ = PFC_POWER_ON_REQ;
    //    
    //        if(PFC_POWER_ON_REQ == (uint8)ADP1048W_DIO_SWITCH_ON)
    //        {
    //            Dio_WriteChannel(DioConf_DioChannel_A5_D_EN_AFE_CM_PPM_00, ADP1048W_DIO_SWITCH_ON);
    //        }
    //        else
    //        {
    //            Dio_WriteChannel(DioConf_DioChannel_A5_D_EN_AFE_CM_PPM_00, ADP1048W_DIO_SWITCH_OFF);
    //        }
    //    }
    //}
    
    /**************************************************************************
    *     Check AC_OK and PGOOD signals and set error code accordingly        *
    **************************************************************************/
    PFC_ACOK = Dio_ReadChannel(DioConf_DioChannel_C12_D_ACOK_PFC_PPM_CM_05);
    if(PFC_ACOK == 0)
    {
        PFC_SET_ERROR(PFC_ERR_AC_NOK, TRUE);
    }
    
    PFC_PGOOD = Dio_ReadChannel(DioConf_DioChannel_D14_D_PGOOD_PFC_PPM_CM_05);
    if(PFC_PGOOD == 0)
    {
        PFC_SET_ERROR(PFC_ERR_PW_NOK, TRUE);
    }
    
    PFC_PSON = SIUL2.GPDO[5].B.PDO;
    
    /**************************************************************************
    *                   PFC SYNCHRONISATION STATE MACHINE                     *
    **************************************************************************/
    PFC_SYNC_FSM();
    
}

/******************************************************************************
*                      P F C   S T A T E   M A C H I N E                      *
******************************************************************************/
static void PFC_SYNC_FSM(void)
{
    switch(ePFCState)
    {
        /**************************************************************************
        *                      PFC SYNCHRONISATION STATE                          *
        **************************************************************************/
        case PFC_STATE_SYNC:
        {
            PFC_SYNC_COUNT++;
            
            /* Start Lable used for jumping to the start within the same cycle */
            PFC_SYNC_START_LABEL:
            
            /* Ignor sync state priority for one cycle after submitting a write request */
            if((ePFCSyncSubState != PFC_SYNC_AFTER_WR_REQ) && (u8RetryCmdUART == 0))
            {
                /**********************************************************************
                * 1st PRIO: Force the PFC FSM to send the requested output voltage    *
                **********************************************************************/
                if((Pre_PFC_VOUT_REQ != PFC_VOUT_REQ) 
                   ||
                   ( PFC_PSON /* PFC is activated by B6CDD*/
                     &&
                     ((uint32)((sint32)PFC_SYNC_COUNT - (sint32)PFC_SYNC_VOUT_REQ_COUNTSTAMP) > PFC_SYNC_VOUT_CHK_AFTER_REQ)
                     &&
                     ((PFC_VOUT < PFC_EXP_VOUT_MIN) || (PFC_VOUT > PFC_EXP_VOUT_MAX))
                   )
                  )
                {
                    PFC_URGENT_CMD_REQ = 1;
                    
                    if((u8ReturnUART == UART_RET_OK)&&(u8UARTState == UART_STATE_IDLE))
                    {
                        /* Set PFC SYNC state immediately to PFC_SYNC_WR_VOUT_REQ  */
                        Pre_PFC_VOUT_REQ = PFC_VOUT_REQ;
                        PFC_EXP_VOUT_MIN = PFC_VOUT_REQ - PFC_VOUT_VALUE_TOLERANCE;
                        PFC_EXP_VOUT_MAX = PFC_VOUT_REQ + PFC_VOUT_VALUE_TOLERANCE;
                        PFC_URGENT_CMD_REQ = 0;
                        PFC_SYNC_VOUT_REQ_COUNTSTAMP = PFC_SYNC_COUNT;
                        ePFCSyncSubState = PFC_SYNC_WR_VOUT_REQ;
                    }
                }
                else
                {
                    /******************************************************************
                    * 2nd PRIO: Force the PFC FSM to clear the faults                 *
                    ******************************************************************/
                    if((PFC_CLEAR_FAULTS_REQ)&& (!PFC_CLEAR_FAULTS_EXE))
                    {
                        PFC_URGENT_CMD_REQ = 1;
                        
                        if((u8ReturnUART == UART_RET_OK)&&(u8UARTState == UART_STATE_IDLE))
                        {
                            PFC_CLEAR_FAULTS_REQ = 0;
                            PFC_CLEAR_FAULTS_EXE = 1;
                            /* Set PFC SYNC state immediately to PFC_SYNC_CLEAR_FAULTS_REQ  */
                            PFC_URGENT_CMD_REQ = 0;
                            ePFCSyncSubState = PFC_SYNC_CLEAR_FAULTS_REQ;
                        }
                    }
                    else
                    {
                        /******************************************************************
                        * 3rd PRIO: Make sure that the input voltage and current value    *
                        * are updated cyclically within 10ms to be provided for B6-CDD    *
                        ******************************************************************/
                        if(((uint32)((sint32)PFC_SYNC_COUNT-(sint32)PFC_SYNC_VIN_UPD_COUNTSTAMP) > PFC_SYNC_VIN_UPD) 
                             && 
                            (u32PFCError == PFC_ERR_OK))
                        {
                            PFC_URGENT_CMD_REQ = 1;
                            
                            if((u8ReturnUART == UART_RET_OK)&&(u8UARTState == UART_STATE_IDLE))
                            {
                                PFC_SYNC_VIN_UPD_COUNTSTAMP = PFC_SYNC_COUNT;
                                PFC_URGENT_CMD_REQ = 0;
                                ePFCSyncSubState = PFC_SYNC_RD_VIN;
                            }
                        }
                    }
                }
            }
            
            /**********************************************************************
            * PFC SYNCRONISATION SUBSTATE                                         *
            **********************************************************************/
            switch(ePFCSyncSubState)
            {
                /**********************************************************************
                * PFC READ STATUS WORD REQUEST                                        *
                **********************************************************************/
                case PFC_SYNC_RD_STS:
                {
                    /* Read PFC status word */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_STATUS_WORD;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,2);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_STS;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING STATUS WORD                                  *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_STS:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_STS << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_STS;
                            u8RetryCmdUART++;
                        }
                        
                        break;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        u16Tmp = (((uint16)u8RxDataUART[1])<<8u) + (uint16)u8RxDataUART[0];
                        PFC_STS_WORD.R = u16Tmp;
                        
                        ePFCSyncSubState = PFC_SYNC_RD_VIN;
                        
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        if(PFC_CLEAR_FAULTS_EXE)
                        {
                            /* Clear the clear faults execution flag */
                            PFC_CLEAR_FAULTS_EXE = 0;
                            
                            /* Reset global error code */
                            PFC_CLEAR_ERRORS();
                            
                            /* Check AC_OK and PGOOD flags immediately after reseting the error code */
                            if(PFC_ACOK == 0)
                            {
                                PFC_SET_ERROR(PFC_ERR_AC_NOK, TRUE);
                            }
                            
                            if(PFC_PGOOD == 0)
                            {
                                PFC_SET_ERROR(PFC_ERR_PW_NOK, TRUE);
                            }
                        }
                        
                        /*************************************************************************************
                         * Modification made according to KPM:7050587 / RTC CR:105000 / RTC 8D Report 105034 *
                         * Evaluate error flags within PFC status word only if ACOK or PGOOD is low          *
                         *************************************************************************************/
                        if(((PFC_ACOK == 0) || (PFC_PGOOD == 0) ) 
                             && 
                           (u16Tmp&PFC_STS_WORD_MASK_FLT))
                        {
                            if(PFC_STS_WORD.B.IOUT_OC)
                            {
                                PFC_SET_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|PFC_STATE_IOUT_OC_FLT), TRUE);
                            }
                        
                            ePFCSyncSubState = PFC_SYNC_RD_STS_OUT;
                            
                            goto PFC_SYNC_START_LABEL;
                        }
                        
                        if(PFC_URGENT_CMD_REQ)
                        {
                            goto PFC_SYNC_START_LABEL;
                        }
                        
                        /* No break here in order to jump directly to next state PFC_SYNC_RD_VIN */
                        
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                        
                        break;
                    }
                }
                /**********************************************************************
                * PFC READ INPUT VOLTAGE REQUEST                                      *
                **********************************************************************/
                case PFC_SYNC_RD_VIN:
                {
                    /* Read input voltage */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_READ_VIN;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,2);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_VIN;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING INPUT VOLTAGE                                *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_VIN:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_VIN << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_VIN;
                            u8RetryCmdUART++;
                        }
                        
                        break;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        u32Tmp = (((uint32)u8RxDataUART[1])<<8u) + (uint32)u8RxDataUART[0];
                        PFC_VIN = PFC_RAW2PHYS(VAL_TYP_VIN, u32Tmp);
                        
                        ePFCSyncSubState = PFC_SYNC_RD_IIN;
                        
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        if(PFC_URGENT_CMD_REQ)
                        {
                            goto PFC_SYNC_START_LABEL;
                        }
                        
                        /* No break here in order to jump directly to next state PFC_SYNC_RD_IIN */
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                        
                        break;
                    }
                }
                /**********************************************************************
                * PFC READ INPUT CURRENT REQUEST                                      *
                **********************************************************************/
                case PFC_SYNC_RD_IIN:
                {
                    /* Read input current */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_READ_IIN;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,2);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_IIN;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING INPUT CURRENT                                *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_IIN:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_IIN << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_IIN;
                            u8RetryCmdUART++;
                        }
                        
                        break;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        u32Tmp = (((uint32)u8RxDataUART[1])<<8u) + (uint32)u8RxDataUART[0];
                        PFC_IIN = PFC_RAW2PHYS(VAL_TYP_IIN, u32Tmp);
                        
                        ePFCSyncSubState = PFC_SYNC_RD_PIN;
                        
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        if(PFC_URGENT_CMD_REQ)
                        {
                            goto PFC_SYNC_START_LABEL;
                        }
                        
                        /* No break here in order to jump directly to next state PFC_SYNC_RD_PIN */
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                        
                        break;
                    }
                }
                /**********************************************************************
                * PFC READ INPUT POWER REQUEST                                        *
                **********************************************************************/
                case PFC_SYNC_RD_PIN:
                {
                    /* Read input power */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_READ_PIN;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,2);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_PIN;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING INPUT POWER                                  *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_PIN:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_PIN << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_PIN;
                            u8RetryCmdUART++;
                        }
                        
                        break;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        u32Tmp = (((uint32)u8RxDataUART[1])<<8u) + (uint32)u8RxDataUART[0];
                        PFC_PIN = PFC_RAW2PHYS(VAL_TYP_PIN, u32Tmp);
                        
                        ePFCSyncSubState = PFC_SYNC_RD_VAC_LN_PRD;
                        
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        if(PFC_URGENT_CMD_REQ)
                        {
                            goto PFC_SYNC_START_LABEL;
                        }
                        
                        /* No break here in order to jump directly to next state PFC_SYNC_RD_VOUT */
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                        
                        break;
                    }
                }
                /**********************************************************************
                * PFC READ VAC LINE PERIOD                                            *
                **********************************************************************/
                case PFC_SYNC_RD_VAC_LN_PRD:
                {
                    /* Read the measured period on the VAC pin signal. 
                       Each LSB corresponds to 163.84 µs               */
                    u16Tmp  = (uint16)ADP1048W_CMD_VAC_LN_PRD;
                     
                    /* Extended command - byte high */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = (uint8)((uint16)(u16Tmp >> 8u));
                    /* Extended command - byte low  */
                    u8TxDataUART[1+UART_PFC_CMD_START_INDEX] = (uint8)((uint16)(u16Tmp & 0x00FF));
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(2,1);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_VAC_LN_PRD;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING VAC LINE PERIOD                              *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_VAC_LN_PRD:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_VAC_LN_PRD << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_VAC_LN_PRD;
                            u8RetryCmdUART++;
                        }
                        
                        break;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        u32Tmp = (uint32)u8RxDataUART[0];
                        PFC_VAC_LN_PRD = PFC_RAW2PHYS(VAL_TYP_VAC_LN_PRD, u32Tmp);
                        
                        ePFCSyncSubState = PFC_SYNC_RD_VOUT;
                        
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        if(PFC_URGENT_CMD_REQ)
                        {
                            goto PFC_SYNC_START_LABEL;
                        }
                        
                        /* No break here in order to jump directly to next state PFC_SYNC_RD_VOUT */
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                        
                        break;
                    }
                }
                /**********************************************************************
                * PFC READ OUTPUT VOLTAGE REQUEST                                     *
                **********************************************************************/
                case PFC_SYNC_RD_VOUT:
                {
                    /* Read output voltage */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_READ_VOUT;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,2);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_VOUT;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING OUTPUT VOLTAGE                               *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_VOUT:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 2u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_VOUT << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_VOUT;
                            u8RetryCmdUART++;
                        }
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        u32Tmp = (((uint32)u8RxDataUART[1])<<8u) + (uint32)u8RxDataUART[0];
                        PFC_VOUT = PFC_RAW2PHYS(VAL_TYP_VOUT, u32Tmp);
                        
                        ePFCSyncSubState = PFC_SYNC_RD_STS;
                        
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        goto PFC_SYNC_START_LABEL;
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                    }
                    
                    break;
                }
                /**********************************************************************
                * PFC WRITE OUTPUT VOLTAGE REQUEST                                    *
                **********************************************************************/
                case PFC_SYNC_WR_VOUT_REQ:
                {
                    u16Tmp = PFC_PHYS2RAW(VAL_TYP_VOUT, PFC_VOUT_REQ);
                    
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_VOUT_COMMAND;
                    /* Data byte low */
                    u8TxDataUART[1+UART_PFC_CMD_START_INDEX]=(uint8)((uint16)(u16Tmp & 0x00FF));
                    /* Data byte high */
                    u8TxDataUART[2+UART_PFC_CMD_START_INDEX]=(uint8)((uint16)(u16Tmp >> 8u));
                    
                    u8Tmp = PFC_CMD_ADD_TX_HEADER(3);
                    
                    u8ReturnUART = UART_TxData(u8Tmp, &u8TxDataUART[0], UART_CYC_TX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_WR_VOUT_REQ;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR TRANSMITTING OUTPUT VOLTAGE REQUEST                    *
                **********************************************************************/
                case PFC_SYNC_WAIT_WR_VOUT_REQ:
                {
                    u8ReturnUART = UART_TxData(u8Tmp, &u8TxDataUART[0], UART_CYC_TX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_WR_VOUT_REQ << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_WR_VOUT_REQ;
                            u8RetryCmdUART++;
                        }
                    }
                    else if(u8ReturnUART == UART_RET_DATA_TRANSMITTED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        ePFCSyncAfterWrState = PFC_SYNC_RD_VOUT;
                        ePFCSyncSubState = PFC_SYNC_AFTER_WR_REQ;
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                /**********************************************************************
                * PFC CLEAR FAULTS REQUEST                                            *
                **********************************************************************/
                case PFC_SYNC_CLEAR_FAULTS_REQ:
                {
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_CLEAR_FAULTS;
                    
                    u8Tmp = PFC_CMD_ADD_TX_HEADER(1);
                    
                    u8ReturnUART = UART_TxData(u8Tmp, &u8TxDataUART[0], UART_CYC_TX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_CLEAR_FAULTS_REQ;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR TRANSMITTING CLEAR FAULTS REQUEST                      *
                **********************************************************************/
                case PFC_SYNC_WAIT_CLEAR_FAULTS_REQ:
                {
                    u8ReturnUART = UART_TxData(u8Tmp, &u8TxDataUART[0], UART_CYC_TX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_CLEAR_FAULTS_REQ << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_CLEAR_FAULTS_REQ;
                            u8RetryCmdUART++;
                        }
                    }
                    else if(u8ReturnUART == UART_RET_DATA_TRANSMITTED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        ePFCSyncAfterWrState = PFC_SYNC_RD_STS;
                        ePFCSyncSubState = PFC_SYNC_AFTER_WR_REQ;
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                /**********************************************************************
                * PFC READ STATUS OUTPUT REQUEST                                     *
                **********************************************************************/
                case PFC_SYNC_RD_STS_OUT:
                {
                    /* Read PFC status output register */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_STATUS_VOUT;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,1);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp, 
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_STS_OUT;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING STATUS OUTPUT                                *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_STS_OUT:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_STS_OUT << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_STS_OUT;
                            u8RetryCmdUART++;
                        }
                        
                        break;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        PFC_STS_VOUT.R = (uint8)u8RxDataUART[0];
                        ePFCSyncSubState = PFC_SYNC_RD_STS_IN;
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        if(PFC_STS_VOUT.B.VOUT_OV_FAULT)
                        {
                            PFC_SET_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|PFC_STATE_VOUT_OV_FLT), TRUE);
                        }
                        
                        if(PFC_STS_VOUT.B.VOUT_UV_FAULT)
                        {
                            PFC_SET_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|PFC_STATE_VOUT_UV_FLT), TRUE);
                        }
                        
                        if(PFC_URGENT_CMD_REQ)
                        {
                            goto PFC_SYNC_START_LABEL;
                        }
                        
                        /* No break here in order to jump directly to next state PFC_SYNC_RD_VIN */
                        
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                        
                        break;
                    }
                }
                /**********************************************************************
                * PFC READ STATUS INPUT REQUEST                                     *
                **********************************************************************/
                case PFC_SYNC_RD_STS_IN:
                {
                    /* Read PFC status output register */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_STATUS_INPUT;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,1);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp, 
                                                 &u8TxDataUART[0], 
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_STS_IN;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING STATUS INPUT                                 *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_STS_IN:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_STS_IN << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_STS_IN;
                            u8RetryCmdUART++;
                        }
                        
                        break;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        PFC_STS_IN.R = (uint8)u8RxDataUART[0];
                        ePFCSyncSubState = PFC_SYNC_RD_STS_TEMP;
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        if(PFC_STS_IN.B.VIN_OV_FAULT)
                        {
                            PFC_SET_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|PFC_STATE_VIN_OV_FLT), TRUE);
                        }
                        
                        if(PFC_STS_IN.B.VIN_UV_FAULT)
                        {
                            PFC_SET_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|PFC_STATE_VIN_UV_FLT), TRUE);
                        }
                        
                        if(PFC_STS_IN.B.IIN_OC_FAULT)
                        {
                            PFC_SET_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|PFC_STATE_IIN_OC_FLT), TRUE);
                        }
                        
                        if(PFC_URGENT_CMD_REQ)
                        {
                            goto PFC_SYNC_START_LABEL;
                        }
                        
                        /* No break here in order to jump directly to next state PFC_SYNC_RD_VIN */
                        
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                        
                        break;
                    }
                }
                /**********************************************************************
                * PFC READ STATUS TEMPERATURE REQUEST                                 *
                **********************************************************************/
                case PFC_SYNC_RD_STS_TEMP:
                {
                    /* Read PFC status output register */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_STATUS_TEMPERATURE;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,1);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp, 
                                                 &u8TxDataUART[0], 
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCSyncSubState = PFC_SYNC_WAIT_RD_STS_TEMP;
                    
                    break;
                }
                /**********************************************************************
                * PFC WAIT FOR RECEIVING STATUS TEMPERATURE                           *
                **********************************************************************/
                case PFC_SYNC_WAIT_RD_STS_TEMP:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_SYNC_WAIT_RD_STS_TEMP << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            u8ReturnUART = UART_RET_OK;
                            ePFCSyncSubState = PFC_SYNC_RD_STS_TEMP;
                            u8RetryCmdUART++;
                        }
                        
                        break;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8ReturnUART = UART_RET_OK;
                        
                        PFC_STS_TEMP.R = (uint8)u8RxDataUART[0];
                        ePFCSyncSubState = PFC_SYNC_RD_VIN;
                        u8RetryCmdUART = 0;
                        
                        PFC_INC_PERF_COUNT();
                        
                        if(PFC_STS_TEMP.B.OT_FAULT)
                        {
                            PFC_SET_ERROR((uint32)(PFC_ERR_IN_SYNC_STATE|PFC_STATE_OT_FLT), TRUE);
                        }
                        
                        goto PFC_SYNC_START_LABEL;
                        
                    }
                    else
                    {
                        PFC_DEC_PERF_COUNT();
                        
                        break;
                    }
                }
                /**********************************************************************
                * AFTER WRITE REQUEST -  STATE TO STABILIZE UART/I2C BRIDGE           *
                **********************************************************************/
                case PFC_SYNC_AFTER_WR_REQ:
                {
                    /* Resynchronize the state machine */
                    ePFCSyncSubState = ePFCSyncAfterWrState;
                    ePFCSyncAfterWrState = PFC_SYNC_SUBSTATE_UNKNOWN;
                    
                    break;
                }
                /**********************************************************************
                * UNKNOWN STATE -  STATE MACHINE ERROR                                *
                * should not be reached in normal operation                           *
                **********************************************************************/
                case PFC_SYNC_SUBSTATE_UNKNOWN:
                {
                    /* Resynchronize the state machine */
                    ePFCSyncSubState = PFC_SYNC_RD_STS;
                    u8RetryCmdUART = 0;
                    
                    break;
                }
                /**********************************************************************
                * PFC SYNC DEFAULT STATE                                              *
                **********************************************************************/
                default:
                {
                    //unknown sync substate --> Error Message?
                    ePFCSyncSubState = PFC_SYNC_SUBSTATE_UNKNOWN;
                    
                    break;
                }
            }
            
            break;
        }
        /**************************************************************************
        *                      PFC INITIALIZATION STATE                           *
        **************************************************************************/
        case PFC_STATE_INIT:
        {
            switch (ePFCInitSubState)
            {
                case PFC_INIT_GET_I2C_BUS_CAPA:
                {
                    u8TxDataUART[0] = SC18IM700_CMD_I2C_START;
                    u8TxDataUART[1] = ADP1048W_I2C_SLAVE_ADDR_WR;
                    u8TxDataUART[2] = 1;
                    u8TxDataUART[3] = ADP1048W_CMD_CAPABILITY;
                    u8TxDataUART[4] = SC18IM700_CMD_I2C_START;
                    u8TxDataUART[5] = ADP1048W_I2C_SLAVE_ADDR_RD;
                    u8TxDataUART[6] = 1;
                    u8TxDataUART[7] = SC18IM700_CMD_I2C_STOP;
                    
                    u8ReturnUART = UART_TxRxData(8u,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCInitSubState = PFC_INIT_WAIT_GET_I2C_BUS_CAPA;
                    
                    break;
                }
                case PFC_INIT_WAIT_GET_I2C_BUS_CAPA:
                {
                    u8ReturnUART = UART_TxRxData(8u, 
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_INIT_WAIT_GET_I2C_BUS_CAPA << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_INIT_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            ePFCInitSubState = PFC_INIT_GET_I2C_BUS_CAPA;
                            u8RetryCmdUART++;
                        }
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        ePFCInitSubState = PFC_INIT_SET_SC18IM700_BAUDRATE;
                        
                        if(u8RxDataUART[0] == ADP1048W_PMBUS_CAPIBILITY_MAX_SPEED)
                        {
                        #ifndef KEEP_SC18_DEF_I2C_SPEED
                            ePFCInitSubState = PFC_INIT_SET_I2C_MAX_SPEED;
                        #endif
                        }
                        
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                case PFC_INIT_SET_I2C_MAX_SPEED:
                {
                    u8TxDataUART[0] = SC18IM700_CMD_WRITE_REG;
                    u8TxDataUART[1] = SC18IM700_REG_I2C_CLKL;
                    u8TxDataUART[2] = SC18IM700_I2C_CLKL_MAX;
                    u8TxDataUART[3] = SC18IM700_REG_I2C_CLKH;
                    u8TxDataUART[4] = SC18IM700_I2C_CLKH_MAX;
                    u8TxDataUART[5] = SC18IM700_CMD_I2C_STOP;
                    
                    u8ReturnUART = UART_TxData(6u, &u8TxDataUART[0], UART_CYC_TX_TIMEOUT);
                    
                    ePFCInitSubState = PFC_INIT_WAIT_SET_I2C_MAX_SPEED;
                    
                    break;
                }
                case PFC_INIT_WAIT_SET_I2C_MAX_SPEED:
                {
                    u8ReturnUART = UART_TxData(6u, 
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_INIT_WAIT_SET_I2C_MAX_SPEED << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_INIT_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            ePFCInitSubState = PFC_INIT_SET_I2C_MAX_SPEED;
                            u8RetryCmdUART++;
                        }
                        
                    }
                    else if(u8ReturnUART == UART_RET_DATA_TRANSMITTED)
                    {
                        ePFCInitSubState = PFC_INIT_AFTER_WR_REQ;
                        ePFCInitAfterWrState = PFC_INIT_GET_I2C_SPEED;
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                case PFC_INIT_GET_I2C_SPEED:
                {
                    u8TxDataUART[0] = SC18IM700_CMD_READ_REG;
                    u8TxDataUART[1] = SC18IM700_REG_I2C_ADDR;
                    u8TxDataUART[2] = SC18IM700_REG_I2C_CLKL;
                    u8TxDataUART[3] = SC18IM700_REG_I2C_CLKH;
                    u8TxDataUART[4] = SC18IM700_REG_I2C_TIMEOUT;
                    u8TxDataUART[5] = SC18IM700_REG_I2C_STAT;
                    u8TxDataUART[6] = SC18IM700_CMD_I2C_STOP;
            
                    u8ReturnUART = UART_TxRxData(7u,
                                                 &u8TxDataUART[0],
                                                 5u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
            
                    ePFCInitSubState = PFC_INIT_WAIT_GET_I2C_SPEED;
                    
                    break;
                }
                case PFC_INIT_WAIT_GET_I2C_SPEED:
                {
                    u8ReturnUART = UART_TxRxData(7u, &u8TxDataUART[0], 5u, &u8RxDataUART[0], UART_CYC_TXRX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_INIT_WAIT_GET_I2C_SPEED << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_INIT_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            ePFCInitSubState = PFC_INIT_GET_I2C_SPEED;
                            u8RetryCmdUART++;
                        }
                        
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        if(SC18IM700_I2C_STAT_OK == u8RxDataUART[4])
                        {
                            //TODO?
                        }
                            
                        ePFCInitSubState = PFC_INIT_SET_SC18IM700_BAUDRATE;
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                case PFC_INIT_SET_SC18IM700_BAUDRATE:
                {
                    u8TxDataUART[0] = SC18IM700_CMD_WRITE_REG;
                    u8TxDataUART[1] = SC18IM700_REG_BRG0;
                    u8TxDataUART[2] = SC18IM700_BRG0_BR_230400;
                    u8TxDataUART[3] = SC18IM700_REG_BRG1;
                    u8TxDataUART[4] = SC18IM700_BRG1_BR_230400;
                    u8TxDataUART[5] = SC18IM700_CMD_I2C_STOP; //TODO CHECK
                    
                    u8ReturnUART = UART_TxData(5u,
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    ePFCInitSubState = PFC_INIT_WAIT_SET_SC18IM700_BAUDRATE;
                    
                    break;
                }
                case PFC_INIT_WAIT_SET_SC18IM700_BAUDRATE:
                {
                    u8ReturnUART = UART_TxData(5u,
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_INIT_WAIT_SET_SC18IM700_BAUDRATE << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_INIT_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            ePFCInitSubState = PFC_INIT_SET_SC18IM700_BAUDRATE;
                            u8RetryCmdUART++;
                        }
                        
                    }
                    else if(u8ReturnUART == UART_RET_DATA_TRANSMITTED)
                    {
                        ePFCInitSubState = PFC_INIT_AFTER_WR_REQ;
                        ePFCInitAfterWrState = PFC_INIT_WAIT_SC18IM700_BAUDRATE_CHANGED;
                        u32Tmp = 0;
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                case PFC_INIT_WAIT_SC18IM700_BAUDRATE_CHANGED:
                {
                    u32Tmp++;
                    
                    /*Check timeout*/
                    if(u32Tmp > SC18IM700_DELAY_UNTIL_BAUDRATE_CHANGED)
                    {
                        ePFCInitSubState = PFC_INIT_SET_UART_BAUDRATE;
                    }
                    
                    break;
                }
                case PFC_INIT_SET_UART_BAUDRATE:
                {
                    if(UART_SetBaudRate(LINFLEXD_LINIBRR_230400,
                                        LINFLEXD_LINFBRR_230400,
                                        UART_ENTER_INIT_MODE_TIMEOUT_US) != UART_RET_OK)
                    {
                        ePFCState = PFC_STATE_NO_COM;
                        u32Tmp = (uint32)(((uint32)PFC_INIT_SET_UART_BAUDRATE << 16)&0x00FF0000);
                        PFC_SET_ERROR((uint32)(PFC_ERR_IN_INIT_STATE|u32Tmp|PFC_STATE_NO_COM_ERR|PFC_STATE_NO_COM_LIN_ERR), FALSE);
                    }
                    else
                    {
                        ePFCInitSubState = PFC_INIT_SET_SC18IM700_STOP_CONDITION;
                    }
                    
                    break;
                }
                case PFC_INIT_SET_SC18IM700_STOP_CONDITION:
                {
                    u8TxDataUART[0] = SC18IM700_CMD_I2C_STOP;
                    
                    u8ReturnUART = UART_TxData(1u,
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    ePFCInitSubState = PFC_INIT_WAIT_SET_SC18IM700_STOP_CONDITION;
                    
                    break;
                }
                case PFC_INIT_WAIT_SET_SC18IM700_STOP_CONDITION:
                {
                    u8ReturnUART = UART_TxData(1u,
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_INIT_WAIT_SET_SC18IM700_STOP_CONDITION << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_INIT_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            ePFCInitSubState = PFC_INIT_SET_SC18IM700_STOP_CONDITION;
                            u8RetryCmdUART++;
                        }
                        
                    }
                    else if(u8ReturnUART == UART_RET_DATA_TRANSMITTED)
                    {
                        ePFCInitSubState = PFC_INIT_AFTER_WR_REQ;
                        ePFCInitAfterWrState = PFC_INIT_SET_PWM_EXT_SYNC_CLK;
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                case PFC_INIT_SET_PWM_EXT_SYNC_CLK:
                {
                    u16Tmp  = (uint16)ADP1048W_CMD_ADVANCED_FEATURE_ENABLE;
                    
                    /* Extended command - byte high */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = (uint8)((uint16)(u16Tmp >> 8u));
                    /* Extended command - byte low  */
                    u8TxDataUART[1+UART_PFC_CMD_START_INDEX] = (uint8)((uint16)(u16Tmp & 0x00FF));
                    
                    u8TxDataUART[2+UART_PFC_CMD_START_INDEX] = (uint8)ADP1048W_SET_ADVANCED_FEATURE_PWM_SYNC;
                    
                    u8Tmp = PFC_CMD_ADD_TX_HEADER(3);
                    
                    u8ReturnUART = UART_TxData(u8Tmp,
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    ePFCInitSubState = PFC_INIT_WAIT_SET_PWM_EXT_SYNC_CLK;
                    
                    break;
                }
                case PFC_INIT_WAIT_SET_PWM_EXT_SYNC_CLK:
                {
                    u8ReturnUART = UART_TxData(u8Tmp,
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_INIT_WAIT_SET_PWM_EXT_SYNC_CLK << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_INIT_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            ePFCInitSubState = PFC_INIT_SET_PWM_EXT_SYNC_CLK;
                            u8RetryCmdUART++;
                        }
                        
                    }
                    else if(u8ReturnUART == UART_RET_DATA_TRANSMITTED)
                    {
                        ePFCInitSubState = PFC_INIT_AFTER_WR_REQ;
                        ePFCInitAfterWrState = PFC_INIT_SET_SYNC_FREQ_DIV;
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                case PFC_INIT_SET_SYNC_FREQ_DIV:
                {
                    u16Tmp  = (uint16)ADP1048W_CMD_FREQ_SYNC_SET;
                    
                    /* Extended command - byte high */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = (uint8)((uint16)(u16Tmp >> 8u));
                    /* Extended command - byte low  */
                    u8TxDataUART[1+UART_PFC_CMD_START_INDEX] = (uint8)((uint16)(u16Tmp & 0x00FF));
                    
                    u8TxDataUART[2+UART_PFC_CMD_START_INDEX] = (uint8)ADP1048W_SET_FREQ_SYNC_DIVISION_2;
                    
                    u8Tmp = PFC_CMD_ADD_TX_HEADER(3);
                    
                    u8ReturnUART = UART_TxData(u8Tmp,
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    ePFCInitSubState = PFC_INIT_WAIT_SET_SYNC_FREQ_DIV;
                    
                    break;
                }
                case PFC_INIT_WAIT_SET_SYNC_FREQ_DIV:
                {
                    u8ReturnUART = UART_TxData(u8Tmp, 
                                               &u8TxDataUART[0],
                                               UART_CYC_TX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        if(u8RetryCmdUART > UART_CMD_RETRY_ATTEMPTS)
                        {
                            ePFCState = PFC_STATE_NO_COM;
                            u32Tmp = (uint32)(((uint32)PFC_INIT_WAIT_SET_SYNC_FREQ_DIV << 16)&0x00FF0000);
                            PFC_SET_INTERNAL_ERROR((uint32)(PFC_ERR_IN_INIT_STATE|u32Tmp|PFC_STATE_NO_COM_ERR));
                        }
                        else
                        {
                            ePFCInitSubState = PFC_INIT_SET_SYNC_FREQ_DIV;
                            u8RetryCmdUART++;
                        }
                    }
                    else if(u8ReturnUART == UART_RET_DATA_TRANSMITTED)
                    {
                        ePFCInitSubState = PFC_INIT_AFTER_WR_REQ;
                        ePFCInitAfterWrState = PFC_INIT_DONE;
                        u8RetryCmdUART = 0;
                    }
                    
                    break;
                }
                /**********************************************************************
                * AFTER WRITE REQUEST -  STATE TO STABILIZE UART/I2C BRIDGE           *
                **********************************************************************/
                case PFC_INIT_AFTER_WR_REQ:
                {
                    /* Resynchronize the state machine */
                    ePFCInitSubState = ePFCInitAfterWrState;
                    ePFCInitAfterWrState = PFC_INIT_SUBSTATE_UNKNOWN;
                    
                    break;
                }
                case PFC_INIT_DONE:
                {
                    ePFCState = PFC_STATE_SYNC;
                    
                    break;
                }
                case PFC_INIT_SUBSTATE_UNKNOWN:
                {
                    asm("nop");
                    
                    break;
                }
                default:
                {
                    ePFCInitSubState = PFC_INIT_SUBSTATE_UNKNOWN;
                    break;
                }
            }
            
            break;
        }
        /**************************************************************************
        *               PFC COMMUNICATION ERROR HANDLING STATE                    *
        **************************************************************************/
        case PFC_STATE_NO_COM:
        {
            switch(ePFCNoComSubState)
            {
                /**********************************************************************
                * CHECK eDMA ERROR REGISTER - UART TX/RX DMA CHANNELS!                *
                **********************************************************************/
                case PFC_NO_COM_CHK_DMA_STS:
                {
                    /*Increment the PFC communication error counter - for debug purposes  */
                    PFC_NO_COM_ERR_COUNT++;
                    
                    #ifdef EN_PFC_RECONNECT
                    PFC_RECONN_TIMEOUT_COUNT = 0;
                    #endif
                    
                    /* 1 - Check eDMA Error Register for UART TX/RX assigned DMA channels */
                    if(DMA_0.ERR.B.ERR21 || DMA_0.ERR.B.ERR22)
                    {
                        u32Tmp = u32PFCInternalError;
                        u32Tmp |= PFC_STATE_NO_COM_DMA_ERR;
                        u32PFCInternalError = 0;
                        PFC_SET_INTERNAL_ERROR(u32Tmp);
                        
                        /* Clear error flags in DMA Error Register*/
                        DMA_0.CERR.B.CERR = DMA_CH_ID_LINFlexD_TX;
                        DMA_0.CERR.B.CERR = DMA_CH_ID_LINFlexD_RX;
                    }
                    
                    ePFCNoComSubState = PFC_NO_COM_CHK_LINFLEXD_STS;
                    
                    break;
                }
                /**********************************************************************
                * CHECK LINFLEXD UART STATUS REGISTER!                                *
                **********************************************************************/
                case PFC_NO_COM_CHK_LINFLEXD_STS:
                {
                    /* 2 - Check LINFlexD/UART Mode Status Register */
                    if(LINFlexD.UARTSR.B.NF || LINFlexD.UARTSR.B.BOF || LINFlexD.UARTSR.B.FEF)
                    {
                        u32Tmp = u32PFCInternalError;
                        u32Tmp |= PFC_STATE_NO_COM_LIN_ERR;
                        u32PFCInternalError = 0;
                        PFC_SET_INTERNAL_ERROR(u32Tmp);
                    }
                    
                    ePFCNoComSubState = PFC_NO_COM_GET_I2C_DEV_ADDR;
                    
                    break;
                }
                /**********************************************************************
                * REQUEST I2C BUS STATUS FROM SC18IM700 - TRY TO COMMUNICATE          *
                **********************************************************************/
                case PFC_NO_COM_GET_I2C_DEV_ADDR:
                {
                    /* 3 - Check the communication to SC18IM700 while reading the I2C bus address */
                    u8TxDataUART[0] = SC18IM700_CMD_READ_REG;
                    u8TxDataUART[1] = SC18IM700_REG_I2C_ADDR;
                    u8TxDataUART[2] = SC18IM700_CMD_I2C_STOP;
                    
                    u8ReturnUART = UART_TxRxData(3u,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCNoComSubState = PFC_NO_COM_WAIT_GET_I2C_DEV_ADDR;
                    
                    break;
                }
                /**********************************************************************
                * WAIT FOR A RESPONCE FROM SC18IM700 - TO DETERMINE IF THE SC18IM700  *
                * STILL FUNCTIONAL - ONLY COMMUNCATION LOST TO PFC                    *
                **********************************************************************/
                case PFC_NO_COM_WAIT_GET_I2C_DEV_ADDR:
                {
                    u8ReturnUART = UART_TxRxData(3u,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        u32Tmp = u32PFCInternalError;
                        u32Tmp |= PFC_STATE_NO_COM_SC18_ERR;
                        u32PFCInternalError = 0;
                        PFC_SET_INTERNAL_ERROR(u32Tmp);
                        
                        ePFCNoComSubState = PFC_NO_COM_WAIT_RESET;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        if(SC18IM700_I2C_ADDR_26H == u8RxDataUART[0])
                        {
                            ePFCNoComSubState = PFC_NO_COM_GET_PFC_MFR_ID;
                        }
                        else
                        {
                            u32Tmp = u32PFCInternalError;
                            u32Tmp |= PFC_STATE_NO_COM_SC18_RD_ERR;
                            u32PFCInternalError = 0;
                            PFC_SET_INTERNAL_ERROR(u32Tmp);
                            ePFCNoComSubState = PFC_NO_COM_WAIT_RESET;
                        }
                    }
                    
                    break;
                }
                /**********************************************************************
                * REQUEST PFC MANUFACTURER'S ID - TO ENSURE THAT THE COMMUNICATION TO *
                * PFC IS ESTABLISHED                                                  *
                **********************************************************************/
                case PFC_NO_COM_GET_PFC_MFR_ID:
                {
                    /* Read PFC status word */
                    u8TxDataUART[0+UART_PFC_CMD_START_INDEX] = ADP1048W_CMD_MFR_ID;
                    
                    u8Tmp = PFC_CMD_ADD_TXRX_HEADER(1,1);
                    
                    u8ReturnUART = UART_TxRxData(u8Tmp, 
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                    
                    ePFCNoComSubState = PFC_NO_COM_WAIT_GET_PFC_MFR_ID;
                    
                    break;
                }
                /**********************************************************************
                * WAIT FOR A RESPONCE FROM PFC CONTAINS THE MANUFACTURER'S ID         *
                **********************************************************************/
                case PFC_NO_COM_WAIT_GET_PFC_MFR_ID:
                {
                    u8ReturnUART = UART_TxRxData(u8Tmp,
                                                 &u8TxDataUART[0],
                                                 1u,
                                                 &u8RxDataUART[0],
                                                 UART_CYC_TXRX_TIMEOUT);
                                                 
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        u32Tmp = u32PFCInternalError;
                        u32Tmp |= PFC_STATE_NO_COM_ADP_ERR;
                        u32PFCInternalError = 0;
                        PFC_SET_INTERNAL_ERROR(u32Tmp);
                        
                        ePFCNoComSubState = PFC_NO_COM_WAIT_RESET;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8Tmp = u8RxDataUART[0];
                        
                        if(u8Tmp == (uint8)ADP1048W_MFR_ID)
                        {
                            // Restart PFC 
                            ePFCState = PFC_STATE_INIT;
                            PFC_INIT_VAR();
                            
                        }
                        else
                        {
                            u32Tmp = u32PFCInternalError;
                            u32Tmp |= PFC_STATE_NO_COM_ADP_RD_ERR;
                            u32PFCInternalError = 0;
                            PFC_SET_INTERNAL_ERROR(u32Tmp);
                            
                            ePFCNoComSubState = PFC_NO_COM_WAIT_RESET;
                        }
                    }
                    
                    break;
                }
                #ifdef EN_PFC_RECONNECT
                /**********************************************************************
                * RE-CONFGURE LINFLEXD WITH DEFAULT BAUD RATE TO MATCH SC18IM700      *
                **********************************************************************/
                case PFC_NO_COM_SET_DEF_UART_BR:
                {
                    if(UART_SetBaudRate(LINFLEXD_LINIBRR_9600, LINFLEXD_LINFBRR_9600, UART_ENTER_INIT_MODE_TIMEOUT_US) != UART_RET_OK)
                    {
                        u32Tmp = u32PFCInternalError;
                        u32Tmp |= PFC_STATE_NO_COM_LIN_BR_ERR;
                        u32PFCInternalError = 0;
                        PFC_SET_INTERNAL_ERROR(u32Tmp);
                        
                        ePFCNoComSubState = PFC_NO_COM_WAIT_RESET;
                        ePFCReconnectStep = PFC_RECONN_STEP_END;
                    }
                    else
                    {
                        ePFCNoComSubState = PFC_NO_COM_EMPTY_UART_FIFO_BUF;
                    }
                    
                    break;
                }
                /**********************************************************************
                * RESET SC18IM700 VIA RESET GPIO - SWITCH ON                          *
                **********************************************************************/
                case PFC_NO_COM_SC18_RESET_ON:
                {
                    Dio_WriteChannel(DioConf_DioChannel_E15_D_RESET_RS485_CM_PPM_01, SC18IM700_RESET_ON);
                    
                    ePFCNoComSubState = PFC_NO_COM_SC18_RESET_OFF;
                    
                    break;
                }
                /**********************************************************************
                * RESET SC18IM700 VIA RESET GPIO - SWITCH OFF                         *
                **********************************************************************/
                case PFC_NO_COM_SC18_RESET_OFF:
                {
                    u8ReturnUART = UART_RxData(SC18IM700_RESET_RESPONSE_SIZE,
                                               &u8RxDataUART[0],
                                               SC18IM700_HW_RESET_RESPONSE_TIMEOUT);
                    
                    Dio_WriteChannel(DioConf_DioChannel_E15_D_RESET_RS485_CM_PPM_01, SC18IM700_RESET_OFF);
                    
                    ePFCNoComSubState = PFC_NO_COM_WAIT_SC18_RESET_RESPONSE;
                    
                    break;
                }
                /**********************************************************************
                * WAIT FOR RESET RESPONSE FROM SC18IM700 - TWO BYTES RESPONSE: 'O''K' *
                **********************************************************************/
                case PFC_NO_COM_WAIT_SC18_RESET_RESPONSE:
                {
                    u8ReturnUART = UART_RxData(SC18IM700_RESET_RESPONSE_SIZE,
                                               &u8RxDataUART[0],
                                               SC18IM700_HW_RESET_RESPONSE_TIMEOUT);
                                               
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        u32Tmp = u32PFCInternalError;
                        u32Tmp |= PFC_STATE_NO_COM_SC18_NO_RESP_ERR;
                        u32PFCInternalError = 0;
                        PFC_SET_INTERNAL_ERROR(u32Tmp);
                        
                        ePFCNoComSubState = PFC_NO_COM_WAIT_RESET;
                    }
                    else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
                    {
                        u8TmpArray[0] = SC18IM700_RESET_RESPONSE_B1;
                        u8TmpArray[1] = SC18IM700_RESET_RESPONSE_B2;
                        
                        if(TS_MemCmp( &u8TmpArray[0], &u8RxDataUART[0],SC18IM700_RESET_RESPONSE_SIZE) != E_OK)
                        {
                            u32Tmp = u32PFCInternalError;
                            u32Tmp |= PFC_STATE_NO_COM_SC18_WRONG_RESP_ERR;
                            u32PFCInternalError = 0;
                            PFC_SET_INTERNAL_ERROR(u32Tmp);
                        
                            ePFCNoComSubState = PFC_NO_COM_WAIT_RESET;
                        }
                        else
                        {
                            ePFCNoComSubState = PFC_NO_COM_GET_I2C_DEV_ADDR;
                        }
                    }
                    
                    break;
                }
                /**********************************************************************
                * EMPTY THE LINFLEXD RX FIFO BUFFER - UART MODE                       *
                **********************************************************************/
                case PFC_NO_COM_EMPTY_UART_FIFO_BUF:
                {
                    u8ReturnUART = UART_RxData(1, &u8RxDataUART[0], UART_CYC_CLEAN_RX_BUFF_TIME);
                    if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
                    {
                        ePFCNoComSubState = PFC_NO_COM_GET_I2C_DEV_ADDR;
                    }
                    
                    break;
                }
                #endif
                /**********************************************************************
                * WAIT FOR RESETING THE TARGET IN CASE RECONNECTING OPTION IS NOT     *
                * ACTIVATED OR TRY TO RE-ESTABLISH A CONNECTION TO PFC VIA I2C BUS    *
                **********************************************************************/
                case PFC_NO_COM_WAIT_RESET:
                {
                    #ifdef EN_PFC_RECONNECT
                    /******************************************************************
                    * Step 1: Reconfigure the UART baud rate to default value of 9600 *
                    ******************************************************************/
                    if(ePFCReconnectStep == PFC_RECONN_STEP_SET_DEF_UART_BR)
                    {
                        ePFCNoComSubState = PFC_NO_COM_SET_DEF_UART_BR;
                        ePFCReconnectStep = PFC_RECONN_STEP_SC18_RESET;
                    }
                    /******************************************************************
                    * Step 2: Reset the SC18IM700 bridge                              *
                    ******************************************************************/
                    else if(ePFCReconnectStep == PFC_RECONN_STEP_SC18_RESET)
                    {
                        ePFCNoComSubState = PFC_NO_COM_SC18_RESET_ON;
                        ePFCReconnectStep = PFC_RECONN_STEP_END;
                    }
                    /******************************************************************
                    * Step 3: End of reconnection attempt sequence                    *
                    ******************************************************************/
                    else if(ePFCReconnectStep == PFC_RECONN_STEP_END)
                    {
                        /*Check reconnection timeout and set the communication error*/
                        if(PFC_RECONN_TIMEOUT_COUNT > PFC_RECONN_TIMEOUT)
                        {
                            PFC_SET_ERROR(u32PFCInternalError, FALSE);
                            ePFCReconnectStep = PFC_RECONN_FAILED;
                        }
                        else
                        {
                            ePFCReconnectStep = PFC_RECONN_STEP_SET_DEF_UART_BR;
                        }
                    }
                    else if(ePFCReconnectStep == PFC_RECONN_FAILED)
                    {
                        /*wait for reset the error*/
                    }
                    #endif
                    
                    break;
                }
                /**********************************************************************
                * UNKNOWN STATE -  STATE MACHINE ERROR                                *
                * should not be reached in normal operation                           *
                **********************************************************************/
                case PFC_NO_COM_SUBSTATE_UNKNOWN:
                {
                    //TODO Diag message!
                    break;
                }
                default:
                {
                    ePFCNoComSubState = PFC_NO_COM_SUBSTATE_UNKNOWN;
                    break;
                }
            }
            
            #ifdef EN_PFC_RECONNECT
            /* increment reconnection attempts timeout counter */
            PFC_RECONN_TIMEOUT_COUNT++;
            #endif
            
            break;
        }
        /**************************************************************************
        *                      PFC STATE MACHINE ERROR                            *
        *              should not be reached in normal operation                  *
        **************************************************************************/
        case PFC_STATE_UNKNOWN:
        case PFC_STATE_SC18_NOT_DETECTED:
        {
            //TODO Diag message!
            asm("nop");
            break;
        }
        default:
        {
            /* unkonwn state */
            ePFCState = PFC_STATE_UNKNOWN;
            PFC_SET_ERROR(PFC_ERR_UNKNOWN_STATE, FALSE);
            break;
        }
    }
}

/******************************************************************************
*                P F C   I N T E R F A C E   F U N C T I O N S                *
******************************************************************************/

/******************************************************************************
* PFC_GET_VIN_mV provides the measured input voltage by PFC in mV             *
******************************************************************************/
sint32 PFC_GET_VIN_mV(void)
{
    return (sint32)(PFC_VIN*1000.0f);
}

/******************************************************************************
* PFC_GET_IIN_mA provides the measured input current by PFC in mA             *
******************************************************************************/
sint32 PFC_GET_IIN_mA(void)
{
    return (sint32)(PFC_IIN*1000.0f);
}

/******************************************************************************
* PFC_GET_PIN_mW provides the measured input power by PFC in mW               *
******************************************************************************/
sint32 PFC_GET_PIN_W(void)
{
    return (sint32)PFC_PIN;
}

/******************************************************************************
* PFC_GET_VOUT_mV provides the measured output voltage by PFC in mV           *
******************************************************************************/
sint32 PFC_GET_VOUT_mV(void)
{
    return (sint32)(PFC_VOUT*1000.0f);
}

/******************************************************************************
* PFC_GET_ErrorCode provides the actual PFC error code                       *
******************************************************************************/
uint32 PFC_GET_ErrorCode(void)
{
    return u32PFCError;
}

/******************************************************************************
* PFC_GET_STATE provides the current PFC state                                *
******************************************************************************/
uint8 PFC_GET_STATE(void)
{
    return (uint8)ePFCState;
}

/******************************************************************************
* PFC_GET_VIN_LINE_PERIOD_ns provides the Vin line period in [ns]             *
******************************************************************************/
uint32 PFC_GET_VIN_LINE_PERIOD_ns(void)
{
    return (uint32)(PFC_VAC_LN_PRD*1000.0f);
}

/******************************************************************************
* PFC_SET_VOUT_mV set the requested output voltage  in mV                     *
******************************************************************************/
void PFC_SET_VOUT_mV(sint32 value)
{
    if(PFC_STANDALONE != 0)
    {
        return;
    }
    
    PFC_VOUT_REQ = ((float)value/1000.f);
}

/******************************************************************************
* PFC_ENABLE_POWER enables the PFC output power                               *
******************************************************************************/
/* SCO 143149 */
//void PFC_ENABLE_POWER(uint8 value)
//{
//    if(PFC_STANDALONE != 0)
//    {
//        return;
//    }
//    
//    if(value == 0x01)
//    {
//        PFC_POWER_ON_REQ = (uint8)ADP1048W_DIO_SWITCH_ON;
//    }
//    else
//    {
//        PFC_POWER_ON_REQ = (uint8)ADP1048W_DIO_SWITCH_OFF;
//    }
//    
//}

/******************************************************************************
* PFC_CLEAR_FAULTS try to clear the current PFC faults                        *
******************************************************************************/
void PFC_CLEAR_FAULTS(uint8 value)
{
    if(PFC_STANDALONE != 0)
    {
        return;
    }
    
    if(value != Pre_PFC_CLEAR_FAULTS_VALUE)
    {
        /*positive edge detected*/
        if((Pre_PFC_CLEAR_FAULTS_VALUE == 0) && (value > 0))
        {
            PFC_CLEAR_FAULTS_REQ = 1;
        }
    }
    
    Pre_PFC_CLEAR_FAULTS_VALUE = value;
    
}

/******************************************************************************
* PFC_CLEAR_FAULTS try to clear the current PFC faults                        *
******************************************************************************/
void PFC_PageSwtFunc(void)
{
   if (PFC_PageSwtVar == 1)
   {
      psPFC_ActivePagePointer = (PFC_Page_tp *)&PFC_Page_1;
   }
   else 
   {
      psPFC_ActivePagePointer = (PFC_Page_tp *)&PFC_Page_0;
   }
}


/******************************************************************************
*                    INTERNAL FUNCTION DEFINITIONS                            *
*******************************************************************************/

static uint8 UART_SetBaudRate(uint32_t uiLINIBRR, uint32_t uiLINFBRR, const uint32 u32Timeout)
{
    /* request INIT mode */
    LINFlexD.LINCR1.R = LINFLEXD_LINCR1_INIT_MODE; /* SLEEP=0, INIT=1 */
    
    (void) OS_UserGetCounterValue(0, &osTickBegin);
    
    /* wait for the INIT mode */
    while ( LINFLEXD_LINSR_LINS_INIT_MODE != (LINFlexD.LINSR.R & LINFLEXD_LINSR_LINS_MASK)) 
    {
        (void) OS_UserGetCounterValue(0, &osTickNow);
        if(OS_TICKS2US_HwCounter((uint32)((sint32)osTickNow - (sint32)osTickBegin)) > u32Timeout)
        {
            return UART_RET_LIN_NOK;
        }
    }
    
    /* configure for UART mode */
    LINFlexD.UARTCR.R = LINFLEXD_UARTCR_UART_MODE;
    LINFlexD.UARTCR.R = LINFLEXD_UARTCR_UART_8N1_TXRX_FIFO;
    
    /* configure baudrate */
    LINFlexD.LINIBRR.R = uiLINIBRR;
    LINFlexD.LINFBRR.R = uiLINFBRR;
    
    /* enable DMA TX/RX channels */
    LINFlexD.DMATXE.R = LINFLEXD_DMATXE_CH_ENABLED;
    LINFlexD.DMARXE.R = LINFLEXD_DMARXE_CH_ENABLED;
    
    /* request NORMAL mode */
    LINFlexD.LINCR1.R = LINFLEXD_LINCR1_NORMAL_MODE;
    
    return UART_RET_OK;
}

static uint8 UART_TxData(uint8 u8TxNrBytes, uint8 *pu8TxData, const uint32 u32Timeout)
{
    if (u8UARTState == UART_STATE_IDLE)
    {
        /* reset timeout counter */
        PFC_TIMEOUT_COUNT = 0;
        
        if((u8TxNrBytes == 0) || (u8TxNrBytes > LINFLEXD_DMA_TX_BUF_SIZE))
        {
            return UART_RET_ERR_PARAM;
        }
        
        if(pu8TxData == NULL_PTR)
        {
            return UART_RET_ERR_PARAM;
        }
        
        /* Note: The DMA TCD configuration for TX mode is based on the setting 
            described in MPC5744P reference manual Rev. 5.1 chapter 52.3.5.7    */
        Mcl_DmaDisableHwRequest(DMA_CH_CFG_IDX_LINFlexD_TX);
        
        /* Copy data in internal DMA TX buffer */
        /* TS_MemCpy(dest, src, num)           */
        TS_MemCpy((uint8 *)&UART_DMA_TX_BUF[0], pu8TxData, u8TxNrBytes);
        
        /* source address */
        DmaTcdConfigTx.u32saddr = (vuint32_t)(&UART_DMA_TX_BUF[0]);
        /* destination address */
        DmaTcdConfigTx.u32daddr = ((vuint32_t)&LINFlexD.BDRL.R) + LINFLEXD_TX_BUFF_BDRL_OFFSET;
        /* source transfer size */
        DmaTcdConfigTx.u32ssize = DMA_SIZE_1BYTE;
        /* destination transfer size */
        DmaTcdConfigTx.u32dsize = DMA_SIZE_1BYTE;
        /* source address offset */
        DmaTcdConfigTx.u32soff = 1;
        /* destination address offset */
        DmaTcdConfigTx.u32doff = 0;
        /* source address modulo */
        DmaTcdConfigTx.u32smod = 0;
        /* destination address modulo */
        DmaTcdConfigTx.u32dmod = 0;
        /* number of bytes to be transferred */
        DmaTcdConfigTx.u32num_bytes = 1;
        /* iteration count */
        DmaTcdConfigTx.u32iter = u8TxNrBytes;

        Mcl_DmaConfigTcd(TcdAddressTx, &DmaTcdConfigTx);
        Mcl_DmaTcdSetFlags(TcdAddressTx, 0);
        Mcl_DmaTcdSetFlags(TcdAddressTx, DMA_TCD_DISABLE_REQ_U8);
        
        Mcl_DmaTcdSetSlast(TcdAddressTx, ((-1)*u8TxNrBytes));
        Mcl_DmaTcdSetDlast(TcdAddressTx, 0);
        
        Mcl_DmaTcdClearDone(DMA_CH_CFG_IDX_LINFlexD_TX);
        
        Mcl_DmaEnableHwRequest(DMA_CH_CFG_IDX_LINFlexD_TX);
    
        /* set UART state to WAIT */
        u8UARTState = UART_STATE_WAIT;
        return UART_RET_EXE_WAIT;
    }
    else if (u8UARTState == UART_STATE_WAIT)
    {
        /* increase timeout counter */
        PFC_TIMEOUT_COUNT++;
        
        if(Mcl_DmaIsTransferCompleted(DMA_CH_CFG_IDX_LINFlexD_TX) == TRUE)
        {
            Mcl_DmaTcdClearDone(DMA_CH_CFG_IDX_LINFlexD_TX);
            
            u8UARTState = UART_STATE_IDLE;
            return UART_RET_DATA_TRANSMITTED;
        }
        else if(PFC_TIMEOUT_COUNT > u32Timeout )
        {
            u8UARTState = UART_STATE_IDLE;
            return UART_RET_EXE_TIMEOUT;
        }
        else
        {
            u8UARTState = UART_STATE_WAIT;
            return UART_RET_EXE_WAIT;
        }
    }
    else if (u8UARTState == UART_STATE_COM_ERR)
    {
        return UART_RET_COM_NOK;
    }
    else if (u8UARTState == UART_STATE_LIN_ERR)
    {
        return UART_RET_LIN_NOK;
    }
    else
    {
        u8UARTState = UART_STATE_IDLE;
        return UART_RET_EXE_WAIT;
    }
}

static uint8 UART_RxData(uint8 u8RxNrBytes, uint8 *pu8RxData, const uint32 u32Timeout)
{
    
    if (u8UARTState == UART_STATE_IDLE)
    {
        /* reset timeout counter */
        PFC_TIMEOUT_COUNT = 0;
        
        if((u8RxNrBytes == 0) || (u8RxNrBytes > LINFLEXD_DMA_RX_BUF_SIZE))
        {
            return UART_RET_ERR_PARAM;
        }
        
        if(pu8RxData == NULL_PTR)
        {
            return UART_RET_ERR_PARAM;
        }
        
        /* Note: The DMA TCD configuration for TX mode is based on the setting 
                 described in MPC5744P reference manual Rev. 5.1 chapter 52.3.5.7    */
        Mcl_DmaDisableHwRequest(DMA_CH_CFG_IDX_LINFlexD_RX);
        
        TS_MemSet((uint8 *)&UART_DMA_RX_BUF[0], 0, u8RxNrBytes);
        
        /* source address */
        DmaTcdConfigRx.u32saddr      = ((vuint32_t)&LINFlexD.BDRM.R) + LINFLEXD_RX_BUFF_BDRM_OFFSET;
        /* destination address */
        DmaTcdConfigRx.u32daddr      = (vuint32_t)(&UART_DMA_RX_BUF[0]);
        /* source transfer size */
        DmaTcdConfigRx.u32ssize      = DMA_SIZE_1BYTE;
        /* destination transfer size */
        DmaTcdConfigRx.u32dsize      = DMA_SIZE_1BYTE;
        /* source address offset */
        DmaTcdConfigRx.u32soff       = 0;
        /* destination address offset */
        DmaTcdConfigRx.u32doff       = 1;
        /* source address modulo */
        DmaTcdConfigRx.u32smod       = 0;
        /* destination address modulo */
        DmaTcdConfigRx.u32dmod       = 0;
        /* number of bytes to be transferred */
        DmaTcdConfigRx.u32num_bytes  = 1;
        /* iteration count */
        DmaTcdConfigRx.u32iter       = u8RxNrBytes;
        
        Mcl_DmaConfigTcd(TcdAddressRx, &DmaTcdConfigRx);
        Mcl_DmaTcdSetFlags(TcdAddressRx, 0);
        Mcl_DmaTcdSetFlags(TcdAddressRx, DMA_TCD_DISABLE_REQ_U8);
    
        Mcl_DmaTcdSetSlast(TcdAddressRx, 0);
        Mcl_DmaTcdSetDlast(TcdAddressRx, ((-1)*u8RxNrBytes));
        
        Mcl_DmaTcdClearDone(DMA_CH_CFG_IDX_LINFlexD_RX);
        
        Mcl_DmaEnableHwRequest(DMA_CH_CFG_IDX_LINFlexD_RX);
        
        /* set UART state to WAIT */
        u8UARTState = UART_STATE_WAIT;
        return UART_RET_EXE_WAIT;
    }
    else if (u8UARTState == UART_STATE_WAIT)
    {
        /* increase timeout counter */
        PFC_TIMEOUT_COUNT++;
        
        if(Mcl_DmaIsTransferCompleted(DMA_CH_CFG_IDX_LINFlexD_RX) == TRUE)
        {
            Mcl_DmaTcdClearDone(DMA_CH_CFG_IDX_LINFlexD_RX);
            
            /* Copy data from internal DMA RX buffer */
            /* TS_MemCpy(dest, src, num)           */
            TS_MemCpy(pu8RxData, (uint8 *)&UART_DMA_RX_BUF[0], u8RxNrBytes);
            
            u8UARTState = UART_STATE_IDLE;
            return UART_RET_DATA_RECEIVED;
        }
        else if(PFC_TIMEOUT_COUNT > u32Timeout)
        {
            u8UARTState = UART_STATE_IDLE;
            return UART_RET_EXE_TIMEOUT;
        }
        else
        {
            u8UARTState = UART_STATE_WAIT;
            return UART_RET_EXE_WAIT;
        }
    }
    else if (u8UARTState == UART_STATE_COM_ERR)
    {
        return UART_RET_COM_NOK;
    }
    else if (u8UARTState == UART_STATE_LIN_ERR)
    {
        return UART_RET_LIN_NOK;
    }
    else
    {
        u8UARTState = UART_STATE_IDLE;
        return UART_RET_EXE_WAIT;
    }
    
}

static uint8 UART_TxRxData(uint8 u8TxNrBytes, uint8 *pu8TxData, 
                           uint8 u8RxNrBytes, uint8 *pu8RxData, const uint32 u32Timeout)
{
    if (u8UARTState == UART_STATE_IDLE)
    {
        /* reset timeout counter */
        PFC_TIMEOUT_COUNT = 0;
        
        if((u8TxNrBytes == 0) || (u8TxNrBytes > LINFLEXD_DMA_TX_BUF_SIZE))
        {
            return UART_RET_ERR_PARAM;
        }
        if(pu8TxData == NULL_PTR)
        {
            return UART_RET_ERR_PARAM;
        }
        
        if((u8RxNrBytes == 0) || (u8RxNrBytes > LINFLEXD_DMA_RX_BUF_SIZE))
        {
            return UART_RET_ERR_PARAM;
        }
        
        if(pu8RxData == NULL_PTR)
        {
            return UART_RET_ERR_PARAM;
        }
        
        
        /* Note: The DMA TCD configuration for TX mode is based on the setting 
           described in MPC5744P reference manual Rev. 5.1 chapter 52.3.5.7    */
        Mcl_DmaDisableHwRequest(DMA_CH_CFG_IDX_LINFlexD_TX);
        Mcl_DmaDisableHwRequest(DMA_CH_CFG_IDX_LINFlexD_RX);
         
        /* Copy data in internal DMA TX buffer */
        /* TS_MemCpy(dest, src, num)           */
        TS_MemCpy((uint8 *)&UART_DMA_TX_BUF[0], pu8TxData, u8TxNrBytes);
        TS_MemSet((uint8 *)&UART_DMA_RX_BUF[0], 0, u8RxNrBytes);

        /* source address */
        DmaTcdConfigTx.u32saddr = (vuint32_t)(&UART_DMA_TX_BUF[0]);
        /* destination address */
        DmaTcdConfigTx.u32daddr = ((vuint32_t)&LINFlexD.BDRL.R) + LINFLEXD_TX_BUFF_BDRL_OFFSET;
        /* source transfer size */
        DmaTcdConfigTx.u32ssize = DMA_SIZE_1BYTE;
        /* destination transfer size */
        DmaTcdConfigTx.u32dsize = DMA_SIZE_1BYTE;
        /* source address offset */
        DmaTcdConfigTx.u32soff = 1;
        /* destination address offset */
        DmaTcdConfigTx.u32doff = 0;
        /* source address modulo */
        DmaTcdConfigTx.u32smod = 0;
        /* destination address modulo */
        DmaTcdConfigTx.u32dmod = 0;
        /* number of bytes to be transferred */
        DmaTcdConfigTx.u32num_bytes = 1;
        /* iteration count */
        DmaTcdConfigTx.u32iter = u8TxNrBytes;

        Mcl_DmaConfigTcd(TcdAddressTx, &DmaTcdConfigTx);
        Mcl_DmaTcdSetFlags(TcdAddressTx, 0);
        Mcl_DmaTcdSetFlags(TcdAddressTx, DMA_TCD_DISABLE_REQ_U8);
        
        Mcl_DmaTcdSetSlast(TcdAddressTx, ((-1)*u8TxNrBytes));
        Mcl_DmaTcdSetDlast(TcdAddressTx, 0);
        
        /* source address */
        DmaTcdConfigRx.u32saddr      = ((vuint32_t)&LINFlexD.BDRM.R) + LINFLEXD_RX_BUFF_BDRM_OFFSET;
        /* destination address */
        DmaTcdConfigRx.u32daddr      = (vuint32_t)(&UART_DMA_RX_BUF[0]);
        /* source transfer size */
        DmaTcdConfigRx.u32ssize      = DMA_SIZE_1BYTE;
        /* destination transfer size */
        DmaTcdConfigRx.u32dsize      = DMA_SIZE_1BYTE;
        /* source address offset */
        DmaTcdConfigRx.u32soff       = 0;
        /* destination address offset */
        DmaTcdConfigRx.u32doff       = 1;
        /* source address modulo */
        DmaTcdConfigRx.u32smod       = 0;
        /* destination address modulo */
        DmaTcdConfigRx.u32dmod       = 0;
        /* number of bytes to be transferred */
        DmaTcdConfigRx.u32num_bytes  = 1;
        /* iteration count */
        DmaTcdConfigRx.u32iter       = u8RxNrBytes;
        
        Mcl_DmaConfigTcd(TcdAddressRx, &DmaTcdConfigRx);
        Mcl_DmaTcdSetFlags(TcdAddressRx, 0);
        Mcl_DmaTcdSetFlags(TcdAddressRx, DMA_TCD_DISABLE_REQ_U8);
    
        Mcl_DmaTcdSetSlast(TcdAddressRx, 0);
        Mcl_DmaTcdSetDlast(TcdAddressRx, ((-1)*u8RxNrBytes));
        
        Mcl_DmaTcdClearDone(DMA_CH_CFG_IDX_LINFlexD_TX);
        Mcl_DmaTcdClearDone(DMA_CH_CFG_IDX_LINFlexD_RX);
        
        Mcl_DmaEnableHwRequest(DMA_CH_CFG_IDX_LINFlexD_RX);
        Mcl_DmaEnableHwRequest(DMA_CH_CFG_IDX_LINFlexD_TX);
        
        /* set UART state to WAIT */
        u8UARTState = UART_STATE_WAIT;
        return UART_RET_EXE_WAIT;
    }
    else if (u8UARTState == UART_STATE_WAIT)
    {
        /* increase timeout counter */
        PFC_TIMEOUT_COUNT++;
        
        if((Mcl_DmaIsTransferCompleted(DMA_CH_CFG_IDX_LINFlexD_RX) == TRUE)&& Mcl_DmaIsTransferCompleted(DMA_CH_CFG_IDX_LINFlexD_TX) == TRUE)
        {
            Mcl_DmaTcdClearDone(DMA_CH_CFG_IDX_LINFlexD_RX);
            Mcl_DmaTcdClearDone(DMA_CH_CFG_IDX_LINFlexD_TX);
            
            /* Copy data from internal DMA RX buffer */
            /* TS_MemCpy(dest, src, num)           */
            TS_MemCpy(pu8RxData, (uint8 *)&UART_DMA_RX_BUF[0], u8RxNrBytes);
            
            u8UARTState = UART_STATE_IDLE;
            return UART_RET_DATA_RECEIVED;
        }
        else if(PFC_TIMEOUT_COUNT > u32Timeout)
        {
            u8UARTState = UART_STATE_IDLE;
            return UART_RET_EXE_TIMEOUT;
        }
        else
        {
            u8UARTState = UART_STATE_WAIT;
            return UART_RET_EXE_WAIT;
        }
    }
    else if (u8UARTState == UART_STATE_COM_ERR)
    {
        return UART_RET_COM_NOK;
    }
    else if (u8UARTState == UART_STATE_LIN_ERR)
    {
        return UART_RET_LIN_NOK;
    }
    else
    {
        u8UARTState = UART_STATE_IDLE;
        return UART_RET_EXE_WAIT;
    }
}

static uint8 UART_SC18IM700_ResetAndCheckResponse(const uint32 u32Timeout)
{
    (void) OS_UserGetCounterValue(0, &osTickBegin);
    
    /* Set the SC18IM700 in reset - PIN E[15] */
    Dio_WriteChannel(DioConf_DioChannel_E15_D_RESET_RS485_CM_PPM_01, SC18IM700_RESET_ON);
    
    /* Initialze RX buffer with zeros */
    TS_MemSet(&u8RxDataUART[0], 0, SC18IM700_RESET_RESPONSE_SIZE);
    
    /* Configure DMA RX channel */
     u8ReturnUART = UART_RxData(SC18IM700_RESET_RESPONSE_SIZE, &u8RxDataUART[0], u32Timeout);
     
    /* Wait for 5ms before releasing the reset PIN */
    do
    {
        (void) OS_UserGetCounterValue(0, &osTickNow);
    }
    while( OS_TICKS2MS_HwCounter((uint32)((sint32)osTickNow - (sint32)osTickBegin)) < SC18IM700_RESET_PULSE_WIDTH_MS );
    
    /* release the SC18IM700 from reset - PIN E[15] */
    Dio_WriteChannel(DioConf_DioChannel_E15_D_RESET_RS485_CM_PPM_01, SC18IM700_RESET_OFF);
    (void) OS_UserGetCounterValue(0, &osTickBegin);
    
    /*Wait for  the bridge response */
    do
    {
        do
        {
            (void) OS_UserGetCounterValue(0, &osTickNow);
        }
        while( OS_TICKS2MS_HwCounter((uint32)((sint32)osTickNow - (sint32)osTickBegin)) < PFC_MAIN_FUNC_CYCLE_TIME_MS );
        
        osTickBegin = osTickNow;
        
        u8ReturnUART = UART_RxData(SC18IM700_RESET_RESPONSE_SIZE, &u8RxDataUART[0], u32Timeout);
        
        if(u8ReturnUART == UART_RET_EXE_TIMEOUT)
        {
            return UART_RET_ERR_DMA_RX_TIMEOUT;
        }
        else if(u8ReturnUART == UART_RET_DATA_RECEIVED)
        {
            u8TmpArray[0] = SC18IM700_RESET_RESPONSE_B1;
            u8TmpArray[1] = SC18IM700_RESET_RESPONSE_B2;
            
            if(TS_MemCmp( &u8TmpArray[0], &u8RxDataUART[0],SC18IM700_RESET_RESPONSE_SIZE) != E_OK)
            {
                return UART_RET_ERR_RESPONSE_NOK;
            }
            else
            {
                return UART_RET_RESPONSE_OK;
            }
        }
    }
    while((u8ReturnUART == UART_RET_EXE_WAIT));
    
    return u8ReturnUART;
}

static uint8 PFC_CMD_ADD_TXRX_HEADER (uint8 u8TxLength, uint8 u8RxLength)
{
    u8TxDataUART[0]            = SC18IM700_CMD_I2C_START;
    u8TxDataUART[1]            = ADP1048W_I2C_SLAVE_ADDR_WR;
    u8TxDataUART[2]            = u8TxLength;
    u8TxDataUART[3+u8TxLength] = SC18IM700_CMD_I2C_START;
    u8TxDataUART[4+u8TxLength] = ADP1048W_I2C_SLAVE_ADDR_RD;
    u8TxDataUART[5+u8TxLength] = u8RxLength;
    u8TxDataUART[6+u8TxLength] = SC18IM700_CMD_I2C_STOP;
    
    return (u8TxLength+UART_PFC_CMD_TXRX_HDR_SIZE);
}

static uint8 PFC_CMD_ADD_TX_HEADER(uint8 u8TxLength)
{
    u8TxDataUART[0]= SC18IM700_CMD_I2C_START;
    u8TxDataUART[1]= ADP1048W_I2C_SLAVE_ADDR_WR;
    u8TxDataUART[2]= u8TxLength;
    
    u8TxDataUART[3+u8TxLength] = SC18IM700_CMD_I2C_STOP;
    
    return (u8TxLength+UART_PFC_CMD_TX_HDR_SIZE);
}

static float PFC_RAW2PHYS(uint8 u8RawType, uint32 u32RawValue)
{
    float  rawmant;
    float  mant;
    
    if(u8RawType == (uint8)VAL_TYP_VIN)         /* scaling set in PFC register 0xfe39 */
    {
        rawmant = (float)(u32RawValue & 0x7FF);
        mant = rawmant / 4.0f;
    }
    else if(u8RawType == (uint8)VAL_TYP_IIN)    /* scaling set in PFC register 0xfe39 */
    {
        /* Mantissa */
        rawmant = (float)(u32RawValue & 0x7FF);
        mant = rawmant / 32.0f;
    }
    else if(u8RawType == (uint8)VAL_TYP_PIN)    /* scaling set in PFC register 0xfe39 */
    {
        rawmant = (float)(u32RawValue & 0x7FF);
        mant = rawmant * 2.0f;
    }
    else if(u8RawType == (uint8)VAL_TYP_VOUT)   /* scaling set in PFC register 0x20   */
    {
        rawmant = (float)(u32RawValue & 0x7FF);
        mant = rawmant / 4.0f;
    }
    else if(u8RawType == (uint8)VAL_TYP_VAC_LN_PRD) /* fixed scaling */
    {
        rawmant = (float)(u32RawValue & 0xFF);
        mant = rawmant * 163.84f;
    }
    else
    {
        mant = rawmant;
    }
    
    return mant;
}

static uint16 PFC_PHYS2RAW(uint8 u8PhysType, float f32PhysValue)
{
    uint16  mant;
    
    if(u8PhysType == (uint8)VAL_TYP_VOUT)
    {
        mant = (uint16)(f32PhysValue * 4.0f);      /* scaling set in PFC register 0x20 */
    }
    else
    {
        mant = (uint16)f32PhysValue;
    }
    
    return mant;
}

static void PFC_SET_ERROR(uint32 u32ErrCode, boolean bMergeErrCode)
{
    if(u8PFCSetErrorFlag != PFC_ERROR_SUPPRESS)
    {
        if(bMergeErrCode)
        {
            u32PFCError = (uint32)(u32PFCError|u32ErrCode);
        }
        else
        {
            if(u32PFCError == PFC_ERR_OK)
            {
                u32PFCError = u32ErrCode;
            }
        }
    }
}

static void PFC_SET_INTERNAL_ERROR(uint32 u32ErrCode)
{
    if(u32PFCInternalError == PFC_ERR_OK)
    {
        u32PFCInternalError = u32ErrCode;
    }
}

static void PFC_CLEAR_ERRORS(void)
{
    u32PFCError = PFC_ERR_OK;
    u32PFCInternalError = PFC_ERR_OK;
}

static void PFC_INC_PERF_COUNT(void)
{
    if(PFC_COM_PERF_COUNT < (float)PFC_COM_PERF_MAX_COUNT)
    {
        PFC_COM_PERF_COUNT += (float)PFC_COM_PERF_COUNT_UP;
    }
}

static void PFC_DEC_PERF_COUNT(void)
{
    if((PFC_COM_PERF_COUNT >= PFC_COM_PERF_COUNT_DOWN) && (PFC_TIMEOUT_COUNT > 1) )
    {
        PFC_COM_PERF_COUNT -= (float)PFC_COM_PERF_COUNT_DOWN;
    }
}

static void PFC_INIT_VAR(void)
{
    ePFCInitSubState = PFC_INIT_GET_I2C_BUS_CAPA;
    ePFCInitAfterWrState = PFC_INIT_SUBSTATE_UNKNOWN;
    u8RetryCmdUART = 0;
    
    ePFCSyncSubState = PFC_SYNC_RD_STS;
    ePFCSyncAfterWrState = PFC_SYNC_SUBSTATE_UNKNOWN;
    ePFCNoComSubState = PFC_NO_COM_CHK_DMA_STS;
    
#ifdef EN_PFC_RECONNECT
    ePFCReconnectStep  = PFC_RECONN_STEP_SET_DEF_UART_BR;
    PFC_RECONN_TIMEOUT = SC18IM700_RECONNECTION_TIMEOUT;
    PFC_RECONN_TIMEOUT_COUNT = 0;
#endif
    /* SCO 143149 */
    //Pre_PFC_POWER_ON_REQ = 0;
    //PFC_POWER_ON_REQ = 0;
    
    Pre_PFC_VOUT_REQ = 0.0f;
    PFC_VOUT_REQ = 0.0f;
    PFC_EXP_VOUT_MIN = 0.0f;
    PFC_EXP_VOUT_MAX = 0.0f;
    
    PFC_URGENT_CMD_REQ = 0;
    
    PFC_CLEAR_FAULTS_REQ = 0;
    Pre_PFC_CLEAR_FAULTS_VALUE = 0;
    PFC_CLEAR_FAULTS_EXE = 0;
    
    PFC_STANDALONE = 0;
    
    //PFC_NO_COM_ERR_COUNT = 0; //muramada@20180509: this variable should not be initialized after startup.
    
    PFC_SYNC_COUNT = 0;
    PFC_SYNC_VIN_UPD_COUNTSTAMP = 0;
    PFC_SYNC_VOUT_REQ_COUNTSTAMP = 0;
    
    PFC_COM_PERF_COUNT = (float)PFC_COM_PERF_MAX_COUNT;
    
    u8ReturnUART = UART_RET_OK;
}

