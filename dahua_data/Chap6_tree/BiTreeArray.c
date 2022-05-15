//? ˳�������
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
#define MAXSIZE 100       //& �洢�ռ��ʼ������
#define MAX_TREE_SIZE 100 //& ���������������
typedef int TElemType;    //* ElemType����,��Ϊint
typedef TElemType SqBiTree[MAX_TREE_SIZE];
//- 0�ŵ�Ԫ�洢�����

typedef struct
{
    int level, order; //* ���Ĳ�,�������(��������������)
} Position;

TElemType Nil = 0; //& ����ո��0

//@����Ԫ��
Status visit(TElemType c)
{
    printf("%d ", c);
    return OK;
}

//@��ʼ����
Status InitBiTree(SqBiTree T)
{
    int i;
    for (i = 0; i < MAX_TREE_SIZE; i++)
        T[i] = Nil;
    return OK;
}
#define ClearBiTree InitBiTree //* ��˳��洢�ṹ�У���������ȫһ��

//@������
Status CreateBiTree(SqBiTree T)
{
    int i = 0;
    printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�������������%d:\n", MAX_TREE_SIZE);

    while (i < 10)
    {
        T[i] = i + 1;

        if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
        //* �˽��(����)��˫���Ҳ��Ǹ�
        {
            printf("������˫�׵ķǸ����%d\n", T[i]);
            exit(ERROR);
        }
        i++;
    }
    while (i < MAX_TREE_SIZE)
    {
        T[i] = Nil; //* ���ո�ֵ��T�ĺ���Ľ��
        i++;
    }

    return OK;
}

//@�Ƿ�Ϊ��
Status BiTreeEmpty(SqBiTree T)
{
    if (T[0] == Nil)
        return TRUE;
    else
        return FALSE;
}

//@���������
int BiTreeDepth(SqBiTree T)
{
    int i, j = -1;
    for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
        if (T[i] != Nil)
            break;
    i++; //* �ҵ����һ�����T[i]

    do
        j++;
    while (i >= powl(2, j)); //* ��log(i)
    return j;
}

//@���ض������ĸ�
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

//@���ؽ��
//& ���ش���λ��e(��,�������)�Ľ���ֵ
TElemType Value(SqBiTree T, Position e)
{
    return T[(int)powl(2, e.level - 1) + e.order - 2];
}

//@��������ֵ
Status Assign(SqBiTree T, Position e, TElemType value)
{
    int i = (int)powl(2, e.level - 1) + e.order - 2;
    //- ���㡢�������תΪ��������
    if (value != Nil && T[(i + 1) / 2 - 1] == Nil)
        //- ��Ҷ�Ӹ��ǿ�ֵ��˫��Ϊ��
        return ERROR;
    else if (value == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil))
        //- ��˫�׸���ֵ����Ҷ�ӣ����գ�
        return ERROR;
    T[i] = value;
    return OK;
}

//@����˫��
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

//@��������
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

//@�����Һ���
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

///@�������ֵ�
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

//@�������ֵ�
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

//@ǰ�����
//& PreOrderTraverse()����
void PreTraverse(SqBiTree T, int e)
{
    visit(T[e]);
    if (T[2 * e + 1] != Nil)
        PreTraverse(T, 2 * e + 1);
    if (T[2 * e + 2] != Nil)
        PreTraverse(T, 2 * e + 2);
}

//@�������
Status PreOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T))
        PreTraverse(T, 0);
    printf("\n");
    return OK;
}

//@ �������
//& InOrderTraverse()���� */
void InTraverse(SqBiTree T, int e)
{
    if (T[2 * e + 1] != Nil)
        InTraverse(T, 2 * e + 1);
    visit(T[e]);
    if (T[2 * e + 2] != Nil)
        InTraverse(T, 2 * e + 2);
}

//@�������
Status InOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T))
        InTraverse(T, 0);
    printf("\n");
    return OK;
}

//@�������
//& PostOrderTraverse()����
void PostTraverse(SqBiTree T, int e)
{
    if (T[2 * e + 1] != Nil)
        PostTraverse(T, 2 * e + 1);
    if (T[2 * e + 2] != Nil)
        PostTraverse(T, 2 * e + 2);
    visit(T[e]);
}

//@�������
Status PostOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T))
        PostTraverse(T, 0);
    printf("\n");
    return OK;
}

//@ �������������
void LevelOrderTraverse(SqBiTree T)
{
    int i = MAX_TREE_SIZE - 1, j;
    while (T[i] == Nil)
        i--; //& �ҵ����һ���ǿս������
    for (j = 0; j <= i; j++)
        if (T[j] != Nil)
            visit(T[j]);
    printf("\n");
}

//@���������
//& ��㡢������������������
void Print(SqBiTree T)
{
    int j, k;
    Position p;
    TElemType e;
    for (j = 1; j <= BiTreeDepth(T); j++)
    {
        printf("��%d��: ", j);
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
    printf("������������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));

    i = Root(T, &e);
    if (i)
        printf("�������ĸ�Ϊ%d\n", e);
    else
        printf("���գ��޸�\n");
    printf("�������������:\n");
    LevelOrderTraverse(T);
    printf("ǰ�����������:\n");
    PreOrderTraverse(T);
    printf("�������������:\n");
    InOrderTraverse(T);
    printf("�������������:\n");
    PostOrderTraverse(T);

    printf("�޸Ľ��Ĳ��3�������2��");
    p.level = 3;
    p.order = 2;
    e = Value(T, p);
    printf("���޸Ľ���ԭֵΪ%d��������ֵ:50 ", e);
    e = 50;
    Assign(T, p, e);
    printf("ǰ�����������:\n");
    PreOrderTraverse(T);
    printf("���%d��˫��Ϊ%d,���Һ��ӷֱ�Ϊ", e, Parent(T, e));
    printf("%d,%d,�����ֱֵܷ�Ϊ", LeftChild(T, e), RightChild(T, e));
    printf("%d,%d\n", LeftSibling(T, e), RightSibling(T, e));

    ClearBiTree(T);
    printf("�����������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T, &e);
    if (i)
        printf("�������ĸ�Ϊ%d\n", e);
    else
        printf("���գ��޸�\n");

    return 0;
}
