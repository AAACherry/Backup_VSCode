/*
类模板作为函数的话，类模板该怎么写？参数该怎么传？（有多种不同的方式）
主要有 3 种类型的情况
1、指定一下作为参数的对象是什么样的情况
2、
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

//这个函数有什么用？
//这个函数就可以接收像data_1这样的东西。
// test_Func_1()就只能去接收data_1这样的参数。
void test_Func_1(MyData<int, double> &obj) //普通全局函数，直接指定需要一个MyData类型的对象。这个对象指明了需要int和double这两种类型组合出来的对象，并且还考虑少掉一次拷贝构造，传引用&。
{
    obj.showData();
}

//第二种，把函数的参数模板化(把它也写成一个模板)
template <typename TT1, typename TT2>
void test_Func_2(MyData<TT1, TT2> &obj)
{
    obj.showData();
}

//把整体的参数都写成一个模板
template <class T>
void test_Func_3(T &obj)
{
    obj.showData();
}

int main()
{

    MyData<int, double> data_1(3, 3.14);
    test_Func_1(data_1); // test_Func_1()就只能去接收data_1这样的参数。

    MyData<char> data_2(67, 3.14);
    // test_Func_1(data_2);//假设让这个函数去接收data_2这样的类型就会有问题。因为data_2是char和double,而函数的类型却是int和double。类型不匹配。所以接收不了。

    MyData<char, float> data_3(68, 3.14f);
    data_3.showData();

    test_Func_2(data_1);              //隐式
    test_Func_2<int, double>(data_1); //显式

    test_Func_2(data_2); //不写类型也能自动推导出来。
    test_Func_2<char, double>(data_2);

    //相当于把整体的( MyData<char, float>)类型就直接赋给了T，然后T就做一个这样的对象的引用
    test_Func_3(data_1);
    test_Func_3<MyData<>>(data_1);
    test_Func_3(data_2);
    test_Func_3<MyData<char>>(data_2);
    test_Func_3(data_3);
    test_Func_3<MyData<char, float>>(data_3);

    return 0;
}
