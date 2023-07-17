// 11-2-3【继承和派生】父子关系-派生类的构造析构顺序

#include <iostream>
using namespace std;

class Father
{
public:
    Father();
    ~Father();

    int num;
};

class Son : public Father
{
public:
    Son();
    ~Son();

    int val;
};

int main()
{
    Son obj_son;
    return 0;
}

//将构造函数和析构函数放在主函数后面
/* Father类的相关函数*/
//在父类和子类的构造中分别给数据成员一个值，用以区分子类对象访问同名数据成员时的情况
Father::Father()
{
    num = 0; //父类的构造中给num赋值0
}
Father::~Father()
{
}

/* Son类的相关函数*/
Son::Son()
{
    val = 10; //子类的构造中给val赋值10
}
Son::~Son()
{
}