#include <stdio.h>

#define MAX 10

int visited[MAX];

void dfs(int graph[MAX][MAX], int n, int node) {
    int i;

    printf("%d ", node);
    visited[node] = 1;

    for (i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int graph[MAX][MAX], n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS: ");
    dfs(graph, n, start);
    printf("\n");

    return 0;
}
