#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n, r, rev = 0, rem, og, sum = 0, psum = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("the number is %d\n", n);
    int num = n;
#pragma omp critical
    {
        // even or odd and sum
        while (n != 0)
        {
            int digit = n % 10;
            sum = sum + digit;
            n = n / 10;
            if (digit % 2 == 0)
                printf("%d is even\n", digit);
            else
                printf("%d is odd\n", digit);
        }
        printf("\nThe sum of the digits = %d\n", sum);

        // prime
        int flag = 0, i;
        if (num == 0 || num == 1)
            flag = 1;

        for (i = 2; i <= num / 2; ++i)
        {
            if (num % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d is a prime number.\n", num);
        else
            printf("%d is not a prime number.\n", num);

        // palindrome check
        int temp = num;
        int r;
        while (num > 0)
        {
            r = num % 10;
            sum = (sum * 10) + r;
            num = num / 10;
        }
        if (temp == sum)
            printf("palindrome number ");
        else
            printf("not palindrome");
    }
    return 0;
}