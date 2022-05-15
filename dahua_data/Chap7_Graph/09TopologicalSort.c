//? 拓扑排序 O(n+e) AOV
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
#define MAXEDGE 20
#define MAXVEX 14
//$ 邻接矩阵结构
typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

//$ 邻接表结构
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

//$ 构件图
void CreateMGraph(MGraph *G)
{
    int i, j;

    // printf("请输入边数和顶点数:");
    G->numEdges = MAXEDGE;
    G->numVertexes = MAXVEX;
    for (i = 0; i < G->numVertexes; i++)
    {
        G->vexs[i] = i;
    }
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][4] = 1;
    G->arc[0][5] = 1;
    G->arc[0][11] = 1;
    G->arc[1][2] = 1;
    G->arc[1][4] = 1;
    G->arc[1][8] = 1;
    G->arc[2][5] = 1;
    G->arc[2][6] = 1;
    G->arc[2][9] = 1;
    G->arc[3][2] = 1;
    G->arc[3][13] = 1;
    G->arc[4][7] = 1;
    G->arc[5][8] = 1;
    G->arc[5][12] = 1;
    G->arc[6][5] = 1;
    G->arc[8][7] = 1;
    G->arc[9][10] = 1;
    G->arc[9][11] = 1;
    G->arc[10][13] = 1;
    G->arc[12][9] = 1;
}

//@ 邻接矩阵 -> 邻接表
void CreateALGraph(MGraph G, GraphAdjList *GL)
{
    int i, j;
    EdgeNode *e;
    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));
    (*GL)->numVertexes = G.numVertexes;
    (*GL)->numEdges = G.numEdges;
    for (i = 0; i < G.numVertexes; i++)
    {
        (*GL)->adjList[i].in = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        (*GL)->adjList[i].firstedge = NULL; //* 初始化
    }

    for (i = 0; i < G.numVertexes; i++) //& 建立边表
    {
        for (j = 0; j < G.numVertexes; j++)
        {
            if (G.arc[i][j] == 1)
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;
                e->next = (*GL)->adjList[i].firstedge;
                //* 将e的next指向原本的表末元素
                (*GL)->adjList[i].firstedge = e;
                //* 将当前顶点的头指针指向e
                (*GL)->adjList[j].in++;
            }
        }
    }
}

//@ 拓扑排序
//&若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0
Status TopologicalSort(GraphAdjList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;   //* 栈指针下标
    int count = 0; //* 输出顶点的个数
    int *stack;    //* 入度为0的顶点 栈
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        if (0 == GL->adjList[i].in) //- 入度为0的顶点入栈
            stack[++top] = i;

    while (top != 0)
    {
        gettop = stack[top--];
        printf("%d -> ", GL->adjList[gettop].data);
        count++;

        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if (!(--GL->adjList[k].in))
                //- 将i号顶点的邻接点的入度减1
                //-如果减1后为0，则入栈
                stack[++top] = k;
        }
    }
    printf("\n");

    if (count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}

int main(void)
{
    MGraph G;
    GraphAdjList GL;
    int result;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);
    result = TopologicalSort(GL);
    printf("result:%d", result);

    return 0;
}