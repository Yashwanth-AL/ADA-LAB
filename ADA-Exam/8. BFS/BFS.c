#include <stdio.h>
#include <stdlib.h>

int graph[100][100], visited[100];
int bfsCount = 0, isCyclic = 0;
int op_count = 0;
int count = 0; // to count how many vertices visited 

void bfs(int n, int start) {
    int queue[n], parent[n];
    int rear = -1, front = -1;
    visited[start] = 1; 
    count++;
    queue[++rear] = start;
    parent[rear] = -1;

    while (rear != front) {
        start = queue[++front];
        int parentNode = parent[front];
        printf("-->%c", start + 65);
        for (int i = 0; i < n; i++) {
            op_count++;
            if (i != parentNode && graph[start][i] && visited[i])
                isCyclic = 1;
            if (graph[start][i] && visited[i] == 0) {
                queue[++rear] = i;
                parent[rear] = start;
                visited[i] = 1;
                count++;
            }
        }
    }
}

void reset(int n) {
    // Reset the visited array and traversal-related counters
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    bfsCount = 0;
    isCyclic = 0;
    count = 0;
    op_count = 0;
}

void plotter(int type) {
    FILE *f1 = fopen(type == 0 ? "bfs_b.txt" : "bfs_w.txt", "a");

    for (int v = 1; v <= 10; v++) {
        //Create the graph based on the type
        for (int r = 0; r < v; r++) {
            for (int c = 0; c < v; c++) {
                if (type == 0) {  // Best case: Dense graph (Complete graph)
                    graph[r][c] = (r == c) ? 0 : 1;
                } else {  // Worst case: Sparse graph (Linear graph)
                    graph[r][c] = (c == r + 1) ? 1 : 0;
                }
            }
        }

        reset(v); // Reset data before traversal
        bfs(v, 0);

        if (count != v) {
            int start = 1;
            while (count != v) {
                if (visited[start] != 1) {
                    bfs(v, start);
                    bfsCount++;
                }
                start++;
            }
        }

        fprintf(f1, "%d\t%d\n", v, op_count);
    }

    fclose(f1);
}

void tester() {
    int n, i, j, start;
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("The Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    reset(n); // Reset data before traversal
    printf("Breadth First Search Traversal:\n");
    bfs(n, 0);
    bfsCount++;

    if (count == n) {
        printf("\nGraph is connected.\n");
    } else {
        printf("\nThe graph is not connected.\n");
        start = 1;
        while (count != n) {
            if (visited[start] != 1) {
                bfs(n, start);
                bfsCount++;
                printf("\n");
            }
            start++;
        }
    }

    printf("\nThe number of components in the graph is %d\n", bfsCount);
    if (isCyclic) {
        printf("\nThe graph is cyclic\n");
    } else {
        printf("\nThe graph is acyclic\n");
    }
}

int main() {
    while (1) {
        int key;
        printf("Enter your choice :\n1. TO TEST \n2. TO PLOT\nOTHER TO EXIT\n");
        scanf("%d", &key);
        
        switch (key) {
            case 1: 
                tester(); 
                break;
            case 2: 
                plotter(0); // Best case
                plotter(1); // Worst case
                printf("Text files generated.\n");
                break;
            default: 
                exit(1);
        } 
    }
}
