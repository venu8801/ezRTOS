
#include <stdio.h>
#include <stdbool.h>
#include <ukernel.h>
#include <uart.h>

int main(void) {

    ez_system_init();

    ez_kernel_init();

    __usart_put_char('a', USART1);
    volatile int i = 0;
    while(i <= 100) {
        i++;
        __usart_put_char('v', USART1);
    }
    
    return 0; // should never come here ideally
}

