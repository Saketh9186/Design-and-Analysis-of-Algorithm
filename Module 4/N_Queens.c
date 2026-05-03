#include <stdio.h>
#include <stdlib.h>

int x[10], n;

int place(int k, int col)
{
    int i;
    for(i = 1; i < k; i++)
        if(x[i] == col || abs(x[i] - col) == abs(i - k))
            return 0;
    return 1;
}

void nqueens(int k)
{
    int i;

    for(i = 1; i <= n; i++)
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                for(i = 1; i <= n; i++)
                    printf("%d ", x[i]);
                printf("\n");
            }
            else
                nqueens(k + 1);
        }
}

int main()
{
    scanf("%d", &n);
    nqueens(1);
    return 0;
}
