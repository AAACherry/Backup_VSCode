/*
obj_1~obj_3是常量数据成员，obj_4是常量成员函数，obj_5，obj_6是常量对象
作用：
const 防止我们对数据进行修改
比如说我们有一个私有的private数据成员，我们想把它保护起来，所以写成了私有的进行封装
但是有时候在外面需要拿出来看一下怎么办》->那么就在这个函数里面加上const。就只能看，无法修改
特例：静态成员可以在const中修改。静态成员是公有的，普通数据成员是自己有的。(从生命周期来思考)
 */
#include <iostream>
using namespace std;

class ClassName
{
public:
    ClassName();
    ClassName(int v); //也可去重载这个构造函数
    ClassName(int v, int num);
    ~ClassName();

    int num;
    // const int val = 0;//这种写法是不允许的。不这样写。即便语法上允许，但是这么做不合适
    //不能这么给值，但是又想要给值，怎么办？当然是用成员初始化列表，写法：
    //在这个构造函数后面给个冒号，然后把需要初始化的东西（注意：静态的不能在这里写）
    const int val;
    static int n;

    void test_func1() //普通成员函数
    {
        cout << "test_func1()" << endl;
        cout << "val=" << val << endl; //普通的成员函数里面是可以访问这个常量成员的
        cout << "num=" << num << endl;
    } //也可以在里面声明，外面定义

    void test_func2() const //常(量)成员函数的const是加在函数参数表后面
    {
        cout << "test_func2()" << endl;
        cout << "val=" << val << endl; //普通的成员函数里面是可以访问这个常量成员的
        cout << "num=" << num << endl;
        // val=0;无法修改
        // num=0;普通成员也无法修改， 也就是说在常（量）成员函数中是不能够去修改任何的这个数据成员的值的
        //语法规定：常量成员函数不能够对当前这个类的任何的数据成员进行修改。也就是说，你这个类中任何只要能够通过this指针指出来的东西在这里面都改不了。但是可以访问(如上面cout)，这样的做的目的是只要函数加上了const，那么在当前的函数体中就不能修改自己的任何成员
        // this->num=0;//无法修改
        n = 10;       // n可以直接修改
        this->n = 99; // this指针也可以访问到
    }                 //也可以在里面声明，外面定义

    void test_func3() const; //先声明，后实现
};
int ClassName::n = 0; //在类外进行实现一下，给静态成员一个初始值

void ClassName::test_func3() const //注意：实现的时候const不能丢掉。类的外面实现const函数的时候，const不能丢掉，因为const是整个函数的一部分
{
    cout << "test_func3()" << endl;
    cout << "val=" << val << endl;
    cout << "num=" << num << endl;
} //先声明，后实现

ClassName::ClassName() : val(0) //给一个默认值
{
}
//使用成员初始化列表对非静态成员进行一个初始化(不一定是常量成员，不是常量成员也可。但是常量成员必须要用成员初始化列表去初始化)
ClassName::ClassName(int v) : val(v) //相当于重载了 一个构造函数
{
}

ClassName::ClassName(int v, int num) : val(v), num(num) //外面的自己的，里面的是参数，this 的作用域范围是这个类里面（类的大括号里面以及函数的大括号里面）.this-> num(n)报错,因为参数表的位置不在函数里面也不是在类里面。但是还是可以区分开来两个同名的东西——括号里面的就是参数，括号外面的就是自己的成员
{
}

ClassName::~ClassName()
{
}

int main()
{
    ClassName obj_1;
    cout << "obj_1.val=" << obj_1.val << endl;

    ClassName obj_2;                           //对象共用const成员
    cout << "obj_2.val=" << obj_2.val << endl; //所有对象，只要是同一个成员就都是同一个值
    // obj_2 = 10; //不允许被修改，因为为常量

    ClassName obj_3(6);                        //调用的是只有一个参数的重载
    cout << "obj_3.val=" << obj_3.val << endl; //输出结果为6
    // obj_3.val = 9;//一样还是改不了，但是输出的val不再是0了，可以通过传参数对它进行初始化了

    ClassName obj_4(9, 8); // val得到9,num得到8
    obj_4.test_func1();    //直接去调用
    obj_4.test_func2();
    obj_4.test_func3();

    //常对象的任何普通数据成员都改不了，但是静态的还是可以改一下
    //常对象只能调用const成员函数，常对象只能调用常成员函数，并且所有的数据成员都不能够通过常对象本身去修改，静态成员不属于这个对象，所以就能修改
    const ClassName obj_5(3, 4); //常（量）对象
    // obj_5.num = 0;//无法修改，既然const修饰了对象，则常对象的任何成员都改不了
    obj_5.n = 0; //静态的成员可以修改，不受const影响。
    //常成员函数本来就不能够去修改它的数据成员，所以说能调用，至于这个普通的成员函数，它有可能去修改你的普通的数据成员，为了不被修改，（谁也无法保证你在这样的普通成员里会不会修改你的普通数据成员），所以常对象就一刀切，但凡是普通成员函数有这个修改风险的（有这个可能性的），统统干掉，不让我们去调用.即为了保证它不被修改，把有可能修改的函数直接不让我们去调用
    // obj_5.test_func1();//常对象不能调用普通成员函数
    obj_5.test_func2(); //可以调用常函数

    ClassName const obj_6(5, 7); //这样也能const
    obj_6.n = 0;                 //静态成员还是可以修改
    // obj_6.num = 9;//一样的，也改不了

    return 0;
}