//?���������� ��enum�����ָ��
//?�൱����һ��˫������
#include <ctype.h>
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
#define OVERFLOW 0
typedef int Status;

//@����
#define MAXSIZE 100    //& �洢�ռ��ʼ������
typedef int TElemType; //* ElemType����,��Ϊint
typedef enum           //&Tag
{
    Link,  //* Link=0 ָ�����Һ���ָ��
    Thread //* Thread=1 ָ��ǰ�����̵�����
} PointerTag;

typedef struct BiThrNode //& ���������洢���
{
    TElemType data;                    //* �������
    struct BiThrNode *lchild, *rchild; //* ���Һ���ָ��
    //* ���ұ�־
    PointerTag LTag; //?ltagΪ0ʱָ�����ӣ�Ϊ1ʱָ��ý���ǰ��
    PointerTag RTag; //?rtagΪ0ʱָ���Һ��ӣ�Ϊ1ʱָ��ý��ĺ��
} BiThrNode, *BiThrTree;

TElemType Nil = '#'; //& ����ո��

//@����Ԫ��
Status visit(TElemType e)
{
    printf("%c ", e);
    return OK;
}

//@������
//& ǰ����������������н���ֵ
//- 0(����)/�ո�(�ַ���)��ʾ�ս��
Status CreateBiThrTree(BiThrTree *T)
{
    TElemType h;
    scanf("%c", &h);

    if (h == Nil) //& �ս��
        *T = NULL;
    else
    {
        *T = (BiThrTree)malloc(sizeof(BiThrNode)); //- ��ʼ��
        if (!*T)
            exit(OVERFLOW);

        (*T)->data = h;                 //- ���ɸ����(ǰ��)
        CreateBiThrTree(&(*T)->lchild); //- �ݹ鹹��������
        if ((*T)->lchild)               //- ������
            (*T)->LTag = Link;
        CreateBiThrTree(&(*T)->rchild); //- �ݹ鹹��������
        if ((*T)->rchild)               //- ���Һ���
            (*T)->RTag = Link;
    }
    return OK;
}

BiThrTree pre; //@ ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ��

//@ �������
//& ��������������
void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild); //& �ݹ�������������
        if (!p->lchild)         //- pû������
        {
            p->LTag = Thread; //* ǰ������
            p->lchild = pre;  //* ����ָ��ָ��ǰ��
        }
        if (!pre->rchild) //- ǰ��û���Һ���
        {
            pre->RTag = Thread; //* �������
            pre->rchild = p;    //* ǰ���Һ���ָ��ָ����
        }
        pre = p;                //* ����
        InThreading(p->rchild); //& �ݹ�������������
    }
}

//@ �������������T
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode)); //& Thrtָ��ͷ���
    if (!*Thrt)
        exit(OVERFLOW);

    (*Thrt)->LTag = Link; //* ��ͷ���
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt); //* ��ָ���ָ
    if (!T)
        (*Thrt)->lchild = *Thrt; //* ����������,����ָ���ָ
    else
    {
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        InThreading(T); //* ���������������������

        pre->rchild = *Thrt;
        pre->RTag = Thread; //* ���һ�����������
        (*Thrt)->rchild = pre;
    }
    return OK;
}

//@ �����������������T - �ǵݹ��㷨
Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild; //* pָ������

    while (p != T)
    { //- �������������ʱ,p==T
        while (p->LTag == Link)
            p = p->lchild;
        if (!visit(p->data))
            return ERROR;

        while (p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
    return OK;
}

int main()
{
    BiThrTree H, T;
    printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
    CreateBiThrTree(&T);     //* ��ǰ�����������
    InOrderThreading(&H, T); //* �������,������������������
    printf("�������(���)����������:\n");
    InOrderTraverse_Thr(H); //* �������(���)����������
    printf("\n");

    return 0;
}
