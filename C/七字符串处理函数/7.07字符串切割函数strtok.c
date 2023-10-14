/*
头文件:#include <string.h>
函数定义:char *strtok(char *str, const char *delim);
功能：对字符串进行切割
参数：
    str：要切割的字符串
第一次切割，就传入指定的字符串，后面所有次的切割传NULL
    delim：标识符，要根据指定的delim进行切割，切割的结果不包含delim
返回值：
    返回切割下来的字符串的首地址，如果都切割完毕，则返回NULL
*/

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    // 使用strtok函数切割字符串
    char s[] = "111:22222:33:4444444444:5555555555555";
    char *ret;
    // 第一次切割
    ret = strtok(s, ":");
    printf("ret = %s\n", ret);
    // 后面所有切割时都要将strtok的第一个参数传NULL
    while ((ret = strtok(NULL, ":")) != NULL)
    {
        printf("ret = %s\n", ret);
    }
    return 0;
}