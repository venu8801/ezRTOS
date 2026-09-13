/**
 * File: clock.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for STM32F103x clock register definitions.
 */
#ifndef __CLOCK_H__
#define __CLOCK_H__
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t __u32;
#define RCC_REG_BASE 0x40021000
#define RCC_REG_END 0x400213FF

typedef struct rcc_reg {
    __u32 RCC_CR;        // control register
    __u32 RCC_CFGR;      // configuration register
    __u32 RCC_CIR;       // control interrupt register
    __u32 RCC_APB2RSTR;  // APB2 peripheral reset register
    __u32  RCC_APB1RSTR; // APB1 peripheral reset register
    __u32 RCC_AHBENR;    // AHB peripheral clock enable register
    __u32 RCC_APB2ENR;   // APB2 peripheral clock enable register
    __u32 RCC_APB1ENR;   // APB1 peripheral clock enable register
    __u32 RCC_BDCR;      // Backup domain control register
    __u32 RCC_CSR;       // Control/Status register
    __u32 RCC_AHBRSTR;   // AHB periperal clock reset register
    __u32 RCC_CFGR2;     // clock configuration regiser 2 

} __attribute__((packed)) rcc_reg_t;


typedef enum io_port_id {
    IO_PORT_A,
    IO_PORT_B,
    IO_PORT_C,
    IO_PORT_D,
    IO_PORT_E
} io_port_id_t;

typedef enum peripheral_id {
    P_USART_1,
    P_USART_2,
    P_USART_3,
    P_USART_4,
    P_USART_5,
    P_SPI_1,
    P_SPI_2,
    P_TIMER_1,
    P_TIMER_2,
    P_ADC_1,
    P_ADC_2
} peripheral_id_t;

/* kernel exposed functions */
int8_t clock_apb2_io_port_enable(io_port_id_t p_id, bool enable);
int8_t clock_apb2_peripheral_enable(peripheral_id_t prphrl_id);
#endif // _CLOCK_H_
