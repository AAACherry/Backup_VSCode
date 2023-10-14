/*
void free(void *ptr)//返回值类型为void,即没有返回值，而不是void *
功能：释放堆区的空间
参数：
    ptr：开辟后使用完毕的堆区的空间的首地址
返回值：
    无

注意：
    free函数只能释放堆区的空间，其他区域的空间无法使用free
    free释放空间必须释放malloc或者calloc或者realloc的返回值对应的空间，不能说只释放一部分。

    free释放空间并不是说把这段内存直接删了，而是说相当于告诉了系统我不再使用这块空间了，其他对象可以使用这段空间。但是我还是知道这块空间的地址，因为p还保存着原本这块空间的地址。
    free(p); 注意当free后，因为没有给p赋值，p就是一个栈区普通的指针变量，所以p还是指向原先动态申请的内存。但是内存已经不能再用了，p变成野指针了，所以一般为了防止野指针，会free完毕之后对p赋为NULL。

    一块动态申请的内存只能free一次，不能多次free

//使用free函数释放空间
free(p);
//防止野指针
p=NULL;
*/
#include <stdio.h>
#include <stdlib.h>
char *fun()
{

    char *str = malloc(100 * sizeof(char));

    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = '\0';

    return str;
}

int main(int argc, int argv[])
{
    char *p;
    p = fun();
    printf("p=%s\n", p);
    free(p);
    // 防止野指针,当再对p操作的时候，不可能再找到这块堆区空间了。
    p = NULL;
    return 0;
}
