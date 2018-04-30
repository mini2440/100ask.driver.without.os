#ifndef __S3C2440A_H
#define __S3C2440A_H

#define u8  unsigned char
#define u16 unsigned short
#define u32 unsigned long

/* Registers */
#define REG08(addr)     (*((volatile unsigned char *)addr))
#define REG16(addr)     (*((volatile unsigned int  *)addr))
#define REG32(addr)     (*((volatile unsigned long *)addr))

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

/* NAND FLASH */
#define NFCONF          REG32(0x4E000000)
#define NFCONT          REG32(0x4E000004)
#define NFCMMD          REG08(0x4E000008)
#define NFADDR          REG08(0x4E00000C)
#define NFDATA          REG08(0x4E000010)
#define NFSTAT          REG08(0x4E000020)

#endif
