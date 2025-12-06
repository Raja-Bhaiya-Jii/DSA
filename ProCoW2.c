// Address change by pointer.

#include <stdio.h>
int main()
{
    int *p;
    int a[] = {1, 2, 3, 4, 5};
    p = a;
    for (int i = 0; i < 5; i++)
    {
        printf("%u\t", *p + i);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%u\t", p + i);
    }
    return 0;
}