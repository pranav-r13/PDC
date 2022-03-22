#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
    int x = 5;
// by default the variable is shared
#pragma omp parallel shared(x)
    {
        x = x + 1;
        printf("shared: x is %d\n", x);
    }

    // private variable
    int a = 1;
#pragma omp parallel private(x)
    {
        a = a + 1; // dangerous
        printf("private: a is %d\n", a);
    }

    // first private variable
    int t = 2;
#pragma omp parallel firstprivate(t)
    {
        t = t + 1;
        printf("first private: t is %d\n", t);
    }
    int y = 10;
    // last private variable
#pragma omp parallel for lastprivate(y)
    for (int i = 0; i < 5; i++)
    {
        int tid = omp_get_thread_num();
        y = i;
        printf("x value %d from thread %d\n", i, tid);
    }
    printf("the value of y after parallel is %d\n ", y);

    return 0;
}