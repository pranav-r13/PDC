#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n, r, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("the number is %d\n", n);
    int num = n;
    int num2 = n;
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
        int r, sum = 0, temp;
        temp = num2;
        while (num2 > 0)
        {
            r = num2 % 10;
            sum = (sum * 10) + r;
            num2 = num2 / 10;
        }
        if (temp == sum)
            printf("The number is a palindrome ");
        else
            printf("The number is not a palindrome");

    }
    return 0;
}