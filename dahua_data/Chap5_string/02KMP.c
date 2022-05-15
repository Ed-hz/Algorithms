//? ����ƥ�临�Ӷ�O((n-m+1)*m),mΪƥ�䳤�ȣ�nΪ��ƥ�䳤��
//? KMP���Ӷ�O(n+m)
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
#define MAXSIZE 100               //& �洢�ռ��ʼ������
typedef int ElemType;             //* ElemType����,��Ϊint
typedef char String[MAXSIZE + 1]; //? String[0]��Ŵ��ĳ���

//@ ���ɴ�T = chars
Status StrAssign(String T, char *chars)
{
    int i;
    if (strlen(chars) > MAXSIZE)
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return OK;
    }
}

//@ �ɴ�S���Ƶô�T
Status StrCopy(String T, String S)
{
    int i;
    for (i = 0; i <= S[0]; i++)
        T[i] = S[i];
    return OK;
}

//@�Ƿ�Ϊ��
//& ��ջSΪ�����򷵻�TRUE�����򷵻�FALSE
Status StrEmpty(String S)
{
    if (S[0] == 0)
        return TRUE;
    else
        return FALSE;
}

//@��ĸ��
//&��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0
int StrCompare(String S, String T)
{
    int i;
    for (i = 1; i <= S[0] && i <= T[0]; ++i)
        if (S[i] != T[i])
            return S[i] - T[i];
    return S[0] - T[0];
}

//@Ԫ�ظ���
int StrLength(String S)
{
    return S[0];
}

//@����Ϊ�մ�
Status ClearString(String S)
{
    S[0] = 0;
    return OK;
}

//@�ϲ���
//& ��T����S1��S2���Ӷ��ɵ��´���
//-��δ�ضϣ��򷵻�TRUE������FALSE
Status Concat(String T, String S1, String S2)
{
    int i;
    if (S1[0] + S2[0] <= MAXSIZE)
    { //- δ�ض�
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i];
        T[0] = S1[0] + S2[0];
        return TRUE;
    }
    else
    { //-  �ض�
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (i = 1; i <= MAXSIZE - S1[0]; i++)
            T[S1[0] + i] = S2[i];
        T[0] = MAXSIZE;
        return FALSE;
    }
}

//@�Ӵ�
//- ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
Status SubString(String Sub, String S, int pos, int len)
{
    int i;
    if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
        return ERROR;
    for (i = 1; i <= len; i++)
        Sub[i] = S[pos + i - 1];
    Sub[0] = len;
    return OK;
}

//@���봮
//*��ȫ���뷵��TRUE,���ֲ��뷵��FALSE
Status StrInsert(String S, int pos, String T)
{
    int i;
    if (pos < 1 || pos > S[0] + 1)
        return ERROR;
    if (S[0] + T[0] <= MAXSIZE)
    { //-  ��ȫ����
        for (i = S[0]; i >= pos; i--)
            S[i + T[0]] = S[i];
        for (i = pos; i < pos + T[0]; i++)
            S[i] = T[i - pos + 1];
        S[0] = S[0] + T[0];
        return TRUE;
    }
    else
    { //-  ���ֲ���
        for (i = MAXSIZE; i <= pos; i--)
            S[i] = S[i - T[0]];
        for (i = pos; i < pos + T[0]; i++)
            S[i] = T[i - pos + 1];
        S[0] = MAXSIZE;
        return FALSE;
    }
}

//@ɾ������
//*�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
Status StrDelete(String S, int pos, int len)
{
    int i;
    if (pos < 1 || pos > S[0] - len + 1 || len < 0)
        return ERROR;
    for (i = pos + len; i <= S[0]; i++)
        S[i - len] = S[i];
    S[0] -= len;
    return OK;
}

//@��ʾԪ��
void StrPrint(String T)
{
    int i;
    for (i = 1; i <= T[0]; i++)
        printf("%c", T[i]);
    printf("\n");
}

//$ ���ص�ģʽƥ�䷨
int Index(String S, String T, int pos)
{
    int i = pos;
    int j = 1;
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

//@  ���Next����ֵ
void NextPrint(int next[], int length)
{
    int i;
    for (i = 1; i <= length; i++)
        printf("%d", next[i]);
    printf("\n");
}

//@ ͨ�����㷵���Ӵ�T��next��
void get_next(String T, int *next)
{
    int i, k;
    i = 1; //& ǰ׺�ĵ����ַ�
    k = 0; //& ��׺�ĵ����ַ�
    next[1] = 0;
    while (i < T[0]) //* �˴�T[0]��ʾ��T�ĳ���
    {
        if (k == 0 || T[i] == T[k])
        {
            ++i;
            ++k;
            next[i] = k;
        }
        else
            k = next[k]; //* ���ַ���ƥ�䣬��kֵ����
    }
}

//$ KMPģʽƥ�䷨
//* �����Ӵ�T������S�е�pos���ַ�֮���λ�� �������ڣ���������ֵΪ0
int Index_KMP(String S, String T, int pos)
{
    int i = pos; //* ��posλ�ÿ�ʼƥ��
    int j = 1;   //* j�����Ӵ�T�е�ǰλ���±�ֵ
    int next[255];
    get_next(T, next); //&�õ�next����
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j]) //&��ʼj=0��ƥ���������㷨��ͬ
        {
            ++i;
            ++j;
        }
        else
            j = next[j]; //? j�˻غ��ʵ�λ�ã�iֵ����
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

//@ ��ģʽ��T��next��������ֵ����������nextval
void get_nextval(String T, int *nextval)
{
    int i, k;
    i = 1; //& ǰ׺�ĵ����ַ�
    k = 0; //& ��׺�ĵ����ַ�
    nextval[1] = 0;
    while (i < T[0]) //* �˴�T[0]��ʾ��T�ĳ���
    {
        if (k == 0 || T[i] == T[k])
        {
            ++i;
            ++k;
            if (T[i] != T[k]) //*��ǰ�ַ���ǰ׺�ַ��Ƿ���ͬ
                nextval[i] = k;
            else
                nextval[i] = nextval[k];
            //* nextvalֵ��ֵ��nextval��iλ�õ�ֵ
        }
        else
            k = nextval[k]; //* ���ַ�����ͬ����kֵ����
    }
}

//$ �������KMPģʽƥ�䷨
int Index_KMP1(String S, String T, int pos)
{
    int i = pos; //* ��posλ�ÿ�ʼƥ��
    int j = 1;   //* j�����Ӵ�T�е�ǰλ���±�ֵ
    int next[255];
    get_nextval(T, next); //&�õ�nextval����
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j]) //&��ʼj=0��ƥ���������㷨��ͬ
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

int main()
{
    int i, *p;
    String s1, s2;

    StrAssign(s1, "abcdex");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "abcabx");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "ababaaaba");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "aaaaaaaab");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "ababaaaba");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    get_nextval(s1, p);
    printf("NextValΪ: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "aaaaaaaab");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    get_nextval(s1, p);
    printf("NextValΪ: ");
    NextPrint(p, StrLength(s1));

    printf("\n");

    StrAssign(s1, "00000000000000000000000000000000000000000000000001");
    printf("����Ϊ: ");
    StrPrint(s1);
    StrAssign(s2, "0000000001");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s2);
    printf("\n");
    printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨����ģʽƥ���㷨��\n", Index(s1, s2, 1));
    printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�㷨�� \n", Index_KMP(s1, s2, 1));
    printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�����㷨�� \n", Index_KMP1(s1, s2, 1));

    return 0;
}
