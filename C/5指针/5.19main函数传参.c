#include <stdio.h>

int main(int argc, int *argv[])
{
    // agrc:是一个int类型的变量，标识命令终端传入的参数的个数
    // argv:是一个指针数组，用于保存每一个命令终端传入的参数

    int i;
    printf("argc=%d\n", argc);
    for (i = 0; i < argc; i++)
    {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    return 0;
}