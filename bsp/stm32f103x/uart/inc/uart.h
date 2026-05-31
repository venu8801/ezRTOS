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

#define TC_BIT_MSK ((0x1 << 6))  // bit 6 is Transmission complete
#define TXE_BIT_MSK ((0x1 << 7)) // bit 6 is Transmission empty
#define TE_BIT_MSK (1U << 3)     // bit 3 for Transmission enable
#define USARTEN_BIT_MSK (1U << 13)    // bit 13 for USART enable
#define USART1 ((usart_reg_t *)USART1_BASE)
#define USART2 ((usart_reg_t *)USART2_BASE)
#define USART3 ((usart_reg_t *)USART3_BASE)
#define UART4  ((usart_reg_t *)UART4_BASE)
#define UART5  ((usart_reg_t *)USART5_BASE)

/**
 * uart driver level routine function declarations
 */

void __uart_init(void);

void transmit_enable(usart_reg_t *reg_ptr);

void usart_enable(usart_reg_t *reg_ptr);

/*
 * STM32F103 USART Baud Rate Reference
 *
 * ---------------------------------------------------------------
 * Baud Rate | fPCLK = 36 MHz          | fPCLK = 72 MHz
 *           | BRR Value | Actual Baud | BRR Value | Actual Baud
 * ---------------------------------------------------------------
 * 2.4 Kbps  | 937.5     | 2400.0      | 1875      | 2400.0
 * 9.6 Kbps  | 234.375   | 9600.0      | 468.75    | 9600.0
 * 19.2 Kbps | 117.1875  | 19200.0     | 234.375   | 19200.0
 * 57.6 Kbps | 39.0625   | 57600.0     | 78.125    | 57600.0
 * 115.2 Kbps| 19.53125  | 115384.6    | 39.0625   | 115200.0
 * 230.4 Kbps| 9.765625  | 230769.2    | 19.53125  | 230769.2
 * 460.8 Kbps| 4.8828125 | 461538.5    | 9.765625  | 461538.5
 * 921.6 Kbps| 2.4414062 | 923076.9    | 4.8828125 | 923076.9
 * 2250 Kbps | 1.0       | 2250000.0   | 2.0       | 2250000.0
 * 4500 Kbps | N/A       | N/A         | 1.0       | 4500000.0
 * ---------------------------------------------------------------
 *
 * USARTDIV = fPCLK / (16 * BaudRate)
 *
 * BRR Register Encoding:
 * ----------------------
 * BRR[15:4] = Mantissa
 * BRR[3:0]  = Fraction
 *
 * Example:
 * --------
 * fPCLK = 72 MHz
 * Baud  = 9600
 *
 * USARTDIV = 72,000,000 / (16 * 9600)
 *           = 468.75
 *
 * Mantissa = 468 = 0x1D4
 * Fraction = 0.75 * 16 = 12 = 0xC
 *
 * BRR = (0x1D4 << 4) | 0xC
 *     = 0x1D4C
 */
int8_t __uart_start(usart_brate_t brate, usart_reg_t *reg_ptr);

void __usart_put_char(char input, usart_reg_t * reg_ptr);









#endif // __UART_H__


