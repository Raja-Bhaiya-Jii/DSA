// Program of doubly linked-list.

#include<stdio.h>
#include<malloc.h>

struct DLink
{
    struct DLink *prev;
    int data;
    struct DLink *next;
};

typedef struct DLink Dnode;

// Global declaration
int num;
Dnode *lp = NULL, *rp = NULL;

// Prototypes of various functions
void deleten(Dnode *);
void inserta(Dnode *);
void insertb(Dnode *);
void deletel(Dnode *);
void deletef(Dnode *);
void insertl(Dnode *);
void insertf(Dnode *);
void create(Dnode *);
void display(Dnode *);

// Function main
int main()
{   
    int ch;
    do
    {
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert first node");
        printf("\n4. Insert last node");
        printf("\n5. Delete first node");
        printf("\n6. Delete last node");
        printf("\n7. Insert before");
        printf("\n8. Insert after");
        printf("\n9. Delete element");
        printf("\nEnter:- ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            create(lp);
            break;
        
        case 2:
            display(lp);
            break;

        case 3:
            insertf(lp);
            break;

        case 4:
            insertl(rp);
            break;

        case 5:
             deletef(lp);
             break;
        
        case 6:
             deletel(rp);
             break;

        case 7:
             insertb(lp);
             break;

        case 8:
             inserta(lp);
             break;

        case 9:
             deleten(lp);
             break;
        
        default:
             ch = 0;
            break;
        }
        
    } while(ch != 0);
    return 0;
}

// Function Create

void create(Dnode *ptr)
{
    int ch;
    num = 0;
    if (ptr == NULL)
    {
     lp = (Dnode *)malloc(sizeof(Dnode));
     ptr = lp;   
    }
    
    lp->prev = NULL;
    do
    {
        printf("\n Input the values node %d: ",(num+1));
        scanf("%d",&ptr->data);

        printf("\nFor continue, Press 1: ");
        scanf("%d",&ch);
        if (ch == 1)
        {
            ptr->next = (Dnode *)malloc(sizeof(Dnode));
            ptr->next->prev = ptr;                           // Previous portion of (ptr->next)
            ptr = ptr->next;
        }
        num++;
        
    } while (ch == 1);

    ptr->next= NULL;
    rp = ptr;     // Assign the address of rightmost node to rp
    printf("\nTotal nodes:- %d",num);
    
}

// Function display 

void display(Dnode *ptr)
{
   while (ptr != NULL)                     // Traverse List
   {
    printf("\n%d", ptr->data);
    ptr = ptr->next;
   }

}


void insertf(Dnode *ptr)
{
    Dnode *new1;
    new1 = (Dnode *)malloc(sizeof(Dnode));
    printf("\nEnter data for 1st Node:- ");
    scanf("%d",&new1->data);
    if (ptr == NULL)
    {
        new1->prev = NULL;
        new1->next = NULL;
        lp = new1;
    }else
    {
        new1->prev = NULL;
        ptr->prev = new1;
        new1->next = ptr;
        lp = new1;
    }
}

void insertl(Dnode *ptr)
{
    Dnode *new1;
    new1 = (Dnode *)malloc(sizeof(Dnode));
    printf("\nEnter data for 1st Node:- ");
    scanf("%d",&new1->data);
    if (ptr == NULL)
    {
        new1->prev = NULL;
        new1->next = NULL;
        lp = new1;
        rp = new1;
    }else
    {
        new1->prev = ptr;
        new1->next = NULL;
        ptr->next = new1;
        rp = new1;
    }
}

void deletef(Dnode *ptr)
{
    if (ptr == NULL)
    {
        printf("\nList is empty.");
    }else if (lp == rp)
    {
        lp = NULL;
        rp = NULL;
        free(ptr);
    }else
    {
        lp = ptr->next;
        lp->prev = NULL;
        free(ptr);
    }
}

void deletel(Dnode *ptr)
{
    if (ptr == NULL)
    {
        printf("\nList is empty.");
    }else if (lp == rp)
    {
        lp = NULL;
        rp = NULL;
        free(ptr);
    }else
    {
        rp = ptr->prev;
        rp->next = NULL;
        free(ptr);
    }   
}

void insertb(Dnode *ptr)
{
    int ch, ct = 1;
    Dnode *new1;
    new1 = (Dnode *)malloc(sizeof(Dnode));
    
    printf("\nEnter element:- ");
    scanf("%d",&ch);

    while(ptr->data != ch && ptr != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("\n The element does not exist:- ");
        exit(0);
    }
    printf("\nEnter the value to insert: ");
    scanf("%d",&new1->data);

    if(ptr == lp)  // Insertion before first node
    {
        new1->next = ptr;
        new1->prev = NULL;
        ptr->prev = new1;
        lp = new1;
    }else
    {
        ptr->prev->next = new1;
        new1->prev = ptr->prev;
        new1->next = ptr;
        ptr->prev = new1;
    }

}

void inserta(Dnode *ptr)
{
     int ch, ct = 1;
    Dnode *new1;
    new1 = (Dnode *)malloc(sizeof(Dnode));
    
    printf("\nEnter element:- ");
    scanf("%d",&ch);

    while(ptr->data != ch && ptr != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("\n The element does not exist:- ");
        exit(0);
    }
    printf("\nEnter the value to insert: ");
    scanf("%d",&new1->data);

    if(ptr == lp)  // Insertion before first node
    {
       ptr->next = new1;
       new1->prev = ptr;
       new1->next = NULL;
       rp = new1;
    }else if (ptr->next == NULL)
    {
       ptr->next = new1;
       new1->prev = ptr;
       new1->next = NULL;
       rp = new1;
    }else
    {
        new1->next = ptr->next;
        ptr->next->prev =new1;
        ptr->next = new1;
        new1->prev = ptr;
    }
}

void deleten(Dnode *ptr)
{
   int search_data;

   printf("\nEnter element:- ");
   scanf("%d",&search_data);

   if ( ptr == NULL)
   {
        printf("\nList is empty.");
   }else
   {
        while (ptr != NULL && search_data != ptr->data)
        {
            ptr = ptr->next;
        }
    }
    if (ptr->prev == NULL && ptr->next == NULL)
    {
        lp = NULL;
        rp = NULL;
    }else if (ptr->prev == NULL)
    {
        lp = ptr->next;
        ptr->next->prev = NULL;
    }else if (ptr->next == NULL)
    {
        rp = ptr->prev;
        ptr->prev->next = NULL;
    }else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
}