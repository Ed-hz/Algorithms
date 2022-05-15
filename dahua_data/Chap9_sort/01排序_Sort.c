#include <ctype.h>
#include <io.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//@״̬
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

//@����
#define MAX_LENGTH_INSERT_SORT 7
//* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ
#define MAXSIZE 10000 //* Ҫ����������� ���ֵ
typedef struct
{
    int r[MAXSIZE + 1]; //* �洢Ҫ��������---r[0]�����ڱ�����ʱ����
    int length;         //* ˳���ĳ���
} SqList;

//@ ����L�� ����r �±�Ϊi��j��ֵ
void swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

//@��ӡԪ��
void print(SqList L)
{
    int i;
    for (i = 1; i < L.length; i++)
        printf("%d,", L.r[i]);
    printf("%d", L.r[i]);
    printf("\n");
}

//$��������ð����������棩
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

//$ð������
//? ��Ƚ���������������
void BubbleSort(SqList *L)
{
    int i, j;
    for (i = 1; i < L->length; i++)
    {
        for (j = L->length - 1; j >= i; j--) //? j�Ӻ���ǰѭ��
        {
            if (L->r[j] > L->r[j + 1])
            {
                swap(L, j, j + 1);
            }
        }
    }
}

//$�Ľ�ð���㷨
//? ����û����Ĳ����Ѿ��źõ���� ʡ��֮��Ľ�������
void BubbleSort2(SqList *L)
{
    int i, j;
    Status flag = TRUE;
    for (i = 1; i < L->length && flag; i++)
    //- ��flagΪtrue˵���й����ݽ���������ֹͣѭ��
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

//$ ��ѡ������
//? ������ð������
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

//$ ֱ�Ӳ�������
//? ��ѡ������õ�
void InsertSort(SqList *L)
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i] < L->r[i - 1]) //* L->r[i]ǰ�Ѿ��ź���
        {
            L->r[0] = L->r[i]; //* r[0]�ڱ�
            for (j = i - 1; L->r[j] > L->r[0]; j--)
                L->r[j + 1] = L->r[j];
            //* L->r[i]�ҵ�����λ��
            L->r[j + 1] = L->r[0]; //* ����
        }
    }
}

//$ ϣ������
//? ���Ÿ��Ӷ�O(n^(3/2))
void ShellSort(SqList *L)
{
    int i, j, k = 0;
    int increment = L->length;
    do
    {
        increment = increment / 3 + 1; //& ��������

        //- ���increment�Ĳ�������
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

        // printf("��%d��������: ", ++k);
        // print(*L);
    } while (increment > 1);
}

//$ ������
//@��ɴ󶥶�
//? ������ȫ������ �󶥶ѵ�˫���ܴ��ڶ��� s�����2s�Ҷ���2s+1
//- �տ�ʼ��������˳�������ȫ������Ԫ��˳�� �̶�
//- ����L->r[s],ʹL->r[��Ϊһ���󶥶�
void HeapAdjust(SqList *L, int s, int m)
{
    int temp, j;
    temp = L->r[s];
    for (j = 2 * s; j <= m; j *= 2) //- ������s������㻻���ϲ�
    {
        if (j < m && L->r[j] < L->r[j + 1])
            ++j; //- ������С���Һ��� �����Һ���
        if (temp >= L->r[j])
            break; //- s��������Ѿ���s
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp; //- ��ɽ���
}

//@������
//? ����ƽ����Ϊ���Ӷ�O(nlogn)
void HeapSort(SqList *L)
{
    int i;
    for (i = L->length / 2; i > 0; i--)
        //? �к��ӵĽ��ȫ��ѭ�� ������ȫ������ ���������к��ӵĽ��
        HeapAdjust(L, i, L->length);
    //? �����Ѹ��Ӷ�O(n)

    for (i = L->length; i > 1; i--)
    {
        swap(L, 1, i);
        //- ���Ѷ���¼�� δ�����������е����һ����¼����
        HeapAdjust(L, 1, i - 1);
        //-  ���Ѷ�Ԫ��Ҳ�������Ԫ�ز��� ��ʣ��Ԫ�����µ���Ϊ�󶥶�
    }
    //? ��ȫ������Ԫ��n����logn ����ؽ��Ѹ��Ӷ�O(logi)
}

//$ �鲢����
//?����ƽ����ΪO(nlogn) �ռ临�Ӷ�O(n) �ŵ�Ϊ�ȶ�
//$ �ݹ鷨
//@ ���������������й鲢Ϊ�����������
//& SR�����������й鲢��TR s tΪ��ʼ�� mΪ�����зָ��
void Merge(int SR[], int TR[], int i, int m, int n)
{
    int j, k, l;

    //- �ϲ��������ص�����
    for (k = i, j = m + 1; i <= m && j <= n; k++)
    {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }

    //- ���ж��
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
//& SRΪԭ���� TR1Ϊ������� s tΪ��ʼ��
void MSort(int SR[], int TR1[], int s, int t)
{
    int m;
    int TR2[MAXSIZE + 1];
    if (s == t)
        TR1[s] = SR[s];
    else
    {
        m = (s + t) / 2; //* ��SRƽ��
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m + 1, t); //*�ֱ�����
        Merge(TR2, TR1, s, m, t); //* �鲢
    }
}

void MergeSort(SqList *L)
{
    MSort(L->r, L->r, 1, L->length);
}

//$ �ǵݹ鷨
//? �����鲢 n�鲢���� s����Ƭ�γ���
void MergePass(int SR[], int TR[], int s, int n)
{
    int i = 1;
    int j;
    while (i <= n - 2 * s + 1)
    {
        Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }

    if (i < n - s + 1) //* �鲢�����������(2s>ʣ�³���>s)
        Merge(SR, TR, i, i + s - 1, n);
    else //* ֻʣ�µ���������(s>ʣ�³���) ֱ�Ӹ���
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
        //& �������л���鲢 ��ʡ�ռ�
    }
}

//$ ��������
//? ���Ӷ��O(n^2) ƽ��O(nlogn) �ռ��O(n) ƽ��O(logn)
//& ��֤pivotkey���Ԫ��С�� �ұ�Ԫ�ش�����
//- lowΪ��Ԫ�� highΪ��Ԫ��
int Partition(SqList *L, int low, int high)
{
    int pivotkey;

    pivotkey = L->r[low]; //* ���ӱ�ĵ�һ����¼�������¼
    while (low < high)    //- �ӱ�����˽�������м�ɨ��
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        swap(L, low, high); //- ���������¼С�ļ�¼�������Ͷ�
        while (low < high && L->r[low] <= pivotkey)
            low++;
        swap(L, low, high); //- ���������¼��ļ�¼�������߶�
    }
    return low; //* ��������
}

//& ������������������
void QSort(SqList *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high); //* �������ֵpivo
        QSort(L, low, pivot - 1);        //*  �Ե��ӱ�ݹ�����
        QSort(L, pivot + 1, high);       //*  �Ը��ӱ�ݹ�����
    }
}

void QuickSort(SqList *L)
{
    QSort(L, 1, L->length);
}

//$ �Ľ����������
int Partition1(SqList *L, int low, int high)
{
    int pivotkey;

    //& ����ȡ�� �ȽϺ�L->r[low]Ϊ�������м�ֵ ����չΪ����ȡ��
    int m = low + (high - low) / 2;
    if (L->r[low] > L->r[high])
        swap(L, low, high);
    if (L->r[m] > L->r[high])
        swap(L, high, m);
    if (L->r[m] > L->r[low])
        swap(L, m, low);

    pivotkey = L->r[low];
    L->r[0] = pivotkey; //* ������ؼ��ֱ��ݵ�L->r[0]
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        L->r[low] = L->r[high];
        while (low < high && L->r[low] <= pivotkey)
            low++;
        L->r[high] = L->r[low];
        //& �������ڱ�֮���ý�����ֻҪһ�����ھ���
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
        InsertSort(L); //& ���ڼ�Ԫ��ֱ���ü򵥲������򼴿�
}

void QuickSort1(SqList *L)
{
    QSort1(L, 1, L->length);
}

//@ β�ݹ�
void QSort2(SqList *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        while (low < high)
        {
            pivot = Partition1(L, low, high);
            QSort2(L, low, pivot - 1);
            low = pivot + 1; //* β�ݹ� ʡ�Ե��ö�ջ
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

    printf("����ǰ:\n");
    print(l0);

    printf("����ð������:\n");
    test_time(BubbleSort0, &Big_l0);
    // print(l0);

    printf("ð������:\n");
    test_time(BubbleSort, &l1);
    // print(l1);

    printf("�Ľ�ð������:\n");
    test_time(BubbleSort2, &l2);
    // print(l2);

    printf("ѡ������:\n");
    test_time(SelectSort, &l3);
    // print(l3);

    printf("ֱ�Ӳ�������:\n");
    test_time(InsertSort, &l4);
    // print(l4);

    printf("ϣ������:\n");
    test_time(ShellSort, &l5);
    // print(l5);

    printf("������:\n");
    test_time(HeapSort, &l6);
    // print(l6);

    printf("�鲢����(�ݹ�):\n");
    test_time(MergeSort, &l7);
    // print(l7);

    printf("�鲢����(�ǵݹ�):\n");
    test_time(MergeSort2, &l8);
    // print(l8);

    printf("��������:\n");
    test_time(QuickSort, &l9);
    // print(l9);

    printf("�Ľ���������:\n");
    test_time(QuickSort1, &l10);
    // print(l10);

    printf("�Ľ���������(β�ݹ�):\n");
    test_time(QuickSort2, &l11);
    // print(l11);

    /*����������
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
