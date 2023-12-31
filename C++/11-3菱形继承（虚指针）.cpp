// 11 - 3菱形继承（虚指针）

#include <iostream>
using namespace std;
//类的结构图写成代码
class A
{
public:
    int n;
};

class A_1 : virtual public A //加上virtual，虚指针，用这种方式类A2就分别会多出4个字节的内存，这4个字节的内存存这个虚指针
{
public:
    int a1;
};

//有一个兄弟类A_2
class A_2 : virtual public A //加上virtual，虚指针，用这种方式类A2就分别会多出4个字节的内存，这4个字节的内存存这个虚指针
{
public:
    int a2;
};

class AA : public A_1, public A_2
{
public:
    int aa;
};

int main()
{
    AA obj_aa; //用AA来定义一个对象
    obj_aa.aa; //可以访问到
    obj_aa.a1; //可以访问到
    obj_aa.a2; //可以访问到
    // obj_aa.n; //有问题，不能直接访问（这里是不明确的问题）
    obj_aa.n; //用了虚指针，原来不行的 obj_aa.n 现在可以了，就不需要类名去限定。即便用类名去限定也是同一份内容。

    obj_aa.A_1::n; //这种方法可以访问，对象+.+类名+作用域符+成员
    obj_aa.A_2::n; //这种方法可以访问，可以用这个来区分清楚n是哪一个的问题
    //这两个变量确实可以访问到，确确实实的不同的两个变量，来自两个不同的父类，只不过是追根溯源的时候，来自同一个类（类A），这是没有必要的。若类 A 中有很多这样的成员，各自继承下去给类 A 1, 类 A 2，这就不合适了，名字一样，来自不同父类，但是这不同父类之间又有亲戚关系，这就很容易混淆。只有一个n都这么麻烦，这么做不合适。
    //治标不治本，内存还是浪费

    // obj_aa.A::n;//不是直接父类，所以不行，这里不知道为啥可以，视频里是不行的。（这里是属于A不是直接父类，所以不行）

    //如何解决：虚继承--在继承的时候加上 virtual，对于类 A1，类 A 2 没有任何影响，实际上是会有一个虚指针存在，这个虚指针最大的作用是标记一下你类A1从类A中继承了哪些东西，你类A2的虚指针就标记一下你类A2从类A中继承了哪些东西，然后由类A1，A2共同派生出类AA时，虚指针起作用：派生时会去查看，我们俩重复了部分内容，那就只给他(类AA)一份内容。
    // 用这种方式类A1,类A2就分别会多出4个字节的内存，这4个字节的内存就是存这个虚指针的。用4个字节的内存去换取不知道多少个的内存就很划算，并且还解决的类AA重复的问题
    //可以这么去理解：不从类 A1，类 A2 中拿了，直接从类 A 中拿过来。
    // 用了虚指针，最终子类就只会有一份来自于最先父类的这么一个内存
    return 0;
}