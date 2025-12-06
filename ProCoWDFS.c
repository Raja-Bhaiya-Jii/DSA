#include<stdio.h>

int graph[10][10], visited[10], total;

// Stack implementation
int stack[10], top = -1;

void push(int v)
{
    top++;
    stack[top] = v;
}

int pop()
{
    int data = stack[top];
    top--;
    return data;
}

int isEmpty()
{
    return top == -1;
}

// DFS using stack

void dfs_stack(int start)
{
    push(start);

    while (!isEmpty())
    {
        int vertex = pop();

        if (!visited[vertex])
        {
            printf("%d ", vertex);
            visited[vertex] = 1;

            // Push adjacent vertices in reverse order to match recursion behavior
            for (int j = total - 1; j >=  0; j--)
            {
                if (graph[vertex][j] == 1 && !visited[j])
                {
                    push(j);
                }
                
            }
            
        }
        
    }
    
}

int main()
{
    int i, j, v;

    printf("\nEnter the total number of vertices: ");
    scanf("%d",&total);

    printf("\nEnter the adjacency matrix: ");
    for ( i = 0; i < total; i++)
    {
        for ( j = 0; j < total; j++)
        {
            scanf("%d",&graph[i][j]);
        }
        
    }
    
    for ( i = 0; i < total; i++)
    {
        visited[i] = 0; 
    }
    
    printf("\nEnter the starting vertex (0 to %d): ", total - 1);
    scanf("%d",&v);

    if (v >= 0 && v < total)
    {
        printf("\nDFS traversal using stack: ");
        dfs_stack(v);
    }else
    {
        printf("\nInvalid starting vertex.");
    }
    
    return 0;
}