#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct Graph
{
    int vertices;
    int edges;
    int *visit;
    struct node **adjLists;
};

typedef struct node Node;
typedef struct Graph Graph;

Node *createnode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjLists = (Node **)malloc(vertices * sizeof(Node));
    graph->visit = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visit[i] = 0;
    }
    return graph;
}

int count = 0, iscyclic = 0;

void DFS(struct Graph *graph, int vertex, int parent)
{
    Node *temp = graph->adjLists[vertex];

    count++;
    graph->visit[vertex] = 1;
    printf("-->%c ", vertex + 65);

    while (temp != NULL)
    {
        int connectedVertex = temp->data;
        if (connectedVertex != parent && graph->visit[connectedVertex] == 1)
        {
            iscyclic = 1;
        }
        if (graph->visit[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex, vertex);
        }
        temp = temp->link;
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    struct Graph *g = createGraph(n);

    printf("Enter the adjacency list \n");
    for (int i = 0; i < g->vertices; i++)
    {
        printf("Enter 1 for the vertices adjacent to vertex %c\n", i + 65);
        for (int j = 0; j < g->vertices; j++)
        {
            int key;
            printf("Is vertex %c adjacent to vertex %c (1 for yes, 0 for no): ", i + 65, j + 65);
            scanf("%d", &key);
            if (key == 1)
            {
                Node *newNode = createnode(j);
                newNode->link = g->adjLists[i];
                g->adjLists[i] = newNode;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < g->vertices; i++)
    {
        Node *temp = g->adjLists[i];
        printf("The vertex adjaacent to %c : ", i + 65);
        while (temp != NULL)
        {
            printf("%c ", temp->data + 65);
            temp = temp->link;
        }
        printf("\n");
    }

    int dfscount = 0;
    printf("\nDFS Traversal starting from Node %c\n", 65);
    DFS(g, 0, -1);
    dfscount++;
    if (count == g->vertices) {
        printf("\nThe graph is connected.\n");
    }
    else {
        printf("\nThe graph is not connected\n");
        int start = 1;
        while (count != g->vertices) {
            if (g->visit[start] != 1) {
                printf("\n");
                DFS(g, start, -1);
                dfscount++;
            }
            start++;
        }
    }

    if (iscyclic == 1)
        printf("\nThe graph has a cycle\n");
    else
        printf("\nThe graph doesn't have a cycle.\n");

    return 0;
}