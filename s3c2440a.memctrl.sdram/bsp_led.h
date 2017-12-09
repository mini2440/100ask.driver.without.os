#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "main.h"

#define GPBCON		REG(0x56000010)
#define GPBDAT		REG(0x56000014)

void led_init(void);
void led_light(u8 led1, u8 led2, u8 led3, u8 led4);

#endif /* _BSP_LED_H_ */
