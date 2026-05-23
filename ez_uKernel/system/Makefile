# sub directory make file to compile the kernel\
# level fucntions
#



$(warning ---------------------------)
$(warning --- compiling the kernel sources ---)

c_system_sources += $(wildcard *c)

kernel_inc_dirs += ../inc


compile_system_sources:
	$(cc) $(cc_flags) $(c_flags) -I $(kernel_inc_dirs) -c $(c_system_sources) -o c_system_sources.o


clean:
	rm -rf *.o
