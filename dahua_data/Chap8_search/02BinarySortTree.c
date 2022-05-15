//? 二叉搜索树
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
#define MAXSIZE 100    //& 存储空间初始分配量
typedef struct BiTNode //& 结点结构
{
    int data;                        //* 结点数据
    struct BiTNode *lchild, *rchild; //* 左右孩子指针
} BiTNode, *BiTree;

//@ 递归查找
//* f指向T的双亲 初始NULL
//* 若查找成功 p指向结点 并返回TRUE
//* 否则 p指向最后访问结点 返回FALSE
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T) //- 找不到
    {
        *p = f;
        return FALSE;
    }
    else if (key == T->data) //- 找到
    {
        *p = T;
        return TRUE;
    }
    else if (key < T->data) //-递归
        return SearchBST(T->lchild, key, T, p);
    else
        return SearchBST(T->rchild, key, T, p);
}

//@插入key
//*  当二叉排序树T中不存在关键字等于key的数据元素时
//*  插入key并返回TRUE，否则返回FALSE
Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if (!SearchBST(*T, key, NULL, &p))
    //- 查找不成功 树中无关键字相同的结点 插入结点
    //* 此时p已经是和最接近的元素
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL; //* 初始化结点

        if (!p)
            *T = s; //* 整棵树为空 插入s为新的根结点
        else if (key < p->data)
            p->lchild = s; //*  插入s为左孩子
        else
            p->rchild = s; //*  插入s为右孩子
        return TRUE;
    }
    else
        return FALSE; //-  树中已有关键字相同的结点，不再插入
}

//@删除结点
//& 从二叉排序树中删除结点p，并重接它的左或右子树
Status Delete(BiTree *p)
{
    BiTree q, s;
    if ((*p)->rchild == NULL) //- 右子树空 只需重接它的左子树
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if ((*p)->lchild == NULL) //- 左子树空 只需重接它的右子树
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else //* 左右子树均不空
    {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        //- 左树最右元素 即离被删除元素最近的元素取代它

        if (q != *p)               //- 此时运行到结点右儿子
            q->rchild = s->lchild; //*  重接q的右子树
        else                       //-此时运行到结点左儿子
            q->lchild = s->lchild; //*  重接q的左子树
        free(s);
    }
    return TRUE;
}

//@递归删除结点
//* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点
//* 并返回TRUE；否则返回FALSE
Status DeleteBST(BiTree *T, int key)
{
    if (!*T) //* 不存在关键字等于key的数据元素
        return FALSE;
    else
    {
        if (key == (*T)->data)
            return Delete(T);
        else if (key < (*T)->data)
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}

int main(void)
{
    int i;
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    BiTree T = NULL;

    for (i = 0; i < 10; i++)
    {
        InsertBST(&T, a[i]);
    }
    DeleteBST(&T, 93);
    DeleteBST(&T, 47);
    printf("本样例建议断点跟踪查看二叉排序树结构");
    return 0;
}
