/*
头文件：#include <string.h>
函数定义:char *strcat(char *dest, const char *src);
功能：将src追加到dest的后面 
参数： 
    dest：目的字符串 
    src：源字符串 
返回值： 
    保存dest字符串的首地址 

char *strncat(char *dest, const char *src, size_t n);
追加src指向的字符串的前n个字符，到dest指向的字符串的后面。 
注意如果n 大于src的字符个数，则只将src字符串追加到dest指向的字符串的后面 
追加的时候会追加’\0’
 */
#include <stdio.h>
#include <string.h>

int main()
{
    //使用strcat函数追加字符串
    char s1[32] = "hello world";
    char s2[32] = "abcdef";

    //strcat是从\0的位置开始追加，直到s2的第一个\0复制完毕之后结束
    //也要保存s1足够大
    strcat(s1, s2);

    printf("s1 = %s\n", s1);
    return 0;
}