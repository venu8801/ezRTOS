# File: ez_uKernel/memory/Makefile
# Copyright (c) 2026 Venu Gopal A. All rights reserved.
# Author: Venu Gopal A
# Email: venu.ark.prasad@gmail.com
# @brief: Build rules for kernel memory sources.

$(warning ---------------------------)
$(warning --- compiling the kernel memory component sources ---)

c_memory_sources += $(wildcard *c)

kernel_inc_dirs += ../inc


compile_memory_sources:
	$(cc) -c $(cc_flags) $(c_flags) -I $(kernel_inc_dirs) $(c_memory_sources)


clean:
	rm -rf *.o
