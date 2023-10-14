/*
头文件:#include <string.h>
函数的定义:char *strcpy(char *dest, const char *src);
功能：
    将src复制给dest
参数：
    dest：目的字符串
    src：源字符串
返回值：
    目的内存的地址(保存dest字符串的首地址)
注意：使用strcpy函数复制字符串时必须保证dest足够大，否则会内存溢出
    strcpy是将src字符串中第一个\0之前包括\0复制给dest

char *strncpy(char *dest, const char *src, size_t n);
函数的说明：
    将src指向的字符串前n个字节，拷贝到dest指向的内存中
返回值 :
    目的内存的首地址
注意：
    1、strncpy不拷贝 '\0'
    2、如果n大于src指向的字符串中的字符个数，则在dest后面填充n‐strlen(src)个'\0' */

#include <stdio.h>
#include <string.h>

int main()
{
    // 使用strcpy函数拷贝字符串
    char s1[32] = "hello world";
    // 使用strcpy函数时，必须保证第一个参数的内存足够大
    // char s1[5]="abcd";
    char s2[32] = "abcdefg";

    printf("s1=%s\n", s1);
    printf("s2=%s\n", s2);

    strcpy(s1, s2); // 后者字符串赋值给前者，所以必须要保证前者的字符串足够大

    printf("s1=%s\n", s1);
    printf("s2=%s\n", s2);

    // for循环验证:s1长度>s2,s1直接变成s2,s1后面的数据有没有丢失/覆盖？
    int i;
    for (i = 0; i < 32; i++)
    {
        printf("[%c]-%d\n", s1[i], s1[i]); // 挨个输出一下32个字节的数组里面的内容到底是什么。
        //%c是直接输出字符,%d输出字符ASCII值
        // ASCII值为0是\0,\0后面r、l、d（world后三位）还是存在在我们的s1当中。只不过遇到了一个\0,所以printf在输出的时候也是遇第一个\0结束,所以第一次输出结果里面只有abcdefg。
        // 基本所有跟字符串相关的函数都是遇第一个\0结束
    }
    return 0;
}