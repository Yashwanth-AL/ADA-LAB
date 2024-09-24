#include <stdio.h>
#include <stdlib.h>

int heapCount = 0;
int graphCount = 0;
int n;

typedef struct pair { // edgeVal-vertices pair
    int u;   // current node
    int val; // cost of edge from v
    int v;   // parent node
} *Pair;

Pair createPair(int u, int val, int v) {
    Pair p = (Pair)malloc(sizeof(struct pair));
    p->u = u;
    p->val = val;
    p->v = v;
    return p;
}

typedef struct heap {
    Pair *arr;
    int size;
} *Heap;

Heap createHeap(int Pairs) {
    Heap heap = (Heap)malloc(sizeof(struct heap));
    heap->arr = (Pair *)malloc(Pairs * sizeof(struct pair));
    heap->size = 0;
    return heap;
}

void add(Heap heap, Pair e) {
    heap->arr[heap->size] = e;
    heap->size += 1;

    int x = heap->size - 1;
    int parIdx = (x - 1) / 2;

    while (x > 0 && heap->arr[x]->val < heap->arr[parIdx]->val) { // if children has less value than parent, swap
        Pair temp = heap->arr[x];
        heap->arr[x] = heap->arr[parIdx];
        heap->arr[parIdx] = temp;

        x = parIdx;
        parIdx = (x - 1) / 2;
    }
}

void heapify(Heap heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int minIdx = i;
    heapCount++;
    
    if (left < heap->size && heap->arr[minIdx]->val > heap->arr[left]->val) {
        minIdx = left;
    }

    if (right < heap->size && heap->arr[minIdx]->val > heap->arr[right]->val) {
        minIdx = right;
    }

    if (minIdx != i) {
        Pair temp = heap->arr[i];
        heap->arr[i] = heap->arr[minIdx];
        heap->arr[minIdx] = temp;

        heapify(heap, minIdx);
    }
}

Pair delete(Heap heap) {
    Pair minPair = heap->arr[0];

    // swap 1st and last index values of array to delete minimum edge
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size -= 1;

    heapify(heap, 0);
    return minPair;
}

int prims(int graph[n][n], int n) {
    int vis[n];
    int mst[n][3]; // store mst result in this array
    int finalCost = 0;

    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }

    int edges = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && graph[i][j] != 0) {
                edges++;
            }
        }
    }

    Heap heap = createHeap(edges);
    add(heap, createPair(0, 0, -1)); // Add the first pair starting from vertex 0 and having cost 0
    int idx = 0;

    while (heap->size != 0) {
        Pair cur = delete(heap);
        if (!vis[cur->u]) {
            vis[cur->u] = 1;
            mst[idx][0] = cur->v;
            mst[idx][1] = cur->u;
            mst[idx++][2] = cur->val;
            finalCost += cur->val;

            graphCount++;
            for (int i = 0; i < n; i++) {
                if (cur->u != i && graph[cur->u][i] != 0) {
                    graphCount++;
                    add(heap, createPair(i, graph[cur->u][i], cur->u));
                }
            }
        }
        free(cur);
    }

    printf("\nMST edges are: \n");
    for (int i = 1; i < n; i++) {
        printf("%d --> %d = %d\n", mst[i][0], mst[i][1], mst[i][2]);
    }

    return finalCost;
}

void tester() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (enter cost if edge is present, else -1): \n");
    int graph[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int finalCost = prims(graph, n);
    printf("\nMinimum cost of MST is: %d\n", finalCost);
}

int main() {
    FILE *f;
    f = fopen("prims.txt", "a");
    int choice;

    while (1) {
        printf("\n1- Tester\n0- Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                tester();
                fprintf(f, "%d\t%d\n", n, graphCount > heapCount ? graphCount : heapCount);
            default:
                return 0;
        }
    }
}
