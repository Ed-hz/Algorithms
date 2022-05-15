//?存取时间O(1),随机存取结构
//?删除最好O(1),最坏O(n),平均O(n)
//- 优点 空间不多，快速存取
//- 缺点 插入删除慢 必须固定存储空间容量 存储空间碎片化

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//@状态
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; //* Status是函数结果状态代码,如OK等

//@定义
#define MAXSIZE 20    //& 存储空间初始分配量
typedef int ElemType; //* ElemType类型,设为int
typedef struct
{
    ElemType data[MAXSIZE]; //* 数组，存储数据元素
    int length;             //* 线性表长度
} SqList;

//@访问元素
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

//@初始化
Status InitList(SqList *L)
{
    L->length = 0;
    return OK;
}

//@是否存在
//& 若L为空表，则返回TRUE，否则返回FALSE
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

//@重置为空表
Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

//@元素个数
int ListLength(SqList L)
{
    return L.length;
}

//@返回元素
//& 返回L中第i个数据元素的值,存在e中
//& 若顺序线性表L已存在，1≤i≤ListLength(L)
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];

    return OK;
}

//@返回位置
//& 若不存在，则返回值为0
int LocateElem(SqList L, ElemType e)
{
    int i;
    if (L.length == 0)
        return 0;

    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            break;
    }

    if (i >= L.length)
        return 0;

    return i + 1;
}

//@插入
//& 在L中第i个位置前插入e，L的长度加1//@在L中第i个位置前插入e，L的长度加1
Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE) //* 顺序线性表已经满
        return ERROR;
    if (i < 1 || i > L->length + 1)
        //* i比第一位小或者比最后一位大
        return ERROR;

    if (i <= L->length) //* 若插入数据位置不在表尾
    {
        for (k = L->length - 1; k >= i - 1; k--)
            //& 将插入位置之后的元素后移一位
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;

    L->length++;
    return OK;
}

//@删除
//& 删除L的第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0) //* 线性表为空
        return ERROR;
    if (i < 1 || i > L->length) //* 删除位置不正确
        return ERROR;

    *e = L->data[i - 1];
    if (i < L->length) //* 如果删除不是最后位置
    {
        for (k = i; k < L->length; k++) //& 将删除位置后继元素前移
            L->data[k - 1] = L->data[k];
    }

    L->length--;
    return OK;
}

//@输出
//& 依次对L的每个数据元素输出
Status ListTraverse(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        visit(L.data[i]);
    printf("\n");
    return OK;
}

//@合并
//& 将所有的在线性表Lb中但不在La中的数据元素插入到La中
void unionL(SqList *La, SqList Lb)
{
    int La_len, Lb_len, i;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb); //& 求线性表的长度

    ElemType e; //& 声明与La和Lb相同的数据元素e
    for (i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, &e);              //& 取Lb中第i个数据元素赋给e
        if (!LocateElem(*La, e))         //& La中不存在和e相同数据元素
            ListInsert(La, ++La_len, e); //& 插入
    }
}

int main()
{

    SqList L;
    SqList Lb;
    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);

    //@初始化
    printf("初始化L后:L.length=%d\n\n", L.length);
    //@插入
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("插入1～5后:\nL.data=");
    ListTraverse(L);
    printf("\n");
    //@长度
    printf("L.length=%d \n\n", L.length);

    //@是否为空
    i = ListEmpty(L);
    printf("L是否空:i=%d(1:是 0:否)\n\n", i);
    //@清空
    i = ClearList(&L);
    printf("清空L后:L.length=%d\n", L.length);
    i = ListEmpty(L);
    printf("L是否空:i=%d(1:是 0:否)\n\n", i);

    //@表尾插入
    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("在L的表尾依次插入1～10后:\nL.data=");
    ListTraverse(L);
    printf("L.length=%d \n\n", L.length);
    //@插入一个
    ListInsert(&L, 1, 0);
    printf("在L的表头插入0后:\nL.data=");
    ListTraverse(L);
    printf("L.length=%d \n\n", L.length);

    //@取得元素
    GetElem(L, 5, &e);
    printf("第5个元素的值为:%d\n", e);
    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j);
        if (k)
            printf("第%d个元素的值为%d\n", k, j);
        else
            printf("没有值为%d的元素\n", j);
    }
    printf("\n");

    //@删除元素
    k = ListLength(L); //& k为表长
    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(&L, j, &e); //& 删除第j个数据
        if (i == ERROR)
            printf("删除第%d个数据失败\n", j);
        else
            printf("删除第%d个的元素值为:%d\n", j, e);
    }
    printf("依次输出L的元素:");
    ListTraverse(L);
    printf("\n");
    //@删除一个
    j = 5;
    ListDelete(&L, j, &e); //& 删除第5个数据
    printf("删除第%d个的元素值为:%d\n", j, e);

    printf("依次输出L的元素:");
    ListTraverse(L);
    printf("\n");

    //@合并元素
    i = InitList(&Lb);
    for (j = 6; j <= 15; j++)
        i = ListInsert(&Lb, 1, j);
    unionL(&L, Lb);

    printf("依次输出合并了Lb的L的元素:");
    ListTraverse(L);

    return 0;
}
