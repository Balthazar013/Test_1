/* board.h - board specific header file for MPC574XP board
**
** CHECK: TABS 4 (see editor commands at end of file)
**
** Copyright 1998-2014 Elektrobit Automotive GmbH
** All rights exclusively reserved for Elektrobit Automotive GmbH,
** unless expressly agreed to otherwise.
** 
** $Id: board.h 18134 2018-03-07 13:04:02Z cfarcas $
*/
#ifndef __BOARD_H__
#define __BOARD_H__

/* frequency of the quartz oscillator installed on the board (XOSC) */
#define BOARD_OSCI_FREQ_HZ    40000000UL
#define BOARD_OSCI_FREQ_MHZ   40UL

/* PLL configuration */
#define BOARD_PLL0_RFDPHI1    9
#define BOARD_PLL0_RFDPHI   2
#define BOARD_PLL0_PREDIV   4
#define BOARD_PLL0_MFD      32

/* selecting XOSC frequency as PLL0 input frequency */
#define BOARD_PLL0_IN_HZ    BOARD_OSCI_FREQ_HZ
#define BOARD_PLL0_VCO_OUT_HZ ((BOARD_PLL0_IN_HZ / BOARD_PLL0_PREDIV) * (2*BOARD_PLL0_MFD))
#define BOARD_PLL0_PHI_OUT_HZ (BOARD_PLL0_VCO_OUT_HZ / (2*BOARD_PLL0_RFDPHI))
#define BOARD_PLL0_PHI1_OUT_HZ  (BOARD_PLL0_VCO_OUT_HZ / (2*BOARD_PLL0_RFDPHI1))

#define BOARD_PLL1_RFDPHI   2
#define BOARD_PLL1_MFD      18

/* selecting XOSC frequency as PLL1 input frequency */
#define BOARD_PLL1_IN_HZ    BOARD_OSCI_FREQ_HZ
#define BOARD_PLL1_VCO_OUT_HZ (BOARD_PLL1_IN_HZ * BOARD_PLL1_MFD)
#define BOARD_PLL1_PHI_OUT_HZ (BOARD_PLL1_VCO_OUT_HZ / (2*BOARD_PLL1_RFDPHI))

#define BOARD_SYSTEM_CLOCK_HZ BOARD_PLL1_PHI_OUT_HZ
#define BOARD_SYSTEM_CLOCK_MHZ  (BOARD_PLL1_PHI_OUT_HZ/1000000)

/* TIME BASE configuration
** Used by timer units: Board currently runs at 80 MHz due to engineering sample CPU
*/
#define BOARD_TMBCLK_MHZ    (BOARD_SYSTEM_CLOCK_MHZ/2)
#define BOARD_TMBCLK_HZ     (BOARD_SYSTEM_CLOCK_HZ/2)


/* Used by timestamp driver and maybe others too.
** This calculation is correct as long as the timebase frequency in MHz is an integer less than 100.
*/
#define OS_PaTimebase_NsToTicks(ns)   ((((ns)/100)*BOARD_TMBCLK_MHZ)/10)
#define OS_PaTimebase_TicksToNs(ticks)  ((((ticks)*100)/BOARD_TMBCLK_MHZ)*10)


/* Timer configuration
** STM Global Timer Prescaler (1-256)
*/
#define OS_STM_PRESCALER  32

/* Configure STM timer to operate in debug mode? */
#define OS_STM_DEBUG_MODE 1

/* STM is clocked by PBRIDGEx_CLK which is SYS_CLK / SC_DC0 (system clock divider 0) */
#define BOARD_STM_CLK_MHZ (BOARD_SYSTEM_CLOCK_MHZ/4)

#include <PA/Os_PA_STMconfig.h>

/* Configuration for PIT timer driver
**
** The PIT runs directly from the system clock (no prescaler)
** This calculation is correct as long as the system frequency in MHz is an integer less than 100.
*/
#define BOARD_PIT_CLOCK_DIVIDER 2
#define OS_PaPit_NsToTicks(ns)      ((((ns)/100)*BOARD_SYSTEM_CLOCK_MHZ/BOARD_PIT_CLOCK_DIVIDER)/10)

#include <PA/Os_PA_PITconfig.h>


/* ASM startup configuration */

/* Derivate supports instruction & data cache so it should be setup at startup.
** #define BOARD_DISABLE_CACHE 1
*/

/* Derivate always runs in lock step mode. An initialisation
** for all register is needed to avoid unexpected system behavior.
*/
#define BOARD_INIT_CPU_REG 1

/* Initialize SRAM. If enabled, cstartup.s will initialize the SRAM according
** to the following settings. This is needed for ECC enabled systems where
** initializing the C bss and data sections is not enough.
** set to 1 to enable initialization, to 0 to disable.
*/
#define INIT_SRAM     1

/* start address of SRAM to initialize */
#define INIT_SRAM_START   0x40000000

/* The bootloader and application are sharing data.
   The size must be defined here. This SRAM must not be initialized during
   startup, if it was a non destructive Reset, because in that case the 
   application has written Data into the shared SRAM */   
#define INIT_NZRAM_SIZE     0x100
/* size of SRAM to initialize */
#define INIT_SRAM_SIZE    (0x60000 - INIT_NZRAM_SIZE)

/* start address of shared SRAM to initialize  */
#define INIT_NZRAM_START    (0x40050000)
#define INIT_NZRAM_SECTION  0x10000 

/* start address of local SRAM to initialize */
#define INIT_DMEM_START   0x50800000
/* size of local SRAM to initialize */
#define INIT_DMEM_SIZE      0x10000

/* Software watchdog timer */
#define BOARD_SWT_0     0xFC050000

#define BOARD_SWT_CR    0x00
#define BOARD_SWT_SR    0x10

#define BOARD_SWT_CR_MAP0 (0x80000000UL)
#define BOARD_SWT_CR_RIA  (0x00000100UL)
#define BOARD_SWT_CR_1    (0x00000008UL)
#define BOARD_SWT_CR_FRZ  (0x00000002UL)

#define BOARD_SWT_SR_KEY_1  0xc520
#define BOARD_SWT_SR_KEY_2  0xd928

#define BOARD_SWT0_CR   OS_REG32(BOARD_SWT_0+BOARD_SWT_CR)
#define BOARD_SWT0_SR   OS_REG32(BOARD_SWT_0+BOARD_SWT_SR)


/* LED configuration */

#define BOARD_SIUL2_BASE  0xFFFC0000UL

/* GPIO pin data output registers */
#define BOARD_SIUL2_GPDO(x)     OS_REG8(BOARD_SIUL2_BASE + 0x1300 + (x))
#define BOARD_SIUL2_GPDO_LED0   BOARD_SIUL2_GPDO(0)
#define BOARD_SIUL2_GPDO_LED1   BOARD_SIUL2_GPDO(1)
#define BOARD_SIUL2_GPDO_LED2   BOARD_SIUL2_GPDO(2)
#define BOARD_SIUL2_GPDO_LED3   BOARD_SIUL2_GPDO(3)

/* Multiplexed signal configuration register */
#define BOARD_SIUL2_MSCR(x)     OS_REG32(BOARD_SIUL2_BASE + 0x0240 + (x)*4)
#define BOARD_SIUL2_MSCR_LED0   BOARD_SIUL2_MSCR(0)
#define BOARD_SIUL2_MSCR_LED1   BOARD_SIUL2_MSCR(1)
#define BOARD_SIUL2_MSCR_LED2   BOARD_SIUL2_MSCR(2)
#define BOARD_SIUL2_MSCR_LED3   BOARD_SIUL2_MSCR(3)

#define BOARD_SIUL2_MSCR_SRC_HALF_SR  (0x00000000UL)  /* slew rate control - half strength with slew rate control */
#define BOARD_SIUL2_MSCR_SRC_FULL_SR  (0x10000000UL)  /* slew rate control - full strength with slew rate control */
#define BOARD_SIUL2_MSCR_SRC_HALF_NOSR  (0x20000000UL)  /* slew rate control - half strength no slew rate control */
#define BOARD_SIUL2_MSCR_SRC_FULL_NOSR  (0x30000000UL)  /* slew rate control - full strength no slew rate control */
#define BOARD_SIUL2_MSCR_OBE      (0x02000000UL)  /* output buffer enable */
#define BOARD_SIUL2_MSCR_ODE      (0x01000000UL)  /* open drain enable */
#define BOARD_SIUL2_MSCR_SMC      (0x00800000UL)  /* safe mode control (don't disable in safe mode) */
#define BOARD_SIUL2_MSCR_APC      (0x00400000UL)  /* analog pad control (enables analog input path) */
#define BOARD_SIUL2_MSCR_IBE      (0x00080000UL)  /* input buffer enable */
#define BOARD_SIUL2_MSCR_HYS      (0x00040000UL)  /* input hysteresis (enable) */
#define BOARD_SIUL2_MSCR_PUS      (0x00020000UL)  /* pull select (1 == pull up; 0 == pull down) */
#define BOARD_SIUL2_MSCR_PUE      (0x00010000UL)  /* pull enable */
#define BOARD_SIUL2_MSCR_INV      (0x00008000UL)  /* invert signal */
#define BOARD_SIUL2_MSCR_SSS      (0x00000000UL)  /* source signal select - pin dependent! */

#define BOARD_SIUL2_MSCR_SSS_IO     (0x00000000UL)  /* source signal select - GPIO */
#define BOARD_SIUL2_MSCR_SSS_SYSCLK   (0x00000001UL)  /* source signal select - GPIO */


#define BOARD_LED_PORT_INIT (BOARD_SIUL2_MSCR_SRC_FULL_SR|BOARD_SIUL2_MSCR_OBE|BOARD_SIUL2_MSCR_SSS_IO)
#define BOARD_LED_ON    (0x00)
#define BOARD_LED_OFF   (0x01)


#define LEDS_SET(x) \
do \
{ \
  BOARD_SIUL2_GPDO_LED0 = ((((x) & 0x8) == 0) ? BOARD_LED_ON : BOARD_LED_OFF); \
  BOARD_SIUL2_GPDO_LED1 = ((((x) & 0x4) == 0) ? BOARD_LED_ON : BOARD_LED_OFF); \
  BOARD_SIUL2_GPDO_LED2 = ((((x) & 0x2) == 0) ? BOARD_LED_ON : BOARD_LED_OFF); \
  BOARD_SIUL2_GPDO_LED3 = ((((x) & 0x1) == 0) ? BOARD_LED_ON : BOARD_LED_OFF); \
} \
while ( 0 )

#define LEDS_INIT() \
do { \
  BOARD_SIUL2_GPDO_LED0 = BOARD_LED_OFF;  \
  BOARD_SIUL2_GPDO_LED1 = BOARD_LED_OFF;  \
  BOARD_SIUL2_GPDO_LED2 = BOARD_LED_OFF;  \
  BOARD_SIUL2_GPDO_LED3 = BOARD_LED_OFF;  \
  BOARD_SIUL2_MSCR_LED0 = BOARD_LED_PORT_INIT;  \
  BOARD_SIUL2_MSCR_LED1 = BOARD_LED_PORT_INIT;  \
  BOARD_SIUL2_MSCR_LED2 = BOARD_LED_PORT_INIT;  \
  BOARD_SIUL2_MSCR_LED3 = BOARD_LED_PORT_INIT;  \
} while (0)

#endif

/* Editor settings: DO NOT DELETE
 * vi:set ts=4:
*/
