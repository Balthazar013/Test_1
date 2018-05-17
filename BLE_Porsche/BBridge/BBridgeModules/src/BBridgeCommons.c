/**
 * \addtogroup BBridgeCommons
 * @{
 *
 * @file 	BBridgeCommons.c
 * @author	p344575
 * @brief 	Shared functions and definitions to be used across the BBridge
 * application
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2017-11-14 12:44:56 +0100 (Di, 14 Nov 2017) $
 * $LastChangedBy: ksteingass $
 * $Revision: 16315 $
 * $Id: BBridgeCommons.c 16315 2017-11-14 11:44:56Z ksteingass $
 *
 */
#include "BBridgeCommons.h"
#include "typedefs.h"


/**
 * @brief It searches for a command in a sorted list using Binary Search
 * algorithm
 * @param aCmd
 * @param commandsList - must be sorted in ascending order
 * @param totalCommands - size of the commandsList
 * @param indexResult - index position in the commands list
 * @return  zero-nonnegative when command was found
 *          -1: when not found on the left-end
 *          -2: when not found on the right-end
 * @note it uses binary search
 */
int BBridgeCommons_FindCMDInList(BBridgeCMDId_t aCmd,
                                const BBridgeCMDId_t commandsList[],
                                uint8_t totalCommands, int * indexResult)
{
    
    int first, last, middle, ret;
    
    *indexResult = -3; /* not found */
    /* Binary search*/
    first = 0;
    last = ((int)totalCommands - 1);
    
    while(first <= last)
    {
        middle = (first+last) / 2;
        /*middle = (first+last) >> 1; // not mirsa compatible */
        if(aCmd < commandsList[middle])
        {
            last = middle - 1;
        }
        else if(commandsList[middle] == aCmd)
        {
            *indexResult = middle;
            break;
        }
        else
        {
            first = middle + 1;
        }
    }
    
    if(*indexResult != -3){
        ret = 0;
    }
    else if(first > last)
    {
        /* not found!*/
        /**indexResult = last;*/
        ret = -2;
    }
    else
    {
        /**indexResult = first;*/
        ret = -1;
    }
    
    return ret;
}

/** @}*/
