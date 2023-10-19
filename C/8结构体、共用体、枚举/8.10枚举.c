/*
将变量的值一一列举出来，变量的值只限于列举出来的值的范围内
枚举类型也是个构造类型的
    1、枚举类型的定义
    enum 枚举类型名 {
        枚举值列表；
    };
    在枚举值表中应列出所有可用值, 也称为枚举元素
    枚举变量仅能取枚举值所列元素
    2、枚举变量的定义方法
        enum 枚举类型名 枚举变量名;

    ① 枚举值是常量, 不能在程序中用赋值语句再对它赋值
        例如：sun = 5; mon = 2; sun = mon; 都是错误的.
    ② 枚举元素本身由系统定义了一个表示序号的数值
        默认是从0开始顺序定义为0，1，2…
        如在week中，mon值为0，tue值为1， …, sun值为6
    ③ 可以改变枚举值的默认值：如
        enum week // 枚举类型
        {
            mon = 3，tue，wed，thu，fri = 4，sat, sun
        };
        mon = 3 tue = 4, 以此类推
        fri = 4 以此类推
        注意：在定义枚举类型的时候枚举元素可以用等号给它赋值，用来代表元素从几开始编号
        在程序中，不能再次对枚举元素赋值，因为枚举元素是常量。
        */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义一个枚举类型
enum week
{
    mon = 8, tue, wed, thu = 2, fri, sat, sun
};

int main(int argc, char *argv[])
{
    // 定义枚举类型的变量
    enum week day = mon;
    printf("day = %d\n", day);
    day = fri;
    printf("day = %d\n", day);
    return 0;
}
