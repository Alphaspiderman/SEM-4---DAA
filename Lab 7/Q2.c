#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount = 0;

// Comparision Counting Sort
void countingSort(int A[], int n)
{
    int i, j;
    int S[150], C[1000];
    for (i = 0; i <= n - 1; i++){C[i] = 0;}
    for (i = 0; i <= n - 2; i++)
    {
        for (j = i + 1; j <= n - 1; j++)
        {
            opcount++;
            if (A[i] < A[j])
                C[j] = C[j] + 1;
            else
                C[i] = C[i] + 1;
        }
    }
    for (i = 0; i <= n - 1; i++)
        S[C[i]] = A[i];
}

// Main
void main(int n)
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    clock_t start, end;
    start = clock();
    countingSort(arr, n);
    end = clock();

    printf("\nTime taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Opcount: %d\n", opcount);
}