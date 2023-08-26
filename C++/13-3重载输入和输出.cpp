/*
通过重载的过程会发现，如果运算符重载是通过友元函数重载，有两个参数，则一般写成第一个参数是cin/cout，当前类的对象写在后面(第二个参数)。
如果运算符重载写成成员函数，则会有this指针，this指针位置是第一个参数，在最前面。所以写成成员函数的话，那么就需要去改系统里面的文件，很麻烦。(可以写，但是麻烦，由于当前类的对象是在运算符的后面的，不适合写成成员函数。)
所以一般写成友元函数更好。
 */
#include <iostream>
using namespace std;

class MyComplex
{
public:
    MyComplex(double real = 0.0, double imag = 0.0)
        : m_real(real), m_imag(imag)
    {
    }

    friend istream &operator>>(istream &in, MyComplex &com);  //声明友元关系，调用私有成员
    friend ostream &operator<<(ostream &out, MyComplex &com); //声明友元关系，调用私有成员

    // private://不知道为什么，把运算符重载的函数声明成了友元friend关系还是会报错，提示不可访问。所以干脆改成了公有成员好了。
    double m_real;
    double m_imag;
};

istream &operator>>(istream &in, MyComplex &com) //考虑到返回引用的话要用到拷贝构造。参数表里面的两个参数是什么看>>两边内容的类型。这个istream写void是可以的。只不过你写这个函数一般是为了可以连续输入多个对象，则用istream(因为要有返回值类型)
{
    in >> com.m_real >> com.m_imag; //发现访问不到，因为访问的成员m_real是私有的，所以考虑去用友元。in当成cin去用就行了
    return in;                      //为什么需要返回值：如果只单独一次输入就可以，有时候连续的去输入，则需要return in
}
ostream &operator<<(ostream &out, MyComplex &com)
{
    out << "(" << com.m_real << "+" << com.m_imag << "i)"; // out当成cout去用就行了
    return out;
}

int main()
{
    /*
         MyComplex obj(2, 3);

        int n;    //看看int类型的n是怎么样存在的。
        cin >> n; // istream输入类型
        // cin >> obj >> obj1 >> obj2;//有时候连续的去输入，则需要return in

        // cin >> obj;//那么同样的，假设obj一开始没有给他们参数，先cin输入一下这个obj里面相关的东西，然后再输出，这个也是不允许的
        cout << "suibian" << endl;

        // cout << obj << endl;//希望直接输出obj，现在做不到这样的事情。因为<<输出运算符需要认识obj的类型，但是没有针对这种类型的重载。那么同样的，假设obj一开始没有给他们参数，先cin输入一下这个obj里面相关的东西，然后再输出，这个也是不允许的
     */

    MyComplex obj;
    cin >> obj; //声明和实现时的参数表不统一，声明时比实现时参数表中的Mycomplex &com少了引用&，导致报错：有多个运算符">>"与这些操作数匹配
    //实际上通过">>"输入的重载，执行运算符重载函数的函数体中的"in >> com.m_real >> com.m_imag;"把实部和虚部依次输入进去，然后再一次输出返回。
    cout << obj << endl; //调用的时候实际上是把cin传给istream运算符重载函数中参数表的第一个参数istream& in中的in，把cout传给ostream运算符重载函数中参数表的第一个参数ostream& out中的out

    //作为函数调用的形式去写:(与上面的写法其实的一样的)
    // cin.operator>> // cin只是一个对象而已，通过一个对象去调用一个函数，没有问题。
    operator>>(cin, obj);  //全局函数，所以直接用operator。//相当于cin>>obj;
    operator<<(cout, obj); //相当于是cout<<obj;

    MyComplex obj_1;                         //假设还有一个对象
    cin >> obj >> obj_1;                     //连续去输入。
    operator>>(operator>>(cin, obj), obj_1); //首先，肯定是从左到右去输。相当于是先输入obj,然后返回一个值，返回的一个值就是cin，然后再去输入obj_1。是一个函数的嵌套调用。
    // cin>>obj相当于最里面一层括号内的operator>>(cin,obj)，然后再返回一个值与第二层括号的obj_1就行输入。
    //  为什么可以这样去嵌套调用呢？因为前面写返回值类型是istream。有返回值的函数调用可以作为其他函数的实参。

    cout << obj << endl
         << obj_1 << endl;                    //连续去输出，会是什么样的形式呢？
    operator<<(operator<<(cout, obj), obj_1); //相当于是这个。

    return 0;
}