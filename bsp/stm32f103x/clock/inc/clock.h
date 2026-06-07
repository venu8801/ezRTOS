/**
 *
 * File: clock.h
 * Author: Venu Gopal Atchyutanna
 * Email: venu.ark.prasad@gmail.com
 *
 */
#include <stdint.h>

typedef uint32_t __u32
#define RCC_REG_BASE 0x40021000
#define RCC_REG_END 0x400213FF

#define RCC_CR RCC_REG_BASE + 0x00


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
