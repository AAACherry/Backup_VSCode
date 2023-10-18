// 必须是相同类型的结构体变量，才能可以相互赋值

#include <stdio.h>
#include <string.h>

struct stu
{
    int id;
    char name[32];
    char sex;
    int age;
};

int main()
{
    struct stu zhangsan;
    zhangsan.id = 1001;
    strcpy(zhangsan.name, "张三");
    zhangsan.sex = 'B';
    zhangsan.age = 18;
    printf("%d-%s-%c-%d\n", zhangsan.id, zhangsan.name, zhangsan.sex, zhangsan.age);

    // 结构体变量，尤其是相同类型的结构体变量之间，是可以直接赋值的。
    struct stu lisi;
    lisi = zhangsan;
    lisi.id = 1002;
    strcpy(lisi.name, "李四");
    printf("%d-%s-%c-%d\n", lisi.id, lisi.name, lisi.sex, lisi.age);
    return 0;
}