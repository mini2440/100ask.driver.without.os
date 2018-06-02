#include "main.h"
#include "bsp_uart.h"

int main()
{
        volatile int i, j;
        uart0_init();

        int a = 9;
        puthex(a);

        return 0;
}
