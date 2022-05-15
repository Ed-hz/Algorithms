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

//@ 循环队列的顺序存储结构
typedef struct
{
    int data[MAXSIZE];
    int front; //* 头指针
    int rear;  //* 尾指针，指向队列尾元素的下一个位置
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

Boolean visited[MAXVEX]; //! 访问标志的数组

//@深度优先递归算法DFS
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);
    for (j = 0; j < G.numVertexes; j++)
        if (G.arc[i][j] == 1 && !visited[j])
            DFS(G, j); //*递归调用
}

//$深度遍历DFS
void DFSTraverse(MGraph G)
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE; //* 初始化
    for (i = 0; i < G.numVertexes; i++)
        if (!visited[i]) //* 对未访问过的顶点调用DFS
            DFS(G, i);
}

//$广度遍历算法BFS
void BFSTraverse(MGraph G)
{
    int i, j;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q); //- 初始化辅助用的队列

    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i]) //* 对未访问过的顶点做循环
        {
            visited[i] = TRUE;
            printf("%c ", G.vexs[i]);
            EnQueue(&Q, i); //* 初始顶点入队列

            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &i); //*队内元素出队列，赋值给i
                for (j = 0; j < G.numVertexes; j++)
                { //& 与顶点若相邻未访问过点入队列

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
    printf("\n深度遍历:");
    DFSTraverse(G);
    printf("\n广度遍历:");
    BFSTraverse(G);
    return 0;
}
