# 提供_start
# 初始化栈指针sp
# 调用 kernel_main
# 如果返回就死循环

.section .text.entry
.globl _start

_start:
    la sp, stack_top
    call kernel_main

1:
    j 1b

    .section .bss.stack
    .align 12
stack:
    .space 4096
stack_top: