#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
    char op[500]; //運算子
    int top;
} Stack;

char string[10005];

void push(Stack *stack, char c) {
    stack->op[++stack->top] = c;
}

int isempty(Stack *stack) 
{
    return stack->top == -1;
}

char pop(Stack *stack) {
    if(isempty(stack))
    {
        return '\0';
    }
    return stack->op[stack->top--];
}

int priority(char formula)
{
    if(formula =='*' || formula == '/') return 3;
    else if(formula == '%') return 2;
    else return 1;  // +, -
}

char get_top(Stack*stack) 
{
    if (stack->top == -1) 
    {
        return '\0'; 
    }
    return stack->op[stack->top];
}

void print(Stack *stack, int pri_formula)
{
    while(!isempty(stack) && priority(get_top(stack))>=pri_formula)
    {
        printf("%c", pop(stack));
    }
}

int main()
{
    Stack stack;
    stack.top=-1;
    int len, pri_formula, pri_top;
    char formula; 
    scanf("%s", string);
    len = strlen(string);
    for(int i = 0; i<len;i++)
    {
        formula = string[i];
        if(formula<='9' && formula >= '0')    //數字直接輸出
        {
            printf("%c", formula);
        }
        else    //符號
        {
            pri_formula = priority(formula);
            pri_top = priority(get_top(&stack));
            print(&stack ,pri_formula);
            push(&stack, formula);
        }
    }
    while(!isempty(&stack))
    {
        printf("%c", pop(&stack));
    }
    return 0;
}
    
