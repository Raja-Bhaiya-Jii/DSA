// Program for insert an element.
#include <stdio.h>
int main()
{
    int a[100], i, n, ch, idx, s = 100;
    printf("Enter the size:- ");
    scanf("%d", &n);
    idx = n - 1;
    printf("\nEnter element\n");
    for (i = 0; i < n; i++)
    {

        scanf("%d", &a[i]);
    }
    printf("\nEnter the new element.");
    printf("\nIndex No. :- ");
    scanf("%d", &ch);
    if (ch < 0 || ch > s)
    {
        printf("\nEnter valid Index No. .");
    }
    else
    {
        idx += 1;
        for (i = idx; i >= ch; i--)
        {
            a[i] = a[i - 1];
        }
        printf("\nEnter:- ");
        scanf("%d", &a[ch]);
    }
    for (i = 0; i < idx+1; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}