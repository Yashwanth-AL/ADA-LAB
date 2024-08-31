#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int op_count, count = 0;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int *arr, int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n) {
        op_count++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        op_count++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    count = op_count;
    op_count = 0;

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void main() {
    int *arr, n;

    printf("enter the number of elements\n");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    printf("enter the elements of the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("the elements of the array before sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, n);

    printf("the elements of the array after sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}
