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
        /** setting 9600 as standard
         * asssuming peripheral clock to
         * be 36Mhz*/
        uint32_t mantissa = 0xEA;
        uint8_t fraction = 0x6;
        reg_ptr->USART_BRR =  (mantissa << 0x4) |
                                fraction;
        // sets 9600 bps in BRR


        break;
    }
    // set usart enable & transmit enable to true here
    transmit_enable(reg_ptr);
    usart_enable(reg_ptr);
    return 0;
}

void transmit_enable(usart_reg_t *reg_ptr) {
    ((reg_ptr->USART_CR1) |= TE_BIT_MSK);
    return;
}

void usart_enable(usart_reg_t *reg_ptr) {
    ((reg_ptr->USART_CR1) |= USARTEN_BIT_MSK);
    return;
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