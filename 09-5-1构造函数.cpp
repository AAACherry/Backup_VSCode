#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Myclass
{
public:
    int num;
    //    const int id = 0;
    // Const 修饰时就必须初始化它。
    // Const：这么初始化语法上没有错误，但后续无法进行修改它

private:
    int val;

public:
    Myclass() //无参构造函数
    {
        cout << "Myclass()" << endl;
    }
    //构造函数，只要是成员函数都可以声明在类里面，定义在外面
    //系统默认的构造函数：
    /*Myclass()
    {
    }
    */
    /*如果把成员函数的函数体直接实现在类中，
    这个构造函数就默认是一个内联函数，是公有属性
    通过内存膨胀，牺牲空间去换取时间。
    一般情况下，尽量在类中声明，外面去实现*/
    Myclass(int n, int v) //带参构造函数
    {
        cout << "Myclass(int n,int v)" << endl;
        num = n;
        val = v;
    }
    void setVal(int v);
    int getVal();
};

void Myclass::setVal(int v)
{
    val = v;
}

int Myclass::getVal()
{
    return val;
}

/*
Myclass::Myclass()//构造函数写在外面
{
}
*/

int main()
{
    Myclass obj; //构造函数在创建一个对象的时候会自动帮你去调用
    // obj.Myclass();
    //不能通过对象去调用这个构造函数(我们不能主动的去调用这个构造函数)
    //由系统自动调用这个构造函数，并且是在创建一个新的对象的时候
    obj.num = 0;
    cout << obj.num << endl;

    obj.setVal(10);
    cout << obj.getVal() << endl;
}