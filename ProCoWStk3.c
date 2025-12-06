#include<stdio.h>
#include<malloc.h>

struct link
{
    int data;
    struct link *next;
} *start;

typedef struct link Node;

void display(Node *);
Node *push(Node *);
Node *pop(Node *);


void display(Node *rec)
{
    while (rec != NULL)
    {
        printf("\n%d",rec->data);
        rec = rec->next;
    }
    
}

Node *push(Node *ptr)
{
    Node *new_rec;
    new_rec = (Node *)malloc(sizeof(Node));
    printf("\nInput the new value for next location of the stack:- ");
    scanf("%d",&new_rec->data);
    new_rec->next = ptr;
    ptr = new_rec;
    return(ptr);
}

Node *pop(Node *rec)
{
    Node *temp;

    if (rec == NULL)
    {
        printf("\nStack is empty.");
    }else
    {
        temp = rec->next;
        free(rec);
        rec = temp;
        printf("\nAfter pop operation the stack is as follows:- \n");
        if (rec != NULL)
        {
            display(rec);
        }else
        {
            printf("\nStack is empty.");
        }
        
       
    }
    return(rec);
    
}

int main()
{
    int choice;
    start = NULL;
    do
    {
        do
        {
            printf("\n 1<-Push ");
            printf("\n 2<-Pop");
            printf("\n 3<-Quit");
            printf("\nEnter:- ");
            scanf("%d",&choice);
            if (choice < 1 || choice > 3)
            {
                printf("\nIncorrect choice -> try Again.");
            }
            
        } while (choice < 1 || choice > 3);
        
        switch (choice)
        {
        case 1:
            start = push(start);
            printf("\nStack is as follows: \n");
            display(start);
            break;
        
        case 2:
            start = pop(start);
            break;

        default:
            choice = 3;
            printf("\nEnd of Session.");
            break;
        }
    } while (choice != 3);
    
    return 0;
}