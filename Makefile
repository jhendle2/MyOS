build:
	# Initializing Kernel
	nasm -f elf32 asm/kernel.asm -o kasm.o
	gcc -fno-stack-protector -m32 -c src/kernel/kernel.c -o kc.o
	gcc -fno-stack-protector -m32 -c src/kernel/sys_props.c -o sps.o

	# Other Low Level Fun
	gcc -fno-stack-protector -m32 -c src/memory/heap.c -o heap.o
	gcc -fno-stack-protector -m32 -c src/shell/shell.c -o sh.o
	gcc -fno-stack-protector -m32 -c src/bin/bin.c -o bin.o

	# Stds
	gcc -fno-stack-protector -m32 -c src/std/string.c -o string.o
	gcc -fno-stack-protector -m32 -c src/std/math.c -o math.o
	gcc -fno-stack-protector -m32 -c src/std/print.c -o print.o
	gcc -fno-stack-protector -m32 -c src/std/datetime.c -o datetime.o
	gcc -fno-stack-protector -m32 -c src/std/args.c -o args.o

	# Bin


	# Entrypoint
	gcc -fno-stack-protector -m32 -c src/main.c -o m.o
	ld -m elf_i386 -T link.ld -o kernel kasm.o \
		kc.o sps.o heap.o sh.o bin.o \
		string.o math.o print.o \
		datetime.o m.o args.o

run:
	make build
	qemu-system-i386 -kernel kernel
