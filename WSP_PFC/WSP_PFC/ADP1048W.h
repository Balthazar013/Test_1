/*----------------------------------------------------------------------------
** Project Name:
** #Archive: ADP1048W.H #
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

#ifndef _ADP1048W_H_
#define _ADP1048W_H_

/******************************************************************************
*                                   INCLUDES                                  *
*******************************************************************************/


/******************************************************************************
*                                   DEFINES                                   *
*******************************************************************************/

/* ADP1048W I2C slave address */
#define ADP1048W_I2C_SLAVE_ADDR_WR                              0xB0u  /* I2C slave address [7:1](0x58) + Write Flag[0] */
#define ADP1048W_I2C_SLAVE_ADDR_RD                              0xB1u  /* I2C slave address [7:1](0x58) + Read Flag[0]  */


/**************************************************************************/
/*         STANDARD PMBus COMMANDS SUPPORTED BY THE ADP1048W              */
/**************************************************************************/
#define ADP1048W_CMD_OPERATION                                  0x01u
#define ADP1048W_CMD_ON_OFF_CONFIG                              0x02u
#define ADP1048W_CMD_CLEAR_FAULTS                               0x03u
#define ADP1048W_CMD_WRITE_PROTECT                              0x10u
#define ADP1048W_CMD_RESTORE_DEFAULT_ALL                        0x12u
#define ADP1048W_CMD_STORE_USER_ALL                             0x15u
#define ADP1048W_CMD_RESTORE_USER_ALL                           0x16u
#define ADP1048W_CMD_CAPABILITY                                 0x19u
#define ADP1048W_CMD_VOUT_MODE                                  0x20u
#define ADP1048W_CMD_VOUT_COMMAND                               0x21u
#define ADP1048W_CMD_VOUT_SCALE_LOOP                            0x29u
#define ADP1048W_CMD_VOUT_SCALE_MONITOR                         0x2Au
#define ADP1048W_CMD_VIN_ON                                     0x35u
#define ADP1048W_CMD_VIN_OFF                                    0x36u
#define ADP1048W_CMD_VOUT_OV_FAULT_LIMIT                        0x40u
#define ADP1048W_CMD_VOUT_OV_FAULT_RESPONSE                     0x41u
#define ADP1048W_CMD_VOUT_OV_WARN_LIMIT                         0x42u
#define ADP1048W_CMD_VOUT_UV_WARN_LIMIT                         0x43u
#define ADP1048W_CMD_VOUT_UV_FAULT_LIMIT                        0x44u
#define ADP1048W_CMD_VOUT_UV_FAULT_RESPONSE                     0x45u
#define ADP1048W_CMD_OT_FAULT_RESPONSE                          0x50u
#define ADP1048W_CMD_VIN_OV_FAULT_LIMIT                         0x55u
#define ADP1048W_CMD_VIN_OV_FAULT_RESPONSE                      0x56u
#define ADP1048W_CMD_VIN_UV_WARN_LIMIT                          0x58u
#define ADP1048W_CMD_VIN_UV_FAULT_LIMIT                         0x59u
#define ADP1048W_CMD_VIN_UV_FAULT_RESPONSE                      0x5Au
#define ADP1048W_CMD_IIN_OC_FAULT_LIMIT                         0x5Bu
#define ADP1048W_CMD_IIN_OC_FAULT_RESPONSE                      0x5Cu
#define ADP1048W_CMD_IIN_OC_WARN_LIMIT                          0x5Du
#define ADP1048W_CMD_PIN_OP_WARN_LIMIT                          0x6Bu
#define ADP1048W_CMD_STATUS_BYTE                                0x78u
#define ADP1048W_CMD_STATUS_WORD                                0x79u
#define ADP1048W_CMD_STATUS_VOUT                                0x7Au
#define ADP1048W_CMD_STATUS_INPUT                               0x7Cu
#define ADP1048W_CMD_STATUS_TEMPERATURE                         0x7Du
#define ADP1048W_CMD_READ_VIN                                   0x88u
#define ADP1048W_CMD_READ_IIN                                   0x89u
#define ADP1048W_CMD_READ_VOUT                                  0x8Bu
#define ADP1048W_CMD_READ_PIN                                   0x97u
#define ADP1048W_CMD_PMBUS_REVISION                             0x98u
#define ADP1048W_CMD_MFR_ID                                     0x99u
#define ADP1048W_CMD_MFR_MODEL                                  0x9Au
#define ADP1048W_CMD_MFR_REVISION                               0x9Bu
#define ADP1048W_CMD_EEPROM_DATA_00                             0xB0u
#define ADP1048W_CMD_EEPROM_DATA_01                             0xB1u
#define ADP1048W_CMD_EEPROM_DATA_02                             0xB2u
#define ADP1048W_CMD_EEPROM_DATA_03                             0xB3u
#define ADP1048W_CMD_EEPROM_DATA_04                             0xB4u
#define ADP1048W_CMD_EEPROM_DATA_05                             0xB5u
#define ADP1048W_CMD_EEPROM_DATA_06                             0xB6u
#define ADP1048W_CMD_EEPROM_DATA_07                             0xB7u
#define ADP1048W_CMD_EEPROM_DATA_08                             0xB8u
#define ADP1048W_CMD_EEPROM_DATA_09                             0xB9u
#define ADP1048W_CMD_EEPROM_DATA_10                             0xBAu
#define ADP1048W_CMD_EEPROM_DATA_11                             0xBBu
#define ADP1048W_CMD_EEPROM_DATA_12                             0xBCu
#define ADP1048W_CMD_EEPROM_DATA_13                             0xBDu
#define ADP1048W_CMD_EEPROM_DATA_14                             0xBEu
#define ADP1048W_CMD_EEPROM_DATA_15                             0xBFu
#define ADP1048W_CMD_EEPROM_CRC_CHKSUM                          0xD1u
#define ADP1048W_CMD_EEPROM_NUM_RD_BYTES                        0xD2u
#define ADP1048W_CMD_EEPROM_ADDR_OFFSET                         0xD3u
#define ADP1048W_CMD_EEPROM_PAGE_ERASE                          0xD4u
#define ADP1048W_CMD_EEPROM_PASSWORD                            0xD5u
#define ADP1048W_CMD_TRIM_PASSWORD                              0xD6u
#define ADP1048W_CMD_EEPROM_INFO                                0xF1u

/**************************************************************************/
/*                  MANUFACTURER-SPECIFIC PMBus COMMANDS                  */
/**************************************************************************/
#define ADP1048W_CMD_CS_FAST_OCP_RESPONSE                       0xFE00
#define ADP1048W_CMD_OVP_FAST_OVP_RESPONSE                      0xFE01
#define ADP1048W_CMD_OLP_RESPONSE                               0xFE02
#define ADP1048W_CMD_VDD3P3_RESPONSE                            0xFE03
#define ADP1048W_CMD_VCORE_RESPONSE                             0xFE04
#define ADP1048W_CMD_PGOOD_AC_OK_DEBOUNCE_SET                   0xFE05
#define ADP1048W_CMD_PSON_SET                                   0xFE06
#define ADP1048W_CMD_FLAG_FAULT_ID                              0xFE07
#define ADP1048W_CMD_SOFTSTART_FLAGS_BLANK1                     0xFE08
#define ADP1048W_CMD_SOFTSTART_FLAGS_BLANK2                     0xFE09
#define ADP1048W_CMD_PGOOD_FLAGS_LIST                           0xFE0A
#define ADP1048W_CMD_AC_OK_FLAGS_LIST                           0xFE0B
#define ADP1048W_CMD_PWM1_RISING_EDGE_TIMING                    0xFE0C
#define ADP1048W_CMD_PWM1_RISING_EDGE_SETTING                   0xFE0D
#define ADP1048W_CMD_PWM1_FALLING_EDGE_TIMING                   0xFE0E
#define ADP1048W_CMD_PWM1_FALLING_EDGE_SETTING                  0xFE0F
#define ADP1048W_CMD_PWM2_RISING_EDGE_TIMING                    0xFE10
#define ADP1048W_CMD_PWM2_RISING_EDGE_SETTING                   0xFE11
#define ADP1048W_CMD_PWM2_FALLING_EDGE_TIMING                   0xFE12
#define ADP1048W_CMD_PWM2_FALLING_EDGE_SETTING                  0xFE13
#define ADP1048W_CMD_PWM_SET                                    0xFE14
#define ADP1048W_CMD_PWM_LIMIT                                  0xFE15
#define ADP1048W_CMD_RTD_ADC_OFFSET_TRIM_SETTING_MSB            0xFE16
#define ADP1048W_CMD_RTD_ADC_OFFSET_TRIM_SETTING_LSB            0xFE17
#define ADP1048W_CMD_RTD_ADC_GAIN_TRIM_SETTING                  0xFE18
#define ADP1048W_CMD_OT_FAULT_LIMIT                             0xFE19
#define ADP1048W_CMD_OT_WARN_LIMIT                              0xFE1A
#define ADP1048W_CMD_SWITCH_FREQ_SETTING                        0xFE1B
#define ADP1048W_CMD_LOW_PW_SWITCH_FREQ_SETTING                 0xFE1C
#define ADP1048W_CMD_FREQ_DITHERING_SET                         0xFE1D
#define ADP1048W_CMD_FREQ_SYNC_SET                              0xFE1E
#define ADP1048W_CMD_VOLT_LOOP_FILT_GAIN                        0xFE20
#define ADP1048W_CMD_VOLT_LOOP_FILT_ZERO                        0xFE21
#define ADP1048W_CMD_FAST_VOLT_LOOP_FILT_GAIN                   0xFE22
#define ADP1048W_CMD_FAST_VOLT_LOOP_FILT_ZERO                   0xFE23
#define ADP1048W_CMD_FAST_VOLT_LOOP_ENABLE                      0xFE24
#define ADP1048W_CMD_VAC_THRESHOLD_SET                          0xFE25
#define ADP1048W_CMD_VAC_THRESHOLD_READ                         0xFE26
#define ADP1048W_CMD_MIN_AC_PRD_SET                             0xFE27
#define ADP1048W_CMD_MAX_AC_PRD_SET                             0xFE28
#define ADP1048W_CMD_CURR_LOOP_FILT_GAIN_LOW_LN_IN              0xFE29
#define ADP1048W_CMD_CURR_LOOP_FILT_ZERO_LOW_LN_IN              0xFE2A
#define ADP1048W_CMD_CURR_LOOP_FILT_GAIN_HIGH_LN_IN             0xFE2B
#define ADP1048W_CMD_CURR_LOOP_FILT_ZERO_HIGH_LN_IN             0xFE2C
#define ADP1048W_CMD_SOFT_START_SET                             0xFE2D
#define ADP1048W_CMD_INRUSH_SET                                 0xFE2E
#define ADP1048W_CMD_FAST_OVP_FAULT_RISE                        0xFE2F
#define ADP1048W_CMD_FAST_OVP_FAULT_FALL                        0xFE30
#define ADP1048W_CMD_FAST_OVP_DEBOUNCE_TIME_SETTING             0xFE31
#define ADP1048W_CMD_LOW_PW_MODE_OP_THRESHOLD                   0xFE32
#define ADP1048W_CMD_PW_METERING_OFFSET_TRIM_LOW_LN_IN          0xFE33
#define ADP1048W_CMD_PW_METERING_GAIN_TRIM_LOW_LN_IN            0xFE34
#define ADP1048W_CMD_HIGH_LN_LIMIT                              0xFE35
#define ADP1048W_CMD_LOW_LN_LIMIT                               0xFE36
#define ADP1048W_CMD_ILIM_TRIM                                  0xFE37
#define ADP1048W_CMD_VOLT_LOOP_OUT                              0xFE38
#define ADP1048W_CMD_EXPONENT                                   0xFE39
#define ADP1048W_CMD_READ_UPDATE_RATE                           0xFE3A
#define ADP1048W_CMD_VIN_SCALE_MONITOR                          0xFE3B
#define ADP1048W_CMD_IIN_GSENSE                                 0xFE3C
#define ADP1048W_CMD_CS_FAST_OCP_BLANK                          0xFE3D
#define ADP1048W_CMD_CS_FAST_OCP_SETTING                        0xFE3E
#define ADP1048W_CMD_TEMP_HYS                                   0xFE2F
#define ADP1048W_CMD_VAC_ADC_GAIN_TRIM                          0xFE40
#define ADP1048W_CMD_VFB_ADC_GAIN_TRIM                          0xFE41
#define ADP1048W_CMD_CS_ADC_GAIN_TRIM_RANGE_500MV               0xFE42
#define ADP1048W_CMD_IBAL_GAIN                                  0xFE43
#define ADP1048W_CMD_SMAERT_VOUT_LOW_PW_THRESHOLD_P1            0xFE44
#define ADP1048W_CMD_SMAERT_VOUT_HIGH_PW_THRESHOLD_P2           0xFE45
#define ADP1048W_CMD_SMAERT_VOUT_LOW_LN_VOL1                    0xFE46
#define ADP1048W_CMD_SMAERT_VOUT_LOW_LN_VOL2                    0xFE47
#define ADP1048W_CMD_SMAERT_VOUT_HIGH_LN_VOH1                   0xFE48
#define ADP1048W_CMD_SMAERT_VOUT_HIGH_LN_VOH2                   0xFE49
#define ADP1048W_CMD_SMAERT_VOUT_UPPER_LIMIT_VOH                0xFE4A
#define ADP1048W_CMD_SMAERT_VOUT_SUPER_HIGH_LN                  0xFE4B
#define ADP1048W_CMD_SYNC_DELAY                                 0xFE4C
#define ADP1048W_CMD_SMART_VOUT_SUPER_HIGH_LN_HYS               0xFE4D
#define ADP1048W_CMD_PW_HYS                                     0xFE4E
#define ADP1048W_CMD_ADVANCED_FEATURE_ENABLE                    0xFE4F
#define ADP1048W_CMD_VOUT_OV_FAULT_HYS                          0xFE50
#define ADP1048W_CMD_VIN_UV_FAULT_HYS                           0xFE51
#define ADP1048W_CMD_VAC_ADC_OFFSET_TRIM                        0xFE53
#define ADP1048W_CMD_CS_ADC_OFFSET_TRIM_RANGE_500MV             0xFE54
#define ADP1048W_CMD_CS_ADC_GAIN_TRIM_HIGH_RANGE_750MV          0xFE7E
#define ADP1048W_CMD_CS_ADC_OFFSET_TRIM_HIGH_RANGE_750MV        0xFE7F
#define ADP1048W_CMD_LATCHED_FLAG_0                             0xFE80
#define ADP1048W_CMD_LATCHED_FLAG_1                             0xFE81
#define ADP1048W_CMD_LATCHED_FLAG_2                             0xFE82
#define ADP1048W_CMD_PWM_VALUE                                  0xFE84
#define ADP1048W_CMD_VAC_LN_PRD                                 0xFE85
#define ADP1048W_CMD_READ_TEMP_ADC                              0xFE86
#define ADP1048W_CMD_PW_METERING_OFFSET_TRIM_HIGH_LN_IN         0xFE8E
#define ADP1048W_CMD_PW_METERING_GAIN_TRIM_HIGH_LN_IN           0xFE8F
#define ADP1048W_CMD_CURR_LOOP_FILT_GAIN_LOW_LN_IN_LIGHT_LOAD   0xFE90
#define ADP1048W_CMD_CURR_LOOP_FILT_ZERO_LOW_LN_IN_LIGHT_LOAD   0xFE91
#define ADP1048W_CMD_CURR_LOOP_FILT_GAIN_HIGH_LN_IN_LIGHT_LOAD  0xFE92
#define ADP1048W_CMD_CURR_LOOP_FILT_ZERO_HIGH_LN_IN_LIGHT_LOAD  0xFE93
#define ADP1048W_CMD_SMART_VOUT                                 0xFE94
#define ADP1048W_CMD_IBAL_CONFIG                                0xFE95


/* ADP1048W Switch-ON condition */
/* SCO 143149 */
//#define ADP1048W_DIO_SWITCH_ON                                  0x01
//#define ADP1048W_DIO_SWITCH_OFF                                 0x00

/* ADP1048W CAPABILITY REGISTER - MAx Speed 400kHz */
#define ADP1048W_PMBUS_CAPIBILITY_MAX_SPEED                     0x20

/*ADP1048W Frequency Synchronization setting defined in register 0xFE1E */
#define ADP1048W_SET_FREQ_SYNC_DIVISION_1                       0x00
#define ADP1048W_SET_FREQ_SYNC_DIVISION_2                       0x01
#define ADP1048W_SET_FREQ_SYNC_DIVISION_3                       0x02
#define ADP1048W_SET_FREQ_SYNC_DIVISION_4                       0x03

/*ADP1048W Advanced feature enable defined in register 0xFE1E */
#define ADP1048W_SET_ADVANCED_FEATURE_PWM_SYNC                  0x02


/* ADP1048W Manufacture's ID - Analoge Devices */
#define ADP1048W_MFR_ID                                         0x41


#endif
