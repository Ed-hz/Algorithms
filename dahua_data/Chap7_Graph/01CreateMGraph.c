//?邻接矩阵时间O(n^2+n+e)
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
#define MAXVEX 100           //& 最大顶点数,应由用户定义
#define GRAPH_INFINITY 65535 //? 用65535来代表∞
typedef char VertexType;     //* 顶点类型应由用户定义
typedef int EdgeType;        //* 边上的权值类型应由用户定义
typedef struct
{
    VertexType vexs[MAXVEX];      //* 顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //* 邻接矩阵,可看作边表
    int numNodes, numEdges;       //* 图中当前的顶点数和边数
} MGraph;

//@ 建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges); //* 输入顶点数和边数
    for (i = 0; i < G->numNodes; i++)           //& 读入顶点,建立顶点表
        scanf("%d", &G->vexs[i]);

    for (i = 0; i < G->numNodes; i++)
        for (j = 0; j < G->numNodes; j++)
            G->arc[i][j] = GRAPH_INFINITY; //* 邻接矩阵初始化
    for (k = 0; k < G->numEdges; k++)
    //& 读入numEdges条边,建立邻接矩阵 */
    {
        printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
        scanf("%d,%d,%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

int main(void)
{
    MGraph G;
    CreateMGraph(&G);

    return 0;
}
