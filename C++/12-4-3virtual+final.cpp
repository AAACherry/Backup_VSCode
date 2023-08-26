// 12 - 4 - 3 virtual+final

#include <iostream>
using namespace std;

class ClassName 
{
public:
    ClassName();
    ~ClassName();
    virtual void test() final = 0;

private:
};

class Son : public ClassName//子类继承父类
{
public:
    Son();
    ~Son();
    // void test();//无法重写函数

private:
};

class G_Son : public Son//孙子类继承子类
{
public:
    G_Son();
    ~G_Son();
    // void test();//无法重写函数

private:
};

int main()
{
    // G_Son obj_2;//孙子类也不能创建对象
    // Son obj_1;//创建不了对象
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

G_Son::G_Son()
{
}
G_Son::~G_Son()
{
}