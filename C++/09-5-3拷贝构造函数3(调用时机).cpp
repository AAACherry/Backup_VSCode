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

//在全局区来添加一个普通的全局函数
// 3.函数的参数是类的对象
void test_func_1(Monster obj)
{
    //只要它参数是类的对象，函数体不写也没事
}

// 4.函数的返回值是类的对象
Monster test_func_2() //返回值类型是类的类型（此处为Monster）
{
    Monster obj; //先在里面创建一个这样的对象
                 //  Monster obj();//带参构造的话也可以传参数
    return obj;  //然后把这个对象返回出去
}

Monster test_func_3() //返回值类型是类的类型（此处为Monster）
{
    return Monster(); //这个叫匿名对象(就是没有名字的一个对象)。此处创建匿名对象。
}

int main()
{
    //    Monster m0;                       //没带参数，调用无参构造
    //    Monster m1("皮卡丘", 120, 10.0f); //调用带参构造函数

    //   test_func_1(m1); //调用函数，参数传类的对象。实参的值拷贝给形参
    //把m1传给obj的时候去调用的(结果显示：默认的拷贝构造(1号))
    //三个析构。第一个析构是test的，第二个是m1的，第三个是m0的
    /*构造和析构函数的调用顺序的问题
    因为test_func_1这个函数调用完毕之后才会回到主调函数，
    回到主调函数来的时候test_func_1结束了，
    test函数的参数表中的obj也就结束了生命周期了，
    所以它要先释放，所以要先析构
    回来后才会结束这个主函数main，结束这个主函数的时候就结束m0，m1的生命周期
    那么就形成了先构造的后析构
    */
    //    test_func_2();//调用该函数时就无需传参数了。//像这种没有东西去接收这个复制体的话，那么系统就会给你创建一个看不见摸不着的
    //    对象。(在test_func_2外面创建一个对象)，然后把obj拷贝给外面这个不知名对象。
    //    Monster monster=test_func_2(); //返回出去，在此处接收的其实不是obj，因为obj在这个test_func_2中已经被释放掉了
    //    而如果有一个对象去接收这个复制体的话，系统会直接把obj复制给对象(monster)，所以这种有对象接收的就不会再额外调用拷贝构造了
    test_func_2(); //拷贝出去的这一份就在函数的调用的地方返回出去了
    //所以return obj;实际上返回出去的是obj的复制体。既然要返回出去，则要拷贝一份出去
    /*首先从主调函数进入被调函数，该过程无参数，所以不存在调用别的函数
    接下来执行函数体，
    执行函数体时需要定义一个object，在此处object属于无参构造(函数体内第一段代码Monster obj;)
    返回的时候object作为一个栈区的对象，是不会被直接返回出去的
    类似这样的栈区对象，它会在这个函数体结束的时候就会被系统自动回收内存，它就没了。
    既然它在这个函数里面没了，就必不可能被返回出去*/

    /*
    先进来创建一个对象调用无参构造，然后返回的时候它本身（obj）必定被释放。此时通过复制体返回出去，所以说返回值返回的是复制体而不是它本身。所以 return obj; 处会调用一次拷贝构造。
    掉完拷贝构造之后，马上就会结束这个函数体就过来了（来到 main 主函数），于是 obj 此时就要被释放，释放就要调用一次析构。
    完毕后，此时 main 主函数这边返回复制体出来了，复制体既然返回出来了，那么这里就有了一个复制体，马上主函数结束。主函数结束之后，这个复制体返回出来的复制体也会被释放掉，所以也会调用析构一次。
    更精确的描述：复制体返回出来后，在第（76 行），没有任何一个当前类的对象去接收你的这个复制体。于是就会在这一行直接释放掉。如果后面还有其他的语句在执行，在执行后面的其他语句之前，这个复制体在这种写法的情况下，它已经释放掉了。
    */

    Monster monster = test_func_2();

    test_func_3(); // return 匿名对象; 此时结果显示无参构造且析构。
    /*为什么可以直接无参构造且析构，没有拷贝构造了？
    因为以return语句为界线，以它为一个分界点。
    return后面的可以认为是函数外面的。
    所以此处在return后面去创建各种东西不用再去拷贝了。
    即，如果是返回函数里面的东西，则要拷贝出来。
    而如果是函数外部的(return后面的)则无需拷贝构造了。
    */
    Monster monster = test_func_3(); /*如果是用一个对象去接收它也是同理，
     不会去额外的调用拷贝构造，而是直接把创建的东西直接给到对象(monster)*/
    return 0;
}
