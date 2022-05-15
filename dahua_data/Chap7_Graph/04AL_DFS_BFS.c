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

//@ �ڽӱ�ṹ
typedef struct EdgeNode //& �߱���
{
    int adjvex;            //* �ڽӵ���
    int weight;            //* Ȩֵ
    struct EdgeNode *next; //* ����
} EdgeNode;

typedef struct VertexNode //& �������
{
    int in;              //* �������
    char data;           //* ������
    EdgeNode *firstedge; //* �߱�ͷָ��
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; //* �������ͱ���
} graphAdjList, *GraphAdjList;

//@ ѭ�����е�˳��洢�ṹ
typedef struct
{
    int data[MAXSIZE];
    int front; //* ͷָ��
    int rear;  //* βָ��
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

//@ ����ͼ���ڽӱ�ṹ
void CreateALGraph(MGraph G, GraphAdjList *GL)
{
    int i, j;
    EdgeNode *e;

    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));

    (*GL)->numVertexes = G.numVertexes;
    (*GL)->numEdges = G.numEdges;
    for (i = 0; i < G.numVertexes; i++) //* ���붥����Ϣ,���������
    {
        (*GL)->adjList[i].in = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        (*GL)->adjList[i].firstedge = NULL; //* ���߱���Ϊ�ձ�
    }

    for (i = 0; i < G.numVertexes; i++) //& �����߱�
    {
        for (j = G.numVertexes - 1; j >= 0; j--)
        {
            if (G.arc[i][j] == 1)
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));

                if (i == 1 && j == 8)
                    e->adjvex = 6;
                else if (i == 1 && j == 6)
                    e->adjvex = 8;
                else
                    /*����5��������ֻ��Ϊ����ͼ���е�206ҳͼƥ�䣬�����ɵĶ��з�������ͼʾ,ʵ�ʹ�������������ֻ����⵱ǰ���ǹ���һ��ͼ�ṹ���ڽӱ���*/
                    e->adjvex = j; //* �ڽ����Ϊj

                e->next = (*GL)->adjList[i].firstedge;
                //* ��e��nextָ��ԭ���ı�ĩԪ��
                (*GL)->adjList[i].firstedge = e;
                //* ����ǰ�����ͷָ��ָ��e

                (*GL)->adjList[j].in++;
            }
        }
    }
}

Boolean visited[MAXSIZE]; //! ���ʱ�־������

//@������ȵݹ��㷨DFS
void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ", GL->adjList[i].data);

    p = GL->adjList[i].firstedge;
    while (p)
    {
        if (!visited[p->adjvex])
            DFS(GL, p->adjvex); //*�ݹ����
        p = p->next;
    }
}

//$��ȱ���DFS
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE; //* ��ʼ��
    for (i = 0; i < GL->numVertexes; i++)
        if (!visited[i]) //* ��δ���ʹ��Ķ������DFS
            DFS(GL, i);
}

//$��ȱ����㷨BFS
void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q); //- ��ʼ�������õĶ���

    for (i = 0; i < GL->numVertexes; i++)
    {
        if (!visited[i]) //* ��δ���ʹ��Ķ�����ѭ��
        {
            visited[i] = TRUE;
            printf("%c ", GL->adjList[i].data);
            EnQueue(&Q, i); //* ��ʼ���������

            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &i); //*����Ԫ�س����У���ֵ��i
                p = GL->adjList[i].firstedge;
                while (p)
                {
                    if (!visited[p->adjvex])
                    { //& �붥��������δ���ʹ��������
                        visited[p->adjvex] = TRUE;
                        printf("%c ", GL->adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

int main(void)
{
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);

    printf("\n��ȱ���:");
    DFSTraverse(GL);
    printf("\n��ȱ���:");
    BFSTraverse(GL);
    return 0;
}
