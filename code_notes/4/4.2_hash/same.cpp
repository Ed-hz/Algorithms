#include <cstdio>
using namespace std;

int main(){
    const int maxn = 100010;
    int hashTable[maxn] = {0};
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        hashTable[x]++;
    }
    for (int i = 0; i < m; i++){
        scanf("%d", &x);
        printf("%d\n", hashTable[x]);
    }
    return 0;

}