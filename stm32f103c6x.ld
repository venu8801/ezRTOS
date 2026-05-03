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