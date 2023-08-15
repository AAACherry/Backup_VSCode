#include <iostream> //i--in,o--out,stream--流。输入输出流的标准头文件
using namespace std;
#include <fstream> //C++中的头文件是不需要加.h的
// using namespace std::fstream;//有这么一个东西，但是不这么写，只要有std就可以用了。

int main()
{
    fstream obj; //按F12转定义//只要是类，就必定可以定义对象

    obj.open("test_3.txt", ios::out);
    // obj << "勇敢牛牛 不怕困难" << endl;//光标在最后面，加上endl的话光标跑到最前面去了
    //如果此处有空格，会判定为0，空格会判定为中断，中断在out还是可以正常给出去，但是in中就会有问题。
    obj << "勇敢牛牛,不怕困难" << endl;
    //勇敢牛牛给str,不怕困难给到int类型的num,如果逗号是空格，那么勇敢牛牛还是正常给到str,但是不怕困难就给不到num
    obj << "123" << endl;
    obj.close(); //关闭文件，不需要参数

    char str[64];
    int num = 0;
    obj.open("test_3.txt", ios::in);
    obj >> str;
    obj >> num;
    obj.close(); //不管怎么样，打开了要关闭。
    cout << str << endl;
    cout << "num=" << num << endl;
    //想要少量的精准的去读取的话,读一个字符就行了。一个字符不够的话就多读几次然后存到一个字符数组里面。但是读一个字符由于中文是要占两个字符的空间，那么一个中文如果分两次去阅读就会出现问题，所以尽量不要用中文

    return 0;
}