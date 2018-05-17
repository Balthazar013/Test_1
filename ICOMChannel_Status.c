/**
* @brief ICOM Status Channel to provide/collect the status data from RTE to/from ICOM Service
*
* @copyright Copyright (c) 2015-2017 Bombardier Transportation. All rights reserved.
*
* @file $RCSfile$
* @author $Author$
* @date $Date$
* @version $Revision$
*/

#include <Std_Types.h>
#include <stddef.h>
#include <TSMem.h>
#include <Crc.h>
#include "ICOM.h"
#include "Rte_SCI_BleDrv.h"
#include "ICOMChannel_Status.h"

//---------------------------------------------------------------------------------------------------------------------
// MAKRO DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

#define STATUS_CHANNEL_PRIORITY                         1
#define ICOM_CRC_16_STARTVALUE                          (uint16)0x0000

//---------------------------------------------------------------------------------------------------------------------
// TYPE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

#pragma pack(1) //For packing of the structure (compiler specific)
typedef struct
{
  //Little endian
  boolean     FODIsDetected       : 1;
  boolean     FodError            : 1;
  boolean     FodDly              : 1;
  boolean     zMoverError         : 1;
  boolean     zMoverInChrgPos     : 1;
  boolean     zMoverIsActive      : 1;
  boolean     zMoverIsDown        : 1;
  boolean     zMoverIsUp          : 1;
  boolean     TempDly             : 1;
  boolean     ChrgInhibited       : 1;
  uint16      ChrgMaxPower        :16;
  uint32      TimestampWS         :32;
  sint16      PosT                :13;
  sint32      PosY                :17;
  sint32      PosX                :17;
  uint8       WsSftyState         : 8;
  uint8       WsState             : 8;
  uint16      CRCPad              :16;
}ICOM_ChStsPad;
#pragma pack()

#pragma pack(1)
typedef struct
{
  //Little endian
  uint32      TimestampORU            :32;
  sint16      PosTrjOfflPosT          :13;
  sint32      PosTrjOfflPosY          :17;
  sint32      PosTrjOfflPosX          :17;
  sint32      PosTrjStrAng            :20;
  sint32      PosTrjDrivingDistance   :17;
  sint16      PosTrjSpeed             :16;
  uint8       OruSftyState            : 8;
  uint8       CmdWsStateMachine       : 8;
  uint16      U_DC_MAX                :16;
  uint16      I_DC_ACT                :16;
  uint16      U_AC_ACT                :16;
  uint16      U_DC_ACT                :16;
  uint16      I_DC_REQ                :16;
  uint16      CRCOru                  :16;
} ICOM_ChStsOru;
#pragma pack()

typedef struct
{
  ICOM_uStsFrameHeader   ChStsOutHdr;
  ICOM_ChStsPad         *pChStsOut;
  ICOM_uStsFrameHeader   ChStsInHdr;
  ICOM_ChStsOru         *pChStsIn;
} ICOM_ChSts;


#define ICOM_CH_STS_PAD_SIZE      sizeof(ICOM_ChStsPad)
#define ICOM_CH_STS_ORU_SIZE      sizeof(ICOM_ChStsOru)

#define DEBUG_ICOM_CH_STS
#ifdef  DEBUG_ICOM_CH_STS
typedef union
{
  uint8 uArray[ICOM_CH_STS_ORU_SIZE];
  ICOM_ChStsOru st;
}ICOM_UChStsIn;

typedef union
{
  uint8 uArray[ICOM_CH_STS_PAD_SIZE];
  ICOM_ChStsPad st;
}ICOM_UChStsOut;
    
ICOM_UChStsOut uChStsOut;
ICOM_UChStsIn  uChStsIn;
#endif


//----------------------------------------------------------------------------
// VARIABLE DECLARATIONS
//----------------------------------------------------------------------------

ICOM_ChSts  ICOMSrvSts_instance;
static ICOM_CH  ICOM_Channel_Status;
uint16 temp = 0;
boolean test = 0;

// @@ SYMBOL = BLE_DataRoundTripCounter
// @@ A2L_TYPE = PARAMETER
// @@ DATA_TYPE = UBYTE
// @@ END
static uint8 BLE_DataRoundTripCounter = 0;

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType ICOM_updateData (const uint8 *databeginptr, const uint8 *dataendptr, uint8 **pDataUpdate);
static Std_ReturnType ICOM_collectData(const uint8 *databeginptr, const uint8 *dataendptr, uint8 **pDataCollect);

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DEFINITIONS
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType ICOMChannelStatus_Init(ICOM_INST *pICOM_Instance)
{
  ICOM_Channel_Status.uFrameType = FRAME_TYPE_STATUS;
  ICOM_Channel_Status.uPriority  = STATUS_CHANNEL_PRIORITY;
  ICOM_Channel_Status.fpUpdate   = &ICOM_updateData;
  ICOM_Channel_Status.fpCollect  = &ICOM_collectData;
  
  ICOMSrvSts_instance.ChStsOutHdr.stStsFrmHdr.FRAME_TYPE = FRAME_TYPE_STATUS;
  ICOMSrvSts_instance.ChStsOutHdr.stStsFrmHdr.FRAME_SEQ = 0;
  ICOMSrvSts_instance.ChStsOutHdr.stStsFrmHdr.FRAME_LENGTH = (uint8)(ICOM_CH_STS_PAD_SIZE + ICOM_FRAME_HDR_SIZE);
  
  if (ICOM_openChannel (pICOM_Instance, &ICOM_Channel_Status) == E_OK)
  {
    return E_OK;
  }
  return E_NOT_OK;
  
}

static Std_ReturnType ICOM_updateData(const uint8 *databeginptr, const uint8 *dataendptr, uint8 **pDataUpdate)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 *pSOF           = NULL_PTR;
  ICOM_uStsFrameHeader * pICOM_uStatusFrameHeader;
  ptrdiff_t allowed_length = dataendptr - databeginptr;
  
  if (allowed_length >= (ICOM_CH_STS_ORU_SIZE + ICOM_FRAME_HDR_SIZE))
  {
    pSOF = (uint8 *)databeginptr;
    
    pICOM_uStatusFrameHeader     = (ICOM_uStsFrameHeader*)pSOF;
    
    ICOMSrvSts_instance.ChStsInHdr.stStsFrmHdr.FRAME_TYPE   = pICOM_uStatusFrameHeader->stStsFrmHdr.FRAME_TYPE;
    ICOMSrvSts_instance.ChStsInHdr.stStsFrmHdr.FRAME_SEQ    = pICOM_uStatusFrameHeader->stStsFrmHdr.FRAME_SEQ;
    ICOMSrvSts_instance.ChStsInHdr.stStsFrmHdr.FRAME_LENGTH = pICOM_uStatusFrameHeader->stStsFrmHdr.FRAME_LENGTH;
    
    pSOF  += ICOM_FRAME_HDR_SIZE;
    ICOMSrvSts_instance.pChStsIn = (ICOM_ChStsOru *)pSOF;
    temp = Crc_CalculateCRC16(databeginptr, (ICOM_CH_STS_ORU_SIZE + ICOM_FRAME_HDR_SIZE - 2U), ICOM_CRC_16_STARTVALUE, TRUE);
    if (ICOMSrvSts_instance.pChStsIn->CRCOru == temp)
    {
      test = 0x1;
    }
    else
    {
      test = 0x0;
    }
    
    Rte_IWrite_BleCom_MainFunction_PP_IDcReqOru_Current(ICOMSrvSts_instance.pChStsIn->I_DC_REQ);
    Rte_IWrite_BleCom_MainFunction_PP_UDcActOru_Voltage((ICOMSrvSts_instance.pChStsIn->U_DC_ACT*10));  /* Hundreds to milliVolt conversion */
    Rte_IWrite_BleCom_MainFunction_PP_UAcActOru_Voltage((ICOMSrvSts_instance.pChStsIn->U_AC_ACT*10));
    Rte_IWrite_BleCom_MainFunction_PP_IDcActOru_Current(ICOMSrvSts_instance.pChStsIn->I_DC_ACT);
    Rte_IWrite_BleCom_MainFunction_PP_UDcMaxOru_Voltage((ICOMSrvSts_instance.pChStsIn->U_DC_MAX*10));
    Rte_IWrite_BleCom_MainFunction_PP_WsCmdStateMachine_SCI_BleDrv_GenericByteValue(ICOMSrvSts_instance.pChStsIn->CmdWsStateMachine);
    Rte_IWrite_BleCom_MainFunction_PP_OruSftyMgrState_SCI_BleDrv_GenericByteValue(ICOMSrvSts_instance.pChStsIn->OruSftyState);
    Rte_IWrite_BleCom_MainFunction_WspBleCdd_recPosOfflTrj_DrivingDistance(ICOMSrvSts_instance.pChStsIn->PosTrjDrivingDistance);
    Rte_IWrite_BleCom_MainFunction_WspBleCdd_recPosOfflTrj_SteeringWheelAngle(ICOMSrvSts_instance.pChStsIn->PosTrjStrAng/10000);
    Rte_IWrite_BleCom_MainFunction_WspBleCdd_recPosOfflTrj_Speed(ICOMSrvSts_instance.pChStsIn->PosTrjSpeed);
    Rte_IWrite_BleCom_MainFunction_WspBleCdd_recPosOfflTrj_Theta(ICOMSrvSts_instance.pChStsIn->PosTrjOfflPosT);
    Rte_IWrite_BleCom_MainFunction_WspBleCdd_recPosOfflTrj_X(ICOMSrvSts_instance.pChStsIn->PosTrjOfflPosX);
    Rte_IWrite_BleCom_MainFunction_WspBleCdd_recPosOfflTrj_Y(ICOMSrvSts_instance.pChStsIn->PosTrjOfflPosY);
    Rte_IWrite_BleCom_MainFunction_WspBleCdd_recPosOfflTrj_Timestamp(ICOMSrvSts_instance.pChStsIn->TimestampORU);
    
    *pDataUpdate = (uint8 *)(pSOF) + (uint8)ICOM_CH_STS_ORU_SIZE;
    
    BLE_DataRoundTripCounter++;
    
    #ifdef DEBUG_ICOM_CH_STS
    TS_MemCpy(&uChStsIn.uArray[0], pSOF, ICOM_CH_STS_ORU_SIZE);
    #endif
    
    retVal = E_OK;
  }
  return retVal;
}

static Std_ReturnType ICOM_collectData(const uint8 *databeginptr, const uint8 *dataendptr, uint8 **ppDataCollect)
{
  Std_ReturnType retVal = E_NOT_OK;
  ptrdiff_t allowed_length = dataendptr - databeginptr;
  
  if (allowed_length >= (ICOM_CH_STS_PAD_SIZE + ICOM_FRAME_HDR_SIZE))
  {
    boolean isChrgInhibited;
    boolean tempdelay;
    uint8 *pCurrentData   = NULL_PTR;
    ICOM_uStsFrameHeader * pICOM_uStatusFrameHeader;
    
    pCurrentData              = (uint8 *)databeginptr;
    pICOM_uStatusFrameHeader  = (ICOM_uStsFrameHeader *) pCurrentData;
    
    ICOMSrvSts_instance.ChStsOutHdr.stStsFrmHdr.FRAME_SEQ++;
    pICOM_uStatusFrameHeader->stStsFrmHdr.FRAME_TYPE    = ICOMSrvSts_instance.ChStsOutHdr.stStsFrmHdr.FRAME_TYPE;
    pICOM_uStatusFrameHeader->stStsFrmHdr.FRAME_SEQ     = ICOMSrvSts_instance.ChStsOutHdr.stStsFrmHdr.FRAME_SEQ;
    pICOM_uStatusFrameHeader->stStsFrmHdr.FRAME_LENGTH  = ICOMSrvSts_instance.ChStsOutHdr.stStsFrmHdr.FRAME_LENGTH;
    
    pCurrentData += ICOM_FRAME_HDR_SIZE;
    ICOMSrvSts_instance.pChStsOut = (ICOM_ChStsPad *)pCurrentData;
    
    Rte_Call_FI_FID_InhChrg_GetFunctionPermission(&isChrgInhibited);
    Rte_Call_FI_FID_TempDly_GetFunctionPermission(&tempdelay);
    
    ICOMSrvSts_instance.pChStsOut->WsState            = Rte_IRead_BleCom_MainFunction_RP_WSState_SCI_BleDrv_ActStateWsValue();
    ICOMSrvSts_instance.pChStsOut->WsSftyState        = Rte_IRead_BleCom_MainFunction_RP_WsSftyMgrState_SCI_BleDrv_GenericByteValue();
    ICOMSrvSts_instance.pChStsOut->PosX               = Rte_IRead_BleCom_MainFunction_WspPosMgr_posActual_X();
    ICOMSrvSts_instance.pChStsOut->PosY               = Rte_IRead_BleCom_MainFunction_WspPosMgr_posActual_Y();
    ICOMSrvSts_instance.pChStsOut->PosT               = Rte_IRead_BleCom_MainFunction_WspPosMgr_posActual_Theta();
    ICOMSrvSts_instance.pChStsOut->TimestampWS        = Rte_IRead_BleCom_MainFunction_WspPosMgr_posActual_Timestamp();
    ICOMSrvSts_instance.pChStsOut->ChrgMaxPower       = Rte_IRead_BleCom_MainFunction_RP_MaxPossiblePower_PowerValue();
    ICOMSrvSts_instance.pChStsOut->ChrgInhibited      = !isChrgInhibited;
    ICOMSrvSts_instance.pChStsOut->zMoverIsUp         = Rte_IRead_BleCom_MainFunction_RP_ZMoverIsUp_BoolVal();
    ICOMSrvSts_instance.pChStsOut->zMoverIsDown       = Rte_IRead_BleCom_MainFunction_RP_ZMoverIsDown_BoolVal();
    ICOMSrvSts_instance.pChStsOut->zMoverIsActive     = Rte_IRead_BleCom_MainFunction_RP_ZMoverActive_Value();
    ICOMSrvSts_instance.pChStsOut->zMoverInChrgPos    = Rte_IRead_BleCom_MainFunction_PP_ZMovrIsChargPos_Value();
    ICOMSrvSts_instance.pChStsOut->FodError           = Rte_IRead_BleCom_MainFunction_RP_Fehler_FOD_Value();
    ICOMSrvSts_instance.pChStsOut->FodDly             = Rte_IRead_BleCom_MainFunction_RP_Verz_FOD_Value();
    ICOMSrvSts_instance.pChStsOut->TempDly            = tempdelay;
    ICOMSrvSts_instance.pChStsOut->CRCPad             = Crc_CalculateCRC16(databeginptr, (ICOM_CH_STS_PAD_SIZE + ICOM_FRAME_HDR_SIZE - 2U), ICOM_CRC_16_STARTVALUE, TRUE);
    
    #ifdef DEBUG_ICOM_CH_STS
    TS_MemCpy(&uChStsOut.uArray[0], pCurrentData, ICOM_CH_STS_PAD_SIZE);
    #endif
    
    *ppDataCollect = (uint8 *)(pCurrentData + ICOM_CH_STS_PAD_SIZE);
    
     retVal = E_OK;
  }
  else
  {
     *ppDataCollect = (uint8 *)databeginptr;
     retVal = E_OK;
  }
  return retVal;
}
