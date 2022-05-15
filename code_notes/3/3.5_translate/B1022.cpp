#include <cstdio>

int main(){
    int a, b, p;
    int ans[31], num = 0;
    scanf("%d%d%d", &a, &b, &p);
    int sum = a + b;
    do{
        ans[num++] = sum % p;
        sum = sum / p;
    } while (sum != 0);
    for (int i = num - 1; i >= 0; i--)
    {
        printf("%d", ans[i]);
    }
    return 0;
}