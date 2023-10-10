#include <stdio.h>

int main()
{
    int a = 100;
    //定义一个一级指针
    //一级指针用于保存普通变量的地址
    int *p = &a;

    //定义一个二级指针
    //二级指针用于保存一级指针的地址
    int **q = &p;
    
    //定义一个三级指针
    //三级指针保存的是二级指针的地址
    int ***m = &q;

    printf("a=%d%d%d\n",a,)

    return 0;
}