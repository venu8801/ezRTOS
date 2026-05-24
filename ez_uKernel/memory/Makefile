

$(warning ---------------------------)
$(warning --- compiling the kernel memory component sources ---)

c_memory_sources += $(wildcard *c)

kernel_inc_dirs += ../inc


compile_memory_sources:
	$(cc) -c $(cc_flags) $(c_flags) -I $(kernel_inc_dirs) $(c_memory_sources)


clean:
	rm -rf *.o
