// 11-2-3【继承和派生】父子关系-派生类的构造析构顺序
// 创建子类的对象，那么就要先调父类的构造函数，调了父类构造当然就要调父类析构函数，先构造的后析构。
// 如果非得要显示的传参去调用这个父类的构造，那么就把父类构造写在成员初始化列表中。(先调用父类构造才能调用自己的构造)
// 如果有多个继承和派生的父子类有这种情况，同样是只需要调用直接父类的构造就行了，因为(你爷爷的构造已经在你父亲那里写好了，而你只需要写你爹的就可以了。子类在成员初始化列表写父类的/去调用就可以了，而父类的父类在父类的成员初始化列表处写/调就可以了)--（俄罗斯套娃）--你只需要对自己的直接父子类去负责即可

#include <iostream>
using namespace std;

class Father
{
public:
    Father();
    Father(int n); //父类构造带参数
    ~Father();

    // int num;
    const int num;
};

class Son : public Father
{
public:
    Son();
    Son(int n, int v); //子类构造带参
    ~Son();

    int val;
};

int main()
{
    // Son obj_son;//创建了子类对象
    Son obj_son(3, 4); //传个参数3和4(令n =3,v=4)
    cout << "obj_son.num=" << obj_son.num
         << "obj_son.val=" << obj_son.val
         << endl;

    return 0;
}

//将构造函数和析构函数放在主函数后面
/* Father类的相关函数*/

/*//父类中int num为公有时
 Father::Father()
{
    num = 0; //父类的构造中给num赋值0
    cout << "父类构造" << endl;
}
Father::Father(int n)
{
    num = n; //父类的构造中参数传给num
    cout << "父类带参构造" << endl;
}
*/
Father::Father() : num(0) //父类中num为const修饰时
{
    cout << "父类构造" << endl;
}
Father::Father(int n) : num(n)
{
    cout << "父类带参构造" << endl;
}
Father::~Father()
{
    cout << "父类析构" << endl;
}

/* Son类的相关函数*/
Son::Son()
{
    val = 10; //子类的构造中给val赋值10
    cout << "子类构造" << endl;
}
//怎么样才能把子类当中的n传倒父类当中的num？
Son::Son(int n, int v) : Father(n), val(v) //这样才是调用父类的构造函数，在成员初始化列表里面调用。其他地方是不能被我们主动调用的，只是把它写在初始化列表里面，本质上还是由系统自动调用，执行到初始化列表的时候还是会给他出一下（这样就能拿到3和4）
//成员初始化列表中写了Father类构造函数，后面同样可以照常写val(v)。
{
    val = v;
    // num = n;//当父类中的num被const修饰时，子类当中同样不能这样去给它值了
    // Father(n);//这么做不是在调构造函数，而是在创建一个父类的、没有名字的对象，传了一个参数为n（这不属于把n传过去）
    cout << "子类构造" << endl;
}
Son::~Son()
{
    cout << "子类析构" << endl;
}

// 如果你要创建子类对象，会先调用父类的构造
