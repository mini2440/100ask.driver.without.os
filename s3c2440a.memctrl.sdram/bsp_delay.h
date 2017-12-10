#ifndef _BSP_DELAY_H_
#define _BSP_DELAY_H_

#include "main.h"

/**
 * @brief 微妙级延时函数
 * @param 需要延时的 us 数
 */
void delay_us(v32 us);

/**
 * @brief 毫秒级延时函数
 * @param 需要延时的 us 数
 */
void delay_ms(v32 ms);

#endif /* _BSP_DELAY_H_ */
