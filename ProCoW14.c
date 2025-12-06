// Program for reversed an array.
#include<stdio.h>
int main()
{
    int a[100], idx, i, b[100];
    printf("Enter the size:- ");
    scanf("%d",&idx);
    printf("\nEnter-\n");
    for ( i = 0; i < idx; i++)
    {
        scanf("%d",&a[i]);
        b[idx-i-1] = a[i];
    }
    printf("\nReversed Array-\n");
    for ( i = 0; i < idx; i++)
    {
        printf("\n%d", b[i]);
    }
    
}