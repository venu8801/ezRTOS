# upper make file of ez kernel

$(warning -------------- Building EZ BSP Components ---------------------)

#----------------uart driver component-------------
ez_uKernel_uart_components:
	$(MAKE) -C uart
clean_uart:
	$(MAKE) -C uart clean


ez_uKernel_bsp_components: ez_uKernel_uart_components

clean_bsp: clean_uart