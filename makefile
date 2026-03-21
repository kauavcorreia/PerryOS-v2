# Compiladores
CC = gcc
LD = ld
ASM = nasm

# Flags
CFLAGS = -ffreestanding -m32 -c
LDFLAGS = -T linker.ld -m elf_i386

# Diretórios
KERNEL_DIR = kernel
DRIVER_DIR = drivers
FS_DIR = fs

# Arquivos fonte
KERNEL_SRC = $(wildcard $(KERNEL_DIR)/*.c)
DRIVER_SRC = $(wildcard $(DRIVER_DIR)/*.c)
FS_SRC = $(wildcard $(FS_DIR)/*.c)

# Objetos
OBJS = $(KERNEL_SRC:.c=.o) $(DRIVER_SRC:.c=.o) $(FS_SRC:.c=.o)

# Bootloader
boot.bin:
	$(ASM) -f bin boot/boot.asm -o boot.bin

# Compilar tudo
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Linkar kernel
kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o kernel.bin

# Criar sistema final
perryos.bin: boot.bin kernel.bin
	cat boot.bin kernel.bin > perryos.bin

# Build completo
all: perryos.bin

# Rodar no QEMU
run: perryos.bin
	qemu-system-i386 -drive format=raw,file=perryos.bin

# Limpar
clean:
	rm -f kernel/*.o drivers/*.o fs/*.o *.bin