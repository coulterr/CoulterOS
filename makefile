all: files.hdd RileyOS.hdd

files.hdd: bin/files.bin
	dd status=noxfer conv=notrunc if=bin/files.bin of=files.hdd
bin/files.bin: obj/files.o
	ld -m elf_i386 --oformat=binary obj/files.o -o bin/files.bin
obj/files.o: filesystem/files.asm
	nasm -f elf filesystem/files.asm -o obj/files.o
RileyOS.hdd: bin/RileyOS.bin
	dd status=noxfer conv=notrunc if=bin/RileyOS.bin of=RileyOS.hdd
bin/RileyOS.bin: obj/boot_sect.o obj/bootloader.o obj/utils.o obj/pio_driver.o obj/char_queue.o obj/mallocator.o obj/kernel.o
	ld -e start -m elf_i386 -Ttext 0x7C00 --oformat=binary obj/boot_sect.o obj/bootloader.o obj/utils.o obj/pio_driver.o obj/char_queue.o obj/mallocator.o obj/kernel.o -o bin/RileyOS.bin
obj/kernel.o: kernel/kernel.c 
	gcc -m32 -ffreestanding -c kernel/kernel.c -o obj/kernel.o
obj/pio_driver.o: drivers/pio/pio_driver.c
	gcc -m32 -ffreestanding -c drivers/pio/pio_driver.c -o obj/pio_driver.o
obj/utils.o: utils/utils.c
	gcc -m32 -ffreestanding -c utils/utils.c -o obj/utils.o 
obj/char_queue.o: utils/queue/char_queue.c
	gcc -m32 -ffreestanding -c utils/queue/char_queue.c -o obj/char_queue.o
obj/mallocator.o: utils/mem/mallocator.c
	gcc -m32 -ffreestanding -c utils/mem/mallocator.c -o obj/mallocator.o
obj/bootloader.o: boot/bootloader.asm
	nasm -f elf boot/bootloader.asm -o obj/bootloader.o
obj/boot_sect.o: boot/boot_sect.asm
	nasm -f elf boot/boot_sect.asm -o obj/boot_sect.o
