/**
 * \file
 *
 * \brief AUTOSAR MemIf
 *
 * This file contains the implementation of the AUTOSAR
 * module MemIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined MEMIF_TRACE_H)
#define MEMIF_TRACE_H
/*==================[inclusions]============================================*/



/*==================[macros]================================================*/

#ifndef DBG_MEMIF_CANCEL_ENTRY
/** \brief Entry point of function MemIf_Cancel() */
#define DBG_MEMIF_CANCEL_ENTRY(a)
#endif

#ifndef DBG_MEMIF_CANCEL_EXIT
/** \brief Exit point of function MemIf_Cancel() */
#define DBG_MEMIF_CANCEL_EXIT(a)
#endif

#ifndef DBG_MEMIF_ERASEIMMEDIATEBLOCK_ENTRY
/** \brief Entry point of function MemIf_EraseImmediateBlock() */
#define DBG_MEMIF_ERASEIMMEDIATEBLOCK_ENTRY(a,b)
#endif

#ifndef DBG_MEMIF_ERASEIMMEDIATEBLOCK_EXIT
/** \brief Exit point of function MemIf_EraseImmediateBlock() */
#define DBG_MEMIF_ERASEIMMEDIATEBLOCK_EXIT(a,b,c)
#endif

#ifndef DBG_MEMIF_GETJOBRESULT_ENTRY
/** \brief Entry point of function MemIf_GetJobResult() */
#define DBG_MEMIF_GETJOBRESULT_ENTRY(a)
#endif

#ifndef DBG_MEMIF_GETJOBRESULT_EXIT
/** \brief Exit point of function MemIf_GetJobResult() */
#define DBG_MEMIF_GETJOBRESULT_EXIT(a,b)
#endif

#ifndef DBG_MEMIF_INVALIDATEBLOCK_ENTRY
/** \brief Entry point of function MemIf_InvalidateBlock() */
#define DBG_MEMIF_INVALIDATEBLOCK_ENTRY(a,b)
#endif

#ifndef DBG_MEMIF_INVALIDATEBLOCK_EXIT
/** \brief Exit point of function MemIf_InvalidateBlock() */
#define DBG_MEMIF_INVALIDATEBLOCK_EXIT(a,b,c)
#endif

#ifndef DBG_MEMIF_READ_ENTRY
/** \brief Entry point of function MemIf_Read() */
#define DBG_MEMIF_READ_ENTRY(a,b,c,d,e)
#endif

#ifndef DBG_MEMIF_READ_EXIT
/** \brief Exit point of function MemIf_Read() */
#define DBG_MEMIF_READ_EXIT(a,b,c,d,e,f)
#endif

#ifndef DBG_MEMIF_WRITE_ENTRY
/** \brief Entry point of function MemIf_Write() */
#define DBG_MEMIF_WRITE_ENTRY(a,b,c)
#endif

#ifndef DBG_MEMIF_WRITE_EXIT
/** \brief Exit point of function MemIf_Write() */
#define DBG_MEMIF_WRITE_EXIT(a,b,c,d)
#endif

#ifndef DBG_MEMIF_GETSTATUS_ENTRY
/** \brief Entry point of function MemIf_GetStatus() */
#define DBG_MEMIF_GETSTATUS_ENTRY(a)
#endif

#ifndef DBG_MEMIF_GETSTATUS_EXIT
/** \brief Exit point of function MemIf_GetStatus() */
#define DBG_MEMIF_GETSTATUS_EXIT(a,b)
#endif

#ifndef DBG_MEMIF_SETMODE_ENTRY
/** \brief Entry point of function MemIf_SetMode() */
#define DBG_MEMIF_SETMODE_ENTRY(a)
#endif

#ifndef DBG_MEMIF_SETMODE_EXIT
/** \brief Exit point of function MemIf_SetMode() */
#define DBG_MEMIF_SETMODE_EXIT(a)
#endif

#ifndef DBG_MEMIF_GETVERSIONINFO_ENTRY
/** \brief Entry point of function MemIf_GetVersionInfo() */
#define DBG_MEMIF_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_MEMIF_GETVERSIONINFO_EXIT
/** \brief Exit point of function MemIf_GetVersionInfo() */
#define DBG_MEMIF_GETVERSIONINFO_EXIT(a)
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

#endif /* (!defined MEMIF_TRACE_H) */
/*==================[end of file]===========================================*/
