#include "s3c2440a.h"
#include "bsp_nandflash.h"

void clear_bss(void)
{
        extern int __bss_start, __bss_end;
        int *p = &__bss_start;
        
        for (; p < &__bss_end; p++)
                *p = 0;
}

void copy_code_to_sdram(unsigned char *src, unsigned char *dest, unsigned int len)
{
        int i = 0;
        
        /* 如果是NOR启动 */
        if (isBootFromNorFlash())
        {
                while (i < len)
                {
                        dest[i] = src[i];
                        i++;
                }
        }
        else
        {
                //nand_init();
                nand_read((unsigned int)src, dest, len);
        }
}