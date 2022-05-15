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
#define OVERFLOW 0
typedef int Status;

//@定义
#define MAXSIZE 100 //& 存储空间初始分配量
int treeIndex = 1;
typedef char TElemType;  //* ElemType类型,设为int
typedef char String[24]; //- 0号单元存放串的长度
String str;              //& 输入序列

typedef struct BiTNode //& 结点结构
{
    TElemType data;                  //* 结点数据
    struct BiTNode *lchild, *rchild; //* 左右孩子指针
} BiTNode, *BiTree;

typedef char TElemType;
TElemType Nil = ' '; //& 定义空格符

//@赋值树
Status StrAssign(String T, char *chars)
{
    int i;
    if (strlen(chars) > MAXSIZE) //* chars为空
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return OK;
    }
}

//@访问元素
Status visit(TElemType e)
{
    printf("%c ", e);
    return OK;
}

//@ 构造空二叉树
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

//@销毁二叉树T
void DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild) //* 有左孩子
            DestroyBiTree(&(*T)->lchild);
        if ((*T)->rchild) //* 有右孩子
            DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL; //& 空指针赋0
    }
}

//@创建树
//* #表示空树，构造二叉链表表示二叉树T
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    /* scanf("%c",&ch); */
    ch = str[treeIndex++];

    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
            exit(OVERFLOW);
        (*T)->data = ch;             //* 生成根结点
        CreateBiTree(&(*T)->lchild); //* 构造左子树
        CreateBiTree(&(*T)->rchild); //* 构造右子树
    }
}

//@是否为空
Status BiTreeEmpty(BiTree T)
{
    if (T)
        return FALSE;
    else
        return TRUE;
}
#define ClearBiTree DestroyBiTree

//@二叉树深度
int BiTreeDepth(BiTree T)
{
    int i, j;
    if (!T)
        return 0;

    if (T->lchild)
        i = BiTreeDepth(T->lchild);
    else
        i = 0;

    if (T->rchild)
        j = BiTreeDepth(T->rchild);
    else
        j = 0;

    return i > j ? i + 1 : j + 1;
}

//@返回二叉树的根
TElemType Root(BiTree T)
{
    if (BiTreeEmpty(T))
        return Nil;
    else
        return T->data;
}

//@返回二叉树
//& 操作结果: 返回p所指结点的值
TElemType Value(BiTree p)
{
    return p->data;
}

//@ 结点赋值
void Assign(BiTree p, TElemType value)
{
    p->data = value;
}

//@前序递归遍历
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//@中序递归遍历
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

//@后序递归遍历
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

int main()
{
    int i;
    BiTree T;
    TElemType e1;
    InitBiTree(&T);

    StrAssign(str, "ABDH#K###E##CFI###G#J##");

    CreateBiTree(&T);

    printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    e1 = Root(T);
    printf("二叉树的根为: %c\n", e1);

    printf("\n前序遍历二叉树:");
    PreOrderTraverse(T);
    printf("\n中序遍历二叉树:");
    InOrderTraverse(T);
    printf("\n后序遍历二叉树:");
    PostOrderTraverse(T);
    ClearBiTree(&T);
    printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T);
    if (!i)
        printf("树空，无根\n");

    return 0;
}
