KERNEL_ELF = main.elf

OBJS = \
	main.o \
	start.o 

$(KERNEL_ELF): $(OBJS)
	riscv64-unknown-elf-gcc -T linker.ld -o main.elf $(OBJS) -nostdlib -ffreestanding

main.o:
	riscv64-unknown-elf-gcc -c main.S -o main.o
start.o:
	riscv64-unknown-elf-gcc -c start.S -o start.o

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
	
gdb: $(KERNEL_ELF)
	gdb-multiarch $(KERNEL_ELF) \
		-ex "set architecture riscv:rv64" \
		-ex "target remote :1234" \
		-ex "b *0x80000000"