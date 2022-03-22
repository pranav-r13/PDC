#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void main()
{
    int a1, a2;
    a1 = 12;
    a2 = 5;
    int tid;
    #pragma omp parallel shared(a1, a2) private(tid)
    {
        tid = omp_get_thread_num();
        if (tid == 0)
        {
            printf("sum is%d\tfrom thread no is%d\t\n", a1 + a2, tid);
        }
        else if (tid == 1)
        {
            printf("product is %d\t from thread no is %d\t\n", a1 * a2, tid);
        }
    }
}