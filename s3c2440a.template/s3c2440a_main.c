#include "s3c2440a.h"
#include "bsp_uart.h"
#include "bsp_nandflash.h"
#include "s3c2440a_init.h"

int main(void)
{
        volatile int i, j;
        uart0_init();

        for(i = 0; i < 10; i++)
        {
                puts("main.c\n\r");
                for(j = 4000000; j > 0; j--);
        }

        return 0;
}
