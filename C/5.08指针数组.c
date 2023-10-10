#include <stdio.h>

int main()
{
    //大多数情况下，指针数组都用来保存多个字符串
    char *name[5] = {"Follow me", "BASIC", "Greatwall", "FORIRAN", "Come"};
    int i;
    for (i = 0; i < 5;i++)
    {
        printf("%s\n", name[i]);
    }
        return 0;
}