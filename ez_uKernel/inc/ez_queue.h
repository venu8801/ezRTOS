/**
 * File: ez_queue.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for ezRTOS queue structures and APIs.
 */

#ifndef _U_KERNEL_QUEUE_H_
#define _U_KERNEL_QUEUE_H_

#include <ez_task.h>

typedef struct ez_queue{
    ez_task_control_block *mTaskCB;
    struct ez_queue *mPrev;
    struct ez_queue *mNext;
} ez_queue_t;

typedef enum {
    EZ_QUEUE_INIT_SUCCESS = 0,
    EZ_QUEUE_INIT_FAIL = -1,
    EZ_QUEUE_INIT_NOMEM = -2,
} ez_queue_error_t;

/* global queue list initializer function */
ez_queue_error_t ez_queue_list_init(void);
























#endif  // _U_KERNEL_QUEUE_H_
