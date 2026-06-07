/**
 * File: task.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for task control block and
 * task related structures, unions, enums etc...
 */

#include <stdint.h>
#ifndef _EZ_TASK_HEADER_
#define _EZ_TASK_HEADER_

typedef uint32_t ez_sptr_t;
typedef uint8_t task_prty_t;

typedef struct {
    ez_sptr_t *sPtr;
    task_prty_t priority;

} ez_task_control_block;

























#endif
