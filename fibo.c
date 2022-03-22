#include <stdio.h>
#include <omp.h>

int fibo(int n)
{
    if (n < 2)
        return n;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int fibnumber[100], i, j, n;
    printf("Enter the number: ");
    scanf("%d", &n);

#pragma omp parallel num_threads(2)
    {
#pragma omp critical
        if (omp_get_thread_num() == 0)
        {
            for (i = 0; i < n; i++)
                fibnumber[i] = fibo(i);
        }
        else
        {
            for (j = 0; j < n; j++)
                printf("%d\t", fibnumber[j]);
        }
    }
    return 0;
}