// TODO ��������ͼ ��Ҫɾ���ظ���� ���ڽӶ��ر�
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
    int ivex;
    int jvex;      //* �ڽӵ���
    EdgeType info; //* ���ڴ洢Ȩֵ
    struct EdgeNode *ilink;
    struct EdgeNode *jlink; //* ����
} EdgeNode;

typedef struct VertexNode //& �������
{
    VertexType data;     //* ������
    EdgeNode *firstedge; //* �߱�ͷָ��
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
        G->adjList[i].firstedge = NULL; //* ���߱���Ϊ�ձ�
    }

    for (k = 0; k < G->numEdges; k++) //& �����߱�
    {
        printf("�����(vi,vj)�ϵĶ������:\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i; //* �ڽ����Ϊi
        e->next = G->adjList[j].firstedge;
        //* ��e��nextָ��ԭ���ı�ĩԪ��
        G->adjList[j].firstedge = e; //* ����ǰ�����ͷָ��ָ��e
    }
}

int main(void)
{
    GraphAdjList G;
    CreateALGraph(&G);

    return 0;
}
