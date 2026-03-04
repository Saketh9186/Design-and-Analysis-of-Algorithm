#include <stdio.h>

int a[10][10], visited[10], n, cost = 0;

void tsp(int city) {
    int i, min = 999, nextcity = 0;

    visited[city] = 1;
    printf("%d -> ", city + 1);

    for(i = 0; i < n; i++) {
        if(a[city][i] != 0 && visited[i] == 0) {
            if(a[city][i] < min) {
                min = a[city][i];
                nextcity = i;
            }
        }
    }

    if(nextcity == 0) {
        printf("1");
        cost += a[city][0];
        return;
    }

    cost += min;
    tsp(nextcity);
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Path: ");
    tsp(0);

    printf("\nMinimum cost: %d\n", cost);

    return 0;
}

