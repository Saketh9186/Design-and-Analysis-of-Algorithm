#include <stdio.h>

int main()
{
    int n, i, j, source;
    int cost[10][10], dist[10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (999 if no edge):\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source: ");
    scanf("%d", &source);

    for(i = 1; i <= n; i++)
        dist[i] = 999;

    dist[source] = 0;

    for(i = 1; i <= n - 1; i++)
        for(j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(cost[j][k] != 999 && dist[k] > dist[j] + cost[j][k])
                    dist[k] = dist[j] + cost[j][k];

    printf("Shortest distances:\n");
    for(i = 1; i <= n; i++)
        printf("%d -> %d = %d\n", source, i, dist[i]);

    return 0;
}