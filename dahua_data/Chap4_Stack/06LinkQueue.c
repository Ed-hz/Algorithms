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
#define MAXSIZE 20     //& �洢�ռ��ʼ������
typedef int QElemType; //* ElemType����,��Ϊint
typedef struct QNode   //-QNodejieg
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct //- ���е�����
{
    QueuePtr front, rear;
} LinkQueue;

//@����Ԫ��
Status visit(QElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ ��ʼ��
Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

//@���ٶ���
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

//@����Ϊ�ն���
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

//@�Ƿ�Ϊ��
//& ������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
Status QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//@Ԫ�ظ���
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

//@���ض�ͷԪ��
//& �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status GetHead(LinkQueue Q, QElemType *e)
{
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    *e = p->data;
    return OK;
}

//@�����βԪ��
//& ����Ԫ��eΪ�µĶ�βԪ��
Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = NULL; //* �ı�ָ������

    Q->rear->next = s;
    Q->rear = s; //* �ı���б���
    return OK;
}

//@ɾ����ͷԪ��
//& �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
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

//@��ʾԪ��
//& �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�����
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
        printf("�ɹ��ع�����һ���ն���!\n");
    printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueEmpty(q));
    printf("���еĳ���Ϊ%d\n", QueueLength(q));
    EnQueue(&q, -5);
    EnQueue(&q, 5);
    EnQueue(&q, 10);
    printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", QueueLength(q));
    printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueEmpty(q));
    printf("���е�Ԫ������Ϊ:");
    QueueTraverse(q);
    i = GetHead(q, &d);
    if (i == OK)
        printf("��ͷԪ����:%d\n", d);
    DeQueue(&q, &d);
    printf("ɾ���˶�ͷԪ��%d\n", d);
    i = GetHead(q, &d);
    if (i == OK)
        printf("�µĶ�ͷԪ����:%d\n", d);
    ClearQueue(&q);
    printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
    DestroyQueue(&q);
    printf("���ٶ��к�,q.front=%u q.rear=%u\n", q.front, q.rear);

    return 0;
}
