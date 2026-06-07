/**
 * File: syscall.c
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Generic system call implementations for C Run-Time
 * environment a.k.a crt0 for ezRTOS.
 */
#include <stdint.h>
#include <stddef.h>
#include <ukernel_memory.h>
#include <ez_syscalls.h>

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

void ez_svc_handler(void) {
    ez_log("Svc handler called");
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
    volatile uint64_t i;
    for (i = 0; i < ((uint64_t)msec * 1000ULL); i++) {
        __asm volatile ("nop");
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
