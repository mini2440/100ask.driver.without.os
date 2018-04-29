#ifndef __BSP_NANDFLASH_H
#define __BSP_NANDFLASH_H

#include "s3c2440a.h"

#define TACLS   0
#define TWRPH0  1
#define TWRPH1  0

int isBootFromNorFlash(void);
void copy_code_to_sdram(unsigned char *src, unsigned char *dest, unsigned int len);
void clear_bss(void);
void nand_init(void);
void nand_select(void);
void nand_deselect(void);
void nand_cmd(unsigned char cmd);
void nand_addr(unsigned int addr);
void nand_wait_ready(void);
unsigned char nand_data(void);
void nand_read(unsigned int addr, unsigned char *buf, unsigned int len);

#endif
