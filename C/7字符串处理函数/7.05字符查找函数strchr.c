/*
头文件：#include <string.h>
函数定义:char *strchr(const char *s, int c);//(int c)可不传ASCII值，改为一个字符
功能：在字符指针s指向的字符串中，找ascii 码为c的字符
参数：
    s：指定的字符串
    c：要查找的字符
返回值：
    成功：找到的字符的地址
    失败：NULL
注意：strchr查找的是首次匹配,s指向的字符串中有多个ASCII为c的字符，则找的是第1个字符

函数定义:char *strrchr(const char *s, int c);
函数说明:末次匹配
功能：在s指向的字符串中，找最后一次出现的ASCII为c的字符，
返回值:
    末次匹配的字符的地址
*/
#include <stdio.h>
#include <string.h>

int main()
{
    // 使用strchr函数在一个字符串中查找字符
    char s[] = "hel6lo wor6ld";
    // 找第一个匹配的字符
    //  char *ret = strchr(s, '6'); // 最好保存返回值
    // 找最后一个匹配的字符
    char *ret = strrchr(s, '6');

    if (ret == NULL)
    {
        printf("no found\n");
    }
    else
    {
        printf("yes,pos= %d\n", ret - s); // 想求位置怎么求? 可以采用地址相减的方式去求
    }

    return 0;
}