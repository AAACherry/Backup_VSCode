#include <stdio.h>
#include <iostream>
#include <string.h> //C语言中是string.h
#include <string>   //C++的头文件不需要加.h，二者不是一个文件
// C++中是string，C++兼容C，所以用string.h也可以访问到，并不会报错
using namespace std;

class Sheep
{
public:
    char name[32];
    string name_str;
};

int main()
{
    string str;
    str = "abc123";   //字符数组中不可以，string中可以
    char ch = str[2]; //直接得到下标为2的字符
    ch = str.at(1);   //得到下标为1的字符
    str.length();     //求string的长度
    // str.clear();//清空字符串，清空string中的内容
    str.empty(); //判断是否为空
    str == str;  //直接通过==去对比两个字符串

    Sheep xiYY;
    xiYY.name_str = "xiYY";
    cout << "My name is:" << xiYY.name_str << endl;
}