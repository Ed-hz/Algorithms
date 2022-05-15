//? ƽ������� �����Ƕ��������� ���ܸ��ȶ�
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
typedef int Status;

//@����
#define MAXSIZE 100    //& �洢�ռ��ʼ������
typedef struct BiTNode //&  ���ṹ
{
    int data;                        //* �������
    int bf;                          //*  ����ƽ������
    struct BiTNode *lchild, *rchild; //* ���Һ���ָ��
} BiTNode, *BiTree;

//@��������
//& pΪ�� ����֮��Pָ���µ�������㣬����ת����֮ǰ���������ĸ����
void L_Rotate(BiTree *P)
{
    BiTree R;
    R = (*P)->rchild;
    (*P)->rchild = R->lchild; //*  P������������������ΪP��������
    R->lchild = (*P);
    *P = R; //*  P��������ȡ��P��Ϊ�����
}

//@��������
//& pΪ�� ����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ����
void R_Rotate(BiTree *P)
{
    BiTree L;
    L = (*P)->lchild;
    (*P)->lchild = L->rchild; //*  P������������������ΪP��������
    L->rchild = (*P);
    *P = L; //*  P��������ȡ��P��Ϊ�����
}

//? AVL����BFֻ�п�����������
#define LH +1 //-  ���
#define EH 0  //-  �ȸ�
#define RH -1 //-  �Ҹ�

//@��ƽ����ת
//& ���㷨����ʱ��ָ��Tָ���µĸ����
void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild; //*  Lָ��T�������������

    switch (L->bf) //&  ���T����������ƽ���
    {
    case LH: //-  T�����ӵ��������ϣ�����������
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:            //-  T�����ӵ��������� ˫������
        Lr = L->rchild; //*  Lrָ��T�����ӵ���������

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
        Lr->bf = EH; //&  �޸�T�������ӵ�ƽ������

        L_Rotate(&(*T)->lchild); //-  ��T��������������ƽ�⴦��
        R_Rotate(T);             //-  ��T������ƽ�⴦��
    }
}

//@��ƽ����ת
//& ���㷨����ʱ��ָ��Tָ���µĸ����
void RightBalance(BiTree *T)
{
    BiTree R, Rl;
    R = (*T)->rchild; //*  Lָ��T�������������
    switch (R->bf)    //&  ���T����������ƽ���
    {
    case RH: //-  T�����ӵ��������ϣ�����������
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    case LH:            //-  T���Һ��ӵ��������� ˫�������� */
        Rl = R->lchild; //*  Rlָ��T���Һ��ӵ���������
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
        Rl->bf = EH; //&  �޸�T�����Һ��ӵ�ƽ������

        R_Rotate(&(*T)->rchild); //-  ��T��������������ƽ�⴦��
        L_Rotate(T);             //-  ��T������ƽ�⴦��
    }
}

//@����e
//*  ������������T�в����ڹؼ��ֵ���e������Ԫ��ʱ
//*  ����e������TRUE�����򷵻�FALSE
//*  ʧȥƽ�⣬����ƽ����ת������������taller��ӳT�������
Status InsertAVL(BiTree *T, int e, Status *taller)
{
    if (!*T) //& �����׸����
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    {
        if (e == (*T)->data) //-  �����Ѵ���e ���ٲ���
        {
            *taller = FALSE;
            return FALSE;
        }
        if (e < (*T)->data) //-  ������T���������н�������
        {
            if (!InsertAVL(&(*T)->lchild, e, taller))
                return FALSE; //- ���Բ���������
            if (*taller)      //- �����������ߡ� ��Ҫ���ƽ���
                switch ((*T)->bf)
                {
                case LH: //*  ԭ������������������ ��Ҫ����ƽ�⴦��
                    LeftBalance(T);
                    *taller = FALSE;
                    break;
                case EH: //*  ԭ�����������ȸ� ���������� ������
                    (*T)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH: //*  ԭ������������������ �����������ȸ�
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }
        }
        else //-  ������T���������н�������
        {
            if (!InsertAVL(&(*T)->rchild, e, taller))
                return FALSE; //- ���Բ���������
            if (*taller)      //- �����������ߡ� ��Ҫ���ƽ���
                switch ((*T)->bf)
                {
                case LH: //*  ԭ������������������ �����������ȸ�
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH: //*  ԭ�����������ȸ� ���������� ������
                    (*T)->bf = RH;
                    *taller = TRUE;
                    break;
                case RH: //*  ԭ������������������ ��Ҫ����ƽ�⴦��
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
    printf("����������ϵ���ٲ鿴ƽ��������ṹ");
    return 0;
}