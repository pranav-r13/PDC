#include <stdio.h>
#include <omp.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    float root = sqrt(num);
    for (int i = 2; i <= root; i++)
        if (num % i == 0)
            return false;
 
    return true;
}

int main()
{
    int n,r, rev = 0, rem, Og,sum = 0,psum = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    Og = n;

#pragma omp critical
    {
        //even or odd
        while(n != 0){
            int digit = n % 10;
            sum = sum + digit;
            n = n / 10;
            if(digit %2== 0)
                printf("%d is even\n", digit);
            else
                printf("%d is odd\n", digit);
        }

        printf("\nThe sum of the digits = %d\n",sum);
        //prime
        if(isPrime(n) == true)
            printf("\nNumber is prime\n");
        else
            printf("\nNumber is not prime\n");

        //palindrome check
    
        while (n > 0)
        {
            r = n % 10;
            psum = (psum * 10) + r;
            n = n / 10;
        }
        if (Og == psum)
            printf("palindrome number ");
        else
            printf("not palindrome");
    }
    return 0;
}