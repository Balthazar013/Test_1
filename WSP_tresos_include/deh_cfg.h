/*==============================================================================
                      Diagnostic Event Handler  (DEH)
                     ---------------------------------
                      Version 4.1.14
                      Author: Hauke Schmidtke / IAV GmbH
                      Date:   08.08.2014
                      Modul:  deh_cfg.h

Revison History:
----------------
Rev.                        Comments
------------------------------------------------------------------------------
------------------------------------------------------------------------------


V4.1.14  Change for DEH_GetVersionInfo()
         Bugfix for DEH_FFiF_ReadFF(), DEH_SetWarningIndicatorRequestedBit(), 
         DEH_ReadDTCExtDataRecord() and DEH_ESiF_WriteEM()
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.13  Bugfix for DEH_Init(), DEH_ESiF_TstLUCandClearEM(), 
         DEH_ESiF_UpdateEM(), DEH_ESiF_WriteEM(), DEH_StM_Memory() and
         DEH_SUiF_StatusOfDTC() and DEH_SUiF_ClearStatusOfDTCInfos()
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.12  Bugfix for DEH_Init(), DEH_FFiF_ReadFF(), DEH_FFiF_GetExtFF(),
         DEH_StM_Event_cyclic(), DEH_ESiF_WriteEM(), DEH_StM_Event() and
         DEH_ProcessDiagEventHandler()  
=======  =====================================================================
  1. SSWCCB-1708: new #define DEH_MAX_NUMBER_FFBUSYRESP
==============================================================================

V4.1.11  Bugfix for DEH_StM_Event() and DEH version number
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.10  Bugfix for DEH_StM_Event() and DEH_StM_Event_cyclic()
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.9   Bugfix for DEH_SUiF_ClearStatusOfDTCInfos()
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.8   Bugfix for DEH_Init(), DEH_SetDiagnosticSession(), 
         DEH_ESiF_WarnLampAndSrvBitUpd(), DEH_SUiF_ClearStatusOfDTCInfos()
         and DEH_ClearDiagnosticInformation()
         Change for DEH_Init(), DEH_StM_Event(), DEH_StM_Event_cyclic(),
         DEH_StM_Memory(), DEH_ClearEvent(), DEH_ESiF_UpdateEM(),
         DEH_SUiF_ClearStatusOfDTCInfos() and
         DEH_SetWarningIndicatorRequestedBit()
         New callback APL_DEH_ReportStatusOfDTCChanged()
=======  =====================================================================
  1. SSWCCB-1589: new #define DEH_SUP_DETECT_CHANGE_STATUSOFDTC
==============================================================================

V4.1.7   Bugfix for DEH_ClearDiagnosticInformation()
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.6   Bugfix for DEH_ESiF_InitEM()
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.5   Bugfix for DEH_ReadDTCExtDataRecord(),
         DEH_StM_Event_cyclic(), DEH_StoreStatusOfDTCInfos(), 
         DEH_ESiF_LookForPosToOvEM(), DEH_ESiF_InitEM(),
         DEH_ReadDTCSnapshotRecord(), DEH_ControlDTCSetting(),
         DEH_ClearDiagnosticInformation(), DEH_StM_Event(), 
         DEH_StM_Memory() and DEH_ESiF_InitEM()
=======  =====================================================================
  1. SSWCCB-1277: new compiler flag to enable/disable the protection of global 
         variables - DEH_PROTECT_GLOBAL_VARIABLES
==============================================================================

V4.1.4   Bugfix for pending bit support in DEH_ESiF_LookForPosToOvEM() and
         DEH_StM_Memory()
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.3     Bugfix for define STOFDTC_POS_STATUS_BYTE
=======  =====================================================================
  1. SSWCCB-925: Calculation of STOFDTC_POS_STATUS_BYTE corrected   
==============================================================================

V4.1.2   Bugfix for define POS_LAST_QUALIFIED_DTC and 
         STOFDTC_STORAGE_BLOCK_SIZE, Change for DEH_ESiF_LookForPosToOvEM() 
         and DEH_ESiF_UpdateEM()
=======  =====================================================================
  1. SSWCCB-925: Calculation of POS_LAST_QUALIFIED_DTC and
         STOFDTC_STORAGE_BLOCK_SIZE corrected   
==============================================================================

V4.1.1   Bugfix for DEH_FFiF_InitFF(), DEH_TEST declarations
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.1.0   Bugfix for define POS_LAST_QUALIFIED_DTC and 
         STOFDTC_STORAGE_BLOCK_SIZE
=======  =====================================================================
  1. SSWCCB-573: Calculation of POS_LAST_QUALIFIED_DTC and
         STOFDTC_STORAGE_BLOCK_SIZE corrected   
==============================================================================

V4.0.7   Bugfix for DEH_CLRBIT(), APL_DEH_ReadAddFF(), DEH_ESiF_WriteEM(),
         APL_DEH_EEPWriteExtFFData() and APL_DEH_EEPReadExtFFData
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.0.6   Bugfix for DEH_FFiF_ReadFF() 
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.0.5   Bugfix for DEH_FFiF_ReadFF() and DEH_ReadDTCExtDataRecord() 
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.0.4   Bugfix for DEH_ESiF_WriteEM() 
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.0.3   Bugfix for DEH_FFiF_ReadFF(), DEH_SetDiagnosticSession(),
         DEH_StoreStatusOfDTCInfos() and DEH_ClearDiagnosticInformation() 
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.0.2   Bugfix DEH_SUP_BLOCKWRITE 
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.0.1   Bugfix for DEH_ClearDiagnosticInformation() and 
         DEH_ReadDTCSnapshotRecord()
=======  =====================================================================
     no code changes in this file
==============================================================================

V4.0.0   New defines for pending bit support, external additional FF buffer,
         support EEP blockwrite and set warning indicator request
=======  =====================================================================
  1. #define DEH_USE_STATUSOFDTC_PENDING_BIT
  2. #define DEH_MAX_NUMBER_PENDING_BIT_IDX 1
  3. #define DEH_EXT_FF_APL_SUP
  4. #define DEH_MAX_NUM_OF_EV_WITH_ADD_FF 2
  5. #define DEH_SUP_BLOCKWRITE
  6. #define DEH_MAX_NUMBER_LOOPLOCK 10
  7. #define DEH_SET_WARNING_INDICATOR_REQ
==============================================================================

V3.0.0   Deletion of KWP specific code
=======  =====================================================================
  1. Deletion of KWP specific code
==============================================================================

V2.2.2   Bugfix for ResponseOnEvent in function DEH_StM_Event_cyclic()
=======  =====================================================================
     no code changes in this file
==============================================================================

V2.2.1   Bugfix for DEH_FFiF_GetExtFF, DEH_ESiF_WarnLampAndSrvBitUpd
         and DEH_ClearDiagnosticInformation
=======  =====================================================================
     no code changes in this file
==============================================================================

V2.2.0   new default value for some defines
=======  =====================================================================
  1. #define DEH_SUP_UDS_OBD_STATUS disabled
  2. #define DEH_STD_FF_TIME_NOT_AVAILABLE 0x00 -> 0xFF
  3. #define DEH_MAX_NUM_OF_UC_CYCLES 10 -> 0xFF
  4. preprocessor check for DEH_FF_BUFFER_SIZE > 254
==============================================================================

V2.1.1   ResponseOnEvent
=======  =====================================================================
     no code changes in this file
==============================================================================  

V2.1.0   LastConfirmedDTC and ResponseOnEvent
=======  =====================================================================
  1. new define to enable/disable ResponseOnEvent
  2. additional storage block (POS_LAST_QUALIFIED_DTC)
==============================================================================

V2.0.1   missing type declarations and wrong variable name
=======  =====================================================================
     no code changes in this file
==============================================================================

V2.0.0   #ifdef DEH_SUP_CAL_PRIO and rename #define DEH_SUP_REQUEST_REPORT_EV
=======  =====================================================================
  1. add ifdef DEH_SUP_CAL_PRIO for activate calibratable event priority
         [SwA_04.0338], switch between the old EventPathParameter-structure
         (compatible to DEH <= V1.3.0) and the new structure with calibratable
         event priority
  2. rename define for APL_DEH_RequestReportEvent to DEH_SUP_REQUEST_REPORT_EV
==============================================================================

V1.4.0   calibratable event priority and new callback function
         APL_DEH_RequestReportEvent()
=======  =====================================================================
  1. splitting the event path parmeter structure for calibratable event
         priority
  2. call up APL_DEH_RequestReportEvent() after clearing diagnostic
         information and after control DTC setting
==============================================================================

V1.3.0   extend Interface for APL_DEH_ReadAddFF and UNLEARN mechanism
=======  =====================================================================
  1. Interface for APL_DEH_ReadAddFF(..) (ONLY UDS relevant)::
         include a new parameter in the function call interface
         - tDEH_EventNumber EventNumber_uT
         to support different freeze frames with the same Extented Data Record Number
         dependent on the DTC (or related the internal event number)

  2. include a mechanism to release the unlearn mechanism without any limits::
        Normally the unlearn mechanism starts if a changes in the received unlearn
        counter (OR aging counter) is detetected.
        Under normal circumstances only some small amount of changes within the
        received unlearn counter is possible (within one driving cycle).
        The unlearn mechanism has a big amount  of runtime to check all stored
        events for there current state and to check if the stored PASSIVE event can
        be erased or not.
        The unlearn limit is necessary to avoid runtime problems if the received unlearn
        counter not plausible (a lot of changes).
        The release the unlearn limit the
        #define DEH_MAX_NUM_OF_UC_CYCLES 0xFF
        has to be set within the file deh_cfg.h!
==============================================================================

V1.2.5   Change StatusOfDTC Flags after DEH_ClearEvent()
=======  =====================================================================
  KWP2000: clear event within the error memory BUT NO change of readiness bit
           and set to PASSIVE (NOT STORED)
  UDS:     bit7 - MIL ........................ => RESET to OFF
           bit6 - Test Not Compl This Op Cycle => reset to NOT TESTED THIS OP.
                                                  CYCLE
           bit5 - Test Failed Since Last Clear => NO CHANGE
           bit4 - Test Not Complete SLC ...... => NO CHANGE
           bit3 - Conf DTC ................... => Reset to NO CONFIRMED DTC
           bit2 - Pending DTC ................ => NO CHANGE
           bit1 - Test Failed This OP Cycle .. => Reset to TEST NOT FAILED
           bit0 - Test Current State ......... => reset to PASSIVE


V1.2.4   Bugfix DEH_ReadDTCExtDataRecord()
=======  =====================================================================
  1. priority test for the current event with correct event index
================================================================================

V1.2.3   NOT ERASABLE EVENTS handling
=======  =====================================================================
  1. All state bits (StatusOfDTC) for NOT erasable events are not reset or
     cleared with the function DEH_ClearDiagnosticInformation() if the current
     diagnostic session NOT equal to Developper Session OR Programmer Session
================================================================================

V1.2.2   Extend Prio 9 / Change Locked DTC handling / Extend DEFECT ECU errors
=======  =====================================================================
  1. Change state from ACTIVE - NOT STORED events after call
     DEH_ControlDTCSetting(ON) back to PASSIVE state. This is necesarry to
     start a normal debouncing and storage after new error detection.
  2. Priority 9 events are only erasable within the developer diagnosis
     session.
  3. DEH_ClearDiagnosticInformation() in all other diagnosis session
     (NOT developer session) has no influence to the Status Of DTC flags for
     Prio 9 Events.
  4. ECU defect events are now erasable within the diagnosis programmer session.
  5. Bugfix:: DEH_ReadDTCExtDataRecord()-> StatusOfDTC return value now correct
     (former only for event with the number 0!)
  6. clear unused variable DEH_stActiveEvents_mb
  7. support the variable DEH_StEV_chgState_mu8 only if compiler switch
    (DEH_SUP_DETECT_CHANGE_EV_STATE) is set
  8. new state for unlearn algorithm state machine (to avoid unlearn blocking
     after a new DEH_Init(..))
================================================================================

V1.2.1   PRIORITY 9 Event support
=======  ========================
  events with priority 9 have no influence to the CAN event state bit
  (macro DEH_GET_CAN_EVENT_BIT (variable DEH_stCANEventBit_mb)) and no
  influence to the warning lamp state(macro DEH_GET_LAMP_INFO
  (variable DEH_stWarnLamp_mu8)

  KWP2000:
  --------
  The function DEH_ReadIdentifiedEvents(..) and DEH_GetNumberOfIdentEvents(..)
  read out the events with priority 9 only in diagnosis session
  DEH_ENTW_DIAG_SESSION (0x86 => developer session) in all other diagnosis session
  this events will be ignored.

  UDS:
  ----
  The function DEH_ReadDTCByStatus(..) and DEH_ReadDTCExtDataRecord(..)
  read out the events with priority 9 only in diagnosis session
  DEH_ENTW_DIAG_SESSION (0x4F => developer session) in all other diagnosis session
  this events will be ignored.
================================================================================
V1.2.0
======

KWP2000
-------
  1) new Readyness Bit Handling to fullfill OBD requirements
  ----------------------------------------------------------
  The readiness bit is permanent set to tested (value 0) after
  the first received test report for an special DTC. The service
  DEH_ClearDiagnosticInformation(clear error memory) reset all
  readiness bits to NOT tested (value 1).

     - I)   DEH_StoreStatusOfDTCInfos()
              function to inform the DEH about system shutt off and to store the
              internal Readiness Bit into a EEPROM Byte - array
     - II)  APL_DEH_WriteStatusOfDTC(..)
              function from application for the DEH to write readiness information
              status bytes in the EEPROM byte array
     - III) APL_DEH_ReadStatusOfDTC(..)
              function from application for the DEH to read readiness information
              status bytes from the EEPROM byte array

UDS/KWP2000
-----------
  2) new unlearn counter handling if no valid unlearn counter available
  ---------------------------------------------------------------------
  - store 0xFF as valid value to the error memory if the application delivered this value
  - NO unlearn of a PASSIVE error with unlearn counter 0xFF in the error memory

  3) DEH_E_INIT for all SDS service function if DEH NOT initialized

UDS
---
  4) function DEH_ReadDTCExtDataRecord
  ------------------------------------
  - return value DEH_OK, if DTC NOT stored
  - return value numOfBytes = 0, if DTC NOT stored

  5) ControllDTC and Pending Bits
  -------------------------------
  - NO support of the Pending Status Bits after ControlDTC with
    parameter DTC_OFF (0x02)

  6) DEH_ReadDTCExtDataRecord new data layout
  -------------------------------------------
  - no central aging counter included in the service answer
================================================================================

V1.1.2
1) new Test Failed Last State Specification
  - Test Failed Last State is NOT debounced error state which are stored into
    the EEPROM for next driving cycle

2) new include structure

3) aprove CAN-Event State Bit and Warning Lamp State after aging

4) read FREEZE FRAMES if error entry with activated Freeze Frame Update Bit
    - for error with Event Debounced 1
      (and Freeze Frame Update Period is not reached)
=================================================================================

V1.1.1   First Revision with full UDS-Support
         ===================================
if UDS and OR OBD supported (dependant on defines):::

1) new application function to read and store the StatusOfDTC flags in buffer
   from the application
    - APL_DEH_ReadStatusOfDTC()
    - APL_DEH_WriteStatusOfDTC()

2) new function to read back all StatusOfTDC flags to application buffer if the
   application going to sleep
    - DEH_StoreStatusOfDTCInfos()

3) update funciton APL_DEH_ReadAddFF() with new data defines

4) support APL_DEH_ReadDTCSnapshotRecord() to read Snap shot data from application

5) inform the application for DEH state canges APL_DEH_SnapShotDatenInit()

6) extend the service DEH_ReadDTCExtDataRecord() with Record Numbers::
  - 0x70-0x7F : Extended Record Datas
  - 0xFF      : AllDTCExtendedDataRecords
============================================================================*/

#ifndef _DEH_CFG_H_
  #define  _DEH_CFG_H_

#include <Dem_Types.h> /* Include AUTOSAR standard types */






/*==========================================================================*/
/* Project Includes                                                         */
/*==========================================================================*/

/*==========================================================================*/
/* Defines                                                                  */
/*==========================================================================*/

/* Always defined to realise Dem_GetEventTested */
#define DEH_TEST

/* ========================================================================== */
/*               U D S - DEFINE Block S T A R T                               */
/*  1  - DEH_SUP_UDS_OBD_STATUS     --> ENABLE OBD SUPPORT                    */
/*  2  - DEH_SUP_SNAP_SHOT_DATA     --> ENABLE SUPPORT OF SNAPSHOT DATAS      */
/*  3  - DEH_MAX_SNAPSHOT_DATA_LEN  --> DEFINE MAXIMUM SNAPSHOT DATA SIZE     */
/*  4  - DEH_MAX_LEN_ADD_FF         --> DEFINE MAXIMUM FOR ADDITIONAL FF DATAS*/
/* ========================================================================== */

    /* -------------------------------------------------------------------- */
    /* flag to enable OBD status bits in the UDS variant of DEH             */
    /* This function is disabled by default. [SwA_04.0020]                  */
    /* -------------------------------------------------------------------- */

/* #define DEH_SUP_UDS_OBD_STATUS */

    /* -------------------------------------------------------------------- */
    /* flag to enable support for snap shot data                            */
    /* -------------------------------------------------------------------- */
/* #define DEH_SUP_SNAP_SHOT_DATA */

    /* -------------------------------------------------------------------- */
    /* define for maximum data length for the snapshot datas                */
    /* This define is only relevant if  snapshot datas are activated        */
    /* -------------------------------------------------------------------- */
#define DEH_MAX_SNAPSHOT_DATA_LEN  0

    /* -------------------------------------------------------------------- */
    /* flag to enable support of pending bit in non OBD configuration       */
    /* This function is disabled by default.                                */
    /* -------------------------------------------------------------------- */
/* #define DEH_USE_STATUSOFDTC_PENDING_BIT */

/* Not necessary because the configuration parameter DemOBDSupport is disabled in Dem.xdm and therefore DEH_SUP_UDS_OBD_STATUS is not activatable.
#if (defined(DEH_SUP_UDS_OBD_STATUS)) 
  #if (defined(DEH_USE_STATUSOFDTC_PENDING_BIT))
	#error "ERROR :: In support OBD status bit configuration the pending bit is already used!"
  #endif
#endif
*/
/* ========================================================================== */
/*               U D S - DEFINE Block E N D                                   */
/* ========================================================================== */

    /* -------------------------------------------------------------------- */
    /* maximum of defined events which are present in the system            */
    /* every event has special parameters (see typedef                      */
    /* tDEH_EventPathParameter                                              */
    /* -------------------------------------------------------------------- */
#define DEH_MAX_NUMBER_OF_EVENTPATHS  176

    /* -------------------------------------------------------------------- */
    /* maximum of possible events which could stored into the event memory  */
    /* all events are normally stored in a EEPROM                           */
    /* The maximum Number of possible events wich can be provided by DEH in */
    /* a EEPROM is 254 !!!                                                  */
    /* The minimum should be 5 entries. (VW 80114 Spec.)                    */
    /* -------------------------------------------------------------------- */

#define DEH_MAX_NUMBER_EV_MEM  25

    /* --------------------------------------------------------------------- */
    /* Max numbers of attemps to read freeze frames [SSWCCB-1708]            */
    /* --------------------------------------------------------------------- */
#define DEH_MAX_NUMBER_FFBUSYRESP 10

    /* -------------------------------------------------------------------- */
    /* flag to read and store standard freeze frames                        */
    /* standard freeze frames are normally received via GATEWAY COMFORT 1   */
    /* message and are 7 Bytes. The internal storage are 8 Byte with the    */
    /* 3 Byte kilometers and 5 Bytes timestamp.                             */
    /* -------------------------------------------------------------------- */

#define DEH_READ_STD_FF
#define DEH_READ_ADD_FF


    /* -------------------------------------------------------------------- */
    /* flag to read and store additional freeze frames                      */
    /* -------------------------------------------------------------------- */

    /* -------------------------------------------------------------------- */
    /* Flag to enable/disable the support of extened FFs by application.    */
    /* This function is disabled by default.                                */
    /* -------------------------------------------------------------------- */
/* #define DEH_EXT_FF_APL_SUP */

    /* -------------------------------------------------------------------- */
    /* Define for maximum number of events with additional freeze frames    */
    /* -------------------------------------------------------------------- */
#ifdef DEH_EXT_FF_APL_SUP
  #define DEH_MAX_NUM_OF_EV_WITH_ADD_FF  2
#endif

    /* -------------------------------------------------------------------- */
    /* Define for maximum number of additional freeze frames per stored     */
    /* event.                                                               */
    /* -------------------------------------------------------------------- */
#define DEH_MAX_NUMBER_ADD_FF  1

    /* -------------------------------------------------------------------- */
    /* Define for maximum length of additional freeze frames                */
    /* The maximum legth should be only defined if the flag                 */
    /* -------------------------------------------------------------------- */
#define DEH_MAX_LEN_ADD_FF 32

    /* -------------------------------------------------------------------- */
    /*  ### check the plausibility of parameters  ###                       */
    /*  Force compiler error in folowing cases:                             */
    /*  I)  ADD FREEZE FRAMES are defined but the value of                  */
    /*      DEH_MAX_NUMBER_ADD_FF or DEH_MAX_LEN_ADD_FF is not correct      */
    /*  II) ADD FREEZE FRAMES are NOT defined  AND the value of             */
    /*      DEH_MAX_NUMBER_ADD_FF or of DEH_MAX_LEN_ADD_FF is not correct   */
    /*  III)DEH_MAX_LEN_ADD_FF is defined in KWP2000 variant                */
    /* -------------------------------------------------------------------- */

#if (defined(DEH_READ_ADD_FF))
    #if ((DEH_MAX_NUMBER_ADD_FF == 0) || (!(defined(DEH_MAX_NUMBER_ADD_FF))))
      #error "ERROR :: The number of additional freeze frames is NOT DEFINED or zero!"
    #elif ((DEH_MAX_LEN_ADD_FF == 0) || (!(defined(DEH_MAX_LEN_ADD_FF))))
      #error "ERROR :: The maximum length of additional freeze frames is NOT DEFINED or zero!"
    #endif
#elif (DEH_MAX_NUMBER_ADD_FF > 0)
   #error "ERROR :: Additional freeze frames are not defined BUT the number of DEH_MAX_NUMBER_ADD_FF is not zero!"
#elif (!(defined(DEH_MAX_NUMBER_ADD_FF)))
  #error "ERROR :: Additional freeze frames has to be DEFINED with value zero!"
#elif (DEH_MAX_LEN_ADD_FF > 0)
  #error "ERROR :: Additional freeze frames are not defined BUT the value of DEH_MAX_LEN_ADD_FF is not zero!"
#elif (!(defined(DEH_MAX_LEN_ADD_FF)))
  #error "ERROR :: The maximum length of additional freeze frames has to be DEFINED with value zero!"
#endif

    /* -------------------------------------------------------------------- */
    /* Maximum numbers  of stored freeze frames. This number is the summary */
    /* of Standard freeze frames and further additional freeze frame.       */
    /* -------------------------------------------------------------------- */

#ifdef DEH_READ_STD_FF

    #ifdef DEH_READ_ADD_FF
      #ifdef  DEH_MAX_NUMBER_ADD_FF
        #define DEH_MAX_NUMBER_FF  (DEH_MAX_NUMBER_ADD_FF+1)
      #endif
    #else
       #define DEH_MAX_NUMBER_FF 1
    #endif

#else

    #if (DEH_MAX_NUMBER_ADD_FF > 0)
       #define DEH_MAX_NUMBER_FF  DEH_MAX_NUMBER_ADD_FF
    #endif

#endif

    /* --------------------------------------------------------------------- */
    /* constants for no standard freeze frames available                     */
    /* two possible reasons :                                                */
    /* I)  read standard FF is not configured                                */
    /* II) for this event is no FF stored (FF buffer was full)               */
    /* --------------------------------------------------------------------- */
#define DEH_STDFF_KM_NOT_AVAILABLE   0xFF
#define DEH_STDFF_TIME_NOT_AVAILABLE 0xFF

    /* -------------------------------------------------------------------- */
    /* Define for lines in Freeze Frame Table                               */
    /* Every line has a different combination of Freeze Frames to storage.  */
    /* Every event has a parameter to address the freeze frame table.       */
    /* -------------------------------------------------------------------- */

#define DEH_MAX_NUMBER_FF_IDX 2

    /* --------------------------------------------------------------------- */
    /* Define for lines in Pending Bit Table                                 */
    /* Every line has a different combination of parameters.                 */
    /* Every event has a parameter to set and to clear the pending bit.      */
    /* --------------------------------------------------------------------- */
#ifdef DEH_USE_STATUSOFDTC_PENDING_BIT
  #define DEH_MAX_NUMBER_PENDING_BIT_IDX 0u
#endif
    /* -------------------------------------------------------------------- */
    /* flag to enable the function to report all state changes.             */
    /* If this flag enabled then would be called the function               */
    /* APL_DEH_ReportChgEventState (eventNumber_uT; newState )              */
    /* default is this function disable                                     */
    /* -------------------------------------------------------------------- */
/* #define DEH_SUP_DETECT_CHANGE_EV_STATE */

    /* -------------------------------------------------------------------- */
    /* Buffer size for temporary storage of freeze frames. If the system    */
    /* should be stored freeze frames this parameter should be minimum      */
    /* one entry.                                                           */
    /* The freeze frame buffer stored the standard freeze frames (8 Bytes ) */
    /* and all needed additional freeze frames ( 3 Byte per Add. FF).       */
    /* This buffer is needed to catch the freeze frames after the first     */
    /* occurance of a event (fault) until this event is stored.             */
    /* Is the event not stored then release the recerve buffer              */
    /* -------------------------------------------------------------------- */

#define DEH_FF_BUFFER_SIZE 40

#if (DEH_FF_BUFFER_SIZE >254)
    #error "ERROR :: Not allowed buffer size. The freeze frame buffer must be smaller than 255!"
#endif

  /* --------------------------------------------------------------------- */
  /* period definition for Update Event Memory                             */
  /* --------------------------------------------------------------------- */

#define DEH_EVENT_MEM_UPD_PERIOD 5 /* 50.0 ms */

  /* --------------------------------------------------------------------- */
  /* period definition for read Freeze Frames                              */
  /* --------------------------------------------------------------------- */

#define DEH_READ_FF_PERIOD  5 /* 50.0 ms */

  /* --------------------------------------------------------------------- */
  /* period definition for analze the warning lamp state and CAN-Event Bit */
  /* --------------------------------------------------------------------- */

#define DEH_CANBIT_WARNLAMP_PERIOD 1 /* 10.0 ms */

  /* --------------------------------------------------------------------- */
  /* period definition for wait after Unlearn Algorithm got an BUSSY from  */
  /* function APL_DEH_EEPWriteEventData (normaly EEPROM access)            */
  /* --------------------------------------------------------------------- */

#define DEH_WAIT_UNLEARN_PERIOD 5 /* 50.0 ms */

  /* --------------------------------------------------------------------- */
  /* max numbers of possible unlearn cycles after receiving a new unlearn  */
  /* counter (default is 0xFF) [SwA_04.0278]                               */
  /* special case : 0xFF => no limit for unlearn cycles                 */
  /* --------------------------------------------------------------------- */

#define DEH_MAX_NUM_OF_UC_CYCLES 40

  /* --------------------------------------------------------------------- */
  /* Flag to enable the support of EEP blockwrite.                         */
  /* This function is disabled by default.                                 */
  /* --------------------------------------------------------------------- */
/* #define DEH_SUP_BLOCKWRITE */

  /* --------------------------------------------------------------------- */
  /* Max numbers of loops to clear the diagnostic information              */
  /* --------------------------------------------------------------------- */
#define DEH_MAX_NUMBER_LOOPLOCK 10

  /* --------------------------------------------------------------------- */
  /* Flag to enable the function to report the successful clearing of the  */
  /* error buffer or the event memory is activated by                      */
  /* DEH_ControlDTCSetting. If this flag is enabled, the function          */
  /* APL_DEH_RequestReportEvent() will be called.                          */
  /* This function is disabled by default. [SwA_04.0284]                   */
  /* --------------------------------------------------------------------- */
/* #define DEH_SUP_REQUEST_REPORT_EV */


  /* --------------------------------------------------------------------- */
  /* Flag to allow to change the priority with a special tool like INCA    */
  /* or CANape.                                                            */
  /* This function is disabled by default. [SwA_04.0338]                   */
  /* --------------------------------------------------------------------- */
/* #define DEH_SUP_CAL_PRIO */

  /* --------------------------------------------------------------------- */
  /* Flag to enable/disable ROE functions                                  */
  /* This function is enabled by default.                                  */
  /* --------------------------------------------------------------------- */
/* #define DEH_RESPONSE_ON_EVENT */

  /* --------------------------------------------------------------------- */
  /* Flag to enable/disable the setting of warning lamp indication bit by  */
  /* application.                                                          */
  /* This function is disabled by default.                                 */
  /* --------------------------------------------------------------------- */
/* #define DEH_SET_WARNING_INDICATOR_REQ */

  /* -------------------------------------------------------------------- */
  /* flag to enable the function to report status of DTC changes.         */
  /* If this flag enabled then would be called the function               */
  /* APL_DEH_ReportStatusOfDTCChanged (eventNumber_uT; statusOfDtc_u8 )   */
  /* This function is disabled by default.                                */
  /* -------------------------------------------------------------------- */
/* #define DEH_SUP_DETECT_CHANGE_STATUSOFDTC */

    /* -------------------------------------------------------------------- */
    /* flag to enable support of VAG DEH critical section                   */
    /* This function is disabled by default.                                */
    /* -------------------------------------------------------------------- */
#define DEH_PROTECT_GLOBAL_VARIABLES 

  /* ===================================================================== */
  /* Definition for exclusive area used in DEH module                      */
  /* DEH critical section must be renamed into the Dem-Wrapper critical    */
  /* section with macros provided by the Dem-Wrapper                       */
  /* ===================================================================== */

/* ASR4 Mapping */
/* !LINKSTO vsc_Dem_450_MQB_MLB, 1 */
#define SchM_Enter_Deh(SCHM_DEH_INSTANCE_0, SCHM_DEH_EXCLUSIVE_AREA_0) SchM_Enter_Dem_SCHM_DEM_EXCLUSIVE_AREA_1()
#define SchM_Exit_Deh(SCHM_DEH_INSTANCE_0, SCHM_DEH_EXCLUSIVE_AREA_0) SchM_Exit_Dem_SCHM_DEM_EXCLUSIVE_AREA_1()



  /* ===================================================================== */
  /* definition for memory block to store the status of DTC infos            */
  /* ===================================================================== */


#define  STOFDTC_ONE_BLOCK_SIZE         ((uint16_t)((((uint16_t)DEH_MAX_NUMBER_OF_EVENTPATHS-(uint16_t)1)/(uint16_t)8)+(uint16_t)1)) 

#ifdef DEH_SUP_UDS_OBD_STATUS
  #define  STOFDTC_POS_TEST_NC          ((uint16_t)  0)
  #define  STOFDTC_POS_TEST_FLS         ((uint16_t)  STOFDTC_ONE_BLOCK_SIZE)
  #define  STOFDTC_POS_PENDING_DTC      ((uint16_t) (STOFDTC_ONE_BLOCK_SIZE*2))
  #define  STOFDTC_POS_TEST_FAILED_SLC  ((uint16_t) (STOFDTC_ONE_BLOCK_SIZE*3))
  #define  STOFDTC_BLOCK_SIZE           ((uint16_t) (STOFDTC_ONE_BLOCK_SIZE*4))
#endif

#ifdef DEH_USE_STATUSOFDTC_PENDING_BIT
  #define  STOFDTC_POS_TEST_NC          ((uint16_t)  0)
  #define  STOFDTC_POS_TEST_FLS         ((uint16_t)  STOFDTC_ONE_BLOCK_SIZE)
  #define  STOFDTC_POS_PENDING_DTC      ((uint16_t) (STOFDTC_ONE_BLOCK_SIZE*2))
  #define  STOFDTC_POS_CONFIRMED_DTC    ((uint16_t) (STOFDTC_ONE_BLOCK_SIZE*3))
  #define  STOFDTC_BLOCK_SIZE           ((uint16_t) (STOFDTC_ONE_BLOCK_SIZE*4))
#endif

#ifndef DEH_SUP_UDS_OBD_STATUS
  #ifndef DEH_USE_STATUSOFDTC_PENDING_BIT
    #define  STOFDTC_POS_TEST_NC        ((uint16_t)  0)
    #define  STOFDTC_POS_TEST_FLS       ((uint16_t)  STOFDTC_ONE_BLOCK_SIZE)
    #define  STOFDTC_BLOCK_SIZE         ((uint16_t) (STOFDTC_ONE_BLOCK_SIZE*2))
  #endif
#endif

#ifdef DEH_RESPONSE_ON_EVENT
      /* SSWCCB-573, SSWCCB-925 */
    #define  POS_LAST_QUALIFIED_DTC         ((uint16_t) (STOFDTC_BLOCK_SIZE ))
    #define  STOFDTC_POS_STATUS_BYTE        ((uint16_t) (POS_LAST_QUALIFIED_DTC + sizeof(tDEH_EventNumber)))
    #define  STOFDTC_STORAGE_BLOCK_SIZE     ((uint16_t) (POS_LAST_QUALIFIED_DTC + sizeof(tDEH_EventNumber) + sizeof(uint8_t)))   
#else
    #define  STOFDTC_POS_STATUS_BYTE        ((uint16_t) (STOFDTC_BLOCK_SIZE))
    #define  STOFDTC_STORAGE_BLOCK_SIZE     ((uint16_t) (STOFDTC_BLOCK_SIZE + sizeof(uint8_t)))
#endif

#define  DEH_MAX_EXT_REC_BUFFER_DATA  	((uint8_t) (DEH_MAX_LEN_ADD_FF+2))

#define BYTE_POS(event_number)          ((event_number==0) ?((uint8_t) 0 ):((uint8_t) (event_number/8)))
#define BIT_POS(event_number)           ((event_number==0) ?((uint8_t) 0 ):((uint8_t) (event_number%8)))

/*==========================================================================*/
/* Typedefs                                                                 */
/*==========================================================================*/

typedef struct
{
    uint8_t StdFF[8];

} tDEH_StdFreezeFrame;


typedef struct
{
    uint16_t            EventNumber;
    tDEH_StdFreezeFrame StdFFrames;
#ifdef DEH_READ_ADD_FF
  #ifndef DEH_EXT_FF_APL_SUP
    uint8_t             ExtDataRec_u8[DEH_MAX_NUMBER_ADD_FF][DEH_MAX_EXT_REC_BUFFER_DATA];
  #endif  
#endif
} tDEH_FFBuffer;


#ifdef DEH_READ_ADD_FF
  #ifdef DEH_EXT_FF_APL_SUP
    typedef struct
    {
      uint16_t            EventNumber;
      uint8_t             ExtDataRec_u8[DEH_MAX_NUMBER_ADD_FF][DEH_MAX_EXT_REC_BUFFER_DATA];
    } tDEH_ADDFFBuffer;
  #endif  
#endif


/*==========================================================================*/
/* Global Variables                                                         */
/*==========================================================================*/

/*==========================================================================*/
/* Global  Prototypes                                                       */
/*==========================================================================*/

/*==========================================================================*/

  /* avoid double INCLUDES */
#endif


