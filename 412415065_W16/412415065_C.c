#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 200000

// 鄰接表節點
struct ListNode {
    int val;
    struct ListNode* next;
};

// 鄰接表
struct List {
    struct ListNode* head;
};

struct List adj[MAX_NODES];
int depth[MAX_NODES];
int maxDepth = 0;

// 創建一個新節點
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 添加邊到鄰接表
void addEdge(int u, int v) {
    struct ListNode* node = createNode(v);
    node->next = adj[u].head;
    adj[u].head = node;

    node = createNode(u);
    node->next = adj[v].head;
    adj[v].head = node;
}

// DFS 遞迴函數
void DFS(int node, int parent, int d) {
    depth[node] = d;
    if (d > maxDepth) {
        maxDepth = d;
    }

    struct ListNode* current = adj[node].head;
    while (current != NULL) {
        if (current->val != parent) {
            DFS(current->val, node, d + 1);
        }
        current = current->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // 初始化鄰接表
    for (int i = 0; i < n; i++) {
        adj[i].head = NULL;
    }

    // 讀取邊並構建鄰接表
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // 從0號節點開始進行DFS
    DFS(0, -1, 0);

    // 輸出樹的高度
    printf("%d\n", maxDepth);

    // 輸出每個節點的深度
    for (int i = 0; i < n; i++) {
        printf("%d ", depth[i]);
    }
    printf("\n");

    return 0;
}
