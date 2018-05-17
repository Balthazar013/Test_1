#ifndef NVMS_TEMPLATE_H
#define NVMS_TEMPLATE_H
/** \brief NvMS read and write functions header
**
** \project vsc_bootloader
** \file
** \author 
**
** \controller independent
** \compiler independent
** \hardware independent
**
**/

/*==================[inclusions]============================================*/

#include <Std_Types.h>                             /* AUTOSAR standard types */

/*==================[macros]=================================================*/
#define PIN_ID_WRITE_FAZIT                              (0xA5BFCF5Au)


// block IDs
/* #define NVMS_BLOCK_SERIES_KEY                        (0xA001u) */
#define NVMS_BLOCK_SAK_PenaltyTime                      (0xA002u)
#define NVMS_BLOCK_SAK_BreakInTries                     (0xA003u)
#define NVMS_BLOCK_SwBlockNumber                        (0xA004u)
#define NVMS_BLOCK_SwBlockNumberNEW                     (0xA005u)

#define NVMS_BLOCK_F187VWSparePartNum                   (0xA010u)
#define NVMS_BLOCK_F189VwSwVerNum                       (0xA011u)
#define NVMS_BLOCK_F191VwEcuHwNum                       (0xA012u)
#define NVMS_BLOCK_F19EODXFileIdent                     (0xA013u)
#define NVMS_BLOCK_F1A2ODXFileVer                       (0xA014u)
#define NVMS_BLOCK_F1A3VwEcuHwVerNum                    (0xA015u)
#define NVMS_BLOCK_F1DFEcuProgrInfo                     (0xA016u)
#define NVMS_BLOCK_F1D5FDSProjectData                   (0xA017u)
#define NVMS_BLOCK_2A30SubsystemIdentification          (0xA018u)
#define NVMS_BLOCK_F179ECUSupplierNumber                (0xA019u)
#define NVMS_BLOCK_F17DECUProdTestSystemNumber          (0xA01Au)
#define NVMS_BLOCK_F17EECUProdChangeNumber              (0xA01Bu)
#define NVMS_BLOCK_F17FVWSupplierNumber                 (0xA01Cu)
#define NVMS_BLOCK_F18ASystemSupplierIdentifier         (0xA01Du)
#define NVMS_BLOCK_F18BECUManufacturingDate             (0xA01Eu)
#define NVMS_BLOCK_F18CECUSerialNumber                  (0xA01Fu)
#define NVMS_BLOCK_F1AENumberOfLogins                   (0xA020u)
/* #define NVMS_BLOCK_F1A0DataSetNum                    (0xA021u) */
/* #define NVMS_BLOCK_F1A1DataSetVer                    (0xA022u) */
/* #define NVMS_BLOCK_F1A8DataSetTesterSerial           (0xA023u) */
/* #define NVMS_BLOCK_F1A9DatasetProgrammingDate        (0xA024u) */
/* #define NVMS_BLOCK_F1B1DataSetIdent                  (0xA025u) */
/* #define NVMS_BLOCK_F1B3DataSetName                   (0xA026u) */
#define NVMS_BLOCK_F180SupplierPlanId                   (0xA027u)

#define NVMS_BLOCK_TstEmuSwBlkFlSts01                   (0xA080u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts02                   (0xA081u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts03                   (0xA082u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts04                   (0xA083u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts05                   (0xA084u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts06                   (0xA085u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts07                   (0xA086u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts08                   (0xA087u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts09                   (0xA088u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts10                   (0xA089u)
#define NVMS_BLOCK_TstEmuSwBlkFlSts11                   (0xA08Au)

#define NVMS_BLOCK_BlockState_ORU_BL                    (0xA100u)
#define NVMS_BLOCK_ProgrammingAttempts_ORU_BL           (0xA101u)
#define NVMS_BLOCK_MaxProgrammingAttempts_ORU_BL        (0xA102u)
#define NVMS_BLOCK_BlockFingerprint_ORU_BL              (0xA103u)
#define NVMS_BLOCK_BlockVersion_ORU_BL                  (0xA104u)

#define NVMS_BLOCK_BlockState_01                        (0xA108u)
#define NVMS_BLOCK_ProgrammingAttempts_01               (0xA109u)
#define NVMS_BLOCK_MaxProgrammingAttempts_01            (0xA10Au)
#define NVMS_BLOCK_BlockFingerprint_01                  (0xA10Bu)
#define NVMS_BLOCK_BlockVersion_01                      (0xA10Cu)

#define NVMS_BLOCK_BlockState_02                        (0xA110u)
#define NVMS_BLOCK_ProgrammingAttempts_02               (0xA111u)
#define NVMS_BLOCK_MaxProgrammingAttempts_02            (0xA112u)
#define NVMS_BLOCK_BlockFingerprint_02                  (0xA113u)
#define NVMS_BLOCK_BlockVersion_02                      (0xA114u)

#define NVMS_BLOCK_BlockState_03                        (0xA118u)
#define NVMS_BLOCK_ProgrammingAttempts_03               (0xA119u)
#define NVMS_BLOCK_MaxProgrammingAttempts_03            (0xA11Au)
#define NVMS_BLOCK_BlockFingerprint_03                  (0xA11Bu)
#define NVMS_BLOCK_BlockVersion_03                      (0xA11Cu)

#define NVMS_BLOCK_BlockState_PAD_BLUPD                 (0xA120u)
#define NVMS_BLOCK_ProgrammingAttempts_PAD_BLUPD        (0xA121u)
#define NVMS_BLOCK_MaxProgrammingAttempts_PAD_BLUPD     (0xA122u)
#define NVMS_BLOCK_BlockFingerprint_PAD_BLUPD           (0xA123u)
#define NVMS_BLOCK_BlockVersion_PAD_BLUPD               (0xA124u)
#define NVMS_BLOCK_DestSparePartNum_PAD_BLUPD           (0xA125u)

#define NVMS_BLOCK_BlockState_04                        (0xA128u)
#define NVMS_BLOCK_ProgrammingAttempts_04               (0xA129u)
#define NVMS_BLOCK_MaxProgrammingAttempts_04            (0xA12Au)
#define NVMS_BLOCK_BlockFingerprint_04                  (0xA12Bu)
#define NVMS_BLOCK_BlockVersion_04                      (0xA12Cu)
#define NVMS_BLOCK_DestSparePartNum_04                  (0xA12Du)

#define NVMS_BLOCK_BlockState_05                        (0xA130u)
#define NVMS_BLOCK_ProgrammingAttempts_05               (0xA131u)
#define NVMS_BLOCK_MaxProgrammingAttempts_05            (0xA132u)
#define NVMS_BLOCK_BlockFingerprint_05                  (0xA133u)
#define NVMS_BLOCK_BlockVersion_05                      (0xA134u)
#define NVMS_BLOCK_DestSparePartNum_05                  (0xA135u)

#define NVMS_BLOCK_BlockState_06                        (0xA138u)
#define NVMS_BLOCK_ProgrammingAttempts_06               (0xA139u)
#define NVMS_BLOCK_MaxProgrammingAttempts_06            (0xA13Au)
#define NVMS_BLOCK_BlockFingerprint_06                  (0xA13Bu)
#define NVMS_BLOCK_BlockVersion_06                      (0xA13Cu)
#define NVMS_BLOCK_DestSparePartNum_06                  (0xA13Du)

#define NVMS_BLOCK_BlockState_07                        (0xA140u)
#define NVMS_BLOCK_ProgrammingAttempts_07               (0xA141u)
#define NVMS_BLOCK_MaxProgrammingAttempts_07            (0xA142u)
#define NVMS_BLOCK_BlockFingerprint_07                  (0xA143u)
#define NVMS_BLOCK_BlockVersion_07                      (0xA144u)
#define NVMS_BLOCK_DestSparePartNum_07                  (0xA145u)

#define NVMS_BLOCK_BlockState_08                        (0xA148u)
#define NVMS_BLOCK_ProgrammingAttempts_08               (0xA149u)
#define NVMS_BLOCK_MaxProgrammingAttempts_08            (0xA14Au)
#define NVMS_BLOCK_BlockFingerprint_08                  (0xA14Bu)
#define NVMS_BLOCK_BlockVersion_08                      (0xA14Cu)
#define NVMS_BLOCK_DestSparePartNum_08                  (0xA14Du)

#define NVMS_BLOCK_BlockState_09                        (0xA150u)
#define NVMS_BLOCK_ProgrammingAttempts_09               (0xA151u)
#define NVMS_BLOCK_MaxProgrammingAttempts_09            (0xA152u)
#define NVMS_BLOCK_BlockFingerprint_09                  (0xA153u)
#define NVMS_BLOCK_BlockVersion_09                      (0xA154u)
#define NVMS_BLOCK_DestSparePartNum_09                  (0xA155u)

#define NVMS_BLOCK_BlockState_10                        (0xA158u)
#define NVMS_BLOCK_ProgrammingAttempts_10               (0xA159u)
#define NVMS_BLOCK_MaxProgrammingAttempts_10            (0xA15Au)
#define NVMS_BLOCK_BlockFingerprint_10                  (0xA15Bu)
#define NVMS_BLOCK_BlockVersion_10                      (0xA15Cu)
#define NVMS_BLOCK_DestSparePartNum_10                  (0xA15Du)

#define NVMS_BLOCK_BlockState_11                        (0xA160u)
#define NVMS_BLOCK_ProgrammingAttempts_11               (0xA161u)
#define NVMS_BLOCK_MaxProgrammingAttempts_11            (0xA162u)
#define NVMS_BLOCK_BlockFingerprint_11                  (0xA163u)
#define NVMS_BLOCK_BlockVersion_11                      (0xA164u)
#define NVMS_BLOCK_DestSparePartNum_11                  (0xA165u)

#define NVMS_BLOCK_BlockState_12                        (0xA168u)
#define NVMS_BLOCK_ProgrammingAttempts_12               (0xA169u)
#define NVMS_BLOCK_MaxProgrammingAttempts_12            (0xA16Au)
#define NVMS_BLOCK_BlockFingerprint_12                  (0xA16Bu)
#define NVMS_BLOCK_BlockVersion_12                      (0xA16Cu)
#define NVMS_BLOCK_DestSparePartNum_12                  (0xA16Du)

#define NVMS_BLOCK_BlockState_13                        (0xA170u)
#define NVMS_BLOCK_ProgrammingAttempts_13               (0xA171u)
#define NVMS_BLOCK_MaxProgrammingAttempts_13            (0xA172u)
#define NVMS_BLOCK_BlockFingerprint_13                  (0xA173u)
#define NVMS_BLOCK_BlockVersion_13                      (0xA174u)
#define NVMS_BLOCK_DestSparePartNum_13                  (0xA175u)

#define NVMS_BLOCK_BlockState_PAD_BL                    (0xA178u)
#define NVMS_BLOCK_ProgrammingAttempts_PAD_BL           (0xA179u)
#define NVMS_BLOCK_MaxProgrammingAttempts_PAD_BL        (0xA17Au)
#define NVMS_BLOCK_BlockFingerprint_PAD_BL              (0xA17Bu)
#define NVMS_BLOCK_BlockVersion_PAD_BL                  (0xA17Cu)

#define NVMS_BLOCK_BlockState_14                        (0xA180u)
#define NVMS_BLOCK_ProgrammingAttempts_14               (0xA181u)
#define NVMS_BLOCK_MaxProgrammingAttempts_14            (0xA182u)
#define NVMS_BLOCK_BlockFingerprint_14                  (0xA183u)
#define NVMS_BLOCK_BlockVersion_14                      (0xA184u)

#define NVMS_BLOCK_BlockState_15                        (0xA188u)
#define NVMS_BLOCK_ProgrammingAttempts_15               (0xA189u)
#define NVMS_BLOCK_MaxProgrammingAttempts_15            (0xA18Au)
#define NVMS_BLOCK_BlockFingerprint_15                  (0xA18Bu)
#define NVMS_BLOCK_BlockVersion_15                      (0xA18Cu)

#define NVMS_BLOCK_BlockState_16                        (0xA190u)
#define NVMS_BLOCK_ProgrammingAttempts_16               (0xA191u)
#define NVMS_BLOCK_MaxProgrammingAttempts_16            (0xA192u)
#define NVMS_BLOCK_BlockFingerprint_16                  (0xA193u)
#define NVMS_BLOCK_BlockVersion_16                      (0xA194u)

#define NVMS_BLOCK_BlockState_17                        (0xA198u)
#define NVMS_BLOCK_ProgrammingAttempts_17               (0xA199u)
#define NVMS_BLOCK_MaxProgrammingAttempts_17            (0xA19Au)
#define NVMS_BLOCK_BlockFingerprint_17                  (0xA19Bu)
#define NVMS_BLOCK_BlockVersion_17                      (0xA19Cu)

#define NVMS_BLOCK_BlockState_18                        (0xA1A0u)
#define NVMS_BLOCK_ProgrammingAttempts_18               (0xA1A1u)
#define NVMS_BLOCK_MaxProgrammingAttempts_18            (0xA1A2u)
#define NVMS_BLOCK_BlockFingerprint_18                  (0xA1A3u)
#define NVMS_BLOCK_BlockVersion_18                      (0xA1A4u)

#define NVMS_BLOCK_BlockState_19                        (0xA1A8u)
#define NVMS_BLOCK_ProgrammingAttempts_19               (0xA1A9u)
#define NVMS_BLOCK_MaxProgrammingAttempts_19            (0xA1AAu)
#define NVMS_BLOCK_BlockFingerprint_19                  (0xA1ABu)
#define NVMS_BLOCK_BlockVersion_19                      (0xA1ACu)

#define NVMS_BLOCK_BlockState_20                        (0xA1B0u)
#define NVMS_BLOCK_ProgrammingAttempts_20               (0xA1B1u)
#define NVMS_BLOCK_MaxProgrammingAttempts_20            (0xA1B2u)
#define NVMS_BLOCK_BlockFingerprint_20                  (0xA1B3u)
#define NVMS_BLOCK_BlockVersion_20                      (0xA1B4u)

#define NVMS_BLOCK_BlockState_21                        (0xA1B8u)
#define NVMS_BLOCK_ProgrammingAttempts_21               (0xA1B9u)
#define NVMS_BLOCK_MaxProgrammingAttempts_21            (0xA1BAu)
#define NVMS_BLOCK_BlockFingerprint_21                  (0xA1BBu)
#define NVMS_BLOCK_BlockVersion_21                      (0xA1BCu)

#define NVMS_BLOCK_BlockState_22                        (0xA1C0u)
#define NVMS_BLOCK_ProgrammingAttempts_22               (0xA1C1u)
#define NVMS_BLOCK_MaxProgrammingAttempts_22            (0xA1C2u)
#define NVMS_BLOCK_BlockFingerprint_22                  (0xA1C3u)
#define NVMS_BLOCK_BlockVersion_22                      (0xA1C4u)

#define NVMS_BLOCK_BlockState_23                        (0xA1C8u)
#define NVMS_BLOCK_ProgrammingAttempts_23               (0xA1C9u)
#define NVMS_BLOCK_MaxProgrammingAttempts_23            (0xA1CAu)
#define NVMS_BLOCK_BlockFingerprint_23                  (0xA1CBu)
#define NVMS_BLOCK_BlockVersion_23                      (0xA1CCu)

#define NVMS_BLOCK_BlockState_24                        (0xA1D0u)
#define NVMS_BLOCK_ProgrammingAttempts_24               (0xA1D1u)
#define NVMS_BLOCK_MaxProgrammingAttempts_24            (0xA1D2u)
#define NVMS_BLOCK_BlockFingerprint_24                  (0xA1D3u)
#define NVMS_BLOCK_BlockVersion_24                      (0xA1D4u)

#define NVMS_BLOCK_BlockState_25                        (0xA1D8u)
#define NVMS_BLOCK_ProgrammingAttempts_25               (0xA1D9u)
#define NVMS_BLOCK_MaxProgrammingAttempts_25            (0xA1DAu)
#define NVMS_BLOCK_BlockFingerprint_25                  (0xA1DBu)
#define NVMS_BLOCK_BlockVersion_25                      (0xA1DCu)

#define NVMS_BLOCK_BlockState_26                        (0xA1E0u)
#define NVMS_BLOCK_ProgrammingAttempts_26               (0xA1E1u)
#define NVMS_BLOCK_MaxProgrammingAttempts_26            (0xA1E2u)
#define NVMS_BLOCK_BlockFingerprint_26                  (0xA1E3u)
#define NVMS_BLOCK_BlockVersion_26                      (0xA1E4u)

#define NVMS_BLOCK_BlockState_27                        (0xA1E8u)
#define NVMS_BLOCK_ProgrammingAttempts_27               (0xA1E9u)
#define NVMS_BLOCK_MaxProgrammingAttempts_27            (0xA1EAu)
#define NVMS_BLOCK_BlockFingerprint_27                  (0xA1EBu)
#define NVMS_BLOCK_BlockVersion_27                      (0xA1ECu)

#define NVMS_BLOCK_BlockState_28                        (0xA1F0u)
#define NVMS_BLOCK_ProgrammingAttempts_28               (0xA1F1u)
#define NVMS_BLOCK_MaxProgrammingAttempts_28            (0xA1F2u)
#define NVMS_BLOCK_BlockFingerprint_28                  (0xA1F3u)
#define NVMS_BLOCK_BlockVersion_28                      (0xA1F4u)

#define NVMS_BLOCK_BlockState_29                        (0xA1F8u)
#define NVMS_BLOCK_ProgrammingAttempts_29               (0xA1F9u)
#define NVMS_BLOCK_MaxProgrammingAttempts_29            (0xA1FAu)
#define NVMS_BLOCK_BlockFingerprint_29                  (0xA1FBu)
#define NVMS_BLOCK_BlockVersion_29                      (0xA1FCu)

#define NVMS_BLOCK_DUMMY                                (0u)
#define NVMS_BLOCK_MAXSIZE                              (32) /* max block is ODX file Ident - 26 */
#define NVMS_DATA_MAXSIZE                               (NVMS_BLOCK_MAXSIZE - 6) /* ID is 2 b, CRC is 4 b */
#define NVMS_CRCINIT                                    (0xFFFFFFFFu)

/* NVMS FLS sector related definitions */
#define NVMS_FLS_SEC_01_VALID                           (0x01u)
#define NVMS_FLS_SEC_01_INVALID                         (0x02u)
#define NVMS_FLS_SEC_01_ERASED                          (0x03u)
#define NVMS_FLS_SEC_02_VALID                           (0x04u)
#define NVMS_FLS_SEC_01_AND_SEC_02_INVALID              (0x05u)
#define NVMS_FLS_SEC_01_ERASED_AND_SEC_02_INVALID       (0x06u)
#define NVMS_FLS_SEC_01_INVALID_AND_SEC_02_ERASED       (0x07u)
#define NVMS_FLS_SEC_01_AND_SEC_02_ERASED               (0x08u)

#define NVMS_FLS_SEC_01_ADDR                            (0x00800000ul)
#define NVMS_FLS_SEC_02_ADDR                            (0x00804000ul)
#define NVMS_FLS_SEC_SIZE                               (16384u)

#define NVMS_SWITCH_TO_FLS_SEC_01                       (0xA5A5u)
#define NVMS_SWITCH_TO_FLS_SEC_02                       (0x9696u)


#define  SECTOR_SIZE_16KB                       0x4000
#define  SECTOR_SIZE_32KB                       0x8000
#define  SECTOR_SIZE_64KB                       0x20000
#define  SECTOR_SIZE_128KB                      0x10000
#define  SECTOR_SIZE_256KB                      0x40000

#define CRC32_16KB_ERASED_SECTOR                0x690B37D3 
#define CRC32_32KB_ERASED_SECTOR                0x1B43EABD 

/*==================[type definitions]=======================================*/
#pragma pack(1)
typedef struct
{
    uint8               u8aSwVersion[4];
    uint8               u8aSuppVersion[8];
    uint32              u32BuildTimeStamp;
}S_NVMsBlockVersion;
#pragma pack()

typedef union
{
    uint8 u8Array[16];
    S_NVMsBlockVersion st;
}NVMsBlockVersion;

#pragma pack(1)
typedef struct
{
    uint8               u8aProgDate[3];
    uint8               u8aTesterSerial[6];
}S_NVMsBlockFingerprint;
#pragma pack()

typedef union
{
    uint8 u8Array[9];
    S_NVMsBlockFingerprint st;
} NVMsBlockFingerprint;

/*==================[external constants]=====================================*/
/*==================[external data]==========================================*/
/*==================[external function declarations]=========================*/



FUNC(Std_ReturnType, BL_CODE) NVMS_ReadBlockSync
(
uint16 BlockId,
P2VAR( uint8, AUTOMATIC, BL_APPL_DATA ) DestPtr
);

FUNC(Std_ReturnType, BL_CODE) NVMS_CheckReadBlock
(
uint16 BlockId
);

FUNC(Std_ReturnType, BL_CODE) NVMS_WriteBlockSync
(
uint16 BlockId,
P2CONST( uint8, AUTOMATIC, BL_APPL_DATA ) SrcPtr
);

FUNC(Std_ReturnType, BL_CODE) NVMS_FindDefVal
(
const  uint16 BlockId,
uint8* pu8BlockSize,
uint8* pu8IdSize,
const uint8** ppuDefVal
);

FUNC(Std_ReturnType, BL_CODE) NVMS_CreateBlocksWithDefaultValues
(
void
);



/*==================[end of file]============================================*/
#endif
