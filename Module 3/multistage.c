#include <stdio.h>

int main()
{
    int n, i, j, k;
    int cost[10][10], dist[10], path[10];
    int min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    dist[n] = 0;

    for(i = n-1; i >= 1; i--)
    {
        min = 999;

        for(j = i+1; j <= n; j++)
        {
            if(cost[i][j] != 0 && cost[i][j] + dist[j] < min)
            {
                min = cost[i][j] + dist[j];
                path[i] = j;
            }
        }

        dist[i] = min;
    }

    printf("Minimum cost = %d\n", dist[1]);

    printf("Path: 1");
    k = 1;

    while(k != n)
    {
        k = path[k];
        printf(" -> %d", k);
    }
    printf("\n");

    return 0;
}

