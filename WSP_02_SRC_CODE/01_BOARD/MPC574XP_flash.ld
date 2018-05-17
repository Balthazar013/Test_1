/**************************************
 * Copyright 1998-2014 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: MPC574XP_flash.ld 17602 2014-02-03 12:09:35Z tojo2507 $
 *
 **************************************/

/* Memory as mapped by the BAM (Internal Boot mode):
 *
 */

MEMORY
{
    /*                  : org = 0x00800000, len = 0x004000         16  kB   NVMS EMU-EEPROM                         */
    /*                  : org = 0x00804000, len = 0x004000         16  kB   NVMS EMU-EEPROM                         */
    /*                  : org = 0x00808000, len = 0x008000         32  kB   NVM  EMU-EEPROM                         */
    /*                  : org = 0x00810000, len = 0x008000         32  kB   NVM  EMU-EEPROM                         */
    /*                  : org = 0x00F98000, len = 0x004000         16  kB   NOT USED                                */
    /*                  : org = 0x00F9C000, len = 0x004000         16  kB   NOT USED                                */
    /*                  : org = 0x00FA0000, len = 0x03F000         252 kB   BOOTLOADER                              */
    map_sw_extfls       : org = 0x00FDF000, len = 0x000400      /* 1   kB   Memory map of SwBlocks in ext. flash    */
    map_ds_extfls       : org = 0x00FDF400, len = 0x000C00      /* 3   kB   Memory map of Datasets in ext. flash    */
    /*                  : org = 0x00FE0000, len = 0x010000         64  kB   NOT USED                                */
    refpage             : org = 0x00FF0000, len = 0x004000      /* 16  kB   REFPAGE XCP Data                        */
    /*                  : org = 0x00FF4000, len = 0x00BC00         47  kB   REFPAGE XCP RESERVED                    */
    refpage_hdr         : org = 0x00FFFC00, len = 0x0003D4      /* 980 B    REFPAGE XCP Header                      */
    refpage_supp_ver    : org = 0x00FFFFD4, len = 0x000008      /* 8   B    REFPAGE Supplier Version                */
    refpage_ver         : org = 0x00FFFFDC, len = 0x000004      /* 4   B    REFPAGE Version                         */
    reset               : org = 0x01000000, len = 0x001000      /* 64  kB   Reset Vector                            */
    exctab              : org = 0x01002000, len = 0x001000      /* 64  kB   Exception Table                         */
    intctab             : org = 0x01003000, len = 0x001000      /* 64  kB   Reset                                   */
    mtext               : org = 0x01004000, len = 0x0FBC00      /* 1   MB   PAD APP SW                              */
    app_hdr             : org = 0x010FFC00, len = 0x0003D4      /* 980 B    PAD APP Header                          */
    app_supp_ver        : org = 0x010FFFD4, len = 0x000008      /* 8   B    PAD APP SW Supplier Version             */
    app_ver             : org = 0x010FFFDC, len = 0x000004      /* 4   B    PAD APP SW Version                      */
    pos_dataset         : org = 0x01100000, len = 0x03FFD3      /* 256 kB   POS Dataset                 */
    pos_supp_ver        : org = 0x0113FFD4, len = 0x000008      /* 8   B    POS Dataset Supplier Version*/
    pos_ver             : org = 0x0113FFDC, len = 0x000004      /* 4   B    MOD Dataset Version         */
    mod_dataset         : org = 0x01140000, len = 0x07FFD3      /* 512 kB   MOD Dataset                 */
    mod_supp_ver        : org = 0x011BFFD4, len = 0x000008      /* 8   B    MOD Dataset Supplier Version*/
    mod_ver             : org = 0x011BFFDC, len = 0x000004      /* 4   B    MOD Dataset Version         */
    mdata               : org = 0x40000000, len = 0x038C00      /* 227 kB   SRAM                                    */
    heap                : org = 0x40038C00, len = 0x010000      /* 64  kB   HEAP ONLY FOR POS ALGO                  */
    workpage            : org = 0x40048C00, len = 0x010000      /* 64  kB   WORKPAGE XCP                            */
    dma                 : org = 0x40058C00, len = 0x001400      /* 5   kB                                           */
    seclib              : org = 0x4005A000, len = 0x004000      /* 16  kB                                           */
    /*                  : org = 0x4005E000, len = 0x001f00                  RESERVED                                */
    sharedram           : org = 0x4005ff00, len = 0x000100      /* 256 B    Shared RAM                              */
    stack_ram           : org = 0x50800000, len = 0x010000      /* 64  kB   Stack RAM                               */
}


SECTIONS
{
    __MAP_SW_EXTFLS_START = ADDR(map_sw_extfls);
    __MAP_DS_EXTFLS_START = ADDR(map_ds_extfls);
    
    .refpage :
    {
        __REF_PAGE_START = .;
        *(.refpage)
        __REF_PAGE_END = .;
    } > refpage
    
    __REF_PAGE_TOTAL_SIZE = ENDADDR(refpage) - __REF_PAGE_START;
    
    .refpage_hdr :
    {
        __REF_PAGE_HDR_START = .;
        *(.refpage_hdr)
        __REF_PAGE_HDR_END = .;
    } > refpage_hdr
    
    __REF_PAGE_HDR_TOTAL_SIZE = ENDADDR(refpage_hdr) - __REF_PAGE_HDR_START;
    
    .RefpageSuppVer : > refpage_supp_ver
    .RefpageVer     : > refpage_ver
    
    .reset : { *(.reset) *(.reset_code) } > reset
    
    .exctab :
    {
        __EXCEPTION_TABLE_START = .;
        *(.exctab)
        *(.exctab_vle)
        __EXCEPTION_TABLE_END = .;
    } > exctab
    
    .intctab :
    {
        __INTC_TABLE_START = .;
        *(.intctab)
        *(.intctab_vle)
        __INTC_TABLE_END = .;
    } > intctab
    
    .text2 :
    {
        *(.text)
        *(.T1_code)
        *(.T1_codeFast)
        *(.T1_codeCore0)
        *(.vletext)
        *(.os_text)
        *(.secinfo)
        *(.rdata)
        *(.frame_info)
        *(.j_class_table)
        *(.init)
        *(.fini)
    } > mtext
    
    __GLBL_RODATA_START = .;
    .sdata2                         : > .
    .rodata                         : > .
    .T1_const                       : > .
    __GLBL_RODATA_END = .;
    
    // Sections to be copied from Flash -> RAM
    // Order MUST match the order of appropriate RAM Sections below
    // AND Alignment Options shall be the same !!!
    .ROM.data           ROM(.data)       ALIGN(16)      : {} > .
    .ROM.sdabase        ROM(.sdabase)    ALIGN(16)      : {} > .
    .ROM.sdata          ROM(.sdata)                     : {} > .
    .ROMend                                             : {} > .
    
    .secinfo : { *(.secinfo) } > .
    .syscall : {}/*    *(.syscall) */
    
    .app_hdr :
    {
        __APP_HDR_START = .;
        *(.app_hdr)
        __APP_HDR_END = .;
    } > app_hdr
    
    __APP_HDR_TOTAL_SIZE = ENDADDR(app_hdr) - __APP_HDR_START;
    
    // next section is used to save APP SW block version (DID 0xF1AB and 0xF195)
    .app_SwSuppVer : > app_supp_ver
    .app_SwVer     : > app_ver
    
    // sections for MOD and POS datasets
    .MOD_DATA :
    {
      *(.MOD_FLAGS)
      *(.MOD_FOD_M)
      *(.MOD_FOD_M_1)
      *(.MOD_FOD_M_2)
      *(.MOD_FOD_M_3)
      *(.MOD_TC1)
      *(.MOD_TC2)
      *(.MOD_TV1)
      *(.MOD_TV2)
    } > mod_dataset
    .mod_SwSuppVer : > mod_supp_ver
    .mod_SwVer     : > mod_ver
    
    .POS_DATA :
    {
      *(.POS_FLAGS)
      *(.POS_A1)
      *(.POS_A2)
      *(.POS_A3)
      *(.POS_A4)
      *(.POS_A5)
      *(.POS_A6)
      *(.POS_A7)
      *(.POS_A8)
      *(.POS_A9)
      *(.POS_A10)
      *(.POS_A11)
      *(.POS_A12)
      *(.POS_A13)
      *(.POS_A14)
      *(.POS_A15)
      *(.POS_A16)
      *(.POS_A17)
      *(.POS_A18)
      *(.POS_A19)
      *(.POS_A20)
      *(.POS_A21)
      *(.POS_A22)
      *(.POS_A23)
      *(.POS_A24)
      *(.POS_A25)
      *(.POS_A26)
      *(.POS_A27)
      *(.POS_A28)
      *(.POS_A29)
      *(.POS_A30)
      *(.POS_A31)
      *(.POS_A32)
      *(.POS_VSIZE)
      *(.POS_X)
      *(.POS_Y)
    } > pos_dataset
    .pos_SwSuppVer : > pos_supp_ver
    .pos_SwVer     : > pos_ver
    
    // Place kernel stack at the start of RAM to detect stack overflow with an exception.
    .os_kernstack ALIGN(16)         : { "*(os_kernstack*)" } > stack_ram
    .os_taskstack ALIGN(16)         : { "*(os_taskstack*)" } > .
    .os_shookstack ALIGN(16)        : { "*(os_shookstack*)" } > .
    .os_ehookstack ALIGN(16)        : { "*(os_ehookstack*)" } > .
    
    __DATA_ROM = ADDR(.ROM.data);
    .data         ALIGN(16)         : > mdata
    .sdabase      ALIGN(16)         : > .
    .sdata                          : > .
    .sapp_var_data                  : > .
    .sapp_var_bss                   : > .
    .ossbss                         : > .
    .sapp_const                     : > .
    .sbss2                          : > .
    __DATA_END = .;
    
    __DATA_RAM = ADDR(.data);
    
    __BSS_START = .;
    .sbss                           : > .
    .bss                            : > .
    .T1_bss                         : > .
    .T1_bssCore0                    : > .
    .T1_traceBufferCore0            : > .
    __BSS_END = .;
    
    .workpage :
    {
        __WORK_PAGE_START = .;
        *(.workpage)  
    } > workpage
    
    __WORK_PAGE_TOTAL_SIZE = ENDADDR(workpage) - __WORK_PAGE_START;
    
    .dma :
    {
        __DMA_START = .;
        *(.dma)  
    } > dma
    
    __DMA_TOTAL_SIZE = ENDADDR(dma) - __DMA_START;
    
    .seclib :
    {
        __SECLIB_START = .;
        *(.seclib)  
    } > seclib
    
    __SECLIB_TOTAL_SIZE = ENDADDR(seclib) - __SECLIB_START;
    
    
    .NOINIT_RAM align(4) NOCLEAR :> sharedram /* non-zero RAM */
    
    /* Start of the Exception table */
    __IVPR          = __EXCEPTION_TABLE_START;
    
    __SP_INIT       = OS_kernStack+128;
    __SP_END        = OS_kernStack;
    __HEAP_END      = __SP_END;
    
    _INIT_          = __DATA_ROM;
    _DATA_START_    = __DATA_RAM;
    _DATA_END_      = __DATA_END; /* This prevent the copy loop to copy anything */
    
    ___SP_INIT      = __SP_INIT;
    ___SP_END       = __SP_END;
    
    ___DATA_ROM     = __DATA_ROM;
    
    __GLBL_DATA_START   = _DATA_START_;
    __GLBL_DATA_SIZE    = _DATA_END_ - _DATA_START_;
    
    __GLBL_RODATA_SIZE  =  __GLBL_RODATA_END - __GLBL_RODATA_START;
    
    _BSS_START_     = __BSS_START;
    _BSS_END_       = __BSS_END;
    
    // HEAP DEFINED ONLY FOR POS ALGO!
    __GLBL_HEAP_START = ADDR(heap);
    __GLBL_HEAP_END = ENDADDR(heap);
    __GLBL_HEAP_SIZE = __GLBL_HEAP_END - __GLBL_HEAP_START;
    __ghsbegin_heap = __GLBL_HEAP_START;
    __ghsend_heap = __GLBL_HEAP_END;
    
}

