#include "bsp_led.h"

/**
 * @brief 初始化 LED
 */
void led_init(void)
{
        /* 设置 LED 灯对应的 GPIO 为输出模式 */
        /* 0000 0000 | 0000 0011 | 1111 1100 | 0000 0000 */
        GPBCON &= ~0x0003fc00;
        /* 0000 0000 | 0000 0001 | 0101 0100 | 0000 0000 */
        GPBCON |= 0x00015400;

        /* 设置 LED 灯对应的 GPIO 为输出 1 */
        /* 0000 0000 | 0000 0000 | 0000 0001 | 1110 0000 */
        GPBDAT &= 0x00000000;
}

/**
 * @brief 点亮指定的 led 灯
 * @param led[1234]: 0 表示熄灭, 非 0 表示点亮
 */
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
