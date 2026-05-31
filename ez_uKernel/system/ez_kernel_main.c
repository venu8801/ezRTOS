/**
 * File: ez_kernel_main.c
 * Author: Venu Gopal Atchyutanna @venu8801
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

void ez_kernel_init(void)
{
    ez_log("-----------EZ KERNEL INIT CALLED ---------------");
    ez_log("system arch details: \n pointer size: %x", sizeof(char *));
    ez_log("size of int %x", sizeof(int));
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
    __uart_start(LOW_BR, USART1);
    ez_log("-----------EZ SYSTEM INIT CALLED ---------------");
    return;
}
