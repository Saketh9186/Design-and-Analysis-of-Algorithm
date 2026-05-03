#include <stdio.h>

int w[10], x[10], n, target;

void sumofsubsets(int s, int k) {
    int i;

    if(s == target) {
        printf("Subset: ");
        for(i = 0; i < k; i++) {
            if(x[i] == 1)
                printf("%d ", w[i]);
        }
        printf("\n");
        return;
    }

    if(k >= n || s > target)
        return;

    x[k] = 1;
    sumofsubsets(s + w[k], k + 1);
 
    x[k] = 0;
    sumofsubsets(s, k + 1);
}

int main() {
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    sumofsubsets(0, 0);

    return 0;
}