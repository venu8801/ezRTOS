/**
 * File: ez_kernel_main.c
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 *
 * @brief: This file contains the entry points of
 * MCUs system initializations and kernel initializations
 * these further drive into the controller specific implementations
 * inside the bsp layer.
 */
#include <ukernel.h>
#include <ez_syscalls.h>
#include <uart.h>
#include <stddef.h>
#include <ez_syscalls.h>

char *get_cpu_name(uint16_t processor_Id) {
    switch(processor_Id) {
        case 0xC23:
            return "Cortex-M3";
        default:
            return "Unknown";
    }
}

char *get_cpu_implementer(uint16_t implementer_id) {
    switch (implementer_id) {
        case 0x41:
            return "ARM";
        default:
            return "Unkown";
    }
}

void ez_kernel_init(void)
{
    ez_log("-----------EZ KERNEL INIT ---------------");
    ez_log("Starting EZ Kernel")
    ez_log("CPU Revision        : %x", GET_PROCESSOR_REVISION);
    ez_log("CPU                 : %s", get_cpu_name(GET_PROCESSOR_PARTNO));
    ez_log("CPU Variant         : %x", GET_PROCESSOR_VARIANT);
    ez_log("CPU Implementer     : %s", get_cpu_implementer(GET_PROCESSOR_IMPLEMENTER));
    ez_log("system arch: %d-bit", sizeof(char *) * 8);
    // not yet implemented
    // ez_queue_init();
    // ez_task_init();
    ez_mem_init();
    uint8_t *ptr = kmalloc(3);
    if (ptr != NULL) {
        ez_log(" kmalloc successful allocated %d  bytes with addr %p", 3, ptr);
    }
    return;
}

void ez_system_init(void)
{
    /**  initialize clocks for peripherals
     * present on MCU or increase the
     * CPU clock to optimal value here
     * should go to bsp specific implementation
     */
    __uart_init();
    __uart_start(LOW_BR, USART1);
    ez_log("-----------EZ SYSTEM INIT CALLED ---------------");
    return;
}
