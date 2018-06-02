#ifndef _MAIN_H_
#define _MAIN_H_

/* 重定义数据结构 */
#define u8      unsigned char
#define u16     unsigned short
#define u32     unsigned long

#define v8      volatile unsigned char
#define v16     volatile unsigned short
#define v32     volatile unsigned long

/* 定义寄存器宏 */
#define REG08(addr)     (*((volatile unsigned char *)addr))
#define REG16(addr)     (*((volatile unsigned int  *)addr))
#define REG32(addr)     (*((volatile unsigned long *)addr))

#endif /* _MAIN_H_ */
