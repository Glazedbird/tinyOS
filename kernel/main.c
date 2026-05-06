#include "uart.h"

int main(void){
    const char* msg = "Hello world!";

    while (*msg)
    {
        *(volatile char*)UART0 = *msg ++;
    }
    
    return 0;
}