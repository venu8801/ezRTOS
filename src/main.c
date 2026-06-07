
/**
 * File: main.c
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Application entry point for ezRTOS startup.
 */

#include <stdio.h>
#include <stdbool.h>
#include <ukernel.h>
#include <ezlog.h>
#include <ez_syscalls.h>
#include <port.h>
extern uint32_t g_systicks_counter;

int main(void) {
    ez_system_init();
    ez_kernel_init();
    systick_init();
    volatile int i = 0;
    while(true) {
        ez_log("idiling %s()..here ...systick: %u", __func__, g_systicks_counter);
        __usleep(10000);
        i += 1;
    }
    
    return 0; // should never come here ideally
}

