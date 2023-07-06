#include <iostream>
using namespace std;

int main()
{
    // 1.申请单个内存
    int *p1 = new int; // new是分配（申请）内存的关键字
    *p1 = 0;

    // 2.申请单个内存且初始化
    int *p2 = new int(999);        //圆括号--值
    cout << "*p2=" << *p2 << endl; //输出：*p2=999

    // 3.批量申请(连续内存)连续内存就无法给初值了(无法初始化)，因为没有空位
    //只能给定长度，后续再进行赋值
    int *p3 = new int[10]; //中括号--个数
    for (size_t i = 0; i < 10; i++)
    {
        p3[i] = i;
        // cout<<"*p3[%d]="<<p3[i]<<endl;
        cout << "p3[" << i << "]=" << p3[i] << endl;
    }

    // delete释放内存（归还）
    //  delete 变量;   这种写法只能释放一个
    delete p1; //直接释放掉p1
    delete p2; // p2同理
    // delete p3;   p3不可这样操作，这样只释放一个

    delete[] p3; // delete后面加上中括号[]即可释放一段连续的内存,全释放
    //连续释放内存，中括号[]后的必须是首地址（p3），否则会有一部分释放不掉
    //从当前位置开始向后释放到标记位置

    /* 自测
        cout << "*p1=" << *p1 << endl;
        cout << "*p2=" << *p2 << endl;
        for (size_t i = 0; i < 10; i++)
        {
            p3[i] = i;
            //cout<<"*p3[%d]="<<p3[i]<<endl;
            cout << "p3[" << i << "]=" << p3[i] << endl;
        }
    */
}
