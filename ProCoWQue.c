// Program of Queue (Using Simple linked-list).

#include<stdio.h>
#include<malloc.h>

struct Stack
{
    int data;
    struct Stack *next;
};

typedef struct Stack Node;

Node *start = NULL;

void insert(Node *);
void delvel(Node *);
void delete(Node *);
void create(Node *);
void display(Node *);

int main()
{
    int ch = 0;
    do
    {
        printf("\n\n1. Create");
        printf("\n2. Display");
        printf("\n3. Dequque");
        printf("\n4. Delete element");
        printf("\n5. Enquque");
        printf("\nEnter:- ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            create(start);
            break;
        
        case 2:
            display(start);
            break;

        case 3:
            delete(start);
            break;

        case 4:
            delvel(start);
            break;

        case 5:
            insert(start);
            break;

        default:
            ch = 0;
            break;
        }

    } while (ch != 0);
    
    return 0;
}


void create(Node *ptr)
{
    int ch = 0;
    if (start == NULL)
    {
        start = (Node *)malloc(sizeof(Node));
        ptr = start;
    }
    do
    {
        printf("\nEnter data:- ");
        scanf("%d",&ptr->data);
        printf("\nFor Continue, Press 1:- ");
        scanf("%d",&ch);
        
        if (ch == 1)
        {
            ptr->next = (Node *)malloc(sizeof(Node));
            ptr = ptr->next;  
        }  
    } while (ch == 1);
  
    ptr->next = NULL;
  
}

void display(Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\nList is Empty.\n");
    }else
    {
        while (ptr != NULL)
        {
            printf(" %d ",ptr->data);
            ptr = ptr->next;
        }  
    }  
}

void delete(Node *ptr)
{
   
   if (ptr == NULL)
   {
     printf("\nList is empty.\n");
   }else if (ptr->next == NULL)
   {
     start = NULL;
   }else
   {
    start = ptr->next;
   }   
   free(ptr);
}

void delvel(Node *ptr)
{
    Node *prv = NULL;
    int dta;

    printf("\nEnter Value:- ");
    scanf("%d",&dta);
   
    if (ptr == NULL)
    {
      printf("\nList is empty.\n");
    }else if (ptr->next == NULL)
    {
      start = ptr->next;
      free(ptr);
    }else
    {
      while (ptr->data != dta && ptr->next != NULL)
      {
         prv = ptr;
         ptr = ptr->next;
      }
      if (prv != NULL)
      {
         prv->next = ptr->next; 
         free(ptr);
      }else
      {
         prv = ptr;
         ptr = ptr->next;
         start = ptr;
         free(prv);
      }
      
    }   
}

void insert(Node *ptr)
{
    Node *new1;

    new1 = (Node *)malloc(sizeof(Node));

    printf("\nEnter Value:- ");
    scanf("%d",&new1->data);

    if (ptr == NULL)
    {
        start = new1;
    }else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new1;
    }   
    new1->next = NULL;   
}