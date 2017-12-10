#include "bsp_delay.h"

/**
 * @brief 微妙级延时函数
 * @param 需要延时的 us 数
 */
void delay_us(v32 us)
{
        for(; us > 0; us--);
}

/**
 * @brief 毫秒级延时函数
 * @param 需要延时的 us 数
 */
void delay_ms(v32 ms)
{
        for(; ms > 0; ms--)
                delay_us(1000);
}
