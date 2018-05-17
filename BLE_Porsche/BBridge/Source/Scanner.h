/**
 * \addtogroup Scanner
 * @{
 *
 * @file 	Scanner.h
 * @author	p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * \addtogroup Scanner
 * @{
 * detailed description here
 * @}
 *
 * @internal
 * $LastChangedDate: 2018-01-19 11:00:31 +0100 (Fr, 19 Jan 2018) $
 * $LastChangedBy: svn_integrationbot $
 * $Revision: 17299 $
 * $Id: Scanner.h 17299 2018-01-19 10:00:31Z svn_integrationbot $
 *
 */


#ifndef SCANNER_H_
#define SCANNER_H_

#include "BBridgeDefs.h"
#include "gatt.h"
#include "central.h"


extern void ScannerInit(BBridgeInterface_t * interface);
extern void ScannerStartDevice(void);
extern uint8 ScannerStartDiscovery(void);
extern uint8 ScannerConnect(const uint8 * peerAddr, uint8 addrType) ;
extern uint8 ScannerPeriodicChecks(void);
extern uint8 ScannerUpdateLink(uint16 connHandle, uint16 connIntervalMin,
                                            uint16 connIntervalMax, uint16 connLatency,
                                            uint16 connTimeout);
extern void ScannerStartServiceDiscovery( void );
extern void ScannerProcessGATTMsg( gattMsgEvent_t *pMsg );
extern uint8 ScannerTxData(uint16_t connHandle, const uint8 * data, uint8 dataLength);
extern void ScannerTerminateConnection( uint16_t connHandle);

#endif /* SCANNER_H_ */
/** @}*/
