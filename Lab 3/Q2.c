#include <stdio.h>
#include <time.h>

void main()
{
    int n;
    printf("Enter Length of array - ");
    scanf("%d", &n);

    int arr[n];
    // printf("Enter Values - ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // Random Values to populate the array
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    printf("Saved");
    printf("\nList before sort - ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    clock_t start, end;
    int opcount = 0;

    start = clock(); 

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            opcount++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    end = clock();

    double time = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\nList after sort - ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nTime - %f\nOPCount - %d", time, opcount);
}