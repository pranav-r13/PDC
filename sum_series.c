#include <stdio.h>
#include<math.h>

int main()
{
    float x, sum;
    int i, n;
    printf("Input the value of x :");
    scanf("%f", &x);
    printf("Input number of terms : ");
    scanf("%d", &n);
#pragma omp shared(sum)
    {
        sum = 1;
        printf("\nsum : %f",sum);
        float temp, power = 1;
        for(int i = 1;i<n;i++)
        {
            power = pow(x,i);
            temp = 1/power;
            sum += temp;            
        }
        printf("\nThe sum of series = %f",sum);
    }

    return 0;
}