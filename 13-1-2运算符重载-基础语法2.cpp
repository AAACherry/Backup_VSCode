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

    Mycomplex &operator+(const Mycomplex &other) const;

    friend Mycomplex &operator+(const Mycomplex &obj1, int num); //声明为友元函数，这个函数就能访问私有成员了

private:
    double m_real; //实部
    double m_imag; //虚部
};

Mycomplex &operator+(const Mycomplex &obj1, int num) //写成全局函数。现在没有this指针了，所以需要传两个这样的参数//我们可以不写两个复数相加的东西。可以考虑复数+整数的做法
{
    return Mycomplex(obj1.m_real + num, obj1.m_imag); //私有成员，在类的外部无法直接访问//实部直接+num，虚部不加，用原来的虚部
}
//现在我们可以做：(3+2i)+6=(9+2i)

int main()
{
    Mycomplex obj_1(3, 2);
    obj_1.display();

    Mycomplex obj_2(4, 3);
    obj_2.display();

    Mycomplex obj_3;       //先定义出来，再进行赋值，而不是直接进行初始化。那么初始化的时候会调一个拷贝构造函数
    obj_3 = obj_1 + obj_2; //赋值函数。此处会有一个低保，赋值这个函数在类里面有一个低保，也就是赋值运算符会有一个重载，类当中是会有一个低保的。除了定义以外调赋值运算符实际上类中是有一个赋值运算符的重载的，有了这个重载才能直接用，否则的话凭什么能够把这两个对象加起来，然后赋值给obj_3.
    obj_3.display();

    //对象之间可以赋值，凭什么？因为类里面实际上有一个默认提供给你的赋值运算符的重载，这个函数叫做赋值函数，属于任何一个类都会有的这么一个东西，其实每个类天生就会有至少四个默认的成员函数：构造函数、析构函数、拷贝构造、赋值函数。拷贝构造和赋值函数最大的区别就是发生的时间点不同，虽然都是通过赋值体现出来的。但是赋值发生在很多时候，而拷贝构造如果就通过赋值来体现的话，就应该发生在初始化的阶段。用一个对象直接构造另一个对象，或者说只要沾上赋值属于这么一个情况:
    Mycomplex obj_3 = obj_2; //所有用赋值运算符的可以认为肯定是调用了类里面的赋值函数，只有这种情况(用一个对象去初始化另一个对象)的时候，会调拷贝构造

    obj_3 = obj_1 + 6;
    obj_3.display();

    obj_3 = operator+(obj_1, 6); //翻译一下，obj_1和6都作为参数，传给operator+()函数。然后用obj_3去接收一下
    obj_3.display();
    //全局的也可以是直接调函数的写法，也可以是加的写法。
    // 缺陷
    // obj_3 = 6 + obj_1;//不能这么写，因为没有这个重载，6在前面，6是第一个参数
    // obj_3 = operator+(6, obj_1); //相当于这种写法。如果需要换这个顺序的话，就应该调换一下参数位置，重新写一个重载
    obj_3.display();

    return 0;
}

Mycomplex::Mycomplex(double real, double imag) //只需要在声明的时候给默认值，实现的时候不需要
    : m_real(real), m_imag(imag)               //成员初始化列表
{
}
//用这种方法（先声明后定义）更加的安全，并且少了拷贝构造
/*
Mycomplex &Mycomplex::operator+(const Mycomplex& other) const //同样也是作为一个函数存在，用类名Mycomplex::去限定函数名
{
    return Mycomplex(this->m_real + other.m_real, this->m_imag + other.m_imag); //直接放回一个匿名对象(没有参数、没有名字的对象)//实部+实部作为实部的参数,虚部+虚部作为虚部的参数
} */
void Mycomplex::display() const
{
    cout << "(" << m_real << "+" << m_imag << "i)" << endl;
}
Mycomplex::~Mycomplex()
{
}

Mycomplex &Mycomplex::operator+(const Mycomplex &other) const //同样也是作为一个函数存在，用类名Mycomplex::去限定函数名
{
    return Mycomplex(this->m_real + other.m_real, this->m_imag + other.m_imag); //直接放回一个匿名对象(没有参数、没有名字的对象)//实部+实部作为实部的参数,虚部+虚部作为虚部的参数
}