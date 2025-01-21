#include <stdio.h>
int pref[200005][32];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        for (int j = 0; j < 32; j++) {
            if (x & 1) pref[i + 1][j] += pref[i][j] + 1;
            x >>= 1;
        }
    }

    int q; scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (pref[r][i] - pref[l - 1][i] == r - l + 1) {
                ans += 1 << i;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
