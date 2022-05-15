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
#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9
typedef int Boolean;     //? 布尔类型,其值是TRUE或FALSE
typedef char VertexType; //* 顶点类型应由用户定义
typedef int EdgeType;    //* 边上的权值类型应由用户定义
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

//@ 邻接表结构
typedef struct EdgeNode //& 边表结点
{
    int adjvex;            //* 邻接点域
    int weight;            //* 权值
    struct EdgeNode *next; //* 链域
} EdgeNode;

typedef struct VertexNode //& 顶点表结点
{
    int in;              //* 顶点入度
    char data;           //* 顶点域
    EdgeNode *firstedge; //* 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; //* 顶点数和边数
} graphAdjList, *GraphAdjList;

//@ 循环队列的顺序存储结构
typedef struct
{
    int data[MAXSIZE];
    int front; //* 头指针
    int rear;  //* 尾指针
} Queue;

//@ 初始化队列
Status InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

//@是否为空
Status QueueEmpty(Queue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//@插入队尾元素
Status EnQueue(Queue *Q, int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; //* rear指针向后移一位置
    return OK;
}

//@删除队头元素
//& 若队列不空，则删除S的队头元素，用e返回其值，并返回OK；否则返回ERROR
Status DeQueue(Queue *Q, int *e)
{
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE; //- front指针向后移一位置
    return OK;
}

//@初始化测试图
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

    for (i = 0; i < G->numVertexes; i++) //* 初始化图
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

//@ 建立图的邻接表结构
void CreateALGraph(MGraph G, GraphAdjList *GL)
{
    int i, j;
    EdgeNode *e;

    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));

    (*GL)->numVertexes = G.numVertexes;
    (*GL)->numEdges = G.numEdges;
    for (i = 0; i < G.numVertexes; i++) //* 读入顶点信息,建立顶点表
    {
        (*GL)->adjList[i].in = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        (*GL)->adjList[i].firstedge = NULL; //* 将边表置为空表
    }

    for (i = 0; i < G.numVertexes; i++) //& 建立边表
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
                    /*上面5句代码仅仅只是为了与图书中的206页图匹配，让生成的队列符合书中图示,实际构建无需这样，只需理解当前就是构建一个图结构的邻接表即可*/
                    e->adjvex = j; //* 邻接序号为j

                e->next = (*GL)->adjList[i].firstedge;
                //* 将e的next指向原本的表末元素
                (*GL)->adjList[i].firstedge = e;
                //* 将当前顶点的头指针指向e

                (*GL)->adjList[j].in++;
            }
        }
    }
}

Boolean visited[MAXSIZE]; //! 访问标志的数组

//@深度优先递归算法DFS
void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ", GL->adjList[i].data);

    p = GL->adjList[i].firstedge;
    while (p)
    {
        if (!visited[p->adjvex])
            DFS(GL, p->adjvex); //*递归调用
        p = p->next;
    }
}

//$深度遍历DFS
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE; //* 初始化
    for (i = 0; i < GL->numVertexes; i++)
        if (!visited[i]) //* 对未访问过的顶点调用DFS
            DFS(GL, i);
}

//$广度遍历算法BFS
void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q); //- 初始化辅助用的队列

    for (i = 0; i < GL->numVertexes; i++)
    {
        if (!visited[i]) //* 对未访问过的顶点做循环
        {
            visited[i] = TRUE;
            printf("%c ", GL->adjList[i].data);
            EnQueue(&Q, i); //* 初始顶点入队列

            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &i); //*队内元素出队列，赋值给i
                p = GL->adjList[i].firstedge;
                while (p)
                {
                    if (!visited[p->adjvex])
                    { //& 与顶点若相邻未访问过点入队列
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

    printf("\n深度遍历:");
    DFSTraverse(GL);
    printf("\n广度遍历:");
    BFSTraverse(GL);
    return 0;
}
