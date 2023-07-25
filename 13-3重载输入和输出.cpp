#include <iostream>
using namespace std;

class MyComplex
{
public:
    MyComplex(double real = 0.0, double imag = 0.0)
        : m_real(real), m_imag(imag)
    {
    }

    friend istream &operator>>(istream &in, MyComplex com);  //声明友元关系，调用私有成员
    friend ostream &operator<<(ostream &out, MyComplex com); //声明友元关系，调用私有成员

private:
    double m_real;
    double m_imag;
};

istream &operator>>(istream &in, MyComplex &com); //考虑到返回引用的话要用到拷贝构造。参数表里面的两个参数是什么看>>两边内容的类型
{
    in >> com.m_real >> com.imag; //发现访问不到，因为访问的成员m_real是私有的，所以考虑去用友元
}
ostream &operator<<(ostream &out, MyComplex &com);
{
}

int main()
{
    MyComplex obj(2, 3);

    int n;    //看看int类型的n是怎么样存在的。
    cin >> n; // istream输入类型

    // cin >> obj;//那么同样的，假设obj一开始没有给他们参数，先cin输入一下这个obj里面相关的东西，然后再输出，这个也是不允许的
    cout << "suibian" << endl;

    // cout << obj << endl;//希望直接输出obj，现在做不到这样的事情。因为<<输出运算符需要认识obj的类型，但是没有针对这种类型的重载。那么同样的，假设obj一开始没有给他们参数，先cin输入一下这个obj里面相关的东西，然后再输出，这个也是不允许的

    return 0;
}