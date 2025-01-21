#include <stdio.h>
#include <stdlib.h>

//W13 C

struct node {
    int val;
    struct node *nxt;
} typedef node;
struct list {
    int size;
    node *head;
} typedef list;

void push(list *lst, int n) { // 當 stack 用
    node *newnode = (node*)malloc(sizeof(node));
    newnode->val = n;
    lst->size++;
    if (lst->size == 0) {
        lst->head = newnode;
    } else {
        newnode->nxt = lst->head;
        lst->head = newnode;
    }
}

int deletenode(list *lst, int q) {
    node *pre = lst->head; // 欲刪除節點的前一個節點
    for (int i = 0; i < q; i++) {
        if (i == q - 1) pre = lst->head;
        lst->head = lst->head->nxt;
    }
    int ans = lst->head->val;
    
    node *tmp = lst->head;
    pre->nxt = lst->head->nxt;
    lst->head = pre;
    lst->size--;
    
    free(tmp);
    
    if (lst->size == 0) {
        lst->head = NULL;
    }
    return ans;
}

int main() {
    list lst = { 0, NULL };
    int n, q; scanf("%d %d", &n, &q);
    node *last = NULL;
    for (int i = n; i >= 1; i--) {
        push(&lst, i);
        if (i == n) {
            last = lst.head;
        }
    }
    last->nxt = lst.head; // circular linked list

    while (lst.size) {
        printf("%d ", deletenode(&lst, q));
    }
    return 0;
}