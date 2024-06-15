#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binarySearch(int *a, int key, int low, int high) {
    int mid;
    if (low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key) 
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
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    index = binarySearch(arr, key, 0, n - 1);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else    
        printf("Element not found\n");
return 0;
}