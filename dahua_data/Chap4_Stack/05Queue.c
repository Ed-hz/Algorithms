//* ѭ������
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
typedef int QElemType; //* ElemType����,��Ϊint
typedef struct
{
    QElemType data[MAXSIZE];
    int front; //? ͷָ��λ��
    int rear;  //? βָ��λ�ã�βԪ�ص���һ��λ��
} SqQueue;

//@����Ԫ��
Status visit(QElemType c)
{
    printf("%d ", c);
    return OK;
}

//@ ��ʼ��
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

//@�Ƿ�Ϊ��
Status QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//@����Ϊ��ջ
Status ClearQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
    return OK;
}

//@Ԫ�ظ���
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
    // $ ������ѭ�����У�rear������frontǰ������ô˷���
}

//@����ջ��Ԫ��
//& �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status GetHead(SqQueue Q, QElemType *e)
{
    if (Q.front == Q.rear)
        return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

//@�����βԪ��
//& ����Ԫ��eΪ�µĶ�βԪ��
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; //- rearָ�������һλ��
    return OK;
}

//@ɾ����ͷԪ��
//& �����в��գ���ɾ��S�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE; //- frontָ�������һλ��
    return OK;
}

//@��ʾԪ��
//& �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�����
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
    printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));

    printf("���������Ͷ���Ԫ��(������%d��),-1Ϊ��ǰ������: ", MAXSIZE - 1);
    do
    {
        /* scanf("%d",&d); */
        d = i + 100;
        if (d == -1)
            break;
        i++;
        EnQueue(&Q, d);
    } while (i < MAXSIZE - 1);

    printf("���г���Ϊ: %d\n", QueueLength(Q));
    printf("���ڶ��пշ�%u(1:�� 0:��)\n\n", QueueEmpty(Q));
    printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n", MAXSIZE);
    for (l = 1; l <= MAXSIZE; l++)
    {
        DeQueue(&Q, &d);
        printf("ɾ����Ԫ����%d,�����Ԫ��:%d ,", d, l + 1000);
        /* scanf("%d",&d); */
        d = l + 1000;
        EnQueue(&Q, d);

        printf("���ڶ����е�Ԫ��Ϊ: \n");
        QueueTraverse(Q);
    }
    l = QueueLength(Q);

    printf("\n�����β������%d��Ԫ��\n", i + MAXSIZE);
    if (l - 2 > 0)
        printf("�����ɶ�ͷɾ��%d��Ԫ��:\n", l - 2);
    while (QueueLength(Q) > 2)
    {
        DeQueue(&Q, &d);
        printf("ɾ����Ԫ��ֵΪ%d\n", d);
    }

    j = GetHead(Q, &d);
    if (j)
        printf("���ڶ�ͷԪ��Ϊ: %d\n", d);
    ClearQueue(&Q);
    printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));
    return 0;
}
