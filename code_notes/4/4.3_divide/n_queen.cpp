#include <cstdio>
#include <cmath>
//n皇后问题只要在全排列的基础上考虑对角线即可
//回溯法

const int maxn = 11;
int n, p[maxn], hashTable[maxn] = {false};
int count = 0;

void generate_p(int index){
    if (index == n + 1){
        count++;
        return;
        /*暴力法
        bool flag = true;
        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++){
                if(abs(i-j)==abs(p[i]-p[j]))
                    flag = false;
            }
        }
        if (flag == true)
            count++;
        return;*/
    }
    for (int x = 1; x <= n; x++){
        if (hashTable[x] == false){
            bool flag = true;
            for (int pre = 1; pre < index; pre++)
            {
                if (abs(index - pre) == abs(x - p[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                p[index] = x;
                hashTable[x] = true;
                generate_p(index + 1);
                hashTable[x] = false;
            }
            /*暴力法
            p[index] = x;
            hashTable[x] = true;
            generate_p(index + 1);
            hashTable[x] = false;*/
        }
    }
}

int main(){
    n = 14;
    generate_p(1);
    printf("%d", count);
    return 0;
}