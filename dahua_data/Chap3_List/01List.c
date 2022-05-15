//?��ȡʱ��O(1),�����ȡ�ṹ
//?ɾ�����O(1),�O(n),ƽ��O(n)
//- �ŵ� �ռ䲻�࣬���ٴ�ȡ
//- ȱ�� ����ɾ���� ����̶��洢�ռ����� �洢�ռ���Ƭ��

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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
typedef struct
{
    ElemType data[MAXSIZE]; //* ���飬�洢����Ԫ��
    int length;             //* ���Ա���
} SqList;

//@����Ԫ��
Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

//@��ʼ��
Status InitList(SqList *L)
{
    L->length = 0;
    return OK;
}

//@�Ƿ����
//& ��LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

//@����Ϊ�ձ�
Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

//@Ԫ�ظ���
int ListLength(SqList L)
{
    return L.length;
}

//@����Ԫ��
//& ����L�е�i������Ԫ�ص�ֵ,����e��
//& ��˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];

    return OK;
}

//@����λ��
//& �������ڣ��򷵻�ֵΪ0
int LocateElem(SqList L, ElemType e)
{
    int i;
    if (L.length == 0)
        return 0;

    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            break;
    }

    if (i >= L.length)
        return 0;

    return i + 1;
}

//@����
//& ��L�е�i��λ��ǰ����e��L�ĳ��ȼ�1//@��L�е�i��λ��ǰ����e��L�ĳ��ȼ�1
Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE) //* ˳�����Ա��Ѿ���
        return ERROR;
    if (i < 1 || i > L->length + 1)
        //* i�ȵ�һλС���߱����һλ��
        return ERROR;

    if (i <= L->length) //* ����������λ�ò��ڱ�β
    {
        for (k = L->length - 1; k >= i - 1; k--)
            //& ������λ��֮���Ԫ�غ���һλ
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;

    L->length++;
    return OK;
}

//@ɾ��
//& ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0) //* ���Ա�Ϊ��
        return ERROR;
    if (i < 1 || i > L->length) //* ɾ��λ�ò���ȷ
        return ERROR;

    *e = L->data[i - 1];
    if (i < L->length) //* ���ɾ���������λ��
    {
        for (k = i; k < L->length; k++) //& ��ɾ��λ�ú��Ԫ��ǰ��
            L->data[k - 1] = L->data[k];
    }

    L->length--;
    return OK;
}

//@���
//& ���ζ�L��ÿ������Ԫ�����
Status ListTraverse(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        visit(L.data[i]);
    printf("\n");
    return OK;
}

//@�ϲ�
//& �����е������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
void unionL(SqList *La, SqList Lb)
{
    int La_len, Lb_len, i;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb); //& �����Ա�ĳ���

    ElemType e; //& ������La��Lb��ͬ������Ԫ��e
    for (i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, &e);              //& ȡLb�е�i������Ԫ�ظ���e
        if (!LocateElem(*La, e))         //& La�в����ں�e��ͬ����Ԫ��
            ListInsert(La, ++La_len, e); //& ����
    }
}

int main()
{

    SqList L;
    SqList Lb;
    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);

    //@��ʼ��
    printf("��ʼ��L��:L.length=%d\n\n", L.length);
    //@����
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("����1��5��:\nL.data=");
    ListTraverse(L);
    printf("\n");
    //@����
    printf("L.length=%d \n\n", L.length);

    //@�Ƿ�Ϊ��
    i = ListEmpty(L);
    printf("L�Ƿ��:i=%d(1:�� 0:��)\n\n", i);
    //@���
    i = ClearList(&L);
    printf("���L��:L.length=%d\n", L.length);
    i = ListEmpty(L);
    printf("L�Ƿ��:i=%d(1:�� 0:��)\n\n", i);

    //@��β����
    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("��L�ı�β���β���1��10��:\nL.data=");
    ListTraverse(L);
    printf("L.length=%d \n\n", L.length);
    //@����һ��
    ListInsert(&L, 1, 0);
    printf("��L�ı�ͷ����0��:\nL.data=");
    ListTraverse(L);
    printf("L.length=%d \n\n", L.length);

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

    //@�ϲ�Ԫ��
    i = InitList(&Lb);
    for (j = 6; j <= 15; j++)
        i = ListInsert(&Lb, 1, j);
    unionL(&L, Lb);

    printf("��������ϲ���Lb��L��Ԫ��:");
    ListTraverse(L);

    return 0;
}
