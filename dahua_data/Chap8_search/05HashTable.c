//? û�г�ͻ��O(1)
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
#define MAXSIZE 100 //& �洢�ռ��ʼ������
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 //& ����ɢ�б�Ϊ����ĳ���
#define NULLKEY -32768
typedef struct
{
    int *elem; //* ����Ԫ�ش洢��ַ����̬��������
    int count; //*  ��ǰ����Ԫ�ظ���
} HashTable;

int m = 0; //& ɢ�б����ȫ�ֱ���

//@ ��ʼ��ɢ�б�
Status InitHashTable(HashTable *H)
{
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return OK;
}

//@ ɢ�к���
int Hash(int key)
{
    return key % m; //* ���������� ģ�������������
}
//? ɢ�к������ǰ���Ϣ��������ֲ�������
//- ֱ�Ӷ�ַ��f(key)=a*key+b
//- ���ַ����� ��ȡ
//- ƽ��ȡ�з�
//- �۵���
//- ����������
//- �������

//@ ����ؼ���
void InsertHash(HashTable *H, int key)
{
    int addr = Hash(key);            //* ��ɢ�е�ַ
    while (H->elem[addr] != NULLKEY) //* �����Ϊ�գ����ͻ
    {
        addr = (addr + 1) % m; //& ���Ŷ�ַ�� �������̽�ⷨ
        //? Ϊ�˷�ֹ�ѻ������Զ���̽�ⷨ �����addr+1 -1 +1...
        //? ���̽�ⷨ addr��һ���̶�seed�������
    }
    H->elem[addr] = key; //* ֱ���п�λ�����ؼ���
}
//- ���Ŷ�ַ��
//- ��ɢ�з� ������ͻ�ͻ�һ��ɢ�к���
//- ����ַ�� ͬһ��λ�õ�Ԫ��������
//- ��������� ��ͻ��Ԫ�طŵ��������

//@ ɢ�б���ҹؼ���
Status SearchHash(HashTable H, int key, int *addr)
{
    *addr = Hash(key);           //* ��ɢ�е�ַ
    while (H.elem[*addr] != key) //* �����Ϊ�գ����ͻ
    {
        *addr = (*addr + 1) % m; //* ���Ŷ�ַ��������̽��
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
            //* ѭ���ص�ԭ�� ˵���ؼ��ֲ�����
            return UNSUCCESS;
    }
    return SUCCESS;
}

int main()
{
    int arr[HASHSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};
    int i, p, key, result;
    HashTable H;

    key = 39;

    InitHashTable(&H);
    for (i = 0; i < m; i++)
        InsertHash(&H, arr[i]);

    result = SearchHash(H, key, &p);
    if (result)
        printf("���� %d �ĵ�ַΪ:%d \n", key, p);
    else
        printf("���� %d ʧ�ܡ�\n", key);

    for (i = 0; i < m; i++)
    {
        key = arr[i];
        SearchHash(H, key, &p);
        printf("���� %d �ĵ�ַΪ:%d \n", key, p);
    }

    return 0;
}
