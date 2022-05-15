//?�ؼ�·���㷨O(n+e) AOE
//?etv��ʾ������Կ�ʼ��ʱ�� ltv��ʾ������뿪ʼ��ʱ�� ��������ʾ�ǹؼ��
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
#define MAXEDGE 30
#define MAXVEX 30
#define GRAPH_INFINITY 65535
int *etv, *ltv; //* �¼����緢��ʱ�� ��ٷ���ʱ������
int *stack2;    //* �洢�������� ջ
int top2;       //* ����stack2��ָ��
//$ �ڽӾ���ṹ
typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

//$ �ڽӱ�ṹ
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

//$ ����ͼ
void CreateMGraph(MGraph *G)
{
    int i, j;
    // printf("����������Ͷ�����:");
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

//@ �ڽӾ��� -> �ڽӱ�
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
        (*GL)->adjList[i].firstedge = NULL; //* ��ʼ��
    }

    for (i = 0; i < G.numVertexes; i++) //& �����߱�
    {
        for (j = 0; j < G.numVertexes; j++)
        {
            if (G.arc[i][j] != 0 && G.arc[i][j] < GRAPH_INFINITY)
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;
                e->weight = G.arc[i][j];
                e->next = (*GL)->adjList[i].firstedge;
                //* ��e��nextָ��ԭ���ı�ĩԪ��
                (*GL)->adjList[i].firstedge = e;
                //* ����ǰ�����ͷָ��ָ��e
                (*GL)->adjList[j].in++;
            }
        }
    }
}

//@ ��������
//&��GL�޻�·������������������в�����1�����л�·����0
Status TopologicalSort(GraphAdjList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;   //* ջָ���±�
    int count = 0; //* �������ĸ���
    int *stack;    //* ���Ϊ0�Ķ��� ջ
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        if (0 == GL->adjList[i].in) //- ���Ϊ0�Ķ�����ջ
            stack[++top] = i;

    top2 = 0;
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    //! BUG ���Ѵ��з���while(top != 0)�����bug

    //* �¼����緢��ʱ������
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
        //* �������Ķ������ѹ���������е�ջ */

        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if (!(--GL->adjList[k].in))
                //- ��i�Ŷ�����ڽӵ����ȼ�1
                //-�����1��Ϊ0������ջ
                stack[++top] = k;

            if ((etv[gettop] + e->weight) > etv[k])
                //* ��������¼������緢��ʱ��etvֵ
                etv[k] = etv[gettop] + e->weight;
            //?��ν������� ����Ҫָ����֮ǰ���е������·���������Ѿ���� ����ʵ���������е���������е����ֵ
        }
    }
    printf("\n");

    if (count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}

//@ ��ؼ�·��
//& GLΪ�����������G�ĸ���ؼ�� */
void CriticalPath(GraphAdjList GL)
{
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;        //* ��������緢��ʱ�����ٷ���ʱ�����
    TopologicalSort(GL); //* ���������� ����etv stack2��ֵ
    printf("etv:");
    for (i = 0; i < GL->numVertexes; i++)
        printf("%d -> ", etv[i]);
    printf("\n");

    for (i = 0; i < GL->numVertexes; i++)
        ltv[i] = etv[GL->numVertexes - 1];
    //* �¼���ٷ���ʱ������

    while (top2 != 0) //& ��ջ ��ltv
    {
        gettop = stack2[top2--];
        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if (ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
        //?�������� ���ٴ���֮��������Ŀ��ʼ֮ǰ��������Ѿ���� ������ ԭ�� - ���򵽴˾�������ֵ
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
                //! ������ȼ��ڹؼ�·���� ��·���ϱ��밴��ʱ�����
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
