// Program to merge two array in a sorted array.

#include <stdio.h>

int main()
{
    int i, j, n, n1, idx, temp, a[100], b[100], c[200];
    printf("Enter the size of A:- ");
    scanf("%d", &n);
    idx = n;
    printf("\nEnter element.\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the size of B:- ");
    scanf("%d", &n1);
    idx += n1;
    printf("\nEnter element.\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < idx; i++)
    {
        if (i < n)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[i - n];
        }
    }

    for ( i = 0; i < idx; i++)
    {
        for ( j = 0; j < idx - i; j++)
        {
            if(c[j] > c[j+1])
            {
             temp = c[j];
             c[j] = c[j+1];
             c[j+1] = temp;   
            }
        }
    }

    for ( int i = 1; i < idx+1; i++)
    {
        printf("%d ",c[i]);
    }
    

}