/*----------------------------------------------------------------------------
** Project Name:
** #Archive: LINFlexUARTMode.H #
** #Author: Muneer Ramadan #
** #Date: 2016-08-10#
** (c) Copyright 2016, Bombardier Primove GmbH
**----------------------------------------------------------------------------
** #Revision: #
**----------------------------------------------------------------------------
** Target system: Freescale MPC5744P
** Compiler:GHS
** Description:
**
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    -------------------------------------
** MuRa         Muneer Ramadan           
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log: #
**--------------------------------------------------------------------------*/

#ifndef _LINFLEXUARTMODE_H_
#define _LINFLEXUARTMODE_H_

/******************************************************************************
*                                   INCLUDES                                  *
*******************************************************************************/


/******************************************************************************
*                                   DEFINES                                   *
*******************************************************************************/

/* Enable PFC RECONNECT OPTION */
#define EN_PFC_RECONNECT


/* Keep the SCI18IM700 default I2C clock speed 100kHz */
//#define KEEP_SC18_DEF_I2C_SPEED


/* PFC ERROR CODES */
#define PFC_ERR_OK                                          (uint32)0x00000000
#define PFC_ERR_IN_UART_INIT                                (uint32)0x01000000
#define PFC_ERR_IN_INIT_STATE                               (uint32)0x02000000
#define PFC_ERR_IN_SYNC_STATE                               (uint32)0x04000000
#define PFC_ERR_UNKNOWN_STATE                               (uint32)0x08000000
#define PFC_ERR_AC_NOK                                      (uint32)0x10000000
#define PFC_ERR_PW_NOK                                      (uint32)0x20000000

/* ERROR DETAILS for PFC_ERR_IN_UART_INIT */
#define UART_INIT_LIN_CTRL_ERR                              (uint32)0x00000001
#define UART_INIT_SC18_COM_ERR                              (uint32)0x00000002

/* ERROR DETAILS for PFC_ERR_IN_INIT_STATE/PFC_ERR_IN_SYNC_STATE in case of 
 * Communication error PFC_STATE_NO_COM_ERR*/
#define PFC_STATE_NO_COM_ERR                                (uint32)0x00001000
#define PFC_STATE_NO_COM_SC18_ERR                           (uint32)0x00000001
#define PFC_STATE_NO_COM_SC18_RD_ERR                        (uint32)0x00000002
#define PFC_STATE_NO_COM_SC18_NO_RESP_ERR                   (uint32)0x00000004
#define PFC_STATE_NO_COM_SC18_WRONG_RESP_ERR                (uint32)0x00000008
#define PFC_STATE_NO_COM_LIN_ERR                            (uint32)0x00000010
#define PFC_STATE_NO_COM_LIN_BR_ERR                         (uint32)0x00000020
#define PFC_STATE_NO_COM_DMA_ERR                            (uint32)0x00000040
#define PFC_STATE_NO_COM_ADP_ERR                            (uint32)0x00000080
#define PFC_STATE_NO_COM_ADP_RD_ERR                         (uint32)0x00000100


/* ERROR DETAILS for PFC_ERR_IN_SYNC_STATE */
#define PFC_STATE_VIN_OV_FLT                                (uint32)0x00002000
#define PFC_STATE_VIN_UV_FLT                                (uint32)0x00004000
#define PFC_STATE_IIN_OC_FLT                                (uint32)0x00008000
#define PFC_STATE_VOUT_OV_FLT                               (uint32)0x00010000
#define PFC_STATE_VOUT_UV_FLT                               (uint32)0x00020000
#define PFC_STATE_IOUT_OC_FLT                               (uint32)0x00040000
#define PFC_STATE_OT_FLT                                    (uint32)0x00080000

#define PFC_STS_WORD_MASK_FLT                               (uint16)0xE03C


/* STATUS WORD REGISTER */ 
typedef union
{
    uint16 R;
    struct 
    {
        uint16 VOUT                 :1;     /* output voltage fault or warning             */
        uint16 IOUTPOUT             :1;     /* output current or output power fault or warning               */
        uint16 INPUT                :1;     /* input voltage, input current, or input power fault or warning */
        uint16 MFR                  :1;     /* manufacturer-specific fault or warning       */
        uint16 POWER_GOOD_N         :1;     /* POWER_GOOD is negated                        */
        uint16 FANS                 :1;     /* fan or airflow fault or warning              */
        uint16 OTHER                :1;     /* Always reads as 0                            */
        uint16 UNKNOWN              :1;     /* fault or warning not listed in Bits[15:1]    */
        uint16 BUSY                 :1;     /* device was busy and unable to respond        */
        uint16 PSON_OFF             :1;     /* device is not providing power to the output  */
        uint16 VOUT_OV              :1;     /* output overvoltage fault                     */
        uint16 IOUT_OC              :1;     /* output overcurrent fault                     */
        uint16 VIN_UV               :1;     /* input undervoltage fault                     */
        uint16 TEMPERATURE          :1;     /* temperature fault or warning                 */
        uint16 CML                  :1;     /* communications, memory, or logic fault       */
        uint16 NONE_OF_THE_ABOVE    :1;     /* fault or warning not listed in Bits[7:1]     */
    } B;
} PFC_STS_WORD_REG;


/* STATUS VOUT REGISTER */
typedef union
{
    uint8 R;
    struct 
    {
        uint8 VOUT_OV_FAULT         :1;     /* output overvoltage fault                     */
        uint8 VOUT_OV_WARN          :1;     /* output overvoltage warning                   */
        uint8 VOUT_UV_WARN          :1;     /* output undervoltage warning.                 */
        uint8 VOUT_UV_FAULT         :1;     /* output undervoltage fault                    */
        uint8                       :4;     /* unused                                       */
    } B;
} PFC_STS_VOUT_REG;


/* STATUS INPUT REGISTER */
typedef union
{
    uint8 R;
    struct 
    {
        uint8 VIN_OV_FAULT          :1;     /* input overvoltage fault                      */
        uint8                       :1;     /* unused                                       */
        uint8 VIN_UV_WARN           :1;     /* input undervoltage warning                   */
        uint8 VIN_UV_FAULT          :1;     /* input undervoltage fault                     */
        uint8 VIN_LOW               :1;     /* device is off due to insufficient input voltage  */
        uint8 IIN_OC_FAULT          :1;     /* input overcurrent fault                      */
        uint8 IIN_OC_WARN           :1;     /* input overcurrent warning                    */
        uint8 PIN_OP_WARN           :1;     /* input overpower warning                      */
    } B;
} PFC_STS_INPUT_REG;

/* STATUS TEMPERATURE REGISTER */
typedef union
{
    uint8 R;
    struct 
    {
        uint8 OT_FAULT              :1;     /* overtemperature fault                        */
        uint8 OT_WARN               :1;     /* overtemperature warning                      */
        uint8                       :6;     /* unused                                       */
    } B;
} PFC_STS_TEMP_REG;

typedef enum
{
    UART_RET_OK,
    UART_RET_DATA_TRANSMITTED,
    UART_RET_DATA_RECEIVED,
    UART_RET_EXE_WAIT,
    UART_RET_EXE_TIMEOUT,
    UART_RET_ERR_PARAM,
    UART_RET_ERR_DMA_TX_TIMEOUT,
    UART_RET_ERR_DMA_RX_TIMEOUT,
    UART_RET_RESPONSE_OK,
    UART_RET_ERR_RESPONSE_NOK,
    UART_RET_I2C_OK,
    UART_RET_ERR_I2C_NOK,
    UART_RET_LIN_NOK,
    UART_RET_COM_NOK,
} UART_RET;

typedef enum
{
    UART_STATE_LIN_ERR,
    UART_STATE_COM_ERR,
    UART_STATE_IDLE,
    UART_STATE_WAIT,
    UART_STATE_TIMEOUT,
} UART_STATE;

typedef enum
{
    PFC_STATE_UNKNOWN,
    PFC_STATE_SC18_NOT_DETECTED,
    PFC_STATE_NO_COM,
    PFC_STATE_INIT,
    PFC_STATE_SYNC,
} PFC_STATE;

typedef enum
{
    PFC_INIT_SUBSTATE_UNKNOWN,                  //0
    PFC_INIT_GET_I2C_BUS_CAPA,                  //1
    PFC_INIT_WAIT_GET_I2C_BUS_CAPA,             //2
    PFC_INIT_SET_I2C_MAX_SPEED,                 //3
    PFC_INIT_WAIT_SET_I2C_MAX_SPEED,            //4
    PFC_INIT_GET_I2C_SPEED,                     //5
    PFC_INIT_WAIT_GET_I2C_SPEED,                //6
    PFC_INIT_SET_SC18IM700_BAUDRATE,            //7
    PFC_INIT_WAIT_SET_SC18IM700_BAUDRATE,       //8
    PFC_INIT_WAIT_SC18IM700_BAUDRATE_CHANGED,   //9
    PFC_INIT_SET_UART_BAUDRATE,                 //10
    PFC_INIT_SET_SC18IM700_STOP_CONDITION,      //11
    PFC_INIT_WAIT_SET_SC18IM700_STOP_CONDITION, //12
    PFC_INIT_SET_PWM_EXT_SYNC_CLK,              //13
    PFC_INIT_WAIT_SET_PWM_EXT_SYNC_CLK,         //14
    PFC_INIT_SET_SYNC_FREQ_DIV,                 //15
    PFC_INIT_WAIT_SET_SYNC_FREQ_DIV,            //16
    PFC_INIT_AFTER_WR_REQ,                      //17
    PFC_INIT_DONE                               //18
} PFC_INIT_SUBSTATE;

#ifdef EN_PFC_RECONNECT
typedef enum
{
    PFC_RECONN_STEP_SET_DEF_UART_BR,
    PFC_RECONN_STEP_SC18_RESET,
    PFC_RECONN_STEP_END,
    PFC_RECONN_FAILED,
} PFC_RECONNECT_STEP;
#endif

typedef enum
{
    PFC_NO_COM_SUBSTATE_UNKNOWN,
    PFC_NO_COM_CHK_DMA_STS,
    PFC_NO_COM_CHK_LINFLEXD_STS,
    PFC_NO_COM_GET_I2C_DEV_ADDR,
    PFC_NO_COM_WAIT_GET_I2C_DEV_ADDR,
    PFC_NO_COM_GET_PFC_MFR_ID,
    PFC_NO_COM_WAIT_GET_PFC_MFR_ID,
#ifdef EN_PFC_RECONNECT
    PFC_NO_COM_SET_DEF_UART_BR,
    PFC_NO_COM_SC18_RESET_ON,
    PFC_NO_COM_SC18_RESET_OFF,
    PFC_NO_COM_WAIT_SC18_RESET_RESPONSE,
    PFC_NO_COM_EMPTY_UART_FIFO_BUF,
#endif
    PFC_NO_COM_WAIT_RESET,
} PFC_NO_COM_SUBSTATE;

typedef enum
{
    PFC_SYNC_SUBSTATE_UNKNOWN,      //0
    PFC_SYNC_RD_STS,                //1
    PFC_SYNC_WAIT_RD_STS,           //2
    PFC_SYNC_RD_VIN,                //3
    PFC_SYNC_WAIT_RD_VIN,           //4
    PFC_SYNC_RD_IIN,                //5
    PFC_SYNC_WAIT_RD_IIN,           //6
    PFC_SYNC_RD_PIN,                //7
    PFC_SYNC_WAIT_RD_PIN,           //8
    PFC_SYNC_RD_VAC_LN_PRD,         //9
    PFC_SYNC_WAIT_RD_VAC_LN_PRD,    //10
    PFC_SYNC_RD_VOUT,               //11
    PFC_SYNC_WAIT_RD_VOUT,          //12
    PFC_SYNC_WR_VOUT_REQ,           //13
    PFC_SYNC_WAIT_WR_VOUT_REQ,      //14
    PFC_SYNC_CLEAR_FAULTS_REQ,      //15
    PFC_SYNC_WAIT_CLEAR_FAULTS_REQ, //16
    PFC_SYNC_RD_STS_OUT,            //17
    PFC_SYNC_WAIT_RD_STS_OUT,       //18
    PFC_SYNC_RD_STS_IN,             //19
    PFC_SYNC_WAIT_RD_STS_IN,        //20
    PFC_SYNC_RD_STS_TEMP,           //21
    PFC_SYNC_WAIT_RD_STS_TEMP,      //22
    PFC_SYNC_AFTER_WR_REQ,          //23
} PFC_SYNC_SUBSTATE;

typedef enum
{
    VAL_TYP_VIN,
    VAL_TYP_IIN,
    VAL_TYP_PIN,
    VAL_TYP_VOUT,
    VAL_TYP_VAC_LN_PRD,
} VALUE_TYPE;

typedef struct tagPFC_Page_tp
{
    uint32 u32PFCBrdgReconnTimeout;     /* Timeout for re-establishing a connection with the UART/I2C bridge [ms]   */
    uint32 u32PFCUartTxTimeout;         /* Timeout for transmitting data via UART using DMA channels [ms]           */
    uint32 u32PFCUartTxRXTimeout;       /* Timeout for transmitting/Receiving data via UART using DMA channels [ms] */
    uint32 u32PFCUartCleanRxBuffTime;   /* Time window for cleaning the UART RX buffer after reseting the bridge [ms] */
    uint32 u32PFCErrSupprerssTime;      /* Time window for supprressing PFC errors which occur at startup [ms]      */
    uint32 u32PFCBrdgRespTimeout;       /* Timeout for receiving a response from the UART/I2C bridge after initiating a HW reset [ms] */
    uint32 u32PFCUartChgBaudrateTime;   /* Required time window for changing the baud rate on the UART/I2C bridge [ms] */
    uint8  u8PFCPwmActExtSync;          /* Flag to activate the PWM frequency synchronisation with the external SYNC clock */
    uint8  u8PFCExtSyncFreqDiv;         /* Frequency division between the switching frequency and the external SYNC clock (valid values are 0,1,2 and 3)*/
    uint32 u32PFCHwConfVersion;         /* PFC HW Configuration Version used for SW compatibility check             */
    float  f32PFCVINRaw2PhyScaling;     /* Input voltage scaling factor used for converting a RAW value received from PFC to a physical value */
    float  f32PFCIINRaw2PhyScaling;     /* Input current caling factor used for converting a RAW value received from PFC to a physical value */
    float  f32PFCPINRaw2PhyScaling;     /* Input power scaling factor used for converting a RAW value received from PFC to a physical value */
    float  f32PFCLnFreqRaw2PhyScaling;  /* Line frequency scaling factor used  for converting a RAW value received from PFC to a physical value */
    float  f32PFCVOUTRaw2PhyScaling;    /* Output voltage Scaling factor used for converting a RAW value received from PFC to a physical value */
    float  f32PFCVOUTPhy2RawScaling;    /* Output voltage scaling factor used for converting a physical value to a RAW value before sending it PFC */
}PFC_Page_tp;

/******************************************************************************
*                     P U B L I C   F U N C T I O N S                         *
*******************************************************************************/
void   PFC_SYNC(void);
sint32 PFC_GET_VIN_mV(void);
sint32 PFC_GET_IIN_mA(void);
sint32 PFC_GET_PIN_W(void);
sint32 PFC_GET_VOUT_mV(void);
uint32 PFC_GET_ErrorCode(void);
uint8  PFC_GET_STATE(void);
uint32 PFC_GET_VIN_LINE_PERIOD_ns(void);
void   PFC_SET_VOUT_mV(sint32 value);
/* SCO 143149 */
//void   PFC_ENABLE_POWER(uint8 value);
void   PFC_CLEAR_FAULTS(uint8 value);
void   PFC_PageSwtFunc(void);

#endif
