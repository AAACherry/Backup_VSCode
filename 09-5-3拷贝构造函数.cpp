#include <iostream>
using namespace std;

 //空类中有三个默认的函数——
//默认的构造函数、默认的析构函数、默认的拷贝构造函数
//(注：实际上有很多的“低保”可以吃，但是目前了解的是这三个)
class Myclass
{
    Myclass(){}
    ~Myclass(){}
    Myclass(const Myclass &obj){}
    //一般情况下，引用会用const去修饰
    //理由：防止修改
    // Myclass(const Myclass &obj,int n){}//可重载
    // Myclass(int n,const Myclass &obj){}//不是拷贝构造函数
    //因为第一个参数不是当前类的对象的引用，所以不是拷贝构造函数
};

int main()
{
    return 0;
}