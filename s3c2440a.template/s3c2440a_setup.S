
#define S3C2440_MPLL_400MHZ     ()

.text
.global _start
_start:
        /* 关闭看门狗 */
        ldr     r0,     =0x53000000
        mov     r1,     #0x0
        str     r1,     [r0]

        /* 设置分频系数 FCLK:HCLK:PCLK = 8:2:1 */
        ldr     r0,     =0x4c000014
        mov     r1,     #0x05;
        str     r1,     [r0]

        /**
         * 根据 S3C2440A 数据手册要求:
         * 如果 HDIVN 非 0, 即 FLCK != HCLK,
         * CPU的总线模式应该从 "fast bus mode" 变为 "asynchronous bus mode"
         */
        mrc     p15,    0,  r1, c1, c0, 0       /* 读出控制寄存器 */ 
        orr     r1,     r1, #0xc0000000         /* 设置为 "asynchronous bus mode" */
        mcr     p15,    0,  r1, c1, c0, 0       /* 写入控制寄存器 */

        /* (2*(0x5c+8)*12MHz)/(0x01+2)*(2^0x01) = 400Mhz */
        ldr     r0,     =0x4c000004
        ldr     r1,     =(0x5c<<12) | (0x01<<4) | (0x01)
        str     r1,     [r0]

        /* 启动 ICACHE */
        mrc     p15,    0,  r0, c1, c0, 0       @ read control reg
        orr     r0,     r0, #(1<<12)
        mcr     p15,    0,  r0, c1, c0, 0       @ write it back

        /* 3. 初始化SDRAM */
        ldr     r0,     =0x48000000     @ BWSCON
        ldr     r1,     =0x22011110
        str     r1,     [r0]
        ldr     r0,     =0x48000004     @ BANKCON0
        ldr     r1,     =0x00000700
        str     r1,     [r0]
        ldr     r0,     =0x48000008     @ BANKCON1
        ldr     r1,     =0x00000700
        str     r1,     [r0]
        ldr     r0,     =0x4800000c     @ BANKCON2
        ldr     r1,     =0x00000700
        str     r1,     [r0]
        ldr     r0,     =0x48000010     @ BANKCON3
        ldr     r1,     =0x00000700
        str     r1,     [r0]
        ldr     r0,     =0x48000014     @ BANKCON4
        ldr     r1,     =0x00000700
        str     r1,     [r0]
        ldr     r0,     =0x48000018     @ BANKCON5
        ldr     r1,     =0x00000700
        str     r1,     [r0]
        ldr     r0,     =0x4800001c     @ BANKCON6
        ldr     r1,     =0x00018005
        str     r1,     [r0]
        ldr     r0,     =0x48000020     @ BANKCON7
        ldr     r1,     =0x00018005
        str     r1,     [r0]
        ldr     r0,     =0x48000024     @ REFRESH
        ldr     r1,     =0x008C07A3
        str     r1,     [r0]
        ldr     r0,     =0x48000028     @ BANKSIZE
        ldr     r1,     =0x000000B1
        str     r1,     [r0]
        ldr     r0,     =0x4800002c     @ MRSRB6
        ldr     r1,     =0x00000030
        str     r1,     [r0]
        ldr     r0,     =0x48000030     @ MRSRB7
        ldr     r1,     =0x00000030
        str     r1,     [r0]

        /* 4. 重定位 : 把bootloader本身的代码从flash复制到它的链接地址去 */
        ldr     sp,     =0x34000000

        bl      nand_init

        mov     r0,     #0
        ldr     r1,     =_start
        ldr     r2,     =__bss_start
        sub     r2,     r2, r1

        bl      copy_code_to_sdram
        bl      clear_bss

        /* 5. 执行main */
        ldr     lr,     =halt
        ldr     pc,     =main

halt:
        b halt
