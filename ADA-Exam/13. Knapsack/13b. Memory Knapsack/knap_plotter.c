#include <stdio.h>
#include <stdlib.h>

int knap[100][100], profit[100], wt[100];
int item, cap;
int op_count = 0;


int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int i, int j) {
    if (knap[i][j] == -1) {
        op_count++; 
        if (j < wt[i]) {
            knap[i][j] = knapSack(i - 1, j);
        } else {
            knap[i][j] = max(knapSack(i - 1, j), profit[i] + knapSack(i - 1, j - wt[i]));
        }
    }
    return knap[i][j];
}


void run() {

    printf("Enter the number of items: ");
    scanf("%d", &item);
    printf("Enter the capacity of the sack: ");
    scanf("%d", &cap);

    printf("Enter weight and value for each item:\n");
    for (int i = 1; i <= item; i++) {
        printf("Item %d - Weight: ", i);
        scanf("%d", &wt[i]);
        printf("Item %d - Value: ", i);
        scanf("%d", &profit[i]);
    }

    // Initialize the DP table
    for (int i = 0; i <= item; i++) {
        for (int j = 0; j <= cap; j++) {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else
                knap[i][j] = -1;
        }
    }

    printf("Maximum Value: %d\n", knapSack(item, cap));

    // Print the DP table
    printf("\nDP Table:\n");
    for (int i = 0; i <= item; i++) {
        for (int j = 0; j <= cap; j++)
            printf("%d ", knap[i][j]);
        printf("\n");
    }

    // Print the items included in the knapsack
    printf("Composition of items in the knapsack:\n");
    int w = cap;
    for (int i = item; i > 0; i--) {
        if (knap[i][w] != knap[i - 1][w]) {
            printf("Item %d ", i);
            w-= wt[i];
        }
    }
    printf("\n");
}


int main() {
    FILE *f1 = fopen("knapsack.txt", "a");
    int ch;
    
    while(1) {
        printf("Enter choice 1 to continue and 0 to exit: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: {
                run();
                fprintf(f1, "%d\t%d\n", item, op_count);
                break;
            }
            default:
                fclose(f1);
                exit(0);
        }
    }

    fclose(f1);
    return 0;
}
