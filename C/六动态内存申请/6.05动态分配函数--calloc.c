/*
在怎么看申请的内存总数上：malloc和calloc的区别就相当于静态内存中的一维数组和二维数组。malooc是在内存的堆中，申请一块长度为size字节的连续区域，而calloc是在内存的堆中，申请nmemb块，每块的大小为size个字节的连续区域。

头文件:#include <stdlib.h>
函数定义:void *calloc(size_t nmemb, size_t size);
//size_t实际是无符号整型，它是在头文件中，用typeof定义出来的。//typedef相当于对我们的类型取别名
函数的功能：在堆区申请指定大小的空间（在内存的堆中，申请nmemb块，每块的大小为size个字节的连续区域）
参数：
    nmemb：要申请的空间的块数
    size：每块的字节数
返回值：
    成功：申请空间的首地址
    失败：NULL
注意：
    malloc和calloc函数都是用来申请内存的。

    区别：
        1) 函数的名字不一样
        2) 参数的个数不一样
        3) malloc申请的内存，内存中存放的内容是随机的，不确定的，而calloc函数申请的内存中的内容为0
例如：
    char *p=(char *)calloc(3,100);
    在堆中申请了3块，每块大小为100个字节，即300个字节连续的区域。
 */