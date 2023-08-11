#include <iostream> //i--in,o--out,stream--流。输入输出流的标准头文件
using namespace std;
#include <fstream> //C++中的头文件是不需要加.h的
// using namespace std::fstream;//有这么一个东西，但是不这么写，只要有std就可以用了。

int main()
{
    fstream obj; //按F12转定义//只要是类，就必定可以定义对象

    /*
        obj.open("test_1.txt", ios::out|ios::trunc); //打开文件，需要两个参数--文件路径和文件的打开方式//路径可以是相对路径,也可以是绝对路径。//可以混合使用。如此处是输出的同时截断一下--以输出文件，并且还希望截断它。防止已经有了同名的文件。
        //in需要从外面读进来，没有的情况下，不能无中生有。而out，把数据给出去，没有这个文件呢，可以自己创建一个文件，然后把你给出去的数据存下来。

        obj.put('S');//向文件当中写入一个字符
        char ch='A';//写完一个之后会接着往后写
        obj.put(ch);

        obj.close();//关闭文件，不需要参数
        obj.is_open();//判断一下是否成功打开了文件，不需要参数
        obj.eof();//eof--end of file是否到达了文件尾，不需要参数 */

    return 0;
}