/**
 * File: uart.c
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: UART driver implementation for STM32F103x.
 */

#include <uart.h>
#include <clock.h>
#include <stdbool.h>
#include <gpio.h>

#define USART_BRR_8MHZ_9600   0x341U
#define USART_BRR_8MHZ_115200 0x45U

void __uart_init(void)
{
    int8_t ret;

    clock_apb2_io_port_enable(IO_PORT_A, true);

    gpio_attr_t request = {
        .port_id = GPIO_PORT_A,
        .pin_id = GPIO_PIN_9,
        .config = GPIO_AF_PUSH_PULL,
        .mode = GPIO_MODE_OUTPUT_10MHZ,
        .pull = GPIO_PULL_DOWN,
    };

    ret = gpio_config_reg(request);
    if (ret != 0) {
        return;
    }

    // enable clock for USART1
    clock_apb2_peripheral_enable(P_USART_1);
}

int8_t __uart_start(usart_brate_t brate, usart_reg_t *reg_ptr)
{
    switch (brate) {
    case STANDARD_BR:
        reg_ptr->USART_BRR = USART_BRR_8MHZ_115200;
        break;
    case LOW_BR:
        /** setting 9600 as standard
         * asssuming peripheral clock to
         * be 8Mhz*/
        reg_ptr->USART_BRR = USART_BRR_8MHZ_9600;
        // sets 9600 bps in BRR
        break;
    default:
        return -1;
    }

    // set usart enable & transmit enable to true here
    transmit_enable(reg_ptr);
    usart_enable(reg_ptr);
    return 0;
}

void transmit_enable(usart_reg_t *reg_ptr) {
    ((reg_ptr->USART_CR1) |= TE_BIT_MSK);
    return;
}

void usart_enable(usart_reg_t *reg_ptr) {
    ((reg_ptr->USART_CR1) |= USARTEN_BIT_MSK);
    return;
}

bool transmit_complete(usart_reg_t *reg_ptr) {
    return (((reg_ptr->USART_SR) &
            (TC_BIT_MSK)) ? true : false);
}

bool transmit_empty(usart_reg_t * reg_ptr) {
    return (((reg_ptr->USART_SR) &
            (TXE_BIT_MSK)) ? true : false);
}

void __usart_put_char(char input, usart_reg_t * reg_ptr) {
    if (input == '\n') {
        while (!transmit_empty(reg_ptr)) {
        }
        // add carriage return for proper serial printing
        reg_ptr->USART_DR = '\r';
    }

    while (!transmit_empty(reg_ptr)) {
    }

    reg_ptr->USART_DR = (uint8_t)input;
    return;
}
