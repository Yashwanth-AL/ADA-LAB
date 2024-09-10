#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int op_count; 

void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int *arr, int beg, int end) { 
    int pivot = arr[beg];  
    int i = beg, j = end + 1; 
    while (i <= j) { 
        do { 
            op_count++; 
            i++; 
        } while (arr[i] <= pivot); 
        do { 
            op_count++; 
            j--; 
        } while (arr[j] > pivot); 
        if(i <= j){
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[beg], &arr[j]); 
    return j; 
}

void quicksort(int *arr, int beg, int end) { 
    if (beg < end) { 
        int split = partition(arr, beg, end); 
        quicksort(arr, beg, split - 1); 
        quicksort(arr, split + 1, end); 
    } 
}

void main() { 
    int *arr, n; 
    printf("enter the number of elements\n"); 
    scanf("%d", &n); 
    arr = (int *)malloc(sizeof(int) * n); 
    printf("enter the elements of the array\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
    printf("the elements of the array before sorting\n");  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
    quicksort(arr, 0, n - 1); 
    printf("the elements of the array after sorting\n");  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
    free(arr); 
}
