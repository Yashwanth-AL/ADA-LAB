#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int n, i, j, arr[10][10], edgeCount = 0, visited[10], removed[10];
int heapSize = 0;

struct edge {
    int src;
    int dist;
    int dest;
} heap[10], result[10];

typedef struct edge edg;

// Min Heap function declaration
void swap(struct edge *a, struct edge *b) {
    struct edge temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct edge arr[], int n, int root) {
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left].dist < arr[smallest].dist)
        smallest = left;

    if (right < n && arr[right].dist < arr[smallest].dist)
        smallest = right;

    if (smallest != root) {
        swap(&arr[root], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(struct edge arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Min heap function declaration end
void makegraph() {
    // Make Graph
    printf("Enter the total number of vertices:");
    scanf("%d", &n);
    printf("Enter the cost matrix of the Graph\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0)
                arr[i][j] = INT_MAX;
        }
    }
}

// Returns the min of the heap
edg deleteheap(edg heap[]) {
    edg min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize = heapSize - 1;
    return min;
}

void prim() {
    // Appending Source vertex to heap and incrementing heap size
    visited[0] = 1;
    heap[heapSize].src = -1;
    heap[heapSize].dest = 0;
    heap[heapSize].dist = 0;
    heapSize++;

    while (edgeCount != n) {
        // Fetching the min and appending to the visited array of edges and deleting from heap
        edg min = deleteheap(heap);
        result[edgeCount].src = min.src;
        result[edgeCount].dest = min.dest;
        result[edgeCount].dist = min.dist;
        edgeCount++;

        int v = min.dest;
        removed[v] = 1;

        for (i = 1; i < n; i++) {
            if (!visited[i] && arr[v][i] != INT_MAX && !removed[i]) {
                // Not visited and not removed from heap
                visited[i] = 1;
                heap[heapSize].src = v;
                heap[heapSize].dest = i;
                heap[heapSize].dist = arr[v][i];
                heapSize++;
            }

            if (visited[i] && arr[v][i] != INT_MAX && !removed[i]) {
                // Visited but not removed from heap --> Scope for minimization?
                for (j = 0; j < heapSize; j++) {
                    // Finding that edge in the sorted heap
                    if (heap[j].dest == i && arr[v][i] < heap[j].dist) {
                        // Replacing if optimal
                        heap[j].dist = arr[v][i];
                        heap[j].src = v;
                        break;
                    }
                }
            }
        }

        heapSort(heap, heapSize); // Sorting after deletions and value modifications
    }
}

void main() {
    int sum = 0;
    makegraph();
    prim();

    for (int i = 1; i < edgeCount; i++) {
        printf("%c --> %c == %d\n", result[i].src + 65, result[i].dest + 65, result[i].dist);
        sum += result[i].dist;
    }

    printf("Minimum Distance is: %d", sum);
}
