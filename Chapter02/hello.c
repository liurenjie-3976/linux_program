#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

void fred(int i){
    printf("fred: we passed %d\n", i);
}

int main(void)
{
    fred(1);
    printf("Hello, world!\n");
    exit(0);
}

// gcc -I/home/jj/linux_pro/Beginning-Linux-Programming/Chapter02/lib.h hello.c -o hello
//这一段是指定自己的头文件的路径，这样就可以在自己的头文件中使用<>来包含自己的头文件了。

//鱼为什么会飞
