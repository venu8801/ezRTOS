/**
 * File: ukernel.h - Micro kernel header for ez RTOS
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for ezRTOS kernel initialization APIs.
 */


#ifndef _U_KERNEL_H_
#define  _U_KERNEL_H_
#include <stdint.h>


void ez_kernel_init(void);

void ez_system_init(void);

void ez_mem_init(void);

#endif // _U_KERNEL_H_

