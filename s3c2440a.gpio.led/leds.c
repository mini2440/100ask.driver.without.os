#define GPBCON (*(volatile unsigned long *)0x56000010)
#define GPBDAT (*(volatile unsigned long *)0x56000014)

void delay(volatile unsigned long dly)
{
        for(; dly > 0; dly--);
}

int main(void)
{
        // 设置 GPIOB4 GPIOB5 GPIOB6 GPIOB7 输出模式
        // GPBCON = 0000 0000 0000 0001 0101 0100 0000 0000
        GPBCON = 0x00015400;

        while(1)
        {
                // GPBDAT = 1111 1111 1111 1111 1111 1111 1101 1111
                GPBDAT = 0xffffffdf;
                delay(50000);

                // GPBDAT = 1111 1111 1111 1111 1111 1111 1011 1111
                GPBDAT = 0xffffffbf;
                delay(50000);

                // GPBDAT = 1111 1111 1111 1111 1111 1111 0111 1111
                GPBDAT = 0xffffff7f;
                delay(50000);

                // GPBDAT = 1111 1111 1111 1111 1111 1110 1111 1111
                GPBDAT = 0xfffffeff;
                delay(50000);
        }

        return 0;
}
