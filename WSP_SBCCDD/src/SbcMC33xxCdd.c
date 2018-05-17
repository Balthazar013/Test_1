
/*----------------------------------------------------------------------------
** Project Name:CAR_36_Wayside
** #Archive: WsSbcCddSwc.c #
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
** RBOGENFU   Reiner Bogenfuerst    Bombardier Transportation
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log: #
**--------------------------------------------------------------------------*/

#include "Rte_SbcMC33xxCdd.h"
#define _SBCMC33XXCDD_C_
#include "SbcMC33xxCdd.h"
#include "SbcMC33xxCdd_cfg.h"
#include "Spi.h"
#include "Dio.h"
#include "Os.h"
#include "EcuM_Cbk.h"
#include "os_api.h"
#include "dem.h"


/* The task starts the first time 30ms after power on and is then called every 10ms. Is the SBC
   ready to init the SbcMC33xxCdd_Init is called and the task will stopped.
*/
TASK(SBC_Init_Task)
{
  Std_ReturnType status = E_NOT_OK;
  uint8 SBC_ready = 0;
  
  status = read_sbc(READ_INIT_VREG2, &SBC_ready);
  
  if(0 != SBC_ready)
  {
    SbcMC33xxCdd_Init();
	flag = 0xDC;
    SbcMC33xxCdd_SetCanMode(NormalModeAutoDis);
    CancelAlarm(AlarmSBCInit);
  }

  (void)TerminateTask();
}


/*------------------------[runnable entity skeletons]------------------------*/
/*! \brief Description: This API shall be called by the application to 
initialize the HW registers used by the SBC.

Name and template: void SbcH_Init(void);

 * Functionality:
 *  -#  Init function shall call write_sbc() to initialize VREGx and HW config 
 * registers
 *  -#  Init function shall call write_sbc() to setup SURPERVISOR mode 
 * register.
 *  -#  Init function shall call write_sbc() to setup INIT SURPERVISOR 1 and 2 
 * mode registers.
 *  -#  Init function shall call write_sbc() to initialize WDG, IOs and CAN if 
 * these features are configured.
 *  -#  Init function shall call write_sbc() to initialize WDG_FLSR if WDG 
 * feature is configured.
 *  -#  Init function shall call write_sbc() to initialize WD WINDOW if WDG 
 * feature is configured.
 *  -#  Init function shall call write_sbc() to trigger WDG once, if this 
 * feature was enabled by configuration.
 *  -#  Init function shall call write_sbc() to clear INIT INT register 
 * (interrupts from SBC are not supported for the first phase)
 *  -#  Init function shall test the SPI_FS_xxx information bits and if an 
 * error is detected, the corresponding error shall be marked in the global 
 * diagnostic array (see Table 3 – Errors 36 .. 39)
 *  -#  Init function shall not be called if the SBC is in NORMAL mode or any 
 * of the SLEEP modes.
 */
void SbcMC33xxCdd_Init (void)
{

	uint8_t writeData = 0;   
	uint8 triggerConditionOutput;
	uint8 u8Temp = 0;
	Std_ReturnType status = E_NOT_OK;
	
/**---------------------------------------------------------------------------
**                       INIT_VREG1
**  Refer to page 55 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef Vpre_DIS
    writeData = writeData | Set_Vpre_DIS_Bit;
#endif
#ifdef IPFF_DIS
    writeData = writeData | Set_IPFF_DIS_Bit;
#endif
    write_sbc( WRITE_INIT_VREG1, writeData);    
/**---------------------------------------------------------------------------
**                       INIT_VREG2
**  Refer to page 56 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef Tcca_lim_off_50ms
    writeData = writeData | Set_Tcca_lim_off_50ms;
#endif
#ifdef Icca_lim_out
    writeData = writeData | Set_Icca_lim_out;
#endif
    write_sbc( WRITE_INIT_VREG2, writeData);
/**---------------------------------------------------------------------------
**                       INIT_CAN
**  Refer to page 56 & 57 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef CAN_WU_Single_Dominant_Pulse
    writeData = writeData | Set_CAN_WU_Single_Dominant_Pulse;
#endif  
#ifdef  CAN_TOY
    writeData = writeData | Set_CAN_TOY;
#endif  
#ifdef  CAN_WU_360
    writeData = writeData | Set_CAN_WU_360;
#endif    
    write_sbc( WRITE_INIT_CAN, writeData);
/**---------------------------------------------------------------------------
**                       INIT_IO_WU1
**  Refer to page 58 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef  IO_0_No_Wakeup
    writeData = writeData | Set_IO_0_No_WU;
#endif
#ifdef  IO_0_Rising_Edge
    writeData = writeData | Set_IO_0_Rising_WU;
#endif
#ifdef  IO_0_Falling_Edge
    writeData = writeData | Set_IO_0_Falling_WU;
#endif
#ifdef  IO_0_Any_Edge
    writeData = writeData | Set_IO_0_Any_WU;
#endif
#ifdef  IO_1_No_Wakeup
    writeData = writeData | Set_IO_1_No_WU;
#endif
#ifdef  IO_1_Rising_Edge
    writeData = writeData | Set_IO_1_Rising_WU;
#endif
#ifdef  IO_1_Falling_Edge
    writeData = writeData | Set_IO_1_Falling_WU;
#endif
#ifdef  IO_1_Any_Edge
    writeData = writeData | Set_IO_1_Any_WU;
#endif
#ifdef  IO_2_No_Wakeup
    writeData = writeData | Set_IO_2_No_WU;
#endif
#ifdef  IO_2_Rising_Edge
    writeData = writeData | Set_IO_2_Rising_WU;
#endif
#ifdef  IO_2_Falling_Edge
    writeData = writeData | Set_IO_2_Falling_WU;
#endif
#ifdef  IO_2_Any_Edge
    writeData = writeData | Set_IO_2_Any_WU;
#endif
#ifdef  INT_inh_IO_1_masked
    writeData = writeData | Set_INT_inh_IO_1_masked;
#endif
#ifdef  INT_inh_IO_0_masked
    writeData = writeData | Set_INT_inh_IO_0_masked;
#endif
    write_sbc( WRITE_INIT_IO_WU1, writeData);
/**---------------------------------------------------------------------------
**                       INIT_IO_WU2
**  Refer to page 59 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef  IO_3_No_Wakeup
    writeData = writeData | Set_IO_3_No_WU;
#endif
#ifdef  IO_3_Rising_Edge
    writeData = writeData | Set_IO_3_Rising_WU;
#endif
#ifdef  IO_3_Falling_Edge
    writeData = writeData | Set_IO_3_Falling_WU;
#endif
#ifdef  IO_3_Any_Edge
    writeData = writeData | Set_IO_3_Any_WU;
#endif
#ifdef  IO_4_No_Wakeup
    writeData = writeData | Set_IO_4_No_WU;
#endif
#ifdef  IO_4_Rising_Edge
    writeData = writeData | Set_IO_4_Rising_WU;
#endif
#ifdef  IO_4_Falling_Edge
    writeData = writeData | Set_IO_4_Falling_WU;
#endif
#ifdef  IO_4_Any_Edge
    writeData = writeData | Set_IO_4_Any_WU;
#endif
#ifdef  IO_5_No_Wakeup
    writeData = writeData | Set_IO_5_No_WU;
#endif
#ifdef  IO_5_Rising_Edge
    writeData = writeData | Set_IO_5_Rising_WU;
#endif
#ifdef  IO_5_Falling_Edge
    writeData = writeData | Set_IO_5_Falling_WU;
#endif
#ifdef  IO_5_Any_Edge
    writeData = writeData | Set_IO_5_Any_WU;
#endif
#ifdef  INT_inh_IO_45_masked
    writeData = writeData | Set_INT_inh_IO_45_masked;
#endif
#ifdef  INT_inh_IO_23_masked
    writeData = writeData | Set_INT_inh_IO_23_masked;
#endif
    write_sbc( WRITE_INIT_IO_WU2, writeData);
/**---------------------------------------------------------------------------
**                       INIT_Supervisor1
**  Refer to page 78 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef  FSSM_Vcore_OV
    writeData = writeData | Set_FSSM_Vcore_OV;
#endif
#ifdef  FSSM_Vcore_UV_RSTb
    writeData = writeData | Set_FSSM_Vcore_UV_RSTb;
#endif
#ifdef  FSSM_Vcore_UV_RSTb_FSxx
    writeData = writeData | Set_FSSM_Vcore_UV_RSTb_FSxx;
#endif
#ifdef  FSSM_Vcca_OV
    writeData = writeData | Set_FSSM_Vcca_OV;
#endif
#ifdef  FSSM_Vcca_UV_RSTb
    writeData = writeData | Set_FSSM_Vcca_UV_RSTb;
#endif
#ifdef  FSSM_Vcca_UV_RSTb_FSxx
    writeData = writeData | Set_FSSM_Vcca_UV_RSTb_FSxx;
#endif
#ifdef  FSSM_Vcca_No_Effect
    writeData = writeData | Set_FSSM_Vcca_No_Effect;
#endif
    write_sbc( WRITE_INIT_SUPERVISOR1, writeData);
/**---------------------------------------------------------------------------
**                       INIT_Supervisor2
**  Refer to page 80 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef  FSSM_Vaux_OV
    writeData = writeData | Set_FSSM_Vaux_OV;
#endif
#ifdef  FSSM_Vaux_UV_RSTb
    writeData = writeData | Set_FSSM_Vaux_UV_RSTb;
#endif
#ifdef  FSSM_Vaux_UV_RSTb_FSxx
    writeData = writeData | Set_FSSM_Vaux_UV_RSTb_FSxx;
#endif
#ifdef  DIS_8s
    writeData = writeData | Set_DIS_8s;
#endif
#ifdef  En_8s
    writeData = writeData | Set_En_8s;
#endif
    write_sbc( WRITE_INIT_SUPERVISOR2, writeData);
/**---------------------------------------------------------------------------
**                       INIT_Supervisor3
**  Refer to page 82 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef  Vcore_uv_D
    writeData = writeData | Set_Vcore_uv_D;
#endif
#ifdef  Vcca_uv_D
    writeData = writeData | Set_Vcca_uv_D;
#endif
#ifdef  Vaux_uv_D
    writeData = writeData | Set_Vaux_uv_D;
#endif
#ifdef  Vaux_uv_5V
    writeData = writeData | Set_Vaux_uv_5V;
#endif
    write_sbc( WRITE_INIT_SUPERVISOR3, writeData);
/**---------------------------------------------------------------------------
**                       INIT_FSSM1
**  Refer to page 84 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef  IO_01_FS
    writeData = writeData | Set_IO_01_FS;
#endif
#ifdef  IO_45_FS
    writeData = writeData | Set_IO_45_FS;
#endif
#ifdef  IO_45_NOT_FS
    writeData = writeData | Set_IO_45_NOT_FS;
#endif
#ifdef  Rstb_low_1ms
    writeData = writeData | Set_Rstb_low_1ms;
#endif
#ifdef  Rstb_low_10ms
    writeData = writeData | Set_Rstb_low_10ms;
#endif
    write_sbc( WRITE_INIT_FSM1, writeData);
/**---------------------------------------------------------------------------
**                       INIT_FSSM2
**  Refer to page 86 of System Basis Chip_MC33907_8_Datasheet.pdf
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef  IO_23_FS
    writeData = writeData | Set_IO_23_FS;
#endif
#ifdef  RSTb_err_FS_1
    writeData = writeData | Set_RSTb_err_FS_1;
#endif
#ifdef  Fccu_eaout_active_LOW
    writeData = writeData | Set_Fccu_eaout_active_LOW;
#endif
#ifdef  Fccu_eaout_active_HIGH
    writeData = writeData | Set_Fccu_eaout_active_HIGH;
#endif
#ifdef  F_FS1
    writeData = writeData | Set_F_FS1;
#endif
#ifdef  NOT_F_FS1
    writeData = writeData | Not_F_FS1;
#endif

/*write_sbc( WRITE_INIT_FSM2, writeData);*/
  write_sbc( WRITE_INIT_FSM2, 0x0C);
/*****************************************************************************/ 
  write_sbc(WRITE_INIT_WD, 0x0C); /*Set default values*/

  SbcMC33xxCdd_WdgSetMode(WDGIF_SLOW_MODE);  //WDGIF_SLOW_MODE
  /*SbcH_WdgSetMode(WDGIF_OFF_MODE);*/
  SbcMC33xxCdd_WdgSetTriggerCondition(0xB2, &triggerConditionOutput);
/*****************************************************************************/ 
/**---------------------------------------------------------------------------
**                       INIT_INT
**  Refer to page 30 & 60 of System Basis Chip_MC33907_8_Datasheet.pdf
**  After writing to this register, the system basic chip goes from init 
**  mode into normal mode. 
**---------------------------------------------------------------------------*/
    writeData = 0;
#ifdef INT_duration_25
    writeData = writeData | Set_INT_duration_25;
#endif
#ifdef INT_inh_all
    writeData = writeData | Set_INT_inh_all;
#endif    
#ifdef INT_inh_Vsns
    writeData = writeData | Set_INT_inh_Vsns;
#endif
#ifdef INT_inh_Vpre
    writeData = writeData | Set_INT_inh_Vpre;
#endif
#ifdef INT_inh_Vcore
    writeData = writeData | Set_INT_inh_Vcore;
#endif
#ifdef INT_inh_Vothers
    writeData = writeData | Set_INT_inh_Vothers;
#endif    
    /*write_sbc( WRITE_INIT_INT, writeData);*/  
    write_sbc( WRITE_INIT_INT, 0x00); 
}

void SbcMC33xxCdd_5ms (void)
{
	if(flag == 0xDC)
	{
	  Std_ReturnType status = E_NOT_OK;
	  uint8 WdgLfsrValue;
	  uint8 triggerConditionOutput;
	  static uint16_t counter = 0;
	  static uint16_t SPIerrorCounterGetWdgLfsr = 0;
	  static uint16_t SPIerrorCounterSetTrigger = 0;
  
  if((counter > 120) && (XCP_WDRESET == 0)) /*Wait 150ms-> 150/5*/ 
  {
		status = SbcMC33xxCdd_GetWdgLfsr (&WdgLfsrValue);
		if(status == E_NOT_OK)
		{
			SPIerrorCounterGetWdgLfsr++;
			return; //Return so counter will not be reset
		}
		SbcMC33xxCdd_ClearFsOutput(WdgLfsrValue);
		status = SbcMC33xxCdd_WdgSetTriggerCondition (WdgLfsrValue, &triggerConditionOutput);
		if(status == E_NOT_OK)
		{
			SPIerrorCounterSetTrigger++;
			return; //Return so counter will not be reset
		}
		counter = 0;    
	  }
	  else
	  {
		++counter;
	  } 
	}
}

void SbcMC33xxCdd_10ms (void)
{

}

void SbcMC33xxCdd_20ms (void)
{

}
/*! \brief Description: This API shall read the value of SBC IO pin configured 
through the logical “SbcChannelId” parameter. The function shall be called 
using the enums in the header file.

Name and template: uint8_t SbcH_ReadDigitalPin(uint8_t SbcChannelId);

Functionality:
* - This API shall return the logical HIGH or LOW of the SBC IO pin determined 
by “SbcChannelId” parameter.
* - This API shall use read_sbc() to request SBC to send the pin level 
by reading IO Input register (using the correct channel mask).
* - This function shall be called only if SBC is in NORMAL mode.

Note: All pins (IO_0:5) may be used as general purpose Inputs.

Call example: SbcH_ReadDigitalPin(SbcDigitalChannel_5);
*/
Std_ReturnType SbcMC33xxCdd_ReadDigitalPin (uint8 sbcChannelId, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pu8DigitalPinValue)
{
  Std_ReturnType status;
  uint8_t temp;
  status = E_OK;
  temp = 0;
  status = read_sbc(READ_IO, &temp);
  
  if( sbcChannelId == SbcDigitalChannel_5)
  {
    *pu8DigitalPinValue = ((temp & FltBit7) > 0)? 1:0;
  }
  else if( sbcChannelId == SbcDigitalChannel_4)
  {
    *pu8DigitalPinValue = ((temp & FltBit6) > 0)? 1:0;
  }
  else if( sbcChannelId == SbcDigitalChannel_3)
  {
    *pu8DigitalPinValue = ((temp & FltBit4) > 0)? 1:0;
  }
  else if( sbcChannelId == SbcDigitalChannel_2)
  {
    *pu8DigitalPinValue = ((temp & FltBit3) > 0)? 1:0;
  }
  else if( sbcChannelId == SbcDigitalChannel_1)
  {
    *pu8DigitalPinValue = ((temp & FltBit1) > 0)? 1:0;
  }
  else if( sbcChannelId == SbcDigitalChannel_0)
  {
    *pu8DigitalPinValue = ((temp & FltBit0) > 0)? 1:0;
  }

  return status;
}
/*! \brief Description: This API shall write the value of parameter “Level on 
the SBC IO pin configured through the logical “SbcChannelId” parameter.

Name and template: SbcMC33xxCdd_WriteDigitalPin (uint8 sbcChannelId, uint8 level);

Functionality:
* - This API shall write the logical HIGH or LOW on the SBC IO pin determined 
by “SbcChannelId” parameter. 
* - This API shall use write_sbc() to request SBC to update the pin level 
by writing IO_OUT-AMUX register (using the correct channel mask).
* - This function shall be called only if SBC is in NORMAL mode.

Note: Only pins IO_4:5 may be used as general purpose Outputs.

Call example: SbcMC33xxCdd_WriteDigitalPin(SbcDigitalChannel_4, HIGH);
*/
Std_ReturnType SbcMC33xxCdd_WriteDigitalPin (uint8 sbcChannelId, uint8 level)
{
  Std_ReturnType status = E_NOT_OK;
  uint8_t temp = 0;
  /*IOs are read from this register and not the read IO register to do the 
  masking*/
  status = read_sbc(READ_IO_OUT_AMUX, &temp); 
  switch (sbcChannelId)
  {
    case SbcDigitalChannel_4:   
      temp = temp & DigitalOut4; /*Mask out the digital 4*/
      if(level == HIGH)
      {
        /*Refer to datasheet page 75. IO_4 configured as output gate 
        driver. IO_4 output gate driver state HIGH.*/
        temp = temp | 0xC0;
      }
      else if(level == LOW)
      {
        /*Refer to datasheet page 75. IO_4 configured as output gate 
        driver. IO_4 output gate driver state LOW.*/
        temp = temp | 0x80;
      }
      else
      {
        return status;
      }
    break;
    case SbcDigitalChannel_5:
      temp = temp & DigitalOut5;
      if(level == HIGH)
      {
        /*Refer to datasheet page 75. IO_5 configured as output gate 
        driver. IO_5 output gate driver state HIGH.*/
        temp = temp | 0x30;
      }
      else if(level == LOW)
      {
        /*Refer to datasheet page 75. IO_5 configured as output gate 
        driver. IO_5 output gate driver state LOW.*/
        temp = temp | 0x20;
      }
      else
      {
        return status;
      }
    break;
    default:
      return status;
  }
  status = write_sbc( WRITE_IO, temp);
  return status;
}
/*! \brief Description: This API shall select a given MUX channel.

Name and template: Std_ReturnType SbcMC33xxCdd_SetMuxChannel (uint8 MuxChanId);

Functionality: This API shall use Spi_SyncTransmit() to request SBC to send the 
pin level by writing IO_OUT-AMUC register (using the correct mux channel mask). 
The following mux channel id's are available:
* - Vref
* - VsnsWideRange
* - IO_0WideRange
* - IO_1WideRange
* - VsnsTightRange
* - IO_0TightRange
* - IO_1TightRange
* - DieTempSens

Call example: SbcMC33xxCdd_SetMuxChannel(IO_0WideRange);
*/
Std_ReturnType SbcMC33xxCdd_SetMuxChannel (uint8 MuxChanId)
{
  Std_ReturnType status = E_NOT_OK;
  uint8_t temp;
  temp = 0;
  status = read_sbc(READ_IO_OUT_AMUX, &temp);
  temp = Delete_AMUX & temp;
  temp = MuxChanId | temp;
  status = write_sbc( WRITE_IO, temp);
  return status;
}
/*! \brief Description: This API shall be used to (re)configure CAN 
functionality of the SBC at run-time.

Name and template: Std_ReturnType SbcH_SetCanMode(int CanMode);

Functionality: Functionality:
* - Depending on the Mode parameter the following options may be configured in 
the CAN Mode Register:
* -# SleepNoWakeUp
* -# ListenOnly
* -# SleepWakeUp
* -# NormalModeNoAutoDis
* -# NormalModeAutoDis
* -# NormalModeAutoDisVcanOVSup
* - If auto disable is set, the CAN MOde is changed from "Normal operation mode 
with auto disable" to "LISTEN ONLY" on on CAN over temp or TXD dominant or RXD 
recessive event.
* - Depending on the Mode parameter the following options may be configured in 
the CAN Mode 2 Register: VCAN overvoltage monitoring.
* - This function shall be called only if SBC is in NORMAL mode. 

Notes:
* - When the device is in Normal mode, the CAN mode bits cannot be read back by 
the SPI when the CAN transceiver is configured in Low Power mode.
* - CAN mode is automatically configured to "Sleep / Wake-up capability" if 
CAN mode was different than "Sleep / NO wake up capability" before the 
device enters in LPOFF. After LPOFF, the initial CAN mode prior to enter LPOFF 
is restored.

Call example: SbcH_SetCanMode(NormalModeNoAutoDis);
*/
Std_ReturnType SbcMC33xxCdd_SetCanMode (uint8 canMode)
{
    Std_ReturnType status = E_NOT_OK;
  switch(canMode)
  {
  case SleepNoWakeUp:
    status = write_sbc( WRITE_CAN_MODE, Set_CanMode_SleepNoWakeup);
  break;
  case ListenOnly:
    status = write_sbc( WRITE_CAN_MODE, Set_CanMode_ListenOnly);
  break;
  case SleepWakeUp:
    status = write_sbc( WRITE_CAN_MODE, Set_CanMode_SleepWakeUp);
  break;
  case NormalModeNoAutoDis:
    status = write_sbc( WRITE_CAN_MODE, Set_CanMode_NormalOpNoAutoDis);
  break;
  case NormalModeAutoDis:
    status = write_sbc( WRITE_CAN_MODE, Set_CanMode_NormalOpAutoDis);
  break;
  case NormalModeAutoDisVcanOVSup:
    status = write_sbc( WRITE_CAN_MODE, Set_CanMode_NormalOpAutoDis);
    status = write_sbc( WRITE_CAN_MODE2, Set_VcanOV_Mon);
  break;
  default:
    return status;
  }
  return status;
}
/*! \brief Description: This API shall be used to set the watchdog mode 
(ASR type).

Name and template: SbcMC33xxCdd_WdgSetMode (uint8 mode);

Functionality: Depending on the Mode parameter the following run-modes may be 
used: WDGIF_OFF_MODE, WDGIF_SLOW_MODE, WDGIF_FAST_MODE. The run-modes properties 
are staticaly defined in the configuration.
* - WDGIF_OFF_MODE: Watchdog is disabled.
* - WDGIF_SLOW_MODE: Watchdog must be refreshed every 1024 ms
* - WDGIF_FAST_MODE: Watchdog must be refreshed every 1 ms

Call example: SbcMC33xxCdd_WdgSetMode(WDGIF_FAST_MODE);
*/
Std_ReturnType SbcMC33xxCdd_WdgSetMode (uint8 mode)
{
    Std_ReturnType status = E_NOT_OK;
  uint8_t temp;
  switch(mode)
  {
  case WDGIF_OFF_MODE:
    status = write_sbc( WRITE_WD_WINDOW, Set_WDGIF_OFF_MODE);
    status = read_sbc(READ_WD_WINDOW, &temp);
    if(temp != 0x00)
    {
      status = E_NOT_OK;
      return status;
    }
  break;
  case WDGIF_SLOW_MODE:
    status = write_sbc( WRITE_WD_WINDOW, Set_WDGIF_SLOW_MODE);
    status = read_sbc(READ_WD_WINDOW, &temp);
    if(temp != 0x0D)
    {
      status = E_NOT_OK;
      return status;
    }
  break;
  case WDGIF_FAST_MODE:
    status = write_sbc( WRITE_WD_WINDOW, Set_WDGIF_FAST_MODE);
    status = read_sbc(READ_WD_WINDOW, &temp);
    if(temp != 0x01)
    {
      status = E_NOT_OK;
      return status;
    }
  break;
  default:
    return status;
  }
  return status;
}
/*! \brief Description: This API shall be used to get from the WD_LFSR 
register the current value of the seed byte.

Name and template: Std_ReturnType SbcMC33xxCdd_GetWdgLfsr (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) WdgLfsrValue);

Functionality: This API shall return the 8 bit value read by calling read_sbc() 
for WD_LFSR register.

Call example: SbcMC33xxCdd_GetWdgLfsr (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) WdgLfsrValue);
*/
Std_ReturnType SbcMC33xxCdd_GetWdgLfsr (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) WdgLfsrValue)
{
  Std_ReturnType status;
  status = E_NOT_OK;

  status = read_sbc(READ_WD_LFSR, WdgLfsrValue);

  return status;
}
/*! \brief Description: This API shall be used to reset the WD Counter 
preventing an assertion of the RST line.

Name and template: uint8_t WdgSetTriggerCondition(uint8_t u8LfsrByte);

Functionality: 
* - This API shall send the WD reset answer by calling write_sbc() for 
WD_ANSWER register.
* - The WD answer is calculated from u8LfsrByte using the following formula:
Answer = (NOT(((LFSR x 4)+6)-4))/4 see datasheet page 91

Note: For every successful WD reset the SBC HW increments the LFSR by 1. This 
means that the application should take this effect into consideration when 
selecting the value for the u8LfsrByte, thus, SbcH_GetWdgLfsr()should be called 
first, before calling SbcH_WdgSetTriggerCondition().

Call example: WdgSetTriggerCondition(u8LfsrByte);
*/
Std_ReturnType SbcMC33xxCdd_WdgSetTriggerCondition (uint8 lfsrByte, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) triggerConditionOutput)
{
  Std_ReturnType status;
    uint16_t temp;
  uint8_t answer;
  status = E_OK;
  temp = 0;
  temp = (uint16_t) lfsrByte;
  temp = temp << 2;
  temp = temp + 6;
  temp = temp -4;
  temp = ~temp;
  temp = temp >> 2;
  answer = (uint8_t) temp;
  status = write_sbc( WRITE_WD_ANSWER, answer);  
  
  return status;
}
/*! \brief Description: This API shall be used to configure the device in Low 
Power mode (with disabled Voltage regulator – Vreg OFF)

Name and template: Std_ReturnType SbcH_LowPowerOff(void);

Functionality: This API shall request LPOFF by calling write_sbc() for MODE 
register and setting Goto_LPOFF bit. This function shall return E_NOT_OK if 
any SPI communication issue is reported or if the request is done while SBC is 
not in NORMAL mode.

Reset condition: Power On Reset

Call example: SbcH_LowPowerOff();
*/
Std_ReturnType SbcMC33xxCdd_SetLowPowerOff (void)
{
  Std_ReturnType status = E_NOT_OK;
  status = write_sbc( WRITE_MODE, Set_LPOFF);
  return status;
}
/*! \brief Description: This API shall be used to assert, on user demand, the 
RSTB line.

Name and template: Std_ReturnType SbcH_RequestReset();

Functionality: This API shall request an assertion of RSTB by calling 
write_sbc() for RSTB REQUEST register and setting RSTb_request bit. 
This function shall return E_NOT_OK if any SPI communication issue is reported.

Reset condition: Power On Reset / When RSTb done
*/
Std_ReturnType SbcMC33xxCdd_RequestReset (void)
{
  Std_ReturnType status = E_NOT_OK;
  status = write_sbc( WRITE_RSTb_request, Set_RSTb_request);
  return status;
}
/*! \brief Description: This API is used to clear the Fail Safe output which 
was activated after the error counter reached maximum value.

Name and template: Std_ReturnType SbcH_ClearFsOutput(uint8 u8LfsrByte);

Functionality: This API shall call write_sbc() and write the value of u8LfsrByte 
parameter to FS_OUT register.

Note: In order to successfully reset the SBC error counter several steps must be 
ensured.
* - Cause of error is no longer present
* - Watchdog was trigger successfully 7 times.
* - SbcH_ClearFsOutput() is called with negated value of the LSFR Word used for 
triggering the WDG.

Call example: SbcH_ClearFsOutput(u8LfsrByte);
*/
Std_ReturnType SbcMC33xxCdd_ClearFsOutput (uint8 lfsrByte)
{
  Std_ReturnType status = E_NOT_OK;
  lfsrByte = ByteSwap(lfsrByte);
  status = write_sbc( WRITE_FS_OUT, ~lfsrByte); 
  return status;
}
/*! \brief Description: This API shall be called by application to read the 
current configuration of the SBC. This feature may be necessary if HW 
reconfiguration is done via servicing the ECU.

Name and template: void SbcH_GetHwInfo(uint8_t HwConfigInfo[1]);

Functionality: The following information shall be read from HW and written in 
HwConfigInfo parameter:
* -   Bit0 High:  DEBUG mode selected
* -   Bit0 Low: Normal operation  
* -   Bit3 High:  Hardware configuration for Vaux is 3.3V
* -   Bit3 Low: Hardware configuration for Vaux is 5V
* -   Bit4 High:  Hardware configuration for Vcca is 5V
* -   Bit4 Low: Hardware configuration for Vcca is 3.3V
* -   Bit5 High:  Internal MOSFET
* -   Bit5 Low: External PNP connected
* -   Bit6 High:  Vaux is not used
* -   Bit6 Low: Vaux is used (external PNP is assumed to be connected, 
      Vaux can be switched OFF/ON through SPI)
* -   Bit7 High:  Buck only
* -   Bit7 Low: Buck-Boost

page 61 of of System Basis Chip_MC33907_8_Datasheet.pdf
*/
Std_ReturnType SbcMC33xxCdd_GetHwInfo (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) hwConfigInfoOutput)
{
  Std_ReturnType status;
  status = read_sbc(READ_HW_CONF, hwConfigInfoOutput);
  status = E_OK;
  return status;
}
/*! \brief Description: This API shall return the current operating mode of 
Sbc.

Name and template: Std_ReturnType SbcH_GetOpMode(uint8_t OpMode[1]);

Functionality:
* - This function shall call read_sbc() to read the MODE register and 
based of its value shall set the value of OpMode parameter to SBCH_NORMAL_MODE 
or SBCH_INIT_MODE and return with E_OK.
* - If bits 3 and 2 of MODE register are both “0”, this API shall set the value 
of OpMode parameter to SBCH_INVALID_MODE and return with E_NOT_OK.
* - The API shall return the value of OpMode to the caller.
*/
Std_ReturnType SbcMC33xxCdd_GetOpMode (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) opModeValue)
{
  Std_ReturnType status;
  uint8_t temp;
  status = read_sbc(READ_MODE, &temp);
  temp = temp & 0x0C;
  switch(temp)
  {
    case 8:
    status = E_OK;
    *opModeValue = SBCH_INIT_MODE;
    break;
    case 4:
    status = E_OK;
    *opModeValue = SBCH_NORMAL_MODE;
    break;
    default: 
    status = E_NOT_OK;
    *opModeValue = SBCH_INVALID_MODE;
  }
  return status;
}
/*! \brief Description: This API shall be used to request an interrupt pulse 
from the SBC.

Name and template: Std_ReturnType SbcH_RequestINT_Pulse(void);

Functionality: This API shall request an interrupt pulse by calling write_sbc() 
for MODE register and setting INT_request bit. This function shall return 
E_NOT_OK if any SPI communication issue is reported or if the request is done 
while SBC is not in NORMAL mode.

Reset condition: Power On Reset

Call example: SbcH_RequestINT_Pulse();
*/
Std_ReturnType SbcMC33xxCdd_RequestInt_Pulse (void)
{
  Std_ReturnType status;
  status = write_sbc( WRITE_MODE, Set_RequestINT_Pulse);  
  return status;
}
/*! \brief Description: FS0B is asserted low when a fault event occurs 
(See Faults Triggering FS0B Activation on page 42).The objective of this pin 
is to drive an electrical safe circuitry to deactivate the whole system and set 
the ECU in a protected and known state.

Name and template: Std_ReturnType SbcH_GetFS0bFaultEvent(uint8_t FaultEvent[1]);

Functionality: This API shall request the fault source which caused FS0B to be 
triggered.
The activation of the FS0B is clearly dependent on the product configuration, 
but the following items can be settled:
* - IO_01/IO_23/IO_45 error detection
* - Undervoltage
* - Overvoltage
* - Analog BIST fail (not configurable)
* - SPI DED (not configurable)
* - RSTB shorted to high (not configurable)
* - RSTB error counter level

Reset condition: Power On Reset

Call example: SbcH_GetFS0bFaultEvent(uint8_t FaultEvent[1]);
*/
Std_ReturnType SbcMC33xxCdd_GetFS0bFaultEvent (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) faultEventValue)
{
  uint8_t temp;
  uint8_t FaultEvent[1];
  Std_ReturnType status = E_NOT_OK;
  FaultEvent[0] = 0;
  status = read_sbc(READ_DIAG_FS1, &temp);
  /*If bit 7 is set, report an external RSTb by setting bit0 of 
  FaultEvent[0] */
  if((temp & FltBit7) > 0)
  {
    FaultEvent[0] = FaultEvent[0] | 0x01;
  }
  /*If bit 6 is set, report a RSTb short circuit to high by setting bit1 of 
  FaultEvent[0] */
  if((temp & FltBit6) > 0)
  {
    FaultEvent[0] = FaultEvent[0] | 0x02;
  }
  /*If bit 4 is set, report a FS0b short circuit to high by setting bit2 of 
  FaultEvent[0] */
  if((temp & FltBit4) > 0)
  {
    FaultEvent[0] = FaultEvent[0] | 0x04;
  }
  /*If bit 3 is set, report a FS0b short circuit to low by setting bit3 of 
  FaultEvent[0] */
  if((temp & FltBit3) > 0)
  {
    FaultEvent[0] = FaultEvent[0] | 0x08;
  }
  status = read_sbc(READ_DIAG_FS2, &temp);
  /*If bit 3 is set, report an error in the IO_45 protocol by setting bit4 
  of FaultEvent[0] */
  if((temp & FltBit3) > 0)
  {
    FaultEvent[0] = FaultEvent[0] | 0x10;
  }
  /*If bit 2 is set, report an error in the FCCU protocol by setting bit5 
  of FaultEvent[0] */
  if((temp & FltBit2) > 0)
  {
    FaultEvent[0] = FaultEvent[0] | 0x20;
  }
  /*If bit 0 is set, report an error in the IO_01 protocol by setting bit6 
  of FaultEvent[0] */
  if((temp & FltBit0) > 0)
  {
    FaultEvent[0] = FaultEvent[0] | 0x40;
  }
  *faultEventValue = FaultEvent[0];
  status = E_NOT_OK;
  return status;
}
/*! \brief Description: This function shall return the status of the interrupt
bits as described in page 98 of System Basis Chip_MC33907_8_Datasheet.pdf 

Functionality: This function shall be invoked by passing 
InterruptData as a pointer of type unsigned int8. The caller should define 
something like this: uint8_t InterruptData_SBC[7];
This function then fills the array with the interrupt code which is
specified in the integration manual.
*/
Std_ReturnType SbcMC33xxCdd_GetInterruptCode (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) interruptDataPtr)
{
  Std_ReturnType status;
  uint8_t temp;
  t_SBC_MC33907_Interrupt* SBC_MC33907_Interrupt;
  SBC_MC33907_Interrupt = (t_SBC_MC33907_Interrupt*) interruptDataPtr;
  
  status = read_sbc(READ_DIAG_VREG1, &temp);
  
/*[1]*/ SBC_MC33907_Interrupt->bits.VSNS_UV    = ((temp & FltBit7) > 0)? 1:0;
/*[2]*/ SBC_MC33907_Interrupt->bits.VSUP_UV_7  = ((temp & FltBit6) > 0)? 1:0;
    /*Bit 5 Tsd_pre has no interrupt bit to map to in Table 88: 
    Interruptions list of datasheet page 98*/                      
/*[3]*/ SBC_MC33907_Interrupt->bits.VPRE_OV    = ((temp & FltBit4) > 0)? 1:0;
/*[4]*/ SBC_MC33907_Interrupt->bits.VPRE_UV    = ((temp & FltBit3) > 0)? 1:0;
    /*Bit 5 Tsd_pre has no interrupt bit to map to in Table 88: 
    Interruptions list of datasheet page 98*/                        
/*[5]*/ SBC_MC33907_Interrupt->bits.VCORE_OV   = ((temp & FltBit1) > 0)? 1:0;
/*[6]*/ SBC_MC33907_Interrupt->bits.VCORE_UV   = ((temp & FltBit0) > 0)? 1:0;
    
  temp = 0;
  status = read_sbc(READ_DIAG_VREG2, &temp); 
    
/*[7]*/ SBC_MC33907_Interrupt->bits.TSDCAN     = ((temp & FltBit7) > 0)? 1:0;
/*[8]*/ SBC_MC33907_Interrupt->bits.VCAN_OV    = ((temp & FltBit6) > 0)? 1:0;
/*[9]*/ SBC_MC33907_Interrupt->bits.VCAN_UV    = ((temp & FltBit5) > 0)? 1:0;
    /*Bit 4 empty*/   
/*[10]*/SBC_MC33907_Interrupt->bits.TSDVAUX    = ((temp & FltBit3) > 0)? 1:0;
/*[11]*/SBC_MC33907_Interrupt->bits.ILIM_AUX_OFF = ((temp & FltBit2) > 0)? 1:0;
/*[12]*/SBC_MC33907_Interrupt->bits.VAUX_OV    = ((temp & FltBit1) > 0)? 1:0;
/*[13]*/SBC_MC33907_Interrupt->bits.VAUX_UV    = ((temp & FltBit0) > 0)? 1:0;
  
  temp = 0;
  status = read_sbc(READ_DIAG_VREG3, &temp); 
  
/*[14]*/SBC_MC33907_Interrupt->bits.TSDVCCA    = ((temp & FltBit7) > 0)? 1:0;
    /*Bit 6 empty*/
/*[15]*/SBC_MC33907_Interrupt->bits.ILIM_CCA_OFF = ((temp & FltBit5) > 0)? 1:0;
    /*Bit 4 empty*/   
/*[16]*/SBC_MC33907_Interrupt->bits.VCCA_OV    = ((temp & FltBit3) > 0)? 1:0;
    /*Bit 2 empty*/     
/*[17]*/SBC_MC33907_Interrupt->bits.VCCA_UV    = ((temp & FltBit1) > 0)? 1:0;
    /*Bit 0 empty*/
  
  temp = 0;
  status = read_sbc(READ_STATUS_VREG1, &temp); 
  
/*[18]*/SBC_MC33907_Interrupt->bits.IPFF     = ((temp & FltBit7) > 0)? 1:0;
/*[19]*/SBC_MC33907_Interrupt->bits.ILIM_PRE   = ((temp & FltBit6) > 0)? 1:0;
/*[20]*/SBC_MC33907_Interrupt->bits.TWARN_PRE  = ((temp & FltBit5) > 0)? 1:0;  
/*[21]*/SBC_MC33907_Interrupt->bits.BoB      = ((temp & FltBit4) > 0)? 1:0;
/*[22]*/SBC_MC33907_Interrupt->bits.VPRE_STATE   = ((temp & FltBit3) > 0)? 1:0;
    /*Bit 2 to 0 empty*/
  
  temp = 0;
  status = read_sbc(READ_STATUS_VREG2, &temp);

/*[23]*/SBC_MC33907_Interrupt->bits.ILIM_CORE  = ((temp & FltBit7) > 0)? 1:0;
/*[24]*/SBC_MC33907_Interrupt->bits.TWARN_CORE   = ((temp & FltBit6) > 0)? 1:0;
/*[25]*/SBC_MC33907_Interrupt->bits.VCORE_STATE  = ((temp & FltBit5) > 0)? 1:0;
/*[26]*/SBC_MC33907_Interrupt->bits.TWARN_CCA  = ((temp & FltBit4) > 0)? 1:0;
/*[27]*/SBC_MC33907_Interrupt->bits.ILIM_CCA   = ((temp & FltBit3) > 0)? 1:0;
/*[28]*/SBC_MC33907_Interrupt->bits.ILIM_AUX   = ((temp & FltBit2) > 0)? 1:0;
/*[29]*/SBC_MC33907_Interrupt->bits.ILIM_CAN   = ((temp & FltBit1) > 0)? 1:0;
  
  temp = 0;
  status = read_sbc(READ_WU_SOURCE, &temp);  
  
/*[30]*/SBC_MC33907_Interrupt->bits.IO_5_WU    = ((temp & FltBit7) > 0)? 1:0;
/*[31]*/SBC_MC33907_Interrupt->bits.IO_4_WU    = ((temp & FltBit6) > 0)? 1:0;
/*[32]*/SBC_MC33907_Interrupt->bits.IO_3_WU    = ((temp & FltBit5) > 0)? 1:0;
/*[33]*/SBC_MC33907_Interrupt->bits.IO_2_WU    = ((temp & FltBit4) > 0)? 1:0;
/*[34]*/SBC_MC33907_Interrupt->bits.IO_1_WU    = ((temp & FltBit3) > 0)? 1:0;
/*[35]*/SBC_MC33907_Interrupt->bits.IO_0_WU    = ((temp & FltBit2) > 0)? 1:0;
    /*Bit 1 described as Vreg_WU but unused. See datasheet for details.*/
/*[36]*/SBC_MC33907_Interrupt->bits.CAN_WU   = ((temp & FltBit0) > 0)? 1:0;
    
  temp = 0;
  status = read_sbc(READ_DIAG_CAN1, &temp);  
  
/*[37]*/SBC_MC33907_Interrupt->bits.CANHBATT   = ((temp & FltBit7) > 0)? 1:0;
/*[38]*/SBC_MC33907_Interrupt->bits.CANHGND    = ((temp & FltBit6) > 0)? 1:0;
/*[39]*/SBC_MC33907_Interrupt->bits.CANLBATT   = ((temp & FltBit5) > 0)? 1:0;
/*[40]*/SBC_MC33907_Interrupt->bits.CANLGND    = ((temp & FltBit4) > 0)? 1:0;
/*[41]*/SBC_MC33907_Interrupt->bits.CAN_dominant = ((temp & FltBit3) > 0)? 1:0;
    /*Bit 2 empty*/ 
/*[42]*/SBC_MC33907_Interrupt->bits.RXD_recessive= ((temp & FltBit1) > 0)? 1:0;
/*[43]*/SBC_MC33907_Interrupt->bits.TXD_dominant = ((temp & FltBit0) > 0)? 1:0;
  
  temp = 0;
  status = read_sbc(READ_DIAG_CAN2, &temp);  
  
      /*Bit 7 to bit 2 empty*/
/*[44]*/SBC_MC33907_Interrupt->bits.CAN_OT     = ((temp & FltBit1) > 0)? 1:0;
/*[45]*/SBC_MC33907_Interrupt->bits.CAN_OC   = ((temp & FltBit0) > 0)? 1:0;
  
  temp = 0;
  status = read_sbc(READ_SPI_DIAG, &temp); 
  
/*[46]*/SBC_MC33907_Interrupt->bits.SPI_err    = ((temp & FltBit7) > 0)? 1:0;
    /*Bit 6 empty*/ 
/*[47]*/SBC_MC33907_Interrupt->bits.SPI_CLK    = ((temp & FltBit5) > 0)? 1:0;
    /*Bit 4 empty*/ 
/*[48]*/SBC_MC33907_Interrupt->bits.SPI_Req    = ((temp & FltBit3) > 0)? 1:0;
    /*Bit 2 empty*/ 
/*[49]*/SBC_MC33907_Interrupt->bits.SPI_Parity   = ((temp & FltBit1) > 0)? 1:0;
    /*Bit 0 empty*/
  
/*[50]*/SBC_MC33907_Interrupt->bits.IO_0     = 0;
/*[51]*/SBC_MC33907_Interrupt->bits.IO_1     = 0;
/*[52]*/SBC_MC33907_Interrupt->bits.IO_2     = 0;
/*[53]*/SBC_MC33907_Interrupt->bits.IO_3     = 0;
/*[54]*/SBC_MC33907_Interrupt->bits.IO_4     = 0;
/*[55]*/SBC_MC33907_Interrupt->bits.IO_5     = 0;
/*[56]*//*INT_Request from MCU*/
    
  return status;
}
/*! \brief Description: This API shall be used to get the watchdog mode 
(ASR type).

Name and template: uint8_t SbcH_WdgGetMode();

Functionality: Depending on the Mode the following shall be returned: 
WDGIF_OFF_MODE, WDGIF_SLOW_MODE, WDGIF_FAST_MODE. The run-modes properties 
are staticaly defined in the configuration.
* - WDGIF_OFF_MODE: Watchdog is disabled.
* - WDGIF_SLOW_MODE: Watchdog must be refreshed every 1024 ms
* - WDGIF_FAST_MODE: Watchdog must be refreshed every 1 ms

Call example: SbcH_WdgSetMode(WDGIF_FAST_MODE);
*/
void SbcMC33xxCdd_WdgGetMode (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) wdgModeValue)
{
  Std_ReturnType status;
    uint8_t temp;
  status = read_sbc(READ_WD_WINDOW, &temp);
  temp = temp & 0x0F;
  if(temp == 0)
  {
    *wdgModeValue = WDGIF_OFF_MODE;
  }
  else if(temp == 0x0E)
  {
    *wdgModeValue = WDGIF_SLOW_MODE;
  }
  else if(temp == 0x01)
  {
    *wdgModeValue = WDGIF_FAST_MODE;
  }
  else *wdgModeValue = WDGIF_UNDEFINED_MODE;
}

void SbcMC33xxCdd_SbcStatusNotification (uint32 sbcStatus)
{
  Std_ReturnType status;

}

void OS_ISR_OsIsr_SbcInterrupt(void)
{
  EcuM_CheckWakeup(EcuM_MLBevo_HCAN);
}

/*! \brief Description: This API shall be used to swap a byte.

Name and template: uint8_t ByteSwap(uint8_t);

The return value is the swaped byte

Call example: ByteSwap(uint8_t);
*/
uint8_t ByteSwap(uint8_t byte_1)
{
  uint8_t byte_2 = 0;
  uint8_t temp = 0;
  
  temp   = (byte_1 & 0x80);
    byte_2 |= (temp >> 7);

    temp   = (byte_1 & 0x40);
    byte_2 |= (temp >> 5);

    temp   = (byte_1 & 0x20);
    byte_2 |= (temp >> 3);

    temp   = (byte_1 & 0x10);
    byte_2 |= (temp >> 1);

    temp   = (byte_1 & 0x08);
    byte_2 |= (temp << 1);

    temp   = (byte_1 & 0x04);
    byte_2 |= (temp << 3);

    temp   = (byte_1 & 0x02);
    byte_2 |= (temp << 5);

    temp   = (byte_1 & 0x01);
    byte_2 |= (temp << 7);
  
  return byte_2;  
}

/*! \brief Description: This function shall calculate the parity bit and write 
data to the SBC by using the standard AUTOSAR SPI function Spi_SyncTransmit(). 
This function is only for internal use inside the SBC Handler and not 
available in the API.

Name and template: 
uint8_t write_sbc( unsigned char RegisterAddress, uint8_t Data);

Functionality: 
* - This function shall receive the register ID of the SBC to 
which it shall write out the information and the data which shall be written
to the register.
* - This function shall return the buffer[1] value of the write sequence which
shall be handled depending on the register which was written to.
*/
Std_ReturnType write_sbc( unsigned char RegisterAddress, uint8_t Data)
{
  Std_ReturnType status = E_NOT_OK;
  unsigned char buffer[2];
  int val = 0;
  buffer[0] = 0;
  buffer[1] = 0;
  val =  RegisterAddress << 8; 
  val = val | Data;
  val ^= val >> 8; 
  val ^= val >> 4; 
  val ^= val >> 2; 
  val ^= val >> 1; 
  val = val & 1; 
  if (val == 0) /*val is 0 if parity is even*/
  {
    /*insert P=1 to make parity odd*/ 
    buffer[0] = RegisterAddress | INSERT_PARITY_BIT; 
  }
  else
  {   
    buffer[0] = RegisterAddress; 
  }
  buffer[1] = Data;  
  /* Comment: Check that the Upit sequence is ready */
    status = Spi_GetSequenceResult(SpiConf_SpiSequence_Spi_Seq_SbcMC33908);
  /*Write data to buffer*/
  status = Spi_WriteIB(SpiConf_SpiChannel_Spi_SbcMC33908_Command_16, buffer);
  if(status == E_NOT_OK)
  {
	  return status;
  }

    /* Comment: Call the Spi Synchronous transmit API */
  status = Spi_SyncTransmit(SpiConf_SpiSequence_Spi_Seq_SbcMC33908);
  if(status == E_NOT_OK)
  {	//Set DTC after exceeding specific timeframe
		OS_UserGetCounterValue(Hardware_Timer_0, &ostickCurrent);
		if(!u8TimeOutDetected)
		{
			ostickBegin = ostickCurrent;
			u8TimeOutDetected = 1;
		}
		
		u32TimeDiffInUs = OS_TICKS2US_HwCounter((ostickCurrent - ostickBegin));
		
		if(u32TimeDiffInUs > SBC_COM_TIMEOUT_US)
		{
			//Set com error code
			u32SBCError = SBC_SPI_COM_ERR;
			Dem_SetEventStatus(84, DEM_EVENT_STATUS_PREFAILED);
		} 
	  return status;
  }
  	else
	{
		u8TimeOutDetected = 0;
		u32SBCError = SBC_ERR_OK;
		Dem_SetEventStatus(84, DEM_EVENT_STATUS_PASSED);
	}
  /*Read data from buffer*/
  status = Spi_ReadIB(SpiConf_SpiChannel_Spi_SbcMC33908_Command_16, buffer);
  return  status;
}
/*! \brief  Description: This function shall return data from the SBC by using
the standard AUTOSAR SPI function Spi_SyncTransmit(). This function is only for 
internal use inside the SBC Handler and not available in the API.

Name and template: Std_ReturnType read_sbc(uint8_t RegisterAddress, * Data);

Functionality: This function shall receive the register ID of the SBC from 
which it shall read out the information and return the data.
*/
Std_ReturnType read_sbc(uint8_t RegisterAddress, uint8_t * Data)
{
  Std_ReturnType status = E_NOT_OK;
  Spi_SeqResultType statusSpiSeq = SPI_SEQ_OK;
  uint8_t buffer[2];
  buffer[0] = 0;
  buffer[1] = 0;
  buffer[0] = RegisterAddress;
  buffer[1] = READ_COMMAND; 
  /* Comment: Check that the Upit sequence is ready */
  Spi_GetSequenceResult(SpiConf_SpiSequence_Spi_Seq_SbcMC33908);
	if(statusSpiSeq != SPI_SEQ_OK)
	{
		//TODO!!! Why this step!
	}
  /*Write data to buffer*/
  status = Spi_WriteIB(SpiConf_SpiChannel_Spi_SbcMC33908_Command_16, buffer);
  if(status == E_NOT_OK)
  {
	  return status;
  }
    /* Comment: Call the Spi Synchronous transmit API */
    status = Spi_SyncTransmit(SpiConf_SpiSequence_Spi_Seq_SbcMC33908);
  if(status == E_NOT_OK)
{
		//Set DTC after exceeding specific timeframe
		OS_UserGetCounterValue(Hardware_Timer_0, &ostickCurrent);
		if(!u8TimeOutDetected)
		{
			ostickBegin = ostickCurrent;
			u8TimeOutDetected = 1;
		}
		
		u32TimeDiffInUs = OS_TICKS2US_HwCounter((ostickCurrent - ostickBegin));
		
		if(u32TimeDiffInUs > SBC_COM_TIMEOUT_US)
		{
			//Set com error code
			u32SBCError = SBC_SPI_COM_ERR;
			Dem_SetEventStatus(84, DEM_EVENT_STATUS_PREFAILED);
		} 
		
		return status;
	}
	else
	{
		u8TimeOutDetected = 0;
		u32SBCError = SBC_ERR_OK;
		Dem_SetEventStatus(84, DEM_EVENT_STATUS_PASSED);
	}
  
  
  /*Read data from buffer*/
  status = Spi_ReadIB(SpiConf_SpiChannel_Spi_SbcMC33908_Command_16, buffer);
  if(status == E_NOT_OK)
  {
	  return status;
  }
  
  *Data = buffer[1];
  return E_OK;
}

Std_ReturnType SbcMC33xxCdd_OruGetSbcP3V3_AIGet_Dummy (P2VAR(IoHwAbAIValue, AUTOMATIC, RTE_APPL_DATA) pValue)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType SbcMC33xxCdd_OruGetSbcP5V0_AIGet_Dummy (P2VAR(IoHwAbAIValue, AUTOMATIC, RTE_APPL_DATA) pValue)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType SbcMC33xxCdd_OruGetSbcP5V0A_AIGet_Dummy (P2VAR(IoHwAbAIValue, AUTOMATIC, RTE_APPL_DATA) pValue)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType SbcMC33xxCdd_OruGetSbcPVpre_AIGet_Dummy (P2VAR(IoHwAbAIValue, AUTOMATIC, RTE_APPL_DATA) pValue)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType SbcMC33xxCdd_OruGetSbcTemp_AIGet_Dummy (P2VAR(IoHwAbAIValue, AUTOMATIC, RTE_APPL_DATA) pValue)
{
  Std_ReturnType status;

  return status;
}

Std_ReturnType SbcMC33xxCdd_OruSbcCddService_GetTempValue_Dummy (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Tempvalue)
{
  Std_ReturnType status;

  return status;
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

