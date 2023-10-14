#include <stdio.h>

// const修饰全局变量，既不能直接拿变量进行修改，也不能拿地址进行修改
// 此时全局变量只能使用但是不能修改，
// 如果直接拿全局变量修改值，编译直接报错
// 如果使用全局变量的地址修改值，运行时程序异常结束。
const int a = 100;
void test1()
{
    printf("a = %d\n", a); // 能不能拿变量a去输出结果

    // a = 666;
    // printf("a = %d\n", a);//能不能拿变量a去修改相应的值//只读的修改不了

    int *p = &a;
    *p = 888;
    printf("a = %d\n", a); // 能不能指针变量保存全局变量的地址
}

// const修饰普通局部变量
// 可以读取变量的值
// 不能直接通过变量进行修改值，编译报错
// 可以通过变量的地址修改值
void test2()
{
    const int b = 100;
    printf("b = %d\n", b);

    // b = 666;
    // printf("b = %d\n", b);// 能不能拿变量b去修改相应的值

    int *p = &b;
    *p = 888;
    printf("b = %d\n", b); // 能不能指针变量保存全局变量的地址
}

// 修饰指针变量的类型还是修饰指针变量？
//  const修饰指针变量
//  如果const修饰指针变量的类型，无法通过指针变量修改地址里面的值
//  如果const修饰指针变量，无法修改指针变量保存的地址
//  如果const既修饰指针变量的类型，又修饰指针变量，则只能通过原本变量修改值
void test3()
{
    int c = 100;
    // const修饰指针变量的类型,不能通过指针变量修改其地址里面的值(*p = 777;报错)
    // const int * p = &c;
    // const修饰指针变量,无法修改指针变量保存的地址(p = &d;报错)
    // int * const p = &c;
    // const既修饰指针变量的类型，又修饰指针变量,则只能通过原本变量修改值。(*p = 777;p = &d;都报错)
    const int *const p = &c;
    printf("*p = %d\n", *p);

    /*
    // 在没有用const修饰时，怎么样改变*p的值？
    c = 666; // 1、直接通过变量进行修改
    printf("*p = %d\n", *p);
    *p = 777; // 2、直接让*p去修改值
    printf("*p = %d\n", *p);
    int d = 888; // 3、重新再定义一个变量
    p = &d;      // 然后让p保存新的变量的值
    printf("*p = %d\n", *p);
    */
}
int main(int argc, char *argv[])
{
    test3();
    return 0;
}