/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 4.5.69 PA/MPC574XP
 * (Build 20140813)
 * 
 * (c) 1998-2018 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * http://www.automotive.elektrobit.com
 * 
 * Date         : 5/22/18 4:05 PM           !!!IGNORE-LINE!!!
 */

#ifndef OS_CONFIG_H
#define OS_CONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * MISRA-C:2004 Deviation List
 *
 * MISRA-1) Deviated Rule: 3.4 (required)
 * All uses of the #pragma directive shall be documented and explained.
 *
 * Reason:
 * The #pragma directive may be used in this file to assign special linker
 * sections to OS-specific data like stack slots.
 *
 *
 * MISRA-2) Deviated Rule: 19.6 (required)
 * #undef shall not be used.
 *
 * Reason:
 * Special #define and corresponding #undef directives may be used in this
 * file to assign special linker sections to OS-specific data like stack
 * slots.
*/

/* Deviation MISRA-1, MISRA-2 <*> */

#include <Os.h>
#include <PA/Os_PA_timer_STM.h>

#define OS_GENERATION_ID_OS_CONF_H 0x893c8559UL

#define OS_AUTOSAROS_VER 4

#define OS_AUTOSAROS_REV 5

#define OS_AUTOSAROS_CORE_BUILD 20140813

#define OS_AUTOSAROS_ARCH_BUILD 20140813

#ifndef OS_ASM
extern const os_uint32_t OS_os_GenBuildId;
#endif  /* OS_ASM */
/*===================================================================
 * Alarms
 *==================================================================*/

#define OS_NALARMS 4
#define OS_FIRSTINTERNALALARM 6
#define OS_NINTERNALALARMS 0
#define OS_NALARMCALLBACKS 0
#define OS_SchM_DefaultScheduleTable 4
#define OS_Rte_DefaultScheduleTable 5
#define OS_ALARM OS_ALARM_INIT(    /* AlarmIncrementRteCounter */  \
  0xffffffffU,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  0x0U,                                                /* Permissions */  \
  &OS_WrapIncrementCounter,                            /* Counter wrapper */  \
  0,                                                   /* Not used */  \
  Rte_Counter,                                         /* Incremented counter */  \
  HwCounter                                            /* Alarm counter */  \
),  \
OS_ALARM_INIT(    /* AlarmIncrementSwCounter */  \
  0xffffffffU,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  0x0U,                                                /* Permissions */  \
  &OS_WrapIncrementCounter,                            /* Counter wrapper */  \
  0,                                                   /* Not used */  \
  SwCounter,                                           /* Incremented counter */  \
  HwCounter                                            /* Alarm counter */  \
),  \
OS_ALARM_INIT(    /* Rte_TimeoutAlarm_2 */  \
  0xffffffffU,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  0x0U,                                                /* Permissions */  \
  &OS_WrapSetEvent,                                    /* Event wrapper */  \
  Rte_OSTimeoutEvent,                                  /* Set event */  \
  MainFunction_Task,                                   /* Event task */  \
  Rte_Counter                                          /* Alarm counter */  \
),  \
OS_ALARM_INIT(    /* Rte_TimeoutAlarm_1 */  \
  0xffffffffU,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  0x0U,                                                /* Permissions */  \
  &OS_WrapSetEvent,                                    /* Event wrapper */  \
  Rte_OSTimeoutEvent,                                  /* Set event */  \
  Rte_ChrgTask,                                        /* Event task */  \
  Rte_Counter                                          /* Alarm counter */  \
),  \
OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable */  \
  0xffffffffU,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  0x0U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  SchM_DefaultScheduleTable,                           /* Schedule table */  \
  Rte_Counter                                          /* Alarm counter */  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable */  \
  0xffffffffU,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  0x0U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  Rte_DefaultScheduleTable,                            /* Schedule table */  \
  Rte_Counter                                          /* Alarm counter */  \
)

/*===================================================================
 * Application modes
 *==================================================================*/

#define OS_NSTARTMODES 2
#define OS_AUTOSTARTTASKS   OS_NULLTASK,                                         \
  Init_Task,                                           \
  OS_NULLTASK
#define OS_STARTMODETASKS   0,                                                   1
#define OS_AUTOSTARTALARMS     {  \
      OS_NULLALARM,                                        \
      OS_STARTMETHOD_REL,                                  \
      0,                                                   \
      0  \
    },  \
    {  \
      AlarmIncrementRteCounter,                            \
      OS_STARTMETHOD_REL,                                  \
      OS_NsToTicks_HwCounter(1000000),                     \
      OS_NsToTicks_HwCounter(1000000)  \
    },  \
    {  \
      AlarmIncrementSwCounter,                             \
      OS_STARTMETHOD_REL,                                  \
      OS_NsToTicks_HwCounter(1000000),                     \
      OS_NsToTicks_HwCounter(1000000)  \
    },  \
    {  \
      OS_NULLALARM,                                        \
      OS_STARTMETHOD_REL,                                  \
      0,                                                   \
      0  \
    }
#define OS_STARTMODEALARMS   0,                                                   1

/*===================================================================
 * Applications
 *==================================================================*/

#define OS_NAPPS 0
#define OS_NAPPSNONPRIV 0
#define OS_NFUNCTIONS 0
#define OS_SHOOKSTACKLEN 0
#define OS_EHOOKSTACKLEN 0

/*===================================================================
 * CPU load measurement
 *==================================================================*/

#define OS_CPULOADCFG_INTERVAL OS_TimestampNsToTicks(100000000)
#define OS_CPULOADCFG_NINTERVALS 10
#define OS_CPULOADCFG_WINDOW OS_TimestampNsToTicks(1000000000)
#define OS_CPULOADCFG_ROUNDING (OS_CPULOADCFG_WINDOW/2)

/*===================================================================
 * Configured Modes
 *==================================================================*/

#define OS_CONFIGMODE (OS_ECC1|OS_SCHEDMIX|OS_EXTENDED|OS_STARTUPCHECK|OS_TRACE|OS_STACKCHECK|OS_DBGPROT_OFF|OS_CPULOAD)
#define OS_IECMODE (OS_IEC_OSEK)
#define OS_HOOKSELECTION (OS_ACTION_PROTECTIONHOOK|OS_ACTION_ERRORHOOK)
#define OS_PERMITTEDCONTEXT (OS_permittedContextAutosar)
#define OS_INCLUDE_RTE 0
#define OS_VECTORMODE OS_INTC_HARDWARE

/*===================================================================
 * Counters
 *==================================================================*/

#define OS_NCOUNTERS 3
#define OS_NGPTTICKERS 0
#define OS_COUNTER OS_COUNTER_INIT(    /* HwCounter */  \
  0xffffffffu,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  &OS_HwCounterUpdate,                                 \
  0x0U,                                                /* Permissions */  \
  &OS_hwTimer[0],                                      /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)30000U,                                   /* Ticks per base */  \
  (os_tick_t)1U                                        /* Min cycle */  \
),  \
OS_COUNTER_INIT(    /* Rte_Counter */  \
  0xffffffffu,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  OS_NULL,                                             \
  0x0U,                                                /* Permissions */  \
  OS_NULL,                                             /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1000U,                                    /* Ticks per base */  \
  (os_tick_t)1U                                        /* Min cycle */  \
),  \
OS_COUNTER_INIT(    /* SwCounter */  \
  0xffffffffu,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  OS_NULL,                                             \
  0x0U,                                                /* Permissions */  \
  OS_NULL,                                             /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1000U,                                    /* Ticks per base */  \
  (os_tick_t)1U                                        /* Min cycle */  \
)
#define OS_NINTERNALTICKERS 0

/*===================================================================
 * Events
 *==================================================================*/

#define OS_NEVENTS 45
/*===================================================================
 * Hardware Timers
 *==================================================================*/

#define OS_NHWTIMERS 1
#define OS_HWTIMER {    /* TIMER_STM_0 */  \
  &OS_timerSTMdriver,                                  /* Driver table */  \
  &OS_hwtLastValue[0],                                 \
  3221225472U,                                         /* Max delta */  \
  2147483648U,                                         /* Default delta if max exceeded */  \
  4294967295U,                                         /* Wrap mask */  \
  0U,                                                  /* Driver number */  \
  0U                                                   /* Driver channel */  \
}

/*===================================================================
 * Hook Functions
 *==================================================================*/

#define OS_ERRORHOOK &ErrorHook
#define OS_SHUTDOWNHOOK &ShutdownHook
#define OS_PROTECTIONHOOK &ProtectionHook
/*===================================================================
 * Interrupts
 *==================================================================*/

#define OS_IRQ209_NAME _OS_VECTOR_I0521_FLEXCAN_0_ESR_BOFF_TW_RW
#define OS_IRQ209_ISRID CanBusOffIsr_0
#define OS_IRQ209_ENTRY OS_Cat2Handler
#define OS_IRQ209_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ209_WRAPPER OS_VECTOR_I0521_FLEXCAN_0_ESR_BOFF_TW_RW
#define OS_IRQ209_NEEDSWRAPPER 1
#define OS_IRQ20a_NAME _OS_VECTOR_I0522_FLEXCAN_0_BUF_00_03
#define OS_IRQ20a_ISRID CanMailboxIsr_0_00_03
#define OS_IRQ20a_ENTRY OS_Cat2Handler
#define OS_IRQ20a_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ20a_WRAPPER OS_VECTOR_I0522_FLEXCAN_0_BUF_00_03
#define OS_IRQ20a_NEEDSWRAPPER 1
#define OS_IRQ20b_NAME _OS_VECTOR_I0523_FLEXCAN_0_BUF_04_07
#define OS_IRQ20b_ISRID CanMailboxIsr_0_04_07
#define OS_IRQ20b_ENTRY OS_Cat2Handler
#define OS_IRQ20b_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ20b_WRAPPER OS_VECTOR_I0523_FLEXCAN_0_BUF_04_07
#define OS_IRQ20b_NEEDSWRAPPER 1
#define OS_IRQ20c_NAME _OS_VECTOR_I0524_FLEXCAN_0_BUF_08_11
#define OS_IRQ20c_ISRID CanMailboxIsr_0_08_11
#define OS_IRQ20c_ENTRY OS_Cat2Handler
#define OS_IRQ20c_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ20c_WRAPPER OS_VECTOR_I0524_FLEXCAN_0_BUF_08_11
#define OS_IRQ20c_NEEDSWRAPPER 1
#define OS_IRQ20d_NAME _OS_VECTOR_I0525_FLEXCAN_0_BUF_12_15
#define OS_IRQ20d_ISRID CanMailboxIsr_0_12_15
#define OS_IRQ20d_ENTRY OS_Cat2Handler
#define OS_IRQ20d_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ20d_WRAPPER OS_VECTOR_I0525_FLEXCAN_0_BUF_12_15
#define OS_IRQ20d_NEEDSWRAPPER 1
#define OS_IRQ20e_NAME _OS_VECTOR_I0526_FLEXCAN_0_BUF_16_31
#define OS_IRQ20e_ISRID CanMailboxIsr_0_16_31
#define OS_IRQ20e_ENTRY OS_Cat2Handler
#define OS_IRQ20e_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ20e_WRAPPER OS_VECTOR_I0526_FLEXCAN_0_BUF_16_31
#define OS_IRQ20e_NEEDSWRAPPER 1
#define OS_IRQ20f_NAME _OS_VECTOR_I0527_FLEXCAN_0_BUF_32_39
#define OS_IRQ20f_ISRID CanMailboxIsr_0_32_39
#define OS_IRQ20f_ENTRY OS_Cat2Handler
#define OS_IRQ20f_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ20f_WRAPPER OS_VECTOR_I0527_FLEXCAN_0_BUF_32_39
#define OS_IRQ20f_NEEDSWRAPPER 1
#define OS_IRQ210_NAME _OS_VECTOR_I0528_FLEXCAN_0_BUF_40_47
#define OS_IRQ210_ISRID CanMailboxIsr_0_40_47
#define OS_IRQ210_ENTRY OS_Cat2Handler
#define OS_IRQ210_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ210_WRAPPER OS_VECTOR_I0528_FLEXCAN_0_BUF_40_47
#define OS_IRQ210_NEEDSWRAPPER 1
#define OS_IRQ211_NAME _OS_VECTOR_I0529_FLEXCAN_0_BUF_48_55
#define OS_IRQ211_ISRID CanMailboxIsr_0_48_55
#define OS_IRQ211_ENTRY OS_Cat2Handler
#define OS_IRQ211_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ211_WRAPPER OS_VECTOR_I0529_FLEXCAN_0_BUF_48_55
#define OS_IRQ211_NEEDSWRAPPER 1
#define OS_IRQ212_NAME _OS_VECTOR_I0530_FLEXCAN_0_BUF_56_63
#define OS_IRQ212_ISRID CanMailboxIsr_0_56_63
#define OS_IRQ212_ENTRY OS_Cat2Handler
#define OS_IRQ212_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ212_WRAPPER OS_VECTOR_I0530_FLEXCAN_0_BUF_56_63
#define OS_IRQ212_NEEDSWRAPPER 1
#define OS_IRQ106_NAME _OS_VECTOR_I0262_DSPI_0_SR_TCF
#define OS_IRQ106_ISRID Spi_Dspi_IsrTCF_DSPI_0
#define OS_IRQ106_ENTRY OS_Cat2Handler
#define OS_IRQ106_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ106_WRAPPER OS_VECTOR_I0262_DSPI_0_SR_TCF
#define OS_IRQ106_NEEDSWRAPPER 1
#define OS_IRQ118_NAME _OS_VECTOR_I0280_DSPI_2_SR_TCF
#define OS_IRQ118_ISRID Spi_Dspi_IsrTCF_DSPI_2
#define OS_IRQ118_ENTRY OS_Cat2Handler
#define OS_IRQ118_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ118_WRAPPER OS_VECTOR_I0280_DSPI_2_SR_TCF
#define OS_IRQ118_NEEDSWRAPPER 1
#define OS_IRQ11f_NAME _OS_VECTOR_I0287_DSPI_3_SR_EOQF
#define OS_IRQ11f_ISRID Spi_Dspi_IsrTCF_DSPI_3
#define OS_IRQ11f_ENTRY OS_Cat2Handler
#define OS_IRQ11f_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ11f_WRAPPER OS_VECTOR_I0287_DSPI_3_SR_EOQF
#define OS_IRQ11f_NEEDSWRAPPER 1
#define OS_IRQ29e_NAME _OS_VECTOR_I0670_FlexPWM_1_RF0
#define OS_IRQ29e_ISRID FLEXPWM_1_SUBMOD_0_REL_ISR
#define OS_IRQ29e_ENTRY OS_ISR_FLEXPWM_1_SUBMOD_0_REL_ISR
#define OS_IRQ29e_TYPE OS_VECTOR_TYPE_CAT1
#define OS_IRQ29e_WRAPPER OS_VECTOR_I0670_FlexPWM_1_RF0
#define OS_IRQ29e_NEEDSWRAPPER 1
#define OS_IRQ216_NAME _OS_VECTOR_I0534_FLEXCAN_1_ESR_BOFF_TW_RW
#define OS_IRQ216_ISRID CanBusOffIsr_1
#define OS_IRQ216_ENTRY OS_Cat2Handler
#define OS_IRQ216_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ216_WRAPPER OS_VECTOR_I0534_FLEXCAN_1_ESR_BOFF_TW_RW
#define OS_IRQ216_NEEDSWRAPPER 1
#define OS_IRQ217_NAME _OS_VECTOR_I0535_FLEXCAN_1_BUF_00_03
#define OS_IRQ217_ISRID CanMailboxIsr_1_00_03
#define OS_IRQ217_ENTRY OS_Cat2Handler
#define OS_IRQ217_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ217_WRAPPER OS_VECTOR_I0535_FLEXCAN_1_BUF_00_03
#define OS_IRQ217_NEEDSWRAPPER 1
#define OS_IRQ218_NAME _OS_VECTOR_I0536_FLEXCAN_1_BUF_04_07
#define OS_IRQ218_ISRID CanMailboxIsr_1_04_07
#define OS_IRQ218_ENTRY OS_Cat2Handler
#define OS_IRQ218_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ218_WRAPPER OS_VECTOR_I0536_FLEXCAN_1_BUF_04_07
#define OS_IRQ218_NEEDSWRAPPER 1
#define OS_IRQ219_NAME _OS_VECTOR_I0537_FLEXCAN_1_BUF_08_11
#define OS_IRQ219_ISRID CanMailboxIsr_1_08_11
#define OS_IRQ219_ENTRY OS_Cat2Handler
#define OS_IRQ219_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ219_WRAPPER OS_VECTOR_I0537_FLEXCAN_1_BUF_08_11
#define OS_IRQ219_NEEDSWRAPPER 1
#define OS_IRQ21a_NAME _OS_VECTOR_I0538_FLEXCAN_1_BUF_12_15
#define OS_IRQ21a_ISRID CanMailboxIsr_1_12_15
#define OS_IRQ21a_ENTRY OS_Cat2Handler
#define OS_IRQ21a_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ21a_WRAPPER OS_VECTOR_I0538_FLEXCAN_1_BUF_12_15
#define OS_IRQ21a_NEEDSWRAPPER 1
#define OS_IRQ21b_NAME _OS_VECTOR_I0539_FLEXCAN_1_BUF_16_31
#define OS_IRQ21b_ISRID CanMailboxIsr_1_16_31
#define OS_IRQ21b_ENTRY OS_Cat2Handler
#define OS_IRQ21b_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ21b_WRAPPER OS_VECTOR_I0539_FLEXCAN_1_BUF_16_31
#define OS_IRQ21b_NEEDSWRAPPER 1
#define OS_IRQ21c_NAME _OS_VECTOR_I0540_FLEXCAN_1_BUF_32_39
#define OS_IRQ21c_ISRID CanMailboxIsr_1_32_39
#define OS_IRQ21c_ENTRY OS_Cat2Handler
#define OS_IRQ21c_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ21c_WRAPPER OS_VECTOR_I0540_FLEXCAN_1_BUF_32_39
#define OS_IRQ21c_NEEDSWRAPPER 1
#define OS_IRQ21d_NAME _OS_VECTOR_I0541_FLEXCAN_1_BUF_40_47
#define OS_IRQ21d_ISRID CanMailboxIsr_1_40_47
#define OS_IRQ21d_ENTRY OS_Cat2Handler
#define OS_IRQ21d_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ21d_WRAPPER OS_VECTOR_I0541_FLEXCAN_1_BUF_40_47
#define OS_IRQ21d_NEEDSWRAPPER 1
#define OS_IRQ21e_NAME _OS_VECTOR_I0542_FLEXCAN_1_BUF_48_55
#define OS_IRQ21e_ISRID CanMailboxIsr_1_48_55
#define OS_IRQ21e_ENTRY OS_Cat2Handler
#define OS_IRQ21e_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ21e_WRAPPER OS_VECTOR_I0542_FLEXCAN_1_BUF_48_55
#define OS_IRQ21e_NEEDSWRAPPER 1
#define OS_IRQ21f_NAME _OS_VECTOR_I0543_FLEXCAN_1_BUF_56_63
#define OS_IRQ21f_ISRID CanMailboxIsr_1_56_63
#define OS_IRQ21f_ENTRY OS_Cat2Handler
#define OS_IRQ21f_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ21f_WRAPPER OS_VECTOR_I0543_FLEXCAN_1_BUF_56_63
#define OS_IRQ21f_NEEDSWRAPPER 1
#define OS_IRQ3c_NAME _OS_VECTOR_I0060_DMA_CH7
#define OS_IRQ3c_ISRID MCL_DMA_CH_7_ISR
#define OS_IRQ3c_ENTRY OS_Cat2Handler
#define OS_IRQ3c_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ3c_WRAPPER OS_VECTOR_I0060_DMA_CH7
#define OS_IRQ3c_NEEDSWRAPPER 1
#define OS_IRQ4c_NAME _OS_VECTOR_I0076_DMA_CH23
#define OS_IRQ4c_ISRID MCL_DMA_CH_23_ISR
#define OS_IRQ4c_ENTRY OS_Cat2Handler
#define OS_IRQ4c_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ4c_WRAPPER OS_VECTOR_I0076_DMA_CH23
#define OS_IRQ4c_NEEDSWRAPPER 1
#define OS_IRQ4e_NAME _OS_VECTOR_I0078_DMA_CH25
#define OS_IRQ4e_ISRID MCL_DMA_CH_25_ISR
#define OS_IRQ4e_ENTRY OS_Cat2Handler
#define OS_IRQ4e_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ4e_WRAPPER OS_VECTOR_I0078_DMA_CH25
#define OS_IRQ4e_NEEDSWRAPPER 1
#define OS_IRQ4f_NAME _OS_VECTOR_I0079_DMA_CH26
#define OS_IRQ4f_ISRID MCL_DMA_CH_26_ISR
#define OS_IRQ4f_ENTRY OS_Cat2Handler
#define OS_IRQ4f_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ4f_WRAPPER OS_VECTOR_I0079_DMA_CH26
#define OS_IRQ4f_NEEDSWRAPPER 1
#define OS_IRQ1fa_NAME _OS_VECTOR_I0506_ADC_2_WD
#define OS_IRQ1fa_ISRID Adc_Adcdig_WatchDogThresholdUnit2
#define OS_IRQ1fa_ENTRY OS_ISR_Adc_Adcdig_WatchDogThresholdUnit2
#define OS_IRQ1fa_TYPE OS_VECTOR_TYPE_CAT1
#define OS_IRQ1fa_WRAPPER OS_VECTOR_I0506_ADC_2_WD
#define OS_IRQ1fa_NEEDSWRAPPER 1
#define OS_IRQ1fe_NAME _OS_VECTOR_I0510_ADC_3_WD
#define OS_IRQ1fe_ISRID Adc_Adcdig_WatchDogThresholdUnit3
#define OS_IRQ1fe_ENTRY OS_ISR_Adc_Adcdig_WatchDogThresholdUnit3
#define OS_IRQ1fe_TYPE OS_VECTOR_TYPE_CAT1
#define OS_IRQ1fe_WRAPPER OS_VECTOR_I0510_ADC_3_WD
#define OS_IRQ1fe_NEEDSWRAPPER 1
#define OS_IRQe2_NAME _OS_VECTOR_I0226_PIT_0_CH0
#define OS_IRQe2_ISRID Gpt_PIT_0_TIMER_0_ISR
#define OS_IRQe2_ENTRY OS_Cat2Handler
#define OS_IRQe2_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQe2_WRAPPER OS_VECTOR_I0226_PIT_0_CH0
#define OS_IRQe2_NEEDSWRAPPER 1
#define OS_IRQe3_NAME _OS_VECTOR_I0227_PIT_0_CH1
#define OS_IRQe3_ISRID Gpt_PIT_0_TIMER_1_ISR
#define OS_IRQe3_ENTRY OS_Cat2Handler
#define OS_IRQe3_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQe3_WRAPPER OS_VECTOR_I0227_PIT_0_CH1
#define OS_IRQe3_NEEDSWRAPPER 1
#define OS_IRQ41_NAME _OS_VECTOR_I0065_DMA_CH12
#define OS_IRQ41_ISRID MCL_DMA_CH_12_ISR
#define OS_IRQ41_ENTRY OS_Cat2Handler
#define OS_IRQ41_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ41_WRAPPER OS_VECTOR_I0065_DMA_CH12
#define OS_IRQ41_NEEDSWRAPPER 1
#define OS_IRQ42_NAME _OS_VECTOR_I0066_DMA_CH13
#define OS_IRQ42_ISRID MCL_DMA_CH_13_ISR
#define OS_IRQ42_ENTRY OS_Cat2Handler
#define OS_IRQ42_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ42_WRAPPER OS_VECTOR_I0066_DMA_CH13
#define OS_IRQ42_NEEDSWRAPPER 1
#define OS_IRQf5_NAME _OS_VECTOR_I0245_SIUL2_DISR0_EI2
#define OS_IRQf5_ISRID SIUL2_EXT_IRQ_16_23_ISR
#define OS_IRQf5_ENTRY OS_Cat2Handler
#define OS_IRQf5_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQf5_WRAPPER OS_VECTOR_I0245_SIUL2_DISR0_EI2
#define OS_IRQf5_NEEDSWRAPPER 1
#define OS_IRQ24_NAME _OS_VECTOR_I0036_STM_0_CH0
#define OS_IRQ24_ISRID Os_Counter_TIMER_STM_0
#define OS_IRQ24_ENTRY OS_Cat2Handler
#define OS_IRQ24_TYPE OS_VECTOR_TYPE_CAT2
#define OS_IRQ24_WRAPPER OS_VECTOR_I0036_STM_0_CH0
#define OS_IRQ24_NEEDSWRAPPER 1
#define OS_NINTERRUPTS 36
#define OS_NCAT1_INTERRUPTS 3
#define OS_NCAT2_INTERRUPTS 33
#define OS_NCATK_INTERRUPTS 0
#define OS_NCAT2K_INTERRUPTS 0
#define OS_NISRSEXECTIMELIMIT 0
#define OS_NISRSINTLOCKLIMIT 0
#define OS_NISRSRESLOCKLIMIT 0
#define OS_NISRACCOUNTING 0
#define OS_CAT1LOCK 5
#define OS_CAT2LOCK 3
#define OS_KERNLOCK 3
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_TIMER_STM_0 35
#endif
#define OS_ISRCONFIG OS_ISRCONFIG_INIT(    /* CanBusOffIsr_0 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanBusOffIsr_0,                              /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanBusOffIsr_0,                                      /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      521,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_00_03 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_00_03,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_00_03,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      522,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_04_07 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_04_07,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_04_07,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      523,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_08_11 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_08_11,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_08_11,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      524,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_12_15 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_12_15,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_12_15,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      525,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_16_31 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_16_31,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_16_31,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      526,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_32_39 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_32_39,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_32_39,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      527,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_40_47 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_40_47,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_40_47,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      528,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_48_55 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_48_55,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_48_55,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      529,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_0_56_63 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_0_56_63,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_0_56_63,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      530,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Spi_Dspi_IsrTCF_DSPI_0 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_Spi_Dspi_IsrTCF_DSPI_0,                      /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Spi_Dspi_IsrTCF_DSPI_0,                              /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      262,                                                 /* Interrupt vector */  \
      3,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Spi_Dspi_IsrTCF_DSPI_2 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_Spi_Dspi_IsrTCF_DSPI_2,                      /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Spi_Dspi_IsrTCF_DSPI_2,                              /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      280,                                                 /* Interrupt vector */  \
      3,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Spi_Dspi_IsrTCF_DSPI_3 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_Spi_Dspi_IsrTCF_DSPI_3,                      /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Spi_Dspi_IsrTCF_DSPI_3,                              /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      287,                                                 /* Interrupt vector */  \
      3,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* FLEXPWM_1_SUBMOD_0_REL_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_FLEXPWM_1_SUBMOD_0_REL_ISR,                  /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  FLEXPWM_1_SUBMOD_0_REL_ISR,                          /* Isr id */  \
  (OS_ISRF_CAT1|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      670,                                                 /* Interrupt vector */  \
      5,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanBusOffIsr_1 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanBusOffIsr_1,                              /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanBusOffIsr_1,                                      /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      534,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_00_03 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_00_03,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_00_03,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      535,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_04_07 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_04_07,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_04_07,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      536,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_08_11 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_08_11,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_08_11,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      537,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_12_15 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_12_15,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_12_15,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      538,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_16_31 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_16_31,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_16_31,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      539,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_32_39 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_32_39,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_32_39,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      540,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_40_47 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_40_47,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_40_47,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      541,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_48_55 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_48_55,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_48_55,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      542,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CanMailboxIsr_1_56_63 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_CanMailboxIsr_1_56_63,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  CanMailboxIsr_1_56_63,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      543,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* MCL_DMA_CH_7_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_MCL_DMA_CH_7_ISR,                            /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  MCL_DMA_CH_7_ISR,                                    /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      60,                                                  /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* MCL_DMA_CH_23_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_MCL_DMA_CH_23_ISR,                           /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  MCL_DMA_CH_23_ISR,                                   /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      76,                                                  /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* MCL_DMA_CH_25_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_MCL_DMA_CH_25_ISR,                           /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  MCL_DMA_CH_25_ISR,                                   /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      78,                                                  /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* MCL_DMA_CH_26_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_MCL_DMA_CH_26_ISR,                           /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  MCL_DMA_CH_26_ISR,                                   /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      79,                                                  /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Adc_Adcdig_WatchDogThresholdUnit2 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_Adc_Adcdig_WatchDogThresholdUnit2,           /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Adc_Adcdig_WatchDogThresholdUnit2,                   /* Isr id */  \
  (OS_ISRF_CAT1|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      506,                                                 /* Interrupt vector */  \
      4,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Adc_Adcdig_WatchDogThresholdUnit3 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_Adc_Adcdig_WatchDogThresholdUnit3,           /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Adc_Adcdig_WatchDogThresholdUnit3,                   /* Isr id */  \
  (OS_ISRF_CAT1|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      510,                                                 /* Interrupt vector */  \
      4,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Gpt_PIT_0_TIMER_0_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_Gpt_PIT_0_TIMER_0_ISR,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Gpt_PIT_0_TIMER_0_ISR,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      226,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Gpt_PIT_0_TIMER_1_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_Gpt_PIT_0_TIMER_1_ISR,                       /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Gpt_PIT_0_TIMER_1_ISR,                               /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      227,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* MCL_DMA_CH_12_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_MCL_DMA_CH_12_ISR,                           /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  MCL_DMA_CH_12_ISR,                                   /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      65,                                                  /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* MCL_DMA_CH_13_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_MCL_DMA_CH_13_ISR,                           /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  1024U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  MCL_DMA_CH_13_ISR,                                   /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      66,                                                  /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* SIUL2_EXT_IRQ_16_23_ISR */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_ISR_SIUL2_EXT_IRQ_16_23_ISR,                     /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  4096U,                                               /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  SIUL2_EXT_IRQ_16_23_ISR,                             /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      245,                                                 /* Interrupt vector */  \
      2,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_TIMER_STM_0 */  \
  OS_NULL,                                             /* Application */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  &OS_CounterIsr_HwCounter,                            /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  464U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Os_Counter_TIMER_STM_0,                              /* Isr id */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      36,                                                  /* Interrupt vector */  \
      1,                                                   /* Run priority */  \
      OS_NULL,                                             /* Stack base */  \
      OS_NULL,                                             /* Initial SP */  \
      OS_NULL,                                             /* not used */  \
      OS_NULL                                              /* not used */  \
    )  \
)
#define OS_ISTACKBASE OS_kernStack
#define OS_ISTACKLEN 9892

/*===================================================================
 * Optimization
 *==================================================================*/

#define OS_CAT1_DIRECTCALL 1
/*===================================================================
 * Rate Monitor
 *==================================================================*/

#define OS_NRATEMONS 0
/*===================================================================
 * Resource Lock Timing
 *==================================================================*/

#define OS_NRESLOCKTIMES 0
/*===================================================================
 * Resources
 *==================================================================*/

#define OS_NRESOURCES 13
#define OS_RESOURCES OS_RESOURCES_INIT(    /* RES_SCHEDULER */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_0 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  10                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_1 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  7                                                    /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_2 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  7                                                    /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_3 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_4 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_5 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_6 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_7 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  4                                                    /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_8 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_9 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_10 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
),  \
OS_RESOURCES_INIT(    /* Rte_Res_11 */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
  13                                                   /* Priority */  \
)

/*===================================================================
 * Schedule Tables
 *==================================================================*/

#define OS_NSCHEDULES 2
#define OS_NSCHEDULESSYNC 0
#define OS_STCONFIG OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable */  \
  0xffffffffU,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  0x0U,                                                /* Permissions */  \
  &OS_stEntries[0],                                    /* Schedule table entries */  \
  20,                                                  /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  4,                                                   /* Alarm ID */  \
  18,                                                  /* Number of expiry points */  \
  (OS_ST_REPEATING)                                    /* Flags */  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable */  \
  0xffffffffU,                                         /* Application id */  \
  OS_NULL,                                             /* Application pointer */  \
  0x0U,                                                /* Permissions */  \
  &OS_stEntries[18],                                   /* Schedule table entries */  \
  100,                                                 /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  5,                                                   /* Alarm ID */  \
  145,                                                 /* Number of expiry points */  \
  (OS_ST_REPEATING)                                    /* Flags */  \
)
#define OS_NSTENTRIES 163
#define OS_STENTRIES     /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_0,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_0 | Rte_OSTimingEvent_1_1,       /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_0,                               /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0 | Rte_OSTimingEvent_3_1,       /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_2000 */  \
    {  \
      2,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_4000 */  \
    {  \
      4,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_5000 */  \
    {  \
      5,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_0,                               /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    /* EP_6000 */  \
    {  \
      6,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_8000 */  \
    {  \
      8,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_10000 */  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_0,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_0,                               /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_0,                               /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0 | Rte_OSTimingEvent_3_1,       /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_12000 */  \
    {  \
      12,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_14000 */  \
    {  \
      14,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_15000 */  \
    {  \
      15,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_0,                               /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    /* EP_16000 */  \
    {  \
      16,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_18000 */  \
    {  \
      18,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_0,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_0 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Rte_ModTask                                          /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2 | Rte_OSTimingEvent_1_3 | Rte_OSTimingEvent_1_4,  /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2 | Rte_OSTimingEvent_0_1,       /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_1000 */  \
    {  \
      1,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_2000 */  \
    {  \
      2,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_3000 */  \
    {  \
      3,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_4000 */  \
    {  \
      4,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_5000 */  \
    {  \
      5,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_6000 */  \
    {  \
      6,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_7000 */  \
    {  \
      7,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_8000 */  \
    {  \
      8,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_9000 */  \
    {  \
      9,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_10000 */  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2,                               /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2,                               /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      10,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_11000 */  \
    {  \
      11,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_12000 */  \
    {  \
      12,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_13000 */  \
    {  \
      13,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_14000 */  \
    {  \
      14,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_15000 */  \
    {  \
      15,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_16000 */  \
    {  \
      16,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_17000 */  \
    {  \
      17,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_18000 */  \
    {  \
      18,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_19000 */  \
    {  \
      19,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_20000 */  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Rte_ModTask                                          /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2 | Rte_OSTimingEvent_1_3,       /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2 | Rte_OSTimingEvent_0_1,       /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      20,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_21000 */  \
    {  \
      21,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_22000 */  \
    {  \
      22,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_23000 */  \
    {  \
      23,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_24000 */  \
    {  \
      24,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_25000 */  \
    {  \
      25,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_26000 */  \
    {  \
      26,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_27000 */  \
    {  \
      27,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_28000 */  \
    {  \
      28,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_29000 */  \
    {  \
      29,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_30000 */  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2,                               /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2,                               /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      30,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_31000 */  \
    {  \
      31,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_32000 */  \
    {  \
      32,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_33000 */  \
    {  \
      33,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_34000 */  \
    {  \
      34,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_35000 */  \
    {  \
      35,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_36000 */  \
    {  \
      36,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_37000 */  \
    {  \
      37,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_38000 */  \
    {  \
      38,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_39000 */  \
    {  \
      39,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_40000 */  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Rte_ModTask                                          /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2 | Rte_OSTimingEvent_1_3,       /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2 | Rte_OSTimingEvent_0_1,       /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      40,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_41000 */  \
    {  \
      41,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_42000 */  \
    {  \
      42,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_43000 */  \
    {  \
      43,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_44000 */  \
    {  \
      44,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_45000 */  \
    {  \
      45,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_46000 */  \
    {  \
      46,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_47000 */  \
    {  \
      47,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_48000 */  \
    {  \
      48,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_49000 */  \
    {  \
      49,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_50000 */  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2,                               /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2,                               /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      50,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_51000 */  \
    {  \
      51,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_52000 */  \
    {  \
      52,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_53000 */  \
    {  \
      53,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_54000 */  \
    {  \
      54,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_55000 */  \
    {  \
      55,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_56000 */  \
    {  \
      56,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_57000 */  \
    {  \
      57,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_58000 */  \
    {  \
      58,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_59000 */  \
    {  \
      59,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_60000 */  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Rte_ModTask                                          /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2 | Rte_OSTimingEvent_1_3,       /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2 | Rte_OSTimingEvent_0_1,       /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      60,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_61000 */  \
    {  \
      61,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_62000 */  \
    {  \
      62,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_63000 */  \
    {  \
      63,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_64000 */  \
    {  \
      64,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_65000 */  \
    {  \
      65,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_66000 */  \
    {  \
      66,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_67000 */  \
    {  \
      67,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_68000 */  \
    {  \
      68,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_69000 */  \
    {  \
      69,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_70000 */  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2,                               /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2,                               /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      70,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_71000 */  \
    {  \
      71,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_72000 */  \
    {  \
      72,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_73000 */  \
    {  \
      73,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_74000 */  \
    {  \
      74,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_75000 */  \
    {  \
      75,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_76000 */  \
    {  \
      76,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_77000 */  \
    {  \
      77,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_78000 */  \
    {  \
      78,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_79000 */  \
    {  \
      79,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_80000 */  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Rte_ModTask                                          /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2 | Rte_OSTimingEvent_1_3,       /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2 | Rte_OSTimingEvent_0_1,       /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      80,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_81000 */  \
    {  \
      81,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_82000 */  \
    {  \
      82,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_83000 */  \
    {  \
      83,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_84000 */  \
    {  \
      84,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_85000 */  \
    {  \
      85,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_86000 */  \
    {  \
      86,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_87000 */  \
    {  \
      87,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_88000 */  \
    {  \
      88,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_89000 */  \
    {  \
      89,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_90000 */  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      Safety_Task                                          /* Task */  \
    },  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_2_1,                               /* Events */  \
      Rte_ChrgTask                                         /* Task */  \
    },  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_1_2,                               /* Events */  \
      MainFunction_Task                                    /* Task */  \
    },  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_0_2,                               /* Events */  \
      Rte_Time_Task_10ms                                   /* Task */  \
    },  \
    {  \
      90,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_91000 */  \
    {  \
      91,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_92000 */  \
    {  \
      92,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_93000 */  \
    {  \
      93,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_94000 */  \
    {  \
      94,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_95000 */  \
    {  \
      95,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_96000 */  \
    {  \
      96,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_97000 */  \
    {  \
      97,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_98000 */  \
    {  \
      98,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    },  \
    /* EP_99000 */  \
    {  \
      99,                                                  /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      Rte_OSTimingEvent_3_2,                               /* Events */  \
      Rte_FastTask                                         /* Task */  \
    }

/*===================================================================
 * Stacks
 *==================================================================*/

#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot0[7208];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot1[2088];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot2[2064];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot3[552];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot4[296];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot5[296];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot6[296];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot7[296];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot8[288];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_taskStack_slot9[288];
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_stackelement_t OS_kernStack[2480];
#endif
#endif  /* OS_ASM */

/*===================================================================
 * Tasks
 *==================================================================*/

#ifndef OS_ASM
DeclareTask(Rte_ModTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(MainFunction_Task);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Rte_FastTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Rte_ChrgTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Rte_Event_Task);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Rte_Time_Task_10ms);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Diag_RteTask);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Init_Task);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Safety_Task);
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(Rte_Background_Task);
#endif  /* OS_ASM */
#define OS_NTASKS 10
#define OS_NETASKS 7
#define OS_NTASKSEXECTIMELIMIT 0
#define OS_NTASKSINTLOCKLIMIT 0
#define OS_NTASKSRESLOCKLIMIT 0
#define OS_NPRIORITIES 14
#define OS_MAXTASKPRIO 13
#define OS_NPRIORITYQUEUEDYNAMICS 0
#define OS_NPRIORITYSLOTS 14
#define OS_PRIORITYQUEUE {    /* Priority 0 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[0U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x40000U,                                            /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 1 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[1U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x80000U,                                            /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 2 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[2U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x100000U,                                           /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 3 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[3U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x200000U,                                           /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 4 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[4U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x400000U,                                           /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 5 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[5U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x800000U,                                           /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 6 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[6U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x1000000U,                                          /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 7 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[7U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x2000000U,                                          /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 8 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[8U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x4000000U,                                          /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 9 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[9U],                                \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x8000000U,                                          /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 10 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[10U],                               \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x10000000U,                                         /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 11 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[11U],                               \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x20000000U,                                         /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 12 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[12U],                               \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x40000000U,                                         /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 13 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_prioritySlot[13U],                               \
  &OS_slavePrioWord[0U],                               /* Priority slave word */  \
  0x80000000U,                                         /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
}
#define OS_NTASKACCOUNTING 0
#define OS_NTASKACTIVATIONS 10
#define OS_TASKCONFIG OS_TASKCONFIG_INIT(    /* Rte_ModTask */  \
  &OS_taskDynamic[0],                                  /* Dynamic task structure */  \
  2U,                                                  /* Run priority */  \
  2U,                                                  /* Queuing priority */  \
  1,                                                   /* Activation index */  \
  &OS_TASK_Rte_ModTask,                                /* Task entry */  \
  &OS_taskStack_slot0[0],                              /* Stack base */  \
  28816U,                                              /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Rte_ModTask,                                         /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* MainFunction_Task */  \
  &OS_taskDynamic[1],                                  /* Dynamic task structure */  \
  3U,                                                  /* Run priority */  \
  3U,                                                  /* Queuing priority */  \
  2,                                                   /* Activation index */  \
  &OS_TASK_MainFunction_Task,                          /* Task entry */  \
  &OS_taskStack_slot3[0],                              /* Stack base */  \
  2192U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  MainFunction_Task,                                   /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Rte_FastTask */  \
  &OS_taskDynamic[2],                                  /* Dynamic task structure */  \
  5U,                                                  /* Run priority */  \
  5U,                                                  /* Queuing priority */  \
  3,                                                   /* Activation index */  \
  &OS_TASK_Rte_FastTask,                               /* Task entry */  \
  &OS_taskStack_slot4[0],                              /* Stack base */  \
  1168U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Rte_FastTask,                                        /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Rte_ChrgTask */  \
  &OS_taskDynamic[3],                                  /* Dynamic task structure */  \
  6U,                                                  /* Run priority */  \
  6U,                                                  /* Queuing priority */  \
  4,                                                   /* Activation index */  \
  &OS_TASK_Rte_ChrgTask,                               /* Task entry */  \
  &OS_taskStack_slot5[0],                              /* Stack base */  \
  1168U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Rte_ChrgTask,                                        /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Rte_Event_Task */  \
  &OS_taskDynamic[4],                                  /* Dynamic task structure */  \
  8U,                                                  /* Run priority */  \
  8U,                                                  /* Queuing priority */  \
  5,                                                   /* Activation index */  \
  &OS_TASK_Rte_Event_Task,                             /* Task entry */  \
  &OS_taskStack_slot6[0],                              /* Stack base */  \
  1168U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Rte_Event_Task,                                      /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Rte_Time_Task_10ms */  \
  &OS_taskDynamic[5],                                  /* Dynamic task structure */  \
  9U,                                                  /* Run priority */  \
  9U,                                                  /* Queuing priority */  \
  6,                                                   /* Activation index */  \
  &OS_TASK_Rte_Time_Task_10ms,                         /* Task entry */  \
  &OS_taskStack_slot7[0],                              /* Stack base */  \
  1168U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Rte_Time_Task_10ms,                                  /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Diag_RteTask */  \
  &OS_taskDynamic[6],                                  /* Dynamic task structure */  \
  11U,                                                 /* Run priority */  \
  11U,                                                 /* Queuing priority */  \
  7,                                                   /* Activation index */  \
  &OS_TASK_Diag_RteTask,                               /* Task entry */  \
  &OS_taskStack_slot2[0],                              /* Stack base */  \
  8240U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  Diag_RteTask,                                        /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Init_Task */  \
  &OS_taskDynamic[7],                                  /* Dynamic task structure */  \
  13U,                                                 /* Run priority */  \
  1U,                                                  /* Queuing priority */  \
  8,                                                   /* Activation index */  \
  &OS_TASK_Init_Task,                                  /* Task entry */  \
  &OS_taskStack_slot8[0],                              /* Stack base */  \
  1136U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Init_Task,                                           /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Safety_Task */  \
  &OS_taskDynamic[8],                                  /* Dynamic task structure */  \
  13U,                                                 /* Run priority */  \
  12U,                                                 /* Queuing priority */  \
  9,                                                   /* Activation index */  \
  &OS_TASK_Safety_Task,                                /* Task entry */  \
  &OS_taskStack_slot9[0],                              /* Stack base */  \
  1136U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  Safety_Task,                                         /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* Rte_Background_Task */  \
  &OS_taskDynamic[9],                                  /* Dynamic task structure */  \
  0U,                                                  /* Run priority */  \
  0U,                                                  /* Queuing priority */  \
  10,                                                  /* Activation index */  \
  &OS_TASK_Rte_Background_Task,                        /* Task entry */  \
  &OS_taskStack_slot1[0],                              /* Stack base */  \
  8336U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  Rte_Background_Task,                                 /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  OS_NULL,                                             /* Application */  \
  0x0U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      0  \
    )  \
)
#define OS_TASKACTIVATIONS   \
  /* 0 */ &OS_taskTable[Rte_ModTask],                          \
  /* 1 */ &OS_taskTable[MainFunction_Task],                    \
  /* 2 */ &OS_taskTable[Rte_FastTask],                         \
  /* 3 */ &OS_taskTable[Rte_ChrgTask],                         \
  /* 4 */ &OS_taskTable[Rte_Event_Task],                       \
  /* 5 */ &OS_taskTable[Rte_Time_Task_10ms],                   \
  /* 6 */ &OS_taskTable[Diag_RteTask],                         \
  /* 7 */ &OS_taskTable[Init_Task],                            \
  /* 8 */ &OS_taskTable[Safety_Task],                          \
  /* 9 */ &OS_taskTable[Rte_Background_Task]

#ifdef __cplusplus
}
#endif
#endif  /* OS_CONFIG_H */
