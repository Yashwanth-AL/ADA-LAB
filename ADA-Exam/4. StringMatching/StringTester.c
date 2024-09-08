#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int count = 0; 

int stringmatching(char *text, char *pattern, int n, int m) { 
    count = 0; 
    for (int i = 0; i <= n - m; i++) { 
        int j = 0; 
        while (j < m) { 
            count++; 
            if (pattern[j] != text[i + j]) 
                break; 
            j++; 
        } 
        if (j == m) { 
            printf("THE PATTERN FOUND \n"); 
            return count; 
        } 
    } 
    printf("THE PATTERN not found \n"); 
    return count; 
} 
 
int main() { 
    char text[100], pattern[100]; 

    printf("enter the pattern\n"); 
    fgets(pattern, sizeof(pattern), stdin); 
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove the newline character from the input 

    printf("enter the text\n"); 
    fgets(text, sizeof(text), stdin); 
    text[strcspn(text, "\n")] = '\0'; // Remove the newline character from the input 

    int m = strlen(pattern); // Get the length of the pattern
    int n = strlen(text);    // Get the length of the text

    int comparisons = stringmatching(text, pattern, n, m); 
    printf("number of comparisons: %d\n", comparisons); 

    return 0; 
}
