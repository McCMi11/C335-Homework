	.text
	.syntax unified
	.thumb
	.global	regName	
	.type regName, %function
regName:
	push {r4-r7}
	// check to see if input is > 15
	cmp r0, 15
	// if it is goto error
	bgt .ERR
	// load the names array into r1
	ldr r1, .labA   @ load contents of memory at labA (address of global_name)
	// multiply input by 4
	lsls r0, #2
	// set r0 to the pointer of the index given, with propper offset
	ldr r0, [r1, r0]
	// goto end
	bal .END
.ERR:
	// return 0, set to r0
	movs r0, #0
.END:
	// return r0
	pop {r4-r7}
	bx	lr
	.align 2
.labA:
	// global vaiable from c function
	.word names
