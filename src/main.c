
#include <stdio.h>

int main(void) {
    // printf("Hello from STM32!\r\n");

    for (int i = 0; ; ++i) {
        if ((i & 0x0FFF) == 0) {
            // printf("tick %d\r\n", i >> 12);
        }
    }

    return 0;
}

