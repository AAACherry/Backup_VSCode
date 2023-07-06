#include <iostream>
using namespace std;
/*实际上Myclass中是这样的//有一个构造、一个析构
class Myclass
{
    public:
        Myclass();
        ~Myclass();

        private:
};

Myclass::Myclass()//系统默认的构造函数
{
    cout<<"构造"<<endl;
}

Myclass::~Myclass()//系统默认的析构函数
{
    cout<<"析构"<<endl;
}
*/
class Myclass
{
public:
    int id;
};

int main()
{
    Myclass obj_0;
    obj_0.~Myclass(); //没写析构函数的话，系统会自动给默认的析构函数

    return 0;
}
