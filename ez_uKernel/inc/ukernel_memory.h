#ifndef _UKERNEL_MEM_H_
#define _UKERNEL_MEM_H_
#include <stdint.h>

#define U_KERNEL_HEAP_SIZE 3072

typedef void * chunk_ptr;
typedef struct heap_info {
    uint8_t *curr_ptr;
    uint32_t available_heap_size;
    void * __heap_region_start;
    uint32_t max_heap_size;
} ez_heap_info_t;

typedef struct heap_meta_data {
    uint32_t chunk_size;
    uint8_t is_aligned : 1;
    uint8_t is_available : 1;
} ez_heap_meta_data_t;

typedef struct heap_chunk {
    ez_heap_meta_data_t heap_mdata;
    chunk_ptr ptr;
    struct heap_chunk *next;
} ez_heap_chunk_t;


void * __ez_mem_allocator(uint32_t alloc_size);

/* memory init */
void __ez_mem_init(void);
#endif
