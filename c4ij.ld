/* IchigoJam Memory Definitions */

MEMORY {
  /* Flash: 1k */
  ROM (rx) : ORIGIN = 0x00000000, LENGTH = 1k
  /* SRAM: 1k?? */
  RAM (w)  : ORIGIN = 0x10000000, LENGTH = 1k
}

SECTIONS {
   .text : {
    KEEP(*(.main))
  } > ROM
}
