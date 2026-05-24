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

void ez_kernel_init(void) {
    // not yet implemented
    // ez_queue_init();
    // ez_task_init();
    // ez_memory_init();
    uint8_t *ptr = kmalloc(3);
    return;
}

void ez_system_init(void) {
    /**  initialize clocks for peripherals
     * present on MCU or increase the 
     * CPU clock to optimal value here
     * should go to bsp specific implementation
     */
    return;
}
