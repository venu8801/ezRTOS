

#include <stdint.h>
#include <stddef.h>
#include <ukernel_memory.h>

#ifdef GLOBAL_POOL_ALLOCATOR
/* global array approach allocated in .bss and managed here */
static uint8_t g_kernel_heap[U_KERNEL_HEAP_SIZE];
#endif

extern uint32_t __ez_heap_end__;
extern uint32_t __ez_heap_start__;
extern uint32_t _estack;
extern uint32_t _Min_Stack_Size;




void * __ez_mem_allocator(uint32_t alloc_size) {
    uint8_t *mem_ptr = NULL;
    const uint32_t max_heap_size = (uint32_t)&_estack - (uint32_t)&_Min_Stack_Size;
exit:
    return mem_ptr;
}