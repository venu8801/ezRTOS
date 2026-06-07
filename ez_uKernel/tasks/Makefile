# File: ez_uKernel/tasks/Makefile
# Copyright (c) 2026 Venu Gopal A. All rights reserved.
# Author: Venu Gopal A
# Email: venu.ark.prasad@gmail.com
# @brief: Build rules for kernel task sources.

# sub directory make file to compile the tasks
# level fucntions
#



$(warning ---------------------------)
$(warning --- compiling the kernel tasks component sources ---)

c_tasks_sources += ./src/task.c

kernel_inc_dirs += ../inc
local_inc_dirs += ./inc
bsp_inc_flags += $(addprefix -I$(make_src_root)/,$(EZ_BSP_ALL_INC_DIRS))


compile_tasks_sources:
	$(cc) -c $(cc_flags) $(c_flags) -I $(kernel_inc_dirs) \
	$(bsp_inc_flags) -I $(local_inc_dirs) $(c_tasks_sources)


clean:
	rm -rf *.o
