/**
 * File: task.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for task control block and task internals.
 */

#ifndef __EZ_TASK_H__
#define __EZ_TASK_H__
#include <stdint.h>

#define TASK_INIT_SUCCESS           0
#define TASK_INIT_FAIL              1

typedef enum task {
    TASK_STATE_RUNNING = 0,
    TASK_STATE_WAITING,
    TASK_STATE_READY,
    TASK_STATE_INVALID = 0xFFF,
} task_state_t;

typedef void (*ez_task_hdlr_t)(void *);

typedef struct task_handler_attributes {
    uint8_t priority;
} taskHandlerAttr;

typedef struct {
    void *pc;
    taskHandlerAttr task_attrs;
    task_state_t task_state;
    ez_task_hdlr_t task_hdlr;
} ez_task_t;

extern volatile uint64_t g_systicks_counter;

/* exposed functions for task creation and control */

int32_t register_task(ez_task_hdlr_t task_to_add , taskHandlerAttr task_attr);


#endif //__EZ_TASK_H__
