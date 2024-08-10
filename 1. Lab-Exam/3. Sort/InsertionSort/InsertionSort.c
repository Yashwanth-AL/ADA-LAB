#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

int count; 

void insertionSort(int *arr, int n) { 
    count = 0; 
    for (int i = 1; i < n; i++) { 
        int value = arr[i]; 
        int j; 
        for (j = i - 1; j >= 0 && arr[j] > value; j--) { 
            arr[j + 1] = arr[j]; 
            count++;
        } 
        arr[j + 1] = value; 
        count++;
    }
} 

void plotter() { 
    int *arr, n = 10; 
    srand(time(NULL)); 
    FILE *f1, *f2, *f3; 
  
    f1 = fopen("i_b.txt", "a"); 
    f2 = fopen("i_w.txt", "a"); 
    f3 = fopen("i_a.txt", "a"); 

    while (n <= 30000) { 
        arr = (int *)malloc(sizeof(int) * n); 
 
        // best case 
        count = 0; 
        for (int i = 0; i < n; i++) 
           arr[i] = i + 1; 
        insertionSort(arr, n); 
        fprintf(f1, "%d\t%d\n", n, count); 
        
        // worst case 
        count = 0;
        for (int i = 0; i < n; i++) 
            arr[i] = n - i; 
        insertionSort(arr, n); 
        fprintf(f2, "%d\t%d\n", n, count); 

        // avg case 
        for (int i = 0; i < n; i++) 
            arr[i] = rand() % n; 
        count = 0; 
        insertionSort(arr, n); 
        fprintf(f3, "%d\t%d\n", n, count); 

        if (n < 10000) 
            n = n * 10; 
        else 
            n = n + 10000; 

        free(arr); 
    } 
    fclose(f1); 
    fclose(f2); 
    fclose(f3); 
} 

void tester() { 
    int *arr, n; 
    printf("Enter the number of elements\n"); 
    scanf("%d", &n); 
 
    arr = (int *)malloc(sizeof(int) * n); 
    printf("Enter the elements of the array\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    printf("The elements of the array before sorting\n");  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
 
    insertionSort(arr, n); 
 
    printf("The elements of the array after sorting\n");  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
    free(arr);
} 

void main() { 
    for (;;) { 
        int key; 
        printf("Enter the choice \n1. To Test \n2. To Plot\n0. To Exit\n"); 
        scanf("%d", &key); 
          
        switch (key) { 
            case 1: 
                tester(); 
                break; 
            case 2: 
                plotter(); 
                break; 
            default: 
                exit(1); 
        }  
    } 
}
