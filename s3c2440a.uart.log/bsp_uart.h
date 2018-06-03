#ifndef _BSP_UART_H_
#define _BSP_UART_H_

#include "main.h"

/* GPIO */
#define GPHCON          REG32(0x56000070)
#define GPHUP           REG32(0x56000078)

/* UART */
#define ULCON0          REG32(0x50000000)
#define UCON0           REG32(0x50000004)
#define UFCON0          REG32(0x50000008)
#define UMCON0          REG32(0x5000000c)
#define UTRSTAT0        REG32(0x50000010)
#define UTXH0           REG08(0x50000020)
#define URXH0           REG08(0x50000024)
#define UBRDIV0         REG32(0x50000028)

#define TXD0READY       (1<<2)

#define PCLK            50000000        // init.c中的clock_init函数设置PCLK为50MHz
#define UART_CLK        PCLK            // UART0的时钟源设为PCLK
#define UART_BAUD_RATE  115200          // 波特率
#define UART_BRD        ((UART_CLK / (UART_BAUD_RATE * 16)) - 1)

void uart0_init(void);
void putc(unsigned char c);
void puts(char *str);
void puti(int dec, int nest);
void putx(unsigned int val);
void printf(const char *format,...);

#endif /* _BSP_UART_H_ */
