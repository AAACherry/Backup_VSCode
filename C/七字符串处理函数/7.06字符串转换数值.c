/*
头文件:#include <stdlib.h>
函数定义:int atoi(const char *nptr);//注意,必须要保证这个字符串是纯数字型的字符串
功能：将一个数字型字符串转化为整形数据
参数：
    nptr：指定的字符串
返回值：
    获取到的整形数据

long atol(const char *nptr);
double atof(const char *nptr);
*/
// 用于命令行传参的时候在main函数内将接收的参数转换

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    // 使用atoi将数字型字符串转化为整形数据
    char s1[] = "7856";
    int ret1 = atoi(s1);
    printf("ret1 = %d\n", ret1);

    // 使用atof将浮点型的字符串转化为浮点型数据
    char s2[] = "3.1415926";
    double ret2 = atof(s2);
    printf("ret2 = %lf\n", ret2);
    return 0;
}