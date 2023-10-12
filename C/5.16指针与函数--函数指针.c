#include <stdio.h>
/*函数指针
//函数指针最常用的地方在于将一个函数作为参数传递给另一个函数的时候要使用函数指针
//作用：本质上来说函数指针就是用来保存函数地址的
函数指针：指针保存函数的地址。本质是一个指针，函数指向指针。
咱们定义的函数，在运行程序的时候，会将函数的指令加载到内存的代码段，所以函数也有起始地址。

定义：返回值类型(*函数指针变量名)(形参列表);

c语言规定：函数的名字就是函数的首地址，即函数的入口地址 咱们就可以定义一个指针变量，来存放函数的地址，这个指针变量就是函数指针变量。

用函数指针去调用函数：原本可以用num=max(3,5),现在可以用int num; int(*p)(int,int); p=max; num=(*p)(3,5);
直接num=p(3,5)也可以。一般情况下用函数名去调用就行了，没必要定义一直函数指针去调用
 */
// 函数指针数组
// 函数指针数组本质上是一个数组，数组里面每一个元素都是一个函数指针
// 定义:返回值类型(*函数指针变量名[函数指针的个数])(形参列表);
// 即 int (*p[10](int,int));在函数指针的变量名后面加一个中括号，中括号里面跟个数字就可以了。

// 函数指针最常用的地方在于将一个函数作为参数传递给另一个函数的时候要使用函数指针
// 将一个函数作为参数传递给另一个函数，将这函数称之为回调函数

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mux(int x, int y)
{
    return x * y;
}

int dive(int x, int y)
{
    return x / y;
}

int process(int (*p)(int, int), int a, int b) // 该函数中没有以上四个函数，但是四个函数都想去使用，
// 于是定义了一个函数指针作为process函数的参数。并且将a和b的值也传递给了process函数
// 我们就可以直接在这个函数里面将原本的这些函数名拿过来作为参数传进来之后就可以实现相应的功能
{
    int ret;
    ret = (*p)(a, b);
    return ret;
}

int main(int argc, char *argv[])
{
    int num;
    num = process(add, 2, 3);
    printf("num= %d\n", num);

    num = process(sub, 2, 3);
    printf("num= %d\n", num);

    num = process(mux, 2, 3);
    printf("num= %d\n", num);

    num = process(dive, 2, 3);
    printf("num= %d\n", num);

    return 0;
}