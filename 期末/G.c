#include <stdio.h>
#include <stdlib.h>

//https://cses.fi/problemset/task/1641

struct cake {
    int val;
    int id;
} typedef cake;

int cmp(const void *a, const void *b) {
    return ((cake *)a)->val - ((cake *)b)->val;
}

int main() {
    int n, k;
    cake cakes[n];

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cakes[i].val);
        cakes[i].id = i + 1;
    }

    qsort(cakes, n, sizeof(cake), cmp);

    for (int i = 0; i < n; i++) {
        if (cakes[i].val >= k) continue;

        int l = 0, r = n - 1;
        int x = k - cakes[i].val;
        while (l < r) {
            if (l == i) { l++; continue; }
            if (r == i) { r--; continue; }
            
            int sum = cakes[l].val + cakes[r].val;
            if (sum == x) {
                printf("%d %d %d\n",
                       cakes[i].id, 
                       cakes[l].id, 
                       cakes[r].id);
                return 0;
            }
            else if (sum < x) l++;
            else r--;
        }
    }
    printf("IMPOSSIBLE\n");
    
    return 0;
}

