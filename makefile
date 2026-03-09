all: perryos.bin

boot.bin: boot/boot.asm
	nasm -f bin boot/boot.asm -o boot.bin

kernel.o: kernel/kernel.c
	gcc -ffreestanding -c kernel/kernel.c -o kernel.o

kernel.bin: kernel.o
	ld -T linker.ld kernel.o -o kernel.bin

perryos.bin: boot.bin kernel.bin
	cat boot.bin kernel.bin > perryos.bin

run: perryos.bin
	qemu-system-x86_64 perryos.bin

clean:
	rm -f *.bin *.o
