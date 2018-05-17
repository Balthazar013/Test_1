/**************************************************************************************
* @file    buildversion.h
* @brief : definition of BLE software version and supplier software version
*          required by the  flash bootloader FBL and DTCs version messages
* $Id:
* @author : M. Ramadan
 ***************************************************************************************
 * @copyright
 *
 * 
 ***************************************************************************************/
#ifndef BUILDVERSION_H
#define BUILDVERSION_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef TARGET_PAD 

/* PAD */
#define BLE_FW_VERSION               {'X','4','3','0'}
#define BLE_FW_SUPP_VERSION          {'X','4','3','0','-','0','0','2'}

#else

/* ORU */
#define BLE_FW_VERSION               {'X','4','3','0'}
#define BLE_FW_SUPP_VERSION          {'X','4','3','0','-','0','0','2'}

#endif

#pragma location="SW_VERSION"
const uint8 _SupVersion[8] = BLE_FW_SUPP_VERSION;
#pragma required=_SupVersion

#pragma location="SW_VERSION"
const uint8 _SwVersion[4]  = BLE_FW_VERSION;
#pragma required=_SwVersion


#ifdef __cplusplus
}
#endif

#endif /* BUILDVERSION_H */
