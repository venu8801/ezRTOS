# File: ez_uKernel/Makefile
# Copyright (c) 2026 Venu Gopal A. All rights reserved.
# Author: Venu Gopal A
# Email: venu.ark.prasad@gmail.com
# @brief: Build rules for ezRTOS kernel components.

$(warning -------------- Building EZ uKernel Components ---------------------)

#----------------system component-------------
ez_uKernel_system:
	$(MAKE) -C system
clean_ez_uKernel_system:
	$(MAKE) -C system clean


#----------------memory component-------------
ez_uKernel_memory:
	$(MAKE) -C memory

clean_ez_uKernel_memory:
	$(MAKE) -C memory clean

#----------------queue component-------------
ez_uKernel_queue:
	$(MAKE) -C queue

clean_ez_uKernel_queue:
	$(MAKE) -C queue clean

#----------------tasks component-------------
ez_uKernel_tasks:
	$(MAKE) -C tasks

clean_ez_uKernel_tasks:
	$(MAKE) -C tasks clean

#----------------logger component-------------
ez_uKernel_logger:
	$(MAKE) -C ezlog

clean_ez_uKernel_logger:
	$(MAKE) -C ezlog clean
#----------------tasks component-------------
ez_uKernel_tasks:
	$(MAKE) -C tasks

clean_ez_uKernel_tasks:
	$(MAKE) -C tasks clean


ez_uKernel_components: ez_uKernel_tasks\
						ez_uKernel_queue\
						ez_uKernel_memory\
						ez_uKernel_system\
						ez_uKernel_logger\
						ez_uKernel_tasks

clean_ez_uKernel_components: \
		clean_ez_uKernel_tasks\
		clean_ez_uKernel_queue\
		clean_ez_uKernel_memory\
		clean_ez_uKernel_system\
		clean_ez_uKernel_logger\
		clean_ez_uKernel_tasks
