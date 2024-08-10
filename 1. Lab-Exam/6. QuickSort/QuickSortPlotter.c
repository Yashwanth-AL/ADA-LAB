#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

int count; 

void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int *arr, int beg, int end) { 
    int pivot = arr[beg];  
    int i = beg, j = end + 1; 
    do { 
        do { 
            count++; 
            i++; 
        } while(arr[i] < pivot); 
        do { 
            count++; 
            j--; 
        } while(arr[j] > pivot); 
        swap(&arr[i], &arr[j]); 
    } while(i < j); 

    swap(&arr[i], &arr[j]); 
    swap(&arr[beg], &arr[j]); 
    return j; 
}

void quicksort(int *arr, int beg, int end) { 
    if(beg < end) { 
        int split = partition(arr, beg, end); 
        quicksort(arr, beg, split - 1); 
        quicksort(arr, split + 1, end); 
    } 
}

void main() { 
    int *arr, n = 4; 
    srand(time(NULL)); 
    FILE *f1, *f2, *f3; 
    f1 = fopen("q_b.txt", "a"); 
    f2 = fopen("q_w.txt", "a"); 
    f3 = fopen("q_a.txt", "a"); 
    while(n < 1034) { 
        arr = (int *)malloc(sizeof(int) * n); 

        // Best case 
        count = 0; 
        for(int i = 0; i < n; i++) 
            arr[i] = 5; 
        quicksort(arr, 0, n - 1); 
        fprintf(f1, "%d\t%d\n", n, count);  
        
        // Worst case 
        count = 0; 
        for(int i = 0; i < n; i++) 
            arr[i] = i + 1; 
        quicksort(arr, 0, n - 1); 
        fprintf(f2, "%d\t%d\n", n, count); 
        
        // Average case 
        count = 0; 
        for(int i = 0; i < n; i++) 
            arr[i] = rand() % n; 
        quicksort(arr, 0, n - 1); 
        fprintf(f3, "%d\t%d\n", n, count);
        
        n *= 2; 
        free(arr); 
    } 
    fclose(f1); 
    fclose(f2); 
    fclose(f3); 
}
