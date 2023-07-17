
/*语法:
一、单继承:
class 父类名
{
};

class 子类名: 继承权限 父类名
{
};

二、多继承:
class 父类名1
{
};

class 父类名2：
{
};

class 子类名: 继承权限1 父类名1,继承权限2 父类名2,...继承权限n 父类名n
{
};

三、继承权限(跟成员的访问权限很像)//写在大括号里面(类体中)是成员的访问权限，写在类体外面是类的继承权限
1.公有继承 public
2.私有继承 private
3.保护继承 protected
多继承每个父类之间可以任意选择其中的某一种继承方式。
注意：
    继承是子类继承父类的全部成员(数据成员和成员函数都能继承过来，无论原来是什么访问权限，只是问题在于能不能用)
*/
/*
1.继承虽然可以让子类得到父类的所有的成员，但是对于子类（子类的对象）而言，这些东西能不能被访问到？

父类的成员在子类对象的一些访问权限（由父类原有的访问权限和子类使用的继承方式决定）

父类的成员通过子类的继承方式最终在子类中得到的访问权限：
（左边竖列是父类原有的成员的访问权限，上边横排是子类所使用的继承方式，共有 9 种情况）

| 访问权限 \ 继承方式 | 公有继承（public） | 私有继承（private） | 保护继承（protected） |
|:-------------------:|:------------------:|:-------------------:|:---------------------:|
|     **public**      |       public       |       private       |       protected       |
|     **private**     |      不可访问      |      不可访问       |       不可访问        |
|    **protected**    |     protected      |       private       |       protected       |

父类的公有访问权限 public ：公有成员用什么方式继承在子类里面就是什么样的权限--在子类中的访问权限看其继承方式（继承权限）是什么样的就是什么样
父类的私有访问权限 private ：私有成员无论用什么样的方式去继承总是在子类中不可访问--只有在当前的类（本类）里面才能访问到，所有无论是在什么样的继承方式下都是不可访问。（确实继承到了，只不过不能去访问它）
父类的保护访问权限 protected：哪一个更严格就是哪一个，private>protected>public

2.继承的过程中数据是不会丢失的，有就能继承下来，没有就继承不了。

3.多级继承：分析直接的父子类
直接套用上面的这一套规定，直接分析它的一对直接父子类
分析他们的关系只需要分析跟你直接有关的这两个就可以了：分析你的直接父子类
至于从这个顶层传达下来的东西，你没有权力去直接得到，不能够预计
一级一级的继承下来，只能（只需要）一级一级的套这个规定去分析就可以了
 */

#include <iostream>
using namespace std;

class Father
{
public:
    Father();
    ~Father();

public:
    int pub;           //创建一个公有的数据成员
    void pub_func() {} //创建一个公有的成员函数
private:
    int pri;           //创建一个私有的数据成员
    void pri_func() {} //创建一个私有的成员函数
protected:
    int pro;           //创建一个保护的数据成员
    void pro_func() {} //创建一个保护的成员函数
};

class Son : public Father //继承写在子类的后面，在子类的后面声明一下继承的关系,public继承是最常见的，一般很少用私有继承，只有在一些特殊情况才可以去用 private 继承，保护继承用的也不多
{
public:
    Son();
    ~Son();

public:
    int num;
    void test_Func_public() //在类的里面创建一个函数，属于在类的里面了
    {
        this->num;        //在类的里面有this指针，通过this指针可以访问到它自己的num;
        this->pub;        //继承过来的公有的肯定可以被访问;
        this->pub_func(); //继承过来的公有的肯定可以被访问;

        this->pro;        //公有方式继承过来的父类的被保护的成员在子类中也是可以从内部访问
        this->pro_func(); //同理

        // this->pri;//父类本身私有的成员无论用什么方式继承都无法访问
        // this->pri_func();//同理
    }

private:
protected:
};

int main()
{
    cout << "sizeof(Father):" << sizeof(Father) << endl; //查看当前Father类类型的对象要占多少个字节的内存（3个int，3X4=12）
    cout << "sizeof(Son):" << sizeof(Son) << endl;       //查看当前Father类类型的对象要占多少个字节的内存（子类虽然什么都没写，但是继承了父类的，所以也是12个字节，自己虽然没有新增，但也是12个在字节）
    //在Son子类中新增定义一个int类型的num，内存就变为12+4=16个字节

    //看看Son子类能够访问的父类的访问权限
    Son obj_son;

    obj_son.num; //自身的public成员，可以访问

    obj_son.pub;        //父类继承过来的public数据成员，可以访问
    obj_son.pub_func(); //父类继承过来的public成员函数，可以访问

    // obj_son.pri;//父类继承过来的private成员，无法访问
    // obj_son.pri_func(); //父类继承过来的private成员函数，不可访问

    //  obj_son.pro;//父类继承过来的protected成员，无法访问。属于是被保护的，在类外无法被访问
    //  obj_son.pro_func(); //父类继承过来的protected成员函数，不可访问，属于是被保护的，在类外无法被访问
    return 0;
}
//将构造函数和析构函数放在主函数后面
/* Father类的相关函数*/
Father::Father()
{
}

Father::~Father()
{
}
/* Son类的相关函数*/
Son::Son()
{
}

Son::~Son()
{
}