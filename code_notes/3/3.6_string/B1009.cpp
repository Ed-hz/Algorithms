#include <cstdio>
#include <cstring>

int main(){
    const int maxn = 90;
    char str[maxn];
    gets(str);
    int len = strlen(str), r = 0, h = 0;
    char ans[maxn][maxn];
    for (int i = 0; i < len; i++)
    {
        if(str[i] != ' '){
            ans[r][h++] = str[i];
        }else{
            ans[r][h] = '\0';//转化为字符，用'\0'而不是"\0"，是一个字符
            r++;
            h = 0;
        }
    }
    for (int i = r; i >= 0; i--){
        printf("%s",ans[i]);
        if(i>0)
            printf(" ");
    }
    return 0;
}