#include <stdio.h>

int n;
int set[10];
int subset[10];

void sumOfSubsets(int i, int sum, int target)
{
    int j;

    if(sum == target)
    {
        printf("Subset: ");
        for(j = 0; j < i; j++)
        {
            if(subset[j] != -1)
            {
                printf("%d ", subset[j]);
            }
        }
        printf("\n");
        return;
    }

    if(i >= n || sum > target)
    {
        return;
    }

    subset[i] = set[i];
    sumOfSubsets(i + 1, sum + set[i], target);

    subset[i] = -1;
    sumOfSubsets(i + 1, sum, target);
}

int main()
{
    int i, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
        subset[i] = -1;
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with given sum:\n");
    sumOfSubsets(0, 0, target);

    return 0;
}