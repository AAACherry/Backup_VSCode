/*
即结构体的地址，结构体变量存放内存中，也有起始地址
咱们定义一个变量来存放这个地址，那这个变量就是结构体指针变量。
1、结构体指针变量的定义方法：
struct 结构体类型名 *结构体指针变量名;

2、结构体指针变量对成员的引用
    (*结构体指针变量名).成员
    结构体指针变量名‐ > 成员
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
};

int main(int argc, char const *argv[])
{
    // 定义一个结构体指针变量
    struct stu *s;
    // 在堆区开辟结构体空间并将其地址保存在结构体变量中
    s = (struct stu *)malloc(sizeof(struct stu));

    s->id = 1001;
    strcpy(s->name, "张三");
    s->sex = 'B';
    s->age = 20;

    printf("%d-%s-%c-%d\n", s->id, s->name, s->sex, s->age);

    return 0;
}
