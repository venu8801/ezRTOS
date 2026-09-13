/**
 * File: gpio.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for STM32F103x GPIO register definitions.
 */
#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t __u32;

/* ------------------------------------------------------------------------------ */
/*                           APB2 PERIPHERAL MEMORY MAP GPIO                      */
/* ------------------------------------------------------------------------------ */
/* 0x4001 0800 - 0x4001 0BFF: GPIO Port A */
/* 0x4001 0C00 - 0x4001 0FFF: GPIO Port B */
/* 0x4001 1000 - 0x4001 13FF: GPIO Port C */
/* 0x4001 1400 - 0x4001 17FF: GPIO Port D */
/* 0x4001 1800 - 0x4001 1BFF: GPIO Port E */
/* 0x4001 1C00 - 0x4001 1FFF: GPIO Port F */
/* 0x4001 2000 - 0x4001 23FF: GPIO Port G */
/* 0x4001 5800 - 0x4001 7FFF: Reserved */

#define GPIO_REG_BASE_PORT_A 0x40010800
#define GPIO_REG_BASE_PORT_B 0x40010C00
#define GPIO_REG_BASE_PORT_C 0x40011000
#define GPIO_REG_BASE_PORT_D 0x40011400
#define GPIO_REG_BASE_PORT_E 0x40011800
#define GPIO_REG_BASE_PORT_F 0x40011C00
#define GPIO_REG_BASE_PORT_G 0x40012000
#define GPIO_RESERVED        0x40015800

typedef struct gpio_reg {
    volatile __u32 CFG_L;
    volatile __u32 CFG_H;
    volatile __u32 PRT_IDR;
    volatile __u32 PRT_ODR;
    volatile __u32 PRT_BSRR;
    volatile __u32 PRT_BRR;
    volatile __u32 PRT_CFG_LCK;
} gpio_reg_base_t;

typedef enum gpio_port {
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
    GPIO_PORT_G,
} gpio_port_t;

typedef enum gpio_config {
    GPIO_ANALOG = 0,
    GPIO_FLOATING = 1,
    GPIO_INPUT_PULL = 2,

    GPIO_PUSH_PULL = 0,
    GPIO_OPEN_DRAIN = 1,
    GPIO_AF_PUSH_PULL = 2,
    GPIO_AF_OPEN_DRAIN = 3,
} gpio_config_t;

typedef enum gpio_mode {
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT_10MHZ = 1,
    GPIO_MODE_OUTPUT_2MHZ = 2,
    GPIO_MODE_OUTPUT_50MHZ = 3,
    GPIO_MODE_OUTPUT0 = GPIO_MODE_OUTPUT_10MHZ,
    GPIO_MODE_OUTPUT1 = GPIO_MODE_OUTPUT_2MHZ,
    GPIO_MODE_OUTPUT2 = GPIO_MODE_OUTPUT_50MHZ,
    GPIO_MODE_IN = GPIO_MODE_INPUT,
} gpio_mode_t;

typedef enum gpio_pin {
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15,
} gpio_pin_t;

typedef enum gpio_pull {
    GPIO_PULL_DOWN,
    GPIO_PULL_UP,
} gpio_pull_t;

typedef struct gpio_attr {
    gpio_port_t port_id;
    gpio_pin_t pin_id;
    gpio_config_t config;
    gpio_mode_t mode;
    gpio_pull_t pull;
} gpio_attr_t;

int8_t gpio_config_reg(gpio_attr_t req);

#endif /* GPIO_H */
