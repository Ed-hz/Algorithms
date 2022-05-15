// TODO 对于无向图 需要删除重复结点 用邻接多重表
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
    int ivex;
    int jvex;      //* 邻接点域
    EdgeType info; //* 用于存储权值
    struct EdgeNode *ilink;
    struct EdgeNode *jlink; //* 链域
} EdgeNode;

typedef struct VertexNode //& 顶点表结点
{
    VertexType data;     //* 顶点域
    EdgeNode *firstedge; //* 边表头指针
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
        G->adjList[i].firstedge = NULL; //* 将边表置为空表
    }

    for (k = 0; k < G->numEdges; k++) //& 建立边表
    {
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i; //* 邻接序号为i
        e->next = G->adjList[j].firstedge;
        //* 将e的next指向原本的表末元素
        G->adjList[j].firstedge = e; //* 将当前顶点的头指针指向e
    }
}

int main(void)
{
    GraphAdjList G;
    CreateALGraph(&G);

    return 0;
}
