#include <iostream>
using namespace std;

template <class F_Type> // father type
class Father
{
public:
    F_Type m_F_val;
};

/*
 //不写模板的情况
class Son : public Father<int>//相当于把int给F_Type,就继承了int类型
{
    public:
        int m_S_Val;
}; */

//写模板的情况(把子类也写成是模板)
template <class S_Type_1, class S_Type_2>
class Son : public Father<S_Type_1> //不一定重复类继承一个int,先把type1传给父类那里继承过来的东西
{
public:
    S_Type_2 m_S_Val; //然后用type2自己去定义一些类型
};

//如果出现多级继承,孙子类和子类参照子类和父类

int main()
{
    //定义对象的时候需要去指定一下类型
    Son<int, double> obj_son; // int传给父类,double自己用
    obj_son.m_F_val;          //然后就可以点到父类的val;
    obj_son.m_S_Val;          //以及子类自己的val

    return 0;
}