/**
 *  File: clock_driver.c
 *  Copyright (c) 2026 Venu Gopal A. All rights reserved.
 *  Author: Venu Gopal A
 *  Email: venu.ark.prasad@gmail.com
 *
 *  @brief: Clock driver routines for STM32 to control RCC register
 *  and provide clocks for different peripherals on APB and AHB buses.
 *
 *
 */

#include <clock.h>

rcc_reg_t *rcc_reg = (rcc_reg_t *) RCC_REG_BASE;
/**
 * Enables clock for a particular port ID
 *
 */
int8_t clock_apb2_io_port_enable(io_port_id_t p_id, bool __attribute__((unused)) enable)
{
    int8_t ret = 0;
    switch (p_id) {
    case IO_PORT_A:
        rcc_reg->RCC_APB2ENR |= 1U << 2;
        break;
    case IO_PORT_B:
        rcc_reg->RCC_APB2ENR |= 1U << 3;
        break;
    case IO_PORT_C:
        rcc_reg->RCC_APB2ENR |= 1U << 4;
        break;
    case IO_PORT_D:
        rcc_reg->RCC_APB2ENR |= 1U << 5;
        break;
    case IO_PORT_E:
        rcc_reg->RCC_APB2ENR |= 1U << 6;
        break;
    default:
        ret = -1;
    }
    return ret;
}

int8_t clock_apb2_peripheral_enable(peripheral_id_t prphrl_id) {
    int8_t ret = 0;
    switch (prphrl_id) {
        case P_USART_1:
            rcc_reg->RCC_APB2ENR |= 1U << 14;
            break;
        case P_TIMER_1:
            rcc_reg->RCC_APB2ENR |= 1U << 11;
            break;
        case P_SPI_1:
            rcc_reg->RCC_APB2ENR |= 1U << 12;
            break;
        case P_ADC_1:
            rcc_reg->RCC_APB2ENR |= 1U << 9;
            break;
        case P_ADC_2:
            rcc_reg->RCC_APB2ENR |= 1U << 10;
            break;
        default:
            ret = -1;
    }
    return ret;
}
