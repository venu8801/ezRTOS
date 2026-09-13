<!--
File: linker_script_explanation.md
Copyright (c) 2026 Venu Gopal A. All rights reserved.
Author: Venu Gopal A
Email: venu.ark.prasad@gmail.com
@brief: Explanation of the STM32F103C6x linker script.
-->

# Linker Script Explanation

This document explains every line of the `stm32f103c6x.ld` linker script used for your STM32 RTOS project. The linker script defines memory layout and controls how all compiled sections are placed in the final binary.

## File Contents

```
ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 32K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
}

SECTIONS
{
    . = 0x0;
    .text : {
        startup.o (.vector_table)
        *(.text)
        *(.text*)
    } >FLASH

    . = ALIGN(4);
    .rodata : {
        *(.rodata)
        *(.rodata*)
    } >FLASH

    . = ALIGN(4);
    _sidata = .;
    .data : {
        _sdata = .;
        *(.data)
        *(.data*)
        _edata = .;
    } >RAM AT> FLASH

    . = ALIGN(4);
    .bss : {
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } >RAM

    _estack = ORIGIN(RAM) + LENGTH(RAM);
}
```

## Line-by-Line Explanation

### `ENTRY(Reset_Handler)`
- Sets the program entry point to `Reset_Handler`.
- This is the address the CPU will jump to after reset.
- It ensures the ELF file and the final image start execution at your startup code.

### `MEMORY` Block
Defines the physical memory regions available on the MCU.

#### `FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 32K`
- `FLASH`: Name of the region.
- `(rx)`: Region attributes: readable and executable.
- `ORIGIN = 0x08000000`: FLASH start address on STM32.
- `LENGTH = 32K`: Reserve 32 KB of flash memory.
- All code and constant data are placed here.

#### `RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 8K`
- `RAM`: Name of the region.
- `(rwx)`: Readable, writable, executable.
- `ORIGIN = 0x20000000`: RAM start address.
- `LENGTH = 8K`: Reserve 8 KB of RAM.
- Runtime data, stack, and BSS go here.

### `SECTIONS` Block
Describes how input sections from object files are combined and where each output section is placed.

#### `. = 0x0;`
- Sets the location counter to 0.
- At this point, the next section starts at the beginning of the current output region.
- For `.text` in FLASH, it means address `0x08000000`.

#### `.text : { ... } >FLASH`
- Defines the `.text` output section.
- `startup.o (.vector_table)`: Places the vector table from `startup.o` first.
- `*(.text)`: Includes all normal code sections from every input object.
- `*(.text*)`: Includes any variant text sections (like `.text.foo`).
- `>FLASH`: Places the final `.text` section into the FLASH region.
- This is where executable code and the vector table are stored.

#### `. = ALIGN(4);`
- Aligns the location counter to a 4-byte boundary.
- Ensures the next section starts on an aligned address.
- Required for ARM memory access and proper section placement.

#### `.rodata : { ... } >FLASH`
- Defines the `.rodata` output section for read-only data.
- `*(.rodata)`: All read-only data sections from object files.
- `*(.rodata*)`: Variant read-only sections, such as string constants.
- `>FLASH`: Stores them in FLASH alongside code.
- This keeps constant data out of RAM.

#### `. = ALIGN(4);`
- Aligns the linker location counter again before the data section.
- Keeps `.data` properly aligned.

#### `_sidata = .;`
- Defines `_sidata` at the current address.
- This symbol marks the load location of initialized data in FLASH.
- The startup code uses `_sidata` to copy `.data` to RAM.

#### `.data : { ... } >RAM AT> FLASH`
- Defines the `.data` section for initialized global/static variables.
- `>RAM`: Runtime address is RAM.
- `AT> FLASH`: Initial values are stored in FLASH.
- `_sdata = .;`: Marks start of `.data` in RAM.
- `*(.data)`: Includes initialized data from all object files.
- `*(.data*)`: Includes any data subsection variants.
- `_edata = .;`: Marks end of `.data` in RAM.
- The startup code copies from `_sidata` to the RAM range `_sdata.._edata`.

#### `. = ALIGN(4);`
- Aligns the location counter before the BSS section.
- Ensures `_sbss` is aligned for RAM data.

#### `.bss : { ... } >RAM`
- Defines the `.bss` section for zero-initialized data.
- `_sbss = .;`: Start address of `.bss` in RAM.
- `*(.bss)`: Includes uninitialized data sections.
- `*(.bss*)`: Variant uninitialized sections.
- `*(COMMON)`: Includes common symbols (uninitialized globals without explicit section).
- `_ebss = .;`: End address of `.bss`.
- `>RAM`: Place it in RAM.
- The startup code zeroes the memory range `_sbss.._ebss`.

#### `_estack = ORIGIN(RAM) + LENGTH(RAM);`
- Defines `_estack` as the top of RAM.
- `ORIGIN(RAM)` is `0x20000000`.
- `LENGTH(RAM)` is `8K`.
- `_estack` becomes `0x20002000`.
- The vector table uses `_estack` as the initial stack pointer.

## Why Each Part Matters
- `ENTRY(Reset_Handler)`: Ensures the CPU starts at the right code.
- `MEMORY`: Maps the physical target memory into the linker’s view.
- `.text`: Stores code and vectors in FLASH.
- `.rodata`: Stores constants in FLASH.
- `.data`: Stores initialized variables in RAM with initial values in FLASH.
- `.bss`: Stores zeroed variables in RAM.
- `_estack`: Provides the initial stack pointer value.

## Summary
This linker script establishes a correct memory layout for STM32 bare-metal execution:
- Code and constant data in FLASH.
- Writable data and BSS in RAM.
- A correct stack start.
- Symbols used by startup code to initialize memory.

If you want, I can also turn this into a PDF-style markdown document with headers and example diagrams.
