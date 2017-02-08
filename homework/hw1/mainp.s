
test.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <stop_light>:
   0:	b508      	push	{r3, lr}
   2:	4b1f      	ldr	r3, [pc, #124]	; (80 <stop_light+0x80>)
   4:	681b      	ldr	r3, [r3, #0]
   6:	2b01      	cmp	r3, #1
   8:	d025      	beq.n	56 <stop_light+0x56>
   a:	2b02      	cmp	r3, #2
   c:	d012      	beq.n	34 <stop_light+0x34>
   e:	2b00      	cmp	r3, #0
  10:	d131      	bne.n	76 <stop_light+0x76>
  12:	481c      	ldr	r0, [pc, #112]	; (84 <stop_light+0x84>)
  14:	f7ff fffe 	bl	0 <puts>
  18:	4b19      	ldr	r3, [pc, #100]	; (80 <stop_light+0x80>)
  1a:	685b      	ldr	r3, [r3, #4]
  1c:	3301      	adds	r3, #1
  1e:	2b04      	cmp	r3, #4
  20:	dc02      	bgt.n	28 <stop_light+0x28>
  22:	4a17      	ldr	r2, [pc, #92]	; (80 <stop_light+0x80>)
  24:	6053      	str	r3, [r2, #4]
  26:	e02a      	b.n	7e <stop_light+0x7e>
  28:	4b15      	ldr	r3, [pc, #84]	; (80 <stop_light+0x80>)
  2a:	2200      	movs	r2, #0
  2c:	605a      	str	r2, [r3, #4]
  2e:	2202      	movs	r2, #2
  30:	601a      	str	r2, [r3, #0]
  32:	e024      	b.n	7e <stop_light+0x7e>
  34:	4814      	ldr	r0, [pc, #80]	; (88 <stop_light+0x88>)
  36:	f7ff fffe 	bl	0 <puts>
  3a:	4b11      	ldr	r3, [pc, #68]	; (80 <stop_light+0x80>)
  3c:	685b      	ldr	r3, [r3, #4]
  3e:	3301      	adds	r3, #1
  40:	2b04      	cmp	r3, #4
  42:	dc02      	bgt.n	4a <stop_light+0x4a>
  44:	4a0e      	ldr	r2, [pc, #56]	; (80 <stop_light+0x80>)
  46:	6053      	str	r3, [r2, #4]
  48:	e019      	b.n	7e <stop_light+0x7e>
  4a:	4b0d      	ldr	r3, [pc, #52]	; (80 <stop_light+0x80>)
  4c:	2200      	movs	r2, #0
  4e:	605a      	str	r2, [r3, #4]
  50:	2201      	movs	r2, #1
  52:	601a      	str	r2, [r3, #0]
  54:	e013      	b.n	7e <stop_light+0x7e>
  56:	480d      	ldr	r0, [pc, #52]	; (8c <stop_light+0x8c>)
  58:	f7ff fffe 	bl	0 <puts>
  5c:	4b08      	ldr	r3, [pc, #32]	; (80 <stop_light+0x80>)
  5e:	685b      	ldr	r3, [r3, #4]
  60:	3301      	adds	r3, #1
  62:	2b01      	cmp	r3, #1
  64:	dc02      	bgt.n	6c <stop_light+0x6c>
  66:	4a06      	ldr	r2, [pc, #24]	; (80 <stop_light+0x80>)
  68:	6053      	str	r3, [r2, #4]
  6a:	e008      	b.n	7e <stop_light+0x7e>
  6c:	4b04      	ldr	r3, [pc, #16]	; (80 <stop_light+0x80>)
  6e:	2200      	movs	r2, #0
  70:	605a      	str	r2, [r3, #4]
  72:	601a      	str	r2, [r3, #0]
  74:	e003      	b.n	7e <stop_light+0x7e>
  76:	4b02      	ldr	r3, [pc, #8]	; (80 <stop_light+0x80>)
  78:	2200      	movs	r2, #0
  7a:	601a      	str	r2, [r3, #0]
  7c:	605a      	str	r2, [r3, #4]
  7e:	bd08      	pop	{r3, pc}
	...
  88:	00000004 	.word	0x00000004
  8c:	0000000c 	.word	0x0000000c

00000090 <main>:
  90:	b510      	push	{r4, lr}
  92:	2400      	movs	r4, #0
  94:	f7ff fffe 	bl	0 <stop_light>
  98:	1c20      	adds	r0, r4, #0
  9a:	f7ff fffe 	bl	0 <inc>
  9e:	1e04      	subs	r4, r0, #0
  a0:	2c23      	cmp	r4, #35	; 0x23
  a2:	ddf7      	ble.n	94 <main+0x4>
  a4:	bd10      	pop	{r4, pc}
  a6:	46c0      	nop			; (mov r8, r8)
