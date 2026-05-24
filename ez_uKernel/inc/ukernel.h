/**
 * File: ukernel.h - Micro kernel header for ez RTOS
 * Author: Venu Gopal Atchyutanna
 * Email: venu.ark.prasad@gmail.com
 */


#ifndef _U_KERNEL_H_
#define  _U_KERNEL_H_
#include <stdint.h>


void ez_kernel_init(void);

void ez_system_init(void);

void *kmalloc(uint32_t alloc_size);


#endif // _U_KERNEL_H_


