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
 * $LastChangedDate: 2018-01-19 11:00:31 +0100 (Fr, 19 Jan 2018) $
 * $LastChangedBy: svn_integrationbot $
 * $Revision: 17299 $
 * $Id: typedefs.h 17299 2018-01-19 10:00:31Z svn_integrationbot $
 *
 */
#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#ifndef SPI_HAS_DATA
#define SPI_HAS_DATA 0xFAu
#endif


#ifndef BB_UINT32_MAX
#define BB_UINT32_MAX 0xFFFFFFFFU
#endif

#ifndef int8_t
typedef signed char int8_t;          /*!< Signed 8 bit integer*/
#endif

#ifndef uint8_t
typedef unsigned char uint8_t;       /*!< Unsigned 8 bit integer*/
#endif

#ifndef int16_t
typedef signed short int int16_t;    /*!< Signed 16 bit integer*/
#endif

#ifndef uint16_t
typedef unsigned short int uint16_t; /*!< Unsigned 16 bit integer*/
#endif

#ifndef int32_t
typedef signed long int int32_t;     /*!< Signed 32 bit integer*/
#endif

#ifndef uint32_t
typedef unsigned long int uint32_t;  /*!< Unsigned 32 bit integer */
#endif

typedef uint8_t (*BBGenericVoiduint8_tuint16_tCB_t)(uint8_t x, uint16_t y, const uint8_t * z);
typedef uint8_t (*BBCharCB_t)(void);
typedef uint8_t (*BBUCharUCharPtr_t)(uint8_t * x);
typedef uint8_t (*DataExchangeFnc)(const uint8_t * x, uint8_t y);
typedef void (*DataExchangeFncVoid)(const uint8_t * x, uint8_t y);
typedef uint8_t (*DataExchangeNConstFnc)(uint8_t * x, uint8_t y);
typedef void (*BBGenericVoidVoidCB_t)(void);
typedef void (*BBGenericVoiduint8_tCB_t)(uint8_t x);
typedef void (*BBGenericVoiduint16_tCB_t)(uint16_t x);
typedef void (*BBGenericVoiduint32_tCB_t)(uint32_t x);
typedef void (*BBGenericVoiduint16uin8_tCB_t)(uint16_t x, uint8_t y);
typedef void (*BBGenericCB_t)(void);
typedef uint8_t (*BBGenericu8_u8_tCB_t)(uint8_t x);
typedef uint8_t (*BBGenericu8_u16_tCB_t)(uint16_t x);
typedef uint16_t (*BBGenericVoid_u16_tCB_t)(void);
typedef uint32_t (*DataExchangeFnc3232)(uint32_t data);
typedef uint32_t (*DataExchangeFncGet32)(void);
typedef void (*fpHandleReceivedFrame_t)(uint16_t x, uint8_t * y, uint8_t z);

#define BB_SUCCESS 0u

#ifndef TRUE
#define TRUE 1u
#endif

#ifndef FALSE
#define FALSE 0u
#endif

#ifndef NILL
#define NILL 0u
#endif

#endif /* TYPEDEFS_H_ */

/** @}*/

