
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
#include <task.h>

void sample_task(void *args) {
    int i = 0;
    while(1) {
        ez_log("waiting here ....");
        i++;
    }
}


int main(void) {
    ez_system_init();
    ez_kernel_init();
    systick_init();
    volatile int i = 0;
    taskHandlerAttr task_attr = {3};
    int32_t ret = TASK_INIT_SUCCESS;
    if ((ret = register_task(sample_task, task_attr)), ret != TASK_INIT_SUCCESS) {
        ez_log("creating a task failed with error %d", ret);
    }
    //ez_scheduler_init();
    while(true) {
        ez_log("idiling %s()..here ...systick: %u", __func__, (uint32_t)g_systicks_counter);
        __usleep(1000);
        i += 1;
    }

    return 0; // should never come here ideally
}
