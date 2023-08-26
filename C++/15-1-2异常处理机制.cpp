#include <iostream>
using namespace std;
#include <exception> //直接加上头文件就可以用了

// exception中实际上只有一个公有的虚函数

class Myexception : public exception
{
public:
    const char *what() const // what函数中加了const，防止修改里面的内容。现在重写一下//来自父类的虚函数，可以重写
    {
        return "English"; //有些情况下不能识别中文，会出现一些奇怪的字符。所以建议用英文
    }
};

int main()
{
    /*     Myexception obj;
        cout << obj.what(); */

    try
    {
        throw Myexception(); //不用烦恼自己究竟要throw什么样的东西了。因为可以直接throw这样类型的对象。这个对象没有名字(匿名对象)。直接throw直接抛出一个这样自定义的异常类类型的匿名对象
    }
    catch (Myexception &obj) //把上面这个对象的内容拷贝给下面这个对象要调拷贝构造。把类的对象作为参数的时候，要调拷贝构造怎么办？减少一次拷贝构造就节约点时间，考虑用引用。
    {
        cout << obj.what() << endl;
    }

    return 0;
}