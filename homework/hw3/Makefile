main: prog

prog: hw3.o
	gcc hw3.o -o disassembler
hw3.o: hw3.c
	gcc -c hw3.c

test: main
	arm-none-eabi-as test_case_file -o test.o
	arm-none-eabi-objcopy test.o -O binary --only-section=.text test.bin
	hexdump -x test.bin |sed -e 's/^[^ ]*//' > test.hex
	./disassembler < test.hex > output.txt
	diff output.txt test_case_file > test.diff

clean:
	rm -rf *.o disassembler *~ test.asm  test.bin test.hex output.txt test.diff
