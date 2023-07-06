#include <stdio.h>
#include <iostream> //要想使用cin和cout先引入头文件
// using namespace std;
using std::cin;
using std::cout;
using std::endl; // std空间太大，只需使用这三个时，可这样操作
int main()
{
    int num;
    std::cin >> num;
    std::cout << num << std::endl; // endl是换行
    // cin和cout和endl都在命名空间std中
    int num2;
    cin >> num2;
    cout << "num2=" << num2 << endl;
    //要想简化代码，省去STD,先using namespace std;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << a << b << c << d << e << f << endl;
}
