#include <cstdio>

int main(){
    int row, col;
    char c;
    scanf("%d %c", &col, &c);
    row = col + ((col % 2 == 1) ? 1 : 0);
    for (int i = 0; i < col; i++)
    {
        printf("%c", c);
    }
    printf("\n");
    for (int i = 2; i < col; i++)
    {
        printf("%c", c);
        for (int j = 0; j < col - 2; j++)
        {
            printf(" ");
        }
        printf("%c\n", c);
    }
    for (int i = 0; i < col; i++)
    {
        printf("%c", c);
    }
    return 0;
}