/*
#include <stdio.h>
函数定义:int sprintf(char *str, const char *format, ...);
功能：将按照格式保存的字符串复制给str
参数：
    str：保存字符串
    format：同printf
返回值：
    保存的字符串的字节数


#include<stdio.h>
函数定义:int sscanf(const char *str, const char *format, ...);
功能：scanf是从终端读取数据并赋值给对应变量，而sscanf是从第一个参数中读取数据
参数：
    str：指定要获取内容的字符串
    format：按照格式获取数据保存在变量中
返回值：
    成功获取的个数
*/

#include <stdio.h>
#include <string.h>
// sprintf和sscanf的基本用法
void test1()
{
    char buf[20];
    int a, b, c;

    sprintf(buf, "%d:%d:%d", 2013, 10, 1);
    printf("buf = %s\n", buf);

    sscanf("2013:10:1", "%d:%d:%d", &a, &b, &c); // 可以用字符串分割函数，然后再通过atoi将数字型字符串转换成整形数据保存在变量abc当中。
    printf("a=%d,b=%d,c=%d\n", a, b, c);
}

// sscanf高级用法
void test2()
{
    // 1、跳过数据：%*s或%*d。
    // 在%和相应的字符中间加一个*，这个*叫做抑制符，只要加了*的这一串字符是不会保存在变量当中的
    char buf1[20];
    sscanf("1234 5678", "%*d %s", buf1);
    printf("%s\n", buf1);

    // 2、读指定宽度的数据：%[width]s
    char buf2[20];
    sscanf("12345678", "%4s ", buf2);
    printf("%s\n", buf2);

    // 3、支持集合操作：只支持获取字符串
    // %[a‐z] 表示匹配a到z中任意字符(尽可能多的匹配)
    // %[aBc] 匹配a、B、c中一员，贪婪性
    // %[^aFc] 匹配非a、F、c的任意字符，贪婪性
    // %[^a‐z] 表示读取除a‐z以外的所有字符
    char buf3[20];
    sscanf("agcd32DajfDdFF", "%[a‐z]", buf3);
    printf("%s\n", buf3);
}

int main()
{
    test1();
    test2();
    return 0;
}
