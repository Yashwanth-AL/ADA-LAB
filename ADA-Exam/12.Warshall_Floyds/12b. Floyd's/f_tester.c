#include <stdio.h>
#include <stdlib.h>

#define MAX 40

int graph[MAX][MAX], op_count = 0;

int min(int a, int b) {
    return a < b ? a : b;
}

void floyds(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) { 
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    op_count++;
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (use value > 1000 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floyds(n);

    printf("All pair shortest path matrix:\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(graph[i][j] > 1000){
                printf("INF\t");              
            }else{
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }
    printf("Operation count: %d\n", op_count);

    return 0;
}
