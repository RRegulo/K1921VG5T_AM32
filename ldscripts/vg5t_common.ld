SECTIONS
{
    .text.startup ORIGIN(REGION_TEXT) :
    {
        *(.startup.entry .startup.*)
        . = ALIGN(16);
        *(.init.rodata .init.rodata.*)
        . = ALIGN(16);
        *(.init.data .init.data.*)
        . = ALIGN(16);
        *(.init.text .init.text.*)
    } > REGION_TEXT

    .text.crt : ALIGN(16) { *(.text.crt*) } > REGION_TEXT
    /* mtvec clears low address bits; keep the SDK trap entry aligned. */
    .text.irq_entry : ALIGN(16) { KEEP(*(.text.irq_entry)) } > REGION_TEXT
    .text : ALIGN(4) { *(.text .text.*) } > REGION_TEXT
    .rodata : ALIGN(4) { *(.rodata .rodata.*) *(.srodata .srodata.*) } > REGION_RODATA

    .sdata : ALIGN(4)
    {
        __SDATA_BEGIN__ = .;
        *(.sdata .sdata.* .sdata2.*)
    } > REGION_DATA AT > REGION_TEXT

    .data : ALIGN(4)
    {
        __DATA_BEGIN__ = .;
        *(.data .data.*)
    } > REGION_DATA AT > REGION_TEXT

    PROVIDE(__data_source_start = LOADADDR(.data));
    PROVIDE(__data_target_start = ADDR(.data));
    PROVIDE(__data_target_end = ADDR(.data) + SIZEOF(.data));
    PROVIDE(__sdata_source_start = LOADADDR(.sdata));
    PROVIDE(__sdata_target_start = ADDR(.sdata));
    PROVIDE(__sdata_target_end = ADDR(.sdata) + SIZEOF(.sdata));

    .sbss :
    {
        PROVIDE(__bss_start = .);
        *(.sbss .sbss.* .scommon)
    } > REGION_BSS

    .bss : ALIGN(4)
    {
        *(.bss .bss.* COMMON)
        . = ALIGN(4);
        PROVIDE(__bss_end = .);
    } > REGION_BSS

    __global_pointer$ = MIN(__DATA_BEGIN__ + 0x780,
                            MAX(__SDATA_BEGIN__ + 0x780, __bss_end - 0x780));

    .stack ORIGIN(REGION_STACK) + LENGTH(REGION_STACK) - STACK_SIZE :
    {
        . += STACK_SIZE;
        PROVIDE(__TLS0_BASE__ = .);
    } > REGION_STACK

    /DISCARD/ : { *(.eh_frame .eh_frame.*) }
}
