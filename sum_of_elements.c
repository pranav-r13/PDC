#include <stdio.h>
#include <omp.h>
void sumArray(int arr[], int n)
{
    int sum = 0;
#pragma omp parallel shared(sum)
    {
#pragma omp for reduction(+ : sum)
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
    }
    printf("\nThe sum of all elements is: %d", sum);
}
void productArray(int arr[], int n)
{
    int prod = 1;
#pragma omp parallel shared(prod)
    {
#pragma omp parallel for reduction(* : prod) 
    for (int i = 0; i < n; i++) {
        prod *= arr[i];
    }
}
printf("\nThe product of all elements is: %d", prod);
}


void main()
{
    int i, arr[7] = {1, 2, 3, 4, 7, 8, 10}, sum = 0;
    sumArray(arr, 7);
    productArray(arr, 7);
}