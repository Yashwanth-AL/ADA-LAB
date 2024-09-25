#include <stdio.h>
#include <limits.h>  

int n;               
int arr[15][15];  // adjacency matrix
int path[15];   // Shortest path set
int dist[15]; // Distances from source
int vertex;      // Source vertex

void readInput() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix of the Graph:\n");
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
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

    // Initialize distances and shortest path set
    for (int i = 0; i < n; i++) {  
        path[i] = 0;
        dist[i] = arr[vertex][i];
    }
    path[vertex] = 1;
    dist[vertex] = 0;

    for (int i = 1; i < n; i++) {  // Loop starts from 1 because vertex is already included
        int k, min = INT_MAX;

        // Find the vertex with the smallest distance
        for (int j = 0; j < n; j++) {  
            if (path[j] == 0 && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }

        path[k] = 1;

        // Update distances to adjacent vertices
        for (int j = 0; j < n; j++) {
            if (path[j] == 0 && arr[k][j] != INT_MAX) {
                int newDistance = dist[k] + arr[k][j];
                dist[j] = newDistance < dist[j] ? newDistance : dist[j];
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
