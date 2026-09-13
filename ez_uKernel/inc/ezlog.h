/**
 * File: ezlog.h
 * Copyright (c) 2026 Venu Gopal A. All rights reserved.
 * Author: Venu Gopal A
 * Email: venu.ark.prasad@gmail.com
 * @brief: Header file for ezRTOS logging APIs.
 */
#ifndef _EZ_LOGGER_H_
#define _EZ_LOGGER_H_
#include <stdint.h>

#define EZ_LOG(fmt, ...)

int16_t __printk(const char *str, ...);

#endif // _EZ_LOGGER_H_
