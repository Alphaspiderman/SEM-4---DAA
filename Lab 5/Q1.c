// Quick Sort
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int opcount = 0;
void quicksort(int a[], int low, int high)
{
    int pivot, i, j, temp;
    opcount++;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i <= high)
                i++;
            while (a[j] > a[pivot] && j >= low)
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
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
    quicksort(a, 0, n - 1);
    end = clock();
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTime taken: %f", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\nOpcount: %d", opcount);
    printf("\n");
}