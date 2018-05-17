#include "Can.h"
#if defined(V_OSTYPE_OSEK)
# include "osek.h"
#endif
/* CAN034 */
#if defined(V_OSTYPE_AUTOSAR)
# include "Os.h"
#endif

/***************************************************************************/
/* Interrupt Service Routine                                               */
/***************************************************************************/
#define CAN_START_SEC_CODE  /*-----------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* CAN033 (P), CAN035, CAN420 */
#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define CanPhysToLogChannel_0
# define CanPhysToLogChannelIndex_0
# define CanPhysToLogChannel_1
# define CanPhysToLogChannelIndex_1
# define CanPhysToLogChannel_2
# define CanPhysToLogChannelIndex_2
# define CanPhysToLogChannel_3
# define CanPhysToLogChannelIndex_3
# define CanPhysToLogChannel_4
# define CanPhysToLogChannelIndex_4
# define CanPhysToLogChannel_5
# define CanPhysToLogChannelIndex_5
# define CanPhysToLogChannel_6
# define CanPhysToLogChannelIndex_6
# define CanPhysToLogChannel_7
# define CanPhysToLogChannelIndex_7
#else
# define CanPhysToLogChannel_0       kCanPhysToLogChannelIndex_0
# define CanPhysToLogChannelIndex_0  kCanPhysToLogChannelIndex_0,
# define CanPhysToLogChannel_1       kCanPhysToLogChannelIndex_1
# define CanPhysToLogChannelIndex_1  kCanPhysToLogChannelIndex_1,
# define CanPhysToLogChannel_2       kCanPhysToLogChannelIndex_2
# define CanPhysToLogChannelIndex_2  kCanPhysToLogChannelIndex_2,
# define CanPhysToLogChannel_3       kCanPhysToLogChannelIndex_3
# define CanPhysToLogChannelIndex_3  kCanPhysToLogChannelIndex_3,
# define CanPhysToLogChannel_4       kCanPhysToLogChannelIndex_4
# define CanPhysToLogChannelIndex_4  kCanPhysToLogChannelIndex_4,
# define CanPhysToLogChannel_5       kCanPhysToLogChannelIndex_5
# define CanPhysToLogChannelIndex_5  kCanPhysToLogChannelIndex_5,
# define CanPhysToLogChannel_6       kCanPhysToLogChannelIndex_6
# define CanPhysToLogChannelIndex_6  kCanPhysToLogChannelIndex_6,
# define CanPhysToLogChannel_7       kCanPhysToLogChannelIndex_7
# define CanPhysToLogChannelIndex_7  kCanPhysToLogChannelIndex_7,
#endif

#if defined( kCanPhysToLogChannelIndex_0 )
# if defined( C_ENABLE_CAN_RXTX_INTERRUPT )
/****************************************************************************
| NAME:             CanMailboxIsr_0_00_03
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_00_03 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_00_03( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_0_04_07
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_04_07 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_04_07( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_0_08_11
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_08_11 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_08_11( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_0_12_15
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_12_15 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_12_15( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_0_16_31
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_16_31 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_16_31( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_0_32_39
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_32_39 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_32_39( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_0_40_47
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_40_47 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_40_47( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_0_48_55
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_48_55 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_48_55( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_0_56_63
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_0_56_63 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_0_56_63( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(0)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_0); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

# endif /* C_ENABLE_CAN_RXTX_INTERRUPT */
#endif /* (kCanPhysToLogChannelIndex_0) */

/* **************************************************************************
	 *************************************************************************/
#if defined( kCanPhysToLogChannelIndex_1 )
# if defined( C_ENABLE_CAN_RXTX_INTERRUPT )
/****************************************************************************
| NAME:             CanMailboxIsr_1_00_03
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_00_03 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_00_03( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_1_04_07
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_04_07 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_04_07( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_1_08_11
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_08_11 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_08_11( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_1_12_15
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_12_15 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_12_15( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_1_16_31
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_16_31 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_16_31( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_1_32_39
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_32_39 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_32_39( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_1_40_47
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_40_47 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_40_47( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_1_48_55
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_48_55 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_48_55( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

/****************************************************************************
| NAME:             CanMailboxIsr_1_56_63
| CALLED BY:        FlexCAN mailbox interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service function for communication mailboxes
****************************************************************************/
/* CODE CATEGORY 1 START */
#  if defined( C_ENABLE_OSEK_OS ) && defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanMailboxIsr_1_56_63 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
void CanMailboxIsr_1_56_63( void )
#  endif /* C_ENABLE_OSEK_OS */
{
#  if defined( CAN_USE_PHYSTOLOG_MAPPING )
  CanMailboxInterrupt(Can_GetPhysToLogChannel(1)); /* call Interrupthandling with identity dependend logical channel */
#  else
  CanMailboxInterrupt(CanPhysToLogChannel_1); /* call Interrupthandling with logical channel */
#  endif
} /* END OF CanMailboxIsr */
/* CODE CATEGORY 1 END */

# endif /* C_ENABLE_CAN_RXTX_INTERRUPT */
#endif /* (kCanPhysToLogChannelIndex_1) */

/* **************************************************************************
	 *************************************************************************/
