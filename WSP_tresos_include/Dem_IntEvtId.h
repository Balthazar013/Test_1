/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DEM_INT_EVT_ID_H)
#define DEM_INT_EVT_ID_H

/* This file contains the configuration declarations of the
 * SW-C Event ID symbols for AUTOSAR module Dem. */

/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

/*------------------[Events configuration]----------------------------------*/

/* Symbolic names of configured SW-C event IDs */

#if (defined FAULT_BATTERY_VOLTAGE_UPPER)
#error FAULT_BATTERY_VOLTAGE_UPPER already defined
#endif
/** \brief Symbolic name of event FAULT_BATTERY_VOLTAGE_UPPER */
#define FAULT_BATTERY_VOLTAGE_UPPER \
16U

#if (defined FAULT_BATTERY_VOLTAGE_LOWER)
#error FAULT_BATTERY_VOLTAGE_LOWER already defined
#endif
/** \brief Symbolic name of event FAULT_BATTERY_VOLTAGE_LOWER */
#define FAULT_BATTERY_VOLTAGE_LOWER \
17U

#if (defined FAULT_CAN_ENABLE)
#error FAULT_CAN_ENABLE already defined
#endif
/** \brief Symbolic name of event FAULT_CAN_ENABLE */
#define FAULT_CAN_ENABLE \
18U

#if (defined FAULT_MAIN_ADC_INTEGRITY)
#error FAULT_MAIN_ADC_INTEGRITY already defined
#endif
/** \brief Symbolic name of event FAULT_MAIN_ADC_INTEGRITY */
#define FAULT_MAIN_ADC_INTEGRITY \
19U

#if (defined FAULT_VBAT_MONITOR)
#error FAULT_VBAT_MONITOR already defined
#endif
/** \brief Symbolic name of event FAULT_VBAT_MONITOR */
#define FAULT_VBAT_MONITOR \
20U

#if (defined POS_FAR_MEASURE)
#error POS_FAR_MEASURE already defined
#endif
/** \brief Symbolic name of event POS_FAR_MEASURE */
#define POS_FAR_MEASURE \
37U

#if (defined POS_NEAR_MEASURE)
#error POS_NEAR_MEASURE already defined
#endif
/** \brief Symbolic name of event POS_NEAR_MEASURE */
#define POS_NEAR_MEASURE \
38U

#if (defined SBC_TEMP_SENSOR_SHORT_GND)
#error SBC_TEMP_SENSOR_SHORT_GND already defined
#endif
/** \brief Symbolic name of event SBC_TEMP_SENSOR_SHORT_GND */
#define SBC_TEMP_SENSOR_SHORT_GND \
39U

#if (defined SBC_TEMP_SENSOR_SHORT_SUPP)
#error SBC_TEMP_SENSOR_SHORT_SUPP already defined
#endif
/** \brief Symbolic name of event SBC_TEMP_SENSOR_SHORT_SUPP */
#define SBC_TEMP_SENSOR_SHORT_SUPP \
40U

#if (defined SBC_TEMP_SENSOR_OPEN)
#error SBC_TEMP_SENSOR_OPEN already defined
#endif
/** \brief Symbolic name of event SBC_TEMP_SENSOR_OPEN */
#define SBC_TEMP_SENSOR_OPEN \
41U

#if (defined P12V0_SENSOR_SHORT_GND)
#error P12V0_SENSOR_SHORT_GND already defined
#endif
/** \brief Symbolic name of event P12V0_SENSOR_SHORT_GND */
#define P12V0_SENSOR_SHORT_GND \
42U

#if (defined P12V0_SENSOR_SHORT_SUPP)
#error P12V0_SENSOR_SHORT_SUPP already defined
#endif
/** \brief Symbolic name of event P12V0_SENSOR_SHORT_SUPP */
#define P12V0_SENSOR_SHORT_SUPP \
43U

#if (defined P12V0_SENSOR_OPEN)
#error P12V0_SENSOR_OPEN already defined
#endif
/** \brief Symbolic name of event P12V0_SENSOR_OPEN */
#define P12V0_SENSOR_OPEN \
44U

#if (defined PFC_VOUT_SENSOR_SHORT_GND)
#error PFC_VOUT_SENSOR_SHORT_GND already defined
#endif
/** \brief Symbolic name of event PFC_VOUT_SENSOR_SHORT_GND */
#define PFC_VOUT_SENSOR_SHORT_GND \
45U

#if (defined PFC_VOUT_SENSOR_SHORT_SUPP)
#error PFC_VOUT_SENSOR_SHORT_SUPP already defined
#endif
/** \brief Symbolic name of event PFC_VOUT_SENSOR_SHORT_SUPP */
#define PFC_VOUT_SENSOR_SHORT_SUPP \
46U

#if (defined PFC_VOUT_SENSOR_OPEN)
#error PFC_VOUT_SENSOR_OPEN already defined
#endif
/** \brief Symbolic name of event PFC_VOUT_SENSOR_OPEN */
#define PFC_VOUT_SENSOR_OPEN \
47U

#if (defined P5V0_SENSOR_SHORT_GND)
#error P5V0_SENSOR_SHORT_GND already defined
#endif
/** \brief Symbolic name of event P5V0_SENSOR_SHORT_GND */
#define P5V0_SENSOR_SHORT_GND \
48U

#if (defined P5V0_SENSOR_SHORT_SUPP)
#error P5V0_SENSOR_SHORT_SUPP already defined
#endif
/** \brief Symbolic name of event P5V0_SENSOR_SHORT_SUPP */
#define P5V0_SENSOR_SHORT_SUPP \
49U

#if (defined P5V0_SENSOR_OPEN)
#error P5V0_SENSOR_OPEN already defined
#endif
/** \brief Symbolic name of event P5V0_SENSOR_OPEN */
#define P5V0_SENSOR_OPEN \
50U

#if (defined P3V3_S_SENSOR_SHORT_GND)
#error P3V3_S_SENSOR_SHORT_GND already defined
#endif
/** \brief Symbolic name of event P3V3_S_SENSOR_SHORT_GND */
#define P3V3_S_SENSOR_SHORT_GND \
51U

#if (defined P3V3_S_SENSOR_SHORT_SUPP)
#error P3V3_S_SENSOR_SHORT_SUPP already defined
#endif
/** \brief Symbolic name of event P3V3_S_SENSOR_SHORT_SUPP */
#define P3V3_S_SENSOR_SHORT_SUPP \
52U

#if (defined P3V3_S_SENSOR_OPEN)
#error P3V3_S_SENSOR_OPEN already defined
#endif
/** \brief Symbolic name of event P3V3_S_SENSOR_OPEN */
#define P3V3_S_SENSOR_OPEN \
53U

#if (defined ZMOVER_CURRENT_HIGH)
#error ZMOVER_CURRENT_HIGH already defined
#endif
/** \brief Symbolic name of event ZMOVER_CURRENT_HIGH */
#define ZMOVER_CURRENT_HIGH \
54U

#if (defined ZMOVER_POWER_DEFECT)
#error ZMOVER_POWER_DEFECT already defined
#endif
/** \brief Symbolic name of event ZMOVER_POWER_DEFECT */
#define ZMOVER_POWER_DEFECT \
55U

#if (defined ZMOVER_HALL_SENSOR_DEFECT)
#error ZMOVER_HALL_SENSOR_DEFECT already defined
#endif
/** \brief Symbolic name of event ZMOVER_HALL_SENSOR_DEFECT */
#define ZMOVER_HALL_SENSOR_DEFECT \
56U

#if (defined ZMOVER_HALL_MIN_POSITION_SENSOR_DEFECT)
#error ZMOVER_HALL_MIN_POSITION_SENSOR_DEFECT already defined
#endif
/** \brief Symbolic name of event ZMOVER_HALL_MIN_POSITION_SENSOR_DEFECT */
#define ZMOVER_HALL_MIN_POSITION_SENSOR_DEFECT \
57U

#if (defined ZMOVER_SWITCH_MIN_POSITION_SENSOR_DEFECT)
#error ZMOVER_SWITCH_MIN_POSITION_SENSOR_DEFECT already defined
#endif
/** \brief Symbolic name of event ZMOVER_SWITCH_MIN_POSITION_SENSOR_DEFECT */
#define ZMOVER_SWITCH_MIN_POSITION_SENSOR_DEFECT \
58U

#if (defined ZMOVER_ACTUATOR_DEFECT)
#error ZMOVER_ACTUATOR_DEFECT already defined
#endif
/** \brief Symbolic name of event ZMOVER_ACTUATOR_DEFECT */
#define ZMOVER_ACTUATOR_DEFECT \
59U

#if (defined ZMOVER_MOVE_RANDOM)
#error ZMOVER_MOVE_RANDOM already defined
#endif
/** \brief Symbolic name of event ZMOVER_MOVE_RANDOM */
#define ZMOVER_MOVE_RANDOM \
60U

#if (defined BOOST_TEMP_LOW)
#error BOOST_TEMP_LOW already defined
#endif
/** \brief Symbolic name of event BOOST_TEMP_LOW */
#define BOOST_TEMP_LOW \
61U

#if (defined BOOST_TEMP_HIGH)
#error BOOST_TEMP_HIGH already defined
#endif
/** \brief Symbolic name of event BOOST_TEMP_HIGH */
#define BOOST_TEMP_HIGH \
62U

#if (defined B6_TEMP_LOW)
#error B6_TEMP_LOW already defined
#endif
/** \brief Symbolic name of event B6_TEMP_LOW */
#define B6_TEMP_LOW \
63U

#if (defined B6_TEMP_HIGH)
#error B6_TEMP_HIGH already defined
#endif
/** \brief Symbolic name of event B6_TEMP_HIGH */
#define B6_TEMP_HIGH \
64U

#if (defined WPC_IN_CURRENT_HIGH)
#error WPC_IN_CURRENT_HIGH already defined
#endif
/** \brief Symbolic name of event WPC_IN_CURRENT_HIGH */
#define WPC_IN_CURRENT_HIGH \
65U

#if (defined BT_SPI_COMMUNICATION_TIMEOUT)
#error BT_SPI_COMMUNICATION_TIMEOUT already defined
#endif
/** \brief Symbolic name of event BT_SPI_COMMUNICATION_TIMEOUT */
#define BT_SPI_COMMUNICATION_TIMEOUT \
66U

#if (defined WPC_IN_VOLTAGE_HIGH)
#error WPC_IN_VOLTAGE_HIGH already defined
#endif
/** \brief Symbolic name of event WPC_IN_VOLTAGE_HIGH */
#define WPC_IN_VOLTAGE_HIGH \
67U

#if (defined FOD_WRONG_OUT_STATE)
#error FOD_WRONG_OUT_STATE already defined
#endif
/** \brief Symbolic name of event FOD_WRONG_OUT_STATE */
#define FOD_WRONG_OUT_STATE \
68U

#if (defined FOD_NULL_VECTOR_INVALID)
#error FOD_NULL_VECTOR_INVALID already defined
#endif
/** \brief Symbolic name of event FOD_NULL_VECTOR_INVALID */
#define FOD_NULL_VECTOR_INVALID \
69U

#if (defined BLE_COMM_TIMEOUT)
#error BLE_COMM_TIMEOUT already defined
#endif
/** \brief Symbolic name of event BLE_COMM_TIMEOUT */
#define BLE_COMM_TIMEOUT \
70U

#if (defined BLE_STATUS_SIGNAL_NOTRECEIVED)
#error BLE_STATUS_SIGNAL_NOTRECEIVED already defined
#endif
/** \brief Symbolic name of event BLE_STATUS_SIGNAL_NOTRECEIVED */
#define BLE_STATUS_SIGNAL_NOTRECEIVED \
71U

#if (defined METAL_ON_PAD)
#error METAL_ON_PAD already defined
#endif
/** \brief Symbolic name of event METAL_ON_PAD */
#define METAL_ON_PAD \
72U

#if (defined ORU_NOT_RECOGNIZED)
#error ORU_NOT_RECOGNIZED already defined
#endif
/** \brief Symbolic name of event ORU_NOT_RECOGNIZED */
#define ORU_NOT_RECOGNIZED \
73U

#if (defined POS_SIGNAL_OUTOFRANGE)
#error POS_SIGNAL_OUTOFRANGE already defined
#endif
/** \brief Symbolic name of event POS_SIGNAL_OUTOFRANGE */
#define POS_SIGNAL_OUTOFRANGE \
74U

#if (defined PFC_MCU_UART_ERROR)
#error PFC_MCU_UART_ERROR already defined
#endif
/** \brief Symbolic name of event PFC_MCU_UART_ERROR */
#define PFC_MCU_UART_ERROR \
75U

#if (defined PFC_UART_COMM_ERROR)
#error PFC_UART_COMM_ERROR already defined
#endif
/** \brief Symbolic name of event PFC_UART_COMM_ERROR */
#define PFC_UART_COMM_ERROR \
76U

#if (defined FOD_CAN_FAILURE)
#error FOD_CAN_FAILURE already defined
#endif
/** \brief Symbolic name of event FOD_CAN_FAILURE */
#define FOD_CAN_FAILURE \
77U

#if (defined FOD_CAN_NO_COMMUNICATION)
#error FOD_CAN_NO_COMMUNICATION already defined
#endif
/** \brief Symbolic name of event FOD_CAN_NO_COMMUNICATION */
#define FOD_CAN_NO_COMMUNICATION \
78U

#if (defined ROM_TEST_FAILED)
#error ROM_TEST_FAILED already defined
#endif
/** \brief Symbolic name of event ROM_TEST_FAILED */
#define ROM_TEST_FAILED \
79U

#if (defined RAM_TEST_FAILED)
#error RAM_TEST_FAILED already defined
#endif
/** \brief Symbolic name of event RAM_TEST_FAILED */
#define RAM_TEST_FAILED \
80U

#if (defined EEPROM_TEST_FAILED)
#error EEPROM_TEST_FAILED already defined
#endif
/** \brief Symbolic name of event EEPROM_TEST_FAILED */
#define EEPROM_TEST_FAILED \
81U

#if (defined CAN_RAM_TEST_FAILED)
#error CAN_RAM_TEST_FAILED already defined
#endif
/** \brief Symbolic name of event CAN_RAM_TEST_FAILED */
#define CAN_RAM_TEST_FAILED \
82U

#if (defined VOLTAGE_SENSOR_DEFECT)
#error VOLTAGE_SENSOR_DEFECT already defined
#endif
/** \brief Symbolic name of event VOLTAGE_SENSOR_DEFECT */
#define VOLTAGE_SENSOR_DEFECT \
83U

#if (defined SBC_SPI_COMMUNICATION_TIMEOUT)
#error SBC_SPI_COMMUNICATION_TIMEOUT already defined
#endif
/** \brief Symbolic name of event SBC_SPI_COMMUNICATION_TIMEOUT */
#define SBC_SPI_COMMUNICATION_TIMEOUT \
84U

#if (defined NVM_ERROR)
#error NVM_ERROR already defined
#endif
/** \brief Symbolic name of event NVM_ERROR */
#define NVM_ERROR \
85U

#if (defined PINCH_PROTECTION_WAS_ACTIVE)
#error PINCH_PROTECTION_WAS_ACTIVE already defined
#endif
/** \brief Symbolic name of event PINCH_PROTECTION_WAS_ACTIVE */
#define PINCH_PROTECTION_WAS_ACTIVE \
86U

#if (defined Z_MOVER_IS_BLOCKED)
#error Z_MOVER_IS_BLOCKED already defined
#endif
/** \brief Symbolic name of event Z_MOVER_IS_BLOCKED */
#define Z_MOVER_IS_BLOCKED \
87U

#if (defined Z_MOVER_WAS_LOWERED_WITH_ACTIVE_FORCE)
#error Z_MOVER_WAS_LOWERED_WITH_ACTIVE_FORCE already defined
#endif
/** \brief Symbolic name of event Z_MOVER_WAS_LOWERED_WITH_ACTIVE_FORCE */
#define Z_MOVER_WAS_LOWERED_WITH_ACTIVE_FORCE \
88U

#if (defined Z_MOVER_ACTIVIATION_TIMEOUT)
#error Z_MOVER_ACTIVIATION_TIMEOUT already defined
#endif
/** \brief Symbolic name of event Z_MOVER_ACTIVIATION_TIMEOUT */
#define Z_MOVER_ACTIVIATION_TIMEOUT \
89U

#if (defined BOOST_VOLTAGE_IS_TOO_LOW)
#error BOOST_VOLTAGE_IS_TOO_LOW already defined
#endif
/** \brief Symbolic name of event BOOST_VOLTAGE_IS_TOO_LOW */
#define BOOST_VOLTAGE_IS_TOO_LOW \
90U

#if (defined BOOST_VOLTAGE_IS_TOO_HIGH)
#error BOOST_VOLTAGE_IS_TOO_HIGH already defined
#endif
/** \brief Symbolic name of event BOOST_VOLTAGE_IS_TOO_HIGH */
#define BOOST_VOLTAGE_IS_TOO_HIGH \
91U

#if (defined CAPS_TEMPERATURE_IS_TOO_LOW)
#error CAPS_TEMPERATURE_IS_TOO_LOW already defined
#endif
/** \brief Symbolic name of event CAPS_TEMPERATURE_IS_TOO_LOW */
#define CAPS_TEMPERATURE_IS_TOO_LOW \
92U

#if (defined CAPS_TEMPERATURE_IS_TOO_HIGH)
#error CAPS_TEMPERATURE_IS_TOO_HIGH already defined
#endif
/** \brief Symbolic name of event CAPS_TEMPERATURE_IS_TOO_HIGH */
#define CAPS_TEMPERATURE_IS_TOO_HIGH \
93U

#if (defined GRID_INPUT_CURRENT_HIGH)
#error GRID_INPUT_CURRENT_HIGH already defined
#endif
/** \brief Symbolic name of event GRID_INPUT_CURRENT_HIGH */
#define GRID_INPUT_CURRENT_HIGH \
94U

#if (defined GRID_INPUT_VOLTAGE_HIGH)
#error GRID_INPUT_VOLTAGE_HIGH already defined
#endif
/** \brief Symbolic name of event GRID_INPUT_VOLTAGE_HIGH */
#define GRID_INPUT_VOLTAGE_HIGH \
95U

#if (defined GRID_INPUT_VOLTAGE_LOW)
#error GRID_INPUT_VOLTAGE_LOW already defined
#endif
/** \brief Symbolic name of event GRID_INPUT_VOLTAGE_LOW */
#define GRID_INPUT_VOLTAGE_LOW \
96U

#if (defined WPC_TEMPERATURE_LOW)
#error WPC_TEMPERATURE_LOW already defined
#endif
/** \brief Symbolic name of event WPC_TEMPERATURE_LOW */
#define WPC_TEMPERATURE_LOW \
98U

#if (defined WPC_INPUT_POWER_HIGH)
#error WPC_INPUT_POWER_HIGH already defined
#endif
/** \brief Symbolic name of event WPC_INPUT_POWER_HIGH */
#define WPC_INPUT_POWER_HIGH \
99U

#if (defined WPC_INPUT_POWER_LOW)
#error WPC_INPUT_POWER_LOW already defined
#endif
/** \brief Symbolic name of event WPC_INPUT_POWER_LOW */
#define WPC_INPUT_POWER_LOW \
100U

#if (defined RCDA_TEST_FAILED)
#error RCDA_TEST_FAILED already defined
#endif
/** \brief Symbolic name of event RCDA_TEST_FAILED */
#define RCDA_TEST_FAILED \
101U

#if (defined RCDA_LEAKAGECURRDETECTED)
#error RCDA_LEAKAGECURRDETECTED already defined
#endif
/** \brief Symbolic name of event RCDA_LEAKAGECURRDETECTED */
#define RCDA_LEAKAGECURRDETECTED \
102U

#if (defined FAN_1_DEFECT)
#error FAN_1_DEFECT already defined
#endif
/** \brief Symbolic name of event FAN_1_DEFECT */
#define FAN_1_DEFECT \
103U

#if (defined FAN_2_DEFECT)
#error FAN_2_DEFECT already defined
#endif
/** \brief Symbolic name of event FAN_2_DEFECT */
#define FAN_2_DEFECT \
104U

#if (defined MAGN_COUPL_TOO_HIGH)
#error MAGN_COUPL_TOO_HIGH already defined
#endif
/** \brief Symbolic name of event MAGN_COUPL_TOO_HIGH */
#define MAGN_COUPL_TOO_HIGH \
105U

#if (defined MAGN_COUPL_TOO_LOW)
#error MAGN_COUPL_TOO_LOW already defined
#endif
/** \brief Symbolic name of event MAGN_COUPL_TOO_LOW */
#define MAGN_COUPL_TOO_LOW \
106U

#if (defined MAGN_COUPL_NOT_PLAUSIBLE)
#error MAGN_COUPL_NOT_PLAUSIBLE already defined
#endif
/** \brief Symbolic name of event MAGN_COUPL_NOT_PLAUSIBLE */
#define MAGN_COUPL_NOT_PLAUSIBLE \
107U

#if (defined SAFETY_SHUTDOWN_TEMPERATURE_PAD)
#error SAFETY_SHUTDOWN_TEMPERATURE_PAD already defined
#endif
/** \brief Symbolic name of event SAFETY_SHUTDOWN_TEMPERATURE_PAD */
#define SAFETY_SHUTDOWN_TEMPERATURE_PAD \
108U

#if (defined SAFETY_SHUTDOWN_TEMPERATURE_WU)
#error SAFETY_SHUTDOWN_TEMPERATURE_WU already defined
#endif
/** \brief Symbolic name of event SAFETY_SHUTDOWN_TEMPERATURE_WU */
#define SAFETY_SHUTDOWN_TEMPERATURE_WU \
109U

#if (defined MAIN_POWER_RELAY_ERROR)
#error MAIN_POWER_RELAY_ERROR already defined
#endif
/** \brief Symbolic name of event MAIN_POWER_RELAY_ERROR */
#define MAIN_POWER_RELAY_ERROR \
110U

#if (defined PWR_GRD_CURRENT_NOT_PLAUSIBLE)
#error PWR_GRD_CURRENT_NOT_PLAUSIBLE already defined
#endif
/** \brief Symbolic name of event PWR_GRD_CURRENT_NOT_PLAUSIBLE */
#define PWR_GRD_CURRENT_NOT_PLAUSIBLE \
111U

#if (defined PWR_GRD_FREQ_HIGH)
#error PWR_GRD_FREQ_HIGH already defined
#endif
/** \brief Symbolic name of event PWR_GRD_FREQ_HIGH */
#define PWR_GRD_FREQ_HIGH \
112U

#if (defined PWR_GRD_FREQ_LOW)
#error PWR_GRD_FREQ_LOW already defined
#endif
/** \brief Symbolic name of event PWR_GRD_FREQ_LOW */
#define PWR_GRD_FREQ_LOW \
113U

#if (defined B6_TEMP_SC_TO_GND)
#error B6_TEMP_SC_TO_GND already defined
#endif
/** \brief Symbolic name of event B6_TEMP_SC_TO_GND */
#define B6_TEMP_SC_TO_GND \
114U

#if (defined B6_TEMP_SC_TO_SUP)
#error B6_TEMP_SC_TO_SUP already defined
#endif
/** \brief Symbolic name of event B6_TEMP_SC_TO_SUP */
#define B6_TEMP_SC_TO_SUP \
115U

#if (defined RECT_TEMP_SC_TO_GND)
#error RECT_TEMP_SC_TO_GND already defined
#endif
/** \brief Symbolic name of event RECT_TEMP_SC_TO_GND */
#define RECT_TEMP_SC_TO_GND \
116U

#if (defined RECT_TEMP_SC_TO_SUP)
#error RECT_TEMP_SC_TO_SUP already defined
#endif
/** \brief Symbolic name of event RECT_TEMP_SC_TO_SUP */
#define RECT_TEMP_SC_TO_SUP \
117U

#if (defined PFC_TEMP_SC_TO_GND)
#error PFC_TEMP_SC_TO_GND already defined
#endif
/** \brief Symbolic name of event PFC_TEMP_SC_TO_GND */
#define PFC_TEMP_SC_TO_GND \
118U

#if (defined PFC_TEMP_SC_TO_SUP)
#error PFC_TEMP_SC_TO_SUP already defined
#endif
/** \brief Symbolic name of event PFC_TEMP_SC_TO_SUP */
#define PFC_TEMP_SC_TO_SUP \
119U

#if (defined DC_LINK_TEMP_SC_TO_GND)
#error DC_LINK_TEMP_SC_TO_GND already defined
#endif
/** \brief Symbolic name of event DC_LINK_TEMP_SC_TO_GND */
#define DC_LINK_TEMP_SC_TO_GND \
120U

#if (defined DC_LINK_TEMP_SC_TO_SUP)
#error DC_LINK_TEMP_SC_TO_SUP already defined
#endif
/** \brief Symbolic name of event DC_LINK_TEMP_SC_TO_SUP */
#define DC_LINK_TEMP_SC_TO_SUP \
121U

#if (defined SENSE_BOARD_DEFECT)
#error SENSE_BOARD_DEFECT already defined
#endif
/** \brief Symbolic name of event SENSE_BOARD_DEFECT */
#define SENSE_BOARD_DEFECT \
122U

#if (defined CTRL_BOARD_DEFECT)
#error CTRL_BOARD_DEFECT already defined
#endif
/** \brief Symbolic name of event CTRL_BOARD_DEFECT */
#define CTRL_BOARD_DEFECT \
123U

#if (defined FOD_TEMP_UNTERVOLTAGE)
#error FOD_TEMP_UNTERVOLTAGE already defined
#endif
/** \brief Symbolic name of event FOD_TEMP_UNTERVOLTAGE */
#define FOD_TEMP_UNTERVOLTAGE \
124U

#if (defined SWITCH_CURR_1_TOO_LOW)
#error SWITCH_CURR_1_TOO_LOW already defined
#endif
/** \brief Symbolic name of event SWITCH_CURR_1_TOO_LOW */
#define SWITCH_CURR_1_TOO_LOW \
125U

#if (defined SWITCH_CURR_1_TOO_HIGH)
#error SWITCH_CURR_1_TOO_HIGH already defined
#endif
/** \brief Symbolic name of event SWITCH_CURR_1_TOO_HIGH */
#define SWITCH_CURR_1_TOO_HIGH \
126U

#if (defined SWITCH_CURR_2_TOO_LOW)
#error SWITCH_CURR_2_TOO_LOW already defined
#endif
/** \brief Symbolic name of event SWITCH_CURR_2_TOO_LOW */
#define SWITCH_CURR_2_TOO_LOW \
127U

#if (defined SWITCH_CURR_3_TOO_LOW)
#error SWITCH_CURR_3_TOO_LOW already defined
#endif
/** \brief Symbolic name of event SWITCH_CURR_3_TOO_LOW */
#define SWITCH_CURR_3_TOO_LOW \
129U

#if (defined SWITCH_CURR_3_TOO_HIGH)
#error SWITCH_CURR_3_TOO_HIGH already defined
#endif
/** \brief Symbolic name of event SWITCH_CURR_3_TOO_HIGH */
#define SWITCH_CURR_3_TOO_HIGH \
130U

#if (defined WPC_PH2_CURR_EXCEEDED)
#error WPC_PH2_CURR_EXCEEDED already defined
#endif
/** \brief Symbolic name of event WPC_PH2_CURR_EXCEEDED */
#define WPC_PH2_CURR_EXCEEDED \
132U

#if (defined WPC_PH3_CURR_EXCEEDED)
#error WPC_PH3_CURR_EXCEEDED already defined
#endif
/** \brief Symbolic name of event WPC_PH3_CURR_EXCEEDED */
#define WPC_PH3_CURR_EXCEEDED \
133U

#if (defined PAD_DERATING_WAS_ACTIVE)
#error PAD_DERATING_WAS_ACTIVE already defined
#endif
/** \brief Symbolic name of event PAD_DERATING_WAS_ACTIVE */
#define PAD_DERATING_WAS_ACTIVE \
134U

#if (defined INCORRECT_CODING_RESISTOR)
#error INCORRECT_CODING_RESISTOR already defined
#endif
/** \brief Symbolic name of event INCORRECT_CODING_RESISTOR */
#define INCORRECT_CODING_RESISTOR \
135U

#if (defined SHORT_CIRCUIT_CODING_RESISTOR)
#error SHORT_CIRCUIT_CODING_RESISTOR already defined
#endif
/** \brief Symbolic name of event SHORT_CIRCUIT_CODING_RESISTOR */
#define SHORT_CIRCUIT_CODING_RESISTOR \
136U

#if (defined OPEN_CIRCUIT_CODING_RESISTOR)
#error OPEN_CIRCUIT_CODING_RESISTOR already defined
#endif
/** \brief Symbolic name of event OPEN_CIRCUIT_CODING_RESISTOR */
#define OPEN_CIRCUIT_CODING_RESISTOR \
137U

#if (defined FREQUENCY_OUT_OF_RANGE)
#error FREQUENCY_OUT_OF_RANGE already defined
#endif
/** \brief Symbolic name of event FREQUENCY_OUT_OF_RANGE */
#define FREQUENCY_OUT_OF_RANGE \
138U

#if (defined ECU_WRONG_CODED)
#error ECU_WRONG_CODED already defined
#endif
/** \brief Symbolic name of event ECU_WRONG_CODED */
#define ECU_WRONG_CODED \
139U

#if (defined DATASET_IMPLAUSIBLE)
#error DATASET_IMPLAUSIBLE already defined
#endif
/** \brief Symbolic name of event DATASET_IMPLAUSIBLE */
#define DATASET_IMPLAUSIBLE \
140U

#if (defined DATASET_INVALID)
#error DATASET_INVALID already defined
#endif
/** \brief Symbolic name of event DATASET_INVALID */
#define DATASET_INVALID \
141U

#if (defined SOFTWARE_UPDATE_FAILED)
#error SOFTWARE_UPDATE_FAILED already defined
#endif
/** \brief Symbolic name of event SOFTWARE_UPDATE_FAILED */
#define SOFTWARE_UPDATE_FAILED \
142U

#if (defined POS_DS_INVALID)
#error POS_DS_INVALID already defined
#endif
/** \brief Symbolic name of event POS_DS_INVALID */
#define POS_DS_INVALID \
143U

#if (defined FOD_DS_INVALID)
#error FOD_DS_INVALID already defined
#endif
/** \brief Symbolic name of event FOD_DS_INVALID */
#define FOD_DS_INVALID \
144U

#if (defined SIGNAL_OUT_OF_RANGE)
#error SIGNAL_OUT_OF_RANGE already defined
#endif
/** \brief Symbolic name of event SIGNAL_OUT_OF_RANGE */
#define SIGNAL_OUT_OF_RANGE \
145U

#if (defined FOD_TEMP_SENSOR_OPEN_LOOP)
#error FOD_TEMP_SENSOR_OPEN_LOOP already defined
#endif
/** \brief Symbolic name of event FOD_TEMP_SENSOR_OPEN_LOOP */
#define FOD_TEMP_SENSOR_OPEN_LOOP \
146U

#if (defined FOD_OVERTEMPERATURE)
#error FOD_OVERTEMPERATURE already defined
#endif
/** \brief Symbolic name of event FOD_OVERTEMPERATURE */
#define FOD_OVERTEMPERATURE \
147U

#if (defined FOD_UNDERTEMPERATURE)
#error FOD_UNDERTEMPERATURE already defined
#endif
/** \brief Symbolic name of event FOD_UNDERTEMPERATURE */
#define FOD_UNDERTEMPERATURE \
148U

#if (defined FOD_METALL_DETECT_CHARGE_INTERRUPT)
#error FOD_METALL_DETECT_CHARGE_INTERRUPT already defined
#endif
/** \brief Symbolic name of event FOD_METALL_DETECT_CHARGE_INTERRUPT */
#define FOD_METALL_DETECT_CHARGE_INTERRUPT \
149U

#if (defined POS_MEASUREMENT_ERROR_ANTENNA_2)
#error POS_MEASUREMENT_ERROR_ANTENNA_2 already defined
#endif
/** \brief Symbolic name of event POS_MEASUREMENT_ERROR_ANTENNA_2 */
#define POS_MEASUREMENT_ERROR_ANTENNA_2 \
150U

#if (defined POS_MEASUREMENT_ERROR_ANTENNA_3)
#error POS_MEASUREMENT_ERROR_ANTENNA_3 already defined
#endif
/** \brief Symbolic name of event POS_MEASUREMENT_ERROR_ANTENNA_3 */
#define POS_MEASUREMENT_ERROR_ANTENNA_3 \
151U

#if (defined POS_MEASUREMENT_ERROR_ANTENNA_4)
#error POS_MEASUREMENT_ERROR_ANTENNA_4 already defined
#endif
/** \brief Symbolic name of event POS_MEASUREMENT_ERROR_ANTENNA_4 */
#define POS_MEASUREMENT_ERROR_ANTENNA_4 \
152U

#if (defined POS_VEHICLE_DETECTION_DEFECT)
#error POS_VEHICLE_DETECTION_DEFECT already defined
#endif
/** \brief Symbolic name of event POS_VEHICLE_DETECTION_DEFECT */
#define POS_VEHICLE_DETECTION_DEFECT \
153U

#if (defined WPC_ASC_ACTIVE_PAD)
#error WPC_ASC_ACTIVE_PAD already defined
#endif
/** \brief Symbolic name of event WPC_ASC_ACTIVE_PAD */
#define WPC_ASC_ACTIVE_PAD \
154U

#if (defined ZMOVER_MOTOR_OVERHEAT)
#error ZMOVER_MOTOR_OVERHEAT already defined
#endif
/** \brief Symbolic name of event ZMOVER_MOTOR_OVERHEAT */
#define ZMOVER_MOTOR_OVERHEAT \
155U

#if (defined P5V0_VOLTAGE_OVERVOLTAGE)
#error P5V0_VOLTAGE_OVERVOLTAGE already defined
#endif
/** \brief Symbolic name of event P5V0_VOLTAGE_OVERVOLTAGE */
#define P5V0_VOLTAGE_OVERVOLTAGE \
156U

#if (defined P5V0_VOLTAGE_UNDERVOLTAGE)
#error P5V0_VOLTAGE_UNDERVOLTAGE already defined
#endif
/** \brief Symbolic name of event P5V0_VOLTAGE_UNDERVOLTAGE */
#define P5V0_VOLTAGE_UNDERVOLTAGE \
157U

#if (defined P3V3_S_VOLTAGE_SENSOR_OVERVOLTAGE)
#error P3V3_S_VOLTAGE_SENSOR_OVERVOLTAGE already defined
#endif
/** \brief Symbolic name of event P3V3_S_VOLTAGE_SENSOR_OVERVOLTAGE */
#define P3V3_S_VOLTAGE_SENSOR_OVERVOLTAGE \
158U

#if (defined P3V3_S_VOLTAGE_SENSOR_UNDERVOLTAGE)
#error P3V3_S_VOLTAGE_SENSOR_UNDERVOLTAGE already defined
#endif
/** \brief Symbolic name of event P3V3_S_VOLTAGE_SENSOR_UNDERVOLTAGE */
#define P3V3_S_VOLTAGE_SENSOR_UNDERVOLTAGE \
159U

#if (defined ZMOVER_CURRENT_OFFSET)
#error ZMOVER_CURRENT_OFFSET already defined
#endif
/** \brief Symbolic name of event ZMOVER_CURRENT_OFFSET */
#define ZMOVER_CURRENT_OFFSET \
160U

#if (defined ZMOVER_MOTOR_POSITIV_OVERLOAD)
#error ZMOVER_MOTOR_POSITIV_OVERLOAD already defined
#endif
/** \brief Symbolic name of event ZMOVER_MOTOR_POSITIV_OVERLOAD */
#define ZMOVER_MOTOR_POSITIV_OVERLOAD \
161U

#if (defined ZMOVER_MOTOR_NEGATIV_OVERLOAD)
#error ZMOVER_MOTOR_NEGATIV_OVERLOAD already defined
#endif
/** \brief Symbolic name of event ZMOVER_MOTOR_NEGATIV_OVERLOAD */
#define ZMOVER_MOTOR_NEGATIV_OVERLOAD \
162U

/* Additional symbolic names of configured SW-C event IDs */

#if (defined DemConf_DemEventParameter_FAULT_BATTERY_VOLTAGE_UPPER)
#error DemConf_DemEventParameter_FAULT_BATTERY_VOLTAGE_UPPER already defined
#endif
/** \brief Additional symbolic name of event FAULT_BATTERY_VOLTAGE_UPPER */
#define DemConf_DemEventParameter_FAULT_BATTERY_VOLTAGE_UPPER \
16U

#if (defined DemConf_DemEventParameter_FAULT_BATTERY_VOLTAGE_LOWER)
#error DemConf_DemEventParameter_FAULT_BATTERY_VOLTAGE_LOWER already defined
#endif
/** \brief Additional symbolic name of event FAULT_BATTERY_VOLTAGE_LOWER */
#define DemConf_DemEventParameter_FAULT_BATTERY_VOLTAGE_LOWER \
17U

#if (defined DemConf_DemEventParameter_FAULT_CAN_ENABLE)
#error DemConf_DemEventParameter_FAULT_CAN_ENABLE already defined
#endif
/** \brief Additional symbolic name of event FAULT_CAN_ENABLE */
#define DemConf_DemEventParameter_FAULT_CAN_ENABLE \
18U

#if (defined DemConf_DemEventParameter_FAULT_MAIN_ADC_INTEGRITY)
#error DemConf_DemEventParameter_FAULT_MAIN_ADC_INTEGRITY already defined
#endif
/** \brief Additional symbolic name of event FAULT_MAIN_ADC_INTEGRITY */
#define DemConf_DemEventParameter_FAULT_MAIN_ADC_INTEGRITY \
19U

#if (defined DemConf_DemEventParameter_FAULT_VBAT_MONITOR)
#error DemConf_DemEventParameter_FAULT_VBAT_MONITOR already defined
#endif
/** \brief Additional symbolic name of event FAULT_VBAT_MONITOR */
#define DemConf_DemEventParameter_FAULT_VBAT_MONITOR \
20U


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_INT_EVT_ID_H ) */
/*==================[end of file]===========================================*/
