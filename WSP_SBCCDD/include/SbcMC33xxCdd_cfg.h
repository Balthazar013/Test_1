 /*----------------------------------------------------------------------------
** Project Name:CAR_36_Wayside
** #Archive: WsSbcCddSwc_cfg.h #
** #Author: Reiner Bogenfuerst#
** #Date: 2015-02-24#
** (c) Copyright 2015, Bombardier Transportation
**----------------------------------------------------------------------------
** #Revision: #
**----------------------------------------------------------------------------
** Target system: Freescale MPC5744P
** Compiler: GHS
** Description: System Basis Chip_MC33907_8
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    -------------------------------------
** RBOGENFU		Reiner Bogenfuerst Bombardier Transportation
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log: #
**--------------------------------------------------------------------------*/

/*! \brief  Configure voltage regulators and power supply
The Vcore voltage regulator is a step-down DC-DC converter with a PWM frequency 
of 2.4 MHz. The high-side MOSFET is integrated in the device. The output voltage 
can be configured around 1.2 V or 3.3 V through an external resistor divider 
(a minimum of 1% accuracy resistors are recommended) connected between Vcore and 
the feedback pin. Define Vcore_DIS to disable the Vcore control. Default configuration
is enabled if the define is commented out. 
!Switch OFF NOT POSSIBLE if Vcore is SAFETY critical!*/
#define Vcore_DIS 

/*! \brief The Vpre voltage pre-regulator is a flexible switched-mode power supply (SMPS).
Define IPFF_DIS to DISABLE the input Power Feed Forward (IPFF) function of 
Vpre. Default configuration is enabled if the define is commented out*/
/*#define IPFF_DIS*/ 

/*! \brief Define Vpre_DIS to DISABLE the Switched Mode Power Supply function of 
Vpre. Default configuration is enabled if the define is commented out*/
/*#define Vpre_DIS*/ 

/*! \brief The Vcca linear voltage regulator is mainly dedicated to supply the MCU 
I/Os, especially the ADC. Define Vcca_DIS to disable the Vcca control. 
Default configuration is enabled if the define is commented out.
!Switch OFF NOT POSSIBLE if Vcca is SAFETY critical!*/
#define Vcca_DIS 

/*! \brief This configuration only has an effect if an external PNP is used. Define 
sets the current limitation duration to 50ms before Vcca regulator 
is switched off. Configuration is set to 10ms if commented out*/
#define Tcca_lim_off_50ms 

/*! \brief This configuration only has an effect if an external PNP is used. Define sets
the current limitation to the OUTPUT current of the Vcca linear voltage regulator. 
Default configuration is set to the INPUT current if commented out.*/
#define Icca_lim_out 

/*! \brief The Vaux auxiliary voltage regulator is a dedicated supply for additional devices in 
the ECU or for sensors outside the ECU. Define Vaux_DIS to disable the Vaux control. 
Default configuration is enabled if the define is commented out.
!Switch OFF NOT POSSIBLE if Vaux is SAFETY critical!*/
#define Vaux_DIS 

/*! \brief This configuration only has an effect if an external PNP is used. Define sets the 
current limitation duration to 10ms before Vaux regulator is switched off. Default 
configuration is set to 50ms if commented out.*/
#define Taux_lim_off_10ms 

/*! \brief Define Vaux_trk_EN to configure Vaux regulator as a tracker. Default configuration is set
to no tracking(HW configuration is used) if commented out.*/
#define Vaux_trk_EN 

/*! \brief The Vcan is a linear voltage regulator fully dedicated to the embedded HSCAN interface.
Define Vcan_DIS to disable the Vcan Control. Default configuration is enabled if the define 
is commented out.*/
#define Vcan_DIS 

/*! \brief  Configure CAN interface
The built-in enhanced high speed CAN interface fulfills the ISO11898-2 and -5 standards. 
Local and bus failure diagnostics, protection and fail safe operation mode are provided. 
The HSCAN exhibits also wakeup capability with a very low current consumption.
The CAN wake up mechanism can be defined as signle dominant pulse. If commented out, the
default configuration which is 3 dominant pulses shall be used.*/
#define CAN_WU_Single_Dominant_Pulse 

/*! \brief Define sets the CAN block to be compliant with TOYOTA specification. If commented out, the 
standard CAN shall be used.*/
#define CAN_TOY 

/*! \brief Define sets the CAN wake-up time-out to be 360µs. If define is commented out, the default
time 120µs shall be used.*/
#define CAN_WU_360 

/*! \brief Only one of these modes shall be defined. If more or non are defined, the default configuration 
shall be CAN_MODE_Sleep_No_Wakeup*/
/*#define CAN_MODE_Sleep_No_Wakeup*/ 
/*#define CAN_MODE_Listen_Only*/ 
/*#define CAN_MODE_Sleep_Wakeup*/ 
#define CAN_MODE_Normal 

/*! \brief Define CAN_No_auto_dis to disable the Reset CAN_mode from “Normal operation mode” to “LISTEN ONLY” 
on CAN over temp or TXD dominant or RXD recessive event. Comment out for default setting wgich is auto 
disable*/
#define CAN_No_auto_dis 

/*! \brief Define Vcan_OV_Mon to enable overvoltage monitoring. In case of OV the Vcan regulator is switched OFF.
If commented out, Vcan OV is not monitored. Flag is ignored.*/
#define Vcan_OV_Mon 

/*! \brief  Configure watchdog
Configure the watchdog window duration. Duty cycle if set to 50%. Only one define shall be set. 
The watchdog may also be disabled if WD_Disable is defined. If more or none are set, the default of 3ms 
shall be used. Define WD_xms and replace x with the allowed cycle times
(2,3,4,6,8,12,16,24,32,64,128,256,512,1024ms)*/
#define WD_Disable 
/*#define WD_xms*/ 

/*! \brief Configure the maximum value of the Watchdog error counter by replacing x with either of the following 
values: 2, 4 or 6. Default value is 6 in case none is defined*/
#define WD__ERR_CNT_x 

/*! \brief Configure the maximum value of the Watchdog refresh counter by replacing x with either of the following 
values: 1, 4 or 6. Default value is 6 in case none is defined*/
#define WD__REF_CNT_x 

/*! \brief  Configure the Fail Safe State Machine
Define IO_01_FS to configure the couple of IO_1:0 as safety inputs. Default value if commented out is
NOT SAFETY RELEVANT*/
/*#define IO_01_FS*/ 

/*! \brief Define IO_45_FS to configure the couple of IO_5:4 as safety inputs.*/
/*#define IO_45_FS*/ 

/*! \brief Define IO_45_FS to configure the couple of IO_5:4 as NOT SAFETY RELEVANT. Neccessary to satisfy secure
bits*/
#define IO_45_NOT_FS 

/*! \brief Define Rstb_low_1ms to set the Rstb LOW duration time to 1ms.*/
/*#define Rstb_low_1ms*/ 

/*! \brief Define Rstb_low_1ms to set the Rstb LOW duration time to 10ms.*/
#define Rstb_low_10ms 

/*! \brief Define IO_23_FS to configure the couple of IO_3:2 as safety inputs for FCCU monitoring. If 
commented out, the default value is NOT SAFETY CRITICAL*/
/*#define IO_23_FS*/

/*! \brief Define RSTb_err_FS_1 to configure the values of the RSTb error counter to be the following:
intermediate=1; final=2. If commented out, the default values intermediate=3; final=6 shall be used.*/ 
/*#define RSTb_err_FS_1*/

/*! \brief Define Fccu_eaout_active_LOW to configure the FCCU polarity to be active LOW or active HIGH.*/
/*#define Fccu_eaout_active_LOW*/ 
#define Fccu_eaout_active_HIGH 

/*! \brief Define F_FS1 to set this bit as described in KT33907_8AEUG User’s Guide Rev. 2.0 32014.pdf pg.22*/
/*#define F_FS1*/
#define NOT_F_FS1

/*! \brief Define FSSM_Vcore_OV to configure Vcore overvoltage to have an impact on RSTb and FSxx.*/
#define FSSM_Vcore_OV 

/*! \brief Define FSSM_Vcore_UV_RSTb to configure Vcore undervoltage to have an impact on RSTb only. If this define
is set, Vcore overvoltage will be set to have an impact on RSTb and FSxx by default. 
Define FSSM_Vcore_UV_RSTb_FSxx to configure Vcore undervoltage to have an impact on RSTb and FSxx. This 
define will also set Vcore overvoltage to have an impact on RSTb and FSxx by default.*/

/*#define FSSM_Vcore_UV_RSTb*/ 
/*#define FSSM_Vcore_UV_RSTb_FSxx*/ 

/*! \brief Define FSSM_Vcca_OV to configure Vcca overvoltage to have an impact on RSTb and FSxx.*/
#define FSSM_Vcca_OV 

/*! \brief Define FSSM_Vcca_UV_RSTb to configure Vcca undervoltage to have an impact on RSTb only. If this define
is set, Vcca overvoltage will be set to have an impact on RSTb and FSxx by default. 
Define FSSM_Vcca_UV_RSTb_FSxx to configure Vcca undervoltage to have an impact on RSTb and FSxx. This 
define will also set Vcca overvoltage to have an impact on RSTb and FSxx by default.*/

/*#define FSSM_Vcca_UV_RSTb*/ 
/*#define FSSM_Vcca_UV_RSTb_FSxx*/ 

/*! \brief Define FSSM_Vcca_No_Effect to configure Vcca to have no impact on RSTb and FSxx.
must be defined explicitly to satisfy secure bits*/
/*#define FSSM_Vcca_No_Effect*/ 

/*! \brief Define FSSM_Vaux_OV to configure Vaux overvoltage to have an impact on RSTb and FSxx.*/
#define FSSM_Vaux_OV 

/*! \brief Define FSSM_Vaux_UV_RSTb to configure Vaux undervoltage to have an impact on RSTb only. If this define
is set, Vaux overvoltage will be set to have an impact on RSTb and FSxx by default. 
Define FSSM_Vaux_UV_RSTb_FSxx to configure Vaux undervoltage to have an impact on RSTb and FSxx. This 
define will also set Vaux overvoltage to have an impact on RSTb and FSxx by default.*/
#define FSSM_Vaux_UV_RSTb 
#define FSSM_Vaux_UV_RSTb_FSxx 

/*! \brief Define DIS_8s to disable the 8s timer used to enter Deep FAILSAFE mode. Default is enabled.*/
#define DIS_8s 

/*! \brief  Enable timer must be defined explicitly to satisfy secure bits*/
/*#define En_8s*/ 

/*! \brief Define Vcore_uv_D to configure the Vcore undervoltage in degraded mode. Only valid for 5V. If commented
out, the undervoltage detection threshold is in normal 5V mode.*/
#define Vcore_uv_D 

/*! \brief Define Vcca_uv_D to configure the Vcca undervoltage in degraded mode. Only valid for 5V. If commented
out, the undervoltage detection threshold is in normal 5V mode.*/
#define Vcca_uv_D 

/*! \brief Define Vaux_uv_D to configure the Vaux undervoltage in degraded mode. Only valid for 5V. If commented
out, the undervoltage detection threshold is in normal 5V mode but the next define must be set to 
satisfy secure bits*/
#define Vaux_uv_D 

/*! \brief The undervoltage detection threshold is in normal 5V mode*/
/*#define Vaux_uv_5V*/ 

/*! \brief  Configure the hardware inputs and outputs
Define the wake up configuration for IO_0. The wake up can be disabled, set on rising edge only, 
falling edge only or any edge.*/
#define IO_0_No_Wakeup 
/*#define IO_0_Rising_Edge*/ 
/*#define IO_0_Falling_Edge*/ 
/*#define IO_0_Any_Edge*/ 

/*! \brief Define the wake up configuration for IO_1. The wake up can be disabled, set on rising edge only, 
falling edge only or any edge.*/
#define IO_1_No_Wakeup 
/*#define IO_1_Rising_Edge*/ 
/*#define IO_1_Falling_Edge*/ 
/*#define IO_1_Any_Edge*/ 

/*! \brief Define the wake up configuration for IO_2. The wake up can be disabled, set on rising edge only, 
falling edge only or any edge.*/
#define IO_2_No_Wakeup 
/*#define IO_2_Rising_Edge*/ 
/*#define IO_2_Falling_Edge*/ 
/*#define IO_2_Any_Edge*/ 

/*! \brief Define INT_inh_IO_1_masked to inhibit the INT pulse for IO_1. IO_1 masked in IO_G. Avoid INT when 
used in FS. Default is set to INT not masked*/
#define INT_inh_IO_1_masked 

/*! \brief Define INT_inh_IO_0_masked to inhibit the INT pulse for IO_0. IO_0 masked in IO_G. Avoid INT when 
used in FS. Default is set to INT not masked*/
#define INT_inh_IO_0_masked 

/*! \brief Define the wake up configuration for IO_3. The wake up can be disabled, set on rising edge only, 
falling edge only or any edge.*/
#define IO_3_No_Wakeup 
/*#define IO_3_Rising_Edge*/ 
/*#define IO_3_Falling_Edge*/ 
/*#define IO_3_Any_Edge*/ 

/*! \brief Define the wake up configuration for IO_4. The wake up can be disabled, set on rising edge only, 
falling edge only or any edge.*/
#define IO_4_No_Wakeup
/*#define IO_4_Rising_Edge*/ 
/*#define IO_4_Falling_Edge*/ 
/*#define IO_4_Any_Edge*/ 

/*! \brief Define the wake up configuration for IO_5. The wake up can be disabled, set on rising edge only, 
falling edge only or any edge.*/
#define IO_5_No_Wakeup 
/*#define IO_5_Rising_Edge*/ 
/*#define IO_5_Falling_Edge*/ 
/*#define IO_5_Any_Edge*/ 

/*! \brief Define INT_inh_IO_45_masked to inhibit the INT pulse for IO_4 and IO_5. IO_4 and IO_5 masked in IO_G. Avoid INT when 
used in FS. Default is set to INT not masked*/
#define INT_inh_IO_45_masked 

/*! \brief Define INT_inh_IO_23_masked to inhibit the INT pulse for IO_2 and IO_3. IO_2 and IO_3 masked in IO_G. Avoid INT when 
used in FS. Default is set to INT not masked*/
#define INT_inh_IO_23_masked 

/*! \brief  Configure the interrupts 
Define INT_duration_25 to set the duration of the interrupt pulse to 25µs. Default value is 100µs*/
#define INT_duration_25 

/*! \brief Define INT_inh_all to inhibit all interrupt sources.*/
#define INT_inh_all 

/*! \brief Define INT_inh_Vsns to Inhibit the interrupt for VSNS_UV. Inhibit VSNS_UV*/
#define INT_inh_Vsns 

/*! \brief Define INT_inh_Vpre to inhibit the interrupt for Vpre status event (cf. register status Vreg1).
Vpre status changed INHIBITED*/
#define INT_inh_Vpre 

/*! \brief Define INT_inh_Vcore to inhibit the interrupt for Vcore status event (cf. register status Vreg2).
Vcore status changed INHIBITED*/
#define INT_inh_Vcore 

/*! \brief Define INT_inh_Vothers to inhibit the interrupt for VCCA / VAUX and VCAN status event (cf. register status Vreg2).
VCCA / VAUX / VCAN status changed INHIBITED*/
#define INT_inh_Vothers
