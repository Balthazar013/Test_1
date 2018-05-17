/* cstartup.s - board specific assembler startup file for MPC574XP board
**
** The code here performs what must be done before any C routines can be called.
** Actually, it does a little more than necessary in assembler.
** Some of the initialisation could comfortably be done in C.
**
** CHECK: TABS 4 (see editor commands at end of file)
**
** Copyright 1998-2014 Elektrobit Automotive GmbH
** All rights exclusively reserved for Elektrobit Automotive GmbH,
** unless expressly agreed to otherwise.
**
** $Id: cstartup.s 18307 2014-06-17 11:06:23Z mist8519 $
*/
#include <PA/Os_asm_PA.h>		/* Must be first */
#include <board.h>

	OS_file(cstartup.s)

#define BOOT_VLE		0x01		/* activate VLE code */

#define BOOT_FLAGS		BOOT_VLE	/* MPC574XP RCHW only supports VLE flag */
#define BOOT_ID			0x5A		/* magic number for the BAM */

#define STARTUP_MSR			0x21200		/* The MSR at startup: CE|ME|DE */

#define BOARD_SWT_DISABLE	0xFF000000	/* disable SWT for all masters */

#define BOARD_RGM_FES       0xfffa8300  /* Reset module functional reset source */
#define F_SOFT_BIT          28

	OS_global	__entry

	OS_extern	OS_SetupExceptions
	OS_extern	HwInit
	OS_extern	BoardInit
	OS_extern	main
	OS_extern	OS_PAResetCodeTlbFill

#if (INIT_SRAM == 1)
	OS_extern	PA_InitRam
#endif

	/* These symbols are defined in the linker script */
	OS_extern	_BSS_START_
	OS_extern	_BSS_END_
	OS_extern	_DATA_START_
	OS_extern	_DATA_END_
	OS_extern	_INIT_

/*
** reset section
**
** Define reset configuration half word (RCHW) for boot assist module (BAM) code.
** The RCHW is a mark at a specific place in memory to tell the BAM code
** if there exists an application ready to run after reset.
*/
	OS_ASM_SECTION_RESET
	OS_ASM_VLE

	OS_align(1,0)

	OS_byte		BOOT_FLAGS,BOOT_ID,0x0,0x0	/* reset config. half word (RCHW) */
	OS_long		__entry						/* reset start address */

/* Startup code
** The processor runs this code first after a reset.
*/
	OS_ASM_SECTION_RESET_CODE
	OS_ASM_ALIGN_TEXT
	OS_ASM_VLE

__entry:
#ifdef BOARD_INIT_CPU_REG
	/* init all CPU register, lock step mode reason */
	bl		__CpuRegInitStart
#endif

	/* Initialise the MSR */
	lis		r3, OS_hi(STARTUP_MSR)
	addi	r3, r3, OS_lo(STARTUP_MSR)
	mtmsr	r3

	/* disable SWT watchdog */
	lis		r7,OS_hi(BOARD_SWT_DISABLE)
	addi	r7,r7,OS_lo(BOARD_SWT_DISABLE)
	li		r3,OS_lo(BOARD_SWT_SR_KEY_1)
	li		r4,OS_lo(BOARD_SWT_SR_KEY_2)

	/* SWT 0 watchdog */
	lis		r5,OS_hi(BOARD_SWT_0)
	addi	r5,r5,OS_lo(BOARD_SWT_0)
	stw		r3,BOARD_SWT_SR(r5)
	stw		r4,BOARD_SWT_SR(r5)
	stw		r7,BOARD_SWT_CR(r5)

	/* Add a default exception handler for all exceptions */
	bl		OS_SetupExceptions

	/* Set up the instruction cache unless we're running with cache disabled (local function) */
#if !defined(BOARD_DISABLE_CACHE)
	bl		__InitInstCache
#endif

#if (INIT_SRAM == 1)
	/* Initialize SRAM
	**
	** SRAM must be initialized after a cold reset. See target reference manual.
	** If running from RAM INIT_SRAM must be left undefined so the following code does not erase
	** the loaded code.
	*/
	lis		r3, OS_hi(INIT_SRAM_START)		/* base address of the SRAM */
	ori		r3, r3,	OS_lo(INIT_SRAM_START)
	li		r4, (INIT_SRAM_SIZE / 128)		/* loop counter to get all of SRAM */
	bl		PA_InitRam
    
    /* Initialize Local SRAM
       Store number of 128 Byte (32GPRs) segments in Counter
    */
    e_lis r5, INIT_DMEM_SIZE@h
    e_or2i r5, INIT_DMEM_SIZE@l
    e_srwi r5, r5, 0x7
    mtctr r5
    e_lis r5, INIT_DMEM_START@h
    e_or2i r5, INIT_DMEM_START@l
    
    lsram_loop:
    e_stmw r0,0(r5)
    e_addi r5,r5,128
    e_bdnz lsram_loop
    
    /* Check if last reset was functional. Reading BOARD_RGM_FES Register.
     * If it was not functional we need to initialize the NZRAM too, otherwise not.
     */
    lis      r3, OS_hi(BOARD_RGM_FES)
    addi     r3, r3, OS_lo(BOARD_RGM_FES)
    se_lwz   r4, 0x0(r3)
	se_btsti r4,F_SOFT_BIT    /* check if Soft_Reset Bit is set */
    se_bne   __sram_init_end
	
	/* The Application has not written anything in the NZRAM, so we can
	   clear it */
    lis     r3, OS_hi(INIT_NZRAM_START)
    addi    r3, r3, OS_lo(INIT_NZRAM_START)
    li      r4, (INIT_NZRAM_SECTION / 128)
    bl      PA_InitRam
__sram_init_end:

#endif /* (INIT_SRAM == 1) */

	/* Set up the data cache unless we're running with cache disabled (local function) */
#if !defined(BOARD_DISABLE_CACHE)
	bl		__InitDataCache
#endif


	/* Use the kernel stack for running the startup code. */
	lis		r3, OS_hi(OS_iSpInitial_PA)
	lwz		r1, OS_lo(OS_iSpInitial_PA)(r3)

	/* Load Small Data Area Pointer to variable data to R13 */
	lis		r13, OS_hi( _SDA_BASE_)
	addi	r13, r13, OS_lo(_SDA_BASE_)

	/* Load Small Data Area Pointer to const data to R2 */
	lis		r2, OS_hi(_SDA2_BASE_)
	addi	r2, r2, OS_lo(_SDA2_BASE_)

	/* HwInit() is in board.c */
	bl		HwInit

	/* Clear BSS
	** Note: the "-1" on the start and end addresses is there because
	** stbu updates before storing.
	*/
	li		r5, 0								/* Initial value for bss */
	lis		r3, OS_hi((_BSS_START_-1))
	addi	r3, r3, OS_lo((_BSS_START_-1))		/* Start of bss */
	lis		r4, OS_hi((_BSS_END_-1))
	addi	r4, r4, OS_lo((_BSS_END_-1))		/* Limit of bss */
	b		__clear_bss

__clear_loop:
	stbu	r5, 1(r3)

__clear_bss:
	cmpw	r3, r4
	bne		__clear_loop

	/* Copy data sections
	** Note: the "-1" on the start and end addresses is there because
	** stbu updates before storing.
	*/
	lis		r3, OS_hi((_DATA_START_-1))
	addi	r3, r3, OS_lo((_DATA_START_-1))		/* Start of data section */
	lis		r4, OS_hi((_DATA_END_-1))
	addi	r4, r4, OS_lo((_DATA_END_-1))		/* Limit of data section */
	lis		r5, OS_hi((_INIT_-1))
	addi	r5, r5, OS_lo((_INIT_-1))			/* Start of initial values in ROM */
	b		__copy_data

__copy_loop:
	lbzu	r0,1(r5)
	stbu	r0,1(r3)

__copy_data:
	cmpw	r3, r4
	bne		__copy_loop

	/* BoardInit() is in board.c */
	bl		BoardInit

	/* main() is wherever the user puts it */
	bl		main

	/* If main() ever returns we just go round again */
	b		__entry
	OS_ASM_SIZE(__entry)
	OS_ASM_FUNCTION(__entry)

#ifdef BOARD_INIT_CPU_REG
	/* CPU register initialization for lock step processor mode (LSM)
	** The following registers are initialized to avoid the CPU to go to safe-mode.
	** If these registers are stored in memory before they have been set to identical
	** initial values on all cores in LSM the CPUs safety mechanism detects a failure.
	*/
__CpuRegInitStart:
	li		r0, 0
	li		r1, 0
	li		r2, 0
	li		r3, 0
	li		r4, 0
	li		r5, 0
	li		r6, 0
	li		r7, 0
	li		r8, 0
	li		r9, 0
	li		r10, 0
	li		r11, 0
	li		r12, 0
	li		r13, 0
	li		r14, 0
	li		r15, 0
	li		r16, 0
	li		r17, 0
	li		r18, 0
	li		r19, 0
	li		r20, 0
	li		r21, 0
	li		r22, 0
	li		r23, 0
	li		r24, 0
	li		r25, 0
	li		r26, 0
	li		r27, 0
	li		r28, 0
	li		r29, 0
	li		r30, 0
	li		r31, 0

/* reset of selected registers */
	mtcrf	0xFF,r0	/* CR */
	mtspr	272,r0	/* SPRG0 */
	mtspr	273,r0	/* SPRG1 */
	mtspr	274,r0	/* SPRG2 */
	mtspr	275,r0	/* SPRG3 */
	mtspr	26,r0	/* SRR0 */
	mtspr	27,r0	/* SRR1 */
	mtspr	58,r0	/* CSRR0 */
	mtspr	59,r0	/* CSRR1 */
	mtspr	63,r0	/* IVPR */
	mtspr	61,r0	/* DEAR */
	mtspr	62,r0	/* ESR */
	/* mtspr	572,r0	;MCSR (= 0 at reset) */
	mtspr	570,r0	/* MCSRR0 */
	mtspr	571,r0	/* MCSRR1 */
	mtspr	512,r0	/* SPEFSCR */

	mtspr	1,r0	/* XER */
	mtspr	256,r0	/* USPRG0 */
	mtspr	9,r0	/* CTR */
	/* mtspr	8,r0	LR (used by 'bl' to call this function) */
	mtspr	308,r0	/* DBCR0 */
	mtspr	309,r0	/* DBCR1 */
	mtspr	310,r0	/* DBCR2 */
	/* mtspr	561,r0	 DBCR3 (not implemented) */
	mtspr	563,r0	/* DBCR4 */
	mtspr	564,r0	/* DBCR5 */
	mtspr	603,r0	/* DBCR6 */
	mtspr	596,r0	/* DBCR7 */
	mtspr	597,r0	/* DBCR8 */
	mtspr	975,r0	/* DEVENT */
	mtspr	976,r0	/* HDBCR0 */
	blr
	OS_ASM_SIZE(__CpuRegInitStart)
	OS_ASM_FUNCTION(__CpuRegInitStart)
#endif

#if !defined(BOARD_DISABLE_CACHE)
	/* Initialize the cache.
	** This small routine invalidates the cache and then enables it.
	*/
__InitInstCache:
	mbar	0						/* complete all pending data accesses */
	isync							/* complete all dispatched instructions */
	li		r3, OS_L1CSRx_CINV		/* set CINV bit (invalidate entries), clear CABT bit */
	li		r4, OS_L1CSRx_CE		/* set CE bit (enable cache) */

__InitInstCache_try:
	mtspr	OS_L1CSR1, r3			/* invalidate cache */
	msync							/* wait until invalidate completes */
	mfspr	r8, OS_L1CSR1			/* check if invalidate was aborted */
	cmpwi	r8, 0
	bne		__InitInstCache_try		/* try again */

	mtspr	OS_L1CSR1, r4			/* enable cache */
	blr
	OS_ASM_SIZE(__InitInstCache)
	OS_ASM_FUNCTION(__InitInstCache)

__InitDataCache:
	mbar	0						/* complete all pending data accesses */
	isync							/* complete all dispatched instructions */
	li		r3, OS_L1CSRx_CINV		/* set CINV bit (invalidate entries), clear CABT bit */
	li		r4, OS_L1CSRx_CE		/* set CE bit (enable cache) */
__InitDataCache_try:
	mtspr	OS_L1CSR0, r3			/* invalidate cache */
	msync							/* wait until invalidate completes */
	mfspr	r8, OS_L1CSR0			/* check if invalidate was aborted */
	cmpwi	r8, 0
	bne		__InitDataCache_try		/* try again */

	mtspr	OS_L1CSR0, r4			/* enable cache */

	blr
	OS_ASM_SIZE(__InitDataCache)
	OS_ASM_FUNCTION(__InitDataCache)
#endif /* !defined(BOARD_DISABLE_CACHE) */

/*
** dummy data section
**
** If the datasection is empty (contains no data) Trace32 fails to load the ELF-image to the target
**
*/

