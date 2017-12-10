#include "main.h"
#include "bsp_led.h"
#include "bsp_delay.h"

int main()
{
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
