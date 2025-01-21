#include <stdio.h>
#include <stdlib.h>

// 定義二叉樹節點結構
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 創建一個新節點
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// 查找值在inorder陣列中的索引
int search(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

// 構建二叉樹的遞迴函數
struct TreeNode* buildTree(int* preorder, int* inorder, int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // 取得當前節點的值並創建節點
    int currentValue = preorder[*preorderIndex];
    struct TreeNode* node = createNode(currentValue);
    (*preorderIndex)++;

    // 如果這個節點沒有子節點，則返回節點
    if (inorderStart == inorderEnd) {
        return node;
    }

    // 在inorder陣列中找到當前節點的索引
    int inorderIndex = search(inorder, inorderStart, inorderEnd, currentValue);

    // 使用該索引構建左右子樹
    node->left = buildTree(preorder, inorder, inorderStart, inorderIndex - 1, preorderIndex);
    node->right = buildTree(preorder, inorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return node;
}
// Postorder遍歷並輸出結果
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n];
    int inorder[n];

    // 輸入Preorder結果
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    // 輸入Inorder結果
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preorderIndex = 0;
    struct TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preorderIndex);

    // 輸出Postorder結果
    postorderTraversal(root);
    printf("\n");

    return 0;
}
