/*
1.1 基本概述
    构造类型：
    1、不是基本类型的数据结构也不是指针，它是若干个相同或不同类型的数据构成的集合
    2、常用的构造类型有 数组、结构体、共用体
    3、数组 用于 保存多个相同类型的数据
    4、结构体 用于 保存多个不同类型的数据

1.2 结构体的概念
    1、结构体是一种构造类型的数据结构，
    2、是一种或多种基本类型或构造类型的数据的集合。
*/

/* 1.3 结构体类型的定义
1.3.1 先定义结构体类型，再去定义结构体变量 struct 结构体类型名
    {
        成员列表
    };

    例子：
         struct stu
        {
            int num;
            char name[20];
            char sex;
        };

    // 有了结构体类型后，就可以用类型定义变量了
    struct stu lucy, bob, lilei; // 定义了三个struct stu类型的变量，注意不要把struct省略
    每个变量都有三个成员，分别是num name sex

1.3.2 在定义结构体类型的时候顺便定义结构体变量，以后还可以定义结构体变量
        struct 结构体类型名{
            成员列表;
        }结构体变量1,变量2;
        struct 结构体类型名 变量3，变量4；
    例子：
        struct stu{
        int num;
        char name[20];
        char sex;
        }lucy,bob,lilei;
        struct stu xiaohong,xiaoming;
    注意：一般结构体类型都会定义在全局，也就是main函数的外面，
    所以在定义结构体类型的同时定义变量，这些变量一般都是全局变量，
    定义完类型之后定义的结构体变量内存分配要看定义的位置。

1.3.3 无名结构体的定义
        在定义结构体类型的时候，没有结构体类型名，顺便定义结构体变量，
        因为没有类型名，所以以后不能再定义相关类型的数据了
        struct {
        成员列表;
        }变量1，变量2;
    注意：无名结构体由于没有结构体名，所以定义完之后是无法在定义结构体变量的，只能在
    定义类型的同时定义结构体变量
    例子：
        struct {
        int num;
        char name[20];
        char sex;
        }lucy,bob;

1.3.4 给结构体类型取别名
        通常咱们将一个结构体类型重新起个类型名，用新的类型名替代原先的类型
        typedef struct 结构体名 {
            成员列表;
        }重新定义的结构体类型名A;
    注意：typedef主要用于给一个类型取别名，此时相当于给当前结构体重新起了一个类型名为A，
    相当于 struct 结构体名，所以如果结构体要取别名，一般不需要先给结构体定义名字，
    定义结构体变量时，直接使用A即可，不用加struct
        例子：
        typedef struct stu{
       int num;
        char name[20];
        char sex;
        }STU;
    以后STU 就相当于 struct stu
    STU lucy;和struct stu lucy;是等价的，所以可以不指定stu这个名字
*/

#include <stdio.h>
#include <string.h>

int main()
{
    return 0;
}