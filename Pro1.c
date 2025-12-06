#include<stdio.h>

int main()
{
    int a[10], i , n , t = 10;
    for (size_t i = 0; i < t; i++)
    {
        printf("\nValue:- ");
        scanf("%d",&a[i]);
    }
    // printf("\nEnter Value to Search: ");
    // scanf("%d",&n);

    // for (size_t i = 0; i < 5; i++)
    // {
    //     if (n == a[i])
    //     {
    //         t = 1;
    //     }
    // }
    
    
    //     if (t == 1)
    //     {
    //         printf("\n%d Value Found.",n);
    //     }else
    //     {
    //         printf("\nValue Not Found.");
    //     }
    
    for ( i = 0; i < t; i++)
    {
       for (size_t n = i; n < t-1; n++)
       {
          if (a[i] > a[n+1])
          {
            int temp = a[i];
            a[i] = a[n+1];
            a[n+1] = temp;
          }
          
         
       }
       
    }

    for (size_t i = 0; i < 10; i++)
    {
        printf("\n%d",a[i]);
    }
    
    return 0;
}