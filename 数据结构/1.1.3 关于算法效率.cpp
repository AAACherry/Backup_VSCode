#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start, stop;
double duration;
#define MAXN 10 /* 多项式最大项数，即多项式阶数+1 */
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main()
{
    int i;
    double a[MAXN]; /* 存储多项式的系数 */
    for (i = 0; i < MAXN; i++)  a[i] = (double)i;

    //测试他们的程序的速度
    start = clock();
    f1(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    printf("ticks1 = %f\n", (double)(stop - start)); //算一下ticks的值(他们中间一共跑了多少个tick)
    printf("duration1 = %6.2e\n", duration);

    // f2以此类推
    start = clock();
    f2(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    printf("ticks2 = %f\n", (double)(stop - start));
    printf("duration2 = %6.2e n", duration);
    return 0;
}
