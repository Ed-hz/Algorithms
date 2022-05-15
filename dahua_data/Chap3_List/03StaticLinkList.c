//!用数组而非指针实现的链表
//- 优点 插入删除不需要移动元素
//- 缺点 必须固定存储空间容量 不能随机存取

#include <ctype.h>
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
typedef int Status; ///& Status是函数结果状态代码,如OK等

//@定义
#define MAXSIZE 10000  //& 存储空间初始分配量
typedef char ElemType; ///& ElemType类型,设为char
typedef struct
{
    ElemType data;
    int cur; //& 游标(Cursor) 为0时表示无指向
} Component, StaticLinkList[MAXSIZE];

//@访问元素
Status visit(ElemType c)
{
    printf("%c ", c);
    return OK;
}

//@备用链表
//& 将一维数组space链成一个备用链表，space[0].cur为头指针
//- "0"表示空指针
Status InitList(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
    //& 目前静态链表为空，最后一个元素的cur为0
    return OK;
}

//@分配一个元素
//& 若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SSL(StaticLinkList space)
{
    int i = space[0].cur;
    //& 当前数组第一个元素的cur存的值就是要返回的第一个备用空闲的下标
    if (space[0].cur)
        space[0].cur = space[i].cur; //& 下一个分量备用
    return i;
}

//@元素个数
int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;

    while (i)
    {
        i = L[i].cur;
        j++;
    }
    return j;
}

//@插入
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1; //& 注意k首先是最后一个元素的下标

    if (i < 1 || i > ListLength(L) + 1)
        return ERROR;

    j = Malloc_SSL(L); //& 获得空闲分量的下标
    if (j)
    {
        L[j].data = e;
        for (l = 1; l <= i - 1; l++) //& 找到第i个元素之前的位置
            k = L[k].cur;
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

//@回收要删除节点
//& 将下标为k的空闲结点回收到备用链表
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    //& 把第一个元素的cur值赋给要删除的分量cur
    space[0].cur = k;
    //& 把要删除的分量下标赋值给第一个元素的cur
}

//@删除
//& 删除在L中第i个数据元素
Status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if (i < 1 || i > ListLength(L))
        return ERROR;
    k = MAXSIZE - 1;
    for (j = 1; j <= i - 1; j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}

//@输出
Status ListTraverse(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;

    while (i)
    {
        visit(L[i].data);
        i = L[i].cur;
        j++;
    }
    return j;
    printf("\n");
    return OK;
}

int main()
{
    StaticLinkList L;
    Status i;

    //@初始化
    i = InitList(L);
    printf("初始化L后:L.length=%d\n", ListLength(L));

    //@插入
    i = ListInsert(L, 1, 'F');
    i = ListInsert(L, 1, 'E');
    i = ListInsert(L, 1, 'D');
    i = ListInsert(L, 1, 'B');
    i = ListInsert(L, 1, 'A');

    printf("\n在L的表头依次插入FEDBA后:\nL.data=");
    ListTraverse(L);

    i = ListInsert(L, 3, 'C');
    printf("\n在L的“B”与“D”之间插入“C”后:\nL.data=");
    ListTraverse(L);
    //@删除元素
    i = ListDelete(L, 1);
    printf("\n在L的删除“A”后:\nL.data=");
    ListTraverse(L);

    return 0;
}
