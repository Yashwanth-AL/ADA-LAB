#include <stdio.h>

int graph[40][40], n, count = 0;

void createGraph() {
    printf("No. of vertices>> ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void main() {
    createGraph();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (graph[i][k] == 1) {
                for (int j = 0; j < n; j++) {
                    count++;
                    if (graph[k][j] == 1) {
                        graph[i][j] = 1;
                    }
                }
            }
        }
    }

    printf("Applying Warshall's Algorithm\n");
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("Operation Count: %d\n", count);
}
