#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main()
{
    int *a, *b, *c, n, n_per_thread, total_threads;

    printf("Enter size of the two vectors: ");
    scanf("%d", &n);
    printf("Enter the number of threads: ");
    scanf("%d", &total_threads);

    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * n);
    c = (int *)malloc(sizeof(int) * n);

    printf("Enter array a elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    printf("Enter array b elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    
    // Setting the number of threads.
    omp_set_num_threads(total_threads);
    n_per_thread = n / total_threads;

    // Computing the vector addition
    float time = omp_get_wtime();
#pragma omp parallel for shared(a, b, c) schedule(static, n_per_thread)
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
        printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
    }
    time = omp_get_wtime() - time;
    printf("Time taken for the addition of two vectors is %f\n", time);

    printf("Printing the values of the three vectors:\n");
    printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
    }
    
    // clean up memory
    free(a);
    free(b);
    free(c);
    return 0;
}