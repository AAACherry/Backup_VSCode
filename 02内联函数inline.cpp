#include <stdio.h>

inline void func(int num);

int main()
{
    func(6);
}

inline void func(int num)
{
    printf("void func(int num);num=%d\n", num);
}

/*
语法：在返回值类型前面加上inline

inline 返回值类型 函数名（）
{
      函数体；
}
*/
