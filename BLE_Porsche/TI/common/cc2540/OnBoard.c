/**************************************************************************************************
  Filename:       OnBoard.c
  Revised:        $Date: 2017-11-14 12:44:56 +0100 (Di, 14 Nov 2017) $
  Revision:       $Revision: 16315 $

  Description:    This file contains the UI and control for the
                  peripherals on the EVAL development board
  Notes:          This file targets the Chipcon CC2430DB/CC2430EB


  Copyright 2005-2013 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
**************************************************************************************************/

/*********************************************************************
 * INCLUDES
 */
#include "bcomdef.h"
#include "OnBoard.h"
#include "OSAL.h"
//#include "hal_led.h"
//#include "hal_key.h"


/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */

// Task ID not initialized
#define NO_TASK_ID 0xFF


/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */
uint8 OnboardKeyIntEnable;


/*********************************************************************
 * EXTERNAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL FUNCTIONS
 */
extern uint8 LL_PseudoRand( uint8 *randData, uint8 dataLen );

#if   defined FEATURE_ABL
#include "..\..\util\ABL\app\sbl_app.c"
#elif defined FEATURE_SBL
#include "..\..\util\SBL\app\sbl_app.c"
#elif defined FEATURE_EBL
#include "..\..\util\EBL\app\sbl_app.c"
#elif defined FEATURE_UBL_MSD
#include "..\..\util\UBL\soc_8051\usb_msd\app\ubl_app.c"
#else
void appForceBoot(void);
#endif

/*********************************************************************
 * LOCAL VARIABLES
 */

// Registered keys task ID, initialized to NOT USED.
//static uint8 registeredKeysTaskID = NO_TASK_ID;

/*********************************************************************
 * @fn      InitBoard()
 * @brief   Initialize the CC2540DB Board Peripherals
 * @param   level: COLD,WARM,READY
 * @return  None
 */
void InitBoard( uint8 level )
{
  if ( level == OB_COLD )
  {
    // Interrupts off
    osal_int_disable( INTS_ALL );
    // Turn all LEDs off
   // HalLedSet( HAL_LED_ALL, HAL_LED_MODE_OFF );
    // Check for Brown-Out reset
//    ChkReset();
  }
  else  // !OB_COLD
  {
    /* Initialize Key stuff */
   // OnboardKeyIntEnable = HAL_KEY_INTERRUPT_ENABLE;
   // HalKeyConfig( OnboardKeyIntEnable, OnBoard_KeyCallback);
  }
}

/*********************************************************************
 * @fn        Onboard_rand
 *
 * @brief    Random number generator
 *
 * @param   none
 *
 * @return  uint16 - new random number
 *
 *********************************************************************/
uint16 Onboard_rand( void )
{
  uint16 randNum;

  LL_PseudoRand( (uint8 *)&randNum, 2 );

  return ( randNum );
}

/*********************************************************************
 * @fn      _itoa
 *
 * @brief   convert a 16bit number to ASCII
 *
 * @param   num -
 *          buf -
 *          radix -
 *
 * @return  void
 *
 *********************************************************************/
void _itoa(uint16 num, uint8 *buf, uint8 radix)
{
  char c,i;
  uint8 *p, rst[5];

  p = rst;
  for ( i=0; i<5; i++,p++ )
  {
    c = num % radix;  // Isolate a digit
    *p = c + (( c < 10 ) ? '0' : '7');  // Convert to Ascii
    num /= radix;
    if ( !num )
      break;
  }

  for ( c=0 ; c<=i; c++ )
    *buf++ = *p--;  // Reverse character order

  *buf = '\0';
}


/*********************************************************************
 * @fn      Onboard_soft_reset
 *
 * @brief   Effect a soft reset.
 *
 * @param   none
 *
 * @return  none
 *
 *********************************************************************/
__near_func void Onboard_soft_reset( void )
{
  HAL_DISABLE_INTERRUPTS();
  asm("LJMP 0x0");
}

#if   defined FEATURE_ABL
#elif defined FEATURE_SBL
#elif defined FEATURE_EBL
#elif defined FEATURE_UBL_MSD
#else
/*********************************************************************
 * @fn      appForceBoot
 *
 * @brief   Common force-boot function for the HCI library to invoke.
 *
 * @param   none
 *
 * @return  void
 *********************************************************************/
void appForceBoot(void)
{
  // Dummy function for HCI library that cannot depend on the SBL build defines.
}
#endif

/*********************************************************************
*********************************************************************/
