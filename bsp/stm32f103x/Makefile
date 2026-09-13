# File: bsp/stm32f103x/Makefile
# Copyright (c) 2026 Venu Gopal A. All rights reserved.
# Author: Venu Gopal A
# Email: venu.ark.prasad@gmail.com
# @brief: Build rules for STM32F103x BSP components.

$(warning -------------- Building EZ BSP Components ---------------------)

#----------------uart driver component-------------
ez_uKernel_uart_components:
	$(MAKE) -C uart
clean_uart:
	$(MAKE) -C uart clean

#----------------clock driver component-------------
ez_uKernel_clock_components:
	$(MAKE) -C clock
clean_clock:
	$(MAKE) -C clock clean

#----------------gpio driver component-------------
ez_uKernel_gpio_components:
	$(MAKE) -C gpio
clean_gpio:
	$(MAKE) -C gpio clean

ez_uKernel_bsp_components: ez_uKernel_uart_components ez_uKernel_clock_components ez_uKernel_gpio_components

clean_bsp: clean_uart clean_clock clean_gpio
