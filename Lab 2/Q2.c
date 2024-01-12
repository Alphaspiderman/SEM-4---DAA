#include <stdio.h>
#include <time.h>

int gcd(unsigned int m, unsigned int n)
{
    int opcount = 0;
    unsigned int t = m > n ? n : m;
    for (int i = t; i > 0; i--)
    {
        opcount++;
        if (m % i == 0 && n % i == 0)
        {
            printf("\nOPCount - %d", opcount);
            return i;
        }
    }
}


void main()
{
    // Manual Driver
    unsigned int n, m;
    printf("Enter two number to find their GCD - \n");
    scanf("%d", &m);
    scanf("%d", &n);
    printf("GCD of the given numbers - %d", gcd(m, n));

    // Automated Driver
    // int m[] = {16, 49, 154, 423, 509, 651, 4689, 7946, 45135, 98416, 164684, 598470, 651352, 1513554};
    // int n[] = {12, 26, 65, 98, 124, 213, 984, 654, 13235, 12224, 25413, 23325, 475, 984143};
    // clock_t start, end;
    // for (int i = 0; i < 14; i++)
    // {
    //     start = clock();
    //     printf("\nGCD of %d and %d is %d", m[i], n[i], gcd(m[i], n[i]));
    //     end = clock();
    //     double time = (double)(end - start) / CLOCKS_PER_SEC;
    //     printf("\nTime taken - %f\n\n", time);
    // }
}