#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//@״̬
//?��ȡʱ��O(1)
//-�ڴ��˷��٣��������ڴ濪��
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

//@����
#define MAXSIZE 20     //& �洢�ռ��ʼ������
typedef int SElemType; //* ElemType����,��Ϊint
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct
{
    LinkStackPtr top; //?ջ��ָ��
    int count;        //?ջԪ����
} LinkStack;

//@����Ԫ��
Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ ��ʼ��
Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!S->top)
        return ERROR;
    S->top = NULL;
    S->count = 0;
    return OK;
}

//@����Ϊ��ջ
Status ClearStack(LinkStack *S)
{
    LinkStackPtr p, q;
    p = S->top;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

//@�Ƿ�Ϊ��
//& ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
Status StackEmpty(LinkStack S)
{
    if (S.count == 0)
        return TRUE;
    else
        return FALSE;
}

//@Ԫ�ظ���
int StackLength(LinkStack S)
{
    return S.count;
}

//@����ջ��Ԫ��
//& ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
Status GetTop(LinkStack S, SElemType *e)
{
    if (S.top == NULL)
        return ERROR;
    else
        *e = S.top->data;
    return OK;
}

//@����ջ��Ԫ��
//& ����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr newtop = (LinkStackPtr)malloc(sizeof(StackNode));
    newtop->data = e;
    newtop->next = S->top; //* �ı�ָ������

    S->top = newtop;
    S->count++; //* �ı�ջ����
    return OK;
}

//@ɾ��ջ��Ԫ��
//& ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if (StackEmpty(*S))
        return ERROR;

    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}

//@��ʾԪ��
//& ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ
Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p = S.top;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    int j;
    LinkStack s;
    int e;
    if (InitStack(&s) == OK)
        for (j = 1; j <= 10; j++)
            Push(&s, j);
    printf("ջ��Ԫ������Ϊ:");
    StackTraverse(s);

    Pop(&s, &e);
    printf("������ջ��Ԫ�� e=%d\n", e);
    printf("ջ�շ�:%d(1:�� 0:��)\n", StackEmpty(s));

    GetTop(s, &e);
    printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));

    ClearStack(&s);
    printf("���ջ��ջ�շ�:%d(1:�� 0:��)\n", StackEmpty(s));
    return 0;
}