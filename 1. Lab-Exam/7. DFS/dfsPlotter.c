#include <stdio.h>
#include <stdlib.h>

int graph[100][100], visited[100];
int op_count = 0, dfsCount = 0, count = 0;
int isCyclic = 0;

void dfs(int n, int start, int parent) {
    visited[start] = 1;
    count++;
    for (int i = 0; i < n; i++) {   
        op_count++;
        if (i != parent && graph[start][i] && visited[i])
            isCyclic = 1;
        if (graph[start][i] && visited[i] == 0)
            dfs(n, i, start);
    }
}

void plotter(int type) {

    FILE *f1 = fopen("dfs_b.txt", "a");
    FILE *f2 = fopen("dfs_w.txt", "a");

    int vertices;
    for (int i = 1; i <= 10; i++) {

        vertices = i;
        
        if (type == 0) { //Creates a complete graph
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (i == j)
                        graph[i][j] = 0;
                    else
                        graph[i][j] = 1;
                }
                visited[i] = 0;
            }
        }
        
        if (type == 1) { //Creates a linear graph
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++)
                    graph[i][j] = 0;
                visited[i] = 0;
            }
            for (int i = 0; i < vertices - 1; i++) {
                graph[i][i + 1] = 1;
            }
        }

        isCyclic = dfsCount = count = op_count = 0;
        dfs(vertices, 0, -1);
        dfsCount++;

        int start = 1;
        while (count != vertices) {
            if (visited[start] != 1) {
                dfs(vertices, start, -1);
                dfsCount++;
            }
            start++;
        }

        if (type == 0)
            fprintf(f2, "%d\t%d\n", vertices, op_count);
        else
            fprintf(f1, "%d\t%d\n", vertices, op_count);
    }

    fclose(f1);
    fclose(f2);
}

void main() {
    for (int i = 0; i < 2; i++)
        plotter(i);
    printf("Data entered into the file\n");
}