#include "uart.h"
#include "log.h"
#include "types.h"
#include "trap.h"
const uint32 TASKFINISHED = 1000000;


// 尝试将 task 的变量保存下来，将前一个task的运行参数保存下来
// 这样可以简单实现
// 但是如果参数量不对等呢？task的数量远远多于两个呢？
// 两个 task 
// void task1(uint32 counter1, uint32 counter2) {

//     // uint32 counter1 = 0;
//     uartwrite("task1 is running!\n");
//     while (counter1 < TASKFINISHED)
//     {   
//         counter1 ++;
//         if(counter1 == 1000)
//             task2(counter2, counter1);
//     }
    
// }


// void task2(uint32 counter1, uint32 counter2) {

//     // uint32 counter1 = 0;
//     uartwrite("task2 is running!\n");
//     while (counter1 < TASKFINISHED)
//     {   
//         counter1 ++;
//         if(counter1 == 1000)
//             task1(counter2, counter1);
//     }

// }

void task() {
    uint32 counter = 0;
    uartwrite("task is runnig! \n");
    
    while (counter < TASKFINISHED)
    {
        counter ++;
    }

    yield();

}

int main(void) {

    task();

    LOG("程序结束!");
    return 0;
}