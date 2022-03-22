#include <stdio.h>
#include <omp.h>
#include <math.h>

void print_arr(int arr[],int n)
{
    printf("\nThe array is : ");
        for(int i = 0;i<n;i++)
            printf("%d ",arr[i]);

    printf("\nThe time taken is : %.2f s ", omp_get_wtime());

}

// void prime(int arr[],int N)
// {
//     int prime_count = 0, prime_sum = 0;
//     for (int i = 0; i < N; i++)
//     {
//         if (isPrime(arr[i]) == 1)
//         {
//             prime_count += 1;
//             prime_sum += arr[i];
//         }
//     }
//     printf("The count of prime numbers is %d\n", prime_count);
//     printf("The sum of prime numbers is %d\n", prime_sum);
// }

// void stats(int x[],int n)
// {
//     int i;
//     float average,variance,std_deviation,sum1,sum;
//     for (i = 0; i < n; i++)
//     {
//         sum = sum + x[i];
//     }
//     average = sum / (float)n;
//     for (i = 0; i < n; i++)
//     {
//         sum1 = sum1 + pow((x[i] - average), 2);
//     }
//     variance = sum1 / (float)n;
//     std_deviation = sqrt(variance);

//     printf("\nThe mean is : %f",average);
//     printf("\nThe standard deviation is : %f",std_deviation);
//     printf("\nThe variance is : %f",variance);
// }

int main()
{
    int i,n = 0,a[100];
    printf("\nEnter the number of elements :");
    scanf("%d",&n);
    
    printf("\nEnter the array ");
    for(i = 0;i<n;i++)
        scanf("%d",&a[i]);

    #pragma omp parallel
    {
        //question 1
        int temp;
        print_arr(a,n);
        
        
        printf("\n");

        //question 2
        for(i = 0;i<n;i++)
        {
            temp = a[i];
            temp = temp * i;
            a[i] = temp;
        }

        print_arr(a,n);

        printf("\n");

        //question 3
        int even_sum = 0;

        for(i = 0;i <n;i++)
        {
            if(i%2 == 0)
                even_sum = even_sum + a[i];
        }

        printf("The sum of elements in odd position is : %d \n",even_sum);

        //question 4
        int odd_count = 0,even_count = 0;

        for(i = 0;i<n;i++)
        {
            if(i%2 == 0)
                odd_count += 1;
            else
                even_count += 1;
        }
        
        printf("The even count is %d and the odd count is %d \n",even_count,odd_count);


        //question 5
        int squares,cube;

        for(i = 0;i<n;i++)
        {
            squares = squares + (a[i] * a[i]);
            cube = cube + (a[i] * a[i] * a[i]);
        }

        printf("\nThe Sum of squares is %d",squares);
        printf("\nThe Sum of cube is %d",cube);

        //question 6
        int min = a[0],max = a[0];

        for(i=1; i<n; i++)
        {
            if(a[i] > max)
            {
                max = a[i];
            }

            if(a[i] < min)
            {
                min = a[i];
            }
        }

        printf("\nThe Minimum is %d",min);
        printf("\nThe Maximum is %d",max);

        // //question 7
        // prime(a,n);

        //question 8
        // stats(a,n);
    }
    
    return 0;
}