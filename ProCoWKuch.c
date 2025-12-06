#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data, pn;
    struct node *next;
};

typedef struct node Node;

Node *f = NULL;

void insert(int data, int pn)
{
    Node *temp , *p;
    temp = (Node)malloc(sizeof(Node));
    temp->data = data;
    temp->pn = pn;
    temp->next = NULL;

    if (f == NULL || pn < f->pn)
    {
        temp->next = f;
        f = temp;
    }else
    {
        p = f;
        while (p->next != NULL && p->next->pn <= pn)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
        
    }
    
    
}

void display()
{
    Node *temp = f;
    if (f == NULL)
    {
        printf("\nQueue is empty.\n");
    }

    while (temp != NULL)
    {
        printf("\nPriority: %d, Data: %d\n", temp->pn, temp->data);
        temp = temp->next;
    }
    
    
}

int main()
{
    int a, data, pn;
    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Exit");
        printf("\nEnter Choice (No.):- ");
        scanf("%d",&a);

        switch (a)
        {
        case 1:
            printf("\nEnter the data:- ");
            scanf("%d",&data);
            printf("\nEnter the priority:- ");
            scanf("%d",&pn);
            insert(data, pn);
            break;
        
        case 2:
            display();
            break;

        case 3:
            exit(0);

        default:
            printf("\nInvalid choice.\n");
            break;
        }
    }
    
}
