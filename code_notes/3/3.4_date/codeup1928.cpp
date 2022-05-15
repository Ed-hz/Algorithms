#include <cstdio>

bool isRUN(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void swap(int& n1, int& n2){
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

int main(){
    int month[13] = {0, 31, 28, 31, 30, 31, 30,
     31, 31, 30, 31, 30, 31};
    int time[2], y[2], m[2], d[2];
    int ans = 1;
    while (scanf("%d %d", &time[0], &time[1]) != EOF){
        if(time[0]>time[1])
            swap(time[0], time[1]);
        y[0] = time[0] / 10000, m[0] = time[0] % 10000 / 100, d[0] = time[0] % 100;
        y[1] = time[1] / 10000, m[1] = time[1] % 10000 / 100, d[1] = time[1] % 100;
        while (y[0] < y[1] || m[0] < m[1] || d[0] < d[1])
        {
            d[0]++;
            if (d[0] == ((m[0] == 2) ? (isRUN(y[0]) ? 29 : 28) : month[m[0]]))
            {
                m[0]++;
                d[0] = 1;
            }
            if (m[0] == 13)
            {
                y[0]++;
                m[0] = 1;
            }
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}