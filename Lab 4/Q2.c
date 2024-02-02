#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// Knapsack Problem

int knapSack(int W, int wt[], int val[], int n)
{
    unsigned int i, temp;
    unsigned int maxVal = 0, maxSequence = 0;
    unsigned int totalWeight, totalValue;
    int opcount = 0; // Intialize the opcount variable unsigned int index=0;
    for (i = 1; i < pow(2, n); i++)
    {
        ++opcount;
        temp = i;
        totalWeight = totalValue = 0;
        int index = 0;
        while (temp)
        {
            if (temp & 0x1)
            {
                totalWeight = totalWeight + wt[index];
                totalValue = totalValue + val[index];
            }
            index++;
            temp = temp >> 1;
        }
        if (totalWeight <= W && totalValue > maxVal)
        {
            maxVal = totalValue;
            maxSequence = i;
        }
    }
    printf("\nOperation count = %d\n", opcount);
    return maxSequence;
}

void main()
{
    // Ask for number of elements
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int wt[n], val[n];
    // Generate random weights and values
    // printf("Generating random weights and values...\n");
    // for (int i = 0; i < n; i++)
    // {
    //     wt[i] = rand() % 100 + 1;
    //     val[i] = rand() % 10 + 1;
    // }
    // int W = 250;
    // Ask user to enter weights and values
    printf("Enter the weights: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }
    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    int W;
    printf("Enter the maximum weight: ");
    scanf("%d", &W);

    clock_t start, end;
    start = clock();
    printf("Maximum value: %d\n", knapSack(W, wt, val, n));
    end = clock();
    printf("Time taken: %f", (double)(end - start) / CLOCKS_PER_SEC);
}