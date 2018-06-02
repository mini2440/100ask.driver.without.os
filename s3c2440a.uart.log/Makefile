CFLAGS := -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -ffreestanding

s3c2440a.bin : startup.s main.c bsp_uart.c
	arm-linux-gcc $(CFLAGS) -c -o startup.o startup.s
	arm-linux-gcc $(CFLAGS) -c -o main.o main.c
	arm-linux-gcc $(CFLAGS) -c -o bsp_uart.o bsp_uart.c
	arm-linux-ld --Ttext 0x30000000 startup.o main.o bsp_uart.o -o s3c2440a.elf
	arm-linux-objcopy -O binary -S s3c2440a.elf s3c2440a.bin
	arm-linux-objdump -D -m arm s3c2440a.elf > s3c2440a.dis
	rm -rf *.o
clean:
	rm -f s3c2440a.dis s3c2440a.bin s3c2440a.elf *.o
