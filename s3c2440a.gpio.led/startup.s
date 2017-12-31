.text
.global _start
_start:
        ldr     sp,     =4096           @ 调用 C 函数之前需要先初始化栈
        ldr     r0,     =0x53000000     @ 关闭看门狗
        mov     r1,     #0x0
        str     r1,     [r0]
        ldr     lr,     =loop           @ 设置 main 函数返回地址
        ldr     pc,     =main           @ 调用 SRAM 中的 main 函数
loop:
        b       loop
