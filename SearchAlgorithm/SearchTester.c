#include <stdio.h> 
#include <stdlib.h> 

int linearSearch(int *a, int n, int key) { 
    for (int i = 0; i < n; i++) { 
        if (a[i] == key) { 
            return i; 
        } 
    } 
    return -1; 
} 

int binarySearch(int *a, int low, int high, int key) { 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
        if (a[mid] == key) 
            return mid; 
        else if (a[mid] > key) 
            high = mid - 1; 
        else 
            low = mid + 1; 
    } 
    return -1; 
} 

void inputArray(int *a, int n) {
    printf("ENTER THE ELEMENTS OF THE ARRAY\n"); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &a[i]); 
    }
}

void sortArray(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() { 
    int arr[100]; 
    int n, key, result, ch; 

    while (1) { 
        printf("1. TO LINEAR SEARCH\n2. TO BINARY SEARCH\n3. TO EXIT\n"); 
        scanf("%d", &ch); 

        if (ch == 3) break;

        printf("ENTER THE NUMBER OF ELEMENTS\n"); 
        scanf("%d", &n); 
        inputArray(arr, n);

        printf("ENTER THE KEY ELEMENT\n"); 
        scanf("%d", &key); 

        switch (ch) { 
            case 1: 
                result = linearSearch(arr, n, key); 
                break; 
            case 2: 
                sortArray(arr, n); 
                result = binarySearch(arr, 0, n - 1, key); 
                break; 
            default: 
                continue; 
        } 

        if (result != -1) { 
            printf("The element is present at the index %d\n", result); 
        } else { 
            printf("Element not found\n"); 
        } 
    } 
    return 0; 
}