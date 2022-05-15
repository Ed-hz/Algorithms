//* 循环队列
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
typedef int QElemType; //* ElemType类型,设为int
typedef struct
{
    QElemType data[MAXSIZE];
    int front; //? 头指针位置
    int rear;  //? 尾指针位置，尾元素的下一个位置
} SqQueue;

//@访问元素
Status visit(QElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ 初始化
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

//@是否为空
Status QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//@重置为空栈
Status ClearQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
    return OK;
}

//@元素个数
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
    // $ 由于是循环队列，rear可能在front前，因此用此方法
}

//@返回栈顶元素
//& 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
Status GetHead(SqQueue Q, QElemType *e)
{
    if (Q.front == Q.rear)
        return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

//@插入队尾元素
//& 插入元素e为新的队尾元素
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; //- rear指针向后移一位置
    return OK;
}

//@删除队头元素
//& 若队列不空，则删除S的队头元素，用e返回其值，并返回OK；否则返回ERROR
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE; //- front指针向后移一位置
    return OK;
}

//@显示元素
//& 从队头到队尾依次对队列Q中每个元素输出
Status QueueTraverse(SqQueue Q)
{
    int i;
    i = Q.front;
    while (i != Q.rear)
    {
        visit(Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}

int main()
{
    Status j;
    int i = 0, l;
    QElemType d;
    SqQueue Q;
    InitQueue(&Q);
    printf("初始化队列后，队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));

    printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ", MAXSIZE - 1);
    do
    {
        /* scanf("%d",&d); */
        d = i + 100;
        if (d == -1)
            break;
        i++;
        EnQueue(&Q, d);
    } while (i < MAXSIZE - 1);

    printf("队列长度为: %d\n", QueueLength(Q));
    printf("现在队列空否？%u(1:空 0:否)\n\n", QueueEmpty(Q));
    printf("连续%d次由队头删除元素,队尾插入元素:\n", MAXSIZE);
    for (l = 1; l <= MAXSIZE; l++)
    {
        DeQueue(&Q, &d);
        printf("删除的元素是%d,插入的元素:%d ,", d, l + 1000);
        /* scanf("%d",&d); */
        d = l + 1000;
        EnQueue(&Q, d);

        printf("现在队列中的元素为: \n");
        QueueTraverse(Q);
    }
    l = QueueLength(Q);

    printf("\n共向队尾插入了%d个元素\n", i + MAXSIZE);
    if (l - 2 > 0)
        printf("现在由队头删除%d个元素:\n", l - 2);
    while (QueueLength(Q) > 2)
    {
        DeQueue(&Q, &d);
        printf("删除的元素值为%d\n", d);
    }

    j = GetHead(Q, &d);
    if (j)
        printf("现在队头元素为: %d\n", d);
    ClearQueue(&Q);
    printf("清空队列后, 队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
    return 0;
}
