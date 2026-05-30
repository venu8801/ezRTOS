/**
 * File: uart.h
 * 
 */


#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>


typedef uint32_t __u32;
/**
 * Memory map from stm32f103x technical reference manual
 * 0x4000 5000 - 0x4000 53FF - UART5
 * 0x4000 4C00 - 0x4000 4FFF - UART4
 * 0x4000 4800 - 0x4000 4BFF - USART3
 * 0x4000 4400 - 0x4000 47FF - USART2
 */
#define USART1_BASE 0x40013800
#define USART5_BASE 0x40005000
#define UART4_BASE 0x40004C00
#define USART3_BASE 0x40004800
#define USART2_BASE 0x40004400

/**
 * use this packed structure to represent
 * a USART GPIO Register on Stm32
 */
typedef struct usart_reg {
    __u32 USART_SR;  // status register
    __u32 USART_DR;  // data register 0:8 bits are 1 byte UART out
    __u32 USART_BRR; // Baud Rate Generator register
    __u32 USART_CR1;  // control 1
    __u32 USART_CR2;  // control 2
    __u32 USART_CR3;  // control 3
    __u32 USART_GTPR;
} __attribute__((packed)) usart_reg_t;

/**
 * Fractional baud rate generation
 * The baud rate for the receiver and transmitter (Rx and Tx) are both set to the same value as
 *  programmed in the Mantissa and Fraction values of USARTDIV.
 * Tx/ Rx baud = fCK / (16*USARTDIV)
 * legend: fCK - Input clock to the peripheral (PCLK1 for USART2, 3, 4, 5 or PCLK2 for USART1)
 */

typedef enum {
    STANDARD_BR = 0, // 115200
    LOW_BR,          // 9600
} usart_brate_t;

#define TC_BIT_MSK ((0x1 << 6)) // bit 6 is Transmission complete
#define TXE_BIT_MSK ((0x1 << 7)) // bit 6 is Transmission empty

#define USART1 ((usart_reg_t *)USART1_BASE)
#define USART2 ((usart_reg_t *)USART2_BASE)
#define USART3 ((usart_reg_t *)USART3_BASE)
#define UART4  ((usart_reg_t *)UART4_BASE)
#define UART5  ((usart_reg_t *)USART5_BASE)

/**
 * uart driver level routine function declarations
 */

void __uart_init(void);

int8_t __uart_start(usart_brate_t brate, usart_reg_t *reg_ptr);

void __usart_put_char(char input, usart_reg_t * reg_ptr);









#endif // __UART_H__


