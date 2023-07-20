/* 要有这3个条件才能有多态
1、虚函数成员的父类
2、同名函数成员的子类
3、指针

类族
指针-->虚函数表
*/

#include <iostream>
using namespace std;

class Father
{
public:
    virtual void Fat_func(); //声明虚函数：你在声明函数成员的时候，如果在函数前面加上 virtual 关键字
};

class Son_1 : public Father //公有继承父类
{                           //显然，除了构造析构都会继承下来
    void Fat_func();        //在子类中写一个同名的函数
};

class Son_2 : public Father //公有继承父类
{                           //显然，除了构造析构都会继承下来
    void Fat_func();        //在子类中写一个同名的函数
};

int main()
{
    /*只是有一些普通的同名函数，属于不该出现的情况。
         Father obj_fat;
        obj_fat.Fat_func();

        Son_1 obj_son1;
        obj_son1.Fat_func();

        Son_2 obj_son2;
        obj_son2.Fat_func();
        */

    return 0;
}

//放到主函数后面
void Father::Fat_func()
{
    cout << "void Father::Fat_func()" << endl;
}

void Son_1::Fat_func()
{
    cout << "void Son_1::Fat_func()" << endl;
}

void Son_2::Fat_func()
{
    cout << "void Son_2::Fat_func()" << endl;
}
