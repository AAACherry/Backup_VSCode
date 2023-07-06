#include <stdio.h>
namespace Name_1
{
    namespace Name_1_1 //可嵌套定义命名空间
    {
        int num = 8;
    }
    int num = 10; //可定义变量
    float val;    //可定义变量
    void func_1() //可定义函数
    {
        printf("fun_1");
    }
    void fun_2();
} //(作用域)不要加分号;(相当于空语句，与前面无关)
/*
struct Mystruct{
}；
要加分号，因为该结构体内是定义域

void fun_2()
{
    printf("fun_2");
}
不加作用域符::就是普遍全局变量，不是命名空间中的函数;作用域符::可理解为“里面的”。
*/
void Name_1::fun_2() //如果此函数表示的是namespace命名空间中先声明过的函数，则要添加命名空间名+作用域符
{
    printf("fun_2");
}

namespace Name_1 //同一个命名空间（命名污染），也可以特意在不同的地方定义同一个命名空间（都可被访问）
{
    char ch;
}

namespace N = Name_1; //取别名，可简化命名空间名，增加可读性

int main()
{
    int num = 9;
    printf("num=%d\n", num);
    printf("num=%d\n", Name_1::num);
    printf("num=%d\n", Name_1::Name_1_1::num);
}