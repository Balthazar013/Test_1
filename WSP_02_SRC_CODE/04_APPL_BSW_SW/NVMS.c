/** \brief NVMS read and write functions
 **
 **/



/*==================[inclusions]============================================*/
#include <MemIf.h>
#include <TSMem.h>           /* Elektrobit Automotive TS_MemCpy/TS_MemSet */
#include <NVMS.h>   /* Extern NVRAM Manager API                  */


/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/
typedef struct sNvmS_Descr
{
    uint16 Id;
    uint8  Size;
    const  uint8* DefVal;
} tNvmS_Descr;

/** \brief Physical to Fls address mapping */
typedef struct {
  uint32 physStart;     /**< Physical address start of block */
  uint32 flsStart;      /**< Fls address start of block */
  uint32 length;        /**< Length of block */
} FlashFlsAddressMapping;


/*==================[internal constants]=====================================*/
static const tNvmS_Descr NvmS_Descr[] =
{
    /* aligned at 32 bytes (not 16) */
    { NVMS_BLOCK_DUMMY                              , 0,  NULL_PTR                 },

/*  { NVMS_BLOCK_SERIES_KEY                         , 4,  NULL_PTR                 }, */

    { NVMS_BLOCK_SAK_PenaltyTime                    , 4,  NULL_PTR                 },
    { NVMS_BLOCK_SAK_BreakInTries                   , 4,  NULL_PTR                 },

    { NVMS_BLOCK_SwBlockNumber                      , 1,  NULL_PTR                 },
    // contains BLCFG_NUMBER_OF_LOGICAL_BLOCKS(1), MAX_NUMBER_OF_LOGICAL_IDENT_BLOCKS(1), MAX_NUMBER_OF_LOGICAL_MEAS_BLOCKS(1)
    { NVMS_BLOCK_SwBlockNumberNEW                   , 3,  NULL_PTR                 },

    { NVMS_BLOCK_F187VWSparePartNum                 , 11, NULL_PTR                 },
    { NVMS_BLOCK_F189VwSwVerNum                     , 4,  NULL_PTR                 },
    { NVMS_BLOCK_F191VwEcuHwNum                     , 11, NULL_PTR                 },
    { NVMS_BLOCK_F19EODXFileIdent                   , 26, NULL_PTR                 },
    { NVMS_BLOCK_F1A2ODXFileVer                     , 6,  NULL_PTR                 },
    { NVMS_BLOCK_F1A3VwEcuHwVerNum                  , 3,  NULL_PTR                 },
    { NVMS_BLOCK_F1DFEcuProgrInfo                   , 1,  NULL_PTR                 },
    { NVMS_BLOCK_F1D5FDSProjectData                 , 7,  NULL_PTR                 },

    { NVMS_BLOCK_2A30SubsystemIdentification        , 3,  NULL_PTR                 },
    { NVMS_BLOCK_F179ECUSupplierNumber              , 4,  NULL_PTR                 },
    { NVMS_BLOCK_F17DECUProdTestSystemNumber        , 4,  NULL_PTR                 },
    { NVMS_BLOCK_F17EECUProdChangeNumber            , 8,  NULL_PTR                 },
    { NVMS_BLOCK_F17FVWSupplierNumber               , 3,  NULL_PTR                 },
    { NVMS_BLOCK_F18ASystemSupplierIdentifier       , 23, NULL_PTR                 },
    { NVMS_BLOCK_F18BECUManufacturingDate           , 3,  NULL_PTR                 },
    { NVMS_BLOCK_F18CECUSerialNumber                , 23, NULL_PTR                 },
    { NVMS_BLOCK_F1AENumberOfLogins                 , 1,  NULL_PTR                 },

/*  { NVMS_BLOCK_F1A0DataSetNum                     , 11, NULL_PTR                 }, */
/*  { NVMS_BLOCK_F1A1DataSetVer                     , 4,  NULL_PTR                 }, */
/*  { NVMS_BLOCK_F1A8DataSetTesterSerial            , 6,  NULL_PTR                 }, */
/*  { NVMS_BLOCK_F1A9DatasetProgrammingDate         , 3,  NULL_PTR                 }, */
/*  { NVMS_BLOCK_F1B1DataSetIdent                   , 12, NULL_PTR                 }, */
/*  { NVMS_BLOCK_F1B3DataSetName                    , 12, NULL_PTR                 }, */
    { NVMS_BLOCK_F180SupplierPlanId                 , 3,  NULL_PTR                 },

    { NVMS_BLOCK_TstEmuSwBlkFlSts01                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts02                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts03                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts04                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts05                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts06                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts07                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts08                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts09                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts10                 , 19, NULL_PTR                 },
    { NVMS_BLOCK_TstEmuSwBlkFlSts11                 , 19, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_ORU_BL                  ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_ORU_BL         ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_ORU_BL      ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_ORU_BL            ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_ORU_BL                , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_01                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_01             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_01          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_01                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_01                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_02                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_02             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_02          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_02                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_02                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_03                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_03             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_03          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_03                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_03                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_PAD_BLUPD               ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_PAD_BLUPD      ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_PAD_BLUPD   ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_PAD_BLUPD         ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_PAD_BLUPD             , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_PAD_BLUPD         , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_04                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_04             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_04          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_04                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_04                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_04                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_05                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_05             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_05          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_05                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_05                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_05                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_06                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_06             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_06          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_06                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_06                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_06                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_07                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_07             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_07          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_07                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_07                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_07                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_08                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_08             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_08          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_08                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_08                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_08                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_09                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_09             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_09          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_09                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_09                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_09                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_10                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_10             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_10          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_10                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_10                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_10                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_11                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_11             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_11          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_11                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_11                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_11                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_12                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_12             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_12          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_12                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_12                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_12                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_13                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_13             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_13          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_13                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_13                    , 16, NULL_PTR                 },
    { NVMS_BLOCK_DestSparePartNum_13                , 11, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_PAD_BL                  ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_PAD_BL         ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_PAD_BL      ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_PAD_BL            ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_PAD_BL                , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_14                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_14             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_14          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_14                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_14                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_15                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_15             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_15          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_15                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_15                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_16                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_16             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_16          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_16                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_16                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_17                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_17             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_17          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_17                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_17                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_18                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_18             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_18          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_18                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_18                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_19                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_19             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_19          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_19                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_19                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_20                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_20             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_20          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_20                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_20                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_21                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_21             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_21          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_21                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_21                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_22                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_22             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_22          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_22                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_22                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_23                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_23             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_23          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_23                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_23                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_24                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_24             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_24          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_24                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_24                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_25                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_25             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_25          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_25                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_25                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_26                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_26             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_26          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_26                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_26                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_27                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_27             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_27          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_27                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_27                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_28                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_28             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_28          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_28                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_28                    , 16, NULL_PTR                 },

    { NVMS_BLOCK_BlockState_29                      ,  1, NULL_PTR                 },
    { NVMS_BLOCK_ProgrammingAttempts_29             ,  2, NULL_PTR                 },
    { NVMS_BLOCK_MaxProgrammingAttempts_29          ,  2, NULL_PTR                 },
    { NVMS_BLOCK_BlockFingerprint_29                ,  9, NULL_PTR                 },
    { NVMS_BLOCK_BlockVersion_29                    , 16, NULL_PTR                 }

};

/*==================[internal data]==========================================*/

/* Table of pre-computed values for CRC32. Used Polynomial is 0xEDB88320 */
STATIC CONST(uint32, BL_CONST) Crc_Table32[16u] =
{
  (uint32)0x00000000UL, (uint32)0x1db71064UL,
  (uint32)0x3b6e20c8UL, (uint32)0x26d930acUL,
  (uint32)0x76dc4190UL, (uint32)0x6b6b51f4UL,
  (uint32)0x4DB26158UL, (uint32)0x5005713cUL,
  (uint32)0xedb88320UL, (uint32)0xf00f9344UL,
  (uint32)0xd6d6a3e8UL, (uint32)0xcb61b38cUL,
  (uint32)0x9b64c2b0UL, (uint32)0x86d3d2d4UL,
  (uint32)0xa00ae278UL, (uint32)0xbdbdf21cUL
};

STATIC volatile MemIf_JobResultType FlashRequestResult;
/* Address mapping to revert the mapping done in the Fls.
 * See FlashConvertAddressToFls() description for details.
 */

STATIC CONST(FlashFlsAddressMapping, BL_APPL_DATA) FlashToFlsMapping[] = {
  /* Phys. addr,  Fls address,  Size */
  { 0x00800000ul, 0x00000000ul, 0x04000 },      /* 0  FLS_DATA_ARRAY_0_PART_0_L00 */
  { 0x00804000ul, 0x00004000ul, 0x04000 },      /* 1  FLS_DATA_ARRAY_0_PART_0_L01 */
  { 0x00f98000ul, 0x00008000ul, 0x04000 },      /* 2  FLS_CODE_ARRAY_0_PART_1_L02 */
  { 0x00f9c000ul, 0x0000c000ul, 0x04000 },      /* 3  FLS_CODE_ARRAY_0_PART_1_L03 */
  { 0x00808000ul, 0x00010000ul, 0x08000 },      /* 4  FLS_DATA_ARRAY_0_PART_2_L00 */
  { 0x00810000ul, 0x00018000ul, 0x08000 },      /* 5  FLS_DATA_ARRAY_0_PART_3_L01 */
  { 0x00fa0000ul, 0x00020000ul, 0x10000 },      /* 6  FLS_CODE_ARRAY_0_PART_4_L00 */
  { 0x00fb0000ul, 0x00030000ul, 0x10000 },      /* 7  FLS_CODE_ARRAY_0_PART_4_L01 */
  { 0x00fc0000ul, 0x00040000ul, 0x10000 },      /* 8  FLS_CODE_ARRAY_0_PART_4_L02 */
  { 0x00fd0000ul, 0x00050000ul, 0x10000 },      /* 9  FLS_CODE_ARRAY_0_PART_5_L03 */
  { 0x00fe0000ul, 0x00060000ul, 0x10000 },      /* 10 FLS_CODE_ARRAY_0_PART_5_L04 */
  { 0x00ff0000ul, 0x00070000ul, 0x10000 },      /* 11 FLS_CODE_ARRAY_0_PART_5_L05 */
  { 0x01000000ul, 0x00080000ul, 0x40000 },      /* 12 FLS_CODE_ARRAY_0_PART_6_L00 */
  { 0x01040000ul, 0x000c0000ul, 0x40000 },      /* 13 FLS_CODE_ARRAY_0_PART_6_L01 */
  { 0x01080000ul, 0x00100000ul, 0x40000 },      /* 14 FLS_CODE_ARRAY_0_PART_6_L02 */
  { 0x010c0000ul, 0x00140000ul, 0x40000 },      /* 15 FLS_CODE_ARRAY_0_PART_6_L03 */
  { 0x01100000ul, 0x00180000ul, 0x40000 },      /* 16 FLS_CODE_ARRAY_0_PART_7_L04 */
  { 0x01140000ul, 0x001c0000ul, 0x40000 },      /* 17 FLS_CODE_ARRAY_0_PART_7_L05 */
  { 0x01180000ul, 0x00200000ul, 0x40000 },      /* 18 FLS_CODE_ARRAY_0_PART_7_L06 */
  { 0x011c0000ul, 0x00240000ul, 0x40000 },      /* 19 FLS_CODE_ARRAY_0_PART_7_L07 */
};

// first 4 bytes shall be 0 because of boot description of the zone
static const uint8 u8Validity[NVMS_BLOCK_MAXSIZE] =
    {
          0x00u, 0x00u, 0x00u, 0x00u, 'N',   'V',   'M',   'S'
        , 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu
        , 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu
        , 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu
    };

static const uint8 u8Empty[NVMS_BLOCK_MAXSIZE] =
    {
          0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu
        , 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu
        , 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu
        , 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu
    };


/*==================[internal function definitions]==========================*/

static FUNC(Std_ReturnType, BL_CODE) FlashConvertAddressToFls( uint32 physAddress, P2VAR(uint32, AUTOMATIC, BL_APPL_DATA) flsAddress)
{
  Std_ReturnType result = E_NOT_OK;
  uint8 i = 0;
  while(i < sizeof(FlashToFlsMapping) / sizeof(FlashFlsAddressMapping))
  {
    uint32 start = FlashToFlsMapping[i].physStart;
    uint32 end = start + FlashToFlsMapping[i].length;
    if(physAddress >= start && physAddress < end)
    {
      result = E_OK;
      *flsAddress = FlashToFlsMapping[i].flsStart + (physAddress - start);
      break;
    }
    i++;
  }
  return result;
}


/** \brief Calculation of CRC32 (table variant)
 **
 ** This function performs the table variant calculation of a CRC32
 ** value over the memory block referenced by \p Crc_DataPtr of byte
 ** length \p Crc_Length.
 **
 ** \pre \p Crc_DataPtr shall be a valid pointer
 ** \pre \p Crc_DataPtr shall point to a memory region at least of
 **    byte length \p Crc_Length
 **
 ** \param[in]  Crc_DataPtr       Pointer to start address of data block
 ** \param[in]  Crc_Length        Length of data block
 ** \param[in]  Crc_StartValue32  Initial Value
 **
 ** \returns The calculated CRC32 value
 **
 ** \Reentrancy {Reentrant}
 ** \Synchronicity{Synchronous}
 **/
static FUNC(uint32, BL_CODE) CalculateCRC32_Table
(
  P2VAR(uint8, AUTOMATIC, BL_APPL_DATA) Crc_DataPtr,
  uint32 Crc_Length,
  uint32 Crc_StartValue32
)
{
  uint32 Crc_Value; /* temporary crc value */
  uint8 i;          /* table index */
  P2CONST(uint8, AUTOMATIC, BL_APPL_DATA) DataPtr; /* internal byte pointer to the memory block */

  /* initialize variables */
  DataPtr = (const uint8 *)Crc_DataPtr;
  Crc_Value = Crc_StartValue32;

  /* Process all data byte-wise */
  while (Crc_Length > (uint32)0)
  {
    /*- Process low nibble of current data -*/
    i = (uint8)(Crc_Value & (uint32)0x0000000FU);
    i ^= (uint8)(*DataPtr & (uint8)0x0FU);

    Crc_Value = (uint32)(Crc_Value >> 4U);
    Crc_Value ^= Crc_Table32[i];

    /*- Process high nibble of current data -*/
    i = (uint8)(Crc_Value & (uint32)0x0000000FU);
    i ^= (uint8)((uint8)(*DataPtr & (uint8)0xF0U) >> 4U);

    Crc_Value = (uint32)(Crc_Value >> 4U);
    Crc_Value ^= Crc_Table32[i];

    DataPtr = &DataPtr[1]; /* increment the pointer */

    --Crc_Length; /* and decrease the remaining bytes to calculate */
  }  /* while (Crc_Length > (uint32)0) */

  return Crc_Value;
} /* uint32 CalculateCRC32_Table */

/** \brief Write a data block to the flash memory
 **
 ** Writes data from RAM memory buffer to ROM (Flash memory). The integrator is required
 ** to implement this function. Usually writing larger blocks to Flash is a slow operation.
 ** It is advisable to send "response pendings" on the bus in the write loop.
 **
 ** \param[in] pBuffer   Pointer to RAM buffer
 ** \param[in]  size     Size in bytes of the data block to be written
 ** \param[in]  adr      Physical address in ROM memory, this is the start address of writing
 **
 ** \returns  Error value
 **
 ** \retval      E_OK            Operation successful
 ** \retval      E_NOT_OK        Operation failed
 **
 ** \Reentrancy {Not Reentrant}
 ** \Synchronicity{Synchronous}
 **/
static FUNC(uint8, BL_CODE) FLASH_RWriteSync
(
  P2CONST(uint8, AUTOMATIC, BL_APPL_DATA) pBuffer,
  uint32 size,
  uint32 adr
)
{
  uint32 dst = 0;
  FlashRequestResult = MEMIF_JOB_FAILED;

  if(FlashConvertAddressToFls(adr, &dst) == E_OK)
  {
    do
    {
      // assure no other task use Fls (asynchronous mode)
      Fee_MainFunction();
      Fls_MainFunction();
      FlashRequestResult = Fee_GetJobResult();
    } while (FlashRequestResult == MEMIF_JOB_PENDING);
    
    if (Fls_Write(dst, pBuffer, size) == E_OK)
    {
      do
      {
          Fls_MainFunction();
          FlashRequestResult = Fls_GetJobResult();
      } while (FlashRequestResult == MEMIF_JOB_PENDING);
    }
  }

  return FlashRequestResult;
}

/** \brief Clears a data block in the flash memory
 **
 ** Clears data in Flash memory. The integrator is required to implement this
 ** function. Usually clearing larger blocks in Flash is a slow operation. When
 ** erasing larger blocks it is advisable to use Fls_Erase function for smaller
 ** blocks and send response pendings on the bus
 **
 ** \param[in]   size     Size in bytes of the data block to be cleared
 ** \param[in]   adr      Physical address in ROM memory, start address
 **
 ** \returns  Error value
 **
 ** \retval      E_OK            Operation successful
 ** \retval      E_NOT_OK        Operation failed
 **
 ** \Reentrancy {Not Reentrant}
 ** \Synchronicity{Synchronous}
 **/
FUNC(uint8, BL_CODE) FLASH_REraseSync
(
  uint32 size,
  uint32 adr
)
{
  FlashRequestResult = MEMIF_JOB_FAILED;

  // DO NOTHING

  return FlashRequestResult;
}


/*==================[external constants]=====================================*/
/*==================[external data]==========================================*/
/*==================[external function definitions]==========================*/


static FUNC(Std_ReturnType, BL_CODE) FindEmptyFlashAddr( uint32* pu32Addr );
static FUNC(Std_ReturnType, BL_CODE) FindBlockId( const uint16 BlockId, uint32* pu32Addr );
static FUNC(Std_ReturnType, BL_CODE) ReadBlockInternal( const uint16 BlockId, P2VAR( uint8, AUTOMATIC, BL_APPL_DATA ) DestPtr, const uint8 IsDefaultChecked );
static FUNC(Std_ReturnType, BL_CODE) WriteBlockInternal( const uint16 BlockId, P2CONST( uint8, AUTOMATIC, BL_APPL_DATA ) SrcPtr, const uint8 IsDefaultChecked );
static FUNC(uint8, BL_CODE) FindActNVMsFlsSec( void );
static FUNC(uint8, BL_CODE) CheckNVMsFlsSecSts( void );

/*==================[external constants]=====================================*/
/*==================[external data]==========================================*/


/*==================[internal function definitions]==========================*/





/*==================[external function definitions]==========================*/

/** \brief Reads a block of data from persistent memory
 **
 ** Reads block of data from logistical or programming persistent memory.
 ** This is a synchronous function. The integrator is required to implement
 ** this function.
 ** The persistent blocks are defined in the file Nvm_RamData_Template.h.
 **
 ** \param[in]   BlockId      Id of the NvM block to be read
 ** \param[out]  DestPtr      Pointer to a RAM buffer into which data from the
 **                           persistent memory is copied
 **
 ** \returns  Error value
 **
 ** \retval      E_OK            Operation successful
 ** \retval      E_NOT_OK        Operation failed
 **
 ** \Reentrancy {Not Reentrant}
 ** \Synchronicity{Synchronous}
 **/
FUNC(Std_ReturnType, BL_CODE) NVMS_ReadBlockSync
(
  uint16 BlockId,
  P2VAR( uint8, AUTOMATIC, BL_APPL_DATA ) DestPtr
)
{
    return ReadBlockInternal( BlockId, DestPtr, 1 );
}

/** \brief Check for validity block of data from persistent memory before Read. Need for CheckRead()
 **
 ** Reads block of data from logistical or programming persistent memory.
 ** This is a synchronous function. The integrator is required to implement
 ** this function.
 ** The persistent blocks are defined in the file Nvm_RamData_Template.h.
 **
 ** \param[in]   BlockId      Id of the NvM block to be read
 **
 ** \returns  Error value
 **
 ** \retval      E_OK            Operation successful
 ** \retval      E_NOT_OK        Operation failed
 **
 ** \Reentrancy {Not Reentrant}
 ** \Synchronicity{Synchronous}
 **/
FUNC(Std_ReturnType, BL_CODE) NVMS_CheckReadBlock
(
  uint16 BlockId
)
{
    uint32 u32Addr;
    const uint8 *pu8DefVal;
    uint8  u8BlockSize = 0;
    uint8  u8IdSize = 0;

    uint8  u8IsOk  = FindBlockId( BlockId, &u32Addr ); // check CRC also
    uint8  u8IsOk2 = NVMS_FindDefVal( BlockId, &u8BlockSize, &u8IdSize, &pu8DefVal );

    if( u8IsOk != E_OK )
    {
        if( u8IsOk2 == E_OK )
        {
            return E_OK;
        }
        else
        {
            return E_NOT_OK;
        }
    }
    return E_OK;
}

/** \brief Write a block of data to persistent memory. If value to write is same as default for block, no write is executed
 **
 ** Writes a block of data to persistent memory. This is a synchronous function.
 ** The integrator is required to implement this function. The persistent blocks
 ** are defined in Nvm_RamData_Template.h file

 ** \param[in]   BlockId         Id of the NvM block to be read
 ** \param[in]   SrcPtr          Pointer to a RAM buffer which is written to persistent memory
 **
 ** \returns     Error value
 **
 ** \retval      E_OK            Operation successful
 ** \retval      E_NOT_OK        Operation failed
 **
 ** \Reentrancy {Not Reentrant}
 ** \Synchronicity{Synchronous}
**/
FUNC( Std_ReturnType, BL_CODE ) NVMS_WriteBlockSync
(
  uint16 BlockId,
  P2CONST( uint8, AUTOMATIC, BL_APPL_DATA ) SrcPtr
)
{
    return WriteBlockInternal( BlockId, SrcPtr, 1 );
}

/** \brief NVMS_FindDefVal
**/
FUNC(Std_ReturnType, BL_CODE) NVMS_FindDefVal( const uint16 BlockId, uint8* pu8BlockSize, uint8*  pu8IdSize, const uint8** ppuDefVal)
{
    const uint16 u16BlockDescrSize = sizeof(NvmS_Descr) / sizeof(NvmS_Descr[0]);
    uint16 u16Indx;

    if(( pu8BlockSize != NULL_PTR ) && (pu8IdSize != NULL_PTR) && ( ppuDefVal != NULL_PTR ))
    {
        *pu8BlockSize = 0; // init value
        *pu8IdSize    = 0;
        *ppuDefVal = NvmS_Descr[NVMS_BLOCK_DUMMY].DefVal;

        // TODO: cycle to be exchanged with qsearch
        for( u16Indx = 0; u16Indx < u16BlockDescrSize; u16Indx++ )
        {
            if( NvmS_Descr[u16Indx].Id == BlockId )
            {
                *ppuDefVal = NvmS_Descr[u16Indx].DefVal;
                *pu8BlockSize = NvmS_Descr[u16Indx].Size; // need block size, even no default value
                *pu8IdSize = sizeof(NvmS_Descr[u16Indx].Id);

                if( *pu8BlockSize > NVMS_DATA_MAXSIZE )
                {
                    // PROTECTION
                    *pu8BlockSize = NVMS_DATA_MAXSIZE;
                }
                if( NvmS_Descr[u16Indx].DefVal != NULL_PTR )
                {
                    return E_OK;
                }
            }

        }
    }
    else
    {
        return E_NOT_OK;
    }
    return E_NOT_OK;
}

/** \brief NVMS_CreateBlocksWithDefaultValues
**/
FUNC(Std_ReturnType, BL_CODE) NVMS_CreateBlocksWithDefaultValues( void )
{
    const uint16 u16Number = sizeof(NvmS_Descr) / sizeof(NvmS_Descr[0]);
    uint32 u32Addr;
    uint16 u16Indx;

    for( u16Indx = 0; u16Indx < u16Number; u16Indx++ )
    {
        if( NvmS_Descr[ u16Indx ].DefVal != NULL_PTR )
        {
            uint8 u8IsOk  = FindBlockId( NvmS_Descr[ u16Indx ].Id, &u32Addr ); // check CRC also
            if( u8IsOk != E_OK )
            {
                WriteBlockInternal( NvmS_Descr[ u16Indx ].Id,  NvmS_Descr[ u16Indx ].DefVal, 0 );
            }
        }
    }
    return E_OK;
}


/*==================[internal function definitions]==========================*/

/* IsDefaultChecked > 0, If block not exist in flash but default value is assigned, returns "found" */
/* IsDefaultChecked == 0, If block not exist in flash, returns "not found" */
static FUNC(Std_ReturnType, BL_CODE) ReadBlockInternal
(
  const uint16 BlockId,
  P2VAR( uint8, AUTOMATIC, BL_APPL_DATA ) DestPtr,
  const uint8 IsDefaultChecked
)
{
    uint32 u32Addr;
    const uint8 *pu8DefVal;
    uint8  u8BlockSize = 0;
    uint8  u8IdSize = 0;
    uint8  u8IsOk  = FindBlockId( BlockId, &u32Addr ); // check CRC also
    uint8  u8IsOk2 = E_NOT_OK;
    if( IsDefaultChecked != 0 )
    {
        u8IsOk2 = NVMS_FindDefVal( BlockId, &u8BlockSize, &u8IdSize, &pu8DefVal );
    }

    if( DestPtr != NULL_PTR )
    {
        if( u8IsOk == E_OK )
        {
            TS_MemCpy( &DestPtr[0], (void *)(u32Addr + u8IdSize), u8BlockSize );
        }
        else
        {
            if( u8IsOk2 == E_OK )
            {
                TS_MemCpy( &DestPtr[0], pu8DefVal, u8BlockSize );
            }
            else
            {
                return E_NOT_OK;
            }
        }
    }
    else
    {
        return E_NOT_OK;
    }
    return E_OK;
}

/* IsDefaultChecked > 0, If value to write is same as default for block, no write is executed */
/* IsDefaultChecked == 0, If block not exist in flash, write is executed, i.e. no check for default */
static FUNC( Std_ReturnType, BL_CODE ) WriteBlockInternal
(
  const uint16 BlockId,
  P2CONST( uint8, AUTOMATIC, BL_APPL_DATA ) SrcPtr,
  const uint8 IsDefaultChecked
)
{
    uint32 u32Addr;
    const uint8 *pu8DefVal;
    uint16 *pu16Id;
    uint32 *pu32Crc;
    uint8  u8BlockSize = 0;
    uint8  u8IdSize = 0;
    uint8  u8Indx;
    uint8  buff[NVMS_BLOCK_MAXSIZE + 2];

    // make unique initial value, if memset with 0x00 is used --> block with default value 0 is never created!!!
    for( u8Indx = 0; u8Indx < NVMS_BLOCK_MAXSIZE; u8Indx++ )
    {
        buff[u8Indx] = SrcPtr[u8Indx] ^ 0xFFu;
    }

    ReadBlockInternal( BlockId, buff, IsDefaultChecked );
    NVMS_FindDefVal( BlockId, &u8BlockSize, &u8IdSize, &pu8DefVal ); // used only to find Block Size

    if( u8BlockSize == 0 )
    {
        return E_NOT_OK;
    }

    if( 0 != TS_MemCmp( &buff[0], &SrcPtr[0], u8BlockSize ))
    {
        if( FindEmptyFlashAddr( &u32Addr ) != E_OK )
        {
            return E_NOT_OK; // cannot switch flash blocks and erase new one
        }
        pu32Crc = (uint32 *)(&buff[0] + u8IdSize + u8BlockSize);
        pu16Id = (uint16 *)&buff[0];

        TS_MemCpy( (&buff[0] + u8IdSize), &SrcPtr[0], u8BlockSize ); // copy block data
        *pu16Id = BlockId; // set ID
        *pu32Crc = CalculateCRC32_Table( buff, (u8BlockSize + u8IdSize), NVMS_CRCINIT ); // set CRC

        if( E_OK != FLASH_RWriteSync( &buff[0], NVMS_BLOCK_MAXSIZE, u32Addr ))
        {
            return E_NOT_OK;
        }

        // verify writing
        if( E_OK != NVMS_ReadBlockSync( BlockId, buff ))
        {
            return E_NOT_OK;
        }
        if( 0 != TS_MemCmp( &buff[0], &SrcPtr[0], u8BlockSize ))
        {
            return E_NOT_OK;
        }
    }
    return E_OK;
}

static FUNC(Std_ReturnType, BL_CODE) FindEmptyFlashAddr( uint32* pu32Addr )
{
    uint8  u8IsValid;
    uint8  *pu8Ptr;
    uint32 u32AddrMin;
    uint32 u32AddrMax;
//  uint16 u16SwitchCmd;

    if( pu32Addr != NULL_PTR )
    {
        u8IsValid = FindActNVMsFlsSec();
        switch( u8IsValid )
        {
            case NVMS_FLS_SEC_01_VALID:
                *pu32Addr = NVMS_FLS_SEC_01_ADDR;
//              u16SwitchCmd = NVMS_SWITCH_TO_FLS_SEC_02;
                break;

            case NVMS_FLS_SEC_02_VALID:
                *pu32Addr = NVMS_FLS_SEC_02_ADDR;
//              u16SwitchCmd = NVMS_SWITCH_TO_FLS_SEC_01;
                break;

            default:
                return E_NOT_OK;
        }

        u32AddrMin = *pu32Addr + (2*NVMS_BLOCK_MAXSIZE);

        *pu32Addr += (NVMS_FLS_SEC_SIZE - NVMS_BLOCK_MAXSIZE);

        u32AddrMax =  *pu32Addr;

        for( ; *pu32Addr >= u32AddrMin; *pu32Addr -= NVMS_BLOCK_MAXSIZE )
        {
            pu8Ptr = (uint8*)(*pu32Addr);

            if(( pu8Ptr[0] != 0xFFu ) || ( pu8Ptr[1] != 0xFFu ) || ( pu8Ptr[2] != 0xFFu )) // we hope invalid flag is FFs, i.e. not written
            {
                break;
            }
        }

        if(*pu32Addr == u32AddrMax)
        {
            return E_NOT_OK;
/*
            if(SwitchNVMsFlsSec(u16SwitchCmd, 1, 1, pu32Addr) != E_OK)
            {
                return E_NOT_OK;
            }
*/
            }
        else
        {
            *pu32Addr += NVMS_BLOCK_MAXSIZE;
        }
    }
    else
    {
        return E_NOT_OK;
    }

    return E_OK;
}

static FUNC(Std_ReturnType, BL_CODE) FindBlockId( const uint16 BlockId, uint32* pu32Addr )
{
    uint8  u8IsValid;
    uint32 u32AddrMin;
    uint32 u32Crc;
    uint32 *pu32CrcPtr;

    if( pu32Addr != NULL_PTR )
    {
        u8IsValid = FindActNVMsFlsSec();
        switch( u8IsValid )
        {
            case NVMS_FLS_SEC_01_VALID:
            {
                *pu32Addr = NVMS_FLS_SEC_01_ADDR;
                break;
            }
            case NVMS_FLS_SEC_02_VALID:
            {
                *pu32Addr = NVMS_FLS_SEC_02_ADDR;
                break;
            }
            default:
                return E_NOT_OK;
        }

        u32AddrMin = *pu32Addr + (2* NVMS_BLOCK_MAXSIZE); //Pointer to the first block after the valid/invalid flag blocks

        *pu32Addr += (NVMS_FLS_SEC_SIZE - NVMS_BLOCK_MAXSIZE);

        for( ; *pu32Addr >= u32AddrMin; *pu32Addr -= NVMS_BLOCK_MAXSIZE )
        {
            if( *(uint16*)(*pu32Addr) == BlockId )
            {
                const uint8 *pu8DefVal;
                uint8 u8BlockSize = 0;
                uint8 u8IdSize = 0;

                NVMS_FindDefVal( BlockId, &u8BlockSize, &u8IdSize, &pu8DefVal );
                u32Crc = CalculateCRC32_Table( (uint8*)(*pu32Addr), (u8BlockSize + u8IdSize), NVMS_CRCINIT );
                pu32CrcPtr = (uint32 *)(*pu32Addr + u8IdSize + u8BlockSize);
                if( *pu32CrcPtr == u32Crc )
                {
                    return E_OK;
                }
                // else search for previous valid
            }
        }
    }
    else
    {
        return E_NOT_OK;
    }

    return E_NOT_OK;
}

static FUNC(uint8, BL_CODE) FindActNVMsFlsSec( void )
{
    uint8  u8NVMsFlsSecSts;
//  uint32 u32Addr;

    u8NVMsFlsSecSts = CheckNVMsFlsSecSts();

    switch( u8NVMsFlsSecSts )
    {
        case NVMS_FLS_SEC_01_VALID:
        case NVMS_FLS_SEC_02_VALID:
        {
            break;
        }
        case NVMS_FLS_SEC_01_AND_SEC_02_ERASED:
        {
/*
            EraseNVMsFlsSec(NVMS_FLS_SEC_01_ADDR, NVMS_FLS_SEC_SIZE);
            EraseNVMsFlsSec(NVMS_FLS_SEC_02_ADDR, NVMS_FLS_SEC_SIZE);

            u32Addr = NVMS_FLS_SEC_01_ADDR;
            FLASH_RWriteSync(&u8Validity[0], NVMS_BLOCK_MAXSIZE, u32Addr);

            u8NVMsFlsSecSts = NVMS_FLS_SEC_01_VALID;
*/
            break;
        }
        case NVMS_FLS_SEC_01_AND_SEC_02_INVALID:
        case NVMS_FLS_SEC_01_ERASED_AND_SEC_02_INVALID:
        {
            /*restore data from 2nd sector */
/*
            if(SwitchNVMsFlsSec(NVMS_SWITCH_TO_FLS_SEC_01, 0, 1, NULL_PTR) != E_OK)
            {
                break;
            }

            u8NVMsFlsSecSts = NVMS_FLS_SEC_01_VALID;
*/
            break;
        }
        case NVMS_FLS_SEC_01_INVALID_AND_SEC_02_ERASED:
        {
            /*restore data from 1st sector */
/*
            if(SwitchNVMsFlsSec(NVMS_SWITCH_TO_FLS_SEC_02, 0, 1, NULL_PTR) != E_OK)
            {
                break;
            }

            u8NVMsFlsSecSts = NVMS_FLS_SEC_02_VALID;
*/
            break;
        }
        default:
            break;
    }

    return u8NVMsFlsSecSts;
}

static FUNC(uint8, BL_CODE) CheckNVMsFlsSecSts( void )
{
    uint8 u8IsValid = 0x00u;
    uint32 u32AddrMin;

    // search for valid block
    u32AddrMin = NVMS_FLS_SEC_01_ADDR;

    if( 0 == TS_MemCmp( (uint8 *)u32AddrMin, &u8Validity[0], NVMS_BLOCK_MAXSIZE )) // check if valid flag ia set
    {
        if( 0 == TS_MemCmp( (uint8 *)(u32AddrMin + NVMS_BLOCK_MAXSIZE), &u8Empty[0], NVMS_BLOCK_MAXSIZE )) // check if invalid flag is set
        {
            u8IsValid = NVMS_FLS_SEC_01_VALID;      /* 1st NVMS sector is valid */
        }
        else
        {
            u8IsValid = NVMS_FLS_SEC_01_INVALID;    /* 1st NVMS sector is invalid */
        }
    }
    else
    {
        u8IsValid = NVMS_FLS_SEC_01_ERASED;         /* 1st NVMS sector is erased */
    }

    if(( u8IsValid == NVMS_FLS_SEC_01_INVALID ) || ( u8IsValid == NVMS_FLS_SEC_01_ERASED ))
    {
        u32AddrMin = NVMS_FLS_SEC_02_ADDR;

        if( 0 == TS_MemCmp( (uint8 *)u32AddrMin, &u8Validity[0], NVMS_BLOCK_MAXSIZE )) // valid flag
        {
            if( 0 == TS_MemCmp( (uint8 *)(u32AddrMin + NVMS_BLOCK_MAXSIZE), &u8Empty[0], NVMS_BLOCK_MAXSIZE )) // check if invalid flag is set
            {
                u8IsValid = NVMS_FLS_SEC_02_VALID;      /* 2nd NVMS sector is valid */
            }
            else
            {
                if(u8IsValid == NVMS_FLS_SEC_01_INVALID )
                {
                    u8IsValid = NVMS_FLS_SEC_01_AND_SEC_02_INVALID;  /* 1st and 2nd NVMS sectors are invalid */
                }
                else
                {
                    u8IsValid = NVMS_FLS_SEC_01_ERASED_AND_SEC_02_INVALID; /* 2st NVMS sector is invalid and 1st NVMS sector is erased*/
                }
            }
        }
        else
        {
            if( u8IsValid == NVMS_FLS_SEC_01_INVALID )
            {
                u8IsValid = NVMS_FLS_SEC_01_INVALID_AND_SEC_02_ERASED;  /* 1st NVMS sector is invalid and 2nd NVMS sector is erased*/
            }
            else
            {
                u8IsValid = NVMS_FLS_SEC_01_AND_SEC_02_ERASED; /* 1st and 2nd NVMS sectors are erased */
            }
        }
    }

    return u8IsValid;
}



/*==================[end of file]============================================*/
