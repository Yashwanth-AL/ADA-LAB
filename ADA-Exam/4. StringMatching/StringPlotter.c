#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int count = 0; 

int stringmatching(char *text, char *pattern, int n, int m) { 
    count = 0; 
    for(int i = 0; i <= n - m; i++) { 
        int j = 0; 
        while(j < m) { 
            count++; 
            if(pattern[j] != text[i + j])  
                break;  
            j++; 
        } 
        if(j == m) { 
            return count; 
        } 
    } 
    return count; 
} 

void main() { 
    FILE *f1 = fopen("sm_b.txt", "a"); 
    FILE *f2 = fopen("sm_w.txt", "a"); 
    FILE *f3 = fopen("sm_a.txt", "a"); 
    char *text = (char *)malloc(1000 * sizeof(char)); 
    char *pattern; 
    for(int i = 0; i < 1000; i++) 
        text[i] = 'a'; 
    int n = 1000, m = 10; 
    while(m <= 1000) { 
        pattern = (char *)malloc(m * sizeof(char)); 

        // For Best case 
        count = 0; 
        for(int i = 0; i < m; i++) 
            pattern[i] = 'a'; 
        stringmatching(text, pattern, n, m); 
        fprintf(f1, "%d\t%d\n", m, count); 
         
        // For Worst case 
        count = 0; 
        pattern[m - 1] = 'b'; 
        stringmatching(text, pattern, n, m);  
        fprintf(f2, "%d\t%d\n", m, count); 

        // For Average Case 
        count = 0; 
        for(int i = 0; i < m; i++) 
            pattern[i] = 97 + rand() % 3; 
        stringmatching(text, pattern, n, m);  
        fprintf(f3, "%d\t%d\n", m, count); 
        
        free(pattern); 
        if(m < 100) 
            m = m + 10; 
        else 
            m = m + 100; 
    } 
}
