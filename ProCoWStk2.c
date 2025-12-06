// Program of Stack (Using Array).

#include<stdio.h>

#define SIZE 10
int top = -1, stk[SIZE];

void delcho();
void update();
void pick();
void push();
void display();
void pop();

int main()
{
    int ch;
    do
    {
        printf("\n\n1. Push");
        printf("\n2. Display");
        printf("\n3. Pop");
        printf("\n4. Pick");
        printf("\n5. Update");
        printf("\n6. Peep");
        printf("\nEnter No.:- ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                push();
                break;

            case 2:
                display();
                break;

            case 3:
                pop();
                break;
            
            case 4:
                pick();
                break;

            case 5:
               update();
               break;

            case 6:
               delcho();
               break;

            default:
                ch = 0;
                break;
        }

    } while (ch != 0);

    return 0;
}

void push()
{
    int data;

    if (top == SIZE-1)
    {
        printf("\nStack is overflow (Not Empty).");
    }else
    {
        top++;
        printf("\nEnter Value:- ");
        scanf("%d",&data);
        stk[top] = data;
    }

}

void display()
{
    int ch;
    ch = top;
    if (ch == -1)
    {
        printf("\nStack is empty.\n");
    }else
    {
        while (ch != -1)
        {
            printf("\n%d",stk[ch]);
            ch--;
        }
        
    }
    
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }else
    {
        top--;
    }
    
}

void pick()
{
    int n, k;
    printf("\nEnter no.:- ");
    scanf("%d",&n);
    if (top == -1)
    {
        printf("\nStack is empty.");
    }else if (n > top+1 || n < 1)
    {
        printf("\nInvalid Choice.");
    }else
    {
        k = top - n + 1;
        printf("%d",stk[k]);  
    }
    
}

void update()
{
    int n, k, data;
    printf("\nEnter no.:- ");
    scanf("%d",&n);
    if (top == -1)
    {
        printf("\nStack is empty.");
    }else if (n > top+1 || n < 1)
    {
        printf("\nInvalid Choice.");
    }else
    {
        k = top - n + 1;
        printf("\nEnter new data:- ");
        scanf("%d",&data);
        stk[k] = data;  
    }

}

void delcho()
{
    int ch, ch2, i = top, ch3 ,new[top+1];
     
    printf("\nEnter Position:- ");
    scanf("%d",&ch);
    ch2 = top;
    ch3 = top;
    while (ch3 >= 0)
    {
        if (ch2 != top - ch + 1)
        {
           new[top-ch3] = stk[ch2];
           ch2--;
           ch3--;  
        }else
        {
            ch2--;
        }   
    }
    
   
    ch = 0;
    if (ch == -1)
    {
        printf("\nStack is empty.\n");
    }else
    {
        while (ch <= top - 1)
        {
            printf("\n%d",new[ch]);
            ch++;
        }
        
    }
}