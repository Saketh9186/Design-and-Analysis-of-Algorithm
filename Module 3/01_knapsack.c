#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int n;
    int i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n];
    int value[n];

    printf("Enter weights of items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter values of items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value[i]);
    }

    int W;
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("Maximum value = %d\n", dp[n][W]);

    return 0;
}