/*
*  @brief Application linker script for K1921VG5T
*         Application region starts right after the 4KB bootloader
*         (bootloader occupies 0x00000000-0x00000FFF, _app_start_addr = 0x1000).
*/

OUTPUT_ARCH( "riscv" )
ENTRY(_start)

MEMORY {
  ROM  (rwx) : ORIGIN = 0x00001000, LENGTH = 512K - 4K
  RAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 16K
  TCM  (rwx) : ORIGIN = 0xF0000000, LENGTH = 32K
}

REGION_ALIAS("REGION_TEXT",   ROM );
REGION_ALIAS("REGION_RODATA", ROM );
REGION_ALIAS("REGION_DATA",   RAM );
REGION_ALIAS("REGION_BSS",    RAM );
REGION_ALIAS("REGION_STACK",  RAM );
REGION_ALIAS("REGION_TCM",    TCM );

STACK_SIZE = 2048;

INCLUDE "k1921vg5t_common.lds"
