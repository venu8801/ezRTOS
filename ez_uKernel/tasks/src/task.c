/**
 * File: task.c
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Task scheduler and task management implementation.
 */

#include <task.h>
#include <stdint.h>
#include <ez_syscalls.h>
uint32_t g_systicks_counter ;

void ez_systick_hanlder(void) {
  ez_log("systick handler triggered: %u", g_systicks_counter);
  g_systicks_counter++;
  return;
}
