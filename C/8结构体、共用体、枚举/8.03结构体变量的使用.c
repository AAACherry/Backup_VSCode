/*
2.2 结构体变量的使用
    结构体变量对成员调用的方式：
        结构体变量.结构体成员
        注意：这地方说的结构体变量主要指的是普通结构体变量
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stu
{
    int id;
    char name[32];
    char sex;
    int age;
} zhangsan, lisi = {1002, "李四", 'B', 25};

typedef struct
{
    int id;
    char name[32];
    char sex;
    int age;
} STU;

void test1()
{
    struct stu wangwu;

    struct stu zhaoliu = {1001, "赵六", 'B', 21};

    STU stu1, stu2 = {1003, "7", 'B', 22};

    // 结构体变量的使用
    zhangsan.id = 1004;
    // zhangsan.name = "张三";//不能直接这样赋值，因为上面定义结构体的时候数组已经定义好了，如果这样赋值，将字符串常量的地址赋值给一个数组名，数组名是地址常量不能赋值
    strcpy(zhangsan.name, "张三");
    zhangsan.sex = 'B';
    zhangsan.age = 23;

    printf("%d-%s-%c-%d\n", zhangsan.id, zhangsan.name, zhangsan.sex, zhangsan.age);
    printf("%d-%s-%c-%d\n", lisi.id, lisi.name, lisi.sex, lisi.age);
    printf("%d-%s-%c-%d\n", zhaoliu.id, zhaoliu.name, zhaoliu.sex, zhaoliu.age);
    printf("%d-%s-%c-%d\n", stu2.id, stu2.name, stu2.sex, stu2.age);
}

// 在结构体中嵌套结构体
// 1.再写一个结构体1，然后在结构体2中传结构体名字即可
// 2.在结构体2中定义一个无名结构体也可
typedef struct
{ // 结构体没有开辟任何的空间，不能给里面的成员赋值，此时在定义类型，而不是定义变量
    int year;
    int month;
    int day;
} BD;

typedef struct
{
    int id;
    char name[32];
    BD birthday;
} MSG;

void test2()
{
    MSG xiaoming;
    xiaoming.id = 1006;
    strcpy(xiaoming.name, "小明");
    // 如果结构体中嵌套结构体，赋值时找到最内层的成员再赋值
    xiaoming.birthday.year = 2023;
    xiaoming.birthday.month = 10;
    xiaoming.birthday.day = 17;

    printf("%d-%s-%d-%d-%d\n", xiaoming.id, xiaoming.name, xiaoming.birthday.year, xiaoming.birthday.month, xiaoming.birthday.day);

    // 嵌套的形式定义的同时初始化
    MSG xiaoli = {1007, "小丽", {2000, 1, 1}}; // 最内层的花括号可以去掉，系统会自动一对一的形式匹配赋值
    printf("%d-%s-%d-%d-%d\n", xiaoli.id, xiaoli.name, xiaoli.birthday.year, xiaoli.birthday.month, xiaoli.birthday.day);
}

int main(int argc, char *argv[])
{
    test1();
    test2();
    return 0;
}