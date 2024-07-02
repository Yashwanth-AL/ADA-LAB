#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count, count2 = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void heapify(int *heap, int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n ) {
        count++;
        if (heap[left] > heap[largest]) {
            largest = left;
        }
    }

    if (right < n ) {
        count++;
        if (heap[right] > heap[largest]) {
            largest = right;
        }
    }

    if (largest != root) {
        swap(&heap[root], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void heapSort(int *heap, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }

    count2 = count;
    count = 0;

    for (int i = n - 1; i >= 0; i--) {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }
}

int max(int a, int b) {
    int temp = a > b ? a : b;
    return temp;
}

void plotter() {
    int *arr, n;
    srand(time(NULL));
    FILE *f1, *f2, *f3;
 
    f1 = fopen("heap_b.txt", "a");
    f2 = fopen("heap_w.txt", "a");
    f3 = fopen("heap_a.txt", "a");

    n = 100;

    while (n <= 1000) {
        arr = (int *)malloc(sizeof(int) * (n + 1));

        // Best case
        for (int i = 0; i < n; i++)
            arr[i] = n - i + 1;

        count = 0;
        heapSort(arr, n);
        count = max(count, count2);
        fprintf(f1, "%d\t%d\n", n, count);

        // Worst case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        heapSort(arr, n);
        count = max(count, count2);
        fprintf(f2, "%d\t%d\n", n, count);

        // Average case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;

        heapSort(arr, n);
        count = max(count, count2);
        fprintf(f3, "%d\t%d\n", n, count);

        n += 100;
        free(arr);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void main() {
    plotter();
    printf("THE DATA ENTERED INTO THE FILE\n");
}
