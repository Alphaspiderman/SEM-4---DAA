#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Insertion Sort
int opcount = 0;
void insertionSort(int arr[], int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            opcount++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void main()
{
    int arr[1000], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Generating random array...\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    // printf("Enter the elements: ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    clock_t start, end;
    start = clock();
    insertionSort(arr, n);
    end = clock();
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nOPCount - %d\nTime taken: %f", opcount, (double)(end - start) / CLOCKS_PER_SEC);
}