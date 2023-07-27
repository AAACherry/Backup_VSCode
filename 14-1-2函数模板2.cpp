#include <iostream>
using namespace std;

class MyData
{
public:
    MyData(int n = 0) : num(n) {} //构造函数，并且带成员初始化列表和默认参数//在需要带参构造的情况下，不想重新去写一个无参构造，可以考虑给初始的缺省值(给了缺省值不传参数也能调用)

    int num;
};
template <typename T>
bool func(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    return false;
}

template <>
bool func(MyData &a, MyData &b) //重载模板函数，类型传都不传。//在这里T类型不认识，直接用MyData类型的参数做两个引用出来//写一个专门处理MyData类型情况下的比较
{
    if (a.num == b.num)
    {
        return true;
    }
    return false;
}

int main()
{
    int num, val;
    num = val = 9;

    cout << (func(num, val) ? "true" : "false") << endl;      //三目运算符表达式。是就输出true，否则输出false
    cout << (func<int>(num, val) ? "true" : "false") << endl; //指定一下是int类型
    //需要使用到一个==的运算符，等号对于基本数据类型来说，我们可以直接使用这个等号，判断他们是否相等。但是MyData是刚刚自己写的一种数据类型，MyData这样的类型传过去，不能直接用等号对他们进行一个比较。(报错:没有找到接收MyData类型的左操作数的运算符等号)，也就是说不能通过等号去比较MyData类型的对象obj_1和obj_2，它不认识这种类型。

    MyData obj_1, obj_2(5); //修改一下，给obj_2传个参数5.此时不相等，输出结果为false
    cout << (func(obj_1, obj_2) ? "true" : "false") << endl;
    cout << (func<MyData>(obj_1, obj_2) ? "true" : "false") << endl; //指定一下是MyData类型
    //自定义的类型运算符不认识，无法执行代码，可以进行运算符的重载
    //如果不通过重载运算符等号==,就通过模板函数(函数模板),能不能比较呢？(写一个模板函数本就希望什么类型都可以比较一下)。
    //怎样才能实现呢？
    //我们需要把模板函数针对这种MyData类型可以去写一个重载,实际上重载等号==会更好。

    return 0;
}