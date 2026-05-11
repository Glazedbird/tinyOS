#pragma once

#include "types.h"

typedef void(*task_entry_t)(void);

struct context
{
// ra 寄存器是 caller saved，理论上来说，ra寄存器应该会被 调用者保存到调用栈中
// 但是，这个栈的布局其实并不是固定的（取决于编译器本身），而这两个参数，需要ra和sp来进行恢复
// 所以直接使用swtch进行保存
    uint64 ra;
    uint64 sp;

// callee saved，caller saved 在调用 swtch时已经进行了保存
    uint64 s0;
    uint64 s1;
    uint64 s2;
    uint64 s3;
    uint64 s4;
    uint64 s5;
    uint64 s6;
    uint64 s7;
    uint64 s8;
    uint64 s9;
    uint64 s10;
    uint64 s11;
};

struct task
{
    task_entry_t task_entry;
    struct context context;
};

void task_init(struct task*); 