#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char op[205]; // 運算子
    int top;
} Stack;

typedef struct OperandStack {
    int values[205]; // 儲存操作數
    int top;
} OperandStack;

char string[10005];

void push(Stack *stack, char c) {
    stack->op[++stack->top] = c;
}

int isempty(Stack *stack) {
    return stack->top == -1;
}

char pop(Stack *stack) {
    if (isempty(stack)) {
        return '\0';
    }
    return stack->op[stack->top--];
}

int priority(char formula) {
    if (formula == '*' || formula == '/') return 3;
    else if (formula == '%') return 2;
    else return 1;  // +, -
}

char get_top(Stack *stack) {
    if (stack->top == -1) {
        return '\0';
    }
    return stack->op[stack->top];
}

void push_operand(OperandStack *stack, int value) {
    stack->values[++stack->top] = value;
}

int pop_operand(OperandStack *stack) {
    if (stack->top == -1) {
        return 0; // 預設返回0，如果堆疊為空
    }
    return stack->values[stack->top--];
}

int main() {
    Stack stack;
    stack.top = -1;
    OperandStack operand_stack;
    operand_stack.top = -1;
    int len, pri_formula;
    char formula;
    char post_order[205] = "";
    int post_order_len = 0;

    // 讀取輸入字串
    scanf("%s", string);
    len = strlen(string);

    // 將中序轉換為後序
    for (int i = 0; i < len; i++) {
        formula = string[i];
        if (formula <= '9' && formula >= '0') { // 數字直接輸出
            post_order[post_order_len++] = formula;
        } else { // 符號
            pri_formula = priority(formula);
            while (!isempty(&stack) && priority(get_top(&stack)) >= pri_formula) {
                post_order[post_order_len++] = pop(&stack);
            }
            push(&stack, formula);
        }
    }
    while (!isempty(&stack)) {
        post_order[post_order_len++] = pop(&stack);
    }

    // 計算後序表達式
    for (int i = 0; i < post_order_len; i++) {
        formula = post_order[i];
        if (formula <= '9' && formula >= '0') { // 數字
            push_operand(&operand_stack, formula - '0'); // 將字符轉換為整數
        } else { // 符號
            int b = pop_operand(&operand_stack);
            int a = pop_operand(&operand_stack);
            int result;
            switch (formula) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '%': result = a % b; break;
            }
            push_operand(&operand_stack, result);
        }
    }

    // 輸出計算結果
    int result = pop_operand(&operand_stack);
    printf("%d\n", result);

    return 0;
}
