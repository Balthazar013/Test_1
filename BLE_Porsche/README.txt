------------------------------------------
BBridge Release Notes v1.4
Date: 19.04.2016
$Id: README.txt 9352 2016-04-19 06:11:30Z p344575 $
------------------------------------------


---------------------
DIRECTORIES
---------------------
Base directory for the BBridge project:
    [RELEASE_DIR]/BBridge
	* Software released

    [RELEASE_DIR]/Documentation/
	* General project documentation

    [RELEASE_DIR]/Tests/
        * Test results in xml


    [RELEASE_DIR]/TI/
	* Part of the TI BLE stack v1.4.1

    [RELEASE_DIR]/STM32F407/
    	* This directory contains sample codes that supports on integrating and communicating
with the BBridge application over a Panther (master application).


 

---------------------
APPLICATION ON THE PANTHER SIDE:
---------------------
Path: [RELEASE_DIR]/STM32F407/main.c

For this sample application the same main.c file can be used for both 
Scanner and Connectbale applications. Only the OPERATING_MODE defines
has to be set for each of the builds:
    #define OPERATING_MODE SCANNER 
    #define OPERATING_MODE CONNECTABLE
    
Ping-Pong application for Scanner and Connectable mode which exchanges bluetooth messages
between two panther devices.
                
[RELEASE_DIR]/STM32F407/SPITransportLayer
        - This module implements the SPI protocol handling which makes the SPI communication reliable
            
[RELEASE_DIR]/STM32F407/typedefs
        - Definitions needed for the sampes


        
---------------------
APPLICATION ON THE BBRIDGE SIDE:
---------------------
Path: [RELEASE_DIR]/BBridge/

[RELEASE_DIR]/BBridge/Source
    - Hardware-dependent source code.

[RELEASE_DIR]/BBridge/BBridgeTIBLEBuilds
    - Project build configurations

[RELEASE_DIR]/BBridge/BBridgeProfiles
    - BBridge TIBLE profile for the project

[RELEASE_DIR]/BBridge/BBridgeModules
    - BBridge busines logics implementation
    
    
---------------------
RELEASE NOTES
---------------------
- Aligned UML diagrams with currently used states in the SPITransportlayer
- Adjusted [RELEASE_DIR]/STM32F407/main.c to reflect real Panther application (running in ticks of 1/10ms)
- Refactored [RELEASE_DIR]/STM32F407/main.c file  so it is aligned with the main.c currently used by PES to test cases (over UART)
	* Changes made to make it easier to "diff" files before releases
- Removed extra "safety" bytes from the SPI slave communication. Such issues shall be handled in the Master side
- Included original UART SPI driver from TI to take advantage of DMA functionalities and comply with standard TI implementations
	- Different pre-compiled values shall be used:
		- HAL_UART_SPI=3 (old USARTSPI=0) 
		- HAL_UART_SPI=2 (old USARTSPI=1)

- SPITransportLayer has independent implementation from master or slave
- Improved SPITransportLayer to read received buffer within 1 reading cycle (with while loop) instead of 1 byte per state-machine cycle
- Removed FrameParser logics from the SPITransportLayer -> SPITransportLayer only works with "payload" information
	-> SOF LEN [payload=FRAME_CTRL + data bytes ] FCS
	-> SOF LEN and FCS shall not be given to the SPITransportLayer

- The calculation of ACK packet length has been fixed:
	In the SPITransportLayer the length of an ACK packet was including the CRC byte, which does not comply with our definition.

	Before (BBridge < 1.4):
		[SOF LEN(2) ACK_DATA FCS]

	Current version (BBridge 1.4):
		[SOF LEN(1) ACK_DATA FCS]

- Tests for RF interference of "indication" messages (communication is not disturbed anymore)
- Removed BBridgeService profile (not needed)

---------------------
KNOWN ISSUES
---------------------
- RSSI readings: Callback values never called by the BLE stack (returns always 0).





