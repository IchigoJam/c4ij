
obj/c4ij.bin:     file format binary


Disassembly of section .data:

00000000 <.data>:
   0:	23cc      	movs	r3, #204	; 0xcc
   2:	b5f7      	push	{r0, r1, r2, r4, r5, r6, r7, lr}
   4:	881b      	ldrh	r3, [r3, #0]
   6:	4798      	blx	r3
   8:	240f      	movs	r4, #15
   a:	27ce      	movs	r7, #206	; 0xce
   c:	2605      	movs	r6, #5
   e:	25c4      	movs	r5, #196	; 0xc4
  10:	0031      	movs	r1, r6
  12:	883b      	ldrh	r3, [r7, #0]
  14:	0020      	movs	r0, r4
  16:	4798      	blx	r3
  18:	882b      	ldrh	r3, [r5, #0]
  1a:	204f      	movs	r0, #79	; 0x4f
  1c:	4798      	blx	r3
  1e:	883b      	ldrh	r3, [r7, #0]
  20:	2020      	movs	r0, #32
  22:	9301      	str	r3, [sp, #4]
  24:	23c0      	movs	r3, #192	; 0xc0
  26:	881b      	ldrh	r3, [r3, #0]
  28:	4798      	blx	r3
  2a:	2117      	movs	r1, #23
  2c:	9b01      	ldr	r3, [sp, #4]
  2e:	4798      	blx	r3
  30:	882b      	ldrh	r3, [r5, #0]
  32:	202a      	movs	r0, #42	; 0x2a
  34:	4798      	blx	r3
  36:	882b      	ldrh	r3, [r5, #0]
  38:	200a      	movs	r0, #10
  3a:	4798      	blx	r3
  3c:	23d6      	movs	r3, #214	; 0xd6
  3e:	2003      	movs	r0, #3
  40:	881b      	ldrh	r3, [r3, #0]
  42:	4798      	blx	r3
  44:	23ca      	movs	r3, #202	; 0xca
  46:	881b      	ldrh	r3, [r3, #0]
  48:	4798      	blx	r3
  4a:	281c      	cmp	r0, #28
  4c:	d109      	bne.n	0x62
  4e:	3c01      	subs	r4, #1
  50:	23d0      	movs	r3, #208	; 0xd0
  52:	0031      	movs	r1, r6
  54:	881b      	ldrh	r3, [r3, #0]
  56:	0020      	movs	r0, r4
  58:	4798      	blx	r3
  5a:	2800      	cmp	r0, #0
  5c:	d0d7      	beq.n	0xe
  5e:	0020      	movs	r0, r4
  60:	bdfe      	pop	{r1, r2, r3, r4, r5, r6, r7, pc}
  62:	381d      	subs	r0, #29
  64:	4243      	negs	r3, r0
  66:	4158      	adcs	r0, r3
  68:	1824      	adds	r4, r4, r0
  6a:	e7f1      	b.n	0x50
