#include<stdio.h>
#include<malloc.h>

struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
};

typedef struct NODE Noden;

Noden *insert_node(int, Noden *);
Noden *Create_Tree(int, Noden *);
void Output(Noden *, int);
int find(int , Noden *);

// Function to create a tree

Noden *Create_Tree(int data, Noden *Node)
{
    if (Node == NULL)
    {
        Node = (Noden *)malloc(sizeof(Noden));
        
        Node->data = data;
        Node->left = NULL;
        Node->right = NULL;
        return(Node);
    }
    
    // Test for the left child

    if (Node->data >= data)
    {
        Node->left = Create_Tree(data, Node->left);
    }else
    {
        Node->right = Create_Tree(data, Node->right);
    }
    return(Node);
    
}


// Insert Function

Noden *insert_node(int data, Noden *Node)
{
    if (Node == NULL)
    {
        Node = (Noden *)malloc(sizeof(Noden));
        
        Node->data = data;
        Node->left = NULL;
        Node->right = NULL;
        return(Node);
    }
    
    // Test for the left child

    if (Node->data >= data)
    {
        Node->left = Create_Tree(data, Node->left);
    }else
    {
        Node->right = Create_Tree(data, Node->right);
    }
    return(Node);
}

// Output function

void Output(Noden *T, int Level)
{
    int i;
    if (T)
    {
        Output(T->right, Level+1);
        printf("\n");
        for ( i = 0; i < Level; i++)
            printf("      ");
            
        printf("%d",T->data);
        printf("\n");

        Output(T->left, Level+1);
            
    }
    
}

int find(int data, Noden *T)
{
    if (T == NULL)
    {
        return 0;
    }else if (data < T->data)
    {
        return find(data, T->left);
    }else if (T->data < data)
    {
        return find(data, T->right);
    }else
    {
        return data;
    }
   
}


// Function main

int main()
{
    int data, dta,t, ch;
    char choice;

    Noden *T = (Noden *)malloc(sizeof(Noden *));
    T = NULL;
    do
    {
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert");
        printf("\n4. Find");
        printf("\n5. Enter:- ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                    printf("\nInput information of the node: ");
                    scanf("%d",&data);
                    T = Create_Tree(data, T);
                    printf("\nRoot = %d",T->data);
                        
                break;
            
            case 2:
                printf("\n Tree is ");
                Output(T, 1);
                break;

            case 3:
                    printf("\nInput information of the node: ");
                    scanf("%d",&data);
                    T = Create_Tree(data, T);
                    printf("\nRoot = %d",T->data);
                break;

            case 4:
                printf("\nFind: ");
                scanf("%d",&dta);
                 t = find(dta, T);
                if (t == 0)
                {
                    printf("\n%d not found.",dta);
                }else
                {
                    printf("\n%d found.",dta);
                }
                break;

            default:
                choice = 'b';
                break;
        }
  
    } while (ch != 0);    
   
    return 0;
}