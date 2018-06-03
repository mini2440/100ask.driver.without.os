#include "bsp_uart.h"

//#include<stdlib.h>
#include<stdarg.h>

/**
 * @brief 初始化 UART0
 * @note 115200, 8N1, 无流控
 */
void uart0_init(void)
{
        GPHCON |= 0xa0;         // GPH2, GPH3用作TXD0,RXD0
        GPHUP   = 0x0c;         // GPH2, GPH3内部上拉

        ULCON0  = 0x03;         // 8N1(8个数据位，无较验，1个停止位)
        UCON0   = 0x05;         // 查询方式，UART时钟源为PCLK
        UFCON0  = 0x00;         // 不使用FIFO
        UMCON0  = 0x00;         // 不使用流控
        UBRDIV0 = UART_BRD;     // 波特率为115200
}

/**
 * @brief 串口 log 函数
 * @note 目前仅支持 %c %d %s %x 选项
 */
void printf(const char *format, ...)
{
        va_list ap;

        /* 将ap指向第一个实际参数的地址 */
        va_start(ap,format);
        while(*format)
        {
                if(*format != '%')
                {
                        putc(*format);
                        format++;
                }
                else
                {
                        format++;
                        switch(*format)
                        {
                                case 'c':
                                {
                                        /* 记录当前实践参数所在地址 */
                                        char valch = va_arg(ap, int);
                                        putc(valch);
                                        format++;
                                        break;
                                }
                                case 'd':
                                {
                                        int valint = va_arg(ap, int);
                                        puti(valint, 0);
                                        format++;
                                        break;
                                }
                                case 's':
                                {
                                        char *valstr = va_arg(ap, char *);
                                        puts(valstr);
                                        format++;
                                        break;
                                }
                                case 'x':
                                {
                                        unsigned int valhex = va_arg(ap, unsigned int);
                                        putx(valhex);
                                        format++;
                                        break;
                                }
                                default:
                                {
                                        putc(*format);
                                        format++;
                                }
                        }
                }
        }
        va_end(ap);
}

/**
 * @brief 发送一个字符
 */
void putc(unsigned char c)
{
        /* 等待，直到发送缓冲区中的数据已经全部发送出去 */
        while (!(UTRSTAT0 & TXD0READY));

        /* 向UTXH0寄存器中写入数据，UART即自动将它发送出去 */
        UTXH0 = c;
}

/**
 * @brief 发送一个字符串
 */
void puts(char *str)
{
        int i = 0;
        while (str[i])
        {
                putc(str[i]);
                i++;
        }
}

/**
 * @brief 发送一个整型数
 * @param dec 将要打印的整形数字
 * @param nest 循环嵌套计数变量
 */
void puti(int dec, int nest)
{
        if(dec == 0)
        {
                if(nest)
                {
                        return;
                }
                else
                {
                        putc('0');
                        return;
                }
        }
        nest++;
        puti(dec / 10, nest);
        putc((char)(dec % 10 + '0'));
}

/**
 * @brief 发送一个 16 进制数
 * @note 打印长度固定为 8 位
 */
void putx(unsigned int val)
{
        int i;
        int j;

        for (i = 0; i < 8; i++)
        {
                j = (val >> ((7-i)*4)) & 0xf;
                if ((j >= 0) && (j <= 9))
                        putc('0' + j);
                else
                        putc('A' + j - 0xa);
        }
}
