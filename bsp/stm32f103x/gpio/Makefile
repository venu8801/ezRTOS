# File: bsp/stm32f103x/gpio/Makefile
# Copyright (c) 2026 Venu Gopal A. All rights reserved.
# Author: Venu Gopal A
# Email: venu.ark.prasad@gmail.com
# @brief: Build rules for STM32F103x GPIO sources.

$(warning ---------------------------)
$(warning --- compiling the [BSP] GPIO component sources ---)

c_gpio_sources += $(wildcard src/*c)

gpio_bsp_inc_dirs += ./inc
gpio_inc_flags := $(addprefix -I, $(gpio_bsp_inc_dirs))

compile_bsp_gpio_sources:
	$(cc) -c $(cc_flags) $(c_flags) $(gpio_inc_flags) $(c_gpio_sources)

clean:
	rm -rf *.o
