// Dynamic memory allocation (MALLOC).

#include<stdio.h>
#include<malloc.h>
int main()
{
    int *p, i, n, sum = 0;
    p = (int *)malloc(10*sizeof(int)); // casting into pointer {(int *)}
    
    for ( i = 0; i < 10; i++)
    {
        printf("Value = ");
        scanf("%d",&n);
        *(p+i) = n;
    }

     for ( i = 0; i < 10; i++)
    {
      sum += *(p+i);
    }
    printf(" Sum is %d", sum);
    free(p);
    return 0;
}