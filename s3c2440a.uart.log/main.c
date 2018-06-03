#include "main.h"
#include "bsp_uart.h"

int main(void)
{
        uart0_init();

        char ch = 'A';
        char *str = "hello world";
        int dec = 1234;
        int hex = 0xabcd;
        printf("ch = %c, str = %s, dec = %d, hex = %x\r\n", ch, str, dec, hex);

        int zero = 0;
        printf("zero = %d\r\n", zero);

        return 0;
}
