#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv)
{
    int i;
    int total;
    printf("Enter the total number :\n");
    scanf("%d",&total);
    printf("Parallel execution: \n");
    int sum = 0;
#pragma omp parallel for
    for (i = 1; i <= total; i++)
    {
        sum += i;
        printf("Sum = %d \n", sum);
    }
    printf("Final  sum: %d\n", sum);
    return 0;
}