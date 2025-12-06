// Program of Quick Sort.

#include<stdio.h>
#include<stdlib.h>

void display(int *, int , int , int);
void quick_sort(int list[], int first, int last)
{
    int temp, low, high, pivot;
    low = first;
    high = last;
    pivot = list[(first+last)/2];

    // printf("\n\n\n<-------------- Process ------------->\n\n\n");
    // display(list, first, high, pivot);
    // display(list, low, last, pivot);

    do
    {
        while (list[low] < pivot)
           low++;
        

        while (list[high] > pivot)
            high--;
        

        if (low <= high)
        {
            temp = list[low];
            list[low++] = list[high];
            list[high--] = temp;
        }
        
    } while (low <= high);
    
    if (first < high)
       quick_sort(list, first, high);

    if (low < last)
     quick_sort(list, low, last);

}

// Output function for process
    
void display(int list[], int low, int upper, int pivot)
{
    int k = 0;
    printf("\nDivided list is as follows.");
    printf("\nPivot is = %d",pivot);

    for (size_t k = low; k < upper; k++)
    {
        printf(" %d ",list[k]);
    }
    
}

int main()
{
    int list[1000], i, n;
    int first = 0, last;
    printf("\nInput number of element: ");
    scanf("%d",&n);

    printf("\nRandomly Generated unsort list is as follow:- ");
    last = n - 1;

    for (size_t i = 0; i < n; i++)
    {
        list[i] = rand() % 100;
        printf(" %d ", list[i]);
    }

    quick_sort(list , first, last);

    printf("\nSorted list as follows:- ");

    for (size_t i = 0; i < n; i++)
    {
        printf(" %d ",list[i]);
    }
    
    return 0;
}
