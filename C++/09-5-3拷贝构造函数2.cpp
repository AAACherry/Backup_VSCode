#include <iostream>
using namespace std;
#include <string>

class Monster
{
public:
    string m_name;
    int m_hp;
    float m_speed;

public:
    Monster();
    Monster(char *name, int hp, float speed);
    Monster(Monster &obj);
    Monster(Monster &obj, int val); //重载一个拷贝构造
    ~Monster();

    void showData(); //声明一个对象去显示数据

private:
};

Monster::Monster()
{
    cout << "无参构造" << endl; //
    m_name = "名字";
    m_hp = 100;
    m_speed = 10.0f;
}

Monster::Monster(char *name, int hp, float speed)
{
    cout << "带参构造" << endl; //
    m_name = name;
    m_hp = hp;
    m_speed = speed;
}

Monster::Monster(Monster &obj) //默认的拷贝构造，有什么就抄一份
{
    cout << "默认的拷贝构造(1号)" << endl; //
    m_name = obj.m_name;
    m_hp = obj.m_hp;
    m_speed = obj.m_speed;
}
//拷贝构造函数重载，一般不这么用，只用上面那种默认的
Monster::Monster(Monster &obj, int val)
{
    cout << "拷贝构造2号" << endl;
    m_name = obj.m_name;
    m_hp = val; //用val来取代血量
    m_speed = obj.m_speed;
}

/*
析构函数中什么都不做，因为成员都可以被系统自动释放
什么时候用做：比如说有一个成员申请了堆区的内存，申请了要释放，就写到析构函数中
这样就不存在忘记释放内容，因为写到析构函数中去后，任何一个对象在生命周期结束的时候系统都会自动的调用这个析构函数，肯定就不会忘记释放堆区的内存
*/
Monster::~Monster()
{
    cout << "析构函数" << endl; //
}

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
