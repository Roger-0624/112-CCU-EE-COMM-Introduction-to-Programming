#include <stdio.h>
#include <stdlib.h>

//W16 B

struct node {
    int val;
    struct node *l, *r;
} typedef node;

int pre[1000], in[1000];
node* dfs(int p, int l, int r) {
    if (l > r) return NULL;
    node *newnode = (node*)malloc(sizeof(node));
    int side = l;
    while (1) {
        if (in[side] == pre[p]) break;
        side++;
    }
    newnode->val = in[side];
    newnode->l = dfs(p + 1, l, side - 1);
    newnode->r = dfs(p + (side - l + 1), side + 1, r);
    return newnode;
}
void post_order(node *root) {
    if (root == NULL) return;
    post_order(root->l);
    post_order(root->r);
    printf("%d ", root->val);
}
int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", pre + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", in + i);
    }
    node *root = dfs(0, 0, n - 1);
    post_order(root);

    return 0;
}