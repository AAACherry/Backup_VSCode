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

    Mycomplex operator+(Mycomplex other) //实际上+成员函数在参数表中有Mycomplex *this指针，只是我们看不见它，也就是说这里已经有一个参数了。我们需要的其实是另外一个Mycomplex other
    {
        Mycomplex obj; //创建一个对象
        obj.m_real = this->m_real + other.m_real;
        obj.m_imag = this->m_imag + other.m_imag;
        return obj;
    }

    // Mycomplex& operator+(const Mycomplex& other) const;//先声明后定义。这个地方要返回对象的话要调一次拷贝构造，所以可以返回一个引用& ，该函数只去做复数的加法，所以考虑只读取，不能修改，加上const。然后参数表也可以加上引用&，防止调拷贝构造。并且可以加上const防止参数被修改

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

    Mycomplex obj_1(3, 2);
    obj_1.display();

    Mycomplex obj_2(4, 3);
    obj_2.display();

    //现在的问题是能否把两个复数加起来
    // obj_1 + obj_2;//+号没有把两个复数加起来的功能。需要重新去定义这种规则

    /*
        int a, b, c;
        a = b = c = 0;
        a = b + c;//把后面看作是函数的调用的话，a=b.+(c)。.是取，+是函数名，()括号内的c是参数
    */

    Mycomplex obj_3;
    obj_3 = obj_1 + obj_2; //在此处直接写+号，究竟是哪一个对象在调用加的函数，哪一个对象是参数？加号无所谓，但是减号的话有减数和被减数之分。所以究竟是哪一种加的写法，我们在实现注意顺序的时候就不会有问题
    obj_3.display();

    //写成函数调用的形式
    //究竟对应的是哪一种的函数调用的形式
    //说到运算符就要说到结合性(往哪边靠)，根据结合性，加号是左结合性(双目运算符)，所以看左边,左边的东西去调的。所以说左结合性，左边就是当前对象，右边是参数。一般都是左结合性。
    obj_1.operator+(obj_2); // 属于是obj_1+obj_2的情况;//谁在前面会有区别
    obj_2.operator+(obj_1); // 属于是obj_2+obj_1的情况;
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
