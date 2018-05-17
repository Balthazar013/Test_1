#ifndef RAMSHAREDDATA_H
#define RAMSHAREDDATA_H
/** \brief Shared RAM data between bootloader and application
 **
 ** \project vsc_bootloader
 ** \file
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** \controller independent
 ** \compiler independent
 ** \hardware independent
 **
 ** Copyright 2011 by EB - Elektrobit Automotive GmbH
 ** All rights exclusively reserved for EB - Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise
 **/

/*==================[inclusions]=============================================*/

#include <Std_Types.h>                             /* AUTOSAR standard types */

/*==================[macros]=================================================*/

#define RSD_START_BOOTLOADER        (0xCAFEBABEul)
#define RSD_START_APPLICATION       (0xFEEDBEEFul)
#define RSD_RESPONSE_REQUISITION    (0xC001D00Dul)
#define RSD_NO_RESPONSE_REQUISITION (0x00000000ul)
#define RSD_VALID_RESETS            (0x52455354ul) /* REST */
#define RSD_VALID_BS                (0x4253495Aul) /* BSIZ */

/*==================[type definitions]=======================================*/
#pragma pack(1)
typedef struct Ram_SharedData
{
  VAR(uint32, TYPEDEF) bootword;            /* bootloader request                       */
  VAR(uint32, TYPEDEF) statusword;          /* send response after application reset    */
  VAR(uint8,  TYPEDEF) reqlength;           /* request len for response after reset     */
  VAR(uint8,  TYPEDEF) reqBuffer[8];        /* request buffer                           */
  VAR(uint32, TYPEDEF) reqTesterEmu;        /* request Tester Emulation Session         */
  VAR(uint32, TYPEDEF) optTesterEmu;        /* options for Tester Emulation task        */
  VAR(uint32, TYPEDEF) reasonBootReq;       /* reason for requesting bootloader mode    */
  VAR(uint32, TYPEDEF) optBootReq;          /* reason for requesting bootloader mode    */
  VAR(uint32, TYPEDEF) reset_validflags;    /* validation of data in reset reason registers   */
  VAR(uint32, TYPEDEF) DES_Resets;          /* Destructive reset reason register     */
  VAR(uint32, TYPEDEF) FES_Resets;          /* Functional reset reason register      */
  VAR(uint32, TYPEDEF) BS_validflags;       /* validation of data CANTP BS           */
  VAR(uint32, TYPEDEF) BS;                  /* CANTP BS                              */
} Ram_SharedDataType;
#pragma pack()

/*==================[external constants]=====================================*/
/*==================[external data]==========================================*/

#define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#pragma ghs section bss=".NOINIT_RAM"
extern VAR(Ram_SharedDataType, BL_VAR) RSD_RamSharedData;
#pragma ghs section bss=default

#define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[external function declarations]=========================*/
/*==================[end of file]============================================*/
#endif /* RAMSHAREDDATA_H */
