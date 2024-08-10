#include<stdio.h>
#include<stdlib.h>

int visited[100], graph[100][100];
int count = 0, op_count = 0;   //count is used to caluclate number of nodes visited in each call of the dfs function
int isCyclic = 0;

void dfs(int n, int start, int parent){
    visited[start] = 1;
    count++;
    printf("-->%c ", start + 65);

    for(int i = 0; i < n; i++){
        op_count++;
        if(i != parent && graph[start][i] && visited[i])
                isCyclic = 1;
        if(graph[start][i] && visited[i] == 0)
            dfs(n, i, start);
    }
}

void main() {

    int n, dfsCount = 0; //dfsCount is used to calculate number of connected components
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    printf("The adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nDFS traversal starting from node %c\n", 65);
    dfs(n, 0, -1);
    dfsCount++; 
    
    if (count == n)
        printf("The graph is connected\n");
    else {
        printf("The graph is not connected\n");
        int start = 1;
        while (count != n) {
            if (visited[start] != 1) {
                printf("\n");
                dfs(n, start, -1);
                dfsCount++;
            }
            start++;
        }
    }

    printf("The number of components is %d\n", dfsCount);

    if (isCyclic)
        printf("The graph is cyclic\n");
    else
        printf("The graph is not cyclic\n");
}

