#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

int count; 

void selectionsort(int *a, int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int min = i; 
        for (int j = i + 1; j < n; j++) { 
            count++; 
            if (a[j] < a[min]) 
                min = j; 
        } 
        if (min != i) { 
            int temp = a[min]; 
            a[min] = a[i]; 
            a[i] = temp; 
        } 
    } 
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

    selectionsort(arr, n); 

    printf("The elements of the array after sorting\n");  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
    printf("\n"); 
    free(arr);
} 

void plotter() { 
    FILE *f = fopen("s.txt", "a"); 
    int n = 10; 
    while (n <= 30000) { 
        int *a = (int *)malloc(sizeof(int) * n); 
        for (int i = 0; i < n; i++) {  
            a[i] = i; 
        } 
        count = 0; 
        selectionsort(a, n); 
        fprintf(f, "%d\t%d\n", n, count); 
        printf("%d\t%d\n", n, count); 
        if (n < 10000) 
            n *= 10; 
        else 
            n += 10000;   
        free(a);
    } 
    fclose(f);
} 

void main() { 
    while(1){
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
