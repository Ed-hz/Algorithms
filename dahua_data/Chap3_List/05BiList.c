//-ͷ�ڵ����ͷָ�룬�ڵ�һԪ��ǰ�������������壬���Ǳ�ҪԪ��
//-ͷָ��ָ���һ��Ԫ�أ����������Ƿ�ն����ڣ���ʱΪnull
//?��ȡʱ�����O(1),�O(n)
//?ɾ������һϵ�� ��һ��O(n),���漸��O(1)
//- �ŵ� ����Ԥ�ȷ����ڴ�
//- ȱ��

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
    ElemType data;         //?������
    struct Node *next;     //& ֱ����һԪ��ָ��
    struct Node *previous; // & ֱ����һԪ��ָ��
} Node;
typedef struct Node *BiList; //& ����BiList

//@����Ԫ��
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ ��ʼ��
Status InitList(BiList *L)
{
    *L = (BiList)malloc(sizeof(Node));
    //& ����ͷ���,��ʹLָ���ͷ���

    if (!(*L)) //* �洢����ʧ��
        return ERROR;
    (*L)->next = NULL; //& ָ����Ϊ��

    return OK;
}

//@�Ƿ����
//& ��LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
Status ListEmpty(BiList L)
{
    if (L->next)
        return FALSE;
    else
        return TRUE;
}

//@����Ϊ�ձ�
Status ClearList(BiList *L)
{
    BiList p, q;
    p = (*L)->next; //& pָ���һ�����

    while (p) //* û����β
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL; //& ͷ���ָ����Ϊ��
    return OK;
}

//@Ԫ�ظ���
int ListLength(BiList L)
{
    int i = 0;
    BiList p = L->next; //& pָ���һ�����

    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//@����Ԫ��
//& ����L�е�i������Ԫ�ص�ֵ,����e��

//& ��˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
Status GetElem(BiList L, int i, ElemType *e)
{
    int j;
    BiList p;
    p = L->next; //& pָ���һ�����
    j = 1;

    while (p && j < i) //* p��Ϊ�գ�������j��iʱ��ѭ������
    {
        p = p->next; //& ��pָ����һ�����
        ++j;
    }

    if (!p || j > i) //* ��i��Ԫ�ز�����
        return ERROR;

    *e = p->data; //& ȡ��i��Ԫ�ص�����
    return OK;
}

//@����λ��
//& �������ڣ��򷵻�ֵΪ0
int LocateElem(BiList L, ElemType e)
{
    int i = 0;
    BiList p = L->next;

    while (p)
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
Status ListInsert(BiList *L, int i, ElemType e)
{
    int j;
    BiList p, q, s;
    p = *L;
    j = 1;

    while (p && j < i) //* Ѱ�ҵ�i�����
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i) //* ��i��Ԫ�ز�����
        return ERROR;

    s = (BiList)malloc(sizeof(Node)); //& �����½��
    s->data = e;
    q = p->next;
    s->next = q;
    s->previous = p;
    p->next = s;
    if (q)
        q->previous = s;
    return OK;
}

//@ɾ��
//& ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
Status ListDelete(BiList *L, int i, ElemType *e)
{
    int j;
    BiList p, q, r;
    p = *L;
    j = 1;

    while (p->next && j < i) //* ����Ѱ�ҵ�i��Ԫ��
    {
        p = p->next;
        ++j;
    }

    if (!(p->next) || j > i) //* ��i��Ԫ�ز�����
        return ERROR;

    q = p->next;
    r = q->next;
    p->next = r; //& ��q�ĺ�̸�ֵ��p�ĺ��
    if (r)
        r->previous = p;
    *e = q->data; //& ��q����е����ݸ�e
    free(q);      //& ��ϵͳ���մ˽�㣬�ͷ��ڴ�
    return OK;
}

//@���
//& ���ζ�L��ÿ������Ԫ�����
Status ListTraverse(BiList L)
{
    BiList p = L->next;

    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

//@ͷ�巨
//& �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
void CreateListHead(BiList *L, int n)
{
    BiList p;
    int i;

    srand(time(0)); //& ��ʼ�����������
    *L = (BiList)malloc(sizeof(Node));
    (*L)->next = NULL; //& �Ƚ���һ����ͷ���ĵ�����

    for (i = 0; i < n; i++)
    {
        p = (BiList)malloc(sizeof(Node)); //& �����½��
        p->data = rand() % 100 + 1;       //& �������100���ڵ�����
        p->next = (*L)->next;
        (*L)->next = p; //& ���뵽��ͷ
    }
}

//@β�巨
//& �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
void CreateListTail(BiList *L, int n)
{
    BiList p, r;
    int i;

    srand(time(0));                    //& ��ʼ�����������
    *L = (BiList)malloc(sizeof(Node)); //& LΪ�������Ա�
    r = *L;                            //? rΪָ��β���Ľ��

    for (i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node)); //& �����½��
        p->data = rand() % 100 + 1;       //& �������100���ڵ�����
        r->next = p;
        //& ����β�ն˽���ָ��ָ���½��
        r = p;
        //& ����ǰ���½�㶨��Ϊ��β�ն˽��
    }
    r->next = NULL; //& ��ʾ��ǰ�������
}

int main()
{
    BiList L;
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

    //@ͷ�巨
    i = ClearList(&L);
    printf("\n���L��:ListLength(L)=%d\n", ListLength(L));
    CreateListHead(&L, 20);
    printf("���崴��L��Ԫ��(ͷ�巨):");
    ListTraverse(L);
    //@β�巨
    i = ClearList(&L);
    printf("\nɾ��L��:ListLength(L)=%d\n", ListLength(L));
    CreateListTail(&L, 20);
    printf("���崴��L��Ԫ��(β�巨):");
    ListTraverse(L);

    return 0;
}
