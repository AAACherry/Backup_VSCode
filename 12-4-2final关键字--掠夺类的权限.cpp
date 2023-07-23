// 12 - 4 - 2final关键字 --掠夺类的权限

#include <iostream>
    using namespace std;

class ClassName final
{
    public:
        ClassName();
        ~ClassName();

    private:
};

class Son // : public ClassName//不管用什么权限方式，总之可以继承ClassName。但是父类中用final关键字，则无法子类无法再继承
{
    public:
        Son();
        ~Son();

    private:
};

int main()
{
    return 0;
}

//相关函数放在主函数后面
ClassName::ClassName()
{
}
ClassName::~ClassName()
{
}

Son::Son()
{
}
Son::~Son()
{
}
