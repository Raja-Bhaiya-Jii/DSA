// Program for insert an element.
#include <stdio.h>
void RR(int a[], int idx, int ch)
{
    int i, temp, j,n = 100;
    if (ch < 0 || ch > n)
    {
        printf("\nEnter valid Index No. .");
    }
    else
    {
        for (i = ch; i > 0; i--)
        {
            temp = a[idx];
            for (j = idx - 1; j > 0; j--)
            {
                a[j] = a[j - 1];
            }
            a[0] = temp;
        }
    }
}
void Print(int a[], int idx)
{
    int i;
    for (i = 0; i <= idx; i++)
    {
        printf("%d", a[i]);
    }
}

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
    printf("\nEnter the number of element for rotation:- ");
    scanf("%d", &ch);
    RR(a, idx, ch);
    Print(a, idx);

    return 0;
}