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
            ans[r][h] = '\0';//ת��Ϊ�ַ�����'\0'������"\0"����һ���ַ�
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