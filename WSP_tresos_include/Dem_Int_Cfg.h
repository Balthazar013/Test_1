/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DEM_INT_CFG_H)
#define DEM_INT_CFG_H

/*==================[includes]==============================================*/

/*------------------[callback header file inclusions]-----------------------*/

#include <Dem.h>

#include <TSMem.h>           /* Elektrobit Automotive TS_MemCpy/TS_MemSet*/

/*==================[macros]=================================================*/

/*------------------[Mem copy/set macros]------------------------------------*/

#if (defined DEM_MemCpy)
#error DEM_MemCpy already defined
#endif

#if (defined DEM_MemSet)
#error DEM_MemSet already defined
#endif
/** \brief This Dem-Wrapper macro maps to TS_MemCpy() */
#define DEM_MemCpy(d,s,n) TS_MemCpy((d),(s),(n))
/** \brief This Dem-Wrapper macro maps to TS_MemSet() */
#define DEM_MemSet(d,s,n) TS_MemSet((d),(s),(n))



/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_INT_CFG_H ) */
/*==================[end of file]===========================================*/
