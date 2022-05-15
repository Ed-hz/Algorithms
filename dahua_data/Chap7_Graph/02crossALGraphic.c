// todo 十字链表 时间也是O(n+e) 把邻接矩阵和逆邻接矩阵结合
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
#define MAXVEX 100       //& 最大顶点数,应由用户定义
typedef char VertexType; //* 顶点类型应由用户定义
typedef int EdgeType;    //* 边上的权值类型应由用户定义
typedef struct EdgeNode  //& 边表结点
{
    int tailvex;               //* 尾点域
    int headvex;               //* 头点域
    EdgeType info;             //* 用于存储权值
    struct EdgeNode *headlink; //* 头链域
    struct EdgeNode *taillink; //* 尾链域
} EdgeNode;

typedef struct VertexNode //& 顶点表结点
{
    VertexType data;    //* 顶点域
    EdgeNode *firstin;  //* 边表入指针
    EdgeNode *firstout; //* 边表出指针
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numNodes, numEdges; //* 图中当前顶点数和边数
} GraphAdjList;

//@ 建立图的邻接表结构
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges);
    for (i = 0; i < G->numNodes; i++) //* 读入顶点信息,建立顶点表
    {
        scanf("%d", &G->adjList[i].data);
        G->adjList[i].firstin = NULL;
        G->adjList[i].firstout = NULL; //* 将边表置为空表
    }

    for (k = 0; k < G->numEdges; k++) //& 建立边表
    {
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->headvex = j; //* 头序号为j
        e->headlink = G->adjList[i].firstin;
        //* 将e的headlink指向原本的表末元素
        G->adjList[i].firstin = e; //* 将当前顶点的头指针指向e

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->tailvex = i; //* 尾序号为i
        e->taillink = G->adjList[j].firstout;
        //* 将e的taillink指向原本的表末元素
        G->adjList[j].firstout = e; //* 将当前顶点的头指针指向e
    }
}

int main(void)
{
    GraphAdjList G;
    CreateALGraph(&G);

    return 0;
}
