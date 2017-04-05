	.text
	.syntax unified
	.thumb
	.global	stringLength
	.type stringLength, %function
stringLength:
	push {r4-r7}
	// set length to 0
	movs r1, #0
.LEN:
	// load the length elem into r3
	ldrb r3, [r0, r1]
	// check if it is null char, 0
	cmp r3, #0
	// if it is goto end
	beq .END
	// else add one to length and repeat
	adds r1, #1
	bal .LEN
.END:
	// move length to r0 to return
	mov r0, r1
	pop {r4-r7}
	bx	lr
