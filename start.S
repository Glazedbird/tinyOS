.text
.global _start

_start:
    la sp, stack_top

hang:
    j hang

.bss
.align 12
stack:
    .space 4096
stack_top: