/**
 * \addtogroup BBridgeCommons
 * @{
 *
 * @file 	BBridgeCommons.h
 * @author	p344575
 * @brief 	Holds functions and definitions used across the project scope
 * @copyright &copy; 2016 Porsche Engineering Services GmbH

 * \addtogroup BBridgeCommons
 * @{
 * This module contains functions and definitions that are for use by other
 * modules from the BBridge application.
 * @attention This module needs to be initialized before any functionality is
 * used. Use BBridge_Init(...)
 * @}
 *
 * @internal
 * $LastChangedDate: 2017-11-14 12:44:56 +0100 (Di, 14 Nov 2017) $
 * $LastChangedBy: ksteingass $
 * $Revision: 16315 $
 * $Id: BBridgeCommons.h 16315 2017-11-14 11:44:56Z ksteingass $
 *
 */

#ifndef BBRIDGECOMMONS_H_
#define BBRIDGECOMMONS_H_

#include "BBridgeDefs.h"

extern int BBridgeCommons_FindCMDInList(BBridgeCMDId_t aCmd,
		const BBridgeCMDId_t commandsList[], uint8_t totalCommands,
int * indexResult);




#endif /* BBRIDGECOMMONS_H_ */

/** @}*/

