
// 1.在默认构造里面给指针p制空
// 2.在带参构造里面给指针p = new int[10];
// 3.默认的拷贝构造中的问题--指针指向同一个地方
// 4.给你的这个新对象重新开辟一段内存，并且让它重新指向这里
// 5.怎么防止默认拷贝构造的发生

#include <iostream>
using namespace std;
#include <string>

class Monster
{
public:
    string m_name;
    int m_hp;
    float m_speed;
    int *p;

public:
    Monster();
    Monster(char *name, int hp, float speed);
    Monster(Monster &obj);
    Monster(Monster &obj, int val); //重载一个拷贝构造
    ~Monster();

    void showData(); //声明一个对象去显示数据

private:
};

//在默认构造里面给指针p制空
Monster::Monster()
{
    cout << "无参构造" << endl; //
    m_name = "名字";
    m_hp = 100;
    m_speed = 10.0f;
    p = NULL;
}

//在带参构造里面给指针p = new int[10];
Monster::Monster(char *name, int hp, float speed)
{
    cout << "带参构造" << endl; //
    m_name = name;
    m_hp = hp;
    m_speed = speed;
    p = new int[10];
}

//默认的拷贝构造中的问题--指针指向同一个地方
Monster::Monster(Monster &obj) //默认的拷贝构造，有什么就抄一份
{
    cout << "默认的拷贝构造(1号)" << endl; //低保构造
    m_name = obj.m_name;
    m_hp = obj.m_hp;
    m_speed = obj.m_speed;
    //    p = obj.p;这种情况不对，指针不能这么用。两个指针指向同一个地方
    /*低保构造还是这样去给。即一一对应赋值。但是这样并没有什么含义，这样给它是会有问题的。
    这样两个指针是给过去指向(把指向给过去了)。这样有问题。
    两个对象的指针都是指向同一块内存。
    所以像这样有指针的情况就不能这样去指向。
    那就应该给你的这个新对象重新开辟一段内存，并且让它重新指向这里。*/
}

//拷贝构造函数重载，一般不这么用，只用上面那种默认的
//给你的这个新对象重新开辟一段内存，并且让它重新指向这里
Monster::Monster(Monster &obj, int val)
{
    cout << "拷贝构造2号" << endl;
    m_name = obj.m_name;
    m_hp = val; //用val来取代血量
    m_speed = obj.m_speed;
    p = new int[10];                //先自行申请一段新的内存
    for (size_t i = 0; i < 10; i++) //因为内存为10，所以用一个for循环
    {
        p[i] = obj.p[i]; //如果只有一个直接拿过去即可，就无需for循环
        //*(p + i) = *(obj.p + i);//两种写法均可
    }
    //申请完后，你可以把这张内存里面的数据拷贝过来，不能指针指过去
}

/*
析构函数中什么都不做，因为成员都可以被系统自动释放
什么时候用做：比如说有一个成员申请了堆区的内存，申请了要释放，就写到析构函数中
这样就不存在忘记释放内容，因为写到析构函数中去后，任何一个对象在生命周期结束的时候系统都会自动的调用这个析构函数，肯定就不会忘记释放堆区的内存
*/
//在析构函数中delete指针，且把指针制空。要用if语句先确认后释放。
Monster::~Monster()
{
    cout << "析构函数" << endl; //
    if (p != NULL)              //要先确定指针是否为空，如果已经为空是不能够重复delete的。先确认，再释放
    {
        delete p;
        p = NULL;
    }
}

/*怎么防止默认拷贝发生？（防不胜防）
我们可以主动让程序报错（主动报错更好去发现和修改）
在一个类中如果声明了指针，但是没有定义，在没调用这个函数的情况下，它不会有问题。
但凡调用了，有声明，没定义的话，就会报错。
所以我们可以声明一个私有的拷贝构造函数，但是不对它进行定义（私有的、不定义），没有函数体。那么只要出现了拷贝构造，首先你写了一个自己的声明的拷贝构造，那么就不会有低保了。如果需要调用这个拷贝构造，首先它是私有的，访问不到。其次没有函数体，会告诉我们未定义。（双重保险）让我们只要调用了拷贝构造，我们就会发现，再进行调整。
*/

void Monster::showData()
{
    cout << "角色名称:" << m_name << endl;
    cout << "当前血量:" << m_hp << endl;
    cout << "移动速度:" << m_speed << endl;
    cout << "***********" << endl
         << endl;
}

int main()
{
    Monster m0;                       //没带参数，调用无参构造
    Monster m1("皮卡丘", 120, 10.0f); //调用带参构造函数
    Monster m2 = m0;                  //调用默认的拷贝构造函数（1号）
    //调用时机：同类对象给一个对象初始化的时候会调用（m2）
    Monster m3(m0); //与m2一样，都是调用拷贝构造1号，写法不同
    //调用时机：一个对象去构造另一个对象的时候会调用
    Monster m4(m1, 180); // m4掉拷贝构造函数2号

    Monster *p = new Monster; //无参数，调用无参构造
    //不会自动释放，因为是堆区的。不还就不会收
    //以上掉用了六次构造，却只有五次析构
    //    delete p;
    //    p = NULL;//哪里释放内存就在哪里析构，所以会在下面几条代码之前执行

    m0.showData();
    m1.showData();
    m2.showData();
    m3.showData();
    m4.showData();
    p->showData(); //默认的无参构造
    //上面delete后此处p->showData();就不能用了

    //哪一个先调用构造函数，哪一个就最后再析构(先构造的后析构)
    //如这里先析构的是m4，因为m4最后构造出来的
    //堆区不在考虑范围之内，堆区的(析构)释放由自己决定
    return 0;
}
