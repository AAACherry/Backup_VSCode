/* 要有这3个条件才能有多态
1、虚函数成员的父类
2、同名函数成员的子类
3、指针：父类类型的指针，指向不同对象（父类或者子类）对象

类族
指针-->虚函数表
*/

#include <iostream>
using namespace std;

class Father
{
public:
    Father();
    ~Father();
    virtual void Fat_func(); //声明虚函数：你在声明函数成员的时候，如果在函数前面加上 virtual 关键字
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
    Father *p_father = new Son; //后半段(new Son)从堆区申请了一个这样的内存，使用new会自动给你返回一个当前这种类型的指针，也就是说在这里给你返回一个Son类型的指针，而Son类型的指针就是你所申请的Son对象的内存的首地址。
    //我们知道父类类型的指针可以指向子类对象，所以我们确确实实的在语法上面可以通过父类指针去接收你new出来的Son的这一段内存。
    //父类指针指向子类对象，只不过这个对象属于是匿名对象(确确实实有个对象，有一段内存，但是它没有名字，只能搞个指针才能访问到)

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
