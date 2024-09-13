#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int graph[MAX][MAX], visited[MAX], path[MAX];
int stack[MAX], top = -1;
int isCyclic = 0, op_count = 0;

void dfs(int n, int start) {
    visited[start] = 1;
    path[start] = 1;

    for (int i = 0; i < n; i++) {
        op_count++;
        if (graph[start][i] && visited[i] && path[i]) {
            isCyclic = 1;
        }
        if (graph[start][i] && visited[i] == 0) {
            dfs(n, i);
        }
    }

    path[start] = 0;
    stack[++top] = start;
}

void main() {
    int n;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
        path[i] = 0;
    }

    printf("\nTopological order:\n");
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(n, i);
        }
    }

    if (isCyclic) {
        printf("The graph has a cycle, so no topological order.\n");
        return;
    }

    for (int i = top; i >= 0; i--) {
        printf(" --> %c", stack[i] + 65);
    }
    printf("\n");
}
