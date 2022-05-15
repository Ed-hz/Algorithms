//?��ȡʱ��O(1)
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
#define MAXSIZE 20     //& �洢�ռ��ʼ������
typedef int SElemType; //* ElemType����,��Ϊint
typedef struct
{
    SElemType data[MAXSIZE];
    int top; //?ջ��ָ�����
} SqStack;

//@����Ԫ��
Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ ��ʼ��
Status InitStack(SqStack *S)
{
    //- S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType));
    S->top = -1;
    return OK;
}

//@�Ƿ�Ϊ��
//& ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
Status StackEmpty(SqStack S)
{
    if (S.top == -1)
        return TRUE;
    else
        return FALSE;
}

//@����Ϊ��ջ
Status ClearStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

//@Ԫ�ظ���
int StackLength(SqStack S)
{
    return S.top + 1;
}

//@����ջ��Ԫ��
//& ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top == -1)
        return ERROR;
    else
        *e = S.data[S.top];
    return OK;
}

//@����ջ��Ԫ��
//& ����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1) //* ջ��
        return ERROR;
    S->top++;            //* ջ��ָ������һ
    S->data[S->top] = e; //* ���²���Ԫ�ظ�ֵ��ջ���ռ�
    return OK;
}

//@ɾ��ջ��Ԫ��
//& ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top]; //* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e
    S->top--;             //* ջ��ָ���һ
    return OK;
}

//@��ʾԪ��
//& ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ
Status StackTraverse(SqStack S)
{
    int i;
    i = 0;
    while (i <= S.top)
    {
        visit(S.data[i++]);
    }
    printf("\n");
    return OK;
}

int main()
{
    int j;
    SqStack s;
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
