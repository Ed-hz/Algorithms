//?关键路径算法O(n+e) AOE
//?etv表示最早可以开始的时间 ltv表示最晚必须开始的时间 若相等则表示是关键活动
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
#define MAXEDGE 30
#define MAXVEX 30
#define GRAPH_INFINITY 65535
int *etv, *ltv; //* 事件最早发生时间 最迟发生时间数组
int *stack2;    //* 存储拓扑序列 栈
int top2;       //* 用于stack2的指针
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
    G->numEdges = 13;
    G->numVertexes = 10;
    for (i = 0; i < G->numVertexes; i++)
    {
        G->vexs[i] = i;
    }
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            if (i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = GRAPH_INFINITY;
        }
    }

    G->arc[0][1] = 3;
    G->arc[0][2] = 4;
    G->arc[1][3] = 5;
    G->arc[1][4] = 6;
    G->arc[2][3] = 8;
    G->arc[2][5] = 7;
    G->arc[3][4] = 3;
    G->arc[4][6] = 9;
    G->arc[4][7] = 4;
    G->arc[5][7] = 6;
    G->arc[6][9] = 2;
    G->arc[7][8] = 5;
    G->arc[8][9] = 3;
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
            if (G.arc[i][j] != 0 && G.arc[i][j] < GRAPH_INFINITY)
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;
                e->weight = G.arc[i][j];
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

    top2 = 0;
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    //! BUG 若把此行放在while(top != 0)后则会bug

    //* 事件最早发生时间数组
    for (i = 0; i < GL->numVertexes; i++)
        etv[i] = 0;
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));

    printf("TopologicalSort:");
    while (top != 0)
    {
        gettop = stack[top--];
        printf("%d -> ", GL->adjList[gettop].data);
        count++;

        stack2[++top2] = gettop;
        //* 将弹出的顶点序号压入拓扑序列的栈 */

        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if (!(--GL->adjList[k].in))
                //- 将i号顶点的邻接点的入度减1
                //-如果减1后为0，则入栈
                stack[++top] = k;

            if ((etv[gettop] + e->weight) > etv[k])
                //* 求各顶点事件的最早发生时间etv值
                etv[k] = etv[gettop] + e->weight;
            //?所谓最早完成 至少要指此项之前所有到这个的路径都必须已经完成 所以实际上是所有到此项距离中的最大值
        }
    }
    printf("\n");

    if (count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}

//@ 求关键路径
//& GL为有向网，输出G的各项关键活动 */
void CriticalPath(GraphAdjList GL)
{
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;        //* 声明活动最早发生时间和最迟发生时间变量
    TopologicalSort(GL); //* 求拓扑序列 数组etv stack2的值
    printf("etv:");
    for (i = 0; i < GL->numVertexes; i++)
        printf("%d -> ", etv[i]);
    printf("\n");

    for (i = 0; i < GL->numVertexes; i++)
        ltv[i] = etv[GL->numVertexes - 1];
    //* 事件最迟发生时间数组

    while (top2 != 0) //& 出栈 求ltv
    {
        gettop = stack2[top2--];
        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if (ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
        //?而最迟完成 至少此项之后所有项目开始之前此项必须已经完成 所以是 原来 - 反向到此距离的最大值
    }

    printf("ltv:");
    for (i = 0; i < GL->numVertexes; i++)
        printf("%d -> ", ltv[i]);
    printf("\n");

    for (j = 0; j < GL->numVertexes; j++)
    {
        for (e = GL->adjList[j].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            ete = etv[j];
            lte = ltv[k] - e->weight;
            if (ete == lte)
                //! 两者相等即在关键路径上 此路径上必须按此时间完成
                printf("<v%d - v%d> length: %d \n", GL->adjList[j].data, GL->adjList[k].data, e->weight);
        }
    }
}

int main(void)
{
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);
    CriticalPath(GL);
    return 0;
}
