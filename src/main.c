
#include <stdio.h>
#include <stdbool.h>
#include <ukernel.h>

int main(void) {

    ez_system_init();

    ez_kernel_init();


    int i = 0;
    while(true) {
        i++;
    }

    return 0; // should never come here ideally
}

