#include<stdio.h>

int main()
{
    int a[10], i , n , t = 10;
    for (size_t i = 0; i < t; i++)
    {
        printf("\nValue:- ");
        scanf("%d",&a[i]);
    }
    
     // Bubble Sort.
    for ( i = 0; i < t; i++)
    {
       for (size_t n = 0; n < t-1-i; n++)
       {
          if (a[n] > a[n+1])
          {
            int temp = a[n];
            a[n] = a[n+1];
            a[n+1] = temp;
          }
          
         
       }
       
    }

    // Selection Sort.
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