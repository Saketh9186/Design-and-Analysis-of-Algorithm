#include <stdio.h>

int main()
{
    int n, cost[10][10], dist[10], visited[10];
    int i, j, u, min, source;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (0 if no edge):\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source: ");
    scanf("%d", &source);

    for(i = 1; i <= n; i++)
    {
        dist[i] = 999;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(i = 1; i <= n; i++)
    {
        min = 999;

        for(j = 1; j <= n; j++)
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }

        visited[u] = 1;

        for(j = 1; j <= n; j++)
            if(cost[u][j] != 0 && dist[j] > dist[u] + cost[u][j])
                dist[j] = dist[u] + cost[u][j];
    }

    printf("Shortest distances:\n");
    for(i = 1; i <= n; i++)
        printf("%d -> %d = %d\n", source, i, dist[i]);

    return 0;
}