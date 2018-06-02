.text
.global _start
_start:
        ldr     r0,     =0x53000000     @ 关闭看门狗
        mov     r1,     #0x0
        str     r1,     [r0]
                                        @ 设置存储控制器
        ldr     r0,     =0x48000000     @ BWSCON
        ldr     r1,     =0x22011110
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
                                        @ 将 Steppingstone 的 4K 数据全部复制到 SDRAM 中去
        mov     r1,     #0              @ Steppingstone 起始地址为0x00000000
        ldr     r2,     =0x30000000     @ SDRAM 中起始地址为 0x30000000
        mov     r3,     #4096           @ 拷贝的数据长度为 4k
copy:
        ldr     r4,     [r1],   #4      @ 从 Steppingstone 读取4字节的数据, 并让源地址加4
        str     r4,     [r2],   #4      @ 将此4字节的数据复制到 SDRAM 中, 并让目地地址加4
        cmp     r1,     r3              @ 判断是否完成: 源地址等于 Steppingstone 的尾地址
        bne     copy                    @ 若没有复制完, 继续

        ldr     sp,     =0x34000000     @ 调用 c 语言代码之前需要先设置好堆栈
        bl      main                    @ 拷贝结束后跳到 SDRAM 中继续执行
loop:
        b       loop
