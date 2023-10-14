/*
#include <string.h>
函数定义:int strcmp(const char *s1, const char *s2);
函数定义:int strncmp(const char *s1, const char *s2, size_t n);
功能：
    strcmp是比较两个字符串的内容，strncmp是比较两个字符串的前n个字节是否一样
参数：
    s1、s2：要比较的两个字符串
    n：strncmp中的参数n表示要比较的字节数
返回值：
    0    s1 = s2
    >0   s1 > s2
    <0   s1 < s2
注意！！这里s1 > s2返回正数，s1 < s2返回负数，相等返回0。并没有规定是1还是 - 1。
 */

#include <stdio.h>
#include <string.h>

int main()
{
    // 使用strcmp比较两个字符串的内容是否一致

    char s1[] = "hello"; // 在定义一个数组的同时给它赋值，可以不写数组元素的个数
    char s2[] = "hella";
    // char s2[] = "w";//如果是w与hello比较,则s1<s2。
    // 因为strcmp进行比较的时候是一个字符一个字符逐个比较，只要有不一样的就立即返回。

    // int ret = strcmp(s1, s2);//o的ASCII值>a，所以应是s1>s2
    int ret = strncmp(s1, s2, 4);

    if (ret == 0)
    {
        printf("s1=s2\n");
    }
    else if (ret < 0)
    {
        printf("s1<s2");
    }
    else
    {
        printf("s1>s2");
    }

    return 0;
}