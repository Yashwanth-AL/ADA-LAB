#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
                    op_count++;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

// Create a graph with random edge weights
void createGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = rand() % 10 + 1; // Random edge weight between 1 and 10
            }
        }
    }
}

int main() {
    srand(time(NULL));
    FILE *f1 = fopen("floyd.txt", "a"); 

    for (int n = 1; n <= 10; n++) {
        createGraph(n);
        op_count = 0;
        floyds(n);
        fprintf(f1, "%d\t%d\n", n, op_count); 
    }
    fclose(f1); 
    printf("text files generated successfully\n");
    return 0;
}
