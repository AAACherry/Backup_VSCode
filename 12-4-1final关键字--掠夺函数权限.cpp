// 12 - 4 - 1final关键字 --掠夺函数权限
//父类当中有虚函数，子类当中重写了，

#include <iostream>
using namespace std;

class Father
{
public:
    Father();
    ~Father();
    virtual void Fat_func();
};

class Son : public Father //公有继承父类
{
public:
    Son();
    ~Son();
    void Fat_func() final; //加上final，当前类为最后一次可重写类，其子类无法再重写
};

class Grand_Son : public Son
{
public:
    Grand_Son();
    ~Grand_Son();
    // void Fat_func();
};

int main()
{
    /*
     Son *p_Son;
    Grand_Son obj_G_Son;

    p_Son = &obj_G_Son;
    p_Son->Fat_func();

    return 0;
    没有必要去探究指针指向什么东西了，因为不能再这么写了，没有这个函数了
    */
}

//放到主函数后面
// Father
Father::Father() //父类构造
{
    cout << "Father::Father()" << endl;
}
void Father::Fat_func()
{
    cout << "void Father::Fat_func()" << endl;
}
Father::~Father() //父类析构
{
    cout << "Father::~Father()" << endl;
}
void Father::Fat_func()
{
    cout << "void Father::Fat_func()" << endl;
}
// Son
Son::Son() //子类构造
{
    cout << "Son::Son()" << endl;
}
void Son::Fat_func()
{
    cout << "void Son::Fat_func()" << endl;
}
Son::~Son() //子类析构
{
    cout << "Son::~Son()" << endl;
}
// Grand_son
Grand_Son::Grand_Son() //孙子类构造
{
    cout << "Grand_Son::Grand_Son()" << endl;
}
/* void Grand_Son::Fat_func()
{
    cout << "void Grand_Son::Fat_func()" << endl;//子类中的虚函数用了final关键字，孙子类无法再重写虚函数
}
 */
Grand_Son::~Grand_Son() //孙子类析构
{
    cout << "Grand_Son::~Grand_Son()" << endl;
}