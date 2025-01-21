#include <stdio.h>
#include <stdlib.h>

//二分搜解 (O(tlogn) + O(nlogn), 查詢+排序)

int cmp(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

void solve(int *a, int n) {
    int x, k; scanf("%d %d", &x, &k);
    k -= x;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == k) {
            printf("True\n");
            return;
        } else if (a[m] > k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    printf("False\n");
}
int main() {
    int n; scanf("%d", &n);
    int q; scanf("%d", &q);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    qsort(a, n, sizeof(int), cmp);
    while (q--) {
        solve(a, n);
    }
    
    return 0;
}