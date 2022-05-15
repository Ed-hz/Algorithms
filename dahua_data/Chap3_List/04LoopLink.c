//-βָ�뷽��ϲ�

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
typedef int Status; //* Status�Ǻ������״̬����,��OK��

//@����
#define MAXSIZE 20    //& �洢�ռ��ʼ������
typedef int ElemType; //* ElemType����,��Ϊint
typedef struct Node
{
    ElemType data;     //?������
    struct Node *next; //?ָ����
    //& ֱ����һԪ��ָ��
} Node, *LoopList; //& ����LoopList

//@����Ԫ��
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ ��ʼ��
Status InitList(LoopList *L)
{
    *L = (LoopList)malloc(sizeof(Node));
    //& ����β���,��ʹLָ���ͷ���

    if (!(*L)) //* �洢����ʧ��
        return ERROR;
    (*L)->next = *L; //& ָ����Ϊ�Լ�

    return OK;
}

//@�Ƿ����
//& ��LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
Status ListEmpty(LoopList L)
{
    if (L->next != L)
        return FALSE;
    else
        return TRUE;
}

//@����Ϊ�ձ�
Status ClearList(LoopList *L)
{
    LoopList p, q;
    p = (*L)->next->next; //& pָ���һ�����
    *L = (*L)->next;

    while (p != *L) //* û����ͷ
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = *L; //& β���ָ����Ϊ�Լ�
    return OK;
}

//@Ԫ�ظ���
int ListLength(LoopList L)
{
    int i = 0;
    LoopList p = L->next->next; //& pָ���һ�����

    while (p != L->next)
    {
        i++;
        p = p->next;
    }
    return i;
}

//@����Ԫ��
//& ����L�е�i������Ԫ�ص�ֵ,����e��
//& ��˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
Status GetElem(LoopList L, int i, ElemType *e)
{
    int j;
    LoopList p;
    p = L->next->next; //& pָ���һ�����
    j = 1;

    while (p != L->next && j < i) //* p��Ϊ�գ�������j��iʱ��ѭ������
    {
        p = p->next; //& ��pָ����һ�����
        ++j;
    }

    if (p == L->next || j > i) //* ��i��Ԫ�ز�����
        return ERROR;

    *e = p->data; //& ȡ��i��Ԫ�ص�����
    return OK;
}

//@����λ��
//& �������ڣ��򷵻�ֵΪ0
int LocateElem(LoopList L, ElemType e)
{
    int i = 0;
    LoopList p = L->next->next;

    while (p != L->next)
    {
        i++;
        if (p->data == e)
            return i;
        p = p->next;
    }

    return 0;
}

//@����
//& ��L�е�i��λ��ǰ����e��L�ĳ��ȼ�1
Status ListInsert(LoopList *L, int i, ElemType e)
{
    int j;
    LoopList p, s;
    p = (*L)->next;
    j = 1;

    while (p != *L && j < i) //* Ѱ�ҵ�i�����
    {
        p = p->next;
        ++j;
    }
    if (p == *L && j == i)
    {
        s = (LoopList)malloc(sizeof(Node));
        *L = s;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return OK;
    }

    if (p == *L || j > i) //* ��i��Ԫ�ز�����
        return ERROR;

    s = (LoopList)malloc(sizeof(Node)); //& �����½��
    s->data = e;
    s->next = p->next; //& ��p�ĺ�̽�㸳ֵ��s�ĺ��
    p->next = s;       //& ��s��ֵ��p�ĺ��
    return OK;
}

//@ɾ��
//& ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ� 1
Status ListDelete(LoopList *L, int i, ElemType *e)
{
    int j;
    LoopList p, q;
    p = (*L)->next;
    j = 1;

    while ((p->next) != *L && j < i) //* ����Ѱ�ҵ�i��Ԫ��
    {
        p = p->next;
        ++j;
    }
    if ((p->next) == *L && j == i)
    {
        q = p->next;
        p->next = q->next;
        *e = q->data;
        free(q);
        *L = p;
        return OK;
    }

    if ((p->next) == *L || j > i)
        return ERROR;

    q = p->next;
    p->next = q->next; //& ��q�ĺ�̸�ֵ��p�ĺ��
    *e = q->data;      //& ��q����е����ݸ�e
    free(q);           //& ��ϵͳ���մ˽�㣬�ͷ��ڴ�
    return OK;
}

//@���
//& ���ζ�L��ÿ������Ԫ�����
Status ListTraverse(LoopList L)
{
    LoopList p = L->next->next;

    while (p != L->next)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

//@�ϲ�
//& �����е������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
void unionL(LoopList *La, LoopList *Lb)
{
    Node *Lc = (*La)->next;
    (*La)->next = (*Lb)->next->next;
    (*Lb)->next = Lc;
    *La = *Lb;
}

int main()
{
    LoopList L, M;
    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);

    //@��ʼ��
    printf("��ʼ��L��:ListLength(L)=%d\n\n", ListLength(L));
    //@����
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("����1��5��:\nL.data=");
    ListTraverse(L);
    printf("\n");
    //@����
    printf("ListLength(L)=%d \n\n", ListLength(L));

    //@�Ƿ�Ϊ��
    i = ListEmpty(L);
    printf("L�Ƿ��:i=%d(1:�� 0:��)\n\n", i);
    //@���
    i = ClearList(&L);
    printf("���L��:ListLength(L)=%d\n", ListLength(L));
    i = ListEmpty(L);
    printf("L�Ƿ��:i=%d(1:�� 0:��)\n\n", i);

    //@����
    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("��L�ı�β���β���1��10��:\nL.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n\n", ListLength(L));
    //@����һ��
    ListInsert(&L, 1, 0);
    printf("��L�ı�ͷ����0��:\nL.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n\n", ListLength(L));

    //@ȡ��Ԫ��
    GetElem(L, 5, &e);
    printf("��5��Ԫ�ص�ֵΪ:%d\n", e);
    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j);
        if (k)
            printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
        else
            printf("û��ֵΪ%d��Ԫ��\n", j);
    }
    printf("\n");

    //@ɾ��Ԫ��
    k = ListLength(L); //& kΪ��
    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(&L, j, &e); //& ɾ����j������
        if (i == ERROR)
            printf("ɾ����%d������ʧ��\n", j);
        else
            printf("ɾ����%d����Ԫ��ֵΪ:%d\n", j, e);
    }
    printf("�������L��Ԫ��:");
    ListTraverse(L);
    printf("\n");
    //@ɾ��һ��
    j = 5;
    ListDelete(&L, j, &e); //& ɾ����5������
    printf("ɾ����%d����Ԫ��ֵΪ:%d\n", j, e);

    printf("�������L��Ԫ��:");
    ListTraverse(L);
    printf("\n");
    //@�ϲ�
    InitList(&M);
    for (j = 1; j <= 10; j++)
        ListInsert(&M, j, 10 - j);
    unionL(&L, &M);
    printf("�������L��Ԫ��:");
    ListTraverse(L);
    printf("\n");

    return 0;
}
