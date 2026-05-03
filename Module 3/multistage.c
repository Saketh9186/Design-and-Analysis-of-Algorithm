#include <stdio.h>

int main()
{
    int n;
    int cost[10][10], dist[10];
    int i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (0 if no edge):\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    for(i = 1; i <= n; i++)
        dist[i] = 999;

    dist[n] = 0;

    for(i = n - 1; i >= 1; i--)
        for(j = i + 1; j <= n; j++)
            if(cost[i][j] != 0 && dist[i] > cost[i][j] + dist[j])
                dist[i] = cost[i][j] + dist[j];

    printf("Minimum cost = %d\n", dist[1]);

    return 0;
}