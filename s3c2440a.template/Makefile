CC       = arm-linux-gcc
LD       = arm-linux-ld
AR       = arm-linux-ar
OBJCOPY  = arm-linux-objcopy
OBJDUMP  = arm-linux-objdump

CFLAGS   := -Wall -O2
CPPFLAGS := -nostdinc -nostdlib -fno-builtin

objs     := start.o bsp_uart.o bsp_nandflash.o main.o

s3c2440a.bin: $(objs)
	${LD} -Ts3c2440a.lds -o s3c2440a.elf $^
	${OBJCOPY} -O binary -S s3c2440a.elf $@
	${OBJDUMP} -D -m arm s3c2440a.elf > s3c2440a.dis

%.o:%.c
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o:%.S
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.bin *.elf *.dis
