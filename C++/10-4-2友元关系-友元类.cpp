/*
友元：
1.单方向
2.不传递(不会默认传递，但是自己可以去声明一下)
3.不继承（父类的友元关系不继承给子类）
*/

#include <iostream>
using namespace std;

class A
{
    int num;
    friend class B; //创建友元关系，在类B中所有区域都可以访问A类的私有成员
};

class B
{
    friend class C;

public:
    void testFunc(A obj)
    {
        obj.num; //私有的，无法访问//希望在b类的这个函数里面可以访问到它，做法：将类B声明为A的友元
    }
};

class C
{
};