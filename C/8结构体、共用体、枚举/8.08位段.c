/*
一、位段
在结构体中，以位为单位的成员，咱们称之为位段(位域)。
struct packed_data
{
    unsigned int a : 2;
    unsigned int b : 6;
    unsigned int c : 4;
    unsigned int d : 4;
    unsigned int i;//什么也不加就以字节为单位
} data;
注意：不能对位段成员取地址(地址都是以字节为单位，以位为单位是不能取地址的)
#include<stdio.h>
struct packed_data{
unsigned int a:2;
unsigned int b:6;
unsigned int c:4;
unsigned int d:4;
unsigned int i;
} data;
int main()
{
printf("%d\n",sizeof(data));
printf("%p\n",&data);//结构体，可以取地址
printf("%p\n",&(data.i));//i以字节为地址，可以取其地址。其他的成员无法取地址
return 0;
}

位段注意：
    1、对于位段成员的引用如下：
        data.a =2
        赋值时，不要超出位段定义的范围;
        如段成员a定义为2位，最大值为3,即（11）2
        所以data.a =5，超出范围就会取5的低两位(01)进行赋值 原：101
    2、位段成员的类型必须指定为整形或字符型
    3、一个位段必须存放在一个存储单元中，不能跨两个单元
    第一个单元空间不能容纳下一个位段，则该空间不用，而从下一个单元起存放该位段

位段的存储单元：
    (1)：char型位段，存储单元是1个字节
    (2)：short int型的位段存储单元是2个字节
    (3)：int的位段，存储单元是4字节
    (4)：long int的位段，存储单元是4字节
    struct stu{
        char a:7;
        char b:7;
        char c:2;
    }temp;//占3字节，b不能跨 存储单元存储
    #include<stdio.h>
    struct stu{
        char a:7;
        char b:7;
        char c:2;
    }temp;
    int main()
    {
        printf("%d\n",sizeof(temp));
        return 0;
    }
    结果为：3 ,证明位段不能跨其存储单元存储
    注意：不能 取 temp.b的地址，因为b可能不够1字节，不能取地址。

    4、位段的长度不能大于存储单元的长度
        (1)：char型位段不能大于8位
        (2)：short int型位段不能大于16位
        (3)：int的位段，位段不能大于32位
        (4)：long int的位段，位段不能大于32位
    #include<stdio.h>
        struct stu{
        char a:9;
        char b:7;
        char c:2;
    }temp;
    int main()
    {
        printf("%d\n",sizeof(temp));
        return 0;
    }
分析：
    编译出错，位段a不能大于其存储单元的大小

    5、如一个段要从另一个存储单元开始，可以定义：
        unsigned char a:1;
        unsigned char b:2;
        unsigned char :0;
        unsigned char c:3;(另一个单元)
    由于用了长度为0的位段，其作用是使下一个位段从下一个存储单元开始存放
    将a、b存储在一个存储单元中，c另存在下一个单元
    #include<stdio.h>
    struct m_type{
        unsigned char a:1;
        unsigned char b:2;
        unsigned char :0;
        unsigned char c:3;
    };
    int main()
    {
        struct m_type temp;
        printf("%d\n",sizeof(temp));
        return 0;
    }//占2个字节

    6、可以定义无意义位段,如：
        unsigned a: 1;
        unsigned : 2;
        unsigned b: 3;
        struct data{
            char a:1;
            char b:1;
            char c:1;
            char d:1;
            char e:1;
            char f:1;
            char g:1;
            char h:1;
        }temp;
        int main()
        {
            char p0;
            //p0=0x01;// 0000 0001
            temp.a=1;
            //p0=temp;//错的，类型不匹配
            //p0=(char)temp;//错的，编译器不允许将结构体变量，强制转成基本类型的。
            p0 = *((char *)(&temp));
        }
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    return 0;
}
