// todo ʮ������ ʱ��Ҳ��O(n+e) ���ڽӾ�������ڽӾ�����
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
#define MAXVEX 100       //& ��󶥵���,Ӧ���û�����
typedef char VertexType; //* ��������Ӧ���û�����
typedef int EdgeType;    //* ���ϵ�Ȩֵ����Ӧ���û�����
typedef struct EdgeNode  //& �߱���
{
    int tailvex;               //* β����
    int headvex;               //* ͷ����
    EdgeType info;             //* ���ڴ洢Ȩֵ
    struct EdgeNode *headlink; //* ͷ����
    struct EdgeNode *taillink; //* β����
} EdgeNode;

typedef struct VertexNode //& �������
{
    VertexType data;    //* ������
    EdgeNode *firstin;  //* �߱���ָ��
    EdgeNode *firstout; //* �߱��ָ��
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numNodes, numEdges; //* ͼ�е�ǰ�������ͱ���
} GraphAdjList;

//@ ����ͼ���ڽӱ�ṹ
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("���붥�����ͱ���:\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges);
    for (i = 0; i < G->numNodes; i++) //* ���붥����Ϣ,���������
    {
        scanf("%d", &G->adjList[i].data);
        G->adjList[i].firstin = NULL;
        G->adjList[i].firstout = NULL; //* ���߱���Ϊ�ձ�
    }

    for (k = 0; k < G->numEdges; k++) //& �����߱�
    {
        printf("�����(vi,vj)�ϵĶ������:\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->headvex = j; //* ͷ���Ϊj
        e->headlink = G->adjList[i].firstin;
        //* ��e��headlinkָ��ԭ���ı�ĩԪ��
        G->adjList[i].firstin = e; //* ����ǰ�����ͷָ��ָ��e

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->tailvex = i; //* β���Ϊi
        e->taillink = G->adjList[j].firstout;
        //* ��e��taillinkָ��ԭ���ı�ĩԪ��
        G->adjList[j].firstout = e; //* ����ǰ�����ͷָ��ָ��e
    }
}

int main(void)
{
    GraphAdjList G;
    CreateALGraph(&G);

    return 0;
}
