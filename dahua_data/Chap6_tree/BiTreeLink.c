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
#define MAXSIZE 100 //& �洢�ռ��ʼ������
int treeIndex = 1;
typedef char TElemType;  //* ElemType����,��Ϊint
typedef char String[24]; //- 0�ŵ�Ԫ��Ŵ��ĳ���
String str;              //& ��������

typedef struct BiTNode //& ���ṹ
{
    TElemType data;                  //* �������
    struct BiTNode *lchild, *rchild; //* ���Һ���ָ��
} BiTNode, *BiTree;

typedef char TElemType;
TElemType Nil = ' '; //& ����ո��

//@��ֵ��
Status StrAssign(String T, char *chars)
{
    int i;
    if (strlen(chars) > MAXSIZE) //* charsΪ��
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return OK;
    }
}

//@����Ԫ��
Status visit(TElemType e)
{
    printf("%c ", e);
    return OK;
}

//@ ����ն�����
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

//@���ٶ�����T
void DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild) //* ������
            DestroyBiTree(&(*T)->lchild);
        if ((*T)->rchild) //* ���Һ���
            DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL; //& ��ָ�븳0
    }
}

//@������
//* #��ʾ������������������ʾ������T
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
        (*T)->data = ch;             //* ���ɸ����
        CreateBiTree(&(*T)->lchild); //* ����������
        CreateBiTree(&(*T)->rchild); //* ����������
    }
}

//@�Ƿ�Ϊ��
Status BiTreeEmpty(BiTree T)
{
    if (T)
        return FALSE;
    else
        return TRUE;
}
#define ClearBiTree DestroyBiTree

//@���������
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

//@���ض������ĸ�
TElemType Root(BiTree T)
{
    if (BiTreeEmpty(T))
        return Nil;
    else
        return T->data;
}

//@���ض�����
//& �������: ����p��ָ����ֵ
TElemType Value(BiTree p)
{
    return p->data;
}

//@ ��㸳ֵ
void Assign(BiTree p, TElemType value)
{
    p->data = value;
}

//@ǰ��ݹ����
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//@����ݹ����
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

//@����ݹ����
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

    printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    e1 = Root(T);
    printf("�������ĸ�Ϊ: %c\n", e1);

    printf("\nǰ�����������:");
    PreOrderTraverse(T);
    printf("\n�������������:");
    InOrderTraverse(T);
    printf("\n�������������:");
    PostOrderTraverse(T);
    ClearBiTree(&T);
    printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T);
    if (!i)
        printf("���գ��޸�\n");

    return 0;
}
