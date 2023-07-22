#include <iostream>
using namespace std;

class Father
{
public:
    Father();
    virtual ~Father() = 0;
    virtual void Fat_func() = 0;
};

class Son : public Father //公有继承父类
{
public:
    Son();
    ~Son();          //显然，除了构造析构都会继承下来
    void Fat_func(); //在子类中写一个同名的函数
};

int main()
{
    // Father obj;//纯虚函数不能声明对象
    return 0;
}

//放到主函数后面
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
