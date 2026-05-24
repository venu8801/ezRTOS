$(warning ---------------------------)
$(warning --- compiling the kernel queue component sources ---)

c_queue_sources += $(wildcard *c)

kernel_inc_dirs += ../inc


compile_queue_sources:
	$(cc) -c -g $(cc_flags) $(c_flags) -I $(kernel_inc_dirs) $(c_queue_sources)


clean:
	rm -rf *.o
