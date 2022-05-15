#include <cstdio>
#include <cstring>

bool judge(char str[]){
    int len=strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

int main(){
    const int maxn=256;
    char str[maxn];
    while (gets(str))
    {
        bool flag = judge(str);
        printf("%s\n", ((flag==true) ? "YES" : "NO"));
    }
    return 0;
}