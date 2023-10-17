#include <stdio.h>

int main()
{
    //定义一个普通变量
    int a = 100;
    //定义一个指针变量
    int *p;
    //给指针变量赋值
    //将a的地址保存在p中
    p = &a;

    printf("a=%d %d\n", a, *p);
    printf("&a=%p %p\n", &a, p);

    return 0;
}