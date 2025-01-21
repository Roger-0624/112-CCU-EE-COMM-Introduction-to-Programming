#include <stdio.h>
#include <stdlib.h>
#define int long long
const int mod = 1e9 + 7;

typedef struct {
    int val;
    int len;    // 代表它管了多少老鼠，也是 nxt 指向的陣列大小
    char op;
    int *nxt;
} node;

void dfs(node *tree, int u) {
    if (tree[u].len == 0) {
        return;
    }
    for (int i = 0; i < tree[u].len; i++) {
        dfs(tree, tree[u].nxt[i]);
        // 做 dfs 後序遍歷，較深的節點會先計算，老鼠大臣最後計算
        if (tree[u].op == '+') tree[u].val += tree[tree[u].nxt[i]].val;
        else tree[u].val *= tree[tree[u].nxt[i]].val;
        tree[u].val %= mod;
    }
}

signed main() {
    int n; scanf("%lld", &n);
    node tree[n + 1];
    int u_buffer[n + 1], v_buffer[n + 1];

    for (int i = 1; i <= n; i++) {
        int u, val; char op;
        scanf("%lld %lld %c", &u, &val, &op);
        tree[u].op = op;
        tree[u].val = val;
        tree[u].len = 0;
        u_buffer[i] = v_buffer[i] = 0;
    }
    
    // 先把 u、v 邊用 buffer 存起來，最後再填入各自的 node 裡
    for (int i = 0; i < n - 1; i++) {
        int u, v; scanf("%lld %lld", &u, &v);
        u_buffer[i] = u;
        v_buffer[i] = v;
        tree[u].len++;
    }
    // 知道了每位老鼠官員管理多少官員，就可以用 malloc 了
    
    int now_len[n + 1];
    // now_len 代表當前節點已經填入了幾個鄰點，當與 tree[i].len 相等代表已經填滿
    for (int i = 1; i <= n; i++) {
        tree[i].nxt = (int *)malloc(sizeof(int) * (tree[i].len));
        now_len[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        tree[u_buffer[i]].nxt[now_len[u_buffer[i]]++] = v_buffer[i];
    }
    
    dfs(tree, 1);
    printf("%lld\n", tree[1].val);
}