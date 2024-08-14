//Tester 
#include<stdio.h>                                                                                                           
#include<stdlib.h>

int test = 0;

int euclid(int m, int n) {
    int r;
    int count = 0;
    while (n) {
        count++;
        r = m % n;
        m = n;
        n = r;
    }
    
    printf("GCD = %d\n", m);
    return count;
}

int consec(int m, int n) {
    int count = 0;
    int min = m < n ? m : n;
    while (1) {
        count++;
        if (m % min == 0) {
            count++;
            if (n % min == 0) {
                printf("GCD = %d\n", min);
                return count;
            }
        }   
        min --;
    } 
}

int modified(int m, int n) {
    int count = 1;
    while (m != n) {
        (m > n) ? (m = m - n) : (n = n - m);
        count++;
    }
    printf("GCD = %d\n", m);
    return count;
} 

int main() {
    int choice, m, n;
    printf("GCD\n");
    printf("1. Euclid's method.\n");
    printf("2. Modified Euclid's method.\n");
    printf("3. Consecutive Integer method.\n");
    printf("0. Exit\n");
    do {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        if (choice == 0) 
        break;
        printf("Enter the two numbers: ");
        scanf("%d%d", &m, &n);
        switch (choice) {
            case 1:
                euclid(m, n);
                break;
            case 2:
                modified(m,n);
                break; 
            case 3:
                consec(m,n);
                break; 
            default:
                break;
        }
    } while (choice != 0);
    return 0;
}
