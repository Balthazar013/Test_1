/*----------------------------------------------------------------------------
** Project Name:
** #Archive: LINFlexD_CFG.H #
** #Author: Muneer Ramadan #
** #Date: 2016-08-10#
** (c) Copyright 2016, Bombardier Primove GmbH
**----------------------------------------------------------------------------
** #Revision: #
**----------------------------------------------------------------------------
** Target system: Freescale MPC5744P
** Compiler:GHS
** Description:
**
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    -------------------------------------
** MuRa         Muneer Ramadan           
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log: #
**--------------------------------------------------------------------------*/

#ifndef _LINFLEXD_CFG_H_
#define _LINFLEXD_CFG_H_

/******************************************************************************
*                                   INCLUDES                                  *
*******************************************************************************/
#include <MPC5744P.h>

/******************************************************************************
*                                   DEFINES                                   *
*******************************************************************************/

/* LIN Control Register 1 */
#define LINFLEXD_LINCR1_INIT_MODE                   (uint32)0x00000081   /* Initialization Mode Request */
#define LINFLEXD_LINCR1_NORMAL_MODE                 (uint32)0x00000080   /* Normal Mode Request */
#define LINFLEXD_LINCR1_LOOPBACK                    (uint32)0x000000A0   /* Loop back mode*/

/* LIN Status Register */   
#define LINFLEXD_LINSR_LINS_MASK                    (uint32)0x0000F000   /* LIN state mask*/
#define LINFLEXD_LINSR_LINS_INIT_MODE               (uint32)0x00001000   /* INIT mode is entered */

/* UART Mode Control Register */
#define LINFLEXD_UARTCR_UART_MODE                   (uint32)0x00000001   /* UART Mode */
#define LINFLEXD_UARTCR_UART_8N1_TXRX_FIFO          (uint32)0x00000333   /* UART Mode, 8bit frame, No parity, 1 stopbit, Tx/RX enabled, TX/RX FIFO mode */

/* Baud Frequency  = HALFSYS_CLK = 100MHz    */
/* LIN Integer/Fractional Baud Rate Register */
//#define LINFLEXD_LINIBRR_9600                       (uint32)651           /* 9599,692  = 100000000 / (16 * 651,0625)  */
//#define LINFLEXD_LINFBRR_9600                       (uint32)1

/* Baud Frequency  = HALFSYS_CLK = 100MHz     */
/* LIN Integer/Fractional Baud Rate Register */
//#define LINFLEXD_LINIBRR_115200                     (uint32)54           /* 115207,373 = 100000000 / (16 * 54,25)  */
//#define LINFLEXD_LINFBRR_115200                     (uint32)4

/* Baud Frequency  = HALFSYS_CLK = 100MHz    */
/* LIN Integer/Fractional Baud Rate Register */
//#define LINFLEXD_LINIBRR_MAX                        (uint32)13           /* 460829,49 = 100000000 / (16 * 13,5625)   */
//#define LINFLEXD_LINFBRR_MAX                        (uint32)9

/* Baud Frequency  = HALFSYS_CLK = 80MHz     */
/* LIN Integer/Fractional Baud Rate Register */
//#define LINFLEXD_LINIBRR_9600                       (uint32)520         /* 9600,384 = 80000000 / (16 * 520,8125)  */
//#define LINFLEXD_LINFBRR_9600                       (uint32)13

/* Baud Frequency  = HALFSYS_CLK = 80MHz     */
/* LIN Integer/Fractional Baud Rate Register */
//#define LINFLEXD_LINIBRR_115200                     (uint32)43          /* 115273,775 = 80000000 / (16 * 43,375)  */
//#define LINFLEXD_LINFBRR_115200                     (uint32)6

/* Baud Frequency  = HALFSYS_CLK = 80MHz     */
/* LIN Integer/Fractional Baud Rate Register */
//#define LINFLEXD_LINIBRR_230400                     (uint32)21          /* 230547,550 = 80000000 / (16 * 21,6875)  */
//#define LINFLEXD_LINFBRR_230400                     (uint32)11

/* Baud Frequency  = HALFSYS_CLK = 80MHz     */
/* LIN Integer/Fractional Baud Rate Register */
//#define LINFLEXD_LINIBRR_MAX                        (uint32)10          /* 459770,11 = 80000000 / (16 * 10,875)   */
//#define LINFLEXD_LINFBRR_MAX                        (uint32)14

/* Baud Frequency  = HALFSYS_CLK = 90MHz     */
/* LIN Integer/Fractional Baud Rate Register */
#define LINFLEXD_LINIBRR_9600                       (uint32)585         /* 9600 = 90000000 / (16 * 585,9375)  */
#define LINFLEXD_LINFBRR_9600                       (uint32)15

/* Baud Frequency  = HALFSYS_CLK = 90MHz     */
/* LIN Integer/Fractional Baud Rate Register */
#define LINFLEXD_LINIBRR_230400                     (uint32)24          /* 230179,028 = 90000000 / (16 * 24,4375)  */
#define LINFLEXD_LINFBRR_230400                     (uint32)7

/* DMA Tx Enable Register */
#define LINFLEXD_DMATXE_CH_ENABLED                  (uint32)0x0000FFFF   /* Enable DMA TX channel */

/* DMA Rx Enable Register */
#define LINFLEXD_DMARXE_CH_ENABLED                  (uint32)0x0000FFFF   /* Enable DMA RX channel */

/* LINFlexD  TX/RX FIFO address offset */
#define LINFLEXD_TX_BUFF_BDRL_OFFSET                3
#define LINFLEXD_RX_BUFF_BDRM_OFFSET                3


/* DMA TX/RX RAM addresses for LINFlexD/UART-Mode */
#define LINFLEXD_DMA_TX_BUF_SIZE            1024    /*buffer size in bytes*/
#define LINFLEXD_DMA_RX_BUF_SIZE            1024    /*buffer size in bytes*/


#endif
