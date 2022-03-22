#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void add(int, int);
void sub(int, int);
void divi(int, int);
void prod(int, int);
void f3(void);

void main(void)
{
    int tid;
    int x, y;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &x, &y);
    float time = omp_get_wtime();
#pragma omp parallel shared(x, y) private(tid)
    {
        tid = omp_get_thread_num();
        if (tid == 0)
        {
            add(x, y);
        }
        else if (tid == 1)
        {
            sub(x, y);
        }
        else if (tid == 2)
        {
            prod(x, y);
        }
        else if (tid == 3)
        {
            divi(x, y);
        }
    }
    time = omp_get_wtime() - time;
    printf("Total time taken for all Arithmatic Operations (Parallel) are: %f", time);
}

void add(int a1, int a2)
{
    int sum;
    sum = a1 + a2;
    printf("Sum is : %d\n", sum);
}

void sub(int b1, int b2)
{
    int diff;
    diff = b1 - b2;
    printf("Difference is : %d\n", diff);
}

void divi(int a, int b)
{
    float d;
    if (a > b)
        d = a / b;
    else
        d = b / a;
    printf("Division is : %0.2f\n", d);
}

void prod(int a, int b)
{
    int prod = a * b;
    printf("Product is : %d\n", prod);
}