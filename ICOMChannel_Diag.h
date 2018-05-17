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

#ifndef _ICOMCHannel_Diag_H_
#define _ICOMCHannel_Diag_H_

//---------------------------------------------------------------------------------------------------------------------
// MAKRO DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// TYPE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

typedef enum
{
  CHANNEL_IDLE = 0,
  INCORRECT_LENGTH,
  CHANNEL_BUSY,
  WRITE_SUCCESS,
  READ_SUCCESS,
} DiagChRsp_t;

//---------------------------------------------------------------------------------------------------------------------
// VARIABLE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

DiagChRsp_t ICOMDiagCh_SendCmd( uint8 *pData, uint16 Length );

DiagChRsp_t ICOMDiagCh_GetRsp( uint8 *pData, uint16* pLength );

Std_ReturnType ICOMDiagCh_CancelCmd(void);

boolean ICOMDiagCh_CheckBusyFlag(void);

#endif