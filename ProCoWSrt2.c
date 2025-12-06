// Program of Merge Sort.

#include<stdio.h>
#include<stdlib.h>

void merge_sort(float *, int , int , int );
void merge_pass(float *, int , int);

// Defination of the function

void merge_sort(float list[], int top, int n, int bottom)
{
    float temp[1000];
    int f = top;
    int s = n +1;
    int t = top;
    int upper;

    while ((f <= n) && (s <= bottom))
    {
        if (list[f] <= list[s])
        {
            temp[t] = list [f];
            f++;
        }else
        {
            temp[t] = list[s];
            s++;
        }
        t++;
        
    }
    
    if ( f <= n)
    {
        for (size_t f = f; f <= n; f++)
        {
            temp[t] = list[f];
            t++;
        }
        
    }else
    {
        for ( s = s; s <= bottom; s++)
        {
            temp[t] = list[s];
            t++;
        }
        
    }

    for ( upper = top; upper <= bottom; upper++)
    {
        list[upper] = temp[upper];
    }
 
}

// Defination of the function

void merge_pass(float append[], int m, int n)
{
    if ( m != n)
    {
        int mid = (m+n)/2;
        merge_pass(append , m , mid);
        merge_pass(append , mid+1 , n);
        merge_sort(append, m, mid, n);
    }
    
}

// Main Function

int main()
{
    float list[1000];
    int i, n;
    printf("\nInput number of element in the list ");
    scanf("%d",&n);

    for (size_t i = 0; i < n; i++)
    {
        list[i] = (float) (rand() % 100);
    }
    
    printf("\nEntered list as follows: ");

    for (size_t i = 0; i < n; i++)
    {
        printf(" %d ", (int) list[i]);
        
    }
    
    i = 0;

    merge_pass(list, i, n-1);

    printf("\nMerge sorted list is as follows: ");

    for (size_t i = 0; i < n; i++)
    {
        printf(" %d ",(int)list[i]);
    }
    
}
