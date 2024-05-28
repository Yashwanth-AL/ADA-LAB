#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSearch(int *a, int key, int n) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *a, int key, int low, int high) {
    int mid;
    if (low <= high) {
        mid = low + (high - low) / 2;
        if (*(a + mid) == key)
            return mid;
        else if (*(a + mid) > key) 
            return binarySearch(a, key, low, mid - 1);
        else
            return binarySearch(a, key, mid + 1, high);
    }
    return -1;
}

int main() {
    int n, key, index, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements into the array\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSearching algorithms\n");
    printf("1. Linear search.\n");
    printf("2. Binary search.\n");
    printf("0. Exit\n");
    do {
        printf("\nEnter your choice from the menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                index = linearSearch(arr, key, n);
                if (index != -1)
                    printf("Element found at index %d\n", index);
                else    
                    printf("Element not found\n");
                break;
            case 2:
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                index = binarySearch(arr, key, 0, n - 1);
                if (index != -1)
                    printf("Element found at index %d\n", index);
                else    
                    printf("Element not found\n");
                break;
        }
    } while (choice != 0);
    return 0;
}