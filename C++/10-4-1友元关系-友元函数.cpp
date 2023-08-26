#include <iostream>
using namespace std;

class A
{
    int num;                        //直接写的成员，默认是私有的。
    friend void test_Func_1(A obj); //友元的声明，可以写在public/private/protect，只要是在类中这样声明的就是友元。friend友元关键字,把哪个函数当朋友就把哪个函数的函数头放过来//A类把test_Func_1当成好朋友,此时test_Func_1函数中的obj.num就可以用了。
public:
    A() { num = 0; } //写一个A类的共有的构造函数,在A类中给num=0（给个初始化值）
};

void test_Func_1(A obj) //普通全局函数，友元并不是把这个函数变成它的成员函数，而是在类中先friend
{
    obj.num = 10; //私有成员，除了在类中，在类外是访问不到的
}

int main()
{
    A a;            //创建一个A类的对象
    test_Func_1(a); //调用这个函数需要A类的对象
}
