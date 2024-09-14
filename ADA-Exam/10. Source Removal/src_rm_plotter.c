#include <stdio.h>
#include <stdlib.h>

int graph[100][100], topo[100], indegree[100], visited[100];
int queue[100], front, rear, count;
int op_count = 0;  


void calculateIndegree(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            op_count++;  
            if (graph[j][i] == 1)
                indegree[i]++;
        }
        if (indegree[i] == 0) {
            rear = (rear + 1) % vertices;
            queue[rear] = i;
            count++;
            visited[i] = 1;
        }
    }
}

void removeSourceVertices(int vertices) {
    int k = 0;
    while (count != 0) {
        int src = queue[front];
        front = (front + 1) % vertices;
        topo[k++] = src;
        count--;
        
        for (int i = 0; i < vertices; i++) {
            op_count++;  
            if (graph[src][i] == 1)
                indegree[i]--;
            if (indegree[i] == 0 && visited[i] == 0) {
                rear = (rear + 1) % vertices;
                queue[rear] = i;
                count++;
                visited[i] = 1;
            }
        }
    }
}

void reset(int vertices) {
    front = 0;
    rear = -1;
    count = 0;
    for (int i = 0; i < vertices; i++) {
        topo[i] = 0;
        indegree[i] = 0;
        visited[i] = 0;
    }
    op_count = 0;
}

void plotter(int type) {
    FILE *f1 = fopen("src_b.txt", "a");
    FILE *f2 = fopen("src_w.txt", "a");

    for (int v = 1; v <= 10; v++) {  

        for (int r = 0; r < v; r++) {
            for (int c = 0; c < v; c++) {
                if (type == 0) {  // Best case: Dense graph
                    graph[r][c] = (r != c) ? 1 : 0;
                } else {  // Worst case: Sparse graph
                    graph[r][c] = (c == r + 1) ? 1 : 0;
                }
            }
        }

        reset(v);
        calculateIndegree(v);
        removeSourceVertices(v);

        if (type == 0) {
            fprintf(f1, "%d\t%d\n", v, op_count);
        } else {
            fprintf(f2, "%d\t%d\n", v, op_count);
        }
    }

    fclose(f1);
    fclose(f2);
}

int main() {
    printf("Generating best case and worst case files...\n");
    plotter(0);  // Best case
    plotter(1);  // Worst case
    return 0;
}
