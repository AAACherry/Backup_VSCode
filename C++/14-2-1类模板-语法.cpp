/*
 template <类型参数列表>
 class 模板类名
 {
    成员;//用类型参数列表传过来的类型
 };//定义域，需要加分号

 类型参数列表: <class T1,...,class Tn>//用Typename也可以，一般用class
 成员:T1 name;...Tn name;
*/

#include <iostream>
using namespace std;

template <class T1 = int, class T2 = double> //类型参数列表也可以初始化(给默认的类型)
// template <class T1, class T2>
class MyData
{
public:
    MyData(T1 n = 0, T2 v = 0.0) : num(n), val(v){};
    // ~MyData();

    // get/set去访问
    T1 getNum() { return num; } //内联
    T2 getVal() { return val; }
    void setNum(T1 n) { num = n; }
    void setVal(T2 v) { val = v; }

    void showData();

private:
    T1 num;
    T2 val;
};

template <typename Type1, typename Type2> //这两个类型会在调用这个函数的时候.当需要使用showData函数的时候必然有对象去调用这个函数，有对象就说明已经有类型了，于是就把类型T1,T2按顺序给Type1,Type2。参考函数的传参
void MyData<Type1, Type2>::showData()     //直接访问访问不了，MyData的类型不确定，类是不完整的，不能访问
{
    cout << "num=" << num << ",val=" << val << endl;
}

int main()
{
    //如何指定模板类的类型？就在创建的时候去指定类型。
    // 为什么是在创建对象的时候呢？因为只有在创建对象的时候才知道当前创建对象需要什么类型
    //创建对象时每个类都不一样，这就是模板类的强大之处。都是同一个类的对象，但是数据类型不一样
    MyData<int, double> data_1(3, 3.14); //定义对象，首先先把类型补充完整。不过此处，由于有两个类型，而此处设置的参数也只有两个参数，上面template时已经初始化了类型，它也能够自动推导出来，所以可以不写类型补充<int,double>。
    data_1.showData();

    MyData<char> data_2(67, 3.14); // char传递给T1,T1是char类型的话num也是char,于是showData中num得到的是C，而val还是3.14，相当于<>中写的是<char,double>，不过由于有默认类型，所以说它也可以自动推导double出来
    data_2.showData();

    MyData<char, float> data_3(68, 3.14f);
    data_3.showData();

    return 0;
}
