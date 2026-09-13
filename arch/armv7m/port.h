/**
 * File: port.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for ARMv7-M port definitions.
 */

/**
 * 
 */

#ifndef __SYSTICK_ARMV7M_H__
#define __SYSTICK_ARMV7M_H__
#include <stdint.h>

typedef uint32_t __u32;
typedef uint8_t __u8;
/* register address for System Control Space on ARM Cortex M3 */
 /* Systick control and status register */
#define SYST_CSR_REG                 0xE000E010
#define SYST_RVR_REG                 0xE000E014 /* Systick reload value register */
#define SYST_CVR_REG                 0xE000E018
#define SYST_CALIB_REG               0xE000E01C
#define CPUID_REG_BASE               0xE000ED00
#define ICSR_REG_BASE                0xE000ED04 /* Interrupt control & state register */
#define VTOR_REG_BASE                0xE000ED08
#define AIRCR_REG_BASE               0xE000ED0C
#define CCR_REG_BASE                 0xE000ED14
#define SYSTICK_RELOAD_1MS_8MHZ      7999U
#define CPU_ID_REGISTER               0xE000ED00

typedef struct systick {
  __u32 SYST_CSR;
  __u32 SYST_RVR;
  __u32 SYST_CVR;
  __u32 SYST_CALIB;
} __attribute__((packed)) systick_reg_t;


typedef struct icsr_reg {
    __u32 VECT_ACTIVE:9;   /*bits 0 to 8*/
    __u32 RESERVED0:2;     /*bit 9 & 10*/
    __u32 RETTOBASE1:1;    /* bit[11]*/
    __u32 VECT_PENDING:9;  /* bit 12 to 20*/
    __u32 RESERVED1:1;     /* bit[21]*/
    __u32 ISR_PENDING:1;   /* bit[22]*/
    __u32 ISR_PREEMPT:1;   /* bit[23]*/
    __u32 RESERVERD2:1;    /* bit[24]*/
    __u32 PENDST_CLR:1;    /*bit[25]*/
    __u32 PENDST_SET:1;    /*bit[26]*/ 
    __u32 PENDSV_CLR:1;    /*bit[27]*/
    __u32 PENDSV_SET:1;    /*bit[28]*/
    __u32 RESERVED3:2;     /*bit 29 & 30*/
    __u32 NMI_PENDSET:1;   /*bit[31]*/
} icsr_reg_t;

#define SYSTICK_ENABLE() (*(volatile uint32_t *)SYST_CSR_REG |= 1U)

#define SYSTICK_ENABLE_INTERRUPT() (*(volatile uint32_t *)SYST_CSR_REG |= (1U << 0x1))

#define SYSTICK_SET_CLK_INTERNAL() (*(volatile uint32_t *)SYST_CSR_REG |= (1U << 0x2))

#define SYSTICK_SET_CLK_EXTERNAL() (*(volatile uint32_t *)SYST_CSR_REG &= ~(1U << 0x2))

#define SYSTICK_SET_RVR(x) (*(volatile uint32_t *)SYST_RVR_REG = x)

#define GET_PROCESSOR_REVISION        (*((volatile uint32_t *)CPU_ID_REGISTER) & ~(0xFFFFFFF0))
#define GET_PROCESSOR_PARTNO          (*((volatile uint32_t *)CPU_ID_REGISTER) & ~(0xFFFF000F)) >> 4
#define GET_PROCESSOR_VARIANT         (*((volatile uint32_t *)CPU_ID_REGISTER) & ~(0xFF0FFFFF)) >> 20
#define GET_PROCESSOR_IMPLEMENTER     (*((volatile uint32_t *)CPU_ID_REGISTER) & ~(0x00FFFFFF)) >> 24

#define TRIGGER_PENDSV()               ((icsr_reg_t *)ICSR_REG_BASE)->PENDSV_SET |= 1U
#define TRIGGER_PENDSV_CLR()           ((icsr_reg_t *)ICSR_REG_BASE)->PENDSV_CLR |= 1U

static inline void systick_init() {
  // load the value
  SYSTICK_SET_RVR(SYSTICK_RELOAD_1MS_8MHZ);

  (*(uint32_t *)SYST_CVR_REG) = 0;
  // set the internal clock as clock source
  SYSTICK_SET_CLK_INTERNAL();
  SYSTICK_ENABLE_INTERRUPT();

  // enable the systick register
  SYSTICK_ENABLE();
  return;
}

#endif // __SYSTICK_ARMV7M_H__
