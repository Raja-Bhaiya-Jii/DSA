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
    int data;

    printf("\nEnter %d:- ",r+1);
    scanf("%d",&data);

    if ( r == SIZE-1 && f == 0) 
    {
        printf("\nQueue is not empty.");
    }else if (r == f-1)
    {
        printf("\nQueue is not empty.");
    }else if ( r == SIZE - 1)
    {
        r = 0;
        que[r] = data;
    }else
    {
        r = r + 1;
        que[r] = data;

        if (f == -1)
        {
            f = 0;
        }
        
    }

}

void show()
{
    if (f == -1)
    {
        printf("\nQueue is Empty.\n");
    }else if ( r < f)
    {
        for (size_t i = f; i < SIZE-1; i++)
        {
            printf(" %d ",que[i]);
        }

        for (size_t i = 0; i <= r; i++)
        {
            printf(" %d ",que[i]);
        }
        
    }else
    {
        for (size_t i = 0; i <= r; i++)
        {
            printf(" %d ",que[i]);
        }
        
    }
    
}

void del()
{
    if ( f == -1)
    {
        printf("\nQueue is Empty.\n");
    }else if (f == r)
    {
        printf("\nDeleted Element is %d.",que[f]);
        que[f] = 0;
        f = -1;
        r = -1;
    }else if ( f == SIZE-1)
    {
        printf("\nDeleted element is %d.",que[f]);
        que[f] = 0;
        f = 0;
    }else
    {
        printf("\nDeleted element is %d.",que[f]);
        que[f] = 0;
        f = f + 1;
    }
    
    
    
}
