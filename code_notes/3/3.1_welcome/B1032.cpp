#include <cstdio>
//ЩЂСа
int main(){
    const int MAX = 1000001;
    int sum[MAX] = {0};

    int n, ID, score;
    int maxscore = -1, maxID = -1;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &ID, &score);
        sum[ID] += score;
    }
    for (int i = 1; i <= n; i++)
    {
        if (sum[i] > maxscore)
        {
            maxscore = sum[i];
            maxID = i;
        }
    }
    printf("%d %d\n", maxID, maxscore);
    return 0;
}