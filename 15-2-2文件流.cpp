#include <iostream> //i--in,o--out,stream--流。输入输出流的标准头文件
using namespace std;
#include <fstream> //C++中的头文件是不需要加.h的
// using namespace std::fstream;//有这么一个东西，但是不这么写，只要有std就可以用了。

int main()
{
    fstream obj; //按F12转定义//只要是类，就必定可以定义对象

    obj.open("test_2.txt", ios::out);
    int num = 99;
    obj.write((const char *)&num, sizeof(int)); // num这里类型不匹配，write是需要一个const char类型的指针，也就是需要寻到它的地址，然后把里面的东西直接拿到文件里面去,所以考虑取num的首地址。
    obj.close();                                //关闭文件，不需要参数

    obj.open("test_2.txt", ios::in);
    int val = 0;
    obj.read((char *)&val, sizeof(int));
    obj.close(); //不管怎么样，打开了要关闭。
    cout << "val=" << val << endl;

    return 0;
}