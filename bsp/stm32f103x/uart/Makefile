
# File: bsp/stm32f103x/uart/Makefile
# Copyright (c) 2026 Venu Gopal A. All rights reserved.
# Author: Venu Gopal A
# Email: venu.ark.prasad@gmail.com
# @brief: Build rules for STM32F103x UART sources.

$(warning ---------------------------)
$(warning --- compiling the [BSP] USART component sources ---)

c_usart_sources += $(wildcard src/*c)

uart_bsp_inc_dirs += ./inc


compile_bsp_uart_sources:
	$(cc) -c $(cc_flags) $(c_flags) -I $(uart_bsp_inc_dirs) $(c_usart_sources)


clean:
	rm -rf *.o
