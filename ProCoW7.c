#include <stdio.h>
int main()
{
    int i, n[100], k, s = 0, l = 0, temp = 0;
    printf("Enter the size:- ");
    scanf("%d", &k);
    printf("Enter the elements of array\n");
    for (i = 0; i < k; i++)
    {
        scanf("%d", &n[i]);
    }
    for (i = 0; i < k; i++)
    {
        if (n[i] > n[i + 1])
        {
            temp = n[i];
            n[i] = n[i + 1];
            n[i + 1] = n[i];
        }
    }
    printf("\nMaximum Element:-%d", n[k - 1]);
    printf("\nMinimum Element:-%d", n[0]);
    for (i = 0; i < k; i++)
    {

        if (n[i] < 0)
        {
            s += n[i];
        }
        else if (n[i] > 0)
        {
            l += n[i];
        }
    }
    printf("\nSum of Negetive :- %d\n", s);
    printf("Sum of Positive :- %d\n", l);
    printf("\nOdd element- \n");
    for (i = 0; i < k; i++)
    {

        if (n[i] % 2 != 0)
        {
            printf("%d\n", n[i]);
        }
    }
    printf("\nEven element- \n");
    for (i = 0; i < k; i++)
    {

        if (n[i] % 2 == 0)
        {
            printf("%d\n", n[i]);
        }
    }

    return 0;
}