# flags for gdb

CFLAGS  = -g -O1 -mcpu=cortex-m0 -mthumb
ASFLAGS = -g -mcpu=cortex-m0 -mthumb
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LDFLAG = -g -mcpu=cortex-m0 -mthumb --specs=rdimon.specs -lc -lrdimon

main: HW1.elf
	@echo -e "Creating main.s\n"
	@arm-none-eabi-objdump -d test.o > main.s
	@echo -e "Creating mainsize.s which contains size and address of functions and variables\n"
	@arm-none-eabi-nm --print-size  HW1.elf > mainsize.s
	@echo -e "Creating readHW1.elf which has more on size of functions and variables as well as the addresses\n"
	@arm-none-eabi-readelf -a HW1.elf > readHW1.elf
	@echo -e "Saving size of HW1.elf executeable to HW1-size.txt"
	@arm-none-eabi-size HW1.elf > HW1-size.txt

HW1.elf: test.o t1.o
	@echo -e "Creating HW1.elf\n"
	@$(CC) $(LDFLAG) test.o t1.o -o HW1.elf
t1.o: t1.s
	@echo -e "Creating test.d\n"
	@$(AS) $(ASFLAGS) t1.s -o t1.o
test.o: test.c
	@echo -e "Creating test.o\n"
	@$(CC) -c $(CFLAGS) test.c
	@echo -e "Creating main.s\n"

test: HW1.elf
	@echo -e "Creating test.txt from HW1.elf\n"
	@qemu-system-arm  -machine versatilepb -cpu cortex-m3 -nographic -monitor null -serial null -semihosting -kernel HW1.elf > output.txt
	@cat output.txt

clean:
	@echo -e "Removing files\n"
	@rm -rf *~ *.elf *.o output.txt *.wav main.s mainsize.s HW1-size.txt




