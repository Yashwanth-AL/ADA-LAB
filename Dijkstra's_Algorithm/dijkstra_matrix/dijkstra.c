#include <stdio.h>
#include <limits.h>  

int n;               
int arr[15][15];  // Adjacency matrix
int path[15];   // Shortest path set
int dist[15]; // Distances from source
int vertex;      // Source vertex

void readInput() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix of the Graph:\n");
    for (int i = 0; i < n; i++) {  // Loop starts from 0
        for (int j = 0; j < n; j++) {  // Loop starts from 0
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0 && i != j) {
                arr[i][j] = INT_MAX;  // Set to infinity if there is no edge
            }
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &vertex);
}

void dijkstra() {
    int cur, adj, min;

    // Initialize distances and shortest path set
    for (int i = 0; i < n; i++) {  
        path[i] = 0;
        dist[i] = arr[vertex][i];
    }

    path[vertex] = 1;
    dist[vertex] = 0;

    for (int num = 1; num < n; num++) {  // Loop starts from 1 because vertex is already included
        min = INT_MAX;

        // Find the vertex with the smallest distance
        for (adj = 0; adj < n; adj++) {  
            if (path[adj] == 0 && dist[adj] < min) {
                min = dist[adj];
                cur = adj;
            }
        }

        path[cur] = 1;

        // Update distances to adjacent vertices
        for (adj = 0; adj < n; adj++) {   
            if (path[adj] == 0 && arr[cur][adj] != INT_MAX && dist[cur] != INT_MAX && dist[adj] > (dist[cur] + arr[cur][adj])) {
                dist[adj] = (dist[cur] + arr[cur][adj]);
            }
        }
    }
}

int main() {
    readInput();
    dijkstra();

    printf("Shortest paths from vertex %d:\n", vertex);
    for (int i = 0; i < n; i++) {  
        if (i != vertex) {  // Skip the source vertex
            if (dist[i] == INT_MAX) {
                printf("%d -> %d = INF\n", vertex, i);
            } else {
                printf("%d -> %d = %d\n", vertex, i, dist[i]);
            }
        }
    }

    return 0;
}
