#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int opcount = 0;

// Warshall's Algorithm
void warshall(int n, int A[n][n])
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                opcount++;
                if (A[i][j] == 0 && (A[i][k] == 1 && A[k][j] == 1))
                    A[i][j] = 1;
            }
        }
    }
}

// void main(){
void run(int n)
{
    // int n;
    // printf("Enter number of vertices: ");
    // scanf("%d", &n);
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 2;
        }
    }

    clock_t start, end;
    start = clock();
    warshall(n, A);
    end = clock();

    printf("\nTime taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Opcount: %d\n", opcount);
}

// Main
void main()
{
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};

    for (int i = 0; i < 12; i++)
    {
        opcount = 0;
        run(arr[i]);
    }
}