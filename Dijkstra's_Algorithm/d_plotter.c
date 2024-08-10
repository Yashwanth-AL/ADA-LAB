#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int n, i, j, src, cost[10][10], d[10] = {0}, removed[10] = {0}, count = 0;
int heapsize;
int graphcount, heapcount, max;

struct vertex {
    int id;
    int dist;
} heap[10];

typedef struct vertex ver;

// Min Heap function declaration
void swap(struct vertex *a, struct vertex *b) {
    struct vertex temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct vertex arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    heapcount++;

    if (left < n && arr[left].dist < arr[smallest].dist)
        smallest = left;

    if (right < n && arr[right].dist < arr[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildHeap(struct vertex arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Min heap function declaration end

void makegraph() {
    // Make Graph
    printf("Enter the total number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix of the Graph\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) // No self-loops; 0 means no edge
                cost[i][j] = INT_MAX;
        }
    }

    // Initialize the source vertex distance to 0 and rest all to infinity (INT_MAX)
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) {
        d[i] = INT_MAX;
        removed[i] = 0;
    }
    d[src] = 0;
}

// Returns the min of the heap and heapifies the rest of the elements
ver deleteMin(ver heap[]) {
    ver min = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize--;
    heapify(heap, heapsize, 0);
    return min;
}

void dijkstra() {
    for (i = 0; i < n; i++) {
        heap[i].id = i;
        heap[i].dist = INT_MAX;
    }

    heap[src].dist = 0;
    heapsize = n;

    // Build min-heap
    buildHeap(heap, heapsize);

    while (count < n) {
        ver minvertex = deleteMin(heap);
        int u = minvertex.id;
        removed[u] = 1;
        count++;

        for (i = 0; i < n; i++) {
            if (!removed[i] && cost[u][i] != INT_MAX) {
                graphcount++;
                if (d[u] + cost[u][i] < d[i]) {
                    d[i] = d[u] + cost[u][i];

                    for (int o = 0; o < heapsize; o++) {
                        if (heap[o].id == i) {
                            heap[o].dist = d[i];
                            break;
                        }
                    }

                    // Rebuild heap after distance update
                    buildHeap(heap, heapsize);
                }
            }
        }
    }
}

void run() {
    makegraph();
    max = 0;
    graphcount = 0;
    heapcount = 0;
    count = 0;

    dijkstra();

    printf("Shortest paths from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (src != i)
            printf("%d -> %d = %d\n", src, i, d[i]);
    }

    max = (graphcount > heapcount) ? graphcount : heapcount;
    printf("Operation count = %d\n", max);
}

int main() {
    FILE *f1;
    f1 = fopen("dijkstrasgraph.txt", "a"); // Open the file once before the loop

    int ch;
    while (1) {
        printf("Enter choice: 1 to continue, 0 to exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            run();
            fprintf(f1, "%d\t%d\n", n, max); // Write to the file inside the loop after each run
        } else {
            break; // Exit the loop
        }
    }

    fclose(f1); // Close the file after the loop ends
    return 0;
}
