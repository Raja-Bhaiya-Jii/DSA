#include<stdio.h>
#define SIZE 10
int f = -1, r = -1, que[SIZE];

void insert();
void del();
void show();

int main()
{
    int ch;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Show");
        printf("\n3. Delete");
        printf("\nEnter Choice (No.):- ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        
        case 2:
            show();
            break;

        case 3:
            del();
            break;

        default:
            ch = 0;
            break;
        }
    } while (ch != 0);

    return 0;
}

void insert()
{
    if (r == SIZE-1)
    {
        printf("\nQueue is overflow.\n");
    }else
    {
       
        r++;
        printf("\nEnter %d:- ",r+1);
        scanf("%d",&que[r]);
        if (f == -1)
        {
            f = 0;
        }
    
    }
       
}


void show()
{
    int i;
    if (r == -1)
    {
       printf("\nQueue is Empty.\n"); 
    }else
    {
       for ( i = f; i <= r; i++)
       {
         printf(" %d ",que[i]);
       }
        
    }
       
}

void del()
{
    int  i;
    if (f == -1)
    {
        printf("\nQueue is Empty.\n"); 
    }else
    {
        if (f == r)
       {
          f = -1;
          r = -1;
       }else
       {
        for ( i = 0; i < r; i++)
        {
            que[i] = que[i+1];
        }
        r--;
       }    
    }
    
    
}