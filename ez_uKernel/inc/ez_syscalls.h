/**
 * File: ez_syscalls.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for ezRTOS system call APIs.
 */


#ifndef _U_SYSCALLS_H_
#define  _U_SYSCALLS_H_
#include <stdint.h>
#include <ezlog.h>

#define ez_log(fmt, ...) __printk(fmt, ##__VA_ARGS__);

void *kmalloc(uint32_t alloc_size);

void __usleep(unsigned long);
#endif // _U_SYSCALLS_H_
