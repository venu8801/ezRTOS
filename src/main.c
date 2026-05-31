
#include <stdio.h>
#include <stdbool.h>
#include <ukernel.h>
#include <ezlog.h>
#include <ez_syscalls.h>


int main(void) {
    ez_system_init();
    ez_kernel_init();
    volatile int i = 0;
    while(true) {
        ez_log("idiling %s()..here ...", __func__);
        __usleep(10000);
        i += 1;
    }
    
    return 0; // should never come here ideally
}

