/* 要有这3个条件才能有多态
1、虚函数成员的父类
2、同名函数成员的子类
3、指针：父类类型的指针，指向不同对象（父类或者子类）对象

类族
指针-->虚函数表
*/

#include <iostream>
using namespace std;

class Father
{
public:
    virtual void Fat_func(); //声明虚函数：你在声明函数成员的时候，如果在函数前面加上 virtual 关键字
};

class Son_1 : public Father //公有继承父类
{                           //显然，除了构造析构都会继承下来
    void Fat_func();        //在子类中写一个同名的函数
};

class Son_2 : public Father //公有继承父类
{                           //显然，除了构造析构都会继承下来
    void Fat_func();        //在子类中写一个同名的函数
};

int main()
{
    /*只是有一些普通的同名函数，属于不该出现的情况。不写虚函数的情况下（普通情况下），就会根据对象当前的这个类型去调用当前类型的函数，是一个正常的操作。属于是静态联编的一种情况。
        Father obj_fat;
        obj_fat.Fat_func();

        Son_1 obj_son1;
        obj_son1.Fat_func();

        Son_2 obj_son2;
        obj_son2.Fat_func();
        */

/*
     Father *p_fat;//创建父类类型的指针
    //创建三个不同类型的对象
    Father obj_fat;
    Son_1 obj_son1;
    Son_2 obj_son2;

    p_fat = &obj_fat;//父类类型的指针去取父类对象的首地址
    p_fat->Fat_func();//通过这个指针我们可以去调用这个函数

    p_fat = &obj_son1; //父类类型的指针还可以去接受一下子类对象的首地址
    p_fat->Fat_func(); //通过这个指针我们可以去调用这个函数

    p_fat = &obj_son2;  //父类类型的指针还可以去接受一下子类对象的首地址，父类指针小一点，读内容的时候不会影响到其他地方
    p_fat->Fat_func();  //通过这个指针我们可以去调用这个函数

    //如果去掉父类中的virtual，执行后全都是父类的：Father::Fat_func()
    //如果根据指针指向的内容，它的这个类型去调对应类型的这个函数。如果不加virtual，那就根据指针本身的类型，指针本身它是father类的类型，所以全都是father。动态根据参数，静态根据不同的子类。
 */

    
    return 0;
}

//放到主函数后面
void Father::Fat_func()
{
    cout << "void Father::Fat_func()" << endl;
}

void Son_1::Fat_func()
{
    cout << "void Son_1::Fat_func()" << endl;
}

void Son_2::Fat_func()
{
    cout << "void Son_2::Fat_func()" << endl;
}
