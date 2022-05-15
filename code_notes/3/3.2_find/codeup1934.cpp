#include <cstdio>

int main(){
    const int maxn = 210;
    int a[maxn];
    int n, x;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        scanf("%d", &x);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x){
                printf("%d\n", i);
                break;
            }
            if (i == n)
                printf("-1\n");
        }
    }
    return 0;
}