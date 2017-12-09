#include "bsp_led.h"

void led_init(void)
{
	GPBCON = 0x00015400;
}

void led_light(u8 led1, u8 led2, u8 led3, u8 led4)
{
	if(led1){
		GPBDAT &= (~0x00000020);
	} else {
		GPBDAT |= 0x00000020;
	}

	if(led2){
		GPBDAT &= (~0x00000040);
	} else {
		GPBDAT |= 0x00000040;
	}

	if(led3){
		GPBDAT &= (~0x00000080);
	} else {
		GPBDAT |= 0x00000080;
	}

	if(led4){
		GPBDAT &= (~0x00000100);
	} else {
		GPBDAT |= 0x00000100;
	}
}
