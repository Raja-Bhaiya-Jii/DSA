// Linked list with dynamic node.

#include<stdio.h>
#include<malloc.h>
struct Link
{
    int data;
    struct Link *next;
};
typedef struct Link Node;

Node *start = NULL;


void delfirst(Node *);
void insert(Node *);
void disp(Node *);
void insertfirst();

int main()
{
    int ch;
    start = (Node *)malloc(sizeof(Node));

    insert(start);
    disp(start);
    insertfirst();
    disp(start);
    delfirst(start);
    disp(start);
    return 0;
}

void insert(Node *ptr)
{
    int data, ch = 0;
    do
    {
        printf("Enter Your Data:- ");
        scanf("%d",&ptr->data);
        printf("For Continue, Press 1:- ");
        scanf("%d",&ch);
        if (ch == 1)
        {
            ptr->next = (Node *)malloc(sizeof(Node));  //  Maybe malloc(sizeof(Node))              Try
            ptr = ptr->next;
        }
        
    } while (ch == 1);
    ptr->next = NULL;  
}

void disp(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

void insertfirst()
{
    Node *nn;
    nn= (Node *)malloc(sizeof(Node));
    printf("Enter data:- ");
    scanf("%d",&nn->data);
    if (start == NULL)
    {
        start = nn;
        nn->next = NULL;
    }else
    {
        nn->next = start;
        start = nn;
    }    
}

void delfirst(Node *ptr)
{
    if (start == NULL)
    {
        printf("\nList is Empty.");
    }else
    {
        start = ptr->next;
        free(ptr);
    }    
}



