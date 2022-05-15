//? 平衡二叉树 首先是二叉排序树 性能更稳定
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
typedef struct BiTNode //&  结点结构
{
    int data;                        //* 结点数据
    int bf;                          //*  结点的平衡因子
    struct BiTNode *lchild, *rchild; //* 左右孩子指针
} BiTNode, *BiTree;

//@左旋处理
//& p为根 处理之后P指向新的树根结点，即旋转处理之前的右子树的根结点
void L_Rotate(BiTree *P)
{
    BiTree R;
    R = (*P)->rchild;
    (*P)->rchild = R->lchild; //*  P的右子树的左子树成为P的右子树
    R->lchild = (*P);
    *P = R; //*  P的右子树取代P成为根结点
}

//@右旋处理
//& p为根 处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点
void R_Rotate(BiTree *P)
{
    BiTree L;
    L = (*P)->lchild;
    (*P)->lchild = L->rchild; //*  P的左子树的右子树成为P的左子树
    L->rchild = (*P);
    *P = L; //*  P的左子树取代P成为根结点
}

//? AVL树的BF只有可能是这三个
#define LH +1 //-  左高
#define EH 0  //-  等高
#define RH -1 //-  右高

//@左平衡旋转
//& 本算法结束时，指针T指向新的根结点
void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild; //*  L指向T的左子树根结点

    switch (L->bf) //&  检查T的左子树的平衡度
    {
    case LH: //-  T的左孩子的左子树上，单右旋处理
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:            //-  T的左孩子的右子树上 双旋处理
        Lr = L->rchild; //*  Lr指向T的左孩子的右子树根

        switch (Lr->bf)
        {
        case LH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case EH:
            (*T)->bf = L->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            L->bf = LH;
            break;
        }            // HACK
        Lr->bf = EH; //&  修改T及其左孩子的平衡因子

        L_Rotate(&(*T)->lchild); //-  对T的左子树作左旋平衡处理
        R_Rotate(T);             //-  对T作右旋平衡处理
    }
}

//@右平衡旋转
//& 本算法结束时，指针T指向新的根结点
void RightBalance(BiTree *T)
{
    BiTree R, Rl;
    R = (*T)->rchild; //*  L指向T的右子树根结点
    switch (R->bf)    //&  检查T的右子树的平衡度
    {
    case RH: //-  T的左孩子的右子树上，单左旋处理
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    case LH:            //-  T的右孩子的左子树上 双旋处理理 */
        Rl = R->lchild; //*  Rl指向T的右孩子的左子树根
        switch (Rl->bf)
        {
        case RH:
            (*T)->bf = LH;
            R->bf = EH;
            break;
        case EH:
            (*T)->bf = R->bf = EH;
            break;
        case LH:
            (*T)->bf = EH;
            R->bf = RH;
            break;
        }
        Rl->bf = EH; //&  修改T及其右孩子的平衡因子

        R_Rotate(&(*T)->rchild); //-  对T的右子树作左旋平衡处理
        L_Rotate(T);             //-  对T作左旋平衡处理
    }
}

//@插入e
//*  当二叉排序树T中不存在关键字等于e的数据元素时
//*  插入e并返回TRUE，否则返回FALSE
//*  失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否
Status InsertAVL(BiTree *T, int e, Status *taller)
{
    if (!*T) //& 插入首个结点
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    {
        if (e == (*T)->data) //-  树中已存在e 不再插入
        {
            *taller = FALSE;
            return FALSE;
        }
        if (e < (*T)->data) //-  继续在T的左子树中进行搜索
        {
            if (!InsertAVL(&(*T)->lchild, e, taller))
                return FALSE; //- 尝试插入左子树
            if (*taller)      //- 左子树“长高” 需要检查平衡度
                switch ((*T)->bf)
                {
                case LH: //*  原本左子树比右子树高 需要作左平衡处理
                    LeftBalance(T);
                    *taller = FALSE;
                    break;
                case EH: //*  原本左、右子树等高 左子树增高 树增高
                    (*T)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH: //*  原本右子树比左子树高 现左、右子树等高
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }
        }
        else //-  继续在T的右子树中进行搜索
        {
            if (!InsertAVL(&(*T)->rchild, e, taller))
                return FALSE; //- 尝试插入右子树
            if (*taller)      //- 右子树“长高” 需要检查平衡度
                switch ((*T)->bf)
                {
                case LH: //*  原本左子树比右子树高 现左、右子树等高
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH: //*  原本左、右子树等高 右子树增高 树增高
                    (*T)->bf = RH;
                    *taller = TRUE;
                    break;
                case RH: //*  原本右子树比左子树高 需要作右平衡处理
                    RightBalance(T);
                    *taller = FALSE;
                    break;
                }
        }
    }
    return TRUE;
}

int main(void)
{
    int i;
    int a[10] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    BiTree T = NULL;
    Status taller;
    for (i = 0; i < 10; i++)
    {
        InsertAVL(&T, a[i], &taller);
    }
    printf("本样例建议断点跟踪查看平衡二叉树结构");
    return 0;
}