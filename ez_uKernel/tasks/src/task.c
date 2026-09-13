/**
 * File: task.c
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Task scheduler and task management implementation.
 */

#include <task.h>
#include <ez_syscalls.h>
#include <stdbool.h>
#include <stdio.h>

volatile uint64_t g_systicks_counter;
ez_task_t g_task_list[MAX_TASK_LIST_SIZE];

static struct ez_list_attr {
    uint8_t end;
} g_list_attr;

bool is_list_full() {
    if (g_list_attr.end == MAX_TASK_LIST_SIZE - 1)
        return true;

    return false;
}

void ez_systick_hanlder(void) {
  //ez_log("systick handler triggered: %u", g_systicks_counter);
  g_systicks_counter++;
  return;
}

void * idle_task_handler(void *args) {
  int i = 0; 
  while (true) {
    i++;
  }
}

int32_t register_task(ez_task_hdlr_t task_to_add , taskHandlerAttr task_attr) {
    int32_t ret = TASK_INIT_FAIL;
    if (is_list_full()) {
        ez_log("Max capacity reached cannot add more tasks\n");
        goto exit;
    }

    ez_task_t current_task = {NULL,
                            task_attr,
                            TASK_STATE_WAITING,
                            task_to_add
                            };
    g_task_list[g_list_attr.end++] = current_task;
    ez_log("task registration successful with priority: %d", task_attr.priority);
    ret = TASK_INIT_SUCCESS;
exit:
    return ret;
}


