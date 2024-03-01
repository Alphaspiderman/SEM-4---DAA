#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int opcount = 0;

// Binomial
void binomial(int n, int k)
{
    int c[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            opcount++;
            if (j == 0 || j == i)
            {
                c[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
    printf("Binomial Coefficient: %d\n", c[n][k]);
}

// Main
int main()
{
    int n, k;
    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);
    clock_t start, end;
    start = clock();
    binomial(n, k);
    end = clock();
    printf("\nOPCount: %d", opcount);
    printf("\nTime - %f", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}