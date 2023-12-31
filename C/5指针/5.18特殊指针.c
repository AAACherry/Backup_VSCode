#include <stdio.h>

/*
回顾：对应类型的指针只能存放对应类型的数据地址
void *通用指针，任何类型的指针都可以给void *类型的指针变量赋值。主要也是用在函数的参数和返回值的位置
int *p;
void *q;
q = p 是可以的，不用强制类型转换

举例子：
有个函数叫memset
void * memset(void *s,int c,size_t n);
这个函数的功能是将s指向的内存前n个字节,全部赋值为c
Memset可以设置字符数组、整型数组、浮点型数组的内容，所以第一个参数，就必须是个通用指针
它的返回值是s指向的内存的首地址，可能是不同类型的地址。所以返回值也得是通用指针

注意：void*类型的指针变量，也是个指针变量，在32为系统下，占4个字节
*/

/* 2、NULL 空指针：
char *p = NULL;//NULL本质上来说就是将0强转成了void *型的0
咱们可以认为p哪里都不指向，也可以认为p指向内存编号为0的存储单位。
在p的四个字节中，存放的是0x00 00 00 00
一般NULL用在给指针初始化。//如果定义了一个指针变量，没有给它赋值的话一定要给一个NULL
 */

int main()
{
    return 0;
}