#include <iostream>
using namespace std;

class ClassName
{
public:
    ClassName();
    ~ClassName();

    int val; // 其他的类型的成员访问不到（如直接 int val，无法直接访问到）。
    void test()
    {
        val;
    }
    static int num;

    static void testFun_1();
    static void testFun_2() //类中声明并实现
    {
        // val;无法访问普通数据成员
        // this->val;无法调用this指针
        // test();无法调用普通成员函数，防止通过普通函数去访问到普通成员，所以统统禁止。
        cout << "testFun_2" << endl;
    }
};
int ClassName::num = 0;

void ClassName::testFun_1() //类中声明，类外实现，static只须写在类中
{
    cout << "ClassName::testFun_1" << endl;
}

ClassName::ClassName()
{
    // num = 0;//只要创建对象就会调构造函数，调构造函数就会使num=0，
    //那么这个成员之前所记载的数据只要创建一个对象就被清空为0，这种做法不合适
    num++; //可以用来记数，每创建一个对象就+1，可以统计创建了几个对象
}

ClassName::~ClassName()
{
}

int main()
{
    ClassName obj_1;
    cout << "obj_1.num=" << obj_1.num << endl; //输出:0

    obj_1.num = 10;

    ClassName obj_2;
    cout << "obj_2.num=" << obj_2.num << endl; //输出：10
    // obj_1.num的值0改为10，而obj_2.num的值变成了10，
    //第一个对象的值改动后影响到了第二个对象的值，这就说明了大家用的是同一份内存。

    cout << "sizeof(obj_1)=" << sizeof(obj_1) << endl; // 1个字节
    // static int num应该是4个字节，它不属于obj_1的对象，同理不属于obj_2
    //也就是说这个num不存在于任何一个对象里面，它存在于类中

    cout << "sizeof(ClassName)=" << sizeof(ClassName) << endl; // 1个字节
    //类型是不能够求字节数，类名属于类型，此处这样求，实际上是悄悄的创建了一个这种类型的对象。

    ClassName::num;
    // 静态成员的寿命比类都要长，自然也比对象的寿命要长
    // 静态成员属于类，而不属于对象。对象共用，所以可以直接类名 + 作用域符访问到静态成员（num）
    // ClassName::val;
    // 其他的类型的成员访问不到（如直接 int val，无法直接访问到）。

    obj_2.testFun_1();
    (&obj_1)->testFun_2(); //取首地址就是一个指针
    // ClassName *p = &obj_1;
    // p->testFun_2();

    ClassName::num;         //可以用类名直接访问到这样的(static)成员
    ClassName::testFun_1(); //可以用类名直接访问到这样的（static）函数
    ClassName::testFun_2(); //可以没创建任何对象的情况下去访问这些东西
    //在静态函数中是不能够去访问这些普通的数据成员（int val;）甚至this指针也没有
    //普通的数据成员、this指针，都是要先有对象后，才会从传参过来。
    //而调用这些静态成员时却连对象都不需要有。

    return 0;
}