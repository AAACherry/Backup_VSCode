/*
 通过 函数模板 定义 模板函数
 template(定义模板的关键字)、typename(用来声明类型参数的关键字)。<>(尖括号属于是类型的参数列表)、关键字+类型名。
 写类型的时候(typename)也可以写成是class。在这里class不再是声明类的意思了，属于是用来声明类型的参数的东西，一般习惯用typename
 语法:
 template <typename Type_1,...,typename Type_n>
 返回值类型 函数名(形参列表)
 {
    函数体;
 }

调用的语法:
 函数名<类型列表>(实参列表);

 */

#include <iostream>
using namespace std;

/*
template <typename T1,typename T2>//类型的参数表
T1 add(T1 a,T2 b)//数据的参数表，函数代码的时候不要再去考虑类型，因为函数体内的类型要根据后面(template一行处)传参数传过来是什么类型就是什么类型
{
    return a + b;
}
 */
/*
 int add(int a,int b)//可以void,int等,也可以用上面的这些类型T1,T2
{
    return a + b;
}
*/

template <typename Type>
Type add(Type a, Type b)
{
    return a + b;
}

template <typename TT1, typename TT2>
void test(TT1 tt1, TT2 tt2)
{
    cout << "tt1=" << tt1 << endl
         << "tt2=" << tt2 << endl;
}

int main()
{                       //属于是隐式的推导类型，让编译器自动的给你把类型推断出来。需要一个前提条件:要传的参数不会导致你的类型推导错误
                        //显示指定类型，直接通过<>告诉编译器需要的是哪种类型，那么不管你后面参数怎么传，参数已经定好了。
    test(1, 2);         //先传的是类型，此处的1，2本身具有类型。1的类型传给templa中的TT1，1传给函数test中的tt1。同理可知2。
    test(1.213, 3.153); // double类型，输出时使用cout的话C++自动会舍弃掉后面的零。
    test("name", 'S');  // string类型和字符型。
    //如果传的参数是自定义的类的类型，那么就需要事先重载一下输出(<<)，否则无法输出

    cout << add(3, 4) << endl;
    cout << add(1.23, 2.46) << endl;

    // cout << add(6, 3.14) << endl;//没有与参数列表匹配的函数模板add(参数类型有两种，无法确定是哪一种)
    //数据的参数是看得见的，在(调用)传参的时候传过去。数据的参数也可以用参数缺省，可以少传两个。
    // 那么类型的参数应该怎么样去传呢？
    // 类型的参数实际上也应该在调用的时候传过去。传到哪个地方呢？
    // 首先，传参需要知道函数名(add)，
    // 另外，类型是在数据前面确定的(Type a, Type b)，所以说在中间搞一个尖括号<>，把类型传过去就可以了
    cout << add<int>(6, 3.14) << endl;    //指明了参数的类型是int(int作为参数传到了Type中)。而3.14实际上是作为double类型传给了int类型的b
    cout << add<double>(6, 3.14) << endl; //同理，6传给double类型的a去接收

    test<const char *, char>("name2", 'S2'); // name2是字符串，字符串没必要每次都使用C++的string类，因为这个东西实际上就是char类型的指针，字符串的首地址。可以加const，加不加const都可以。一般情况下，字符串是默认不能被修改的，可以考虑加上const

    return 0;
}
