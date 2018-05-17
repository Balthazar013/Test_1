/**
* @brief General Purpose Timer, to be used by other components for the timeout calculations
*
* @copyright Copyright (c) 2015-2017 Bombardier Transportation. All rights reserved.
*
* @file $RCSfile$
* @author $Author: Muhammad$
* @date $Date: 21.02.2018$
* @version $Revision: 1.2$
*/

#ifndef _SWGPT_H_
#define _SWGPT_H_
#include <Std_Types.h>

//---------------------------------------------------------------------------------------------------------------------
// MAKRO DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------
#define MAX_CHANNEL_ID (uint8)10

//---------------------------------------------------------------------------------------------------------------------
// TYPE DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

typedef uint32 SwGPT_ChannelID;

// Function Pointer
typedef void (*SwGPTFnPtr) (void);

//---------------------------------------------------------------------------------------------------------------------
// FUNCTION DECLARATIONS
//---------------------------------------------------------------------------------------------------------------------

/// @brief Function to Register the Software GPT for a specific channel
/// @param [in] pfCbkTimeout Function to be called after the timeout occured.
/// @param [in] ulTimeout Timeout period (in ms) after that a notification shall occur.
/// @param [out] ptrSwGPTCh Pointer to the SwGPT_ChannelInstance.
Std_ReturnType SwGPT_Register (SwGPTFnPtr pfCbkTimeout, uint32 ulTimeout, SwGPT_ChannelID* ptrSwGPTCh ); // ptr_enum will update the channel assigned at the registration of the GPT

/// @brief Function to Deregister the Software GPT for a specific channel
/// @param [in] eSwGPTCh Number of channel to be deregistered.
Std_ReturnType SwGPT_Deregister (SwGPT_ChannelID eSwGPTCh);

/// @brief Function to start the Software GPT for a specific channel
/// @param [in] eSwGPTCh ID of the Channel for which the timer is to be activated 
Std_ReturnType SwGPT_Start (SwGPT_ChannelID eSwGPTCh);

/// @brief Function to stop the Software GPT for a specific channel
/// @param [in] eSwGPTCh ID of the Channel for which the timer is to be deactivated 
Std_ReturnType SwGPT_Stop (SwGPT_ChannelID eSwGPTCh);

Std_ReturnType SwGPT_SetTimeout(SwGPT_ChannelID eSwGPTCh, uint32 ulTimeout);
/// @brief Initialization function for the SwGPT 
void SwGpt_Init(void);

#endif
