/**
 * File: uart.c
 * Author: Venu Gopal Atchyutanna
 * Email: venu.ark.prasad@gmail.com
 */

#include <uart.h>
#include <stdbool.h>



void __uart_init(void) {

}

int8_t __uart_start(usart_brate_t brate, usart_reg_t *reg_ptr) {
    switch(brate) {
        case STANDARD_BR:
        break;
        default:
        break;
    }
    return 0;
}


bool transmit_complete(usart_reg_t *reg_ptr) {
    return (((reg_ptr->USART_SR) &
            (TC_BIT_MSK)) ? true : false);
}

bool transmit_empty(usart_reg_t * reg_ptr) {
    return (((reg_ptr->USART_SR) &
            (TXE_BIT_MSK)) ? true : false);
}

void __usart_put_char(char input, usart_reg_t * reg_ptr) {
    (reg_ptr->USART_DR) = input;
    return;
}