#include <stdio.h>

void solve(int *vis) {
    int x, k; scanf("%d %d", &x, &k);
    k -= x;
    if (k >= 0 && vis[k]) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

int main() {
    int n, q; scanf("%d %d", &n, &q);
    int vis[200005] = {};
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        vis[x] = 1;
    }
    
    while (q--) {
        solve(vis);
    }
    
    return 0;
}

//如果你有在寫 leetcode，應該對這種把排序O(nlogn)壓成O(num)+O(n)的做法不陌生
//，只要num不要太大就可以這麼做，否則就只能二分搜。出題者說這是非預期解，但為了平均分，在我的建議下還是維持原樣。
//n是陣列大小、num是陣列中最大的數字

//補充:
//本題若把num拉大，除了二分搜外，也可以用之後資料結構會學到的平衡二元搜尋樹，
//也可以做到跟二分搜一樣O(logn)的查詢，本學期教的BST由於沒有保證平衡、可能會歪斜，
//導致查詢有可能會退化到O(n)。