# upper make file of ez kernel

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

ez_uKernel_components: ez_uKernel_tasks\
						ez_uKernel_queue\
						ez_uKernel_memory\
						ez_uKernel_system

clean_ez_uKernel_components: \
		clean_ez_uKernel_tasks\
		clean_ez_uKernel_queue\
		clean_ez_uKernel_memory\
		clean_ez_uKernel_system