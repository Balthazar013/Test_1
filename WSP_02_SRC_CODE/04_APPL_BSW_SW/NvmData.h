#ifndef NVMDATA_H
#define NVMDATA_H
/** \brief NVM data
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

#include <Std_Types.h>                             /* AUTOSAR standard types */

/*==================[macros]=================================================*/
/*==================[type definitions]=======================================*/
/*==================[external constants]=====================================*/
/*==================[external data]==========================================*/

#define NVM_START_SEC_VAR_INIT_8
#include "MemMap.h"

extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf17b[3];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf19a[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf19b[3];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a5[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a8[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a9[3];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf190[17];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf197[13];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1aa[5];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a0[11];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a4[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1a1[4];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1b1[4];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_DIDf1b3[12];
extern VAR(uint8, NVM_VAR) Nvm_Ram_PersistentCounterValue[5];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_ResetsNumber[6];
extern VAR(uint8, NVM_VAR) Nvm_Ram_NullVectorValid[1];

extern VAR(uint8, NVM_VAR) Nvm_Ram_Zmover_Pos[2];
extern VAR(uint8, NVM_VAR) Nvm_Ram_BLE_Name[17];

extern VAR(uint8, NVM_VAR) NvM_RamBlock_DeviceSleepTimeout[4];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDevFilterName[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleCommTimeout[2];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleScanTimeout[2];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDefaultRole[1];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDriverLoc[1];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey1[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey2[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey3[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey4[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey5[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey6[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey7[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey8[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey9[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey10[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey11[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey12[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey13[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey14[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleSessionKey15[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC1[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC2[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC3[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC4[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC5[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC6[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC7[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC8[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC9[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC10[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC11[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC12[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC13[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC14[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleMAC15[6];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName1[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName2[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName3[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName4[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName5[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName6[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName7[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName8[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName9[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName10[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName11[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName12[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName13[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName14[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleDeviceName15[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence1[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence2[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence3[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence4[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence5[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence6[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence7[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence8[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence9[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence10[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence11[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence12[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence13[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence14[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_BleNoncence15[12];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_PINverf[32];
extern VAR(uint8, NVM_VAR) NvM_RamBlock_PUKverf[32];


#define NVM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf17b[3];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf19a[6];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf19b[3];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a5[6];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a8[6];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a9[3];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf190[17];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf197[13];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1aa[5];
extern CONST(uint8, NVM_CONST) Nvm_Rom_NullVectorValid[1];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_ResetsNumber[6];

extern CONST(uint8, NVM_CONST) Nvm_Rom_Zmover_Pos[2];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a0[11];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a4[12];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1a1[4];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1b1[4];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_DIDf1b3[12];
extern CONST(uint8, NVM_CONST) Nvm_Rom_BLE_Name[17];

extern CONST(uint8, NVM_CONST) NvM_RomDefault_DeviceSleepTimeout[4];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_BleScanTimeout[2];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_BleCommTimeout[2];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_BleDefaultRole[1];
extern CONST(uint8, NVM_CONST) NvM_RomDefault_BleDriverLoc[1];


/*==================[external function declarations]=========================*/
/*==================[end of file]============================================*/
#endif /* NVMDATA_H */
