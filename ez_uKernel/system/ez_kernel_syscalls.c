/**
 * File: syscall.c
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Generic system call implementations for C Run-Time
 * environment a.k.a crt0 for ezRTOS.
 */
#include <stdint.h>
#include <stddef.h>
#include <ukernel_memory.h>
#include <ez_syscalls.h>

extern volatile uint64_t g_systicks_counter;

void _exit(int pid) {
    (void)pid;
    while (1) {
    }
}

void *kmalloc(uint32_t alloc_size) {
    if (alloc_size <= 0)
        return NULL;
    return __ez_mem_allocator(alloc_size);
}

void ez_svc_handler(uint32_t *svc_args) {
  unsigned int svc_number;
  /*
  * Stack contains:
  * r0, r1, r2, r3, r12, r14, the return address and xPSR
  * First argument (r0) is svc_args[0]
  */
  svc_number = ((char *)svc_args[6])[-2];
  ez_log("svc number: %d", svc_number);
  switch( svc_number )
  {
    case 1:
      break;
    case 2:
        break;
    case 3:
        // trigger pendSV
        //pend_sv_request();
    default:
        ez_log("unknown svc call\n");
        break;
  }
    return;
}

void * _sbrk(uint32_t memory) {
    extern uint8_t __ez_heap_end__; /* Symbol defined in the linker script */
    extern uint8_t _estack; /* Symbol defined in the linker script */
    extern uint32_t _Min_Stack_Size; /* Symbol defined in the linker script */
    static uint8_t *heap_ptr = NULL;

    if (heap_ptr == NULL) {
        heap_ptr = &__ez_heap_end__;
    }

    const uint32_t stack_limit = (uint32_t)&_estack - (uint32_t)&_Min_Stack_Size;
    uint8_t *prev_heap_ptr = heap_ptr;

    if ((uint32_t)(heap_ptr + memory) > stack_limit) {
        return NULL;
    }

    heap_ptr += memory;
    return prev_heap_ptr;
}

int _write(const char *ptr) {
    return 0;
}

void delay(void)
{
    volatile uint32_t i;

    for(i = 0; i < 1000000; i++)
    {
        __asm volatile ("nop");
    }
}


void __usleep(uint32_t msec)
{
    uint64_t start_tick = g_systicks_counter;

    while ((g_systicks_counter - start_tick) < msec) {
        __asm volatile ("wfi");
    }
}

int _close(int fd) {
    return 0;
}

int _lseek(int bytes_to_seek) {
    return 0;
}

int _read(char *user_buf) {
    return 0;
}
