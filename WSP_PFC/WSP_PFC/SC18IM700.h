/*----------------------------------------------------------------------------
** Project Name:
** #Archive: SC18IM700.H #
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

#ifndef _SC18IM700_H_
#define _SC18IM700_H_

/******************************************************************************
*                                   INCLUDES                                  *
*******************************************************************************/


/******************************************************************************
*                                   DEFINES                                   *
*******************************************************************************/
/* SC18IM700 commands */
#define SC18IM700_CMD_I2C_START             0x53u
#define SC18IM700_CMD_I2C_STOP              0x50u
#define SC18IM700_CMD_READ_REG              0x52u
#define SC18IM700_CMD_WRITE_REG             0x57u
#define SC18IM700_CMD_READ_GPIO             0x49u
#define SC18IM700_CMD_WRITE_GPIO            0x4Fu
#define SC18IM700_CMD_POWER_DOWN            0x5Au


/* SC18IM700 internal registers */
#define SC18IM700_REG_BRG0                  0x00u
#define SC18IM700_REG_BRG1                  0x01u
#define SC18IM700_REG_GPIO_CONF1            0x02u
#define SC18IM700_REG_GPIO_CONF2            0x03u
#define SC18IM700_REG_IOSTATE               0x04u
#define SC18IM700_REG_I2C_ADDR              0x06u
#define SC18IM700_REG_I2C_CLKL              0x07u
#define SC18IM700_REG_I2C_CLKH              0x08u
#define SC18IM700_REG_I2C_TIMEOUT           0x09u
#define SC18IM700_REG_I2C_STAT              0x0Au


/* SC18IM700 I2C bus status */
#define SC18IM700_I2C_STAT_OK               0xF0u
#define SC18IM700_I2C_STAT_NACK_ON_ADDR     0xF1u
#define SC18IM700_I2C_STAT_NACK_ON_DATA     0xF2u
#define SC18IM700_I2C_STAT_TIMEOUT          0xF8u


/* SC18IM700 BRG registers settings */
#define SC18IM700_BRG0_BR_9600              (uint8)0xF0 /* default value after HW reset */
#define SC18IM700_BRG1_BR_9600              (uint8)0x02 /* default value after HW reset */

#define SC18IM700_BRG0_BR_115200            (uint8)0x30
#define SC18IM700_BRG1_BR_115200            (uint8)0x00

#define SC18IM700_BRG0_BR_230400            (uint8)0x10
#define SC18IM700_BRG1_BR_230400            (uint8)0x00

#define SC18IM700_BRG0_BR_MAX               (uint8)0x00
#define SC18IM700_BRG1_BR_MAX               (uint8)0x00

/* SC18IM700 I2C CLKH/CLKL settings */
#define SC18IM700_I2C_CLKH_100KHZ           0x13u /* default value after HW reset */
#define SC18IM700_I2C_CLKL_100KHZ           0x13u /* default value after HW reset */
#define SC18IM700_I2C_CLKH_MAX              0x05u
#define SC18IM700_I2C_CLKL_MAX              0x05u

/* SC18IM700 I2C master address settings */
#define SC18IM700_I2C_ADDR_26H              0x26u /* default value after HW reset */

/* SC18IM700 I2C timeout settings */
#define SC18IM700_I2C_TIMEOUT_227MS         0x66u /* default value after HW reset, Timeout is not enabled by default */
#define SC18IM700_I2C_TIMEOUT_ENABLE        0x01u

/* SC18IM700 reset condition */
#define SC18IM700_RESET_ON                  0x00
#define SC18IM700_RESET_OFF                 0x01

/*SC18IM700 reset respose on UART */
#define SC18IM700_RESET_RESPONSE_SIZE       2               /* size in bytes */
#define SC18IM700_RESET_RESPONSE_B1         (uint8)0x4F     /* ASCII CODE 'O'*/
#define SC18IM700_RESET_RESPONSE_B2         (uint8)0x4B     /* ASCII CODE 'K'*/


#endif
