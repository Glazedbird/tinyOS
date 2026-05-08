K = kernel
TOOLPREFIX = riscv64-unknown-elf

KERNEL_ELF = main.elf
CC = $(TOOLPREFIX)-gcc
DUMP = $(TOOLPREFIX)-objdump
# 保证 abi 是 lp64
CFLAGS += -march=rv64gc -mabi=lp64
CFLAGS += -mcmodel=medany
CFLAGS += -g

OBJS = \
	$(K)/main.o \
	$(K)/start.o \
	$(K)/uart.o

$(KERNEL_ELF) : $(OBJS)
	$(CC) -T linker.ld -o main.elf $(OBJS) -nostdlib -ffreestanding

$(K)/%.o : $(K)/%.S
	$(CC) -march=rv64gc -mabi=lp64 -c -o $@ $<

# main.o:
# 	riscv64-unknown-elf-gcc -c main.S -o main.o
# start.o:
# 	riscv64-unknown-elf-gcc -c start.S -o start.o

run:$(KERNEL_ELF)
	qemu-system-riscv64 \
	-machine virt \
	-nographic \
	-bios none \
	-kernel $(KERNEL_ELF)

test:$(KERNEL_ELF)
	qemu-system-riscv64 \
	-machine virt \
	-nographic \
	-bios none \
	-kernel $(KERNEL_ELF) \
	-S -s
	
gdb:$(KERNEL_ELF)
	gdb-multiarch $(KERNEL_ELF) \
		-ex "set architecture riscv:rv64" \
		-ex "target remote :1234" \
		-ex "b *0x80000000"
dump:$(KERNEL_ELF)
	$(DUMP) -d $(KERNEL_ELF) > main.asm

clean:
	rm -f */*.o *.elf main.asm