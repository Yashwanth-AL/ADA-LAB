#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

int linearSearch(int *a, int n, int key) {
    int i;
    count = 0;
    for (i = 0; i < n; i++) {
        count++;
        if (a[i] == key) {
            return count;
        }
    }
    return count;
}
    
void main() {
    srand(time(NULL));
    int *arr, n, key, r; 
    FILE *f1, *f2, *f3;
    f1 = fopen("l_b.txt", "a");
    f2 = fopen("l_a.txt", "a");
    f3 = fopen("l_w.txt", "a");
    n = 5;

    while (n <= 1024) {
        arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            *(arr + i) = 1;
        }   
        r = linearSearch(arr, n, 1);
        fprintf(f1, "%d\t%d\n", n, r);

        for (int i = 0; i < n; i++) {
            *(arr + i) = rand() % n;
        }
        key = *(arr + (n - 1) / 2);
        r = linearSearch(arr, n, key);
        fprintf(f2, "%d\t%d\n", n, r);

        for (int i = 0; i < n; i++) {
            *(arr + i) = 0;
        }
        r = linearSearch(arr, n, 1);
        fprintf(f3, "%d\t%d\n", n, r);
        n = n * 2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}