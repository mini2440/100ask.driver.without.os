#include "bsp_sdram.h"

void sdram_init(void)
{
        BWSCON   = 0x22011110;
        BANKCON0 = 0x00000700;
        BANKCON1 = 0x00000700;
        BANKCON2 = 0x00000700;
        BANKCON3 = 0x00000700;
        BANKCON4 = 0x00000700;
        BANKCON5 = 0x00000700;
        BANKCON6 = 0x00018005;
        BANKCON7 = 0x00018005;
        REFRESH  = 0x008C07A3;
        BANKSIZE = 0x000000B1;
        MRSRB6   = 0x00000030;
        MRSRB7   = 0x00000030;
}

void sdram_copy_steppingstone(void)
{
        int sram_start_addr = 2048;
        int sdram_start_addr = 0x30000000;
        int sram_satrt_lenght = 2048;
        int i = 0;
        int j = 5;
        for(i = 0; i < sram_satrt_lenght; i--) {
                REG(sdram_start_addr + i) = REG(sram_start_addr + i);
                while(j--);
                j = 5;
        }
}
