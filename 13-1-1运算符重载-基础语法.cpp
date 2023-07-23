#include <iostream>
using namespace std;

//复数：实部，虚部 i i的平方平方应该是-1
//(3+2i) (0+6i) (5+0i)
//要实现复数的加法，肯定要写一个成员函数，才能够在类中把它进行重载
class Mycomplex
{
public:
    Mycomplex(double real = 0.0, double imag = 0.0);
    ~Mycomplex();
    void display() const; //显示当前所构建的虚数的对象里面的数据，只给显示，不给修改
    //返回值类型 函数名 (形参列表) {函数体}
    //唯一重要的区别就是它的函数名有要求，要重载哪个运算符，你的这个函数名就应该叫operator+运算符名称。operator本身是关键字，专门用来定义这个重载运算符的函数
    //函数名：operator运算符名称

private:
    double m_real; //实部
    double m_imag; //虚部
};

int main()
{
    /*
         //其实在平时已经用到过了运算符的重载，系统给的低保，像这样的重载我们也还是可以自己去实现的，赋予它低保以外的含义，实现更多的功能。
        6 + 1;//int+int
        3.14 + 5.12;//double+double
        6 + 3.14;//int+double

        int num = 0;
        char ch='A';
        cout << num << endl;//原来是左移的运算符，现在可以输出int类型的整数。
        cout << ch << endl;
     */

    Mycomplex obj_1(3, 5);
    obj_1.display();

    Mycomplex obj_2(4, 6);
    obj_1.display();

    //现在的问题是能否把两个复数加起来
    // obj_1 + obj_2;//+号没有把两个复数加起来的功能。需要重新去定义这种规则

    return 0;
}

Mycomplex::Mycomplex(double real, double imag) //只需要在声明的时候给默认值，实现的时候不需要
    : m_real(real), m_imag(imag)               //成员初始化列表
{
}
void Mycomplex::display() const
{
    cout << "(" << m_real << "+" << m_imag << "i)" << endl;
}
Mycomplex::~Mycomplex()
{
}
