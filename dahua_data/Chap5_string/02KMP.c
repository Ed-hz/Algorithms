//? 朴素匹配复杂度O((n-m+1)*m),m为匹配长度，n为被匹配长度
//? KMP复杂度O(n+m)
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
#define MAXSIZE 100               //& 存储空间初始分配量
typedef int ElemType;             //* ElemType类型,设为int
typedef char String[MAXSIZE + 1]; //? String[0]存放串的长度

//@ 生成串T = chars
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

//@ 由串S复制得串T
Status StrCopy(String T, String S)
{
    int i;
    for (i = 0; i <= S[0]; i++)
        T[i] = S[i];
    return OK;
}

//@是否为空
//& 若栈S为串，则返回TRUE，否则返回FALSE
Status StrEmpty(String S)
{
    if (S[0] == 0)
        return TRUE;
    else
        return FALSE;
}

//@字母序
//&若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
int StrCompare(String S, String T)
{
    int i;
    for (i = 1; i <= S[0] && i <= T[0]; ++i)
        if (S[i] != T[i])
            return S[i] - T[i];
    return S[0] - T[0];
}

//@元素个数
int StrLength(String S)
{
    return S[0];
}

//@重置为空串
Status ClearString(String S)
{
    S[0] = 0;
    return OK;
}

//@合并串
//& 用T返回S1和S2联接而成的新串。
//-若未截断，则返回TRUE，否则FALSE
Status Concat(String T, String S1, String S2)
{
    int i;
    if (S1[0] + S2[0] <= MAXSIZE)
    { //- 未截断
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i];
        T[0] = S1[0] + S2[0];
        return TRUE;
    }
    else
    { //-  截断
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (i = 1; i <= MAXSIZE - S1[0]; i++)
            T[S1[0] + i] = S2[i];
        T[0] = MAXSIZE;
        return FALSE;
    }
}

//@子串
//- 用Sub返回串S的第pos个字符起长度为len的子串
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

//@插入串
//*完全插入返回TRUE,部分插入返回FALSE
Status StrInsert(String S, int pos, String T)
{
    int i;
    if (pos < 1 || pos > S[0] + 1)
        return ERROR;
    if (S[0] + T[0] <= MAXSIZE)
    { //-  完全插入
        for (i = S[0]; i >= pos; i--)
            S[i + T[0]] = S[i];
        for (i = pos; i < pos + T[0]; i++)
            S[i] = T[i - pos + 1];
        S[0] = S[0] + T[0];
        return TRUE;
    }
    else
    { //-  部分插入
        for (i = MAXSIZE; i <= pos; i--)
            S[i] = S[i - T[0]];
        for (i = pos; i < pos + T[0]; i++)
            S[i] = T[i - pos + 1];
        S[0] = MAXSIZE;
        return FALSE;
    }
}

//@删除部分
//*从串S中删除第pos个字符起长度为len的子串
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

//@显示元素
void StrPrint(String T)
{
    int i;
    for (i = 1; i <= T[0]; i++)
        printf("%c", T[i]);
    printf("\n");
}

//$ 朴素的模式匹配法
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

//@  输出Next数组值
void NextPrint(int next[], int length)
{
    int i;
    for (i = 1; i <= length; i++)
        printf("%d", next[i]);
    printf("\n");
}

//@ 通过计算返回子串T的next数
void get_next(String T, int *next)
{
    int i, k;
    i = 1; //& 前缀的单个字符
    k = 0; //& 后缀的单个字符
    next[1] = 0;
    while (i < T[0]) //* 此处T[0]表示串T的长度
    {
        if (k == 0 || T[i] == T[k])
        {
            ++i;
            ++k;
            next[i] = k;
        }
        else
            k = next[k]; //* 若字符不匹配，则k值回溯
    }
}

//$ KMP模式匹配法
//* 返回子串T在主串S中第pos个字符之后的位置 若不存在，则函数返回值为0
int Index_KMP(String S, String T, int pos)
{
    int i = pos; //* 从pos位置开始匹配
    int j = 1;   //* j用于子串T中当前位置下标值
    int next[255];
    get_next(T, next); //&得到next数组
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j]) //&初始j=0，匹配与朴素算法相同
        {
            ++i;
            ++j;
        }
        else
            j = next[j]; //? j退回合适的位置，i值不变
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

//@ 求模式串T的next函数修正值并存入数组nextval
void get_nextval(String T, int *nextval)
{
    int i, k;
    i = 1; //& 前缀的单个字符
    k = 0; //& 后缀的单个字符
    nextval[1] = 0;
    while (i < T[0]) //* 此处T[0]表示串T的长度
    {
        if (k == 0 || T[i] == T[k])
        {
            ++i;
            ++k;
            if (T[i] != T[k]) //*当前字符和前缀字符是否相同
                nextval[i] = k;
            else
                nextval[i] = nextval[k];
            //* nextval值赋值给nextval在i位置的值
        }
        else
            k = nextval[k]; //* 若字符不相同，则k值回溯
    }
}

//$ 改良后的KMP模式匹配法
int Index_KMP1(String S, String T, int pos)
{
    int i = pos; //* 从pos位置开始匹配
    int j = 1;   //* j用于子串T中当前位置下标值
    int next[255];
    get_nextval(T, next); //&得到nextval数组
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j]) //&初始j=0，匹配与朴素算法相同
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
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "abcabx");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "ababaaaba");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "aaaaaaaab");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "ababaaaba");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    get_nextval(s1, p);
    printf("NextVal为: ");
    NextPrint(p, StrLength(s1));
    printf("\n");

    StrAssign(s1, "aaaaaaaab");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    get_next(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    get_nextval(s1, p);
    printf("NextVal为: ");
    NextPrint(p, StrLength(s1));

    printf("\n");

    StrAssign(s1, "00000000000000000000000000000000000000000000000001");
    printf("主串为: ");
    StrPrint(s1);
    StrAssign(s2, "0000000001");
    printf("子串为: ");
    StrPrint(s2);
    printf("\n");
    printf("主串和子串在第%d个字符处首次匹配（朴素模式匹配算法）\n", Index(s1, s2, 1));
    printf("主串和子串在第%d个字符处首次匹配（KMP算法） \n", Index_KMP(s1, s2, 1));
    printf("主串和子串在第%d个字符处首次匹配（KMP改良算法） \n", Index_KMP1(s1, s2, 1));

    return 0;
}
