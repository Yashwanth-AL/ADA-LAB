#include <stdio.h>
#include <stdlib.h>
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
        if (graph[start][i] && !visited[i]) {
            dfs(n, i);
        }
    }

    path[start] = 0;
    stack[++top] = start;
}

void reset(int n) { 
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        path[i] = 0;
    }
    top = -1;
    isCyclic = 0;
    op_count = 0;
}

void plotter(int type) {
    FILE *f1 = fopen("dfs_b.txt", "a");
    FILE *f2 = fopen("dfs_w.txt", "a");

    for (int v = 1; v <= 10; v++) {
        
        // Create the graph based on the input type
        for (int r = 0; r < v; r++) {
            for (int c = 0; c < v; c++) {
                if (type == 0) { // Best case: Dense graph (Complete graph)
                    graph[r][c] = (r != c) ? 1 : 0;
                } else { // Worst case: Sparse graph (Linear graph)
                    graph[r][c] = (c == r + 1) ? 1 : 0;
                }
            }
        }

        reset(v);

        // Perform DFS
        int count = 0;
        for (int j = 0; j < v; j++) {
            if (!visited[j]) {
                dfs(v, j);
            }
        }

        if (isCyclic) {
            count = -1; // Indicate a cycle
        }

        if (type == 0) {
            fprintf(f2, "%d\t%d\n", v, op_count);
        } else {
            fprintf(f1, "%d\t%d\n", v, op_count);
        }
    }
    
    fclose(f1);
    fclose(f2);
}

int main() {
    printf("Generating best case and worst case files...\n");
    plotter(0);
    plotter(1);
    return 0;
}
