#include <stdio.h>
#include<math.h>

float fact(int n)  
{  
  if (n == 0)  
    return 1;  
  else  
    return(n * fact(n-1));  
}  
   

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
        float temp, power = 1,facto;
        for(int i = 1;i<n;i++)
        {
            power = pow(x,i);
            facto = fact(i);
            temp = power/facto;
            sum += temp;            
        }
        printf("\nThe sum of series = %f",sum);
    }

    return 0;
}