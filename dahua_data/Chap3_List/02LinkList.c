//-头节点在第一元素前，数据域无意义，不是必要元素
//-头指针指向第一个节点（有头节点时为头节点，否则为第一元素），无论链表是否空都存在，空时为null
//?存取时间最好O(1),最坏O(n)
//?删除插入一系列 第一次O(n),后面几次O(1)
//- 优点 不用预先分配内存
//- 缺点

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
typedef int Status; //* Status是函数结果状态代码,如OK等

//@定义
#define MAXSIZE 20    //& 存储空间初始分配量
typedef int ElemType; //* ElemType类型,设为int
typedef struct Node
{
    ElemType data;     //?数据域
    struct Node *next; //?指针域
    //& 直向下一元素指针
} Node;
typedef struct Node *LinkList; //& 定义LinkList

//@访问元素
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ 初始化
Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    //& 产生头结点,并使L指向此头结点

    if (!(*L)) //* 存储分配失败
        return ERROR;
    (*L)->next = NULL; //& 指针域为空

    return OK;
}

//@是否存在
//& 若L为空表，则返回TRUE，否则返回FALSE
Status ListEmpty(LinkList L)
{
    if (L->next)
        return FALSE;
    else
        return TRUE;
}

//@重置为空表
Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next; //& p指向第一个结点

    while (p) //* 没到表尾
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL; //& 头结点指针域为空
    return OK;
}

//@元素个数
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next; //& p指向第一个结点

    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//@返回元素
//& 返回L中第i个数据元素的值,存在e中

//& 若顺序线性表L已存在，1≤i≤ListLength(L)
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;
    p = L->next; //& p指向第一个结点
    j = 1;

    while (p && j < i) //* p不为空，计数器j≠i时，循环继续
    {
        p = p->next; //& 让p指向下一个结点
        ++j;
    }

    if (!p || j > i) //* 第i个元素不存在
        return ERROR;

    *e = p->data; //& 取第i个元素的数据
    return OK;
}

//@返回位置
//& 若不存在，则返回值为0
int LocateElem(LinkList L, ElemType e)
{
    int i = 0;
    LinkList p = L->next;

    while (p)
    {
        i++;
        if (p->data == e)
            return i;
        p = p->next;
    }

    return 0;
}

//@插入
//& 在L中第i个位置前插入e，L的长度加1
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;

    while (p && j < i) //* 寻找第i个结点
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i) //* 第i个元素不存在
        return ERROR;

    s = (LinkList)malloc(sizeof(Node)); //& 生成新结点
    s->data = e;
    s->next = p->next; //& 将p的后继结点赋值给s的后继
    p->next = s;       //& 将s赋值给p的后继
    return OK;
}

//@删除
//& 删除L的第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;

    while (p->next && j < i) //* 遍历寻找第i个元素
    {
        p = p->next;
        ++j;
    }

    if (!(p->next) || j > i) //* 第i个元素不存在
        return ERROR;

    q = p->next;
    p->next = q->next; //& 将q的后继赋值给p的后继
    *e = q->data;      //& 将q结点中的数据给e
    free(q);           //& 让系统回收此结点，释放内存
    return OK;
}

//@输出
//& 依次对L的每个数据元素输出
Status ListTraverse(LinkList L)
{
    LinkList p = L->next;

    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

//@头插法
//& 随机产生n个元素的值，建立带表头结点的单链线性表L
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;

    srand(time(0)); //& 初始化随机数种子
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL; //& 先建立一个带头结点的单链表

    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); //& 生成新结点
        p->data = rand() % 100 + 1;         //& 随机生成100以内的数字
        p->next = (*L)->next;
        (*L)->next = p; //& 插入到表头
    }
}

//@尾插法
//& 随机产生n个元素的值，建立带表头结点的单链线性表L
void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    int i;

    srand(time(0));                      //& 初始化随机数种子
    *L = (LinkList)malloc(sizeof(Node)); //& L为整个线性表
    r = *L;                              //? r为指向尾部的结点

    for (i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node)); //& 生成新结点
        p->data = rand() % 100 + 1;       //& 随机生成100以内的数字
        r->next = p;
        //& 将表尾终端结点的指针指向新结点
        r = p;
        //& 将当前的新结点定义为表尾终端结点
    }
    r->next = NULL; //& 表示当前链表结束
}

//@合并
//& 将所有的在线性表Lb中但不在La中的数据元素插入到La中
void unionL(LinkList *La, LinkList *Lb)
{
    Node *Lc = *La;
    while (Lc->next)
        Lc = Lc->next;
    Lc->next = (*Lb)->next;
}

int main()
{
    LinkList L, M;
    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);

    //@初始化
    printf("初始化L后:ListLength(L)=%d\n\n", ListLength(L));
    //@插入
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("插入1～5后:\nL.data=");
    ListTraverse(L);
    printf("\n");
    //@长度
    printf("ListLength(L)=%d \n\n", ListLength(L));

    //@是否为空
    i = ListEmpty(L);
    printf("L是否空:i=%d(1:是 0:否)\n\n", i);
    //@清空
    i = ClearList(&L);
    printf("清空L后:ListLength(L)=%d\n", ListLength(L));
    i = ListEmpty(L);
    printf("L是否空:i=%d(1:是 0:否)\n\n", i);

    //@插入
    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("在L的表尾依次插入1～10后:\nL.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n\n", ListLength(L));
    //@插入一个
    ListInsert(&L, 1, 0);
    printf("在L的表头插入0后:\nL.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n\n", ListLength(L));

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

    //@合并
    InitList(&M);
    for (j = 1; j <= 10; j++)
        ListInsert(&M, j, 10 - j);
    unionL(&L, &M);
    printf("依次输出L的元素:");
    ListTraverse(L);
    printf("\n");

    //@头插法
    i = ClearList(&L);
    printf("\n清空L后:ListLength(L)=%d\n", ListLength(L));
    CreateListHead(&L, 20);
    printf("整体创建L的元素(头插法):");
    ListTraverse(L);
    //@尾插法
    i = ClearList(&L);
    printf("\n删除L后:ListLength(L)=%d\n", ListLength(L));
    CreateListTail(&L, 20);
    printf("整体创建L的元素(尾插法):");
    ListTraverse(L);

    return 0;
}
