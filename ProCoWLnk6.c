#include<stdio.h>
#include<stdlib.h>

struct Link
{
    struct Link *previous;
    int pos;
    int data;
    struct Link *next;
};

struct Link2
{
    struct Link *previous;
    int pos;
    int data;
    struct Link *next; 
};

typedef struct Link Node;
typedef struct Link2 Node2;

Node *lp = NULL, *rp = NULL;
Node2 *lp2 = NULL, *rp2 = NULL;
int pos = 1, pos2 = 1;

void merge(Node *, Node2 *);
void Create2(Node2 *);
void Create1(Node *);
// void Display(Node *);
// void Find(Node *);
void Inter(Node *, Node2 *);

int main()
{
    int ch;

    do
    {
        printf("\n1. Create First list");
        printf("\n2. Create Second list");
        // printf("\n3. Display");
        // printf("\n4. Find");
        printf("\n5. InterSection Node(No.):- ");
        scanf("%d",&ch);


        switch (ch)
        {
        case 1:
            Create1(lp);
            break;
        
        case 2:
            Create2(lp2);
            merge(lp, rp2);
            break;
        
        // case 3:
        //     Display(lp);
        //     break;

        // case 4:
        //     Find(lp);
        //     break;

        case 5:
           Inter(rp, rp2);
           break;

        default:
            ch = 0;
            break;
        }
    } while (ch != 0);
    
}

void Create1(Node *ptr)
{
    int ch, dta;
    if (ptr == NULL)
    {
        ptr = (Node *)malloc(sizeof(Node));
        lp = ptr;
    }

    do
    {
       printf("\nEnter data %d:- ",pos);
       scanf("%d",&dta);
       printf("\nFor Continue, Press 1:- ");
       scanf("%d",&ch);
       ptr->pos = pos;
       pos = pos + 1;
       if (ch == 1)
       {
         ptr->next = (Node *)malloc(sizeof(Node));
         ptr = ptr->next;
       }else
       {
         ch = 0;
       }
       
       
    } while (ch != 0);
    
    rp = ptr;
}

void merge(Node *ptr, Node2 *ptr2)
{
    while (ptr->pos != 5)
    {
        ptr = ptr->next;
    }
    ptr2->next = ptr;
}


void Create2(Node2 *ptr2)
{
    int ch2, dta2;
    if (ptr2 == NULL)
    {
        ptr2 = (Node2 *)malloc(sizeof(Node2));
        lp2 = ptr2;
    }

    do
    {
       printf("\nEnter data %d:- ",pos2);
       scanf("%d",&dta2);
       printf("\nFor Continue, Press 1:- ");
       scanf("%d",&ch2);
       ptr2->pos = pos2;
       pos2 = pos2 + 1;
       if (ch2 == 1)
       {
         ptr2->next= (Node *)malloc(sizeof(Node));
         ptr2 = ptr2->next;
       }else
       {
         ch2 = 0;
       }
       
       
    } while (ch2 != 0);
    
}

void Inter(Node *ptr, Node2 *ptr2)
{
    while (ptr == ptr2)
    {
        ptr = ptr->previous;
        ptr2 = ptr2->previous;
    }
    printf("\nPosition: %d",ptr->pos);
}