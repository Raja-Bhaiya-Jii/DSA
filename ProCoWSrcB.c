// Program of binary search.

#include<stdio.h>
int main()
{
    int x[20], n , a, b, first, last, mid, item, i, j, temp;

    printf("\nEnter size of array element:- ");
    scanf("%d",&n);

    

    for (size_t a = 0; a < n; a++)
    {
        printf("\nEnter %d:- ",a+1);
        scanf("%d",&x[a]);
    }

    // Bubble Shorting

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n-1; j++)
        {
            if (x[j] > x[j+1])
            {
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
            
        }
        
    }

    printf("\nEnter item for search:- ");
    scanf("%d",&item);
    
    // Binary Search

    first = 0; last = n-1;

    while (first <= last)
    {
        mid = (first + last)/2;

        if (x[mid] == item)
        {
            printf("\nItem is Found.");
            break;
        }

        if (item < x[mid])
        {
            last = mid - 1;
        }else
        {
            first = mid + 1;
        }
        
        
    }

    if (first > last)
    {
        printf("\nItem is not found.\n");
    }
    
    
    return 0;
}