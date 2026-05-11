#include "uart.h"
#include "log.h"
#include "types.h"
#include "trap.h"
#include "yield.h"
#include "contex.h"

#define N 3

const uint64 TASKFINISHED = 100000000000;
const uint32 TASKYIELD = TASKFINISHED / 2;

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

static struct task tasks[N];

void task0() {
    uint32 counter = 0;
    uartwrite("task1 is runnig! \n");
    
    while (counter < TASKFINISHED)
    {
        counter ++;
        // if(counter == TASKYIELD)
        //     yield();
    }

    uartwrite("task1 is finished! \n");

}

void task1() {
    uint32 counter = 0;
    uartwrite("task2 is runnig! \n");
    
    while (counter < TASKFINISHED)
    {
        counter ++;
    }

    uartwrite("task2 is finished! \n");

}

// void task2() {
//     uint32 counter = 0;
//     while (counter < TASKFINISHED)
//     {
//         uartwrite("task2 running! \n");
//         if(counter)
        
//     }
    
// }

int main(void) {

    tasks[0].task_entry = task0;
    task_init(&tasks[0]);



    LOG("程序结束!");
    return 0;
}