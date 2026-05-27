#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int visited[MAX];
int graph[MAX][MAX];
int n;

void push(int v)
{
    stack[++top] = v;
}

/* DFS function */
void DFS(int v)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }

    push(v);
}

void topologicalSort()
{
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }

    printf("Topological Ordering:\n");

    while(top != -1)
    {
        printf("%d ", stack[top--]);
    }
}

int main()
{
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");

    for(int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();

    return 0;
}
