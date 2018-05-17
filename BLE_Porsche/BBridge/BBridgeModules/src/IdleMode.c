/**
 * \addtogroup IdleMode
 * @{
 *
 * @file 	IdleMode.c
 * @author	p344575
 * @brief 	It implements the business logics for the IDLE mode of the BBridge
 * application
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * @internal
 * $LastChangedDate: 2018-01-19 11:00:31 +0100 (Fr, 19 Jan 2018) $
 * $LastChangedBy: svn_integrationbot $
 * $Revision: 17299 $
 * $Id: IdleMode.c 17299 2018-01-19 10:00:31Z svn_integrationbot $
 *
 *
 */

#include <string.h>
#include <stdlib.h>
#include "IdleMode.h"
#include "BBridgeCommons.h"

/**
 * @brief Total number of commands that can be accepted by this operating mode
 */
#define TOTAL_ACCEPTABLE_COMMANDS  12u

/**
 * @brief List of accepted commands by this operating mode.
 * @note The values in available in this list be placed in ascending sorted
 * order.
 */
static BBridgeCMDId_t ACCEPTABLE_COMMANDS[TOTAL_ACCEPTABLE_COMMANDS] =
{
    BBCMD_SET_BROADCAST_MSG,
    BBCMD_GET_BROADCAST_MSG,
    BBCMD_SET_FILTER_MSG,
    BBCMD_GET_FILTER_MSG,
    BBCMD_SET_OP_MODE,
    BBCMD_GET_OP_MODE,
    BBCMD_SET_NVM_BYTE,
    BBCMD_GET_NVM_BYTE,
    BBCMD_SET_ADV_INTERVAL,
    BBCMD_GET_ADV_INTERVAL,
    BBCMD_SET_BOOT_MODE,
    BBCMD_GET_BOOT_MODE,
};

/**
 * @brief Holds the local attributes for this module
 */
typedef struct
{
    /**
    * @brief Idle operating mode state
    */
    BBIDleMDState_t state;
    
    /**
    * @brief Last command received from the BBridge application module
    */
    BBridgeCommand_t lastCommand;
    
    /**
    * @brief Flag to check whether the last command received has been processed
    */
    uint8_t lastCommandProcessed;
    
    /**
    * @brief Store the new operating mode value when receiving new commands
    */
    BBridgeOpMode_t newOpMode;
    
    
    /**
    * @brief Used to control exit operation
    */
    uint8_t exitRequested;
    
    /**
    * @brief Stores a pointer to the BBridgeAPP interface
    */
    BBridgeAppInterface_t * bbAppInterface;
    
    /**
    * @brief Stores the last nackReason (internal usage only)
    */
    BBridgeNACKReason_t nackReason;
    
} BBIdleMD_Controls_t;

/* Private functions */
static void setCMDAsProcessed(void);

/* Private variables */
/**
 * @brief Local pointer for the controls struct
 */
static BBIdleMD_Controls_t controls;

/* Module implementation */

/**
 * @brief It initializes the IDLE operating mode module
 * @return	BB_SUCCESS: ok\n
 * 			1: invalid shared memory pointer\n
 * 			2: invalid bbridge interface pointer\n
 * 			3: acceptable commands list is not in ascending order\n
 */
uint8_t IdleMode_Init(BBridgeAppInterface_t * bbridgeInterface)
{
    uint8_t i;
    uint8_t ret = BB_SUCCESS;
    
    if (bbridgeInterface == BB_SUCCESS)
    {
        ret = 2u; /* invalid bbridge interface pointer*/
    }
    else if (bbridgeInterface->sharedMemValue == NULL)
    {
        ret = 1u; /* invalid shared memory pointer*/
    }
    else
    {
        /* checking acceptable commands list (it must be sorted)*/
        for (i = 0u; i < TOTAL_ACCEPTABLE_COMMANDS - 1u; i++)
        {
            if (ACCEPTABLE_COMMANDS[i] > ACCEPTABLE_COMMANDS[i + 1u])
            {
                ret = 3u;
                break;
            }
        }
        
        if(ret == BB_SUCCESS)
        {
            controls.bbAppInterface = bbridgeInterface;
            /* reseting internal working variables*/
            controls.exitRequested = FALSE;
            setCMDAsProcessed();
            controls.state = BBIDLEMD_IDLE;
            controls.bbAppInterface->sharedMemValueLength = 0u;
        }
    }
    
    return ret;
}

/**
 * @brief It "exits" the idle mode. This function shall be called by the main
 * worker controlling the "IDLE MODE" when it needs to switch between modes
 * @return  BB_SUCCESS: exit executed correctly\n
 *          1: there was no previous command to set a different operating mode
 */
uint8_t IdleMode_ExitMode(void)
{
    uint8_t ret = BB_SUCCESS;
    
    if (controls.state == BBIDLEMD_WAIT_EXIT_CALL)
    {
        controls.exitRequested = TRUE;
    }
    else
    {
        ret = 1u;
    }
    
    return ret;
}

uint8_t IdleMode_IsBusy(void)
{
    return (controls.lastCommandProcessed == TRUE) ? FALSE : TRUE;
}

/**
 * @brief Called when a new command has been received
 * @param data
 * @param length
 * @return  BB_SUCCESS: command received\n
 *          1: BUSY\n
 *          2: invalid command pointer\n
 *          4: command is not acceptable by the IDLE state
 */
uint8_t IdleMode_OnRxCommand(const BBridgeCommand_t * command)
{
    uint8_t ret = BB_SUCCESS;
    int cmdPosition, searchRet;
    
    if (controls.lastCommandProcessed == FALSE)
    {
        ret = 1u; /* BUSY*/
    }
    else if (command == NULL)
    {
        ret = 2u; /* invalid command pointer*/
    }
    else
    {
        /* check is this mode can accept the command*/
        searchRet = BBridgeCommons_FindCMDInList(command->id, ACCEPTABLE_COMMANDS,
        TOTAL_ACCEPTABLE_COMMANDS, &cmdPosition);
        if (searchRet < 0) 
        {
            /* command not found in the list*/
            ret = 3U;
        }
        
        if(ret == BB_SUCCESS)
        {
            /* ok to accept command*/
            controls.lastCommand.id = command->id;
            controls.lastCommand.cmd.length = command->cmd.length;
            
            if (controls.lastCommand.cmd.length > 0u)
            {
                memcpy(controls.lastCommand.cmd.data,
                       command->cmd.data,
                       (uint16_t)command->cmd.length);
            }
            
            controls.lastCommandProcessed = FALSE; /* setting it to not processed*/
        }
    }
    
    return ret;
}

/**
 * @brief It checks whether the IDLE mode is on "exit state". When yes, the
 * main application handler shall retrieve the current MODE and call
 * IdleMode_ExitMode()
 * @see IdleMode_GetNewOperatingMode()
 * @see IdleMode_ExitMode()
 * @return  1: IDLE mode is waiting to exit\n
 *          BB_SUCCESS: there is not new operating mode
 */
uint8_t IdleMode_ReadyToExit(void)
{
    return (controls.state == BBIDLEMD_WAIT_EXIT_CALL) ? TRUE : FALSE;
}

/**
 * @brief It retrieves the new operating mode set
 * @param newMode
 * @return  BB_SUCCESS: ok\n
 *          1: could not retrieve there is no info to be retrieved
 */
uint8_t IdleMode_GetNewOperatingMode(BBridgeOpMode_t * newMode)
{
    uint8_t ret = BB_SUCCESS;
    
    if (IdleMode_ReadyToExit() == TRUE)
    {
        *newMode = controls.newOpMode;
    }
    else
    {
        ret =1u;
    }
    
    return ret;
}

/**
 * @brief It sets the current command as processed. Thus freeing the module to
 * receive more commands
 */
static void setCMDAsProcessed(void)
{
    controls.lastCommandProcessed = TRUE;
}

/**
 * @brief It processes the business logics concerning the IDLE mode of the
 * BBridge application
 */
void IdleMode_Work(void)
{
    BBCMDType_t cmdType;
    uint8_t tmp, ret;
    
    switch (controls.state)
    {
        case (BBIDLEMD_IDLE):
        {
            if (controls.lastCommandProcessed == FALSE)
            {
                /* there is a new command available*/
                /* deciding how to process received command (checking cmd type)*/
                cmdType = controls.bbAppInterface->getCMDType(controls.lastCommand.id);
                switch (cmdType) {
                case (CMDTYPE_SET):
                    /* Setting values */
                    controls.state = BBIDLEMD_PROCESS_SETCMD;
                    break;
                case (CMDTYPE_GET):
                    /* Loading values */
                    controls.state = BBIDLEMD_PROCESS_GETCMD;
                    break;
                default:
                    /* Invalid command -> send NACK */
                    controls.nackReason = BB_NACK_CMD_UNKNOWN;
                    controls.state = BBIDLEMD_SND_NACK;
                    break;
                }
            }
            
            break;
        }
        
        case (BBIDLEMD_PROCESS_GETCMD):
        {
            tmp = 0U; /* reseting value*/
            ret = controls.bbAppInterface->proccessGetCmd(&controls.lastCommand,
                                                    controls.bbAppInterface->sharedMemValue, &tmp);
            if (ret == BB_SUCCESS)
            {
                controls.bbAppInterface->sharedMemValueLength = tmp;
                controls.state = BBIDLEMD_SND_ACK;
            }
            else
            {
                /* error processing -> sending NACK*/
                controls.nackReason = BB_NACK_CMD_UNKNOWN;
                controls.state = BBIDLEMD_SND_NACK;
            }
            
            break;
        }
        
        case (BBIDLEMD_PROCESS_SETCMD):
        {
            if(controls.lastCommand.id == BBCMD_SET_OP_MODE)
            {
                /* processing SET OP MODE command */
                if ((controls.lastCommand.cmd.data[0] == BB_SCANNER_MODE)
                    ||
                    (controls.lastCommand.cmd.data[0] == BB_CONNECTABLE_MODE))
                {
                    controls.newOpMode = (BBridgeOpMode_t) controls.lastCommand.cmd.data[0];
                    /* no need to send ACK at this point (it is done by the BBridge*/
                    /* application module)*/
                    controls.state = BBIDLEMD_WAIT_EXIT_CALL;
                }
                else
                {
                    /* could not set operating mode*/
                    controls.nackReason = BB_NACK_INVALID_REQ;
                    controls.state = BBIDLEMD_SND_NACK;
                }
            }
            else
            {
                /* "Set commands" acceptable by the IDLE OP mode can be handled by
                * the BBridge application mode directly.
                */
                ret = controls.bbAppInterface->proccessSetCmd(&controls.lastCommand);
                if (ret == BB_SUCCESS)
                {
                    if((controls.lastCommand.id)== 0x09)
                    { controls.state = BBIDLEMD_IDLE;  //controls.state = BBIDLEMD_SND_ACK;
                        controls.bbAppInterface->releaseDataHandler(); /* freeing data handler*/
                        setCMDAsProcessed();
                    }
                    else
                    {
                        controls.state = BBIDLEMD_SND_ACK;
                        controls.bbAppInterface->sharedMemValueLength = 0U;
                    }
                }
                else 
                {
                    /* error processing set command, send NACK*/
                    controls.nackReason = BB_NACK_CMD_UNKNOWN;
                    controls.state = BBIDLEMD_SND_NACK;
                }
            }
            break;
        }
        
        case (BBIDLEMD_WAIT_TX2PANTHER):
        {
            if (controls.bbAppInterface->isTxToPantherComplete() == TRUE)
            {
                controls.state = BBIDLEMD_IDLE;
                controls.bbAppInterface->releaseDataHandler(); /* freeing data handler*/
                setCMDAsProcessed();
            }
            
            break;
        }
        
        case (BBIDLEMD_SND_ACK):
        {
            ret = controls.bbAppInterface->pushACK(controls.lastCommand.id,
                                                    controls.bbAppInterface->sharedMemValue,
                                                    controls.bbAppInterface->sharedMemValueLength);
            if (ret == BB_SUCCESS)
            {
                /* data was pushed to be transmitted correctly*/
                controls.state = BBIDLEMD_WAIT_TX2PANTHER;
            }
            else
            {
                /* could not push ACK... try again*/
            }
            
            break;
        }
        
        case (BBIDLEMD_SND_NACK):
        {
            ret = controls.bbAppInterface->pushNACK(controls.lastCommand.id, controls.nackReason);
            if (ret == BB_SUCCESS)
            {
                /* data was pushed to be transmitted correctly*/
                controls.state = BBIDLEMD_WAIT_TX2PANTHER;
            }
            else
            {
                /* could not push NACK... try again*/
            }
            
            break;
        }
        
        case (BBIDLEMD_WAIT_EXIT_CALL):
        {
            /* Waiting exit "IdleMode_ExitMode" call to be called by the bbridge app */
            if (controls.exitRequested == TRUE)
            {
                /* reseting internal variables*/
                controls.exitRequested = FALSE;
                if (controls.lastCommandProcessed == FALSE) 
                {
                    /* there is a command not yet processed (it shall not be possible here)*/
                    controls.lastCommandProcessed = TRUE;
                }
                
                controls.bbAppInterface->releaseDataHandler(); /* freeing data handler*/
                controls.state = BBIDLEMD_IDLE;
            }
            
            break;
        }
        
        default:
        {
            controls.state = BBIDLEMD_IDLE;
            break;
        }
    }
}

#ifdef TESTENVIRONMENT

BBIDleMDState_t * IdleMode_GetState(void)
{
    return &controls.state;
}

#endif

/** @}*/
