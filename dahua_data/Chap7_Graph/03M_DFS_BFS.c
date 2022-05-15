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
#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9
typedef int Boolean;     //? ��������,��ֵ��TRUE��FALSE
typedef char VertexType; //* ��������Ӧ���û�����
typedef int EdgeType;    //* ���ϵ�Ȩֵ����Ӧ���û�����
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

//@ ѭ�����е�˳��洢�ṹ
typedef struct
{
    int data[MAXSIZE];
    int front; //* ͷָ��
    int rear;  //* βָ�룬ָ�����βԪ�ص���һ��λ��
} Queue;

//@ ��ʼ������
Status InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

//@�Ƿ�Ϊ��
Status QueueEmpty(Queue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//@�����βԪ��
Status EnQueue(Queue *Q, int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; //* rearָ�������һλ��
    return OK;
}

//@ɾ����ͷԪ��
//& �����в��գ���ɾ��S�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
Status DeQueue(Queue *Q, int *e)
{
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE; //- frontָ�������һλ��
    return OK;
}

//@��ʼ������ͼ
void CreateMGraph(MGraph *G)
{
    int i, j;

    G->numEdges = 15;
    G->numVertexes = 9;

    G->vexs[0] = 'A';
    G->vexs[1] = 'B';
    G->vexs[2] = 'C';
    G->vexs[3] = 'D';
    G->vexs[4] = 'E';
    G->vexs[5] = 'F';
    G->vexs[6] = 'G';
    G->vexs[7] = 'H';
    G->vexs[8] = 'I';

    for (i = 0; i < G->numVertexes; i++) //* ��ʼ��ͼ
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][1] = 1;
    G->arc[0][5] = 1;

    G->arc[1][2] = 1;
    G->arc[1][8] = 1;
    G->arc[1][6] = 1;

    G->arc[2][3] = 1;
    G->arc[2][8] = 1;

    G->arc[3][4] = 1;
    G->arc[3][7] = 1;
    G->arc[3][6] = 1;
    G->arc[3][8] = 1;

    G->arc[4][5] = 1;
    G->arc[4][7] = 1;

    G->arc[5][6] = 1;

    G->arc[6][7] = 1;

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

Boolean visited[MAXVEX]; //! ���ʱ�־������

//@������ȵݹ��㷨DFS
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);
    for (j = 0; j < G.numVertexes; j++)
        if (G.arc[i][j] == 1 && !visited[j])
            DFS(G, j); //*�ݹ����
}

//$��ȱ���DFS
void DFSTraverse(MGraph G)
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE; //* ��ʼ��
    for (i = 0; i < G.numVertexes; i++)
        if (!visited[i]) //* ��δ���ʹ��Ķ������DFS
            DFS(G, i);
}

//$��ȱ����㷨BFS
void BFSTraverse(MGraph G)
{
    int i, j;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q); //- ��ʼ�������õĶ���

    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i]) //* ��δ���ʹ��Ķ�����ѭ��
        {
            visited[i] = TRUE;
            printf("%c ", G.vexs[i]);
            EnQueue(&Q, i); //* ��ʼ���������

            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &i); //*����Ԫ�س����У���ֵ��i
                for (j = 0; j < G.numVertexes; j++)
                { //& �붥��������δ���ʹ��������

                    if (G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j] = TRUE;
                        printf("%c ", G.vexs[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}

int main(void)
{
    MGraph G;
    CreateMGraph(&G);
    printf("\n��ȱ���:");
    DFSTraverse(G);
    printf("\n��ȱ���:");
    BFSTraverse(G);
    return 0;
}
