#include "contex.h"
#include "log.h"

void task_init(struct task* task) {
    task -> task_entry();
    LOG("task init finished!");
}