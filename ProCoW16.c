// Program for Print element in deffrent types.
#include<stdio.h>
int main()
{
    int a[3][3], i, j, k = 4, n;
    printf("\nEnter- \n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }    
    }
    
    // Left diagonal
    printf("\nLeft Diagonal-\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if (i==j)
            {
                printf("%d",a[i][j]);
            }else
            {
                printf(" ");
            }
            
            
        }
        printf("\n");
        
    }

    // Right Diagonal
    printf("\nRight Diagonal-\n");
   for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if (i+j == 2)
            {
                printf("%d",a[i][j]);
            }else
            {
                printf(" ");
            }
            
            
        }
        printf("\n");   
    }
    
    // Down Triangel
   
    printf("\nDown triangle.\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
         if (i > j)
         {
            printf("%d  ",a[i][j]);
              
         }
         else
         {
           printf("   ");
             
         }    
        }
        printf("\n");   
    }
    
}