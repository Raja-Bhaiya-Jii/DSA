// Program of Linked-List.

#include<stdio.h>
#include<malloc.h>

struct Link {
	int data;
	struct Link *next;
};

typedef struct Link Node;

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
		printf("\nEnter your Choice(No.) :- ");
		scanf("%d",&ch);
		
		switch (ch)
		{
		case 1:
			 insert(start);
			break;

		case 2:
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
	int node_no, ct;
	printf("\nEnter position of Node:- ");
	scanf("%d",&node_no);
	
	if (node_no == num)
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
				num--;
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
	}else if (node_no == 1)
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
	}else
	{
		Node *ctr, *ctr1;

		if (start != NULL)
		{
			ctr1 = start;
			ctr = start->next;
			ct = 1;
			while (ct < node_no && ctr != NULL)
			{
				ct++;
				ptr = ptr->next;
				ctr = ctr->next;
				if (ct > 2)
				{
				  ctr1 = ctr1->next;
				}
				  
			}
			if (ctr == NULL)
			{
				printf("Try again");
			}else
			{
				num--;
				ctr1->next = ptr->next;
				free(ptr);
			}
	    }else
		{
			printf("List is empty.");
		}		
	}	
}