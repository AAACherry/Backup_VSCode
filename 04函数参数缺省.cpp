#include <stdio.h>
void function(int num = 0, float val = 0.0f);
//先声明后定义时，缺省只需在声明部分，定义部分不要再缺省。
void function(void);
int main()
{
    function(6, 3.14f); //传参是由前往后的；
    function(8);
    /*function();报错：有两种函数均可被调用，编译器出错*/
    function(0); //要么给一个参数，要么选择将函数二选一删除。
    //    function();
}
void function(int num, float val) //因此设置默认值(缺省)应该从后往前。
{                                 //缺省的值要为常量，不可在前面定义一个变量赋给它。
    printf("num=%d,val=%f\n", num, val);
}
void function()
{
    printf("void function();");
}
