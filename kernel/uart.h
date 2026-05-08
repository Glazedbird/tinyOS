#pragma once

#define UART0 (0x10000000L)

#define REG(reg) ((volatile unsigned char*)(UART0 + (reg)))

#define RHR 0
#define THR 0

#define LSR 5
#define LSR_THR_EMPTY (1 << 5)
#define LSR_DATA_READY (1 << 0)
 
void uartwrite(const char*);