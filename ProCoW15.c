// Program for sorting an array by create function of pointer.
#include<stdio.h>
void Bubsot(int a[], int n)
{
    int *p = a;
    for ( int i = 0; i < n; i++)
    {
        for ( int j = 0; j < n-i-1; j++)
        {
            if(*(p+j) > *(p+j+1))
            {
                int temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }
        }
        
    }
    for ( int i = 0; i < n; i++)
    {
        printf("%d ",*(p+i));
    }
        
}

int main()
{
    int a[100], ch, i, j, temp;
    printf("Enter the size:- ");
    scanf("%d",&ch);
    printf("\nEnter- ");
    for ( i = 0; i < ch; i++)
    {
        scanf("%d",&a[i]);
    }
    Bubsot(a,ch);
    
}