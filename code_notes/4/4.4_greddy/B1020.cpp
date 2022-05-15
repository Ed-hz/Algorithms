#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake{
    double store;
    double sell;
    double price;
} cake[1010];

bool cmp(mooncake a, mooncake b){
    return a.price > b.price;
}

int main(){
    int n;
    double D;
    scanf("%d%lf", &n, &D);
    for (int i = 0; i < n; i++)
        scanf("%lf", &cake[i].store);
    for (int i = 0; i < n; i++){
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + n, cmp);

    double earn = 0;
    for (int i = 0; i < n; i++){
        if (cake[i].store <= D){
            D -= cake[i].store;
            earn += cake[i].sell;
        }else{
            earn += cake[i].price * D;
            break;
        }
    }
    printf("%.2f", earn);
    return 0;
}