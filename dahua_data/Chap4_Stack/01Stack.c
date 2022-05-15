//?存取时间O(1)
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//@状态
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

//@定义
#define MAXSIZE 20     //& 存储空间初始分配量
typedef int SElemType; //* ElemType类型,设为int
typedef struct
{
    SElemType data[MAXSIZE];
    int top; //?栈顶指针序号
} SqStack;

//@访问元素
Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ 初始化
Status InitStack(SqStack *S)
{
    //- S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType));
    S->top = -1;
    return OK;
}

//@是否为空
//& 若栈S为空栈，则返回TRUE，否则返回FALSE
Status StackEmpty(SqStack S)
{
    if (S.top == -1)
        return TRUE;
    else
        return FALSE;
}

//@重置为空栈
Status ClearStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

//@元素个数
int StackLength(SqStack S)
{
    return S.top + 1;
}

//@返回栈顶元素
//& 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top == -1)
        return ERROR;
    else
        *e = S.data[S.top];
    return OK;
}

//@插入栈顶元素
//& 插入元素e为新的栈顶元素
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1) //* 栈满
        return ERROR;
    S->top++;            //* 栈顶指针增加一
    S->data[S->top] = e; //* 将新插入元素赋值给栈顶空间
    return OK;
}

//@删除栈顶元素
//& 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top]; //* 将要删除的栈顶元素赋值给e
    S->top--;             //* 栈顶指针减一
    return OK;
}

//@显示元素
//& 从栈底到栈顶依次对栈中每个元素显示
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
    printf("栈中元素依次为:");
    StackTraverse(s);
    Pop(&s, &e);

    printf("弹出的栈顶元素 e=%d\n", e);
    printf("栈空否:%d(1:空 0:否)\n", StackEmpty(s));
    GetTop(s, &e);

    printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否:%d(1:空 0:否)\n", StackEmpty(s));

    return 0;
}
