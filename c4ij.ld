/* c4ij memory definitions */

MEMORY {
  /* PROG: 512 #700-#8FF */
  PROG (rx) : ORIGIN = 0x00000000, LENGTH = 512
  /* SRAM: 1k?? */
  RAM (w)  : ORIGIN = 0x10000000, LENGTH = 1k
}

SECTIONS {
   .text : {
    KEEP(*(.main))
  } > PROG
}
