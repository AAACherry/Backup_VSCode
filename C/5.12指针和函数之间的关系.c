#include <stdio.h>

//咱们可以给一个函数传一个 整型、字符型、浮点型的数据，也可以 给函数传一个地址。
//函数的传参方式：复制传参、地址传参、全局传参（几乎用不到）

//函数的传参方式之复制传参：将实参的值传递给形参，不管形参怎么改变，跟实参都没有关系
void myfun(int a,int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    printf("in fun:a=%d,b=%d\n", a, b);
    printf("a=%p,b=%p\n", &a, &b);
}

void test1()
{
    int a = 100, b = 20;
    printf("before fun:a=%d,b=%d\n", a, b);
    printf("a=%p,b=%p\n", &a, &b);

    myfun(a, b);
    printf("after fun:a=%d,b=%d\n", a, b);
    printf("a=%p,b=%p\n", &a, &b);
}

//就想在函数体内部交换两个变量的值，如果直接把a和b传给形参，那么其实就相当于把地址传给函数体内部。如果在函数体内部对地址进行操作，相当于实参a和b的值就会改变
//函数的传参方式之地址传参:将实参的地址传递给形参，形参对保存的地址的内容
//进行任何操作，实参的值会跟着改变
void myfun2(int *p,int *q)//要传的是地址，这里就定义指针来接收
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;

    printf("*p=%d,*q=%d\n", *p, *q);
    printf("p=%p.q=%p\n", p, q);
}

void test2()
{
    int a = 100, b = 20;
    printf("before fun:a=%d,b=%d\n", a, b);
    printf("a=%p,b=%p\n", &a, &b);

    myfun2(&a,&b);
    printf("after fun:a=%d,b=%d\n", a, b);
    printf("a=%p,b=%p\n", &a, &b);
}

int main()
{
    test1();
    return 0;
}