#include <iostream>
using namespace std;

double test(double a, double b)
{
    /*     if(b==0)
        {
            cout << "!!!" << endl;
            return 0.0;
        } */
    if (b == 0)
    {
        //异常情况==>打报告
        // throw 抛出的异常信息;
        //抛出的异常信息:支持多种类型
        throw "这里有问题！"; //不管是什么，只要是双引号里面括起来的，都是字符串//只要这里触发了，后面都没有用了，根本就不会执行后面的代码。(只要此处触发了,此处已经中断程序了)

        /*  throw 666;//虽然还没有写catch，但是只要发现了throw关键字，那么马上就会结束程序，抛出异常。
            throw 'S';
            throw 3.14; */
    }
    return a / b;
}

int main()
{

    try
    {
        cout << test(9, 0) << endl; // try里面就是需要尝试的代码
    }

    catch (const char *str) // throw抛出的信息是const char类型的东西，所以用const char类型的一个指针，比如叫str
    {
        cout << str << endl;
    }
    catch (int num) //假设是int类型的情况下(throw 666;的情况下)
    {
        cout << num << endl; //用int类型的参数去接收它。
    }
    catch (...) //不知道抛出的是什么类型，则可以用...代替，除上面两种类型就会在这个catch中处理。有点像switch中的default
    {
        cout << "不对劲" << endl;
    }

    return 0;
}

/*
3个关键词：
throw：专门用来抛出异常（做一个提示）
try：尝试可能会出错的代码
catch：接收前面抛出的异常，并且进行解决

//可以进行嵌套，但是需要注意，但凡通过throw抛出了一个异常，那么必然要有一个地方能够去把这个东西接收起来，如果说没有平级的东西(catch)去接收的话，那么在有嵌套的情况下，会继续往外层把问题(异常)进行抛出，在外层的catch去抛出它。当然，只要接收到了就会进行处理。<-(一定要有一个catch去接收它)
try()
{
    //......
    直接或间接有throw
    //......
}
catch(接收异常)//参数表
{
    处理
}
*/