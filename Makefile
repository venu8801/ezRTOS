# File: Makefile
# Copyright (c) 2026 Venu Gopal A. All rights reserved.
# Author: Venu Gopal A
# Email: venu.ark.prasad@gmail.com
# @brief: Top-level build rules for ezRTOS.

# initialization variables
arch=armv7m
cc=arm-none-eabi-gcc
cpu_name=cortex-m3
#mcu_family=stm32f103c6x
is_stdlib=false
output_file=ezRTOS
obj_copy=arm-none-eabi-objcopy
target_board=stm32f103x
make_src_root=$(shell pwd)
.DEFAULT_GOAL := all

ESC := $(shell printf '\033')
COLOR_RESET := $(ESC)[0m
COLOR_RED := $(ESC)[1;31m
COLOR_GREEN := $(ESC)[1;32m
COLOR_YELLOW := $(ESC)[1;33m
COLOR_BLUE := $(ESC)[1;34m
COLOR_CYAN := $(ESC)[1;36m
COLOR_BOLD := $(ESC)[1m


ifeq ($(arch), armv7m)
	cc_flags += -mcpu=$(cpu_name) -mthumb
else
	cc_flags=
endif

ifeq ($(is_stdlib), true)
	cc_flags +=
else
	cc_flags += -nostdlib
endif

c_flags = -Wall \
		  -g

main_inc_dirs += ez_uKernel/inc\
		 ez_uKernel/tasks/inc

main_inc_flags := $(addprefix -I,$(main_inc_dirs))

arch_armv7_incs = arch/armv7m

arch_armv7_incs = arch/armv7m

c_sources += src/main.c\

asm_sources += arch/$(arch)/startup.S\

ifeq ($(mcu_family),)
    mcu_family = stm32f103c6x
    $(warning  "$(COLOR_RED)MCU Family undefined using default: $(mcu_family)$(COLOR_RESET)")
endif

link_sources  += linker_scripts/$(mcu_family).ld

EZ_C_MACRO_DEFS += -DMAX_TASK_LIST_SIZE=20

EZ_BSP_UART_INCS := bsp/$(target_board)/uart/inc
EZ_BSP_GPIO_INCS := bsp/$(target_board)/gpio/inc
EZ_BSP_CLOCK_INCS := bsp/$(target_board)/uart/inc

EZ_BSP_ALL_INC_DIRS += $(EZ_BSP_UART_INCS)\
						$(EZ_BSP_GPIO_INCS)\
						$(EZ_BSP_CLOCK_INCS)

EZ_BSP_INC_FLAGS = $(addprefix -I,$(EZ_BSP_ALL_INC_DIRS))

$(info $(COLOR_CYAN)bsp includes: $(EZ_BSP_INC_FLAGS)!$(COLOR_RESET))

#--------------- Export Make vars to inner makefiles -------------------
$(info $(COLOR_CYAN)exporting make vars to inner tree !!!!!!!!!!$(COLOR_RESET))
export cc
export c_flags
export cc_flags
export cpu_name
export target_board
export EZ_BSP_INC_FLAGS
export EZ_BSP_ALL_INC_DIRS
export make_src_root
export EZ_C_MACRO_DEFS

clean:
	@printf '$(COLOR_YELLOW)----------------------$(COLOR_RESET)\n'
	@printf '$(COLOR_YELLOW)cleaning all files$(COLOR_RESET)\n'
	@printf '$(COLOR_YELLOW)----------------------$(COLOR_RESET)\n'
	$(MAKE) -C ez_uKernel clean_ez_uKernel_components
	$(MAKE) -C bsp/$(target_board) clean_bsp
	rm -rf *.o *.elf *.bin *.s *.i
	exit 0;


#-------------------------------------
#  Build the arch dependent assemblies
#  ASM: assemble
#-------------------------------------
startup.o:
	@printf '$(COLOR_BLUE)----------------------$(COLOR_RESET)\n'
	@printf '$(COLOR_BLUE)building startup asm files$(COLOR_RESET)\n'
	@printf '$(COLOR_BLUE)----------------------$(COLOR_RESET)\n'
	$(cc) -g $(cc_flags) $(c_flags) -c $(asm_sources) -o startup.o

ez_uKernel_components:
	$(MAKE) -C ez_uKernel ez_uKernel_components

ez_uKernel_bsp_components:
	$(MAKE) -C bsp/$(target_board)/ ez_uKernel_bsp_components

#-------------------------------------
#  Build the c files to object files
#  C files: compile + assemble
#-------------------------------------
all_c_sources.o: $(c_sources) arch/$(arch)/port.h
	@printf '$(COLOR_BLUE)----------------------$(COLOR_RESET)\n'
	@printf '$(COLOR_BLUE)building all c source files$(COLOR_RESET)\n'
	@printf '$(COLOR_BLUE)----------------------$(COLOR_RESET)\n'
	$(cc) $(cc_flags) $(c_flags) $(main_inc_flags)\
		-save-temps\
		-I $(arch_armv7_incs) -c   $(c_sources) -o all_c_sources.o

#-------------------------------------
#  Build the all files to elf
#  C files: compile + assemble
#-------------------------------------
EZ_KERNEL_COMPONENTS = $(shell find ez_uKernel -name "*.o")

EZ_BSP_COMPONENTS = $(shell find bsp/$(target_board) -name "*.o")

build_elf: all_c_sources.o startup.o ez_uKernel_components ez_uKernel_bsp_components
	@printf '$(COLOR_BLUE)----------------------$(COLOR_RESET)\n'
	@printf '$(COLOR_BLUE)building eZRTOS elf$(COLOR_RESET)\n'
	@printf '$(COLOR_BLUE)----------------------$(COLOR_RESET)\n'
	$(cc) $(cc_flags)\
		-T $(link_sources) all_c_sources.o\
		$(EZ_KERNEL_COMPONENTS)\
		$(EZ_BSP_COMPONENTS)\
		startup.o -o $(output_file).elf
#-------------------------------------
#  Build the all files to elf
#  C files: compile + assemble
#-------------------------------------
all: build_elf
	@printf '$(COLOR_BLUE)------------------------$(COLOR_RESET)\n'
	@printf '$(COLOR_BLUE)building eZRTOS binary$(COLOR_RESET)\n'
	@printf '$(COLOR_BLUE)------------------------$(COLOR_RESET)\n'
	$(obj_copy) -O binary \
	$(output_file).elf \
	$(output_file).bin
	@printf '$(COLOR_GREEN)!!!! build completed successfully !!!!!$(COLOR_RESET)\n'
