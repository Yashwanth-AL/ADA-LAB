#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Graph {
    int vertices;
    int edges;
    int *visit;
    struct Node **adjLists;
};

typedef struct Node *Node;

Node createnode(int n) {
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->info = n;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visit = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visit[i] = 0;
    }
    return graph;
}

int count = 0, iscyclic = 0;

void DFS(struct Graph* graph, int vertex, int parent) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    count++;
    graph->visit[vertex] = 1;
    printf("-->%c ", vertex + 65);

    while (temp != NULL) {
        int connectedVertex = temp->info;
        if (graph->visit[connectedVertex] == 1 && connectedVertex != parent) {
            iscyclic = 1;
        }
        if (graph->visit[connectedVertex] == 0) {
            DFS(graph, connectedVertex, vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    struct Graph* g = createGraph(n);
    Node temp;

    printf("Enter the adjacency list\n");
    for (int i = 0; i < g->vertices; i++) {
        printf("Enter 1 for the vertices adjacent to vertex %c\n", i + 65);
        for (int j = 0; j < g->vertices; j++) {
            if (i != g->vertices - j - 1) {
                Node newNode = createnode(g->vertices - j - 1);
                newNode->next = g->adjLists[i];
                g->adjLists[i] = newNode;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < g->vertices; i++) {
        temp = g->adjLists[i];
        printf("The vertices adjacent to %c: ", i + 65);
        while (temp != NULL) {
            printf("%c ", temp->info + 65);
            temp = temp->next;
        }
        printf("\n");
    }

    int dfscount = 0;
    printf("\nDFS traversal starting from node %c\n", 65);
    DFS(g, 0, -1);
    dfscount++;
    if (count == g->vertices)
        printf("\nThe graph is connected\n");
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

    if (iscyclic == 1) {
        printf("\nThe graph has a cycle\n");
    } else {
        printf("\nThe graph does not have a cycle\n");
    }

    return 0;
}
