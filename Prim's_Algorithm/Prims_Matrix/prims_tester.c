#include <stdio.h>
#include <limits.h>  //For using infinity

int numNodes;  
int visited[10] = {0}; 
int totalCost = 0; 
int arr[10][10]; 

void readInput() {
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0) {
                arr[i][j] = INT_MAX;  // Set to infinity if there is no edge
            }
        }
    }
}

int main() {
    int edgeCount = 1;  
    int minCost, r, c;

    readInput();
    visited[1] = 1;

    printf("\n");

    while (edgeCount < numNodes) {
        minCost = INT_MAX;

        // Find the smallest edge connecting visited and non-visited nodes
        for (int i = 1; i <= numNodes; i++) {
            for (int j = 1; j <= numNodes; j++) {
                if (arr[i][j] < minCost && visited[i]) {
                    minCost = arr[i][j];
                    r = i;
                    c = j;
                }
            }
        }

        // Add the edge to the MST if it connects a visited node to a non-visited node
        if (visited[r] && !visited[c]) {
            printf("Edge %d: (%c to %c) cost: %d\n", edgeCount++, r+64, c+64, minCost);
            totalCost += minCost;
            visited[c] = 1; 
        }
        
        // Remove the edge from consideration
        arr[r][c] = arr[c][r] = INT_MAX;
    }

    printf("Minimum cost of the MST: %d\n", totalCost);

    return 0;
}