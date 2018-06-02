## 使用 GPIO 输出高低电平控制 LED 灯量灭

### 一 例程效果

实现了板载 4 个 led 等循环点亮的效果，同一时刻只有一个 led 灯被点亮。

### 二 例程逻辑

作为第一个简单的程序，没有初始化外部 64M 的 SDRAM，程序运行 S3C2440A 内部 4k 的 SRAM 中。

程序的大致逻辑是：  

1. 关闭看门狗，防止系统一直异常复位  

2. 设置 C 语言的栈指针，准备 c 语言执行环境  
   栈是向下增长的，因此设置栈指针为 4096，4096 是 S3C2440 内部 4K SRAM 的最高地址

3. 跳转执行 C 语言 main 函数  
   初始化 led，配置 led 对应的 gpio 引脚为输出模式  
   控制 led，配置 led 对应的 gpio 引脚输出高低电平  

### 三 例程使用

在例程目录下执行 make 编译的到 s3c2440a.bin 文件

    user@vmware:~/mini2440/bare/s3c2440a.gpio.led$ make
    user@vmware:~/mini2440/bare/s3c2440a.gpio.led$ ls -l s3c2440a.*
    -rwxrwxr-x 1 user user   516 6月   2 18:58 s3c2440a.bin
    -rw-rw-r-- 1 user user  6827 6月   2 18:58 s3c2440a.dis
    -rwxrwxr-x 1 user user 34450 6月   2 18:58 s3c2440a.elf

使用 oflash 工具，下载到开发板 nandflash 中

    Z:\bare\s3c2440a.gpio.led>oflash
