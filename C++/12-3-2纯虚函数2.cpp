//父类当中有虚函数，子类当中重写了，

#include <iostream>
using namespace std;

class Father
{
public:
    Father();
    ~Father();
    virtual void Fat_func() = 0; //声明虚函数：你在声明函数成员的时候，如果在函数前面加上 virtual 关键字
};

class Son : public Father //公有继承父类
{
public:
    Son();
    ~Son();          //显然，除了构造析构都会继承下来
    void Fat_func(); //在子类中写一个同名的函数
    /*
    virtual void Fat_func();
    如果想要比较稳妥，想要它继续被子类重写，就继续声明为虚函数就行了。不写的话其实也会属于是重写的情况。所以如果希望成员函数在子类里面继续是虚函数，希望它继续能够重写的话呢，那就加个 virtual 就好了（严格、保险起见），不加其实也是能够重写的。
    */
};

class Grand_Son : public Son
{
public:
    Grand_Son();
    ~Grand_Son();    //显然，除了构造析构都会继承下来
    void Fat_func(); //在子类中写一个同名的函数
    /*
    virtual void Fat_func();
    如果想要比较稳妥，想要它继续被子类重写，就继续声明为虚函数就行了。不写的话其实也会属于是重写的情况。所以如果希望成员函数在子类里面继续是虚函数，希望它继续能够重写的话呢，那就加个 virtual 就好了（严格、保险起见），不加其实也是能够重写的。
    */
};

int main()
{
    /*
         //验证父类的子类
        Father *p_fat;

        Son obj_Son1;

        p_fat=&obj_Son1;
        p_fat->Fat_func();
     */

    //验证子类和孙子类
    //相当于父类指针指向子类对象，然后通过这个指针去调的时候，它的函数是由什么决定的？
    //动态联编根据指向的对象的类型去调函数，静态联编会根据指针的类型去调函数
    Son *p_Son;
    Grand_Son obj_G_Son;

    p_Son = &obj_G_Son;
    p_Son->Fat_func();

    return 0;
}

//放到主函数后面
// Father
Father::Father() //父类构造
{
    cout << "Father::Father()" << endl;
}
/* void Father::Fat_func()//纯虚函数，不能实现函数体和声明对象。要在子类中完成
{
    cout << "void Father::Fat_func()" << endl;
} */
Father::~Father() //父类析构
{
    cout << "Father::~Father()" << endl;
}
void Father::Fat_func()
{
    cout << "void Father::Fat_func()" << endl;
}
// Son
Son::Son() //子类构造
{
    cout << "Son::Son()" << endl;
}
void Son::Fat_func()
{
    cout << "void Son::Fat_func()" << endl;
}
Son::~Son() //子类析构
{
    cout << "Son::~Son()" << endl;
}
// Grand_son
Grand_Son::Grand_Son() //孙子类构造
{
    cout << "Grand_Son::Grand_Son()" << endl;
}
void Grand_Son::Fat_func()
{
    cout << "void Grand_Son::Fat_func()" << endl;
}
Grand_Son::~Grand_Son() //孙子类析构
{
    cout << "Grand_Son::~Grand_Son()" << endl;
}