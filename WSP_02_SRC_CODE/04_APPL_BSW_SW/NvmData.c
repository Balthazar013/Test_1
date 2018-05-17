/** \brief Nvm data
 **
 ** \project 
 ** \file
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** \controller independent
 ** \compiler independent
 ** \hardware independent
 **
 ** Copyright 2015 by EB - Elektrobit Automotive GmbH
 ** All rights exclusively reserved for EB - Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise
 **/

/*==================[inclusions]=============================================*/

#include <NvmData.h>

/*==================[macros]=================================================*/
/*==================[internal function declarations]=========================*/
/*==================[internal constants]=====================================*/
/*==================[internal data]==========================================*/
/*==================[external constants]=====================================*/
/*==================[external data]==========================================*/

#define NVM_START_SEC_VAR_INIT_8
#include "MemMap.h"

#define APP_SW_BLOCK_ID                     0xBA000021
#define APP_SW_VERSION_STRING               {'X','4','3','0'}
#define APP_SW_SUPP_VERSION_STRING          {'X','4','3','0','-','0','1','3'}

#define REF_PAGE_BLOCK_ID                   0xBC000023
#define REF_PAGE_VERSION_STRING             {'X','4','3','0'}
#define REF_PAGE_SUPP_VERSION_STRING        {'X','4','3','0','-','0','1','3'}

VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf17b[3];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf19a[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf19b[3];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a5[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a8[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a9[3];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf190[17];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf197[13];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1aa[5];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a0[11];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a4[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a1[4];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1b1[4];
VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1b3[12];
VAR(uint8, NVM_VAR) Nvm_Ram_PersistentCounterValue[5];
VAR(uint8, NVM_VAR) NvM_RamBlock_ResetsNumber[6];
VAR(uint8, NVM_VAR) Nvm_Ram_NullVectorValid[1];

VAR(uint8, NVM_VAR) Nvm_Ram_Zmover_Pos[2];
VAR(uint8, NVM_VAR) Nvm_Ram_BLE_Name[17];

VAR(uint8, NVM_VAR) NvM_RamBlock_DeviceSleepTimeout[4];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDevFilterName[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleCommTimeout[2];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleScanTimeout[2];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDefaultRole[1];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDriverLoc[1];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey1[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey2[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey3[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey4[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey5[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey6[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey7[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey8[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey9[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey10[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey11[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey12[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey13[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey14[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey15[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC1[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC2[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC3[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC4[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC5[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC6[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC7[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC8[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC9[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC10[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC11[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC12[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC13[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC14[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC15[6];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName1[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName2[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName3[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName4[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName5[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName6[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName7[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName8[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName9[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName10[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName11[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName12[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName13[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName14[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName15[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence1[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence2[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence3[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence4[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence5[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence6[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence7[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence8[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence9[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence10[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence11[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence12[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence13[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence14[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence15[12];
VAR(uint8, NVM_VAR) NvM_RamBlock_PINverf[32];
VAR(uint8, NVM_VAR) NvM_RamBlock_PUKverf[32];

#define NVM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf17b[3]      = { 0x00, 0x01, 0x01 }; // YYMMDD in BCD
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf19a[6]      = { '0', '0', '0', '0', '0', '0' };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf19b[3]      = { 0x00, 0x01, 0x01 }; // YYMMDD in BCD
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a5[6]      = { '0', '0', '0', '0', '0', '0' };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a8[6]      = { '0', '0', '0', '0', '0', '0' };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a9[3]      = { 0x00, 0x01, 0x01 }; // YYMMDD in BCD
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf197[13]     = { 'A', 'W', 'C', '_', 'P', 'A', 'D', '_', '3', 'k', '6', 'G', '1' };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1aa[5]      = { 'P', '5', '3', ' ', ' ' };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf190[17]     = {0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D};
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a0[11]     = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a4[12]     = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a1[4]      = { 0x00, 0x00, 0x00, 0x00 };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1b1[4]      = { 0x00, 0x00, 0x00, 0x00 };
CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1b3[12]     = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
CONST(uint8, NVM_CONST) NvM_RomDefault_ResetsNumber[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
CONST(uint8, NVM_CONST) Nvm_Rom_NullVectorValid[1]     = {0x00};
CONST(uint8, NVM_CONST) Nvm_RomDefPersistentCounterValueROM[5] = { 0 };

CONST(uint8, NVM_CONST) Nvm_Rom_Zmover_Pos[2] = { 0x00, 0x80 };
CONST(uint8, NVM_CONST) Nvm_Rom_BLE_Name[17]  = { 'A', 'U', 'D', 'I', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

CONST(uint8, NVM_CONST) NvM_RomDefault_DeviceSleepTimeout[4] = { 0x00, 0x00, 0x27, 0x10 }; // 10000 ms = 10 s
CONST(uint8, NVM_CONST) NvM_RomDefault_BleScanTimeout[2]     = { 0x27, 0x10 };             // 10000
CONST(uint8, NVM_CONST) NvM_RomDefault_BleCommTimeout[2]     = { 0x0B, 0xB8 };             // 3000
CONST(uint8, NVM_CONST) NvM_RomDefault_BleDefaultRole[1]     = { 0x02 };                   // 1: Central 2:Peripheral
CONST(uint8, NVM_CONST) NvM_RomDefault_BleDriverLoc[1]       = { 0x02 };                   // 1: ORU 2:PAD


#pragma ghs section rodata=".app_SwSuppVer"
const uint8 SuppSwVer[8] = APP_SW_SUPP_VERSION_STRING;
#pragma ghs section rodata=default

#pragma ghs section rodata=".app_SwVer"
const uint8 SwVer[4]     = APP_SW_VERSION_STRING;
#pragma ghs section rodata=default

#pragma ghs section rodata=".RefpageSuppVer"
const uint8 RefpageSuppVer[8] = REF_PAGE_SUPP_VERSION_STRING;
#pragma ghs section rodata=default

#pragma ghs section rodata=".RefpageVer"
const uint8 RefpageVer[4]     = REF_PAGE_VERSION_STRING;
#pragma ghs section rodata=default


/*==================[external function definitions]==========================*/
/*==================[internal function definitions]==========================*/
/*==================[end of file]============================================*/
