#include <stdio.h>

// 咱们可以给一个函数传一个 整型、字符型、浮点型的数据，也可以 给函数传一个地址。
// 函数的传参方式：复制传参、地址传参、全局传参（几乎用不到）

// 函数的传参方式之复制传参：将实参的值传递给形参，不管形参怎么改变，跟实参都没有关系
void myfun(int a, int b)
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

// 就想在函数体内部交换两个变量的值，如果直接把a和b传给形参，那么其实就相当于把地址传给函数体内部。如果在函数体内部对地址进行操作，相当于实参a和b的值就会改变
// 函数的传参方式之地址传参:将实参的地址传递给形参，形参对保存的地址的内容
// 进行任何操作，实参的值会跟着改变
void myfun2(int *p, int *q) // 要传的是地址，这里就定义指针来接收
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

    myfun2(&a, &b);
    printf("after fun:a=%d,b=%d\n", a, b);
    printf("a=%p,b=%p\n", &a, &b);
}
// 总结一句话：要想改变主调函数中变量的值，必须传变量的地址，而且还得通过*+地址去赋值。无论这个变量是什么类型的。

// 注意：如果实参是一个普通变量，地址传参的话需要形参是一个一级指针。
// 以此类推：如果实参是一个一级指针，地址传参的话需要形参是一个二级指针。
void fun(int *p) // int **p结果才是hello kitty
{
    p = "hello kitty";
}
int main()
{
    test1();

    char *p = "Hello world";
    fun(p);            // 传了一个指针常量（指针传指针）//如果结果要为hello kitty，那么应是&p
    printf("%s\n", p); // 结果为：Hello world
    // 在fun中改变的是fun函数中的局部变量p,并没有改变main函数中的变量p，所以main函数中的变量p还是指向hello world
    // 如果就想改变p的值，那么应该传实参的地址给形参。当前是一级指针，那么应该传一级指针的地址给形参，也就意味着要传一个二级指针

    return 0;
}