/**
 * File: ezlog.h
 */
#ifndef _EZ_LOGGER_H_
#define _EZ_LOGGER_H_
#include <stdint.h>

#define EZ_LOG(fmt, ...)

int16_t __printk(const char *str, ...);

#endif // _EZ_LOGGER_H_