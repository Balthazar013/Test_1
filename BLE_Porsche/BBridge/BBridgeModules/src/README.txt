Just internal annotations here:



 /***************************************************************************
     * Configure SPI to SLAVE TX complete
     */
    // Configure USART0 for Alternative 1 => Port P0 (PERCFG.U0CFG = 0).
    PERCFG = (PERCFG & ~PERCFG_U0CFG) | PERCFG_U0CFG_ALT1;
    PPRI &= ~PPRI_PRI0P0; // Give priority to USART 0 over Timer 1 for port 0 pins.
    P0SEL |= BIT5 | BIT4 | BIT3 | BIT2; // Set pins 2, 3, 4 and 5 as peripheral I/O.
 
    // Set USART to SPI mode and Slave mode.
    U0CSR = (U0CSR & ~U0CSR_MODE) | U0CSR_SLAVE;
    U0BAUD =  SPI_BAUD_M;
    U0GCR = (U0GCR & ~(U0GCR_BAUD_E | U0GCR_CPOL | U0GCR_CPHA)) | U0GCR_ORDER | SPI_BAUD_E;// MSB first

    //enable the interrupt USART0 TX: IEN2.UTX0IE
    IEN2 |= IEN2_UTX0IE; // Enable interrupt
    txBufferINDEX = 0;
    U0DBUF = txBufferINDEX;

    ...

MY INTERRUPT:

 #pragma vector = UTX0_VECTOR
__interrupt void uart_TX_ISR(void)
{
  IRCON2 = ~UTX0IF; // clear the interrupt flag the proper way
  P1_4 = 1; // so I can easily see the interrupt on a scope
  txBufferINDEX++; // will wrap, but that's ok.
  U0DBUF = txBufferINDEX; // just load the VALUE of the index
  P1_4 = 0; // so I can easily see the interrupt on a scope
}