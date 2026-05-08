#include "uart.h"
#include "types.h"

void uartwrite(const char* msg) {
    while (*msg)
    {
        if ((*REG(LSR) & LSR_THR_EMPTY)){
            *REG(THR) = *msg ++;
        }
    }
}
