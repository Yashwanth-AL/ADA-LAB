#include <stdio.h>
#include <stdlib.h>

int euclid(int m, int n) {
    int r, count = 0;
    while (n) {
        count++;
        r = m % n;
        m = n;
        n = r;
    }
    return count;
}

int main() {
    int m, n, i, j, k;
    int count, maxcount, mincount;
    FILE *fp1, *fp2;
    fp1 = fopen("e_b.txt", "a");
    fp2 = fopen("e_w.txt", "a");

    for (i = 10; i < 100; i += 10) {
        maxcount = 0;
        mincount = 10000;
        for (m = 2; m <= i; m++) {
            for (n = 2; n <= i; n++) {
                count = 0;
                count = euclid(m, n);

                if (count > maxcount)
                    maxcount = count;
                if (count < mincount)
                    mincount = count;
            }
        }
        fprintf(fp1, "%d %d\n", i, mincount);
        fprintf(fp2, "%d %d\n", i, maxcount);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
