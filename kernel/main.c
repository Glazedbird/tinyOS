#include "uart.h"
#include "log.h"
#include "types.h"

void task1() {

    uint32 counter1 = 0;
    while (1)
    {   
        uartwrite("task1 is running!\n");
        if(counter1 == 1000)
            yield();
    }

}

void task2() {

    uint32 counter1 = 0;
    while (1)
    {   
        uartwrite("task2 is running!\n");
        if(counter1 == 1000)
            yield();
    }

}

int main(void) {





    LOG("程序结束!");
    return 0;
}