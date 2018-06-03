CC       = arm-linux-gcc
LD       = arm-linux-ld
AR       = arm-linux-ar
OBJCOPY  = arm-linux-objcopy
OBJDUMP  = arm-linux-objdump

CFLAGS   := -Wall -O2
CPPFLAGS := -nostdlib -fno-builtin

objs := startup.o bsp_uart.o main.o

s3c2440a.bin: $(objs)
	${LD} -Ttext 0x30000000 -o s3c2440a.elf $^
	${OBJCOPY} -O binary -S s3c2440a.elf $@
	${OBJDUMP} -D -m arm s3c2440a.elf > s3c2440a.dis

%.o: %.c
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o: %.S
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o: %.s
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.bin *.elf *.dis
