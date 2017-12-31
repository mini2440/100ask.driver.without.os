#include "main.h"
#include "bsp_led.h"
#include "bsp_delay.h"

/* 定义 LCD 对应 GPIO 的控制器寄存器 */
#define GPGCON          REG(0x56000060)
#define GPGDAT          REG(0x56000064)

int main()
{
        /* 设置 LCD PWR 对应的 GPIO 为输出模式 */
        /* 0000 0000 | 0000 0000 | 0000 0011 | 0000 0000 */
        GPGCON &= ~0x00000300;
        /* 0000 0000 | 0000 0000 | 0000 0001 | 0000 0000 */
        GPGCON |= 0x00000100;

        /* 设置 LCD PWR 对应的 GPIO 为输出 0 */
        /* 0000 0000 | 0000 0000 | 0000 0000 | 0001 0000 */
        GPGDAT &= ~0x00000010;

        led_init();
        while(1)
        {
                led_light(1, 0, 0, 0);
                delay_ms(100);
                led_light(0, 1, 0, 0);
                delay_ms(100);
                led_light(0, 0, 1, 0);
                delay_ms(100);
                led_light(0, 0, 0, 1);
                delay_ms(100);
        }
        return 0;
}
