/**
 * File: port.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for ARMv7-M port definitions.
 */



#ifndef __SYSTICK_ARMV7M_H__
#define __SYSTICK_ARMV7M_H__
#include <stdint.h>

typedef volatile uint32_t __u32_v;
/* register address for System Control Space on ARM Cortex M3 */
#define SYST_CSR_REG 0xE000E010 /* Systick control and status register */
#define SYST_RVR_REG 0xE000E014 /* Systick reload value register */
#define SYST_CVR_REG 0xE000E018
#define SYST_CALIB_REG 0xE000E01C

typedef struct systick {
  __u32_v SYST_CSR;
  __u32_v SYST_RVR;
  __u32_v SYST_CVR;
  __u32_v SYST_CALIB;
} __attribute__((packed)) systick_reg_t;

systick_reg_t * syst_scs_ptr = (systick_reg_t *) SYST_CSR_REG;

#define SYSTICK_ENABLE() (*(volatile uint32_t *)SYST_CSR_REG |= 1U)

#define SYSTICK_ENABLE_INTERRUPT() (*(volatile uint32_t *)SYST_CSR_REG |= (1U << 0x1))

#define SYSTICK_SET_CLK_INTERNAL() (*(volatile uint32_t *)SYST_CSR_REG |= (1U << 0x2))

#define SYSTICK_SET_CLK_EXTERNAL() (*(volatile uint32_t *)SYST_CSR_REG &= ~(1U << 0x2))

#define SYSTICK_SET_RVR(x) (*(volatile uint32_t *)SYST_RVR_REG = x)

static inline void systick_init() {
  // load the value
  SYSTICK_SET_RVR(71999);

  (*(uint32_t *)SYST_CVR_REG) = 0;
  // set the internal clock as clock source
  SYSTICK_SET_CLK_INTERNAL();
  SYSTICK_ENABLE_INTERRUPT();

  // enable the systick register
  SYSTICK_ENABLE();
  ez_log("syst_csr :%p ", syst_scs_ptr->SYST_CSR);
  ez_log("syst_rvr :%p ", syst_scs_ptr->SYST_RVR);
  ez_log("syst_cvr :%p ", syst_scs_ptr->SYST_CVR);
  return;
}

#endif
