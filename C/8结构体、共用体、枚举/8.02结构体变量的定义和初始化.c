/*
2.1 结构体变量的定义和初始化
    结构体变量，是个变量，这个变量是若干个数据的集合
    注：
        (1) : 在定义结构体变量之前首先得有结构体类型，然后在定义变量
        (2) : 在定义结构体变量的时候，可以顺便给结构体变量赋初值，被称为结构体的初始化
        (3) : 结构体变量初始化的时候，各个成员顺序初始化
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义结构体类型
struct stu
{
    int id;
    char name[32];
    char sex;
    int age;
    // 定义结构体变量之定义结构体类型的同时定义结构体变量
} zhangsan, lisi = {1002, "李四", 'B', 25};

// 使用typedef，对结构体变量取别名
typedef struct
{
    int id;
    char name[32];
    char sex;
    int age;
} STU;

int main(int argc, char *argv[])
{
    // 定义结构体变量之类型定义完毕之后定义变量
    struct stu wangwu;
    // 结构体变量的初始化
    struct stu zhaoliu = {1001, "赵六", 'B', 21};

    // 如果使用typedef堆结构体取别名
    // 就无法在定义类型的同时定义结构体变量
    // 在定义结构体变量的时候不加struct
    STU stu1, stu2 = {1003, "7", 'B', 22};

    return 0;
}