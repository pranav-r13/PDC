#include<stdio.h>

void main()
{
    int a[5] = {12,1,123,2,5};

    int i,max,n,r1,count,count1;
    max = a[0];
    for(i = 0;i<5;i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }

    }
    printf("Maximum is %d\t\n",max);

    for(i = 0;i<5;i++)
    {
        printf("%d\t\n",a[i]);
    }
    n = max;
    while(n! = 0)
    {
        r1 = n%10;
        count = count+1;

        n = n/10;

    }

    printf("count is %d\n\t");
    count1 = count;
    for(i = 0;i<5;i++)
    {
        x = a[i];
        while(x!=0)
        {
            r2 = x%10;
            r3 = r3+1;
            x = x/10;

        }
        if(r3!=3)
        {
            
    
        }
    }

}