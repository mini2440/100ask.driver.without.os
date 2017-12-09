.text
.global _start
_start:
	ldr	sp,	=4096			@ 调用 C 函数之前需要先初始化栈
	ldr	r0,	=0x53000000		@ 关闭看门狗
	mov	r1,	#0x0
	str	r1,	[r0]
	bl	sdram_init			@ 初始化 SDRAM
	bl	sdram_copy_steppingstone	@ 复制 steppingstone 中代码到 SDRAM 中
	ldr	sp,	=0x34000000		@ 在 SDRAM 中重新设置栈空间
	ldr	lr,	=halt_loop		@ 设置 main 函数返回地址
	ldr	pc,	=main			@ 调用 SDRAM 中的 main 函数
halt_loop:
	b	halt_loop
