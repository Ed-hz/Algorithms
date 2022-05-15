//? 顺序二叉树
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
typedef int Status;

//@定义
#define MAXSIZE 100       //& 存储空间初始分配量
#define MAX_TREE_SIZE 100 //& 二叉树的最大结点数
typedef int TElemType;    //* ElemType类型,设为int
typedef TElemType SqBiTree[MAX_TREE_SIZE];
//- 0号单元存储根结点

typedef struct
{
    int level, order; //* 结点的层,本层序号(按满二叉树计算)
} Position;

TElemType Nil = 0; //& 定义空格符0

//@访问元素
Status visit(TElemType c)
{
    printf("%d ", c);
    return OK;
}

//@初始化树
Status InitBiTree(SqBiTree T)
{
    int i;
    for (i = 0; i < MAX_TREE_SIZE; i++)
        T[i] = Nil;
    return OK;
}
#define ClearBiTree InitBiTree //* 在顺序存储结构中，两函数完全一样

//@创建树
Status CreateBiTree(SqBiTree T)
{
    int i = 0;
    printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n", MAX_TREE_SIZE);

    while (i < 10)
    {
        T[i] = i + 1;

        if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
        //* 此结点(不空)无双亲且不是根
        {
            printf("出现无双亲的非根结点%d\n", T[i]);
            exit(ERROR);
        }
        i++;
    }
    while (i < MAX_TREE_SIZE)
    {
        T[i] = Nil; //* 将空赋值给T的后面的结点
        i++;
    }

    return OK;
}

//@是否为空
Status BiTreeEmpty(SqBiTree T)
{
    if (T[0] == Nil)
        return TRUE;
    else
        return FALSE;
}

//@二叉树深度
int BiTreeDepth(SqBiTree T)
{
    int i, j = -1;
    for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
        if (T[i] != Nil)
            break;
    i++; //* 找到最后一个结点T[i]

    do
        j++;
    while (i >= powl(2, j)); //* 求log(i)
    return j;
}

//@返回二叉树的根
Status Root(SqBiTree T, TElemType *e)
{
    if (BiTreeEmpty(T))
        return ERROR;
    else
    {
        *e = T[0];
        return OK;
    }
}

//@返回结点
//& 返回处于位置e(层,本层序号)的结点的值
TElemType Value(SqBiTree T, Position e)
{
    return T[(int)powl(2, e.level - 1) + e.order - 2];
}

//@二叉树赋值
Status Assign(SqBiTree T, Position e, TElemType value)
{
    int i = (int)powl(2, e.level - 1) + e.order - 2;
    //- 将层、本层序号转为矩阵的序号
    if (value != Nil && T[(i + 1) / 2 - 1] == Nil)
        //- 给叶子赋非空值但双亲为空
        return ERROR;
    else if (value == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil))
        //- 给双亲赋空值但有叶子（不空）
        return ERROR;
    T[i] = value;
    return OK;
}

//@返回双亲
TElemType Parent(SqBiTree T, TElemType e)
{
    int i;
    if (T[0] == Nil)
        return Nil;
    for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
        if (T[i] == e)
            return T[(i + 1) / 2 - 1];
    return Nil;
}

//@返回左孩子
TElemType LeftChild(SqBiTree T, TElemType e)
{
    int i;
    if (T[0] == Nil)
        return Nil;
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
        if (T[i] == e)
            return T[i * 2 + 1];
    return Nil;
}

//@返回右孩子
TElemType RightChild(SqBiTree T, TElemType e)
{
    int i;
    if (T[0] == Nil)
        return Nil;
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
        if (T[i] == e)
            return T[i * 2 + 2];
    return Nil;
}

///@返回左兄弟
TElemType LeftSibling(SqBiTree T, TElemType e)
{
    int i;
    if (T[0] == Nil)
        return Nil;
    for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
        if (T[i] == e && i % 2 == 0)
            return T[i - 1];
    return Nil;
}

//@返回右兄弟
TElemType RightSibling(SqBiTree T, TElemType e)
{
    int i;
    if (T[0] == Nil)
        return Nil;
    for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
        if (T[i] == e && i % 2)
            return T[i + 1];
    return Nil;
}

//@前序调用
//& PreOrderTraverse()调用
void PreTraverse(SqBiTree T, int e)
{
    visit(T[e]);
    if (T[2 * e + 1] != Nil)
        PreTraverse(T, 2 * e + 1);
    if (T[2 * e + 2] != Nil)
        PreTraverse(T, 2 * e + 2);
}

//@先序遍历
Status PreOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T))
        PreTraverse(T, 0);
    printf("\n");
    return OK;
}

//@ 中序调用
//& InOrderTraverse()调用 */
void InTraverse(SqBiTree T, int e)
{
    if (T[2 * e + 1] != Nil)
        InTraverse(T, 2 * e + 1);
    visit(T[e]);
    if (T[2 * e + 2] != Nil)
        InTraverse(T, 2 * e + 2);
}

//@中序遍历
Status InOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T))
        InTraverse(T, 0);
    printf("\n");
    return OK;
}

//@后序调用
//& PostOrderTraverse()调用
void PostTraverse(SqBiTree T, int e)
{
    if (T[2 * e + 1] != Nil)
        PostTraverse(T, 2 * e + 1);
    if (T[2 * e + 2] != Nil)
        PostTraverse(T, 2 * e + 2);
    visit(T[e]);
}

//@后序遍历
Status PostOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T))
        PostTraverse(T, 0);
    printf("\n");
    return OK;
}

//@ 层序遍历二叉树
void LevelOrderTraverse(SqBiTree T)
{
    int i = MAX_TREE_SIZE - 1, j;
    while (T[i] == Nil)
        i--; //& 找到最后一个非空结点的序号
    for (j = 0; j <= i; j++)
        if (T[j] != Nil)
            visit(T[j]);
    printf("\n");
}

//@输出二叉树
//& 逐层、按本层序号输出二叉树
void Print(SqBiTree T)
{
    int j, k;
    Position p;
    TElemType e;
    for (j = 1; j <= BiTreeDepth(T); j++)
    {
        printf("第%d层: ", j);
        for (k = 1; k <= powl(2, j - 1); k++)
        {
            p.level = j;
            p.order = k;
            e = Value(T, p);
            if (e != Nil)
                printf("%d:%d ", k, e);
        }
        printf("\n");
    }
}

int main()
{
    Status i;
    Position p;
    TElemType e;
    SqBiTree T;
    InitBiTree(T);
    CreateBiTree(T);
    printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));

    i = Root(T, &e);
    if (i)
        printf("二叉树的根为%d\n", e);
    else
        printf("树空，无根\n");
    printf("层序遍历二叉树:\n");
    LevelOrderTraverse(T);
    printf("前序遍历二叉树:\n");
    PreOrderTraverse(T);
    printf("中序遍历二叉树:\n");
    InOrderTraverse(T);
    printf("后序遍历二叉树:\n");
    PostOrderTraverse(T);

    printf("修改结点的层号3本层序号2。");
    p.level = 3;
    p.order = 2;
    e = Value(T, p);
    printf("待修改结点的原值为%d请输入新值:50 ", e);
    e = 50;
    Assign(T, p, e);
    printf("前序遍历二叉树:\n");
    PreOrderTraverse(T);
    printf("结点%d的双亲为%d,左右孩子分别为", e, Parent(T, e));
    printf("%d,%d,左右兄弟分别为", LeftChild(T, e), RightChild(T, e));
    printf("%d,%d\n", LeftSibling(T, e), RightSibling(T, e));

    ClearBiTree(T);
    printf("清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T, &e);
    if (i)
        printf("二叉树的根为%d\n", e);
    else
        printf("树空，无根\n");

    return 0;
}
