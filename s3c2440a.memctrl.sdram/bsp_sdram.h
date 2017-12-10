#ifndef _BSP_SDRAM_H_
#define _BSP_SDRAM_H_

#include "main.h"

#define BWSCON          REG(0x48000000)
#define BANKCON0        REG(0x48000004)
#define BANKCON1        REG(0x48000008)
#define BANKCON2        REG(0x4800000c)
#define BANKCON3        REG(0x48000010)
#define BANKCON4        REG(0x48000014)
#define BANKCON5        REG(0x48000018)
#define BANKCON6        REG(0x4800001c)
#define BANKCON7        REG(0x48000020)
#define REFRESH         REG(0x48000024)
#define BANKSIZE        REG(0x48000028)
#define MRSRB6          REG(0x4800002c)
#define MRSRB7          REG(0x48000030)

void sdram_init(void);

#endif /* _BSP_SDRAM_H_ */
