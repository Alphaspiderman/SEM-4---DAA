// PROBABLY WRONG
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount = 0;

// check if there is a subset of set[] with sum equal to target
int subsetSum(int set[], int n, int target)
{
    opcount++;
    // return true if target becomes 0 (subset found)
    if (target == 0)
        return 1;

    // base case: no items left, or target becomes negative
    if (n < 0 || target < 0)
        return 0;

    // Case 1. include current item in the subset (A[n]) and recur
    // for remaining items (n - 1) with remaining target (target - A[n])
    int include = subsetSum(set, n - 1, target - set[n]);

    // Case 2. exclude current item n from subset and recur for
    // remaining items (n - 1)
    int exclude = subsetSum(set, n - 1, target);

    // return true if we can get subset by including or excluding the current item
    return include || exclude;
}

// Subset sum problem using backtracking
void run(int n)
// int main()
{
    // int n;
    // printf("Enter the number of elements in the set: ");
    // scanf("%d", &n);

    int *set = (int *)malloc(n * sizeof(int));
    if (set == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // scanf("%d", &set[i]);
        set[i] = rand() % 100;
    }

    int target;
    // printf("Enter the target sum: ");
    // scanf("%d", &target);
    target = n * (rand() % 100);

    clock_t start, end;

    start = clock();
    if (subsetSum(set, n - 1, target))
        printf("Yes\n");
    else
        printf("No\n");
    end = clock();

    printf("\nTime taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Opcount: %d\n", opcount);
}

void main()
{
    int arr[] = {3, 5, 8, 10, 13, 15, 18, 20, 23, 25, 28, 30};

    for (int i = 0; i < 12; i++)
    {
        run(arr[i]);
    }
}