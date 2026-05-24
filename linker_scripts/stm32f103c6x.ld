ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 32K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
}


_Min_Heap_Size = 0xC00; /* kernel heap is reserved explicitly in ez_kmalloc.c */
_Min_Stack_Size = 0x1000; /* stack size 4096 bytes 4kB */

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
    /* data section stored in flash but loaded to SRAM */
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
  /* User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
  ._ez_heap :
  {
    . = ALIGN(8);
    __ez_heap_start__ = .;
    . = . + _Min_Heap_Size;
    __ez_heap_end__ = .;
    . = ALIGN(8);
  } >RAM

    _estack = ORIGIN(RAM) + LENGTH(RAM);
}
 