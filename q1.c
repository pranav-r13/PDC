#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main()
{
#pragma omp parallel
    {
        int tot = omp_get_max_threads();
        printf("\nThe maximum number of threads = %d\n", tot);

        int pro = omp_get_num_procs();
        printf("The number of processors in this system are = %d\n", pro);

        int num_threads = omp_get_num_threads();
        printf("number of threads used for the parallel = %d\n", num_threads);

        int tid = omp_get_thread_num();
        printf("Hello world from omp thread %d\n", tid);
    }

    return 0;
}
