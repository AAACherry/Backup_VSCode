#include <iostream>
using namespace std;

//先声明一下，不然会出错
template <class T> //所以有这么四行的东西都要声明一下。
class A;           //这个类要声明又要把类型带上
//先声明一下，不然会出错
template <typename T>   //而要声明一下类型，发现又要声明一下类
void show_2(A<T> &obj); //其实只要声明一下这个函数，但是发现声明一下这个函数需要就需要把类型声明一下。

template <class T>
class A
{
public:
    A(T t = 0) : m_a(t){};

private:
    T m_a;

    friend void show_1(A<T> &obj) //直接在类的内部写友元函数体
    {
        cout << obj.m_a << endl;
    }
    friend void show_2<>(A<T> &obj); //还需要说明一下它的这个模板类的友元: 在函数体的后面加上尖括号
};

template <typename T> //这里的T和前面的T没有必然联系的
void show_2(A<T> &obj)
{
    cout << obj.m_a << endl;
}

int main()
{
    A<int> obj_a(666);

    show_1(obj_a);
    show_2(obj_a);

    return 0;
}