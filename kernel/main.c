// 内核主函数
// 调用uart_init()
// uart_puts("hello tinyOS")


#include "uart.h"

void kernel_main(void) {
    uart_init();
    uart_puts("hello tinyOS\n");

    while (1) {
        // 暂时什么也不做
    }
}