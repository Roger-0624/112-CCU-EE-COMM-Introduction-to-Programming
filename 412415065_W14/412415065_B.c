#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    char formula[200005];
    int top;
} Stack;

void push(Stack*stack, char c) {
    stack->formula[++stack->top] = c;
}

int isempty(Stack*stack) 
{
    return stack->top == -1;
}

char pop(Stack*stack) {
    if(isempty(stack))
    {
        return '\0';
    }
    return stack->formula[stack->top--];
}

char get_top(Stack*stack) {
    if (isempty(stack)) {
        return '\0'; // 堆疊為空時返回空字符
    }
    return stack->formula[stack->top];
}

int main()
{
    Stack stack;
    stack.top = -1;
    int n;
    scanf("%d", &n);
    char characters, top, string[n+1];
    scanf("%s", string);
    if(n%2==0)
    {
        for(int i=0;i<n;i++)
        {
            characters = string[i];
            if(characters == '(' || characters == '[' || characters == '{') //左括號直接push進去
            {
                push(&stack, characters);
            }
            else
            {
                top = get_top(&stack);
                if(characters == ')' && top == '(' ||
                   characters == ']' && top == '[' ||
                   characters == '}' && top == '{')
                   {
                        pop(&stack);
                   }
                else    //只要有一組不行 就一定不行
                {
                    printf("No");
                    return 0;
                }
            }
            
        }

        if(isempty(&stack))
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }
    }
    else
    {
        printf("No");
    }
    return 0;
}