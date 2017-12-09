#ifndef _MAIN_H_
#define _MAIN_H_

#define u8	unsigned char
#define u16 	unsigned short
#define u32	unsigned long

#define v8	volatile unsigned char
#define v16 	volatile unsigned short
#define v32	volatile unsigned long

#define REG(n) 	(*(volatile unsigned long *)(n))

#endif /* _MAIN_H_ */
