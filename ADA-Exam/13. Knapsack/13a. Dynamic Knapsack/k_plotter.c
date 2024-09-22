#include<stdio.h>
#include<stdlib.h>

int knap[100][100], profit[100], wt[100];
int op_count = 0;
int item, cap;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int item, int cap) {
    for(int i = 0; i <= item; i++) {
        for(int j = 0; j <= cap; j++) {
            if(i == 0 || j == 0) {
                knap[i][j] = 0;
            } else {
                op_count++; 
                if(j < wt[i]) {
                    knap[i][j] = knap[i - 1][j];
                } else {
                    knap[i][j] = max(knap[i - 1][j], profit[i] + knap[i - 1][j - wt[i]]);
                }
            }
        }
    }
    return knap[item][cap];
}

void run() {
    op_count = 0;
    printf("Enter the number of items: ");
    scanf("%d", &item);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &cap);

    for(int i = 1; i <= item; i++) {
        printf("Enter details of item %d :\n", i);
        printf("Weight: ");
        scanf("%d", &wt[i]);
        printf("Profit: ");
        scanf("%d", &profit[i]);
    }

   // Calculate the maximum profit
    int maxProfit = knapSack(item, cap);

    // Print the knap table
    printf("\nKnap Table:\n");
    for(int i = 0; i <= item; i++) {
        for(int j = 0; j <= cap; j++)
            printf("%d\t", knap[i][j]);
        printf("\n");
    }
    printf("\nMaximum profit: %d\n", maxProfit);

    printf("\nItems included in the knapsack:\n");
    int w = cap;
    for(int i = item; i > 0; i--) {
        if(knap[i][w] != knap[i - 1][w]) {
            printf("Item %d (Weight: %d, Profit: %d)\n", i, wt[i], profit[i]);
            w -= wt[i];
        }
    }
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
