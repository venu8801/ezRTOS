/**
 * File: ezlogger.c
 * Brief: Generic logging function for ezRTOS kernel
 * Author: Venu Gopal Atchyutanna
 * Email: venu.ark.prasad@gmail.com
 */

#include <ezlog.h>
#include <uart.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <ez_syscalls.h>

bool g_uart_initialized;

void put_hex(uint32_t num) {
    char hex_arr[] = "0123456789ABCDEF";
    int i, k;
    uint8_t nibble;
    for (i = 28, k = 4; i >=0; i -= 4, k += 4) {
        nibble = ((num & (0xF << i)) >> (32 - k));
        __usart_put_char(hex_arr[nibble], USART1);
    }
    return;
}

void put_hex_addr(uint32_t addr) {
    char hex_arr[] = "0123456789ABCDEF";
    int i, k;
    uint8_t nibble;
    for (i = 28, k = 4; i >=0; i -= 4, k += 4) {
        nibble = ((addr & (0xF << i)) >> (32 - k));
        __usart_put_char(hex_arr[nibble], USART1);
    }
    return;
}

void put_generic_str(const char *str) {
    if (!str)
        return;
    int i = 0;
    while (str[i]) {
        __usart_put_char(str[i], USART1);
        i++;
    }
    return;
}

int __memcpy(char *dst, char *src, size_t bytes) {
    int i;
    if (!dst || !src || (bytes <= 0))
        return 0;
    for (i = 0; i < bytes; i++) {
        dst[i] = src[i];
    }
    return i;
}

int16_t __printk(const char *str, ...) {
    int i = 0;
    va_list ap;
    va_start(ap, str);
    while(str[i]) {
        if (str[i] == '%') {
            switch(str[i + 1]) {
                case 'x':
                    int d = va_arg(ap, int);
                    __usart_put_char('0', USART1);
                    __usart_put_char('x', USART1);
                    put_hex(d);
                    break;
                case 's':
                    char *s = va_arg(ap, char *);
                    put_generic_str(s);
                    break;
                case 'p':
                    uint32_t ptr = va_arg(ap, uint32_t);
                    __usart_put_char('0', USART1);
                    __usart_put_char('x', USART1);
                    put_hex_addr(ptr);
                    break;

                default:
                    i++;
                    continue;
            }
            // skip % and format specifier chars from printing
            i += 2;
            if (!str[i])
                continue;
        }
        __usart_put_char(str[i++], USART1);
    }
    va_end(ap);
    __usart_put_char('\n', USART1);
    return i + 1;
}

