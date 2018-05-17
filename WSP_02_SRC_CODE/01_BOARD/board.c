/* board.c - board specific startup file for EvaMPC574XP board
**
** CHECK: TABS 4 (see editor commands at end of file)
**
** Copyright 1998-2014 Elektrobit Automotive GmbH
** All rights exclusively reserved for Elektrobit Automotive GmbH,
** unless expressly agreed to otherwise.
**
** $Id: board.c 18134 2018-03-07 13:04:02Z cfarcas $
*/
#include <Os.h>
#include <board.h>
#include <PA/Os_PA_magiccarpet.h>

/*******************************************************************************
 * check PLL settings
 ******************************************************************************/

/* check PLL0 settings */
#if (BOARD_PLL0_RFDPHI1 < 4) || (BOARD_PLL0_RFDPHI1 > 15)
#error "BOARD_PLL0_RFDPHI1 not in range."
#endif
#if (BOARD_PLL0_RFDPHI < 1) || (BOARD_PLL0_RFDPHI > 63)
#error "BOARD_PLL0_RFDPHI not in range."
#endif
#if (BOARD_PLL0_PREDIV < 1) || (BOARD_PLL0_PREDIV > 7)
#error "BOARD_PLL0_PREDIV not in range."
#endif
#if (BOARD_PLL0_MFD < 8) || (BOARD_PLL0_MFD > 127)
#error "BOARD_PLL0_MFD not in range."
#endif

/* check PLL0 input frequency */
#if (BOARD_OSCI_FREQ_HZ < 8000000) || (BOARD_OSCI_FREQ_HZ > 56000000)
#error "PLL0 input frequency BOARD_OSCI_FREQ_HZ out of range."
#endif

/* check PLL0 VCO frequency */
#if (BOARD_PLL0_VCO_OUT_HZ < 600000000) || (BOARD_PLL0_VCO_OUT_HZ > 1250000000)
#error "PLL0 VCO output frequency out of range."
#endif

/* check PLL0 PHI output frequency */
#if (BOARD_PLL0_PHI_OUT_HZ < 40000000) || (BOARD_PLL0_PHI_OUT_HZ > 180000000)
#error "PLL0 PHI output frequency out of range."
#endif

/* check PLL0 PHI1 output frequency */
#if (BOARD_PLL0_PHI1_OUT_HZ < 20000000) || (BOARD_PLL0_PHI1_OUT_HZ > 156000000)
#error "PLL0 PHI1 output frequency out of range."
#endif


/* check PLL1 settings */
#if (BOARD_PLL1_RFDPHI < 1) || (BOARD_PLL1_RFDPHI > 63)
#error "BOARD_PLL0_RFDPHI not in range."
#endif
#if (BOARD_PLL1_MFD < 16) || (BOARD_PLL1_MFD > 34)
#error "BOARD_PLL1_MFD not in range."
#endif

/* check PLL1 input frequency */
#if (BOARD_PLL1_IN_HZ < 37500000) || (BOARD_PLL1_IN_HZ > 78125000)
#error "PLL1 input frequency BOARD_PLL1_IN_HZ out of range."
#endif

/* check PLL1 VCO frequency */
#if (BOARD_PLL1_VCO_OUT_HZ < 600000000) || (BOARD_PLL1_VCO_OUT_HZ > 1250000000)
#error "PLL1 VCO output frequency out of range."
#endif

/* check PLL1 output frequency */
#if (BOARD_PLL1_PHI_OUT_HZ < 40000000) || (BOARD_PLL1_PHI_OUT_HZ > 180000000)
#error "PLL1 PHI output frequency out of range."
#endif


/*******************************************************************************
 * PLL (phase locked loop) registers, bits used for configuration
 ******************************************************************************/
#define BOARD_PLLDIG_BASE			(0xFFFB0100UL)
#define BOARD_PLLDIG_PLL0CR			OS_REG32(BOARD_PLLDIG_BASE+0x00)
#define BOARD_PLLDIG_PLL0SR			OS_REG32(BOARD_PLLDIG_BASE+0x04)
#define BOARD_PLLDIG_PLL0DV			OS_REG32(BOARD_PLLDIG_BASE+0x08)

#define BOARD_PLLDIG_PLL1CR			OS_REG32(BOARD_PLLDIG_BASE+0x20)
#define BOARD_PLLDIG_PLL1SR			OS_REG32(BOARD_PLLDIG_BASE+0x24)
#define BOARD_PLLDIG_PLL1DV			OS_REG32(BOARD_PLLDIG_BASE+0x28)
#define BOARD_PLLDIG_PLL1FM			OS_REG32(BOARD_PLLDIG_BASE+0x2C)
#define BOARD_PLLDIG_PLL1FD			OS_REG32(BOARD_PLLDIG_BASE+0x30)

#define BOARD_PLLDIG_PLLCR_CLKCFG			(0x00000300UL)
#define BOARD_PLLDIG_PLLCR_CLKCFG_PLL_OFF	(0x00000000UL)
#define BOARD_PLLDIG_PLLCR_CLKCFG_PLL_ON	(0x00000300UL)
#define BOARD_PLLDIG_PLLCR_LOLIE			(0x00000008UL)
#define BOARD_PLLDIG_PLLCR_LOCIE			(0x00000004UL)

#define BOARD_PLLDIG_PLLSR_LOLF				(0x00000008UL)
#define BOARD_PLLDIG_PLLSR_LOCK				(0x00000004UL)

#define BOARD_PLLDIG_PLLDV(rfdphi1,rfdphi,prediv,mfd)	\
	(((rfdphi1)<<27)|((rfdphi)<<16)|((prediv)<<12)|(mfd))


/*******************************************************************************
 * MC_ME (mode control mode entry) registers, bits used for configuration
 ******************************************************************************/
#define BOARD_MC_ME_BASE			(0xFFFB8000UL)
#define BOARD_MC_ME_GS				OS_REG32(BOARD_MC_ME_BASE+0x000)
#define BOARD_MC_ME_MCTL			OS_REG32(BOARD_MC_ME_BASE+0x004)
#define BOARD_MC_ME_ME				OS_REG32(BOARD_MC_ME_BASE+0x008)
#define BOARD_MC_ME_IS				OS_REG32(BOARD_MC_ME_BASE+0x00C)
#define BOARD_MC_ME_IM				OS_REG32(BOARD_MC_ME_BASE+0x010)
#define BOARD_MC_ME_DRUN_MC			OS_REG32(BOARD_MC_ME_BASE+0x02C)
#define BOARD_MC_ME_RUN0_MC			OS_REG32(BOARD_MC_ME_BASE+0x030)
#define BOARD_MC_ME_RUN1_MC			OS_REG32(BOARD_MC_ME_BASE+0x034)
#define BOARD_MC_ME_RUN2_MC			OS_REG32(BOARD_MC_ME_BASE+0x038)
#define BOARD_MC_ME_RUN3_MC			OS_REG32(BOARD_MC_ME_BASE+0x03C)
#define BOARD_MC_ME_HALT0_MC		OS_REG32(BOARD_MC_ME_BASE+0x040)
#define BOARD_MC_ME_STOP0_MC		OS_REG32(BOARD_MC_ME_BASE+0x048)
#define BOARD_MC_ME_RUN_PC0			OS_REG32(BOARD_MC_ME_BASE+0x080)
#define BOARD_MC_ME_RUN_PC1			OS_REG32(BOARD_MC_ME_BASE+0x084)
#define BOARD_MC_ME_RUN_PC2			OS_REG32(BOARD_MC_ME_BASE+0x088)
#define BOARD_MC_ME_RUN_PC3			OS_REG32(BOARD_MC_ME_BASE+0x08C)
#define BOARD_MC_ME_RUN_PC4			OS_REG32(BOARD_MC_ME_BASE+0x090)
#define BOARD_MC_ME_RUN_PC5			OS_REG32(BOARD_MC_ME_BASE+0x094)
#define BOARD_MC_ME_RUN_PC6			OS_REG32(BOARD_MC_ME_BASE+0x098)
#define BOARD_MC_ME_RUN_PC7			OS_REG32(BOARD_MC_ME_BASE+0x09C)
#define BOARD_MC_ME_LP_PC0			OS_REG32(BOARD_MC_ME_BASE+0x0A0)
#define BOARD_MC_ME_LP_PC1			OS_REG32(BOARD_MC_ME_BASE+0x0A4)
#define BOARD_MC_ME_LP_PC2			OS_REG32(BOARD_MC_ME_BASE+0x0A8)
#define BOARD_MC_ME_LP_PC3			OS_REG32(BOARD_MC_ME_BASE+0x0AC)
#define BOARD_MC_ME_LP_PC4			OS_REG32(BOARD_MC_ME_BASE+0x0B0)
#define BOARD_MC_ME_LP_PC5			OS_REG32(BOARD_MC_ME_BASE+0x0B4)
#define BOARD_MC_ME_LP_PC6			OS_REG32(BOARD_MC_ME_BASE+0x0B8)
#define BOARD_MC_ME_LP_PC7			OS_REG32(BOARD_MC_ME_BASE+0x0BC)

#define BOARD_MC_ME_GS_S_MTRANS			(0x08000000UL)
#define BOARD_MC_ME_GS_S_CURRENT_MODE	(0xF0000000UL)
#define BOARD_MC_ME_GS_DRUN				(0x30000000UL)
#define BOARD_MC_ME_GS_RUN0				(0x40000000UL)

#define BOARD_MC_ME_MCTL_MODE_DRUN		(0x30000000UL)
#define BOARD_MC_ME_MCTL_MODE_RUN0		(0x40000000UL)
#define BOARD_MC_ME_MCTL_KEY			(0x00005AF0UL)
#define BOARD_MC_ME_MCTL_KEY_INV		(0x0000A50FUL)

#define BOARD_MC_ME_ME_PC_STOP0			(0x00000400UL)
#define BOARD_MC_ME_ME_PC_HALT0			(0x00000100UL)
#define BOARD_MC_ME_ME_PC_RUN3			(0x00000080UL)
#define BOARD_MC_ME_ME_PC_RUN2			(0x00000040UL)
#define BOARD_MC_ME_ME_PC_RUN1			(0x00000020UL)
#define BOARD_MC_ME_ME_PC_RUN0			(0x00000010UL)
#define BOARD_MC_ME_ME_PC_DRUN			(0x00000008UL)
#define BOARD_MC_ME_ME_PC_SAFE			(0x00000004UL)
#define BOARD_MC_ME_ME_PC_TEST			(0x00000002UL)
#define BOARD_MC_ME_ME_PC_RESET_FUNC	(0x00000001UL)

#define BOARD_MC_ME_ME_ALL_MODES	\
	(BOARD_MC_ME_ME_PC_STOP0|BOARD_MC_ME_ME_PC_HALT0	\
	|BOARD_MC_ME_ME_PC_RUN3|BOARD_MC_ME_ME_PC_RUN2	\
	|BOARD_MC_ME_ME_PC_RUN1|BOARD_MC_ME_ME_PC_TEST)

#define BOARD_MC_ME_IS_I_MTC			(0x00000001UL)

#define BOARD_MC_ME_MC_MVRON			(0x00100000UL)
#define BOARD_MC_ME_MC_FLAON_POWERDOWN	(0x00010000UL)
#define BOARD_MC_ME_MC_FLAON_NORMAL		(0x00030000UL)
#define BOARD_MC_ME_MC_PLL1ON			(0x00000080UL)
#define BOARD_MC_ME_MC_PLL0ON			(0x00000040UL)
#define BOARD_MC_ME_MC_XOSCON			(0x00000020UL)
#define BOARD_MC_ME_MC_IRCON			(0x00000010UL)
#define BOARD_MC_ME_MC_SYSCLK			(0x0000000FUL)
#define BOARD_MC_ME_MC_SYSCLK_IRCOSC	(0x00000000UL)
#define BOARD_MC_ME_MC_SYSCLK_XOSC		(0x00000002UL)
#define BOARD_MC_ME_MC_SYSCLK_PLL0		(0x00000002UL)
#define BOARD_MC_ME_MC_SYSCLK_PLL1		(0x00000004UL)

#define BOARD_MC_ME_MODE_CONFIG_POWERDOWN	\
	( BOARD_MC_ME_MC_MVRON			\
	| BOARD_MC_ME_MC_FLAON_NORMAL	\
	| BOARD_MC_ME_MC_XOSCON			\
	| BOARD_MC_ME_MC_IRCON			\
	| BOARD_MC_ME_MC_SYSCLK_IRCOSC	\
	)
#define BOARD_MC_ME_MODE_CONFIG_LOWPOWER	\
	( BOARD_MC_ME_MC_MVRON			\
	| BOARD_MC_ME_MC_FLAON_NORMAL	\
	| BOARD_MC_ME_MC_PLL1ON			\
	| BOARD_MC_ME_MC_PLL0ON			\
	| BOARD_MC_ME_MC_XOSCON			\
	| BOARD_MC_ME_MC_IRCON			\
	| BOARD_MC_ME_MC_SYSCLK_IRCOSC	\
	)
#define BOARD_MC_ME_MODE_CONFIG_NORMAL	\
	( BOARD_MC_ME_MC_FLAON_NORMAL	\
	| BOARD_MC_ME_MC_PLL1ON			\
	| BOARD_MC_ME_MC_PLL0ON			\
	| BOARD_MC_ME_MC_XOSCON			\
	| BOARD_MC_ME_MC_IRCON			\
	| BOARD_MC_ME_MC_SYSCLK_IRCOSC	\
	)
#define BOARD_MC_ME_MODE_CONFIG_XOSC	\
	( BOARD_MC_ME_MC_MVRON			\
	| BOARD_MC_ME_MC_FLAON_NORMAL	\
	| BOARD_MC_ME_MC_XOSCON			\
	)
#define BOARD_MC_ME_MODE_CONFIG_PLLON	\
	( BOARD_MC_ME_MC_FLAON_NORMAL	\
	| BOARD_MC_ME_MC_PLL1ON			\
	| BOARD_MC_ME_MC_PLL0ON			\
	| BOARD_MC_ME_MC_XOSCON			\
	)

#define BOARD_MC_ME_RUN_PC_RUN3			(0x00000080UL)
#define BOARD_MC_ME_RUN_PC_RUN2			(0x00000040UL)
#define BOARD_MC_ME_RUN_PC_RUN1			(0x00000020UL)
#define BOARD_MC_ME_RUN_PC_RUN0			(0x00000010UL)
#define BOARD_MC_ME_RUN_PC_DRUN			(0x00000008UL)
#define BOARD_MC_ME_RUN_PC_SAFE			(0x00000004UL)
#define BOARD_MC_ME_RUN_PC_TEST			(0x00000002UL)

#define BOARD_MC_ME_RUN_PC_ALL	\
	( BOARD_MC_ME_RUN_PC_RUN3	\
	| BOARD_MC_ME_RUN_PC_RUN2	\
	| BOARD_MC_ME_RUN_PC_RUN1	\
	| BOARD_MC_ME_RUN_PC_RUN0	\
	| BOARD_MC_ME_RUN_PC_DRUN	\
	| BOARD_MC_ME_RUN_PC_SAFE	\
	| BOARD_MC_ME_RUN_PC_TEST	\
	)

#define BOARD_MC_ME_LP_PC_STOP0			(0x00000400UL)
#define BOARD_MC_ME_LP_PC_HALT0			(0x00000100UL)

#define BOARD_MC_ME_LP_PC_ALL	(BOARD_MC_ME_LP_PC_STOP0|BOARD_MC_ME_LP_PC_HALT0)


/*******************************************************************************
 * MC_CGM (mode control clock generation module) registers, bits used for configuration
 ******************************************************************************/
#define BOARD_MC_CGM_BASE			(0xFFFB0000UL)
#define BOARD_MC_CGM_SC_DC0			OS_REG32(BOARD_MC_CGM_BASE+0x7E8)
#define BOARD_MC_CGM_AC0_SC			OS_REG32(BOARD_MC_CGM_BASE+0x800)
#define BOARD_MC_CGM_AC0_DC0		OS_REG32(BOARD_MC_CGM_BASE+0x808)
#define BOARD_MC_CGM_AC0_DC1		OS_REG32(BOARD_MC_CGM_BASE+0x80C)
#define BOARD_MC_CGM_AC0_DC2		OS_REG32(BOARD_MC_CGM_BASE+0x810)
#define BOARD_MC_CGM_AC1_DC0		OS_REG32(BOARD_MC_CGM_BASE+0x828)
#define BOARD_MC_CGM_AC1_DC1		OS_REG32(BOARD_MC_CGM_BASE+0x82C)
#define BOARD_MC_CGM_AC2_DC0		OS_REG32(BOARD_MC_CGM_BASE+0x848)
#define BOARD_MC_CGM_AC3_SC			OS_REG32(BOARD_MC_CGM_BASE+0x860)
#define BOARD_MC_CGM_AC4_SC			OS_REG32(BOARD_MC_CGM_BASE+0x880)
#define BOARD_MC_CGM_AC5_SC			OS_REG32(BOARD_MC_CGM_BASE+0x8A0)
#define BOARD_MC_CGM_AC5_DC0		OS_REG32(BOARD_MC_CGM_BASE+0x8A8)
#define BOARD_MC_CGM_AC6_SC			OS_REG32(BOARD_MC_CGM_BASE+0x8C0)
#define BOARD_MC_CGM_AC6_DC0		OS_REG32(BOARD_MC_CGM_BASE+0x8C8)

#define BOARD_MC_CGM_SC_DC_DE		(0x80000000UL)
#define BOARD_MC_CGM_SC_DC_DIV		(0x003F0000UL)
#define BOARD_MC_CGM_SC_DC_DIV1		(0x00000000UL)
#define BOARD_MC_CGM_SC_DC_DIV2		(0x00010000UL)
#define BOARD_MC_CGM_SC_DC_DIV3		(0x00020000UL)
#define BOARD_MC_CGM_SC_DC_DIV4		(0x00030000UL)
#define BOARD_MC_CGM_SC_DC_DIV5		(0x00040000UL)
#define BOARD_MC_CGM_SC_DC_DIV6		(0x00050000UL)
#define BOARD_MC_CGM_SC_DC_DIV7		(0x00060000UL)
#define BOARD_MC_CGM_SC_DC_DIV8		(0x00070000UL)

#define BOARD_MC_CGM_AC0_SC_SELCTL		(0x03000000UL)
#define BOARD_MC_CGM_AC0_SC_SELCTL_IRC	(0x00000000UL)
#define BOARD_MC_CGM_AC0_SC_SELCTL_XOSC	(0x01000000UL)
#define BOARD_MC_CGM_AC0_SC_SELCTL_PLL0	(0x02000000UL)

#define BOARD_MC_CGM_AC_DC_DE		(0x80000000UL)
#define BOARD_MC_CGM_AC_DC_DIV		(0x003F0000UL)
#define BOARD_MC_CGM_AC_DC_DIV1		(0x00000000UL)
#define BOARD_MC_CGM_AC_DC_DIV2		(0x00010000UL)
#define BOARD_MC_CGM_AC_DC_DIV3		(0x00020000UL)
#define BOARD_MC_CGM_AC_DC_DIV4		(0x00030000UL)
#define BOARD_MC_CGM_AC_DC_DIV5		(0x00040000UL)
#define BOARD_MC_CGM_AC_DC_DIV6		(0x00050000UL)
#define BOARD_MC_CGM_AC_DC_DIV7		(0x00060000UL)
#define BOARD_MC_CGM_AC_DC_DIV8		(0x00070000UL)

#define BOARD_MC_CGM_AC3_SC_SELCTL		(0x01000000UL)
#define BOARD_MC_CGM_AC3_SC_SELCTL_IRC	(0x00000000UL)
#define BOARD_MC_CGM_AC3_SC_SELCTL_XOSC	(0x01000000UL)

#define BOARD_MC_CGM_AC4_SC_SELCTL		(0x03000000UL)
#define BOARD_MC_CGM_AC4_SC_SELCTL_XOSC	(0x01000000UL)
#define BOARD_MC_CGM_AC4_SC_SELCTL_PLL0	(0x02000000UL)

#define BOARD_MC_CGM_AC5_SC_SELCTL		(0x03000000UL)
#define BOARD_MC_CGM_AC5_SC_SELCTL_XOSC	(0x01000000UL)
#define BOARD_MC_CGM_AC5_SC_SELCTL_PLL0	(0x02000000UL)
#define BOARD_MC_CGM_AC5_SC_SELCTL_LFST	(0x05000000UL)

#define BOARD_MC_CGM_AC6_SC_SELCTL		(0x03000000UL)
#define BOARD_MC_CGM_AC6_SC_SELCTL_IRC	(0x00000000UL)
#define BOARD_MC_CGM_AC6_SC_SELCTL_XOSC	(0x01000000UL)
#define BOARD_MC_CGM_AC6_SC_SELCTL_PLL0	(0x02000000UL)
#define BOARD_MC_CGM_AC6_SC_SELCTL_PLL1	(0x04000000UL)


/*******************************************************************************
 * MC_RGM (mode control reset generation module) registers, bits used for configuration
 ******************************************************************************/
#define BOARD_MC_RGM_BASE			(0xFFFA8000UL)
#define BOARD_MC_RGM_DES			OS_REG32(BOARD_MC_RGM_BASE+0x0)
#define BOARD_MC_RGM_FES			OS_REG32(BOARD_MC_RGM_BASE+0x300)


/*******************************************************************************
 * PFLASH (platform flash memory controller) registers, bits used for configuration
 ******************************************************************************/
#define BOARD_PFLASH_BASE			(0xFC030000UL)
#define BOARD_PFLASH_PFCR1			OS_REG32(BOARD_PFLASH_BASE+0x0UL)

#define BOARD_PFLASH_PFCR1_APC		(0x0000E000UL)
#define BOARD_PFLASH_PFCR1_APC_CYC1	(0x00002000UL)
#define BOARD_PFLASH_PFCR1_RWSC		(0x00001F00UL)
#define BOARD_PFLASH_PFCR1_RWSC_WS2	(0x00000500UL)


/*******************************************************************************
 * XOSC (OSC Digital Interface) registers, bits used for configuration
 ******************************************************************************/
#define BOARD_XOSC_BASE				(0xFFFB0080UL)
#define BOARD_XOSC_CTL				OS_REG32(BOARD_XOSC_BASE+0x0UL)

#define BOARD_XOSC_CTL_OSCBYP		(0x80000000UL)
#define BOARD_XOSC_CTL_OSCM			(0x40000000UL)
#define BOARD_XOSC_CTL_MON			(0x20000000UL)
#define BOARD_XOSC_CTL_EOCV			(0x00FF0000UL)
#define BOARD_XOSC_CTL_M_OSC		(0x00008000UL)
#define BOARD_XOSC_CTL_I_OSC		(0x00000080UL)

#define BOARD_XOSC_CTL_EOCV_48		(0x00300000UL)


/*******************************************************************************
 * FCCU (Fault Collection and Control Unit) registers, bits used for configuration
 ******************************************************************************/
#define BOARD_FCCU_BASE				(0xFBF58000UL)
#define BOARD_FCCU_CTRL				OS_REG32(BOARD_FCCU_BASE+0x000UL)
#define BOARD_FCCU_CTRLK			OS_REG32(BOARD_FCCU_BASE+0x004UL)
#define BOARD_FCCU_NCF_E0			OS_REG32(BOARD_FCCU_BASE+0x094UL)
#define BOARD_FCCU_NCF_E1			OS_REG32(BOARD_FCCU_BASE+0x098UL)
#define BOARD_FCCU_NCF_E2			OS_REG32(BOARD_FCCU_BASE+0x09CUL)
#define BOARD_FCCU_CFG_TO			OS_REG32(BOARD_FCCU_BASE+0x0B8UL)
#define BOARD_FCCU_TRANS_LOCK		OS_REG32(BOARD_FCCU_BASE+0x0F0UL)
#define BOARD_FCCU_IRQ_ALARM_EN0	OS_REG32(BOARD_FCCU_BASE+0x0FCUL)
#define BOARD_FCCU_IRQ_ALARM_EN1	OS_REG32(BOARD_FCCU_BASE+0x100UL)
#define BOARD_FCCU_IRQ_ALARM_EN2	OS_REG32(BOARD_FCCU_BASE+0x104UL)
#define BOARD_FCCU_NMI_EN0			OS_REG32(BOARD_FCCU_BASE+0x10CUL)
#define BOARD_FCCU_NMI_EN1			OS_REG32(BOARD_FCCU_BASE+0x110UL)
#define BOARD_FCCU_NMI_EN2			OS_REG32(BOARD_FCCU_BASE+0x114UL)

#define BOARD_FCCU_CTRL_CONFIG		(0x00000001UL)
#define BOARD_FCCU_CTRL_NORMAL		(0x00000002UL)

#define BOARD_FCCU_CTRLK_CONFIG_KEY	(0x913756AFUL)
#define BOARD_FCCU_CTRLK_NORMAL_KEY	(0x825A132BUL)

#define BOARD_FCCU_TRANS_LOCK_KEY	(0x000000BCUL)


#ifdef  OS_TESTSUITE_IS_RUNNING_
#include <osektest.h>
#endif


/*
** HwInit()
**
** HwInit() is called directly after startup before RAM memory is accessed.
** It can be used to set up external RAM, ROM, FLASH etc.
*/
void HwInit( void ); /* MISRA */
void HwInit( void )
{
	/* clear reset event status for later mode switching
	** Note: Run mode switch into safe mode is not possible while
	**       safe mode interrupt pending flag is set
	*/
	BOARD_MC_RGM_DES = 0xFFFFFFFF; /* clear destructive event reset reason (write 1 to clear) */
	BOARD_MC_RGM_FES = 0xFFFFFFFF; /* clear functional event reset reason (write 1 to clear) */
}

/*
** BoardInit()
**
** BoardInit() is called by the startup code (cstartup.s) after data and bss
** sections have been initialized (global variables may now be used).
** The BoardInit() can be used to start up drivers etc.
*/
void BoardInit(void); /* MISRA */
void BoardInit(void)
{
	/* disable watchdog */
	BOARD_SWT0_SR = BOARD_SWT_SR_KEY_1;
	BOARD_SWT0_SR = BOARD_SWT_SR_KEY_2;
	BOARD_SWT0_CR = (BOARD_SWT_CR_MAP0|BOARD_SWT_CR_RIA|BOARD_SWT_CR_1|BOARD_SWT_CR_FRZ);


	/* FCCU disable reactions */
	/* unlock FCCU transient lock for CONFIG */
	BOARD_FCCU_TRANS_LOCK = BOARD_FCCU_TRANS_LOCK_KEY;
	/* set CONFIG timeout */
	BOARD_FCCU_CFG_TO = 0x00000007UL;

	/* enter CONFIG state */
	BOARD_FCCU_CTRLK = BOARD_FCCU_CTRLK_CONFIG_KEY;
	BOARD_FCCU_CTRL = BOARD_FCCU_CTRL_CONFIG;

	/* disable IRQ_ALARM for all error sources */
	BOARD_FCCU_IRQ_ALARM_EN0 = 0x000000000UL;
	BOARD_FCCU_IRQ_ALARM_EN1 = 0x000000000UL;
	BOARD_FCCU_IRQ_ALARM_EN2 = 0x000000000UL;

	/* disable NMI for all non-critical faults */
	BOARD_FCCU_NMI_EN0 = 0x000000000UL;
	BOARD_FCCU_NMI_EN1 = 0x000000000UL;
	BOARD_FCCU_NMI_EN2 = 0x000000000UL;

	/* disable state transitions for all non-critical faults */
	BOARD_FCCU_NCF_E0 = 0x000000000UL;
	BOARD_FCCU_NCF_E1 = 0x000000000UL;
	BOARD_FCCU_NCF_E2 = 0x000000000UL;

	/* enter NORMAL state */
	BOARD_FCCU_CTRLK = BOARD_FCCU_CTRLK_NORMAL_KEY;
	BOARD_FCCU_CTRL = BOARD_FCCU_CTRL_NORMAL;


	/* select appropriate settings for all modes */
	BOARD_MC_ME_DRUN_MC = BOARD_MC_ME_MODE_CONFIG_NORMAL;
	BOARD_MC_ME_RUN0_MC = BOARD_MC_ME_MODE_CONFIG_NORMAL;
	BOARD_MC_ME_RUN1_MC = BOARD_MC_ME_MODE_CONFIG_NORMAL;
	BOARD_MC_ME_RUN2_MC = BOARD_MC_ME_MODE_CONFIG_NORMAL;
	BOARD_MC_ME_RUN3_MC = BOARD_MC_ME_MODE_CONFIG_NORMAL;
	BOARD_MC_ME_HALT0_MC = BOARD_MC_ME_MODE_CONFIG_LOWPOWER;
	BOARD_MC_ME_STOP0_MC = BOARD_MC_ME_MODE_CONFIG_POWERDOWN;

	/* activate all peripheral configs in all normal modes */
	BOARD_MC_ME_RUN_PC0 = BOARD_MC_ME_RUN_PC_ALL;
	BOARD_MC_ME_RUN_PC1 = BOARD_MC_ME_RUN_PC_ALL;
	BOARD_MC_ME_RUN_PC2 = BOARD_MC_ME_RUN_PC_ALL;
	BOARD_MC_ME_RUN_PC3 = BOARD_MC_ME_RUN_PC_ALL;
	BOARD_MC_ME_RUN_PC4 = BOARD_MC_ME_RUN_PC_ALL;
	BOARD_MC_ME_RUN_PC5 = BOARD_MC_ME_RUN_PC_ALL;
	BOARD_MC_ME_RUN_PC6 = BOARD_MC_ME_RUN_PC_ALL;
	BOARD_MC_ME_RUN_PC7 = BOARD_MC_ME_RUN_PC_ALL;

	/* activate all peripheral configs in all low-power modes */
	BOARD_MC_ME_LP_PC0 = BOARD_MC_ME_LP_PC_ALL;
	BOARD_MC_ME_LP_PC1 = BOARD_MC_ME_LP_PC_ALL;
	BOARD_MC_ME_LP_PC2 = BOARD_MC_ME_LP_PC_ALL;
	BOARD_MC_ME_LP_PC3 = BOARD_MC_ME_LP_PC_ALL;
	BOARD_MC_ME_LP_PC4 = BOARD_MC_ME_LP_PC_ALL;
	BOARD_MC_ME_LP_PC5 = BOARD_MC_ME_LP_PC_ALL;
	BOARD_MC_ME_LP_PC6 = BOARD_MC_ME_LP_PC_ALL;
	BOARD_MC_ME_LP_PC7 = BOARD_MC_ME_LP_PC_ALL;


	/* activate XOSC - PLLs remain off */
	BOARD_MC_ME_DRUN_MC = BOARD_MC_ME_MODE_CONFIG_XOSC;
	BOARD_XOSC_CTL = BOARD_XOSC_CTL_OSCM | BOARD_XOSC_CTL_EOCV_48  | BOARD_XOSC_CTL_OSCBYP;
	BOARD_MC_ME_ME = BOARD_MC_ME_ME_ALL_MODES;

	/* start mode transition to DRUN mode */
	BOARD_MC_ME_MCTL = BOARD_MC_ME_MCTL_MODE_DRUN|BOARD_MC_ME_MCTL_KEY;
	BOARD_MC_ME_MCTL = BOARD_MC_ME_MCTL_MODE_DRUN|BOARD_MC_ME_MCTL_KEY_INV;

	while(BOARD_MC_ME_GS & BOARD_MC_ME_GS_S_MTRANS);	/* wait until mode transition is complete */
	while((BOARD_MC_ME_GS&BOARD_MC_ME_GS_S_CURRENT_MODE) != BOARD_MC_ME_GS_DRUN);	/* check mode */
	BOARD_MC_ME_IS = BOARD_MC_ME_IS_I_MTC;				/* clear transition flag (write 1 to clear) */


/* enable clocks to all peripherals */
	/* enable sys clock divider, divide sys clock by 2 */
	BOARD_MC_CGM_SC_DC0 = BOARD_MC_CGM_SC_DC_DE | BOARD_MC_CGM_SC_DC_DIV2;

	/* select Auxiliary Clock 0 clock source and dividers */
	BOARD_MC_CGM_AC0_SC = BOARD_MC_CGM_AC0_SC_SELCTL_PLL0;	/* PLL0 PHI */
	BOARD_MC_CGM_AC0_DC0 = BOARD_MC_CGM_AC_DC_DE | BOARD_MC_CGM_AC_DC_DIV2;
	BOARD_MC_CGM_AC0_DC1 = BOARD_MC_CGM_AC_DC_DE | BOARD_MC_CGM_AC_DC_DIV4;
	BOARD_MC_CGM_AC0_DC2 = BOARD_MC_CGM_AC_DC_DE | BOARD_MC_CGM_AC_DC_DIV2;

	/* select Auxiliary Clock 1 clock dividers */
	BOARD_MC_CGM_AC1_DC0 = BOARD_MC_CGM_AC_DC_DE | BOARD_MC_CGM_AC_DC_DIV1;
	BOARD_MC_CGM_AC1_DC1 = BOARD_MC_CGM_AC_DC_DE | BOARD_MC_CGM_AC_DC_DIV2;

	/* select Auxiliary Clock 2 clock divider */
	BOARD_MC_CGM_AC2_DC0 = BOARD_MC_CGM_AC_DC_DE | BOARD_MC_CGM_AC_DC_DIV2;

	/* select Auxiliary Clock 5 clock source and divider */
	BOARD_MC_CGM_AC5_SC = BOARD_MC_CGM_AC5_SC_SELCTL_PLL0;	/* PLL0 PHI */
	BOARD_MC_CGM_AC5_DC0 = BOARD_MC_CGM_AC_DC_DE | BOARD_MC_CGM_AC_DC_DIV1;

	/* select Auxiliary Clock 6 clock source and divider */
	BOARD_MC_CGM_AC6_SC = BOARD_MC_CGM_AC5_SC_SELCTL_PLL0;	/* PLL0 PHI */
	BOARD_MC_CGM_AC6_DC0 = BOARD_MC_CGM_AC_DC_DE | BOARD_MC_CGM_AC_DC_DIV4;
    
    
	/* route XOSC to the PLLs - IRCOSC is default */
	BOARD_MC_CGM_AC3_SC = BOARD_MC_CGM_AC3_SC_SELCTL_XOSC;	/* route XOSC to PLL0 */
	BOARD_MC_CGM_AC4_SC = BOARD_MC_CGM_AC4_SC_SELCTL_XOSC;	/* route XOSC to PLL1 */


	/* configure PLL0 dividers - 80MHz from 40Mhx XOSC */
	BOARD_PLLDIG_PLL0DV = BOARD_PLLDIG_PLLDV(BOARD_PLL0_RFDPHI1,BOARD_PLL0_RFDPHI,BOARD_PLL0_PREDIV,BOARD_PLL0_MFD);

	/* put PLL0 into normal mode */
	BOARD_PLLDIG_PLL0CR = (BOARD_PLLDIG_PLL0CR&~BOARD_PLLDIG_PLLCR_CLKCFG) | BOARD_PLLDIG_PLLCR_CLKCFG_PLL_ON;

	/* configure PLL1 dividers - - 64MHz from 40Mhx XOSC */
	BOARD_PLLDIG_PLL1DV = BOARD_PLLDIG_PLLDV(0,BOARD_PLL0_RFDPHI,0,BOARD_PLL0_MFD);

	/* put PLL1 into Normal mode */
	BOARD_PLLDIG_PLL1CR = (BOARD_PLLDIG_PLL1CR&~BOARD_PLLDIG_PLLCR_CLKCFG) | BOARD_PLLDIG_PLLCR_CLKCFG_PLL_ON;


	/* start mode transition to DRUN mode with PLLs on */
	BOARD_MC_ME_DRUN_MC = BOARD_MC_ME_MODE_CONFIG_PLLON;
	BOARD_MC_ME_MCTL = BOARD_MC_ME_MCTL_MODE_DRUN|BOARD_MC_ME_MCTL_KEY;
	BOARD_MC_ME_MCTL = BOARD_MC_ME_MCTL_MODE_DRUN|BOARD_MC_ME_MCTL_KEY_INV;

	while(BOARD_MC_ME_GS & BOARD_MC_ME_GS_S_MTRANS);	/* wait until mode transition is complete */
	while((BOARD_MC_ME_GS&BOARD_MC_ME_GS_S_CURRENT_MODE) != BOARD_MC_ME_GS_DRUN);	/* check mode */
	BOARD_MC_ME_IS = BOARD_MC_ME_IS_I_MTC;				/* clear transition flag (write 1 to clear) */

	while (!(BOARD_PLLDIG_PLL0SR & BOARD_PLLDIG_PLLSR_LOCK)) {};	/* wait for PLL0 to lock */
	while (!(BOARD_PLLDIG_PLL1SR & BOARD_PLLDIG_PLLSR_LOCK)) {};	/* wait for PLL1 to lock */

	/* RUN0 MODE with SYS_CLK from PLL0 */
	BOARD_MC_ME_RUN0_MC = (BOARD_MC_ME_RUN0_MC&~BOARD_MC_ME_MC_SYSCLK) | BOARD_MC_ME_MC_SYSCLK_PLL0;


	/* start mode transition to RUN0 mode */
	BOARD_MC_ME_MCTL = BOARD_MC_ME_MCTL_MODE_RUN0|BOARD_MC_ME_MCTL_KEY;
	BOARD_MC_ME_MCTL = BOARD_MC_ME_MCTL_MODE_RUN0|BOARD_MC_ME_MCTL_KEY_INV;

	/* flash: activate pipelined access 1 cycle early; use 2 additional read waitstates */
	BOARD_PFLASH_PFCR1 = (BOARD_PFLASH_PFCR1&~BOARD_PFLASH_PFCR1_APC) | BOARD_PFLASH_PFCR1_APC_CYC1;
	BOARD_PFLASH_PFCR1 = (BOARD_PFLASH_PFCR1&~BOARD_PFLASH_PFCR1_RWSC) | BOARD_PFLASH_PFCR1_RWSC_WS2;

	while(BOARD_MC_ME_GS & BOARD_MC_ME_GS_S_MTRANS);	/* wait until mode transition is complete */
	while((BOARD_MC_ME_GS&BOARD_MC_ME_GS_S_CURRENT_MODE) != BOARD_MC_ME_GS_RUN0);	/* check mode */
	BOARD_MC_ME_IS = BOARD_MC_ME_IS_I_MTC;				/* clear transition flag (write 1 to clear) */
    
}

/*
** boardInvalidInterrupt(os_uint32_t id)
**
** The boardInvalidInterrupt() routine is used for uninitialized
** vectors of the vector table if errorhandling is set to minimal.
** Parameter 'id' is containing the interrupt identification number.
**
** CHECK: RULE 404 OFF (externally-defined interface)
*/
void boardInvalidInterrupt(os_uint32_t id)
{
	/* CHECK: RULE 404 ON */

	/* remove unused parameter warning */
	(void) id;

#ifdef  OS_TESTSUITE_IS_RUNNING_
#ifdef  TESTCASE_InvalidInterrupt
	BTestOK();
#else  /* TESTCASE_InvalidInterrupt */
	BPanic();
#endif /* TESTCASE_InvalidInterrupt */
#endif /* OS_TESTSUITE_IS_RUNNING_ */

	for (;;) { }
}

/*
** boardInvalidException(os_uint32_t id, os_address_t sp)
**
** The boardInvalidException() routine is used for uninitialized
** vectors of the exception table if exception handling is off.
** Parameter 'id' contains the exception id
** and 'sp' is the current stack pointer.
**
** CHECK: RULE 404 OFF (externally-defined interface)
*/
void boardInvalidException(os_uint32_t id, os_address_t sp)
{
	/* CHECK: RULE 404 ON */

	/* remove unused parameter warning */
	(void) id;
	(void) sp;

#ifdef  OS_TESTSUITE_IS_RUNNING_
#ifdef  TESTCASE_InvalidException
	BTestOK();
#else  /* TESTCASE_InvalidInterrupt */
	BPanic();
#endif /* TESTCASE_InvalidInterrupt */
#endif /* OS_TESTSUITE_IS_RUNNING_ */

	for (;;) { }
}

#if (OS_TOOL==OS_gnu)
/* The Gnu compiler calls this function automatically from main()
**
** CHECK: RULE 404 OFF (externally-defined interface)
*/
void __eabi(void); /* MISRA */
void __eabi(void)
{
}
/* CHECK: RULE 404 ON */
#endif
