# initialization variables
arch=armv7m
cc=arm-none-eabi-gcc
cpu_name=cortex-m3
mcu_family=stm32f103c6x
is_stdlib=false
output_file=ezRTOS
obj_copy=arm-none-eabi-objcopy

.DEFAULT_GOAL := all


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

main_inc_dirs += ez_uKernel/inc

c_sources += src/main.c\

asm_sources += arch/$(arch)/startup.S\

link_sources  += linker_scripts/$(mcu_family).ld

#--------------- Export Make vars to inner makefiles -------------------
$(warning exporting make vars to inner tree !!!!!!!!!!)
export cc
export c_flags
export cc_flags
export cpu_name

$(warning "----------------------")
$(warning "cleaning all files")

clean:
	$(MAKE) -C ez_uKernel clean_ez_uKernel_components
	rm -rf *.o *.elf *.bin
	exit 0;
$(warning "----------------------")


#-------------------------------------
#  Build the arch dependent assemblies
#  ASM: assemble
#-------------------------------------
$(warning "----------------------")
$(warning "building startup asm files")
$(warning "----------------------")
startup.o:
	$(cc)  $(cc_flags) $(c_flags) -c $(asm_sources) -o startup.o

ez_uKernel_components:
	$(MAKE) -C ez_uKernel ez_uKernel_components

#-------------------------------------
#  Build the c files to object files
#  C files: compile + assemble
#-------------------------------------
$(warning "----------------------")
$(warning "building all c source files")
$(warning "----------------------")
all_c_sources.o:
	$(cc) $(cc_flags) $(c_flags) -I $(main_inc_dirs) -c   $(c_sources) -o all_c_sources.o

#-------------------------------------
#  Build the all files to elf
#  C files: compile + assemble
#-------------------------------------
$(warning "----------------------")
$(warning "building eZRTOS elf")
$(warning "----------------------")

EZ_KERNEL_COMPONENTS = $(shell find ez_uKernel -name "*.o")

build_elf: all_c_sources.o startup.o ez_uKernel_components
	$(cc) $(cc_flags)\
		-T $(link_sources) all_c_sources.o\
		$(EZ_KERNEL_COMPONENTS)\
		startup.o -o $(output_file).elf
#-------------------------------------
#  Build the all files to elf
#  C files: compile + assemble
#-------------------------------------
$(warning "------------------------")
$(warning "building eZRTOS binary")
$(warning "------------------------")
all: build_elf
	$(obj_copy) -O binary \
	$(output_file).elf \
	$(output_file).bin
