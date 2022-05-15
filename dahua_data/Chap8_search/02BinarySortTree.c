//? ����������
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
typedef struct BiTNode //& ���ṹ
{
    int data;                        //* �������
    struct BiTNode *lchild, *rchild; //* ���Һ���ָ��
} BiTNode, *BiTree;

//@ �ݹ����
//* fָ��T��˫�� ��ʼNULL
//* �����ҳɹ� pָ���� ������TRUE
//* ���� pָ�������ʽ�� ����FALSE
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T) //- �Ҳ���
    {
        *p = f;
        return FALSE;
    }
    else if (key == T->data) //- �ҵ�
    {
        *p = T;
        return TRUE;
    }
    else if (key < T->data) //-�ݹ�
        return SearchBST(T->lchild, key, T, p);
    else
        return SearchBST(T->rchild, key, T, p);
}

//@����key
//*  ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ
//*  ����key������TRUE�����򷵻�FALSE
Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if (!SearchBST(*T, key, NULL, &p))
    //- ���Ҳ��ɹ� �����޹ؼ�����ͬ�Ľ�� ������
    //* ��ʱp�Ѿ��Ǻ���ӽ���Ԫ��
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL; //* ��ʼ�����

        if (!p)
            *T = s; //* ������Ϊ�� ����sΪ�µĸ����
        else if (key < p->data)
            p->lchild = s; //*  ����sΪ����
        else
            p->rchild = s; //*  ����sΪ�Һ���
        return TRUE;
    }
    else
        return FALSE; //-  �������йؼ�����ͬ�Ľ�㣬���ٲ���
}

//@ɾ�����
//& �Ӷ�����������ɾ�����p�����ؽ��������������
Status Delete(BiTree *p)
{
    BiTree q, s;
    if ((*p)->rchild == NULL) //- �������� ֻ���ؽ�����������
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if ((*p)->lchild == NULL) //- �������� ֻ���ؽ�����������
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else //* ��������������
    {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        //- ��������Ԫ�� ���뱻ɾ��Ԫ�������Ԫ��ȡ����

        if (q != *p)               //- ��ʱ���е�����Ҷ���
            q->rchild = s->lchild; //*  �ؽ�q��������
        else                       //-��ʱ���е���������
            q->lchild = s->lchild; //*  �ؽ�q��������
        free(s);
    }
    return TRUE;
}

//@�ݹ�ɾ�����
//* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ��
//* ������TRUE�����򷵻�FALSE
Status DeleteBST(BiTree *T, int key)
{
    if (!*T) //* �����ڹؼ��ֵ���key������Ԫ��
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
    printf("����������ϵ���ٲ鿴�����������ṹ");
    return 0;
}
