	.text
	.syntax unified
	.thumb
	.global	maxArray
	.type maxArray, %function
maxArray:
	push {r4-r7}
	// array in r0
	// size in r1
	// max in r2
	// checking in r3
	movs r2, #0
	movs r3, #0
.MAX:
	cmp r1, #0
	// if size = 0 goto end
	beq .END
	// load the next of the array into r4
	ldr r4, [r0, r3]
	// add 4 to r3, 4 bytes
	adds r3, #4
	// subtract 1 from the size
	subs r1, #1
	// check if curr > max
	cmp r2, r4
	bgt .MAX
	// if it is move curr to max and repeat
	movs r2, r4
	bal .MAX
.END:
	// move the max to r0 to return
	movs r0, r2
	pop {r4-r7}
	bx	lr
