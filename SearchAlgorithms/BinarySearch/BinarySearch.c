#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

int binarySearch(int *a, int key, int low, int high) {
    int mid;
    count++;
    mid = (high + low) / 2;

    if (low > high)
        return count - 1;
    if (a[mid] == key)
        return count;
    else if (a[mid] > key)
        return binarySearch(a, key, low, mid - 1);
    else
        return binarySearch(a, key, mid + 1, high);
}
    
void main() {
    srand(time(NULL));
    int *arr, key, r, n = 5;
    FILE *f1, *f2, *f3;
    f1 = fopen("b_b.txt", "a");
    f2 = fopen("b_a.txt", "a");
    f3 = fopen("b_w.txt", "a");

    while (n <= 1024) {
        arr = (int *)malloc(n * sizeof(int));
        
        //best-Case
        count = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = 1;
        }
        int mid = (n - 1) / 4;
        arr[mid] = 0;
        r = binarySearch(arr, 0, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, r);

        //Average-Case
        count = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % n;
        }   
        r = binarySearch(arr, -1, 0, n-1);
        fprintf(f2, "%d\t%d\n", n, r);

        //Worst-case
        count = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
        r = binarySearch(arr, 1, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n ,r);

        n = n * 2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}