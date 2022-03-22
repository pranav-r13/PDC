#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main()
{
    int *array = (int *)malloc(sizeof(int) * 3);

    /*Accepting Input Values*/
    printf("Enter 3 Numbers: ");
    for(int i = 0; i < 3; i++)
        scanf("%d", &array[i]);
    
    /*Largest Number Calculation*/
    float par_max_time, par_min_time, ser_max_time, ser_min_time;

    /*Parallel Calculation*/
    int par_max = 0;

    par_max_time = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < 3; i++)
    {
        if (array[i] > par_max)
#pragma omp critical
            if (array[i] > par_max)
                par_max = array[i];
    }
    par_max_time = omp_get_wtime() - par_max_time;

    printf("Time taken for finding largest number (Parallel): %f", par_max_time);

    /* Serial Calculation */
    int ser_max = array[0];

    ser_max_time = omp_get_wtime();
    for (int i = 1; i < 3; i++)
        if (array[i] > ser_max)
            ser_max = array[i];
    ser_max_time = omp_get_wtime() - ser_max_time;

    printf("\nTime taken for finding largest number (Serial): %f", ser_max_time);

    /*Smallest Number Calculation*/

    /*Parallel Calculation*/
    int par_min = array[0];

    par_min_time = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < 3; i++)
    {
        if (array[i] < par_min)
#pragma omp critical
            if (array[i] < par_min)
                par_min = array[i];
    }
    par_min_time = omp_get_wtime() - par_min_time;
    
    printf("\nTime taken for finding smallest number (Parallel): %f", par_min_time);

    /* Serial Calculation */
    int ser_min = array[0];
    
    ser_min_time = omp_get_wtime();
    for (int i = 1; i < 3; i++)
        if (array[i] < ser_min)
            ser_min = array[i];
    ser_min_time = omp_get_wtime() - ser_min_time;
    
    printf("\nTime taken for finding smallest number (Serial): %f", ser_min_time);

    /* Checking For Output Validity */
    if(ser_max == par_max)
        printf("\nLargest among the 3 numbers: %d", par_max);
    
    if(ser_min == par_min)
        printf("\nSmallest among the 3 numbers: %d", par_min);
}