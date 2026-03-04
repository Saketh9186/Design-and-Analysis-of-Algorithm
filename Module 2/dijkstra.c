#include <stdio.h>

int main() {
    int n, i, j, u;
    int cost[10][10], dist[10], visited[10];
    int min, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 1; i <= n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    visited[source] = 1;

    for(i = 1; i < n; i++) {
        min = 999;

        for(j = 1; j <= n; j++) {
            if(dist[j] < min && visited[j] == 0) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] > dist[u] + cost[u][j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances from source:\n");
    for(i = 1; i <= n; i++)
        printf("%d -> %d = %d\n", source, i, dist[i]);

    return 0;
}

