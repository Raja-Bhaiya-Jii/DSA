#include<stdio.h>
int main()
{
    int k,n[100],i,temp;
 printf("Enter the size:- ");
    scanf("%d", &k);
    printf("Enter the elements of array\n");
    for (i = 0; i < k; i++)
    {
        scanf("%d", &n[i]);
    }
    for (i = 0; i < k; i++)
    {
        if (n[i] > n[i+1])
        {
         temp = n[i];
         n[i] = n[i+1];
         n[i+1] = temp;
        }
    }
    printf("Max:- %d", n[k-1]);
    printf("\nMin:- %d", n[k-2]);
    return 0;
}