# File: bsp/stm32f103x/clock/Makefile
# Copyright (c) 2026 Venu Gopal A. All rights reserved.
# Author: Venu Gopal A
# Email: venu.ark.prasad@gmail.com
# @brief: Build rules for STM32F103x clock sources.


$(warning ---------------------------)
$(warning --- compiling the [BSP] USART component sources ---)

c_clock_sources += $(wildcard src/*c)

clock_bsp_inc_dirs += ./inc


compile_bsp_clock_sources:
	$(cc) -c $(cc_flags) $(c_flags) -I $(clock_bsp_inc_dirs) $(c_clock_sources)


clean:
	rm -rf *.o
