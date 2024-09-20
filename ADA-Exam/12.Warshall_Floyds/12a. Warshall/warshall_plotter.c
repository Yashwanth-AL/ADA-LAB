#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int op_count = 0;

void warshall(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                op_count++;
            }
        }
    }
}

void ploter(int type) {
    FILE *f1 = fopen("w_b.txt", "a"); // File for sparse graph
    FILE *f2 = fopen("w_w.txt", "a"); // File for dense graph

    for (int n = 1; n <= 10; n++) {
       
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (type == 1) { // Dense graph
                    graph[r][c] = (r != c) ? 1 : 0;
                } else { // Sparse graph
                    graph[r][c] = (r == c + 1 || (r == 0 && c == n - 1)) ? 1 : 0;
                }
            }
        }

        op_count = 0;
        warshall(n);

        // Write results to the appropriate file
        if (type == 0) {
            fprintf(f1, "%d\t%d\n", n, op_count); // Sparse graph
        } else {
            fprintf(f2, "%d\t%d\n", n, op_count); // Dense graph
        }
    }

    fclose(f1);
    fclose(f2);
}

int main() {
    printf("Generating best case and worst case files...\n");
    ploter(0); // Sparse graph
    ploter(1); // Dense graph
    printf("The graph is plotted\n");
    return 0;
}
