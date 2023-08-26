/*
int a = 0;

int b(2, 1);//这个看起来像是调构造函数

int m[4];//这个看起来像是初始化结构体
int n = {(int)3.14};
新的写法不允许有精度的缺失 */

/*
int *p = NULL;
int *p = nullptr;//这个东西跟NULL是一样的，只不过写法不一样，都是给指针置空，没有区别
但是本质上有区别，上面是宏定义，nullptr可以认为是一个关键字，
*/

#include <iostream>
using namespace std;
#include <string>

int main()
{
    /*     // 1、初始化的方式
        int num = 0;

        int val(5);
        cout << "val=" << val << endl;

        // 2、指针置空
        int *p = NULL;
        int *p = nullptr;

        // 3、自动类型
        int num(0);
        int *p(&num);
        auto p(&num); //自动类型，不需要自己去搞这个//auto放在前面表示是类型，根据值匹配类型
        auto val(3.14);//auto自动推断给val一个double类型
        auto val(3.14f);//加上f就自动推断为float
        auto val(3);//自动推断为int

        //一般情况看不出有什么优势，举个例子比较容易懂:
        //auto使用也有缺点，主要适用于明确知道它的类型，并且懒得去写那么复杂的时候可以用auto
        // double***** p[3][4][5];
        // auto pp = **p;

        // 4、decltype ()
        int a = 0;
        decltype(a) b;//这个地方相当于是根据a的类型定义了一个和他相同类型的b
        decltype((a)) m = a;//再加上一个圆括号意思就变了，这个的意思就相当于把a的类型先拿出来，然后给m定义一下，并且拿初始(a)给他。//这个方式就相当于取别名，给a取别名m。
        //如果没有这个圆括号，就相当于是根据a的类型定义一个m，然后把a的值给他，
        //但是如果是加了圆括号，(相当于取别名)
     */
    // 5、新的 for 循环的规则
    string str("abcdefg");

    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    for (auto ch : str) //新的方式，两种方式都可以//意思是使用for循环遍历str,每次就用自动类型定义的这个ch每次循环去接收一下str里面的当前这个元素,然后再输出出来。//很显然，每一次它的每个元素在这里应该是一个char。里面是一个字符串嘛，每个字符串是char类型的。
    {
        cout << ch << " ";
    }
    //有局限性，不是所有的for循环都可以这么改，只能够改一些数组，或者string容器类型的东西。至于具体是什么容器需要等数据结构的时候才会学
    //指针什么的不能这么去搞。这个新的for循环有时候被称为序列for循环，也有人称为范围for,就先限定范围，然后再在里面进行遍历。

    // 6、给类型取别名
    typedef int INT;
    typedef void (*pFUN)(); // typedef可以去给简单类型直接取别名，也可以给稍微复制一点的类型取别名

    using Int = int;         //现在我们就可以用Int代替int,可以直接用新名字代替后面的东西
    using PFUN = void (*)(); //复杂一点一样的，直接使用PFUN取代替后面的一整坨
    //好处是不管简单类型还是复杂类型都统一了写法，就使用这个东西代替赋值等号后面的这个类型

    // 7、default在类中的用法
    class CA //写了一个CA的类，其中有一个构造函数
    {
    public:
        CA(); //这个构造函数声明了，但是突然发现好像没什么要些的。这时可以把这个声明直接删掉，直接吃低保。
    };
    // CA::CA() = default;
    //也可以在这里写default，意思就是说我要调这个低保。
    //直接删掉就是默默吃低保，写上default就是光明正大肆无忌惮的吃低保

    // 8、final
    class CA //加到类后面，类不能继承
    {
    public:
        virtual void fun() final {} //这个东西要加到函数上面，那么虚函数不能重写。
                                    // final加上纯虚函数的搞法尽量不要去有，如果有那就必定是说你想搞一个这样的特殊的类出来。而且编译条件如果严格一点的话纯虚函数+final可能还会出现问题。
    };

    return 0;
}
