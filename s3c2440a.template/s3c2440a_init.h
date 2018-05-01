#ifndef __BSP_NANDFLASH_H
#define __BSP_NANDFLASH_H

#include "s3c2440a.h"

void copy_code_to_sdram(unsigned char *src, unsigned char *dest, unsigned int len);
void clear_bss(void);

#endif
