#include <stdio.h>
void main()
{
    //&解析引用符，作为取舍地址使用，
    //也可作为位运算符使用，还可表示定义的是个引用。
    int number = 0; // int类型4个字节大小内存。
    int &dd = number;
    //引用，dd与number具有同等法律效力，同一段内存不同名
    printf("number=%d\n", number);
    printf("number=%d\n", dd);
    printf("dd=%d\n", number);
    printf("ddr=%d\n", dd);
    dd = 10; // dd与number对应同一段内存。
    printf("number=%d\n", number);
    printf("number=%d\n", dd);
    printf("dd=%d\n", number);
    printf("dd=%d\n", dd);
    int gamecontrolnumber = 9;
    int &gcn = gamecontrolnumber;
    //引用的价值：方便使用变量名。
}