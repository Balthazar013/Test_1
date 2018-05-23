/**
 * \file
 *
 * \brief AUTOSAR Det
 *
 * This file contains the implementation of the AUTOSAR
 * module Det.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DET_TRACE_H)
#define DET_TRACE_H
/*==================[inclusions]============================================*/



/*==================[macros]================================================*/

#ifndef DBG_DET_INIT_ENTRY
/** \brief Entry point of function Det_Init() */
#define DBG_DET_INIT_ENTRY()
#endif

#ifndef DBG_DET_INIT_EXIT
/** \brief Exit point of function Det_Init() */
#define DBG_DET_INIT_EXIT()
#endif

#ifndef DBG_DET_START_ENTRY
/** \brief Entry point of function Det_Start() */
#define DBG_DET_START_ENTRY()
#endif

#ifndef DBG_DET_START_EXIT
/** \brief Exit point of function Det_Start() */
#define DBG_DET_START_EXIT()
#endif

#ifndef DBG_DET_ASR40_REPORTERROR_ENTRY
/** \brief Entry point of function Det_ASR40_ReportError() */
#define DBG_DET_ASR40_REPORTERROR_ENTRY(a,b,c,d)
#endif

#ifndef DBG_DET_ASR40_REPORTERROR_EXIT
/** \brief Exit point of function Det_ASR40_ReportError() */
#define DBG_DET_ASR40_REPORTERROR_EXIT(a,b,c,d,e)
#endif

#ifndef DBG_DET_ASR32_REPORTERROR_ENTRY
/** \brief Entry point of function Det_ASR32_ReportError() */
#define DBG_DET_ASR32_REPORTERROR_ENTRY(a,b,c,d)
#endif

#ifndef DBG_DET_ASR32_REPORTERROR_EXIT
/** \brief Exit point of function Det_ASR32_ReportError() */
#define DBG_DET_ASR32_REPORTERROR_EXIT(a,b,c,d)
#endif

#ifndef DBG_DET_GETVERSIONINFO_ENTRY
/** \brief Entry point of function Det_GetVersionInfo() */
#define DBG_DET_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_DET_GETVERSIONINFO_EXIT
/** \brief Exit point of function Det_GetVersionInfo() */
#define DBG_DET_GETVERSIONINFO_EXIT(a)
#endif

#ifndef DBG_DET_PRECONDITIONASSERTPRINT_ENTRY
/** \brief Entry point of function Det_PreconditionAssertPrint() */
#define DBG_DET_PRECONDITIONASSERTPRINT_ENTRY(a,b,c,d,e,f,g)
#endif

#ifndef DBG_DET_PRECONDITIONASSERTPRINT_EXIT
/** \brief Exit point of function Det_PreconditionAssertPrint() */
#define DBG_DET_PRECONDITIONASSERTPRINT_EXIT(a,b,c,d,e,f,g)
#endif

#ifndef DBG_DET_POSTCONDITIONASSERTPRINT_ENTRY
/** \brief Entry point of function Det_PostconditionAssertPrint() */
#define DBG_DET_POSTCONDITIONASSERTPRINT_ENTRY(a,b,c,d,e,f,g)
#endif

#ifndef DBG_DET_POSTCONDITIONASSERTPRINT_EXIT
/** \brief Exit point of function Det_PostconditionAssertPrint() */
#define DBG_DET_POSTCONDITIONASSERTPRINT_EXIT(a,b,c,d,e,f,g)
#endif

#ifndef DBG_DET_UNREACHABLECODEASSERTPRINT_ENTRY
/** \brief Entry point of function Det_UnreachableCodeAssertPrint() */
#define DBG_DET_UNREACHABLECODEASSERTPRINT_ENTRY(a,b,c,d,e,f)
#endif

#ifndef DBG_DET_UNREACHABLECODEASSERTPRINT_EXIT
/** \brief Exit point of function Det_UnreachableCodeAssertPrint() */
#define DBG_DET_UNREACHABLECODEASSERTPRINT_EXIT(a,b,c,d,e,f)
#endif

#ifndef DBG_DET_INVARIANTASSERTPRINT_ENTRY
/** \brief Entry point of function Det_InvariantAssertPrint() */
#define DBG_DET_INVARIANTASSERTPRINT_ENTRY(a,b,c,d,e,f,g)
#endif

#ifndef DBG_DET_INVARIANTASSERTPRINT_EXIT
/** \brief Exit point of function Det_InvariantAssertPrint() */
#define DBG_DET_INVARIANTASSERTPRINT_EXIT(a,b,c,d,e,f,g)
#endif

#ifndef DBG_DET_ASR32_RTE_REPORTERROR_ENTRY
/** \brief Entry point of function Det_ASR32_Rte_ReportError() */
#define DBG_DET_ASR32_RTE_REPORTERROR_ENTRY(a,b,c,d)
#endif

#ifndef DBG_DET_ASR32_RTE_REPORTERROR_EXIT
/** \brief Exit point of function Det_ASR32_Rte_ReportError() */
#define DBG_DET_ASR32_RTE_REPORTERROR_EXIT(a,b,c,d)
#endif

#ifndef DBG_DET_ASR40_RTE_REPORTERROR_ENTRY
/** \brief Entry point of function Det_ASR40_Rte_ReportError() */
#define DBG_DET_ASR40_RTE_REPORTERROR_ENTRY(a,b,c,d)
#endif

#ifndef DBG_DET_ASR40_RTE_REPORTERROR_EXIT
/** \brief Exit point of function Det_ASR40_Rte_ReportError() */
#define DBG_DET_ASR40_RTE_REPORTERROR_EXIT(a,b,c,d,e)
#endif

#ifndef DBG_DET_ENTER_SCHM_DET_EXCLUSIVE_AREA_0_ENTRY
/** \brief Entry point of function Det_Enter_SCHM_DET_EXCLUSIVE_AREA_0() */
#define DBG_DET_ENTER_SCHM_DET_EXCLUSIVE_AREA_0_ENTRY()
#endif

#ifndef DBG_DET_ENTER_SCHM_DET_EXCLUSIVE_AREA_0_EXIT
/** \brief Exit point of function Det_Enter_SCHM_DET_EXCLUSIVE_AREA_0() */
#define DBG_DET_ENTER_SCHM_DET_EXCLUSIVE_AREA_0_EXIT()
#endif

#ifndef DBG_DET_EXIT_SCHM_DET_EXCLUSIVE_AREA_0_ENTRY
/** \brief Entry point of function Det_Exit_SCHM_DET_EXCLUSIVE_AREA_0() */
#define DBG_DET_EXIT_SCHM_DET_EXCLUSIVE_AREA_0_ENTRY()
#endif

#ifndef DBG_DET_EXIT_SCHM_DET_EXCLUSIVE_AREA_0_EXIT
/** \brief Exit point of function Det_Exit_SCHM_DET_EXCLUSIVE_AREA_0() */
#define DBG_DET_EXIT_SCHM_DET_EXCLUSIVE_AREA_0_EXIT()
#endif

#ifndef DBG_DET_RTE_REPORTERROR_ENTRY
/** \brief Entry point of function Det_Rte_ReportError() */
#define DBG_DET_RTE_REPORTERROR_ENTRY(a,b,c,d)
#endif

#ifndef DBG_DET_RTE_REPORTERROR_EXIT
/** \brief Exit point of function Det_Rte_ReportError() */
#define DBG_DET_RTE_REPORTERROR_EXIT(a,b,c,d)
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

#endif /* (!defined DET_TRACE_H) */
/*==================[end of file]===========================================*/
