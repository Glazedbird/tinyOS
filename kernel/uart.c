// 串口调用的最小实现

// 定义uart寄存器地址
// 初始化uart
// 输出一个字符
// 输出字符串

#include "types.h"
#include "uart.h"

#define UART0 0x10000000L

#define RHR 0   // receive holding register (read mode)
#define THR 0   // transmit holding register (write mode)
#define LSR 5   // line status register

#define LSR_TX_IDLE (1 << 5)

static inline void write_reg(int reg, uint8 value) {
    *(volatile uint8 *)(UART0 + reg) = value;
}

static inline uint8 read_reg(int reg) {
    return *(volatile uint8 *)(UART0 + reg);
}

void uart_init(void) {
    // 第一版可以几乎不做复杂初始化
    // QEMU virt 下很多时候直接写 THR 就能看到输出
}

void uart_putc(char c) {
    while ((read_reg(LSR) & LSR_TX_IDLE) == 0)
        ;
    write_reg(THR, c);
}

void uart_puts(const char *s) {
    while (*s) {
        if (*s == '\n') {
            uart_putc('\r');
        }
        uart_putc(*s++);
    }
}