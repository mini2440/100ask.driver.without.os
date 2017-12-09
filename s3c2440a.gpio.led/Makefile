CFLAGS := -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -ffreestanding
leds.bin : startup.s  leds.c
	arm-linux-gcc $(CFLAGS) -c -o startup.o startup.s
	arm-linux-gcc $(CFLAGS) -c -o leds.o leds.c
	arm-linux-ld -Ttext 0x0000000 startup.o leds.o -o leds_elf
#	arm-linux-ld -Tleds.lds startup.o leds.o -o leds_elf
	arm-linux-objcopy -O binary -S leds_elf leds.bin
	arm-linux-objdump -D -m arm  leds_elf > leds.dis
clean:
	rm -f   leds.dis leds.bin leds_elf *.o
