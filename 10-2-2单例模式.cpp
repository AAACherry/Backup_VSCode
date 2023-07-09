#include <iostream>
using namespace std;

//单例模式：设计模式
/*
最基础要求：创建一个只能实例化一个对象的类
怎样让一个类只能创建一个对象，要从构造函数的角度去限制，创建对象是必须要去调用构造函数的

核心思路：
如果我们把一个类的构造函数进行一波限制，让它只能创建一个对象，就能满足我们的要求了。

我们也不能直接去限制一个函数的调用次数。（C++中做不到），我们只是让构造函数在其他地方调用不了
简单来说就是把构造函数写成私有的。在外面调用不了，这样一来在所有地方（类的外面）就都调用不了这个函数，那就不能创建对象了。
既然我们这样在类的外部不能创建对象，那我们就可以在类的内部创建一个对象，然后写一些条件判断，让他只要创建了对象，就不再去调用这个函数就好了。
*/

//具体写法：
/*
先创建类、析构函数、构造函数
第一步先想办法把构造函数写成私有的（只要写成私有的了，这个类在外面就不能创建对象了）
    当然，为了防止防止一些问题，我们把拷贝构造，所以我们把拷贝构造也写成私有的。不能创建也不能拷贝（复制对象）。
我们总要实现些东西——通过static
我们首先先在私有成员这一块，搞一个当前这个类的这个类型的指针
这些都完成后其实实际上就是实现了这个所谓的单例模式
在类的外面去使用的时候，就只需要调这个getInstance，那么你就能够得到当前类类型的这么一个指针
 */
class SingleInstance
{
public:
    // SingleInstance();
    ~SingleInstance();
    static SingleInstance *getInstance(); //静态修饰的，返回值类型是当前类类型指针的这么一个函数

private:
    SingleInstance();
    SingleInstance(const SingleInstance &obj);
    static SingleInstance *pInstance; //修饰为static，我们首先先在私有成员这一块，搞一个当前这个类的这个类型的指针，静态的指针也是静态的数据成员，那就只能在静态成员函数里面访问
public:
    int num; //把基本的要求实现之后，如果说有一些数据需要用它，那么这些就可以去用了。
};
SingleInstance *SingleInstance::pInstance = NULL; //简单制个空

SingleInstance::SingleInstance()
{
    num = 0; //一开始创建的时候，在构造函数里面，还是可以给这些num初值什么的都可以。
}

/* SingleInstance::SingleInstance(const SingleInstance& obj);
{

} */

SingleInstance::~SingleInstance()
{
}

//我们在实现这个函数时的状态是成员函数
SingleInstance *SingleInstance::getInstance()
{
    // SingleInstance();//成员函数里面可以去访问当前这个类的构造函数
    if (pInstance == NULL) //申请内存的时候给判断一下，如果指针为空就去申请,如果不为空则什么都不做，保持原指向即可
    {
        pInstance = new SingleInstance; //给静态指针一个指向,new一个当前这个类的对象，给他申请出来内存
    }
    //当然，这里有返回值，不管这么样，我们都需要把这个指针给他返回出去
    return pInstance; //其实就是返回它的指向
}

int main()
{
    SingleInstance::getInstance();                      //在类外我们可以直接通过类名去访问这个static函数，返回值是声明时那种类型的指针
    SingleInstance *p1 = SingleInstance::getInstance(); //在类外面去使用时，就只需要调用这个getInstance，那么你就能够得到一个当前类类型的这么一个指针，不管这个东西去使用多少次，都是一样的
    cout << "num=" << p1->num << endl;                  //然后通过p1去创建出来，然后输出普通的数据成员num（p1->num）的状态。（一开始多少）
    SingleInstance *p2 = SingleInstance::getInstance();
    p2->num = 99; //然后我们可以通过p2把num给个值，如99（改一下num的值）
    SingleInstance *p3 = SingleInstance::getInstance();
    cout << "num=" << p3->num << endl; //然后通过p3把它输出出来（输出改后的状态）。结果说明这三个指针确实指向同一个对象。任何一个指针对它（num）的操作大家都可以看得到。这样一种情况就适合在你的程序里面的一些所谓的管理者的时候去使用这些东西（只需要一份的时候）。因为任何一个程序，都可能会有叫做权限最高的这么一个管理，用它可以去纵观整个程序的全局（可以看到所有东西）

    cout << hex << p1 << endl; // hex表示要输出16进制，理由：因为我要看这几个指针是不是相同的
    cout << hex << p2 << endl;
    cout << hex << p3 << endl; //执行起来发现，指针都是一样的（结果显示都是0xf66620），但我确确实实的调用了这个函数三次    （SingleInstance *p2 = SingleInstance::getInstance();）。这是因为只要这个对象在这里创建过了不为空的指针，初始化的时候给的为空，只要创建的时候创建成功了，他就不会为空，不会为空就不会进这个if，不进if就一直都是原来这一个对象。这就是所谓的单例模式。

    return 0;
}