#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

/*类和结构体之间的联系和区别*/
//类和结构体是两个不同的东西
/*区别：
1.结构体属于C语言，C语言中不能有类
类属于C++，但C++中可以有结构体，
结构体中不允许存在函数，类中可以存在函数
2.在C++语言中，可用class去定义一个类，也可用struct去定义一个类，
在C++中struct不再是单纯的结构体的关键字，可以用来定义一个类，身兼数职。
在C语言中不行，struct结构体中不能有函数
3.一般情况下，如果使用C++，使用面向对象编程思想，
去声明一个类，定义一个类，就用class，因为class声明出来的类是私有的，符合封装性
定义结构体用struct，struct声明出来的类默认是公有的，不具有封装性
*/
struct Name // struct可以声明类，但初学不建议
{
    int num;
    void fun()
    {
    }
};

class Sheep //类的内存占多少个内存--内存对齐，与结构体一致
{           //如果这个类中有另一个类的对象就展开再对齐
    int a;  //默认私有的
public:
    char name[32];

private:
    int age;

public:
    void setAge(int n) //函数是公有的，外部可以访问
    {
        age = n; //赋值给私有变量age
    }
    void eat()
    {
        cout << "闲着没事，吃点草" << endl;
    }
    void speak();

private:
    void speakEnglish()
    {
        cout << "My name is:" << name << ",I am" << age << "." << endl;
    }
};

void Sheep::speak() //不加Sheep::是普通全局变量，加了后指定为类中的函数
{
    cout << "我叫" << name << "，我" << age << "岁了。" << endl;
}

int main()
{
    Sheep xiYY; //对象的定义，‘类’类型+对象名;
    xiYY.eat();
    // xiYY.name="喜羊羊"; 错误的，该name为char型字符数组
    strcpy(xiYY.name, "喜羊羊");
    // xiYY.age=10; 错误的，age是私有属性，不能直接访问
    xiYY.setAge(19); //通过公有成员函数去访问不能直接访问的私有变量
    xiYY.speak();    //访问函数用点号.
    Sheep *py;       /* 这种方法不被允许，语法没错，
           但该指针没有具体指向哪个对象，否则该指针只有4个字节的指针变量 */
    py = &xiYY;      //要先取上某一个对象的首地址，让指针有了指向后才能再去访问
    py->eat();       //指针用箭头->去访问
    py->speak();
}
