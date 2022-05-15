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
#define OVERFLOW 0
typedef int Status;

//@定义
#define MAXSIZE 20     //& 存储空间初始分配量
typedef int QElemType; //* ElemType类型,设为int
typedef struct QNode   //-QNodejieg
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct //- 队列的链表
{
    QueuePtr front, rear;
} LinkQueue;

//@访问元素
Status visit(QElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ 初始化
Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

//@销毁队列
Status DestroyQueue(LinkQueue *Q)
{
    while (Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

//@重置为空队列
Status ClearQueue(LinkQueue *Q)
{
    QueuePtr p, q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

//@是否为空
//& 若队列Q为空队列，则返回TRUE，否则返回FALSE
Status QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//@元素个数
int QueueLength(LinkQueue Q)
{
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while (Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//@返回队头元素
//& 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
Status GetHead(LinkQueue Q, QElemType *e)
{
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    *e = p->data;
    return OK;
}

//@插入队尾元素
//& 插入元素e为新的队尾元素
Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = NULL; //* 改变指针连接

    Q->rear->next = s;
    Q->rear = s; //* 改变队列本身
    return OK;
}

//@删除队头元素
//& 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
Status DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if (Q->front == Q->rear)
        return ERROR;

    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return OK;
}

//@显示元素
//& 从队头到队尾依次对队列Q中每个元素输出
Status QueueTraverse(LinkQueue Q)
{
    QueuePtr p;
    p = Q.front->next;
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
    int i;
    QElemType d;
    LinkQueue q;
    i = InitQueue(&q);
    if (i)
        printf("成功地构造了一个空队列!\n");
    printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));
    printf("队列的长度为%d\n", QueueLength(q));
    EnQueue(&q, -5);
    EnQueue(&q, 5);
    EnQueue(&q, 10);
    printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(q));
    printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));
    printf("队列的元素依次为:");
    QueueTraverse(q);
    i = GetHead(q, &d);
    if (i == OK)
        printf("队头元素是:%d\n", d);
    DeQueue(&q, &d);
    printf("删除了队头元素%d\n", d);
    i = GetHead(q, &d);
    if (i == OK)
        printf("新的队头元素是:%d\n", d);
    ClearQueue(&q);
    printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
    DestroyQueue(&q);
    printf("销毁队列后,q.front=%u q.rear=%u\n", q.front, q.rear);

    return 0;
}
