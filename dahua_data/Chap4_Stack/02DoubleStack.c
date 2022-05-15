//-两栈共享空间，一般在两栈一个变长一个缩短时使用
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
    int top1; //?栈1顶指针序号
    int top2; //?栈2顶指针序号
} SqDoubleStack;
//- 两个栈，一个底为-1，另一个底为MAXSIZE

//@访问元素
Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ 初始化
Status InitStack(SqDoubleStack *S)
{
    S->top1 = -1;      //* 栈 1栈顶到栈1底
    S->top2 = MAXSIZE; //* 栈 1栈顶为栈2底
    return OK;
}

//@重置为空栈
Status ClearStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

//@是否为空
//& 若栈S为空栈，则返回TRUE，否则返回FALSE
Status StackEmpty(SqDoubleStack S)
{
    if (S.top1 == -1 && S.top2 == MAXSIZE)
        return TRUE;
    else
        return FALSE;
}

//@元素个数
int StackLength(SqDoubleStack S)
{
    return (S.top1 + 1) + (MAXSIZE - S.top2);
}

//@插入栈顶元素
//& 插入元素e为新的栈顶元素
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2) //* 栈已满
        return ERROR;
    if (stackNumber == 1)       //* 栈1有元素进栈
        S->data[++S->top1] = e; //* 若是栈1则先top1+1后给数组元素赋值
    else if (stackNumber == 2)  //* 栈2有元素进栈
        S->data[--S->top2] = e; //* 若是栈2则先top2-1后给数组元素赋值
    return OK;
}

//@删除栈顶元素
//& 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (S->top1 == -1)
            return ERROR;        //* 溢出
        *e = S->data[S->top1--]; //* 将栈1的栈顶元素出栈
    }
    else if (stackNumber == 2)
    {
        if (S->top2 == MAXSIZE)
            return ERROR;        //* 溢出
        *e = S->data[S->top2++]; //* 将栈2的栈顶元素出栈
    }
    return OK;
}

//@显示元素
//& 从栈底到栈顶依次对栈中每个元素显示
Status StackTraverse(SqDoubleStack S)
{
    int i;
    i = 0;
    while (i <= S.top1)
    {
        visit(S.data[i++]);
    }
    i = S.top2;
    while (i < MAXSIZE)
    {
        visit(S.data[i++]);
    }
    printf("\n");
    return OK;
}

int main()
{
    int j;
    SqDoubleStack s;
    int e;
    if (InitStack(&s) == OK)
    {
        for (j = 1; j <= 5; j++)
            Push(&s, j, 1);
        for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
            Push(&s, j, 2);
    }

    printf("栈中元素依次为:");
    StackTraverse(s);

    printf("当前栈中元素有:%d \n", StackLength(s));

    Pop(&s, &e, 2);
    printf("弹出的栈顶元素 e=%d\n", e);
    printf("栈空否:%d(1:空 0:否)\n", StackEmpty(s));

    for (j = 6; j <= MAXSIZE - 2; j++)
        Push(&s, j, 1);

    printf("栈中元素依次为:");
    StackTraverse(s);

    printf("栈满否:%d(1:否 0:满)\n", Push(&s, 100, 1));

    ClearStack(&s);
    printf("清空栈后，栈空否:%d(1:空 0:否)\n", StackEmpty(s));

    return 0;
}