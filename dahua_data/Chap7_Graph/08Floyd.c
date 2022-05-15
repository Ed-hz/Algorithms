//?求所有顶点到 其他所有顶点 或某一顶点 最短距离的复杂度为O(n^3)

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
#define MAXVEX 20
#define GRAPH_INFINITY 65535
typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

typedef int Patharc[MAXVEX][MAXVEX];
//* 存储最短路径下标的矩阵
typedef int ShortPathTable[MAXVEX][MAXVEX];
//* 存储到各点最短路径的权值和

//$ 构件图
void CreateMGraph(MGraph *G)
{
    int i, j;

    // printf("请输入边数和顶点数:");
    G->numEdges = 16;
    G->numVertexes = 9;

    for (i = 0; i < G->numVertexes; i++) //* 初始化点
    {
        G->vexs[i] = i;
    }

    for (i = 0; i < G->numVertexes; i++) //* 初始化距离
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            if (i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
        }
    }

    G->arc[0][1] = 1;
    G->arc[0][2] = 5;
    G->arc[1][2] = 3;
    G->arc[1][3] = 7;
    G->arc[1][4] = 5;

    G->arc[2][4] = 1;
    G->arc[2][5] = 7;
    G->arc[3][4] = 2;
    G->arc[3][6] = 3;
    G->arc[4][5] = 3;

    G->arc[4][6] = 6;
    G->arc[4][7] = 9;
    G->arc[5][7] = 5;
    G->arc[6][7] = 2;
    G->arc[6][8] = 7;

    G->arc[7][8] = 4;

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

//@  Dijkstra算法
//& 求有向网G的v0顶点到  v的最短路径P[v]及带权长度D[v]
//* P[v]的值为前驱顶点下标  D[v]表示v0到v的最短路径长度和
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{
    int v, w, k;
    for (v = 0; v < G.numVertexes; ++v) //* 初始化D与P
    {
        for (w = 0; w < G.numVertexes; ++w)
        {
            (*D)[v][w] = G.arc[v][w];
            (*P)[v][w] = w; //* P里是w->v第一个经过的下标
        }
    }

    for (k = 0; k < G.numVertexes; ++k)
    {
        for (v = 0; v < G.numVertexes; ++v)
        {
            for (w = 0; w < G.numVertexes; ++w)
            {
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
                {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }
}

int main(void)
{
    int v, w, k;
    MGraph G;
    Patharc P;
    ShortPathTable D;

    CreateMGraph(&G);
    ShortestPath_Floyd(G, &P, &D);

    printf("各顶点间最短路径如下:\n");
    for (v = 0; v < G.numVertexes; ++v)
    {
        for (w = v + 1; w < G.numVertexes; w++)
        {
            printf("v%d-v%d weight: %d ", v, w, D[v][w]);
            k = P[v][w]; //* 第一个路径顶点下标
            printf(" path: %d", v);

            while (k != w)
            {
                printf(" -> %d", k);
                k = P[k][w]; //* 获得下一个路径顶点下标
            }
            printf(" -> %d\n", w); //* 打印终点
        }
        printf("\n");
    }

    printf("最短路径D\n");
    for (v = 0; v < G.numVertexes; ++v)
    {
        for (w = 0; w < G.numVertexes; ++w)
        {
            printf("%4d", D[v][w]);
        }
        printf("\n");
    }

    printf("最短路径P\n");
    for (v = 0; v < G.numVertexes; ++v)
    {
        for (w = 0; w < G.numVertexes; ++w)
        {
            printf("%d ", P[v][w]);
        }
        printf("\n");
    }

    return 0;
}
