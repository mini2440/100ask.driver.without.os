#include "bsp_uart.h"

/*
 * ��ʼ��UART0
 * 115200,8N1,������
 */
void uart0_init(void)
{
        GPHCON |= 0xa0;         // GPH2,GPH3����TXD0,RXD0
        GPHUP   = 0x0c;         // GPH2,GPH3�ڲ�����

        ULCON0  = 0x03;         // 8N1(8������λ���޽��飬1��ֹͣλ)
        UCON0   = 0x05;         // ��ѯ��ʽ��UARTʱ��ԴΪPCLK
        UFCON0  = 0x00;         // ��ʹ��FIFO
        UMCON0  = 0x00;         // ��ʹ������
        UBRDIV0 = UART_BRD;     // ������Ϊ115200
}

/*
 * ����һ���ַ�
 */
void putc(unsigned char c)
{
        /* �ȴ���ֱ�����ͻ������е������Ѿ�ȫ�����ͳ�ȥ */
        while (!(UTRSTAT0 & TXD0READY));

        /* ��UTXH0�Ĵ�����д�����ݣ�UART���Զ��������ͳ�ȥ */
        UTXH0 = c;
}

void puts(char *str)
{
        int i = 0;
        while (str[i])
        {
                putc(str[i]);
                i++;
        }
}

void puthex(unsigned int val)
{
        /* 0x1234abcd */
        int i;
        int j;

        puts("0x");

        for (i = 0; i < 8; i++)
        {
                j = (val >> ((7-i)*4)) & 0xf;
                if ((j >= 0) && (j <= 9))
                        putc('0' + j);
                else
                        putc('A' + j - 0xa);
        }
}
