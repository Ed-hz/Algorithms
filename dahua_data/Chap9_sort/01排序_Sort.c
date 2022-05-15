#include <ctype.h>
#include <io.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//@状态
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

//@定义
#define MAX_LENGTH_INSERT_SORT 7
//* 用于快速排序时判断是否选用插入排序阙值
#define MAXSIZE 10000 //* 要排序数组个数 最大值
typedef struct
{
    int r[MAXSIZE + 1]; //* 存储要排序数组---r[0]用作哨兵或临时变量
    int length;         //* 顺序表的长度
} SqList;

//@ 交换L中 数组r 下标为i和j的值
void swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

//@打印元素
void print(SqList L)
{
    int i;
    for (i = 1; i < L.length; i++)
        printf("%d,", L.r[i]);
    printf("%d", L.r[i]);
    printf("\n");
}

//$交换排序（冒泡排序初级版）
void BubbleSort0(SqList *L)
{
    int i, j;
    for (i = 1; i < L->length; i++)
    {
        for (j = i + 1; j <= L->length; j++)
        {
            if (L->r[i] > L->r[j])
            {
                swap(L, i, j);
            }
        }
    }
}

//$冒泡排序
//? 相比交换排序对整体更优
void BubbleSort(SqList *L)
{
    int i, j;
    for (i = 1; i < L->length; i++)
    {
        for (j = L->length - 1; j >= i; j--) //? j从后往前循环
        {
            if (L->r[j] > L->r[j + 1])
            {
                swap(L, j, j + 1);
            }
        }
    }
}

//$改进冒泡算法
//? 对于没排序的部分已经排好的情况 省略之后的交换步骤
void BubbleSort2(SqList *L)
{
    int i, j;
    Status flag = TRUE;
    for (i = 1; i < L->length && flag; i++)
    //- 若flag为true说明有过数据交换，否则停止循环
    {
        flag = FALSE;
        for (j = L->length - 1; j >= i; j--)
        {
            if (L->r[j] > L->r[j + 1])
            {
                swap(L, j, j + 1);
                flag = TRUE;
            }
        }
    }
}

//$ 简单选择排序
//? 略优于冒泡排序
void SelectSort(SqList *L)
{
    int i, j, min;
    for (i = 1; i < L->length; i++)
    {
        min = i;
        for (j = i + 1; j <= L->length; j++)
        {
            if (L->r[min] > L->r[j])
                min = j;
        }

        if (i != min)
            swap(L, i, min);
    }
}

//$ 直接插入排序
//? 比选择排序好点
void InsertSort(SqList *L)
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i] < L->r[i - 1]) //* L->r[i]前已经排好序
        {
            L->r[0] = L->r[i]; //* r[0]哨兵
            for (j = i - 1; L->r[j] > L->r[0]; j--)
                L->r[j + 1] = L->r[j];
            //* L->r[i]找到插入位置
            L->r[j + 1] = L->r[0]; //* 插入
        }
    }
}

//$ 希尔排序
//? 最优复杂度O(n^(3/2))
void ShellSort(SqList *L)
{
    int i, j, k = 0;
    int increment = L->length;
    do
    {
        increment = increment / 3 + 1; //& 增量序列

        //- 跨度increment的插入排序
        for (i = increment + 1; i <= L->length; i++)
        {
            if (L->r[i] < L->r[i - increment])
            {
                L->r[0] = L->r[i];
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
                    L->r[j + increment] = L->r[j];
                L->r[j + increment] = L->r[0];
            }
        }

        // printf("第%d趟排序结果: ", ++k);
        // print(*L);
    } while (increment > 1);
}

//$ 堆排序
//@组成大顶堆
//? 堆是完全二叉树 大顶堆的双亲总大于儿子 s左儿子2s右儿子2s+1
//- 刚开始按照数组顺序就是完全二叉树元素顺序 固定
//- 调整L->r[s],使L->r[成为一个大顶堆
void HeapAdjust(SqList *L, int s, int m)
{
    int temp, j;
    temp = L->r[s];
    for (j = 2 * s; j <= m; j *= 2) //- 迭代把s下最大结点换到上层
    {
        if (j < m && L->r[j] < L->r[j + 1])
            ++j; //- 若左孩子小于右孩子 跳到右孩子
        if (temp >= L->r[j])
            break; //- s下最大结点已经是s
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp; //- 完成交换
}

//@堆排序
//? 最好最坏平均均为复杂度O(nlogn)
void HeapSort(SqList *L)
{
    int i;
    for (i = L->length / 2; i > 0; i--)
        //? 有孩子的结点全部循环 由于完全二叉树 包含所有有孩子的结点
        HeapAdjust(L, i, L->length);
    //? 构建堆复杂度O(n)

    for (i = L->length; i > 1; i--)
    {
        swap(L, 1, i);
        //- 将堆顶记录和 未经排序子序列的最后一个记录交换
        HeapAdjust(L, 1, i - 1);
        //-  将堆顶元素也就是最大元素不管 把剩下元素重新调整为大顶堆
    }
    //? 完全二叉树元素n层数logn 因此重建堆复杂度O(logi)
}

//$ 归并排序
//?最好最坏平均均为O(nlogn) 空间复杂度O(n) 优点为稳定
//$ 递归法
//@ 将两个有序子序列归并为有序的总序列
//& SR的两个子序列归并到TR s t为起始点 m为子序列分割点
void Merge(int SR[], int TR[], int i, int m, int n)
{
    int j, k, l;

    //- 合并两序列重叠部分
    for (k = i, j = m + 1; i <= m && j <= n; k++)
    {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }

    //- 还有多的
    if (i <= m)
    {
        for (l = 0; l <= m - i; l++)
            TR[k + l] = SR[i + l];
    }
    if (j <= n)
    {
        for (l = 0; l <= n - j; l++)
            TR[k + l] = SR[j + l];
    }
}
//& SR为原数组 TR1为完成排序 s t为起始点
void MSort(int SR[], int TR1[], int s, int t)
{
    int m;
    int TR2[MAXSIZE + 1];
    if (s == t)
        TR1[s] = SR[s];
    else
    {
        m = (s + t) / 2; //* 将SR平分
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m + 1, t); //*分别排序
        Merge(TR2, TR1, s, m, t); //* 归并
    }
}

void MergeSort(SqList *L)
{
    MSort(L->r, L->r, 1, L->length);
}

//$ 非递归法
//? 两两归并 n归并长度 s单个片段长度
void MergePass(int SR[], int TR[], int s, int n)
{
    int i = 1;
    int j;
    while (i <= n - 2 * s + 1)
    {
        Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }

    if (i < n - s + 1) //* 归并最后两个序列(2s>剩下长度>s)
        Merge(SR, TR, i, i + s - 1, n);
    else //* 只剩下单个子序列(s>剩下长度) 直接复制
        for (j = i; j <= n; j++)
            TR[j] = SR[j];
}

void MergeSort2(SqList *L)
{
    int *TR = (int *)malloc(L->length * sizeof(int));
    int k = 1;
    while (k < L->length)
    {
        MergePass(L->r, TR, k, L->length);
        k = 2 * k;
        MergePass(TR, L->r, k, L->length);
        k = 2 * k;
        //& 两个序列互相归并 节省空间
    }
}

//$ 快速排序
//? 复杂度最坏O(n^2) 平均O(nlogn) 空间最坏O(n) 平均O(logn)
//& 保证pivotkey左边元素小于 右边元素大于它
//- low为左元素 high为右元素
int Partition(SqList *L, int low, int high)
{
    int pivotkey;

    pivotkey = L->r[low]; //* 用子表的第一个记录作枢轴记录
    while (low < high)    //- 从表的两端交替地向中间扫描
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        swap(L, low, high); //- 将比枢轴记录小的记录交换到低端
        while (low < high && L->r[low] <= pivotkey)
            low++;
        swap(L, low, high); //- 将比枢轴记录大的记录交换到高端
    }
    return low; //* 返回枢轴
}

//& 对子序列作快速排序
void QSort(SqList *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high); //* 算出枢轴值pivo
        QSort(L, low, pivot - 1);        //*  对低子表递归排序
        QSort(L, pivot + 1, high);       //*  对高子表递归排序
    }
}

void QuickSort(SqList *L)
{
    QSort(L, 1, L->length);
}

//$ 改进后快速排序
int Partition1(SqList *L, int low, int high)
{
    int pivotkey;

    //& 三数取中 比较后L->r[low]为三数中中间值 可扩展为⑨数取中
    int m = low + (high - low) / 2;
    if (L->r[low] > L->r[high])
        swap(L, low, high);
    if (L->r[m] > L->r[high])
        swap(L, high, m);
    if (L->r[m] > L->r[low])
        swap(L, m, low);

    pivotkey = L->r[low];
    L->r[0] = pivotkey; //* 将枢轴关键字备份到L->r[0]
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        L->r[low] = L->r[high];
        while (low < high && L->r[low] <= pivotkey)
            low++;
        L->r[high] = L->r[low];
        //& 增加了哨兵之后不用交换，只要一个等于就行
    }
    L->r[low] = L->r[0];
    return low;
}

void QSort1(SqList *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        pivot = Partition1(L, low, high);
        QSort1(L, low, pivot - 1);
        QSort1(L, pivot + 1, high);
    }
    else
        InsertSort(L); //& 对于简单元素直接用简单插入排序即可
}

void QuickSort1(SqList *L)
{
    QSort1(L, 1, L->length);
}

//@ 尾递归
void QSort2(SqList *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        while (low < high)
        {
            pivot = Partition1(L, low, high);
            QSort2(L, low, pivot - 1);
            low = pivot + 1; //* 尾递归 省略调用堆栈
        }
    }
    else
        InsertSort(L);
}
void QuickSort2(SqList *L)
{
    QSort2(L, 1, L->length);
}

//@
void test_time(void (*fp)(SqList *), SqList *L)
{
    clock_t start, finish;
    double duration;

    start = clock();
    (*fp)(L);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
}

#define N 9
int main()
{
    int i;

    // int d[N]={9,1,5,8,3,7,4,6,2};
    // int d[N]={9,8,7,6,5,4,3,2,1};
    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};

    SqList l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11;
    for (i = 0; i < N; i++)
        l0.r[i + 1] = d[i];
    l0.length = N;
    srand(time(0));
    int Max = 10000;
    int Big_d[10000];
    int Big_i;
    SqList Big_l0;
    for (Big_i = 0; Big_i < Max; Big_i++)
        Big_d[Big_i] = rand() % Max + 1;
    for (Big_i = 0; Big_i < Max; Big_i++)
        Big_l0.r[Big_i + 1] = Big_d[Big_i];
    Big_l0.length = Max;
    l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l11 = Big_l0;

    printf("排序前:\n");
    print(l0);

    printf("初级冒泡排序:\n");
    test_time(BubbleSort0, &Big_l0);
    // print(l0);

    printf("冒泡排序:\n");
    test_time(BubbleSort, &l1);
    // print(l1);

    printf("改进冒泡排序:\n");
    test_time(BubbleSort2, &l2);
    // print(l2);

    printf("选择排序:\n");
    test_time(SelectSort, &l3);
    // print(l3);

    printf("直接插入排序:\n");
    test_time(InsertSort, &l4);
    // print(l4);

    printf("希尔排序:\n");
    test_time(ShellSort, &l5);
    // print(l5);

    printf("堆排序:\n");
    test_time(HeapSort, &l6);
    // print(l6);

    printf("归并排序(递归):\n");
    test_time(MergeSort, &l7);
    // print(l7);

    printf("归并排序(非递归):\n");
    test_time(MergeSort2, &l8);
    // print(l8);

    printf("快速排序:\n");
    test_time(QuickSort, &l9);
    // print(l9);

    printf("改进快速排序:\n");
    test_time(QuickSort1, &l10);
    // print(l10);

    printf("改进快速排序(尾递归):\n");
    test_time(QuickSort2, &l11);
    // print(l11);

    /*大数据排序
    srand(time(0));
    int Max = 10000;
    int Big_d[10000];
    int Big_i;
    SqList Big_l0;
    for (Big_i = 0; Big_i < Max; Big_i++)
        Big_d[Big_i] = rand() % Max + 1;
    for (Big_i = 0; Big_i < Max; Big_i++)
        Big_l0.r[Big_i + 1] = Big_d[Big_i];
    Big_l0.length = Max;
    MergeSort(&Big_l0);
    print(Big_l0);*/

    return 0;
}
