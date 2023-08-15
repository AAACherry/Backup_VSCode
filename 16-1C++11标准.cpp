/* 
int a = 0;

int b(2, 1);//这个看起来像是调构造函数

int m[4];//这个看起来像是初始化结构体
int n = {(int)3.14};
新的写法不允许有精度的缺失 */

#include <iostream>
using namespace std;

int main()
{
    int num = 0;

    int val(5);
    cout << "val=" << val << endl;

    return 0;
}
