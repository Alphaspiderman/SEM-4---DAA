// PROBABLY WRONG

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 999999999

int opcount = 0;

// Kruskal's Algorithm
int kruskal(int n, int** A, int** cost)
{
    int mincost = 0;
    int* parent = (int*)malloc(n * sizeof(int));
    int ne = 0, a, b, u, v, i, j, min;
    for (i = 0; i < n; i++)
        parent[i] = 0;
    while (ne < n - 1)
    {
        min = MAX;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];
        if (u != v)
        {
            ne++;
            mincost += min;
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = MAX;
    }
    return mincost;
}
// void main()
void run(int n)
{
    int n = 5;
    int** cost = (int**)malloc(n * sizeof(int*));
    int** A = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        cost[i] = (int*)malloc(n * sizeof(int));
        A[i] = (int*)malloc(n * sizeof(int));
    }
    int edgecount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 2;
            edgecount += (A[i][j] == 1) ? 1 : 0;
            cost[i][j] = rand() % 50;
        }
    }

    clock_t start, end;
    printf("Starting");
    start = clock();
    int mincost = kruskal(n, A, cost);
    end = clock();

    printf("\nMinimum cost = %d\n", mincost);

    printf("\nTime taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Opcount: %d\n", opcount);
    printf("V+E: %d\n", n + edgecount);
}

void main()
{
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};
    printf("Starting the file\n");

    for (int c = 0; c < 12; c++)
    {
        printf("\nNew Loop");
        opcount = 0;
        run(arr[c]);
    }
}
