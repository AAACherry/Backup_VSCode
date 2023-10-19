/*
规则1：以多少个字节为单位开辟内存
    给结构体变量分配内存的时候，会去结构体变量中找基本类型的成员
    哪个基本类型的成员占字节数多，就以它大大小为单位开辟内存,
    在gcc中出现了double类型的例外
    (1)：成员中只有char型数据 ，以1字节为单位开辟内存。
    (2)：成员中出现了short 类型数据，没有更大字节数的基本类型数据。以2字节为单位开辟内存
    (3)：出现了int 、float 没有更大字节的基本类型数据的时候以4字节为单位开辟内存。
    (4)：出现了double类型的数据

    情况1：
        在vc里，以8字节为单位开辟内存。
    情况2：
        在gcc里，以4字节为单位开辟内存。
    无论是那种环境，double型变量，占8字节。(5)：如果在结构体中出现了数组，数组可以看成多个变量的集合。
    如果出现指针的话，没有占字节数更大的类型的，以4字节为单位开辟内存。
    (6)：在内存中存储结构体成员的时候，按定义的结构体成员的顺序存储。

    规则2：字节对齐
    (1):char 1字节对齐 ，即存放char型的变量，内存单元的编号是1的倍数即可。
    (2):short 2字节对齐 ，即存放short int 型的变量，起始内存单元的编号是2的倍
    数即可。
    (3):int 4字节对齐 ，即存放int 型的变量，起始内存单元的编号是4的倍数即可
    (4):long 在32位平台下，4字节对齐 ，即存放long int 型的变量，起始内存单元的编号是4的倍数即可
    (5):float 4字节对齐 ，即存放float 型的变量，起始内存单元的编号是4的倍数即可
    (6)：
    double a.vc环境下:
        8字节对齐，即存放double型变量的起始地址，必须是8的倍数，double变量 占8字节
    b.gcc环境下:
        4字节对齐，即存放double型变量的起始地址，必须是4的倍数，double变量 占8字节。
    注意：
        当结构体成员中出现数组的时候，可以看成多个变量。
        开辟内存的时候，从上向下依次按成员在结构体中的位置顺序开辟空间
*/
// 为什么要有字节对齐？
// 目的:用空间来换取时间，提高cpu读取数据的效率

/*
指定对齐原则：
使用#pragma pack改变默认对齐原则
    格式：
        #pragma pack(value)时的指定对齐值value
    注意：
        1、value只能是：1、2、4、8等
        2、指定对齐值与数据类型对齐值相比取较小值
    说明：
        咱们制定一个value

    （1）：以多少个字节为单位开辟内存
        结构体成员中，占字节数最大的类型长度和value比较，
        取较小值，为单位开辟内存。
    #pragma pack(2)
        struct stu{
            char a;
            int b;
        }temp;//以2个字节为单位开辟内存
    int main()
    {
        printf("%d\n", sizeof(temp));
        printf("%p\n", &(temp.a));
        printf("%p\n", &(temp.b));
        printf("%p\n", &(temp.c));
    }//temp的大小为6个字节，a和b的地址差2个字节

    #pragma pack(8)
        struct stu{
            char a;
            int b;
        }temp;
    //以4个字节为单位开辟内存
    int main()
    {
        printf("%d\n", sizeof(temp));
        printf("%p\n", &(temp.a));
        printf("%p\n", &(temp.b));
    }//temp的大小为8个字节，a和b的地址差4个字节

    （2）：字节对齐
        结构体成员中成员的对齐方法，各个默认的对齐字节数和value相比，取较小值。
        #pragma pack(2)
        struct stu{
            char a;
            int b;
        }tamp;
    int main()
    {
        printf("%d\n", sizeof(temp));
        printf("%p\n", &(temp.a));
        printf("%p\n", &(temp.b));
    }//b成员是2字节对齐，a和b的地址差2个字节

    #pragma pack(8)
    struct stu{
        char a;
        int b;
    }tamp;
    int main()
    {
        printf("%d\n", sizeof(temp));
        printf("%p\n", &(temp.a));
        printf("%p\n", &(temp.b));
    }
    //a和b都按原先的对齐方式存储
    如： 如果指定对齐值：
        设为1：则short、int、float等均为1
        设为2：则char仍为1，short为2，int变为2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stu
{
    char a;
    short int b;
    int c; // 以4个字节开辟空间，因为这里最大的类型为int类型。
    // 开辟空间情况：//对于前两个类型而言，short最大为2个字节,所以以两个字节为单位开辟空间,不会挨着a存放,空出一个位置后存放
    //         1    2   3   4
    // 第一行： a        b   b   //中间这个位置相当于开辟了空间，但是不放任何内容
    // 第二行：      c          //占4个字节
} temp_1; // temp_1是8个字节

struct stu2
{
    char a;
    int c;
    short int b;
    // 开辟情况：
    //          1    2   3   4
    //  第一行： a               //后面开辟了空间，但是不放任何内容,int c 占4个字节，放不下，以四字节对齐原则，到下一行
    //  第二行：      c          //占4个字节
    //  第三行： b    b
} temp_2; // temp_2是12个字节

struct stu3
{
    char buf[10];
    int a;
    // 按照int的倍数开辟空间啊，10个字节要放在12个字节的空间里，int占四个字节，剩下的两个字节放不下继续开辟四个字节，
    // 所以说12+4=16(4的倍数，8＜10，所以取12＞10)
} temp_3; // temp_33占16个字节

struct stu4
{
    char a;
    double b;
    // 在vc中占16个字节，a和b的地址差8个字节;
    // 在gcc中占12个字节，a和b的地址差4个字节;  double占8个字节，但是整体按照4字节对齐原则
} temp_4;

int main()
{
    printf("%d\n", sizeof(temp_1));
    printf("%p\n", &(temp_1.a));
    printf("%p\n", &(temp_1.b));
    printf("%p\n", &(temp_1.c));
    // 结果:a和b的地址差2个字节，b和c的地址差2个字节

    printf("%d\n", sizeof(temp_2));
    printf("%p\n", &(temp_2.a));
    printf("%p\n", &(temp_2.b));
    printf("%p\n", &(temp_2.c));
    // 结果:a和b的地址差4个字节，b和c的地址差4个字节

    return 0;
}
