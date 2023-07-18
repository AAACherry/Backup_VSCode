#include <iostream>
using namespace std;
//类的结构图写成代码
class A
{
public:
    int n;
};

class A_1 : public A
{
public:
    int a1;
};

//有一个兄弟类A_2
class A_2 : public A
{
public:
    int a2;
};

class AA : public A_1,public A_2
{
public:
    int aa;
};

int main()
{
    AA obj_aa;//用AA来定义一个对象
    obj_aa.aa;//可以访问到
    obj_aa.a1;//可以访问到
    obj_aa.a2;//可以访问到
    // obj_aa.n; //有问题，不能直接访问（这里是不明确的问题）

    obj_aa.A_1::n;//这种方法可以访问，对象+.+类名+作用域符+成员
    obj_aa.A_2::n;//这种方法可以访问，可以用这个来区分清楚n是哪一个的问题
    // obj_aa.A::n;//不是直接父类，所以不行，这里不知道为啥可以，视频里是不行的。（这里是属于A不是直接父类，所以不行）
    return 0;
}