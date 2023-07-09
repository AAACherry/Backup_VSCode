#include <iostream>
using namespace std;

class MyClass
{
    int num;

public:
    //    void setNum(int n)
    //    {
    //        num = n;
    //    }
    //区分成员和同名的参数
    // this指针不能改指向，本身是常量(MyClass *this)(默认且隐藏)在参数表中

    void setNum(int num)
    {
        //      num = num;
        this->num = num;
    }
    int getNum()
    {
        return num;
        // return this->num;
    }
    /*
    MyClass getThis()
    {
        return *this;
    }

    MyClass* getThisP()
    {
        return this;
    }
    */
};

int main()
{
    MyClass obj_1;
    obj_1.setNum(10);
    //↑ obj_1.setNum(&obj_1,10);每一次调用的时候其实就相当于是自己把这个对象去取首地址传过去
    cout << "num=" << obj_1.getNum() << endl;
}