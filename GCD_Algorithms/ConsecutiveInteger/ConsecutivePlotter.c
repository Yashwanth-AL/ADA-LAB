#include <stdio.h>
#include <stdlib.h>

int consec(int m, int n) {
    int count = 0;
    int min = m < n ? m : n;
    while (1) {
        count++;
        if (m % min == 0) {
            count++;
            if (n % min == 0) {
                return count;
            }
        }
        min--;
    }
}

int main() {
    int m, n, i, j, k;
    int count, maxcount, mincount;
    FILE *fp1, *fp2;
    fp2 = fopen("c_b.txt", "a");
    fp1 = fopen("c_w.txt", "a");

    for (i = 10; i < 100; i += 10) {
        maxcount = 0;
        mincount = 10000;
        for (m = 2; m <= i; m++) {
            for (n = 2; n <= i; n++) {
                count = consec(m, n);
                if (count > maxcount)
                    maxcount = count;
                if (count < mincount)
                    mincount = count;
            }
        }
        fprintf(fp2, "%d %d\n", i, mincount);
        fprintf(fp1, "%d %d\n", i, maxcount);
    }
    fclose(fp2);
    fclose(fp1);
    return 0;
}
