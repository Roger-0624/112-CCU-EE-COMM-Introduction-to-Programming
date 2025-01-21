#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *nxt;
} typedef node;
struct stack {
    int size;
    node *topnode;
} typedef stack;

int f(char c) {
    if (c == 'R') return 1;
    else return -1;
}
int main() {
    int n; scanf("%d", &n);
    stack stk = { 0, NULL };
    for (int i = 0; i < n; i++) {
        char op; scanf(" %c", &op);
        if (op != 'B') {
            node *newnode = (node*)malloc(sizeof(node));
            newnode->d = f(op);
            newnode->nxt = stk.topnode;
            stk.topnode = newnode;
            stk.size++;
        }
        else if (stk.size) {
            node *tmp = stk.topnode;
            stk.topnode = tmp->nxt;
            free(tmp);
            stk.size--;
        }
    }
    int ans = 0;
    while (stk.size) {
        node *tmp = stk.topnode;
        stk.topnode = tmp->nxt;
        ans += tmp->d;
        free(tmp);
        stk.size--;
    }

    printf("%d\n", ans);
    return 0;
}

//1.Stack 題，遇到 L、R 就 push、遇到 B 就對 stack pop，最後才根據 stack 剩下的東西決定答案，測資應該要放入連續 pop 幫助大家理解題目，在此致歉。
//2.因為不長且為了方便直接在 main 裡實作 stack 函式。