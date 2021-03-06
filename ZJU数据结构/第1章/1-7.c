#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t  start, stop;  /* clock_t是clock()函数返回的变量类型 */
double  duration;      /* 记录被测函数运行时间，以秒为单位 */
#define MAXN 10        /* 多项式最大项数，即多项式阶数+1 */
#define MAXK 1e7       /* 被测函数最大重复调用次数 */

double f( int n, double a[], double x );

int main ()
{	/* 测试多项式求值函数的运行时间 */
	int i;
	double a[MAXN]; /* 存储多项式的系数 */
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i; 
	/* 给f(x)的系数a[]赋值 */

	start = clock(); /* 开始计时 */
	for ( i=0; i<MAXK; i++ ) /* 重复调用函数以获得充分多的时钟打点数*/
		f(MAXN-1, a, 1.1); 
	stop = clock();	/* 停止计时 */
	duration = ((double)(stop - start))/CLK_TCK/MAXK; 
	/* 计算函数单次运行的时间 */

	printf("ticks = %f\n", (double)(stop - start));
	printf("duration= %6.2e\n", duration);

	return 0;
}

/* 运行时可使用下列两个*.h文件之一 */
/* #include "1-4.h" */
/* #include "1-5.h" */
