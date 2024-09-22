#include<stdio.h>
#include<stdlib.h>

int knap[100][100], profit[100], wt[100];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int item, int cap) {
    for(int i = 0; i <= item; i++) {
        for(int j = 0; j <= cap; j++) {
            if(i == 0 || j == 0)
                knap[i][j] = 0;
            else if(j < wt[i])
                knap[i][j] = knap[i - 1][j];
            else
                knap[i][j] = max(knap[i - 1][j], profit[i] + knap[i - 1][j - wt[i]]);
        }
    }
    return knap[item][cap];
}

int main() {
    int item, cap;

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

    // Print the items included in the knapsack
    printf("\nItems included in the knapsack:\n");
    int w = cap;
    for(int i = item; i > 0; i--) {
        if(knap[i][w] != knap[i - 1][w]) {
            printf("Item %d (Weight: %d, Profit: %d)\n", i, wt[i], profit[i]);
            w -= wt[i];
        }
    }

    return 0;
}
