/*
 结构体数组是个数组，由若干个相同类型的结构体变量构成的集合
1、结构体数组的定义方法
struct 结构体类型名 数组名[元素个数];
    例子：
    struct stu
    {
        int num;
        char name[20];
        char sex;
    };
    struct stu edu[3];
    定义了一个struct stu 类型的结构体数组edu，
    这个数组有3个元素分别是edu[0] 、edu[1]、edu[2]

2、结构体数组元素的引用
    数组名[下标]
3、结构体数组元素对成员的使用
    数组名[下标].成员
*/

#include <stdio.h>
#include <string.h>

typedef struct 
{
    int num;
    char name[20];
    float score;
}STU;

int main(int argc, char const *argv[])
{
    //定义一个结构体数组
    STU edu[3] = {//初始化不加大括号也可以，只要按顺序传会自动进行赋值。
        {101, "lucy", 78},
        {102, "Bob", 59.5},
        {103, "Tom", 85}};

    //输出结构体数组中的元素
    int j;
    for (j = 0; j < 3;j++)
    {
        printf("%d-%s-%.2f\n", edu[j].num, edu[j].name, edu[j].score);
    }

        int i;
    float sum = 0;
    for (i = 0; i < 3;i++)
    {
        sum += edu[i].score;
    }

    printf("平均成绩:%f\n", sum / 3);
    return 0;
}
