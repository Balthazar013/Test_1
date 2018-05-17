/**
 * \addtogroup Connectable
 * @{
 *
 * @file 	Connectable.h
 * @author	p344575
 * @brief ...
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 * \addtogroup Connectable
 * @{
 * detailed description here
 * @}
 *
 * @internal
 * $LastChangedDate: 2018-01-19 11:00:31 +0100 (Fr, 19 Jan 2018) $
 * $LastChangedBy: svn_integrationbot $
 * $Revision: 17299 $
 * $Id: Connectable.h 17299 2018-01-19 10:00:31Z svn_integrationbot $
 *
 */

#ifndef CONNECTABLE_H_
#define CONNECTABLE_H_

#include "BBridgeDefs.h"
#include "gatt.h"
#include "peripheral.h"

extern void ConnectableInit(BBridgeInterface_t * interface);
extern void ConnectableStartDevice(void);
extern uint8 ConnectableSetScanResp(const uint8 * scanResp, uint8 length);
extern void ConnectableEnableAdv(uint8 enable);
extern uint8  ConnectableSetAdvertiseInterval(uint16 offTime);
extern uint16 ConnectableGetAdvertiseInterval(void);
extern void ConnectableOnConnParametersUpdate(uint16 connInterval,
                                              uint16 connSlaveLatency, uint16 connTimeout);
extern uint8_t ConnectableUpdateConnectionparams(uint16 connMin, uint16 connMax,
                                                 uint16 connSlaveLatency, uint16 connTimeout);

extern void ConnectableSetDeviceStatus(uint8_t status);
extern void ConnectableProcessGATTMsg(gattMsgEvent_t *pMsg);
extern uint8 ConnectableTxData(uint16_t connHandle, const uint8 * data, uint8 dataLength);
extern void ConnectableTerminateConnection(uint16_t connHandle);


#endif /* CONNECTABLE_H_ */
/** @}*/
