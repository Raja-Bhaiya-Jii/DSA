#include<stdio.h>
#define size 10
int q[size];
int r = -1, f = -1;

void insert(int v)
{
    if(r == size - 1)
    {
        printf("\nQuesue is Full.");
        return;
    }

    if (f == -1)
    {
        f = r = 0;
    }else
    {
        r++;
    }
    q[r] = v;
}

int delete()
{
    if (f == -1 || f > r)
    {
        printf("\nQueue is empty.");
        return -1;
    }

    int data = q[f++];
    
    if (f > r)
    {
        f = r = -1;
    }
    return data;
}

int isEmpty()
{
    return (f == -1 || f > r);
}

void bfs(int adj[size][size], int n_v, int start_ver)
{
    int visited[size] = {0};
    visited[start_ver] = 1;
    insert(start_ver);

    while (!isEmpty())
    {
        int curv = delete();
        printf("%d", curv);
        for (int i = 0; i < n_v; i++)
        {
            if (adj[curv][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                insert(i);
            }
        
        }
        
    }
    
}

int main()
{
    int adj[size][size], n_v, start_ver;
    printf("\nEnter the totel number of vertices: ");
    scanf("%d", &n_v);

    printf("\nEnter the element of the adjenceny matrix: ");

    for (int i = 0; i < n_v; i++)
    {
        for (int j = 0; j < n_v; j++)
        {
            scanf("%d", &adj[i][j]);
        }
        
    }
    
    printf("\nEnter the starting vertex: ");
    scanf("%d",&start_ver);

    printf("\nBFS started from vertex = %d",start_ver);
    bfs(adj, n_v, start_ver);

    return 0;
}

