#include "s3c2440a.h"
#include "bsp_uart.h"
#include "bsp_nandflash.h"

int main(void)
{
        uart0_init();
        puts("main.c\n\r");
        return 0;
}
