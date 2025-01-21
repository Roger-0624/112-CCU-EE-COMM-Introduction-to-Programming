#include <stdio.h>

int main() {
    int l = -1e9, r = 1e9;
    while (l <= r) {
        int m = (l + r) / 2;
        printf("? %d\n", m);
        fflush(stdout);
        int res; scanf("%d", &res);

        if (res == 0) {
            printf("! %d\n", m);
            break;
        } else if (res == 1) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return 0;
}