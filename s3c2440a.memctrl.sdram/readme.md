## 将程序拷贝到 SDRAM 上执行

### 一 例程效果

实现了板载 4 个 led 等循环点亮的效果，同一时刻只有一个 led 灯被点亮

### 二 例程逻辑

本例程在上电后第一时间初始化外部 64M 的 SDRAM，SDRAM 初始化成功后便跳转到 SDRAM 中执行 main 函数

程序的大致逻辑是：  

1. 关闭看门狗，防止系统一直异常复位  

2. 初始化 SDRAM，配置内存控制器寄存器

3. 将 SDRAM 中运行的程序拷贝到 SDRAM 0x30000000 位置处

3. 设置 C 语言的栈指针，准备 c 语言执行环境  
   栈是向下增长的，因此设置栈指针为 0x34000000，0x34000000 是板载 SDRAM 的最高地址

3. 跳转执行 C 语言 main 函数  
   初始化 led，配置 led 对应的 gpio 引脚为输出模式  
   控制 led，配置 led 对应的 gpio 引脚输出高低电平  

### 三 例程使用

在例程目录下执行 make 编译的到 s3c2440a.bin 文件

    user@vmware:~/mini2440/bare/s3c2440a.memctrl.sdram$ make
    user@vmware:~/mini2440/bare/s3c2440a.memctrl.sdram$ ls -l s3c2440a.*
    -rwxrwxr-x 1 user user   652 6月   2 19:31 s3c2440a.bin
    -rw-rw-r-- 1 user user  8934 6月   2 19:31 s3c2440a.dis
    -rwxrwxr-x 1 user user 34607 6月   2 19:31 s3c2440a.elf

使用 oflash 工具，下载到开发板 nandflash 中

    Z:\bare\s3c2440a.memctrl.sdram>oflash
