/**
 * \addtogroup Typedefs
 * @{
 *
 * @file 	typedefs.h
 * @author	p344575
 * @brief 	makes it possible to use standard "stdint" type definitions
 * @copyright &copy; 2016 Porsche Engineering Services GmbH
 *
 *
 * @internal
 * $LastChangedDate: 2016-03-22 17:51:44 +0100 (Di, 22 Mrz 2016) $
 * $LastChangedBy: p344575 $
 * $Revision: 8978 $
 * $Id: typedefs.h 8978 2016-03-22 16:51:44Z p344575 $
 *
 */
#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include <stdint.h>


typedef uint8_t (*BBGenericVoiduint8_tuint16_tCB_t)(uint8_t x, uint16_t y, const uint8_t * z);
typedef uint8_t (*BBCharCB_t)(void);
typedef uint8_t (*BBUCharUCharPtr_t)(uint8_t * x, uint8_t y);
typedef uint8_t (*DataExchangeFnc)(const uint8_t * x, uint8_t y);
typedef uint8_t (*DataExchangeFnc2)(const uint8_t * x, uint8_t y);
typedef uint8_t (*DataExchangeNConstFnc)(uint8_t * x, uint8_t y);
typedef void (*BBGenericVoidVoidCB_t)(void);
typedef void (*BBGenericVoiduint8_tCB_t)(uint8_t x);
typedef void (*BBGenericVoiduint16_tCB_t)(uint16_t x);
typedef void (*BBGenericCB_t)(void);
//typedef uint8_t (*DataExchangeFnc32)(uint32_t data);
typedef uint8_t (*BBGenericu8_u8_tCB_t)(uint8_t x);
typedef uint8_t (*BBGenericu8_u16_tCB_t)(uint16_t x);
typedef uint16_t (*BBGenericVoid_u16_tCB_t)(void);
typedef uint32_t (*DataExchangeFnc3232)(uint32_t data);
typedef uint32_t (*DataExchangeFncGet32)(void);


#define BB_SUCCESS 0
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#endif /* TYPEDEFS_H_ */

/** @}*/

