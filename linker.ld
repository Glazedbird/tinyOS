SECTIONS 
{
    . = 0x80000000;
    .text : {
        *(.text.entry)
        *(.text)
    }
    .data : {
        *(.data)
    }
    .rodata : {
        *(.rodata)
    }
    .bss : {
        *(.bss)
    }

}