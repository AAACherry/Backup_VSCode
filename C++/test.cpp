/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
#define null 0
/*字符串匹配函数
char *strstr(const char *haystack,const char *needle);
函数说明：在haystack指向的字符串中查找needle指向的字符串，也是首次匹配
返回值：找到了：找到的字符串的首地址
        没找到：返回null


*/

int main()
{
    char s[] = "1234:4567:666:789:666:7777";
    char *ret = strstr(s, "666");
    if (ret == null)
        printf("没找到\n");
    else
        printf("找到了，在第%d个位置\n", ret - s);
}
