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

#ifndef OS_USER_H
#define OS_USER_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_H 0x893c8559UL

#define OS_AUTOSAROS_VER 4

#define OS_AUTOSAROS_REV 5

#define OS_AUTOSAROS_CORE_BUILD 20140813

#define OS_AUTOSAROS_ARCH_BUILD 20140813

#ifndef OS_INTERRUPT_KEYWORD
#define OS_INTERRUPT_KEYWORD
#endif

#include <Os_autosar.h>
/*===================================================================
 * Alarms
 *==================================================================*/

#define AlarmIncrementRteCounter 0
#define AlarmIncrementSwCounter 1
#define Rte_TimeoutAlarm_2 2
#define Rte_TimeoutAlarm_1 3

/*===================================================================
 * Application modes
 *==================================================================*/

#define OSDEFAULTAPPMODE 0
#define OsAppMode 1
/*===================================================================
 * Counters
 *==================================================================*/

#define OSMAXALLOWEDVALUE_HwCounter 4294967295
#define OSTICKSPERBASE_HwCounter 30000
#define OSMINCYCLE_HwCounter 1
#ifndef OS_ASM
extern void OS_CounterIsr_HwCounter(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_HwCounter(x) OS_NsToTicks_TIMER_STM_0((x))
#define OS_TicksToNs_HwCounter(x) OS_TicksToNs_TIMER_STM_0((x))
#define OS_TICKS2NS_HwCounter(x) (OS_TicksToNs_TIMER_STM_0((x)))
#define OS_TICKS2US_HwCounter(x) (OS_TicksToNs_TIMER_STM_0((x))/1000)
#define OS_TICKS2MS_HwCounter(x) (OS_TicksToNs_TIMER_STM_0((x))/1000000)
#define OS_TICKS2SEC_HwCounter(x) (OS_TicksToNs_TIMER_STM_0((x))/1000000000)
#define OSMAXALLOWEDVALUE_Rte_Counter 4294967295
#define OSTICKSPERBASE_Rte_Counter 1000
#define OSMINCYCLE_Rte_Counter 1
#define OS_NsToTicks_Rte_Counter(x) ((x)/1000000)
#define OS_TicksToNs_Rte_Counter(x) ((x)*1000000)
#define OS_TICKS2NS_Rte_Counter(x) (OS_TicksToNs_Rte_Counter((x)))
#define OS_TICKS2US_Rte_Counter(x) (OS_TicksToNs_Rte_Counter((x)))/1000
#define OS_TICKS2MS_Rte_Counter(x) (OS_TicksToNs_Rte_Counter((x)))/1000000
#define OS_TICKS2SEC_Rte_Counter(x) (OS_TicksToNs_Rte_Counter((x)))/1000000000
#define OSMAXALLOWEDVALUE_SwCounter 4294967295
#define OSTICKSPERBASE_SwCounter 1000
#define OSMINCYCLE_SwCounter 1
#define HwCounter 0
#define Rte_Counter 1
#define SwCounter 2
#define OSMAXALLOWEDVALUE OSMAXALLOWEDVALUE_HwCounter
#define OSTICKSPERBASE OSTICKSPERBASE_HwCounter
#define OSMINCYCLE OSMINCYCLE_HwCounter
#define OSTICKDURATION OS_TicksToNs_HwCounter(1)

/*===================================================================
 * Events
 *==================================================================*/

#define Rte_OSTimingEvent_3_6  0x0001u
#define Rte_OSResolveWaitPointEvent  0x0002u
#define Rte_OSTimingEvent_6_0  0x0001u
#define Rte_OSTimingEvent_6_1  0x0002u
#define Rte_OSTimeoutEvent  0x0004u
#define Rte_OSTriggerExecutableEvent_1_0  0x0001u
#define Rte_OSTimingEvent_3_3  0x0008u
#define Rte_OSTimingEvent_3_4  0x0010u
#define Rte_OSTimingEvent_3_5  0x0020u
#define Rte_OSTimingEvent_1_6  0x0040u
#define SchM_OSShutdownEvent  0x0080u
#define Rte_OSTimingEvent_0_0  0x0100u
#define Rte_OSTimingEvent_0_1  0x0200u
#define Rte_OSTimingEvent_0_2  0x0400u
#define Rte_OSTimingEvent_1_0  0x0800u
#define Rte_OSTimingEvent_1_1  0x01000u
#define Rte_OSTimingEvent_1_2  0x02000u
#define Rte_OSTimingEvent_2_0  0x0001u
#define Rte_OSTimingEvent_2_1  0x0008u
#define Rte_OSTimingEvent_3_0  0x0001u
#define Rte_OSTimingEvent_3_1  0x0002u
#define Rte_OSShutdownEvent  0x0001u
#define Rte_OSTriggerExecutableEvent_4_0  0x0002u
#define Rte_OSTriggerExecutableEvent_4_1  0x0004u
#define Rte_OSTriggerExecutableEvent_4_2  0x0008u
#define Rte_OSTriggerExecutableEvent_4_3  0x0010u
#define Rte_OSTriggerExecutableEvent_4_4  0x0020u
#define Rte_OSTriggerExecutableEvent_4_5  0x0040u
#define Rte_OSTriggerExecutableEvent_4_6  0x0080u
#define Rte_OSTriggerExecutableEvent_4_7  0x0100u
#define Rte_OSTriggerExecutableEvent_7_0  0x0002u
#define Rte_OSTriggerExecutableEvent_7_1  0x0004u
#define Rte_OSTriggerExecutableEvent_7_2  0x0008u
#define Rte_OSTriggerExecutableEvent_7_3  0x0010u
#define Rte_OSTriggerExecutableEvent_7_4  0x0020u
#define Rte_OSTriggerExecutableEvent_7_5  0x0040u
#define Rte_OSTriggerExecutableEvent_7_6  0x0080u
#define Rte_OSTriggerExecutableEvent_7_7  0x0100u
#define Rte_OSTriggerExecutableEvent_7_8  0x0200u
#define Rte_OSTriggerExecutableEvent_7_9  0x0400u
#define Rte_OSTriggerExecutableEvent_7_10  0x0800u
#define Rte_OSTimingEvent_1_3  0x04000u
#define Rte_OSTimingEvent_1_4  0x08000u
#define Rte_OSTimingEvent_3_2  0x0004u
#define Rte_OSTriggerExecutableEvent_4_8  0x0200u

/*===================================================================
 * Interrupts
 *==================================================================*/

#ifndef OS_ASM
extern void OS_ISR_CanBusOffIsr_0(void);
#endif  /* OS_ASM */
#define CanBusOffIsr_0_ISR_CATEGORY 2
#define CanBusOffIsr_0_ISR_VECTOR 521
#define CanBusOffIsr_0_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_00_03(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_00_03_ISR_CATEGORY 2
#define CanMailboxIsr_0_00_03_ISR_VECTOR 522
#define CanMailboxIsr_0_00_03_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_04_07(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_04_07_ISR_CATEGORY 2
#define CanMailboxIsr_0_04_07_ISR_VECTOR 523
#define CanMailboxIsr_0_04_07_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_08_11(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_08_11_ISR_CATEGORY 2
#define CanMailboxIsr_0_08_11_ISR_VECTOR 524
#define CanMailboxIsr_0_08_11_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_12_15(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_12_15_ISR_CATEGORY 2
#define CanMailboxIsr_0_12_15_ISR_VECTOR 525
#define CanMailboxIsr_0_12_15_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_16_31(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_16_31_ISR_CATEGORY 2
#define CanMailboxIsr_0_16_31_ISR_VECTOR 526
#define CanMailboxIsr_0_16_31_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_32_39(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_32_39_ISR_CATEGORY 2
#define CanMailboxIsr_0_32_39_ISR_VECTOR 527
#define CanMailboxIsr_0_32_39_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_40_47(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_40_47_ISR_CATEGORY 2
#define CanMailboxIsr_0_40_47_ISR_VECTOR 528
#define CanMailboxIsr_0_40_47_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_48_55(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_48_55_ISR_CATEGORY 2
#define CanMailboxIsr_0_48_55_ISR_VECTOR 529
#define CanMailboxIsr_0_48_55_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_0_56_63(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_0_56_63_ISR_CATEGORY 2
#define CanMailboxIsr_0_56_63_ISR_VECTOR 530
#define CanMailboxIsr_0_56_63_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_Spi_Dspi_IsrTCF_DSPI_0(void);
#endif  /* OS_ASM */
#define Spi_Dspi_IsrTCF_DSPI_0_ISR_CATEGORY 2
#define Spi_Dspi_IsrTCF_DSPI_0_ISR_VECTOR 262
#define Spi_Dspi_IsrTCF_DSPI_0_ISR_LEVEL 3
#ifndef OS_ASM
extern void OS_ISR_Spi_Dspi_IsrTCF_DSPI_2(void);
#endif  /* OS_ASM */
#define Spi_Dspi_IsrTCF_DSPI_2_ISR_CATEGORY 2
#define Spi_Dspi_IsrTCF_DSPI_2_ISR_VECTOR 280
#define Spi_Dspi_IsrTCF_DSPI_2_ISR_LEVEL 3
#ifndef OS_ASM
extern void OS_ISR_Spi_Dspi_IsrTCF_DSPI_3(void);
#endif  /* OS_ASM */
#define Spi_Dspi_IsrTCF_DSPI_3_ISR_CATEGORY 2
#define Spi_Dspi_IsrTCF_DSPI_3_ISR_VECTOR 287
#define Spi_Dspi_IsrTCF_DSPI_3_ISR_LEVEL 3
#ifndef OS_ASM
extern OS_INTERRUPT_KEYWORD void OS_ISR_FLEXPWM_1_SUBMOD_0_REL_ISR(void);
#endif  /* OS_ASM */
#define FLEXPWM_1_SUBMOD_0_REL_ISR_ISR_CATEGORY 1
#define FLEXPWM_1_SUBMOD_0_REL_ISR_ISR_VECTOR 670
#define FLEXPWM_1_SUBMOD_0_REL_ISR_ISR_LEVEL 5
#ifndef OS_ASM
extern void OS_ISR_CanBusOffIsr_1(void);
#endif  /* OS_ASM */
#define CanBusOffIsr_1_ISR_CATEGORY 2
#define CanBusOffIsr_1_ISR_VECTOR 534
#define CanBusOffIsr_1_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_00_03(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_00_03_ISR_CATEGORY 2
#define CanMailboxIsr_1_00_03_ISR_VECTOR 535
#define CanMailboxIsr_1_00_03_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_04_07(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_04_07_ISR_CATEGORY 2
#define CanMailboxIsr_1_04_07_ISR_VECTOR 536
#define CanMailboxIsr_1_04_07_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_08_11(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_08_11_ISR_CATEGORY 2
#define CanMailboxIsr_1_08_11_ISR_VECTOR 537
#define CanMailboxIsr_1_08_11_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_12_15(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_12_15_ISR_CATEGORY 2
#define CanMailboxIsr_1_12_15_ISR_VECTOR 538
#define CanMailboxIsr_1_12_15_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_16_31(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_16_31_ISR_CATEGORY 2
#define CanMailboxIsr_1_16_31_ISR_VECTOR 539
#define CanMailboxIsr_1_16_31_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_32_39(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_32_39_ISR_CATEGORY 2
#define CanMailboxIsr_1_32_39_ISR_VECTOR 540
#define CanMailboxIsr_1_32_39_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_40_47(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_40_47_ISR_CATEGORY 2
#define CanMailboxIsr_1_40_47_ISR_VECTOR 541
#define CanMailboxIsr_1_40_47_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_48_55(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_48_55_ISR_CATEGORY 2
#define CanMailboxIsr_1_48_55_ISR_VECTOR 542
#define CanMailboxIsr_1_48_55_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_CanMailboxIsr_1_56_63(void);
#endif  /* OS_ASM */
#define CanMailboxIsr_1_56_63_ISR_CATEGORY 2
#define CanMailboxIsr_1_56_63_ISR_VECTOR 543
#define CanMailboxIsr_1_56_63_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_MCL_DMA_CH_7_ISR(void);
#endif  /* OS_ASM */
#define MCL_DMA_CH_7_ISR_ISR_CATEGORY 2
#define MCL_DMA_CH_7_ISR_ISR_VECTOR 60
#define MCL_DMA_CH_7_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_MCL_DMA_CH_23_ISR(void);
#endif  /* OS_ASM */
#define MCL_DMA_CH_23_ISR_ISR_CATEGORY 2
#define MCL_DMA_CH_23_ISR_ISR_VECTOR 76
#define MCL_DMA_CH_23_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_MCL_DMA_CH_25_ISR(void);
#endif  /* OS_ASM */
#define MCL_DMA_CH_25_ISR_ISR_CATEGORY 2
#define MCL_DMA_CH_25_ISR_ISR_VECTOR 78
#define MCL_DMA_CH_25_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_MCL_DMA_CH_26_ISR(void);
#endif  /* OS_ASM */
#define MCL_DMA_CH_26_ISR_ISR_CATEGORY 2
#define MCL_DMA_CH_26_ISR_ISR_VECTOR 79
#define MCL_DMA_CH_26_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern OS_INTERRUPT_KEYWORD void OS_ISR_Adc_Adcdig_WatchDogThresholdUnit2(void);
#endif  /* OS_ASM */
#define Adc_Adcdig_WatchDogThresholdUnit2_ISR_CATEGORY 1
#define Adc_Adcdig_WatchDogThresholdUnit2_ISR_VECTOR 506
#define Adc_Adcdig_WatchDogThresholdUnit2_ISR_LEVEL 4
#ifndef OS_ASM
extern OS_INTERRUPT_KEYWORD void OS_ISR_Adc_Adcdig_WatchDogThresholdUnit3(void);
#endif  /* OS_ASM */
#define Adc_Adcdig_WatchDogThresholdUnit3_ISR_CATEGORY 1
#define Adc_Adcdig_WatchDogThresholdUnit3_ISR_VECTOR 510
#define Adc_Adcdig_WatchDogThresholdUnit3_ISR_LEVEL 4
#ifndef OS_ASM
extern void OS_ISR_Gpt_PIT_0_TIMER_0_ISR(void);
#endif  /* OS_ASM */
#define Gpt_PIT_0_TIMER_0_ISR_ISR_CATEGORY 2
#define Gpt_PIT_0_TIMER_0_ISR_ISR_VECTOR 226
#define Gpt_PIT_0_TIMER_0_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_Gpt_PIT_0_TIMER_1_ISR(void);
#endif  /* OS_ASM */
#define Gpt_PIT_0_TIMER_1_ISR_ISR_CATEGORY 2
#define Gpt_PIT_0_TIMER_1_ISR_ISR_VECTOR 227
#define Gpt_PIT_0_TIMER_1_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_MCL_DMA_CH_12_ISR(void);
#endif  /* OS_ASM */
#define MCL_DMA_CH_12_ISR_ISR_CATEGORY 2
#define MCL_DMA_CH_12_ISR_ISR_VECTOR 65
#define MCL_DMA_CH_12_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_MCL_DMA_CH_13_ISR(void);
#endif  /* OS_ASM */
#define MCL_DMA_CH_13_ISR_ISR_CATEGORY 2
#define MCL_DMA_CH_13_ISR_ISR_VECTOR 66
#define MCL_DMA_CH_13_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_SIUL2_EXT_IRQ_16_23_ISR(void);
#endif  /* OS_ASM */
#define SIUL2_EXT_IRQ_16_23_ISR_ISR_CATEGORY 2
#define SIUL2_EXT_IRQ_16_23_ISR_ISR_VECTOR 245
#define SIUL2_EXT_IRQ_16_23_ISR_ISR_LEVEL 2
#define Os_Counter_TIMER_STM_0_ISR_CATEGORY 2
#define Os_Counter_TIMER_STM_0_ISR_VECTOR 36
#define Os_Counter_TIMER_STM_0_ISR_LEVEL 1
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanBusOffIsr_0 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_00_03 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_04_07 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_08_11 3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_12_15 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_16_31 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_32_39 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_40_47 7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_48_55 8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_0_56_63 9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Spi_Dspi_IsrTCF_DSPI_0 10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Spi_Dspi_IsrTCF_DSPI_2 11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Spi_Dspi_IsrTCF_DSPI_3 12
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define FLEXPWM_1_SUBMOD_0_REL_ISR 13
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanBusOffIsr_1 14
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_00_03 15
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_04_07 16
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_08_11 17
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_12_15 18
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_16_31 19
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_32_39 20
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_40_47 21
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_48_55 22
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CanMailboxIsr_1_56_63 23
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define MCL_DMA_CH_7_ISR 24
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define MCL_DMA_CH_23_ISR 25
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define MCL_DMA_CH_25_ISR 26
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define MCL_DMA_CH_26_ISR 27
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Adc_Adcdig_WatchDogThresholdUnit2 28
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Adc_Adcdig_WatchDogThresholdUnit3 29
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Gpt_PIT_0_TIMER_0_ISR 30
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Gpt_PIT_0_TIMER_1_ISR 31
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define MCL_DMA_CH_12_ISR 32
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define MCL_DMA_CH_13_ISR 33
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define SIUL2_EXT_IRQ_16_23_ISR 34
#endif

/*===================================================================
 * Resources
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_0 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_1 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_2 3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_3 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_4 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_5 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_6 7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_7 8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_8 9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_9 10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_10 11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Res_11 12
#endif

/*===================================================================
 * Schedule Tables
 *==================================================================*/

#define SchM_DefaultScheduleTable 0
#define Rte_DefaultScheduleTable 1
/*===================================================================
 * Tasks
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_ModTask 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define MainFunction_Task 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_FastTask 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_ChrgTask 3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Event_Task 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Time_Task_10ms 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Diag_RteTask 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Init_Task 7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Safety_Task 8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Rte_Background_Task 9
#endif

/*===================================================================
 * Timestamp timer
 *==================================================================*/

#define OS_TimestampNsToTicks(ns) OS_NsToTicks_TbTimer(ns)
#define OS_TimestampTicksToNs(ticks) OS_TicksToNs_TbTimer(ticks)
#ifdef __cplusplus
}
#endif
#endif  /* OS_USER_H */
