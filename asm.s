
obj/c4ij.bin:     file format binary


Disassembly of section .data:

00000000 <.data>:
   0:	23e0      	movs	r3, #224	; 0xe0
   2:	00db      	lsls	r3, r3, #3
   4:	18c9      	adds	r1, r1, r3
   6:	2203      	movs	r2, #3
   8:	23ee      	movs	r3, #238	; 0xee
   a:	b570      	push	{r4, r5, r6, lr}
   c:	0004      	movs	r4, r0
   e:	881d      	ldrh	r5, [r3, #0]
  10:	4342      	muls	r2, r0
  12:	3bed      	subs	r3, #237	; 0xed
  14:	4801      	ldr	r0, [pc, #4]	; (0x1c)
  16:	47a8      	blx	r5
  18:	0020      	movs	r0, r4
  1a:	bd70      	pop	{r4, r5, r6, pc}
  1c:	0004      	movs	r4, r0
  1e:	5001      	str	r1, [r0, r0]
