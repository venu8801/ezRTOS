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


ez_uKernel_bsp_components: ez_uKernel_uart_components

clean_bsp: clean_uart
