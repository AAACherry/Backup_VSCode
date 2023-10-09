#include <stdio.h>

int main()
{
    int *p1, *p2, temp, a, b;
    p1 = &a;
    p2 = &b;

    printf("请输入a和b的值:\n");
    scanf("%d%d", p1, p2); // 给p1和p2指向的变量赋值

    // 交换值
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("a=%d,b=%d", a, b);
    printf("*p1=%d,*p2=%d", *p1, *p2);

    return 0;
}