/**
* @brief 
*
* @copyright Copyright (c) 2015-2017 Bombardier Transportation. All rights reserved.
*
* @file $RCSfile$
* @author $Author$
* @date $Date$
* @version $Revision$
*/

#include <Std_Types.h>

#ifndef _ICOM_H_
#define _ICOM_H_


//---------------------------------------------------------------------------------------------------------------------
// MAKRO DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

#define ICOM_CH_MAX                   4
#define STS_CHANNEL_BUFFER_LENGTH     (uint8)35
#define CHANNEL_BUFFER_LENGTH         256
#define MAX_BUFFER_LENGTH             (uint16)(CHANNEL_BUFFER_LENGTH*ICOM_CH_MAX)
#define MAX_PAYLOAD_LENGTH            80

#define FRAME_TYPE_STATUS             (uint8)0x1 //or 00000001b
#define FRAME_TYPE_DIAG               (uint8)0x2
#define FRAME_TYPE_FLS                (uint8)0x4
#define FRAME_TYPE_REMOTE_ACCESS      (uint8)0x8


//---------------------------------------------------------------------------------------------------------------------
// TYPE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

/* Function Pointer */
typedef Std_ReturnType (*ICOMChUpdFnPtr)  (uint8*, uint8*, uint8**);
typedef Std_ReturnType (*ICOMChCollFnPtr) (uint8*, uint8*, uint8**);

typedef struct
{
  uint8           uFrameType;
  uint8           uPriority;
  ICOMChUpdFnPtr  fpUpdate;
  ICOMChCollFnPtr fpCollect;
} ICOM_CH;

typedef struct 
{
  ICOM_CH*      pICOM_CH;                         //pointer to the ICOM_CH_INFO_list
  uint8        *pCollectBuffer;                   //pointer to the CollectBuffer
}ICOM_CH_INFO;

typedef struct 
{
  ICOM_CH_INFO  ICOM_CH_INFO_list[ICOM_CH_MAX];   //channel info list containing pointer to channel instance and the related collect buffer
  uint8         first_free_idx;                   // first free index to point to the channel info list
  uint8         CollectBuffer[MAX_BUFFER_LENGTH]; //Internal buffer to store the CollectData from ICOM_Channel (instance dependent)
  uint16        first_free_CollBuff_idx;          // first free index to point to the first available space in the CollectBuffer
} ICOM_INST;                                      //ICOM Instance

#pragma pack(1)
typedef struct
{
  uint8  FRAME_TYPE    :4;
  uint16 DUMMY         :12;
} ICOM_DummyFrameHeader;                            // Frame header for the payload
#pragma pack()

#define ICOM_FRAME_HDR_SIZE       sizeof(ICOM_DummyFrameHeader)

#pragma pack(1)
typedef struct
{
  uint8  FRAME_TYPE    :4;
  uint8  FRAME_SEQ     :4;
  uint8  FRAME_LENGTH  :8;
} ICOM_StsFrameHeader;                              // Frame header for the payload
#pragma pack()


typedef struct
{
  uint8  FRAME_TYPE    :4;
  uint8  FRAME_SEQ     :4;
  uint8  FRAME_LENGTH  :8;
} ICOM_DiagFrameHeader;                             // Frame header for the payload

// #pragma pack(1)
// typedef struct
// {
  // uint8  FRAME_TYPE    :4;
  // uint8  FRAME_SEQ     :6;
  // uint8  FRAME_LENGTH  :6;
// } ICOM_StreamFrameHeader;                           // Frame header for the payload
// #pragma pack()

// #pragma pack(1)
// typedef struct
// {
  // uint8  FRAME_TYPE    :4;
  // uint8  FRAME_SEQ     :6;
  // uint8  FRAME_LENGTH  :6;
// } ICOM_RemoteAccFrameHeader;                        // Frame header for the payload
// #pragma pack()

#pragma pack(1)
typedef union
{
  uint16                      Hdr;
  ICOM_DummyFrameHeader       st;
} ICOM_uDummyFrameHeader;                                //Union in order to access each entry in the ICOM_FrameHeader directly
#pragma pack()

#pragma pack(1)
typedef union
{
  uint16                      Hdr;
  ICOM_StsFrameHeader         stStsFrmHdr;
} ICOM_uStsFrameHeader;                                //Union in order to access each entry in the ICOM_FrameHeader directly
#pragma pack()

#pragma pack(1)
typedef union
{
  uint8                     Hdr[2];
  ICOM_DiagFrameHeader      stDiagFrmHdr;
} ICOM_uDiagFrameHeader;                                //Union in order to access each entry in the ICOM_FrameHeader directly
#pragma pack()

//---------------------------------------------------------------------------------------------------------------------
// VARIABLE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

/// @brief Function to create a new instance in the ICOM
/// @param [out] Returns the pointer to the newly created instance
ICOM_INST* ICOM_Create(void);

/// @brief Function to open a new communication channel in the ICOM
/// @param [in] ICOMSrv_Instance Pointer to the ICOM Instance
/// @param [in] ICOM_Channel Pointer to the ICOM Channel
Std_ReturnType ICOM_openChannel(ICOM_INST *ICOMSrv_Instance, ICOM_CH *ICOM_Channel);

/// @brief Function to close a specific communication channel existing in the ICOM
/// @param [in] ICOMSrv_Instance Pointer to the ICOM Instance
/// @param [in] ICOM_Channel Pointer to the ICOM Channel
Std_ReturnType ICOM_closeChannel(ICOM_INST *ICOMSrv_Instance, ICOM_CH *ICOM_Channel);

/// @brief Function for the collection of new data received from the DataLinkManager & providing it to the respective communication channels
/// @param [in] ICOMSrv_Instance Pointer to the ICOM Instance
/// @param [in] databeginpointer Pointer to the start of the buffer from which the data is supposed to be collected
/// @param [in] dataendpointer Pointer to the end of the buffer from which the data is supposed to be collected
Std_ReturnType ICOM_onReceivedFrame(ICOM_INST *ICOMSrv_Instance, const uint8 *databeginpointer, const uint8 *dataendpointer);

/// @brief Function for the collection of new data from the communication channels & providing it to the DataLinkManager
/// @param [in] ICOMSrv_Instance Pointer to the ICOM Instance
/// @param [in] databeginpointer Pointer to the start of the buffer to which the data is to be copied to
/// @param [in] Length The length of the data requested from the ICOM by the Function caller
/// @param [in] WrittenLength Pointer to the length variable which contains the length of the data actually copied by the ICOM to the buffer of the function caller
Std_ReturnType ICOM_onCollectFrame(ICOM_INST *ICOMSrv_Instance, const uint8 *databeginpointer, const uint8 Length, uint8* WrittenLength);

#endif