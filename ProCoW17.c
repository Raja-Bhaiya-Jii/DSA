// Program for Check Identity and Sparce Matrix.
#include <stdio.h>
int main()
{
    int a[3][3], i, j, ch = 0, ch1 = 0;
    printf("\nEnter- \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Check Identity Matrix.
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j && a[i][j] == 1)
            {
                ++ch;
            }
            else if (i != j && a[i][j] == 0)
            {
                ++ch;
            }
        }
    }
    if (ch == 9)
    {
        printf("\nEnter matrix is 'Identity Matrix'.");
    }else
    {
        printf("\nEnter matrix is not 'Identity Matrix'.");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
            {
               ++ch1; 
            }
            
        }
    }
    if (ch1 >= ((3*3)/2))
    {
        printf("\nIt's a Sparse matrix.");
    }else
    {
        printf("\nIt is not a Sparse matrix.");
    }    
}
