
void selectSort(){
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        for (int j = i; j <= n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        int tmp = A[i];
        A[i] = A[k];
        A[k] = tmp;
    }
}

const int maxn = 200;
int A[maxn], n;
void insertsort(){
    for (int i = 2; i <= n; i++){
        int tmp = A[i], j = i;
        while (j > 1 && tmp < A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tmp;
    }
}