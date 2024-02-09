// Merge Sort
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int opcount = 0;

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, c[1000];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        opcount++;
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while (i <= mid)
        c[k++] = a[i++];
    while (j <= high)
        c[k++] = a[j++];
    for (i = low; i < k; i++)
        a[i] = c[i];
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    // printf("Enter the elements: ");
    // for (i = 0; i < n; i++)
    //     scanf("%d", &a[i]);
    // Generating random numbers
    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;
    clock_t start, end;
    start = clock();
    mergesort(a, 0, n - 1);
    end = clock();
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTime taken: %f", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\nOpcount: %d", opcount);
    printf("\n");
}