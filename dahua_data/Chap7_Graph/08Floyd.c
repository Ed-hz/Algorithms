//?�����ж��㵽 �������ж��� ��ĳһ���� ��̾���ĸ��Ӷ�ΪO(n^3)

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
//* �洢���·���±�ľ���
typedef int ShortPathTable[MAXVEX][MAXVEX];
//* �洢���������·����Ȩֵ��

//$ ����ͼ
void CreateMGraph(MGraph *G)
{
    int i, j;

    // printf("����������Ͷ�����:");
    G->numEdges = 16;
    G->numVertexes = 9;

    for (i = 0; i < G->numVertexes; i++) //* ��ʼ����
    {
        G->vexs[i] = i;
    }

    for (i = 0; i < G->numVertexes; i++) //* ��ʼ������
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

//@  Dijkstra�㷨
//& ��������G��v0���㵽  v�����·��P[v]����Ȩ����D[v]
//* P[v]��ֵΪǰ�������±�  D[v]��ʾv0��v�����·�����Ⱥ�
void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{
    int v, w, k;
    for (v = 0; v < G.numVertexes; ++v) //* ��ʼ��D��P
    {
        for (w = 0; w < G.numVertexes; ++w)
        {
            (*D)[v][w] = G.arc[v][w];
            (*P)[v][w] = w; //* P����w->v��һ���������±�
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

    printf("����������·������:\n");
    for (v = 0; v < G.numVertexes; ++v)
    {
        for (w = v + 1; w < G.numVertexes; w++)
        {
            printf("v%d-v%d weight: %d ", v, w, D[v][w]);
            k = P[v][w]; //* ��һ��·�������±�
            printf(" path: %d", v);

            while (k != w)
            {
                printf(" -> %d", k);
                k = P[k][w]; //* �����һ��·�������±�
            }
            printf(" -> %d\n", w); //* ��ӡ�յ�
        }
        printf("\n");
    }

    printf("���·��D\n");
    for (v = 0; v < G.numVertexes; ++v)
    {
        for (w = 0; w < G.numVertexes; ++w)
        {
            printf("%4d", D[v][w]);
        }
        printf("\n");
    }

    printf("���·��P\n");
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
