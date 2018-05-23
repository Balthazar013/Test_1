/* --------{ EB Automotive C Source File }-------- */

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[MemMap error checking]----------------------------------*/

#if (defined MEMMAP_ERROR) /* to prevent double definition */
#error MEMMAP_ERROR defined, wrong MemMap.h usage
#endif /* if (!defined MEMMAP_ERROR) */

/** \brief Checks if this file has been correctly used
 **
 ** This definition checks if this file has been correctly included
 ** the last time.
 ** We do it here, before the big if-elif. */
#define MEMMAP_ERROR


/*------------------[Start of a module]--------------------------------------*/


/* Memory section macros for NvmExt */

#include <Common_MemMap.h>
#ifdef MEMMAP_ERROR
#error MEMMAP_ERROR defined, wrong MemMap.h usage
#endif
