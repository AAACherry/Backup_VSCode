
/*
头文件 : #include<string.h>
函数定义 : ssize_t strlen(const char *s);
size_t,_t类型的，称之为类整型
函数功能:
    测字符指针s指向的字符串中字符的个数，不包括'\0'
返回值:
    字符串中字符个数
 */

#include <stdio.h>
#include <string.h>

int main()
{
    // 使用strlen函数获取字符串的长度
    // strlen获取的字符串的长度遇到第一个\0就结束
    char s1[100] = "hello";

    printf("s1_len = %d\n", strlen(s1));  // 测字符串的长度，并且遇到第一个\0就停止
    printf("s1_size = %d\n", sizeof(s1)); // 获取当前数组所开辟的空间的大小

    char s2[10] = "hel\0lo";

    printf("s2_len = %d\n", strlen(s2)); // 并且遇到第一个\0就停止
    printf("s2_size = %d\n", sizeof(s2));

    char *str1 = 'hello'; // 将一个字符串常量的地址赋值给指针变量
    // 数组保存字符串和指针变量保存字符串的地址完全是两码事,数组的可以进行修改，指针变量无法进行修改
    printf("str1_len = %d\n", strlen(str1));  // 还是去看字符串，遇第一个\0结束
    printf("str1_size = %d\n", sizeof(str1)); // 理论上应该是6个字节(加上\0)，其实是因为sizeof获取到的是str1的大小，但是str1是应该指针变量，所以在32位的操作系统中，不管指针变量是什么类型都是4个字节，所以结果为4。

    return 0;
}
