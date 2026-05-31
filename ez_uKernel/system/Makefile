# sub directory make file to compile the kernel\
# level fucntions
#



$(warning ---------------------------)
$(warning --- compiling the kernel system component sources ---)

c_system_sources += $(wildcard *c)

kernel_inc_dirs += ../inc
bsp_inc_flags += $(addprefix -I$(make_src_root)/,$(EZ_BSP_ALL_INC_DIRS))


compile_system_sources:
	$(cc) -c $(cc_flags) $(c_flags) -I $(kernel_inc_dirs) \
	$(bsp_inc_flags) $(c_system_sources)


clean:
	rm -rf *.o
