#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode *insert(TreeNode *root, int num)
{
    if(root == NULL)
    {
        TreeNode *new_node = malloc(sizeof(TreeNode));
        new_node->data = num;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if(num < root->data)
    {
        root->left = insert(root->left, num);
    }
    else if(num > root->data)
    {
        root->right = insert(root->right, num);
    }
    return root;
}

TreeNode *search(TreeNode *root, int num)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(num < root->data)
    {
        return search(root->left, num);
    }
    else if(num > root->data)
    {
        return search(root->right, num);
    }
    else    // num == root->data
    {
        return root;
    }
}

TreeNode *Delete(TreeNode *root, int num)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(num < root->data)
    {
        root->left = Delete(root->left, num);
    }
    else if(num > root->data)
    {
        root->right = Delete(root->right, num);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            TreeNode *temp = root->right;
            while(temp && temp->left != NULL)   //找右子樹的最小節點
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void PreorderTraversal (TreeNode* root) {
    if (root != NULL) 
    {
        printf("%d ", root->data);
        PreorderTraversal (root->left);
        PreorderTraversal (root->right);
    }
}

void InorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        printf("%d ", root->data);
        InorderTraversal(root->right);
    }
}

void PostorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void Traversal(TreeNode *root, int mode)
{
    if(mode == 1)
    {
        PreorderTraversal(root);
    }
    else if(mode == 2)
    {
        InorderTraversal(root);
    }
    else    //mode == 3
    {
        PostorderTraversal(root);
    }
    printf("\n");
}

int main()
{
    int n, conditions, num, mode;
    TreeNode *root = NULL;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &conditions);
        if(conditions == 1)
        {
            scanf("%d", &num);
            root = insert(root, num);
        }
        else if(conditions == 2)
        {
            scanf("%d", &num);
            root = Delete(root, num);
        }
        else if(conditions == 3)
        {
            scanf("%d", &mode);
            Traversal(root, mode);
        }
        else    //conditions == 4
        {
            scanf("%d", &num);
            if(search(root, num)!=NULL)
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
    }
    return 0;
}