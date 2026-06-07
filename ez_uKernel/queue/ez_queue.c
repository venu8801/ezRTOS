/*
 * File: ez_queue.c
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Queue implementation for the ez RTOS.
 */


#include <stddef.h>
#include <ez_queue.h>
#include <ez_syscalls.h>


/* global queue head pointer */
ez_queue_t * g_queue_list_head = NULL;

/* global queue tail pointer */
ez_queue_t * g_queue_list_tail = NULL;


ez_queue_error_t ez_queue_list_init(void) {
    /* create an idle task related queue member */
    ez_queue_error_t ret = EZ_QUEUE_INIT_FAIL;
    ez_queue_t *tmp_list = (ez_queue_t *) kmalloc(1 * sizeof(ez_queue_t));
    if (!tmp_list) {
        // log the error here to std out
        ret = EZ_QUEUE_INIT_NOMEM;
        goto exit;
    }
exit:
    return ret;
}
