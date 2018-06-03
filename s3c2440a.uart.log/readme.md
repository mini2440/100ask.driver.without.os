## 使用串口实现 printf 函数

### 一 例程效果

通过串口实现简易的 printf 函数，能够打印调试信息，方便日后调试

### 二 例程逻辑

程序的大致逻辑是：

1. 关闭看门狗，防止系统一直异常复位

2. 初始化时钟，CPU 运行在 400Mhz  
   设置时钟分频系数，设置 CPU 工作在异步模式，使能 MPLL

3. 初始化 SDRAM，配置内存控制器寄存器

4. 将 SDRAM 中运行的程序拷贝到 SDRAM 0x30000000 位置处

5. 设置 C 语言的栈指针，准备 c 语言执行环境
   栈是向下增长的，因此设置栈指针为 0x34000000，0x34000000 是板载 SDRAM 的最高地址

6. 跳转执行 C 语言 main 函数  
   初始化 UART0  
   实现 putc 函数打印一个字符  
   使用 putc 实现 puti、putx、puts 函数  
   封装成支持可变参数的 printf 函数  
   使用 printf 函数打印示例

### 三 例程使用

在例程目录下执行 make 编译的到 s3c2440a.bin 文件

    user@vmware:~/mini2440/bare/s3c2440a.uart.log$ make
    user@vmware:~/mini2440/bare/s3c2440a.uart.log$ ls -l s3c2440a.*
    -rwxrwxr-x 1 user user  1148 6月   3 10:23 s3c2440a.bin
    -rw-rw-r-- 1 user user 13652 6月   3 10:23 s3c2440a.dis
    -rwxrwxr-x 1 user user 35193 6月   3 10:23 s3c2440a.elf

使用 oflash 工具，下载到开发板 nandflash 中

    Z:\bare\s3c2440a.uart.log>oflash

使用串口线连接 PC 和开发板，PC 运行串口终端，接收开发板打印信息

    ch = A, str = hello world, dec = 1234, hex = 0000ABCD
    zero =

对照源码发现 0 是打印不出来的，这个后续在看看怎么优化它

```
#include "main.h"
#include "bsp_uart.h"

int main(void)
{
        uart0_init();

        char ch = 'A';
        char *str = "hello world";
        int dec = 1234;
        int hex = 0xabcd;
        printf("ch = %c, str = %s, dec = %d, hex = %x\r\n", ch, str, dec, hex);

        int zero = 0;
        printf("zero = %d\r\n", zero);

        return 0;
}
```

这里顺便推荐下 Xshell 工具，还是很好用的：

![Xshell](https://raw.githubusercontent.com/mini2440/100ask.driver.without.os.material/master/s3c2440a.uart.log/xshell.png)

### 四 参考资料

fengxin的博客 [实现简单的printf函数](https://blog.csdn.net/fengxinlinux/article/details/52064816)
