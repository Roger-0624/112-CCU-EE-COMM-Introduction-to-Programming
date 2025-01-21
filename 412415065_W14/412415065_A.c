#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    char c;
    struct Stack *next;
} Stack;

Stack *top = NULL;

void push(char c) {
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    new_node->c = c;
    new_node->next = top;
    top = new_node;
}

char pop() {
    if (top == NULL) {
        return '\0'; // 堆疊為空時返回空字符
    }
    Stack *temp = top;
    char popped_char = top->c;
    top = top->next;
    free(temp);
    return popped_char;
}

char get_top() {
    if (top == NULL) {
        return '\0'; // 堆疊為空時返回空字符
    }
    return top->c;
}

int isempty() {
    return top == NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int conditions;
        scanf("%d", &conditions);
        if (conditions == 1) 
        {
            char c;
            scanf(" %c", &c); // 注意 %c 前面的空格來跳過換行符
            push(c);
        } 
        else if (conditions == 2) 
        {
            pop();
        } 
        else 
         {
            if (isempty())
            {
                printf("no character\n");
            } else {
                printf("%c\n", get_top());
            }
        }
    }
    return 0;
}