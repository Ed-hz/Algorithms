#include <cstdio>

const int p = 99, Q = 34;
int x = 9898;

int main(){
    int y = 0, product = 1;
    int z[40], num = 0;
    while (x != 0)
    {
        y = y + (x % 10) * product;
        x = x / 10;
        product *= p;
    }
    do{
        z[num++] = y % Q;
        y = y / Q;
    } while (y != 0);
    return 0;
}