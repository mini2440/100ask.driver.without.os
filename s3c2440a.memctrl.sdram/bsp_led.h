#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "main.h"

/* 定义 LED 对应 GPIO 的控制器寄存器 */
#define GPBCON          REG(0x56000010)
#define GPBDAT          REG(0x56000014)

/**
 * @brief 初始化 LED
 */
void led_init(void);

/**
 * @brief 点亮指定的 led 灯
 * @param led[1234]: 0 表示熄灭, 非 0 表示点亮
 */
void led_light(u8 led1, u8 led2, u8 led3, u8 led4);

#endif /* _BSP_LED_H_ */
