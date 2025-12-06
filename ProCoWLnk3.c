// Program of Simple Linked-List.

#include<stdio.h>
#include<malloc.h>

struct Link {
	int data;
	struct Link *next;
};

typedef struct Link Node;

void reverse(Node *);
void selsort(Node *);
void deldta(Node *);
void delete(Node *);
void dellast(Node *);
void delfirst(Node *);
void insertNode(Node *);
void insertLast(Node *);
void insertfirst(Node *);
void insert(Node *);
void display(Node *);

Node *start = NULL;
int num;

int main()
{
	int ch;
	
	do
	{
		printf("\n1. Create: ");
		printf("\n2. Display: ");
		printf("\n3. Insert First: ");
		printf("\n4. Insert Last: ");
		printf("\n5. Insert: ");
		printf("\n6. Delete first: ");
		printf("\n7. Delete Last: ");
        printf("\n8. Delete: ");
		printf("\n9. Delete by value.");
		printf("\n10. Sort(selection):- ");
		printf("\n11. Reverse: ");
		printf("\nEnter your Choice(No.) :- ");
		scanf("%d",&ch);
		
		switch (ch)
		{
		case 1:
			 insert(start);
			break;

		case 2:
		     printf("\nNo. of Node:- %d ",num);
		     printf("\n created list is as follows:\n");
		     display(start);
			break;
		
		case 3:
		     insertfirst(start);
			 break;

		case 4:
		     insertLast(start);
			 break;

		case 5:
		     insertNode(start);
			 break;

		case 6:
		     delfirst(start);
			 break;

		case 7:
		     dellast(start);
			 break;

		case 8:
		     delete(start);
			 break;

		case 9:
		     deldta(start);
			 break;

		case 10:
		     selsort(start);
			 break;

		case 11:
		     reverse(start);
			 break;
		
		default:
		     ch = 0;
			break;
		}
	} while (ch != 0);
	return 0;
}

void insert(Node *ptr)
{
	int ch;
	num = 0;

	if (start == NULL)
	{
		start = (Node *)malloc(sizeof(Node));
		ptr = start;
	}
	
	do
	{
		printf("Enter data %d :- ",(num+1));
		scanf("%d",&ptr->data);
		printf("For continue, Press 1:- ");
		scanf("%d",&ch);

		if (ch == 1)
		{
		  
			ptr->next = (Node *)malloc(sizeof(Node));
			ptr = ptr->next;
		}
		num++;
	}while(ch == 1);

	ptr->next = NULL;
	printf("\n Total nodes = %d\n",num);
}

void display(Node *show)
{
	while(show != NULL)
	{
		printf("%d\n",show->data);
		show = show->next;
	}
}

void insertfirst(Node *ptr)
{
	Node *new1;
	
	new1 = (Node *)malloc(sizeof(Node));
	printf("Enter data on 1st node:- ");
	scanf("%d",&new1->data);

    if (start == NULL)
	{
		new1->next = NULL;
		start = new1;
		num++;	
	}else
	{
		new1->next = start;
		start = new1;
		num++;
	}
}

void insertLast(Node *ptr)
{
	Node *last;

	last = (Node *)malloc(sizeof(Node));
	printf("Enter data for last node:- ");
	scanf("%d",&last->data);

	if (start == NULL)
	{
		last->next = NULL;
		start = last;
		num++;
	}else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = last;
		last->next = NULL;
		num++;
	}
}

void insertNode(Node *ptr)
{
	Node *noden;
	int node_no, ct;

	noden = (Node *)malloc(sizeof(Node));
	printf("\nEnter position of Node:- ");
	scanf("%d",&node_no);
	printf("\nEnter data for this node:- ");
	scanf("%d",&noden->data);
	
	if (node_no == num)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		num++;
		ptr->next = noden;
		noden->next = NULL;
	}else if (node_no == 1)
	{
		if (start == NULL)
		{
			noden->next = NULL;
			start = noden;
			num++;	
		}else
		{
			noden->next = start;
			start = noden;
			num++;
		}
	}else
	{
		ct = 2;

		while (ct < node_no && ptr != NULL)
		{
			ct++;
			ptr = ptr->next;
		}
		if (ptr == NULL)
		{
			printf("Try again");
		}else
		{
			num++;
			noden->next = ptr->next;
			ptr->next = noden;
		}	
	}	
}

void delfirst(Node *ptr)
{
    if (start == NULL)
    {
        printf("\nList is Empty.");
    }else
    {
		num--;
        start = ptr->next;
        free(ptr);
    }    
}

void dellast(Node *ptr)
{
	Node *prv;
	prv = NULL;
    if (start == NULL)
    {
         printf("\nList is Empty.");
    }else if (start->next == NULL)
	{
		free(ptr);
		start = NULL;
	}else
	{
		while (ptr->next != NULL)
		{
			prv = ptr;
			ptr = ptr->next;
		}
		prv->next = NULL;
		free(ptr);
	}
}
void dellast(Node *ptr)
{
	int ch = 2;
	Node *cnt;
	cnt = start;

	if (start == NULL)
    {
        printf("\nList is Empty.");
    }else
    {
		if (num <= 2)
		{
			cnt = ptr->next;
			free(cnt);
			ptr->next = NULL;
		}else
		{
			while (ch < num)
		    {
				ch++;
				ptr = ptr->next;
			}
			num--;
			cnt = ptr->next;
			free(cnt);
			ptr->next = NULL;
		}	
    }   
}

void delete(Node *ptr)
{
	if (node_no == num)             // For last node delete.
	{
		int ch = 2;
		Node *cnt;
		cnt = start;

		if (start == NULL)            // - For Only one node delete. -
		{
			printf("\nList is Empty.");
		}else                        // - For more than one node delete. -
		{
			if (num <= 2)             // -> For only two node delete. <-
			{
				num--;
				cnt = ptr->next;
				free(cnt);
				ptr->next = NULL;
			}else                      // -> For more than two node delete. <-
			{
				while (ch < num)
				{
					ch++;
					ptr = ptr->next;
				}
				num--;
				cnt = ptr->next;
				free(cnt);
				ptr->next = NULL;
			}	
		}   
	}else if (node_no == 1)        // For first node delete.
	{
		if (start == NULL)
		{
			printf("\nList is Empty.");
		}else
		{
			num--;
			start = ptr->next;
			free(ptr);
		}    
	}else if (node_no != 1)       // For Delete.
	{
		Node *ctr1;

		if (start != NULL)
		{
			ctr1 = start;
			ct = 1;
			while (ct < node_no && ptr != NULL)
			{
				ct++;
				ptr = ptr->next;
				if (ct > 2)
				{
				  ctr1 = ctr1->next;
				}
				  
			}
			if (ptr == NULL)
			{
				printf("Try again");
			}else
			{
				num--;
				ctr1->next = ptr->next;
				free(ptr);
			}
	    }else                       // For empty list delete.
		{
			printf("List is empty.");
		}			
	}	
}

void deldta(Node *ptr)
{
	Node *prv;
	int dta, ct = 1;
	printf("Enter value:- ");
	scanf("%d",&dta);

	if (start == NULL)
	{
		printf("\nList is empty.");
	}else
	{
		while (dta != ptr->data && ptr != NULL)
		{
			
			prv = ptr;
			ptr = ptr->next;
			ct++;
			if(ct==1)
			{
				start = ptr->next;
			}else if (ptr->next == NULL)
			{
				prv->next = ptr->next;
			}else if (ptr == NULL)
			{
				printf("\nInvalid Input.");
			}else
			{
				prv->next = ptr->next;
			}
			free(ptr);	
		}
		
	}	
}

void selsort(Node *ptr)
{
	Node *temp;
	int x;

	for ( ; ptr->next != NULL; ptr = ptr->next)
	{
		for ( temp = ptr->next; temp != NULL; temp = temp->next)
		{
			if (ptr->data > temp->data)
			{
				x = ptr->data;
				ptr->data = temp->data;
				temp->data = x;
			}
			
		}
		
	}
	
}

void reverse(Node *ptr)
{
	Node *curr , *prv = NULL;
	curr = ptr->next;
	while (curr != NULL)
	{
		ptr->next = prv;
		prv = ptr;
		ptr = curr;
		curr = curr->next;
	}
	ptr->next = prv;
	start = ptr;
	
}