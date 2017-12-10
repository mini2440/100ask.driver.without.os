CFLAGS 	:= -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -ffreestanding

s3c2440a.bin : startup.s bsp_led.c bsp_delay.c bsp_sdram.c main.c
        arm-linux-gcc $(CFLAGS) -c -o startup.o startup.s
        arm-linux-gcc $(CFLAGS) -c -o bsp_sdram.o bsp_sdram.c
        arm-linux-gcc $(CFLAGS) -c -o bsp_led.o bsp_led.c
        arm-linux-gcc $(CFLAGS) -c -o bsp_delay.o bsp_delay.c
        arm-linux-gcc $(CFLAGS) -c -o main.o main.c
        arm-linux-ld -Ts3c2440a.lds startup.o bsp_sdram.o bsp_led.o bsp_delay.o main.o -o s3c2440a.elf
        arm-linux-objcopy -O binary -S s3c2440a.elf s3c2440a.bin
        arm-linux-objdump -D -m arm s3c2440a.elf > s3c2440a.dis
        rm -rf *.o
clean:
        rm -f s3c2440a.dis s3c2440a.bin s3c2440a.elf *.o
