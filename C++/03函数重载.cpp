#include <stdio.h>

int func(int n)
{
}

float func(float a)
{
}

void func(double b)
{
}

double func(int n, float v)
{
}

int main()
{
    func(3.14);      //小数默认为双精度(字面量默认双精度)
    func((int)3.14); //强转为int类型
    func(5);
    func(3, 3.5f); //规定3.5为float类型
    return 0;
}