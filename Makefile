CROSS = riscv64-unknown-elf-
CC = $(CROSS)gcc
LD = $(CROSS)ld
OBJCOPY = $(CROSS)objcopy
OBJDUMP = $(CROSS)objdump

CFLAGS = -Wall -Werror -O0 -g -ffreestanding -fno-omit-frame-pointer -nostdlib -nostartfiles -mcmodel=medany -fno-pie -no-pie
LDFLAGS = -T linker.ld

KERNEL_ELF = main.elf
KERNEL_BIN = main.bin

OBJS = \
	kernel/main.o \
	kernel/start.o

all: $(KERNEL_ELF)

$(KERNEL_ELF): $(OBJS) linker.ld
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

$(KERNEL_BIN): $(KERNEL_ELF)
	$(OBJCOPY) -O binary $(KERNEL_ELF) $(KERNEL_BIN)

kernel/start.o: kernel/start.S
	$(CC) $(CFLAGS) -c $< -o $@

kernel/main.o: kernel/main.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel/uart.o: kernel/uart.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(KERNEL_ELF)
	qemu-system-riscv64 \
		-machine virt \
		-nographic \
		-bios none \
		-kernel $(KERNEL_ELF)

test: $(KERNEL_ELF)
	qemu-system-riscv64 \
		-machine virt \
		-nographic \
		-bios none \
		-kernel $(KERNEL_ELF) \
		-S -s

dump: $(KERNEL_ELF)
	$(OBJDUMP) -d $(KERNEL_ELF) > kernel.asm

clean:
	rm -f $(OBJS) $(KERNEL_ELF) $(KERNEL_BIN) kernel.asm