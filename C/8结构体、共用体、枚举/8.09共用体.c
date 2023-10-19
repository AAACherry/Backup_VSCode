/*
1：共用体和结构体类似，也是一种构造类型的数据结构。 既然是构造类型的，咱们得先定义出类型，然后用类型定义变量。
    定义共用体类型的方法和结构体非常相似，把struct 改成union 就可以了。
        在进行某些算法的时候，需要使几种不同类型的变量存到同一段内存单元中，几个变量
        所使用空间相互重叠
        这种几个不同的变量共同占用一段内存的结构，在C语言中，被称作“共用体”类型结构
        共用体所有成员占有同一段地址空间
        共用体的大小是其占内存长度最大的成员的大小

    typedef struct data{//12个字节
        short int i;
        char ch;
        float f;
    }DATA;
    DATA temp1;
    结构体变量temp1最小占7个字节（不考虑字节对齐）

     typedef union data{//4个字节
        short int i;
        char ch;
        float f;
    }DATA;
    DATA temp2;
    共用体temp2占4个字节，即i、ch、f共用4个字节

    int main()
    {
        DATA temp2;
        printf("%d\n",sizeof(temp2));
        printf("%p\n",&temp2);
        printf("%p\n",&(temp2,i));
        printf("%p\n",&(temp2,ch));
        printf("%p\n",&(temp2,f));
        return 0;
    }
    结果；temp2的大小为4个字节，下面几个地址都是相同的，证明了共用体的各个成员占用同一块内存。

    共用体的特点：
        1、同一内存段可以用来存放几种不同类型的成员，但每一瞬时只有一种起作用
        2、共用体变量中起作用的成员是最后一次存放的成员，在存入一个新的成员后原有的成员的值会被覆盖
        3、共用体变量的地址和它的各成员的地址都是同一地址
        4、共用体变量的初始化 union data a={123}; 初始化共用体为第一个成员
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义一个共用体
union un{
    int a;
    int b;
    int c;
};

int main(int argc, char const *argv[])
{
    //定义共用体变量
    union un myun;
    myun.a = 100;
    myun.b = 200;
    myun.c = 300;

    printf("a=%d,b=%d,c=%d\n", myun.a, myun.b, myun.c);//结果都是300

    return 0;
}
