/**
 * File: ukernel.h - Micro kernel header for ez RTOS
 * Author: Venu Gopal Atchyutanna
 * Email: venu.ark.prasad@gmail.com
 */


#ifndef _U_SYSCALLS_H_
#define  _U_SYSCALLS_H_
#include <stdint.h>
#include <ezlog.h>

#define ez_log(fmt, ...) __printk(fmt, ##__VA_ARGS__);

void *kmalloc(uint32_t alloc_size);

void __usleep(unsigned long);
#endif // _U_SYSCALLS_H_
