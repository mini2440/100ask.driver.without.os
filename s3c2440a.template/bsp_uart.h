#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "s3c2440a.h"

#define TXD0READY   (1<<2)

#define PCLK            50000000    // init.c�е�clock_init��������PCLKΪ50MHz
#define UART_CLK        PCLK        //  UART0��ʱ��Դ��ΪPCLK
#define UART_BAUD_RATE  115200      // ������
#define UART_BRD        ((UART_CLK  / (UART_BAUD_RATE * 16)) - 1)

void uart0_init(void);
void putc(unsigned char c);
void puts(char *str);
void puthex(unsigned int val);

#endif
