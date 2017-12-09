SECTIONS {
	firtst	0x00000000: { startup.o bsp_sdram.o }
	second	0x30000000: AT(2048) { main.o bsp_led.o bsp_delay.o }
}
