#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int cnt[33] = {};
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    int ans = 0; int mx = 0;
    for (int i = 1; i <= 32; i++) {
        if (cnt[i] > mx) {
            ans = i;
            mx = cnt[i];
        }
    }
    printf("%d\n", ans);
    
    return 0;
}