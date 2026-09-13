/**
 * File: gpio_driver.c
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: GPIO driver implementation for STM32F103x.
 */

#include <gpio.h>
#include <stddef.h>

#define GPIO_PIN_COUNT             16U
#define GPIO_CFG_BITS_PER_PIN      4U
#define GPIO_CFG_PIN_MASK          0xFU
#define GPIO_CNF_SHIFT             2U
#define GPIO_PINS_PER_CFG_REGISTER 8U

static gpio_reg_base_t *gpio_get_port(gpio_port_t port_id)
{
    switch (port_id) {
    case GPIO_PORT_A:
        return (gpio_reg_base_t *)GPIO_REG_BASE_PORT_A;
    case GPIO_PORT_B:
        return (gpio_reg_base_t *)GPIO_REG_BASE_PORT_B;
    case GPIO_PORT_C:
        return (gpio_reg_base_t *)GPIO_REG_BASE_PORT_C;
    case GPIO_PORT_D:
        return (gpio_reg_base_t *)GPIO_REG_BASE_PORT_D;
    case GPIO_PORT_E:
        return (gpio_reg_base_t *)GPIO_REG_BASE_PORT_E;
    case GPIO_PORT_F:
        return (gpio_reg_base_t *)GPIO_REG_BASE_PORT_F;
    case GPIO_PORT_G:
        return (gpio_reg_base_t *)GPIO_REG_BASE_PORT_G;
    default:
        return NULL;
    }
}

static bool gpio_is_valid_config(gpio_mode_t mode, gpio_config_t config)
{
    if (mode == GPIO_MODE_INPUT) {
        return config != GPIO_AF_OPEN_DRAIN;
    }

    return config <= GPIO_AF_OPEN_DRAIN;
}

int8_t gpio_config_reg(gpio_attr_t req)
{
    gpio_reg_base_t *port = gpio_get_port(req.port_id);
    volatile __u32 *cfg_reg;
    __u32 cfg_value;
    __u32 cfg_shift;
    __u32 cfg_mask;
    __u32 pin_mask;
    __u32 pin_index;

    if (port == NULL) {
        return -1;
    }

    if (req.pin_id >= GPIO_PIN_COUNT) {
        return -2;
    }

    if (req.mode > GPIO_MODE_OUTPUT_50MHZ || !gpio_is_valid_config(req.mode, req.config)) {
        return -3;
    }

    pin_index = req.pin_id % GPIO_PINS_PER_CFG_REGISTER;
    cfg_shift = pin_index * GPIO_CFG_BITS_PER_PIN;
    cfg_mask = GPIO_CFG_PIN_MASK << cfg_shift;
    cfg_value = (((__u32)req.config << GPIO_CNF_SHIFT) | (__u32)req.mode) << cfg_shift;
    cfg_reg = (req.pin_id < GPIO_PINS_PER_CFG_REGISTER) ? &port->CFG_L : &port->CFG_H;

    *cfg_reg = (*cfg_reg & ~cfg_mask) | cfg_value;

    if (req.mode == GPIO_MODE_INPUT && req.config == GPIO_INPUT_PULL) {
        pin_mask = 1U << req.pin_id;

        if (req.pull == GPIO_PULL_UP) {
            port->PRT_ODR |= pin_mask;
        } else {
            port->PRT_ODR &= ~pin_mask;
        }
    }

    return 0;
}
