// Program to find common elements of both array.

#include <stdio.h>

int main()
{
    int i, j, n, k = 0, n1, idx, temp, a[100], b[100], c[200];
    printf("Enter the size of A:- ");
    scanf("%d", &n);
    idx = n;
    printf("\nEnter element.\n");
    for (i = 1; i < n+1; i++)
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

    for (i = 0; i < n+1; i++)
    {
        for ( j = 0; j < n1; j++)
        {
            if (a[i] == a[j])
            {
                c[k] = a[i];
            }else if (a[i] == b[j])
            {
                c[k] = a[i];
                k++;
            }
            
            
        }
        
    }

    /*for ( i = 1; i < k + 1; i++)
    {
        for ( j = 1; j < k - i + 1; j++)
        {
            if(c[j] > c[j+1])
            {
             temp = c[j];
             c[j] = c[j+1];
             c[j+1] = temp;   
            }
        }
    }*/

    for ( int i = 1; i < k; i++)
    {
        printf("%d ",c[i]);
    }
    

}