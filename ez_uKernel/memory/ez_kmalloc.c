

#include <stdint.h>
#include <stddef.h>
#include <ukernel_memory.h>

#ifdef GLOBAL_POOL_ALLOCATOR
/* global array approach allocated in .bss and managed here */
static uint8_t g_kernel_heap[U_KERNEL_HEAP_SIZE];
#endif

ez_heap_info_t g_heap_info;

#define MAX_HEAP_SIZE 0xC00;

extern uint32_t __ez_heap_end__;
extern uint32_t __ez_heap_start__;
extern uint32_t _estack;
extern uint32_t _Min_Stack_Size;


/* this must be called before any heap mem allocations
 * this should be part of kernel memory subsystem init */
void __ez_mem_init(void) {
    /* initialize the curr_heap_ptr here
     * update the available heap size */
    g_heap_info.available_heap_size = (uint32_t)&__ez_heap_end__ - (uint32_t)&__ez_heap_start__;
    g_heap_info.curr_ptr = (uint8_t *)((uint32_t)&__ez_heap_start__);
    g_heap_info.max_heap_size = MAX_HEAP_SIZE;
    g_heap_info.__heap_region_start = g_heap_info.curr_ptr;
    return;
}

void * __ez_mem_allocator(uint32_t alloc_size) {
    uint8_t *mem_ptr = NULL;
    if (alloc_size <= g_heap_info.available_heap_size) {
        mem_ptr = g_heap_info.curr_ptr;
        g_heap_info.curr_ptr += alloc_size;
        g_heap_info.available_heap_size -= alloc_size;
    }
    
exit:
    return mem_ptr;
}

void ez_mem_init(void) {
    return __ez_mem_init();
}
