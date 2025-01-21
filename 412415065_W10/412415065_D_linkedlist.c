#include <stdio.h>
#include <stdlib.h>
#define int long long
const int mod = 1e9 + 7;

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct {
    int val;
    int len;    // 管几只老鼠
    char op;
    ListNode *nxt; // 子节点链表
} mouse; 

void dfs(mouse *tree, int u) {
    if (tree[u].len == 0) return;

    ListNode *current = tree[u].nxt;
    while (current != NULL) {
        dfs(tree, current->val);
        if (tree[u].op == '+') {
            tree[u].val += tree[current->val].val;
        } else {
            tree[u].val *= tree[current->val].val;
        }
        tree[u].val %= mod;
        current = current->next;
    }
}

signed main() {
    int n;
    scanf("%lld", &n);
    mouse tree[n + 1];

    for (int i = 1; i <= n; i++) {
        int u, val;
        char op;
        scanf("%lld %lld %c", &u, &val, &op);
        tree[u].op = op;
        tree[u].val = val;
        tree[u].len = 0;
        tree[u].nxt = NULL; // 初始化链表头指针为 NULL
    }

    for (int i = 0; i < n - 1; i++) { // 读取边信息
        int u, v;
        scanf("%lld %lld", &u, &v);

        // 创建新的链表节点
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->val = v;
        newNode->next = tree[u].nxt; // 插入到链表头部
        tree[u].nxt = newNode;

        tree[u].len++;
    }

    dfs(tree, 1);
    printf("%lld\n", tree[1].val);

    // 释放链表内存
    for (int i = 1; i <= n; i++) {
        ListNode *current = tree[i].nxt;
        while (current != NULL) {
            ListNode *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}