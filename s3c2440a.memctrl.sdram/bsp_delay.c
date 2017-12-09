#include "bsp_delay.h"

void delay_us(v32 us)
{
	for(; us > 0; us--);
}

void delay_ms(v32 ms)
{
	for(; ms > 0; ms--)
		delay_us(1000);
}
