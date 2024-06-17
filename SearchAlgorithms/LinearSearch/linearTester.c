#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSearch(int *a, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) == key) {
            return i;
        }
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
    index = linearSearch(arr, n, key);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else    
        printf("Element not found\n");
return 0;
}